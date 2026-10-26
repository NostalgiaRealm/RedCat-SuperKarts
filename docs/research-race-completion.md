# Germany, France and Italy completion checks

This follow-up investigates the three unfinished easy normal races in
`evidence/gameplay/followup-driven-normal.json`. The original report remains
unchanged. Runs use character 0, four original opponents, 25 ms updates and
construction/gameplay seeds 0. The test driver supplies ordinary analog
controls to the composed race, including its original collision, AI, bonuses,
rescue and lap-counting code.

## Germany: a stale test-driver detour

The unchanged baseline reproduces the previous input digest. During the last
100 seconds, the driver keeps chasing one corner, remaining 36.859–50.813
world units from it. Its acceptance radius is 35. The kart still moves at
6.844–7.090 units of forward speed, so the stationary recovery detector never
fires. This is a route-following failure, not evidence of a physics mismatch.

The test driver now detects a detour target that has not become at least five
units closer for six seconds. It checks a road reconnect with the original
collision query, or replans against current obstacle positions. It changes
only its steering target. A continuously improving detour is retained even
when it takes longer than six seconds.

Evidence: `germany-baseline.json`, `germany-orbit-fixture.json` and
`germany-detour-refresh.json` under `evidence/race-completion/`.

## Italy: driving into an occupied rescue return

The original follower enters authored environmental waypoint 491, marker 50,
near sector 94 at about 303.6 seconds. The original forward array search
selects return marker 51 at waypoint 514. NPC 0 occupies that return point.
The player remains in the shrinking rescue sequence at frame 19 while the
destination is blocked; ordinary throttle and reverse input cannot end it.

The trace retains every actor and rescue queue entry. NPC 0 has already
finished its own rescue and later enters recovery mode 10; it is not a
finished racer and is not itself waiting in the rescue queue. These state
observations alone do not prove whether the complete native race would reach
the same prolonged situation.

`tools/native-italy-rescue-check.py` executes original `0x48c170` and
`0x417e90` with the captured occupants. All six checks at 24/53-bit precision
confirm the original planar occupancy rule: the captured destination is
blocked; moving NPC 0 away makes it free; changing only its height leaves it
blocked. Only logging is stubbed. The isolated input variations are not
changes to a driven race.

The test driver now prefers ordinary authored road nodes beside marker 50
nodes where those alternatives exist. Its detour planner applies the same
preference, so it cannot quietly reintroduce the water route. Sections whose
only authored nodes are marker 50 remain available: the original rescue
condition also tests height above the fallback plane, and raised road
sections must not be removed from the route.

The Italy diagnostic completed five continuously driven laps in 503550 ms,
with zero player rescue entries, zero marker-50 waypoint ticks and a maximum
3D position step of 8.25367 world units per 25 ms update. A second run
reproduced the input digest. Final shared-helper results are recorded
separately from this diagnostic.

Evidence: `italy-analysis.md`, `italy-all-rescue-trace.json`,
`italy-native-rescue.json` and `italy-qualified-continuous.json` under
`evidence/race-completion/`.

## France: original clearance permits a subsequent overlap

A control-driven trace catches environmental rescue relocating the player
at 331150 ms to waypoint 471. NPC 3 is already only 2167.74047 squared XZ
units away. Original `0x48c170` rejects distances at or below 2000, so it
accepts this destination. Original `0x49a480` confirms the resulting rotated
kart rectangles overlap in both directed tests.

The composed original `0x491d30` probe then executes candidate discovery,
model bounds, sweep/slide, player substeps, NPC integration and paired contact
response at the captured blocked pair. All 256 recurrent frames at the
port's active 24-bit precision agree exactly. Another 256 frames at 53-bit
precision have rounding differences, retained explicitly in the report.
Time, occupancy bookkeeping, sector/waypoint and ground callbacks are isolated
boundaries; this is not a complete original race replay.

This evidence does not justify enlarging the rescue clearance or adding a
new overlap escape as a claim of native parity. The user subsequently
authorized a deliberate safety exception, described below.

Evidence: `france-live-approach.json`, `france-native-rescue-overlap.json`,
`france-native-frame-fixtures.json` and
`france-native-frame-comparison.json` under `evidence/race-completion/`.

## Recovered jump and direction corrections

