import * as THREE from 'three';
import {resolveAsset} from './asset-animation.js';
import {createNativeMeshMaterial} from './asset-materials.js';
import {getHudStringSpec,layoutHudText} from './hud-text.js';

const specFields=['type','alignment','length','maxCharWidth','cellWidth','precision','visible'];
const glyphFields=['texture','x','y','width','height'];
const sameValues=(a,b)=>a.length===b.length&&a.every((value,index)=>Object.is(value,b[index]));

// Cache only the most recently drawn state per string. Layout, font geometry,
// tint and notification animation are independent inputs; all can invalidate
// the buffers without skipping a draw into the original RGB565 destination.
function unchanged(state,spec,text,width,height,x,y,scale,textures){
  return state&&state.text===text&&state.width===width&&state.height===height
    &&state.x===x&&state.y===y&&state.scale===scale&&state.font===spec.font
    &&state.fontWidth===spec.font.maxWidth&&state.fontDistance===spec.font.distance
    &&state.coordinateWidth===spec.coordinateSpace.width
    &&specFields.every(name=>Object.is(state[name],spec[name]))
    &&sameValues(state.context,spec.context)&&sameValues(state.rgba,spec.rgba)
    &&state.glyphs.every(({character,source,values,image,width,height})=>{
      const current=spec.font.glyphs[character];
      const currentImage=current&&textures.get(current.texture)?.image;
      return current===source&&(!current||(glyphFields.every((name,index)=>Object.is(current[name],values[index]))
        &&currentImage===image&&currentImage?.width===width&&currentImage?.height===height));
    });
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
    if(!this.strings.has(id))this.strings.set(id,{
      scene:new THREE.Scene(),meshes:[],glyphCount:0,spec:null,
    });
    return this.strings.get(id);
  }
  glyphMesh(entry,index,texture) {
    if(!entry.meshes[index]){
      const geometry=new THREE.BufferGeometry();
      geometry.setAttribute('position',new THREE.Float32BufferAttribute(new Float32Array(12),3)
        .setUsage(THREE.DynamicDrawUsage));
      geometry.setAttribute('uv',new THREE.Float32BufferAttribute(new Float32Array(8),2)
        .setUsage(THREE.DynamicDrawUsage));
      geometry.setAttribute('color',new THREE.Uint8BufferAttribute(new Uint8Array(16),4,true)
        .setUsage(THREE.DynamicDrawUsage));
      // TL, TR, BL, BR. Retain 0045ed60's TL-to-BR diagonal; the pixel
      // camera reverses Y, so reverse winding to remain front-facing.
      geometry.setIndex([0,3,1,0,2,3]);
      const mesh=new THREE.Mesh(geometry,this.material(texture));
      mesh.frustumCulled=false;mesh.renderOrder=index;
      entry.meshes.push(mesh);entry.scene.add(mesh);
    }
    return entry.meshes[index];
  }
  renderString(renderer,id,text,width,height,layout) {
    const entry=this.string(id);
    // captureNotification replaces the override on each native HUD update.
    // Interpolated draws use that same snapshot, including while paused.
    if(id==='string_special'&&(!entry.spec||!sameOverride(entry.override,this.hud.specialOverride))){
      entry.override=copyOverride(this.hud.specialOverride);
      entry.spec=getHudStringSpec(this.hud.config,id,{overrides:{[id]:entry.override}});
    }
    const spec=id==='string_special'?entry.spec:this.hud.specs.get(id);
    if(!spec)throw new Error(`Original HUD string has not been loaded: ${id}`);
    entry.spec=spec;
    const {x:offsetX,y:offsetY,scale=layout.scale}=layout.text(id);
    const value=String(text===undefined?spec.text:text);
    if(!unchanged(entry.bufferState,spec,value,width,height,offsetX,offsetY,scale,this.textures)){
      const glyphs=spec.visible&&width>0&&height>0?layoutHudText(spec,text):[];
      entry.glyphCount=glyphs.length;
      for(let i=glyphs.length;i<entry.meshes.length;i++)entry.meshes[i].visible=false;
      for(const [index,glyph]of glyphs.entries()){
        const source=glyph.source,texture=this.textures.get(source.texture);
        if(!texture)throw new Error(`Original HUD texture has not been loaded: ${source.texture}`);
        const mesh=this.glyphMesh(entry,index,source.texture);
        mesh.material=this.material(source.texture);mesh.visible=true;
        const {position,uv,color}=mesh.geometry.attributes;
        const left=offsetX+glyph.x*scale,top=offsetY+glyph.y*scale;
        const right=left+glyph.width*scale,bottom=top+glyph.height*scale;
        position.setXYZ(0,left,top,0);position.setXYZ(1,right,top,0);
        position.setXYZ(2,left,bottom,0);position.setXYZ(3,right,bottom,0);
        // 0045ed60 uses the atlas rectangle's exact edges, with no half-texel
        // inset. Native DataTextures retain top-down row order (flipY=false),
        // so original source y=0 is v=0 at the top of this quad.
        const image=texture.image,u0=source.x/image.width,v0=source.y/image.height;
        const u1=(source.x+source.width)/image.width,v1=(source.y+source.height)/image.height;
        uv.setXY(0,u0,v0);uv.setXY(1,u1,v0);uv.setXY(2,u0,v1);uv.setXY(3,u1,v1);
        for(let vertex=0;vertex<4;vertex++)color.array.set(spec.rgba,vertex*4);
        position.needsUpdate=uv.needsUpdate=color.needsUpdate=true;
      }
      entry.bufferState=remember(spec,value,width,height,offsetX,offsetY,scale,this.textures);
    }
    if(!entry.glyphCount)return 0;
    if(this.width!==width||this.height!==height){
      this.width=width;this.height=height;
      this.camera.right=width;this.camera.bottom=height;this.camera.updateProjectionMatrix();
    }
    renderer.setViewport(0,0,width,height);
    const autoClear=renderer.autoClear;renderer.autoClear=false;
    try{renderer.render(entry.scene,this.camera);}
    finally{renderer.autoClear=autoClear;}
    return entry.glyphCount;
  }
  dispose() {
    for(const {scene,meshes}of this.strings.values()){
      for(const mesh of meshes)mesh.geometry.dispose();
      scene.clear();
    }
    for(const material of this.materials.values())material.dispose();
    this.strings.clear();this.materials.clear();this.textures.clear();
    // Textures belong to textureLoader (shared with the native overlay).
  }
}
