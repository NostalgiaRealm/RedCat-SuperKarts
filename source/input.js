export const KEYS=Object.freeze({ArrowUp:'accelerate',ArrowDown:'brake',ArrowLeft:'left',ArrowRight:'right',ControlLeft:'bonus',ControlRight:'bonus',AltLeft:'handbrake',AltRight:'handbrake'});
export function axisDeadzone(value,deadzone=.18){
  if(!Number.isFinite(value))return 0;
  const magnitude=Math.min(1,Math.abs(value)),limit=Math.min(.99,Math.max(0,deadzone));
  return magnitude<=limit?0:Math.sign(value)*(magnitude-limit)/(1-limit);
}
/** SuperTuxKart's wheel uses absolute X/Y position, not a circular gesture.
 * Its default .1 deadzone and .2/.65 axis sensitivities leave comfortable
 * neutral zones while reaching full steering/drive before the rim.
 */
export function touchWheelInput(clientX,clientY,{left,top,width,height}){
  if(!(width>0&&height>0))return {steer:0,throttle:0,brake:0};
  const factor=(value,sensitivity)=>Math.max(-1,Math.min(1,axisDeadzone(value,.1)/(1-sensitivity)));
  const steer=factor((clientX-left)/width*2-1,.2);
  const drive=factor(1-(clientY-top)/height*2,.65);
  return {steer,throttle:Math.max(0,drive),brake:Math.max(0,-drive)};
}
export class InputState {
  constructor({onClear=null}={}){this.sources=new Map();this.keys=new Set();this.analog=null;this.touchAnalog=new Set();this.onClear=onClear;}
  set(source,action,value=1){if(!value){this.release(source);return;}this.sources.set(source,{action,value});}
  release(source){this.sources.delete(source);}
  clear(){this.onClear?.();this.sources.clear();this.keys.clear();this.analog=null;this.touchAnalog.clear();}
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
    const sources=[...this.sources.keys()];
    // Pedal/bonus touches must not turn proportional wheel steering into a
    // digital left/right press. Keyboard and ordinary gamepad priority stay
    // unchanged; touching the wheel opts into the native analog input path.
    if((this.touchAnalog.size&&!sources.some(key=>key.startsWith('key:')))||
      (this.analog&&!sources.some(key=>!key.startsWith('pad:'))))state.analog={...state};
    if(this.freeFlightActive)state.lift=Math.max(this.value('flightUp'),this.keys.has(32)?1:0)
      -Math.max(this.value('flightDown'),this.keys.has(67)?1:0);
    return state;
  }
}
export class InputController {
  constructor({onMenu,onPause,onActivity,onKeysChanged,deadzone=()=>.18,bindings=null,window:win=window}={}){
    this.state=new InputState({onClear:()=>this.releaseTouches()});this.win=win;this.onMenu=onMenu;this.onPause=onPause;this.onActivity=onActivity;this.deadzone=deadzone;this.mode='menu';this.lastPadButtons=new Map();this.lastMenuTime=0;this.padId=null;this.touchReleases=new Map();
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
  // DrivingView owns the InputState, so its direct clear() calls must also
  // release pointer capture and styling through the state's ownership hook.
  releaseTouches(){for(const release of [...this.touchReleases.values()])release();}
  clear(){this.state.clear();}
  suspend(){this.clear();this.clearPad();this.onPause?.('focus');}
  clearPad(){for(const key of this.state.sources.keys())if(key.startsWith('pad:'))this.state.release(key);for(const key of ['Enter','P'])this.state.keys.delete(key);this.state.analog=null;this.lastPadButtons.clear();this.padId=null;}
  setMode(mode){this.mode=mode;this.clear();}
  bindTouch(element,action){
    const opts={signal:this.abort.signal},held=new Map();
    element.addEventListener('pointerdown',e=>{
      if(e.pointerType==='mouse'&&e.button!==0)return;
      e.preventDefault();if(held.has(e.pointerId))return;
      this.touchReleases.get(e.pointerId)?.();
      const source='pointer:'+e.pointerId;
      const release=()=>{
        if(!held.delete(e.pointerId))return;
        this.touchReleases.delete(e.pointerId);this.state.release(source);
        element.classList.toggle('held',held.size>0);
        if(element.hasPointerCapture(e.pointerId))element.releasePointerCapture(e.pointerId);
      };
      held.set(e.pointerId,release);this.touchReleases.set(e.pointerId,release);
      element.setPointerCapture(e.pointerId);this.state.set(source,action);
      element.classList.add('held');this.onActivity?.();
    },opts);
    const release=e=>held.get(e.pointerId)?.();
    for(const event of ['pointerup','pointercancel','lostpointercapture'])element.addEventListener(event,release,opts);
    element.addEventListener('contextmenu',e=>e.preventDefault(),opts);
  }
  bindSteeringWheel(element){
    const opts={signal:this.abort.signal};let pointer=null,release=null;
    const visual=({steer=0,throttle=0,brake=0}={})=>{
      element.dataset.steer=String(steer);
      element.dataset.drive=throttle?'forward':brake?'reverse':'neutral';
      element.style.setProperty('--steer-angle',`${steer*90}deg`);
      element.classList.toggle('held',pointer!==null);
    };
    const update=e=>{
      const controls=touchWheelInput(e.clientX,e.clientY,element.getBoundingClientRect());
      const source=`pointer:${pointer}:wheel:`;
      this.state.set(source+'left','left',Math.max(0,-controls.steer));
      this.state.set(source+'right','right',Math.max(0,controls.steer));
      this.state.set(source+'accelerate','accelerate',controls.throttle);
      this.state.set(source+'brake','brake',controls.brake);
      visual(controls);
    };
    element.addEventListener('pointerdown',e=>{
      if(e.pointerType==='mouse'&&e.button!==0)return;
      e.preventDefault();if(pointer!==null)return;
      this.touchReleases.get(e.pointerId)?.();pointer=e.pointerId;
      const id=pointer,source=`pointer:${id}:wheel:`;
      release=()=>{
        if(pointer!==id)return;
        pointer=null;release=null;this.touchReleases.delete(id);this.state.touchAnalog.delete(source);
        for(const action of ['left','right','accelerate','brake'])this.state.release(source+action);
        visual();if(element.hasPointerCapture(id))element.releasePointerCapture(id);
      };
      this.touchReleases.set(id,release);this.state.touchAnalog.add(source);
      element.setPointerCapture(id);update(e);this.onActivity?.();
    },opts);
    element.addEventListener('pointermove',e=>{if(e.pointerId===pointer){e.preventDefault();update(e);}},opts);
    for(const event of ['pointerup','pointercancel','lostpointercapture'])
      element.addEventListener(event,e=>{if(e.pointerId===pointer)release?.();},opts);
    element.addEventListener('contextmenu',e=>e.preventDefault(),opts);
    visual();
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
  destroy(){this.clear();this.abort.abort();}
}
