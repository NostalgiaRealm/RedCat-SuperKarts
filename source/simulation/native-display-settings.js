/** Menu45b334 writes these fields; race42b220/42cff0 consume them.
 * Only explicit browser choices override the original configuration.
 */
export function configWithNativeDisplaySettings(config,display) {
  if(!display)return config;
  const options={...config['game.ini'].options},graphics={...config['sndgfx.ini']['gfx options']};
  if(typeof display.bilinearFiltering==='boolean')options.filter=display.bilinearFiltering?'2':'0';
  if(typeof display.brightnessLight==='boolean')graphics.gamma=display.brightnessLight?'0':'1';
  if(typeof display.alphaBlending==='boolean')graphics.alpha_blending=display.alphaBlending?'2':'0';
  if(typeof display.particles==='boolean')graphics.particles=display.particles?'1':'0';
  return {...config,'game.ini':{...config['game.ini'],options},
    'sndgfx.ini':{...config['sndgfx.ini'],'gfx options':graphics}};
}

/** The RGB converter4b5470 squares each channel before packing when gamma!=0.
 * Standalone pre-pack operation retained for original instruction comparisons;
 * the runtime uploader combines it with key handling and RGB565 packing.
 */
export function nativeTextureGamma(bytes,enabled) {
  const result=new Uint8ClampedArray(bytes);
  if(enabled)for(let i=0;i<result.length;i+=4)
    for(let c=0;c<3;c++)result[i+c]=(result[i+c]*result[i+c])>>8;
  return result;
}
