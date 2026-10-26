import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeControlDraft,NATIVE_CONTROL_ACTIONS,NATIVE_DEFAULT_KEYS,nativeBindingImage,
  browserBindingCode,nativeOptionsDraft,commitNativeOptions,nativeShowsStartInfo} from '../source/native-control-settings.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/menu-settings-fixtures.json',import.meta.url)));
const bindings=Object.fromEntries(NATIVE_CONTROL_ACTIONS.map((action,i)=>[action,browserBindingCode(NATIVE_DEFAULT_KEYS[i])]));
test('90 original keyboard capture traces preserve clear, duplicate, rejection and Escape behavior',()=>{
  for(const row of fixture.capture){
    const draft=new NativeControlDraft(bindings);
    assert.equal(draft.begin(row.action),true);
    assert.deepEqual(draft.keys,row.before.keys);
    assert.equal(draft.capture!==null,row.before.capture);
    const result=draft.release(row.key);
    assert.deepEqual(draft.keys,row.after.keys);
    assert.equal(draft.capture!==null,row.after.capture);
    assert.equal(draft.capture===null,row.after.enabled);
    assert.deepEqual(result.samples,row.after.events.filter(event=>event[0]==='sound').map(event=>event[1]));
    assert.equal(result.decision==='duplicate',row.after.events.some(event=>event[0]==='duplicateWarning'));
  }
});
test('12 original control commits/cancels and96 key artwork selections',()=>{
  for(const row of fixture.transactions){
    const draft=new NativeControlDraft(bindings);draft.keys[row.action]=113;
    row.finish==='ok'?draft.commit():draft.cancel();
    assert.deepEqual(draft.keys,row.keys);assert.deepEqual(draft.saved,row.saved);
  }
  for(const row of fixture.images)
    assert.equal(nativeBindingImage(row.action,row.key,row.capture),row.image);
});
test('six original options commits and Back cancellations retain separate draft state',()=>{
  for(const row of fixture.options){
    const settings={controlType:0,resolution:'640x480',music:1,effects:1,startInfo:true,bindings};
    const draft=nativeOptionsDraft(settings);
    Object.assign(draft,{controlType:2,resolution:'800x600',music:row.volume/100,effects:row.volume/100,startInfo:false});
    const actual=row.finish==='ok'?commitNativeOptions(settings,draft):settings;
    assert.equal(actual.controlType,row.controlType);
    assert.equal(actual.music*100,row.music);assert.equal(actual.effects*100,row.effects);
    assert.equal(actual.startInfo,row.startInfo);
    assert.equal(actual.resolution,row.resolutionCode===3?'640x480':'800x600');
    assert.equal(actual.bindings,bindings);
  }
});
test('12 original QuickRace and Adventure start-info gates only show keyboard controls',()=>{
  for(const row of fixture.startInfo)assert.equal(nativeShowsStartInfo(row),row.shown);
});
