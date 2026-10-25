# Texture-key sampling across effects

The October 20 audit extends the reproduced stream-flare outline defect to
the other active texture sampling paths. The original-source conversion
inventory and x86 upload fixtures are separate evidence; this document covers
where their shared loader correction reaches the browser renderer.

## Shared paths and preserved draw rules

All WebGL game textures enter through `TrackViewer.texture`. Records marked
`nativeRGB` now receive the original RGB565 conversion: key-to-black, optional
gamma, channel truncation and protected non-key black. The generated binary
PNG mask identifies the exact semantic key even after Canvas decoding removes
hidden RGB. Stored native channel counts are scaled in the shader. This
implements `0x4b5470` before filtering and keeps vertex alpha independent.
See [the precision follow-up](research-native-texture-precision.md).

Every listed effect uses `createNativeMeshMaterial`, with the source blend
and depth overrides listed below. These settings were not changed for the
key correction. The table describes the shipped default display settings;
world filtering, alpha-effect gates and the HUD sampler's state cache are
covered separately by [the active render audit](research-render-audit.md).
In particular, disabling alpha effects makes the shadow inherit blend factors,
and nearest world filtering gives the HUD a first-render-only linear override.

| Path | Original texture | RGB blend | Depth writes | Sampling |
| --- | --- | --- | --- | --- |
| Flare and ribbon | S_SFX.PCX → s_sfx.tga | ONE / ONE | On | Linear |
| Rescue rings | S_SFX.PCX → s_sfx.tga | ONE / ONE | On | Linear |
| Tyre/damage smoke | S_SFX.PCX → s_sfx.tga | SRCALPHA / ONE | On | Linear |
| Rain and snow | S_SFX.PCX → s_sfx.tga | SRCALPHA / ONE | Off | Linear |
| Rocket explosion | S_SFX.PCX → s_sfx.tga | SRCALPHA / ONE | On | Linear |
| Skidmarks | S_SFX.PCX → s_sfx.tga | INVSRCALPHA / SRCALPHA | On | Linear |
| Homing arm | S_SFX.PCX → s_sfx.tga | Disabled | On | Linear |
| Finish flag | S_SFX.PCX → s_sfx.tga | SRCALPHA / INVSRCALPHA | Off | Nearest |
| Kart shadow | s_shadow.tga | SRCALPHA / INVSRCALPHA | On | Linear |
| Bonus/star/projectile meshes | weapon.tga | Disabled (native mode0) | On | Linear |
| HUD overlay meshes | overlay1–4.tga and configured bonus art | SRCALPHA / INVSRCALPHA | Off | Linear |

Relevant source paths are `0x48a170`/`0x4888b0` (streams), `0x48d460`
(rescue), `0x428a00` (smoke), `0x483350` (weather), `0x4844e0`
(explosion), `0x426e50` (skidmarks), `0x487780` (arm), `0x423280`
(finish flag), `0x4260c0` (shadow), and the `0x490d40`/`0x48f600`
object drawing paths. The [later HUD renderer](research-hud-framebuffer.md)
uses the world's WebGL context and an RGB565 composition target. Its cloned
textures retain independent native sampler state and shared packed source pixels.

The finish flag clones the shared texture only to select its original nearest
filter. The old stream-specific clone has been removed; all active effects
receive the same metadata-gated correction. Source asset pixels, UVs,
geometry, animation and simulation timing are not modified by this change.

## Paths that require distinct interpretation

Black shadow diffuse multiplies every sampled RGB component by zero, so
the pink-key RGB could not tint a shadow even before correction. Its original
vertex opacity is retained; the precision follow-up changes key-edge rejection
and framebuffer rounding. The explosion uses the same
opaque atlas point `(float32(.45), float32(.15))` throughout its original
geometry. The arm's small UV window also remains in opaque atlas artwork.
These are useful unchanged-output controls, not additional claimed defects.
Nearest-filtered finish-flag samples do not mix hidden key RGB into adjacent
texels.

The sky also uses `TrackViewer.texture`, but uses `MeshBasicMaterial` with
the native byte-color pipeline rather than the custom key-cutout shader.
Its image metadata therefore determines whether any key-upload correction
applies; the effect tests do not claim a sky-rendering comparison.

Native menu images remain a separate browser-image path. HUD glyph text uses
Canvas2D with an expanded image from the processed native texture. Neither is
evidence of WebGL key filtering or an original 16-bit framebuffer. Their layout
and compositing remain browser implementations; source image files are unchanged.

Authored TGA alpha and semantic-key transparency are distinct. The native
active RGB16 upload ignores authored alpha; the texture inventory records
those source alpha channels separately and generates the active renderer's
binary key mask. Arbitrary images with genuine fractional alpha are not
eligible for `configureNativeTextureColorKey` merely because they contain
transparent pixels.

## Browser comparisons

`tests/texture-key-effects-browser.mjs` uses the actual shared loader for
the corrected pass and an independent copy of its quantized pixels for its
control. Only the control's key texels regain pink RGB, isolating key bleeding
from the intentional precision change. It samples original rescue UVs/colors, an emitted native smoke fan,
rain/snow atlas windows, the explosion/arm UVs, skidmark UVs and blend,
shadow UVs/black diffuse, the original finish-flag geometry, star and bubble
models, and four HUD models with `Overlay.ini` RGBA. Bounded planar patches
stand in for weather, explosion, arm, skidmark and shadow geometry where the
test concerns texture sampling rather than gameplay placement.

Each comparison verifies visible non-background pixels against the actual
clear-color readback. Tests preserve the material's native blend and depth
settings. The rescue control must reproduce contamination; the shadow,
explosion, arm and nearest-filtered flag must remain identical. Other rows
report their observed differences without asserting that every use of a
keyed atlas must exhibit a defect. Before/after images and the complete
results are saved under `evidence/texture-key-effects/`.

The separate `tests/streams-render-browser.mjs` retains full S_SFX texel
readback: all 8,682 opaque RGB values match independent native conversion,
including the protected red quantum for 2,621 source-black texels; all 7,702
semantic-key texels contribute zero RGB. It also
checks real ArrowUp driving, shared texture ownership, exact strip indices,
ONE/ONE blending and enabled depth writes.

These tests establish WebGL key-RGB contamination and its correction in the
tested paths. The former `.5` cutoff is replaced by the documented historical
driver's greater-than-zero rule. These comparisons do not prove complete
screenshot equivalence with every original Direct3D device.
