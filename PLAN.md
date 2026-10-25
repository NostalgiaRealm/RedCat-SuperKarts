# RedCat SuperKarts reconstruction

Status: the `v0.9.0` source update includes the runnable browser/Electron game,
prepared assets, movie/HUD corrections, Help navigation, redesigned touch
controls, menu speech/flow fixes and power-up audio audit. See `CHANGELOG.md`.
Existing builds and broad validation reports describe earlier checkpoints.
Complete native-process parity and unavailable platforms remain unverified.
The current [remaining-work audit](docs/remaining-work.md) separates source
improvements, validation gaps and deliberately deferred distribution work.
The complete accepted request is preserved in `docs/request.txt`.

## Latest requested additions

The live host now uses measured variable updates with the original 25 ms minimum
gate and uncapped rendering. World textures and framebuffer use native RGB565
conversion and blending; HUD meshes and original font quads now share an RGB565
composition target with native draw order and per-blend rounding.
The shared movie layout now fits the complete original 4:3 frame to the viewport.
See `docs/research-variable-update-timing.md`,
`docs/research-native-texture-precision.md`, `docs/research-hud-framebuffer.md`
and `docs/validation.md` for focused
source checks. These changes did not refresh the full-race matrix or packages.

The England tyre soft-lock now has automatic player recovery after sustained
attempted driving without travel. Returns use revalidated road positions and
the original rescue animation/audio, with no teleport awards. This is a
source-only change with focused regression checks; the running AppImage,
`dist/` and `release/` are unchanged. See `docs/player-stuck-recovery.md` and
`evidence/player-recovery/validation.json`.

Electron now launches the source game without a server and packages the same
original assets for Linux, Windows and macOS. At that earlier checkpoint,
source and delivered Linux AppImage passed12 desktop checks each and all513
JavaScript tests passed. Linux
packages and a cross-built Windows installer/ZIP were produced locally. They
are not current builds or assets of the public source release. macOS build
instructions cover Intel and Apple Silicon, with native Windows/macOS runs
and Mac packaging still unverified. See `docs/desktop.md` and
`evidence/desktop/validation.json`. The static browser build was also refreshed
at that checkpoint with the earlier missing-dependency/start-button correction.

The kart-shadow audit corrects premature viewport clipping and the browser's
extra alpha compositing while retaining the original texture, shape, position
and blend behavior. **Meer instellingen** now sits below the sound sliders and
contains selectable MSAA and the requested free-flight/country-unlock cheats.
See `docs/more-settings.md`, `docs/research-kart-shadows.md` and
`evidence/more-settings/validation.json` for the focused rebuilt checkpoint.
Earlier full-race results retain their original runtime hashes and are not
claimed as fresh runs of these additions.

## Milestones

1. **Established — original startup contract.** Executable types, process
   handoff, configuration paths, media, tracks, models, active race modes and
   persistence inventoried. Original inputs preserved.
2. **Implemented and validated — compatible extraction.** Compare Spookkasteel's implementation
   first; reuse only matching formats. Extract all assets with validated bounds,
   source hashes and reproducible conversion.
3. **Implemented and browser-checked — original menus and platform foundation.**
   Intro, selection, settings, input, responsive artwork and independent 3D resolution.
4. **Implemented and bounded-native-compared — recovered racing simulation.**
   Handling/reverse, AI, collision, timing, checkpoints, items, progression and cameras.
5. **Implemented with separate flow/mode checks — active original content.**
   Six tracks, four playable characters, three difficulties, four modes,
   adventure stages, results, persistence, original audio and effects.
6. **Available-host checks passed; external comparisons remain — validation.**
   Controlled 31/32/60/120/144/240 schedules, stalls, reverse cases, Linux
   Chromium/Firefox, simulated controller and browser multi-touch. Native
   race comparison and physical-device coverage remain explicitly unverified.

## Initial findings

- New workspace was empty at first inspection.
- SuperKarts contains `.rmp/.omp/.cmp/.dmp/.pth` maps, `.d3d` models,
  binary car/physics tables and INI configuration.
- Spookkasteel uses Genesis3D GBSP/ACT and Davi-Script. These systems cannot be
  presumed compatible; its archive index layout is compatible with `rcs.ind`.
- Native code corroborates Davilex's M25/A2 Racer lineage. Race configuration is
  consumed from `data/game.ini` and `data/race.ini`, not the legacy `data/ini/game.ini`.

## Implemented systems and retained checkpoints

