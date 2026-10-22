import {mkdir,readFile,writeFile,readdir} from 'node:fs/promises';
import path from 'node:path';
const input=process.argv[2]||'evidence/native/menu-resources';
const output=process.argv[3]||'public/assets/ui';
const names=(await readdir(input)).filter(name=>name.endsWith('.json')).sort();
const forms={};
for(const filename of names){
  const form=JSON.parse(await readFile(path.join(input,filename),'utf8'));
  if(form.source?.bytes!==form.source?.parsedBytes)throw new Error(`Incomplete native form: ${filename}`);
  forms[filename.replace(/\.json$/,'')]=form;
}
if(Object.keys(forms).length!==20)throw new Error('Expected all 20 shipped DFM form resources');
const layouts={
  schema:1,
  source:'rcskmenu.dat SHA2561b6872290010d6357db1b63d6691498b52f8d3def0083e5b42e816a2b7366733',
  // Rectangle edges, not x/y/width/height. Division truncates toward zero.
  handlers:{},
};
for(const [name,address]of Object.entries({
  defQuitButtonGetCaptionRect:'0x45cb70',defBackButtonGetCaptionRect:'0x45cc28',defOkButtonGetCaptionRect:'0x45cce0',
  defRadiobuttonGetCaptionRect:'0x45cd98',defCommandButtonGetCaptionRect:'0x45ce50',defCheckButtonGetCaptionRect:'0x45cf08',
  defAdvancedGetCaptionRect:'0x46b498',defItemGetCaptionRect:'0x46ff74',
}))layouts.handlers[name]={kind:'icon-button',address,left:'trunc((width-60)/2)',top:'trunc((height-38)/2)',right:'width',bottom:'height'};
for(const[name,address]of Object.entries({defAdventureGetCaptionRect:'0x474b34',defQuickraceGetCaptionRect:'0x474bd8',defHighscoreGetCaptionRect:'0x474c7c'}))
  layouts.handlers[name]={kind:'main-tile',address,left:'0',top:'height-36',right:'width',bottom:'height'};
await mkdir(output,{recursive:true});
await writeFile(path.join(output,'forms.json'),JSON.stringify(forms));
await writeFile(path.join(output,'caption-layouts.json'),JSON.stringify(layouts,null,2));
console.log(`Prepared ${Object.keys(forms).length} native menu form layouts and ${Object.keys(layouts.handlers).length} caption handlers.`);
