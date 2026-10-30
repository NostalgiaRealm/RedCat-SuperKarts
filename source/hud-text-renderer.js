import * as THREE from 'three';
import {resolveAsset} from './asset-animation.js';
import {createNativeMeshMaterial} from './asset-materials.js';
import {getHudStringSpec,layoutHudText} from './hud-text.js';

const specFields=['type','alignment','length','maxCharWidth','cellWidth','precision','visible'];
const glyphFields=['texture','x','y','width','height'];
const sameValues=(a,b)=>{
  if(a.length!==b.length)return false;
  for(let i=0;i<a.length;i++)if(!Object.is(a[i],b[i]))return false;
  return true;
};

// Cache only the most recently drawn state per string. Layout, font geometry,
// tint and notification animation are independent inputs; all can invalidate
// the buffers without skipping a draw into the original RGB565 destination.
function unchanged(state,spec,text,width,height,x,y,scale,textures){
  if(!state||state.text!==text||state.width!==width||state.height!==height
    ||state.x!==x||state.y!==y||state.scale!==scale)return false;
  const font=spec.font,stored=state.glyphs;
  if(state.font!==font||state.fontWidth!==font.maxWidth||state.fontDistance!==font.distance
    ||state.coordinateWidth!==spec.coordinateSpace.width)return false;
  for(let i=0;i<specFields.length;i++)if(!Object.is(state[specFields[i]],spec[specFields[i]]))return false;
  if(!sameValues(state.context,spec.context)||!sameValues(state.rgba,spec.rgba))return false;
  for(let i=0;i<stored.length;i++){
    const glyph=stored[i],current=font.glyphs[glyph.character];
    if(current!==glyph.source)return false;
    if(!current)continue;
    const values=glyph.values;
    for(let k=0;k<glyphFields.length;k++)if(!Object.is(current[glyphFields[k]],values[k]))return false;
    const image=textures.get(current.texture)?.image;
    if(image!==glyph.image||image?.width!==glyph.width||image?.height!==glyph.height)return false;
  }
  return true;
}
function remember(spec,text,width,height,x,y,scale,textures){
  // Include space even when it is absent from text: fixed fonts pad with it.
  const characters=new Set(Array.from(text).slice(0,spec.length));characters.add(' ');
  const state={text,width,height,x,y,scale,font:spec.font,fontWidth:spec.font.maxWidth,
    fontDistance:spec.font.distance,coordinateWidth:spec.coordinateSpace.width,
    context:[...spec.context],rgba:[...spec.rgba],glyphs:[...characters].map(character=>{
      const source=spec.font.glyphs[character];
      const image=source&&textures.get(source.texture)?.image;
      return {character,source,values:source?glyphFields.map(name=>source[name]):null,
        image,width:image?.width,height:image?.height};
    })};
  for(const name of specFields)state[name]=spec[name];
  return state;
}
const sameOverride=(a,b)=>a&&Object.keys(a).length===Object.keys(b??{}).length
  &&Object.entries(a).every(([name,value])=>Array.isArray(value)
    ?Array.isArray(b?.[name])&&sameValues(value,b[name]):Object.is(value,b?.[name]));
const copyOverride=value=>Object.fromEntries(Object.entries(value??{}).map(([name,item])=>
  [name,Array.isArray(item)?[...item]:item]));

/** Draw original font quads directly into the caller's bound race surface.
 * The atlas and vertex bytes use the same native pipeline as overlay models;
 * each glyph therefore blends into (and rounds in) the RGB565 destination.
 */
