// rcskmenu.dat 46a350 reads the controls;46a5a0 commits them. This dialog's
// ordinary Windows widgets and captions come from its original Delphi form.
export function nativeDisplayControls(value){
  return {rdoBrightnessLight:value.brightnessLight,rdoBrightnessDark:!value.brightnessLight,
    chkBilinearFiltering:!value.bilinearFiltering,chkAlphaBlending:!value.alphaBlending,
    chkParticles:!value.particles};
}
export function nativeDisplayValues(controls){
  return {brightnessLight:!controls.rdoBrightnessDark,bilinearFiltering:!controls.chkBilinearFiltering,
    alphaBlending:!controls.chkAlphaBlending,particles:!controls.chkParticles};
}
export function nativeDisplayFields(value){
  return {gamma:value.brightnessLight?0:1,filter:value.bilinearFiltering?2:0,
    alpha:value.alphaBlending?2:0,reducedEffects:value.particles?0:1};
}
const unavailable={
  cboDriver:'De browser kiest de videokaart.',
  chkRenderToSystemMemory:'De browser beheert het rendergeheugen.',
  chkWaitVbl:'De browser synchroniseert de weergave met het beeldscherm.',
};
const css=`
.native-display-wrap{min-height:calc(100dvh - 32px);display:grid;place-items:center}
.native-display-dialog{width:min(100%,593px);background:#c0c0c0;border:2px outset #eee;color:#000;color-scheme:light;box-sizing:content-box;font-family:'Original Comic Sans',Arial,sans-serif}
.native-display-caption{margin:0;padding:3px 6px;background:#000080;color:white;font:700 13px Arial,sans-serif}
.native-display-stage{position:relative;width:100%;aspect-ratio:593/408;container-type:inline-size}
.native-display-item{position:absolute;box-sizing:border-box;font-size:2.024cqw;line-height:1}
.native-display-item label{display:flex;align-items:center;gap:5px;height:100%;white-space:nowrap}
.native-display-item input{width:13px;height:13px;margin:0;flex:none;accent-color:#333}
.native-display-item fieldset{margin:0;padding:0;width:100%;height:100%;border:2px groove #eee}
.native-display-item legend{margin-left:8px;padding:0 3px}
.native-display-dialog button{background:#c0c0c0;border:2px outset #eee;border-radius:0;padding:1px 5px;width:auto;height:auto;min-height:0;box-shadow:none;color:#000;font:inherit}
.native-display-dialog button:active{border-style:inset}
.native-display-dialog button:focus-visible,.native-display-dialog input:focus-visible{outline:1px dotted #000;outline-offset:2px}
.native-display-dialog select{background:white;color:black;width:100%;height:100%;font:inherit}
.native-display-dialog :disabled{color:#777;cursor:default}
.native-display-tabs{display:flex;gap:2px;height:7.2%;align-items:end;border-bottom:2px groove #eee}
.native-display-tabs button{height:100%;padding:0 10px}
.native-display-tabs button[aria-selected=true]{border-bottom-color:#c0c0c0;font-weight:bold}
.native-display-page{position:absolute;left:0;top:7.2%;width:100%;height:92.8%}
.native-display-notes{font:12px/1.5 Arial,sans-serif;padding:6px 12px;border-top:1px solid #888}
@media(max-width:600px){
 .native-display-dialog{width:100%;max-width:520px;box-sizing:border-box}
 .native-display-stage{aspect-ratio:auto;display:flex;flex-direction:column;gap:12px;padding:12px;box-sizing:border-box}
 .native-display-stage .native-display-item,.native-display-page{position:relative!important;inset:auto!important;width:auto!important;height:auto!important;font-size:14px;line-height:1.4;white-space:normal!important}
 .native-display-tabs{height:auto;min-height:44px;align-items:stretch}
 .native-display-tabs button{min-height:44px}
 .native-display-page{padding-top:10px}
 .native-display-page .native-display-item{margin:7px 0}
 .native-display-item fieldset{padding:8px;box-sizing:border-box}
 .native-display-item label{min-height:42px;white-space:normal}
 .native-display-item input{width:20px;height:20px}
 .native-display-stage>button{min-height:44px}
}
`;

