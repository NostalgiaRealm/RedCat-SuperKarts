import fs from 'node:fs/promises';
import {fileURLToPath} from 'node:url';
import path from 'node:path';

/** Local static imports actually executed by a headless validation entry point. */
export async function validationSourceDependencies(entry,root){
  const found=new Set(),base=fileURLToPath(root);
  async function visit(url){
    const name=path.relative(base,fileURLToPath(url));
    if(found.has(name))return;
    found.add(name);
    const source=await fs.readFile(url,'utf8');
    for(const match of source.matchAll(/\b(?:import|export)\s+(?:(?:[^;'"]*?)\s+from\s+)?['"](\.[^'"]+)['"]/g))
      await visit(new URL(match[1],url));
  }
  await visit(entry);
  return [...found].sort();
}
