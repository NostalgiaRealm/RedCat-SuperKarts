import {cp,rm,access,rename} from 'node:fs/promises';
import path from 'node:path';
import {bundleRuntime,projectRoot} from './bundle.mjs';
for(const file of ['source/index.html','source/main.js','public/assets/menu/manifest.json'])await access(path.join(projectRoot,file));
const output=path.join(projectRoot,'dist'),staging=path.join(projectRoot,'dist.tmp');
await rm(staging,{recursive:true,force:true});
try{
  const {manifest}=await bundleRuntime(staging);
  await cp(path.join(projectRoot,'public/assets'),path.join(staging,'assets'),{recursive:true});
  // Retain the previous usable output until compilation and asset copying succeed.
  await rm(output,{recursive:true,force:true});
  await rename(staging,output);
  console.log(`Static browser build ready in dist/: ${manifest.sourceModules} modules combined into ${manifest.files.filter(file=>file.endsWith('.js')).length} JavaScript files. Original assets included.`);
}catch(error){await rm(staging,{recursive:true,force:true});throw error;}
