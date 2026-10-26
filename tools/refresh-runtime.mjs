import {mkdtemp,rename,rm,mkdir,readFile,writeFile,stat} from 'node:fs/promises';
import {randomUUID} from 'node:crypto';
import {hostname} from 'node:os';
import {setTimeout as delay} from 'node:timers/promises';
import path from 'node:path';
import {pathToFileURL} from 'node:url';
import {bundleRuntime,projectRoot} from './bundle.mjs';

const lockName='.runtime-lock';
async function readOwner(directory){
  try{return JSON.parse(await readFile(path.join(directory,'owner.json'),'utf8'));}
  catch{return null;}
}
function ownerExited(owner){
  if(owner?.hostname!==hostname()||!Number.isSafeInteger(owner.pid)||owner.pid<=0||!owner.token)return false;
  try{process.kill(owner.pid,0);return false;}
  catch(error){return error.code==='ESRCH';}
}
async function recoverExitedOwner(directory){
  const previous=await readOwner(directory);
  if(!ownerExited(previous))return;
  // Only one waiter may remove a dead owner's lock. Recheck after claiming:
  // another waiter may already have replaced it with an active owner's lock.
  const claim=path.join(directory,'reclaim');
  try{await mkdir(claim);}
  catch(error){if(['EEXIST','ENOENT'].includes(error.code))return;throw error;}
  let removed=false;
  try{
    const current=await readOwner(directory);
    if(current?.token===previous.token&&ownerExited(current)){
      await rm(directory,{recursive:true,force:true});removed=true;
    }
  }finally{
    if(!removed)await rm(claim,{recursive:true,force:true});
  }
}
async function acquireRefreshLock(root,timeoutMs){
  if(!Number.isFinite(timeoutMs)||timeoutMs<0)throw Error('Runtime lock timeout must be a non-negative number.');
  const directory=path.join(root,lockName);
  const candidate=await mkdtemp(path.join(root,'.runtime-lock-'));
  const owner={pid:process.pid,hostname:hostname(),token:randomUUID(),startedAt:new Date().toISOString()};
  const started=performance.now();
  try{
    await writeFile(path.join(candidate,'owner.json'),JSON.stringify(owner)+'\n');
    for(;;){
      try{
        // Publishing a non-empty directory atomically avoids an ownerless-lock
        // window if a process crashes between creating a lock and writing it.
        await rename(candidate,directory);
        return async()=>{
          if((await readOwner(directory))?.token===owner.token)
            await rm(directory,{recursive:true,force:true});
        };
      }catch(error){
        if(!['EEXIST','ENOTEMPTY','EPERM','EACCES'].includes(error.code))throw error;
        const current=await readOwner(directory);
        if(!current){
          // The owner can finish between the failed rename and this read.
          // A complete published lock always has owner.json; a persistent
          // invalid lock is reported after the same bounded wait.
          try{await stat(directory);}
          catch(missing){if(missing.code==='ENOENT')continue;throw missing;}
        }else await recoverExitedOwner(directory);
        if(performance.now()-started>=timeoutMs)
          throw Error(current
            ?`Timed out waiting for runtime refresh process ${current.pid} at ${directory}. Let it finish and retry; if its owner is no longer running, remove that abandoned lock.`
            :`Cannot acquire runtime refresh lock at ${directory}. Inspect its permissions or remove an abandoned invalid lock.`);
        await delay(50);
      }
    }
  }finally{await rm(candidate,{recursive:true,force:true});}
}

/** Compile first, then replace only generated files under a cross-process lock.
 * Compilation failures preserve the previous game. Replacement failures roll
 * back; if rollback also fails, retain backups and report their location. */
export async function refreshRuntime({root=projectRoot,lockTimeoutMs=30_000}={}){
  root=path.resolve(root);
  const release=await acquireRefreshLock(root,lockTimeoutMs);
  let staging,preserveBackups=false;
  const replaced=[];
  try{
    staging=await mkdtemp(path.join(root,'.runtime-'));
    const result=await bundleRuntime(staging,{root});
    for(const file of ['src','index.html','runtime-manifest.json']){
      const destination=path.join(root,file),backup=path.join(staging,file+'.previous');
      const entry={destination,backup,saved:false,installed:false};
      replaced.push(entry);
      try{await rename(destination,backup);entry.saved=true;}
      catch(error){if(error.code!=='ENOENT')throw error;}
      await rename(path.join(staging,file),destination);entry.installed=true;
    }
    return result;
  }catch(error){
    const rollbackErrors=[];
    for(const entry of replaced.reverse()){
      try{
        if(entry.installed)await rm(entry.destination,{recursive:true,force:true});
        if(entry.saved)await rename(entry.backup,entry.destination);
      }catch(rollbackError){rollbackErrors.push(rollbackError);}
    }
    if(rollbackErrors.length){
      preserveBackups=true;
      throw new AggregateError([error,...rollbackErrors],`Runtime replacement and rollback failed. Previous files are preserved at ${staging}.`);
    }
    throw error;
  }finally{
    try{if(staging&&!preserveBackups)await rm(staging,{recursive:true,force:true});}
    finally{await release();}
  }
}

if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){
  const {manifest}=await refreshRuntime();
  console.log(`Runtime refreshed: ${manifest.sourceModules} modules → ${manifest.files.filter(file=>file.endsWith('.js')).length} JavaScript files in src/.`);
}
