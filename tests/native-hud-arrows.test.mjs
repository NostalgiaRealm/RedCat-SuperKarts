import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeHudArrows,NATIVE_ARROW_ALPHA} from '../source/simulation/native-hud-arrows.js';
import {NativeRaceState} from '../source/simulation/native-race.js';

const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/hud-arrows-fixtures.json',import.meta.url)));
test('Original arrow state, visibility and tint match both x87 precision captures',()=>{
  for(const trace of fixtures.traces){
    const controller=new NativeHudArrows({precision:trace.precision});
    for(const [index,frame] of trace.frames.entries()){
      const commands=controller[frame.method](frame.input),label=`${trace.name}/${trace.precision}/${index}`;
      assert.deepEqual(controller.state,frame.state,label);
      assert.deepEqual(commands.map(command=>({visible:command.visible,
        argb:command.overrides[command.id].rgba.reduce((value,component,i)=>
          (value|(component<<[16,8,0,24][i]))>>>0,0)})),frame.elements,label);
    }
  }
});
test('Arrow palette preserves original limited peak, initial hiding and authored RGB',()=>{
  assert.deepEqual(NATIVE_ARROW_ALPHA,[0,18,36,54,72,91,109,127,145,163,182,200,218,236]);
  const arrows=new NativeHudArrows({backRgba:[12,34,56,255]});
  assert(arrows.commands().every(command=>!command.visible));
  arrows.update({forward:false,nowSeconds:0,deltaSeconds:.025});
  arrows.update({forward:false,nowSeconds:100,deltaSeconds:.1});
  assert.equal(arrows.state.alphaStep,1,'A long stall advances only one step');
  assert.deepEqual(arrows.commands()[0].overrides.backarrow.rgba,[12,34,56,18]);
});
test('Junction marker54 emits original player-only notification9 in every race mode',()=>{
  assert.deepEqual(fixtures.junctionTriggers.map(({event})=>event),[0xffffffff,9,0xffffffff]);
  for(const raceType of [0,1,2,3]){
    const race=new NativeRaceState({track:{route:[{},{}]},startSector:0,raceType,
      lapLimit:5,lapTimerLimitMs:999999,gateTimes:[10000,10000]});
    race.trigger(54,{player:false});assert.deepEqual(race.events,[]);
    race.trigger(54,{player:true});assert.deepEqual(race.events,[{type:'native-notification',id:9}]);
  }
});
