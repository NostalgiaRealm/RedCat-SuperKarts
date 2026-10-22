// Native menu wrappers 0x45c668 (generic) and 0x45c518 (character).
// This single voice channel follows sndPlaySound's replacement semantics.
import {NATIVE_MENU_GAIN} from './audio-mixing.js';
export class MenuAudio {
  constructor(configs,volume=()=>1,manifest={}){this.configs=configs;this.volume=volume;this.manifest=manifest;this.audio=null;this.finish=null;this.last=null;this.missing=new Set();}
  generic(id,wait=false){return this.play(this.configs['ini/soundset.dat']?.generic_samples?.[id],wait);}
  character(character,id,wait=false){
    const files=['rc_snd.dat','wk_snd.dat','br_snd.dat','mx_snd.dat'];
    return this.play(this.configs['ini/'+files[character]]?.sample_set?.[id],wait);
  }
  async play(file,wait=false){
    this.stop();if(!file)return false;this.last=file.toLowerCase();
    const asset=this.manifest.audio?.[this.last];
    // Five referenced samples are absent from both original installation and
    // CD. Preserve their silent failure rather than substitute other sounds.
    if(!asset){this.missing.add(this.last);return false;}
    const audio=new Audio('/assets/'+asset.file);audio.volume=NATIVE_MENU_GAIN;this.audio=audio;
    const completion=new Promise(resolve=>{this.finish=resolve;audio.onended=()=>resolve(true);audio.onerror=()=>resolve(false);});
    try{await audio.play();}catch{return false;}
    return wait?completion:true;
  }
  setVolume(){if(this.audio)this.audio.volume=NATIVE_MENU_GAIN;}
  stop(){this.audio?.pause();this.finish?.(false);this.audio=null;this.finish=null;}
}
