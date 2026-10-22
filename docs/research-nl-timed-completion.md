# Netherlands hard time-trial completion

The composed port completed five laps on the original hard time-trial clock in
165,675 ms with RedCat (character 0), construction/gameplay seeds 0, and the
25 ms reference cadence. Rank was 0 and the original qualification rule passed.
The 15 checkpoint awards left 23,825 ms. This is a port full-race validation;
it is not an original Windows full-process trajectory comparison. This original
report starts from the active grid and skips the camera/countdown sequence;
“opening” in its private controller name means the sector-before-57 driving
policy repeated each lap, not the authored pre-race camera.

No production source or game assets were changed. A private controller selects
ordinary analog steering/throttle/brake. It never writes the live kart pose,
velocity, timers, checkpoints, laps, pickups, opponents or physics tables.

## Evidence

- `evidence/full-race-matrix/timed-nl-authored-opening-3.json` and matching log:
  accepted full race. Lap times are 35,050 / 32,675 / 32,925 / 32,425 / 32,600 ms.
- `evidence/full-race-matrix/nl-authored-completion-audit.json`: independently
  checked all 131 recorded source/controller hashes and six asset hashes,
  declared dependency coverage, original timer accounting, qualification and
  authored-node linkage. Run-time and subsequent source/asset drift lists are
  empty.
- `tools/audit-nl-authored-completion.mjs`: reproducible read-only audit.
- `evidence/full-race-matrix/nl-authored-branch-map.png`: original road triangles,
  DMP nodes, CMP rails and retained outer-route trajectory around the fork.

The successful run has zero player rescues, reverse recoveries and recorded
NPC finite-velocity safety events. The slower alternate opening switch at
sector 40 also completed all five laps in 167,050 ms, but recorded two NPC
finite-velocity safety events; that distinct evidence remains in
`timed-nl-authored-opening-2.json`.

## Concrete control issue and route

The retained `timed-nl-windmill-offset-1.json` avoided the windmill but followed
the long outer route around sectors 90–125. It expired at progress 115. The
previous ground-chord composite selected bridge-side nodes 461 and 465, and
one retained trial stalled at sector 85. Entering its inner line later could
instead leave the kart on the outer fork, then steer across a separating rail.
These were controller choices; no collision or timing correction was made.

The new target chain stays on the main bridge nodes 441, 444, 448, 452, 456,
460, 464, 468, then enters the inner road via 472, 479, 486, 494 and 502. All
47 nodes form 46 existing forward DMP links; the chain is 5,188.993 source units
in XZ. The full node list is recorded in the report. A projected path target
with 0.4-second lookahead cleared this section without observed contact in the
isolated branch trial and improved deadline progress to 122. The earlier
longer-lookahead attempts and failures remain preserved in
`timed-nl-authored-branch-0.json` through `-7.json`.

Completion combines two ordinary-input policies each lap:

1. Before sector 57, the existing hazard-aware source-node line uses inverse
   original tire-force yaw control (lookahead 0.5, response 0.1, no angle
   penalty). This gets the first hard checkpoint at 11,775 ms on lap 1.
2. From sector 57, the existing 12-frame private native force/integration
   predictor chooses steering/braking. It retains the tested 120-unit eastward
   target offset through the windmill window and uses the explicit inner node
   chain in sectors 80–125. The game still executes every original collider
   and squash callback.

Predictions use copied scalar state and read-only collision queries; they do
not advance the actual game separately. All real updates remain 25 ms.

## Reproduction

The following private sources are frozen because the accepted report hashes
these exact files:

- `tools/timed-nl-authored-opening.mjs`
- `tests/helpers/private-nl-authored-branch.mjs`
- `tests/helpers/private-ground-hazard-line.mjs`
- `tests/helpers/private-predictive-driving-v3.mjs`

```sh
RCSK_DRIVEN_CASES='0,2,1' \
RCSK_DRIVEN_CHARACTER=0 \
RCSK_DRIVEN_SPEED=170 RCSK_DRIVEN_LOOK=.8 \
RCSK_DRIVEN_P=1.5 RCSK_DRIVEN_D=.3 \
RCSK_PREDICT_FRAMES=12 RCSK_DRIVEN_OPENING_END=57 \
RCSK_DRIVEN_WINDMILL_OFFSET='[55,73,120]' \
RCSK_DRIVEN_BRANCH_POLICY='[80,125,0.4]' \
RCSK_DRIVEN_AUTHORED_BRANCH='[441,444,448,452,456,460,464,468,472,479,486,494,502,509,515,522,529,536,544,552,560,567,573,579,585,591,597,603,609,615,621,627,633,639,645,652,660,668,675,681,686,691,697,702,706,709,712]' \
RCSK_DRIVEN_TRACE_DRIVER=1 RCSK_DRIVEN_SAMPLE_MS=250 \
RCSK_DRIVEN_REPORT=evidence/full-race-matrix/timed-nl-authored-replay.json \
node tools/timed-nl-authored-opening.mjs
```

The original hard clock is `[14500,11000,13000,11000]` ms. Five cycles of the
three awards give 175,000 ms; `14500 + 175000 - 165675 = 23825` ms matches the
captured timer. All 15 index/award pairs and the original qualification result
are checked by the audit. No deadlines were extended.

## Authored camera/countdown confirmation

A separate immutable runner, `tools/timed-nl-authored-countdown.mjs`, repeats
exactly the successful character 0 / seeds 0 driving policy but constructs the
race with `countdown:true`. It holds ordinary throttle 1 / steer 0 while the
original camera and 321 sequence run, and never invokes the route driver before
green. No phase, pose or timer is forced.

`evidence/full-race-matrix/timed-nl-authored-countdown-0.json` completed five
laps in **166,475 ms active race time** (174,525 ms wall time). Native green
occurred at 8,050 ms with race time 0, and the first controller input was on the
next 25 ms tick at 8,075 ms. Rank 0 qualified. Lap times were 34,950 / 32,625 / 33,050
/ 32,825 / 33,025 ms; 15 original checkpoint awards left 23,025 ms.

This separate run recorded zero player rescues/reverse recoveries and **one
NPC finite-velocity safety event**. It therefore confirms real startup and
completion with that already documented safeguard active, without claiming
an exception-free native execution.

`tools/audit-nl-authored-countdown.mjs` and
`evidence/full-race-matrix/nl-authored-countdown-audit.json` independently check
all 131 source/controller hashes, 6 asset hashes, declared dependencies, green/first
input/race-clock separation,all 5 laps, all 15 original awards, qualification and the
46 authored forward links. All checks pass, with no source or asset drift.
Reproduce using the environment above and the new countdown runner, changing
the report destination to a new file. Both original and countdown reports and
their exact private sources remain retained.
