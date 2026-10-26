import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {updateNativeRankings} from '../source/simulation/native-rank.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/rank-fixtures.json',import.meta.url)));
test('all native ranks and ordered overtake callbacks match original instruction execution',()=>{
  for(const [i,c]of fixture.cases.entries()){
    const actors=structuredClone(c.actors),events=updateNativeRankings(actors);
    assert.deepEqual(actors.map(actor=>actor.rank),c.ranks,`case ${i} ranks`);
    assert.deepEqual(events,c.events,`case ${i} overtake callbacks`);
  }
});
