import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import * as THREE from 'three';
import {HudTextRenderer} from '../source/hud-text-renderer.js';
import {getHudStringSpec} from '../source/hud-text.js';
import {nativeMatrix,setNativeMatrix} from '../source/render-transforms.js';
import {KartShadowVisual,StreamVisuals,WeatherVisuals} from '../source/race-visuals.js';

const config=JSON.parse(fs.readFileSync(new URL('../public/assets/config.json',import.meta.url)));
function fixture(id='string_lap'){
  const spec=getHudStringSpec(config,id),hud={config,specs:new Map([[id,spec]])};
  const glyphs=new HudTextRenderer(hud,()=>{});
  for(const source of Object.values(spec.font.glyphs))if(!glyphs.textures.has(source.texture))
    glyphs.textures.set(source.texture,new THREE.Texture({width:256,height:256}));
  const renderer={autoClear:true,draws:0,setViewport(){},render(){this.draws++;}};
  const anchor={x:0,y:0,scale:1},layout={text:()=>anchor};
  return {id,spec,hud,glyphs,renderer,anchor,layout};
}
const buffers=entry=>entry.meshes.filter(mesh=>mesh.visible).map(mesh=>
  Object.fromEntries(['position','uv','color'].map(name=>[name,[...mesh.geometry.attributes[name].array]])));
const versions=entry=>entry.meshes.map(mesh=>['position','uv','color'].map(name=>mesh.geometry.attributes[name].version));

test('unchanged HUD redraws retain draw order and blending without new geometry uploads',()=>{
  const f=fixture(),draw=()=>f.glyphs.renderString(f.renderer,f.id,'ronde',640,480,f.layout);
  draw();const entry=f.glyphs.strings.get(f.id),first=buffers(entry),initialVersions=versions(entry),state=entry.bufferState;
  for(let i=0;i<240;i++)draw();
  assert.equal(f.renderer.draws,241);assert.equal(f.renderer.autoClear,true);
  assert.equal(entry.bufferState,state);assert.deepEqual(buffers(entry),first);
  assert.deepEqual(versions(entry),initialVersions);
  assert.equal(f.glyphs.strings.size,1);
  f.glyphs.dispose();assert.equal(f.glyphs.strings.size,0);assert.equal(f.glyphs.materials.size,0);
});

test('cached HUD matches a fresh composition after text, layout, atlas, font and notification-style changes',()=>{
  const f=fixture();let text='ronde',width=640,height=480;
  const draw=()=>f.glyphs.renderString(f.renderer,f.id,text,width,height,f.layout);
  draw();
  const changes=[
    ()=>{text='R';},()=>{f.anchor.x=19.5;f.anchor.y=7.25;},()=>{f.anchor.scale=.75;},
    ()=>{width=800;height=600;},()=>{f.spec.rgba[0]=127;f.spec.rgba[3]=64;},
    ()=>{f.spec.context[0]+=.25;},()=>{f.spec.cellWidth=.05;},
    ()=>{f.spec.font.distance+=1;},()=>{f.spec.font.maxWidth+=2;},
    ()=>{f.spec.font.glyphs.R.width+=3;},()=>{f.spec.font.glyphs.R.x+=2;},
    ()=>{f.spec.font={...f.spec.font};},()=>{f.glyphs.textures.get(f.spec.font.glyphs.R.texture).image.width=512;},
    ()=>{text='';},()=>{text='R';},()=>{f.spec.visible=false;},()=>{f.spec.visible=true;},
    ()=>{width=0;},()=>{width=640;},
  ];
  for(const change of changes){
    change();draw();
    const fresh=new HudTextRenderer(f.hud,()=>{});fresh.textures=new Map(f.glyphs.textures);
    fresh.renderString(f.renderer,f.id,text,width,height,f.layout);
    assert.deepEqual(buffers(f.glyphs.strings.get(f.id)),buffers(fresh.strings.get(f.id)));
    assert.equal(f.glyphs.strings.get(f.id).glyphCount,fresh.strings.get(f.id).glyphCount);
    fresh.dispose();
  }
  f.glyphs.dispose();
});

