import {createReadStream} from 'node:fs';
import {readFile,realpath,stat} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {Readable} from 'node:stream';
import path from 'node:path';
import {GAME_SCHEME} from './runtime.mjs';

// The JS port's handler (../RedCat Superkarts/electron/game-protocol.mjs) for the packaged website of the recomp
// (dist/site): every file below the site is served, since the page, its modules, the wasm module, the menu's assets
// and the original game files (data/, read by Range requests) all live there under relative URLs.
const types={'.html':'text/html; charset=utf-8','.js':'text/javascript; charset=utf-8',
  '.mjs':'text/javascript; charset=utf-8','.css':'text/css; charset=utf-8',
  '.json':'application/json','.wasm':'application/wasm','.png':'image/png','.svg':'image/svg+xml',
  '.jpg':'image/jpeg','.jpeg':'image/jpeg','.gif':'image/gif','.webp':'image/webp','.bmp':'image/bmp',
  '.ico':'image/x-icon','.mp4':'video/mp4','.webm':'video/webm','.mp3':'audio/mpeg','.wav':'audio/wav',
  '.ogg':'audio/ogg','.ttf':'font/ttf','.woff2':'font/woff2','.txt':'text/plain; charset=utf-8',
  '.ini':'text/plain; charset=utf-8','.sha256':'text/plain; charset=utf-8','.map':'application/json'};
// The original's data files have many extensions of their own (.img, .dat, .d3d, .raw, ...): bytes.
const typeOf=file=>types[path.extname(file).toLowerCase()]||'application/octet-stream';
const within=(base,file)=>file===base||file.startsWith(base+path.sep);

// Cross-origin isolation: the game worker and the render worker share memory with the page (SharedArrayBuffer,
// Atomics.wait), as on the website (docs/hosting.md). On every answer, errors too: a worker's script and every
// file a worker fetches are judged by their own headers.
export const ISOLATION=Object.freeze({'Cross-Origin-Opener-Policy':'same-origin',
  'Cross-Origin-Embedder-Policy':'require-corp','Cross-Origin-Resource-Policy':'same-origin'});

/** Single ranges are sufficient for Chromium's seeking audio/video requests and the game's data reads. */
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
  // Inline scripts by hash rather than 'unsafe-inline'. 'wasm-unsafe-eval' lets the game worker compile the
  // recompiled race (WebAssembly.compile); workers are module scripts of the site (worker-src 'self'). A worker
  // takes the policy of its own script's answer, which is this one too. blob: for media and images only.
  const hashes=[...html.matchAll(/<script\b([^>]*)>([\s\S]*?)<\/script>/gi)]
    .filter(([,attributes])=>!/(?:^|\s)src\s*=/i.test(attributes))
    .map(([, ,body])=>`'sha256-${createHash('sha256').update(body).digest('base64')}'`);
  return ["default-src 'self'",["script-src 'self' 'wasm-unsafe-eval'",...hashes].join(' '),"worker-src 'self'",
    "style-src 'self' 'unsafe-inline'","img-src 'self' data: blob:","media-src 'self' blob:","font-src 'self'",
    "connect-src 'self'","object-src 'none'","frame-src 'none'","base-uri 'none'","form-action 'none'"].join('; ');
}

/** Returns a protocol.handle-compatible handler without importing Electron. */
export async function createGameProtocolHandler({root}){
  const base=await realpath(root);
  const csp=gameContentSecurityPolicy(await readFile(path.join(base,'index.html'),'utf8'));
  const security={...ISOLATION,'Content-Security-Policy':csp,'X-Content-Type-Options':'nosniff','Cache-Control':'no-cache'};
  const error=(status,text,extra={})=>new Response(text,{status,headers:{...security,'Content-Type':'text/plain; charset=utf-8',...extra}});
  return async request=>{
    if(!['GET','HEAD'].includes(request.method))return error(405,'Method not allowed',{'Allow':'GET, HEAD'});
    let url,decoded;
    try{url=new URL(request.url);decoded=decodeURIComponent(url.pathname);}catch{return error(400,'Invalid URL');}
    if(url.protocol!==GAME_SCHEME+':'||url.hostname!=='game'||url.port||url.username||url.password)return error(403,'Forbidden');
    if(decoded.includes('\\')||decoded.includes('\0')||decoded.split('/').some(part=>part==='..'||part.startsWith('.')))
      return error(403,'Forbidden');
    const relative=decoded.endsWith('/')?decoded.slice(1)+'index.html':decoded.slice(1);
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
      const headers={...security,'Content-Type':typeOf(canonical),'Accept-Ranges':'bytes',
        'Content-Length':String(range?end-start+1:info.size)};
      if(range)headers['Content-Range']=`bytes ${start}-${end}/${info.size}`;
      // An already-aborted signal destroys the file stream before Readable.toWeb
      // listens for its error, which would be unhandled and end the process.
      const body=request.method==='HEAD'||info.size===0||request.signal?.aborted?null:
        Readable.toWeb(createReadStream(canonical,{start,end,signal:request.signal}));
      return new Response(body,{status:range?206:200,headers});
    }catch{return error(404,'Not found');}
  };
}

/** The packaged site is there and whole: its build.json names the revision whose page modules and race it loads. */
export async function assertGameRuntime({root}){
  let build;
  try{build=JSON.parse(await readFile(path.join(root,'build.json'),'utf8'));}
  catch(error){
    if(error.code==='ENOENT')throw Error(`The packaged site is missing (${root}). Run npm run package in the project folder.`);
    throw error;
  }
  if(typeof build.revision!=='string'||!/^[\w.-]+$/.test(build.revision))throw Error('Invalid build.json in the packaged site.');
  const app=`app/${build.revision}`;
  const files=['index.html','build.json',`${app}/source/main.js`,`${app}/source/web/worker.js`,
    `${app}/source/web/render-worker.js`,`${app}/game/rcskspel.wasm`,'data/index.json'];
  const missing=[];
  for(const file of files){try{if(!(await stat(path.join(root,file))).isFile())missing.push(file);}catch{missing.push(file);}}
  if(missing.length)throw Error(`Required game files are missing from ${root}:\n${missing.join('\n')}\nRun npm run package in the project folder.`);
  return build;
}
