import {createReadStream} from 'node:fs';
import {readFile,realpath,stat} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {Readable} from 'node:stream';
import path from 'node:path';
import {GAME_SCHEME} from './runtime.mjs';

const types={'.html':'text/html; charset=utf-8','.js':'text/javascript; charset=utf-8',
  '.mjs':'text/javascript; charset=utf-8','.css':'text/css; charset=utf-8',
  '.json':'application/json','.png':'image/png','.svg':'image/svg+xml','.jpg':'image/jpeg','.jpeg':'image/jpeg',
  '.gif':'image/gif','.webp':'image/webp','.ico':'image/x-icon','.mp4':'video/mp4',
  '.webm':'video/webm','.mp3':'audio/mpeg','.wav':'audio/wav','.ogg':'audio/ogg',
  '.ttf':'font/ttf','.woff2':'font/woff2','.bin':'application/octet-stream',
  '.dat':'application/octet-stream','.map':'application/json','.sha256':'text/plain; charset=utf-8'};
const threeFiles=new Set(['build/three.module.js','build/three.core.js','examples/jsm/controls/OrbitControls.js']);
const within=(base,file)=>file===base||file.startsWith(base+path.sep);

/** Single ranges are sufficient for Chromium's seeking audio/video requests. */
export function byteRange(value,size){
  if(value===null)return null;
  const match=value.trim().match(/^bytes=(\d*)-(\d*)$/);
  if(!match||(!match[1]&&!match[2])||size===0)return false;
  let start,end;
  if(!match[1]){
    const suffix=Number(match[2]);
    if(!Number.isSafeInteger(suffix)||suffix<=0)return false;
    start=Math.max(0,size-suffix);end=size-1;
  }else{
    start=Number(match[1]);end=match[2]?Number(match[2]):size-1;
    if(!Number.isSafeInteger(start)||!Number.isSafeInteger(end)||start>=size||end<start)return false;
    end=Math.min(end,size-1);
  }
  return {start,end};
}

export function gameContentSecurityPolicy(html){
  // Hash any inline script (including the diagnostic import map) rather than
  // granting arbitrary inline scripts or disabling CSP.
  const hashes=[...html.matchAll(/<script\b([^>]*)>([\s\S]*?)<\/script>/gi)]
    .filter(([,attributes])=>!/(?:^|\s)src\s*=/i.test(attributes))
    .map(([, ,body])=>`'sha256-${createHash('sha256').update(body).digest('base64')}'`);
  return ["default-src 'self'",`script-src 'self' ${hashes.join(' ')}`,
    "style-src 'self' 'unsafe-inline'","img-src 'self' data: blob:",
    "media-src 'self' blob:","font-src 'self'","connect-src 'self'",
    "object-src 'none'","frame-src 'none'","worker-src 'none'",
    "base-uri 'none'","form-action 'none'"].join('; ');
}

/** Returns a protocol.handle-compatible handler without importing Electron.
 * Checkout and packaged bundles share the same URL paths and storage origin.
 * Authored modules are accessible only in an explicit browser test session.
 */
