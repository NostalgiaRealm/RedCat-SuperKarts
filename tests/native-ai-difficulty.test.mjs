import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { parseRacerTable, applyNativeRaceTypeTable } from '../source/simulation/native-tables.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/ai-difficulty-fixtures.json',import.meta.url)));
const tables=Array.from({length:3},(_,i)=>parseRacerTable(new Uint8Array(readFileSync(new URL(`../public/assets/racer-tables/cars${i}.dat`,import.meta.url)))));
test('original duel-race difficulty modifier changes precisely the first ten records of each shipped table',()=>{
  for(const f of fixtures.cases){
    const table=applyNativeRaceTypeTable(tables[f.difficulty],{raceType:3,difficulty:f.difficulty});
    assert.deepEqual(table.map(record=>record.raw),f.expected);
    assert.deepEqual(table.slice(10),tables[f.difficulty].slice(10));
    for(const record of table){
      assert.deepEqual(record.acceleration,record.raw.slice(6,12));
      assert.deepEqual(record.maxSpeed,record.raw.slice(18,24));
      assert.equal(record.steerSpeed,record.raw[30]);
    }
  }
});
test('race-type modification does not accumulate across restarts or mutate other modes',()=>{
  const before=structuredClone(tables);
  for(let difficulty=0;difficulty<3;difficulty++){
    for(const raceType of [0,1,2,4,5]){
      assert.deepEqual(applyNativeRaceTypeTable(tables[difficulty],{raceType,difficulty}),tables[difficulty]);
    }
    assert.deepEqual(applyNativeRaceTypeTable(tables[difficulty],{raceType:3,difficulty}),
      applyNativeRaceTypeTable(tables[difficulty],{raceType:3,difficulty}));
  }
  assert.deepEqual(tables,before);
});
