import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeQuitRequester} from '../source/native-quit-requester.js';
import {createRaceQuitRequester} from '../source/race-requester.js';
const fixture=JSON.parse(readFileSync(new URL('../evidence/native/quit-requester-fixtures.json',import.meta.url)));
const keys=JSON.parse(readFileSync(new URL('../evidence/native/race-lifecycle-fixtures.json',import.meta.url))).quitKeys;

test('15 original requester traces preserve chosen art, click and exactly100ms unsigned delay',()=>{
  for(const {choice,epoch,trace} of fixture.traces){
    const controller=new NativeQuitRequester();controller.update({},epoch);
    assert.equal(controller.choose(choice,epoch),true);
    for(const frame of trace){
      const state=controller.update({},frame.nowMs);
      assert.equal(state.done,frame.returned);
      assert.equal(state.pressed,state.done?null:([0,2].includes(choice)?'yes':'no'));
      const draw=frame.events.find(e=>e.type==='draw');
      assert.equal(draw.args[1],[0,2].includes(choice)?7:10);
      assert.equal(frame.events.filter(e=>e.type==='sound').length,1);
      assert.equal(frame.events[0].name,'click4.wav');
    }
  }
});

test('original keyboard priority and release loop precede the100ms pressed phase',()=>{
  for(const sample of keys){
    const c=new NativeQuitRequester();c.update({},1000);
    assert.equal(c.update(new Set(sample.keys),1010).stage,'key-release');
    assert.equal(c.update(new Set(sample.keys),9999).startedMs,null);
    assert.equal(c.choose(3,9999),false);
    const released=c.update({},10000);
    assert.equal(released.code,sample.code);assert.equal(released.stage,'pressed');
    assert.equal(c.update({},10099).done,false);
    assert.equal(c.update({},10100).done,true);
  }
  const c=new NativeQuitRequester();
  assert.equal(c.update({Escape:true},10).stage,'initial-release');
  assert.equal(c.choose(2,15),false);
  assert.equal(c.update({Y:true,Shift:true,J:true},20).stage,'input');
  assert.equal(c.update({Y:true},30).stage,'input');
  assert.equal(c.update({J:true},40).stage,'key-release');
  // Holding Shift makes the original unmodified key poll report released.
  assert.equal(c.update({J:true,Shift:true},50).stage,'pressed');
});

class FakeElement {
  constructor(tag){this.tagName=tag;this.dataset={};this.style={};this.children=[];this.attributes={};}
  append(...children){this.children.push(...children);}
  setAttribute(name,value){this.attributes[name]=value;}
  focus(){this.focused=true;}
}

test('DOM pressed state and single sound/commit survive repeated pointer, click and direct choices',()=>{
  const originalDocument=globalThis.document;
  globalThis.document={createElement:tag=>new FakeElement(tag)};
  try{
    const config=JSON.parse(readFileSync(new URL('../public/assets/config.json',import.meta.url)));
    const manifest=JSON.parse(readFileSync(new URL('../public/assets/manifest.json',import.meta.url)));
    let time=1000;const log=[];
    const wrap=createRaceQuitRequester(config,manifest,code=>log.push(['choice',code,time]),
      {onPress:code=>log.push(['press',code,time]),now:()=>time});
    const stage=wrap.children[0],[yes,no]=stage.children;
    wrap.update({});
    let prevented=false;
    yes.onpointerdown({button:2,preventDefault(){throw new Error('right-click must not activate');}});
    assert.deepEqual(log,[]);
    yes.onpointerdown({button:0,preventDefault(){prevented=true;}});
    assert.equal(prevented,true);assert.equal(wrap.pending,true);
    assert.equal(stage.dataset.state,'pressed');assert.equal(yes.dataset.pressed,'true');
    assert.equal(no.dataset.pressed,'false');assert.deepEqual(log,[['press',2,1000]]);
    no.onclick();yes.onclick();wrap.choose(3);
    time=1099;wrap.update({N:true});assert.equal(log.length,1);
    time=1100;wrap.update({N:true});
    assert.deepEqual(log,[['press',2,1000],['choice',2,1100]]);
    time=5000;wrap.update({});no.onclick();assert.equal(log.length,2);
    assert.equal(yes.dataset.pressed,'false');assert.equal(wrap.stage,'done');
    assert.match(yes.style.cssText,/ja_i/);assert.match(no.style.cssText,/nee_i/);
  }finally{globalThis.document=originalDocument;}
});

test('keyboard No/Escape and host controller activation share the same pending callbacks',()=>{
  const originalDocument=globalThis.document;
  globalThis.document={createElement:tag=>new FakeElement(tag)};
  try{
    const config=JSON.parse(readFileSync(new URL('../public/assets/config.json',import.meta.url)));
    const manifest=JSON.parse(readFileSync(new URL('../public/assets/manifest.json',import.meta.url)));
    for(const activation of ['N','Escape','controller']){
      let time=0;const events=[];
      const wrap=createRaceQuitRequester(config,manifest,code=>events.push(['choice',code]),
        {onPress:code=>events.push(['press',code]),now:()=>time});
      wrap.update({});
      if(activation==='controller')wrap.children[0].children[1].onclick();
      else{
        wrap.update({[activation]:true});assert.deepEqual(events,[]);
        time=500;wrap.update({[activation]:true});assert.deepEqual(events,[]);
        time=600;wrap.update({});
      }
      const start=time;
      assert.equal(events.length,1);
      assert.equal(wrap.children[0].children[1].dataset.pressed,'true');
      time=start+99;wrap.update({});assert.equal(events.length,1);
      time=start+100;wrap.update({});assert.equal(events.length,2);
      assert.equal(events[0][0],'press');assert.equal(events[1][0],'choice');
      assert.equal(events[0][1],activation==='controller'?3:1);
    }
  }finally{globalThis.document=originalDocument;}
});
