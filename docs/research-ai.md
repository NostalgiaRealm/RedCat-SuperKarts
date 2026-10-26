# Native opponent driving

The active `game.ini` selects `ai_model=0`. The opponents do not use the
player's tire-force model: their callback updates local speed and yaw directly
before the common engine integrator moves them.

All addresses below belong to the original `rcskspel.dat`, SHA-256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
Decompiled functions, instruction exports and executable fixtures are under
`evidence/native/`. No native Wine race screenshot is claimed as a reference.

## Connected implementation

`source/simulation/native-ai-driver.js` exports `NativeAIDriver` for the active
racer transition table and `NativeWaypointOccupancy` for shared waypoint lists.
The constructor requires the original racer table records, track/geometry,
an explicit rail collision adapter, original efficiency value, shared
`NativeRandom`, shared `NativeGroundClock`, and shared occupancy object.

Call `prepare(dt, { difficulty, progressDifference, active, slippery, decision, effect })` for
every actor before integrating any actor. Then call `integrate()` in native
object-list order. `progressDifference` is the integer racer progress minus
player progress, not a distance in metres. Occupancy must also contain the
player; remove/reinsert the player around its integration stage.

`0x415d70` creates the player before the NPCs; `0x4939d0` appends to the
integration list. Thus callbacks and integration visit the player first,
then NPCs in roster order. This differs from the bonus/character roster,
which places NPCs first and the player last.

This preserves the ordering in `0x491530` and `0x491d30`. NPC flags are 3:
they use one Euler step and skip the player's `0x492470` sliding displacement
pass. Their wheel update uses `0x41c4b0`, with yaw-rate steering and a route
plane suspension offset. The shared ground callback uses the NPC gravity
path (`player:false`).

The connected adapter implements normal (0), approach (1/3), chase (2),
finished movement (9), stuck recovery (10), hit effects (24/25), item firing
(26), forced route (27), and timed catch-up (28). It runs the 23 populated
transition rows from `0x407150` in their original order. The `decision`
context supplies the current player/racer bodies, previous race ranks,
engine time in seconds, owned item, shared dropper counter, original profile
timings and fire/respawn callbacks. The hit callback replaces normal NPC
movement while active; player hit processing has a different order.

`RaceSimulation` connects those decisions, dynamic kart contacts, bonuses,
rankings and the original spawn effect. The connected track tests establish
deterministic composition, not a full native executable race comparison.
Dormant state 22's guard `0x40cd30` and hit guard `0x40cd00` return zero in
this binary. No active transition enters the old maneuver state 23. They
are explicitly unimplemented instead of being replaced by normal movement.

## Original routines

| Routine | Established behavior |
| --- | --- |
| `0x417640` | Registers NPC callbacks `0x40b0b0`, ground `0x416650`, collision `0x434c40`; creates cars with flags 3. |
| `0x40b0b0` | Runs transition selection, state dispatch, bonuses/visual state, slippery damping, then NPC wheel presentation. |
| `0x406940` | Dispatches the racer state, updates sector progress and triggers, then applies catch-up except in state 10. |
| `0x4024d0` | Evaluates transition rows in order, retaining guard side effects even when a row does not match. |
| `0x401570`, `0x4016e0` | First-place opponent reacts to nearby player bearing, then may chase at speed ≥30 using a shared RNG draw. |
| `0x409cc0`, `0x409dc0` | Approach/chase use fixed lane order [1,2,0]; chase searches from the player's waypoint and advances its timer. |
| `0x40e4b0` | Stuck recovery, reverse steering/speed, route-plane spring and two distinct wobble orders; repeated recovery can enqueue spawn. |
| `0x409ea0` | Finished movement disables ordinary acceleration, increases steering, applies route-plane spring and wobble. |
| `0x40cde0`, `0x410420` | Item firing decisions use original graph direction, nearest-target order, elapsed pickup time and shared dropper counter. |
| `0x40d070`, `0x40c010` | Timed catch-up uses integer millisecond division and strict reaction deadline checks. |
| `0x406470`, `0x4067e0` | Sector/waypoint markers update finish/laps, speed zones, forced-route flags, slippery state and track turbo. |
| `0x40e180` | Normal racer: closest right waypoint, five-link path search, obstruction check, controls, motion. |
| `0x494000` | Closest waypoint by 3D distance; side 1 right, 0 left, -1 right then left. |
| `0x40ed40` | Depth-first graph search; node 1 becomes route choice, node 2 steering target, node 4 speed target. |
| `0x40f0b0` | For states 0/3, returns current lane preferences before rerolling the preferences for the next visit. |
| `0x40e030`, `0x40e070` | Shared CRT draws: `rand()%100 < max(0,efficiency-1)`, then `rand()%3` chooses a lane order. |
| `0x409b30` | Checks only occupants of the nearest waypoint, excluding self; slower actors within unsigned bearing <1024 or >3072 obstruct. |
| `0x401320` | Unsigned obstacle bearing, including one-turn yaw repair and the exact-zero X difference fix. |
| `0x414360` | Signed target-heading error; subtly different zero-X handling from `0x401320`. |
| `0x4010e0` | Target speed `70 - trunc(min(abs(heading),500)/15)`; throttle grows by `75*dt`, brake by `400*dt`. |
| `0x414470` | Gear-dependent NPC acceleration; original player-table brake power; reverse clamp -13.333f. |
| `0x414750` | Lateral/yaw steering, roll response, disabled/sliding branch, upgrade modifiers. |
| `0x412fd0`, `0x4130e0` | Body roll then pitch wobble, consuming two shared random draws. |
| `0x401200` | Composes speed, steering, yaw dynamics and wobble for registered racers. |
| `0x4062b0`, `0x405fd0`, `0x406100` | Difficulty-dependent catch-up/slowdown. The division in the ramp is integer division. |
| `0x41c4b0` | NPC wheel spin, front steering clamp ±500, shared suspension clamp [-1.11,0]. |
| `0x4944e0`, `0x494510` | Ordered waypoint actor lists with capacity 10. |

