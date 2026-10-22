# Registered scenery collision

This audit uses `rcskspel.dat` SHA256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
The instruction fixtures are isolated x86 execution, not a successful Wine race.

## Registration and texture rules

`0x43e140` creates OMP objects and selects their initialization from the original
integer object type. `0x4939d0` registers physical objects. `0x499b20` appends
those registered objects, in registration order, after CMP rails from the
current sector and its two neighbours. It excludes inactive objects, flag8
objects, the mover and its two ignored-object slots, and objects at wrapped
sector distance ten or more. It does not look at texture names, pixels,
transparency, or material blend mode.

`0x499630` uses the **current mesh frame's bounding rectangle**, position and
signed away-from-zero integer yaw. This is a planar rectangle test; the image's
opaque silhouette does not replace the rectangle. Both test directions use
`0x49a120`, and object contact uses the paired-body response `0x49b9c0`, including
zero-inverse-mass scenery. It must not be substituted with the CMP rail impulse.

| OMP type | Registration | Initial mass | Restitution | In supplied tracks |
|---|---|---:|---:|---|
| 5, 14, 15, 17, 19 | `43f1b0` | 0 | .1 | type5 |
| 6, 45 | `43d130` | Rotobj `MASSA`, default400 | .1 | type6 |
| 8 | `43f200` | 13000 | .2 | no |
| 23 | `43f3b0` | 300 | .2 | no |
| 24 | `43f360` | 300 | .2 | no |
| 25 | `43f2c0` | 400 | .2 | no |

Other OMP types do not enter this physical registry through their factories.
Type20 trees/bushes and type44 chickens are therefore not made solid merely
because their artwork depicts an object. Type2 scenery has its separate
proximity controller, not a registered rectangle. The out-of-table registration
at `0x444327` belongs to the authored camera-path dummy constructor `0x444240`;
it starts inactive and is not an OMP static-obstacle registration.

The Rotobj stanza for `strobaal_anim` contains mass500 and inertia1, but the
shipped hay bales are type5: that branch ignores the stanza and has zero inverse
mass. Type6 reads `SNELHEID` (default0), `HOOGTE` (default0) and `INERTIA`
(default0); the latter is stored directly in the inverse-inertia field.
All six placed type6 objects use those defaults and mass400.

`tools/audit-scenery-collision.mjs` produces
`evidence/native/scenery-collision-inventory.json`, covering every supplied OMP
placement and its authored mesh/texture association. A texture can appear on
both registered and unregistered objects; the integer factory type governs.
The complementary RMP ground/grip audit is
`docs/research-track-surfaces.md`, with its own complete track-texture inventory.

| Track | Static type5 | Physical animated type6 |
|---|---:|---:|
| Netherlands | 74 | 0 |
| Germany | 24 | 2 |
| England | 116 | 1 |
| France | 14 | 3 |
| Spain | 8 | 0 |
| Italy | 28 | 0 |

## Frame order and integration

Scenery registration occurs during OMP construction, before the player and NPC
factories. Its collision candidates and integration therefore precede racers.
Type6 update `0x43d010` advances/applies its mesh animation before integration;
the collision rectangle changes with the selected frame.

`0x491d30` integrates these flags0 objects once per matching callback range,
with the same always-update bypass used by `0x491530`. Sound-attached objects
have that bypass. It truncates planar velocity before checking ranges, uses
the ordinary Euler kernel and first collision sweep, and skips the player's
second sliding sweep. It updates sector with `0x4932e0` and applies the slope
matrix through `0x4936a0`; it does not call the kart wheel-ground callback.
These objects have no custom contact callback in the shipped type5/type6 table.

The engine's contact latch `+4c` is checked after each response, including each
player substep. `0x491d30` calls the moving body's callback before marking it
and contact object1; it then conditionally calls object2. A no-contact substep
clears only the moving body's latch. Both player `0x4319f0` and NPC `0x417640`
register `0x434c40`. That shared callback reaches player crash handler
`0x4350b0` whenever either contact body is the player. Some directed pairs
therefore call it twice; the audio selector's own 300ms gate handles this.
`0x434f20` truncates the response impulse float at `0x6a5b80` before selecting
its severity. The pure collision adapter preserves this callback order and
provides the impulse to `RaceSimulation.onPlayerCollision` synchronously.

