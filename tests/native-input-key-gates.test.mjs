import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {InputState} from '../src/input.js';
import {createNativeInputState,updateNativeInput,updateNativeAnalogInput} from '../src/simulation/native-input.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/gameplay/native-input-key-gates.json',import.meta.url)));
const actions={18:'handbrake',32:'bonus',37:'left',38:'accelerate',39:'right',40:'brake'};

test('mapped keyboard actions follow24 original4b3880 Shift-filtered polls',()=>{
  for(const item of fixture.mappedKeys){
    const state=new InputState();
    state.keys=new Set(item.pressed);
    if(item.pressed.includes(item.code))state.set(`key:${item.code}`,actions[item.code]);
    assert.equal(state.value(actions[item.code]),Number(item.expected),JSON.stringify(item));
  }
});

test('Shift release resumes held keyboard controls without suppressing touch or joystick inputs',()=>{
  const state=new InputState();
  state.set('key:ArrowUp','accelerate');
  assert.equal(state.snapshot().throttle,1);
  state.keys.add(16);
  assert.equal(state.snapshot().throttle,0);
  state.set('pointer:1','accelerate',.5);
  state.set('pad:handbrake','handbrake');
  assert.equal(state.snapshot().throttle,.5);
  assert.equal(state.snapshot().handbrake,1);
  state.keys.delete(16);
  assert.equal(state.snapshot().throttle,1);
});

test('original keyboard and analog handlers do not inherit the digital-joystick Space shortcut',()=>{
  for(const item of fixture.handbrake){
    if(item.device===2)continue;
    const state=createNativeInputState();
    if(item.device===1)updateNativeInput(state,{handbrake:item.mapped},.025);
    else updateNativeAnalogInput(state,{x:50,y:50,buttonMask:item.mapped?32:0});
    assert.equal(state.handbrake,item.expected,JSON.stringify(item));
  }
  // Retain the source distinction explicitly: this WinMM digital mode is not
  // the browser's standard-gamepad analog adapter.
  for(const item of fixture.handbrake.filter(item=>item.device===2))
    assert.equal(item.expected,item.mapped||(item.space&&!item.shift));
});
