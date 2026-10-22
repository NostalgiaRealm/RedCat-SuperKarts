import fs from 'node:fs';
import crypto from 'node:crypto';
import {runEnglandTyreFixture} from '../tests/helpers/england-tyre-fixture.mjs';
const hash=file=>crypto.createHash('sha256').update(fs.readFileSync(file)).digest('hex');
const files=['src/race-simulation.js','src/simulation/player-stuck-recovery.js',
  'src/simulation/player-recovery-position.js','src/simulation/native-rescue.js',
  'src/simulation/native-bonus.js',
  'src/simulation/native-motion.js','src/simulation/native-collision.js',
  'tests/helpers/england-tyre-fixture.mjs','tests/player-recovery-integration.test.mjs',
  'tools/diagnose-england-tyre-recovery.mjs','public/assets/tracks/etappe2.json',
  'public/assets/cars.json','public/assets/physics/phys0.dat'];
const hashes=Object.fromEntries(files.map(file=>[file,hash(file)]));
const report={scope:'Original England tyre230 regression, software simulation, 25ms updates.',
  sourceAndAssetHashes:hashes,runs:[0,1,2,3].map(runEnglandTyreFixture)};
report.changedDuringRun=files.filter(file=>hash(file)!==hashes[file]);
fs.mkdirSync('evidence/player-recovery',{recursive:true});
fs.writeFileSync('evidence/player-recovery/england-tyre.json',JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({changedDuringRun:report.changedDuringRun,runs:report.runs.map(r=>({
  mode:r.raceMode,detectedAt:r.detectedAt,finishedAt:r.finishedAt,recoveries:r.recoveries,
  relocation:r.relocations[0],final:r.final,voices:r.voiceRequests}))},null,2));
