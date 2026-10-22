# Germany hard time-trial completion

The corrected runtime completes Germany’s hard time trial with five laps,
first place and native qualification. The retained run is
`evidence/full-race-matrix/timed-germany-hard-ground-predict8.json`.
It takes **185,375 ms of active race time** and **192,900 ms including the
authored opening and countdown**. Green occurs at wall time 7,525 ms; the
ordinary route controller first runs on the following 25 ms update.

This is a composed browser-runtime result, not an original Windows process
trajectory comparison. No production code changed during these controller
experiments. The run uses the corrected original startup sequence: loaded
upgrade flags are cleared by player construction before physics and timers
are initialized. See `research-startup-upgrades.md`.

## Controller and evidence

The immutable private runner is `tools/timed-germany-ground-predictive.mjs`.
Its route helper, `tests/helpers/private-ground-chord-driver.mjs`, selects a
21,914-unit closed line between authored driving nodes. Hypothetical chords
must clear every intersecting CMP rail and sample original road, land or extra
ground, excluding fallback planes. It does not add routes to the game or
change collisions. This planner does not preclude every scenery object;
the unchanged live collision system and the predictor still see those objects.

The steering selector is
`tests/helpers/private-predictive-driving-v3.mjs`. It evaluates eight frames
of original force/integration kernels on private body copies, then supplies
ordinary analog steering, throttle and brake. It never applies predicted
poses, velocities or contacts to the real kart.

The successful settings are character 0, construction/gameplay seeds 0,
25 ms cadence, chord turn penalty 0, speed target 170, lookahead .8,
steering gain 3, damping .6 and prediction horizon 8. The speed target is a
controller request; original engine and physics still determine actual speed.
There are no pickups in the original timed mode, and no bonus was granted or
fired. No player rescue, reverse-recovery maneuver or NPC nonfinite-reset
event occurs in this run.

All 120 recorded source entries and six input assets were independently
rehashed after completion and match the current files. The run’s source and
asset mutation guards are empty. Its ordinary-input stream SHA-256 is
`26bf3d8f059396f809fc5869618d152076d769960e5a494303a5feb428f93ee5`.
The failed twelve-frame predictor, handbrake pulses, longer preview settings,
alternative seeds and other control policies remain in the same evidence
directory. They are not counted as completed races.

## Why sixteen gate awards are original behavior

The source route contains checkpoint 74 at sectors 174 and 175, checkpoint
75 at 53, checkpoint 76 at 112 and 113, finish marker 14 at 175, and finish-arm
marker 15 at 176. The initial player sector is 173; ground settling moves it
to 172 before green, with cumulative progress -1. The first checkpoint is
therefore crossed before the first complete lap is armed.

Original `0x441e70` accepts a player checkpoint only when the saved gate
progress is strictly less than cumulative progress. It then saves
`progress + 1`, cycles the next award index and adds the award to timer 18’s
remaining time. Consequently the adjacent duplicate checkpoint markers do
not award twice. The initial award plus three per completed circuit gives
**sixteen awards**, not fifteen.

`tools/native-germany-timed-audit.py` executes the original handler for all
sixteen captured award times and the eleven corresponding adjacent-marker
rejections. Authored forward-topology progress values are supplied explicitly;
this bounded handler replay is not a native replay of the whole race.
The output is `evidence/native/germany-timed-success-audit.json`, with the
original executable, captured report, track and configuration hashes.

The unmodified hard configuration is `7000, 12500, 13000, 11000` ms. Six awards
of 12,500, five of 13,000 and five of 11,000 give:

```
7,000 + 195,000 - 185,375 = 16,625 ms remaining
```

The original handler produces that exact balance. Final cumulative progress
and the next gate threshold are both 937. The five recorded lap times are
37,450, 35,525, 36,600, 41,375 and 34,425 ms, summing to the active finish time.
No deadline, trigger, lap or position was forced.

## Reproduce

```sh
RCSK_DRIVEN_CASES='1,2,1' \
RCSK_DRIVEN_CHARACTER=0 \
RCSK_DRIVEN_SPEED=170 RCSK_DRIVEN_LOOK=.8 \
RCSK_DRIVEN_P=3 RCSK_DRIVEN_D=.6 \
RCSK_DRIVEN_TURN_PENALTY=0 RCSK_PREDICT_FRAMES=8 \
RCSK_DRIVEN_TRACE_DRIVER=1 RCSK_DRIVEN_SAMPLE_MS=1000 \
RCSK_DRIVEN_REPORT=evidence/full-race-matrix/germany-hard-reproduction.json \
node tools/timed-germany-ground-predictive.mjs
```

Use a separate output filename to preserve the accepted report. The original
instruction audit is run with a Python environment containing Unicorn and
pefile:

```sh
python tools/native-germany-timed-audit.py
```