Angles are **4096 units per revolution at runtime**. `0x442fc0` overrides
the PE's initial 1024-entry setting through `0x4ac410` → `0x4a1510`.
See `docs/research-startup.md` and the native transform fixtures.

## Native edge cases and explicit policies

`0x40ed40` can return a waypoint while leaving some output-vector components
unwritten. This occurs on the supplied Spain graph with occupied nodes. Native
`0x40e180` then reads retained caller-stack data, whose initial process contents
are unspecified. The adapter uses one shared scratch vector pair, initialized
to zero, and preserves exactly the components that the native routine does not
write. This is an explicit deterministic initialization policy, not a claim
that the original process stack started at zero. Native sentinel fixtures
verify the original output write mask and unchanged path-search choices.

After spawn relocation, the steering target can have exactly the body's XZ
coordinates. `0x414360` divides zero by zero, then calls CRT `__ftol`
(`0x4be698`). Its `FISTP qword` returns integer indefinite
`0x8000000000000000`; the caller uses EAX, which is zero. The port preserves
zero steering in this case. Twelve original-instruction cases cover coincident
targets at both precisions; it is not a guessed recovery direction.

The shooter branch of `0x40cde0` passes an **engine object index** to the
roster-index rank accessor `0x417e90`. Out-of-range indices select the player
rank. World placements allocate object slots before all racers on the six
supplied maps, so this branch uses the player rank there. Other NPC rank
queries use the NPC's roster rank. Logical actor IDs must not silently erase
this native indexing mistake.

## Difficulty selection

`0x42b840` reads `game.ini OPTIONS.difficulty`; `0x4319f0` directly selects
both `cars0/1/2.dat` and `Phys0/1/2.dat` with that value. `Race.ini`'s
`PhysicsModel` is a separate field, not the table-file index. The shipped
cars1/cars2 files are identical; cars0 differs. The player uses its selected
car row, while each NPC uses its AI ID as the racer-table row.

| Difficulty | Slowdown (start sectors, span, factor) | Catch-up (start sectors, span, factor) |
| --- | --- | --- |
| 0 | 1, 11, .055 | 100, 25, 0 |
| 1 | 5, 18, .045 | 5, 15, .05 |
| 2 | 100, 25, 0 | 1, 6, .08 |

These are the original `0x405fd0`/`0x406100` parameters, including integer
division in the intermediate ramp. Race type 3 additionally invokes
`0x4350d0`: only the first ten racer records have steering multiplied by
1.6/1.7/2.5 and acceleration/top-speed fields by 1.15/1.2/1.5 for difficulties
0/1/2. `applyNativeRaceTypeTable` copies the input before applying this once.

Character intelligence, efficiency and reaction settings come from
`npc_ai.ini`; they are not replaced with invented difficulty multipliers.
The catch-up guard's `lastRank=-1` and `rankTime=0` are native constructor
values. No active writer of those two fields has been found, so no synthetic
rank-duration updater is added. State 28 is validated independently but
normally remains unreachable with the observed initialization.

## Animation and hit-state signals

`animationEvents` is a persistent callback queue, cleared only by the visual
consumer. Pickups and projectiles update after native rendering, so their
animation requests survive into the next visual tick. Normal NPC steering
does not call the old maneuver callbacks `0x40c0c0`/`0x40c370`.

Track marker 53 calls `0x40dc10` (TURBO and IDLE_TURBO), and `0x40e760`
repeats those requests for five seconds. `animationTurbo` captures the
pre-expiry input before clearing the native flag. The ordinary callback
then submits race-phase-3 first-place CHEER, TURBO_IDLE, RIGHT_IDLE,
LEFT_IDLE and IDLE in that order. Owned turbo firing `0x4537f0` does not
call the track-turbo animation callback.