- The retained 72-combination full-race audit is tracked by
  `evidence/full-race-matrix/race-matrix.json` and
  `docs/research-full-race-matrix.md`. Its verifier checks original rules,
  five actual driven laps and unchanged runtime/assets, and rejects
  standalone experiments above its then-production 40 Hz reference cadence.
  That checkpoint passed 492 unit tests and eleven focused mirror/recovery
  browser checks and refreshed its static build; these are historical results.
  Its five-lap coverage is 71/72; France on hard difficulty in timed
  mode remains an incomplete automated driving check. Failed attempts do not
  establish that the original deadline is impossible. The current measured
  variable host and later recovery changes still need full-race coverage.
- Original constructor execution establishes that loaded upgrade flags are
  cleared before player/NPC/timer initialization. The port follows this reset.
  Mirrored-world camera composition is corrected. Two captured native failure
  cases have narrow authorized safeguards: NPC return waits when its original
  destination overlaps the player, and a newly nonfinite NPC velocity
  component is zeroed without changing finite original motion.
- All 5,498 archive records are accounted for byte-for-byte. Converted content
  includes 3,495 meshes, six tracks, 41 paths, menu images/fonts, 11 movies,
  1,220 WAV files, six music streams, and all three original physics tables.
- Native Delphi resources supply 20 forms, button states, component geometry,
  caption rectangles, and ten original hit masks. The port uses these for
  menus, controls and requesters. Portrait layouts rearrange original
  artwork; 26 layouts have bounded checks at 320/390-pixel widths.
- The original WinHelp file supplies 13 linked Dutch help topics and 46
  losslessly converted illustrations. No help prose was rewritten.
- QuickRace selection leads through the original control-information form,
  country/character loading art, authored fly-through, countdown, racing,
  finish camera, debrief, highscore entry and retry/main.
  A browser check follows this path with a controlled finish-trigger fixture;
  that fixture is not a driven full race.
  Key reassignment, settings and selections persist. Original low/high hardware
  presets are 640×480 and 800×600. Added Auto/render-scale controls are separate.
- `/?track=0..5` inspects original tracks with original skies/scenery animations.
  `/?drive=0..5` is an explicit research view: original kart, driver animations,
  camera, player motion, four original opponents, ground/rails/kart contacts,
  weapons and recovery. It skips the menu/countdown for repeatable investigation.
- Native instruction fixtures cover input, forces, integration, wheel/ground,
  sector search, static collision, camera, transforms, mesh clocks and race
  triggers. Six-track driving/reverse/contact traces remain identical under
  controlled 31/32/60/120/144/240 render schedules and stalls.
- **Initialization correction:** startup changes the angle table from the PE's
  initial 1,024 entries to **4,096**. Production kernels and native fixtures now
  initialize 4,096 entries. Earlier synthetic 1,024-state comparisons do not
  establish active-game parity.
- Active NPC decision/movement handlers now run with original difficulty
  tables, path/occupancy decisions, item use, catch-up, hit reactions, finish
  timers and recovery. A five-minute stationary-player endurance run passes
  on all six tracks at all three difficulties. This is a composition check,
  separate from the many bounded original-instruction comparisons. After the
  shared-player grip and upgrade corrections, all 18 runs still pass and all
  four hard-mode opponents finish five laps on each track.
- Original HUD glyphs, minimaps, animated portraits, bonus frame/owned item,
  countdown and notifications are connected. Engine layers, starter, gear
  changes, skid loop, event sounds and music use original samples and controls.
- Pause-aware race timers are separate from absolute engine time. Native pause,
  quit, finish and timeout gates/cameras are connected. Keyboard, touch and
  proportional native analog input are checked in Chromium.
- Adventure profile, briefing, progression, unlock and movie flows pass the
  browser transition checks, including deletion/reload, original lock prompts,
  final-duel star movie, highscore and Max's campaign movie. These controlled
  results do not replace driven completion. Source helpers cover all three
  difficulties, 24 stages and the original save/result decisions.
- All 35 moving scenery paths and six start-camera paths have native instruction
  comparisons. Original linear texture filtering, front-face culling and
  camera-facing sector windows are connected. The shared RNG is seeded before
  construction and reseeded before gameplay, following the original order.
- Original roadside sounds use 311 independent placement voices, the native
  listener/distance/pan/doppler rules and original samples. Kart shadows and
  the finishing checker flag are connected with native geometry/timing fixtures.
- Sound coverage precedes mixing correction: the audit now accounts for496
  sound records,327 logical bank names and52 native call sites. Twenty-six
  live browser trigger fixtures start57 actual sounds in the final run;
  missing original names
  remain silent. Native source/group/music levels, initial FX repair and
  independent menu/movie volume are implemented and checked.
