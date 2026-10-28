import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {applyNativeKartContact} from '../source/simulation/native-kart-contact.js';

const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/kart-contact-fixtures.json',import.meta.url)));
test('kart-to-kart impulse matches original instructions exactly at both x87 precisions',()=>{
  // The fixture's tolerance field predates the exact 53-bit path; it is unused.
  for(const [index,c]of fixture.cases.entries()){
    const actors=structuredClone(c.actors);
    const result=applyNativeKartContact(...actors,c.contact,{precision:c.precision});
    assert.equal(result.impulse,c.impulse,`${index}:impulse`);
    c.expected.forEach((expected,actor)=>Object.entries(expected).forEach(([key,value])=>
      assert.equal(actors[actor][key],value,`${index}:${actor}:${key}`)));
  }
});
