import fs from 'node:fs/promises';
import crypto from 'node:crypto';

const directory = new URL('../evidence/full-race-matrix/', import.meta.url);
const root = new URL('../', import.meta.url);
const hash = value => crypto.createHash('sha256').update(value).digest('hex');
const fingerprint = entries => hash(JSON.stringify(entries));
const anchor = JSON.parse(await fs.readFile(new URL('stars-upgrade-reset-summary.json', directory)));
const files = (await fs.readdir(directory))
  .filter(name => /^timed-.*\.json$/.test(name)).sort();
const rows = [], errors = [], excluded = [];
const currentHashes = new Map();
async function currentHash(path) {
  if (!currentHashes.has(path)) currentHashes.set(path, hash(await fs.readFile(new URL(path, root))));
  return currentHashes.get(path);
}
const scalar = value => ['string', 'number', 'boolean'].includes(typeof value) ? value : null;
function contactIdentity(contact, side) {
  const body = contact[`${side}Body`];
  return {
    [`${side}BodyId`]: scalar(body?.id),
    [`${side}PlacementIndex`]: scalar(body?.placementIndex),
    // Animated meshes may change after this contact. This label comes from
    // the retained reference when the report was serialized, not the event.
    [`${side}MeshAtSerialization`]: scalar(body?.mesh),
  };
}
for (const name of files) {
  const bytes = await fs.readFile(new URL(name, directory));
  const report = JSON.parse(bytes);
  const runs = report?.runs?.filter(run => run.track === 3 && run.difficulty === 2 && run.raceMode === 1);
  if (!runs?.length) continue;
  const productionEntries = Object.entries(report.sourceAtStart ?? {})
    .filter(([path]) => path.startsWith('src/'));
  const productionFingerprint = fingerprint(Object.entries(report.sourceAtStart ?? {})
    .filter(([path]) => path.startsWith('src/')));
  const reasons = [];
  if (productionFingerprint !== anchor.productionFingerprint) reasons.push('different production runtime');
  if (report.cadenceMs !== 25) reasons.push('different or unrecorded cadence');
  if (reasons.length) {
    excluded.push({ report: name, reportSha256: hash(bytes), runs: runs.length,
      reasons, productionFingerprint, cadenceMs: report.cadenceMs });
    continue;
  }
  if (!report.completedAt) errors.push(`${name}: report has no completion timestamp`);
  for (const key of ['sourceChangedDuringRun', 'executionSourceChangedDuringRun', 'assetsChangedDuringRun']) {
    if (!Array.isArray(report[key]) || report[key].length) errors.push(`${name}: ${key} not clear`);
  }
  for (const [path, digest] of productionEntries) {
    if (await currentHash(path) !== digest) errors.push(`${name}: current production differs at ${path}`);
  }
  if (!report.assetSha256 || !Object.keys(report.assetSha256).length) errors.push(`${name}: missing asset digests`);
  for (const [path, digest] of Object.entries(report.assetSha256 ?? {})) {
    if (await currentHash(`public/assets/${path}`) !== digest) errors.push(`${name}: current asset differs at ${path}`);
  }
  for (const run of runs) {
    const controls = {};
    for (const key of ['character', 'constructionSeed', 'gameplaySeed', 'driverOptions',
      'turnPenalty', 'prediction', 'inverseControl', 'smoothing', 'groundSections',
      'groundActivationAfterMs', 'profiles', 'bypass', 'testClearance', 'laneOrder',
      'predictionSections', 'predictionAfterMs', 'forecastIntervalMs', 'cornerProfiles',
      'trafficForecast', 'passingFallback', 'railForecast', 'contactForecast', 'hybridRoute',
      'wholeRaceForecast', 'minimumForecastForwardSpeed',
      'auditedRouteSource', 'projectedRouteSource', 'auditedGeometry',
      'openingPolicy', 'startLane', 'startEnd', 'startLook',
      'centerSections', 'laneBypass', 'laneSchedule', 'openingControls', 'openingCutoff',
      'openingInverse', 'openingOptions', 'policyProfiles', 'slipGain', 'testGroundLine',
      'waypointSchedule']) {
      if (report[key] !== undefined) controls[key] = report[key];
    }
    rows.push({
      report: name, reportSha256: hash(bytes), status: run.status,
      ...(run.error ? { error: run.error } : {}),
      complete: run.status === 'finished' && run.race.finished && run.race.lapCount === 5
        && run.lapEvents.length === 5 && run.race.lapTimes.length === 5
        && run.race.lapTimes.every(Number.isFinite) && run.race.remainingMs > 0,
      physicalLapEvents: run.lapEvents.length, lapTimes: run.race.lapTimes,
      checkpointEvents: run.gateEvents.length, distance: run.race.distance,
      activeElapsedMs: run.activeElapsedMs ?? run.race.elapsedMs, durationMs: run.durationMs,
      rank: run.rank, qualification: run.qualification,
      opening: run.opening ? { greenWallMs: run.opening.greenWallMs,
        firstDriverInputWallMs: run.opening.firstDriverInputWallMs,
        countdownStartWallMs: run.opening.countdownStartWallMs } : null,
      ...(run.authoredBranches ? { authoredBranches: run.authoredBranches } : {}),
      startPolicy: report.startPolicy, testDriverPolicy: report.testDriverPolicy,
      cadenceMs: report.cadenceMs,
      controls, rescue: run.rescue, inputSha256: run.inputSha256,
      ...(run.forecasts ? { forecastDiagnostics: {
        decisions: run.forecasts.length,
        evaluatedCandidates: run.forecasts.reduce((sum, frame) => sum + frame.candidates.length, 0),
        executedPrivateFrames: run.forecasts.flatMap(frame => frame.candidates)
          .reduce((sum, candidate) => sum + candidate.executedFrames, 0),
        scope: 'Private candidate steps only; these are not additional actual race ticks or independent full-race attempts.',
      } } : {}),
      executionDependencies: report.executionDependencies,
      productionFingerprint, assetFingerprint: fingerprint(Object.entries(report.assetSha256).sort()),
      npcVelocitySafetyCorrections: run.events['npc-velocity-safety'] ?? 0,
      ...(run.travel ? { travel: {
        measurement: 'Position differences after each actual 25 ms tick; source contact callback chained without replacing its behavior.',
        contactReferenceScope: 'The diagnostic callback retained firstBody/secondBody as live references until final report serialization. Only the copied event position, sector and timestamps are collision-time pose/time evidence. Body-reference positions, yaw, sector and velocities describe final serialization state and are intentionally omitted here. Body IDs and placement indices identify objects; meshAtSerialization is not a claim about the collision-time animation frame. Contact impulse and type were captured as event scalars.',
        laps: run.travel.laps.map(lap => ({
          travelledMetres: lap.distance / 10, elapsedMs: lap.ticks * 25,
          meanForwardSpeed: lap.forwardSpeedSum / lap.ticks,
          meanAbsoluteLateralSpeed: lap.absLateralSpeedSum / lap.ticks,
          fullSteerFraction: lap.fullSteerTicks / lap.ticks,
        })),
        contacts: run.travel.contacts.map(contact => ({
          activeElapsedMs: contact.activeElapsedMs, wallMs: contact.wallMs,
          nativeNowMs: contact.nowMs, sector: contact.sector,
          contactType: contact.contactType, impulse: contact.impulse,
          playerPositionAtCallback: contact.position,
          ...contactIdentity(contact, 'first'), ...contactIdentity(contact, 'second'),
        })),
      } } : {}),
    });
  }
}
const best = rows.filter(row => row.status !== 'error').sort((a, b) => b.physicalLapEvents - a.physicalLapEvents
  || b.distance - a.distance || a.activeElapsedMs - b.activeElapsedMs)[0];
