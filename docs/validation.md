# Validation

The local build implements the recorded active systems. Bounded original-
instruction comparisons and available-host browser checks are recorded below;
complete native race parity has not been established.

## Version 0.9.0 source update — 25 October 2026

The [0.9.0 changelog](../CHANGELOG.md) collects the source changes since the
previous publication, including the focused follow-ups below. Version metadata
in `package.json` and its lockfile agrees with the generated browser module;
the npm version hook keeps that module in sync. The version is shown under
**Instellingen → Meer instellingen**.

The version update receives a focused landscape/portrait menu check and
metadata consistency checks; it does not repeat the earlier suites or races.
Evidence is recorded in `evidence/version-0.9.0/validation.json`. No desktop
packages or static build outputs were regenerated.

## Source audit and movie layout — 22 October 2026

[Remaining work](remaining-work.md) records the current source/evidence audit.
The audit itself ran no tests, races or builds. Its two rendering/harness items
are now complete: the HUD shares an RGB565 composition surface, and the smoke
tests inspect world geometry, packed textures and real HUD output. The focused
23 October follow-up passed 23 unit tests, 120 glyph pixel samples, the existing
197 texture GPU samples, mode/layout/mirror/lifecycle checks, and Chromium,
Firefox and source Electron smoke checks. See
[HUD framebuffer research](research-hud-framebuffer.md) for original addresses,
commands, reports and limits. No full suite, full races or builds were run.

The preceding movie-layout correction constrains the shared grid/video box to
the viewport. All 11 original and prepared movies are 320×240, SAR 1:1, DAR 4:3;
no media conversion was changed. That source-only check passed 66 combinations
(11 movies × six viewports), complete-frame/black-border pixel comparisons at
ultrawide and portrait sizes, and intro skipping to the menu. The local record
is `evidence/runtime/movie-aspect/validation.json` (ignored, not distributed).
The movie fix is included in `v0.9.0`, but not in the earlier `v0.1.0` source
tag. No package was rebuilt for it.

The published source release includes all prepared assets and no desktop
builds. Packaging results below describe the earlier local checkpoint only.

## Source-only power-up audio audit — 25 October 2026

The [power-up sound audit](research-powerup-audio.md) found no recording,
dispatch or mixing discrepancy requiring a game-audio change. It checks both
original copies, 314 byte-identical WAVs, fresh REA/Hopper analyses and 3,001
original instruction cases. Twenty focused comparison/queue/mixing/spatial
tests and 118 controlled browser cases pass. All four player characters use
the expected five pickup effects and 15 numbered firing recordings; FIFO,
NPC suppression, homing warnings and missing-name behavior are preserved.

The browser checks use explicit item-race fixture setup rather than full
races. Random pickup type 7 has no authored track placement and is explicitly
injected for its supported-state checks. No full suite, build, publication or
native sound-card capture was performed. See
`evidence/audio/powerup-parity/validation.json` for source hashes and limits.

## Source-only menu speech and flow — 25 October 2026

The [menu follow-up](research-menu-audio.md) restores all 24 Adventure briefing
recordings and corrects selected-profile voices, modal returns, character Back,
FIRSTTIME handling, source stop order and the awaited quit farewell. The audit
resolved 65 original wrapper calls and verified 398 supplied menu WAVs against
the original bytes; five configured references are absent in the supplied
originals. No substitute recordings or unused filename-based greetings were added.

Seventy-six original instruction probes, five focused JavaScript tests, 12
menu-flow browser groups, 57 existing menu-playback cases and three existing
profile-bank groups passed. One race opening checks menu narration does not
carry into the race. Browser media events confirm playback and ordering, not
a live original Windows sound-card comparison. Start-info/Landinfo Escape
adaptations remain documented. See `evidence/audio/menu-flow/validation.json`.
No full race, full suite, build or publication was run.

## Source-only Help navigation — 23 October 2026

The [Help follow-up](research-help-navigation.md) verifies 13 original topics,
nine current-window jumps and 13 keyword mappings directly from the HLP.
It corrects mode-specific Help contexts and country-information notice 46,
adds Contents/Back/Index/History, and preserves the caller's form/drafts.
There is no authored browse sequence or popup link to reconstruct; the old
helpdeco warnings were misleading. Thirteen parser tests, nine JavaScript tests
and ten focused browser groups passed. No race or build was required.

## Source-only touch controls — 23 October 2026

