import test from 'node:test';
import assert from 'node:assert/strict';
import {runEnglandTyreFixture} from './helpers/england-tyre-fixture.mjs';

for(const mode of [0,1,2,3])test(`England tyre contact automatically rescues and resumes (race mode ${mode})`,()=>{
  const r=runEnglandTyreFixture(mode);
  assert.equal(r.ground.kind,'road');
  assert.equal(r.startClear,true);
  assert.ok(r.contacts.some(c=>c.placementIndex===230&&c.mesh==='banden00.d3d'));
  assert.equal(r.recoveries,1);
  assert.ok(r.detectedAt>=8000&&r.detectedAt<12000);
  assert.equal(r.rescueFrames.length,40);
  assert.ok(r.rescueFrames.some(f=>f.shrinking&&f.scale<1));
  assert.equal(r.relocations.length,1);
  const relocation=r.relocations[0];
  assert.equal(relocation.clear,true);
  assert.equal(relocation.occupancyCount,1);
  assert.equal(relocation.occupancyWaypoint,relocation.bodyWaypoint);
  assert.equal(relocation.bodyPreviousSector,relocation.destination.sector);
  assert.equal(relocation.racePreviousSector,relocation.destination.sector);
  assert.equal(relocation.after.lapCount,relocation.before.lapCount);
  assert.equal(relocation.after.gateIndex,relocation.before.gateIndex);
  assert.equal(relocation.after.gateDeadlineMs,relocation.before.gateDeadlineMs);
  assert.equal(relocation.after.stars,relocation.before.stars);
  assert.ok(relocation.after.distance<=relocation.before.distance);
  assert.ok(relocation.after.elapsedMs>=relocation.before.elapsedMs);
  assert.equal(relocation.followingFrame.progress.distance,relocation.after.distance);
  assert.deepEqual(relocation.followingFrame.events,[]);
  assert.deepEqual(r.voiceRequests.filter(v=>v.voiceId===r.playerVoiceId).map(v=>v.sample),['DISAPP','REAPP']);
  assert.equal(r.activeRescue,false);
  assert.ok(r.finishedAt);
  assert.ok(Math.hypot(r.final.position[0]-relocation.destination.position[0],
    r.final.position[2]-relocation.destination.position[2])>100);
  assert.ok(r.final.forwardSpeed>5);
  assert.equal(r.progress.lapCount,0);
});
