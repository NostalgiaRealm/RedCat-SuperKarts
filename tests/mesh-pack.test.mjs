import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {fileURLToPath} from 'node:url';
import {buildMeshPack} from '../tools/mesh-pack.mjs';
import {nativeVertexRGBA} from '../source/asset-materials.js';

const directory=new URL('../public/assets/meshes/',import.meta.url);
test('the mesh pack holds exactly the values the JSON loader produces, for every mesh',async()=>{
  const pack=await buildMeshPack(fileURLToPath(directory)),names=fs.readdirSync(directory).filter(name=>name.endsWith('.json'));
  assert.equal(Object.keys(pack.entries).length,names.length);
  const buffer=pack.buffer.buffer.slice(pack.buffer.byteOffset,pack.buffer.byteOffset+pack.buffer.byteLength);
  for(const name of names){
    const data=JSON.parse(fs.readFileSync(new URL(name,directory))),[vertices,indices,position,uv,color,index]=pack.entries[name.slice(0,-5)];
    assert.equal(vertices,data.position.length/3,name);
    assert.deepEqual(new Float32Array(buffer,position,vertices*3),Float32Array.from(data.position),name);
    if(data.uv)assert.deepEqual(new Float32Array(buffer,uv,vertices*2),Float32Array.from(data.uv),name);else assert.equal(uv,-1,name);
    assert.deepEqual(new Uint8Array(buffer,color,vertices*4),nativeVertexRGBA(data),name);
    if(data.index)assert.deepEqual(new Uint16Array(buffer,index,indices),Uint16Array.from(data.index),name);else assert.equal(index,-1,name);
  }
});
