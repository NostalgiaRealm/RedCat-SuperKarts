# Original racer and projectile streams

`src/simulation/native-streams.js` implements the two separate controllers
from the shipped `rcskspel.dat`: the growing ribbon (`0x489400` family,
manager `0x48a480`) and its attached rotating flare (`0x488100` family,
manager `0x488a90`). Neither consumes the shared random stream.

## Setup and ownership

`0x489300` initializes the racer attachment offset to `[0,10,-28]`;
`0x489350` initializes the rocket attachment offset to `[0,0,-15]`.
The original color table at `0x4f9e60` is retained as six RGB triplets.
Baseline race setup `0x42d7d0` first creates one ribbon per racer in
NPC-then-player order. Color is the racer index, including the player.
Its subsequent player-color2 and repeated NPC creations are rejected by the
existing-body duplicate guard; assigning player color2 would change the result.

Turbo `0x4537f0` replaces the original ribbon. Level1 advances the color;
level2 cycles the ribbon colors; level3 creates two rotating ribbons at
`[-18,12,-12]` and `[18,12,-12]`. `0x428cc0` restores the baseline once the
stored raw tick is positive and signed elapsed time exceeds5000ms.
`NativeStreams.racer(body,racerIndex,level)` implements replacement and the
source setup arguments.

Only rocket projectiles receive streams in `0x456440`. Level2 uses the
authored asymmetric offsets `[-6,0,-15]` and `[6,10,-28]`; the other levels use
one `[0,0,-15]` ribbon. `NativeStreams.projectile(shot)` uses these original
arguments, and `.remove(body)` follows the native swap-with-last deletion,
associated flare removal and paired-ribbon counter behavior.

Creation requires jetstreams and alpha blending enabled and a non-paletted
renderer. Existing manager update/draw require jetstreams and non-paletted
rendering; removal checks jetstreams. Maximums are30 ribbons and20 flares,
with paired creation requiring at most28 existing ribbons. A body cannot
receive another ribbon except through the paired constructor. Flare creation
allows at most three for one body.

## Update versus draw

The frame updates halo, ribbon, flare, arm and generic effect managers in that
order after rescue. `NativeStreams.step(dt,{playerSpeedKmh,playerThrottle})`
preserves the ribbon-before-flare order. The ribbon gate uses the original
stored integer `0x53be34`: `0x432688` truncates
`float32(preUpdateForwardSpeed * float32(3.6))` before player input and force
preparation. Negative/zero player speed adds no new points; other bodies
always add points. Rescue `0x48ca60` separately clears this integer in its
takeover branch. Post-integration speed is not interchangeable.

Each ribbon update prepends two transformed endpoints. A rotating ribbon
advances its angle using the original dt expression, but its second endpoint
is always-10 even if configured size differs from20. Texture coordinates,
six fixed colors and color cycling retain the original arithmetic.

Flare `0x488850` rotates by15 native angle units per callback, independent of
dt. Player size is `throttle * float32(0.2) + configuredSize`; other bodies use
`5 + configuredSize`. Its manager receives the original player size or a2.5
multiple for other bodies. Geometry, seven-vertex crossed option, color and
texture atlas coordinates are retained.

Rendering is skidmarks, halo, flare, ribbon, arm, generic effects, rescue,
smoke, finish flag. Ribbon `0x48a170` invokes `0x489f50` during drawing:
it shrinks every endpoint pair and discards the remaining tail once a pair is
too narrow. The first pairs have distinct shrink factors on long ribbons.
Running this in the update callback or twice per rendered frame changes the
effect. `.draw()` performs that mutation once and returns `{jets,ribbons}`
with original `{position,color,specular,uv}` vertices.

The update reads the engine render matrix after the rescue controller has
applied its display pose. `NativeStreams.step` accepts `renderPose(body)` so
the connected port can supply that matrix and position without replacing the
underlying body identity. Player gates, duplicate detection and removal still
use the original body reference. A composition test checks the override against
the same native-fixture pose and verifies that physics position remains intact.

Both controllers draw triangle strips using `s_sfx.pcx`, enable alpha blending
with source ONE and destination ONE, and disable alpha blending afterward.
They do not change depth-write or culling state. The optional second ribbon
strip omits the last original vertex and reverses the remainder; the helper
returns the exact second packet rather than replacing it with an assumed
two-sided material.

## Synchronous gameplay callbacks

`NativeBonusCombat.onTurbo(shooter,level)` occurs after the turbo character
request and before the FIRE_TURBO sound request. `onProjectileState(shot,2)`
creates the stream before the homing arm; `onProjectileState(shot,1)` removes
it before deactivation on hit, height impact and expiry.

