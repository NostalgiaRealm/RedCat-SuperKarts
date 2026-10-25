import http from 'node:http';
import {createReadStream} from 'node:fs';
import {stat} from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {assertServerRuntime} from './server-runtime.mjs';

const root = path.resolve(fileURLToPath(new URL('..', import.meta.url)));
try{await assertServerRuntime(root);}catch(error){console.error(error.message);process.exit(1);}
const port = Number(process.env.PORT || 4173);
const mime = {'.html':'text/html; charset=utf-8','.js':'text/javascript; charset=utf-8','.mjs':'text/javascript; charset=utf-8','.css':'text/css; charset=utf-8','.json':'application/json','.png':'image/png','.svg':'image/svg+xml','.jpg':'image/jpeg','.ico':'image/x-icon','.webm':'video/webm','.mp4':'video/mp4','.mp3':'audio/mpeg','.wav':'audio/wav','.ogg':'audio/ogg','.ttf':'font/ttf','.woff2':'font/woff2','.bin':'application/octet-stream'};
const server = http.createServer(async (req,res) => {
  try {
    const urlPath = decodeURIComponent(new URL(req.url,'http://local').pathname);
    const base = urlPath.startsWith('/assets/') ? path.join(root,'public') : root;
    const relative = urlPath === '/' ? 'index.html' : urlPath.slice(1);
    const file = path.resolve(base,relative);
    if (!file.startsWith(base + path.sep) || /(^|\/)\./.test(relative) || !['GET','HEAD'].includes(req.method)) {res.writeHead(403);res.end();return;}
    // Serve only web runtime trees, never original working copies or evidence.
    if (!['index.html','src','assets','node_modules/three'].some(p=>relative===p||relative.startsWith(p+'/'))) {res.writeHead(404);res.end();return;}
    const s=await stat(file); if(!s.isFile())throw Error('Not a file');
    const headers={'Content-Type':mime[path.extname(file)]||'application/octet-stream','Accept-Ranges':'bytes','Cache-Control':'no-cache'};
    const match=req.headers.range?.match(/^bytes=(\d+)-(\d*)$/);
    if(match){
      const start=Number(match[1]),end=match[2]?Math.min(Number(match[2]),s.size-1):s.size-1;
      if(start>end||start>=s.size){res.writeHead(416,{'Content-Range':`bytes */${s.size}`});res.end();return;}
      res.writeHead(206,{...headers,'Content-Range':`bytes ${start}-${end}/${s.size}`,'Content-Length':end-start+1});
      if(req.method==='HEAD')res.end();else createReadStream(file,{start,end}).pipe(res);
    }else{
      res.writeHead(200,{...headers,'Content-Length':s.size});
      if(req.method==='HEAD')res.end();else createReadStream(file).pipe(res);
    }
  }catch {res.writeHead(404,{'Content-Type':'text/plain'});res.end('Not found');}
});
server.listen(port,'127.0.0.1',()=>console.log(`Local: http://127.0.0.1:${port}`));
