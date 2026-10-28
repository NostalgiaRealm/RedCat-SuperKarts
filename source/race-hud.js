import {getHudStringSpec,getRaceHudText} from './hud-text.js';
import {HudTextRenderer} from './hud-text-renderer.js';
import {nativeHudDrawOrder} from './hud-draw-order.js';
import {measureRaceHudLayout} from './race-hud-layout.js';
import {createNativeHudNotifications,dispatchNativeHudNotification,
  updateNativeHudNotifications,getNativeHudNotificationOverride} from './hud-notifications.js';
import {getNativeGameplayHudNotificationId} from './hud-gameplay-events.js';
import {NativeLapDisplay} from './simulation/native-lap-display.js';

/** Draw the shipped HUD atlas, retaining native glyph sizes and placement. */
export class RaceHud {
  constructor(canvas,config,manifest){
    this.canvas=canvas;
    this.specs=new Map();
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
  async load(textureLoader){
    const ids=['string_lap','string_laptime','string_bestlap','string_lap_value',
      'string_lapof_value','string_laptime_value','string_bestlap_value','string_countdown_value',
      'string_bonus','string_special'];
    for(const id of ids){
      const spec=getHudStringSpec(this.config,id);this.specs.set(id,spec);
    }
    this.glyphs=new HudTextRenderer(this,textureLoader);
    await this.glyphs.load();
    this.textures=this.glyphs.textures;
    this.drawOrder=nativeHudDrawOrder(this.meshes.config,{extraElements:[...this.meshes.elements.keys()]});
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
      lapTimeMs:race.lapTimerMs??Math.min(race.lapTimerLimitMs,race.elapsedMs-race.lapStartMs),
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
    const {canvas}=this,rect=canvas.getBoundingClientRect();
    const dpr=devicePixelRatio||1,width=Math.round(rect.width*dpr),height=Math.round(rect.height*dpr);
    if(width===0||height===0)return;
    if(canvas.width!==width||canvas.height!==height){canvas.width=width;canvas.height=height;}
    const layout=measureRaceHudLayout(canvas,width,height);
    this.layout=layout;
    // The canvas now supplies only layout/accessibility metadata. Both meshes
    // and glyphs blend directly into the RGB565 race presentation surface.
    this.present?.(renderer=>this.draw(renderer,width,height,layout),width,height);
  }
  draw(renderer,width,height,layout){
    this.meshes.viewer.nativeBlendState?.setNative(5,6);
    const stats={calls:0,triangles:0,glyphs:0,order:[]};
    for(const id of this.drawOrder){
      let drawn=false;
      if(Object.hasOwn(this.text,id)){
        const count=this.glyphs.renderString(renderer,id,this.text[id],width,height,layout);
        stats.glyphs+=count;drawn=count>0;
      }else drawn=this.meshes.renderElement(renderer,id,width,height,layout);
      if(drawn){
        stats.calls+=renderer.info.render.calls;stats.triangles+=renderer.info.render.triangles;
        stats.order.push(id);
      }
    }
    this.stats=stats;return stats;
  }
  dispose(){
    this.present=null;this.glyphs?.dispose();
  }
}