const inputGroups = Map.groupBy(rows, row => row.inputSha256);
const normalizedContacts = rows.flatMap(row => row.travel?.contacts ?? []);
const result = {
  format: 'superkarts-france-hard-upgrade-reset-attempts-v2',
  generatedAt: new Date().toISOString(),
  scope: 'Retained report rows for ordinary-control France hard time-trial attempts on the corrected constructor-upgrade runtime at the native 25 ms cadence, including shared multi-track reports. The test controllers do not change timers, pickups, poses, velocities, triggers, collisions, or physics tables. Opening versus active-grid scope is recorded per attempt. Earlier runtime and nonproduction-cadence diagnostics are listed separately. Counts include exact replays; repeated input digests are identified rather than counted as independent policies. A harness exception is retained as an error, not evidence of gameplay failure.',
  status: errors.length ? 'audit-errors' : rows.some(row => row.complete) ? 'completed' : 'not-completed',
  productionFingerprint: anchor.productionFingerprint,
  attempts: rows.length, completed: rows.filter(row => row.complete).length,
  outcomes: Object.fromEntries([...Map.groupBy(rows, row => row.status)]
    .map(([status, group]) => [status, group.length])),
  uniqueInputDigests: inputGroups.size,
  repeatedInputDigests: [...inputGroups].filter(([, group]) => group.length > 1)
    .map(([inputSha256, group]) => ({ inputSha256, reports: group.map(row => row.report) })),
  contactDiagnostics: {
    normalizedContacts: normalizedContacts.length,
    serializedBodyIdentities: normalizedContacts.reduce((sum, contact) => sum + ['first', 'second']
      .filter(side => ['BodyId', 'PlacementIndex', 'MeshAtSerialization'].some(key => contact[side + key] !== null)).length, 0),
    poseEvidence: 'playerPositionAtCallback, sector and event timestamps were copied at the callback. Live body references were serialized at run end: their pose/velocity fields are deliberately excluded, and meshAtSerialization labels are not collision-frame proof.',
  },
  currentProductionAndAssetsVerified: errors.length === 0,
  bestOrdering: 'Most physical laps, then greatest native accumulated sector distance, then least active elapsed time. This is furthest progress, not a claim of the fastest individual lap.',
  best, rows, excluded, errors,
};
await fs.writeFile(new URL('france-hard-upgrade-reset-attempts.json', directory), JSON.stringify(result, null, 2) + '\n');
console.log(JSON.stringify({
  status: result.status, attempts: result.attempts, completed: result.completed,
  outcomes: result.outcomes, uniqueInputDigests: result.uniqueInputDigests,
  excluded: excluded.length,
  best: best && { report: best.report, laps: best.physicalLapEvents,
    checkpoints: best.checkpointEvents, distance: best.distance,
    activeElapsedMs: best.activeElapsedMs }, errors,
}, null, 2));
if (errors.length) process.exitCode = 1;
