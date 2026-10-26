// Read-only review of the selected evidence and the human-facing summary generator.
// This writes its own audit artifact; it does not regenerate the matrix or summary.
import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import { nativeAdventureQualification } from '../source/simulation/native-adventure.js';

const root = new URL('../', import.meta.url);
const folder = 'evidence/full-race-matrix/';
const digest = value => crypto.createHash('sha256').update(value).digest('hex');
const bytes = path => fs.readFile(new URL(path, root));
const json = async path => JSON.parse(await bytes(path));
const matrixBytes = await bytes(`${folder}race-matrix.json`);
const matrix = JSON.parse(matrixBytes);
const generatorBytes = await bytes('tools/write-full-race-summary.mjs');
const documentBytes = await bytes('docs/full-race-results.md');
const document = String(documentBytes);
const errors = [], rows = [];
for (const cell of matrix.races) {
  const reportBytes = await bytes(cell.file), report = JSON.parse(reportBytes);
  const run = report.runs[cell.index];
  const check = (condition, message) => { if (!condition) errors.push(`${cell.key}: ${message}`); };
  check(digest(reportBytes) === cell.reportSha256, 'selected report changed');
  check([run.track, run.difficulty, run.raceMode].join(',') === cell.key, 'wrong report run selected');
  check(run.status === 'finished' && run.race.finished && run.lapEvents.length === 5,
    'selected run does not have five physical lap events');
  check(cell.lapTimes.length === 5 && cell.lapTimes.every(Number.isFinite), 'invalid lap times');
  const displayedTimeMs = cell.lapTimes.reduce((sum, value) => sum + value, 0);
  check(displayedTimeMs === run.race.raceTimeMs, 'displayed time differs from original race total');
  check(displayedTimeMs === (run.activeElapsedMs ?? run.race.elapsedMs),
    'displayed time differs from active elapsed time');
  check(Number.isInteger(cell.rank) && cell.rank >= 0 && cell.rank <= run.opponents,
    'rank outside the original race population');
  check(cell.rank === run.rank, 'rank differs from linked report');
  const qualification = nativeAdventureQualification(
    { difficulty: run.difficulty, raceType: run.raceMode },
    { rank: run.rank, finished: run.race.finished, stars: run.stars });
  check(cell.qualified === qualification.qualified, 'qualification differs from original rule');
  check(cell.cadenceMs === 25 && report.cadenceMs === 25, 'selected nonproduction cadence');
  if (run.raceMode === 1) check(run.race.remainingMs > 0, 'timed run has no remaining time');
  if (run.raceMode === 2) check(run.stars === 12, 'star run lacks all twelve stars');
  rows.push({ key: cell.key, report: cell.file, displayedTimeMs, rank: cell.rank,
    qualified: cell.qualified,
    startScope: run.opening ? 'authored-camera-and-countdown' : 'active-grid',
    ...(run.opening ? { greenWallMs: run.opening.greenWallMs,
      firstDriverInputWallMs: run.opening.firstDriverInputWallMs } : {}),
    ...(report.sourceReport ? { sourceReport: report.sourceReport } : {}) });
}
if (rows.length !== matrix.counts.completed) errors.push('completed count does not match selected rows');
if (rows.filter(row => row.qualified).length !== matrix.counts.qualified) errors.push('qualification count mismatch');
const countries = ['Nederland', 'Germany', 'England', 'France', 'Spain', 'Italy'];
const difficulties = ['Easy', 'Medium', 'Hard'];
const tableRows = document.split('\n').filter(line => /^\| (Nederland|Germany|England|France|Spain|Italy) \|/.test(line));
if (tableRows.length !== 18) errors.push('document does not contain eighteen track/difficulty rows');
for (const row of rows) {
  const [track, difficulty, mode] = row.key.split(',').map(Number);
  const line = tableRows.find(line => line.startsWith(`| ${countries[track]} | ${difficulties[difficulty]} |`));
  const value = line?.split('|')[mode + 3]?.trim();
  const match = value?.match(/^\[(\d+):(\d{2})\.(\d{3}) · (\d+)(?:st|nd|rd|th)( ✓)?\]\(\.\.\/(.+)\)$/);
  if (!match || Number(match[1]) * 60000 + Number(match[2]) * 1000 + Number(match[3]) !== row.displayedTimeMs
    || Number(match[4]) !== row.rank + 1 || Boolean(match[5]) !== row.qualified || match[6] !== row.report) {
    errors.push(`${row.key}: human-facing table value/link differs from verified report`);
  }
}
if (!document.includes(`${matrix.counts.completed} of 72 combinations`)
  || !document.includes(`${matrix.counts.qualified} of those runs`)) errors.push('document headline counts are stale');
const browser = [];
for (const path of ['mirror-browser/validation.json', 'rescue-browser/environment-rescue-browser.json',
  'rescue-browser/player-rescue-safety-browser.json']) {
  const reportBytes = await bytes(`${folder}${path}`), report = JSON.parse(reportBytes);
  if (report.status !== 'passed' || report.errors.length) errors.push(`browser check failed: ${path}`);
  browser.push({ path, sha256: digest(reportBytes), checks: report.checks.length });
}
const unitBytes = await bytes(`${folder}final-unit-tests.log`), unitText = String(unitBytes);
const unit = Object.fromEntries(['pass', 'fail', 'skipped'].map(key =>
  [key, Number(unitText.match(new RegExp(`ℹ ${key} (\\d+)`))?.[1])]));
if (!unit.pass || unit.fail !== 0 || unit.skipped !== 0) errors.push('unit test totals are not a clean pass');
const browserChecks = browser.reduce((sum, item) => sum + item.checks, 0);
if (!document.includes(`passes ${unit.pass} tests and ${browserChecks} focused browser checks`)) {
  errors.push('document validation totals differ from current logs');
}
const result = {
  format: 'superkarts-full-race-summary-review-v1', generatedAt: new Date().toISOString(),
  status: errors.length ? 'failed' : 'passed',
  scope: 'Independent read-only check of displayed times, ranks, native qualification, cadence and recorded start scope against each selected full-race report. This does not rerun the races or claim every runtime feature is verified.',
  matrixSha256: digest(matrixBytes), generatorSha256: digest(generatorBytes), documentSha256: digest(documentBytes),
  completed: rows.length, qualified: rows.filter(row => row.qualified).length,
  startScopes: Object.fromEntries([...Map.groupBy(rows, row => row.startScope)]
    .map(([scope, group]) => [scope, group.length])),
  unit: { ...unit, logSha256: digest(unitBytes) }, browser,
  resolvedEditorialFindings: [
    'The generator now describes the existing player-return safeguard as well as the two newer safeguards.',
    'The generator distinguishes active-grid validation from selected original opening/countdown runs without relying on misleading runner filenames.',
  ],
  rows, errors,
};
await fs.writeFile(new URL(`${folder}summary-review.json`, root), JSON.stringify(result, null, 2) + '\n');
console.log(JSON.stringify({ status: result.status, completed: result.completed,
  qualified: result.qualified, startScopes: result.startScopes, unit: result.unit,
  browserChecks, errors }, null, 2));
if (errors.length) process.exitCode = 1;
