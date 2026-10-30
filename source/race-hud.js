import {getHudStringSpec,getRaceHudText} from './hud-text.js';
import {HudTextRenderer} from './hud-text-renderer.js';
import {nativeHudDrawOrder} from './hud-draw-order.js';
import {RaceHudLayoutCache} from './race-hud-layout.js';
import {createNativeHudNotifications,dispatchNativeHudNotification,
  updateNativeHudNotifications,getNativeHudNotificationOverride} from './hud-notifications.js';
import {getNativeGameplayHudNotificationId} from './hud-gameplay-events.js';
import {NativeLapDisplay} from './simulation/native-lap-display.js';
import * as THREE from 'three';

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
    this.meshes.batch(this.drawOrder);
    // Consecutive items sharing a camera render in one pass; renderOrder keeps
    // the native child-list order, the transparent sort is stable on it.
    this.runs=[];
    this.drawOrder.forEach((id,index)=>{
      const text=this.specs.has(id),element=this.meshes.elements.get(id);
      if(!text&&!element)return;
      if(this.runs.at(-1)?.text!==text){
        const scene=new THREE.Scene();scene.matrixAutoUpdate=false;
        this.runs.push({text,ids:[],scene,items:[]});
      }
      const run=this.runs.at(-1);run.ids.push(id);
      if(!text&&element.mesh.parent.parent!==run.scene)run.scene.add(element.mesh.parent);
    });
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
    const dpr=this.pixelRatio??(devicePixelRatio||1),width=Math.round(rect.width*dpr),height=Math.round(rect.height*dpr);
    if(width===0||height===0){this.invalidateLayout();return;}
    if(canvas.width!==width||canvas.height!==height){canvas.width=width;canvas.height=height;}
    const layout=(this.layoutCache??=new RaceHudLayoutCache(canvas)).get(width,height,dpr);
    this.layout=layout;
    // The canvas now supplies only layout/accessibility metadata. Both meshes
    // and glyphs blend directly into the RGB565 race presentation surface.
    this.present?.(renderer=>this.draw(renderer,width,height,layout),width,height);
  }
  invalidateLayout(){if(this.layoutCache)this.layoutCache.dirty=true;}
  draw(renderer,width,height,layout){
    this.meshes.viewer.nativeBlendState?.setNative(5,6);
    const stats=this.stats??={calls:0,triangles:0,glyphs:0,order:[]},order=stats.order,glyphs=this.glyphs;
    stats.calls=stats.triangles=stats.glyphs=order.length=0;
    if(this.layoutApplied!==layout){this.layoutApplied=layout;this.meshes.applyLayout(layout,height);}
    for(const run of this.runs){
      let drawn=0;
      if(run.text){
        for(const id of run.ids){
          if(!Object.hasOwn(this.text,id)){const e=glyphs.strings.get(id);if(e?.mesh)e.mesh.visible=false;continue;}
          const count=glyphs.prepareString(id,this.text[id],width,height,layout);
          const entry=glyphs.strings.get(id);
          if(entry.mesh){
            if(entry.mesh.parent!==run.scene){run.scene.add(entry.mesh);entry.mesh.renderOrder=this.drawOrder.indexOf(id);}
            entry.mesh.visible=count>0;
          }
          stats.glyphs+=count;
          if(count>0){order.push(id);drawn++;}
        }
        if(!drawn)continue;
        renderer.setViewport(0,0,width,height);
        renderer.render(run.scene,glyphs.camera);
      }else{
        for(const id of run.ids)if(this.meshes.elements.get(id).mesh.visible){order.push(id);drawn++;}
        if(!drawn)continue;
        renderer.render(run.scene,this.meshes.camera);
      }
      stats.calls+=renderer.info.render.calls;stats.triangles+=renderer.info.render.triangles;
    }
    return stats;
  }
  dispose(){
    this.present=null;this.glyphs?.dispose();this.layoutCache?.dispose();
  }
}
