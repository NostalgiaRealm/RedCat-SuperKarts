# Gameplay evidence and recovered subsystems

[Documentation index](README.md) · [Movement](#native-data-layouts-and-movement) ·
[Race timing](#lap-and-time-gate-state) · [Input](#timing-and-input) ·
[Pickups and weapons](#pickups-projectiles-and-hit-effects) ·
[Results and progression](#results-scores-and-adventure-progression) ·
[Verification limits](#verification-and-limits)

This document records the investigation in stages. Native input, forces,
wheel/ground contact, integration, collision, race rules, opponents, bonuses and
progression now have connected implementations. Later sections supersede the
initial discovery notes. `feature-parity.md` and `research-followup-audit.md`
describe current coverage and subsequent corrections; the dated validation
reports identify the source versions actually tested.
Complete original race parity has not been established.
The original race currently has rendering problems under Wine/WineD3D, according
to the user's report. That environment must not be treated as a reliable visual
baseline. Instruction emulation described below is separate from Wine gameplay.

## Evidence and reproducibility

All original files are read from the supplied installation's `data` directory.
`tools/inventory_gameplay.py` creates `evidence/gameplay/inventory.json`, containing
source SHA-256 digests, line numbers, all parsed key/value sections, the full
physics/car tables as float32 values **and raw uint32 words**, and unresolved
questions. Run:

```sh
python3 tools/inventory_gameplay.py
re-python tools/generate_native_gameplay_fixtures.py
re-python tools/generate_native_ground_fixtures.py
re-python tools/generate_native_track_fixtures.py
re-python tools/generate_native_race_fixtures.py
re-python tools/generate_native_bonus_fixtures.py
re-python tools/generate_native_projectile_fixtures.py
re-python tools/generate_native_effect_fixtures.py
node --test tests/simulation-*.test.mjs
```

The second command needs the already installed analysis environment's `pefile`
and `unicorn` modules. Tests only need Node and the retained evidence files.
It executes original x86 instructions in memory; it never patches the original
installation. The fixture records the exact executable SHA-256.

The consolidated native export is under
[`original-source/modules/rcskspel.dat/`](../original-source/modules/rcskspel.dat/).
Earlier investigation exports remain referenced as
`evidence/native/rcskspel.dat/functions/`; the [export README](../original-source/README.md)
explains which generated reference files are included and how to reproduce them.
Address references in this document are virtual addresses in that executable.
Do not use a decompiler's inferred types or missing `__ftol` arguments as evidence
of a different algorithm. The brake ramp is one concrete instance where
disassembly was necessary.

## Spookkasteel comparison

Read-only reference inspection included:

- `tools/import_scripts.py`: Davi-Script version 27 grammar, linked references.
- `tools/inspect_scripts.py`: compiled script and native API inventory.
- `docs/player-movement-native.md`: Genesis3D/platformer movement integration.
- `docs/native-refresh-performance.md`: explicit distinction between render
  pacing and simulation.

SuperKarts' `car_ssr.ini` header explicitly calls its engine the **M25 engine**.
Its `game.ini` distinguishes old Autobahn Raser and newer A2 Racer II steering
and AI models. Its authored files are `.d3d`, `.rmp`, `.pmp`, `.dmp`, `.cmp`,
`.omp`, `.pth`, binary `Phys*.dat`/`cars*.dat`, and INIs. No `.dso`, `.ds`,
Genesis3D `.act` or `.bsp` was found in the inspected installation inventory.
The reused approach is evidence-bound extraction, per-system native notes,
separate render/update clocks and regression testing. The Davi-Script parser and
Spookkasteel movement code were deliberately not copied because their formats
and gameplay do not match the discovered inputs.

## Authored feature inventory

Presence in a config or enum does not establish runtime use. The files include
leftover references to police, road-speed violations, Trabants and other earlier
racing games. Those entries must not turn into invented SuperKarts features.

| System | Confirmed authored content | Evidence / remaining verification |
| --- | --- | --- |
| Tracks | Nederland, Duitsland, Engeland, Frankrijk, Spanje, Italie | `track.ini [MAPS]`, six complete file families. Mirrored flag set for Engeland, Frankrijk, Italie. |
| Characters | RedCat, WhizzKitty, Brutus, Max, Nederland, Engeland, Duitsland, Frankrijk, Spanje, Italie | `game.ini [AVAILABLE_CHARACTERS]`; four selectable players and six country guests. Native roster/profile/movie checks are described below. |
| Difficulty | Makkelijk, Normaal, Moeilijk | `ini/shellang.ini [DUTCH] 8..10`; **three**, despite outdated two-level comment in `game.ini`. Native difficulty global `0x53b9f4`. |
| Main modes | Avontuur, QuickRace, Highscore | `ini/shellang.ini`, `ini/trans.dat`. |
| Race types | NormalRace/Landenrace, TimeTrial/Tijdrace, ItemRace/Sterrenrace, DuelRace | `race.ini` enum, menu labels, `ini/brief.dat`. First three appear in QuickRace labels; duel in adventure briefings. |
| Additional enum | BonusRace id 4 | No offered mode or campaign event in the shipped content; see `research-legacy-features.md`. |
| Vehicles | 13 mapping entries: 0..8 indy, 9 ufo, 10 standard, 11 buggy, 12 racer | `car_ssr.ini`; runtime car construction `0x415f90` accepts 0..9. Do not expose 10..12 without confirming they are used. |
| Controls | Up accelerate, Down brake, Left/Right steer, Ctrl bonus, Alt handbrake | `game.ini [INPUT]` VK 38,40,37,39,17,18. Native gamepad and joystick paths separate. |
| Pickup/object enums | Rocket, Bubble, Lightning, Oil, Gum, Water, Turbo 1/2, Time Compression, Shield 1/2/3, Random Bonus, Item | `Etappe0.ini [objecttypes] 29..42`. Active placement, conversion and controller rules are documented below; enum names alone do not establish reachability. |
| Triggers | Start/finish/finish-valid, Time_Check, jump forward/back, kill/respawn, zipper, bonus/weapon/dropper/speed/euro, smart ways, water, player/opponent starts, 3 time gates, ice, rain and snow | `Etappe*.ini [triggers]`; enums include leftovers. Match actual PMP trigger IDs before asserting use. |
| AI | Five levels of awareness/preferences, efficiency, reaction, mass, catch-up timing; ten person entries | `npc_ai.ini [RCR_Global]`, `[Person_0..9]`. Every shipped person currently chooses awareness3, style3, efficiency5, mass3, reaction5, preferred turbo. |
| Progression | Adventure matrix indexed by six countries; selected character/country/race type/difficulty; completed field; result transfer and best times | `race.ini [playerdata]`, `[advmatrix]`, `[RACERS]`, `[PLAYER]`, `[BEST TIMES]`. Native predicates, saves/unlocks and connected browser flows are described below. |
| Outcomes/media | Four character winning movies and six country star movies | `ini/settings.ini [WINMOVIES]`, `[STARMOVIES]`; separate from intro. |
| Weather | Germany snow; England rain; race-type-specific weather sequences | `track.ini [TRACKxy]`. Presence of `type` without `enable` is not sufficient proof weather is active. |
| HUD | Positions 1..5, portraits, minimap, bonus, stars, countdown, lap and best time | `overlay.ini`, Dutch notifications in `language.ini`. |

The later native finish/progression investigation verifies these briefing rules:
star races require exactly twelve stars; normal difficulty permits third place,
hard requires first; duels require winning; time trials require crossing gates
before time runs out. The easy rank cutoff is fifth place. The active root
`game.ini` supplies five laps; the conflicting three-lap `ini/game.ini` is a
legacy copy. Tie handling and restart decisions follow the native paths below.

## Authored constants

`game.ini [BONUS_DATA]` establishes these **configuration values**:

| Parameter | Value |
| --- | --- |
| Max bonus levels | 3 |
| Respawn | 5000 ms |
| Next-pickup timeout | 250 ms |
| Bullet speeds 0/1/2 | 1000 / 750 / 1500 cm/sec |
| Bullet lifetimes 0/1/2/3 | 3000 / 4000 / 5000 / 4000 ms |
| Weapon lock ranges 0/1/2 | 10 / 10 / 0 chunks |
| Weapon owner invincibility | 500 ms |
| Turbo factors | 150 / 160 / 170 percent |
| Gum stick times | 1500 / 1000 / 1000 ms |
| Bubble fly times | 1500 / 2000 / 2500 ms |
| Oil turn times | 1000 / 1000 / 1000 ms |
| Rocket turn times | 3000 / 3000 / 3000 ms |
| Bubble speed factors | 50 / 15 / 0 percent |
| Oil speed factors | 70 / 50 / 30 percent |
| Player/opponent gravity config | 400 / 100; file explicitly says units unknown |

The inventory retains all gum sublevel speed factors, time-gate arrays, zipper
boosts and AI constants. No pickup subsystem has yet been claimed implemented
from these numbers alone.

## Native data layouts and movement

`0x4319f0` loads `cars<difficulty>.dat` into `0x5068d0`, 20 records of `0x7c`
bytes, and `Phys<difficulty>.dat` into `0x505b60`, 20 records of `0xac` bytes.
Three Phys files and four cars files are shipped. The parser preserves every
field and only names fields justified by native labels or consumers.

`source/simulation/native-tables.js` recovers:

- Phys offsets `+00..20`: weight, front/rear weight share, wheel radius,
  front/rear axle-to-CG distance, air surface, maximum steer angle, max brake
  force (`0x419550` labels).
- `+24..38`: paired engine A/B/C parameters; `+3c..68`: two six-gear
  transmission sets; `+6c..70`: max RPM (`0x419c00`, `0x419830`).
- `+74..88`: paired rear tire A/B/C; `+8c..a0`: paired front tire A/B/C;
  `+a4..a8`: friction (rear indices29..34, front35..40, friction41..42).
- Cars acceleration indices6..11, max-speed indices18..23, upshift24,
  downshift25, brake27, friction28, steer30 (`0x41a8e0..0x41ada0`).

The active `stuur_model=0` player path is
`0x4325b0 -> 0x414160 -> 0x415990`. It uses physical forces, unlike the
simpler AI/racer speed path at `0x414470`. Player reverse clamp is **-15 native
speed units**; AI's separate limit is **-13.333**. These must not be conflated.

`source/simulation/native-forces.js` implements isolated native kernels:

| Kernel | Native evidence |
| --- | --- |
| Front/rear slip angle, including reverse sign | `0x414ff0` |
| Weight load and rear handbrake factor 0.6 | `0x4150f0` |
| Tire lateral force | `0x415160` |
| Quadratic engine power | `0x415410` |
| Engine/transmission drive force and brake force | `0x415450` |
| Rolling/aerodynamic/slope resistance | `0x415520` |
| Handbrake ±30000 at speed magnitude≥10, otherwise -speed×1000 | `0x4156c0` |
| Player reverse limit | `0x415990` |

The engine's rigid-body inverse mass and inertia initialization is `0x48fda0`;
force/torque accumulation is `0x4914d0`. The kart ground-contact callback
`0x416650` was recovered after it initially appeared only as an indirect code
pointer. It uses four wheel locations, rendered mesh dimensions, surface
projection and its own filtered time. That system and native rigid-body
integration now have portable implementations, described below. Collision
response and rectangle sweeps are separately checked by the native investigation.
No arbitrary acceleration, cornering, gravity or body dimensions are substituted.

The follow-up input audit keeps the three original device paths distinct:
`0x4325b0` selects keyboard `0x433870`, digital joystick `0x433cf0` or
analog joystick `0x4341d0`, as configured by `0x42ed30`.
Only the digital-joystick handler adds an unshifted Space handbrake fallback.
Keyboard and the browser's analog standard-gamepad adapter therefore do not
inherit that shortcut. The mapped keyboard poll `0x4b3880` rejects ordinary
bindings while Shift is held; `InputState` now applies that gate at sampling
time and resumes still-held keys when Shift is released. Touch and pad sources
remain independent. `native-input-key-gates.json` executes24 original device
handbrake combinations and24 original mapped-key polls; the corresponding
tests also cover held-key restoration and mixed input sources.

`native-player.js` implements the complete active force branch of `0x415990`,
including low-speed lateral/yaw damping, steering changes in reverse, gear/RPM
selection (`0x415840`), tire forces and resistance. Its output and its mutations
to body velocity match 120 original instruction cases. The nine standard body
records at `0x4e02a0 + car*300` contain mass600, length4.5, width1.7; the body
inverse mass/inertia are distinct from named fields in the Phys table.
The later composition audit removed excess intermediate precision here too:
the original stores slip/mass and RPM products, multiplies axle load by0.25
before the tire curve, and rounds resistance, low-speed damping and torque
products in the instruction order. The previous force comparison allowance
hid715 differing outputs across720 complete calls (maximum force/torque
difference0.0078125). Those720 complete calls now compare exactly. A further
2400 recurring frames execute the original force function followed by eight
original Euler substeps, retaining all velocity, position, RPM and gear state
between frames. All stored outputs agree exactly at explicit24-bit precision.
That recurrence intentionally excludes terrain and contact so it isolates
force/integrator composition. One isolated rear-slip double return differs
from host `Math.atan` by one double ULP; the caller's float32 store removes
that difference. The narrow standalone slip check retains a1e-15 allowance.

`native-ground.js` implements `0x416650`, its shared per-car filtered delta,
four wheel contact tests, gravity400/100, height rise thresholds and body basis.
The original leaves the up-vector Y matrix entry untouched; this was verified
in assembly and retained. `0x41c0b0` supplies wheel spin, steering and suspension.
It uses the front-wheel radius for all four suspension offsets. The player
handler calls this wheel updater twice during an active race frame.
The composition audit tightened both callbacks to exact agreement at the
explicit 24-bit fixture precision. The previous JavaScript implementation
rounded several expressions only at their final store; the original rounds
each arithmetic operation. This affected the shared filtered delta, wheel
velocity/position, suspension spin and the normalized body basis. The old
0.002 comparison allowance hid 748 differing stored outputs across160 contact
cases (largest position difference0.000244 native units). These allowances
have been removed for ground and wheel pose. An additional320 recurring
frames use the shipped wheel offsets/radii and retain matrix/wheel storage,
with two original pose callbacks followed by the ground callback each frame.
All640 isolated cases/recurring frames agree exactly. Terrain height answers
remain explicit probe inputs; this is not a whole-race Windows comparison.

`native-track.js` implements native XZ winding (`0x495ed0`), sector selection
(`0x4977d0`), upward-face selection (`0x495fe0`) and plane height (`0x496290`).
It preserves face order: road, land, extra, with normalY greater than0.4.
No matching face uses the sector fallback plane (`0x495cb0`), including the
original final-sector copy from the penultimate sector. It does not use an
arbitrary nearest raycast against all render triangles.

`native-motion.js` connects these systems in original order:
pre-input wheel update, input/forces, second wheel update, planar velocity
quantization, eight Euler/collision substeps, sector update, then ground contact.
Player creation assigns flags3 and selects the player for eight substeps with
`0x493110`; bit4/RK4 is not active on that player path. A collision adapter is a
required constructor input rather than a silent approximation.

Player sector history is also engine state, not the last sector observed by
the race controller. `0x4932e0` copies engine+0x1c to+0x20 before choosing
the new sector; `0x4325b0` uses those two fields for progress and `0x4938e0`
uses them for trigger dispatch. Rescue `0x48ca60`/`0x430ff0` replaces that
history at the destination. The port now passes `body.previousSector` to
player rank progress, weather markers and `NativeRaceState.beginUpdate`.
It retains the separate NPC controller history required by `0x409530`.
The6552 original-code cases cover all six tracks, adjacent and skipped
sectors, both wrap directions and stale race-controller history. The composed
Netherlands moat test verifies that returning to waypoint441 counts only
the native local destination adjustment (nearest sector80 to selected79),
rather than the teleport from the old sector, and fires no distant marker.

The initialized game uses **4096 units per revolution**: `0x442fc0` passes
4096 through `0x4ac410` to `0x4a1510`. This supersedes the PE's initial 1024.
The first kernel fixtures used that PE default and were corrected when the
runtime initialization override was recovered. Original trig table
initialization uses float32 2π and is checked against x86 output.
The Euler routine floors heading for translation, truncates yaw increments
for rotating local velocities, and quantizes X/Z displacement to0.0001.
Both 24-bit and 53-bit FPU modes are tested in `native-integrator.test.mjs`.
The input/force/wheel/track fixtures explicitly select CW0x007f (24-bit); CRT
startup chooses53-bit and the later graphics-device precision state remains an
environment-sensitive question. This precision choice is not claimed as a
complete Windows runtime observation.

`native-start.js` recovers the actual grid placement. `0x415dd0` scans right-side
DMP waypoints for triggers69 (player) and70..73 (opponents). When every required
slot occurs exactly once, `0x415f90` uses those positions and sectors directly;
the legacy lane4/start-chunk/previous-finishing-position path is only a fallback.
The player heading always uses direction1 in `0x493540`. All six tracks'
player starts and headings match original instructions for0,1 and4 opponents.
The unusual tiny DMP Y values are original file contents, loaded unchanged by
`0x493c80`; they are not replaced with a guessed height during initialization.

Browser setup uses the byte-identical `/assets/physics/phys0.dat` through
`phys2.dat`, `parsePhysicsTable(bytes)[car]`, `/assets/cars.json`,
`createNativeTrack(track)` and `nativePlayerStart(track, world)`. Supply those
to `NativePlayerMotion` together with the explicit collision adapter. Its
`step(buttons, deltaSeconds)` returns original-coordinate position,4096-unit
yaw, basis, wheel poses, local velocities, RPM, gear and sector.

## Lap and time-gate state

`native-race.js` implements the player race handlers. `0x4938e0` dispatches the
two trigger slots at one boundary selected from previous/current sector; it does
not invent intermediate crossings when movement skips sectors. The wrap boundary
between the final sector and zero dispatches sector zero in either direction.
Signed progress uses `0x404eb0` and `0x493a40`, including the native half-course
comparison. `0x440e40` arms the finish. `0x440dd0` accepts an armed crossing only
in phases 0, 7 or 8, counts a lap when previous sector is less than current, and
disarms it when crossed backwards. `0x440c30` records laps and best times;
`0x440d70` enters phase 3 when the configured lap count is reached. It also
pauses race timer 3 and, right after `0x440c30` restarted it, lap timer 0. The
port pauses timer 0 at that point and the HUD reads it; timer 3's pause is
represented by the fixed `raceTimeMs`.

The shipped configuration gives all six tracks five laps. Race type 1 loads
time-gate durations from `track.ini` using `trackIndex * 3 + difficulty`.
Triggers 74, 75 and 76 share `0x441e70`: they select the next duration in a
cycle, regardless of trigger number. The cumulative distance must exceed the
previous accepted gate distance plus one, preventing backwards recrossings from
granting repeated time. `0x42f170` enters phase 6 when time expires and plays the
native countdown sound when the integer seconds below six change.

Construct `NativeRaceState` with `nativeRaceSettings(config, trackIndex,
difficulty, raceType)` and the original start sector. Call
`beginUpdate(motion.body.sector, activeMs)` before movement and
`endUpdate(activeMs)` afterwards. The clock input explicitly excludes paused
time. Events expose lap completion, last lap, record, finish, time gate and
countdown effects. The race class intentionally does not assert tournament
qualification or implement the separate split-time, bonus and ice trigger
handlers. Active player jump callbacks are composed by `RaceSimulation`
before player preparation; see `research-player-jump.md`. The earlier
classification of those jumps as legacy was incorrect.

## Three-course completion follow-up

`research-race-completion.md` supersedes the later incomplete Germany/France/
Italy checkpoint retained below. The final current-source runs finish five
laps in648975/812350/565975ms respectively, first place and qualified. Original
jump callbacks and British/direction configuration were corrected. The user
also authorized a player-only rescue safeguard for occupied or overlapping
return positions. `evidence/race-completion/validation.json` records its
distinct scope, 445 tests, seven browser checks and rebuilt-file verification.
Historical full-mode matrices remain evidence for their own source versions.

## Timing and input

Confirmed native static findings from the startup investigation:

- `0x4432a0` waits until `GetTickCount() - previous >= 25 ms`.
- Main simulation runs once per original render, not a separately established
  fixed 32 Hz loop.
- `0x48f3e0` uses delta weights 0.5, 0.25, 0.125, 0.125. History starts at 0.1.
- `0x48f4e0` caps at 0.1 seconds and substitutes 0.1 for exactly zero.
- Race timers use separate `GetTickCount` and explicit pause accumulation.

The reported ~31–32 FPS is not a proved physics frequency. The 25 ms pacing
gate and Windows timer quantization could produce that rate. The startup agent
measured29.20 updates/sec from a stationary Wine/Xvfb frame counter, but that
rendering environment was rejected as a reliable visual baseline and this
measurement does not establish the intended simulation rate.

`native-input.js` reproduces `0x433870`'s newer model:

- Throttle ramps +70/sec, max100, immediately clears when released.
- Brake ramps `truncate(previousBrake + 40×dt)`, max100, clears on release.
- Steering initially jumps to ±15; increments by
  `2×(1−abs(previous)×0.01f)×200×dt`; changing direction first clears to0.
- Release centers at400/sec. Mirrored tracks reverse left/right interpretation.
- Every float operation rounds to single precision, as under the documented
  24-bit x87 mode; the `0.01f` constant is the float at `0x4d2480`.
- Handbrake is an independent button.

**The integer brake step is a concrete frame-rate trap.** At25 ms, holding
brake adds1 per update. Calling the same formula at144 Hz adds0 forever due to
truncation. Multiplying by delta time does not make this original calculation
independent of render rate.

`clock.js` provides a render-independent update host with **no default simulation
frequency**. A caller must provide an explicit interval justified by the chosen
reference behavior. Tests use25 ms solely because it is the native minimum
pacing gate; they do not promote it to a measured Wine baseline. Connected
movement tests explicitly use that25ms interval. `NativeDeltaFilter`
retains the original filter for future captured-trace replay. `RaceClock`
excludes explicitly paused time; pause/resume clears the frame timestamp so a
hidden browser interval does not become a giant catch-up update.

## Pickups, projectiles and hit effects

`native-bonus.js` preserves `0x451f80`'s OMP-type mapping and the six race-type
constructors' enabled categories. Time trials disable all bonuses; star modes
enable stars; the other race modes enable weapons and turbo without stars.
Pickups scan NPCs before the player, except stars test only the player. The
strict pickup deadline is `now > previousDeadline`; the shipped timeout is250ms.
Only opponents arm it: `0x4514e0` passes the loop index to `0x4106b0`, which
writes the player's own deadline (`+0x100`, read by `0x410650`) only for index
-1. The player's index N lands in an unread opponent slot, so the player can
collect consecutive or overlapping pickups (2026-10-28 comparison).
Duplicate weapons level up to3. NPC pickup levels get one extra increment and
an additional increment for an odd shared CRT random draw. Random pickups draw
types1..5. Collected stars never respawn. Other pickups become active after5s
only while the global active-bonus count is below40; this includes owned bonuses
and both projectile pools. Respawn retains elapsed age and contact resumes on
the following controller update.

The original logical type overrides an OMP animation's mesh at initialization.
`nativeBonusVisual(config, manifest, type, level, kind)` reads the actual
`gen_anim.ini` sequence. Constructor frame offsets are0 for pickups,1 for owned
weapons,4 for shots. This matters for two English-course OMP oil bonuses authored
with turbo artwork: the original factory replaces them with the oil paw.
Active pickup yaw increments by `weapon_rotation_speed * dt` (3000 angle units
per second), followed by a matrix rebuild and contact tests. There is no bobbing
in `0x4540c0`. Owned bonuses spin each controller update; their peculiar pitch
assignment is the cosine-table value at angleCount/8, used directly as an angle.

The player fire gate in `0x433870` uses held input bit0x10 and unsigned
`GetTickCount() - lastFire > 500`; it updates the timestamp even with an empty
inventory. `0x451640` consumes owned bonuses. Turbo multiplies the existing
signed forward speed by1.5,1.6,1.7; it neither supplies continuous thrust nor
makes a stationary car move. Normal projectiles use the first inactive slot of
a41-object heap pool. Multi-bubble weapons hatch2 or4 extra projectiles from a
separate40-record static pool, spaced120 native angle units apart.

`native-projectile.js` reproduces launch position and captured local velocity,
lane/graph facing, wrapped-sector homing target selection, flight, lifetime and
height checks. Original quirks retained include:

- Launch X/Z offset uses captured forward speed without a dt or world-scale
  multiplier. Height uses the current shot model radius plus10.
- Level1 rockets do not home; level2 lock range is10 sectors, level3 range0
  means unlimited. Targets within1 sector are excluded.
- The parameter loader assigns the4s `BULLET3_LIFETIME` only to rocket level2;
  levels1/3 retain the15s static defaults. Bubble lifetimes are3/4/5s.
- A projectile records its first integer height once. More than20 units of
  ascent above that initial height deactivates it, except rocket level3.
- A flight step that expires a projectile is still followed by same-frame
  contact tests in `0x455a10`.
- Oil/gum remain until contact; their branch does not run the flying-projectile
  lifetime check. The shooter is immune until age is strictly greater than the
  configured500ms. Other racers are eligible immediately.

**Original uninitialized field:** flight reads shot offset+0x3c as a height
clearance, but neither the primary pool constructor nor `Shoot` writes it.
The original heap contents therefore affect this field. The launch probe
preserves a17.25 sentinel unchanged, and independent native analysis confirms
the missing initialization. `NativeBonusCombat` requires an explicit
`shotClearance` policy for that pool. Zero is a deterministic browser adaptation,
not an observed original value. Secondary bubbles occupy loader-zeroed BSS and
retain clearance0. The code deliberately does not substitute mesh radius.

`native-bonus-effects.js` covers shared rocket/oil spin, gum slowdown and bubble
motion. Contact captures velocity/angles and consumes the shared CRT RNG.
Rocket/oil spin zeros all local velocity, sets yaw rate to signed6.5/duration
and terminates at the duration or a full unwrapped4096-unit revolution; only
forward speed is restored. Gum applies its first speed factor while its timer
is positive, then restores the configured captured speed. Bubbles stop planar
movement while airborne and active, run original vertical/pitch/roll springs,
and finish when the timer/ground conditions and rear-wheel vertical speed allow.
Initial launches write **wheel vertical speeds**, not suspension positions:
rocket/gum launch rear wheels at `level*6+60`; higher-level bubbles launch all
wheels at `level*10+100`. Player launch speeds are doubled.

Composition is in `native-combat.js`. Actors preserve native order (NPCs then
player), current mesh collision radius, body and ground references. Use the same
`NativeBonusPickups` and `NativeRandom` instance. Player firing occurs before
force preparation; player hit effects occur after forces and before integration.
NPC state24/25 skips ordinary AI movement and dispatches the effect instead.
After all movement, `0x451200` rotates owned bonuses, handles static pickups,
handles the primary projectile pool, then handles secondary bubbles. Root's
renderer decides display timing separately; the native controller follows the
render call, so current-frame collection visibility is a separate concern.

## Opponent item decisions and finish rules

`native-ai-items.js` ports the active item guard `0x40cde0`, graph-direction
queries `0x406320/0x410420`, reaction controller `0x40eb20/0x40eba0`,
catch-up guard `0x40d070`, and state26/28 dispatch helpers. The NPC core owns
the ordered state transition table and movement dispatch.

The item guard preserves its different rules for each weapon family. A racer
in first place retains shooters. Other racers find the nearest eligible racer
ahead using the original waypoint graph, with a distance greater than two
sectors. A player target can trigger a rocket immediately; bubbles additionally
require fewer than20 sectors. A protected player is excluded. Other NPC targets
require more than10 seconds since the last pickup. Dropped hazards fire when
the player is behind within four sectors, after more than five seconds, or at
the original shared456789-call fallback counter. Turbo requests firing
immediately. State26 fires once, resets the reaction controller/priorities and
runs ordinary movement in that same update.

`lastBonusTime` and reaction deadlines are **absolute seconds** from
`0x48f4d0`; they are not race-timer milliseconds. `nativeAIBonusCollected`
stores this timestamp even for an already-finished NPC. The caller must supply
consistent time. An adapter that excludes focus pauses differs from the
original absolute clock. The shooter branch also reads rank using the racer
object index, whereas the catch-up guard reads rank using the NPC roster index.
The explicit `rank` arguments preserve these distinct lookups.

Catch-up thresholds/durations use integer division by1000 before comparison;
for example2500ms becomes2 seconds. The constructor initializes `lastRank=-1`
and `rankTime=0`. No active writes to these fields have been found beyond
initialization, so the port must not manufacture a rank timer to activate this
apparently dormant state. Similarly the shipped binary's effect/pickup-scan
guards `0x40cd00/0x40cd30` return zero. All six shipped waypoint graphs contain
no forced-route markers64/65/66; the original handler remains represented for
explicit marker inputs.

NPC trigger order in `0x406940` is movement, sector-progress update, both sector
markers (excluding53), current waypoint marker, then difficulty catch-up.
Integration follows the complete preparation callback. NPC lap handling is
separate from the player's: marker15 arms marker14, and a new lap additionally
requires **more than10 seconds** since the previous accepted finish crossing.
The final lap sets NPC state9. Non-circuit tracks finish immediately on14.
`recordNativeNPCFinish` ports `0x417e30`: for matching NPC object indices it
reads timer9+rosterIndex, stores uint32 milliseconds, pauses that timer and
marks the racer finished. State9 then runs its original disabled steering and
body-spring update; it does not instantly freeze the kart.

Additional reproducible probes:

```sh
re-python tools/native-ai-item-fixtures.py
re-python tools/native-ai-trigger-fixtures.py
re-python tools/native-ai-finish-fixtures.py
re-python tools/native-ai-difficulty-fixtures.py
node --test tests/native-ai-items.test.mjs tests/native-ai-triggers.test.mjs tests/native-ai-finish.test.mjs tests/native-ai-difficulty.test.mjs
```

These cover720 graph/target searches and720 complete weapon decisions on all
six tracks;720 catch-up guards,720 duration updates and60 firing dispatches;
1120 marker updates,1200 native marker dispatches and120 pickup timestamps;
360 finished movement updates across all three racer tables and120 finish-timer
recordings. All compare exactly at both24-bit and53-bit x87 precision. Graph
data, timers and rendering boundaries are recorded in the generators. These
are instruction-level checks, not a full-race runtime baseline.

`applyNativeRaceTypeTable` reproduces the additional `0x4350d0` modifier invoked
by `0x4319f0` only for race type3. After selecting the original difficulty's
`cars0/1/2.dat`, records0..9 receive steering factors1.6/1.7/2.5 and
acceleration/maximum-speed factors1.15/1.2/1.5. Records10..19 stay unchanged.
Six complete native table fixtures cover both x87 precisions. The helper
returns a fresh parsed table so changing modes or restarting cannot accumulate
modifiers. Other difficulty-written globals `0x507284`, `0x4e0198` and
`0x4e019c` have no direct reads found in the complete assembly; no speculative
player-physics change was inferred from those writes.

## HUD coordinates and bonus movement

`native-minimap.js` reproduces the six five-word transforms copied from PE
table `0x4f4620` by `0x466360`. The complete `0x466830` update and `0x4669d0`
orientation helper match720 native updates and160 orientation cases at both
explicit x87 precisions. Outputs are overlay-local coordinates before the
parent transform. Italy's orientation3 swaps the two coordinates without
negation; it is not a conventional quarter-turn rotation.

The minimap constructor enables `DotPlayer` and `DotRacer0..count-1`. It does
not assign character-specific colors or scales. The original player and
opponent meshes are `ovrldot2.d3d` and `ovrldot1.d3d`; all opponent dots share
the latter appearance and the track's original overlay texture.

`NativeBonusHud` in `native-bonus-hud.js` requires the original converted
`BonusObject` overlay-local destination and the initial owned item. The
constructor caches state/type/level. `step(owned, dtSeconds)` performs the
original three-phase controller: state changes start motion from
`[f32(.7),f32(.1),2]`, type/level changes restart an existing transition, and
unchanged items move linearly for1000ms. The deadline uses the unspilled
intermediate before storing float32 elapsed time. Owned angles and render
visibility are copied after movement, overriding the start/reset visibility.
The complete original controller, its original vtable, movement callbacks and
overlay setters match960 native cases. The probe runs `0x465900` to initialize
the original origin, rather than assuming uninitialized zero BSS values.

Reproduction: `re-python tools/native-minimap-fixtures.py` and
`re-python tools/native-bonus-hud-fixtures.py`, followed by their respective
`tests/native-minimap.test.mjs` and `tests/native-bonus-hud.test.mjs` Node tests.

### Sterrenrace collected-star display

`native-star-hud.js` restores the original twelve-symbol counter, which was
missing even though `NativeBonusPickups.stars` already tracked collections.
`0x467e30` creates the stars controller only for race type2 (Sterrenrace).
The controller creates `Star1..Star12` under the authored `Stars` overlay;
`0x46e070` positions them clockwise from the top, with radius
`f32(.14)` and scale `[f32(.18), f32(.18), 1]`. `0x46e260` colors the first N
stars white and the remainder gray (`127,127,127,255`), clamping N to12.
There is no additional numeric count in this native display.

The port uses the original `ovrlster.d3d` stars, `ovrlvlag.d3d` blue translucent
flag and `overlay1.pcx` atlas through their converted assets. It reads the
collection total at the existing HUD capture boundary. The authored center
`[210,47]` is retained in landscape; portrait layouts move the group down by
110 authored pixels to clear the race times and touch controls.

`evidence/native/star-hud-fixtures.json` covers24 original creation cases,
42 count/color updates at both x87 precisions, and six mode-switch branches.
These are bounded original-instruction probes, not a live Windows renderer
comparison. Reproduce with `re-python tools/native-star-hud-fixtures.py`, then
`node --test tests/native-star-hud.test.mjs tests/star-hud-layout.test.mjs`.
The separate `tests/star-hud-browser.mjs` checks the source renderer with
controlled pickup contacts; it does not claim a full driven race.

## Outside-car audit and hit integration

`0x4107e0` executes after integration but excludes registered types3 and4 from
its relocation requests. Original opponent creation `0x417640` passes type3
to `0x415f90`, which registers that value through `0x4165f0`. The player is
type1 but is excluded by object identity. Consequently the shipped racing
roster is never relocated by this controller. `native-ai-range.js` reproduces
the complete selection and original `0x497b30` range wrap, including its
low-boundary count-minus-one expression.720 original executions agree,
including144 race-only registries with no relocation requests. The deeper
`0x4108f0` legacy traffic relocation is an explicit callback boundary, not a
replacement opponent rescue mechanism.

Accepted NPC hits reset priorities to `[1,0,2]` before effect initialization,
as `0x40d310` calls `0x40f380`. The one-second marker `0x40ddd0` sets its
absolute-seconds timestamp only while clear;120 native cases cover repeats
and finished opponents. Hit animation callbacks use a persistent event queue.
The NPC attacker's `0x40de60` cheer occurs only when its projectile hits the
player and its own state is not9. NPC-on-NPC contacts do not submit that cheer.
Finished NPCs still consume a colliding projectile and the shared hit-record
RNG draw, but do not enter a hit state or reset priorities.

The race timer audit confirms `0x42f980` starts player and opponent timers
together, with NPC timer IDs9+index. `0x417e30` reads and pauses the matching
timer. Their native upper limit is `0x0fffffff` milliseconds. AI item/effect
timestamps instead come from `0x48f4d0` absolute engine seconds; zero-start
active race time is not interchangeable with that clock's startup epoch.

Reproduction: `re-python tools/native-ai-range-fixtures.py` and
`re-python tools/native-ai-trigger-fixtures.py`, then the corresponding Node
tests and `tests/simulation-combat.test.mjs`.

## Verification and limits

The initial fixtures recorded an input allowance0.00003 and force allowance
max(0.002, abs(native)×0.000003). The follow-up audit established that many
differences were correctable instruction-order/storage differences, not a
necessary host boundary. Complete player force calls, force/Euler recurrence,
ground/wheel callbacks and their recurrence now require exact stored outputs
at the stated24-bit precision. Only the standalone slip transcendental return
retains the1e-15 allowance described above. Since the 2026-10-28 comparison the
1,600 keyboard input frames are also exact. Original graphics-driver precision
remains unverified.

`generate_native_gameplay_fixtures.py` maps the original PE into Unicorn and
executes `0x433870`, `0x414ff0`, `0x415160`, `0x415410`, `0x415450`, `0x415520`,
and the full active force function `0x415990`.
Only input-poll and delta functions are replaced by tiny stubs reading
caller-supplied values. Initial state is explicitly controlled. Result:

- **1600 input updates** compare against actual shipped instructions.
- **120 force cases**, including positive/negative/zero speed, steering,
  upgrades, braking and handbrake, compare against shipped instructions.
- **720 complete force calls** and **2400 recurring force/Euler frames** now
  require exact stored outputs; see `native-player-phase.test.mjs` and
  `native-player-recurrence.test.mjs`.
- **6552 player engine-sector-history cases** compare exact progress and
  ordered trigger callbacks; `native-player-sectors.test.mjs` also supplies
  a deliberately stale controller history to test the explicit engine input.
- **160 wheel contact callbacks** and **160 wheel pose callbacks** compare
  exactly against original instructions at24-bit precision. **320 recurring
  frames** additionally use actual shipped wheel geometry, variable deltas,
  forward/reverse motion, steps and airborne drops. Terrain height answers
  remain explicit boundary inputs, not an assertion of whole-world collision parity.
- **960 ground selections on all six original tracks** compare native sector,
  selected face, fallback behavior and height. Triangle-plane initialization is
  supplied separately; route-axis construction itself executes the original.
- All derived source-track side/forward axes and18 player starting headings now
  match exactly at the explicit24-bit fixture precision. The normalization
  reproduces original X²+Y²+Z² x87 rounding; no axis/heading tolerance remains.
- Identical input-update sequences at31,32,60,120,144,240 simulated rendering
  rates, fluctuating frame times and stalls.
- A connected12-second acceleration/braking/reverse trajectory is identical
  across those render rates and long stalls, with an explicitly collision-free
  adapter to isolate movement composition and timing.
- Twenty-second connected traces on **all six original tracks**, using original
  grid positions, kart bounds, physics and native rail collision, include contact,
  reverse steering and return to forward motion. Every update's position, yaw,
  local velocities, RPM and gear is identical across the six render rates and
  long stalls.
- **240 finish, 240 time-gate and 120 timeout cases** compare directly with native
  handler instructions. Timer, sound, log and UI calls are explicit boundaries.
  **1296 source-track sector crossings** compare trigger order and signed
  progress against native instructions, including wrap and skipped sectors.
- Explicit pause/resume and active race-clock checks.
- Pickup evidence includes420 collections,180 respawns,240 collision checks,
  120 cooldown checks,33 signed turbo boosts,6 mode constructors, and all 12
  native parameter records. An additional120 original owned-item updates verify
  yaw rotation and the original cosine-valued pitch assignment; the callback
  does not move or scale the item.
- Projectile evidence includes480 flight updates,180 launches,240 target
  selections,360 original graph-facing queries on all six tracks and120
  unsigned fire-clock checks. An additional120 original bubble-fan routines
  verify secondary-pool scanning, inherited velocities and reused pitch/roll.
- Effect evidence includes600 original spin/gum/bubble updates and120 shared
  initializations, including player/NPC wheel launch speeds. UI and sound
  boundaries are explicitly listed in the fixture generators.
- Ten-second driving/combat composition replays across all six tracks are
  identical at31,32,60,144,240 display frames per second. Inventory grants in
  this test are explicit replay inputs for exercising all weapons.
- 63 focused gameplay, item/trigger/finished-NPC/difficulty, outside-range and
  minimap Node tests pass together; the two additional bonus HUD tests also
  pass. Native timing, integration, collision and other NPC suites are
  additional tests owned by the native investigation.

An initial fixture attempt changed an immediate value in emulated code between
updates; Unicorn's translated-code cache retained the earlier value. It was
corrected to use an unchanging stub reading a mutable data word before any
fixture was accepted. This was a probe defect, not a game discrepancy.

**Not verified:** full original-game race parity, intended native runtime update
cadence, all collision aggregation/ordering, complete trigger/NPC states,
and a whole-race reverse/steering comparison against a working native renderer.
The connected deterministic drive/reverse replay verifies portability and
composition; it is not a substitute for that unavailable whole-race baseline.
The separate native AI, lifecycle, presentation and release reports track the
remaining aggregate coverage. This limitation concerns the unavailable native
whole-race baseline, and does not negate the instruction-level cases above.

## Results, scores and adventure progression

`source/simulation/native-results.js` reproduces the original completion writes
from `0x42c4c0`, including the exact `BEST TIMES` section name. Aborted races
write only `PLAYER.finished=0`; existing time/result fields are left untouched.
Completed races save player damage, total time, rank, collected stars and best
lap, then NPC rows and the track's best-time/checkpoint records. NPC result
identity is its CHARDATA AI identifier, copied by `0x417aa0` into the result
record; it is not the renderer's shared kart selection.

`0x417d00` records unfinished opponents' timers and estimates their finish time
from their live progress, using a signed integer quotient **before**
multiplying by the progress deficit.
Its duplicate-time adjustment only modifies opponent zero, and compares against
one record past the active roster. The helper requires this trailing time as an
explicit boundary value. It preserves divide-by-zero and signed-division
overflow as errors instead of inventing a replacement estimate.

The QuickRace debrief's original OK caption is **Opnieuw** and its result4
selects `PHASE_RETRY`; **Hoofdmenu** returns8 and selects `PHASE_MAIN`.
Both paths process a high score first. The five-row board is per country and
orders by **FASTEST_LAP**, not total race time. Ties remain ahead of an equal
new score. The saved row is `name,character,totalRaceMs,bestLapMs,difficulty`.
The invoked name dialog is **TfrmEditBox**, verified from VMT`0x4701c4` and its
classname pointer`0x470363`; the bundled TfrmEnterName is an older unused form
on this path. The active dialog is457×236 with20-character edit limit. Cancel
clears its text before returning. OK is disabled for empty text, although the
original Enter key handler still closes an empty edit.

The native Delphi time formatter uses colon-separated minutes, seconds and
rounded centiseconds. It does not carry centisecond overflow, and its seconds
branch is strictly greater than60: `999→0:00:100` and `60000→1:60:00` are
preserved native edge cases. The helper exposes24/53-bit arithmetic explicitly.
`tools/native-result-fixtures.py` executes360 full NPC finalizations,120
completion writers,500 score lookups,500 insertions and528 native time-component
evaluations. Filesystem writes, timer reads and string-reference assignment are
named boundaries; all six result tests pass.

`source/simulation/native-adventure.js` loads the original24 entries from
`shellimg.dat [ADVSEQUENCE]`. The six normal races are followed by six time
trials, six star races and six duels in the original country order. The
zero-based rank limits are4,2,0 for Easy, Normal and Hard. The type-specific
check additionally requires a completed time trial, **exactly12 stars**, or
first place in a duel. Normal/bonus types have no extra condition.

Successful results set the country/type cell in the original6×5 completion
matrix and advance the event. The final event resets the sequence index to0,
sets the profile's completed flag and requests the original campaign completion
presentation. The profile's current country/type remains the finished event
until Start on the next briefing. After qualification processing, the menu
checks all six cells for the current type and updates shared country locks:
normal→Spain, time→France, stars→England, duel→Italy. The shipped initial state
unlocks Netherlands/Germany. Locks are global shell settings, not fields in an
individual profile. The unlock check runs even after a failed qualification,
as in `0x472fe0`; a previously complete type can therefore repeat that dialog.

New profiles default to Normal difficulty and an empty completion matrix.
The reset routine deliberately preserves raceType until the event is applied.
Loading an absent difficulty field instead defaults to0, matching the INI
read. There are30 save slots, `players/player0.dat` through`player29.dat`.
Navigation does not wrap. The original first-occupied search reads a31st byte;
the helper makes that out-of-roster boundary explicit. The source supplies no
menu purchase/upgrade flow: the menu executable contains none of the keys
`motor`, `banden`, `versnellingsbak`, `physicsmodel` or `damage`, and the handoff
writer preserves these existing Race.INI fields. The shipped three upgrade
values are all1 and physics model is2. The game subsequently clears the six
upgrade globals in the player constructor `4319f0`; their active values are
zero before NPC and timer setup. The former assumption that the loaded ones
survived construction was incorrect; see `research-startup.md` and the
original execution evidence `../evidence/native/startup-upgrades.json`.
Menu opponent counts for modes0..3 are
4,3,3,1.

`tools/native-adventure-fixtures.py` executes the original full`0x472cfc` and
`0x472fe0` decision/store paths in960 cases, plus80 profile resets,80 completed-profile replay resets,45 sequence
transitions,480 slot lookups and128 original Delphi menu random draws. UI, sound, result-file reads and string
allocation are explicit boundaries. All seven adventure tests pass. These
fixtures establish the original menu rules independently of browser
persistence and UI integration.


## Connected adventure UI validation

The browser now uses these source-derived helpers for all24 adventure events,
with30 saved profiles and shared country locks. The new-name acceptance path
`0x4760c0` commits the default profile immediately, before character/difficulty
selection. Character OK `0x473cec` commits those choices; Back `0x473cdc`
returns to the main menu without deleting the profile. Only character-select
Stop in adventure mode uses prompt50 and `0x474048` to delete the provisional
profile before exit. Existing-profile OK opens the briefing directly. Starting
a completed profile calls `0x45a184`, clearing only its matrix, adventure index
and completed flag, and preserving identity and difficulty.

Character, country, profile and highscore carousels retain native nonwrapping
bounds and original disabled art. Progress icons use STATICONS CSV field0
when complete and field1 when incomplete, as selected by `0x475d6c/0x478c38`.
Briefing text preserves the original WELCOME/country prefix and CRLF inserted
for empty numbered lines; nonempty lines concatenate as in `0x478e80`.
Country portraits use DEBRIEFPICS field0 (`0x478958`).

Result processing occurs on either debrief OK or Back (`0x471bc0`), never
merely on display. Its order is qualification and any country-star movie,
progress message, country unlock, highscore, campaign-win movie, profile save.
Back then selects the main menu (`0x471b8c`). The browser persists best-time
results separately from this delayed profile progress; a highscore name also
becomes the profile name. `native-menu-random.js` reproduces Delphi's separate
unsigned random stream, seeded with UTC milliseconds of day at debrief
construction (`0x40293c`), for the original rank/outcome voice pairs.

STARMOVIES map Netherlands/Germany/England/France/Spain/Italy to
ster5/ster0/ster2/ster4/ster3/ster1.mpg. WINMOVIES map the four player characters
to rcwin/wkwin/brwin/mxwin.mpg. The browser plays the existing converted
original movies. The native key handlers are empty: neither reward movie is
skipped by Escape. A configured BMP alternative has the original9-second timer.

`tests/adventure-browser.mjs` passes in Chromium/SwiftShader with no page or
asset errors. It exercises name cancellation, immediate profile save, character
and difficulty commit, Back preservation, profile navigation/deletion/reload,
QuickRace lock art and its original requester, sixth-normal-race unlock and next
briefing, final-duel star movie, campaign movie, highscore/profile-name update,
and completed-profile replay. `evidence/adventure/report.json` and screenshots
record the run. Race completion in this UI test uses **controlled native finish
trigger fixtures**; this is deliberately not a claimed driven full-campaign run.
The separate QuickRace regression also passed after the adventure integration.

Timeout and abort remain original behavior: the gameplay exit writes only
PLAYER.finished=0, and menu `0x4718b4` skips the debrief entirely and returns to
the main menu. The false-finished time-trial qualification branch exists but is
not reached by ordinary timeout handoff; no complete timeout result is invented.

### Legacy split-checkpoint reachability

The separate `0x4425f0` checkpoint callback is registered at trigger45 in the
original `0x4ecd80` table. Neither trigger field in any of the six shipped PMP
routes contains45. Its helpers `0x4424f0/0x442570/0x4425a0` are called only by
that callback. The current-sector global `0x53be40` supplies its duplicate
guard, not total race progress. The active time-gate markers74–76 instead call
`0x441e70`; they update timer18 and play CHECKPOINT without writing the legacy
split-time arrays.

`0x440c30` copies the current checkpoint count to saved count `0x4ed1c0` after
every lap, including laps that do not beat the record, then clears the current
count. On the shipped routes that count stays zero. `0x42c3b0` also normalizes
the initial saved-count sentinel -1 to zero. Consequently the current result
writer's zero split count matches these tracks; an inactive speculative
checkpoint subsystem has not been connected to the time gates.

### Character victory movie gate

`0x471bc0` tests the application mode against3 (Adventure), runs progression
`0x472cfc`, country unlock `0x472fe0`, then highscore `0x471c70`. Only Adventure
with the current debrief's completion byte `form+0x33c == 1` calls `0x473158`
to show `TfrmAdventWin`. `0x472cfc` sets that byte only after qualification
and `0x458468` returning999, the end of the configured24-event sequence.
Winning a single race or completing the first six normal, timed, or item races
does not play the character victory movie. QuickRace never reaches this movie
branch, including a first-place finish.

The original constructor `0x470a7c` reads the selected profile's character byte
at+0x22 and indexes the key table for `0x470c4c` to read settings.ini WINMOVIES:
RedCat→rcwin.mpg, WhizzKitty→wkwin.mpg, Brutus→brwin.mpg, Max→mxwin.mpg.
The connected browser flow already uses these exact mappings. After the final
successful duel, the country-star movie occurs before progression/unlock;
highscore follows, then the character movie, and only then the profile save.

The native fixture generator now executes240 complete debrief gates across
all four characters and five application-mode values, with intermediate type
endpoints and successful/failed qualification. Only four cases play the
character movie: successful final-event Adventure for each character. Four
additional original constructor executions verify the actual key selection.
Tests compare the port's progression decision and mappings, check the
highscore→movie→save order, and verify all four converted movie assets exist.
The earlier browser test separately verifies Max's connected final-duel flow.

### Full and sparse profile banks

`tests/adventure-profile-bank-browser.mjs` additionally verifies the original
thirty-slot ceiling in the connected browser UI. A full bank opens the original
message52 without changing save contents. Deleting slot29 selects28, then
creating a profile reuses29 and survives Back/reload. A sparse bank at0/7/29
skips empty slots without wrapping; deleting7 selects29 and a new profile uses
the lowest free slot1. Deleting the sole profile selects-1 and disables
navigation, accept and delete while retaining New. The three browser groups
passed with zero page/asset errors; `evidence/adventure/profile-bank-report.json`
records the run. These checks do not run or inject a race.

### Character request order, queue semantics and raw animation clock

The player callback `0x4325b0` submits steering requests from its pre-input
lateral speed, then updates controls/forces, wheels and the hit effect. Its
nearest-opponent look request (`0x435d50`) precedes finish/brake/turbo/reverse
requests, and `0x44a6c0` advances the selected mesh before body integration.
The look test uses the nearest opponent within a strict 100-unit planar radius
and that opponent's yaw. It does not use the player's facing direction.

Conditional `0x44ce90` requests require matching state and an empty queue.
Unconditional `0x44f390` appends, then restarts the current queue head. After a
head completes, `0x44f110` resets the new head and `0x44cac0` displays its first
frame in the same callback. Pickup and hit requests after rendering therefore
execute synchronously; postponing them until the next actor update changes
queue admission and restart order. The pickup fixture captures the exact RNG
state at each animation callback, including random pickups and AI upgrades.

`0x44e460` initializes each sequence timestamp to zero, while `0x44e850` reads
raw GetTickCount, advances at most once and discards excess elapsed time.
`0x44eb90` preserves the timestamp on restart. The browser uses a documented
60,000-ms reference uptime plus elapsed wall time for these consumers, rather
than a race clock that freezes when paused. This is an explicit initial clock
epoch, not a measurement of a Windows launch.

The separate `0x53be64` branch in `0x4325b0` is named
`legacyAutopilotActive`: it calls the old route controller `0x404f00`.
It is not the rescue crane state. The supplied binary has no direct writer to
this zero-initialized global; ordinary rescue does not enable that branch.
Likewise NPC steering callbacks `0x40c0c0/0x40c370` are reached through
`0x40bbf0` in FSM state23, but the active transition table and direct mode
writes do not enter23. Normal NPCs retain their original idle/turbo/cheer/hit
requests. The six player STEER sequences are not synthesized for country
opponents, whose authored character sets do not contain them.

`tools/native-player-animation-fixtures.py` records920 original instruction
cases:480 complete player request paths,400 nearest-look cases,10 immediate
event cases and30 queue-pop/reset cases. The collection fixture additionally
checks140 original synchronous animation/RNG traces.
`tests/animation-browser.mjs` then exercised all four player characters with
real Arrow-key input through520 DrivingView ticks each, both lean directions
and reverse. It recorded zero displayed-geometry mismatches and checked20
immediate pickup/hit events. Results are in
`evidence/animations/browser.json`. These are connected port checks and bounded
native instruction comparisons, not a Windows whole-race capture.

### Kart and driver ground diffuse

Engine-body constructor `0x48fef0` initializes persistent diffuse to
`0xffffffff`. Flag2 is enabled for every racer. Draw callback `0x490d40`
calls `0x4903c0` before parent and child drawing: this samples the existing
body sector with `0x495fe0`, then `0x496360` returns the selected triangle's
third-vertex diffuse, without interpolating vertex colors. No ground triangle
returns white. The port retains this color alongside each extracted triangle.

Each RGB component approaches that ground color by
`dt * (abs(forwardSpeed) * float32(0.1) + 1)`. The original float stores,
integer truncation and blue-channel unspilled intermediate are preserved.
The smoothed packed value remains on the body; the draw value additionally
receives country RGB offsets and an upper clamp of255. `0x42bbf0` reads
track.ini MAPS comma fields11–13 as signed shorts; `0x42d7d0/0x493b10` install
them. Netherlands uses `[0,0,0]`; the other five tracks use `[128,128,128]`.
These are additive draw offsets, not a replacement for ground shading.

`native-kart-color.js` exposes the ground sample, original country offsets and
complete color update. `tools/native-kart-color-fixtures.py` executes600
original `0x4903c0/0x4902d0` cases at both24-bit and53-bit precision, including
the actual parent/child vertex writes. Ordinary children receive the color;
child render modes1 and2 are excluded. All cases match exactly. Coloring
belongs to the draw callback; it must not run an extra time per physics
substep or feed the brightened render value into the next persistent update.

### Control-only validation driver

`tools/validate-driven-races.mjs` supplies ordinary analog throttle, brake and
steering to `RaceSimulation`. Its helper is test automation, separate from the
ported opponent AI. It reads the authored DMP graph, CMP rails and current
registered scenery/opponent bounds; its optional star planner chooses approach and
departure waypoints. It never writes kart poses, velocities, pickup state,
sector triggers, race timers or physics tables.

The headless runner records construction/gameplay seeds, control-stream hashes,
source hashes, race results and optional detailed driver traces. Reports with
changed guarded source hashes are marked `source-changed`. The optional
`RCSK_SOURCE_SCOPE=execution` guard follows every transitive local import of
the headless runner, while still recording hashes and changes for all`src`
files. This lets concurrent menu/HUD-only work remain explicitly recorded
without implying a change to the tested simulation. Files named
`driver-*-diagnostic.json` are route-planning diagnostics, including failed
approaches; they are not the final cross-track validation matrix. Earlier
driving results predate restored scenery contacts and shared-RNG controllers
and cannot establish coverage of the later source checkpoint.

Focused test-driver checks reproduce the England approach blocked by original
solid dummy placement120, verify a planned detour against the native directed
rectangle sweep, exercise the narrower Netherlands star-pocket route, and
prevent a recovery loop that immediately repeated reverse input forever.
These checks validate the automation only; they are not additional claims
about original opponent behaviour.

The later arithmetic/sector audit retains its failed diagnostic reports:
`ground-audit-driven-normal.json` stopped at the duration limit on Germany
(track1) and France(track3), while all18 endurance cases remained finite.
That run also detected an unrelated menu-source change. Subsequent live
contact capture (`force-audit-live-contact.json`) identified player/NPC
overlap, not a new terrain contact, in the repeated France stall. The test
follower previously avoided scenery only; its independent planner now reads
live opponents too and checks its next segment every250ms. No game body or
collision rule is changed by these queries. The short opponent-aware
diagnostics clear both former traps; the final follow-up reports separately
record whether all six complete on the corrected production source.

The follow-up result is **not an all-course completion pass**.
`followup-endurance.json` records18/18 finite five-minute opponent runs across
all six tracks and three difficulties. `followup-driven-normal.json` records
five-lap completion for Netherlands633275ms, England674475ms and Spain506850ms.
At the900000ms automation bound, Germany had2 laps, France1 and Italy2.
Both reports have zero changed execution dependencies. Concurrent changes
to five view/HUD/tab-order source files are listed in the reports; they are
outside the executed headless import graph.

Germany's final detour circles without advancing; France repeatedly reaches
a player/NPC contact; Italy also fails to progress with this follower.
One bounded held-bonus diagnostic per Germany/France did not finish either;
France exercised32 firing and28 hit events. Temporary speed/waypoint and
bonus-use experiments were not applied to the retained driver. The earlier
successful star/normal matrices remain historical checkpoints, not evidence
for these later arithmetic/sector corrections.

`native-live-contact-fixtures.json` executes original `0x499c30/0x492470`
at the captured France world-space pose, with its observed opponent bounds
and eight signed-velocity variants at both24-bit and53-bit precision.
All16 sweep/contact/order/slide outputs agree exactly. Candidate discovery
is supplied by the capture and vertical speed is an explicit zero boundary.
This establishes that the blocking sweep at that pose is not a discrepancy
in the portable sweep itself. It does **not** prove that the original full
game reaches the same overlap, that all prior integration is equivalent,
or that these prolonged traps are original game behavior. The failed
automated completions remain a concrete validation limitation.

The diagnostic sequence reached five laps, all 12 stars and successful original
qualification on every easy course. Netherlands' final diagnostic is
`driver-directed-avoidance-nl-diagnostic.json`; England is in
`driver-avoidance-nl-england-diagnostic.json`, and the other four courses are in
`driver-avoidance-other-diagnostic.json`. These successful runs reported no
source changes within their individual run windows, but the Netherlands route
selection correction occurred after the other five courses' runs. A final
all-six matrix therefore repeated them on one frozen source checkpoint.

`evidence/gameplay/final-driven-stars.json` records that final run on
2026-10-20,15:26:39–15:32:17UTC. All six easy star races finished five laps,
collected12 stars and passed `nativeAdventureQualification`; the report status
is `all-finished`, with no changed source hashes and no nonfinite actor errors.
Track0–5 race durations were811850,667200,693875,715375,607475 and649050ms.
The report preserves the input hashes, source fingerprints, seeds and sampled
race state; `final-driven-stars.log` contains the per-course completion log.
This establishes control-only completion in the composed port at that source
checkpoint, not original Windows whole-process equivalence.

### Full mode/difficulty matrix and return-placement audit

The subsequent all-mode request uses `evidence/full-race-matrix/`. Normal
mode's source inventory is `normal-source-coverage.json`: `0x4319f0` selects
both the original `Phys<difficulty>.dat` and `cars<difficulty>.dat`; the duel
table multipliers at `0x4350d0` do not apply to mode 0. Original normal-race
qualification accepts zero-based rank 4, 2, 0 at easy, normal and hard
difficulty respectively. A five-lap finish therefore does not necessarily
qualify. All normal tests retain four original opponents and the original
difficulty-dependent slowdown/catch-up behavior.

The first three normal baseline reports preserve 16 completed races and two
duration-limit failures. Medium Germany and Italy remained at zero laps
despite ordinary forward/reverse input. The Germany 100-second diagnostic
reproduced all ten retained ten-second samples exactly, then recorded both
straight directions as blocked by NPC0. Its approach trace shows the player
had already completed rescue before NPC0 returned into the player's shape.
`normal-germany-medium-contact.json` contains the live poses, full opponent
headings and the 73–80-second approach; the long failed run remains in
`normal-d1-baseline.json`.

`tools/native-blockage-germany-rescue.py` executes the original
`0x48c170` clearance and `0x4999c0/0x49a480` rectangle functions at that
captured return. The player's squared center distance is 2054.483457699418,
so the original 2000 threshold permits the return. Both directed original
rectangle tests nevertheless report overlap at 24-bit and 53-bit precision.
`normal-germany-native-rescue-overlap.json` preserves this evidence. This is
an original clearance limitation, not evidence of a portable sweep error.

The user-authorized safety extension now also holds an NPC's original return
while its full rectangle overlaps the player, and checks again before NPC
growth retires. It does not choose an alternative NPC destination or change
NPC-to-NPC clearance. Germany's retained retry completes five laps in 627025 ms
with nine such deferrals. Italy's retry completes in 487625 ms with one deferral
and no player rescue; its failed baseline's NPC0 position was exactly the
authored return waypoint 514. These are
`normal-germany-medium-guard-retry.json` and
`normal-italy-medium-guard-retry.json`, both with unchanged source/asset guards.

The automation also now selects the clearer straight forward/reverse sweep
when stuck, requests straight steering for the first 1250 ms of its existing
2500 ms escape, then resumes turning. This controller-only correction is
supported by the Netherlands star contact and its complete replay:
`stars-nederland-easy-straight-escape-attempt3.json` reaches five laps and all 12
stars without rescue. The helper has an optional no-detour policy which keeps
the initial original-rail-prechecked DMP links. Neither policy changes game
bodies or collision rules.

The corrected mirrored-course runtime uses the original MAPS mirror flag
independently of British road-side selection. The controller continues
planning in original world coordinates and reflects its ordinary joystick
command at the native integer-axis boundary. Quantizing before reflection
preserves steering at asymmetric `Math.round` half steps. Nine focused driver
tests include the recorded collision escape, mirror-axis composition and
preservation of rail-prechecked links with detours disabled.


## Normal-race completion matrix before the nonfinite-velocity safeguard

`evidence/full-race-matrix/normal-final-coverage.json` selects actual five-lap
completions for all 18 normal-mode course/difficulty combinations. Every
selected report has unchanged source and asset guards, and all share the same
production-source fingerprints. Eight finishes qualify under the original
rank rule; the other ten still finish all five laps. These runs retain original
character 0, four opponents, startup seeds 0/0 and ordinary analog controls.
The report is composed-runtime evidence, not a Windows full-trajectory parity
claim.

The medium and hard batches finish all twelve races directly. The easy batch
finishes four courses, while Germany and France repeatedly fall from the
bridge after rescue. Their complete failures remain in `normal-d0-final.json`.
The rescue ledger rules out an indefinite return wait: each wait lasts at most
two seconds, followed by successful fallback. The test driver retains an old
detour and reverse maneuver after relocation, limits itself to speed 8, then
falls again. `normal-germany-easy-bridge-loop.json` reproduces the first 250
seconds and exactly matches all 25 retained samples, including the repeated
return to waypoint 400. No additional production rescue change was made.

The private `tools/normal-rescue-aware-runner.mjs` clears only its test driver's
old route targets and reverse maneuver when it observes a rescue relocation.
It never requests a relocation or writes a kart, timer, trigger or item. At the
same speed-30 policy it completes Germany in 613075 ms and France in 590400 ms,
with five observed rescue resets each. Both qualify. The complete guarded
report is `normal-bridge-driver-reset-retry.json`. Independent ordinary
speed-70 retries also finish Germany in 569000 ms and France in 563725 ms.
The shared test helper and production runtime remained frozen throughout.

## Original catch-up overflow and bounded safety exception

The valid-control England hard time-trial capture
`evidence/full-race-matrix/timed-england-nonfinite-deep.json` records NPC0's
vertical speed growing to `3.3529011546832445e38`, then becoming positive
infinity at 59650 ms. The player input remains finite, including steering
`-0.26` on the failing frame. Deep-copied positions and matrices distinguish
this accumulated velocity from a controller-generated invalid input.

Executing the original instructions in
`evidence/native/ai-vertical-overflow.json` reproduces all 119 preceding
24-bit transitions and the next overflow. `0x406100` scales all three linear
velocities by the catch-up factor but caps only forward speed. The registered
NPC path in `0x401200` skips the `0x413330` vertical spring, while `0x416650`
grounds the body without clearing its vertical velocity. These are bounded
instruction and composition proofs, not a full original-process replay.

The user-authorized port safeguard is explicitly outside those unchanged
native routines. `npc-velocity-safety.js` snapshots the three NPC linear
velocities before preparation and, immediately afterward, resets only a
finite-to-nonfinite component to zero before integration. Every finite value,
including the large captured predecessors, is retained. It does not alter
route, AI state, rank, laps, timers, position, or angular velocity. A cumulative
counter and `npc-velocity-safety` event expose each intervention.

The four focused safety tests preserve all 119 finite updates and exercise
the captured overflow through the composed preparation/integration boundary.
The original offending ordinary-control policy is replayed in
`timed-england-overflow-repaired.json`: it passes 59650 ms with exactly one
intervention and remains finite until the normal 67000 ms timeout. It does
not complete that race. Source and asset guards remain unchanged. The earlier
18 normal finishes above are preserved as historical evidence. The fresh
`normal-finite-refresh-coverage.json` now selects all 18 five-lap finishes on
the safeguard's 106 production-source fingerprints. All four report guards
remain unchanged. Every selected input hash and finish duration is identical
to its earlier successful policy; none of these races needs the velocity
intervention. Eight finishes qualify and ten do not. These are active-grid
runs, with the opening/countdown tested separately.

## Constructor upgrade reset and refreshed normal races

The preceding matrices are historical after the startup-order correction.
The INI loader `0x42b870` reads the six upgrade flags, but player construction
`0x4319f0` subsequently clears all six at `0x431ecd..0x431eeb`, before NPC
construction and race timer initialization. The earlier options adapter
covered only the loader and incorrectly retained its values. The corrected
runtime preserves the loaded settings separately and uses the initialized
zero values for player handling, shared NPC tire settings and timer setup.
This is an original-behavior correction, not a race-difficulty adjustment.

The normal-race refresh retains the exact earlier controller policies:
character 0, seeds 0/0, speed 30, five original laps, four opponents, 25 ms
cadence, with only the private rescue-aware controller for easy Germany and
France. Reports `normal-d0-constructor-refresh.json`,
`normal-bridge-constructor-refresh.json`, `normal-d1-constructor-refresh.json`
and `normal-d2-constructor-refresh.json` retain their complete source and
asset guards. Completion and original rank qualification are reported
separately; these runs start at the active grid and do not establish original
Windows whole-trajectory parity.

`normal-constructor-refresh-coverage.json` verifies all 18 refreshed runs
finished five laps and emitted the ordinary finish event. Nine qualify and
nine do not. All 106 production-source fingerprints and 15 loaded asset
digests agree across the four reports and with the files at consolidation;
every run retains empty source/asset change guards. No nonfinite-velocity
safeguard intervention occurred. The earlier controller policies needed no
changes after the native constructor correction. Previous reports remain
available with their original source hashes.

## England timed controller diagnostics after the constructor correction

The remaining England timed attempts retain ordinary analog inputs and the
original 25 ms cadence. They do not justify a physics or deadline change.
`timed-england-windmill-contact58.json` records the decisive contact near
sector 71: at 10675 ms the player strikes solid OMP placement 120,
`cdummy_ANIM`, at `[-4795.10107421875, 5, 3292.797119140625]`, producing an
impulse of `38492.84375`. This is a Stonehenge entrance collider. The similarly
located windmill in the Netherlands must not be used to infer England's
object behavior. The contact observer forwards the original callback, so
crash selection and shared RNG ordering remain active.

A private controller in `tools/timed-england-closed-loop.mjs` forecasts
1.2 seconds on copied body scalars, recomputes its road target at each
forecast step, and scores forward progress, path drift and actual collider
queries. It submits only the first ordinary steering/throttle/brake input;
its forecasts are an aid to the test driver, not an alternate game integrator.
Its first medium attempt, `timed-england-closed-loop1.json`, passes the first
two checkpoints at 12950 and 25025 ms of active race time with no reverse
recovery, then stalls at the barrel/crate entrance around sector 176. It
expires normally at 47000 ms and is retained as an incomplete attempt.

The separate immutable offset controller adds left/right approach candidates
while preserving the same runtime. Its focused test checks bounded ordinary
inputs, deterministic selection, and absence of writes to real racer state,
shared RNG, collision state, or race progress. A successful full-race report,
not the forecast or unit check alone, is required for matrix acceptance.

`timed-england-hard-closed-loop-held1.json` subsequently completes all five
laps and all 15 time checkpoints in 182525 ms of active race time (190350 ms
including the original opening). The ordinary finish event occurs once;
source and asset guards are empty. It has no reverse recovery. The private
forecast policy is selected every 100 ms, while feedback inputs and actual
simulation still run every 25 ms. This is a controller computation choice,
not a faster simulation cadence. The result is rank 1: the full-race
completion passes, but original hard-mode qualification is false because it
requires rank 0. That distinction is retained in the report.

`timed-england-medium-closed-loop-verified.json` completes five laps and all
15 checkpoints in 206325 ms of active race time, rank 2, qualifying under
the original medium rule. The standard report selects the completed case
from `timed-england-medium-prefix-snapshot.json` and retains that immutable
source report's digest. The original batch was interrupted only after this
case was verified, while its redundant hard case was running; the stop is
recorded in `timed-england-offset-batch-stop.json`. No result is claimed for
that interrupted hard case.

## France hard timed: remaining controller losses

The private later-corner investigation retains the original opening,
character 1, seed 6, projected authored DMP line and 25 ms cadence. In the
baseline `timed-france-hard-reset-best-travel.json`, the large rail impacts
at sectors 137, 170 and 172 cost time despite correct game contacts.
`timed-france-predictive-continuous.json` uses copied scalar forecasts only
while the player is in sectors 129–176. The actual game still receives
ordinary controls and resolves all contacts normally. It removes the rail
impacts in that range and completes two laps (38300 and 37425 ms), passing
six checkpoints before the original timer expires at 87500 ms. It is an
incomplete race, not a matrix completion.

The isolated sector-26 forecast removes the earlier large rail impact and
reaches checkpoint 1 350 ms sooner, but that changes arrival at the moving
train and misses checkpoint 2. Continuing the forecast across the lap seam
removes repeated impacts at 183, 8 and 25–26, but reaches NPC traffic at
136–152 and fails later. These attempts are preserved in
`timed-france-predictive-26.json`, `timed-france-predictive-lap-seam.json`
and `timed-france-predictive-full-later.json`.

`timed-france-predictive-traffic-full-later.json` tests a separate private
forecast that extrapolates copied obstacle positions from current velocity
and yaw rate. Its two focused tests verify copied-pose movement, deterministic
bounded inputs and absence of changes to live bodies, shared RNG, contacts or
race state. Constant-velocity prediction of turning NPCs nevertheless
regresses this race. It is retained as a failed controller experiment;
neither it nor the other forecast variants changes production physics,
AI, geometry, collision rules or time limits. All these completed diagnostic
reports retain empty source and asset change guards.

The follow-up `timed-france-predictive-route-traffic-seam.json` projects only
copied opponents onto authored forward DMP links, retains their lateral and
heading offsets, and follows the bends at current speed. Train and other
scenery positions retain the previous forecast model. The route-aware
forecast is used only in sectors 129–176; other forecast sections are
unchanged. Two additional tests cover corner geometry, circuit wrap,
deterministic bounded inputs, unchanged scenery and absence of writes to
live NPC state/RNG. An independent agent review also found no mutation.
This remains a test-driver approximation and still fails the full race:
one lap, five checkpoints, normal expiry at 76000 ms. At the second-lap
sector-129 approach all of its standard passing candidates already predict
contact; subsequent NPC encounters remain the limiting condition. This
attempt supplies no justification for weakening original collisions or
timers.

The final bounded passing-target test,
`timed-france-predictive-passing-seam.json`, widens the private targets to
±100/±140 only when every standard candidate explicitly predicts contact or
fallback terrain. The wider targets retain the same rail, obstacle and
ground checks. An additional focused test verifies this gate and that a
worse candidate cannot replace the existing choice. The replay selects
wider targets for 48 of the dense recorded corner ticks and reduces the
late traffic contacts to one impulse of 5890.934 at sector 137, but it still
expires at 76000 ms with one lap and five checkpoints. The six fixed
startup-seed checks (2, 3, 4, 5, 7 and 8) of the unchanged static lap-seam
policy likewise do not finish. Their individual `...lap-seam-seedN.json`
reports preserve empty source/asset guards. These are retained failures;
the best France-hard timed attempt still has two completed laps, not five.

The exact-rail forecast variant delegates to private copies of
`NativePlayerMotion.prepare/integrate`, including integer analog controls,
wheel updates, eight collision/Euler/matrix/rail-response substeps, sector
selection and wheel-ground handling. It owns body arrays, wheel state,
ground clock and collider candidates; dynamic contacts abort before
resolution and contact callbacks are suppressed. Two focused tests cover
160 real-track rail-contact recurrences with exact isolated-player snapshots
and ground state, source nonmutation, and safe dynamic-contact abort.
`timed-france-predictive-native-rail-seam.json` nevertheless times out at
76000 ms with one lap and five checkpoints. It records 24 dense forecast
ticks whose selected trajectories contain original rail responses. This is
an improved isolated-player forecast, not exact future whole-race prediction.

`timed-france-predictive-ground-native-rail-seam.json` then uses the exact
44-node ground-chord route from `timed-france-hard-reset-ground0.json`, with
an equality assertion and hashes of that report and the independent geometry
audit. The route is 73.256 metres shorter than the projected-line baseline.
The unchanged controller before the forecast window still cuts bends and
hits rails/train traffic; it reaches two checkpoints and expires at 40000 ms
before completing a lap. Both reports retain empty source and asset guards.
No production handling, collision geometry, NPC behavior or deadline was
changed for either experiment.

The full-ground follow-up,
`timed-france-predictive-ground-native-rail-full.json`, applies the private
rail forecast from the observed green across the entire retained route.
It reaches the first checkpoint at 13750 ms (1025 ms earlier than the
projected baseline), but forecast braking around sectors 89 and 96, actual
the moving train at 89 and a rail contact at 99 consume that gain. The original timer
expires at 29000 ms in sector 109 with no completed lap. Source and asset
guards remain empty. The digest-bound companion
`timed-france-predictive-ground-native-rail-full-scope.json` explicitly records
that the copied player forecast does not advance global jump/sector
triggers, moving scenery, opponent AI or future shared-clock interactions.
The actual race executes all of those systems unchanged.

`timed-france-predictive-hybrid-contacts.json` tests one independently reviewed
combination: retained ground-route edges 0–57 and 171–187 join the retained
projected route at original nodes 253, 732 and 0. Two tests verify that every
edge comes from those sources, the joins do not invent geometry, and the
middle projected controller returns identical inputs over 53 sectors without
writing the source body. Copied native contact forecasts run in 0–57 and
111–186; the original jump at 103–104 stays outside that forecast window.
The copied-contact helper permits original rail and kart responses on private
bodies, while callbacks and live-body mutation remain excluded. Its future
NPC/train positions and global triggers are still approximate or unmodeled.

This hybrid reaches checkpoint 1 at 13775 ms, but the middle controller
loses time against rails at 67–84 and the moving train at 87–89. The second
lap also encounters NPC contacts near the bridge exit at 106. It completes
one lap (39150 ms) and five checkpoints (13775, 27550, 38950, 50725, 64450 ms)
before the unchanged timer expires at 76000 ms, sector 162. All source and
asset guards are empty. This remains a retained incomplete controller
experiment; it does not establish a production defect or satisfy the missing
five-lap France-hard timed matrix cell.
