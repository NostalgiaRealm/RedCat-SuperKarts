import * as THREE from 'three';
import {chooseMultisampleCount} from './settings.js';
// Keep the existing module API for renderer consumers and inspection tools.
export {chooseMultisampleCount} from './settings.js';

export function supportedMultisampleCounts(gl) {
  const counts=format=>Array.from(gl.getInternalformatParameter(gl.RENDERBUFFER,format,gl.SAMPLES)??[]);
  const depth=new Set(counts(gl.DEPTH_COMPONENT24));
  return [...new Set(counts(gl.RGB565).filter(value=>value>=2&&depth.has(value)))].sort((a,b)=>a-b);
}

const FRESH=0,BURNED=1,CLEAN=2;
/** Native 16-bit race/track framebuffer, with optional WebGL2 multisampling.
 * The supplied RESOLUTION3 selects a 16-bit display; choose its RGB565 profile
 * consistently with native texture upload. A real RGB565 attachment rounds
 * each write/blend, which a final 8-bit postprocessing pass cannot reproduce.
 * Materials and resolve/copy keep display-byte RGB without another sRGB
 * transfer. HUD draws share a full-display RGB565 surface, so they remain
 * sharp when the world resolution is reduced and still round every blend.
 * When the world already has the display's size and no MSAA, that surface is
 * the world target itself, without a copy. worldState tracks whether its
 * contents are a fresh world, or already carry a HUD and must be redrawn before
 * the next paused composition, so paused redraws never blend a HUD twice. */
