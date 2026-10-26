import path from 'node:path';
import {assertGameRuntime} from '../electron/game-protocol.mjs';

// Local and packaged games both execute generated bundles.
export async function assertServerRuntime(root){
  await assertGameRuntime({root,assetsRoot:path.join(root,'public/assets')});
}

/** Browser and Electron use one allowlist, MIME table and media-range path. */
export async function createWebServer(paths){
  const [{default:http},{Readable},{pipeline},{createGameProtocolHandler}]=await Promise.all([
    import('node:http'),import('node:stream'),import('node:stream/promises'),import('../electron/game-protocol.mjs'),
  ]);
  const handle=await createGameProtocolHandler(paths);
  return http.createServer(async(req,res)=>{
    const abort=new AbortController();
    res.on('close',()=>abort.abort());
    try{
      const response=await handle({url:new URL(req.url,'rcsk://game').href,method:req.method,
        headers:new Headers(req.headers),signal:abort.signal});
      res.writeHead(response.status,Object.fromEntries(response.headers));
      if(req.method==='HEAD'||!response.body){await response.body?.cancel();res.end();}
      else await pipeline(Readable.fromWeb(response.body),res);
    }catch(error){
      if(abort.signal.aborted)return;
      if(res.headersSent)res.destroy(error);
      else {res.writeHead(500,{'Content-Type':'text/plain'});res.end('Unable to read game file');}
    }
  });
}
