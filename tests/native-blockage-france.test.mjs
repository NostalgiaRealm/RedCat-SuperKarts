import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeRescuePositionFree} from '../source/simulation/native-rescue.js';
import {nativeRectangleOverlap} from '../source/simulation/native-collision.js';

const fixture=JSON.parse(fs.readFileSync(new URL(
  '../evidence/race-completion/france-native-rescue-overlap.json',import.meta.url)));

test('captured France return is accepted by native clearance despite two directed rectangle overlaps',()=>{
  const {actors,destination}=fixture.input,player=actors.at(-1),other=actors[3];
  assert.equal(nativeRescuePositionFree(player,destination,actors),fixture.nativePositionFree);
  const rectangle=body=>({...body.bounds,position:body.position,angle:Math.trunc(body.yaw)});
  const a=rectangle(player),b=rectangle(other);
  assert.deepEqual([nativeRectangleOverlap(a,b),nativeRectangleOverlap(b,a)],
    fixture.nativeDirectedRectangleOverlaps);
});
