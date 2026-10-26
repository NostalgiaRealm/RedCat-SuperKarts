import fs from 'node:fs';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {nativeSceneryIsSolid, nativeSceneryPhysics} from '../source/simulation/native-scenery-contact.js';

const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const read=name=>JSON.parse(fs.readFileSync(path.join(root,'public/assets',name),'utf8'));
const manifest=read('manifest.json'), config=read('config.json');
const textures=new Map(), tracks=[];
for(let id=0;id<6;id++){
  const track=read(`tracks/etappe${id}.json`);
  const placements=track.placements.map((placement,index)=>{
    const definition=track.objectDefinitions[placement.animation.toLowerCase()];
    if(!definition)throw new Error(`Missing definition ${id}:${index} ${placement.animation}`);
    const mesh=definition.mesh.toLowerCase(), texture=definition.texture.toLowerCase();
    const bounds=manifest.meshes[mesh]?.bounds;
    if(!bounds)throw new Error(`Missing mesh collision data ${mesh}`);
    const solid=nativeSceneryIsSolid(placement.type);
    const record={placementIndex:index,sector:placement.sector,type:placement.type,
      animation:placement.animation,mesh,texture,solid,bounds,
      rule:solid?'Registered physical-object mesh rectangle':'No physical-object registration',
      registration:solid?(placement.type===6?'0043d130':'0043f1b0'):null};
    if(solid)record.physics=nativeSceneryPhysics(placement.type,config['rotobj.ini']?.[placement.animation.toLowerCase()]);
    let entry=textures.get(texture);
    if(!entry)textures.set(texture,entry={texture,solidPlacements:0,nonSolidPlacements:0,types:new Set(),meshes:new Set(),tracks:new Set()});
    entry[solid?'solidPlacements':'nonSolidPlacements']++;
    entry.types.add(placement.type);entry.meshes.add(mesh);entry.tracks.add(id);
    return record;
  });
  tracks.push({id,placements:placements.length,solid:placements.filter(p=>p.solid).length,
    movingMass:placements.filter(p=>p.solid&&p.physics.inverseMass!==0).length,records:placements});
}
const result={sourceSHA256:'68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f',
  scope:'Every original OMP placement and its authored mesh/texture association in the supplied six tracks. Texture appearance does not select collision behavior.',
  sourceFunctions:['0043e140','0043df30','004939d0','00499b20','00499630','0049b9c0'],
  tracks,textures:[...textures.values()].sort((a,b)=>a.texture.localeCompare(b.texture))
    .map(x=>({...x,types:[...x.types].sort((a,b)=>a-b),meshes:[...x.meshes].sort(),tracks:[...x.tracks].sort()}))};
const output=path.join(root,'evidence/native/scenery-collision-inventory.json');
fs.writeFileSync(output,JSON.stringify(result,null,2)+'\n');
console.log({tracks:tracks.length,placements:tracks.reduce((n,t)=>n+t.placements,0),
  solid:tracks.reduce((n,t)=>n+t.solid,0),textures:result.textures.length,output});
