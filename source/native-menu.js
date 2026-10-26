const artPath=name=>'/assets/menu/'+name.replace('(IMAGEBASE)','').replace(/\.bmp$/i,'.png').toLowerCase();
import {adaptNativePortrait} from './native-portrait.js';
import {nativeFormTabOrder} from './native-tab-order.js';
const nativeColor=value=>{
  if(typeof value==='number')return `rgb(${value&255},${value>>>8&255},${value>>>16&255})`;
  return {clWhite:'#ffffff',clBlack:'#000000',clWindowText:'#000000',clSilver:'#c0c0c0',
    clNavy:'#000080',clBtnFace:'#c0c0c0'}[value]??'#000000';
};
const labels={btnAdventure:'Avontuur',btnQuickRace:'QuickRace',btnHighscore:'Highscore',btnMainHelp:'Help',btnHelp:'Help',btnMainOptions:'Instellingen',btnMainStop:'Stoppen',btnQuit:'Stoppen',btnBack:'Terug',btnOk:'OK',btnCancel:'Annuleren',btnPrevious:'Vorig karakter',btnNext:'Volgend karakter',btnLeft:'Vorig land',btnRight:'Volgend land',rdoEasy:'Makkelijk',rdoMedium:'Normaal',rdoHard:'Moeilijk',rdoCountry:'Landenrace',rdoTime:'Tijdrace',rdoItem:'Sterrenrace',rdoKeyboard:'Toetsenbord',rdoJoystick:'Joystick',rdoGamepad:'Gamepad',rdoLowQual:'Lage kwaliteit',rdoHighQual:'Hoge kwaliteit',btnAdvanced:'Geavanceerd',btnControlsAdvanced:'Instellen',btnNewPlayer:'Nieuw',btnDeletePlayer:'Verwijderen',btnDefault:'Standaard',btnOverview:'Landinfo'};
const languageIds={btnAdventure:5,btnQuickRace:6,btnHighscore:7,btnMainHelp:2,btnHelp:2,
  btnMainOptions:3,btnMainStop:4,btnQuit:4,btnBack:15,btnOk:14,btnCancel:64,
  rdoEasy:8,rdoMedium:9,rdoHard:10,rdoCountry:11,rdoTime:12,rdoItem:13,
  rdoKeyboard:16,rdoJoystick:17,rdoGamepad:18,rdoLowQual:21,rdoHighQual:22,
  btnAdvanced:23,btnControlsAdvanced:19,btnNewPlayer:44,btnDeletePlayer:45,
  btnDefault:33,btnOverview:77,chk3dCard:51,lblStartInfo:62,lblShowStartInfo:66,
  lblHelp:76,lblForward:26,lblBackwards:27,lblLeft:28,lblRight:29,lblBonus:30,lblHandbrake:31};
