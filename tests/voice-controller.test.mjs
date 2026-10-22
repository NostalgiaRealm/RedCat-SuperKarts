import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeVoiceController} from '../src/native-voice-controller.js';
const read=path=>JSON.parse(fs.readFileSync(new URL(path,import.meta.url)));
const config=read('../public/assets/config.json'),manifest=read('../public/assets/manifest.json');
const fixture=read('../evidence/native/voice-queue-fixtures.json');
test('600 original voice updates preserve FIFO, current-sample gate, and one dequeue per tick',()=>{
 const controller=new NativeVoiceController(config,manifest,[4,5,6,7,0]);
 for(const [index,row]of fixture.rows.entries()){
  controller.voices[10]={current:row.input.current,queue:[...row.input.queue]};
  const selected=controller.advanceVoice(10,()=>row.input.playing);
  assert.deepEqual(controller.voices[10],{current:row.current,queue:row.queue},String(index));
  assert.deepEqual(selected?[controller.banks[10].indexOf(selected)]:[],row.spatial,String(index));
 }
});
test('original logical names resolve only loaded banks; replace stops and clears before disabled enqueue',()=>{
 const c=new NativeVoiceController(config,manifest,[4,5,6,7,0]);
 assert.equal(c.request({voiceId:0,sample:'BONUS0'}).accepted,true);
 assert.equal(c.request({voiceId:0,sample:'CLAXON'}).accepted,false);
 assert.equal(c.request({voiceId:1,sample:'BONUS0'}).accepted,false);
 c.advanceVoice(0,()=>false);c.request({voiceId:0,sample:'BONUS1'});
 c.enabled=false;
 const replaced=c.request({voiceId:0,sample:'BONUS2',replace:true});
 assert.deepEqual(replaced,{accepted:true,commands:[{event:'RCBONUS0',op:'stop'}]});
 assert.deepEqual(c.voices[0],{current:-1,queue:[]});
});
