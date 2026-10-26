import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeRandom} from '../source/simulation/native-random.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/startup-random-fixtures.json',import.meta.url)));
test('Native window seconds seed is replaced by tick seed after construction',()=>{
 for(const c of fixture.cases){
  const random=new NativeRandom(c.seconds);
  assert.equal(random.state,c.constructionSeed);
  assert.deepEqual(Array.from({length:c.constructionDraws},()=>random.next()),c.constructionValues);
  random.seed(c.tickMs);
  assert.equal(random.state,c.raceSeed);
  for(const action of c.actions)assert.equal(action.randomState,random.state);
  assert.equal(c.actions.find(action=>action.address==='0042f740').phase,1);
  assert.deepEqual(Array.from({length:16},()=>random.next()),c.raceValues);
  assert.equal(random.state,c.finalState);
 }
});