export async function createGameProtocolHandler({root,assetsRoot,inspectSource=false}){
  const roots={game:await realpath(root),assets:await realpath(assetsRoot),
    src:await realpath(path.join(root,'src')),
    source:inspectSource?await realpath(path.join(root,'source')).catch(()=>null):null,
    three:inspectSource?await realpath(path.join(root,'node_modules/three')).catch(()=>null):null};
  let html=await readFile(path.join(root,'index.html'),'utf8');
  if(inspectSource){
    const importMap='<script type="importmap">'+JSON.stringify({imports:{
      three:'/node_modules/three/build/three.module.js','three/addons/':'/node_modules/three/examples/jsm/'}})+'</script>';
    html=html.replace(/\s*<script\s+type="importmap">[\s\S]*?<\/script>/,'');
    // Before any module script, including minimalist test fixtures without head.
    html=html.replace(/<script\b/i,importMap+'<script');
  }
  const csp=gameContentSecurityPolicy(html);
  const security={'Content-Security-Policy':csp,'X-Content-Type-Options':'nosniff',
    'Cross-Origin-Resource-Policy':'same-origin','Cache-Control':'no-cache'};
  const error=(status,text,extra={})=>new Response(text,{status,headers:{...security,'Content-Type':'text/plain; charset=utf-8',...extra}});
  return async request=>{
    if(!['GET','HEAD'].includes(request.method))return error(405,'Method not allowed',{'Allow':'GET, HEAD'});
    let url,decoded;
    try{url=new URL(request.url);decoded=decodeURIComponent(url.pathname);}catch{return error(400,'Invalid URL');}
    if(url.protocol!==GAME_SCHEME+':'||url.hostname!=='game'||url.port||url.username||url.password)return error(403,'Forbidden');
    if(decoded.includes('\\')||decoded.includes('\0')||decoded.split('/').some(part=>part==='..'||part.startsWith('.')))
      return error(403,'Forbidden');
    let base,relative;
    if(decoded==='/'||decoded==='/index.html'){base=roots.game;relative='index.html';}
    else if(decoded.startsWith('/assets/')){base=roots.assets;relative=decoded.slice(8);}
    else if(decoded.startsWith('/src/')&&['.js','.mjs','.css','.map'].includes(path.extname(decoded))){base=roots.src;relative=decoded.slice(5);}
    else if(roots.source&&decoded.startsWith('/source/')&&['.js','.css'].includes(path.extname(decoded))){base=roots.source;relative=decoded.slice(8);}
    else if(roots.three&&decoded.startsWith('/node_modules/three/')&&threeFiles.has(decoded.slice(20))){base=roots.three;relative=decoded.slice(20);}
    else return error(403,'Forbidden');
    const type=types[path.extname(relative).toLowerCase()];
    if(!type)return error(403,'Forbidden');
    const file=path.resolve(base,relative);
    if(!within(base,file))return error(403,'Forbidden');
    try{
      if(inspectSource&&base===roots.game&&relative==='index.html'){
        const bytes=Buffer.from(html);
        return new Response(request.method==='HEAD'?null:bytes,{headers:{...security,
          'Content-Type':type,'Content-Length':String(bytes.length)}});
      }
      const canonical=await realpath(file);
      if(!within(base,canonical))return error(403,'Forbidden');
      const info=await stat(canonical);
      if(!info.isFile())return error(404,'Not found');
      const range=byteRange(request.headers.get('range'),info.size);
      if(range===false)return error(416,'Range not satisfiable',{'Content-Range':`bytes */${info.size}`});
      const start=range?.start??0,end=range?.end??info.size-1;
      const headers={...security,'Content-Type':type,'Accept-Ranges':'bytes',
        'Content-Length':String(range?end-start+1:info.size)};
      if(range)headers['Content-Range']=`bytes ${start}-${end}/${info.size}`;
      const body=request.method==='HEAD'||info.size===0?null:
        Readable.toWeb(createReadStream(canonical,{start,end,signal:request.signal}));
      return new Response(body,{status:range?206:200,headers});
    }catch{return error(404,'Not found');}
  };
}

export async function assertGameRuntime({root,assetsRoot}){
  let runtime;
  try{
    const manifest=JSON.parse(await readFile(path.join(root,'runtime-manifest.json'),'utf8'));
    if(manifest.format!=='rcsk-runtime-v1'||manifest.entry!=='src/main.js'||!Array.isArray(manifest.files)
      ||!manifest.files.includes(manifest.entry)||!manifest.files.includes('src/style.css')
      ||!manifest.files.every(file=>typeof file==='string'&&/^src\/(?:[\w-]+\/)*[\w.-]+\.(?:js|css)$/.test(file)))
      throw Error('Invalid bundled runtime manifest.');
    runtime=manifest.files;
  }catch(error){
    if(error.code==='ENOENT')throw Error('Required bundled runtime manifest is missing. Run npm ci and npm run bundle in the project folder.');
    throw error;
  }
  const files=['index.html',...runtime]
    .map(file=>path.join(root,file));
  files.push(...['ui/forms.json','menu/manifest.json','config.json','manifest.json'].map(file=>path.join(assetsRoot,file)));
  const missing=[];
  for(const file of files){try{if(!(await stat(file)).isFile())missing.push(file);}catch{missing.push(file);}}
  if(missing.length)throw Error('Required game files are missing:\n'+missing.join('\n')+
    '\nFor a checkout, run npm ci and npm run bundle; prepare the original assets if they are missing.');
}
