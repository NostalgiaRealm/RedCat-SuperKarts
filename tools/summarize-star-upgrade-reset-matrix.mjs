// Summarizes frozen historical evidence; src/ keys are the paths recorded then.
import fs from 'node:fs/promises';
import crypto from 'node:crypto';

const directory = new URL('../evidence/full-race-matrix/', import.meta.url);
const filenames = [
  'stars-upgrade-reset-d0.json',
  'stars-upgrade-reset-d1.json',
  'stars-upgrade-reset-d2.json',
  'stars-upgrade-reset-nl-normal-early.json',
  ...JSON.parse(process.env.RCSK_STAR_RETRY_REPORTS ?? '[]'),
];
const digest = value => crypto.createHash('sha256').update(JSON.stringify(value)).digest('hex');
const selected = new Map(), attempts = [], errors = [], assets = {};
let productionFingerprint;
for (const filename of filenames) {
  const bytes = await fs.readFile(new URL(filename, directory));
  const report = JSON.parse(bytes);
  const fingerprint = digest(Object.entries(report.sourceAtStart).filter(([name]) => name.startsWith('src/')));
  if (productionFingerprint && productionFingerprint !== fingerprint) errors.push(`${filename}: production differs`);
  productionFingerprint ??= fingerprint;
  for (const field of ['sourceChangedDuringRun', 'assetsChangedDuringRun']) {
    if (!Array.isArray(report[field]) || report[field].length) errors.push(`${filename}: ${field} not clear`);
  }
  if (report.cadenceMs !== 25) errors.push(`${filename}: cadence is not the production 25 ms`);
  for (const [name, sha256] of Object.entries(report.assetSha256)) {
    if (assets[name] && assets[name] !== sha256) errors.push(`${filename}: asset differs: ${name}`);
    assets[name] = sha256;
  }
  for (const run of report.runs) {
    const starIds = [...new Set(run.pickupEvents.filter(event => event.type === 'star').map(event => event.pickup))].sort((a, b) => a - b);
    const authoredStarIds = run.starApproaches.map(star => star.index).sort((a, b) => a - b);
    const complete = run.status === 'finished' && run.race.lapCount === 5
      && run.lapEvents.length === 5 && run.stars === 12 && starIds.length === 12
      && JSON.stringify(starIds) === JSON.stringify(authoredStarIds);
    const row = {
      track: run.track, difficulty: run.difficulty, mode: run.raceMode,
      report: filename, reportSha256: crypto.createHash('sha256').update(bytes).digest('hex'),
      complete, status: run.status, character: report.character,
      constructionSeed: report.constructionSeed, gameplaySeed: report.gameplaySeed,
      cadenceMs: report.cadenceMs, driverOptions: report.driverOptions,
      testDriverPolicy: report.testDriverPolicy ?? 'Canonical collision-aware route follower',
      durationMs: run.durationMs, laps: run.race.lapCount,
      physicalLapEvents: run.lapEvents.length, stars: run.stars, starIds, authoredStarIds,
      rank: run.rank, qualification: run.qualification, rescue: run.rescue,
      npcVelocitySafetyCorrections: run.events['npc-velocity-safety'] ?? 0,
      inputSha256: run.inputSha256,
    };
    attempts.push(row);
    selected.set(`${row.track},${row.difficulty},${row.mode}`, row);
  }
}
const rows = [...selected.values()].sort((a, b) => a.difficulty - b.difficulty || a.track - b.track);
if (rows.length !== 18 || rows.some(row => row.mode !== 2)) errors.push('Expected exactly 18 unique STAR cases');
for (const row of rows) if (!row.complete) errors.push(`track ${row.track}, difficulty ${row.difficulty}: five laps and all twelve authored stars not completed`);
const summary = {
  format: 'superkarts-star-upgrade-reset-matrix-summary-v1',
  status: errors.length ? 'incomplete' : 'all-18-star-objectives-complete',
  scope: 'Original-data active-grid simulation with the recovered constructor upgrade reset, driven only by ordinary controls at the production 25 ms cadence. Requires five physical laps and all twelve distinct authored star pickups. Rank qualification is separate. Does not include the authored opening/countdown or an original Windows full-process comparison.',
  productionFingerprint, assetFingerprint: digest(Object.entries(assets).sort()),
  rows, attempts,
  completed: rows.filter(row => row.complete).length,
  qualified: rows.filter(row => row.qualification.qualified).length,
  npcVelocitySafetyCorrections: rows.reduce((sum, row) => sum + row.npcVelocitySafetyCorrections, 0),
  errors, generatedAt: new Date().toISOString(),
};
await fs.writeFile(new URL('stars-upgrade-reset-summary.json', directory), JSON.stringify(summary, null, 2) + '\n');
console.log(JSON.stringify({
  status: summary.status, completed: summary.completed, qualified: summary.qualified,
  npcVelocitySafetyCorrections: summary.npcVelocitySafetyCorrections, errors,
}, null, 2));
if (errors.length) process.exitCode = 1;
