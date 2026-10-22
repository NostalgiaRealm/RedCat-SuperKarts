# Meer instellingen and optional browser features

The requested **Meer instellingen** button sits below music and effects on the
main **Instellingen** page. The original **Geavanceerd** display dialog remains
separate. The added page uses the original menu background, font, sliders and
button imagery, with new Dutch labels for the requested features.

Changes on this page are a nested draft. Its **OK** returns the draft to the
main settings page; the main **OK** saves it. **Terug** or Escape cancels the
corresponding draft. The unlock action explicitly saves immediately.

## MSAA

**Randen gladmaken (MSAA)** enables multisample anti-aliasing for the world,
karts and effects. The quality choices are **2×**, **4×** and **8×**. It is off
by default; the stored quality defaults to 4×. The original separately rendered
HUD retains its own rendering path.

The renderer queries sample counts shared by RGB565 color and 24-bit depth
renderbuffers. It uses the greatest supported count at or below the request,
or the smallest available count if all available counts are higher. The page
reports the actual fallback once a track renderer is available. On the tested
SwiftShader device, all three requests resolve to supported 4×; true 2×/8×
hardware rendering is not claimed for that device.

The resolved image is copied without another color-space conversion. Native
materials deliberately perform texture modulation and blending on stored RGB
bytes. An extra sRGB conversion would brighten the original artwork. The
browser check verifies actual 5/6/5-bit color storage, real color/depth sample
counts, fractional diagonal-edge coverage, per-draw blend rounding, identical
quantized clear colors, an exact off/on/off image, and target resizing/disposal.
Disabling MSAA replaces its multisampled target with a single-sample RGB565
target. The native colour buffer is retained in both modes; see
[texture and framebuffer precision](research-native-texture-precision.md).

The scene canvas explicitly requests an opaque WebGL2 context. Three r186
otherwise creates an alpha-bearing canvas even when its renderer option says
`alpha:false`; native shadow blending then leaves alpha below one, causing the
browser compositor to brighten the completed RGB image. The final canvas now
presents opaque RGB with MSAA enabled or disabled. The separate transparent HUD
canvas keeps its original transparency.

## Cheats

**Vrij vliegen (no-clip)** is an explicit new feature. The normal movement
controls move and turn the kart; **Space** raises it and **C** lowers it.
Controller shoulders provide up/down, and touch mode adds **Omhoog/Omlaag**.
It crosses terrain, water, scenery and other karts freely. The whole track is
drawn while flying rather than only the normal forward sectors.

The original starting camera and countdown finish first. While flying, race
timers, opponents, pickups, lap/gate awards and random-number consumption are
frozen. Race sound effects pause while music continues. Disabling flight, or
using **Stop vliegen**, restores a checked road position and neutralizes
airborne velocity and wheel state before ordinary racing resumes. This avoids
awarding progress for flying across a finish line or stranding the kart inside
an obstacle. **Stop vliegen** also saves the disabled setting.

**Alles ontgrendelen** immediately saves the six country locks as unlocked.
Profiles, Adventure progress, high scores and records are preserved; it does
not fabricate completed Adventure events. The page reports whether saving
succeeded. Cancelling a settings draft does not undo this explicit action.

## Evidence and scope

The shadow correction and original-code/asset comparisons are recorded in
[research-kart-shadows.md](research-kart-shadows.md). The added graphics and
cheat controls are requested adaptations, not claims about original menus or
native cheat behavior.

The original feature checkpoint is [validation.json](../evidence/more-settings/validation.json):
504 unit tests and 60 browser checks pass, with 110 runtime files unchanged
during the final checks and all 6,844 static build copies matching their inputs.
Its build and counts are historical. The later source-only colour-precision
checks are recorded in [texture precision validation](../evidence/texture-precision/validation.json).
Focused browser reports are retained in
[MSAA](../evidence/more-settings/msaa-validation.json),
[menu and save flows](../evidence/ui/more-settings-browser.json),
[free flight](../evidence/free-flight/browser.json), and
[shadows](../evidence/shadow-audit/browser.json).

Reproduce with `npm test`, `node tests/multisample-browser.mjs`,
`node tests/more-settings-browser.mjs`, `node tests/free-flight-browser.mjs`,
and `node tests/kart-shadow-browser.mjs`, with the local server running.
After rebuilding, `node tools/verify-more-settings.mjs` verifies the retained
reports, frozen runtime hashes and every build copy. The first broad driving
test exposed a stale expectation of positive steering on mirrored Italy;
the corrected test uses the original negative sign. That initial failure is
retained alongside the passing 15-check rerun, with no production change.

Earlier full-race results retain their historical runtime hashes. This focused
feature checkpoint does not rerun or re-label those races as results for the
new renderer and optional cheat implementation. Original Windows framebuffer
comparison and physical controller/mobile/GPU coverage remain separate from
these local source and browser checks.
