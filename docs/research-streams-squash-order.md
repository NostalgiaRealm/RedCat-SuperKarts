# Streams, squash hazards and render submission

The accelerated browser path now uses the original stream and squash controllers.
The native evidence is isolated execution of the unchanged `rcskspel.dat` instructions;
it is not a claim that the original race renderer works in Wine.

## Squash activation and clocks

`43f740` (type43) updates rotation, takes the truncated Z angle modulo **1024**
even though the initialized angle table has4096 entries, then applies the configured
hit-angle gate and strict integer Manhattan distance below70. Player and NPCs are
tested in that order. `440290` (type44) uses distance below32 and requests squash on
the prop itself for each nearby racer. This executable behavior is preserved.
`43bc70` (type46) updates its mesh clock first, uses distance below95, and activates
only outside frames17..48. Its roster loop starts at1 and includes the player slot:
NPC0 is skipped and the player may be requested twice. Unplaced type47's `43fab0`
equivalent uses distance44 and frames3..38.

Types44/46/47 read the cached player coordinates `53be44/48/4c`; type43 reads the
player's current render object. The cache is initially zero and is updated by
`4325b0` before movement, with the original rescue relocation overwrite retained.
The original frame and proximity functions are executed in1920 fixtures at both
24-bit and53-bit x87 precision in `evidence/native/squash-activation-fixtures.json`.

`48e210` lazily constructs the manager through `48e480`, which reserves player
timer19 and NPC timers20 onward before the OMP props append. `42e910→48e540`
later fills those reserved body identities. Type44's `43f250` registers a1200ms
entry without a game timer. `NativeSquash` shares the race timer bank, uses raw
native ticks for its own deadlines, and preserves the source's retained timer
result for later prop entries. Its720 native frames cover activation, speed
clamps, matrix flattening, aliased wobble, rebound and expiry.

OMP callback families are interleaved by placement index before player/NPC
updates. This matters when an earlier hazard clamps the player's speed before a
later reactive prop samples it. Animated and rotating hazards have simulation-owned
clocks; presentation copies their current frame/transform. Browser construction
passes its existing rotation states; headless construction performs those same
phase draws before racer construction, avoiding duplicate or omitted random draws.
The squash manager runs after skidmarks, before rescue. It consumes no RNG.

## Streams

`NativeStreams` preserves the original racer/rocket registration, duplicate
checks, pool ordering, strip geometry and draw-time ribbon shrink. Baseline
registration uses CHARDATA order (NPCs then player), with the player's color index
equal to opponent count. Turbo callbacks replace the corresponding streams;
`428cc0` restores baseline only when the signed raw timestamp is positive and
strictly more than5000ms old. Projectile state2 adds its streams, and state1
removes them before deactivation.

Stream update follows rescue and uses its captured render matrix/position where
applicable. The player speed input is the original pre-update integer km/h,
including the rescue relocation's zero overwrite; throttle is the native control
value. Capture is called once at the native render boundary because ribbon draw
mutates its widths. Jet strips precede ribbon strips, then homing arms. Both use
the original S_SFX image, ONE/ONE additive blending, enabled depth test/write and
the inherited culling rule. The renderer copies the source's explicit reversed
ribbon strip rather than manufacturing a second side. Streams consume no RNG.

## Submission ordering

`4971f0→497270` renders each visible interval as ROAD, LAND, EXTRA, RAIL batches,
in sector order within each batch. Wrapped intervals remain separate. The
browser group list now follows that order, and its opaque comparator does not
re-sort by material identity. `430020` then invokes `423010` for the sky before
ordinary objects. Sky `4a0d80` inherits enabled depth test/write.

`4918f0` walks engine creation order. On its second texture pass, `4931a0`
submits a kart's shadow immediately before `490d40` submits that kart and its
children. Texture initializers `4a33b0/4a3760` write classifier+44=0 on the
accelerated asset-loading path; `4a3a70` supplies the alternate software case.
The browser assigns ordered slots to OMP objects, then player, then NPCs.
Each shadow occupies its own slot immediately before its kart. Blended model
work remains in the deferred queue in insertion order, followed by skidmarks,
jets, ribbons, arms, rescue, smoke, finish flag, weather and explosions.

`tools/native-render-order-fixtures.py` captures36 original `4918f0` traces and
four original `497270` draw traces, covering visibility, allocated slots,
shadow adjacency and wrapped ranges. Browser binding tests inspect actual
`onBeforeRender` submission order, source stream packets and prop squash matrices.
These tests cover the active accelerated renderer; software texture-classifier
behavior is documented, not silently treated as implemented.

Focused validation passed:1920 native activation cases,720 native squash frames,
the stream packet/manager fixtures,36 object draw traces and four road traces.
The Chromium binding test passed all three scenarios with no JavaScript,
console, shader, HTTP or request errors. Its actual draw callback trace also
caught asynchronous mesh loading assigning wheel IDs out of order; explicit
parent/child submission slots now preserve native slots0..4 regardless of load
completion. The composed tests cover shared construction phases, raw turbo
expiry, hazard registration and post-movement squash transforms.

Pause does not run a squash update or expiry read. Shared timer resume adjusts
only the elapsed pause duration, which is independent of the reference epoch.
The source's separate raw `startedMs` deadline continues aging through pause;
the browser deliberately retains that original branch.