export class MultisampleSceneRenderer {
  constructor(renderer) {
    this.renderer=renderer;
    this.supportedSamples=supportedMultisampleCounts(renderer.getContext());
    this.status={enabled:false,requestedSamples:4,actualSamples:0,supportedSamples:[...this.supportedSamples]};
    this.target=null;
    this.compositionTarget=null;
    this.stats={world:null,hud:null,presentation:null};
    this.scene=new THREE.Scene();this.camera=new THREE.Camera();
    this.geometry=new THREE.BufferGeometry();
    this.geometry.setAttribute('position',new THREE.Float32BufferAttribute([-1,-1,0,3,-1,0,-1,3,0],3));
    this.material=new THREE.RawShaderMaterial({
      uniforms:{image:{value:null}},depthTest:false,depthWrite:false,blending:THREE.NoBlending,
      vertexShader:'precision highp float; attribute vec3 position; varying vec2 uv; void main(){uv=position.xy*.5+.5;gl_Position=vec4(position,1.0);}',
      fragmentShader:'precision highp float; uniform sampler2D image; varying vec2 uv; void main(){gl_FragColor=vec4(texture2D(image,uv).rgb,1.0);}',
    });
    // Canvas presentation of an equally sized surface: the exact texel, whatever
    // the source's filter. Three re-resolves a program when one material changes
    // destination colour space, so the canvas and render targets keep their own.
    this.exactMaterial=new THREE.RawShaderMaterial({glslVersion:THREE.GLSL3,uniforms:{image:{value:null}},
      depthTest:false,depthWrite:false,blending:THREE.NoBlending,
      vertexShader:'precision highp float; in vec3 position; void main(){gl_Position=vec4(position,1.0);}',
      fragmentShader:'precision highp float; precision highp sampler2D; uniform sampler2D image; out vec4 color; void main(){color=vec4(texelFetch(image,ivec2(gl_FragCoord.xy),0).rgb,1.0);}'});
    this.mesh=new THREE.Mesh(this.geometry,this.material);this.mesh.frustumCulled=false;this.scene.add(this.mesh);
    this.clearColor=new THREE.Color();this.byteClearColor=new THREE.Color();
    this.drawingBufferSize=new THREE.Vector2();
    this.worldState=CLEAN;this.worldPass=null;this.worldScene=null;this.worldCamera=null;
  }
  configure(settings,width,height) {
    this.release();
    const enabled=settings.msaaEnabled===true;
    const requestedSamples=[2,4,8].includes(settings.msaaSamples)?settings.msaaSamples:4;
    const actualSamples=enabled?chooseMultisampleCount(requestedSamples,this.supportedSamples):0;
    this.status={enabled,requestedSamples,actualSamples,supportedSamples:[...this.supportedSamples]};
    if(this.target&&this.target.samples!==actualSamples){
      this.target.dispose();this.target=null;
      this.compositionTarget?.dispose();this.compositionTarget=null;
    }
    if(!this.target){
      this.target=new THREE.WebGLRenderTarget(width,height,{samples:actualSamples,
        minFilter:THREE.LinearFilter,magFilter:THREE.LinearFilter,
        type:THREE.UnsignedByteType,format:THREE.RGBFormat,internalFormat:'RGB565',colorSpace:THREE.NoColorSpace,
        depthBuffer:true,stencilBuffer:false,generateMipmaps:false});
      this.target.texture.name='Native RGB565 race framebuffer';
      this.worldState=this.worldScene?BURNED:CLEAN;
    }
    // A reallocated target holds no world: the next composition redraws it.
    if(this.target.width!==width||this.target.height!==height)this.worldState=this.worldScene?BURNED:CLEAN;
    this.target.setSize(width,height);
    return this.status;
  }
  /** End a world pass left bound for a direct HUD that never came (hidden canvas). */
  release() {
    if(!this.worldPass)return;
    const {previous}=this.worldPass,gl=this.renderer.getContext();
    this.worldPass=null;
    gl.invalidateFramebuffer(gl.FRAMEBUFFER,[gl.DEPTH_ATTACHMENT]);
    this.renderer.setRenderTarget(previous);
  }
  blit(material,texture) {
    material.uniforms.image.value=texture;this.mesh.material=material;
    this.renderer.render(this.scene,this.camera);
  }
  render(scene,camera,{present=true}={}) {
    const renderer=this.renderer,gl=renderer.getContext();
    this.release();
    // Inspection callers can render before the first settings/resize event.
    if(!this.target){
      renderer.getDrawingBufferSize(this.drawingBufferSize);
      this.configure({},this.drawingBufferSize.x,this.drawingBufferSize.y);
    }
    const target=this.target,hold=!present&&!target.samples,dither=gl.isEnabled(gl.DITHER);
    const previousTarget=renderer.getRenderTarget(),autoClear=renderer.autoClear;
    const clearAlpha=renderer.getClearAlpha(),background=scene.background;
    renderer.getClearColor(this.clearColor);
    // Three converts clear/unlit colors for its default framebuffer, but not
    // a linear render target. Keep the same byte-space clear before RGB565 conversion.
    this.byteClearColor.copy(this.clearColor).convertLinearToSRGB();
    try {
      // D3DRENDERSTATE_DITHERENABLE defaults to FALSE in the original path.
      // Preserve the caller's GL capability and Three's capability cache.
      renderer.state.disable(gl.DITHER);
      renderer.setRenderTarget(target);
      renderer.setClearColor(this.byteClearColor,clearAlpha);
      if(background?.isColor)scene.background=background.clone().convertLinearToSRGB();
      renderer.render(scene,camera);
      this.stats.world={...renderer.info.render,width:target.width,height:target.height};
      this.stats.hud=null;
      this.worldScene=scene;this.worldCamera=camera;this.worldState=FRESH;
      // Stay bound: a HUD drawn directly next avoids a render pass switch.
      if(hold){this.worldPass={previous:previousTarget};return;}
      // Tile-based GPUs need not write this frame's depth to memory.
      if(!target.samples)gl.invalidateFramebuffer(gl.FRAMEBUFFER,[gl.DEPTH_ATTACHMENT]);
      renderer.setRenderTarget(previousTarget); // resolves the multisample attachments
      renderer.autoClear=false;
      if(present){
        this.blit(this.material,target.texture);
        this.stats.presentation={...renderer.info.render};
      }
    } finally {
      scene.background=background;
      if(!this.worldPass)renderer.setRenderTarget(previousTarget);
      renderer.setClearColor(this.clearColor,clearAlpha);
      renderer.autoClear=autoClear;
      if(dither)renderer.state.enable(gl.DITHER);else renderer.state.disable(gl.DITHER);
    }
  }
  compose(draw,width,height) {
    if(!this.target)return;
    const renderer=this.renderer,gl=renderer.getContext();
    renderer.getDrawingBufferSize(this.drawingBufferSize);
    if(this.drawingBufferSize.x!==width||this.drawingBufferSize.y!==height)renderer.setSize(width,height,false);
    const target=this.target;
    const direct=this.worldState===FRESH&&!target.samples&&target.width===width&&target.height===height;
    // The last frame blended its HUD into the world: redraw that world once.
    if(!direct&&this.worldState===BURNED)this.render(this.worldScene,this.worldCamera,{present:false});
    const worldPass=this.worldPass,dither=gl.isEnabled(gl.DITHER);
    const previousTarget=worldPass?worldPass.previous:renderer.getRenderTarget(),autoClear=renderer.autoClear;
    try{
      renderer.state.disable(gl.DITHER);
      renderer.autoClear=false;
      if(direct){
        if(!worldPass)renderer.setRenderTarget(target);
        renderer.setViewport(0,0,width,height);
        this.stats.hud=draw(renderer);
        this.worldState=BURNED;this.worldPass=null;
        gl.invalidateFramebuffer(gl.FRAMEBUFFER,[gl.DEPTH_ATTACHMENT]);
        renderer.setRenderTarget(previousTarget);
        renderer.setViewport(0,0,width,height);
        this.blit(this.exactMaterial,target.texture);
      }else{
        if(worldPass){this.worldPass=null;gl.invalidateFramebuffer(gl.FRAMEBUFFER,[gl.DEPTH_ATTACHMENT]);}
        if(!this.compositionTarget){
          // HUD meshes and glyphs never use depth.
          this.compositionTarget=new THREE.WebGLRenderTarget(width,height,{
            samples:target.samples,minFilter:THREE.NearestFilter,magFilter:THREE.NearestFilter,
            type:THREE.UnsignedByteType,format:THREE.RGBFormat,internalFormat:'RGB565',colorSpace:THREE.NoColorSpace,
            depthBuffer:false,stencilBuffer:false,generateMipmaps:false});
          this.compositionTarget.texture.name='Native RGB565 world and HUD framebuffer';
        }
        this.compositionTarget.setSize(width,height);
        if(this.worldState===FRESH)this.worldState=CLEAN;
        renderer.setRenderTarget(this.compositionTarget);
        renderer.setViewport(0,0,width,height);
        // Start from the clean world each time: paused HUD redraws must not
        // repeatedly darken partially transparent pixels from the previous HUD.
        // The opaque copy replaces every pixel, so skip loading the old contents.
        if(!target.samples)gl.invalidateFramebuffer(gl.FRAMEBUFFER,[gl.COLOR_ATTACHMENT0]);
        this.blit(this.material,target.texture);
        this.stats.hud=draw(renderer);
        renderer.setRenderTarget(previousTarget); // resolves HUD multisampling
        renderer.setViewport(0,0,width,height);
        this.blit(this.exactMaterial,this.compositionTarget.texture);
      }
      this.stats.presentation={...renderer.info.render,width,height};
    }finally{
      renderer.setRenderTarget(previousTarget);
      renderer.setViewport(0,0,width,height);
      renderer.autoClear=autoClear;
      if(dither)renderer.state.enable(gl.DITHER);else renderer.state.disable(gl.DITHER);
    }
  }
  dispose() {
    this.release();
    this.target?.dispose();this.target=null;
    this.compositionTarget?.dispose();this.compositionTarget=null;
    this.material.uniforms.image.value=null;this.exactMaterial.uniforms.image.value=null;
    this.material.dispose();this.exactMaterial.dispose();this.geometry.dispose();
  }
}
