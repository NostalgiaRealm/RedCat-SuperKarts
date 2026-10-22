# Six tracks, three difficulties, four modes

The current audit runs ordinary analog controls through the complete composed
simulation. Its target is 72 five-lap races: six countries × three difficulties
× normal, timed, star and duel modes. It uses the original opponent counts
(4/3/3/1), original track files, player physics, opponent tables, timing and
qualification rules. No driving run writes positions, velocities, laps,
pickups, timers or physics tables.

`evidence/full-race-matrix/race-matrix.json` is the generated coverage report.
It accepts only finished five-lap runs whose complete runtime, test sources and
loaded assets still match their recorded hashes. Star cases additionally need
twelve distinct collected stars. Timed cases must finish before expiry and
retain every original checkpoint award. It reports Adventure qualification
separately: an ordinary or star race can finish while the player's place is
insufficient to advance, and a finished duel can be lost.

Each accepted run records its actual original character, construction/gameplay
seeds and control policy. The test driver is automation, not original opponent
AI. Different ordinary driving policies are permitted, and unsuccessful
policies remain in the evidence directory. This is neither an all-character/
all-seed claim nor an uninterrupted Adventure campaign.

Accepted races use the browser's 25 ms simulation interval. The original
`4432a0` loop waits at least 25 ms before calling `42f4c0`, which updates both
the timer and physics. Faster standalone experiments are excluded even if
they finish. Original-instruction evidence confirms that truncated substep
velocity rotations make the original physics cadence-sensitive; the 120 Hz
France finishes do not establish completion in the browser. See
`research-frame-cadence.md`. Display refresh remains independent.

## Original files and native checks

- `original-asset-validation.json` refreshes the complete archive, geometry,
  six-track, image, sound and movie comparison against the supplied original
  installation and CD. It checks all road, route, placement, collision,
  driving-node and camera-path data for each course.
- `original-table-comparison.json` directly compares all three player and
  opponent difficulty tables with their installed original files.
- `timed-native-audit.json` checks every track/difficulty time-gate row,
  initial deadline and gate inventory. Existing original-instruction fixtures
  cover timer setup, expiry, crossings and qualification.
- `native-mirror-setup-rea.json` retains a fresh REA/Ghidra inspection of the
  original race setup function. `native-track-mirror.json` executes its
  original projection/track-flag/culling instructions with only D3D calls
  captured at an explicit external boundary.
- `normal-germany-native-rescue-overlap.json` executes original rescue
  clearance and rectangle overlap instructions at the captured failure.
- `../native/ai-vertical-overflow.json` reproduces the newly captured hard
  opponent overflow using original catch-up, normal-state and ground code.
- `../native/startup-upgrades.json` executes the original configuration load
  and constructor reset for all 64 switch combinations and both Phys loading
  exits, followed by 72 timer comparisons. `upgrade-writer-audit.json`
  independently checks subsequent stores and the disabled debug pathway.

WineD3D cannot render the original races reliably on this host. These checks
therefore distinguish original data and bounded instruction execution from
full races in the port. They do not establish an original Windows whole-race
trajectory, framebuffer or audible comparison.

## Restored original mirrored courses

Original MAPS field14 is set for England, France and Italy. Race setup
`42d7d0` negates the projection's horizontal terms and selects clockwise
culling; `430020` restores ordinary projection/culling for the HUD. Original
digital `433870` and analog `4341d0` input handlers reverse steering on the
same flag. The port had implemented these isolated input functions but had
not supplied the flag or reflected the race presentation.

Race composition now passes the authored flag to player motion. The renderer
reflects the world group and camera pose, letting Three use the resulting
mesh determinant for face winding. The camera stays a sibling of the world
group: reflecting their shared scene would reflect it twice. Camera-relative
weather and finish-flag geometry receive the corresponding local reflection.
HUD scenes stay ordinary. Road geometry, lane selection, physics and audio
coordinates do not change.

The tests check arbitrary rolled/interpolated cameras, camera parenting and
camera-relative objects, digital/analog input and identical physical
trajectories under correspondingly reflected ordinary joystick commands.
Four browser cases compare actual original-asset frames and real ArrowLeft
input. Retained failures include the missing flag and the initially incorrect
shared-scene reflection. Repeated translucent HUD draws can differ by one
channel value; after an unchanged-orientation control draw, changing the world
mirror leaves the HUD byte-identical.

## Restored original player initialization

The hard timed failures prompted a complete setup-order audit. Although
`42b870` loads motor, tyre and gearbox switches as one from the original
Race.INI, the later player constructor `4319f0` clears all six upgrade globals.
Opponents and race timers are initialized after that reset. The only later
direct writer is a debug tuning interface gated by `HELPDESK.tweak_mode`,
which is zero in the active original Game.INI.