- Camera re-audit is complete at the bounded instruction level: startup uses
  the original cold timing history, all four keyboard views use original
  transforms/gates, and camera selection persists across scripted phases.
  Native fixtures and browser key/visibility checks pass.
- Player animation dispatch and queue transitions now follow source order.
  Four-character browser checks display both steering directions and reverse
  clips;20 pickup/hit fixtures verify immediate head reset and next-clip display.
  Ground-dependent kart/driver shading, weather, skidmarks, rocket rings,
  jet/ribbon streams and squash hazards are connected. Original draw ordering
  is checked with native traces and actual browser submissions.
- BonusRace4, ordinary traffic, money purchases and collision damage have been
  classified against the shipped executable/content. They are inactive legacy
  paths, not missing playable modes or mechanics; see the legacy audit.

## Earlier broad local validation

`evidence/final/validation.json` consolidates the frozen-source evidence:
374 JavaScript tests, four parser tests, complete asset checks, 36 driven race
cases, 18 five-minute opponent runs, Chromium/Firefox browser checks and the
rebuilt static package. All six courses qualify in all four active modes on
easy; all six star races collect twelve stars. Ordinary races finish on all
three difficulties, with qualification reported separately. All hard-mode
opponents finish five laps in the endurance matrix.

The two unsuccessful England control-policy attempts and initial sound-harness
failure are retained. Shorter steering look-ahead and a real PCM-completion wait
corrected those tests without changing production rules.

## Follow-up corrections

Original FIRSTTIME settings now select the initial menu greeting. The motor
starter begins after the authored camera pan. Player/NPC danger-zone recovery
uses original marker50/51 rules, with occupied-return retry, shrink/grow rings
and character sounds. Texture-key filtering is audited against original loader
instructions and source images. `evidence/regressions/validation.json` records
that focused checkpoint, separately from the earlier long race/endurance run.

The broader follow-up compares connected callers as well as isolated routines.
It restores menu commit/cancel and key-capture behavior, native focus/tab order,
advanced graphics controls and their consumers, Shift gates, bubble shells,
rescue render coordinates and sector progress, and precise ground/force
arithmetic. All24 Adventure transitions now run consecutively through the UI
with controlled race results, including country and final-character movies.
The rebuilt-runtime checkpoint and refreshed checks are linked from
`evidence/followup/validation.json` and `docs/research-followup-audit.md`.

## Remaining comparison work

The maintained list, including source/test maintenance, is
[`docs/remaining-work.md`](docs/remaining-work.md). The principal verification
items are:

1. Obtain a trustworthy original Windows race baseline for complete visual,
   audible and trajectory comparison. WineD3D is unsuitable on this host.
   Exact color-key filtering/framebuffer precision still needs that reference.
2. Validate Windows/macOS and real Android/iOS devices, physical controllers
   and physical high-refresh displays. Current touch/pad tests are simulated.
3. Drive an uninterrupted 24-stage Adventure through its UI. Current evidence
   combines separate course/mode completions with controlled profile,
   progression, highscore and movie transitions.
4. Validate current variable-cadence full races, including the still-unfinished
   France hard timed check. Update the fixed-step test host for that scope;
   retain its existing deterministic reference role separately.

The previously outstanding Germany, France and Italy normal-race checks were
completed at their recorded checkpoint:
five laps and first place each in648975/812350/565975ms. The follow-up restored
original jump callbacks and route settings, improved the test driver and added
the explicitly authorized player rescue safeguard. See
`evidence/race-completion/validation.json` and `docs/research-race-completion.md`.

Undefined native weather/stream storage uses the documented zero policy.
Custom nonzero fog and the legacy software renderer are outside the active
shipped-configuration coverage; they are not silently claimed as verified.

## Work ownership and evidence

- Native startup/timing: `docs/research-startup.md`, `evidence/native/`.
- Asset formats/conversion: `docs/research-assets.md`, `tools/prepare-assets.py`.
- Gameplay content/rules: `docs/research-gameplay.md`, `src/simulation/`.
- Integration and browser work: root `src/`, `tests/`, this plan and core docs.

## Acceptance gate

Each system needs separate implemented and compared statuses. A successful
build, an extracted asset, a scripted race, or a visually plausible result
does not prove native parity. See `docs/feature-parity.md` and
`docs/validation.md`. Unknown native behavior is a research task, not
authorization to invent it.
