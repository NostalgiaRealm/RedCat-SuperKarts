import * as THREE from 'three';
import {nativeTextureChannelScale} from './native-texture-upload.js';

// Original table at 004fa400, consumed by 0048f600. Values are D3DBLEND enums.
const factors = [
  {source: 2, destination: 1}, // ONE, ZERO
  {source: 5, destination: 6}, // SRCALPHA, INVSRCALPHA
  {source: 2, destination: 4}, // ONE, INVSRCCOLOR
  {source: 5, destination: 6},
];
const threeFactor = {1: THREE.ZeroFactor, 2: THREE.OneFactor,
  4: THREE.OneMinusSrcColorFactor, 5: THREE.SrcAlphaFactor, 6: THREE.OneMinusSrcAlphaFactor};

export function getNativeMaterialSpec({placementType = 0, blendMode = null} = {}) {
  // 0043e140 assigns the render-object field; mesh alpha does not select mode.
  const mode = blendMode ?? (placementType === 9 ? 1 : placementType === 10 ? 2 : 0);
  if (!Number.isInteger(mode) || !factors[mode]) throw new Error(`Unknown native blend mode: ${mode}`);
  return {mode, transparent: mode !== 0, depthWrite: mode === 0 || mode === 3,
    sourceBlend: factors[mode].source, destinationBlend: factors[mode].destination,
    vertexAlphaAffectsRGB: mode === 1 || mode === 3,
    // 00490d40 queues nonzero modes; 0048f600 traverses insertion order.
    deferred: mode !== 0, sortByDepth: false,
    nativeFunctions: ['0043e140', '00490d40', '0048f600', '004a0d80']};
}

// 004a9ad0's D3DLVERTEX path packs ARGB using trunc(channel*255), not rounded
// bytes. Source JSON retains untouched floats; the render attribute uses bytes.
export function nativeVertexRGBA(data) {
  const count = data.position.length / 3, result = new Uint8Array(count * 4);
  for (let i = 0; i < count; i++) {
    for (let axis = 0; axis < 3; axis++) {
      result[i * 4 + axis] = Math.trunc(Math.fround(Math.fround(data.color?.[i * 3 + axis] ?? 1) * 255));
    }
    // Legacy reader supplies 0x00ffffff; opaque objects ignore its alpha byte.
    result[i * 4 + 3] = data.sourceVersion === 'legacy' ? 0
      : Math.trunc(Math.fround(Math.fround(data.alpha?.[i] ?? 1) * 255));
  }
  return result;
}

export function nativeColorAttribute(data) {
  return new THREE.Uint8BufferAttribute(nativeVertexRGBA(data), 4, true);
}

/** Legacy unconverted-image adapter. Native RGB16 DataTextures already contain
 * packed-channel counts and black key texels; they must not be premultiplied.
 * This fallback is only for original PNGs with their generated binary key mask.
 */
export function configureNativeTextureColorKey(texture, record) {
  if (record?.nativeRGB === true && record.pixelsMadeTransparent > 0) {
    texture.premultiplyAlpha = !texture.userData.nativeTextureFormat;
    texture.userData.nativeColorKeyFilter = true;
    texture.userData.nativeColorKeyRGB = [...record.colorKeyRGB];
    texture.needsUpdate = true;
  }
  return texture;
}

/** D3D3 fixed-function colors are normalized stored bytes. Texture sampling,
 * vertex modulation and destination blending have no sRGB transfer step.
 * Apply to non-helper materials (e.g. the sky) as well. This changes the shared
 * texture annotation intentionally, so every consumer must use this pipeline.
 */
