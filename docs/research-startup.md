# Native startup, menus, engine and timing investigation

[Documentation index](README.md) · [Original-code export](../original-source/README.md) ·
[Process handoff](#process-sequence-and-settings-handoff) ·
[Menus](#intro-and-native-menus) · [Timing](#timing-and-render-coupling) ·
[Reference limits](#reference-environment-and-limits) ·
[Camera](#active-player-camera-and-projection)

Evidence recorded 2026-10-20. Original inputs and Spookkasteel reference were read only. All runtime tests use copied game, disc and Wine prefix under `evidence/native/runtime/`.

## Artifact identity and reproducible inspection

The [five-module original-code reference](../original-source/README.md) now
provides the consolidated C/assembly export and reproducible verification.
The earlier paths and recovery notes below retain their investigation history;
use the new reference to navigate the complete identified function inventory.

`evidence/native/metadata/*.json` records hashes, import tables, sections and entry points. The launcher `RCSK.exe`, menu `rcskmenu.dat`, race `rcskspel.dat`, and legacy `RCMovie.dat` are all native Windows GUI PE32/i386 executables. The `.dat` extension does not mean those files are data archives. `rclemu00.dat` through `rclemu05.dat` are MP3 streams, while `cars*.dat` and `Phys*.dat` are separate numeric binary tables.

| Executable | SHA-256 | Bytes |
|---|---|---:|
| RCSK.exe | `245757e4029e11500f7dddfa956a4a36dfc40341a39dab38ed770da9792e39ac` | 40960 |
| rcskmenu.dat | `1b6872290010d6357db1b63d6691498b52f8d3def0083e5b42e816a2b7366733` | 759808 |
| rcskspel.dat | `68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f` | 1064960 |
| RCMovie.dat | `2f38f352cbe0af983f9b95bf78eec1edeefc25fd8f727bc67155ba57996d25f7` | 229376 |

Ghidra 12.1.4 exports are stored under `evidence/native/<executable>/`, including function pseudocode, complete decoded assembly, source address mappings and call tables. This is inferred C-like code, not source code or a buildable decompilation. `tools/native-export.py` reproduces the initial export using the locally installed Ghidra; `tools/native-ghidra/` contains the export and grounded function-recovery scripts. Additional original instruction entries recovered after initial export: race `0x432460`, `0x4325b0`, `0x416620`, `0x416650`; menu `0x479b78`, `0x479b88`, `0x479b90`, `0x479bbc`, `0x479bd4`, `0x479cd4`. Recovery logs are retained. A successful function export does not establish complete code discovery; some decoded instructions remain outside Ghidra functions, especially Delphi exception epilogues and indirect callbacks.

REA MCP inspection reported Ghidra unavailable because `GHIDRA_INSTALL_DIR` was unset. No host configuration was changed. A separate REA 6.4.0 CLI process with the existing Ghidra directory and explicit `--provider ghidra` produced `rea-launcher-entry.json`, Evidence ID `ev_da3773bea2d2f4087d2e2f6da9ee1e1fc8a90f075aa44f38e1d03ff0f5598981`. The remaining bulk exports are ordinary Ghidra output and must not be represented as REA Evidence records.

## Engine comparison with Spookkasteel

**Confirmed:** SuperKarts has a Delphi/VCL menu, a C/C++ DirectDraw/Direct3D race executable, Davilex `Engine/Prog_*` and `Libs/win3dlib` source-path strings, and a chunked racing world with RMP/OMP/CMP/DMP/PTH files. `game.ini` identifies the old steering/AI model as Autobahn Raser I and the newer one as A2 Racer II; `car_ssr.ini` identifies the M25 engine data evolution. Native files explicitly reference `car_phys.cpp`, `Gm_main.cpp`, `ai_rcr_*`, and `Engine/Prog_tmr.cpp`.

The primary Spookkasteel reference `docs/asset-formats.md` describes Genesis3D GBSP version 15 worlds; `docs/script-vm-investigation.md` describes DaviScript objects. SuperKarts' confirmed formats and race code do **not** match those world/script assumptions. Therefore no Genesis3D collision, Spookkasteel character physics, camera rules or script VM was accepted as SuperKarts behavior. Similar Davilex naming and common media utilities do not prove gameplay equivalence. This is a positive format/code comparison, not a claim that every library function has been compared.

## Process sequence and settings handoff

**Confirmed static and runtime:** `RCSK.exe` creates a full-screen black window and synchronously launches `rcskmenu.dat /FIRST`. The intro is played *inside the menu executable*, followed by the menu UI. Selecting a race exits that menu and causes the launcher to launch `rcskspel.dat` with no gameplay arguments. After a normal race exit the launcher launches the menu again without `/FIRST`.

The dispatch function is launcher `0x4012c0`; wrapper `0x401140` ultimately calls `CreateProcessA` in the CRT process-spawn helper (see `calls.tsv` for the exact call site). Its current-directory argument is NULL, so children inherit the launcher's working directory. Menu exit codes `0x28`/`0x29` trigger the race; `0x2d` opens the obsolete Davilex web page; `0xff` dispatches the separate legacy `RCMovie.dat` with a `RTTMENU\\SHELLTRO.AVI` or `.MOV` filename. That legacy branch is not the observed standard `Intro.mpg` startup route. Race exit `0xff` returns a restart indicator to the launcher.

Runtime `startup-cd.log` contains actual CreateProcess records for `rcskmenu.dat /FIRST` and `rcskspel.dat`; the working directory was the copied installation's `data` directory.

Race function `0x4b1d60` builds the INI path from the **current directory** plus filename, through `0x4cc99d` -> `0x4cc9b0` -> `GetCurrentDirectoryA`. It is therefore the root `data/game.ini`, `data/race.ini`, `data/SndGfx.ini`, and related data files that the race consumes in the tested launch. Root and `data/ini/game.ini` must not be conflated. Race `0x4295f0` reads resolution, debug, track and audio settings; `0x42b*`/Gm_ini helpers read `RACETYPEINFO`, gravity and other rules.

Menu helper `0x479a4c` reads `ini/settings.ini` relative to its executable directory, `[SETTINGS] INTRO_MOVIE`. `0x479bd4` joins `\\media\\movies\\` with that filename. `0x45c7cc` searches CD-ROM drives (GetDriveTypeA == 5) for the requested movie. The menu also checks the specific `intro.mpg` path at `0x479e1c` unless `HELPDESK/COMPLETE_SHELL` bypasses that check.

`runtime/race-before-start.ini`, `race-after-launch.ini` and `race-handoff.diff` preserve an actual RedCat/Normal/Netherlands/Landenrace selection handoff. The selected character changed `PLAYER/car` from 1 to 0 and rewrote the player/AI rows. Existing unrelated profile values were retained by the original program. The copied original profile is not a clean installation, so default settings must not be inferred from it.

## Intro and native menus

`tools/native-menu-resources.py` parses all 20 binary Delphi DFM form resources exactly to end-of-resource. `evidence/native/menu-resources/*.json` contains authored coordinates, component tree, fonts, artwork paths, callbacks, graphic-state definitions, and transparency/region properties. The menu canvas is 640×480. TFRMINTRO's media destination is 640×480; the movie is stretched into that authored 4:3 rectangle by `0x479bd4`/`0x46e230`.

`metadata/intro-methods.json` connects retained Delphi method records to addresses:

| Handler | Address | Behavior |
|---|---|---|
| FormCreate | `0x479bd4` | Reads movie setting, finds CD-ROM, opens player, sets display rectangle |
| FormShow | `0x479b90` | Enables notification and starts player if in ready state |
| FormKeyPress | `0x479cd4` | Stops media and closes intro without inspecting key value |
| FormMouseDown | `0x479cec` | Closes intro without inspecting button value |
| playerNotify | `0x479bbc` | Closes on playback notification when completion flag permits |

**Runtime confirmed:** a printable `a` key skipped a playing intro and exposed the original main menu immediately. `intro-or-menu.png` and `intro-after-a.png` retain before/after screenshots. Other key/button cases are supported by the unconditional handlers but were not separately exercised yet.

The observed QuickRace flow is main menu -> character + Makkelijk/Normaal/Moeilijk -> country + Landenrace/Tijdrace/Sterrenrace -> optional start-information control panel -> race process. Screenshots: `quickrace-screen-2.png`, `country-screen.png`, `race-start-screen.png`. The control panel displays arrows, Ctrl bonus and Alt handbrake. Its `Startinfoscherm weergeven` checkbox controls future display; this is original behavior, not invented browser UI.

Image transparency is per component. Several native image controls explicitly use `clFuchsia` with `Transparent=true`; other title images use black. Many graphic-button definitions set `Transparent=false` and supply a separate RegionLink mask such as `mn_0004z.bmp`. Applying one global magenta policy to every image does not reproduce all native masking rules. See each parsed definition and the runtime screenshots.

## Timing and render coupling

**Confirmed static:** race main `0x4432a0` reads GetTickCount, then busy-waits until elapsed milliseconds are at least **25** (`0x19`). It timestamps immediately before running the game frame. It does not contain a literal 31/32 FPS constant. A 31–32 FPS observed limit is consistent with coarse Windows tick quantization, but the actual interval depends on the reference runtime and must be measured.

`0x42f4c0` calls `0x48f3e0` once, then input/game object handling, AI, cameras, audio listeners, particles/effects, rendering, post-frame actions, and display update. There is one game update per rendered frame in this loop, not an independently demonstrated fixed simulation clock.

The global clock object is `0x67ec70`:

- `0x48f2c0` selects QueryPerformanceCounter/frequency, falling back to timeGetTime at 1000 units/sec.
- `0x48f3e0` computes elapsed seconds and a four-sample weighted smoothing filter: newest 1/2, previous 1/4, older 1/8, oldest 1/8. Samples initialize to 0.1 seconds.
- `0x48f4d0` returns the absolute timer seconds.
- `0x48f4e0` returns smoothed delta capped at **0.1 s** and substitutes **0.1 s** when the value is exactly zero.
- `0x48f520` resets the clock and history after pause; `0x42f350` pauses/resumes 22 game timers around its pause/menu routines.

Race/event clock helpers are a distinct GetTickCount system: `0x42a670` initializes timer duration/direction, `0x42a210` starts, `0x42a280` pauses, `0x42a420` shifts the start to exclude paused time, `0x42a4d0` returns elapsed/remaining clamped milliseconds, and `0x42a700` tests completion. These are not simply the sum of smoothed physics deltas. Mesh animation `0x44e850` also checks GetTickCount against authored frame timing.

### Countdown, green-light and pause clocks

`0x42f930` starts phase 1 with main-loop flag `0x53b9bc=1`, movement flag
`0x53b9e0=0` and player-active flag `0x53be54=0`. During this period
`0x4325b0` still updates progress, ranks, crossing triggers and the first wheel
pose. Its inactive block `0x432b85..0x432c09` clears RPM, low-speed steering
flag, local lateral/vertical/forward speed and yaw rate. It preserves input
state, gear, pitch/roll rates and orientation. It skips input processing,
forces, the second wheel update and hit-effect update. Engine integration and
ground callbacks still execute.

The pre-movement `0x457730/0x457b60` pair only updates active racer bubble
visual objects; it is not the HUD controller. The main frame `0x42f4c0`
prepares and integrates all objects, updates cameras, then renders.
`0x430020` calls `0x467d30`, whose `0x468d30` overlay update visits its
element array, the three special widgets, then `0x464a70` for 321.
Thus HUD/countdown update uses moved actors and the old bonus state.
Bonus pickup/projectile updates `0x4513c0/0x451200` happen after rendering.
Game-action processing `0x420cf0` follows them.

Countdown action update `0x420dc0` submits CHEER to each character and tests
`0x469680` → `0x464fc0` (`countdown.phase > 3`). Its completion callback
`0x420f00` enters phase 0 through `0x42f740`; this enables movement and calls
`0x42f980` to start timers in order 8, 0, 3, NPC timers 9 onward, and timer 18
for race type 1. The first active movement occurs on the following update.
The CHEER calls use virtual slot +0x0c, proven by vtable `0x4d2710` to be
conditional `0x44ce90`, with from/to values 0/0. The action then updates all
character animators again through `0x44a6c0`, in NPC-first/player-last order.
This happens after rendering. Green also performs one extra camera0 update,
then selects mode1; `0x498a10` disables target damping and does not reset
the camera position. `NativePlayerCamera.startRace(body)` represents that
extra update.

`native-game-timers.js` implements the original timer records and exports
`nativeRaceTimerSetup`:

| Timer | Initialization |
| --- | --- |
| 0 | Count up, clamped to `track.ini MAPS` field 10 ×1000 milliseconds |
| 3 | Player race elapsed time, count up, limit `0x0fffffff` |
| 8 | Count down, original `0x42d300` computed route limit |
| 9.. | Each NPC race elapsed time, count up, limit `0x0fffffff` |
| 18 | Race type 1 time-gate countdown, first `TIME_GATES` value in milliseconds |

Timer 8 uses track constants `[0,142,0,110,0,142,0]`. `0x415cf0` reads
racer-record raw offset +0x40 without the gearbox upgrade, or +0x5c with it,
and adds 4 for a motor upgrade. `0x42d300` computes truncated seconds from
`trunc(trackConstant*10)/(speed*(difficulty==0?.4f:.65f))`, then multiplies by
1000. These unusual raw fields and integer truncations are preserved.

Pause `0x42f350` suspends exactly timers `[0,3,8,9..27]`, enters its blocking
pause/requester loop, then resumes those records by shifting their start
timestamps. `0x48f520` refreshes engine absolute time, sets its current delta
to zero and fills all four delta-history slots with `.1f`. The engine clock
is not green-relative: NPC reaction, pickup and turbo timestamps measured
against `0x48f4d0` age across pause, whereas the race timers exclude pause.
The browser host must keep engine/wall time separate from elapsed race time.

`native-game-timer-fixtures.py` executes 2,880 original timer operations
(including pause, restart, zero/sentinel values and 32-bit clock wrap),
80 inactive-player reset blocks and 576 complete native timer
initialization/green-reset cases across all tracks/difficulties/upgrades and
24/53-bit arithmetic. These are instruction emulation, not a Windows race run.

### Finish and result phases

Entering phase 3 or 6 in `0x42f740` does **not** clear either driving flag.
Input polling and player integration continue until phase 4 exits the race.
However, force routine `0x415990` checks the race phase itself: every phase
except 0 and 8 forces the global handbrake on and locally replaces throttle
and brake force arguments with zero. The retained input values are not
cleared. Phase8 instead applies `0x4140b0` velocity damping. The portable
player now receives an explicit phase and preserves these distinctions.
The alternate `0x53be64` branch in `0x4325b0` is not the phase-3 finish flag;
no active write to that global has been found.

Phase 3 schedules `0x41fc60/0x41fd90/0x41fe50`. Its camera is fixed at
logical route entry `playerSector+3`, with Y increased by 40; there is no
source wrap at that lookup. It targets player-local `[0,20,0]` transformed
by the current body matrix, with world up `[0,1,0]`, no smoothing.
`NativeFinishCamera` matches 120 original `0x41fc60` setup and `0x498c00`
tracking cases across all six track geometries at both precisions.

`0x41fd90` initializes its wall-clock timestamp on the first result update,
requires at least 1,500ms, then accepts Esc/Enter/Space and waits for all three
to be released. At 8,001ms it automatically completes. `0x41fe50` marks
the completed race and enters phase 4. Phase 6 instead uses
`0x420730/0x420850/0x420950`: a different camera path, a 1,000ms minimum,
and a required Esc/Enter/Space press with no automatic timeout. Its camera
orbit is separate from the phase-3 finish camera. `NativeFailureCamera`
executes `0x420730/0x420850/0x498c00`, verified by 60 complete camera setups
and 720 orbit updates under both x87 precisions. It begins at player-local
`[0,50,-150]`, targets `[0,50,0]`, and retains body-relative up. It calculates
`frames=trunc(8/entryDelta)`, `increment=trunc(4096/frames)`, starts angle
-1024, and advances that angle after each rendered frame. The next frame
transforms the newly stored local offset; it is not a wall-time orbit.

`native-race-lifecycle.js` exposes the phase switch, result gates and native
pause/requester state machines. The gate epoch starts on its first action
update. Once the successful-result handler has entered its key-release
busy-wait, the 8001ms timeout is no longer tested: the host must suspend the
game loop until release. Only success callback `0x41fe50` writes the
completed flag; failure callback `0x420950` only exits. The fixtures cover
24 original result timelines, 240 phase transitions and six graphical
requester keyboard loops.

`0x42f9c0` disables Escape during phases1/3/6 and P during phases3/6.
P is checked last and wins simultaneous presses. Pause waits for initial
P release, scans all 256 virtual keys, then waits for each encountered key
to be released before returning. The graphical STOPPEN requester accepts
J for Yes and N/Escape for No, each on release. Y is accepted only by the
missing-art fallback. Key helper `0x4b3830` suppresses these unmodified
polls while Shift is held.

The graphical requester uses `[STOPPEN]` in `sndgfx.ini`, not a Delphi
form: `0x470560` maps resolution0/1/3,4,6 to L/N/H prefixes. H uses
`esc_hi`, Yes at150,350 and No at425,350 in640×480 coordinates, with
`ja_u/ja_f/ja_i`, `nee_u/nee_f/nee_i`, and `mncursor`. Positions are read
by `0x4710e0`; `0x470c50` reads bitmap dimensions. In3D both positions and
dimensions scale by screenWidth/640 and screenHeight/480. `0x473820`
initially centers the cursor on No. Image5/1 returns Yes, image8/3 No;
the exact hit test is Win32 PtInRect.

### Loaded switches, constructor reset, difficulty and analog controls

The menu has no motor/banden/versnellingsbak/PhysicsModel strings and does
not overwrite those `Race.INI` settings. Engine `0x42b870` reads the
persistent switches. The supplied installation has motor, banden and
versnellingsbak all1. These are the loaded values, not the values retained
through construction. The later `42d7d0 → 415d70 → 4319f0` player constructor
clears all six upgrade globals at `431ecd..431eeb`, before NPC initialization
and race timers. The active motor, tyre and gearbox indices therefore start
at zero. `evidence/native/startup-upgrades.json` executes 128 original
loader/reset cases and 72 timer comparisons. The earlier port incorrectly
treated the raw loader result as the active state; that conclusion is
superseded by the complete initialization order. These are not difficulty flags.
Menu profile save `0x45a5dc` indexes table `rcskmenu:0x47bd10`, yielding
opponent counts `[4,3,3,1]` for shipped race modes0..3.
Difficulty still selects `cars0..2.dat` and `Phys0..2.dat` directly.
NPC steering `0x414750` reads the player's global tire upgrade and
slip indicator, so those globals must be passed to every NPC update too.

The tail `0x415aea` sets integer slip intensity to
`min(10,trunc(abs(lateralSpeed*.5)))`; handbrake with absolute forward
speed>1 or gear0 with effective throttle>=80 overrides it to10. The
phase-aware force adapter and slip stores were validated with720 complete
original force calls, preserving source float tolerances for the existing
force math and exact equality for slip/gear/handbrake.

Actual analog input is `0x4341d0` (device3), whereas `0x433cf0` is digital
joystick input. The active model receives clamped integer x/y0..100:
steering=`2*x-100` (mirrored sign on reversed-control tracks), y<50 means
brake=`2*(50-y)` and zero throttle, otherwise throttle=`2*y-100` and
zero brake. Handbrake is button bit0x20. It has no keyboard ramp.
`updateNativeAnalogInput` matches1200 original `0x42ef90/0x4341d0` cases.
`nativeAnalogFromNormalized` is explicitly a browser adapter: a normalized
stick and the difference of two triggers map to the native single pedal
axis, rounded to its two-percent steps after the host-configured deadzone.
The WinMM calibration routine's own center threshold is10%; it is not
silently substituted for the user's browser deadzone setting.

The port must preserve these different time domains deliberately. Replacing all code with fixed 60 Hz or blindly multiplying each expression by delta would be unsupported. The original's 25 ms outer wait can be removed for rendering only after simulation behavior and any frame-dependent code are accounted for.

## Reference environment and limits

Reference: Fedora host, Wine 11.0 Staging, Xvfb. Menu/intro ran at 800×600×24 with authored 640×480 UI centered. Race requested a native 640×480 16-bit DirectDraw mode; the first 800×600 Xvfb test failed with `Initlib.cpp(2225): could not set display mode`. A second Xvfb server at 640×480×16 successfully ran the Netherlands race using Mesa llvmpipe (LLVM 22.1.8), with screenshot `race-native16.png`. This is software-rendered Wine reference testing, not a Windows hardware performance measurement.

The working prefix initially inherited `d:: -> /dev/sr0`; Wine removed the manual d: mapping. In the copy only, d:: was removed and d: mapped to the copied disc with Wine drive type cdrom. The original Wine prefix was not changed.

`tools/native-sample-frames.py` passively reads the owned reference process's frame counter at `0x53bab8` (incremented once by `0x430cd0`) and records monotonic-time changes to `runtime/frame-sample.json`. It changes neither executable nor process memory. Poll resolution bounds frame-edge timestamp precision; aggregate frame count is more reliable than individual short intervals.

No complete campaign, all-mode completion, collision parity, controller/device compatibility or original hardware comparison is established by these observations. Native pseudocode and menus provide implementation evidence, not automatic port parity certification.

## Bounded runtime result and user-directed limitation

The 12.0007-second stationary race sample recorded **29.20 frames/sec** in Wine/Xvfb/llvmpipe, with median observed frame edge interval 34.75 ms. This is an environment-specific measurement only. It does not verify the reported 31–32 FPS original hardware behavior and cannot determine whether the host renderer or scheduler is limiting throughput. Native code establishes the 25 ms throttle independently.

The user then clarified that WineD3D does not render the race correctly and asked that time not be spent fixing it. Race runtime investigation was stopped immediately; no visual, movement, lap, AI, collision or handling parity is claimed from this Wine race. All owned Wine and Xvfb reference processes were closed. Menu, intro skip and process-handoff observations remain bounded valid observations. Future physics verification should use the recovered native x86 routines and fixtures, and eventually a known-correct reference environment.

Player-memory locations recovered by the gameplay investigation, retained for a future suitable reference runtime: player index `int[0x53be28]`; object table pointer `int[0x67ee20]`, stride 0xd0; lateral velocity +0x9c, longitudinal velocity +0xa4, yaw rate +0xac, inverse mass +0x90, inverse inertia +0x94; force xyz +0xb4/+0xb8/+0xbc, torque +0xc0; render-object index +0x0c. Render-object table pointer `int[0x6a5c38]`, stride 0xa9, position +0x50/+0x54/+0x58. Input state: throttle float `0x53bd74`, brake int `0x53be04`, steering float `0x53bd70`, handbrake int `0x53bdf4`; gear int `0x507298`, RPM float `0x507290`. These locations were established statically, not validated by reverse-driving the Wine race.

## Menu resource and audio follow-up

`tools/native-menu-resources.py --source <rcskmenu.dat> --output <directory>` parses all20 DFM resources with bounds checks and exact EOF; errors fail nonzero. `tools/native-menu-methods.py` associates17 forms with published method tables and field offsets using Delphi VMT pointers. Output is `evidence/native/metadata/menu-form-methods.json`. `tools/prepare-ui.mjs` packages all20 forms and the11 recovered caption rectangle handlers. The icon-caption handlers return `(trunc((width-60)/2),trunc((height-38)/2),width,height)` as rectangle edges; main tiles use `(0,height-36,width,height)`. Native fonts are Comic Sans MS (source form sizes), not replacement text art.

Button state1 is pressed: draw handler0x45e234 uses `DRAWITEMSTRUCT.itemState & ODS_SELECTED`, plus its active button flag; state2 is focused/hovered. Setter0x45e01c invokes0x453528, which forwards old/new states to the published callback. Generic sound wrapper0x45c668 resolves `data/ini/soundset.dat` and calls `sndPlaySoundA`: arg1=1 uses flags2 (synchronous,NODEFAULT),arg1=0 flags3 (asynchronous,NODEFAULT). Character wrapper0x45c518 uses the selected character's sample table with the same flag convention.0x45c720 always plays generic samples asynchronously.

Pressed callbacks: OK generic44; Back45; Quit46 then selected-character22 async; Help46 then character20 async; Options46 then character23 sync. Main explicit click handlers add character14 QuickRace,13 Adventure,15 Highscore synchronously. Main FormShow0x474b00 plays generic0 on firsttime,1 later; firsttime state is read/written in `ini/settings.ini [FIRSTTIME]`. SelectChar0x4742d4 plays31 first QuickRace entry,53 later (othermode53). SelectCountry0x47004c plays35 firsttime only. AdventureMain0x4762ec plays24 firsttime,25 later.

QuickRace country OK0x46fdf0 invokes0x46222c when start-info is enabled. This creates `TfrmControlSettings` in mode0.0x461858 hides lblHelp,btnDefault,btnCancel and moves btnOk to384,410; checkbox and “Dit scherm niet meer weergeven” remain visible. Mode1(settings) hides the checkbox/label instead. The native runtime reference is `evidence/native/runtime/race-start-screen.png`. After the modal dialog the menu closes with phase4 and launches the race. It does not visit adventure briefing for QuickRace.

## Native integrator and rail collision execution

Player creation0x4319f0 calls0x415f90; constructor0x490130 clears flags, and both callers OR3. Active player uses Euler0x4911a0, not the RK4 branch gated by flag4.0x493110 sets0x680ad8 to the player index;0x491d30 always divides the selected player's frame delta into8 substeps. Planar velocities are truncated to0.0001 once before this loop.0x491530 first calls object+0x54 (player0x4325b0) once; after integration0x491d30 calls0x4932e0 sector update,0x4937e0 waypoint alignment and0x4936a0, whose object+0x58 callback is0x416650 ground placement. Thus the ground callback is after all8 substeps.

`source/simulation/native-integrator.js` matches360 isolated native Euler cases exactly, including original4096-entry sin/cos tables, floor-heading conversion, quantized displacement, local-velocity rotation and force integration.0x4c062b uses temporary CW0x173f (round toward-negative-infinity). CRT initialization0x4be597→0x4c17bc→0x4c8ee9 sets53-bit precision; later Direct3D runtime precision has not been measured. Fixtures explicitly cover CW0x007f(24-bit) and0x027f(53-bit), rather than relying on Unicorn's default CW0. This is instruction execution against synthetic states, not a complete native race comparison.

`source/simulation/native-collision.js` ports the static rail path. CMP0x49ced0 reads position and direction vectors, derives XZ length and yaw;0x4997f0 builds a rectangle x[-10,0],z[-1,length+1].0x499b20 gathers rails from previous/current/next sectors via the PMP collision indices. Native0x499c30 runs both directed corner sweeps0x49a120, then rotation overlap0x49a480; it does not collide against arbitrary render triangles.0x492470 temporarily projects velocity away from an incoming contact, repeats the sweep, restores velocity and provides a displacement override.0x49c220 applies the rail impulse after movement. The reversed sweep really supplies a rail-local contact point; that surprising native behavior is preserved and covered by execution fixtures.

Validation:120 native CMP loader cases,480 point-clipping cases,360 rectangle sweeps,200 composed sweep/projection cases,320 rail impulse cases,360 Euler cases, and410 clock samples. Generator scripts under `tools/native-*-fixtures.py` preserve original PEs. Composed collision fixtures mock only geometry/broadphase and diagnostic logging; sweep/projection/contact math executes original code. Static track rails are implemented; kart-to-kart0x49b9c0 remains separate. These tests do not establish AI, checkpoint progression, race rules or full race parity.

PRNG0x4be6c9 is `(state*214013+2531011) mod2^32`, returning `(state>>16)&0x7fff`; seed setter0x4be6bf. Initial window setup0x4b14e0 seeds CRT time(). **World loading and actor construction precede** the second seed: main0x4432a0 calls0x442fc0 (which calls0x42d7d0), then0x42f930 reseeds GetTickCount. Animation StartRandomX/Y/Z0x43e696/0x43e6e2/0x43e732 consume the construction stream and take modulo2000. Race updates consume the reset stream. A deterministic browser seed must be explicitly identified as a fixture seed; preserving a single stream through construction without this reset is not native startup ordering.

## Active player camera and projection

`source/simulation/native-camera.js` executes the active-player camera formula, validated against200 original0x498c00 cases under both explicit FPU precisions.0x41dee0 creates the player camera and selects0x41e280 mode1: body-relative position offset(0,50,-150), target offset(0,50,0), world up(0,1,0). The position filter converts desired-minus-previous into body local space, scales by(.1,.1,.5), transforms back and adds the previous position. Target smoothing is disabled. These coefficients apply per native frame, with no dt; update the camera alongside simulation rather than independently per render.

Game initialization0x42d7xx passes near1.5,far12500,FOV1.4137166738510132radians to0x4a1a40. Although the projection matrix has equal X/Y scale, **viewport0x4acf40 corrects aspect**: D3DVIEWPORT2 clipX=-1,clipY=H/W,clipWidth=2,clipHeight=2H/W. Thus81degrees is the horizontal FOV; equivalent Three.js vertical FOV is `2*atan(tan(horizontalFov/2)/aspect)`. No geometric stretching is implied by the equal matrix scales. The [Microsoft Direct3D transformation pipeline](https://learn.microsoft.com/en-us/windows/win32/dxtecharts/the-direct3d-transformation-pipeline) describes this clip-volume scaling stage. Browser widescreen can preserve the native4:3 vertical framing and reveal additional horizontal space as an explicit modern adaptation.

### Authored startup camera and countdown handoff

All six PTH files contain a type1 startup camera path. `0x420fb0` selects the
first such path. Its authored durations are9000,6000,6500,6500,4000,6000ms.
`0x443d20` adds1000ms, converts that duration to ticks using the current engine
delta, and rounds down to a complete spline-segment count. This happens during
`0x42f930`, before the first main-loop update. The global timer constructor
at`0x48f125/0x48f12f` zeroes its previous time; `0x48f2c0` initializes the
history to.1 and samples the absolute host clock. The initial delta is therefore
capped at.1 by`0x48f4e0` on an ordinary already-running system. It is not the
first browser reference-clock filtered update.

`0x443e80/0x443db0` select camera6 at the first authored point, target the
player's local(0,50,0), and use world up. The path controller`0x4441a0` waits
1000 wall milliseconds, then`0x443f10` advances using integer25ms wall-clock
ticks, discarding sub-tick remainder when advancing. It samples the old tick
before incrementing; when the new tick reaches durationTicks-2 it skips that
position write and enters the final approach. `0x443ff0` then moves by.1 of
the remaining distance per update toward body-local(0,50,-150), stopping at
distance<=1. Thus the frozen initialization delta and25ms path clock are
distinct, and the authored milliseconds alone do not describe elapsed time.

The path manager runs after rendering/bonuses and before game actions.
`0x443ef0` schedules countdown action1 immediately upon path completion.
Its start`0x420d90` resets the321 controller from its constructor's hidden
phase6 to phase0 and shows the sprites. The countdown action submits CHEER
and advances character animations that same post-render stage, but321's
first movement step is the next frame. Camera6 stays selected throughout
the countdown; green`0x420f00` alone updates and selects the retained
player camera. Camera0 is frozen while camera6 is active.

`source/simulation/native-start-camera.js` reproduces this controller and reuses
the verified scenery Hermite spline.48 original startup executions and12988
updates match exactly at both24-bit and53-bit precision, across all six tracks,
four entry deltas including.1, and varied body matrices. The initialization
fixture seeds a native uninitialized temporary duration with4096: that value
is used only for the tick-zero sample, which equals the first authored point
for any valid nonzero segment duration. The allocated path's actual duration
and all later timing are computed by unmodified original instructions.


### Runtime angle initialization correction and render transforms

The PE initial data contains1024, but this is overridden during actual game
startup: `0x442fc0` calls `0x4ac410(buffer,10,10,0x1000)`, which calls
`0x4a1510(4096)`. That writes integer count `0x4fc8f0`, float count `0x4fc8f4`
and mask4095 `0x4fc8f8`. Thus **4096 units per revolution** is authoritative.
Earlier isolated1024 fixtures measured a synthetic initial-data environment;
the generators and portable kernels were corrected to execute the real startup
initializer and regenerated. `tools/native_probe_math.py` shares this original
initializer, replacing only LocalAlloc with isolated emulator memory.

`source/simulation/native-integrator.js` exports `NATIVE_ANGLE_COUNT=4096` and
4096-entry tables. Original Euler, CMP loader, directed rectangle sweeps,
composed rail collision, and render matrix fixtures were regenerated with4096.
20 focused tests passed after the correction; their stored test cases cover
both24-bit and53-bit FPU arithmetic. This correction does not establish full
native race parity.

`0x42ccf0` calls `0x49f540(0)`, overriding the transform-order PE default1.
Active `0x4a09e0` applies Z, then X, then Y rotations in native row-vector
storage. It truncates each float angle toward zero and masks with4095, composes
via `0x4a2560`, then scales rows via `0x4a26b0`. The portable
`nativeRotationMatrix([x,y,z], {precision,order,scale})` returns that3x3matrix;
it matches480 original-instruction cases across all three orders and both FPU
modes. A Three.js adapter must transpose this storage, rather than substituting
an assumed Euler order. The helper is in `source/simulation/native-transform.js`.

`source/simulation/native-random.js` exposes `NativeRandom(seed).next()` and shared
`.state` with the exact CRT update at `0x4be6c9`;384 draws across six seed cases
match original instructions. Consumers must preserve startup reseeding and
call ordering, as described above. The composed implementation now preserves
construction draws before the gameplay reseed, including rotating scenery,
opponents and weather; see [the integration evidence](research-assets.md).
A deterministic inspection seed is an explicit testing mode.

### Rendering states and visibility

`0x42cff0` selects D3DTBLEND_MODULATE (2) for the hardware renderer and COPY
(7) for software. With shipped `OPTIONS/FILTER=2`, hardware sets both
TEXTUREMAG (17) and TEXTUREMIN (18) to D3DFILTER_LINEAR (2), and SHADEMODE (9)
to GOURAUD (2). Other filter values select NEAREST (1). Software with filter2
returns without changing its cached filtering/shading. None of these settings
selects a mipmap filter. `source/simulation/native-render.js` exposes the choices
and the exact state-cache write sequence.

Mirrored track startup `0x42d7d0` negates the projection X column and sets
CULLMODE (22) to CW (2). Ordinary rendering retains Direct3D's CCW (3) default.
`0x430020` temporarily restores CCW and the ordinary projection for the HUD,
then restores the mirrored world. No CULL_NONE write occurs in these paths.
The local DirectX header supplies the enum values; the
[Microsoft culling documentation](https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dcull)
describes their winding meanings. This is a renderer-state conclusion, not a
claim of complete matching rasterization. The browser's reflected native
coordinate group requires Three to flip its front-face convention through the
negative determinant. The three original sky meshes each contain56 triangles;
all triangle cross-products point inward, so they already face the inside
camera without a double-sided material.

Both world track and object passes call `0x4304d0(2)` to choose their first
visible chunk. It normalizes the active camera chunk's forward vector and the
camera target-minus-position, then compares their dot product with
`float32(±0.5736)`: forward-facing starts at sector−2; side-facing at
sector−trunc(visibleChunks/2); backward-facing at sector−visibleChunks+2.
A negative result adds routeCount−1 once. `0x497ab0` splits the result into
one or two **inclusive** ranges; an ordinary count40 therefore traverses41
chunks. It does not apply a general modulo operation to arbitrary ranges.
`0x496b40` verifies equal RMP/PMP chunk counts and allocates the chunks in
source order, so the exported `groups[].sector` is the chunk index in the
supplied tracks. `0x497270` draws road, land, extra, then rail within each chunk.

Hardware display presets select the `0x4916f0` object traversal through
`0x493130(1)`. It scans allocated engine object indices in ascending order,
checks active (`+0x44`), render-enabled (`+0x3c`) and sector-in-range, draws
the shadow pass, then the object pass. Nonzero blend modes defer to the shared
transparent queue in insertion order. Native camera-sector selection in
`0x41d920` happens using the camera's position **before** that frame's
`0x498c00` update. Camera activation initializes its sector hint from the player.

`VISIBLECHUNKS` initially clamps to10..50 in `0x42bba0`; the shipped value is40.
During phase0 only, `0x42f470` decrements it if `1/delta<10` and it exceeds25
for hardware or15 for software. This comparison has a real precision
difference: float32(0.1) yields exactly10 after a24-bit divide, but slightly
less than10 after a53-bit divide, so the latter can reduce40 to25 even though
the delta filter caps at0.1.

Shipped `OPTIONS/FOG=0` leaves fog disabled and consumes no random value.
`0x422ed0` consumes one CRT draw only when hardware rendering and nonzero fog
are selected; only an odd result enables it. Fog mode1 also selects COPY;
mode2 keeps the current blend. `0x441210` sets the linear fog color0xb4b4c8,
start3.5 and end1000. These constants are static instruction evidence.

`tools/native-render-fixtures.py` executes144 cached render-state cases,
1200 camera-facing window selections across24/53-bit FPU precision,120 range
splits,252 adaptive-count cases, and72 fog-selection/RNG cases. All five tests
in `tests/native-render.test.mjs` pass exactly. Device calls return success;
these fixtures do not render GPU pixels or establish DirectDraw filtered
color-key parity.

### Construction and race random streams

The original main entry `0x4432a0` calls initialization `0x442fc0` at
`0x4432d0`, then race initialization `0x42f930` at `0x4432f2`. Window setup
`0x4b14e0` first obtains CRT epoch seconds through `0x4bf48c` at `0x4b14eb`,
then seeds at `0x4b14f5`. During subsequent `0x42d7d0`:

1. `0x493140→0x496a60→0x497070` loads OMP objects in their original order.
   Types7/43 in `0x43e140` draw for StartRandomX, thenY, thenZ, only for each
   flag equal to1. Each selected angle is `rand()%2000`.
2. `0x415d70` constructs the player (`0x4319f0`), then NPCs (`0x417640`),
   then initializes NPC state (`0x407490`). The NPC generic AI constructor
   `0x403d90` draws only for behavior types2..5; ordinary racers use7..16,
   so this branch consumes no construction random values for them.
3. `0x422ed0` performs the optional fog draw described above.
4. Once initialization returns, `0x42f930` calls GetTickCount and immediately
   reseeds at `0x42f937`, before the phase1/start-camera action.

This is a grounded construction-order audit, not a complete execution trace
of every indirect initializer. The directly reachable random callsites from
`0x42d7d0` are the three rotation calls, the inactive ordinary-racer constructor
branch, and the optional fog call. `tools/native-startup-random-fixtures.py`
executes both original seed callsites and CRT PRNG over64 synthetic construction
draw sequences; the phase1 action always sees the new tick seed. Its test
passes exactly. Synthetic draw counts verify the reset boundary, not a claim
that they are each track's actual initialization count.

Browser menu races can supply current Unix seconds for construction and
monotonic browser milliseconds for the later reseed. Browser milliseconds
have a different epoch from Windows boot uptime; this is an explicit host
adaptation. Inspection fixtures may use0 at both boundaries for repeatability.
