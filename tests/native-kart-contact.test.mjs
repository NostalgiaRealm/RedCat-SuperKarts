import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {applyNativeKartContact} from '../source/simulation/native-kart-contact.js';

const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/kart-contact-fixtures.json',import.meta.url)));
test('kart-to-kart impulse matches original instructions at both x87 precisions',()=>{
  const {absolute,relative}=fixture.tolerance;
  const near=(actual,expected,label)=>assert.ok(
    Math.abs(actual-expected)<=absolute+relative*Math.abs(expected),
    `${label}: ${actual} != ${expected}`);
  for(const [index,c]of fixture.cases.entries()){
    const actors=structuredClone(c.actors);
    const result=applyNativeKartContact(...actors,c.contact,{precision:c.precision});
    near(result.impulse,c.impulse,`${index}:impulse`);
    c.expected.forEach((expected,actor)=>Object.entries(expected).forEach(([key,value])=>
      near(actors[actor][key],value,`${index}:${actor}:${key}`)));
  }
});
