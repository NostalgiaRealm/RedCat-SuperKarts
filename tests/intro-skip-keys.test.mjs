import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {nativeIntroSkipKey} from '../source/input.js';

const key=(key,{altKey=false,altGraph=false,ctrlKey=false,shiftKey=false}={})=>({key,altKey,ctrlKey,shiftKey,
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

// rcskmenu.dat bytes, mapped through the PE section table.
const menu=await readFile(new URL('../original-source/inputs/rcskmenu.dat',import.meta.url));
function bytes(address,length){
  const pe=menu.readUInt32LE(0x3c),sections=menu.readUInt16LE(pe+6),table=pe+24+menu.readUInt16LE(pe+20);
  const rva=address-menu.readUInt32LE(pe+52);
  for(let i=0;i<sections;i++){
    const s=table+i*40,va=menu.readUInt32LE(s+12),size=menu.readUInt32LE(s+16),raw=menu.readUInt32LE(s+20);
    if(rva>=va&&rva+length<=va+size)return menu.subarray(raw+rva-va,raw+rva-va+length).toString('hex');
  }
  throw Error('Address outside the PE image');
}

test('Tab is a VCL dialog key that never reaches the intro OnKeyPress',()=>{
  for(const options of [{},{shiftKey:true},{ctrlKey:true}])assert.equal(nativeIntroSkipKey(key('Tab',options)),false);
  // ProcessMessage 0x432150: IsKeyMsg 0x431ffc returning true skips
  // TranslateMessage 0x4321cd, so no WM_CHAR is generated.
  assert.equal(bytes(0x4321a9,0x2f),'e8fefdffff84c0752f8bd78bc6e841feffff84c075228bd78bc6e8c0fdffff84c07515'+
    '57e8a649fdff57e89845fdff');
  // IsKeyMsg sends CN_BASE+WM_KEYDOWN (0xbc00) and returns its result.
  assert.equal(bytes(0x432069,0x0f),'8b46040500bc00005055e8204afdff');
  // TWinControl.CNKeyDown 0x444f90 (DMT 0xbd00): VK_TAB selects DLGC_WANTTAB,
  // then CM_DIALOGKEY 0xb005 goes to the parent form; Result stays 1.
  assert.equal(bytes(0x444fdf,0x25),'83e803742983e806741683e804741feb2283c0db83e804720e83e8027410eb13bf02000000');
  assert.equal(bytes(0x44504b,0x17),'0fb74e04ba05b00000e897b5ffff85c0750533c089460c');
  // TCustomForm.CMDialogKey 0x42e414 (DMT slot 0x42801a): without Alt or Ctrl,
  // Tab calls SelectNext (Shift chooses direction) and sets Result to 1.
  assert.equal(bytes(0x42e414,0x59),'53568bf28bd86a12e85784fdff6685c07c7c668b46046683e809740b83c0e46683e8047234eb67'+
    '6a11e83684fdff6685c07c5b6a016a10e82884fdff6685c00f9dc18b93080200008bc3e8e5770100c7460c010000005e5bc3');
  assert.equal(bytes(0x42801a,4),'14e44200');
});