Tracing the approach to the France gap uncovered an omitted active player
jump callback. Registered markers 49/52 add velocity to all four wheels and
apply the original forward multiplier. The original integer configuration
reader truncates the authored decimal multipliers. There are 648 callback,
320 registered-crossing and two integer-loader instruction cases.
`research-player-jump.md` records the dispatch, gates, values and boundaries.

The investigation also separated `Race.INI / ETAPPE / british` and `DIRECTION`
from the track's mirrored graphics flag. The shared route options now feed
start/grid fallback, projectile/weather facing, rescue and jumps. The supplied
British and Direction values both resolve to zero.

## Authorized player rescue safeguard

The user explicitly allowed divergence from native behavior to prevent stuck
players. The original destination is retained when clear. Player placement
also checks complete rotated rectangles against active physical bodies and
rails, including edge crossings which the original corner test misses.

After two seconds of blocked simulation time, the controller searches nearby
authored road positions up to twelve sectors behind the original return.
Candidates must have road support under the center and all four corners,
clear geometry and no environmental-rescue marker. It never moves the
blocking opponents, advances a timer, awards a lap or forces an occupied
placement. If every candidate is unsafe, the search keeps waiting and retries.

The fallback restores upright orientation, wheel world heights and wheel
velocities at the new road position. Clearance is checked again before growth
finishes, so an opponent entering during the animation cannot leave the
player trapped. Native helper fixtures and opponent rescue behavior retain
their reference rules.

Captured Italy and France regressions, wheel-height restoration, incoming
opponents during growth and an entirely blocked search are tested separately.
The browser safeguard fixture retains the original shrinking effect and
both actual character sounds, returns Italy's player to road waypoint 508
while the original point 514 remains occupied, and drives onward with
ArrowUp. The unchanged Nederland bridge/moat browser test still returns to
the original waypoint 441 in forty animation ticks.

## Completion gates and scope

`tools/validate-driven-races.mjs` now returns a failing exit status for
unfinished races as well as errors or changed source. A 25 ms negative check
retains `status: incomplete` and exits 1 in
`evidence/race-completion/incomplete-exit-check.json`; it is deliberately not
counted as a race-completion pass.

Final reports retain the actual lap events, input digests, source fingerprints,
opponent counts and qualification results. Finishing five laps and qualifying
are separate assertions. These checks establish completion in the port under
ordinary controls, not full Windows trajectory, framebuffer or audio parity.
WineD3D remains unsuitable for that original whole-game comparison.

## Final results

All three runs use identical source fingerprints, with no source changes
during execution. They each finish all five laps, place first and qualify.
The maximum test duration was 1800000 ms; all three finish within the previous
900000 ms limit.

| Track | Five-lap simulation time | Report |
| --- | --- | --- |
| Germany | 648975 ms (10:48.975) | `final-germany.json` |
| France | 812350 ms (13:32.350) | `final-france.json` |
| Italy | 565975 ms (9:25.975) | `final-italy.json` |

`evidence/race-completion/validation.json` consolidates these runs, 445 passing
JavaScript tests, seven browser checks and byte comparison of 6830 copied
runtime/asset files in the rebuilt 6841-file package. Earlier failures and
the successful pre-safety Germany/Italy runs remain retained separately.

The following commands record how that historical checkpoint was verified.
The final verifier requires its frozen source/runtime hashes; a build from the
current checkout cannot reproduce those hashes. Run new driven checks with a
new report path to keep the retained checkpoint intact. See
[development checks](development.md) for current validation guidance.

```sh
RCSK_DRIVEN_CASES='1,0,0' RCSK_DRIVEN_MAX_MS=1800000 RCSK_DRIVEN_REPORT=evidence/race-completion/final-germany.json node tools/validate-driven-races.mjs
RCSK_DRIVEN_CASES='3,0,0' RCSK_DRIVEN_MAX_MS=1800000 RCSK_DRIVEN_REPORT=evidence/race-completion/final-france.json node tools/validate-driven-races.mjs
RCSK_DRIVEN_CASES='5,0,0' RCSK_DRIVEN_MAX_MS=1800000 RCSK_DRIVEN_REPORT=evidence/race-completion/final-italy.json node tools/validate-driven-races.mjs
npm test > evidence/race-completion/final-unit-tests.log 2>&1
npm run build
node tools/verify-race-completion.mjs
```