/** Native desktop layout, with the separately requested portrait reflow. */
export function createNativeDisplaySettings(form,value,{onOk,onCancel}){
  if(!document.getElementById('native-display-style')){
    const style=document.createElement('style');style.id='native-display-style';style.textContent=css;document.head.append(style);
  }
  const controls=nativeDisplayControls(value),inputs={};
  const readValues=()=>nativeDisplayValues(Object.fromEntries(Object.entries(inputs).map(([name,input])=>[name,input.checked])));
  const wrap=document.createElement('div');wrap.className='native-display-wrap';
  const dialog=document.createElement('section');dialog.className='native-display-dialog';dialog.dataset.form='TFRMDISPLAYSETTINGS';
  const caption=document.createElement('h1');caption.className='native-display-caption';caption.textContent=form.properties.Caption;dialog.append(caption);
  const stage=document.createElement('div');stage.className='native-display-stage';dialog.append(stage);wrap.append(dialog);
  function node(item,parent,parentWidth=593,parentHeight=408){
    const p=item.properties;
    if(p.Visible===false||item.class==='TDaviImage')return;
    const el=document.createElement('div');el.className='native-display-item';el.dataset.element=item.name;
    Object.assign(el.style,{left:`${(p.Left??0)/parentWidth*100}%`,top:`${(p.Top??0)/parentHeight*100}%`,
      width:`${(p.Width??parentWidth)/parentWidth*100}%`,height:`${(p.Height??parentHeight)/parentHeight*100}%`});
    if(item.class==='TDaviPageControl'){
      const tabs=document.createElement('div');tabs.className='native-display-tabs';tabs.setAttribute('role','tablist');el.append(tabs);
      const pages=[];
      for(const [index,child]of item.children.entries()){
        const button=document.createElement('button');button.textContent=child.properties.Caption;button.dataset.native=child.name;
        button.setAttribute('role','tab');button.setAttribute('aria-selected',String(index===0));
        const content=document.createElement('div');content.className='native-display-page';content.hidden=index!==0;content.setAttribute('role','tabpanel');
        button.onclick=()=>{for(const page of pages){page.button.setAttribute('aria-selected',String(page.button===button));page.content.hidden=page.button!==button;}};
        tabs.append(button);el.append(content);pages.push({button,content});
        for(const descendant of child.children)node(descendant,content,p.Width,p.Height*.928);
      }
    }else if(item.class==='TLabel'){el.textContent=p.Caption;if(!p.WordWrap)el.style.whiteSpace='nowrap';if(p['Font.Style']?.includes('fsBold'))el.style.fontWeight='bold';}
    else if(['TCheckBox','TDaviRadioButton'].includes(item.class)){
      const label=document.createElement('label'),input=document.createElement('input');input.type=item.class==='TCheckBox'?'checkbox':'radio';
      input.dataset.native=item.name;input.checked=!!controls[item.name];input.disabled=!!unavailable[item.name];
      if(input.type==='radio')input.name='nativeBrightness';inputs[item.name]=input;
      label.append(input,document.createTextNode(p.Caption));el.append(label);
      if(unavailable[item.name])el.title=unavailable[item.name];
    }else if(item.class==='TComboBox'){
      const select=document.createElement('select');select.dataset.native=item.name;select.disabled=true;select.title=unavailable[item.name]??'De browser beheert deze instelling.';
      for(const text of p['Items.Strings']??[]){const option=document.createElement('option');option.textContent=text;select.append(option);}
      el.append(select);
    }else if(item.class==='TButton'){
      const button=document.createElement('button');button.dataset.native=item.name;button.textContent=p.Caption;
      button.style.cssText='width:100%;height:100%';
      button.onclick=item.name==='btnOk'?()=>onOk(readValues()):onCancel;
      el.append(button);
    }else{
      const container=item.class==='TGroupBox'?document.createElement('fieldset'):document.createElement('div');
      if(item.class==='TGroupBox'){const legend=document.createElement('legend');legend.textContent=p.Caption;container.append(legend);}
      el.append(container);
      // DOM reading/portrait order follows the authored vertical positions.
      for(const child of [...item.children].sort((a,b)=>(a.properties.Top??0)-(b.properties.Top??0)))node(child,container,p.Width??parentWidth,p.Height??parentHeight);
    }
    parent.append(el);
  }
  for(const item of form.children)node(item,stage);
  const notes=document.createElement('div');notes.className='native-display-notes';
  notes.textContent=Object.values(unavailable).join(' ');dialog.append(notes);
  return wrap;
}
