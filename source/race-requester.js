import {resolveAsset} from './asset-animation.js';
import {assetURL} from './asset-url.js';
import {NativeQuitRequester} from './native-quit-requester.js';

/** The race executable's SndGfx.ini STOPPEN screen (0x470860/0x473f20). */
export function createRaceQuitRequester(config,manifest,onChoice,{onPress,now=()=>performance.now()}={}){
  const definitions=config['sndgfx.ini'].stoppen;
  const image=name=>{
    const [source,x,y]=definitions['h'+name].split(',');
    const file=resolveAsset(manifest,'images',source+'.tga');
    if(!file)throw new Error(`Missing original race requester image: ${source}`);
    return {url:assetURL('assets/'+file),x:Number(x),y:Number(y)};
  };
  const wrap=document.createElement('div');wrap.className='native-wrap';
  const stage=document.createElement('div');stage.className='native-stage race-requester';
  stage.dataset.form='RACE_STOPPEN';stage.style.aspectRatio='640/480';
  stage.style.background=`url("${image('background').url}") center/100% 100% no-repeat`;
  stage.style.cursor=`url("${image('mouse').url}") 0 0, auto`;
  const controller=new NativeQuitRequester(),buttons=[];
  let notifiedPress=false,notifiedChoice=false;
  const sync=()=>{
    stage.dataset.state=controller.stage;
    stage.setAttribute('aria-busy',String(controller.stage==='pressed'));
    for(const button of buttons){
      button.dataset.pressed=String(button.dataset.choice===controller.pressed);
      button.setAttribute('aria-disabled',String(controller.stage!=='input'));
    }
    // Like 0x473fb0, choose the pressed sprite and sound once. Completion is
    // driven by the host's UI clock, independently of the suspended race.
    if(controller.startedMs!==null&&!notifiedPress){notifiedPress=true;onPress?.(controller.code);}
    if(controller.done&&!notifiedChoice){notifiedChoice=true;onChoice(controller.code);}
    return controller.snapshot();
  };
  wrap.update=(keys,time=now())=>{controller.update(keys,time);return sync();};
  wrap.choose=(choice,time=now())=>{const accepted=controller.choose(choice,time);sync();return accepted;};
  Object.defineProperties(wrap,{
    requesterState:{get:()=>controller.snapshot()},
    stage:{get:()=>controller.stage},
    pending:{get:()=>controller.stage==='pressed'||controller.stage==='key-release'},
  });
  for(const [name,label,choice]of [['yes','Ja',2],['no','Nee',3]]){
    const normal=image(name+'_normal'),hover=image(name+'_focus'),pressed=image(name+'_pressed');
    const button=document.createElement('button');button.className='race-requester-button';
    button.ariaLabel=label;button.dataset.choice=name;
    button.style.cssText=`left:${normal.x/640*100}%;top:${normal.y/480*100}%;width:${115/640*100}%;height:${38/480*100}%;--up:url("${normal.url}");--hover:url("${hover.url}");--down:url("${pressed.url}")`;
    // 0x474040 accepts the held left mouse button, before its release. Click
    // remains available for keyboard/controller and accessibility activation.
    button.onpointerdown=event=>{if(event.button===0){event.preventDefault();button.focus();wrap.choose(choice);}};
    button.onclick=()=>wrap.choose(choice);buttons.push(button);stage.append(button);
  }
  wrap.append(stage);sync();return wrap;
}
