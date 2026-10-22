# Native texture precision and filtered color keys

This follow-up separates three stages that the earlier rendering limitation
combined: CPU texture conversion, GPU texture filtering, and framebuffer writes.
The original target is `rcskspel.dat`, SHA-256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
The original installation and extracted CD remain read-only.

## Display depth and texture-format choice

Both extracted-CD configurations, `data/Game/game.ini` and `data/ini/game.ini`,
set `PROGRAM.RESOLUTION=3`. The installed configuration agrees. The game maps
this option through `00429220 → 004b00c0` to the built-in mode table at
`004fe948`, entry 9: 640 × 480, 16 bits per pixel. The other accelerated options,
4 and 6, request 800 × 600 and 1024 × 768 at the same depth. These are executed
in `evidence/native/texture-format-fixtures.json`.

Sixteen-bit depth does not uniquely specify the channel masks. `004b5ad0` calls
the DirectDraw surface's `GetPixelFormat` and calculates component bit counts
and shifts from its returned masks. The selected device can therefore matter.

`004ac410` chooses the `TXF_16BPP_RGB` category through selector `004ae5e0(3)`.
The enumeration callback `004ad8b0`, especially `004ae3a8–004ae467`, chooses its
concrete format using the current display's component layout:

- The first RGB candidate is accepted only if its total component bits do not
  exceed the display's total.
- A later candidate must also have red, green and blue shifts matching the
  display. Its total bit-count distance must be no worse than the previous
  selection's distance.
- This is not an unconditional preference for the last enumerated format.

Executing both enumeration orders for RGB565 and RGB555 gives:

| Display layout | Enumerated formats | Selected texture layout |
| --- | --- | --- |
| RGB565 | RGB565 and RGB555, either order | RGB565 |
| RGB555 | RGB565 and RGB555, either order | RGB555 |
| RGB888 | RGB565 then RGB555 | RGB565 |
| RGB888 | RGB555 then RGB565 | RGB555 |

The RGB888 cases describe the library callback under controlled input, not the
game's default display mode. A browser RGB565 path is a representative original
16-bit device profile. It must not be described as the sole format the native
game supported.

## CPU conversion is exact and occurs before filtering

The original converter `004b5470` and full TGA loader `004ac010` are already
executed by `tools/native-texture-key-fixtures.py`. See
[the earlier upload audit](research-texture-key.md) for its 3,072 conversion
cases and eight complete TGA loads.

The source converter compares the unmodified source RGB against the exact key
`(255, 0, 127)`. Key pixels become packed zero. For every other pixel, optional
gamma applies integer `channel * channel >> 8`, then component shifts truncate
the result to the selected channel widths. If the result would equal the zero
key, the red component becomes one quantum. These operations precede filtering
and cannot be reproduced correctly by reducing the final screen image alone.

For RGB565, the non-key channel codes are `r >> 3`, `g >> 2`, `b >> 3` after any
gamma operation. RGB555 uses shifts of three for every channel. Non-key black
uploads as `0x0800` or `0x0400`, respectively. Near-key pink remains opaque even
when its packed color equals another near-key pixel. Authored TGA alpha remains
ignored in this active RGB upload path.

An RGBA8 carrier can store the exact integer channel codes plus a separate
binary key mask. Scaling its sampled RGB by `255/31, 255/63, 255/31` recovers
normalized RGB565 values without first rounding them to an 8-bit display
palette. Linear interpolation commutes with this scale. The carrier is a host
implementation; the native surface itself has no alpha channel.

## Filtering and key rejection

The original device constructor and state application,
`004aad10 → 004aaef0`, enable `COLORKEYENABLE` (state 41). The game initializer
`0042cff0` selects `D3DTBLEND_MODULATE` (state 21, value 2) and, with `FILTER=2`,
linear minification and magnification (states 17/18, value 2). Neither captured
initializer writes `ALPHATESTENABLE` (15), `ALPHAREF` (24), `ALPHAFUNC` (25), or
`DITHERENABLE` (26). This is recorded in the new original-instruction fixture.

A review of the 120 direct vtable-offset `+0x5c` calls in the retained complete
assembly found no writes of those four states. The ten calls with register
state operands load state 1 (texture handle). That static inventory corroborates
the captured initialization; it does not instrument every possible native
execution or establish driver defaults by itself.

