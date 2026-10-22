# Active render composition audit

This audit compares the current accelerated browser path with the shipped
`rcskspel.dat`, SHA-256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
The evidence is static disassembly/decompilation, execution of original x86
instructions with explicit service boundaries, and browser binding tests.
It does not claim native race framebuffer comparisons; the original race
renderer does not work reliably in the available Wine environment.

## Confirmed discrepancies corrected

* The original soap-hit bubble shell was missing. The separate object manager
  runs `457b60` before racer callbacks in `42f4c0`; its draw therefore uses the
  preceding racer pose. The implemented manager and renderer preserve that
  timing, original mesh/texture, screen blending, independent first-person
  visibility, settled cleanup and replacement cleanup. See
  [bubble shell evidence](research-bubble-shells.md).
* During Spawn relocation, `48ca60` writes the new logical position at
  render-object `+50/+54/+58` but retains that tick's draw-matrix translation
  at `+40/+44/+48`. `4a0d80` draws the old matrix. `4903c0` samples color at
  the new logical position. `4260c0` samples shadow height at the new logical
  X/Z, retains the old matrix X/Z plus 2, and caps height by the new logical
  Y. `423010` moves the sky to the new logical position. The browser now
  preserves these separate fields, including sky interpolation.
* Camera keys `1`–`4` were read without the original modifier rule.
  `41d920` calls `4b3830`, which rejects these unmodified polls while Shift
  is held. `NativePlayerCamera` now uses the same key rule as race lifecycle
  handling. The original query is executed in the strengthened camera
  fixtures, replacing only Win32 `GetAsyncKeyState`.

## Original display option consumers

Menu `45b334` writes `game.ini OPTIONS.FILTER` and `SndGfx.ini GFX_OPTIONS`
`GAMMA`, `ALPHA_BLENDING`, `PARTICLES`. `42b220` reads the latter values.

| Setting | Active behavior |
| --- | --- |
| FILTER=2 | `42cff0` sets linear minification and magnification; other values use nearest. The overlay has a separate cached-state quirk: with nearest world filtering, its first render is linear and subsequent renders are nearest. With linear world filtering, all overlay renders stay linear. See the sequential proof below. |
| GAMMA!=0 | `42ccf0 → 4b5460` enables source-channel `c*c >> 8` conversion before texture packing. It is not a final-screen brightness multiplier. |
| PARTICLES=0 | `4818c0` skips rain/snow construction, including its initialization random draws. Explosion construction is independent. |
| ALPHA_BLENDING=0 | `4288b0 → 428880` disables accelerated tyre/damage clouds. `487af0/4879c0` gate homing arms, `48a570/48a6d0` gate ribbon creation, and `48d610/48d460` gate rescue strips and their angle update. |

The alpha option does not globally disable transparency. `48f600` still
sets each queued model's original blend factors, including the bubble shell.
The shadow callback `4260c0` still draws when alpha is disabled, but skips
writing source/destination factors. `4a0d80` enables blending because the
shadow is mode 1, so it uses inherited factors. `NativeBlendState` tracks
those factors through actual draw callbacks without resetting them for opaque
draws. The separate hardware HUD sets SRCALPHA/INVSRCALPHA at entry, just as
`462320` does, and those factors remain for the following world render.
The tracker begins with Direct3D's ONE/ZERO factors for a new game device.

The WebGL adapter assumes the source/destination alpha operations available
on the selected browser renderer; native unsupported-device fallbacks are
not a claim about running the original Direct3D device.

### Overlay sampler cache and render boundary

The first version of this audit incorrectly described the HUD as always
linear. Executing complete sequential `462320 → 462610` pairs disproved
that claim. Entry saves the actual minification state twice: both
`GetRenderState` calls at `462337/462349` request state 17, even for the
value later restored to magnification. It writes both filters to linear
only when cache `6a6274` differs from the requested cache value. Exit
restores both device states from those saved values and leaves the cache
unchanged. This produces the first-render-only linear override when the
world uses nearest filtering.

The cache request depends on manager byte `+88`. Base constructor
`4604e0`, derived constructor `467a60`, and projection setup `462770`
do not initialize that byte. Four original-instruction sentinel cases
confirm its retention, while adjacent hardware byte `+89` becomes zero.
The browser helper explicitly uses zero for the unspecified byte. Both
zero and nonzero produce the same visible sequence from the shipped
FILTER 0/2 startup states. This does not claim to reproduce unspecified
native heap contents.

`430020 → 467d30 → 4614d0` enters once, draws the whole overlay hierarchy,
then exits once. Font sprites and 3D overlay groups share this boundary.
`NativeHudSamplerState.capture()` therefore advances at a logical native
render, and its saved `current` state serves every intervening browser
refresh and every overlay layer. Private HUD texture clones share the
processed image but do not change the world's sampling. Canvas font
sampling uses the captured state; Canvas rasterization remains a browser
implementation rather than an original Direct3D framebuffer claim.

## Checked ordering that already matched

`41d920` polls camera keys before sector selection and camera update.
`42f4c0` calls it before `430020` render; the post-render `42f9c0` call handles
other keys. Moving camera selection after render would therefore be wrong.

Streams use the retained full render matrix (`4885c0`, ribbon transform
chain through `489c70`), so their rescue translation correctly stays with the
old draw matrix on the relocation tick. They do not use the logical
color-sampling position.

## Reproducible verification

* `tools/native-render-position-fixtures.py` produces 200 original
  `4903c0/4a0d80/4260c0` position and shadow-blend cases, at 24- and 53-bit
  x87 precision, in `evidence/native/render-position-fixtures.json`.
  Ground color selection is intercepted to record the coordinates; the
  original shadow plane evaluation and matrix writes execute.
* `tools/native-display-effect-fixtures.py` executes 32 original cloud
  initialization combinations and eight rescue-ring update gates.
* `tools/native-hud-sampler-fixtures.py` executes 144 complete sequential
  original HUD enter/leave pairs and four constructor/projection sentinel
  cases. `tests/native-hud-sampler.test.mjs` compares the independent
  actual device states and cached state, including unequal initial
  minification and magnification.
* `tools/native-camera-control-fixtures.py` now executes 1,024 key
  combinations, 384 mode/transform cases and eight green transitions.
* `tests/native-render-position.test.mjs`, `native-display-effects.test.mjs`,
  existing shadow/color/smoke tests and render-order tests pass. Logs:
  `evidence/native/render-audit-tests.log` and
  `evidence/native/render-camera-audit-tests.log`.
* `evidence/bubble-shells/browser.json`: four real-browser controlled
  contact, pose, first-person and cleanup checks.
* `evidence/display/alpha-browser.json`: actual WebGL callbacks with alpha
  enabled and disabled, inherited preset factors, HUD reset, cloud/arm/
  stream gates and rescue strips.
* `evidence/camera/browser.json`: five real key sequences, including Shift.
* `evidence/regressions/environment-rescue-browser.json`: ordinary throttle
  drives off the original bridge after a declared starting-pose fixture.
  The actual relocation frame verifies old kart matrix, new sky and color
  sample position, and the split shadow position, then completes all 40
  rescue frames and both original speech events.

Browser checks report no page, shader-console or HTTP errors where those
channels are collected. The camera test collects page errors; the overlapping
alpha/rescue suites collect all three. The scope is these active consumers,
not proof that every legacy renderer/platform branch has been reconstructed.
