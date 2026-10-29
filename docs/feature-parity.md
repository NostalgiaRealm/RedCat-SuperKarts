# Feature inventory and parity

Status is deliberately split: importing content does not implement its behavior,
and a source comparison does not establish a complete native-process replay.
The inventory below covers active shipped content and documented inactive paths.
Historical long-run results below retain their source checkpoint. The earlier
follow-up build, refreshed checks and confirmed corrections are recorded in
`research-followup-audit.md` and `../evidence/followup/validation.json`.
The subsequent Germany/France/Italy completion, restored jumps and authorized
player rescue safeguard are recorded in `research-race-completion.md` and
`../evidence/race-completion/validation.json`.
The historical all-track/difficulty/mode audit is recorded in
`research-full-race-matrix.md` and `../evidence/full-race-matrix/race-matrix.json`.
That report retains source and asset hashes for its fixed-25-ms checkpoint:
71/72 finishes, with France hard timed incomplete. It does not validate the
later variable update host or recovery changes. The earlier shadow and
requested browser-feature checkpoint is recorded in
`more-settings.md` and `../evidence/more-settings/validation.json`; it does not
re-label earlier race completions as runs on the new source.

Later source corrections and their focused scope are recorded in
`research-variable-update-timing.md`, `research-native-texture-precision.md`,
`player-stuck-recovery.md` and `validation.md`. The movie viewport now preserves
the full original 4:3 image. See [remaining work](remaining-work.md) for the
22 October 2026 audit and the completed
[HUD precision/smoke-test follow-up](research-hud-framebuffer.md). Tests listed below are retained results, not a fresh
whole-project pass on today's source.

The [26 October original-code comparison](full-source-audit.md) adds a
five-module decompilation reference and corrects confirmed menu focus,
name-entry, player update and pause/music ordering differences. It includes
fresh route/drive-data comparisons and focused source checks; it does not
replace the historical full-race results with a new whole-game parity claim.

