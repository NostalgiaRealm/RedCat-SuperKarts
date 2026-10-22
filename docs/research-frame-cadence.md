# Native frame cadence and validation scope

The original executable limits the **whole game update** to at most 40 Hz.
`0x4432a0` waits until `GetTickCount() - previousTick >= 0x19` (25 ms), records
the next tick, and calls `0x42f4c0`. That function calls the physics timer update
`0x48f3e0`, the object callbacks/integration through `0x491530`, and rendering
within the same capped frame. There is no separate faster simulation loop in
this call chain. The retained exports are:

- `evidence/native/rcskspel.dat/functions/004432a0_FUN_004432a0.c`
- `evidence/native/rcskspel.dat/functions/0042f4c0_FUN_0042f4c0.c`
- `evidence/native/rcskspel.dat/functions/00491530_FUN_00491530.c`

The cap does not establish an invariant historical 40 Hz rate. Coarse Windows
ticks and rendering cost can produce slower updates. The live browser now
uses the original integer minimum-interval gate and measured variable updates,
scheduled independently of display refresh. A late callback runs once with its
actual elapsed time rather than replaying fixed steps. Rendering remains
uncapped. See [the variable-update correction](research-variable-update-timing.md).
The former fixed 25 ms `SimulationClock` remains available for explicit
deterministic replay and the historical full-race reports below.

`NativeDeltaFilter` preserves the original weighted history
`current/2 + previous/4 + previous2/8 + previous3/8`, with the original 0.1 s
upper cap and exactly-zero substitution. It has no positive minimum-delta
clamp. Feeding it 120 Hz samples directly therefore executes a diagnostic
scenario that the original main loop and the current browser host do not
permit.

## Original-instruction quantization check

`0x4911a0` advances yaw with a floating-point delta but truncates that delta
before choosing the lookup-table rotation of local velocity. The player uses
eight Euler substeps per frame. A smaller frame interval can therefore change
the integer rotation applied at each substep.

`tools/native-cadence-quantization.py` executes the original instructions for
16 synthetic cases in both 24-bit and 53-bit x87 precision. It compares equal
0.1 s durations at 40 Hz and diagnostic 120 Hz, with constant yaw rate, zero
external force, and no contacts. For initial forward speed 60 and yaw rate
0.5, the 24-bit results are:

| Update cadence | Final yaw, native units | Final lateral speed | Final forward speed |
| --- | ---: | ---: | ---: |
| 40 Hz | 32.5949249 | 2.9437315 | 59.9276733 |
| 120 Hz, diagnostic only | 32.5949593 | 0 | 60 |

The JavaScript kernel matches every recorded field within 0.00002. The two
tests in `tests/native-cadence-quantization.test.mjs` pass. Fixtures and logs
are in `evidence/native/cadence-quantization.json`,
`cadence-quantization-generation.log`, and `cadence-quantization-tests.log`.
This demonstrates native cadence sensitivity; it does not justify advancing
physics at display frequency. The live variable-update correction retains
the original minimum interval and does not adopt the 120 Hz experiment.

## France hard time-trial reports

The real-start diagnostic runners execute the authored opening camera and
countdown, hold ordinary throttle with zero steering before green, and only
then invoke the route follower. They record opening, green, wall duration,
and the original active race time separately. They never write kart poses,
velocities, pickups, phases, or timers.

The retained 40 Hz attempts still fail the complete five-lap objective.
Diagnostic 120 Hz runs `timed-france-hard-real-cadence8.json` and
`timed-france-hard-real-cadence9.json` finish five laps in 176400 ms and
178025 ms of active race time. Both include the original opening, but their
simulation cadence is outside the native cap. **Neither is a production
matrix completion.** They are explicitly excluded by
`evidence/full-race-matrix/cadence-diagnostic-scope.json`, which preserves
their digests and the relevant native call chain. The immutable diagnostic
runner is `tools/diagnose-countdown-cadence.mjs`.
