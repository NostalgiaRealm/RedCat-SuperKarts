import * as THREE from 'three';
import {resolveAsset} from './asset-animation.js';
import {createNativeMeshMaterial} from './asset-materials.js';
import {getHudStringSpec,layoutHudText} from './hud-text.js';

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
    const spec=id==='string_special'?getHudStringSpec(this.hud.config,id,{overrides:{
      [id]:this.hud.specialOverride,
    }}):this.hud.specs.get(id);
    if(!spec)throw new Error(`Original HUD string has not been loaded: ${id}`);
    entry.spec=spec;
    const glyphs=spec.visible&&width>0&&height>0?layoutHudText(spec,text):[];
    entry.glyphCount=glyphs.length;
    for(let i=glyphs.length;i<entry.meshes.length;i++)entry.meshes[i].visible=false;
    if(!glyphs.length)return 0;
    const {x:offsetX,y:offsetY,scale=layout.scale}=layout.text(id);
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
    if(this.width!==width||this.height!==height){
      this.width=width;this.height=height;
      this.camera.right=width;this.camera.bottom=height;this.camera.updateProjectionMatrix();
    }
    renderer.setViewport(0,0,width,height);
    const autoClear=renderer.autoClear;renderer.autoClear=false;
    try{renderer.render(entry.scene,this.camera);}
    finally{renderer.autoClear=autoClear;}
    return glyphs.length;
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
