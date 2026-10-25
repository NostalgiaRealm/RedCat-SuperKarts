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
  '.dat':'application/octet-stream','.sha256':'text/plain; charset=utf-8'};
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
  // The import map is an inline script in the shipped HTML. Hash its exact
  // bytes instead of granting arbitrary inline scripts or disabling CSP.
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
 * Source and packaged layouts share the same URL paths and storage origin.
 */
export async function createGameProtocolHandler({root,assetsRoot}){
  const roots={game:await realpath(root),assets:await realpath(assetsRoot),
    src:await realpath(path.join(root,'src')),three:await realpath(path.join(root,'node_modules/three'))};
  const csp=gameContentSecurityPolicy(await readFile(path.join(root,'index.html'),'utf8'));
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
    else if(decoded.startsWith('/src/')&&['.js','.mjs','.css'].includes(path.extname(decoded))){base=roots.src;relative=decoded.slice(5);}
    else if(decoded.startsWith('/node_modules/three/')&&threeFiles.has(decoded.slice(20))){base=roots.three;relative=decoded.slice(20);}
    else return error(403,'Forbidden');
    const type=types[path.extname(relative).toLowerCase()];
    if(!type)return error(403,'Forbidden');
    const file=path.resolve(base,relative);
    if(!within(base,file))return error(403,'Forbidden');
    try{
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
  const files=['index.html','src/main.js',...Array.from(threeFiles,file=>'node_modules/three/'+file)]
    .map(file=>path.join(root,file));
  files.push(...['ui/forms.json','menu/manifest.json','config.json','manifest.json'].map(file=>path.join(assetsRoot,file)));
  const missing=[];
  for(const file of files){try{if(!(await stat(file)).isFile())missing.push(file);}catch{missing.push(file);}}
  if(missing.length)throw Error('Required game files are missing:\n'+missing.join('\n')+
    '\nFor a source checkout, run npm ci and prepare the original assets before launching.');
}
