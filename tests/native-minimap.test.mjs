import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NATIVE_MINIMAP_TRANSFORMS, nativeMinimapPosition, nativeMinimapRacers } from '../source/simulation/native-minimap.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/minimap-fixtures.json',import.meta.url)));
test('all six minimap transform records match original PE bytes exactly',()=>{
  assert.deepEqual(NATIVE_MINIMAP_TRANSFORMS,fixtures.transforms);
});
test('720 original minimap callbacks preserve coordinates and player/NPC order at both precisions',()=>{
  for(const f of fixtures.cases)assert.deepEqual(nativeMinimapRacers(f.track,f.player,f.opponents,f),f.expected);
});
test('160 original minimap orientation operations retain the nonrotational Italy axis swap',()=>{
  for(const f of fixtures.orientations){
    const result=nativeMinimapPosition(0,[f.position[0],0,f.position[1]],{transform:[1,0,1,0,f.orientation]});
    assert.deepEqual(result.slice(0,2),f.expected.slice(0,2));
  }
});
