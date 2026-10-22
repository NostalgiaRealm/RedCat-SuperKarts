import * as THREE from 'three';

/** Choose a count actually supported by BOTH the color and depth attachment.
 * Some WebGL devices only advertise 4 samples, even for a request of 2. */
export function chooseMultisampleCount(requested,supported) {
  const values=[...new Set(supported.filter(value=>Number.isInteger(value)&&value>=2))].sort((a,b)=>a-b);
  return values.filter(value=>value<=requested).at(-1)??values[0]??0;
}

export function supportedMultisampleCounts(gl) {
  const counts=format=>Array.from(gl.getInternalformatParameter(gl.RENDERBUFFER,format,gl.SAMPLES)??[]);
  const depth=new Set(counts(gl.DEPTH_COMPONENT24));
  return [...new Set(counts(gl.RGB565).filter(value=>value>=2&&depth.has(value)))].sort((a,b)=>a-b);
}

/** Native 16-bit race/track framebuffer, with optional WebGL2 multisampling.
 * The supplied RESOLUTION3 selects a 16-bit display; choose its RGB565 profile
 * consistently with native texture upload. A real RGB565 attachment rounds
 * each write/blend, which a final 8-bit postprocessing pass cannot reproduce.
 * Materials and resolve/copy keep display-byte RGB without another sRGB
 * transfer. The separately sized original HUD stays separate. */
export class MultisampleSceneRenderer {
  constructor(renderer) {
    this.renderer=renderer;
    this.supportedSamples=supportedMultisampleCounts(renderer.getContext());
    this.status={enabled:false,requestedSamples:4,actualSamples:0,supportedSamples:[...this.supportedSamples]};
    this.target=null;
    this.scene=new THREE.Scene();this.camera=new THREE.Camera();
    this.geometry=new THREE.BufferGeometry();
    this.geometry.setAttribute('position',new THREE.Float32BufferAttribute([-1,-1,0,3,-1,0,-1,3,0],3));
    this.material=new THREE.RawShaderMaterial({
      uniforms:{image:{value:null}},depthTest:false,depthWrite:false,blending:THREE.NoBlending,
      vertexShader:'precision highp float; attribute vec3 position; varying vec2 uv; void main(){uv=position.xy*.5+.5;gl_Position=vec4(position,1.0);}',
      fragmentShader:'precision highp float; uniform sampler2D image; varying vec2 uv; void main(){gl_FragColor=vec4(texture2D(image,uv).rgb,1.0);}',
    });
    const mesh=new THREE.Mesh(this.geometry,this.material);mesh.frustumCulled=false;this.scene.add(mesh);
    this.clearColor=new THREE.Color();this.byteClearColor=new THREE.Color();
    this.drawingBufferSize=new THREE.Vector2();
  }
  configure(settings,width,height) {
    const enabled=settings.msaaEnabled===true;
    const requestedSamples=[2,4,8].includes(settings.msaaSamples)?settings.msaaSamples:4;
    const actualSamples=enabled?chooseMultisampleCount(requestedSamples,this.supportedSamples):0;
    this.status={enabled,requestedSamples,actualSamples,supportedSamples:[...this.supportedSamples]};
    if(this.target&&this.target.samples!==actualSamples){this.target.dispose();this.target=null;}
    if(!this.target){
      this.target=new THREE.WebGLRenderTarget(width,height,{samples:actualSamples,
        minFilter:THREE.NearestFilter,magFilter:THREE.NearestFilter,
        type:THREE.UnsignedByteType,format:THREE.RGBFormat,internalFormat:'RGB565',colorSpace:THREE.NoColorSpace,
        depthBuffer:true,stencilBuffer:false,generateMipmaps:false});
      this.target.texture.name='Native RGB565 race framebuffer';
    }
    if(this.target)this.target.setSize(width,height);
    this.material.uniforms.image.value=this.target?.texture??null;
    return this.status;
  }
  render(scene,camera) {
    const renderer=this.renderer,gl=renderer.getContext();
    // Inspection callers can render before the first settings/resize event.
    if(!this.target){
      renderer.getDrawingBufferSize(this.drawingBufferSize);
      this.configure({},this.drawingBufferSize.x,this.drawingBufferSize.y);
    }
    const target=this.target,dither=gl.isEnabled(gl.DITHER);
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
      renderer.setRenderTarget(previousTarget); // resolves the multisample attachments
      renderer.autoClear=false;
      renderer.render(this.scene,this.camera);
    } finally {
      scene.background=background;
      renderer.setRenderTarget(previousTarget);
      renderer.setClearColor(this.clearColor,clearAlpha);
      renderer.autoClear=autoClear;
      if(dither)renderer.state.enable(gl.DITHER);else renderer.state.disable(gl.DITHER);
    }
  }
  dispose() {
    this.target?.dispose();this.target=null;
    this.material.uniforms.image.value=null;
    this.material.dispose();this.geometry.dispose();
  }
}
