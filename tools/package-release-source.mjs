import {createWriteStream} from 'node:fs';
import {mkdir,readFile,rename,rm,stat} from 'node:fs/promises';
import {spawn} from 'node:child_process';
import {pipeline} from 'node:stream/promises';
import {createGzip} from 'node:zlib';
import {parseArgs} from 'node:util';
import {fileURLToPath} from 'node:url';
import path from 'node:path';

const root=fileURLToPath(new URL('..',import.meta.url));
const {values}=parseArgs({options:{
  output:{type:'string',default:'release'},
  ref:{type:'string',default:'HEAD'},
  help:{type:'boolean',default:false},
}});

if(values.help){
  console.log('Usage: npm run release:source -- [--output release/1.0.0] [--ref HEAD]\n'+
    'Run after committing the release, including the entire original-source/ folder.\n'+
    'Creates a Git source archive and a separate complete original-source archive.\n'+
    'Does not run tests, build checks, or archive inspection.');
}else{
  const {version}=JSON.parse(await readFile(path.join(root,'package.json'),'utf8'));
  if(typeof version!=='string'||!/^\d+\.\d+\.\d+(?:-[0-9A-Za-z.-]+)?(?:\+[0-9A-Za-z.-]+)?$/.test(version))
    throw Error('package.json must contain a release version suitable for archive filenames.');
  const original=path.join(root,'original-source');
  if(!(await stat(original)).isDirectory())throw Error('The complete original-source/ directory is required for every release.');
  const output=path.resolve(root,values.output);
  if(output===original||output.startsWith(original+path.sep))
    throw Error('Archive output must be outside original-source/.');
  await mkdir(output,{recursive:true});
  const prefix=`RedCat-SuperKarts-${version}`;

  await writeArchive(path.join(output,`${prefix}-source.tar.gz`),async temporary=>{
    // HEAD (or --ref) is the frozen source release. Commit original-source/ in
    // full beforehand; this archive includes all files in that commit.
    const child=spawn('git',['archive','--format=tar',`--prefix=${prefix}/`,values.ref],{
      cwd:root,stdio:['ignore','pipe','inherit'],
    });
    try{
      await Promise.all([
        completed(child,'git archive'),
        pipeline(child.stdout,createGzip({level:9}),createWriteStream(temporary)),
      ]);
    }catch(error){child.kill();throw error;}
  });
  await writeArchive(path.join(output,`${prefix}-original-source.tar.gz`),async temporary=>{
    // Passing the directory itself includes every descendant, including hidden
    // files and anything ignored by Git. Do not add exclusion patterns here.
    await completed(spawn('tar',['--create','--gzip','--file',temporary,'--directory',root,'original-source'],{
      cwd:root,stdio:'inherit',
    }),'tar');
  });
}

function completed(child,label){
  return new Promise((resolve,reject)=>{
    child.once('error',reject);
    child.once('close',(code,signal)=>{
      if(code===0)resolve();
      else reject(Error(`${label} failed (${signal??`exit ${code}`}).`));
    });
  });
}

async function writeArchive(destination,write){
  const temporary=`${destination}.tmp-${process.pid}`;
  try{
    await write(temporary);
    await rename(temporary,destination);
    console.log(`Created ${path.relative(root,destination)}`);
  }finally{await rm(temporary,{force:true});}
}
