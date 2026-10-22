import assert from 'node:assert/strict';
import fs from 'node:fs';
import test from 'node:test';
import {NATIVE_TEXTURE_COLOR_KEY_RGB, packNativeTextureRGBA,
  nativeTexturePixelsRGBA, nativeTextureChannelScale} from '../src/native-texture-upload.js';

const native = JSON.parse(fs.readFileSync(
  new URL('../evidence/native/texture-key-fixtures.json', import.meta.url)));

test('all 96 pixels from eight original TGA uploads match packed RGB565/RGB555 bytes', () => {
  assert.equal(native.sourceSha256, '68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f');
  let pixels = 0;
  for (const upload of native.uploads) {
    const actual = packNativeTextureRGBA(upload.sourceRGBA.flat(), {
      format: upload.pixelFormat, gamma: upload.gamma,
    });
    assert.ok(actual instanceof Uint16Array);
    assert.deepEqual([...actual], upload.packedPixels,
      `${upload.pixelFormat}, gamma ${upload.gamma}, ${upload.sourceBits}-bit TGA`);
    assert.deepEqual(upload.keyRange, [0, 0]);
    pixels += actual.length;
  }
  assert.equal(native.uploads.length, 8);
  assert.equal(pixels, 96);
});

test('all 3072 original near-black and near-pink conversions preserve the exact source key', () => {
  let pixels = 0;
  for (const grid of native.quantizationGrids) {
    const actual = packNativeTextureRGBA(grid.cases.flatMap(({rgb}) => [...rgb, 255]), {
      format: grid.pixelFormat, gamma: grid.gamma,
    });
    assert.deepEqual([...actual], grid.cases.map(({packed}) => packed),
      `${grid.pixelFormat}, gamma ${grid.gamma}, ${grid.region}`);
    assert.equal(actual.filter(pixel => pixel === 0).length, grid.zeroCount);
    for (let index = 0; index < actual.length; index++) {
      const [red, green, blue] = grid.cases[index].rgb;
      assert.equal(actual[index] === 0, red === 255 && green === 0 && blue === 127);
    }
    pixels += actual.length;
  }
  assert.equal(pixels, 3072);
});

test('native RGB upload ignores all source-alpha values without treating ordinary black as key', () => {
  const colors = [[...NATIVE_TEXTURE_COLOR_KEY_RGB], [0, 0, 0], [1, 1, 1],
    [254, 0, 127], [255, 1, 127], [40, 120, 200], [255, 255, 255]];
  for (const format of ['RGB565', 'RGB555']) {
    for (const gamma of [false, true]) {
      for (const rgb of colors) {
        const data = Array.from({length: 256}, (_, alpha) => [...rgb, alpha]).flat();
        const packed = packNativeTextureRGBA(data, {format, gamma});
        assert.ok(packed.every(value => value === packed[0]));
      }
    }
    const keyAndBlack = packNativeTextureRGBA([255, 0, 127, 255, 0, 0, 0, 0], {format});
    assert.deepEqual([...keyAndBlack], [0, format === 'RGB565' ? 0x0800 : 0x0400]);
  }
});

test('conversion leaves source bytes intact and respects a typed-array view boundary', () => {
  const input = new Uint8ClampedArray([99, 99, 99, 99,
    255, 0, 127, 0, 40, 120, 200, 128, 99, 99, 99, 99]);
  const before = input.slice();
  const data = packNativeTextureRGBA(input.subarray(4, 12));
  assert.deepEqual([...data], [0, 11225]);
  assert.deepEqual(input, before);
  data[1] = 0;
  assert.deepEqual(input, before);
  assert.deepEqual(packNativeTextureRGBA([]), new Uint16Array());
});

test('unsupported formats and incomplete RGBA input are rejected', () => {
  assert.throws(() => packNativeTextureRGBA([0, 0, 0, 255], {format: 'RGBA4444'}), RangeError);
  assert.throws(() => packNativeTextureRGBA([0, 0, 0]), TypeError);
  assert.throws(() => packNativeTextureRGBA(null), TypeError);
});

test('RGBA8 adapter stores native channel counts and separates keyed zero from protected black', () => {
  for (const format of ['RGB565', 'RGB555']) {
    const greenMaximum = format === 'RGB565' ? 63 : 31;
    const packed = packNativeTextureRGBA([255, 0, 127, 255, 0, 0, 0, 0,
      255, 255, 255, 0, 40, 120, 200, 255], {format});
    const before = packed.slice();
    const rgba = nativeTexturePixelsRGBA(packed, {format});
    assert.deepEqual([...rgba], [0, 0, 0, 0, 1, 0, 0, 255,
      31, greenMaximum, 31, 255, 5, format === 'RGB565' ? 30 : 15, 25, 255]);
    assert.deepEqual(packed, before);
    const scale = nativeTextureChannelScale(format);
    assert.deepEqual(scale, [255 / 31, 255 / greenMaximum, 255 / 31]);
    // A filtered half-white/half-key sample must retain half intensity, not
    // divide RGB by key coverage or become alpha-premultiplied a second time.
    for (let channel = 0; channel < 3; channel++) {
      const sample = .5 * rgba[8 + channel] / 255;
      assert.ok(Math.abs(sample * scale[channel] - .5) < 1e-15);
    }
  }
});