The [touch-control follow-up](research-touch-controls.md) replaces the old
button grid with a proportional left steering wheel, right Alt-equivalent
brake pedal and generated bonus button. It documents the SuperTuxKart response
reference and the CC0 SVG artwork source. Twenty-four focused unit/protocol/
layout tests and twelve browser groups passed, with remaining-group/layout-only
reruns after fixes. The browser checks include actual forward/reverse movement,
multi-touch, pause/rotation cleanup and four phone viewport layouts. See
`evidence/touch-controls/browser.json` for source-specific segments.

No full races, full suite or builds were run. Desktop SVG serving is verified
through the protocol handler; physical phones, Safari and desktop packages
remain outside this focused source check.

## Current source-only variable update timing

The live runtime now follows the original minimum-interval admission and
absolute-clock arithmetic while drawing independently on every browser frame.
Late callbacks run one measured update, without fixed-step catch-up. Pause
retains the admission gate and resets the separate physics clock/history.
See `research-variable-update-timing.md` and
`evidence/variable-cadence/validation.json` for original probes and focused
source/browser verification. Earlier builds and full-race reports retain
their earlier source and fixed-reference-cadence scope.

## Current source-only player recovery

The England tyre soft-lock has a focused regression and automatic recovery
safeguard using the original rescue animation/audio. See
`player-stuck-recovery.md` and `evidence/player-recovery/validation.json` for
the exact source checks and scope:63 focused tests and four source-browser
check groups pass, including the tyre reproduction in all four race modes.
The full suite and full-race matrix were
not rerun. No browser or desktop package was rebuilt for this change; the
running AppImage and existing release files remain at their earlier checkpoint.

## Earlier desktop integration

Electron desktop launch and packaging are implemented with the same game code
and original assets. `evidence/desktop/validation.json` records 513 passing
JavaScript tests and 12 checks each for the source launcher and delivered Linux
AppImage. These exercise original intro/menu media, native fullscreen,
single-instance focus, QuickRace opening/countdown, keyboard movement, race
audio, persistent settings/save data and original-menu exit with the normal
Chromium sandbox enabled. Runs used Linux/Xvfb/KWin and SwiftShader; physical
GPU/audio/controller testing and full races are outside this integration check.

At that checkpoint, Linux AppImage/tar.gz and Windows x64 NSIS/ZIP packages were
built locally. Each staged 6,844 game files checked byte-for-byte, plus the
narrowly scoped wrapper. The then-current browser `dist/` was refreshed and
included the startup correction below. These packages do not include later
source changes and are not attached to the public source release.
Windows packages are cross-built, with native execution unverified. macOS Intel
and Apple Silicon build instructions/configuration are supplied; Mac packages,
native runs, signing and notarization have not been validated here. See
`desktop.md` for platform commands and limitations.

## Earlier source-server startup correction

Missing `node_modules/three` prevented the browser import graph from evaluating,
leaving an empty blue screen. The pinned dependencies were restored with
`npm ci`; the server now checks its three required library files before listening
and reports the installation command when they are absent. The noninteractive
autoplay notice also lets clicks reach the Start button beneath it.

The focused records are in `evidence/startup-blue-screen/`: three server
preflight tests plus Chromium and Firefox intro/menu/race checks. This source
startup fix does not require rebuilding or restarting an already running server
after restoring dependencies. The static build was not refreshed at that
checkpoint; the later desktop integration above now includes this correction.

## Earlier shadow and extra-settings checkpoint

`evidence/more-settings/validation.json` records the focused checkpoint for
the requested shadow comparison, relocated **Meer instellingen**, selectable
MSAA, free flight and persistent country unlock. See `more-settings.md` and
`research-kart-shadows.md` for behavior, original evidence and reproducible
checks. These optional features have separate unit, menu/save, real WebGL and
browser-input verification. All 504 unit tests and 60 checks across seven
browser suites passed. All 6,844 built files match their source inputs. These
checks do not establish a new full-race matrix.

## Historical full-race matrix

`evidence/full-race-matrix/race-matrix.json` records the earlier72 requested
track/difficulty/mode combinations. Its verifier requires five naturally
completed laps, original opponent counts, valid native time-gate accounting,
all twelve distinct stars where required, and unchanged runtime/assets.
Unfinished combinations remain explicit. Race completion and placing or
Adventure qualification are separate results.

