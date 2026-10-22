import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeObjectRenderOrder,nativeRoadDrawGroups,NATIVE_RENDER_ORDER} from '../src/render-order.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/render-order-fixtures.json',import.meta.url)));
test('36 original accelerated object submissions keep each shadow immediately before its own kart',()=>{
  for(const c of fixture.objects){
    const events=[];
    c.objects.forEach((object,index)=>{
      if(!object.active||!object.used||!object.renderable)return;
      for(const [first,last]of c.ranges)if(object.sector>=first&&object.sector<=last){
        if(object.shadow)events.push({order:nativeObjectRenderOrder(index,{shadow:true}),event:['shadow',index]});
        events.push({order:nativeObjectRenderOrder(index),event:['object',index]});
      }
    });
    assert.deepEqual(events.sort((a,b)=>a.order-b.order).map(x=>x.event),c.expected);
  }
});
test('original road draw batches and wrapped interval order are preserved across materials',()=>{
  const groups=Array.from({length:6},(_,sector)=>['road','land','extra','rail'].map((kind,textureIndex)=>
    ({sector,kind,textureIndex,count:(textureIndex+1)*3,start:sector*30+textureIndex}))).flat();
  for(const c of fixture.road){
    const result=nativeRoadDrawGroups({groups},[c.range]);
    assert.deepEqual(c.expected.map(x=>x.kind),[0,1,2,3]);
    assert.deepEqual([0,1,2,3].map(kind=>({kind,count:result.filter(x=>x.textureIndex===kind)
      .reduce((sum,x)=>sum+x.count,0)})),c.expected);
    assert.deepEqual(result.map(x=>x.textureIndex),[0,1,2,3].flatMap(kind=>
      Array(c.range[1]-c.range[0]+1).fill(kind)));
  }
  const wrapped=nativeRoadDrawGroups({groups},[[4,5],[0,1]]);
  assert.deepEqual(wrapped.map(x=>x.sector),[4,5,4,5,4,5,4,5,0,1,0,1,0,1,0,1]);
  assert.ok(NATIVE_RENDER_ORDER.road<NATIVE_RENDER_ORDER.sky);
  assert.ok(NATIVE_RENDER_ORDER.sky<NATIVE_RENDER_ORDER.objects);
});
