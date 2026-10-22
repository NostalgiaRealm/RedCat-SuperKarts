import {getHudStringSpec,layoutHudText,getRaceHudText} from './hud-text.js';
import {resolveAsset} from './asset-animation.js';
import {measureRaceHudLayout} from './race-hud-layout.js';
import {createNativeHudNotifications,dispatchNativeHudNotification,
  updateNativeHudNotifications,getNativeHudNotificationOverride} from './hud-notifications.js';
import {getNativeGameplayHudNotificationId} from './hud-gameplay-events.js';
import {NativeLapDisplay} from './simulation/native-lap-display.js';

/** Draw the shipped HUD atlas, retaining native glyph sizes and placement. */
export class RaceHud {
  constructor(canvas,config,manifest){
    this.canvas=canvas;
    this.context=canvas.getContext('2d');
    this.specs=new Map();
    this.images=new Map();
    this.config=config;this.manifest=manifest;
    this.text={};
    this.lapDisplay=new NativeLapDisplay();
    this.lapCount=0;this.nowSeconds=0;
    this.notifications=createNativeHudNotifications();
    this.lastElapsedMs=0;
    this.notificationEvents=new WeakSet();
    this.specialOverride=null;
    this.filter=2;
  }
  async load(imageLoader=null){
    const pending=[];
    const ids=['string_lap','string_laptime','string_bestlap','string_lap_value',
      'string_lapof_value','string_laptime_value','string_bestlap_value','string_countdown_value',
      'string_bonus','string_special'];
    for(const id of ids){
      const spec=getHudStringSpec(this.config,id);this.specs.set(id,spec);
      for(const glyph of Object.values(spec.font.glyphs)){
        if(this.images.has(glyph.texture))continue;
        const file=resolveAsset(this.manifest,'images',glyph.texture);
        if(!file)throw Error(`Original HUD image missing: ${glyph.texture}`);
        this.images.set(glyph.texture,null);
        if(imageLoader)pending.push(Promise.resolve(imageLoader(file)).then(image=>this.images.set(glyph.texture,image)));
        else{
          const image=new Image();image.src='/assets/'+file;
          this.images.set(glyph.texture,image);pending.push(image.decode());
        }
      }
    }
    await Promise.all(pending);
  }
  notify(id,deltaSeconds=0,{capture=false,lapCount=this.lapCount,nowSeconds=this.nowSeconds}={}){
    if(id===8)this.lapDisplay.notifyLap({lapCount,nowSeconds});
    const event=dispatchNativeHudNotification(this.notifications,this.config,id,deltaSeconds);
    if(capture)this.captureNotification();
    return event;
  }
  captureNotification(){
    this.specialOverride=getNativeHudNotificationOverride(this.notifications);
    if(this.notifications.visible)this.text.string_special=this.notifications.text;
    else delete this.text.string_special;
  }
  processEvents(events,deltaSeconds=0,{playerIndex,lapCount=this.lapCount,nowSeconds=this.nowSeconds}={}){
    for(const event of events){
      if(this.notificationEvents.has(event))continue;
      this.notificationEvents.add(event);
      const id=getNativeGameplayHudNotificationId(event,{playerIndex});
      if(id!==undefined)this.notify(id,deltaSeconds,{lapCount,nowSeconds});
    }
  }
  update(race,deltaSeconds=Math.max(0,race.elapsedMs-this.lastElapsedMs)/1000,
    {nowSeconds=race.elapsedMs/1000}={}){
    this.lastElapsedMs=race.elapsedMs;
    this.lapCount=race.lapCount;this.nowSeconds=nowSeconds;
    this.processEvents(race.events,deltaSeconds);
    updateNativeHudNotifications(this.notifications,deltaSeconds);
    const values=getRaceHudText({lapCounter:race.lapCount,totalLaps:race.lapLimit,
      lapTimeMs:Math.min(race.lapTimerLimitMs,race.elapsedMs-race.lapStartMs),
      bestLapTimeMs:race.bestLapMs,
      countdownTimeMs:race.raceType===1?race.remainingMs:null});
    values.string_laptime_value=this.lapDisplay.update({lapText:values.string_laptime_value,nowSeconds});
    this.text={
      string_lap:this.specs.get('string_lap').text,
      string_laptime:this.specs.get('string_laptime').text,
      string_bestlap:this.specs.get('string_bestlap').text,
      string_bonus:this.specs.get('string_bonus').text,
      ...values,
    };
    this.captureNotification();
  }
  render(){
    const {canvas,context:ctx}=this,rect=canvas.getBoundingClientRect();
    const dpr=devicePixelRatio||1,width=Math.round(rect.width*dpr),height=Math.round(rect.height*dpr);
    if(width===0||height===0)return;
    if(canvas.width!==width||canvas.height!==height){canvas.width=width;canvas.height=height;}
    ctx.setTransform(1,0,0,1,0,0);ctx.clearRect(0,0,width,height);
    const layout=measureRaceHudLayout(canvas,width,height);
    this.layout=layout;
    this.meshes?.render(ctx,width,height,layout);
    // Captured once per native overlay pass; modern redraws do not advance
    // 462320/462610's persistent sampler cache.
    ctx.imageSmoothingEnabled=this.filter===2;
    const {scale}=layout;
    for(const [id,text]of Object.entries(this.text)){
      const spec=id==='string_special'?getHudStringSpec(this.config,id,{overrides:{
        [id]:this.specialOverride,
      }}):this.specs.get(id);
      if(!spec.visible)continue;
      const {x,y}=layout.text(id);
      ctx.setTransform(scale,0,0,scale,x,y);
      ctx.globalAlpha=spec.rgba[3]/255;
      for(const glyph of layoutHudText(spec,text)){
        const s=glyph.source;
        ctx.drawImage(this.images.get(s.texture),s.x,s.y,s.width,s.height,
          glyph.x,glyph.y,glyph.width,glyph.height);
      }
    }
    ctx.globalAlpha=1;
  }
}