That runtime passed492 JavaScript tests and eleven focused browser
checks: four mirror/input checks and seven recovery checks. The static build
was refreshed at that checkpoint. `research-full-race-matrix.md` records the original
constructor upgrade reset, mirrored-world composition correction and the
two narrowly scoped anti-stuck safeguards. Original assets and all three
player/opponent table pairs were checked again against the supplied files.
`runtime-checks.json` records the before/after runtime hashes, test-source
hashes, logs and browser results for this exact validation run.

All accepted historical matrix races use the then-production25ms reference cadence.
Standalone faster-kernel experiments are excluded: the original main loop
waits at least25ms, and its angular truncation depends on that interval.
See `research-frame-cadence.md`. Whole-race Windows comparison remains
unavailable; these are ordinary-control port races plus bounded execution
of original instructions, not a native-versus-port campaign replay.

## Earlier follow-up checkpoint

`evidence/race-completion/validation.json` closes the three previously
unfinished normal races. `research-race-completion.md` records the original
jump/direction corrections and the user-authorized player rescue safeguard.
All three finish five laps and place first under ordinary controls on one
unchanged source checkpoint: Germany648975ms, France812350ms, Italy565975ms.

`evidence/followup/validation.json` retains the broader audit after the
reported-regression checkpoint. `research-followup-audit.md` explains the native
evidence, confirmed discrepancies and implemented corrections.

| Check | Result and scope |
| --- | --- |
| Runtime tests |445 JavaScript tests passed at this historical checkpoint; six parser tests passed in the unchanged asset pipeline |
| Original assets | Complete asset validator passes; texture audit retains817 source records plus587 aliases with no source-pixel mismatches; all11 movie frame counts/cadences match |
| Menu/settings |293 original instruction cases;33 browser checks;57 original menu WAV starts |
| Player arithmetic |320 isolated plus320 recurrent wheel/ground comparisons;720 original force callbacks plus2,400 recurrent force/integration updates |
| Rescue progress and keys |6,552 sector/progress/trigger cases;24 device handbrake cases and24 mapped-key polls;1,024 strengthened camera-key cases; composed Space-audio gate check |
| Bubble and render positions |480 original bubble operations,200 position/blend cases; browser hit/cleanup/first-person and actual moat relocation checks |
| Graphics settings |Three off/on/off reloads verify source-channel brightness, shared processed HUD imagery, independent samplers and effect construction;144 original HUD entry/exit pairs and four constructor cases establish state carry-over |
| Texture effects |15 rendered comparisons retain original effect geometry/UV/blend rules;32 WebGL material samples match byte-space modulation/blending |
| Opponent endurance |All18 course/difficulty combinations run five simulated minutes with finite state and no exceptions; execution dependencies retain their hashes |
| Current requested autonomous checks |Germany, France and Italy each finish five laps, first place, with identical frozen source. The earlier Nederland/England/Spain completions retain their previous checkpoint |
| Jump and rescue follow-up |648 original jump callbacks,320 registered crossings and two integer-load cases;256 active-precision composed contact frames exact. Authorized player safeguard passes captured Italy/France cases and seven browser checks including both original rescue sounds |
| Adventure sequence |All24 stages use one profile and actual menu/save/movie transitions; controlled final-lap/star fixtures are declared separately from physically driven races |
| Browsers and build |Current rescue browser checks pass; prior all-six-track/menu/QuickRace/Firefox checks remain retained. Rebuilt package contains6841 files and6830 copied runtime/asset files compare byte-for-byte |

That frozen runtime comprised106 files including `index.html`. Long headless
tests also record their transitive execution dependencies, so concurrent changes
to presentation-only files do not disguise movement-code changes.

The cleanup review caught an asynchronous HUD disposal bug: clearing the Three
renderer before texture-disposal callbacks left GPU handles alive across races.
The port now finishes owned-resource disposal first. A live GPU regression
checks three reloads and final disposal while retaining the world's shared
source textures.

Retained earlier harness failures include stale initial-focus artwork
expectations, provisional tab-order tests during editing, and autonomous route
follower limitations. These are recorded separately; incomplete checks are
explicitly marked. Current driven-race outcomes and unsuccessful control
policies are linked from the consolidated report.

## Earlier results recorded on 2026-10-20

The broad checkpoint below predates the subsequent greeting, starter, environment
recovery and texture-key corrections. Its source hashes and long race/endurance
results remain a historical checkpoint. The focused follow-up is recorded in
`evidence/regressions/validation.json`. The current follow-up above refreshes
the18-run endurance matrix and selected browser/driven checks. It does not
claim the earlier36-case driven-mode matrix was repeated in full.

