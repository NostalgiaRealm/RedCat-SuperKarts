/** 424360 / 424f70: original country/driver wait screen and seven progress images. */
export function createLoadingScreen(manifest,track,character){
  const root=document.createElement('div');root.className='native-wrap';
  const stage=document.createElement('div');stage.className='native-stage';stage.dataset.form='RACE_LOADING';
  stage.style.setProperty('--native-aspect',640/480);root.append(stage);
  const background=document.createElement('img');background.className='native-image';
  background.alt='';background.draggable=false;background.style.cssText='inset:0;width:100%;height:100%';
  const backgroundKey=`e0${track}_${String.fromCharCode(97+character)}_hi.tga`;
  if(!manifest.images[backgroundKey])throw Error(`Original loading image missing: ${backgroundKey}`);
  background.src='/assets/'+manifest.images[backgroundKey].file;stage.append(background);
  const progress=document.createElement('img');progress.className='native-image';progress.alt='';
  // 640×480 high-colour blit rectangle: [194,416,444,479].
  progress.style.cssText='left:30.3125%;top:86.6666667%;width:39.0625%;height:13.125%';
  stage.append(progress);
  const update=percent=>{
    const frame=Math.min(7,Math.trunc(percent*7/100)+1);
    const spec=manifest.images[`image_0${frame}.tga`];
    if(!spec)throw Error(`Original loading progress image missing: ${frame}`);
    progress.src='/assets/'+spec.file;
  };
  update(0);return {root,update};
}