The port had correctly implemented the isolated loader, force calculations
and both table banks, but incorrectly retained the loaded switches throughout
a race. It now preserves them separately as `loadedUpgrades`, then applies the
original reset before player physics, shared opponent steering and timer setup.
The effective motor, tyre and gearbox indices begin at zero. This changes
acceleration, grip, gearing and the timer8 opponent estimate; every time-trial
timer18 deadline remains unchanged. It restores original behavior.

`research-startup-upgrades.md` records the original callsites, stores and
validation boundaries. All 72 cases require fresh runs after this correction.
The earlier 69 completed cases and verification checkpoint remain under
`pre-upgrade-reset/`; they are not current completion claims.

## Necessary exception: returning opponents must not overlap the player

The previous safeguard protected the player's own return. The new Germany
medium trace reveals the converse: after the player finishes rescue and
drives away, NPC0 returns to waypoint425 inside the player's rectangle.
Original `48c170` accepts the center separation (2054.483 squared units,
above its 2000 threshold), while original `49a480` reports rectangle overlap
in both directions at both tested precisions.

Both karts then remain at fixed XZ/yaw despite changing velocities and
hundreds of ordinary recovery attempts. The baseline reaches its
1,800,000 ms bound without completing a lap. Italy medium shows the same
failure pattern at opponent return514.

Under the user's explicit permission to prevent an unfinishable race, an NPC
now waits if its returned rectangle would intersect the player. It retains
the original destination and original shrink/grow sequence, and returns when
the player clears that position. The check also runs before the NPC's growth
retires. It does not change NPC/NPC clearance, move the player or another
blocker, award progress, alter a timer or weaken opponent driving.

Controlled captured-state regressions verify waiting, subsequent native
placement, unchanged NPC/NPC behavior and a player arriving during growth.
The first corrected full replays complete Germany medium in627025ms
(nine prevented placements) and Italy medium in487625ms (one), with ordinary
controls and unchanged source/assets during each run. Their presentation
checkpoint preceded the final mirror-parenting correction; the final matrix
requires the later complete runtime hashes as well.

## Necessary exception: original opponent velocity overflow

A later England hard timed attempt found a separate original defect under
finite ordinary player inputs. Hard catch-up multiplies all three opponent
velocity fields by 1.08, but caps only forward speed. Registered opponents
skip the vertical spring, and their wheel-based ground update does not reset
the accumulated body vertical speed. Original instruction execution matches
all 119 captured finite transitions and then stores positive infinity at
59,650 ms. This is documented in `research-npc-vertical-overflow.md`.

The composition now snapshots an opponent's linear velocity before its
original preparation. Immediately afterwards, it resets only a component
that changed from finite to nonfinite. Finite values, original arithmetic,
AI state, position, route and race progress are preserved. The exception is
counted and emitted as an `npc-velocity-safety` event. It does not silently
repair already-invalid inputs.

The actual failing ordinary-input run now passes that point with exactly
one intervention and remains finite until the original time limit at
67,000 ms. It is still a failed timed-race completion, which is retained as
such. The successful matrix races are refreshed against the new runtime;
the prior runtime, tests and browser evidence are retained under
`evidence/full-race-matrix/pre-overflow/`. The 67-second repaired trajectory
also predates the later constructor reset. Its captured overflow boundary
still passes a composed regression on the current runtime; its historical
whole-race trajectory is not presented as a current replay.

## Automation corrections

The route follower previously tried turning while reversing out of a blocked
corner. In Nederland's star race, a straight reverse was clear; in France,
straight forward was clear while reverse hit an NPC. The test driver now
queries both straight directions and gives the clearer direction1250ms with
zero steering inside its existing2500ms recovery. This changes only input.
A retained Nederland replay improves from one lap/nine stars and366 repeated
reversals to five laps/twelve stars and three reversals.

Mirrored test commands reflect the already-quantized native joystick axis,
which preserves two-percent steering steps even at half-step rounding
boundaries. Optional obstacle-detour planning can be disabled for fast timed
driving; physical scenery, rails and kart collisions remain active.

Two later bridge loops were also automation faults. After the game relocated
the player, the follower retained its old detour goal and reverse command,
then drove off the bridge again. The rescue ledger showed successful safe
returns every few seconds, rather than an exhausted return search. A private
controller clears only its own stale plan after observing a relocation;
Germany and France then finish at the original 30-unit controller speed.
The production rescue search was not widened.

Nederland's medium star run initially completed five laps with eleven stars.
The missed star lies beyond a fork and scenery obstruction. Starting the
test driver's existing visibility planner earlier routes around that
obstruction and collects all twelve on the same seed. A separate ordinary
seed-one run also completes the objective. Both policies, original failure
and source hashes are retained; pickup positions and collection rules stay
unchanged.

Timed driving uses the original character physics and startup seeds recorded
in each report. Some difficult courses need a faster original character and
course-specific steering, authored lane choices or waypoint goals. These are
instructions to the private test driver. They neither change player physics
nor grant missing time, pickups or progress. The timer audit checks the
original awards and exact clock balance, including legitimate repeated gate
crossings after detours.