export class HudTextRenderer {
  constructor(hud,textureLoader) {
    this.hud=hud;this.textureLoader=textureLoader;
    this.textures=new Map();this.materials=new Map();this.strings=new Map();
    // Pixel coordinates have their origin at the top left, like the native
    // projected rectangles returned by layoutHudText.
    this.camera=new THREE.OrthographicCamera(0,640,0,480,-1,1);
    this.width=640;this.height=480;
  }
  async load() {
    const names=new Set();
    for(const spec of this.hud.specs.values())
      for(const glyph of Object.values(spec.font.glyphs))names.add(glyph.texture);
    await Promise.all([...names].map(async name=>{
      if(this.textures.has(name))return;
      const file=resolveAsset(this.hud.manifest,'images',name);
      if(!file)throw new Error(`Original HUD image missing: ${name}`);
      const texture=await this.textureLoader(file);
      this.textures.set(name,texture);
    }));
  }
  material(name) {
    if(!this.materials.has(name)){
      const texture=this.textures.get(name);
      if(!texture)throw new Error(`Original HUD texture has not been loaded: ${name}`);
      const material=createNativeMeshMaterial(texture,{blendMode:1});
      material.depthTest=false;material.depthWrite=false;
      this.materials.set(name,material);
    }
    return this.materials.get(name);
  }
  string(id) {
    if(!this.strings.has(id)){
      const spec=id==='string_special'?null:this.hud.specs.get(id);
      this.strings.set(id,{mesh:null,glyphCount:0,spec,capacity:0});
    }
    return this.strings.get(id);
  }
  stringMesh(entry,spec,texture) {
    if(!entry.mesh){
      const capacity=entry.capacity=spec.length,geometry=new THREE.BufferGeometry();
      const dynamic=(array,size,normalized)=>new THREE.BufferAttribute(array,size,normalized).setUsage(THREE.DynamicDrawUsage);
      geometry.setAttribute('position',dynamic(new Float32Array(12*capacity),3));
      geometry.setAttribute('uv',dynamic(new Float32Array(8*capacity),2));
      geometry.setAttribute('color',dynamic(new Uint8Array(16*capacity),4,true));
      // TL, TR, BL, BR. Retain 0045ed60's TL-to-BR diagonal; the pixel
      // camera reverses Y, so reverse winding to remain front-facing.
      const index=new Uint16Array(6*capacity);
      for(let i=0;i<capacity;i++)index.set([i*4,i*4+3,i*4+1,i*4,i*4+2,i*4+3],i*6);
      geometry.setIndex(new THREE.BufferAttribute(index,1));
      const mesh=new THREE.Mesh(geometry,this.material(texture));
      mesh.frustumCulled=false;mesh.matrixAutoUpdate=false;
      entry.mesh=mesh;entry.scene=null;
    }
    return entry.mesh;
  }
  /** Refresh one string's buffers; returns its glyph count. Drawing is the caller's. */
  prepareString(id,text,width,height,layout) {
    const entry=this.string(id);
    if(id==='string_special'&&(!entry.spec||!sameOverride(entry.override,this.hud.specialOverride))){
      entry.override=copyOverride(this.hud.specialOverride);
      entry.spec=getHudStringSpec(this.hud.config,id,{overrides:{[id]:entry.override},font:entry.spec?.font});
    }
    const spec=id==='string_special'?entry.spec:this.hud.specs.get(id);
    if(!spec)throw new Error(`Original HUD string has not been loaded: ${id}`);
    entry.spec=spec;
    const {x:offsetX,y:offsetY,scale=layout.scale}=layout.text(id);
    const value=String(text===undefined?spec.text:text);
    if(!unchanged(entry.bufferState,spec,value,width,height,offsetX,offsetY,scale,this.textures)){
      const glyphs=spec.visible&&width>0&&height>0?layoutHudText(spec,text):[];
      entry.glyphCount=glyphs.length;
      for(const [index,glyph]of glyphs.entries()){
        const source=glyph.source,texture=this.textures.get(source.texture);
        if(!texture)throw new Error(`Original HUD texture has not been loaded: ${source.texture}`);
        const mesh=this.stringMesh(entry,spec,source.texture);
        const {position,uv,color}=mesh.geometry.attributes;
        const left=offsetX+glyph.x*scale,top=offsetY+glyph.y*scale;
        const right=left+glyph.width*scale,bottom=top+glyph.height*scale;
        const q=index*4;
        position.setXYZ(q,left,top,0);position.setXYZ(q+1,right,top,0);
        position.setXYZ(q+2,left,bottom,0);position.setXYZ(q+3,right,bottom,0);
        const image=texture.image,u0=source.x/image.width,v0=source.y/image.height;
        const u1=(source.x+source.width)/image.width,v1=(source.y+source.height)/image.height;
        uv.setXY(q,u0,v0);uv.setXY(q+1,u1,v0);uv.setXY(q+2,u0,v1);uv.setXY(q+3,u1,v1);
        for(let channel=0,c=q*4;channel<16;channel++)color.array[c+channel]=spec.rgba[channel&3];
        position.needsUpdate=uv.needsUpdate=color.needsUpdate=true;
      }
      if(entry.mesh){entry.mesh.geometry.setDrawRange(0,entry.glyphCount*6);entry.mesh.visible=entry.glyphCount>0;}
      entry.bufferState=remember(spec,value,width,height,offsetX,offsetY,scale,this.textures);
    }
    if(this.width!==width||this.height!==height){
      this.width=width;this.height=height;
      this.camera.right=width;this.camera.bottom=height;this.camera.updateProjectionMatrix();
    }
    return entry.glyphCount;
  }
  renderString(renderer,id,text,width,height,layout) {
    const count=this.prepareString(id,text,width,height,layout);
    if(!count)return 0;
    renderer.setViewport(0,0,width,height);
    const autoClear=renderer.autoClear;renderer.autoClear=false;
    try{renderer.render(this.strings.get(id).mesh,this.camera);}
    finally{renderer.autoClear=autoClear;}
    return count;
  }
  dispose() {
    for(const {mesh}of this.strings.values())mesh?.geometry.dispose();
    for(const material of this.materials.values())material.dispose();
    this.strings.clear();this.materials.clear();this.textures.clear();
    // Textures belong to textureLoader (shared with the native overlay).
  }
}
