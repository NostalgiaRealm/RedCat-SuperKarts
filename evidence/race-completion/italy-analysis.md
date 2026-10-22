# Italy control-only completion diagnostic

The original incomplete Italy run is reproducible. A test-driver routing
correction completes all five laps in **503,550 ms**, with rank **0** and the
original qualification result true. No production simulation code changed.

## Failed trajectory

`italy-baseline.json` reproduces the retained
`evidence/gameplay/followup-driven-normal.json` Italy run through 340 seconds.
All 34 shared ten-second samples agree exactly for position, sector, speed,
lap count, race distance, rank, stars and reverse-recovery count. The first two
lap times remain 130,325 and 127,775 ms.

The follower reaches marker-50 DMP waypoint 491 in sector 94 around 303.6
seconds. The player is at approximately `[-6008.79, 0, 943.18]`. Its active
environment rescue then remains at shrink frame 19 with a blocked destination.
The source environment scan selects marker-51 waypoint 514:
`[-5518.708, -0.439684, 1152.188]`. NPC 0 occupies its ground-projected position.
The player's sampled collision sweeps have fraction 1 and no contact; it is not
wedged against a rail or another nearby kart. Rescue zeroes its linear speeds
after normal movement, so the follower's repeated forward/reverse attempts do
not escape the pending return.

`italy-all-rescue-trace.json` captures all racer states and rescue entries:

- At 302 seconds NPC 0 is growing after its own environmental return at
  waypoint 514, with `blockRecovery=true`.
- At 303 seconds the queue is empty. NPC 0 remains at the destination and has
  `disabled=true`; NPC 3 is nearby in recovery mode 10.
- From 304 seconds NPC 0 and NPC 3 are both in recovery mode 10, with
  `blockRecovery=false`. Neither remains queued. Their recovery clocks cycle.
- From 305 seconds only player 4 remains in the rescue queue, blocked at
  shrinking frame 19.

Mode 10 means recovery, not finished. This trace establishes the composed
port's blocker; it does not establish that the original full process reaches
the same preceding trajectory or NPC arrangement.

The applicable original routines are `48c030` (environment test), `48bf80`
(marker-51 search), `48c170` (return-position occupancy) and `48ca60` (rescue
update/retry). Existing native fixtures cover those rules. This diagnostic does
not alter or bypass them.

## Control-only correction

The temporary `tools/diagnose-italy-driver.mjs` and
`tools/diagnose-italy-planner.mjs` prefer adjacent authored road nodes over
marker-50 nodes when selecting nearest candidates, forward links, visibility
graph vertices and default road-return goals. They continue to supply only
ordinary throttle, brake and steering inputs. Collision probes are read-only.
They do not write positions, velocities, waypoints, rescue state, pickups,
triggers, timers or physics parameters.

The merged general-purpose helper must retain original candidates/links when
no alternative exists. Germany and France contain sectors whose only nodes
have marker 50. The temporary strict filter is deliberately Italy-scoped;
Italy has safe adjacent lanes through its marked regions.

`italy-avoid-environment.json` and the strengthened replay
`italy-qualified-continuous.json` both finish at 503,550 ms with identical input
SHA-256:

`9d618a992986daa308c1a60379e586fbc60908765e0deff22da187fda6c25cca`

Lap times are 124,850 / 94,500 / 96,250 / 94,275 / 93,675 ms. The strengthened
replay measures every 25-ms simulation tick:

- Five laps, finished phase 3, rank 0, qualified.
- Zero player marker-50 waypoint ticks.
- Zero player rescue entries.
- Maximum three-dimensional position change 8.2536677964 original world units
  per tick.
- One ordinary reverse maneuver by the test driver.
- No nonfinite actors or changed execution dependencies.

Thus completion follows a continuous alternate driving line, rather than
using rescue relocation or forcing lap triggers.

## Reproduction

Run the failed policy with detailed NPC/rescue traces:

```sh
RCSK_SOURCE_SCOPE=execution RCSK_DRIVEN_TRACE_DRIVER=1 RCSK_DRIVEN_MAX_MS=310000 RCSK_DRIVEN_REPORT=evidence/race-completion/italy-all-rescue-trace.json node tools/diagnose-italy-race.mjs
```

Run the continuous five-lap completion:

```sh
ITALY_AVOID_ENVIRONMENT=1 RCSK_SOURCE_SCOPE=execution RCSK_DRIVEN_TRACE_DRIVER=1 RCSK_DRIVEN_SAMPLE_MS=1000 RCSK_DRIVEN_MAX_MS=900000 RCSK_DRIVEN_REPORT=evidence/race-completion/italy-qualified-continuous.json node tools/diagnose-italy-race.mjs
```

Each report records source digests, imported execution dependencies, seed 0
for both construction and gameplay, original opponent count, actual inputs'
digest, lap events and final original qualification. This is a headless
composed-port driving check, not an original Windows whole-race comparison or
campaign UI run.
