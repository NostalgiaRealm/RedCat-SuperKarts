# Native texture upload and color-key filtering

This audit covers the shipped accelerated rendering path in `rcskspel.dat`,
SHA256 `68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
Original inputs remain unchanged. Source functions are exported under
`evidence/native/rcskspel.dat/functions/`; REA/Ghidra independently inspected
the key-range and RGB-conversion functions in
`evidence/native/rea-texture-colorkey.json` and
`evidence/native/rea-texture-rgb-conversion.json`.

## Source image and active format

`0042ccf0` selects accelerated source mode through `004a2cc0(1)` and sets
the semantic source key through `004afdb0(0x7f00ff)`. Color DWORDs here store
red in the low byte, so this key means RGB `(255,0,127)`.

`004a3c50` removes the logical extension, then chooses `.tga` in source mode 1
or `.pcx` in mode 0. A logical request for `S_SFX.PCX` therefore loads the
original `S_SFX.TGA` in the accelerated path. The menu's Delphi bitmap
`clFuchsia` key is a separate mechanism and is outside this conversion.

The initialization branch at `004ac4d9–004ac4ee` calls selector `004ae5e0`
with type 2 for an 8-bit display or type 3 otherwise. The selector's labels are:

| Selector | Label in the binary | Active initializer |
| --- | --- | --- |
| 1 | `TXF_4BPP_RAMP` | No |
| 2 | `TXF_8BPP_RAMP` | 8-bit display |
| 3 | `TXF_16BPP_RGB` | Display depth above 8 bits |
| 4 | `TXF_16BPP_ALPHA` | No |

The full static call inventory has one call to this selector, at `004ac4ea`.
Executing the branch at display depths 8, 16, 24 and 32 confirms selections
2, 3, 3 and 3. This is evidence about the supplied executable's initialization,
not a claim that the library lacks support for alpha texture formats.

TGA loader `004ac010` reads uncompressed 24-bit or 32-bit pixels. Its alpha
conversion branch requires the selected pixel format's alpha flag. Under
the selected RGB format it passes each pixel to `004b5740` as a 24-bit RGB
color, including pixels read from 32-bit source files. The only shipped
32-bit race TGAs, `fran07.tga` and `fran08.tga`, therefore do not provide active
texture alpha in this path. Their source alpha should remain recorded as
asset provenance, while the runtime PNG alpha represents only the key mask.

## Exact key conversion

`004b5740` dispatches RGB24 conversion to `004b5470`. That function performs
the following operations, in this order:

1. Compare the full, unquantized source RGB value against `006a6500`.
2. If it matches, use the key components at `006ab774/778/77c`, initialized
   to zero. The complete assembly inventory contains reads of these globals
   but no direct writes.
3. Otherwise, optionally apply the source's integer gamma operation
   `channel * channel >> 8`, then shift channels to the chosen pixel format.
4. If a non-key color's packed components would equal the key components,
   change its red component by one unit. With the zero key, zero red becomes
   one. This prevents ordinary black and very dark colors from becoming holes.
5. Pack the selected components into the surface pixel.

Palette setup `004b2680` likewise reserves index 254 for the key components.
`004a4a30` converts reserved index `004fc9d8 = 254` through `004b5740(index,8)`
and writes the same packed value into both endpoints of a `DDCOLORKEY`.
The resulting range is `[0,0]`. `004a3d90` calls `SetColorKey` with source
blit flag 8 on the memory surface at `004a40a8`, and on the ordinary device
surface at `004a40e3`. Device initialization `004aad10` defaults its color-key
enable field to 1; `004aaef0` submits that value as render state `0x29`.

Consequently, a naive comparison against *quantized pink* is incorrect.
Near-pink source pixels remain non-key purple pixels. Only the exact semantic
key is converted to black. The separate asset inventory's hypothetical
930 RGB565 / 941 RGB555 additional pink matches must not become extra masks.

Selected original instruction results, with gamma disabled:

| Source RGB | RGB565 upload | RGB555 upload | Key |
| --- | --- | --- | --- |
| `(255,0,127)` | `0x0000` | `0x0000` | Yes |
| `(0,0,0)` | `0x0800` | `0x0400` | No |
| `(1,1,1)` | `0x0800` | `0x0400` | No |
| `(254,0,127)` | `0xf80f` | `0x7c0f` | No |
| `(255,1,127)` | `0xf80f` | `0x7c0f` | No |

## Filter and blend behavior

`0042cff0` sets accelerated texture-map blending to enum value 2
(`D3DTBLEND_MODULATE`). With `[OPTIONS] FILTER=2` it sets magnification and
minification states `0x11/0x12` to value 2 (linear); the other branch uses
value 1 (nearest). These settings do not select a mip filter.

Key RGB replacement belongs to texture upload and is independent of the
later material's blend factors. The generated PNG's binary mask is a host
representation of the key, not authored texture opacity. It must not silently
replace the original vertex alpha or change the pass's blending:

| Source pass | Source / destination blend | Treatment to preserve |
| --- | --- | --- |
| Ordinary mode 0 objects | `ONE / ZERO` | Keyed cutout, otherwise opaque RGB |
| Modes 1 and 3 objects | `SRCALPHA / INVSRCALPHA` | Original vertex alpha; mode 3 retains depth writes |
| Mode 2 objects | `ONE / INVSRCCOLOR` | Original screen-style RGB blend |
| Jet flares and stream ribbons | `ONE / ONE` | Original additive RGB blend |
| Weather and explosion rings | `SRCALPHA / ONE` | Original vertex-alpha-scaled additive blend |
| Tyre marks | `INVSRCALPHA / SRCALPHA` | Original reversed alpha fade |

Object modes are the table at `004fa400` consumed by `0048f600`. Effect
draw states are separately covered by the weather, explosion, skidmark and
stream instruction fixtures; the consumer inventory and browser pixel tests
cover their actual texture bindings. This table does not authorize replacing
any material with conventional alpha blending.

## Port implementation and remaining boundary

Converted race PNGs retain their decoded RGB bytes and have alpha zero only
at exact semantic-key pixels. The runtime now packs `nativeRGB` records through
`packNativeTextureRGBA`: exact key comparison, optional integer gamma, channel
truncation and protection of non-key black, in the original order. All 3,168
retained original-instruction pixels match for RGB565 and RGB555. The browser
uses the RGB565 display profile; format enumeration depends on the original
device, as explained in [the precision follow-up](research-native-texture-precision.md).

GPU textures store the exact native channel counts in RGBA8. The shader scales
them by `255/31, 255/63, 255/31`, avoiding an intermediate rounded 8-bit RGB
expansion. Key texels already contain black; no upload premultiplication is
needed. The generated alpha remains a separate key mask, never authored TGA
opacity or a replacement for vertex alpha. The [HUD framebuffer follow-up](research-hud-framebuffer.md)
draws original glyph quads from the same packed pixels, replacing the earlier
expanded Canvas images. Non-race images retain their own alpha semantics.

The former `.5` filtered-mask cutoff is removed. The shader rejects only zero
coverage, before vertex-alpha modulation, following the documented default
in NVIDIA's contemporary [Color Key in Direct3D](https://developer.download.nvidia.com/assets/gamedev/docs/ColorKey.pdf).
Filtered RGB is not divided by coverage. Blend factors and vertex alpha are
unchanged. This is an evidence-based historical driver profile, not a claim
that every Direct3D device had identical filtering precision or key behavior.

## Reproduction

Run `tools/native-texture-key-fixtures.py` with the project's `re-python`
environment. It writes `evidence/native/texture-key-fixtures.json` and asserts:

- Four original initialization/format-selector cases.
- Eight complete original TGA loads: RGB565/RGB555, gamma off/on, 24/32-bit
  sources; 96 uploaded pixels include exact key, ordinary black, near-black,
  near-key and identical RGB with alpha 0/64/128/255.
- 3,072 original RGB-converter cases exhausting the near-black and near-pink
  quantization cells for both formats and both gamma settings.
- The key range is `[0,0]`, only exact source key becomes zero, and active RGB
  uploads ignore all tested source-alpha values.

The complete original loader's header parsing, pixel read loop and packing
instructions execute in Unicorn. Only file access, DirectDraw surface
allocation/locking, logging and restoration of the host display format are
service stubs. These fixtures neither emulate a GPU nor establish a Wine race
rendering baseline.