| Check | Result and scope |
| --- | --- |
| Earlier frozen-source verification |374 JavaScript tests and four parser tests pass;95 runtime files retain identical hashes across those checks; consolidated report `evidence/final/validation.json` |
| Documented preparation command | `npm run prepare:assets` completed with zero conversion errors, fresh form/mask/help extraction and the original launcher icon |
| Archive/source verification | 5,498 byte-exact records; 3,495 completely parsed meshes; all six tracks; 1,302 decoded images; 1,220 WAVs; 410 byte-exact loose CD sounds; three byte-exact player physics tables |
| Menu voices | 398 of 403 references resolve; five files are absent from both original inputs and remain silent |
| Movies | All 11 have matching source frame counts and cadence; aspect/audio checked separately; lossy encoding is not pixel/bit-exact |
| Menu regions | Ten original masks retained; shape/coverage tests include scaled hit areas |
| Help | 13 original Dutch topics, 46 pixel-exact illustrations, nine links, original table/bullet content |
| Native routine comparisons | Instruction fixtures cover timing, digital input, forces, integration, wheel/ground contact, track/rail geometry, transforms, camera, animation, race triggers, bonus rules, AI, HUD text and material states |
| Sound coverage before mixing |496 Sound.ini records,495 unique names,11 banks/327 logical names,311 ambient and174 impact clones,52 native call sites;26 final DrivingView trigger fixtures produce57 actual WebAudio starts, including incidental original voices. Missing original symbols remain silent |
| Sound/music settings |5,952 source-volume cases,16 controller gates and101 music conversions match native instructions. Browser checks verify initial FX0→75 repair, source clone levels, live25/0 changes and independent movie volume |
| Countdown | 1,920 original state/sound-command updates and 204 slide positions match at explicit 24/53-bit x87 precision; QuickRace browser check verifies original 321 meshes, stationary controls before green and active timers afterward |
| Authored camera and scenery | Six startup-camera paths: 48 initialization cases and 12,988 native updates. All 35 scenery paths: 210 durations, 1,750 spline positions, 1,050 motion updates and 4,368 activation cases; browser checks render all paths |
| Camera re-audit |144 cold timer/path cases,384 mode transforms,512 key/phase cases and8 green transitions; browser checks cover keys1/2/3/4, first-person body/shadow hiding and inherited rear-view damping |
| Player animation composition |Four playable characters display both steering directions and reverse meshes under real browser key events;20 synchronous pickup/hit callback fixtures verify queue-head reset and same-update next-mesh selection |
| Weather, skidmarks and rocket rings |Eight weather constructors,256 complete particle frames,320 marker callbacks,520 skidmark frames and six complete explosion traces compare original instructions at24/53-bit precision. Browser checks verify rain/snow/camera-space state and a rocket ring |
| Streams and squash |960 jet frames,960 ribbon frames,720 stream manager operations,30 setup branches,16 draw traces,720 squash frames and1,920 hazard callbacks compare original instructions. Three browser scenarios verify stream packets, squash transforms and actual world/model draw order |
| Submission order |36 original object traces and four road traces establish road/land/extra/rail batching and kart-shadow adjacency; explicit child slots preserve wheel order despite asynchronous loading |
| Render-rate independence | Equal ordered simulation input gives identical traces at controlled 31/32/60/120/144/240 render schedules, jitter and stalls; all six tracks include forward/reverse/rail cases |
| Connected opponents and difficulty | Original AI roster, all active handlers, item decisions, collision, catch-up, finish and rescue are connected; isolated original-instruction comparisons are recorded in `research-ai.md` |
| Endurance | Five minutes with a stationary player on each of six tracks and each of three difficulties stayed finite and completed without exceptions; hard-mode NPCs completed five laps on every track. This does not establish full original race parity |
| Driven mode completion |36 selected control-only cases finish five laps:18 ordinary races across all difficulties, plus six each of timed/star/duel on easy. Every easy course/mode pair qualifies; all six star races collect exactly12 stars. Medium/hard ordinary completion is distinct from qualification |
| Kart contacts and ranks | 480 paired contact responses, 360 native full sweeps and 600 rank updates match recorded original instructions |
| HUD and recovery imagery | Native minimap positions match 720 full callback cases plus 160 orientation cases; rescue matches 80 updates, 6,720 vertices and 360 destination selections; Chromium renders original artwork |
| Chromium menus and inspection | Original forms, selections, prompts, key reassignment, persistence, help, all six tracks, resolution buffers, portrait/orientation and simulated controller/touch navigation |
| Chromium driving | All six tracks/four selectable characters render with original HUD atlases and keyboard movement; simulated B-button braking stays in race; partial analog throttle/steering/brake, keyboard takeover/release, focus pause/resume and two browser touch contacts pass |
| QuickRace flow | Main → character/difficulty → country → controls → countdown → racing → native pause/quit → controlled finish → debrief → original name entry → saved highscore → retry passes. The finish is a trigger fixture, not a physically driven race |
| Native lifecycle/analog/results | Pause-aware timer bank, finish/failure cameras, result/pause gates, 1,200 proportional analog cases, 1,480 results cases and 528 original menu time formats have bounded native comparisons |
| Engine and tyres | Original three engine layers, starter, gear-change sample and skid loop connected; 360 engine updates, 101 volume values and 176 skid decisions compared; actual WebAudio decode/gating/loop/pause/disposal checked |
| Roadside audio | 311 independent placement voices across six tracks; 700 native spatial mixer cases plus camera/listener fixtures; original samples, per-voice pan/attenuation/looping checked in WebAudio |
| Rendering and effects | Native filtering/culling/fog selection and camera-facing chunk range fixtures; original kart shadow has 200 native poses, finish flag has 40 complete native wave frames and exact original atlas coordinates |
| Adventure browser flow | Original profile creation/deletion/reload, briefing, locks, country unlock, highscore, final-duel star movie, Max campaign movie and completed-profile replay reset pass controlled transition checks in `evidence/adventure/report.json` |
| Firefox | Original menus, first/last tracks, sky/animation and keyboard driving pass in Firefox 158.0 under Xvfb/software OpenGL |
| Static build |Fresh `npm run build` produces6,831 files; runtime sources and all prepared assets match the tested trees byte-for-byte. A separately served `dist/` passes QuickRace selection/countdown/pause/results/highscore/retry |

