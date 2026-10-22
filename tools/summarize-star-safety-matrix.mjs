import fs from 'node:fs/promises';
import crypto from 'node:crypto';

const directory = new URL('../evidence/full-race-matrix/', import.meta.url);
const sources = [
  ['stars-safety-d0.json', 'stars-d0-final.json'],
  ['stars-safety-d1.json', 'stars-d1-final.json'],
  ['stars-safety-d2.json', 'stars-d2-final.json'],
  ['stars-safety-nl-normal-early.json', 'stars-nl-normal-early-approach-final.json'],
];
const hash = value => crypto.createHash('sha256').update(JSON.stringify(value)).digest('hex');
const rows = [], assets = {}, errors = [];
let productionFingerprint;
for (const [filename, priorFilename] of sources) {
  const report = JSON.parse(await fs.readFile(new URL(filename, directory)));
  const prior = JSON.parse(await fs.readFile(new URL(priorFilename, directory)));
  if (report.status !== 'all-finished') errors.push(`${filename}: ${report.status ?? 'still running'}`);
  for (const field of ['sourceChangedDuringRun', 'assetsChangedDuringRun']) {
    if (!Array.isArray(report[field]) || report[field].length)
      errors.push(`${filename}: ${field} not clear`);
  }
  const production = Object.entries(report.sourceAtStart).filter(([name]) => name.startsWith('src/'));
  const fingerprint = hash(production);
  if (productionFingerprint && fingerprint !== productionFingerprint)
    errors.push(`${filename}: production fingerprint differs`);
  productionFingerprint ??= fingerprint;
  for (const [name, digest] of Object.entries(report.assetSha256)) {
    if (assets[name] && assets[name] !== digest) errors.push(`${filename}: asset differs: ${name}`);
    assets[name] = digest;
  }
  for (const run of report.runs) {
    const old = prior.runs.find(candidate => candidate.track === run.track
      && candidate.difficulty === run.difficulty && candidate.raceMode === run.raceMode);
    const complete = run.status === 'finished' && run.race.lapCount === 5 && run.stars === 12;
    if (!complete) errors.push(`${filename}: track ${run.track} difficulty ${run.difficulty} incomplete`);
    rows.push({
      track: run.track, difficulty: run.difficulty, mode: run.raceMode,
      report: filename, priorReport: priorFilename, complete,
      character: report.character, constructionSeed: report.constructionSeed,
      gameplaySeed: report.gameplaySeed, driverOptions: report.driverOptions,
      testDriverPolicy: report.testDriverPolicy ?? 'Canonical collision-aware route follower',
      durationMs: run.durationMs, laps: run.race.lapCount, stars: run.stars,
      rank: run.rank, qualification: run.qualification, rescue: run.rescue,
      npcVelocitySafetyCorrections: run.events['npc-velocity-safety'] ?? 0,
      inputSha256: run.inputSha256,
      identicalPriorControlTrace: old?.inputSha256 === run.inputSha256,
    });
  }
}
rows.sort((a, b) => a.difficulty - b.difficulty || a.track - b.track);
if (rows.length !== 18 || new Set(rows.map(row => `${row.track},${row.difficulty},${row.mode}`)).size !== 18)
  errors.push('Expected exactly 18 unique STAR cases');
const summary = {
  format: 'superkarts-star-safety-matrix-summary-v1',
  status: errors.length ? 'failed' : 'all-18-star-objectives-complete',
  scope: 'Original-data active-grid composed simulation driven only by ordinary controls. Five physical laps and twelve stars required; rank qualification reported separately. Does not include authored opening/countdown or original Windows full-process comparison.',
  policy: 'Canonical speed 30 driver for 17 cases; Netherlands normal uses the frozen earlier-approach private helper with the same original character 0 and gameplay seed 0.',
  productionFingerprint, assetFingerprint: hash(Object.entries(assets).sort()),
  rows, completed: rows.filter(row => row.complete).length,
  qualified: rows.filter(row => row.qualification.qualified).length,
  identicalPriorControlTraces: rows.filter(row => row.identicalPriorControlTrace).length,
  npcVelocitySafetyCorrections: rows.reduce((sum, row) => sum + row.npcVelocitySafetyCorrections, 0),
  errors, generatedAt: new Date().toISOString(),
};
await fs.writeFile(new URL('stars-safety-summary.json', directory), JSON.stringify(summary, null, 2) + '\n');
console.log(JSON.stringify({
  status: summary.status, completed: summary.completed, qualified: summary.qualified,
  identicalPriorControlTraces: summary.identicalPriorControlTraces,
  npcVelocitySafetyCorrections: summary.npcVelocitySafetyCorrections, errors,
}, null, 2));
if (errors.length) process.exitCode = 1;
