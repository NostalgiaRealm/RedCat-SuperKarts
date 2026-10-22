import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {createNativeStarHudConfig,getNativeStarHudCommands} from '../src/simulation/native-star-hud.js';
import {getHudMeshSpec,projectNativeHudPoint} from '../src/hud-mesh.js';

const read=name=>JSON.parse(fs.readFileSync(new URL('../'+name,import.meta.url)));
const fixture=read('evidence/native/star-hud-fixtures.json');
const config=read('public/assets/config.json'),manifest=read('public/assets/manifest.json');
const argb=rgba=>((rgba[3]<<24)|(rgba[0]<<16)|(rgba[1]<<8)|rgba[2])>>>0;

test('24 original star creation cases match native ring position, scale, visibility and tint',()=>{
  for(const row of fixture.slots){
    const command=getNativeStarHudCommands(0,{precision:row.precision})[row.index+1];
    const state=command.overrides[command.id];
    assert.deepEqual(state.position,row.position);
    assert.deepEqual(state.scale,row.scale);
    assert.equal(command.visible,row.visible);
    assert.equal(argb(state.rgba),row.argb);
  }
});

test('42 original collected-count transitions preserve first-N colors and twelve-slot maximum',()=>{
  for(const row of fixture.updates){
    const commands=getNativeStarHudCommands(row.count,{precision:row.precision}).slice(1);
    assert.deepEqual(commands.map(command=>argb(command.overrides[command.id].rgba)),row.argb);
    assert.equal(commands.filter(command=>command.variant==='collected').length,row.storedCount);
  }
  assert.throws(()=>getNativeStarHudCommands(-1),RangeError);
  assert.throws(()=>getNativeStarHudCommands(NaN),RangeError);
});

test('original race-mode dispatch shows all thirteen elements only for Sterrenrace',()=>{
  for(const {raceType,createsStars}of fixture.modes){
    const commands=getNativeStarHudCommands(1,{raceType});
    assert.equal(commands.length,13);
    assert.equal(commands[0].id,'starflag');
    assert.equal(commands[0].variant,undefined);
    assert.ok(commands.every(command=>command.visible===createsStars));
    assert.ok(commands.every(command=>command.overrides.stars.visible===createsStars));
  }
});

test('generated definitions preserve original assets and compose through the real HUD transform',()=>{
  const original=structuredClone(config),dynamic=createNativeStarHudConfig(config);
  assert.deepEqual(config,original);
  assert.notEqual(dynamic['overlay.ini'],config['overlay.ini']);
  for(const raceType of [0,1,2,3])for(const count of [0,1,12]){
    for(const command of getNativeStarHudCommands(count,{raceType})){
      const spec=getHudMeshSpec(dynamic,manifest,command.id,{overrides:command.overrides});
      assert.equal(spec.visible,raceType===2);
      assert.equal(spec.texture,'textures/overlay1.tga.png');
      assert.equal(spec.mesh,command.id==='starflag'?'meshes/ovrlvlag.json':'meshes/ovrlster.json');
      if(command.id!=='starflag')assert.deepEqual(spec.rgba,command.overrides[command.id].rgba);
      if(command.id==='star1'){
        const [x,y]=projectNativeHudPoint(spec.transform.position);
        assert.ok(Math.abs(x-210)<.2&&Math.abs(y-13.6)<.3,'first star is at top of authored flag circle');
      }
    }
  }
});
