#!/usr/bin/env node
// The built website (dist/site) as one archive for the macOS workflow (.github/workflows/macos-release.yml): the
// original game files are not in git, so a Mac runner cannot build the site from the checkout and packages this one,
// the same bytes the Linux and Windows packages carry. The archive is reproducible (sorted names, no owners or
// times, gzip without a name or time), so building it twice from one dist/site gives the same SHA-256.
//   node tools/site-archive.mjs   ->  release/<version>/RedCat-SuperKarts-<version>-site.tar.gz and .sha256
// GNU tar and gzip (Linux). The .gz/.br copies for web servers stay out, as electron-builder.json leaves them out.
import {createHash} from 'node:crypto';
import {createReadStream,existsSync,mkdirSync,openSync,closeSync,readFileSync,writeFileSync,statSync} from 'node:fs';
import {spawn} from 'node:child_process';
import path from 'node:path';
import {fileURLToPath} from 'node:url';

const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const {version}=JSON.parse(readFileSync(path.join(root,'package.json'),'utf8'));
const site=path.join(root,'dist/site');
if(!existsSync(path.join(site,'build.json'))){console.error('site-archive: no dist/site/build.json (npm run package)');process.exit(1);}
const out=path.join(root,'release',version),name=`RedCat-SuperKarts-${version}-site.tar.gz`,file=path.join(out,name);
mkdirSync(out,{recursive:true});

const tar=spawn('tar',['--sort=name','--owner=0','--group=0','--numeric-owner','--mtime=@0','--mode=u+rw,go+r,go-w',
  '--exclude=*.gz','--exclude=*.br','-C',path.dirname(site),'-cf','-','site'],{stdio:['ignore','pipe','inherit']});
const fd=openSync(file,'w');
const gzip=spawn('gzip',['-n','-9'],{stdio:['pipe',fd,'inherit']});
tar.stdout.pipe(gzip.stdin);
const done=p=>new Promise((resolve,reject)=>p.on('close',code=>code===0?resolve():reject(Error(`${p.spawnfile} exited with ${code}`))));
await Promise.all([done(tar),done(gzip)]);closeSync(fd);
const hash=createHash('sha256');
for await(const chunk of createReadStream(file))hash.update(chunk);
const line=`${hash.digest('hex')}  ${name}\n`;
writeFileSync(file+'.sha256',line);
console.log(`${file} (${(statSync(file).size/1048576).toFixed(1)} MB)\n${line.trim()}`);