Later private controllers compare short hypothetical futures on copied scalar
state, using original force/integration functions and read-only collision
queries. They may choose a different steering goal, braking input or legal
original road branch. These forecasts are test-driver approximations: they
do not replace the live race, move any actor, advance its clock, or write back
predicted poses or velocities. The real simulation still processes every
collision, hazard, checkpoint and opponent on every25ms update.

France's remaining hard timed check also uses a complete private
`RaceSimulation` forecast. Each candidate has separate mutable actors,
services, random state and clocks; it retains the native crash callback and
advances moving opponents, the train, jumps and rescue together. Seven
snapshot tests compare independent replay through three natural contact,
train and jump windows and a constructed rescue/squash window. Three
controller tests check cached route calculations, steering mirroring once,
repeatability and unchanged live state. This establishes bounded JavaScript
forecast recurrence, not native Windows whole-race equivalence. The snapshot
contract and hashes are recorded in
`../evidence/private-forecast/race-snapshot-validation.json`.

The first whole-race forecast trial, `timed-france-whole-race-hybrid.json`,
expires after one lap while leading. Its one-second policy selection interval
is separate from the unchanged25ms controls and simulation. Failed private
drivers do not demonstrate that the original hard deadline is impossible.
The final focused comparison, `timed-france-whole-race-projected-seam.json`,
retains the earlier projected route and baseline input outside sectors129–186
and0–31 after25 seconds. Two additional tests check that composition. Its
complete private-race forecasts select inputs every100ms while actual
controls and simulation still advance every25ms. It completes three laps
(38200,37400 and36450ms) and nine checkpoints, then expires at123500ms
in sector50 while leading. The kart is still moving at57.78 native speed
units, with no rescue or reverse recovery. The recorded runtime and asset
change lists are empty. This improves the diagnostic coverage but leaves
France hard timed without a verified five-lap finish.

The shorter original ground prefix remains an unproven alternative for this
test driver. It joins the projected route at original node253/sector57 and
saves35.111m of route length. An earlier hybrid trial reached the first gate
one second sooner but lost two seconds before the second gate through rail
and train contacts. A shared geometric endpoint does not preserve the kart's
motion or the moving objects' phase. Neither that local saving nor the
automated failures justify altering the original race deadline.

The original stock-force audit in `../evidence/native/stock-force-audit.json`
also finds no timed-mode upgrade or input boost omitted by the port. Brutus's
flat-road force equilibrium is about0.64% above WhizzKitty's, with weaker
low-speed acceleration; this isolated calculation is not a measured lap
advantage. The dormant legacy turbo writer has no identified direct caller
or stored entry pointer, which is bounded reachability evidence only.

Germany's hard timed completion also has a bounded original-handler replay
of all sixteen checkpoint awards and eleven adjacent-marker rejections.
The extra initial award follows the original starting position before the
finish-arm marker; it is not a duplicate-marker bug. See
`research-germany-timed-completion.md` and
`../evidence/native/germany-timed-success-audit.json`.

Nederland's hard timed check completes in 166475ms after its full authored
camera introduction and countdown, using a faster ordinary driving segment
followed by 46 existing DMP links through the inner branch. All 15 original
awards leave 23025ms at the finish. This run records one opponent finite-velocity
safety event and no player rescues. The earlier active-grid run finishes in
165675ms without that event. The path audit checks each link against the
original track; no collision surface or checkpoint moved. See
`research-nl-timed-completion.md`.

England's medium and hard timed checks also finish five laps with15 awards.
The medium run qualifies in third place. The hard run finishes in second
place and correctly fails the original first-place qualification rule.
Its private driver chooses a forecast policy every100ms but supplies controls
and advances the actual simulation every25ms. The medium result retains an
immutable completed-case snapshot and independently verified source/asset
hashes when its redundant following hard case was stopped.

## Verification artifacts

- `final-unit-tests.log`:492 passing JavaScript tests.
- `runtime-checks.json`:before/after runtime hashes and source/output hashes
  bind each unit and browser check to this exact source checkpoint.
- `mirror-browser/validation.json`:four mirrored/ordinary rendering and
  input checks; original failures and paired screenshots retained.
- `rescue-browser/`:four player-safety and three original environment-rescue
  browser checks, including the original shrink/grow sounds.
- `build.log`:rebuilt static browser package.
- `race-matrix.json`:live, hash-checked full-race coverage. An incomplete
  matrix is explicitly marked incomplete; use
  `node tools/verify-full-race-matrix.mjs --require-all` to require all72.
- `interim-validation.json`:the current audit also verifies the original
  tables/timer evidence, runtime-bound checks and all6,831 copied build files.
  Its status remains `incomplete-race-coverage` while any full race is missing.
  Only the default strict delivery verifier can write `validation.json`.