test('special HUD overrides reuse identical snapshots and invalidate for animated scale/alpha/position',()=>{
  const f=fixture('string_special');
  f.hud.specialOverride={position:[0,0,0],scale:[2,2,2],rgba:[255,255,255,255],cellWidth:.05,visible:true};
  const draw=()=>f.glyphs.renderString(f.renderer,f.id,'PAUZE',640,480,f.layout);
  draw();const entry=f.glyphs.strings.get(f.id),spec=entry.spec,initial=versions(entry);
  f.hud.specialOverride=structuredClone(f.hud.specialOverride);draw();
  assert.equal(entry.spec,spec);assert.deepEqual(versions(entry),initial);
  for(const change of [()=>f.hud.specialOverride.scale[0]=3,()=>f.hud.specialOverride.rgba[3]=128,
    ()=>f.hud.specialOverride.position[0]=.4,()=>f.hud.specialOverride.visible=false]){
    change();draw();
    const fresh=new HudTextRenderer(f.hud,()=>{});fresh.textures=new Map(f.glyphs.textures);
    fresh.renderString(f.renderer,f.id,'PAUZE',640,480,f.layout);
    assert.deepEqual(buffers(entry),buffers(fresh.strings.get(f.id)));fresh.dispose();
  }
  f.glyphs.dispose();
});

test('direct native matrix writes preserve every element and retain object-owned storage',()=>{
  for(let i=0;i<1000;i++){
    const m=Array.from({length:9},(_,j)=>Math.fround(Math.sin(i*3+j)*31));
    const p=[i-500,Math.fround(i/3),Math.fround(-i*1.7)];
    const expected=new THREE.Matrix4().set(m[0],m[3],m[6],p[0],m[1],m[4],m[7],p[1],m[2],m[5],m[8],p[2],0,0,0,1);
    const target=new THREE.Matrix4();assert.equal(nativeMatrix(m,p,target),target);
    assert.deepEqual(target.elements,expected.elements);
    const mesh=new THREE.Object3D(),before=mesh.matrix;mesh.position.fromArray(p);
    mesh.position.toArray=()=>{throw Error('temporary position array');};setNativeMatrix(mesh,m);
    assert.equal(mesh.matrix,before);assert.deepEqual(mesh.matrix.elements,expected.elements);
    assert.equal(mesh.matrixWorldNeedsUpdate,true);assert.equal(mesh.matrixAutoUpdate,false);
  }
});

test('shadow interpolation retains captured native transforms over repeated unlocked draws',()=>{
  const body={position:[1,2,3],sector:0,matrix:[1,.2,0,0,.9,.1,.3,0,1]};
  const world={sectors:[{fallback:{normal:[0,1,0],distance:0}}]};
  const shadow=Object.assign(new KartShadowVisual(),{actor:{body},mesh:new THREE.Mesh()});
  shadow.capture(world);body.position=[20,30,40];body.matrix=body.matrix.map(value=>value*.5);shadow.capture(world);
  const before=shadow.previous.renderMatrix,after=shadow.current.renderMatrix;
  for(const alpha of [0,.1,.5,.9,1,0]){
    shadow.present(alpha);
    const previous=nativeMatrix(shadow.previous.matrix,shadow.previous.position),current=nativeMatrix(shadow.current.matrix,shadow.current.position);
    assert.deepEqual(shadow.mesh.matrix.elements,previous.elements.map((value,i)=>value*(1-alpha)+current.elements[i]*alpha));
    assert.equal(shadow.previous.renderMatrix,before);assert.equal(shadow.current.renderMatrix,after);
  }
});

test('stream and weather captures retain packed native color bytes and draw lengths',async()=>{
  const viewer={group:new THREE.Group(),scene:new THREE.Scene(),camera:new THREE.PerspectiveCamera(),texture:async()=>new THREE.Texture()};
  const manifest={images:{'s_sfx.tga':{file:'s_sfx.png'}}},streams=new StreamVisuals(viewer);
  await streams.load(manifest);
  const packed=[0x00123456,0x7f9abcde,0xff13579b],expected=[18,52,86,0,154,188,222,127,19,87,155,255];
  const vertices=packed.map((color,index)=>({color,position:[index,index+1,index+2],uv:[.1,.2]}));
  streams.capture({jets:[vertices],ribbons:[vertices]});
  for(const mesh of [streams.jets[0],streams.ribbons[0]]){
    assert.deepEqual([...mesh.geometry.attributes.color.array.slice(0,12)],expected);
    assert.equal(mesh.geometry.drawRange.count,3);
  }
  const weather=new WeatherVisuals(viewer,{count:2});await weather.load(manifest);
  weather.capture([{vertices:Array(18).fill(1),uv:Array(12).fill(.25),argb:[...packed,...packed]},
    {vertices:Array(18).fill(2),uv:Array(12).fill(.5),argb:[...packed,...packed]}]);
  assert.deepEqual([...weather.mesh.geometry.attributes.color.array],[...expected,...expected,...expected,...expected]);
  assert.equal(weather.mesh.geometry.drawRange.count,12);
  streams.dispose();weather.dispose();
});
