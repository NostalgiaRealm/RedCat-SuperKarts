# Original HUD framebuffer and smoke-test maintenance

Source follow-up, 23 October 2026. This completes the two rendering/harness
items in the preceding remaining-work audit. No package or release was made.

## Original-file evidence

The retained decompilation and assembly of `rcskspel.dat` show the overlay
entry `004614d0 → 00462320`, root traversal `00458550/00458760`, and exit
`00462610`. The HUD draws on the race's Direct3D device and framebuffer without
a render-target change or clear. Depth testing is disabled and blending uses
`SRCALPHA / INVSRCALPHA`.

`0045b450` registers composites, elements, fonts and strings in that order.
`00458900/00459170` append children, and traversal visits them in ascending
order. Consequently the bonus frame/item precede its label, while root
countdown and notification strings follow the grouped meshes. Dynamic stars
append under their original Stars parent. The port derives this order from
`Overlay.ini` rather than drawing all strings as a separate pass.

The glyph builder `0045ed60` uses exact atlas rectangle edges without a
half-texel inset. Its quads use the top-left to bottom-right diagonal.
`00459440` supplies the string/element vertex RGBA. Texture-key rejection and
vertex alpha are independent: filtered black key RGB participates in sampling,
zero coverage is discarded, and vertex alpha determines the subsequent blend.
See [the texture precision profile](research-native-texture-precision.md) for
original upload instructions and the contemporary driver reference.

This follow-up reused retained native functions, assembly, original assets and
instruction fixtures. It does not claim a new working native race capture;
WineD3D remains unsuitable for that comparison on this machine.

## Source implementation

`HudTextRenderer` draws original font quads with the same packed texture and
native material path as HUD models. `RaceHud` interleaves glyphs and models in
the recovered hierarchy order. Canvas 2D no longer composites race HUD pixels.

The world first renders into its RGB565 target at the selected race resolution.
The same WebGL renderer then copies it into a full-display RGB565 composition
target, draws the HUD there, and presents the opaque image. Thus every HUD
blend rounds into a 5/6/5-bit destination. The additional full-display target
preserves sharp lettering when race resolution is reduced, responsive anchors,
and optional MSAA. Scaling the world to a different display size remains a
browser extension, not an original-resolution parity claim.

Each HUD refresh starts from the clean world target. Pausing and repeatedly
redrawing translucent labels therefore cannot accumulate darkening. Glyph
geometry/materials and independently sampled HUD texture clones are retired
on race reload; the shared world renderer and textures remain owned by the
viewer. The transparent `race-hud` DOM canvas only supplies layout dimensions.
The independent requestAnimationFrame loop is unchanged and remains uncapped.

`viewer.renderStats` records world, HUD and final presentation separately.
Smoke tests now measure actual world geometry rather than the final one-triangle
copy, and inspect packed font/key pixels instead of obsolete Canvas/PNG-image
assumptions. HUD screenshots/readback use the complete WebGL image.

## Focused validation

Only relevant checks were run; there were no full races, full unit-suite runs,
asset regeneration, desktop builds or publication.

- 23 native hierarchy, glyph, mesh, sampler, notification-order and layout tests.
- 120 glyph pixel samples using the original atlas, controlled tint/alpha,
  keyed edges and consecutive RGB565 blends. Real attachments report
  5/6/5/0 bits; a 400×300 world composes with an 800×600 HUD. Frozen redraw,
  MSAA off/on/off and glyph cache/disposal checks pass.
- Existing world RGB565/MSAA checks and 197 texture/material GPU samples pass.
- HUD coverage across all four modes, portrait layouts, arrows and hit notices;
  HUD pixels remain identical against a fixed backdrop on mirrored courses.
- Off/on/off graphics settings preserve original gamma and captured HUD sampler
  state. Three race reloads plus final cleanup preserve world-owned GL handles
  and delete exclusive HUD handles, including hidden bonus atlases.
- Repaired Chromium smoke tests pass: browser 13, startup 5, driving 16 checks.
  The driving check compares frozen world-only and world-plus-HUD pixels on all
  six tracks. Firefox passes its three inspection tracks and keyboard driving.
  Source Electron passes all 12 checks with its normal sandbox enabled.

Reports include `evidence/hud-framebuffer/browser.json`,
`evidence/hud-framebuffer/validation.json`, `evidence/texture-precision/browser.json`,
`evidence/display/runtime-browser.json`, and
`evidence/followup/hud-texture-lifecycle-browser.json`. Browser/desktop reports
retain their own platform scope. GPU checks use Linux software rendering;
exact historical hardware rasterization, dithering and rounding, real-device
refresh rates and native Windows/macOS execution remain unverified.