Evidence files:

- `evidence/final/validation.json`: consolidated criteria, selected race cases,
  retained failed/losing attempts, source fingerprints and comparison limits.
- `evidence/final/*-summary.json`, `*.log`: command outcomes and source/build checks.
- `docs/evidence/asset-validation.json`: source/parser/media checks.
- `docs/evidence/help-validation.json`, `help-browser-validation.json`.
- `evidence/native/*-fixtures.json`: original instruction cases, hashes and
  explicit stub/precision conditions.
- `evidence/gameplay/`: native gameplay fixtures and source inventory.
- `evidence/browser/report.json`: menu/track browser run and screenshots.
- `evidence/driving/report.json`: research driving checks and screenshots.
- `evidence/quickrace/report.json`: QuickRace transition/result/persistence check.
- `evidence/adventure/report.json`: original profile and adventure transition checks.
- `evidence/audio/browser-engine.json`: WebAudio engine/skid check.
- `evidence/audio/coverage.json`, `race-trigger-playback.json`,
  `settings-playback.json`: original coverage, live trigger playback and mixing.
- `evidence/camera/browser.json`: real key selection and body/shadow visibility.
- `evidence/animations/browser.json`: four-character driving and event/mesh checks.
- `evidence/weather/browser.json`: weather and rocket-ring render binding.
- `evidence/streams-squash/browser.json`: stream packets, squash transforms and draw order.
- `docs/research-streams-squash-order.md`: original effect activation, clocks and ordering.
- `evidence/firefox/report.json`: Firefox capabilities, scope and results.
- `evidence/native/race-simulation-endurance.json`: all 18 five-minute composed
  runs, states/items/laps/finish times; a stability report, not a native replay.

Browser reports are overwritten by each run, including failures. Read the
report's status and source state together; a historical pass is not evidence
for later edits. Console shader errors and missing runtime resources fail the
Chromium suites.

The final audio run preserves one harness failure and its correction in
`evidence/final/audio-camera-summary.json`. The original recovery voice was
accepted behind a passing voice in the FIFO. A synchronous test advanced game
ticks without allowing the earlier PCM sample to finish. The corrected test
waits for real playback, bounded to five seconds; no game audio rule changed.

## Comparison criteria

