import {nativeRaceKeyDown,nativeQuitRequesterChoice} from './simulation/native-race-lifecycle.js';

/** Resumable 0x42f290 / 0x474040 / 0x4743b0 / 0x473fb0 requester input. */
export class NativeQuitRequester {
  constructor(){
    this.stage='initial-release';this.heldKey=null;this.code=-1;
    this.startedMs=null;this.pressed=null;this.done=false;
  }
  /** Pointer-down, or the host's focused-button/controller activation. */
  choose(code,nowMs){
    if(this.stage!=='input'||nativeQuitRequesterChoice(code)===null)return false;
    this.code=code;this.pressed=nativeQuitRequesterChoice(code)?'yes':'no';
    this.startedMs=nowMs>>>0;this.stage='pressed';return true;
  }
  update(keys={},nowMs=0){
    if(this.done)return this.snapshot();
    if(this.stage==='initial-release'){
      if(nativeRaceKeyDown(keys,27))return this.snapshot();
      this.stage='input';
    }
    if(this.stage==='key-release'){
      if(nativeRaceKeyDown(keys,this.heldKey))return this.snapshot();
      const code=this.heldKey===74?0:1;
      this.heldKey=null;this.stage='input';this.choose(code,nowMs);
    }else if(this.stage==='input'){
      // Native keyboard priority and Shift filtering precede the mouse poll.
      const key=[74,78,27].find(code=>nativeRaceKeyDown(keys,code));
      if(key!==undefined){this.heldKey=key;this.stage='key-release';}
    }
    if(this.stage==='pressed'&&(((nowMs>>>0)-this.startedMs)>>>0)>=100){
      this.done=true;this.stage='done';this.pressed=null;
    }
    return this.snapshot();
  }
  snapshot(){return {stage:this.stage,heldKey:this.heldKey,code:this.code,
    startedMs:this.startedMs,pressed:this.pressed,done:this.done};}
}
