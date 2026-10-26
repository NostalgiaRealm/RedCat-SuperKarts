import {resolveAsset} from './asset-animation.js';

/**
 * Spawn.cpp builds this original geometry at runtime (0x48c370/0x48c7e0);
 * there is no separate crane mesh. Positions come from nativeRescueRingPositions.
 */
export function getNativeRescueVisualSpec(manifest) {
  const uvStrip = [
    .4921875, .984375, .4921875, .4921875, .984375, .984375,
    .984375, .4921875, .984375, .984375, .4921875, .4921875, .4921875, .984375,
  ];
  const uv = [], rgba = [], index = [];
  let red = 10, green = 60, blue = 170;
  for (let ring = 0; ring < 20; ring++) {
    uv.push(...uvStrip);
    for (let vertex = 0; vertex < 7; vertex++) {
      red += 45; if (red > 255) red = 0;
      green += 65; if (green > 255) green = 0;
      blue += 85; if (blue > 255) blue = 0;
      rgba.push(red, green, blue, 255);
    }
    // D3DPT_TRIANGLESTRIP=5: preserve every triangle, including the original
    // degenerate connector and reversed-facing second copy of the square.
    for (let triangle = 0; triangle < 5; triangle++) {
      const base = ring * 7 + triangle;
      index.push(...(triangle & 1 ? [base + 1, base, base + 2] : [base, base + 1, base + 2]));
    }
  }
  return {
    texture: resolveAsset(manifest, 'images', 's_sfx.tga'),
    textureSource: 'S_SFX.PCX', vertexCount: 140, ringCount: 20,
    uv, rgba, index, blendSource: 'one', blendDestination: 'one',
    // 0x430020 -> 0x491670 -> 0x48f600 restores ZWRITEENABLE=1 before
    // rendering these effects; 0x48d460 retains it.
    depthWrite: true, nativeFunctions: ['0048c370', '0048c7e0', '0048d610', '0048d460', '0048f600'],
  };
}
