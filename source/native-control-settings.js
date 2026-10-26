// Original rcskmenu.dat: 4620ec capture, 461958 key release, 461b44 key art.
export const NATIVE_CONTROL_ACTIONS=['accelerate','brake','left','right','bonus','handbrake'];
export const NATIVE_CONTROL_FIELDS=['ACCELERATE','BRAKE','STEERLEFT','STEERRIGHT','USEBONUS','HANDBRAKE'];
export const NATIVE_DEFAULT_KEYS=[38,40,37,39,17,18];
const codes={Enter:13,ShiftLeft:16,ControlLeft:17,AltLeft:18,Space:32,PageUp:33,
  PageDown:34,End:35,Home:36,ArrowLeft:37,ArrowUp:38,ArrowRight:39,ArrowDown:40,
  Backspace:8,Tab:9,Escape:27,Delete:46};
const browserCodes=Object.fromEntries(Object.entries(codes).map(([key,value])=>[value,key]));
const labels={17:'Ctrl',18:'Alt',16:'Shift',13:'Enter',33:'PGUP',34:'PGDN',35:'End',36:'Home',32:'Spatie'};

export function nativeBindingCode(code=''){
  code=code.replace(/^(Control|Alt|Shift)Right$/,'$1Left');
  if(/^Key[A-Z]$/.test(code))return code.charCodeAt(3)+32;
  if(/^Digit[0-9]$/.test(code))return code.charCodeAt(5);
  return codes[code]??0;
}
export function browserBindingCode(code){
  if(code>=65&&code<=90||code>=97&&code<=122)return 'Key'+String.fromCharCode(code).toUpperCase();
  if(code>=48&&code<=57)return 'Digit'+String.fromCharCode(code);
  return browserCodes[code]??'';
}
export function nativeBindingLabel(code){
  return code>=65&&code<=90||code>=97&&code<=122?String.fromCharCode(code):labels[code]??'';
}
export function nativeBindingImage(action,code,capturing=false){
  const name=action>=4?(capturing?'toetsgr0':'toetsgrd'):capturing?'toetskl0':
    ({37:'pijl0002',38:'pijl0003',39:'pijl0000',40:'pijl0001'}[code]??'toetskld');
  return `(IMAGEBASE)${name}.bmp`;
}

/** Bindings are edited in memory; 461904 saves, 4618d0 reloads on Cancel. */
export class NativeControlDraft{
  constructor(bindings){
    this.saved=NATIVE_CONTROL_ACTIONS.map(action=>nativeBindingCode(bindings[action]));
    this.keys=[...this.saved];this.capture=null;this.captureImage=false;
  }
  begin(action){
    if(this.capture!==null)return false;
    this.capture=action;this.captureImage=true;this.keys[action]=0;return true;
  }
  release(key){
    if(this.capture===null)return {decision:'inactive',samples:[51]};
    const stored=key>=65&&key<=90?key+32:key;
    // The original clears the current key on entry, then checks all six slots.
    if(this.keys.includes(stored))return {decision:'duplicate',samples:[51]};
    if(key===27){this.capture=null;this.captureImage=false;return {decision:'cancel',samples:[51]};}
    if(!(key>=65&&key<=90||key===13||key>=16&&key<=18||key>=32&&key<=40))
      return {decision:'reject',samples:[51,110]};
    this.keys[this.capture]=stored;this.capture=null;this.captureImage=false;
    return {decision:'accept',samples:[51]};
  }
  defaults(){this.keys=[...NATIVE_DEFAULT_KEYS];this.captureImage=false;}
  cancel(){this.keys=[...this.saved];this.capture=null;this.captureImage=false;}
  commit(){this.saved=[...this.keys];return this.bindings();}
  bindings(){return Object.fromEntries(NATIVE_CONTROL_ACTIONS.map((action,index)=>[action,browserBindingCode(this.keys[index])]));}
}

export const NATIVE_OPTION_FIELDS=['controlType','resolution','music','effects','startInfo'];
export function nativeOptionsDraft(settings){
  return Object.fromEntries(NATIVE_OPTION_FIELDS.map(key=>[key,settings[key]]));
}
export function commitNativeOptions(settings,draft){return {...settings,...draft};}
// Both46fdf0 QuickRace and4786a4 Adventure gate the keyboard-only information.
export function nativeShowsStartInfo(settings){return settings.startInfo&&settings.controlType===0;}
