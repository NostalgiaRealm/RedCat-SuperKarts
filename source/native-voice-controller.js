import {getSoundSpec} from './asset-animation.js';
import {getNativeSpatialAudioCommands} from './spatial-audio.js';
import {nativeTrigTable} from './simulation/native-integrator.js';
import {NATIVE_PRECISION} from './simulation/native-precision.js';
const f=Math.fround;

/** Voice logical IDs0..9 follow original character IDs;10 is shared EFFECTS.
 * Only roster banks are loaded, in NPC-first/player-last order437560. */
export class NativeVoiceController{
 constructor(config,manifest,racerCharacters,{enabled=true,precision=NATIVE_PRECISION}={}){
  this.enabled=enabled;this.precision=precision;this.playerIndex=racerCharacters.length-1;
  this.racerByVoice=Array(11).fill(this.playerIndex);
  this.banks=Array.from({length:11},()=>[]);
  const source=config['rcrsound.ini'];
  const load=(voiceId,sectionName)=>{
   const section=source[sectionName.toLowerCase()];
   this.banks[voiceId]=Array.from({length:Number(section.count)},(_,index)=>{
    const sample=section[index],event=section[sample.toLowerCase()];
    const sound=getSoundSpec(config,manifest,event);
    if(!sound)throw new Error(`Original voice ${voiceId}/${sample} has no Sound.ini event ${event}`);
    return{sample,event,sound};
   });
  };
  racerCharacters.forEach((character,racer)=>{
   load(character,source.voices[character]);this.racerByVoice[character]=racer;
  });
  load(10,'effects');
  this.voices=Array.from({length:11},()=>({current:-1,queue:[]}));
 }
 /**436d70 replaces immediately;436b10 preserves FIFO and missing-name failure. */
 request({voiceId,sample,replace=false}){
  const voice=this.voices[voiceId],bank=this.banks[voiceId];
  if(!voice)throw new RangeError('Original voice ID must be0..10');
  const commands=[];
  if(replace){
   if(voice.current>=0)commands.push({event:bank[voice.current].event,op:'stop'});
   voice.current=-1;voice.queue.length=0;
  }
  if(!this.enabled)return{accepted:true,commands};
  const index=bank.findIndex(entry=>entry.sample===sample);
  if(index<0)return{accepted:false,commands};
  voice.queue.push(index);return{accepted:true,commands};
 }
 clear(){
  const commands=[];
  this.voices.forEach((voice,id)=>{
   if(voice.current>=0)commands.push({event:this.banks[id][voice.current].event,op:'stop'});
   voice.current=-1;voice.queue.length=0;
  });
  return commands;
 }
 /** One native436760 update. Spatial rendering may stop an out-of-range
  * sample; the next queued sample waits until the next controller tick. */
 advanceVoice(voiceId,isPlaying){
  const voice=this.voices[voiceId],bank=this.banks[voiceId];
  if(voice.current>=0&&isPlaying(bank[voice.current].event))return bank[voice.current];
  if(voice.queue.length){voice.current=voice.queue.shift();return bank[voice.current];}
  voice.current=-1;return null;
 }
 service({listener,bodies,isPlaying,baseVolume,execute=()=>{}}){
  if(!this.enabled)return[];
  const result=[];
  for(let voiceId=0;voiceId<11;voiceId++){
   const entry=this.advanceVoice(voiceId,isPlaying);if(!entry)continue;
   const body=bodies[this.racerByVoice[voiceId]];
   const commands=getNativeSpatialAudioCommands({
    position:body.position,velocity:nativeVoiceVelocity(body,this.precision),
    listenerPosition:listener.position,listenerForward:listener.forward,listenerVelocity:listener.velocity,
    range:Number(entry.sound.fields[4]),baseVolume:baseVolume?.(entry.event)??Number(entry.sound.fields[3]),
    doppler:Number(entry.sound.fields[5]),playing:isPlaying(entry.event),loop:false,precision:this.precision,
   }).map(command=>({...command,event:entry.event,spatial:true}));
   execute(commands);result.push(...commands);
  }
  return result;
 }
}

/**436980 actor sound source velocity, native yaw and localX/Z body speeds. */
export function nativeVoiceVelocity(body,precision=NATIVE_PRECISION){
 const r=precision===24?f:Number,{sin,cos}=nativeTrigTable(precision),index=Math.trunc(body.yaw)&4095;
 return[f(r(r(cos[index]*body.lateralSpeed)-r(sin[index]*body.forwardSpeed))),0,
  f(r(r(sin[index]*body.lateralSpeed)+r(cos[index]*body.forwardSpeed)))];
}