- Declared archive ranges must fit exactly; malformed inputs fail rather than
  generating fallback geometry.
- Lossless conversions retain source dimensions and pixel values before
  separately documented colour-key application.
- Movies retain frame count/cadence/aspect; allowed duration difference is one
  original frame. Re-encoded audio/video are not called lossless.
- Native discrete state, call order and integer results match exactly.
  Floating-point fixtures use explicit native precision and routine-specific
  tolerances documented in their tests and research notes.
- The active executable initializes **4,096 angle units**, overriding the PE's
  initial 1,024. Active-game comparisons use the initialized state.
- Original timing is a filtered variable update with an integer 25 ms minimum
  update gate. The live browser follows this gate on an independent measured
  timer and keeps rendering uncapped. Earlier deterministic replay tests do
  not establish a historical fixed rate or replace current scheduler checks.
- Equal-time JavaScript traces compare identical state, independently of native
  fidelity. Scripted routes through trigger tests are not completed races.
- Auto resolution applies device pixel ratio once. Presets retain viewport
  aspect independently of DPR; scale multiplies both dimensions. Integer
  drawing buffers allow one rounding pixel; artwork keeps original proportions.
- Focus loss clears input, stops simulation time and resumes without backlog.
- Settings/selection/key assignment survive reload; corrupt storage fails safely.

## Platform and device limits

| Environment | Status |
| --- | --- |
| Linux Chromium 155.0.8059.84 | Passed automated scope above; headless/SwiftShader |
| Linux Firefox 158.0 | Passed bounded scope above; Xvfb/software OpenGL |
| Windows Chrome/Firefox/Edge | Unavailable / unverified |
| macOS Safari/Chrome/Firefox | Unavailable / unverified |
| Android real Chrome device | Unavailable / unverified |
| iOS real Safari device | Unavailable / unverified |
| Physical controller | Unavailable / unverified; standard-pad states simulated |
| Touch contacts | Browser protocol multi-contact tests; not a physical device |
| 60/120/144/240 Hz physical displays | Unverified; controlled render schedules only |

Wine 11 Staging verified the original intro/menu/process handoff using a working
copy. WineD3D cannot provide a reliable native race image on this machine, as
the user warned. No full visual, audio or handling parity is inferred from it.
Original bytes/configuration and bounded instruction execution remain the
authority until a trustworthy native gameplay baseline is available.

Rendering now uses original RGB565 texture packing, including gamma and the
protected-black rule, and a real RGB565 scene framebuffer for per-write blend
rounding. The former `.5` key-mask cutoff is replaced by the documented
historical driver's nonzero-coverage rule. Focused instruction, pixel, effect,
MSAA and shadow checks are recorded in
[the precision follow-up](research-native-texture-precision.md) and
`evidence/texture-precision/validation.json`; no full suite or build was run for
this source-only change. RGB555 is also tested in the converter; RGB565 is the
chosen browser device profile. HUD meshes and glyphs now blend into an RGB565
composition target; see [the HUD follow-up](research-hud-framebuffer.md). Exact
historical GPU filtering/rounding and menu HTML remain outside pixel-parity claims.
The original leaves most
weather UVs and several stream fields uninitialized; the port initializes
those undefined fields to zero. These policies are not claimed as pixel parity.
Shipped fog is disabled (`FOG=0`); custom nonzero fog and the old software
renderer are outside the active accelerated-path validation.

The earlier 36-case control-only reports used the historical runtime after
shared-RNG audio, scenery, weather, explosion, stream and squash integration.
Their source hashes identify that checkpoint, which predates the current
constructor reset and 72-case audit. In that earlier checkpoint, shortening
England's test-driver steering look-ahead from `.7` to `.5` qualified its timed
and duel attempts without production edits. Those historical outcomes do not
establish current qualification: the later retained hard England timed run
finished second and did not qualify. See `full-race-results.md` for those
historical results. Every retained route follower only supplies ordinary controls;
it never teleports, forces pickups or changes race rules.

These separate course/mode completions and controlled UI transitions are not
an uninterrupted 24-stage Adventure playthrough. The conservative normal-race
driver usually does not qualify on medium/hard; source difficulty/qualification
checks and race completion are reported independently.

The original country/character loading images and seven progress frames are
used at their source 640×480 rectangle. Browser asynchronous load milestones
drive the original configured percentages; this is a host adaptation and does
not reproduce the elapsed loading time of a Windows installation.
