# Camera speed and behavior audit

This audit executes instructions from the preserved `rcskspel.dat` (SHA256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`).
It does not claim a successful Wine race-rendering observation. This earlier
audit used an explicit 25ms reference update. The live browser subsequently
adopted [measured variable updates](research-variable-update-timing.md), still
independent of uncapped display refresh; the original updates once per
main-loop iteration and can slow under load.

## Opening camera and initial clock

The short opening fly-through is supported by the original code. The startup
chain `4432a0 → 442fc0 → 48f2c0 → 42f930 → 42f740(1)` initializes the engine
clock before the immediate start-action initializer allocates its path.
There has not yet been a main-loop `48f3e0` update.

`48f2c0` fills the four history slots with float32 `.1`, then calls `48f3e0`.
The previous absolute time was zeroed by the static timer constructor
`48f125/48f12f`. Consequently this call inserts absolute host uptime into
the delta history. `48f4e0` caps the resulting delta at `.1` for an ordinary
already-running host. The startup path uses this capped initialization
delta, rather than the first browser frame's `.0625` filtered delta.

`443d20` adds 1000 to the authored duration, divides by that initialization
delta, and quantizes the result to whole Hermite segments. `443f10` later
advances the resulting tick count using 25ms wall-clock ticks. These are two
different clocks. At initial delta `.1`, the six path tick counts are:

| Track | Authored milliseconds | Allocated ticks |
| --- | ---: | ---: |
| Netherlands | 9000 | 96 |
| Germany | 6000 | 70 |
| England | 6500 | 72 |
| France | 6500 | 70 |
| Spain | 4000 | 45 |
| Italy | 6000 | 64 |

The controller also waits 1000ms before travel and then approaches the
player by `.1` of the remaining distance per update, stopping at distance
`<=1`. The allocated travel duration alone is not the total opening duration.
Changing the fly-through to last the authored milliseconds would change the
original behavior.

There was a separate browser gap: the initialized history had not contained
that initial uptime sample. The first three main-loop deltas for ordinary
uptimes are therefore `.1` in the original, whereas an unprimed filter
returned `.0625`, `.04375`, and `.034375` for 25ms input. `NativeDeltaFilter`
now accepts `{uptimeMs}` and exposes `initialDelta`. The exported
`NATIVE_REFERENCE_UPTIME_MS=60000` is an explicit deterministic browser-host
policy, not a measurement of the user's operating-system uptime. Sixty seconds
also places zero-initialized raw-tick deadlines in their ordinary expired
state, including the player's five-second turbo-animation window. A one-second
reference host would reproduce that unusual boot-time window for four seconds.

Pause uses a different routine, `48f520`: it updates the absolute timestamp,
sets current delta to zero, and fills the histories with `.1`, without
inserting uptime. An unprimed filter on resume remains correct. Original
absolute-clock cancellation at long uptimes is retained in instruction
fixtures; browser reference updates do not deliberately reproduce that
host-dependent precision loss.

## Chase, first-person, rear and lower-target views

`41d920` checks virtual keys in the order 1, 2, 3, 4. Keys1,3,4 require race
phase0; key2 works in other phases too. Held3 remembers the previous mode and
selects rear view; releasing it restores that mode only in phase0.

| Key | Native mode | Position offset | Target | Position damping |
| --- | ---: | --- | --- | --- |
| 1 | 1 | `(0,50,-150)` | Body-local `(0,50,0)` | `(.1,.1,.5)` |
| 2 | 3 | `(0,15.5,-1)` | Position plus body forward | Disabled |
| Held3 | 5 | `(0,23,40)` | Body-local `(0,50,0)` | Inherited |
| 4 | 0 | `(0,50,-150)` | Body-local `(0,25,0)` | `(.1,.1,.5)` |

`498c00` applies chase damping in body coordinates, once per native update,
with no delta multiplier. It is not a camera speed expressed per second.
Rear view entered from first-person consequently has no damping; rear view
entered from chase does. First-person uses body up and hides the player's
whole render tree. `4918f0` also suppresses that object's shadow callback
behind the same object `+3c` flag. HUD and separately emitted particles are
not controlled by that flag.

Mode changes select camera0 and reset its sector hint from the player's
current sector, even when a held key repeatedly selects the same mode.
The selected camera persists until another key or scripted action changes
it. Merely reaching the end of the opening path or showing the321 countdown
does not reselect camera6.

Green `420f00` disables target damping, updates the retained player camera
once using its current mode, and then selects/restores mode1. Finish
`41fc60` selects fixed camera5 without resetting player mode or its draw
flag. Failure `420730` first restores player mode1 and then selects the
camera6 orbit. Thus mode changes must not be overridden on every frame by
a preference for a still-existing opening/finish camera object.

## Finish, expiry and projection

The existing fixed finish camera is supported by `41fc60`: logical route
entry `sector+3`, Y offset40, target at body-local `(0,20,0)`. The expiry
camera uses `420730/420850`: it calculates an integer orbit increment from
entry delta and advances after rendering. In the24-bit reference calculation,
at entry delta float32 `.025`,
the stored period is320 frames and increment12 native angle units; this
quantization must be preserved rather than replaced by a smooth eight-second
orbit. The existing finish/expiry instruction fixtures still validate these
helpers.

Projection remains81 degrees horizontally at4:3. `4acf40` supplies the
viewport aspect correction despite equal X/Y projection-matrix scales.
Modern wider framing is separately documented in `research-startup.md`.

## Reproducible evidence

- `tools/native-camera-clock-fixtures.py`:144 complete timer/path
  initializations, both QPC and timeGetTime branches, six host uptimes, all
  six tracks and both explicit x87 precisions.
- `tools/native-camera-control-fixtures.py`:384 original mode transitions
  and transforms,512 original key/phase combinations,8 green transitions.
- Existing camera fixtures:200 chase updates,48 startup executions with
  12988 updates,120 finish-camera cases,60 expiry-camera setups/traces.
- `tests/native-camera-clock.test.mjs`,
  `tests/native-camera-controls.test.mjs`, `tests/native-camera.test.mjs`
  compare the helpers to this instruction output.
- REA/Ghidra12.1.4 refreshed `48f2c0` and `41d920` independently in
  `evidence/native/rea-camera-timer-init.json` and
  `evidence/native/rea-camera-update.json`. Evidence IDs:
  `ev_f49183672434e7f3b8e84872f37cbd983e257388bbf2194efb26fbf4c725c57d`
  and `ev_c9492fa8adf0a04a9cb79b701cb35343ff5bf365436da02d736668e07dfc9890`.

The helpers are connected in `RaceSimulation`, `DrivingView` and the reference
clock. The active camera persists; key selection and green reset its sector
hint; failure restores normal mode; first-person hides kart and shadow.
`tests/camera-browser.mjs` used real browser keydown/keyup events and passed
all four scenarios: first-person, rear view retaining disabled damping,
lower-target chase and normal chase. `evidence/camera/browser.json` records
the captured states and zero browser errors. This verifies the browser
wiring separately from the native transform comparisons.
