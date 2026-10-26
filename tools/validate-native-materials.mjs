// Module-level browser diagnostic: start tools/serve.mjs with --inspect-source.
import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {writeFile,mkdir} from 'node:fs/promises';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
try{
  const page=await browser.newPage();
  const errors=[];page.on('pageerror',e=>errors.push(e.message));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/assets/manifest.json');
  await page.setContent('<script type="importmap">{"imports":{"three":"/node_modules/three/build/three.module.js","three/addons/":"/node_modules/three/examples/jsm/"}}</script>');
  const checks=await page.evaluate(async()=>{
    const THREE=await import('three');
    const {createNativeMeshMaterial,applyNativeByteColorPipeline}=await import('/source/asset-materials.js');
    const renderer=new THREE.WebGLRenderer({alpha:false,antialias:false,preserveDrawingBuffer:true});
    renderer.setSize(8,8);renderer.outputColorSpace=THREE.SRGBColorSpace;
    // A deliberately non-native renderer default must not tone-map these assets.
    renderer.toneMapping=THREE.ACESFilmicToneMapping;
    const gl=renderer.getContext(), camera=new THREE.OrthographicCamera(-1,1,1,-1,0,10);
    camera.position.z=2;
    const scene=new THREE.Scene(), geometry=new THREE.PlaneGeometry(2,2);
    geometry.setAttribute('color',new THREE.Uint8BufferAttribute(new Uint8Array(16).fill(255),4,true));
    const texture=new THREE.DataTexture(new Uint8Array([128,64,192,255]),1,1);
    texture.colorSpace=THREE.SRGBColorSpace;texture.needsUpdate=true;
    const backgroundTexture=new THREE.DataTexture(new Uint8Array([32,96,160,255]),1,1);backgroundTexture.needsUpdate=true;
    const background=applyNativeByteColorPipeline(new THREE.MeshBasicMaterial({map:backgroundTexture}));
    const back=new THREE.Mesh(new THREE.PlaneGeometry(2,2),background);
    back.position.z=-.5;scene.add(back);
    const materials=Array.from({length:4},(_,blendMode)=>createNativeMeshMaterial(texture,{blendMode}));
    const front=new THREE.Mesh(geometry,materials[0]);scene.add(front);
    const rows=[];
    const values=[0,1,32,64,128,192,254,255];
    for(const mode of [0,1,2,3])for(const value of values){
      const vertex=[value,255-value,128,value];
      for(let i=0;i<4;i++)geometry.attributes.color.array.set(vertex,i*4);
      geometry.attributes.color.needsUpdate=true;front.material=materials[mode];
      renderer.render(scene,camera);
      const actual=new Uint8Array(4);gl.readPixels(4,4,1,1,gl.RGBA,gl.UNSIGNED_BYTE,actual);
      const texel=[128,64,192],destination=[32,96,160],alpha=value/255;
      const source=texel.map((c,i)=>c*vertex[i]/255);
      const expected=source.map((s,i)=>Math.round(mode===0?s:mode===2?s+destination[i]*(1-s/255):s*alpha+destination[i]*(1-alpha)));
      rows.push({mode,texel,vertex,destination,expected,actual:[...actual].slice(0,3)});
    }
    for(const material of materials)material.dispose();
    background.dispose();texture.dispose();backgroundTexture.dispose();
    geometry.dispose();back.geometry.dispose();renderer.dispose();
    return rows;
  });
  assert.deepEqual(errors,[]);
  for(const row of checks)row.actual.forEach((value,i)=>assert.ok(Math.abs(value-row.expected[i])<=1,JSON.stringify(row)));
  await mkdir('evidence/native',{recursive:true});
  await writeFile('evidence/native/material-webgl-pixels.json',JSON.stringify({
    browser:browser.version(),renderer:'Chromium SwiftShader WebGL2, direct sRGB canvas',
    basis:'Original D3DTBLEND_MODULATE plus recovered blend factors; stored-byte arithmetic. 1-byte raster rounding tolerance.',
    limitation:'Does not establish original GPU texture-format quantization, filtering or display gamma ramp.',checks
  },null,2)+'\n');
  console.log(`Verified ${checks.length} actual WebGL pixel samples against original byte-space modulation/blending.`);
}finally{await browser.close();}
