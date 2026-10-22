export const KEYS=Object.freeze({ArrowUp:'accelerate',ArrowDown:'brake',ArrowLeft:'left',ArrowRight:'right',ControlLeft:'bonus',ControlRight:'bonus',AltLeft:'handbrake',AltRight:'handbrake'});
export function axisDeadzone(value,deadzone=.18){
  if(!Number.isFinite(value))return 0;
  const magnitude=Math.min(1,Math.abs(value)),limit=Math.min(.99,Math.max(0,deadzone));
  return magnitude<=limit?0:Math.sign(value)*(magnitude-limit)/(1-limit);
}
export class InputState {
  constructor(){this.sources=new Map();this.keys=new Set();this.analog=null;}
  set(source,action,value=1){if(!value){this.release(source);return;}this.sources.set(source,{action,value});}
  release(source){this.sources.delete(source);}
  clear(){this.sources.clear();this.keys.clear();this.analog=null;}
  value(action){
    // Native4b3880 rejects unmodified keyboard bindings while Shift is held.
    // Retain the held source so releasing Shift resumes it without a new
    // keydown; touch and joystick sources do not use this keyboard poll.
    const shift=this.keys.has(16)||this.keys.has('Shift');
    let value=0;
    for(const [source,s]of this.sources)
      if(s.action===action&&!(shift&&source.startsWith('key:')))value=Math.max(value,s.value);
    return value;
  }
  snapshot(){
    const state={throttle:this.value('accelerate'),brake:this.value('brake'),steer:this.value('right')-this.value('left'),handbrake:this.value('handbrake'),bonus:this.value('bonus')};
    if(this.analog&&![...this.sources.keys()].some(key=>!key.startsWith('pad:')))state.analog={...state};
    if(this.freeFlightActive)state.lift=Math.max(this.value('flightUp'),this.keys.has(32)?1:0)
      -Math.max(this.value('flightDown'),this.keys.has(67)?1:0);
    return state;
  }
}
export class InputController {
  constructor({onMenu,onPause,onActivity,onKeysChanged,deadzone=()=>.18,bindings=null,window:win=window}={}){
    this.state=new InputState();this.win=win;this.onMenu=onMenu;this.onPause=onPause;this.onActivity=onActivity;this.deadzone=deadzone;this.mode='menu';this.lastPadButtons=new Map();this.lastMenuTime=0;this.padId=null;
    this.abort=new AbortController();const opts={signal:this.abort.signal};
    win.addEventListener('keydown',e=>{
      if(e.keyCode)this.state.keys.add(e.keyCode);
      onKeysChanged?.();
      if(['INPUT','SELECT','TEXTAREA'].includes(e.target.tagName))return;
      if(e.code==='Escape'){if(!e.repeat)this.onPause?.();return;}
      if(e.code==='KeyP'&&this.mode!=='menu'){if(!e.repeat)this.onPause?.('pause');return;}
      if(this.mode==='menu'){if(['ArrowUp','ArrowDown','ArrowLeft','ArrowRight','Enter','Space'].includes(e.code)){e.preventDefault();if(!e.repeat)this.onMenu?.(e.code);}return;}
      if(this.state.freeFlightActive&&['Space','KeyC'].includes(e.code)){
        e.preventDefault();this.state.set('key:'+e.code,e.code==='Space'?'flightUp':'flightDown');this.onActivity?.();return;
      }
      const normalized=code=>code.replace(/^(Control|Alt|Shift)Right$/,'$1Left');
      const action=bindings?Object.entries(bindings()).find(([,code])=>normalized(code)===normalized(e.code))?.[0]:KEYS[e.code];
      if(action){e.preventDefault();this.state.set('key:'+e.code,action);this.onActivity?.();}
    },opts);
    win.addEventListener('keyup',e=>{this.state.release('key:'+e.code);this.state.keys.delete(e.keyCode);onKeysChanged?.();},opts);
    win.addEventListener('blur',()=>this.suspend(),opts);
    win.document.addEventListener('visibilitychange',()=>{if(win.document.hidden)this.suspend();},opts);
    win.addEventListener('gamepaddisconnected',e=>{const active=this.padId===e.gamepad?.id;this.clearPad();if(active)this.onPause?.('focus');},opts);
  }
  suspend(){this.state.clear();this.clearPad();this.onPause?.('focus');}
  clearPad(){for(const key of this.state.sources.keys())if(key.startsWith('pad:'))this.state.release(key);for(const key of ['Enter','P'])this.state.keys.delete(key);this.state.analog=null;this.lastPadButtons.clear();this.padId=null;}
  setMode(mode){this.mode=mode;this.state.clear();}
  bindTouch(element,action){
    const opts={signal:this.abort.signal};
    element.addEventListener('pointerdown',e=>{e.preventDefault();element.setPointerCapture(e.pointerId);this.state.set('pointer:'+e.pointerId,action);element.classList.add('held');this.onActivity?.();},opts);
    const release=e=>{this.state.release('pointer:'+e.pointerId);element.classList.remove('held');};
    for(const event of ['pointerup','pointercancel','lostpointercapture'])element.addEventListener(event,release,opts);
  }
  poll(time){
    let pads;try{pads=this.win.navigator.getGamepads?.()||[];}catch{this.clearPad();return;}
    const pad=Array.from(pads).find(p=>p&&p.connected&&p.mapping==='standard');
    if(!pad){this.clearPad();return;}
    this.padId=pad.id;const button=n=>Math.max(0,Math.min(1,pad.buttons[n]?.value||0));
    for(const [key,index]of [['Enter',0],['P',9]])button(index)>.5?this.state.keys.add(key):this.state.keys.delete(key);
    const axis=axisDeadzone(pad.axes[0]||0,this.deadzone());
    const actions={accelerate:Math.max(button(7),button(0)),brake:Math.max(button(6),button(1)),left:Math.max(-axis,button(14)),right:Math.max(axis,button(15)),bonus:button(2),handbrake:button(3)};
    if(this.state.freeFlightActive){actions.flightUp=button(4);actions.flightDown=button(5);}
    this.state.analog=this.mode!=='menu';
    if(this.mode!=='menu')for(const [name,value]of Object.entries(actions))this.state.set('pad:'+name,name,value);
    const vertical=axisDeadzone(pad.axes[1]||0,this.deadzone());
    const menu={ArrowUp:button(12)>.5||vertical<-.5,ArrowDown:button(13)>.5||vertical>.5,ArrowLeft:button(14)>.5||axis<-.5,ArrowRight:button(15)>.5||axis>.5,Enter:button(0)>.5,Escape:button(1)>.5,Pause:button(9)>.5};
    for(const [key,pressed]of Object.entries(menu)){
      const was=this.lastPadButtons.get(key);
      if(pressed&&!was){
        if(key==='Pause')this.onPause?.('pause');
        else if(key==='Escape'&&this.mode==='menu')this.onPause?.();
        else if(this.mode==='menu')this.onMenu?.(key);
      }
      this.lastPadButtons.set(key,pressed);
    }
  }
  destroy(){this.abort.abort();this.state.clear();}
}
