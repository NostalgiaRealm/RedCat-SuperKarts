import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {calculateNativePlayerForces} from '../src/simulation/native-player.js';
import {parsePhysicsTable} from '../src/simulation/native-tables.js';
import {nativeRacePlayerOptions,nativeMenuOpponentCount} from '../src/simulation/native-race-options.js';
const read=name=>JSON.parse(readFileSync(new URL(`../${name}`,import.meta.url)));
const fixtures=read('evidence/native/player-phase-fixtures.json');
const inventory=read('evidence/gameplay/inventory.json');
const tables=[0,1,2].map(i=>{
  const table=inventory.binaryTables.find(t=>t.source===`Phys${i}.dat`);
  const bytes=new Uint8Array(table.bytes),view=new DataView(bytes.buffer);
  for(const record of table.records)record.uint32.forEach((value,n)=>view.setUint32(record.offset+n*4,value,true));
  return parsePhysicsTable(bytes);
});
test('720 complete original player force calls include result-phase braking and exact slip intensity',()=>{
  for(const [i,c] of fixtures.cases.entries()){
    const body={...c.body},controls={throttle:c.throttle,brake:c.brake,steering:c.steering,handbrake:c.handbrake};
    const force=calculateNativePlayerForces(body,tables[c.preset][c.record],controls,.025,c);
    const actual={...body,...force,handbrake:controls.handbrake};
    for(const [key,value] of Object.entries(c.expected)){
      assert.ok(actual[key]===value,`${i}/${key}: ${actual[key]} != ${value}`);
    }
    assert.equal(controls.throttle,c.throttle,'source force arguments do not overwrite retained throttle');
    assert.equal(controls.brake,c.brake);
  }
});
test('Raw INI upgrades and shipped menu opponent-count table are distinct from difficulty',()=>{
  const config=read('public/assets/config.json');
  assert.deepEqual(nativeRacePlayerOptions(config),{motorUpgrade:1,tireUpgrade:1,gearboxUpgrade:1});
  assert.deepEqual([0,1,2,3].map(nativeMenuOpponentCount),[4,3,3,1]);
  for(const difficulty of [0,1,2]){
    const copy=structuredClone(config);copy['game.ini'].options.difficulty=String(difficulty);
    assert.deepEqual(nativeRacePlayerOptions(copy),nativeRacePlayerOptions(config));
  }
});
