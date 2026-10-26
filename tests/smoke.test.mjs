import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeSmoke} from '../source/simulation/native-smoke.js';
import {NativeRandom} from '../source/simulation/native-random.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/smoke-fixtures.json',import.meta.url)));
test('native smoke emission,random,all70slot sort,geometry,growth,drag,fade andexpiry',()=>{
 for(const trace of fixture.traces){
  const random=new NativeRandom(trace.seed),smoke=new NativeSmoke({random,precision:trace.precision});
  for(const [tick,frame]of trace.frames.entries()){
   const input=frame.input;
   smoke.enabled=input.enabled;smoke.hardware=input.hardware;
   if(input.kind==='damage')smoke.emitDamage(input);else smoke.emitSkid(input);
   const drawn=smoke.capture(input);
   const message=`${trace.precision}:${tick}`;
   assert.equal(random.state,frame.randomState,`${message}:random`);
   assert.deepEqual(smoke.clouds.map(cloud=>cloud.id),frame.order,`${message}:order`);
   assert.deepEqual(smoke.clouds.filter(cloud=>cloud.active).map(cloud=>{
    const{id,position,velocity,period,tick,width,height,alpha}=cloud;
    return{id,position,velocity,period,tick,width,height,alpha};
   }),frame.clouds,`${message}:state`);
   assert.deepEqual(drawn.map(cloud=>({id:cloud.id,vertices:cloud.vertices,uv:cloud.uv,
    argb:Array.from({length:6},(_,i)=>((cloud.rgba[i*4+3]<<24)|(cloud.rgba[i*4]<<16)|
      (cloud.rgba[i*4+1]<<8)|cloud.rgba[i*4+2])>>>0)})),frame.drawn,`${message}:draw`);
  }
 }
});