export class NativeMenu {
  constructor(forms,manifest={},onPress=()=>{}){this.forms=forms;this.manifest=manifest;this.onPress=onPress;}
  render(formName,{actions={},images={},text={},selected=[],values={},disabled=[],hidden=[],properties={}}={}){
    const root=document.createElement('div');root.className='native-wrap';
    const stage=document.createElement('div');stage.className='native-stage';stage.dataset.form=formName;root.append(stage);
    const form=this.forms[formName],defs={},manifest=this.manifest,onPress=this.onPress,language=this.language||{};
    const stageWidth=form.properties.ClientWidth||640,stageHeight=form.properties.ClientHeight||480;
    stage.style.aspectRatio=`${stageWidth}/${stageHeight}`;stage.style.setProperty('--native-aspect',stageWidth/stageHeight);
    for(const f of [this.forms.TDATAMODULE1,form])for(const item of f.children)if(item.class==='TDaviGraphicDef')defs[item.name]=item.properties;
    function node(item,parent,offsetX=0,offsetY=0){
      const p={...item.properties,...properties[item.name]};if(p.Visible===false||hidden.includes(item.name))return;
      const x=(p.Left||0)+offsetX,y=(p.Top||0)+offsetY;let w=p.Width||0,h=p.Height||0;
      let element;
      if(item.class==='TDaviImage'){
        const file=images[item.name]??p['LinkedDIB.Filename'];if(!file)return;
        element=document.createElement('img');element.src=file.startsWith('/')?file:artPath(file);element.alt='';element.draggable=false;element.className='native-image';
        const original=manifest[file.replace('(IMAGEBASE)','')];
        if(original&&!p.Stretch&&p.Align!=='alClient'){w=original.width;h=original.height;}
      }else if(item.class==='TLabel'){
        element=document.createElement('span');element.textContent=text[item.name]??language[languageIds[item.name]]??p.Caption??'';element.className='native-label';
        element.style.color=nativeColor(p['Font.Color']);
        element.style.justifyContent=p.Alignment==='taCenter'?'center':p.Alignment==='taRightJustify'?'flex-end':'flex-start';
        element.style.textAlign=p.Alignment==='taCenter'?'center':'left';
        if(p.WordWrap)element.style.whiteSpace='normal';
      }else if(['TDaviGraphicButton','TDaviGraphicRadioButton','TDaviGraphicCheckBox'].includes(item.class)){
        const def=defs[p.Definition?.split('.').at(-1)];element=document.createElement('button');element.className='native-button';element.dataset.native=item.name;
        const label=text[item.name]??language[languageIds[item.name]]??labels[item.name]??p.Caption??'';element.setAttribute('aria-label',label);
        const arrow=['btnPrevious','btnNext','btnLeft','btnRight'].includes(item.name);
        if(!arrow){const span=document.createElement('span');span.textContent=label;element.append(span);}
        if(item.class==='TDaviGraphicRadioButton'||item.class==='TDaviGraphicCheckBox'){element.setAttribute('aria-pressed',String(selected.includes(item.name)));element.classList.add('native-radio');}
        if(def){
          for(const [state,field]of [['up','UpLink.Filename'],['hover','HoveredLink.Filename'],['focus','FocusedLink.Filename'],['down','DownLink.Filename'],['disabled','DisabledLink.Filename']]){
            const file=def[field]||def['UpLink.Filename'];
            if(file)element.style.setProperty('--'+state,`url("${artPath(file)}")`);
          }
          applyNativeMenuRegion(element,manifest[def['RegionLink.Filename']?.replace('(IMAGEBASE)','').toLowerCase()]?.region,w,h);
        }
        element.style.setProperty('--font-color',nativeColor(p['Font.Color']));
        element.style.setProperty('--disabled-font-color',nativeColor(p.DisabledFontColor));
        element.disabled=disabled.includes(item.name);
        // Native ODS_SELECTED triggers the common definition's sound on press.
        // Pointer cancellation still produces that sound, but never the action.
        let press=null,invoking=false;
        const begin=()=>press=Promise.resolve(onPress(def?.OnButtonStateChange));
        element.onpointerdown=event=>{if(event.button===0)begin();};
        element.onpointercancel=()=>{press=null;};
        element.onclick=async()=>{
          if(invoking)return;invoking=true;
          try{await(press||begin());if(element.isConnected)await actions[item.name]?.();}
          finally{press=null;invoking=false;}
        };
        if(def?.OnGetCaptionRect==='defAdventureGetCaptionRect'||def?.OnGetCaptionRect==='defQuickraceGetCaptionRect'||def?.OnGetCaptionRect==='defHighscoreGetCaptionRect'){
          element.firstElementChild.style.cssText=`inset:auto 0 0;height:${36/h*100}%;display:flex;align-items:center;justify-content:center;`;
        }else if(def?.OnGetCaptionRect){
          const left=Math.trunc((w-60)/2),top=Math.trunc((h-38)/2);
          element.firstElementChild.style.cssText=`inset:${top/h*100}% 0 0 ${left/w*100}%;display:flex;align-items:center;justify-content:center;`;
        }
      }else if(item.class==='TDaviGraphicSlider'){
        element=document.createElement('input');element.type='range';element.min=0;element.max=100;element.value=values[item.name]??50;element.setAttribute('aria-label',text[item.name]||item.name);element.className='native-slider';
        element.oninput=()=>actions[item.name]?.(Number(element.value));
      }else if(['TDaviEdit2','TEdit'].includes(item.class)){
        element=document.createElement('input');element.type='text';element.value=values[item.name]??'';element.className='native-edit';element.setAttribute('aria-label',text[item.name]||'Naam');element.oninput=()=>actions[item.name]?.(element.value);
        if(p.MaxLength)element.maxLength=p.MaxLength;
        if(p.Color==='clNavy')element.style.backgroundColor='#000080';
        if(p['Font.Color']==='clWhite')element.style.color='white';
      }
      if(element){
        element.style.left=`${x/stageWidth*100}%`;element.style.top=`${y/stageHeight*100}%`;element.style.width=`${w/stageWidth*100}%`;element.style.height=`${h/stageHeight*100}%`;
        element.dataset.element=item.name;
        if(p['Font.Height'])element.style.fontSize=`${Math.abs(p['Font.Height'])/stageWidth*100}cqw`;
        if(p['Font.Style'])element.style.fontWeight=p['Font.Style'].includes('fsBold')?'bold':'normal';
        if(actions[item.name]&&['TDaviImage','TLabel'].includes(item.class)){
          element.onclick=actions[item.name];element.style.cursor='pointer';
          if(item.class==='TDaviImage'){element.setAttribute('role','button');element.tabIndex=0;element.setAttribute('aria-label',text[item.name]||item.name);}
        }
        parent.append(element);
      }
      for(const child of item.children)node(child,parent,x,y);
    }
    for(const item of form.children)node(item,stage);
    adaptNativePortrait(stage,formName);
    const tabOrder=nativeFormTabOrder(form);
    for(const element of stage.querySelectorAll('button,input,select')){
      const index=tabOrder.get(element.dataset.element);
      if(index!==undefined){element.tabIndex=index;element.dataset.nativeTabOrder=index;}
    }
    return root;
  }
}
import {applyNativeMenuRegion} from './menu-regions.js';