NVIDIA's contemporary [Color Key in Direct3D](https://developer.download.nvidia.com/assets/gamedev/docs/ColorKey.pdf)
describes the DDK sequence: derive an alpha mask per texel from the key, filter
RGB and alpha, then reject fragments through an alpha comparison. It says a
driver enables a greater-than-zero comparison when an RGB color-keyed texture
is used without an application alpha test, and identifies TNT's implementation
as alpha testing. The texture's key RGB participates in filtering. This supports
discarding only zero sampled coverage as a documented reference profile,
instead of the port's previous 0.5 cutoff. It also supports retaining the
game's pre-filter black substitution. Dividing filtered RGB by coverage would
undo that substitution. The paper places key rejection before vertex color
modulation; the native draw's blend factors and vertex alpha remain separate.

This is primary vendor evidence for a reference behavior, not a captured race
on every historical accelerator. Other hardware can differ. In particular,
Microsoft's [primitive-capability reference](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/d3dcaps/ns-d3dcaps-_d3dprimcaps)
distinguishes texture transparency and color-key blending capabilities. No
universal historical subtexel precision or edge result is claimed here.

## Framebuffer precision is a separate boundary

The game requests a 16-bit output surface for the accelerated modes above.
Hardware performs shading, fog and blending before conversion into the target
pixel format; the NVIDIA pipeline description places destination conversion
after blending. Consequently, a final image-only quantization pass cannot
reproduce the intermediate destination rounding used by overlapping effects.

The scene renderer now uses a real RGB565 render target for the chosen profile
because every write, including blending, reaches that format. It retains this
target with MSAA off and chooses supported RGB565/depth sample counts with MSAA
on. Dithering is disabled during drawing and the caller's state is restored.
The final copy presents opaque RGB without an additional sRGB conversion.
It still uses the browser driver's supported rasterization and conversion
rules. The original CPU bytes cannot determine a 1999 device's framebuffer
rounding, driver overrides, dithering pattern or sample precision. The captured
game initialization does not request dithering. Browser multisampling is an
intentional extension, and a separate Canvas/HTML HUD or menu is not an original
16-bit Direct3D framebuffer merely because the world has a 16-bit target.

## Focused source validation

The consolidated [validation record](../evidence/texture-precision/validation.json)
lists commands, results and current source hashes. No builds or full-race suite
were run for this change.

- Six upload tests compare all 96 loader pixels and 3,072 converter-grid
  outputs with the original instructions, including both formats and gamma.
- Material/display/MSAA unit checks preserve vertex alpha, blend factors,
  exact-key decisions, sampler settings and supported sample-count selection.
- `tests/native-texture-precision-browser.mjs` checks 197 rendered pixel samples
  within one output byte, including low nonzero coverage, both texture formats,
  gamma, all four native blend modes, additive effects and the sky. It also
  checks the live loader, shared HUD clones and expanded font pixels.
- Stream checks compare every S_SFX texel with independently calculated packed
  values. Fifteen effect/HUD comparisons isolate hidden pink contamination from
  the intentional precision change. Display off/on/off reloads retain the
  original gamma/filter rules and independent HUD samplers.
- MSAA checks observe actual 5/6/5/0-bit attachments, distinguish sequential
  blend rounding from final-only quantization, and cover resize, disposal,
  off/on/off stability and dither-state restoration. Shadow checks retain
  viewport-edge visibility and verify browser presentation against readback.

These checks use Chromium with SwiftShader. They establish the implemented
profile, not a capture of an original race on historical graphics hardware.

## Reproduction and analysis limits

Run only the focused fixture when changing this behavior:

```sh
re-python tools/native-texture-format-fixtures.py
```

It executes 12 complete original enumeration callbacks across six sequences,
the device constructor and render-state initializers, and three accelerated
display-mode selections. Format descriptors and array memory are controlled
inputs. Logging, matrix-constructor results, INI lookup and COM calls are stated
service boundaries. The actual selection comparisons and state-writing
instructions execute unchanged. The output is
`evidence/native/texture-format-fixtures.json`.

REA validated the original target identity during this pass, but live
decompilation was unavailable: the configured Hopper provider was owned by
another REA session, and this session had no configured Ghidra provider. No
other session was stopped or reconfigured. The investigation therefore reused
the retained Ghidra functions and complete assembly, then executed the original
bytes in the existing Unicorn environment. These new fixtures are not REA
Evidence records and do not claim a working native race framebuffer under Wine.
