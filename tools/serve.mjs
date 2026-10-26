import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {assertServerRuntime,createWebServer} from './server-runtime.mjs';

const project=fileURLToPath(new URL('..',import.meta.url));
const packaged=process.argv.includes('--dist');
const root=packaged?path.join(project,'dist'):project;
const paths={root,assetsRoot:path.join(root,packaged?'assets':'public/assets'),
  inspectSource:!packaged&&process.argv.includes('--inspect-source')};
try{
  if(packaged){
    const {assertGameRuntime}=await import('../electron/game-protocol.mjs');
    await assertGameRuntime(paths);
  }else{
    const {refreshRuntime}=await import('./refresh-runtime.mjs');
    await refreshRuntime({root});
    await assertServerRuntime(root);
  }
}catch(error){console.error(error.message+(packaged?'\nRun npm run build before npm run preview.':''));process.exit(1);}
const port=Number(process.env.PORT||4173);
if(!Number.isInteger(port)||port<0||port>65535){console.error('PORT must be an integer from 0 to 65535.');process.exit(1);}
const server=await createWebServer(paths);
server.on('error',error=>{
  console.error(error.code==='EADDRINUSE'
    ?`Port ${port} is already in use. The game may already be running at http://127.0.0.1:${port}. Stop that server first or choose another PORT.`
    :error.message);
  process.exitCode=1;
});
server.listen(port,'127.0.0.1',()=>console.log(`Local: http://127.0.0.1:${server.address().port}`));