export function applyNativeByteColorPipeline(material) {
  if (material.userData.nativeByteColors) return material;
  if (material.map && material.map.colorSpace !== THREE.NoColorSpace) {
    material.map.colorSpace = THREE.NoColorSpace;
    material.map.needsUpdate = true;
  }
  material.toneMapped = false;
  const compile = material.onBeforeCompile;
  const programKey = material.customProgramCacheKey.bind(material);
  // Capture before replacing onBeforeCompile: Three's default cache key reads
  // that callback dynamically.
  const baseKey = programKey();
  material.onBeforeCompile = function(shader, renderer) {
    compile.call(this, shader, renderer);
    if (this.map?.userData.nativeTextureFormat) {
      const scale = nativeTextureChannelScale(this.map.userData.nativeTextureFormat);
      // Store the exact 5/6-bit integers, not rounded 8-bit expansions. The
      // linear decode commutes with filtering and also covers the sky material.
      shader.fragmentShader = shader.fragmentShader.replace('#include <map_fragment>', THREE.ShaderChunk.map_fragment)
        .replace(/vec4 sampledDiffuseColor = texture2D\(\s*map,\s*vMapUv\s*\);/,
          `$&\n  sampledDiffuseColor.rgb *= vec3(${scale.map(n=>n.toPrecision(12)).join(', ')});`);
    }
    shader.fragmentShader = shader.fragmentShader.replace('#include <colorspace_fragment>',
      '// Native fixed-function RGB already contains the display byte values.');
  };
  material.customProgramCacheKey = () => `${baseKey}-rcsk-byte-colors-${material.map?.userData.nativeTextureFormat ?? 'bytes'}`;
  material.userData.nativeByteColors = true;
  material.needsUpdate = true;
  return material;
}

// The texture's generated PNG alpha represents its original color key. Keep
// that cutout separate from vertex alpha: combined alphaTest=.5 removes lamps.
// Native upload replaces key RGB before filtering. The documented Direct3D/TNT
// default rejects only zero filtered coverage, before vertex-alpha modulation.
// See docs/research-native-texture-precision.md for the hardware scope.
export function createNativeMeshMaterial(map, {
  placementType = 0, blendMode = null, side = THREE.FrontSide,
  colorKeyThreshold = null, textureHasNativeAlpha = false,
} = {}) {
  const spec = getNativeMaterialSpec({placementType, blendMode});
  const material = new THREE.MeshBasicMaterial({
    map, vertexColors: true, side, transparent: spec.transparent, depthWrite: spec.depthWrite,
    blending: spec.transparent ? THREE.CustomBlending : THREE.NoBlending,
    blendEquation: THREE.AddEquation, blendSrc: threeFactor[spec.sourceBlend],
    blendDst: threeFactor[spec.destinationBlend], alphaTest: 0,
  });
  // Native 0048f600 submits each queued object once; Three's default two-pass
  // transparent DoubleSide path would apply its blending twice.
  material.forceSinglePass = true;
  material.userData.native = {...spec, colorKeyThreshold, textureHasNativeAlpha};
  material.onBeforeCompile = shader => {
    shader.fragmentShader = shader.fragmentShader.replace('#include <map_fragment>', `
#ifdef USE_MAP
  vec4 sampledDiffuseColor = texture2D(map, vMapUv);
  ${colorKeyThreshold === null ? 'if (sampledDiffuseColor.a <= 0.0) discard;'
    : `if (sampledDiffuseColor.a < ${Number(colorKeyThreshold).toPrecision(12)}) discard;`}
  diffuseColor.rgb *= sampledDiffuseColor.rgb;
#endif
`);
    // D3DTBLEND_MODULATE (0042cff0's accelerated branch): RGB textures keep
    // interpolated vertex alpha; a genuine alpha format replaces vertex alpha.
    if (textureHasNativeAlpha) {
      shader.fragmentShader = shader.fragmentShader.replace('#include <color_fragment>',
        '#include <color_fragment>\n#ifdef USE_MAP\n diffuseColor.a = opacity * sampledDiffuseColor.a;\n#endif');
    }
  };
  material.customProgramCacheKey = () => `rcsk-material-${colorKeyThreshold}-${textureHasNativeAlpha}`;
  return applyNativeByteColorPipeline(material);
}
