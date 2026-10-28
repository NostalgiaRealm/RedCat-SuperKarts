import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeRailCollision} from '../source/simulation/native-collision.js';

const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/gameplay/native-live-contact-fixtures.json',import.meta.url)));
const exact=(actual,expected,label)=>assert.ok(Object.is(actual,expected),`${label}: ${actual} != ${expected}`);
for(const precision of [24,53])test(`original sweeps reproduce the captured France contact and signed velocity variants exactly (${precision}-bit)`,()=>{
  const cases=fixture.cases.filter(c=>c.precision===precision);
  assert.equal(cases.length,8);
  const track={collision:[],route:Array.from({length:187},()=>({collisionIndices:[]}))};
  for(const c of cases){
    const index=fixture.cases.indexOf(c);
    const bodies=[c.body,...c.others].map(body=>({...structuredClone(body),
      get x(){return this.position[0]},get y(){return this.position[1]},get z(){return this.position[2]}}));
    const collision=new NativeRailCollision(track,c.bounds,{precision:c.precision});
    collision.bodies=bodies;
    const actual=collision.sample(bodies[0],c.dt),expected=c.expected;
    exact(actual.fraction,expected.fraction,`${index}:fraction`);
    assert.equal(actual.stopYaw,expected.stopYaw,`${index}:stopYaw`);
    assert.equal(Boolean(actual.contact),Boolean(expected.contact),`${index}:contact`);
    if(expected.contact){
      assert.equal(bodies.indexOf(actual.contact.firstBody),expected.contact.first,`${index}:first`);
      assert.equal(bodies.indexOf(actual.contact.secondBody),expected.contact.second,`${index}:second`);
      for(const key of ['point','normal'])actual.contact[key].forEach((v,i)=>exact(v,expected.contact[key][i],`${index}:${key}:${i}`));
    }
    assert.equal(Boolean(actual.velocityOverride),Boolean(expected.velocityOverride),`${index}:slide`);
    actual.velocityOverride?.forEach((v,i)=>exact(v,expected.velocityOverride[i],`${index}:slide:${i}`));
  }
});