Authored PTH updates occur after rendering. `0x446dd0` always writes the object's
sector while active, but only writes position/yaw/matrix before the terminal
hold interval. Retained collision velocity is not cleared. `0x447210` stops the
path by clearing main-object `+44`, which also removes it from collision
candidates. Activation sets that field again, including when no path slot can
be allocated. The port tracks these write events independently so a held path
does not erase collision displacement.

Rescue clearance is a different list: `0x48c170` visits opponentCount+1 racers,
through `0x417e90`/`0x5081bc`. Registered scenery must not be added to the rescue
occupant list.

## Implementation and validation

`NativeSceneryBodies` owns registered bodies, type6 mesh clocks, path write
synchronization and flags0 integration. `NativeRailCollision` now accepts
per-body bounds, active state, ignored bodies and the original rail-ignore flag.
The caller composes scenery before racer bodies and supplies callback ranges.

`tools/native-scenery-contact-fixtures.py` captures:

- 192 original physics initializations and registry writes.
- 240 original current-frame rectangle constructions.
- 360 original continuous slope matrices and 360 ground-matrix compositions.
- 240 original `0x491d30` visibility/integration cases.

Matrices and initialization fields match exactly. Euler comparisons retain the
existing explicit floating-point tolerance, with both 24-bit and 53-bit x87
precision tested. Six-track coverage additionally checks every registered
mesh bound, order, mass and restitution; tests cover contact response,
inactive exclusion, held path writes and animated collision bounds.

`tools/native-contact-callback-fixtures.py` adds192 original engine callback
cases across both mover identities, both directed contact orders, world/body/no
contact, callback presence and prior latch combinations. These match exactly.
The360 original dynamic sweep fixtures now include120 unequal per-body bounds
cases, including nonzero bottom-corner height. Combined race tests pass all six
tracks at all three difficulties and preserve render-cadence independence.
Chromium driving validation passes all six tracks, analog/controller/touch
input, pause/resume and portrait layout without browser errors.

Unshipped solid types are identified but intentionally rejected by the body
aggregate until their separate controllers are implemented. This does not omit
any registered physical scenery type present in the six shipped tracks.

## Non-solid roadside reactions

All174 shipped type2 placements use `0x43fe80`. State0 calls `0x43c5c0`
with mass4 and proximity override0. `0x43df60` tests **only the player**
through `0x497bd0`: strict squared XZ distance below the squared sum of both
mesh radii. Y, texture alpha and the NPC list are not consulted. The object
launches from the player's local X/Z speeds and heading, consumes three CRT
draws in X/Y/Z order, and enters state1 with gravity-45. It then requests its
own cloned `PION_HIT_CAR` attachment through `0x43b790`, observing the previous
audio listener. There is no physical-registry insertion or force on the racer.

State1 `0x43c870` applies .6 drag and gravity scaled by frame delta, but adds the
resulting velocity directly to position once per callback. It updates sector,
tests height against the current route plane and mesh radius, bounces with
factor-.7 and enters state3 below vertical speed2. State3 `0x43cbf0` uses .8
drag, multiplies angular rates by1.15 and settles at an angle limit of1024.
The final render matrix is written before the final angle clamps; state2 then
stops updating, retaining that matrix.

`native-scenery-reactions.js` implements these operations and a player-only
callback aggregate in OMP order. Its instruction fixtures include240 overlap
checks,240 launches with exact RNG state,360 flight/bounce cases and360 settling
cases, all matching exactly at both x87 precisions. Placement coverage checks
all174 authored objects. The counts by track are24,26,22,51,40,11. Type26 uses
the same named sound attachment but is not placed in any supplied track.
