import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeDisplayControls,nativeDisplayValues,nativeDisplayFields} from '../source/native-display-settings.js';
import {normalizeSettings,DEFAULT_DISPLAY_SETTINGS} from '../source/settings.js';
const fixtures=JSON.parse(fs.readFileSync(new URL('../evidence/native/display-dialog-fixtures.json',import.meta.url)));
test('48 original advanced display init, cancel and commit cases preserve inverse checkbox semantics',()=>{
  for(const row of fixtures.cases){
    const controls=nativeDisplayControls(row.values);
    for(const [key,value]of Object.entries(controls))assert.equal(value,row.initialControls[key]);
    assert.deepEqual(nativeDisplayFields(row.values),row.before);
    assert.deepEqual(row.cancel,row.before);
    const edited=Object.fromEntries(Object.entries(controls).map(([key,value])=>[key,!value]));
    assert.deepEqual(nativeDisplayFields(nativeDisplayValues(edited)),row.committed);
  }
});
test('display defaults and explicit disabled settings survive normalization',()=>{
  assert.deepEqual(normalizeSettings().display,DEFAULT_DISPLAY_SETTINGS);
  for(const row of fixtures.cases)assert.deepEqual(normalizeSettings({display:row.values}).display,row.values);
  assert.equal(normalizeSettings({bindings:{accelerate:''}}).bindings.accelerate,'');
});
