// Original RGB24 converter 004b5470, reached by the accelerated TGA loader
// 004ac010 through 004b5740. See docs/research-texture-key.md and the captured
// original-instruction fixtures in evidence/native/texture-key-fixtures.json.
export const NATIVE_TEXTURE_COLOR_KEY_RGB = Object.freeze([255, 0, 127]);

function nativeTextureFormat(format) {
  if (format !== 'RGB565' && format !== 'RGB555') {
    throw new RangeError(`Unsupported native texture format: ${format}`);
  }
  return {redShift: format === 'RGB565' ? 11 : 10,
    greenDrop: format === 'RGB565' ? 2 : 3, greenMask: format === 'RGB565' ? 63 : 31};
}

/** Pack decoded source RGBA bytes into the original 16-bit RGB surface.
 * Source alpha is deliberately ignored: the accelerated initializer selects
 * TXF_16BPP_RGB, including for 32-bit TGAs. Only the exact, unquantized source
 * RGB key becomes zero. Consequently packed zero also serves as the key mask.
 *
 * A generated PNG's binary key alpha is a host encoding, not source alpha.
 * Callers decoding that PNG through a canvas must first restore the semantic
 * key RGB at transparent pixels, because canvas readback clears hidden RGB.
 */
export function packNativeTextureRGBA(rgba, {format = 'RGB565', gamma = false} = {}) {
  const {redShift, greenDrop} = nativeTextureFormat(format);
  if (!rgba || !Number.isInteger(rgba.length) || rgba.length % 4 !== 0) {
    throw new TypeError('Native texture pixels must contain complete RGBA bytes');
  }
  const data = new Uint16Array(rgba.length / 4);
  const protectedBlack = 1 << redShift;
  for (let source = 0, target = 0; source < rgba.length; source += 4, target++) {
    let red = rgba[source], green = rgba[source + 1], blue = rgba[source + 2];
    // Key comparison precedes gamma and channel truncation in 004b5470.
    if (red === 255 && green === 0 && blue === 127) continue;
    if (gamma) {
      red = red * red >> 8;
      green = green * green >> 8;
      blue = blue * blue >> 8;
    }
    const packed = ((red >> 3) << redShift) | ((green >> greenDrop) << 5) | (blue >> 3);
    // The original reserves zero for the key and moves ordinary black one
    // stored red quantum away from it; near-pink RGB must remain visible.
    data[target] = packed || protectedBlack;
  }
  return data;
}

/** Store exact native channel counts in RGBA8 without rounded RGB expansion.
 * The shader scales normalized sampled RGB using nativeTextureChannelScale.
 * Alpha carries only key coverage, independently of original vertex alpha.
 */
export function nativeTexturePixelsRGBA(packed, {format = 'RGB565'} = {}) {
  const {redShift, greenMask} = nativeTextureFormat(format);
  const rgba = new Uint8Array(packed.length * 4);
  for (let source = 0, target = 0; source < packed.length; source++, target += 4) {
    const value = packed[source];
    rgba[target] = (value >> redShift) & 31;
    rgba[target + 1] = (value >> 5) & greenMask;
    rgba[target + 2] = value & 31;
    rgba[target + 3] = value === 0 ? 0 : 255;
  }
  return rgba;
}

/** Undo RGBA8 normalization to recover the original 5/6-bit RGB fractions. */
export function nativeTextureChannelScale(format = 'RGB565') {
  const {greenMask} = nativeTextureFormat(format);
  return [255 / 31, 255 / greenMask, 255 / 31];
}
