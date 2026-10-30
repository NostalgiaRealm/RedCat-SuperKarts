import {createHash} from 'node:crypto';
import {readFile,readdir} from 'node:fs/promises';
import path from 'node:path';
import {nativeVertexRGBA} from '../source/asset-materials.js';

/** One binary file with every prepared mesh, so that a race needs one request
 * instead of about 1,250 JSON files. It holds the exact values the JSON loader
 * produces; repeated arrays (animation frames share UVs, colours and indices)
 * are stored once. public/assets/meshes stays the source of this file.
 * Entry: [vertices,indices,position,uv,color,index] with byte offsets; -1 = none. */
export async function buildMeshPack(directory){
  const names=(await readdir(directory)).filter(name=>name.endsWith('.json')).sort();
  const chunks=[],seen=new Map(),entries={};let size=0;
  const add=typed=>{
    const bytes=Buffer.from(typed.buffer,typed.byteOffset,typed.byteLength);
    const key=typed.BYTES_PER_ELEMENT+':'+createHash('sha1').update(bytes).digest('hex');
    if(seen.has(key))return seen.get(key);
    const padding=-size&(typed.BYTES_PER_ELEMENT-1);
    if(padding){chunks.push(Buffer.alloc(padding));size+=padding;}
    const offset=size;chunks.push(bytes);size+=bytes.length;seen.set(key,offset);
    return offset;
  };
  for(const name of names){
    const data=JSON.parse(await readFile(path.join(directory,name),'utf8'));
    const vertices=data.position.length/3,index=data.index??null;
    if(index&&Math.max(...index)>=65535)throw Error(`Mesh ${name} needs 32-bit indices`);
    entries[name.slice(0,-5)]=[vertices,index?index.length:0,add(Float32Array.from(data.position)),
      data.uv?add(Float32Array.from(data.uv)):-1,add(nativeVertexRGBA(data)),index?add(Uint16Array.from(index)):-1];
  }
  return {buffer:Buffer.concat(chunks),entries};
}
