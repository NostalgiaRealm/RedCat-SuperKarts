import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {nativeBonusVisual} from '../src/simulation/native-bonus.js';
const read=path=>JSON.parse(readFileSync(new URL(path,import.meta.url)));
const fixture=read('../evidence/native/bonus-visual-fixtures.json');
const config=read('../public/assets/config.json'),manifest=read('../public/assets/manifest.json');

test('original bonus mesh selection uses level offsets, with fixed projectile frames',()=>{
  for(const row of fixture.cases){
    const visual=nativeBonusVisual(config,manifest,row.type,row.level,row.kind);
    assert.deepEqual({frame:visual.frame,mesh:visual.mesh,texture:visual.texture},
      {frame:row.frame,mesh:row.mesh,texture:row.texture});
    if(row.updates){
      assert.equal(row.updates.length,80);
      assert.equal(new Set(row.updates.map(v=>`${v.meshId}:${v.textureId}`)).size,1);
      assert.ok(row.updates.at(-1).age>row.updates[0].age);
    }
  }
});
