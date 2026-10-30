# Original-code comparison — 28 October 2026

This report covers a read-only comparison of the `main` checkout at
`991cba9f` against the recovered native code and the ten approved corrections
that followed: items 1–6 with a pause follow-up, then items 7–10. All ten are
in the published 1.0.1 release. It
records bounded static and instruction evidence; see [coverage](#coverage)
for what this pass did and did not re-check. It does not
establish complete equivalence with the original game, and no comparison
against a working original Windows installation was possible.

Module names are given with every address. All addresses are in
`rcskspel.dat` unless another module is named. Decompiled C was treated as
pseudocode; each finding below was checked against the assembly, the bytes or
the data tables in `original-source/modules/`. The original installation, the
binary copies and `original-source/` were only read.

## Approved corrections

### 1. Player bonus pickups had a cooldown the original does not have

- **Original:** pickup handler `0x4514e0` passes the racer index from the loop
  `0x4540c0` unchanged to `0x4106b0` (call at `0x45151f`). `0x4106b0` writes
  the player's own deadline only for index -1 (`CMP ESI,-1` at `0x4106cd`);
  any other index, including the player's index N, writes
  `0x503ff0 + index×0x11c`. The eligibility reader `0x410650` checks the player
  against `[player+0x100]`, which constructor `0x4023a0` zeroes and no
  reachable code writes afterwards. Every other `+0x100` store was checked;
  the 400.0 store in `0x4031f0` targets a separate object at `0x504fe0`.
- **Port before:** `NativeBonusPickups.step` armed `eligibleAfter` for the
  player as well, so the player waited 250 ms between pickups.
- **Change:** `source/simulation/native-bonus.js` arms the deadline for
  opponents only. The soft-lock protections (`canCollect`,
  `excludedPickups`) are unchanged.
- **Effect:** the player can collect overlapping or closely spaced pickups in
  consecutive updates, so pickup counts, bonus voice lines and random-number
  use can differ from earlier port runs.

### 2. The starting rank ignored the previous finishing position

- **Original:** `0x42c680` (jump table `0x42c758`) reads Race.ini
  `PLAYER.position` (strings `0x4ea114`/`0x4ea108`) for race types 0, 2, 4 and 5
  and uses 0 for types 1 and 3. It clamps the value to the opponent count
  (`0x42abe0`) and stores it in `0x53be60`, which is the live player rank read
  by `0x401570`, `0x4016e0`, `0x406be0`, `0x40cde0`, `0x40d070` and others.
  `0x42c570` writes the position only after a finished race; `rcskmenu.dat`
  `0x472194` only reads it. Grid placement is not affected because every
  shipped track has complete start markers 69–73.
- **Port before:** `nativeRaceGrid` already supported `previousFinishPosition`
  but `RaceSimulation` never passed it, and the player's rank state was fixed
  at 0.
- **Change:**
  - `source/race-save.js` keeps an additive `playerPosition` field. It is set
    only when a finished result carries a position, so it survives
    unfinished races.
  - Saves without the field use `lastResult.PLAYER.position` when that result
    was finished; otherwise the shipped value 0 applies. Older saves are not
    rewritten until the next race result.
  - `configWithRaceSave` passes the value as Race.ini `PLAYER.position`.
  - `source/race-simulation.js` passes it to `nativeRaceSetup`, and
    `source/simulation/native-race-setup.js` returns the clamped rank that
    now seeds the player's rank state.

### 3. Volume settings lost 1% at 29, 57 and 58%

- **Original:** the options sliders (`rcskmenu.dat` `0x46b7f0`/`0x46b80c`,
  `0x46b400`) hold integers, which are clamped (`0x45bb8c`/`0x45bb6c`) and
  saved (`0x45b629`) as integers. The race reads integers (`0x42c320`,
  `0x431610`, `0x49d520`).
- **Port before:** settings store `slider/100`, and every conversion back
  used `x*100` followed by native truncation, so 29, 57 and 58 became 28, 56
  and 57. Because the effects repair check in `main.js` compared the stored
  fraction with the race's integer, it also wrote the reduced effects value
  back, which lowered it by one more on each later race.
- **Change:** `settingsAudioPercent` in `source/audio-mixing.js` rounds the
  stored fraction to a whole percentage. It is used for the race effects
  level and music level (`source/driving-view.js`), the options slider values
  and the 0→75 repair check (`source/main.js`). The native truncating helpers
  and the 0→75 repair are unchanged. Values that had already drifted stay as
  saved; nothing is reset.

### 4. The lap timer kept counting during the results phase

- **Original:** at the finish, `0x440dd0` calls `0x440c30` (which restarts
  lap timer 0) and then `0x440d70`. `0x440d70` pauses race timer 3 through
  `0x4356a0`/`0x42a280` and pauses timer 0 (`0x440d77`, `0x440d9c`). The HUD
  update `0x46ecc0` formats timer 0, so after the lap hold the lap-time
  string shows the paused, roughly zero timer.
- **Port before:** `race-hud.js` showed `elapsedMs − lapStartMs`, derived from
  the still-running race clock, so the value climbed during phase 3.
- **Change:** `source/race-simulation.js` pauses timer 0 in the port's timer
  bank on the `finished` event and publishes `race.lapTimerMs` from that
  timer after each update; `source/race-hud.js` displays it. The race clock
  (timer 3 in the port) is not paused, because the timed-race countdown
  display is derived from it; the finish time itself was already fixed in
  `raceTimeMs`. The countdown timer 18 and the result gates are unchanged.
- **Follow-up, pauses during the results:** the original game pause
  `0x42f350` pauses its 22 timers with `0x42a2f0` (skipping paused ones) and
  resumes all of them with `0x42a420`, which also ends an earlier pause such
  as the finish pause. `0x42f9c0` makes that unreachable after the finish: it
  sets the P pause only outside phases 3 and 6 and the Escape requester only
  outside phases 1, 3 and 6, so the lap time stays frozen. The port already
  gates P and Escape the same way, but its own host suspensions (focus loss,
  leaving to a menu) reused the native resume and restarted the lap timer.
  `NativeGameTimers.pauseHost`/`resumeTimers` now pause only running timers
  and resume exactly those; `RaceSimulation.pause` uses the native
  `pauseGame`/`resumeGame` only for the P/Escape pause
  (`nativePause` from `main.js` through `driving-view.js`). A focus loss in
  phase 0 also no longer ends an earlier native pause, such as an opponent's
  finish timer.

### 5. The player's waypoint was chosen after the ground update

- **Original:** `0x491d30` updates the sector (`0x49212d` → `0x4932e0`),
  selects the waypoint and occupancy (`0x49215c` → `0x4937e0`) and then runs
  the object callback (`0x492165` → `0x4936a0`). For the player that callback
  is ground placement `0x416650` (installed at `0x431ae6` in `0x4319f0`).
- **Port before:** `RaceSimulation` inserted the player into the waypoint
  occupancy after `NativePlayerMotion.integrate` had already updated the
  ground height. The opponent path was already in native order.
- **Change:** `NativePlayerMotion.integrate` (`source/simulation/native-motion.js`)
  removes and inserts the player itself, after the sector update and before
  the ground update, like `NativeAIDriver.integrate`. The free-flight, rescue
  and recovery inserts are unchanged.
- **Effect:** only when two candidate waypoints are nearly equidistant and
  the ground update changes the height enough to flip the choice.

### 6. Keyboard input rounded once in double precision

- **Original:** keyboard `0x433870` and digital joystick `0x433cf0` use
  single-precision constants (70, 40, 0.01f at `0x4d2480`, 1, 200, 400; read
  from the binary) and store the steering gain as a float (`0x433b42`).
- **Port before:** `updateNativeInput` used a double 0.01 and rounded once at
  the end. Against the 1,600 instruction-emulation frames in
  `evidence/gameplay/native-fixtures.json` (24-bit control word), the old law
  differed exactly on 58 throttle and 296 steering frames, by at most
  7.6e-6, hidden by the fixture's 3e-5 tolerance.
- **Change:** `source/simulation/native-input.js` rounds every operation to
  single precision, matching the documented 24-bit x87 mode. All 1,600 frames
  now match exactly. Centring writes a plain 0 instead of −0.

## Confirmed differences initially left unchanged

These were recorded during the first pass. Items 7–10 below later corrected
the first four; only the damage item remains, because it has no effect.

- **Random draw when the player object is created** (`0x435a30` →
  `0x4356f0` → `0x40c790`): the port did not consume it. The first-pass
  note that this was unobservable was too broad; see item 8.
- **AI forced-route counter** (`0x40d5c0`) uses the profile efficiency field;
  the port used `6 − drivingStyle`. See item 10.
- **Opponent result estimates** used progress from one update earlier
  (`0x417d00`). See item 9.
- **`PLAYER.damage` carry-over:** unchanged. Race.ini sets the value at load
  (`0x4354a0`) and it can only decrease afterwards (`0x435640`); the
  collision increment is a single `RET`. It therefore stays 0 in both games.
- **Intro skip keys** (`rcskmenu.dat` `0x479cd4`): see item 7.

## Follow-up corrections after 1.0.1

### 7. Intro skip keys

- **Original:** `TfrmIntro` (`rcskmenu.dat`) has `KeyPreview` and only
  `OnKeyPress` (`0x479cd4`) and `OnMouseDown` (`0x479cec`), both of which close
  the intro. Windows sends key presses only for keys that type a character
  (WM_CHAR): letters, digits, Space, Enter, Escape and Backspace. Arrow keys
  type nothing, and Alt combinations arrive as WM_SYSCHAR instead. The Alt
  and AltGr behaviour is standard Windows/Delphi handling, not traced in the
  original code.
- **Port before:** keyboard arrow keys skipped the intro through
  `input.js` → `menuKey`; Backspace did not skip and Alt+letter did.
- **Change:** `nativeIntroSkipKey` in `source/input.js` applies the
  typed-character rule (AltGr still types). `menuKey` in `source/main.js` now
  learns whether a menu key came from the keyboard or a controller and leaves
  keyboard skips to that rule. Controller, mouse and touch skipping are
  unchanged adaptations. Tab still does not skip; whether it types under the
  original form's dialog-key handling is unverified. Escape also keeps its
  separate path through `back()`.

### 8. Missing random draw when the player record is created

- **Original:** `0x435a30` creates the player record on first use. Its
  constructor `0x4356f0` calls `0x40c790`, which marks the hit record
  inactive and stores `rand()%7`. A hit (`0x40c820`) replaces the whole
  record, so only the draw matters. `0x42f930` (`srand(GetTickCount())`,
  called once from `0x4432a0` before the main loop) runs first, so the draw
  always shifts the race's random stream.
- **First caller:** the frame routine `0x42f4c0` calls the bonus update
  `0x451200` every frame, including during the countdown. For each active
  pickup, `0x4540c0` calls eligibility `0x410650` for each racer before the
  overlap test, so in races with pickups the record is created on the first
  frame. Time trials enable no pickups; there the first caller is the player
  callback `0x4325b0` at `0x432f30`, inside the movement-active branch after
  forces `0x414160` and the wheel pass `0x41c0b0`, just before the hit effect
  `0x435c30`. The other callers cannot come first in the shipped modes:
  `0x40cde0` only reaches it when an opponent holds an item (`0x452370`),
  `0x455b00` needs a projectile, and `0x429a90` handles developer keys.
- **Port before:** no draw.
- **Change:** `RaceSimulation.createPlayerRecord` draws once, guarded by the
  data flag `playerRecordCreated`. It runs from a hook that
  `NativeBonusPickups.step` calls when its loop reaches the player (before
  the port's soft-lock checks, as 0x410650 always runs), and before the
  player's `combat.prepareEffect`. The isolated pickup class makes no draw
  of its own, so its instruction fixtures are unchanged.
- **Effect:** no visible change in normal play, because the port seeds from
  the clock. Fixed-seed runs follow a different random stream from the first
  frame (pickup races) or the green light (time trials).

### 9. Opponent result estimates used old progress

- **Original:** `0x417d00` reads each opponent's live progress after the last
  update's callbacks.
- **Port before:** `RaceSimulation.resultPatch` used the rank-state copies,
  taken before that update's opponent progress.
- **Change:** unfinished opponents' distances are refreshed from their live
  progress before the estimate. Only the saved opponent times in RACERS
  change; the debrief reads ranks only.

### 10. AI forced-route counter read the wrong profile field

- **Original:** `0x40e000` returns `6 − [profile+0x8]`. The profile array at
  `0x505930` has 0x18-byte records; `0x40fe50` stores `bonus_awareness`,
  `driving_style` and `efficiency` levels at +0x0, +0x4 and +0x8.
- **Port before:** `6 − drivingStyle`.
- **Change:** `nativeAIProfile` also keeps the raw `efficiencyLevel`, and
  `applyNativeAITrigger` uses it. The existing instruction fixture already
  wrote its value to `+0x8` (`0x505938`) under the label `drivingStyle`; the
  test now passes it as `efficiencyLevel`. No shipped track has markers 64/65,
  so play is unaffected.

### Follow-up validation

- `npm run bundle` regenerated `src/`.
- New tests: `tests/intro-skip-keys.test.mjs`, `tests/native-player-record.test.mjs`
  (one draw, from the pickup check during the countdown in race types 0, 2
  and 3; from the first active update before the hit effect in time trials),
  a live-progress estimate test in `tests/race-simulation.test.mjs` and a
  profile-field test in `tests/native-race-setup.test.mjs`.
- One run of the edited tests, the bundle check and every full-simulation or
  pickup test: 171 tests, 170 passed. The failure was the France time-trial
  scenario in `tests/private-race-snapshot.test.mjs`: with fixed seed 6 and
  the shifted stream, its scripted test bot ran out of time at sector 46 and
  never reached the train and jump windows it checks. All its clone
  comparisons that ran still matched. Of the first 40 seeds, 22 reach both
  windows; the test now uses seed 0, and its file passes (7 tests). This is
  a test-bot scenario, not evidence about the original deadline.
- Browser checks: see [browser validation](#browser-validation).

## Second comparison pass

A later read-only pass re-derived the areas the first pass took from existing
fixtures: weather (`0x4818c0`, `0x482020`), jet streams (`0x488b40`,
`0x48a530`), explosions (`0x481ec0`, `0x483fc0`, `0x484270`), the rescue
queue, the kart sweep/contact routines (`0x499c30`, `0x492470`, `0x49c220`,
`0x49b9c0`), start camera and countdown order, and Adventure progression,
unlocks and the profile bank in `rcskmenu.dat`. Weather, streams, explosions,
start/countdown order and the sweep/contact routines showed no reachable
difference. The six approved corrections follow.

### 11. Escape on the result screen discarded the result

- **Original:** `TfrmDebrief` (`rcskmenu.dat`) has only `OnClick` and `OnShow`
  handlers. Its Back button `0x471b8c` processes the result through
  `0x471bc0` (progression `0x472cfc`, unlock `0x472fe0`, highscore
  `0x471c70`, win movie `0x473158`, save `0x457b34`), like OK.
- **Port before:** keyboard Escape and controller B/Start fell through
  `back()` to `showMain()`. No qualification, unlock, highscore or save
  happened, so the event had to be driven again.
- **Change:** `back()` in `source/main.js` runs the debrief's Back action
  (`debriefBack`), which the button now also uses.

### 12. Back in Adventure character selection

- **Original:** `rcskmenu.dat 0x473c8d..0x473c9f` enables `TfrmSelectChar`
  field `+0x2e4` (`btnBack`) only in shell state 2 (QuickRace). A new
  Adventure profile leaves this form only through OK or Stop.
- **Port before:** Back and Escape returned to Adventure main.
- **Change:** `showCharacters` disables `btnBack` in Adventure, and `back()`
  ignores Escape there. QuickRace is unchanged.

### 13. Adventure main remembered the browsed profile

- **Original:** `[shell] lastplayer` is written by OK (`rcskmenu.dat
  0x4755d9`), New player (`0x476175`), Delete (`0x476093`) and the
  provisional delete (`0x4740e0`). Left/Right (`0x475e90`/`0x475ec0`) change
  only the form slot; re-entering seeds it from `lastplayer`
  (`0x475422..0x475430`).
- **Port before:** each Left/Right saved `raceSave.selectedSlot`.
- **Change:** `showAdventure` keeps a transient form slot. OK saves it,
  New and Delete save their new selection, and Delete and New use the browsed
  profile. The save format is unchanged; browsing alone no longer writes.

### 14. Rescue queue order

- **Original:** `0x48dce0` and `0x48dc30` insert new rescues at `begin()`
  (`0x48dd51`, `0x48dca1`), and `0x48db00` updates from the front, so the
  newest rescue updates first.
- **Port before:** `NativeRescueController.enqueue` appended.
- **Change:** `enqueue` prepends. Effect: when two racers reach one return
  marker on the same tick, the newer rescue takes it, and same-tick
  DISAPP/REAPP voices are queued newest first.

### 15. Rescue retirement

- **Original:** `0x48db30` loops over the original count (`[ESP+0x14]`),
  including stale slots past the shrinking end. Each finished slot is
  overwritten with `back()` without being re-checked. Two rescues that finish
  on the same tick are both removed. On a stale slot it also copies `back()`
  when that is a different entry, which can drop an unfinished rescue with its
  stuck flag still set.
- **Port before:** `finishRender` skipped stale slots, so the second of two
  finished rescues stayed one more tick.
- **Change:** `finishRender` walks the same slots. As approved, a stale slot
  retires only its own entry, so the port never drops an unfinished rescue.

### 16. Homing arm on a racer under rescue

- **Original:** the rescue scales the shared render-object matrix in place
  (`0x48cc4e..0x48cc7f`, `0x48d283..0x48d2b4`) before the arm update
  (`0x42f618` before `0x42f648`), and `0x486ea0` copies that matrix
  (`0x486ec0..0x486efb`).
- **Port before:** the arm used the unscaled body matrix.
- **Change:** `RaceSimulation` passes the rescue render pose to
  `NativeHomingArms.step`, as it already did for the streams. Visual only.

### 17. `0x49b9c0` impulse rationale (comment and doc only)

- **Original:** the impulse's Y term multiplies an unwritten stack slot (the
  rotated normal's Y, read at `0x49bea9`) by a relative Y built from two
  unwritten velocity slots (`0x49bd3b`, `0x49bdca`). The record normal's Y only
  reaches the unused lever Y. Called from `0x491d30`, the slot holds the low
  dword of the floor result left by `0x4911a0` (`__frnd` `FSTP` at
  `0x4c8566`, the same stack address), which is zero below 2²¹ heading units.
- **Port before:** the behaviour was already equivalent, but the comment in
  `native-kart-contact.js` and `research-kart-collision.md` said the term was
  zero because the collision normals are planar.
- **Change:** both texts now give the actual reason. The arithmetic is
  unchanged.

### 18. The sine/cosine table was built at 24-bit precision

- **Original:** the CRT selects 53-bit precision at startup: `_cinit` calls
  `_FPinit` `0x4be597` (computed call at `0x4c0238`, pointer at `0x50296c`),
  which calls `0x4c17bc` = `_controlfp(_PC_53, _MCW_PC)`. No game code writes
  the control word; every `FLDCW` belongs to CRT helpers that restore it.
  `0x4ac410` builds the table with `0x4a1510` (`0x4ac425`, its only caller)
  before it creates the Direct3D device (`0x4aace0`/`0x4aacd0` →
  `0x4ab5c0`/`0x4ab460`, called at `0x4ac497`/`0x4ac4a2`). `0x4a1510`
  computes `(i/count)·2π_f` with `FDIVR`/`FMUL`, which precision control
  affects, then `FSIN`/`FCOS`, stored as floats. The table therefore uses the
  unrounded 53-bit angle. The game uses only DirectX 5 interfaces (IID
  `IDirectDraw2` `0x4d34c0`, `IDirect3D2` `0x4d4110`) and passes no FPU flag to
  `SetCooperativeLevel` (`0x4b171c`; `0x11`|`0x40` from `0x429233`, or `0x8`
  windowed at `0x4b1587`). Whether gameplay then runs at 24-bit is a separate
  question; see [gameplay precision](#gameplay-precision-runtime-check).
- **Port before:** `nativeTrigTable(24)` rounded the angle product to float,
  which reproduces a table the game only builds at 24-bit. Emulating
  `0x4a1510` showed the 53-bit table equals the exact-angle law in all 8,192
  entries; the two tables differ in 4,615 entries by one float step (up to
  2.4×10⁻⁷). The instruction fixtures had the same table, because the probe
  ran the initializer under each case's control word.
- **Change:** `nativeTrigTable` in `source/simulation/native-integrator.js`
  builds one table from the exact angle for both precisions.
  `initialize_native_trig` in `tools/native_probe_math.py` runs `0x4a1510` at
  `0x027f` and then restores the case's control word. `native-hud-portrait`
  had also built its table once at 24-bit for its 53-bit cases.
- **Effect:** a last-bit change in every 24-bit rotation, through all 22 port
  modules that read the table.
- **Fixtures:** before the change, all 33 generators that call
  `initialize_native_trig` reproduced the committed fixtures byte for byte.
  After it, 24 fixture files changed, with only numeric values changing (no
  structure or text). The changes are last-bit except in the multi-frame
  replays (`native-player-recurrence.json`,
  `france-native-frame-fixtures.json`), where they accumulate.

### Gameplay precision (runtime check)

The port runs its simulation at 24-bit on the assumption that the Direct3D
device switches the game to single precision. This check found the opposite.

- **Runtime:** a reflinked copy of the earlier Wine prefix and disc (ignored
  `work/dgvoodoo-fpu/`, original installation untouched) ran `rcskspel.dat`
  under Wine 11.20 Staging (WoW64) and Xvfb. The main thread's x87 control
  word was read with `ptrace` (`PTRACE_GETFPREGS`) while it executed game code
  in a running race (frame counter `0x53bab8` advancing, phase `0x53b9c0` = 0):
  - dgVoodoo2 2.87.5 (fixed `MS/x86` `DDraw.dll`/`D3DImm.dll`) with DXVK
    2.6.2: 300 samples, all `0x027F`, 46 at `0x44331d` in the frame wait;
    the race rendered.
  - dgVoodoo2 with Wine's D3D11: 200 samples, `0x027F` (black output).
  - Wine's built-in DirectDraw: 200 samples, `0x027F`; the race rendered.
  - Writing `0x007F` into that word while it was in game code kept `0x007F`
    across seconds of frames, so Wine's WoW64 preserves the game's control
    word and these readings are not an artefact of Wine.
  - Neither environment emulates a lasting switch: dgVoodoo's `DDraw.dll`
    sets 53-bit for its own work and restores the caller's word, and every
    `fldcw` in Wine's `ddraw.dll` is in the Direct3D 7 FPU-preserve wrappers.
- **Microsoft's runtime (static):** the disc's `DXSetup/DirectX.cab` holds
  DirectX 7.0 (`ddraw.dll`/`d3dim.dll` 4.07.00.0700). Its SetCooperativeLevel
  maps DDSCL_FPUSETUP to local flag `0x8000` (`0xbaac6ea5..0xbaac6eaa`) and
  DDSCL_FPUPRESERVE to `0x80000` (`0xbaac6eae..0xbaac6eb3`). In `d3dim.dll`
  the only unrestored single-precision write is in device creation
  (`0x5666476c..0x56664793`) and requires that FPUSETUP flag. The other five
  sites switch only for the duration of a Direct3D call and restore the
  caller's word (guard `0x56678310`; functions `0x56698400`, `0x566a81a0`,
  `0x566a8810`; rasterizer pair `0x566bb902`/`0x566bb935`). RedCat passes no
  FPU flag.
- **Conclusion:** with the DirectX 7 runtime shipped on the disc, the game's
  own arithmetic most likely runs at the CRT's 53-bit precision, not 24-bit.
  Not established: older DirectX 5/6 runtimes, drivers that change the control
  word outside these guards, and an observation on real Windows.
- **Switched:** the port now defaults to 53-bit; see
  [phase 2](#53-bit-switch-phase-2-precision-options) for the exact 53-bit
  paths and [phase 3](#53-bit-switch-phase-3-default-switched) for the
  switch. Item 18's table is 53-bit either way.

### 53-bit switch, phase 1: fixtures and audit

No game behaviour changed. The eight generators whose fixtures were 24-bit
only (`generate_native_gameplay_fixtures.py`, `generate_native_ground_fixtures.py`,
`native-player-recurrence-fixtures.py`, `generate_native_projectile_fixtures.py`,
`generate_native_effect_fixtures.py`, `generate_native_bonus_fixtures.py`,
`generate_native_track_fixtures.py`, `native-player-phase-fixtures.py`) accept
`RCSK_FIXTURE_PRECISION=53`. The probe then starts at control word `0x027f` and
writes a sibling `*-53.json` from the same inputs. Their default output is
byte-identical to before, and no test reads the new files yet. Pass the
variable through the host wrapper explicitly, for example
`distrobox-host-exec env RCSK_FIXTURE_PRECISION=53 re-python tools/<generator>.py`.

Zero-tolerance audit (outputs that differ between each 24-bit fixture and
its 53-bit sibling with identical inputs, or port results compared exactly):

| Routine | 24-bit port | 53-bit difference |
| --- | --- | --- |
| Input `0x433870` (item 6) | exact | 148 steering and 22 throttle frames of 1,600 |
| Forces/player `0x414ff0`–`0x415990` | exact | 699 force/RPM values in 120 cases; player phase 777 values |
| Ground `0x416650` | exact | 4,639 values, including contact flips |
| Player recurrence `0x415990`+`0x4911a0` | exact | 19,070 values (accumulated) |
| Projectiles `0x455ce0` | exact | 90 values |
| Bonus effects | exact | 212 values |
| Bonus pickups | exact | none |
| Track sectors/heights | sectors exact; height inexact (below) | 2,418 values |
| Kart contact `0x49b9c0` | exact | port 53-bit path inexact in 135 of 240 cases |
| Kart sweeps, live contact, scenery contact, cadence, HUD portraits | exact | port 53-bit path exact |
| Scenery-path heading | 125 of 525 inexact (within 0.0005) | port exact |

Found by the audit, independent of the precision switch:

- **Track height** (`sampleNativeTrack`, `native-track.js:122`): 490 of 960
  24-bit cases differ by up to 5.6×10⁻⁴ world units. The test's 0.01
  tolerance covers it. The fixture supplies triangle planes as inputs and the
  native plane initializer is not emulated, so the port's own plane
  construction differs. This height is the ground sampler for the player,
  opponents, projectiles and recovery. Resolved: see [follow-up fixes after phase 3](#follow-up-fixes-after-phase-3).
- **Frame-delta filter** (`NativeDeltaFilter`, `0x48f4e0`): returns the
  unrounded double where the original returns its stored float; every
  difference disappears after `Math.fround` (at most 0.2 float steps).
  Resolved: see [follow-up fixes after phase 3](#follow-up-fixes-after-phase-3).

### 53-bit switch, phase 2: precision options

The default is still `precision: 24`, and no caller passes another value yet,
so play is unchanged. Each core module now accepts `precision: 53`. Values the
original keeps on the x87 stack then round to double, and values it stores
with `FSTP`/`FST float` keep `Math.fround`. Every new expression reduces to
the old one at 24. All addresses are in `rcskspel.dat`.

| Module | Routines | 53-bit result |
| --- | --- | --- |
| `native-input.js` | `0x433870` | 1,600 of 1,600 frames exact |
| `native-forces.js`, `native-player.js` | `0x414ff0`–`0x415990`, `0x415840`, `0x4914d0` | 120 force, 120 player and 720 phase cases, and 2,400 recurrence frames, exact |
| `native-ground.js` | `0x416650`, `0x41c0b0`, `0x4a25f0` | 160 callbacks, 160 wheel poses and 4×80 trace frames exact |
| `native-track.js`, `native-start.js` | `0x495cb0`, `0x4977d0`, `0x495ed0`, `0x496290`, `0x493540` | 1,092 sector axes and fallback planes, 960 selections and 18 start yaws exact; heights see below |
| `native-projectile.js`, `native-bonus-effects.js` | `0x455490`, `0x455ce0`, `0x4560c0`, `0x415be0`, `0x412390`, `0x413330` | 480 flight, 180 launch and 600 effect cases exact |
| `native-kart-contact.js` | `0x49b9c0` | 240 of 240 exact at both precisions (was 105 of 240 at 53) |
| `native-collision.js` | `0x49a750`, `0x499c30` | sweep fixtures still exact at both precisions |
| `native-rescue.js` | `0x48c170` | new clearance case exact at both precisions |

Play at 24-bit is unchanged:

- **Differential check:** this used a scratch copy of `source/` with only the
  phase 2 edits reverted. It and the current source ran the same 18 headless
  `RaceSimulation` races: six tracks, QuickRace at two difficulties and race
  type 2, 4,800 updates each with scripted steering, braking and bonus use.
  The whole simulation state, without the shared assets, was hashed after
  every update.
- **Result:** all 86,400 hashes and the derived track are identical, with no
  errors.
- **Coverage:** in copies that switch one module's default to 53, the same
  races diverge for input (update 318), ground, track and collision (update
  0), player (315), projectiles (660), effects (966) and rescue (3,366). The
  forces, kart contact and start yaw rows do not diverge on their own:
  `native-player.js` and `NativeRailCollision` pass `precision` explicitly,
  and the stored start yaw is identical on that track.

Register values that were missing at 53-bit:

- **Input `0x433870`:** `dt·70 + throttle` and `dt·40 + brake` stay in ST0
  until `FSTP float` and `__ftol`. So do the steering ramp
  (`0x433b9f`/`0x433c2e`) and the decay. The clamps compare ST0, which orders
  like the stored float. The gain at `0x433b42` is stored.
- **Kart contact `0x49b9c0`:** the mass sum (`0x49bec5`), both impulse
  products (`0x49bef4`, `0x49bf2d`), the second component of A's
  velocity change (`0x49c03b`) and of B's rotated normal (`0x49c190`). A fifth,
  not in the phase 1 list, is B's angular term: it stays in ST0 from
  `0x49bf5e` through its clamp and the yaw update (`0x49c0eb`), while A's
  term is stored (`0x49bf5a`).
- **Sweeps:** `0x49a750` compares the quotient in ST0 and rounds it only on
  store. `0x499ffc`/`0x49a009` pass the yaw delta to `ceil`/`floor` as a
  double, and `0x499f9f` stores `z·amount` as a float before the add.
- **Rescue clearance `0x48c170`:** dx is stored (`0x48c261`) and dz stays in
  ST0 (`0x48c2af..0x48c2b8`).
- The full lists for forces, ground, track, projectiles and effects are in
  the comments next to each expression.

Fixture changes (generators only, `original-source/` untouched):

- `tools/native-rescue-fixtures.py` adds one clearance case queried from
  z = 0.1f, where dz is not a float. The original returns blocked at 24-bit
  and clear at 53-bit, and a float-rounded dz gives blocked at 53-bit. Only
  the two new `clearance` entries changed in `rescue-fixtures.json`.
- `tools/native-player-recurrence-fixtures.py` reproduced the outer planar
  quantization in Python with float products at both precisions. It now runs
  the original instructions `0x491e1c..0x491e72` (speed·10000, `__ftol`,
  ·0.0001, `FSTP float`). The 24-bit fixture's 2,400 frames are unchanged.
  In the 53-bit fixture, 2,092 frames changed: the first change is a 10⁻⁴
  step and later frames follow from it. The port's
  `quantizeNativePlanarVelocity(body, 53)` matches it exactly.

Found during phase 2 and left unchanged:

- **Track height at 24-bit (cause of the 490 differences above):** two
  port-side roundings differ from the original under PC=24.
  - `nativePlaneHeight` rounds once at the end, but `0x496290` rounds each
    `FMUL`/`FSUBR`/`FMUL`/`FSUBP`/`FDIV`. With the fixture's own triangle
    planes, the current form is inexact in 475 of 849 triangle cases, and
    per-step rounding is exact in all 849.
  - The fallback plane (`0x495cb0`): the cross product does not round each
    product (`0x495dcc..0x495e0c`), and the distance adds X, Y, Z where
    `0x495e57..0x495e6c` adds Z, Y, X. As a result, 83 normals and 134
    distances differ.

  A scratch copy with both fixed matches all 1,092 fallback planes and all
  fallback heights, and leaves 279 of 960 heights inexact, all on triangles.
  Those 279 cannot be judged yet. The fixture's triangle planes come from the
  generator's Python `plane()`, not from the original's `0x494f40`, which is
  not emulated and keeps normal.z in ST0 for the length (`FST` at
  `0x495190`). Both fixes change 24-bit results, so they need separate
  approval. At 53-bit, `nativePlaneHeight` already rounds each step, and the
  346 remaining height differences (up to 3.6×10⁻⁴) are triangle cases of
  the same plane question. Resolved: see [follow-up fixes after phase 3](#follow-up-fixes-after-phase-3).
- **Transcendentals:** `FSIN`/`FCOS`/`FPATAN` return extended results and
  the port uses JavaScript's double functions. One rear-axle slip angle
  differs from `Math.atan` by one double ULP at both precisions. The test
  allows 10⁻¹⁵ there, and the float stores at `0x415388`/`0x4153b4` hide
  it. The 53-bit start yaw (`0x493540`) is exact in all 18 cases only
  because of its float store.
- **Delta filter:** `NativeDeltaFilter` is used only by tests. The live
  `NativeEngineTimer` already had a 53-bit path and returns the float 0.1
  (`0x4d2270`), and `0x48f3e0` stores every partial sum as a float.
- **Inputs needed when the race switches (phase 3):** at 53-bit the tyre load
  (`0x4150f0`) uses `body.mass` directly, so it must hold the double
  `1/inverseMass`. `sampleNativeTrack` returns its height unrounded, as
  `0x496290` does, so callers that store it must round it themselves. The
  projectile hit test `nativeBonusOverlap` and the projectile matrix rebuild
  in `native-transform.js` have no 53-bit fixture. `native-motion.js`,
  `native-ai-driver.js`, `native-combat.js` and `race-simulation.js` do not
  pass `precision` yet.

Phase 2 validation:

- **Node:** the five new `*-precision.test.mjs` files, the tightened
  kart-contact and rescue tests, and every other test file that imports a
  changed module, the race clock or `race-simulation.js`. That is 75 files and
  343 tests; all passed.
- **Bundle:** `npm run bundle` regenerated `src/` and `runtime-manifest.json`.
  The bundle, server, Electron and display runtime tests (21) and
  `bundle-browser.mjs` (`RCSK_BUNDLE_TRACKS=2`) passed. The evidence file
  that test writes was restored.

### 53-bit switch, phase 3: default switched

The game now runs its native arithmetic at 53-bit. A shared constant,
`NATIVE_PRECISION` in `source/simulation/native-precision.js` (53), replaces
the literal default 24 in every module that takes a `precision` option (59
files import it). Tests that compare with 24-bit fixtures pass
`precision: 24` explicitly. All addresses are in `rcskspel.dat`.

Remaining modules given a 53-bit path, each exact against new 24- and 53-bit
fixtures (`tools/native-race-precision-fixtures.py`,
`evidence/gameplay/native-race-precision-fixtures{,-53}.json`) unless noted:

- **AI driver:** the route plane height `0x494b70` stays in ST0 and is
  returned there; its callers store it (`0x41346e`) or subtract in the
  register (`0x41c72f`). The turbo and hit-flash timers compare `now − start`
  from ST0 (`0x40e7a2..0x40e7b8`, `0x40ea84..0x40eaa3`). The driver now
  passes its precision to every callee.
- **Grid heading of opponents:** `0x415f90` calls the same `0x493540` as the
  player (`0x416184`), so `native-race-setup.js` mirrors `native-start.js`.
- **Kart body:** the inverse inertia `0x48fda0` stays in registers from
  `0x48fdfa` to its `FSTP` at `0x48fe1e`. At 53-bit it is
  0.0008643041946925223 instead of 0.0008643042529001832; 1/mass is one stored
  `FDIV` (`0x48fdf4`).
- **Bonus overlap** `0x497bd0`/`0x44fc80`: nothing is stored before `FCOMPP`
  (`0x497c46..0x497c86`, `0x44fd97..0x44fdd2`). Static pickup rotation keeps
  speed·dt in ST0 (`0x45410b..0x454115`).
- **HUD text layout** (`0x45a6b0`, `0x4631d0`, `0x4632c0`, `0x463400`):
  distance + cell width, width·ratio and distance·ratio stay in ST0. 487 of
  3,276 glyph values were wrong at 53-bit and none now. `tools/native-hud-fixtures.py`
  writes `hud-text-fixtures-53.json`; its 24-bit output is byte-identical.
- **Speed in km/h** (`0x432696..0x4326a6`): `__ftol` truncates the
  `FMUL 3.6f` product in ST0. Lateral km/h (`player-assets.js`) already did.
- **Dropped options:** four `native-ai.js` functions read `options.precision`
  without a default, and `advanceNativeProjectile` called the overlap test
  without precision. Both now follow the shared default.
- **Precision-independent from the assembly** (each a single operation
  stored at once, or integer-only): ranks `0x406be0`, jump `0x441d27..0x441d43`,
  sector time `0x40968e`, 0.98 damping `0x40b417..0x40b442`, turbo
  `0x45384d`/`0x453887`, pickup cooldown, age and loader.
- **Audited at zero tolerance, already exact at both precisions:** spatial
  audio, HUD meshes and string contexts, star HUD, kart shadow, camera path
  ticks and the engine timer.

End-to-end check: `tools/native-blockage-france-check.mjs` replays the
composed original `0x491d30` blocked-pair probe (discovery, sweep and slide,
player substeps, NPC integration, paired contact). At 53-bit it had 1,101
differences against the original's 256 frames before phase 2 and now has
none; the 24-bit frames stay exact. The tool now judges the active precision
by `NATIVE_PRECISION` and the regenerated
`france-native-frame-comparison.json` is kept.

Tests changed for the switch (no game rule, deadline or geometry changed):

- **24-bit fixture tests pinned:** `simulation-native`, `simulation-ground`,
  `simulation-projectile`, `simulation-effects`, `simulation-track`,
  `native-player-phase`, `native-player-recurrence`, `native-race-setup` and
  the host-seconds case of `native-engine-timer`. At 53-bit the timer keeps
  a residue between the stored float baseline and the next double quotient,
  as the original does; its fixture traces cover that.
- **Default tests:** the ground, player and track precision tests now check
  that the default follows `NATIVE_PRECISION`.
- **Port capture:** `npc-velocity-safety` replays a history the port recorded
  at 24-bit, so it passes 24.
- **Start camera:** `race-simulation` asserted a positive speed 20 s after a
  straight-steering start; at both precisions the kart is pinned against
  scenery by then (0.77 at 24, −0.03 at 53). It now checks that the kart
  accelerated after green.

Found during phase 3 and left unchanged:

- **Degree-to-angle conversion, at both precisions:** `0x43e140`
  (`0x43e283..0x43e2ad`) multiplies by 4096 × f32(1/360) held in ST0, one
  `FMUL` and `FSTP`. `world.js:170`, `scenery-paths.js:104` and
  `nativeTrackPickups` divide by 360 instead, so 433 of 4,857 placement
  angles and 50 pickup yaws are one ULP off. Not a precision question; it
  changes placement angles, so it needs separate approval. The scenery
  reactions, hazards and contact modules already use the original factor.
  Resolved: see [follow-up fixes after phase 3](#follow-up-fixes-after-phase-3).
- **`NativeDeltaFilter`** (tests only) returns a double 0.1 where `0x48f4e0`
  loads the float at `0x4d2270` and `0x48f520` primes the history with
  `0x3dcccccd`. Making both floats makes every timing fixture exact. Test
  drivers feed it to `RaceSimulation`; the game uses `NativeEngineTimer`.
  Resolved: see [follow-up fixes after phase 3](#follow-up-fixes-after-phase-3).
- **Recurrence fixture input:** `native-player-recurrence-fixtures.py`
  builds the inverse inertia with 24-bit rounding for its 53-bit run too. The
  fixture is self-consistent but not the real 53-bit kart body. Resolved:
  see [remaining items closed](#remaining-items-closed-29-october-2026).
- **Not probed:** the first compare of the `0x41c4b0` suspension clamp
  (argued equivalent), and which ground sampler the bubble spring uses.
  Resolved: see [remaining items closed](#remaining-items-closed-29-october-2026).
- **Fixture caveat:** `hud-string-transform-fixtures.json` takes `scale` from
  the input and `parent` from a Python transcription. Resolved: see [remaining items closed](#remaining-items-closed-29-october-2026).

Phase 3 validation:

- **24-bit unchanged before the switch:** the phase 2 differential (18
  races, 86,400 updates) was repeated with the phase 3 code and the constant
  still at 24, against the pre-phase-2 copy. Every state hash matched,
  ignoring the new `precision` fields.
- **Node:** the full suite, `node --test tests/*.test.mjs`, passed 716 of 716
  at the 53-bit default. With the constant at 24 the same suite passed before
  the test updates (698 of 698).
- **Bundle:** `npm run bundle` regenerated `src/` and `runtime-manifest.json`
  (126 modules); the bundle, server, Electron and display runtime tests
  passed (21).
- **Browser** (Chrome for Testing 145.0.7632.6, headless): `driving-browser`,
  `quickrace-browser`, `bundle-browser` (`RCSK_BUNDLE_TRACKS=2`),
  `variable-cadence-browser`, `track-mirror-browser` and `camera-browser`
  passed. `player-recovery-browser` stopped with "Race time must be finite and
  monotonic" at 24-bit and 53-bit alike, and an exported copy of `71080ed3`
  failed the same way; see
  [browser harness: paused update loop](#browser-harness-paused-update-loop).
  Evidence files written by the browser tests were restored.

### Browser harness: paused update loop

Three browser tests failed because of how they drove the clock; the game
code was not at fault and is unchanged.

- **Synthetic tick times:** `player-recovery-browser.mjs` paused the clock,
  then called `view.onTick` with times counted from `clock.tick*25`. The
  update gate (`0x4432a0`, `NativeUpdateClock`) passes its real elapsed active
  time, which runs ahead of `tick*25` whenever a live update came late, so the
  synthetic time could fall behind the race time already set and
  `NativeRace.setTime` threw. The test now continues from
  `clock.simulationMs`. `animation`, `bubble-shells`, `free-flight`,
  `streams-squash`, `weather` and `streams-render` used the same start and
  passed only when the page paused early; they now use it too.
- **Resuming the live loop:** `NativeUpdateLoop` stops itself on its next
  wake once it sees the clock paused. These tests paused with
  `clock.pause()` and resumed with `clock.resume()`, which unpaused the clock
  but never re-armed the loop, so no update ran afterwards. That is why
  `player-recovery-browser` then timed out waiting for the stuck-kart timer,
  and why `environment-rescue-browser` and `player-rescue-safety-browser`
  timed out waiting for the REAPP voice (second-pass validation below). They
  now resume with `updateLoop.start()`, which resumes the clock and re-arms
  the loop in either state.
- **Result:** those three tests pass (4, 3 and 4 checks, including the real
  DISAPP/REAPP voice starts), and all 13 browser tests that call `onTick` pass.

### Follow-up fixes after phase 3

Approved after phase 3. All addresses are in `rcskspel.dat`.

**Track planes and heights** (`native-track.js`):
- **Triangle planes:** `0x494f40`, called once per sector through
  `0x4948c0` → `0x494d20`, builds the road, land and extra planes from the
  RMP tiles loaded by `0x49cc90`. Four vertices per tile, triangles (c0,c1,c2)
  and (c3,c4,c5). The port's `etappe*.json` vertices are those tile vertices
  in that order.
  - **Stored as floats:** five edge differences (`0x495094..0x495132`), n.x
    and n.y, the normalised components and the distance partials.
  - **Kept in ST0:** c.z − a.z (`0x49514b`) and n.z, which is stored by `FST`
    at `0x495190` while its register value feeds the length and division.
  - **Distance order:** y, z, x for road and land (`0x4951e7..0x49522f`),
    z, y, x for extra (`0x495bf0..0x495c3f`).

  `nativeTrianglePlane` now follows this at both precisions.
- **24-bit heights:** `nativePlaneHeight` rounds each step as all four
  `0x496290` branches do under PC=24. The fallback plane rounds each
  cross-product term (`0x495dcc..0x495e0c`) and adds the distance Z, Y, X
  (`0x495e57..0x495e6c`). The 53-bit expressions of both are unchanged.
- **Fixture:** `tools/generate_native_track_fixtures.py` now runs native
  `0x494f40` on the original `Etappe*.rmp` tiles instead of its Python
  `plane()`, and records all 52,516 planes per precision. Case inputs, sector
  axes, fallback planes, starts and selections are unchanged. Only
  `expected.height` moved: 330 cases at 24-bit, 137 at 53-bit.
- **Result:** planes 52,516 of 52,516, fallback planes 1,092 of 1,092,
  selections and all 960 heights are exact at both precisions (before: 490
  heights at 24-bit and 346 at 53-bit). The 0.01 height tolerance is gone.
  Zero-area triangles (876) get NaN planes natively, as in the port, and the
  sampler skips them because `0x496088` rejects an unordered comparison.

**Degree-to-angle conversion** (`nativePlacementAngle` in
`native-transform.js`):
- **Original:** the OMP loader `0x497070` copies each placement's float32
  rotation dwords into `0x43e140` (`0x497186..0x4971a9`). There, `0x43e283`
  loads the count 4096 (`0x4fc8f4`, set by `0x4a1510`) and multiplies it by
  f32(1/360) at `0x4d2468`. Each axis is then one `FMUL` and `FSTP float`,
  with `FCHS` on Y at `0x43e2a0`. The asset converter already writes Y
  negated, and negation commutes with rounding. Both products are exact, so
  24-bit and 53-bit agree.
- **Pickups:** `0x43ef69` → `0x4512b0` receives no angles; a pickup keeps the
  converted angles its object was created with (`0x48fc70`/`0x48fb60`).
- **Port changes:**
  - `world.js` changes 433 of 4,857 render angles.
  - `asset-animation.js` `createNativeRotation` changes 3 of 24 rotating
    start angles; this also covers the type-43 hazard in the simulation.
  - `scenery-paths.js` changes 4 of 28 path yaws.
  - `nativeTrackPickups` changes 50 of 180 pickup yaws.

  Each was one ULP. The reaction, hazard and contact modules were already
  right and now share the helper.
- **Fixture:** `tools/native-placement-angle-fixtures.py` runs the unmodified
  `0x497070` loop on the real OMP bytes of all six tracks at both control
  words. `tests/native-placement-angles.test.mjs` compares all 4,857 angles
  bit-exactly and checks the bodies, reactions, hazards, path objects and
  pickups of real `RaceSimulation` instances.

**`NativeDeltaFilter`** (`clock.js`, used by test drivers):
- **Change:** the history is primed with the float 0.1 (`0x48f590` stores
  `0x3dcccccd`) and the cap returns the float at `0x4d2270`; the comparison
  stays against the double at `0x4d2d98`.
- **Tests:** `native-clock` and `native-camera-clock` now compare exactly, the
  latter at both control words since `0x48f3e0` stores every partial sum.

**Test expectation:** the scripted France bot of `private-race-snapshot`
took a different path once heights moved (by at most about 0.001) and
reached 1 of its 3 windows. Its fixture seed went back from 0 to 6, the same
kind of change as after item 8. Seeds 2, 6, 7, 9, 11–17 and 22 pass every
assertion; 6 opens its jump window at 33,175 of 36,500 ms with 27 contact
callbacks inside windows. No game rule, deadline or geometry changed for it.

**Validation:**
- **Node:** the full suite passed 721 of 722 before the seed change, the one
  failure being that test, which then passed 7 of 7.
- **Bundle:** `npm run bundle` regenerated `src/`; the 21 runtime tests
  passed.
- **Browser:** `driving`, `quickrace`, `bundle` (`RCSK_BUNDLE_TRACKS=2`),
  `variable-cadence`, `track-mirror`, `camera`, `player-recovery`,
  `environment-rescue` and `player-rescue-safety` passed.
- **France blockage:** the comparison stayed byte-identical (512 of 512
  frames exact).
- **Evidence:** files written by the browser tests were restored.

### Remaining items closed (29 October 2026)

The open items from the second-pass proposal, the phase 3 loose ends and the
open questions. Addresses are `rcskspel.dat` unless another module is named.

**Rescue queue, run natively.**
- **Fixture:** `tools/native-rescue-queue-fixtures.py` executes the
  unchanged queue code at PC24 and PC53. That covers the enqueue entry
  points `0x48dce0`/`0x48dc30` with cap and duplicate scan, the insert
  `0x48de90` with reallocation, update `0x48db00` with `0x48ca60`, and
  retirement `0x48db30`. Only the heap, free, texture lookup and draw calls
  are stubbed.
- **Coverage:** 7 natural sequences (405 ticks) plus every finished or
  unfinished pattern for 1–10 entries (2,036 cases). In all: 4,477 ticks,
  38,864 updates and 9,269 retirements, 2,856 of them of stale slots.
  `tests/native-rescue-queue.test.mjs` compares order, update order,
  clearance order, phases and flags per tick.
- **Result:** the port matches. The one exception is the approved one:
  where `0x48db30` copies a live `back()` over a stale finished slot and so
  drops an unfinished rescue, the port keeps it. Natively that happens in
  real play too: player 2's return blocked once and player 1's twice, so
  player 1 is dropped at tick 41 with its stuck flag set; the port keeps it
  and finishes it at tick 44 with the flag cleared.
- **Fixed:** the cap of 10 is now tested before the duplicate scan, as in
  `0x48dce0`/`0x48dc30`. Only the return value for a duplicate in a full
  queue changes.

**Sweep and contact fixtures.**
- **Kart sweeps:** 780 cases, adding 90 zero-yaw-rate and 120
  rails-and-karts cases per precision.
- **Rails:** 400 cases, adding 100 cases of varied rail poses per
  precision. The old cases are byte-identical.
- **Tests:** kart sweep, live contact and scenery contact compare exactly at
  both precisions; all were already exact, and no port change was needed.

**Loose ends from phase 3.**
- **Recurrence fixture body:** `native-player-recurrence-fixtures.py` now
  takes the kart body from native `0x48fda0` at the run's precision. The
  24-bit file is byte-identical; the 53-bit inverse inertia is
  0.0008643041946925223, and all 2,400 frames still match.
- **Suspension clamp `0x41c4b0`:** 352 emulated cases (`0x41c70a..0x41c767`)
  around 0 and −1.11f match at both precisions. A NaN difference natively
  stores −1.11f (unordered at `0x41c752`), and `updateNativeAIWheels` now
  does too.
- **AI vertical spring:** `updateNativeAIVerticalSpring` now stores vx/vz as
  floats (`0x4133c6`/`0x4133df`).
- **Bubble spring `0x413330`** (player and NPC through `0x412560`):
  - **Wrong sampler:** it samples the route plane `0x494b70` after the
    sector search `0x4977d0` from the body's sector hint (`0x41343b`,
    `0x41345f`) and stores the height (`0x41346e`). The port used the
    projectile's track-triangle sampler; combat now passes
    `nativeRouteSpringHeight`.
  - **Player slip reset:** if the stored height + 2.0 is below the entry Y,
    the player's slip magnitude `[0x50728c]` is cleared
    (`0x4134a7..0x4134c4`); the port now does the same through `clearSlip`.
  - **Evidence:** 144 emulated cases, player and NPC.
- **HUD string transforms:** `tools/native-hud-string-transform-fixtures.py`
  now executes the original root context (`0x4606c0`), composite (`0x460ba0`,
  `0x45c4d0`, `0x45cc00`) and string routines (`0x45caa0`, `0x463c90`,
  `0x463bb0`) on the shipped `overlay.ini`. Two port fixes followed: the HUD
  ini position quotients stay in ST0 until stored (`0x45c370`/`0x45c4d0`;
  `hud-mesh.js`), and a string's scale is stored as float (`0x458420`;
  `hud-text.js`).

**Open questions settled.**
- **Timer 0 at 0** shows `00:00:00` (`0x46ecc0` → `0x46f5f0`/`0x46f700`)
  before the start, in the countdown (also after a P pause there), and after
  the finish. Results-phase P and Escape are refused (`0x42ffba..0x42ffff`).
  The port matches; `race-hud-order.test.mjs` covers the start states.
- **Menu sliders** (`rcskmenu.dat` `TDaviGraphicSlider`, VMT `0x45efe4`):
  - **Range:** 0–100, `LargeStep` 17.
  - **Keys:** arrows ±1, PageUp/PageDown ±17, Home 100, End 0 (`0x45fb80`).
  - **Setting a value** (`0x45fd98`) always fires OnChange unless it is
    unchanged.
  - **Track clicks:** any button steps 17 toward the click, repeating after
    250 ms and then every 50 ms until the thumb is under the cursor
    (`0x45fc24`, `0x45fde4`/`0x45fe38`).
  - **Drag:** left button only, `trunc((Left−5)·100/147)` (`0x45fa58`).

  The port used the browser's range behaviour (PageUp/PageDown ±10, Home and
  End reversed, a click jumped to the pointer). `source/native-slider.js` now
  implements the original rules; touch and controller input are unchanged.
- **Slider thumb height:** `0x45fd00` sets the needle's Left from `0x45fb08`
  and its Top to `MarginVert` (`[+0x214]` through `TControl.SetTop`
  `0x43ee8c`; 5 from the constructor at `0x45f9b6`, 6 in the DFM).
  - **Before:** the port centred the 35 px thumb in the 57 px slider (top 11).
  - **Change:** `native-menu.js` now pads the slider by `MarginVert` above
    and `Height − MarginVert − needle height` (16) below, so the
    content-box-centred thumb starts at 6. `nativeSliderGeometry` derives the
    needle top from that padding for hit tests. The portrait layout keeps its
    centred 40 px thumb (vertical padding 0).
  - **Measured in Chromium 145 and Firefox 146** (Playwright build 1509),
    identically: thumb rows 9..62 at 1024×768 (6 DFM px × 1.533) and 6..38 at
    640×480; portrait 4..43 in its 48 px slider.
  - **Firefox:** `menu-settings-browser` passes all 35 checks there too.
    Playwright's Firefox delivers whole-pixel pointer coordinates, so the
    test now aims at the first whole CSS pixel inside each DFM pixel; it
    still passes in Chromium.
  - **Validation:** the full Node suite (751) and, after `npm run bundle`,
    the runtime tests (21) passed. In Chromium, `menu-settings`,
    `audio-settings`, `more-settings`, `menu-flow-audio`,
    `storage-compatibility` and `touch-controls` passed.
- **Tab on the intro** does not skip it in the original either. The VCL
  message loop sends Tab to `TCustomForm.CMDialogKey` (`rcskmenu.dat`
  `0x42e414`) as a focus key, so no `WM_CHAR` reaches `FormKeyPress`
  (`0x479cd4`). The port matches; the intro-skip test now covers Tab,
  Shift+Tab and Ctrl+Tab.
- **Older DirectX runtimes** (statically, from the redistributables on other
  Davilex discs): DX5.0 (4.05.00.0155) has no FPU flag and never sets
  single precision. DX6.0 (4.06.00.0318), DX7, DX8.0 and DX9.0b/c switch
  lastingly only at device creation with DDSCL_FPUSETUP; every other switch
  restores the caller's control word. So the game's arithmetic stays 53-bit
  with all of them. DX5.2 and DX6.1 are not on any disc, and third-party
  retail HAL drivers are not checked.
- **Transcendentals:** Unicorn 2.1.4 (QEMU 5.0) computes `FSIN`, `FCOS` and
  `FPATAN` in double precision; the low 11 mantissa bits were zero in 900 of
  900 results even at PC64. The fixtures therefore validate the port's double
  functions, not hardware's extended results. A float store flips only when
  the true value lies within about 2⁻⁵³ (relative) of a rounding boundary:
  about 2⁻²⁹ per store, or roughly one flip in several thousand races.
  Matching hardware would need hardware traces, so this stays a documented
  limitation.

**Tooling note:** Unicorn reuses translated blocks, so running one routine to
different stop addresses can overshoot. The clamp probe flushes its cache and
checks EIP. The other generators use one fixed stop per region, and their
exact tests would catch an overshoot.

**Validation:**
- **Node:** the full suite passed 751 of 751.
- **Bundle:** `npm run bundle` (127 modules) and the 21 runtime tests passed.
- **Browser:** these 17 passed: `driving`, `quickrace`, `bundle`
  (`RCSK_BUNDLE_TRACKS=2`), `variable-cadence`, `player-recovery`,
  `environment-rescue`, `player-rescue-safety`, `menu-entry`,
  `menu-settings`, `audio-settings`, `more-settings`, `menu-flow-audio`,
  `adventure`, `hud-modes`, `hud-timing`, `star-hud`, and
  `startup --intro-only`.
- **Test fix:** `menu-entry-browser` left Adventure character selection
  through the Back button that item 12 disabled; it now leaves through OK
  and the briefing.
- **Evidence:** files written by the browser tests were restored.

### Questions settled by the second pass

- **Opponent object index:** `obj+0x10` is written only by `0x403d90`
  (`0x40400d`) with the progress record it allocates. Its only caller
  `0x417640` allocates once per slot, in slot order, from the fresh 50-record
  pool `0x4031f0(0x32)` created at `0x42daf6`. The index therefore always
  equals the AI slot that `0x4062b0` reads.
- **Up-vector summation in `0x416650`:** |u|² = (ux·ux + uz·uz) + uy·uy, with
  uz rounded through `[ESP+0x68]` (`0x416f8a..0x416faa`); matrix `+0x24` is
  never written. `native-ground.js` matches, and its 24-bit fixture compares
  exactly.
- **Phase 4:** `0x42f740(4)` clears the main-loop flag `0x53b9bc`
  (`0x42f7e4`), so `0x4432a0` exits after the current iteration without
  another `0x42f4c0`. The port stops its update loop on `race-exit` in the
  same update.

### Intentional departures

These two differences are deliberate and are not open work.

- **Pause entry:** on the frame P or Escape is requested, `0x42f4c0` runs
  `0x491530` (callbacks and integration) again, renders and presents before
  the blocking pause `0x42f350` (`0x42f6cf..0x42f712`). The port pauses
  immediately, without that extra object pass and render.
- **QuickRace highscore name:** the original pre-fills the current profile's
  name (`rcskmenu.dat 0x471dec`, `race.ini [playerdata] name`, `john` on a
  fresh install); the port pre-fills its own `quickRaceName` (`Speler 1`).

### Left for later

Both items were checked after phase 3:

- **Marker 51 returns: no difference.** `0x48c170` checks only other racers,
  so with no traffic the original always accepts a marker 51 return. The
  port's `rescuePlacementClear` (3-unit margin, rails included) accepts all
  eight on the six tracks too: 441, 425, 333, 471, 514, 516, 606 and 610.
  The kart rectangle at `nativeRescueDestinationAtWaypoint` overlaps no rail
  or body even with the margin, and the destination depends only on the
  waypoint.
- **Readers of the rescue-scaled matrix.** Order in `0x42f4c0`: racer
  callbacks (`0x491530`, `0x491605`/`0x491637`), then integration `0x491d30`,
  which alone rebuilds the body matrix (`0x4a09e0` at `0x49206f`/`0x49232a`).
  Then the rescue scale (`0x42f618`), effects and render (`0x42f663`), and
  `0x451200` (`0x42f686`). Rendering never rebuilds the body
  (`0x4901d4`, `0x4a09d0`).
  - `0x40b0b0` (NPC callback) reads the matrix only through `0x415be0`
    (`0x415cb1..0x415cc7`), a sign test for the homing target order. Rescue
    scales are positive, so the sign is unchanged. NPC motion and the wheel
    pass `0x41c4b0` use angles, positions and the route-plane height.
  - `0x4863e0` (halo) and `0x4856e0` (generic effects) would copy the body
    matrix, but nothing references their add routines (`0x486460`,
    `0x485730`); the port has neither.
  - `0x451200` (`CBonusController::Handle`) uses positions and radii; its
    only matrix reader is the sign-only HUD arrow, which already gets the
    rescue matrix (`race-hud-meshes.js:153`).
  - **Player: differs (proposed, not changed).** `0x41c48d` rebuilds the
    four wheel children (`0x4906b0` with EBX at `0x41c461`), not the body.
    So during a player rescue, `0x4325b0` reads the previous tick's scaled
    body matrix in two places:
    - `0x41c0b0` transforms each wheel offset with it (`0x41c29f`,
      `0x41c2ee..0x41c30b` → `0x4a25f0`), which moves the ground sample
      points that feed wheel `+0x54`;
    - `0x415520` reads its `+0x34`/`+0x14` slope terms (`0x415646`,
      `0x41566b`).

    The last 1.2 matrix also lasts one tick after the rescue retires. The
    port ran `motion.prepare` every tick with the unscaled `body.matrix`.

    **Fixed (approved).**
    - **`native-ground.js`:** `updateNativeWheelPose` takes a `matrix`
      option, defaulting to `body.matrix`.
    - **`native-motion.js`:** `prepare` takes a `matrix` and uses it for both
      wheel passes and for `matrix14`/`matrix34`.
    - **`race-simulation.js`:** passes the player's rescue `entry.matrix`
      from the previous tick, then the retired entry's last matrix for
      exactly one tick. Everything else keeps the rebuilt `body.matrix`,
      including the ground callback `0x416650`, which runs after the rebuild.

    Evidence:
    - **Fixture:** `tools/native-rescue-matrix-fixtures.py` writes
      `evidence/native/rescue-matrix-fixtures.json`, 60 cases per control
      word:
      - six bodies, five with pitch and roll;
      - shrink and grow frames at 1.4, 1.2, 1.0, 0.5 and 0.1;
      - the scale tables come from `0x48c520` (diag(s, s, s, 1); called by
        `0x48c7e0` at `0x48c98d`), and the matrix is scaled with native
        `0x4a17c0` exactly as `0x48ca60` does;
      - for `0x41c0b0`, a height stub logs the sample points;
      - for `0x415520`, four speeds with and without handbrake.
    - **`tests/native-rescue-matrix.test.mjs`:** at both precisions the
      port's scaled matrix, the `0x41c0b0` sample points and wheel outputs,
      and all 960 resistance results match. The unscaled matrix samples
      different points in every case with a scale other than 1.
      `0x41c0b0` reads only the 3×3 (`0x4a2622` in `0x4a25f0`), and
      `0x415520` only `+0x34` and, above speed 5, `+0x14`.
    - **`tests/rescue-player-matrix.test.mjs`:** a composed race checks the
      handoff tick by tick: the previous tick's matrix, then the last 1.2
      matrix once after retiring, then the body matrix. It fails without the
      change.
    - **Other checks:** the full Node suite passed (723 of 723). After
      `npm run bundle`, the runtime tests (21) and `player-recovery`,
      `environment-rescue`, `player-rescue-safety`, `driving` and `bundle`
      browser tests passed. The evidence they wrote was restored.

    Signed zero (found by the fixture, then fixed): the native multiply adds
    the +0 product of column 3 last, so a −0 matrix entry becomes +0. The
    port's `f32(m·s)` kept −0, which flipped the sign of a zero lateral
    resistance. `updateNativeRescue` now scales through one helper that adds
    `+ 0`. The fixture test compares every matrix entry and resistance result
    with `Object.is` at both precisions. The full Node suite passed 729 of 729
    and, after `npm run bundle`, the runtime tests 21 of 21.

### Second-pass validation

- `npm run bundle` regenerated `src/` and `runtime-manifest.json`.
- Node: `native-rescue` (append order replaced by front insertion; new
  stale-slot retirement cases), `native-homing-arm` (new rescue-scaled matrix
  case), the rescue/recovery safety tests, and every test that builds a full
  `RaceSimulation` or uses the rescue: 131 tests passed, 0 failed. Bundle,
  server, Electron and storage runtime tests: 24 passed.
- Browser (Chrome for Testing 145.0.7632.6, headless):
  `adventure-browser.mjs` (new Escape-on-result scenario; Adventure
  character Back disabled), `adventure-profile-bank-browser.mjs` (browsing not
  remembered), `storage-compatibility-browser.mjs` (browsing keeps the save;
  OK writes the same schema), `menu-flow-audio-browser.mjs`,
  `quickrace-browser.mjs` and `bundle-browser.mjs` (`RCSK_BUNDLE_TRACKS=2`)
  passed.
- `environment-rescue-browser.mjs` and `player-rescue-safety-browser.mjs`
  reach rescue completion but time out waiting for the REAPP voice to start.
  An unmodified copy of `71080ed3` fails at the same lines, so this predates
  these changes. Resolved later: the tests resumed only the clock, not the
  update loop; see
  [browser harness: paused update loop](#browser-harness-paused-update-loop).
- The diagnostic server crashed twice on an unhandled `ABORT_ERR`. A
  request aborted while the handler still awaited `stat` made
  `createReadStream` start with an aborted signal, so the stream was
  destroyed before `Readable.toWeb` listened for its error. The browser runs
  above used a test-only preload that ignored that error. Afterwards
  `electron/game-protocol.mjs` stopped opening a stream for an already-aborted
  request (shared by the local server and Electron). New tests in
  `tests/electron-runtime.test.mjs` and `tests/server-runtime.test.mjs` fail
  without that change and pass with it. `adventure-browser.mjs` and
  `menu-flow-audio-browser.mjs` then passed again on the unmodified
  diagnostic server.
- Evidence files written by the browser tests were restored afterwards.
- Item 18: the 26 test files that read the regenerated fixtures (104 tests,
  including the exact table comparison in `native-integrator.test.mjs`) and
  51 further files that build a full `RaceSimulation` or import a table user
  (222 tests) passed. After `npm run bundle`, the bundle, server and Electron
  runtime tests (19) and `bundle-browser.mjs` (`RCSK_BUNDLE_TRACKS=2`)
  passed.

## Browser validation

Run after the follow-up corrections, against the source inspection server
(`tools/serve.mjs --inspect-source`, which `npm run dev -- --inspect-source`
starts). Browser: Playwright 1.58.2's
Chrome for Testing 145.0.7632.6 (installed into `~/.cache/ms-playwright`),
headless with SwiftShader, passed through `CHROME_PATH`. This is software
rendering, not display refresh or physical-device testing.

Each of these passed once, with no page errors reported:

| Test | Covers | Result |
| --- | --- | --- |
| `star-hud-browser.mjs` | Pickups without the player cooldown (item 1), random draw (item 8) | 7 checks |
| `powerup-audio-browser.mjs` | Pickup and firing audio after item 1 | 118 cases, 4 characters |
| `audio-settings-browser.mjs` | Whole-percentage volumes (item 3) | passed |
| `hud-timing-browser.mjs` | Lap-time display (item 4) | 9 groups |
| `quickrace-browser.mjs` | Finish, results, debrief, P pause and quit requester (items 2, 4, 9) | passed |
| `storage-compatibility-browser.mjs` | Existing saves and settings (item 2) | passed |
| `pause-audio-browser.mjs` | P pause and resume (pause follow-up) | 9 checks |
| `variable-cadence-browser.mjs` | Input at varying frame rates (item 6) | 10 groups |
| `driving-browser.mjs` | Driving all six tracks, portrait layout (items 5, 6) | passed |
| `startup-browser.mjs --intro-only` | Intro autoplay, audio button, Enter/Space skipping (item 7) | passed |
| `menu-entry-browser.mjs` | Keyboard menu entry and focus (item 7's key routing) | 8 checks |
| `help-navigation-browser.mjs` | Keyboard Help navigation (item 7's key routing) | passed |
| `version-browser.mjs` | Version 1.0.1 display | 2 layouts |
| `bundle-browser.mjs` | Generated `src/` bundles and save continuation | 11 checks |

An extra scratch check (not added to `tests/`) loaded the intro and pressed
one key per page: ArrowUp/Down/Left/Right, Alt+A, Alt+Enter, Tab, Shift and
F2 left it playing; Backspace, A, Space, Enter, Escape and 1 skipped it, and
ArrowDown then moved main-menu focus. Controller skipping was not exercised.

Several tests write reports and screenshots into `evidence/`. Those outputs
were copied out and the committed evidence files restored, so the existing
evidence records keep their original runs. The full browser suite
(`npm run test:browser` and the other browser tests) and Electron desktop
checks were not run.

## Intentional differences preserved

Browser and Electron hosting, existing save storage, unlocked frame rate and
interpolation, responsive/widescreen/portrait layouts, keyboard, controller
and touch input (including the touch wheel, brake pedal and paw-and-bolt
button), Meer instellingen with MSAA, free flight, unlock-all, the version
display, stuck-kart recovery and its pickup protections, movie presentation
(aspect ratios, autoplay with muted fallback, **Geluid inschakelen**,
fullscreen on activation), focus/visibility handling, accessibility,
documented navigation adaptations and the `source/` and `src/` separation.
The pause-entry object pass and the QuickRace highscore default name are
also deliberate; see [intentional departures](#intentional-departures).

No difficulty table, deadline, qualification rule or collision geometry was
changed. Saves, profiles, unlocks, settings, high scores and records load
unchanged; the only storage addition is `playerPosition`.

## Coverage

The comparison traced call order, data and state for the areas below. Apart
from the ten corrections, the reviewers found them matching, checked against
assembly, original tables and callers (addresses in `rcskspel.dat` unless
noted). Matching here means no difference was found in the traced paths, not
that every instruction was compared.

- **Player driving:** callback order in `0x4325b0`; forces `0x414160`,
  `0x415990` and their helpers; gears `0x415840`; body setup `0x48fda0`;
  integration `0x491d30`/`0x4911a0`; wheel pose `0x41c0b0`; ground callback
  `0x416650`; keyboard and analog mapping.
- **Opponent AI:** callback order `0x40b0b0`; state transitions
  `0x406940`/`0x407150`; rubber-band tables `0x4062b0`, `0x405fd0`,
  `0x406100`; ranking `0x406be0`; guards `0x401570`, `0x4016e0`, `0x402040`,
  `0x40cde0`, `0x40d070`; lane order `0x40f0b0`; markers `0x4067e0`/`0x406470`;
  profiles `0x40fe50`; delta filter `0x48f4e0`.
- **Race rules:** lap and finish handlers `0x440dd0`, `0x440e40`, `0x440c30`,
  `0x440d70`; time gates `0x441e70`/`0x42f170`; timer bank
  `0x42a210`–`0x42a700`; result gates `0x41fd90`/`0x420850`; result writer
  `0x42c4c0`; `rcskmenu.dat` debrief and briefing records.
- **Items and effects:** bonus controller `0x451200`; pickups `0x4514e0`,
  `0x453fd0`, `0x4540c0`; firing `0x451640`/`0x455490`; flight and hits
  `0x455ce0`/`0x455b00`; hit effects `0x411830`, `0x411b40`, `0x411e50`,
  `0x412090`; skidmarks `0x426aa0`; smoke `0x428690`, `0x432240`, `0x420490`;
  squash `0x48e480` and related routines; type-2 scenery `0x43df60`.
- **Presentation and audio:** cameras `0x41d920`, `0x41e280`, `0x498950`; HUD
  notices `0x430610`, statistics `0x46ecc0`, minimap, stars `0x46e070` and
  portraits `0x46b5e0`; audio conversions `0x49d520`, `0x49d5e0`, `0x431610`;
  skid and crash sounds `0x432190`/`0x434f20`; `rcskmenu.dat` menu sounds,
  options, requester `0x470560` and movie forms.

**Not re-derived in this pass** (it relied on earlier research and fixtures):
weather `0x4818c0`/`0x482020`; jet streams `0x488b40`/`0x48a530`; rescue
internals; explosion particles `0x483fc0`; kart sweep and contact routines
`0x499c30`, `0x492470`, `0x49c220`, `0x49b9c0`; start camera and countdown
timing; and, in `rcskmenu.dat`, Adventure progression, unlocks, the profile
bank, Help and high-score name entry.

## Validation performed

- `npm run bundle` regenerated `src/` and `runtime-manifest.json`.
- New focused tests:
  - `tests/simulation-bonus.test.mjs`: the player collects two overlapping
    pickups in one update, and an opponent is blocked until after its
    deadline.
  - `tests/native-race-setup.test.mjs`: player rank from position 2 in race
    types 0, 2, 1 and 3, and the clamp to the opponent count.
  - `tests/native-startup-upgrades.test.mjs`: a composed `RaceSimulation`
    starts the player at rank 2 with opponents at 0, 1, 3 and 4.
  - `tests/race-save.test.mjs`: the position survives an unfinished race,
    older saves derive it without rewriting, and invalid values are ignored.
  - `tests/audio-mixing.test.mjs`: every slider value 0–100 survives the
    stored fraction, and only enabled effects at 0 trigger the repair.
  - `tests/race-hud-order.test.mjs`: a real simulation crossing the finish
    keeps lap timer 0 at 0 and shows the frozen text 4 s later, including
    after a 1 s host suspension inside the results phase. The same test with
    the native resume path fails, as intended.
  - `tests/native-game-timers.test.mjs`: the native resume ends an earlier
    pause, while a host suspension leaves it in place.
  - `tests/native-player-waypoint-order.test.mjs`: over 80 updates the player
    waypoint is chosen before the ground update.
  - `tests/simulation-native.test.mjs`: the 1,600 input frames now compare
    exactly.
- One combined run of the edited test files, the bundle freshness test and
  every test that constructs a full `RaceSimulation` (including the existing
  save-compatibility, trace and forecast tests): 159 tests passed, 0 failed.
  After the pause follow-up, a run of the timer, lifecycle, race, bundle and
  full-simulation tests passed 128 tests.
- **Not run at the time:** `tests/star-hud-browser.mjs` and
  `tests/powerup-audio-browser.mjs`, because no Chrome or Chromium was
  installed. Both later passed; see [browser validation](#browser-validation).
- The full test suite, desktop packages and full races were not run at that
  time; see [later validation](#later-validation).

## Later validation

- **Release packaging (1.0.1):** the normal build checks passed for all four
  packages. Each integrity report says "passed", with the same 6,748 game
  files and game-tree hash `80a99e1d…` on Linux x64, Windows x64 (both built
  on Fedora Linux) and macOS Intel and Apple Silicon (built by the
  [macOS workflow](https://github.com/NostalgiaRealm/RedCat-SuperKarts/actions/runs/40708703181)).
  The finished packages were not launched.
- **Full unit suite:** one `npm test` run on the released source (tag
  `v1.0.1`, plus documentation-only edits) passed all 668 tests, with none
  failed or skipped, in about 24 seconds on Fedora Linux x64 with Node.js
  v24.13.1.
- Still not run: the remaining 31 browser tests, Electron desktop checks,
  launch tests of the packages, full races and physical devices.

## Unresolved questions

- x87 precision: the port runs 53-bit. DirectX 5.0, 6.0, 7, 8.0 and 9 keep
  the game at 53-bit (statically; see
  [gameplay precision](#gameplay-precision-runtime-check) and
  [remaining items closed](#remaining-items-closed-29-october-2026)).
  DirectX 5.2/6.1, third-party retail drivers and real Windows hardware are
  not checked, and hardware's extended `FSIN`/`FCOS`/`FPATAN` results have
  no reference here.
- Settled: the HUD text when timer 0 reads 0 (`00:00:00`), the slider steps,
  and Tab on the intro (no skip); see [remaining items closed](#remaining-items-closed-29-october-2026).
- The opponent object index, the `0x416650` up-vector order and the extra
  phase-4 frame are settled; see
  [questions settled by the second pass](#questions-settled-by-the-second-pass).
- Controller skipping of the intro and other gamepad paths were not exercised
  in a browser.
- Whole-race trajectories, audio and rendering against a working original
  Windows installation; WineD3D is not an authoritative reference.
