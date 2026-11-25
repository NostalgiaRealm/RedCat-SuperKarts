#!/usr/bin/env node
// Copies the part of the JS reconstruction's prepared assets (../RedCat Superkarts/public/assets, read-only;
// SUPERKARTS_ASSETS overrides) that this port's menu uses into this project's public/assets, so the recomp needs the
// JS port's folder neither on the development server (tools/serve.mjs) nor in a package (tools/package.mjs). The race
// itself reads none of them: it reads the original files (data/).
//
// What the menu uses (source/main.js, source/menu/, source/style.css, source/index.html; the JS port's at 5bfe0b62):
//   config.json, manifest.json   the original INI and DAT files as JSON, and the list of converted assets (main.js:848)
//   menu/   the menu's art, every form's pictures (native-menu.js artPath, the forms of ui/forms.json, style.css)
//   ui/     forms.json (the original menu forms), original.ico (the page's icon), the forms' layouts
//   fonts/  comic.ttf, comicbd.ttf (style.css; the menu's own text)
//   help/   topics.json and its pictures and sound (Help, main.js:395)
//   media/  the intro and the reward movies, *.mp4 (main.js:610, :819)
//   audio/  the menu's voices: config.json ini/soundset.dat generic_samples and ini/{rc,wk,br,mx}_snd.dat sample_set,
//           through manifest.json audio (menu-audio.js)
//   textures/  the race loading screen: e0<country>_<a..d>_hi.tga and image_01..07.tga through manifest.json images
//           (loading-screen.js)
//   touch/  this project's own (the JS port's touch art, already here); left as it is
// A file already here with other content is not replaced (reported); nothing here is deleted.
//   node tools/build-assets.mjs [--check]   (--check: only report what is missing or different, exit code 1 then)
import { existsSync, readFileSync, readdirSync, statSync, mkdirSync, copyFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { ROOT } from './game-data.mjs';

const FROM = process.env.SUPERKARTS_ASSETS || join(ROOT, '..', 'RedCat Superkarts', 'public', 'assets');
const TO = join(ROOT, 'public', 'assets');
const CHECK = process.argv.includes('--check');
if (!existsSync(join(FROM, 'manifest.json'))) { console.error('the JS port\'s assets were not found at ' + FROM + ' (SUPERKARTS_ASSETS)'); process.exit(1); }
const json = (rel) => JSON.parse(readFileSync(join(FROM, rel), 'utf8'));
const walk = (dir, rel) => readdirSync(join(FROM, dir, rel)).sort().flatMap((n) => { const r = rel ? rel + '/' + n : n; return statSync(join(FROM, dir, r)).isDirectory() ? walk(dir, r) : [dir + '/' + r]; });

const want = new Set(['config.json', 'manifest.json', 'fonts/comic.ttf', 'fonts/comicbd.ttf']);
for (const dir of ['menu', 'ui', 'help']) for (const f of walk(dir, '')) want.add(f);
for (const f of walk('media', '')) if (/\.mp4$/i.test(f)) want.add(f);
const manifest = json('manifest.json'), config = json('config.json');
const missing = [];
const viaManifest = (table, name) => { const e = manifest[table] && manifest[table][name.toLowerCase()]; if (e) want.add(e.file); else missing.push(`${table}:${name}`); };
// menu-audio.js: five samples the original names are on neither the installation nor the CD; the menu stays silent
// there (missing in manifest.json too), so they are reported, not an error
const samples = new Set(Object.values(config['ini/soundset.dat'].generic_samples || {}));
for (const f of ['rc_snd.dat', 'wk_snd.dat', 'br_snd.dat', 'mx_snd.dat']) for (const s of Object.values(config['ini/' + f].sample_set || {})) samples.add(s);
for (const s of samples) if (s) viaManifest('audio', s);
for (let c = 0; c < 6; c++) for (const ch of 'abcd') viaManifest('images', `e0${c}_${ch}_hi.tga`);
for (let k = 1; k <= 7; k++) viaManifest('images', `image_0${k}.tga`);

let copied = 0, same = 0, bytes = 0;
const differ = [], absent = [];
for (const rel of [...want].sort()) {
  const src = join(FROM, rel), dst = join(TO, rel);
  if (!existsSync(src)) { absent.push(rel); continue; }
  const size = statSync(src).size;
  bytes += size;
  if (existsSync(dst)) {
    if (statSync(dst).size === size && readFileSync(dst).equals(readFileSync(src))) same++;
    else differ.push(rel);
    continue;
  }
  if (CHECK) { absent.push(rel + ' (not copied yet)'); continue; }
  mkdirSync(dirname(dst), { recursive: true });
  copyFileSync(src, dst);
  copied++;
}
console.log(`${want.size} files the menu uses, ${(bytes / 1048576).toFixed(1)} MB: ${copied} copied, ${same} already here${differ.length ? `, ${differ.length} here with other content (kept): ${differ.join(' ')}` : ''}`);
if (missing.length) console.log(`named by the original but not among the converted assets (the menu stays silent or shows nothing there, as the JS port): ${missing.join(' ')}`);
if (absent.length) { console.log('missing: ' + absent.join(' ')); process.exit(1); }
if (CHECK && differ.length) process.exit(1);
