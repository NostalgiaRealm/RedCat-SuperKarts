import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import * as THREE from 'three';
import {KartShadowVisual} from '../source/race-visuals.js';
import {getNativeKartShadowSpec,getNativeKartShadowPose,getSurfaceKartShadowGrid,surfaceKartShadowPositions,
  SURFACE_SHADOW_LIFT} from '../source/kart-shadow.js';
import {createNativeTrack,sampleNativeTrack} from '../source/simulation/native-track.js';
import {nativePlayerStart} from '../source/simulation/native-start.js';
import {nativeRotationMatrix} from '../source/simulation/native-transform.js';
import {DEFAULT_SETTINGS,normalizeSettings} from '../source/settings.js';
const read=name=>JSON.parse(fs.readFileSync(new URL(name,import.meta.url)));
const fixture=read('../evidence/shadow-audit/native.json');
const manifest=read('../public/assets/manifest.json');
const source=read('../public/assets/meshes/s_shadow.json');

test('original416270 shadow initialization has black alpha128 and two-pixel UV insets',()=>{
  for(const row of fixture.initializers){
    const m={...manifest,images:{...manifest.images,'s_shadow.tga':{...manifest.images['s_shadow.tga'],width:row.width}}};
    const spec=getNativeKartShadowSpec(m,manifest.meshes['kart03.d3d'].bounds);
    assert.deepEqual(spec.uv,row.uv);
    assert.deepEqual(row.diffuse,[0x80000000,0x80000000,0x80000000,0x80000000]);
    assert.deepEqual(row.specular,[0,0,0,0]);
    assert.deepEqual(spec.rgba,[0,0,0,128,0,0,0,128,0,0,0,128,0,0,0,128]);
  }
});

test('shadow owns current kart bounds and keeps native sector visibility without a second sphere rejection',async()=>{
  const original=new THREE.BufferGeometry();
  original.setAttribute('position',new THREE.Float32BufferAttribute(source.position,3));
  original.setIndex(source.index);original.computeBoundingSphere();
  const sourceRadius=original.boundingSphere.radius;
  for(const name of ['kart03.d3d','ufotje.d3d']){
    const actor={body:{}};
    const viewer={motion:actor,opponents:[],track:{placements:[]},group:new THREE.Group(),
      model:async()=>original,texture:async()=>new THREE.Texture()};
    const bounds=manifest.meshes[name].bounds;
    const visual=await KartShadowVisual.load(viewer,manifest,{bounds},actor);
    const g=visual.mesh.geometry;
    assert.equal(g.boundingBox.min.x,bounds.minX);assert.equal(g.boundingBox.max.z,bounds.maxZ);
    for(let i=0;i<4;i++)assert.ok(g.boundingSphere.center.distanceTo(
      new THREE.Vector3().fromBufferAttribute(g.attributes.position,i))<=g.boundingSphere.radius+1e-12);
    assert.ok(g.boundingSphere.radius>sourceRadius);
    assert.equal(visual.mesh.frustumCulled,false);
    assert.equal(visual.mesh.material.transparent,false);
    assert.equal(visual.mesh.material.depthWrite,true);
    assert.equal(visual.mesh.material.blendSrc,THREE.SrcAlphaFactor);
    assert.equal(visual.mesh.material.blendDst,THREE.OneMinusSrcAlphaFactor);
    assert.equal(visual.mesh.material.side,THREE.FrontSide);
    assert.deepEqual([...original.attributes.position.array],source.position);
    assert.equal(original.boundingSphere.radius,sourceRadius);
  }
});

test('surface shadow grid keeps the original quad corners, UVs, colour and face winding',()=>{
  const spec=getNativeKartShadowSpec(manifest,manifest.meshes['kart03.d3d'].bounds);
  const grid=getSurfaceKartShadowGrid(spec,source.index,4),n=4;
  const corner=k=>[grid.local[k*3],grid.local[k*3+2]],uv=k=>[grid.uv[k*2],grid.uv[k*2+1]];
  // Grid corners are the 4260c0 quad's corners (maxX/maxZ, minX/maxZ, minX/minZ, maxX/minZ).
  [0,n,(n+1)*(n+1)-1,n*(n+1)].forEach((k,i)=>{
    assert.deepEqual(corner(k),[spec.position[i*3],spec.position[i*3+2]]);
    assert.deepEqual(uv(k).map(Math.fround),[spec.uv[i*2],spec.uv[i*2+1]]);
  });
  for(let k=0;k<grid.count;k++)assert.deepEqual([...grid.rgba.slice(k*4,k*4+4)],[0,0,0,128]);
  // Every triangle turns the same way as S_SHADOW's own two triangles.
  const area=(p,a,b,c)=>Math.sign((p(b)[0]-p(a)[0])*(p(c)[1]-p(a)[1])-(p(b)[1]-p(a)[1])*(p(c)[0]-p(a)[0]));
  const quad=k=>[spec.position[k*3],spec.position[k*3+2]],expected=area(quad,...source.index.slice(0,3));
  assert.equal(area(quad,...source.index.slice(3,6)),expected);
  assert.equal(grid.index.length,n*n*6);
  for(let i=0;i<grid.index.length;i+=3)assert.equal(area(corner,...grid.index.slice(i,i+3)),expected);
});