Pickup `0x40d610` timestamps the pickup and queues CHEER unless finished.
`0x455b00` calls attacker CHEER `0x40de60` only when an NPC hits the player.
Accepted victim effects enqueue HIT through `0x411830`, `0x411b40`,
`0x411e50` or `0x412090`. NPC state 9 ignores incoming effects. The separate
`0x40ddd0` material-flash flag has a one-second timeout in `0x40ea50`.
Player protection queried by `0x4362e0` is the active hit-effect flag at
player singleton +0x11c, set by `0x435aa0` and cleared by `0x4359a0`.

## Validation and precision

The isolated executable runs use explicit x87 precision of 24 or 53 bits.
CRT startup selects 53-bit precision, but later Direct3D runtime control-word
changes have not been measured on a working original race. These are separate
tested arithmetic environments, not a claim that one has been observed live.
The connected driver currently follows the existing 24-bit simulation path.

| Generator / fixture | Original instruction cases |
| --- | ---: |
| `native-ai-fixtures.py` / `ai-fixtures.json` | 360 control, 480 speed, 480 lateral, 240 composed movement |
| `native-ai-path-fixtures.py` / `ai-path-fixtures.json` | 720 closest waypoint / path, across six tracks |
| `native-ai-support-fixtures.py` / `ai-support-fixtures.json` | 240 lane choices, 240 wobble, 240 catch-up, 240 wheel |
| `native-ai-normal-fixtures.py` / `ai-normal-fixtures.json` | 480 unsigned bearing, 360 full normal callback |
| Same generator with mode 1 / 2 | 720 full approach/chase callbacks |
| Same generator with mode 27 | 360 forced-route callbacks with explicit synthetic marker 66 |
| `native-ai-state-fixtures.py` | 480 player-behind, 480 random-chase, 400 ordered transitions |
| `native-ai-recovery-fixtures.py` | 360 recovery callbacks |
| `native-ai-item-fixtures.py` | 720 graph queries, 720 firing guards, 720 catch-up guards, 720 duration updates, 60 fire handlers |
| `native-ai-trigger-fixtures.py` | 1120 marker updates, 1200 marker dispatches, 120 pickup timestamps |
| `native-ai-finish-fixtures.py` | 360 finished movement, 120 finish timer records |
| `native-ai-difficulty-fixtures.py` | Six complete 20-record table modifications |

The normal callback fixtures execute original `0x40e180`, including the real
graph search, occupied-waypoint checks, lane RNG, motion functions and world
model allocation/release. Only logging and the configuration accessor for the
explicit efficiency input are replaced. They use original data from all six
tracks and all three racer table presets.

`node --test tests/native-ai*.test.mjs tests/native-race-setup.test.mjs`
passes 65 tests at this checkpoint. These include executable fixtures,
connected automatic firing/recovery, and five-second normal traces on all
six tracks at 31/40/60/144 render FPS and with stalls. The separate
`race-simulation.test.mjs` exercises the full connected FSM on all six tracks
and all difficulties, and compares differing render schedules. These do not
establish a complete original-race replay match.

## Roster and starts

`native-race-setup.js` reads the original `AVAILABLE_CHARACTERS` and
`npc_ai.ini` data. Menu `0x46e9bc` chooses the country guest first when
there are four opponents (also for a one-opponent duel), then the other main
characters in configured order. The selected player appears last with AI
ID -1. The country order comes from PE pointer table `0x47bc80`, independently
of the order of available character records.

Runtime `0x44a220` takes each NPC's AI ID as its `carsN.dat` record.
The player record instead comes from `PLAYER.car`: menu `0x45a5dc` calls
`0x45aa8c` to write the selected available-character index, and runtime
`0x42c0a0` loads it into `0x53be2c`. NPC model construction always uses base
car 1 at `0x417640`, before applying the separate character visual.

Quick Race writes four opponents. Runtime `0x42ac60` reads the explicit
`RACETYPEINFO.Opponents` value, so race type alone does not determine count.
The menu player-data race-type count table is `[4,3,3,1]` at `0x47bd10`;
an adventure event's explicit settings must be retained.

`native-race-setup-fixtures.py` executes the grid scan `0x415dd0`, heading
`0x493540` and rank assignment `0x417ae0` for 90 combinations across all six
tracks. These checks compare native track axes as explicit inputs.
Marker 69 supplies the player; 70 onward supply NPCs in roster order.
Fallback placement uses assigned race position and the original lane clamp.
`NativeAIProgress` reuses verified signed sector distance. `0x403d90`
initializes NPC distance to start sector minus the first marker-14 sector
(`0x440e50`); player distance separately starts at zero. The explicit
`progressOriginSector` in `nativeRaceSetup` preserves that asymmetry.

The forced-route handlers are implemented and tested, but none of the six
shipped DMP graphs contains markers 64/65/66. Their fixtures deliberately
overlay marker 66 on original geometry and are labeled synthetic. The normal
spawn path is separately owned by `native-rescue.js`; special spawn-marker
paths remain outside the validated active NPC recovery route.