| System/content | Original evidence | Implementation | Native comparison |
| --- | --- | --- | --- |
| Launcher → intro → menu → race | Native process handoff + Wine working-copy trace | Intro/menu/selection/race/results connected | Startup confirmed; original QuickRace/browser flow passes in source and static build; native full-process race comparison unavailable |
| Intro, win and star movies | ISO Media/movies; settings.ini | All 11 converted; intro and adventure movies connected; shared viewport preserves 4:3 without cropping | Frame counts/cadence/aspect checked; retained final-duel/Max flow checks; local viewport fix checked in 66 movie/viewport combinations and two pixel comparisons |
| Main/options/character/country/adventure/results/highscores | 20 DFM forms, Shellang/Shellimg, native methods | Original forms connected, including results, name entry and adventure | Source layouts/text/art; QuickRace and adventure transition browser checks pass |
| Four playable characters | CHARPICS, CharAnim, native construction | Original body/wheels/driver and sequences connected in races | Native animation gates and actual four-character browser meshes checked; full native race comparison unavailable |
| Six country opponents | game.ini AVAILABLE_CHARACTERS, native menu roster/grid | Original country guest and other three core characters connected on every track | Native roster/grid fixtures; all 18 track/difficulty combinations run |
| Nederland/Duitsland/Engeland/Frankrijk/Spanje/Italië | track.ini MAPS, Etappe0–5 | All extracted, rendered and connected to QuickRace/Adventure | Every course completes all four active modes in control-only tests; no full native lap comparison |
| Three difficulties | Menu labels, Phys0–2.dat, cars0–2.dat, native catch-up and duel modifiers | Original player/NPC tables, catch-up, reaction and duel scaling connected | Complete native handler fixtures at both x87 precisions; composed endurance traces |
| Country race/time trial/star race/duel | Race.ini, ADVSEQUENCE, trigger handlers | Native lap/time/star/duel rules and original opponent counts connected | Native trigger/qualification fixtures; every course has a qualified control-only completion in all four modes on easy |
| 24 adventure stages and unlocks | shellimg.dat, native menu progression | Original sequence, profile matrix, country locks and movie selection connected | 1,085 progression and 480 profile-selection instruction cases; profile/unlock/movie/replay browser checks pass |
| Bonus race identifiers | Menu radio writes,24 ADVSEQUENCE entries, empty mode4 HUD methods | Preserved enum/profile compatibility; no invented playable fifth mode | Bounded shipped-content/PE reachability audit finds no offered BonusRace |
| Acceleration/brake/reverse/steering/grip/handbrake | Native input/force/integration functions and constructor reset | Digital and native analog driving, original active upgrade initialization and shared grip globals connected | Instruction fixtures,128 startup reset paths,72 timer comparisons and all-six-track render-rate traces; full original trajectory comparison absent |
| Ground/wall/kart/scenery collision, jumps/gravity | Wheel, ground, CMP, registered-body functions and active jump table49/52 | Ground, rails, paired kart contacts, type5/6 solids,174 non-solid reactive props and original player jump impulses connected | Native sweep/ground/prop cases plus648 jump callbacks,320 registered crossings and two integer-load cases; texture identity does not add grip or solidity |
| Opponent racing and interactions | npc_ai.ini, active FSM and movement callbacks | Normal/approach/chase/finish/recovery/hit/item/forced-route/catch-up handlers connected, with shared occupancy and RNG | Full handler/decision fixtures; five-minute runs on all 18 track/difficulty combinations |
| Checkpoints/laps/timing/position/results | Native trigger/clock/functions and menu | Pause-aware clocks, lap/time gates, rankings, NPC timers, results and restart connected | Native triggers/ranks/results/time-format fixtures; controlled QuickRace debrief/retry passes |
| Bonus pickup/upgrade/weapon/turbo/euros/stars | BONUS_DATA + native handlers | Spatial pickups, upgrades, projectiles, bubbles, oil/gum, turbo and hit effects connected | Native projectile/effect/fan/item-decision comparisons; all six star races finish with exactly twelve collected stars |
| Power-up pickup/firing audio | Original bank enumeration, WAV bytes, pickup/fire/hit/turbo handlers | Original player/NPC gates, numbered recordings, character replacement and effects FIFO; absent names remain silent | 3,001 original instruction cases, 20 focused tests, 118 controlled WebAudio cases across four players; see research-powerup-audio.md |
| Camera/FOV/transitions | 41e280,41d920,498c00,4acf40 and action callbacks | Authored start path, original key1/2/3/4 views with Shift gates, persistent camera selection, finish/failure transitions and corrected cold clock history |144 combined timer/path,384 mode-transform,1,024 key-phase,8 green and existing camera fixtures; browser keys/hidden body+shadow pass |
| Meshes/textures/lighting/fog/sky/visibility | Original models/maps + native loaders | Original geometry/textures/skies, linear filtering, front culling, camera-facing sector windows and ground-dependent kart/driver diffuse; shipped fog disabled | Source conversion,600 native diffuse cases and render-state/visibility fixtures; no trustworthy full native rendering baseline |
| 16-bit colour and keyed edges | Original RGB converter, display/format selection and contemporary driver documentation | RGB565 texture conversion, scene and HUD composition framebuffers; native gamma/protected black; nonzero key coverage preserves filtered edges | 3,168 original upload pixels, format/state fixtures, 197 GPU samples, effect/HUD/MSAA/shadow checks; RGB555 converter verified separately. HUD glyph/mesh rounding and native order now have focused pixel checks; historical GPU precision remains bounded in research-native-texture-precision.md |
| Character/wheel/object animations | Animation INIs + native animation/transform functions | Source steering/look/brake/reverse/turbo dispatch, synchronous pickup/hit queue rules, wheel pose/spin, scenery rotation and all35 moving scenery paths | Native clocks/gates/transforms/path fixtures; all4 playable drivers display both lean directions and reverse;20 browser event/mesh fixtures |
| Original WinHelp navigation | HLP topic/context/hash/keyword tables and original menu Help handlers | Correct mode-specific contexts; contents, back, index/history and preserved caller drafts; no invented browse sequence | 13 parser tests, nine JS tests and ten browser groups; see research-help-navigation.md |
| Menu speech and modal flow | 65 original sound calls, briefing byte table, original WAVs and menu transitions | All24 Adventure briefings, selected-profile voices, farewell, original stop/wait order and caller restoration | 76 original instruction probes, five focused JS tests, 12 flow groups and 57 existing playback cases; 398 supplied menu WAVs byte-identical. See research-menu-audio.md for host adaptations |
| Original fonts/HUD/menu art | DFM, menu bitmaps, original fonts, Overlay.ini | Menus/help/button masks, race lettering, minimap, bonus/item, animated portraits, 321 and notifications connected | Native hierarchy/glyph/portrait/notification/map fixtures and browser imagery |
| Kart shadows and finish flag | 416270/4260c0, 423230/423280/423450 | Original shadow quad/texture and animated checker overlay connected; resized shadow clipping and opaque canvas presentation corrected | Original texture bytes, ten initializer executions, 200 native shadow poses, 40 full flag frames, source UVs and browser screenshot/viewport-edge checks |
| Recovery effect | Spawn.cpp callbacks, S_SFX texture; explicit user safety authorization | Original shrink/grow imagery and sounds; player overlap rejection and delayed safe-road alternative; NPC return waits at its original destination while overlapping the player | Original fixtures retained; captured stuck cases and seven browser checks cover the deliberate safety exceptions separately |
| Weather, skidmarks and rocket rings |4818c0/482020,426aa0/426db0,481ec0 plus shipped marker/configuration inventory | Rain/snow pools, mode/marker gates, rear-wheel strips and two rocket-ring activation paths connected with original S_SFX image |256 weather frames,320 marker callbacks,520 skidmark frames and six complete explosion traces; browser rain/snow/ring checks pass |
| Racer/turbo/projectile trails |488b40/48a530 and original add/remove callers | Source registration, turbo expiry, rocket streams, geometry and recovery-pose binding connected |960 jet frames,960 ribbon frames,720 manager operations,30 caller branches and16 draw traces; actual WebGL packets checked |
| Scenery squash animations |48e210/48e970 and type43/44/46 callbacks | Original hazard activation, speed clamps, flattening, wobble, rebound and shared timers connected |720 native controller frames and1,920 activation callback cases; browser prop matrix matches simulation |
| World and model draw order |497270/4918f0/430020 | Original road batches, sky depth, scenery order and adjacent kart/shadow/child slots connected |36 original object traces, four road traces and actual browser draw callbacks |
| Legacy halo, generic effect and spark managers | Complete PE references and empty-manager execution | No unsupported activations added | Add/caller entry points have zero decoded references;120 original empty frames emit no geometry and consume no RNG |
| Engine/effects/voice/music/loops/volume | Sound INIs, loose CD audio, DirectShow code | Original FIFO character/effect requests, engine/starter/gear/skid,311 roadside clones, reactive impacts and direct events connected; original source/group mixing restored | All1,220 WAVs decode;327 logical voice names and26 live tick-trigger fixtures play; native mix fixtures and browser PCM checks; whole-race audible comparison unavailable |
| Player profiles/progression/highscores/settings | Native save/result routines | Local storage preserves original profile/highscore/record decisions | Native result/progression fixtures; QuickRace score and adventure profile/unlock/replay round-trips pass |
| Uncapped rendering and independent simulation | Native integer 25ms minimum + filtered absolute-clock delta | Measured variable updates on an independent timer; uncapped interpolated drawing; no fixed catch-up bursts | Six original gate traces and 288 absolute-clock observations; focused integration in research-variable-update-timing.md. Earlier fixed-host six-track traces retain their historical scope |
| Keyboard/gamepad/touch throughout | Original keys + requested adaptations | Keyboard ramps; proportional gamepad and SuperTuxKart-style touch wheel; separate Alt-equivalent pedal and bonus button | Focused multi-touch driving, native handbrake equivalence, cancellation/pause/rotation and four phone layouts checked; CC0 SVGs and generated bonus artwork documented in research-touch-controls.md; physical devices unverified |
| Focus loss/resume/input release | Requested adaptation | Input clearing and paused simulation | Clock/input tests; browser click, Enter and controller Start resume without backlog |
| Portrait/landscape/safe areas/widescreen | Requested adaptation | Original forms rearranged for portrait; separate HUD resolution and aspect-preserving camera | 26 layouts at 320/390 widths; driving orientation/touch checks and HUD bounds above the control band |
| Auto/preset resolution, render scale 25–200% | Requested adaptation | Persistent; original low/high presets retained separately | Actual WebGL buffers checked at 25/100/200% |
| Kart shadows on the road surface | Requested enhancement; original 4260c0 quad kept as the off setting | Optional, on by default: the original quad as an 8×8 grid on the sampled road surface, without depth writes | Grid, France-start placement, mode-switch and setting tests; both modes rendered with and without MSAA; menu save and in-race switch checks |
| Cross-browser/device support | Requested platforms | Retained Linux Chromium and Firefox checks; newer precision checks use Chromium | Updated source Chromium/Firefox/Electron rendering smokes pass; see validation matrix for unverified Windows/macOS and physical devices |
| Original settings transactions and focus | Native Options/Controls/Advanced callbacks and Delphi loaded control lists | Independent commit/cancel, original key images and capture, keyboard-only start information, original main focus and tab order |293 original instruction cases,33 menu browser checks and57 actual menu sample starts |
| Graphics option consumers | Native texture conversion, filter state, weather and alpha-gated effects | Source brightness conversion, world filtering, stateful HUD sampler, particle construction and original effect gates | Source-pixel checks,144 sequential native HUD pairs, four constructor cases, native effect fixtures and browser off/on/off reloads |
| Bubble shell and rescue rendering |457780/457b60,4903c0,4260c0,423010 | Original bubble mesh/blend/lifetime; separate logical and drawn rescue positions for shading/shadow/sky |480 native bubble operations,200 render-coordinate cases, browser hit/cleanup/first-person and moat-relocation checks |

The legacy reachability audit is recorded in `research-legacy-features.md`.
The shipped content has no active ordinary traffic paths, BonusRace menu or
campaign entry, or money purchase interface. The collision damage function is
one return instruction. The supplied motor/tyre/gearbox settings load as one,
but the later race constructor clears all six upgrade switches before active
player physics, opponent initialization and timer setup. The port now follows
that reset; see `research-startup-upgrades.md`. Source damage loading and the
>98 expiry branch remain supported.

The source texture/ground audit is in `research-track-surfaces.md`. Ground
comes from the original sector triangle search; static walls and registered
objects use separate collision data. There is no active player/NPC lookup
that adds grass, mud, water or ice grip merely from a visible texture.
`research-race-sound-coverage.md` separates original trigger reachability,
browser decoding, live playback and the unavailable native audible comparison.

The driving research view skips the menu/start sequence for investigation.
QuickRace has its own connected menu/countdown/results path. Control-only mode
completion, controlled menu/profile transitions and bounded native comparisons
are separate evidence; none is an uninterrupted native-versus-port campaign.
Five menu sound references are missing from the supplied originals; the manifest
records these rather than replacing their content.
