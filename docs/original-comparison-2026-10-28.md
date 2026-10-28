# Original-code comparison — 28 October 2026

This report covers a read-only comparison of the `main` checkout at
`991cba9f` against the recovered native code, followed by six approved
corrections. It records bounded static and instruction evidence. It does not
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

No difficulty table, deadline, qualification rule or collision geometry was
changed. Saves, profiles, unlocks, settings, high scores and records load
unchanged; the only storage addition is `playerPosition`.

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
- The full test suite, desktop packages and full races were not run.

## Unresolved questions

- Whether the shipped game ran with 24-bit or 53-bit x87 precision. Item 6
  follows the documented 24-bit assumption.
- The exact HUD text when timer 0 reads 0. (The original resume does end the
  finish pause, but the original cannot pause during the results phase.)
- Slider change granularity in the original shell, and whether Tab produces
  `WM_CHAR` for the intro (it currently does not skip).
- Whether each opponent's object index always equals its AI slot, and the
  summation order of the up vector in `0x416650` (last-digit matrix values).
- Whole-race trajectories, audio and rendering against a working original
  Windows installation; WineD3D is not an authoritative reference.
