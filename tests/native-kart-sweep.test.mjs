import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeRailCollision} from '../source/simulation/native-collision.js';

const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/kart-sweep-fixtures.json',import.meta.url)));
const exact=(actual,expected,label)=>assert.ok(Object.is(actual,expected),`${label}: ${actual} != ${expected}`);
for(const precision of [24,53])test(`dynamic sweeps, rails, paired contact order and player slide match original x86 exactly (${precision}-bit)`,()=>{
  const cases=fixture.cases.filter(c=>c.precision===precision);
  assert.ok(cases.some(c=>c.body.yawRate===0)&&cases.some(c=>c.rails));
  for(const c of cases){
    const index=fixture.cases.indexOf(c);
    // 0x499b20 lists the previous/current/next sector rails before objects.
    const track={collision:[],route:Array.from({length:50},(_,sector)=>({
      collisionIndices:sector===0&&c.rails?c.rails.map((_,k)=>k):[]}))};
    const bodies=[c.body,...c.others].map(body=>({...structuredClone(body),
      get x(){return this.position[0]},get y(){return this.position[1]},get z(){return this.position[2]}}));
    const collision=new NativeRailCollision(track,c.bounds,{precision:c.precision});
    if(c.rails)collision.rails=structuredClone(c.rails);
    collision.bodies=bodies;
    const actual=collision.sample(bodies[0],c.dt),expected=c.expected;
    exact(actual.fraction,expected.fraction,`${index}:fraction`);
    assert.equal(actual.stopYaw,expected.stopYaw,`${index}:stopYaw`);
    assert.equal(Boolean(actual.contact),Boolean(expected.contact),`${index}:contact`);
    if(expected.contact){
      // 0x49c540: a rail record leaves 0x6a5b5c=0, first=moving id, second=0.
      if(expected.contact.dynamic===false){
        assert.equal(actual.contact.firstBody,undefined,`${index}:static first`);
        assert.equal(actual.contact.secondBody,undefined,`${index}:static second`);
        assert.deepEqual([expected.contact.first,expected.contact.second],[0,0],`${index}:static ids`);
      }else{
        assert.equal(bodies.indexOf(actual.contact.firstBody),expected.contact.first,`${index}:first`);
        assert.equal(bodies.indexOf(actual.contact.secondBody),expected.contact.second,`${index}:second`);
      }
      for(const key of ['point','normal'])actual.contact[key].forEach((v,i)=>exact(v,expected.contact[key][i],`${index}:${key}:${i}`));
    }
    assert.equal(Boolean(actual.velocityOverride),Boolean(expected.velocityOverride),`${index}:slide`);
    actual.velocityOverride?.forEach((v,i)=>exact(v,expected.velocityOverride[i],`${index}:slide:${i}`));
  }
});