test('surface shadow lies on the driven surface where the original quad is hidden below the road',()=>{
  // France's starting sector 174: fallback plane Y=0, road triangles Y>=20.
  const track=read('../public/assets/tracks/etappe3.json'),world=createNativeTrack(track);
  const spec=getNativeKartShadowSpec(manifest,manifest.meshes['kart03.d3d'].bounds);
  const grid=getSurfaceKartShadowGrid(spec,source.index);
  const start=nativePlayerStart(track,world),yaw=start.yaw;
  const body={position:[...start.position],sector:start.sector,matrix:nativeRotationMatrix([0,yaw,0])};
  body.position[1]=sampleNativeTrack(world,body.sector,...body.position).height+5;
  const native=getNativeKartShadowPose(body,world.sectors[body.sector].fallback);
  const positions=surfaceKartShadowPositions(body,world,grid);
  let road=0;
  for(let k=0;k<grid.count;k++){
    const [x,y,z]=positions.slice(k*3,k*3+3),lx=grid.local[k*3],lz=grid.local[k*3+2],m=body.matrix;
    assert.equal(x,Math.fround(lx*m[0]+lz*m[6]+body.position[0]+2));
    assert.equal(z,Math.fround(lz*m[8]+lx*m[2]+body.position[2]+2));
    const ground=sampleNativeTrack(world,body.sector,x,body.position[1],z);
    assert.equal(y,Math.fround(ground.height+SURFACE_SHADOW_LIFT));
    if(ground.kind!=='fallback')road++;
  }
  assert.equal(start.sector,174);assert.equal(native.position[1],0);
  assert.ok(road===grid.count,`${road} of ${grid.count} grid points on road triangles`);
  assert.ok(Math.min(...positions.filter((_,i)=>i%3===1))>=20);
});

test('KartShadowVisual switches between the original quad and the surface grid on one mesh',async()=>{
  const original=new THREE.BufferGeometry();
  original.setAttribute('position',new THREE.Float32BufferAttribute(source.position,3));
  original.setIndex(source.index);
  const track=read('../public/assets/tracks/etappe3.json'),world=createNativeTrack(track),start=nativePlayerStart(track,world);
  const body={position:[...start.position],sector:start.sector,matrix:nativeRotationMatrix([0,start.yaw,0])};
  const actor={body};
  const viewer={motion:actor,opponents:[],track:{placements:[]},group:new THREE.Group(),surfaceShadows:true,
    model:async()=>original,texture:async()=>new THREE.Texture()};
  const visual=await KartShadowVisual.load(viewer,manifest,{bounds:manifest.meshes['kart03.d3d'].bounds},actor);
  const mesh=visual.mesh,grid=visual.grid;
  assert.equal(visual.surface,true);assert.equal(mesh.geometry,visual.surfaceGeometry);
  assert.equal(mesh.userData.inactiveGeometry,visual.nativeGeometry);
  assert.equal(mesh.material.polygonOffset,true);assert.ok(mesh.material.polygonOffsetUnits<0);
  assert.equal(mesh.material.depthWrite,false);
  assert.equal(mesh.material.side,THREE.FrontSide);
  visual.capture(world);visual.present(.5);
  assert.ok(mesh.matrix.equals(new THREE.Matrix4()));
  assert.deepEqual([...mesh.geometry.attributes.position.array],[...surfaceKartShadowPositions(body,world,grid)]);
  // A second capture interpolates between the two in world space.
  const first=[...visual.surfacePositions[1]];body.position[0]+=10;visual.capture(world);visual.present(.5);
  const second=visual.surfacePositions[1],mid=mesh.geometry.attributes.position.array;
  assert.equal(mid[0],Math.fround((first[0]+second[0])/2));
  visual.setSurface(false,world);
  assert.equal(mesh.geometry,visual.nativeGeometry);assert.equal(mesh.material.polygonOffset,false);
  assert.equal(mesh.material.depthWrite,true);
  assert.ok(!mesh.matrix.equals(new THREE.Matrix4()));
});

test('the surface shadow setting is on by default and an explicit off is kept',()=>{
  assert.equal(DEFAULT_SETTINGS.surfaceShadows,true);
  assert.equal(normalizeSettings({}).surfaceShadows,true);
  assert.equal(normalizeSettings({surfaceShadows:false}).surfaceShadows,false);
  assert.equal(normalizeSettings({surfaceShadows:'no'}).surfaceShadows,true);
});
