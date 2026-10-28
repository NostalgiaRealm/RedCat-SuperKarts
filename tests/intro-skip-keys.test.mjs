import test from 'node:test';
import assert from 'node:assert/strict';
import {nativeIntroSkipKey} from '../source/input.js';

const key=(key,{altKey=false,altGraph=false,ctrlKey=false}={})=>({key,altKey,ctrlKey,
  getModifierState:name=>name==='AltGraph'&&altGraph});

test('0x479cd4 intro skip follows typed-character key presses, not arrow or Alt keys',()=>{
  for(const name of ['a','Z','1',' ','@','Enter','Escape','Backspace'])assert.equal(nativeIntroSkipKey(key(name)),true,name);
  for(const name of ['ArrowUp','ArrowDown','ArrowLeft','ArrowRight','Shift','Control','Alt','F1','Delete','Home','Dead','Tab'])
    assert.equal(nativeIntroSkipKey(key(name)),false,name);
  // Ctrl+letter types a control character; Alt+key is a system key press.
  assert.equal(nativeIntroSkipKey(key('a',{ctrlKey:true})),true);
  assert.equal(nativeIntroSkipKey(key('a',{altKey:true})),false);
  assert.equal(nativeIntroSkipKey(key('Enter',{altKey:true})),false);
  // AltGr reports Alt but still types characters such as @ or €.
  assert.equal(nativeIntroSkipKey(key('€',{altKey:true,ctrlKey:true,altGraph:true})),true);
});
