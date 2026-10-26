# Variable native update timing

This source-only investigation executes preserved `rcskspel.dat` instructions.
It does not launch the Windows game, measure historical hardware, or change
the original files. The source SHA-256 is
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.

## One update after at least 25 milliseconds

`004432a0` samples an initial `GetTickCount` after initialization and
`0042f930`. At `0044331b`, it repeatedly samples the clock until the **unsigned
32-bit difference** from the preceding update start is at least 25. It then
samples `GetTickCount` again at `00443324`, stores that actual start, and calls
the complete game handler at `00443335 → 0042f4c0`.

The second sample matters: if admission was at25ms but the next clock read is
26ms, the following deadline is51ms. No accumulated25ms schedule is retained.
A300ms late callback causes one update, not twelve updates. Callback work,
rendering and presentation can all delay the next start. The original loop
does not establish a fixed40Hz or33ms cadence.

The browser retains uncapped presentation while an independent scheduled
callback polls the same minimum-interval condition. It uses its actual
monotonic start time, not its scheduled deadline, records one accepted
start and performs at most one complete update. Rendering only reads the
captured state and never advances simulation. Browser scheduling and display
interpolation remain host adaptations; they must not become another source
of physics updates.

## A separate absolute engine clock

The first operation within `0042f4c0` is `0048f3e0`. It reads
`QueryPerformanceCounter`, with its frequency stored as float32, or unsigned
`timeGetTime` with frequency1000. The clock does **not** simply filter the
difference of two JavaScript double timestamps:

1. Divide the full counter by the stored float32 frequency at the selected
   x87 arithmetic precision.
2. Subtract the prior stored float32 absolute time and store raw delta as
   float32; separately store the new absolute quotient as float32.
3. Insert raw delta in the four-entry circular history. Compute
   `raw/2 + previous/4 + previous2/8 + previous3/8`, storing the intermediate
   accumulated result after each addition as float32.
4. `0048f4e0` substitutes the original float32 `.1` only when the stored result
   equals zero or is greater than double `.1`. Negative finite deltas are
   retained. `0048f4d0` separately returns the stored absolute seconds.

At24-bit arithmetic the quotient is rounded to float32 before subtraction.
At53-bit arithmetic it retains extra precision until the two stores, so even
an identical repeated clock sample can have a tiny signed raw delta. The
fixture verifies both precisions explicitly; it does not identify an unknown
historical graphics driver's FPU setting.

`NativeEngineTimer` in `source/simulation/clock.js` implements this arithmetic.
The live-host API is:

```js
const timer = new NativeEngineTimer({absoluteSeconds: 60, precision: 24});
const delta = timer.sampleAbsoluteSeconds((60000 + wallMs) / 1000);
timer.resetAbsoluteSeconds((60000 + resumeWallMs) / 1000);
```

`initialDelta` captures the constructor's original priming update.
`sampleCounter` and `resetCounter` additionally accept the source counter and
frequency for exact fixture replay. The existing deterministic `SimulationClock`
and duration-only `NativeDeltaFilter` remain available for historical reference
traces; they are distinct from the live variable-update host.

The60-second browser epoch is explicit, rather than a claim about original
Windows uptime. It retains the previous reference host's expired zero-initialized
raw deadlines. Use it consistently for native absolute seconds and raw tick
consumers. Race timers still use their separate pause-aware elapsed records.

## Cold startup and pause/resume

`0048f2c0` fills all four history slots with float32 `.1`, then performs an
ordinary update while the prior absolute time is zero. At60 seconds uptime,
that inserts raw60 into history; the constructor and first three ordinary
updates return the capped float32 `.1`. The authored start-camera initializer
runs before the first main-loop update and uses that constructor value.

`0042f350` pauses timer IDs`0,3,8,9..27`, executes the blocking pause/requester,
resumes those records, and then calls `0048f520`. Reset refreshes absolute
engine time from the current OS clock, fills all four history entries with
float32 `.1`, writes current delta zero, and **retains the circular index**.
It does not insert uptime again. The main-loop previous-start timestamp is
not reset by this function.

