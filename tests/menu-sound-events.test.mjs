import {readFile} from 'node:fs/promises';
import assert from 'node:assert/strict';
import {test} from 'node:test';
import {nativeMenuNavigationSound,nativeMenuRaceModeSound,nativeCountryInfoSound,nativeMenuBindingKey} from '../src/menu-sound-events.js';
const fixture=JSON.parse(await readFile(new URL('../evidence/native/menu-audio-fixtures.json',import.meta.url)));

test('original shell navigation, race announcements and all country narrations',()=>{
  for(const row of fixture.navigation){
    const blocked=row.direction>0?row.index===row.maximum:row.index===0;
    assert.deepEqual(blocked?null:{bank:'generic',sample:nativeMenuNavigationSound(row.direction),wait:true},row.expected);
  }
  for(const row of fixture.modes)
    assert.deepEqual({bank:'character',character:row.character,sample:nativeMenuRaceModeSound(row.mode),wait:false},row.expected);
  for(const row of fixture.countryInfo)
    assert.deepEqual({bank:'generic',sample:nativeCountryInfoSound(row.country,row.photo),wait:false},row.expected);
  for(const row of fixture.bindingKeys)
    assert.equal(nativeMenuBindingKey(row.keyCode),row.expected,`original key ${row.keyCode}`);
});