The separate `onExplosion(body)` hook occurs at the two original creation
sites: victim rocket-hit initialization after spin-direction/launch setup and
before HIT_BY_ROCKET/AMHIT, and a projectile's height impact before state1
cleanup. The latter retains the projectile body reference, including its live
position after deactivation. The explosion controller can therefore consume
its original RNG draws synchronously at those sites.

## Verification and explicit storage policy

`tools/native-stream-fixtures.py` executes960 original ribbon update/draw
frames and960 flare frames at both24-bit and53-bit x87 precision. It also
executes720 complete manager creation/removal operations and16 complete
original draw calls. The actual native vector routines, matrix operations,
color/UV writes, buffer retirement and draw packets execute unchanged.
Allocation, resource lookup, debug keyboard and clock inputs are bounded
adapters. `tools/native-stream-setup-fixtures.py` captures30 original caller
branches for baseline, turbo and projectile setup. All comparisons pass in
`tests/native-streams.test.mjs`.

The native constructors leave initial flare vertex memory, two ribbon rainbow
channels and manager paired-count storage untouched. The port deliberately
uses zero storage for those unwritten fields, while preserving the red channel
initialization to200. This is an explicit allocator-state policy, not a claim
that Windows heap contents were always zero. The unused original debug
NumPad7/8/9 toggles are bounded off in these fixtures; no browser shortcut is
introduced for them. These comparisons do not establish whole-game Windows
rendering parity.

## October 20 trail-artifact regression

The reported trailing-effect artifacts prompted a new audit of first
allocation, history insertion, strip topology, color, UVs, mode selection and
inherited render state. No mismatch was found in those simulation rules:
the six native stream tests still pass, including 16 captured native device
calls. Fresh REA analysis of `0x48a170` is saved in
`evidence/native/rea-stream-draw.json`, evidence ID
`ev_cffa8b406513aef62cbde650c9090e2eeda2479b2310e34026e97d2c7ee2c142`.
The source binary SHA-256 is
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.

Actual ArrowUp input reproduced a thin pink rectangular outline around the
rear flare. Isolating ribbons and flares located it in the flare draw. The
larger pink/yellow stripe across the starting road persists with both effects
hidden and was ruled out as a stream artifact.

The flare's original atlas boundary is `63/128`. Its black sprite region
begins at texel63, adjacent to pink keyed texels62. The PNG preserves their
RGB `(255,0,127)` beneath generated alpha0. WebGL's linear filter mixed that
pink RGB into neighboring black samples; the shared shader's later alpha
cutoff admitted those partially covered samples. This produced the outline
without any malformed triangle or trail-history vertex.

The accelerated original does use the TGA: `0x42ccf0` calls `0x4a2cc0(1)`,
which selects source mode `0x6a5edc=1`; `0x4a3c50` substitutes `.tga` for the
logical `S_SFX.PCX` name. The RGB loader `0x4ac010` writes a 16-bit texture,
and `0x4a3d90` applies `DDCKEY_SRCBLT` to its memory/video surfaces at
`0x4a40a8`/`0x4a40e3`. A subsequent deeper audit found that conversion helper
`0x4b5470` explicitly rewrites semantic-key pink to black before packing;
the key's component globals are zero. Non-key colors that quantize to the
same packed black key are adjusted so they remain opaque. This is stronger
evidence than the initial caller-only audit, which had missed that helper.
The original uses an RGB texture and color key, not a synthesized alpha
texture. Its complete GPU filtering behavior remains device-dependent.

The first correction was a private stream-atlas upload. The expanded texture
audit moved this into `TrackViewer.texture` through
`configureNativeTextureColorKey`: original RGB textures with semantic-key
pixels use premultiplied-alpha **upload** with the generated binary key mask,
making those pixels zero RGB before filtering. `StreamVisuals` now uses that
shared corrected texture and does not own or dispose it. This reproduces the
native key-to-black conversion through WebGL upload; it does not mean the
original used alpha blending for color-key transparency. Extracted source
assets remain untouched. Native vertices, UVs, diffuse colors, ONE/ONE
blending, depth writes, culling and draw order remain unchanged.

`tests/streams-render-browser.mjs` renders the original flare vertices in
Chromium with and without the correction. Its control reproduces the
outline; the corrected draw removes3,706 outline pixels, changes zero
interior pixels, and retains158,408 visible glow pixels. A complete atlas
readback verifies all8,682 opaque RGB texels unchanged, including2,621 black
texels, and all7,702 key texels contributing zero RGB. The test also checks
the shared loader's key selection, strip indices, draw count, blend/depth settings and a
real ArrowUp driving capture. Results and images are in
`evidence/streams-regression/browser.json`,
`isolated-flare-before.png`, `isolated-flare-after.png` and
`driving-after.png`. This establishes the diagnosed browser artifact and
its correction; it does not establish full original-driver screenshot parity
or rule out every artifact encompassed by the user's broader description.