Consequences for the live adapter:

- Time before pause is not carried into the first post-reset physics delta.
- After a long pause the unchanged main-loop gate can admit an update
  immediately. Its raw physics delta is the time since the reset, possibly
  almost zero, rather than a forced25ms interval.
- The reset's delta getter returns `.1`, but the first subsequent update at
  the same absolute clock returns approximately `.05` after history filtering.
- Native raw-clock deadlines and absolute engine time age through ordinary
  pause. Race records exclude the pause by shifting their starts. Use the
  actual event timestamp for pause/resume, not the last accepted physics tick.
- A late unpaused update advances race clocks by the actual elapsed wall time,
  although the filtered physics delta may cap at`.1`. There is no native
  mechanism to recover that missed motion through additional updates.

For example, the24-bit1MHz fixture at60 seconds reads absolute
`60.025001525878906` after25ms, giving raw`.02500152587890625`. After a reset
at61537ms, an update at the same clock stores raw0 and returns
`.05000000074505806`. These are original stored values, not tolerance targets.

## Reproducible bounded checks

```sh
re-python tools/native-variable-timing-fixtures.py
node --test tests/native-engine-timer.test.mjs
```

`evidence/native/variable-timing-fixtures.json` contains:

- Six original gate traces /36 polling observations, including exact boundary,
  distinct admission/start readings, long delays, unsigned wrap and a pause-shaped
  gap. The gate range executes `0044331b..0044333a`; only clock/log calls and
  the game-update body are boundaries.
- Eighteen complete constructor/update/reset traces /288 observations across
 24-/53-bit x87, timeGetTime, QPC1MHz and QPC3,579,545Hz, and0/60-second/24-hour
  epochs. OS clocks, logging and allocation are supplied; original arithmetic,
  stores, circular index, getter and reset execute unchanged.

All288 JavaScript samples match the returned delta, stored absolute time,
raw delta, accumulated delta, history and ring index exactly. Three focused
tests pass, including cold priming, pause reset and signed cancellation.
The existing native game-timer fixtures separately cover2,880 timer operations.
No full suite, new race-completion matrix, browser run or release build is
claimed by this evidence task. Historical fixed25ms driven reports retain
their original scope and are not automatically reclassified as variable-host
validation.

## Live browser integration

`NativeUpdateClock` separates the integer admission gate, active elapsed time,
absolute elapsed time and reset-relative physics interval. Its `snapshot`
method is read-only. `NativeUpdateLoop` owns one browser timer and subtracts
the time spent doing update work when scheduling the next eligible callback.
If the gate is already due, it yields through a new timer rather than running
another update synchronously. Delayed callbacks never replay a fixed backlog.

`TrackViewer` starts this loop on resume and stops it before loading another
track, pausing or disposing its renderer. `DrivingView` gives race timers the
measured wall clock and gives native absolute-time consumers the same clock
with the declared60-second epoch. Physical-key events remain immediate, and
gamepad state is polled at update admission as well as display refresh.

Every active browser animation frame still draws the world and HUD. Kart and
camera interpolation uses the previous measured update interval. Rendering
reads current `performance.now()`, since a browser RAF timestamp can precede
a timer callback already executed in the same display frame. There is no
game-imposed30/40/60FPS presentation limit; browser/display scheduling still
sets the available refresh opportunities. The port does not emulate native
DirectDraw flip blocking.

The first browser check exposed an older input guard that rejected the native
float32`.1` value because it is slightly larger than JavaScript double`.1`.
Input and the soft-lock detector now accept the original float32 cap. The
timer output is not rounded down to hide the mismatch. Focused regressions
cover startup, delayed updates and continued soft-lock detection.

The live-host checks and source hashes are recorded separately in
[`evidence/variable-cadence/validation.json`](../evidence/variable-cadence/validation.json).
The full test suite, full-race matrix and release packages are not rerun or
rebuilt for this source-only correction.
