#!/usr/bin/env node
// Package the shipped launcher artwork; no renderer, image library, or new art.
import {readFile, writeFile, mkdir} from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {createHash} from 'node:crypto';
import {deflateSync} from 'node:zlib';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const args = process.argv.slice(2);
let source = path.join(root, 'public/assets/ui/original.ico');
let output = path.join(root, 'desktop/icons');
let check = false;
for (let i = 0; i < args.length; i++) {
  if (args[i] === '--check') check = true;
  else if (['--source', '--output'].includes(args[i]) && args[i + 1]) {
    const key = args[i++];
    if (key === '--source') source = path.resolve(args[i]);
    else output = path.resolve(args[i]);
  } else throw new Error(`Unknown or incomplete option: ${args[i]}`);
}
const hash = data => createHash('sha256').update(data).digest('hex');
const requireValue = (condition, message) => {
  if (!condition) throw new Error(message);
};

function decodeOriginalIco(data) {
  requireValue(data.length >= 22 && data.readUInt16LE(0) === 0 &&
    data.readUInt16LE(2) === 1 && data.readUInt16LE(4) === 1,
  'Expected the original launcher ICO with exactly one image.');
  const width = data[6] || 256, height = data[7] || 256;
  const size = data.readUInt32LE(14), offset = data.readUInt32LE(18);
  requireValue(offset >= 22 && offset + size === data.length,
    'Original ICO image offset/size is invalid.');
  const dib = data.subarray(offset, offset + size);
  requireValue(dib.length >= 40 && dib.readUInt32LE(0) === 40 &&
    dib.readInt32LE(4) === width && dib.readInt32LE(8) === height * 2 &&
    dib.readUInt16LE(12) === 1 && dib.readUInt16LE(14) === 8 &&
    dib.readUInt32LE(16) === 0,
  'Unsupported source icon: expected the shipped bottom-up, uncompressed 8-bit DIB.');
  const paletteSize = dib.readUInt32LE(32) || 256;
  requireValue(paletteSize <= 256, 'Invalid original icon palette size.');
  const colorOffset = 40 + paletteSize * 4;
  const colorStride = Math.ceil(width / 4) * 4;
  const maskStride = Math.ceil(width / 32) * 4;
  const maskOffset = colorOffset + colorStride * height;
  requireValue(dib.length === maskOffset + maskStride * height,
    'Original icon palette, color plane, or transparency mask is incomplete.');
  const rgba = Buffer.alloc(width * height * 4);
  let transparentPixels = 0;
  for (let y = 0; y < height; y++) {
    const originalY = height - 1 - y;
    for (let x = 0; x < width; x++) {
      const index = dib[colorOffset + originalY * colorStride + x];
      requireValue(index < paletteSize, 'Original icon references a missing palette color.');
      const p = 40 + index * 4, target = (y * width + x) * 4;
      const masked = (dib[maskOffset + originalY * maskStride + (x >> 3)] >> (7 - (x & 7))) & 1;
      // AND=1 with nonblack XOR would invert destination pixels. The shipped
      // icon does not use that operation; fail rather than invent an RGBA equivalent.
      requireValue(!masked || (dib[p] === 0 && dib[p + 1] === 0 && dib[p + 2] === 0),
        'Original icon uses a destination-inverting mask that RGBA cannot preserve.');
      rgba[target] = dib[p + 2];
      rgba[target + 1] = dib[p + 1];
      rgba[target + 2] = dib[p];
      rgba[target + 3] = masked ? 0 : 255;
      transparentPixels += masked;
    }
  }
  return {width, height, rgba, dib, directoryEntry: data.subarray(6, 22), transparentPixels};
}

function nearest(original, size) {
  const rgba = Buffer.alloc(size * size * 4);
  for (let y = 0; y < size; y++) for (let x = 0; x < size; x++) {
    const sx = Math.min(original.width - 1, Math.floor((x + 0.5) * original.width / size));
    const sy = Math.min(original.height - 1, Math.floor((y + 0.5) * original.height / size));
    original.rgba.copy(rgba, (y * size + x) * 4, (sy * original.width + sx) * 4,
      (sy * original.width + sx) * 4 + 4);
  }
  return rgba;
}

