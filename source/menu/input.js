// The menu part of the JavaScript reconstruction's input: ../RedCat Superkarts/source/input.js at commit 5bfe0b62
// (1.0.3). Kept as there: axisDeadzone, nativeIntroSkipKey, and InputController's menu keys (arrows, Enter, Space,
// Escape), its pad navigation (D-pad or stick, A, B, Start) and its focus handling (blur, a hidden page, a lost pad).
// Left out, because the recompiled race reads its own input (source/input/ in shared memory, owned by
// source/race-runner.js while a race runs): the driving actions, InputState's held keys and analog values, the touch
// wheel and touch buttons, free-flight lift. New here: enabled(), which main.js turns off while a race runs, so the
// menu neither reacts to keys and the pad nor reports focus loss then, and resyncPad(), so a pad button still held
// when a race ends does not press a menu button.
export function axisDeadzone(value,deadzone=.18){
  if(!Number.isFinite(value))return 0;
  const magnitude=Math.min(1,Math.abs(value)),limit=Math.min(.99,Math.max(0,deadzone));
  return magnitude<=limit?0:Math.sign(value)*(magnitude-limit)/(1-limit);
}
/** rcskmenu 0x479cd4: TfrmIntro only handles OnKeyPress, which Windows sends
 * for keys that type a character (WM_CHAR). Arrow keys type nothing, Alt
 * combinations send WM_SYSCHAR instead, AltGr still types. Tab never types:
 * ProcessMessage 0x432150 skips TranslateMessage when IsKeyMsg 0x431ffc's
 * CN_KEYDOWN (TWinControl 0x444f90) is handled, and TCustomForm.CMDialogKey
 * 0x42e414 handles Tab and Shift+Tab as focus moves. */
export function nativeIntroSkipKey(event){
  if(event.altKey&&!event.getModifierState?.('AltGraph'))return false;
  return event.key.length===1||['Enter','Escape','Backspace'].includes(event.key);
}
const MENU_KEYS=['ArrowUp','ArrowDown','ArrowLeft','ArrowRight','Enter','Space'];
export class InputController {
  constructor({onMenu,onPause,deadzone=()=>.18,enabled=()=>true,window:win=window}={}){
    this.win=win;this.onMenu=onMenu;this.onPause=onPause;this.deadzone=deadzone;this.enabled=enabled;
    this.mode='menu';this.lastPadButtons=new Map();this.padId=null;
    this.abort=new AbortController();const opts={signal:this.abort.signal};
    win.addEventListener('keydown',e=>{
      if(!this.enabled())return;
      if(['INPUT','SELECT','TEXTAREA'].includes(e.target.tagName))return;
      if(e.code==='Escape'){if(!e.repeat)this.onPause?.();return;}
      if(this.mode==='menu'&&MENU_KEYS.includes(e.code)){e.preventDefault();if(!e.repeat)this.onMenu?.(e.code,'keyboard');}
    },opts);
    win.addEventListener('blur',()=>this.suspend(),opts);
    win.document.addEventListener('visibilitychange',()=>{if(win.document.hidden)this.suspend();},opts);
    win.addEventListener('gamepaddisconnected',e=>{const active=this.padId===e.gamepad?.id;this.clearPad();if(active&&this.enabled())this.onPause?.('focus');},opts);
  }
  clear(){}
  suspend(){this.clearPad();if(this.enabled())this.onPause?.('focus');}
  clearPad(){this.lastPadButtons.clear();this.padId=null;}
  setMode(mode){this.mode=mode;this.clear();}
  /** Take the pad's current buttons as already seen (after a race), without acting on them. */
  resyncPad(){this.clearPad();this.poll(performance.now(),{silent:true});}
  poll(time,{silent=false}={}){
    let pads;try{pads=this.win.navigator.getGamepads?.()||[];}catch{this.clearPad();return;}
    const pad=Array.from(pads).find(p=>p&&p.connected&&p.mapping==='standard');
    if(!pad){this.clearPad();return;}
    this.padId=pad.id;const button=n=>Math.max(0,Math.min(1,pad.buttons[n]?.value||0));
    const axis=axisDeadzone(pad.axes[0]||0,this.deadzone());
    const vertical=axisDeadzone(pad.axes[1]||0,this.deadzone());
    const menu={ArrowUp:button(12)>.5||vertical<-.5,ArrowDown:button(13)>.5||vertical>.5,ArrowLeft:button(14)>.5||axis<-.5,ArrowRight:button(15)>.5||axis>.5,Enter:button(0)>.5,Escape:button(1)>.5,Pause:button(9)>.5};
    const acting=!silent&&this.enabled();
    for(const [key,pressed]of Object.entries(menu)){
      const was=this.lastPadButtons.get(key);
      if(pressed&&!was&&acting){
        if(key==='Pause')this.onPause?.('pause');
        else if(key==='Escape'&&this.mode==='menu')this.onPause?.();
        else if(this.mode==='menu')this.onMenu?.(key,'pad');
      }
      this.lastPadButtons.set(key,pressed);
    }
  }
  destroy(){this.clear();this.abort.abort();}
}