const crcTable = Uint32Array.from({length: 256}, (_, n) => {
  for (let i = 0; i < 8; i++) n = (n >>> 1) ^ ((n & 1) ? 0xedb88320 : 0);
  return n >>> 0;
});
function chunk(type, bytes) {
  const name = Buffer.from(type, 'ascii');
  const out = Buffer.alloc(12 + bytes.length);
  out.writeUInt32BE(bytes.length, 0);
  name.copy(out, 4); bytes.copy(out, 8);
  let crc = 0xffffffff;
  for (const value of out.subarray(4, out.length - 4)) crc = crcTable[(crc ^ value) & 255] ^ (crc >>> 8);
  out.writeUInt32BE((crc ^ 0xffffffff) >>> 0, out.length - 4);
  return out;
}
function png(size, rgba) {
  const header = Buffer.alloc(13);
  header.writeUInt32BE(size, 0); header.writeUInt32BE(size, 4);
  header[8] = 8; header[9] = 6; // 8-bit RGBA, no interlacing.
  const rows = Buffer.alloc(size * (1 + size * 4));
  for (let y = 0; y < size; y++) rgba.copy(rows, y * (1 + size * 4) + 1, y * size * 4, (y + 1) * size * 4);
  return Buffer.concat([Buffer.from('89504e470d0a1a0a', 'hex'), chunk('IHDR', header),
    chunk('IDAT', deflateSync(rows, {level: 9})), chunk('IEND', Buffer.alloc(0))]);
}
function windowsIcon(original, pngs) {
  // Retain the source's 32px DIB byte-for-byte for the native small-icon path.
  const sizes = [original.width, 48, 64, 128, 256];
  let offset = 6 + sizes.length * 16;
  const header = Buffer.alloc(offset);
  header.writeUInt16LE(1, 2); header.writeUInt16LE(sizes.length, 4);
  const images = sizes.map((size, index) => {
    const bytes = index === 0 ? original.dib : pngs.get(size);
    const p = 6 + index * 16;
    if (index === 0) original.directoryEntry.copy(header, p);
    else {
      header[p] = size === 256 ? 0 : size;
      header[p + 1] = header[p];
      header.writeUInt16LE(1, p + 4); header.writeUInt16LE(32, p + 6);
    }
    header.writeUInt32LE(bytes.length, p + 8); header.writeUInt32LE(offset, p + 12);
    offset += bytes.length;
    return bytes;
  });
  return {bytes: Buffer.concat([header, ...images]), sizes};
}
function appleIcon(pngs) {
  // Modern ICNS PNG records; no iconutil, native executable, or platform API.
  const formats = [['ic08', 256], ['ic09', 512], ['ic10', 1024]];
  const records = formats.map(([type, size]) => {
    const image = pngs.get(size), header = Buffer.alloc(8);
    header.write(type, 0, 4, 'ascii'); header.writeUInt32BE(image.length + 8, 4);
    return Buffer.concat([header, image]);
  });
  const header = Buffer.alloc(8);
  header.write('icns', 0); header.writeUInt32BE(8 + records.reduce((sum, record) => sum + record.length, 0), 4);
  return {bytes: Buffer.concat([header, ...records]), formats};
}

try {
  let sourceBytes;
  try { sourceBytes = await readFile(source); }
  catch (error) {
    if (error.code === 'ENOENT') throw new Error(`Original launcher icon is missing: ${source}. Run npm run prepare:assets with the original game files first.`);
    throw error;
  }
  const original = decodeOriginalIco(sourceBytes);
  requireValue(original.width === 32 && original.height === 32,
    'The original launcher icon changed size; review its packaging conversion before continuing.');
  const pngs = new Map([48, 64, 128, 256, 512, 1024].map(size => [size, png(size, nearest(original, size))]));
  const ico = windowsIcon(original, pngs), icns = appleIcon(pngs);
  const files = new Map([['icon.png', pngs.get(512)], ['icon.ico', ico.bytes], ['icon.icns', icns.bytes]]);
  const provenance = {
    source: path.relative(root, source).split(path.sep).join('/'),
    sourceSha256: hash(sourceBytes), sourceBytes: sourceBytes.length,
    sourceImage: {width: original.width, height: original.height, bitsPerPixel: 8,
      format: 'uncompressed paletted DIB plus 1-bit AND mask',
      transparentPixels: original.transparentPixels,
      opaquePixels: original.width * original.height - original.transparentPixels,
      rgbaSha256: hash(original.rgba)},
    conversion: 'Original palette RGB and binary transparency preserved. Nearest-neighbor pixel replication only; no smoothing, padding, redrawing, or synthesized detail. Original 32px DIB retained byte-for-byte inside ICO.',
    formats: {'icon.png': {width: 512, height: 512}, 'icon.ico': {sizes: ico.sizes},
      'icon.icns': {records: icns.formats.map(([type, size]) => ({type, size}))}},
    outputs: Object.fromEntries([...files].map(([name, bytes]) => [name, {bytes: bytes.length, sha256: hash(bytes)}])),
  };
  files.set('provenance.json', Buffer.from(JSON.stringify(provenance, null, 2) + '\n'));
  if (check) {
    for (const [name, expected] of files) requireValue((await readFile(path.join(output, name))).equals(expected),
      `Desktop icon is stale or modified: ${name}. Run node tools/prepare-desktop-icons.mjs.`);
  } else {
    await mkdir(output, {recursive: true});
    for (const [name, bytes] of files) await writeFile(path.join(output, name), bytes);
  }
  console.log(`${check ? 'Verified' : 'Prepared'} original desktop icons: PNG 512px; ICO ${ico.sizes.join('/')}px; ICNS 256/512/1024px.`);
} catch (error) {
  console.error(`Desktop icon preparation failed: ${error.message}`);
  process.exitCode = 1;
}
