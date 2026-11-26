# The host for rcskspel.dat

What the race needs from Windows and DirectX, and where it is implemented. Addresses are rcskspel.dat's.
The mapping behind this (all 134 imports, the DirectX 5 method table, the boot path) was done on
2026-11-25 from the Ghidra export in `../RedCat Superkarts/original-source/modules/rcskspel.dat/`.

## Process and files

- The launcher starts the race in the installation's `data` folder with no arguments. The race builds every
  INI path from `GetCurrentDirectoryA` (0x4b1d60) and some from its module file name (0x474410), so
  `GAME_DIR` is `C:\RCSK\data` and the module is `C:\RCSK\data\rcskspel.dat` (`win32.js`).
- **Disc check:** 0x4b9a00 reads `getenv("NOCD")` first and takes its first letter as the CD drive; with it
  set, no drive is searched for `\data\redcat.cmp`. The host's environment block is `NOCD=D`, so no patch is
  needed. The C runtime asks for the wide environment first (0x4c7a3e); `GetEnvironmentStringsW` returns 0
  so it takes the narrow block. `D:` reports as a CD-ROM; `D:\data\x` (the archive fallback of 0x4b9af0)
  and `C:\RCSK\data\x` both map to the game folder in `vfs.js`.
- **INI handoff:** the menu writes `race.ini` (race type, characters, track, player) and the race reads it
  with `game.ini`, `SndGfx.ini` and the rest. `source/host/race-setup.js` pins what a race without the menu
  needs; the installation copy's `race.ini` is the recorded RedCat / Normaal / Nederland / Landenrace
  handoff. At exit the race writes `race.ini [PLAYER]`, `[RACERS]` and `[BEST TIMES]` (0x42c4c0).
- A Nederland race reads 28 files (`evidence/headless/files-read.txt`), 186 MB, 97% of it `rcs.img`.
- **Files in the browser** (since 2026-11-25; `source/web/game-files.js`, [`hosting.md`](hosting.md)): of those 186 MB a
  race reads 22 to 30 MB; `rcs.img` (180 MB) and `rc.img` are opened with `vfs.addRanged` and read in pieces
  (CreateFileA takes `vfs.ranged(path)` for a read-only open; ReadFile copies through `rangeRead`), which the game
  worker answers from 16 KB pages fetched by HTTP Range. Before a race it fetches what the race's lists name
  (`public/game/preload.json`, measured on 96 races in Node by `tools/build-preload.mjs`; every file with its size in
  `public/game/files.json`, `tools/build-manifest.mjs`); a read beyond them waits for one synchronous request (128 KB
  at least): 1 to 8 per five-lap race (`tools/checks/loading-full-race.mjs`). The lists and the files come from
  `tools/game-data.mjs` (the CD copy under the installation's names: not the installation's Wine-written `race.ini`
  and `debug.txt`).

## The loop

The race runs in a game worker (`source/web/worker.js`), Spookkasteel's model, chosen on 2026-11-25 over
per-tick hooks on the page's thread: inside a pass of its loop the game waits in loops of its own (the pause
0x42f220, the quit requester 0x473780, keys it waits to see released, the finish screen), and in a worker these
run as on Windows. Input is in shared memory (`source/web/shared.js`), so such a loop sees keys change; while
it waits, the clock follows real time and the thread naps once per 512 polls until input changes
(`VirtualClock.realNow`, `idle` in `win32.js`). The worker runs a pass every 25 ms of real time and does not
make up for late ones.

`race.js`: the CRT runs until WinMain (a hook), which saves hInstance and nCmdShow and throws. The host then
calls init_main 0x442fc0 and start_game 0x42f930, and per tick: the frame 0x42f4c0, the screen-switch check
(0x473460 then 0x473550 on its result), 0x430cd0, the message pump 0x442e80, and WinMain's Ctrl+Q and
Backspace checks. The loop ends when 0x53b9bc is cleared (only 0x42f740(4) does). The clock is virtual
(`VirtualClock` in `win32.js`, kept in whole microseconds): GetTickCount, QueryPerformanceCounter and
timeGetTime all read it, and it moves 25 ms per tick, the minimum of WinMain's gate. Summed as a double it
read 1999 ms at tick 40 and moved the start camera one update late; in whole microseconds the start matches
the JS reconstruction's model (`evidence/checks/start-compare-intclock.txt`).

## Imports added to A2's win32.js

CreateDirectoryA (dead code), CreateProcessA (only with `game.ini [HELPDESK] ENABLE_RRM=1`, returns
FALSE), SetCursorPos and PtInRect (the quit requester's mouse form), ShowCursor, InflateRect, OffsetRect,
GetFocus, SetFocus, ChildWindowFromPoint (dead code), SetWindowsHookExA and CallNextHookEx (0x442fa0 hooks
the keyboard to swallow the Windows keys; the hook is never called). RaiseException and RtlUnwind go to
`eh.js`.

## DirectX

- **DirectDraw / Direct3D:** A2's `directx.js` (IDirectDraw2, IDirectDrawSurface, IDirect3D2,
  IDirect3DDevice2, IDirect3DViewport2, IDirect3DMaterial2, IDirect3DTexture2). Added: `GetRenderState`
  (0x58; the HUD saves and restores TEXTUREMAG, 0x462337). Geometry is DrawIndexedPrimitive triangle lists
  (track 0x497270, meshes 0x4a96b0) and DrawPrimitive strips, fans and lists (effects), all D3DLVERTEX.
  The HUD is 3D (0x4614d0).
- **DirectInput:** only the system mouse (`GUID_SysMouse`, 16-byte DIMOUSESTATE every frame, 0x4318a0).
  A2's DirectInput only knew its own fake GUIDs, so `dinput.js` keys devices on the real GUIDs.
- **Keyboard:** `GetAsyncKeyState` through 0x4b3830 is the only keyboard path (with a Shift rule: a key
  without 0x100 counts only while Shift is up). The bound driving keys go through 0x4b3880 (8 calls from
  0x42ee60, which polls the table 0x53a5b8..0x53a5d4 that 0x42ce10 -> 0x42ec40 fills from game.ini [INPUT] at boot);
  the other 263 calls are to 0x4b3830. Without the cheats option the import answers "up" to the debug and cheat keys
  among them (Race safeguards below). Bindings changed during a race (the flight panel's Instellingen) reach that
  table before the next pass: the page publishes them in CTRL.KEYS/KEYS_SEQ and the game worker writes a change as
  0x42ec40 does, also into 0x4bab80's copy at 0x6aba20 (`source/input/race-keys.js`; the JS reconstruction applies
  new bindings at once, its input.js:71).
- **DirectSound:** `dsound.js`, after Spookkasteel's: play state and positions on the race's clock, so
  GetStatus ends a one-shot sound when its samples are over (the game frees its 60 slots by it, 0x4b4310),
  with or without a sound device. Loading locks from the write cursor of a new, stopped buffer, i.e. its start
  (0x4b4ab0; Spookkasteel's 512-frame lead would rotate every WAV). A duplicate shares its original's samples,
  freed with the last of them (the game releases originals whose duplicates still play). Nothing fails: values
  out of range are clamped, as every failure is fatal to the game. No 3D: the game's 3D-buffer code is
  unreachable (slot +0x34 is never written); it pans and attenuates itself (0x49da60).
- **DirectShow:** `dshow.js`, new. The race music `rclemu%02d.dat` (MP3) through `CLSID_FilterGraph`:
  RenderFile, Run, Pause, Stop, put_CurrentPosition, put_Volume, and one GetEvent per frame (EC_COMPLETE
  restarts it). Playback runs on the virtual clock; durations come from the MP3 frame headers. In the browser both
  run on the sound's clock (`host.soundUs`, `source/web/worker.js`): the virtual clock less the game time that passed
  while the page held the sound (CTRL.HOLD SOUND: a focus pause, whose loop runs the clock in real time while the
  page's AudioContext is suspended; a hidden page; the menu over the race), so the track ends and restarts where the
  page's does and a one-shot effect ends where it is heard, as the JS port's paused track and effects keep their
  place (`tools/check-audio.mjs`, music place). In Node the virtual clock itself.
- **Joystick:** `winmm.js`, after Spookkasteel's. In the browser joystick 0 is a virtual one that is always
  there (centred at boot, when the game calibrates it once, 0x4ba5e0): the pad and the touch wheel move it
  (`source/input/shared-input.js`), and the game worker switches the driving handler to the game's own analog one
  (0x4341d0) while they drive (docs/intentional-differences.md, Input device; `evidence/checks/input-modes.txt`).

## Input on the page

Keyboard, pad and touch hold Windows virtual keys in shared memory per source, so one source letting go does not
release another's (`source/input/shared-input.js`). The pad (`gamepad.js`, standard mapping, after the JS
reconstruction) and the touch wheel (`touch.js`, its artwork, layout and SuperTuxKart wheel formula) also drive
the virtual joystick. The game worker sets a control word while the game waits in a loop of its own (the pause,
the quit requester; CTRL_WAITING) and one for which loop it is (0x53b9f8; CTRL.PAUSE_KIND): in the pause the pad's A
and Start answer it (J, P), in a focus pause also B (N) and the stick or D-pad (an arrow key for a moment); in the
requester the pad and the keyboard move a focus between ja and nee, from nee, by putting the game's pointer on the
button's centre (the stick, D-pad or arrows), and A, Enter or Space hold the left mouse button there
(`requester-focus.js`), B is N; the touch controls step aside so a tap on the picture reaches it as a mouse
click, and in the pause they stay drawn but hold nothing, as the JS reconstruction's (a tap on the picture ends it).
Stoppen holds Esc only while racing or in the arrest (phases 0 and 8). The pad has no Back, as the JS
reconstruction's. On the finish and game-over screens a press on the picture holds Space, as there. A press, by
finger, mouse or touch button, lasts at least 80 ms for the game, which reads keys once per 25 ms pass. A driving key
held (also with Shift) keeps the keyboard's handler, and the pad's and the wheel's actions then reach it as pressed
bindings (`safeguards.js` BINDING_SLOTS), as the JS reconstruction merges its sources per action. The browser keeps
every key but the bound ones (and Space and C while flying, and the arrows, Enter and Space while the game waits), so
Tab moves the focus, as in the JS reconstruction.

The HUD's layout (`hud-layout.js`) is the JS reconstruction's (its `source/race-hud-layout.js`): every group is the
640x480 HUD at one scale in a frame placed at an edge, the top or the middle (portraits and stars top left, the race
times top right, the bonus box and the minimap above the bottom, the start lights, arrows and notices centred). The
page measures what that layout needs as the JS reconstruction's `measureRaceHudLayout` does and passes it in shared
control words: the safe area's insets (`env(safe-area-inset-*)`, at least 8 CSS px at the top and sides of an upright
screen; CTRL.INSET_*) and the touch controls' band (their box less the bottom inset; CTRL.CONTROLS_L). The scale
follows from the shape: an upright screen fits 480 of the HUD's 640 pixels across its width (the start lights and
arrows then sit in the middle of the height, the stars 110 pixels lower), a landscape one the whole HUD in the height
above the band, except the race times, which keep the height without the band. A group grows only with its scale
(+0x10/+0x14), its Width/Height (+0x7c/+0x80, which place its children) and its strings' +0x7c (glyph spacing, which
follows the root's ScreenWidth, 0x463bb0) together (`evidence/checks/hud-scale-levers.txt`). Each group of meshes is
also cut to its frame, as the JS reconstruction's viewport of the group cuts it (its race-hud-meshes.js:251-258; its
strings are not cut): the composite draw 0x458760 draws each child of Screen through 0x458550, which first calls the
child's callback +0x30 (0 in the HUD); while laid out, that is a host thunk (`m.makeThunk`) that hands the group's
frame to the recorder (`hudClip`, CMD.CLIP before the next HUD draw that needs another cut), and the renderer
scissors the group's draws to it. The bonus box, whose model is 3D (z up to 3 in flight), is not moved in memory: the
renderer draws it with the frame as the viewport and the game's 4:3 clip (CMD.CLIP mode 2), which is the JS
reconstruction's drawing of a group exactly. The touch controls' style rules are the JS reconstruction's
(`source/style.css`, `source/dev/race.html`; `tools/checks/hud-touch-boxes.mjs` compares their pixels).
`tools/checks/hud-scale-check.mjs` holds every HUD draw and its cut to the JS reconstruction's own `raceHudLayout`, imported
read-only (`evidence/checks/hud-scale-*.txt`); `hud-shots.mjs` takes both ports' HUDs in the same shapes
(`evidence/frames/hud/`).

## Sound on the page

The game worker queues what the page must play (`host.audio`, `host.music`) and posts it once per frame, and
once per nap while the game waits inside a pass. `source/web/audio.js` plays it with Web Audio: PCM buffers made
at their first play, duplicates sharing their original's, DirectSound volume and pan as hundredths of a decibel
(pan turns the other channel down), frequency as playback rate; the music track decoded from its MP3 and started
at the offset the worker's DirectShow graph is at. The game's pause (0x42f350) stops no sound (only its timers
and a DirectShow poll, see the JS reconstruction's `tools/native-pause-audio-fixtures.py`), so engines and music
go on under "pauze" as in the original. A focus pause (the runner presses P for a blur, a hidden page or a lost
pad) is silent instead, as the JS reconstruction's: the page suspends its AudioContext until the game leaves its
pause loop (`race-runner.js` focusMuted, CTRL_WAITING 1 -> 0).

Music and effects levels changed during a race (the flight panel's Instellingen) reach the race through the page's
control word CTRL.VOLUME and `source/host/live-volume.js`, which the game worker calls before a pass: the effects
through the race's own 0x437e30 on the voice controller (0x53bf70; every source outside MOTOR and MUSIC, 0 switches
the voices off), the music through 0x431610 and 0x48f010 (put_Volume(49 p - 5000)); at 0 the graph is paused through
its IMediaControl and a later level runs it on, and a race that started at 0 starts its track with 0x48edc0 and
0x48ec20(1) as init_game would. Both go into race.ini [GAME_SETTINGS]. After boot the worker reports race.ini's levels
with 'running' (an enabled FX_VOLUME 0 is 75 then, 0x437560), which the menu adopts (`onEffects`, the JS port's
main.js:716-719). `tests/live-volume.test.mjs` runs these on a race booted in Node.

## Free flight

The JS reconstruction's Vrij vliegen (`settings.freeFlight`; its `source/simulation/free-flight.js`,
`race-simulation.js:260-275, :599-637`, `driving-view.js`) is `source/host/free-flight.js`, with no game code
changed and no recompiler hook of its own (it wraps two existing thunks: GetAsyncKeyState and the HUD pass's guard,
as `race.js` does; the kart parts come from `render-replay.js`, below). `Race.tick` asks it before every pass, after the clock moved. With the setting on (CTRL.FLIGHT,
from the page) it takes off at the first pass that starts in phase 0 (green came in the pass before);
while it flies the host does not call HANDLE_GAME 0x42f4c0 but a pass of the original's pieces: the kart's render
object placed (level, yaw only, from the native 4096-step sine table; the minimap's dot 0x53be44 with it), its chunk 0x4932e0, the cameras 0x41d920, the render 0x430020
(the HUD pass included), Esc and P as 0x42f9c0 reads them, the present 0x430470, and the pause 0x42f350 when one of
them asked for it. No object pass, AI, timer, bonus, lap or sound update runs, so the race stands still: rand, the
opponents, every timer, the laps, GetTickCount and the sounds' plays are unchanged over 80 flight passes
(`tools/checks/flight.mjs`, `evidence/checks/flight.txt`). The motion is the JS port's: 650 units/s, 400 up and down,
1.5 rad/s turning, the arc integrated exactly, the turn reversed on a mirrored track.

- **Take-off** saves what the flight changes (the racer record, 0xd0 bytes, and the render object, 0xa9, of the
  player; the render objects of every kart's parts; the minimap dot; the ten cameras, 0x178 each, their slots 0x508620..0x508677, mode 0x4e3064,
  0x4e2ac8; the visible chunks 0x53b9d0), sets the chase camera 0x41e280(1) with its eye and damped eye (+0x08,
  +0xa0) at (0, 20, -150) in the kart's frame (the JS port's `NativePlayerCamera.reset`), zeroes the kart's speeds
  (`advanceFreeFlight` does at every step), sets the shadow slot +0x28 to -1 (0x4918f0 then draws no shadow) and the
  visible chunks to the chunk count less one (every chunk once: Nederland 463 draws against 130), freezes the clock and
  holds the sound.
- **HUD and colour:** the HUD stands still, as the JS port skips `hud.update` and captures its meshes with dt 0
  (`driving-view.js:231-234`): in a flight pass the HUD pass 0x467d30 sees a frame time of 1e-30 s (0x48f4e0 reads 0 as
  0.1 s), so what its elements add up per frame (the start lights 0x464a70, the notices 0x46c910 and others) stays;
  its times read the frozen clock, and the minimap's dot follows the kart. The start lights therefore stay green in the
  middle while it flies (the JS port's stay red: its HUD drew the frame before green), and a BackArrow that the HUD
  starts while flying the wrong way stays at alpha 0. The kart's lit colour (racer +0x34, which 0x4903c0 eases towards
  the light under it at dt per draw) is written back to its take-off value before every flight pass, as the JS port
  leaves the flying kart's `captureColor` out (`driving-view.js:264`); without it the kart dimmed from ff to cb.
- **The parts** (wheels and driver, slot +0x64.., +0x8c of them) are render objects whose matrix the object pass
  leaves relative to the body; the draw 0x490d40 multiplies it by the body's in place (0x4a2560) before drawing, so
  between passes it holds the world matrix. Flight renders run without an object pass: `render-replay.js` (Renders
  without an object pass, below) puts back before each one, for every kart, the matrices the render before found, so
  the original draw puts the flying kart's parts on its flying body and the opponents' on theirs (every kart whole, as
  the JS port draws them; before it the opponents showed without wheels and driver in flight, and the flying kart too
  in the flight pause). The flight pause's render runs through `again()`, as the pause entry's: the flight picture
  with the notice (`tools/checks/flight.mjs`: the scene draw for draw).
- **Clock:** `VirtualClock.freeze()`/`thaw()` (`win32.js`): GetTickCount, timeGetTime and QueryPerformanceCounter stand
  still while it flies and go on from there after it (`offsetUs`, the JS port's `flightClockOffsetMs`); DirectSound
  and DirectShow keep the raw clock, so the music plays on. Around an in-flight pause the clock runs (the requester's
  button waits 100 ms on GetTickCount, 0x473fb0); the pause takes its time out of the timers it stops (0x42a2f0,
  0x42a420) and the frame time it zeroed (0x48f520) is set back to 25 ms, which 0x48f4e0 would read as 0.1 s. Before
  the thaw a clock reading lets the browser's catch-up with real time (after 40 ms in a pass) happen while still
  frozen, so it stays out of the timers (the lap time stays at the millisecond over a pause, `flight-browser.json`).
  The pass draws the pause tail's render (HUD still) and present before the pause, so "pauze" shows
  (`evidence/frames/flight/flight-pause.png`).
- **Sound:** `host.dsound.hold(true)` (`dsound.js`) stops every playing effect where it is; the game still sees it
  playing at that place (GetStatus, GetCurrentPosition), so no slot is freed; a sound started meanwhile waits at its
  start. `hold(false)` plays them on from there.
- **Keys:** GetAsyncKeyState is wrapped (around whatever binds it): in a flight pass the game sees only Esc, P and
  Shift (0x4b3830's rule); in the pause everything; after landing Space and C stay hidden until let go (they lifted
  the kart; Space is the original's horn in 0x42f9c0).
- **Landing** puts every saved byte back, so the kart stands where it took off with wheels, suspension, chunk, camera
  set-up and visible chunks as they were; then, as the JS port (`race-simulation.js:630-633`), resets the player's
  camera eye to (0, 20, -150) behind the kart, level at the take-off yaw (`restoreFlightPose` levels the body), sets the
  active slot's last chunk 0x508648[slot] to the kart's and runs one camera update 0x498c00 (ecx = the camera) with the
  kart's matrix levelled for it: the eye equals the JS port's `reset` and `step` to 0.00 units on six tracks
  (`tools/checks/flight.mjs`), and the next pass's update makes the second, as there. Then it zeroes the speeds +0x9c/+0xa0/+0xa4, the yaw rate +0xac, the driving input
  words, rpm and gear (the engine as before the start: the next pass idles at 800 rpm in gear 0), thaws the clock (the
  elapsed race time goes on from where it stood) and lets the sound go. The quit requester's J during flight ends the
  race; `Race.finish` lands first (without zeroing), so exit_main sees the race as it was.

The game worker passes CTRL.FLIGHT to `flightWanted()`, reports CTRL.FLIGHT_ACTIVE after every pass and builds
`flightInput()` from the driving keys bound in the settings (only while Shift is up), the virtual joystick (its ±10%
window taken off) and Space and C, which the pad's LB and RB and the touch buttons Omhoog and Omlaag hold while it
flies. The page shows the JS port's panel (`#flight-controls`) and `#flight-touch` while it flies and the game does
not wait in its own pause or requester; Instellingen holds the race under the settings (`runner.menu(true)`: the game
thread and the sound held, every input let go and the runner's input off) until OK or Terug; Stop vliegen stores the
setting off and the next pass lands. `tools/check-flight.mjs` runs it all on the menu page.

## Renders without an object pass

`source/host/render-replay.js` wraps the render 0x430020 (`hook!Render`, tools/recomp/build.py GAME_HOOKS; callers
0x42f663 and 0x42f703 only, and free flight's `m.call`). The render's draws change state in place: the racer draw
0x490d40 multiplies every kart part's matrix (slot +0x64.., count +0x8c, render object +0x10) by the body's
(0x4a2560), 0x4903c0 eases the kart's lit colour (+0x34), 0x426e50/0x426db0 ages the skid marks (0x14 x 0x1910 bytes
from 0x50dfb0), 0x428a00/0x4282e0 moves, sorts and ages the smoke clouds (0x46 x 300 from 0x535020), 0x48a170/0x489f50
narrows and cuts the jet streams (container u32 0x67da6c). Only the object pass 0x491530 sets the parts back to body
relative, so a render without it (the pause entry's, return 0x42f708, and every flight render, return 0) drew the parts
on the body twice: every kart without wheels and driver.

- Around every render it notes, per kart the render drew, the part matrices it found and the ones it left, and after a
  render that a pause render may follow, copies of the colours and effects (found and left).
- Before a render that is not HANDLE_GAME's own (return 0x42f668): every kart whose parts still hold what the last
  render left gets back what that render found (the parts land on the body, the flying one in flight).
- A pause render (the pause entry's, and free flight's pause render through `again(fn)`) also gets back every colour
  and effect that still holds what the render before left, and its HUD pass sees free flight's still frame time, so it
  draws that render's picture with the notice, as the JS port pauses on its last frame and captures the notice. The
  draw code is a function of what it found: after it every piece holds what the render before left
  (`stats.effectsDiffer`, 0 in 36 pauses on six tracks), so the pass leaves the game as one render does.
- What the pass's own code changes between the two renders stays (0x451200 turns the bonus boxes, scenery moves).
- Stats (`host.renderReplay`, the worker's `stats.replay`): renders, karts and effects put back, and `displaced`, the
  karts drawn with a part more than 60 units from the body (none: the farthest measured is 30).
- Costs a racing pass two copies of about 150 KB (skids and smoke) and the five karts' 25 matrices.

## Race safeguards

`source/host/safeguards.js` (installed by `Race.instantiate` after `eh.js`; `beforePass()` runs in `tick()` after
`host.beforeTick`, before free flight) puts the JS reconstruction's three race safeguards around the original code
(docs/intentional-differences.md: Debug and cheat keys, Key bindings, Stuck recovery, NPC speed overflow). What they
did goes to the page in CTRL.SAFE_STUCK, SAFE_NPC and SAFE_KEYS and in the worker's stats (`gameStats.safe`).

- **Keys.** The GetAsyncKeyState import is wrapped. The recompiler stores every call's return address at [esp]
  (`lift.py`, build.py's default `debug_ret`), so a call from 0x4b3830 returns to 0x4b3848/0x4b3850/0x4b3860/
  0x4b3868 and 0x4b3830's own caller is at [esp + 0x10] (push esi, push edi, the argument). Without the cheats option
  (`host.cheats`, which the game worker sets from CTRL.OPTIONS & OPT.CHEATS before every pass and the module reads
  once per pass: Ctrl+E+N waits inside a pass for a digit) a caller outside the 39 allowed calls (`KEY_ALLOW_CALLS`:
  cameras 1-4, P and the pause loop, Esc and J/Y/N, the requester and its mouse buttons, Space, the phase 3 and 6
  keys) reads "up"; the call still counts as a poll for the clock's naps. Calls from 0x4b3880 are not filtered but for
  P and Esc (its key polls return to 0x4b38da/0x4b38f0 with the key at [esp + 4]; with or without the option): bound,
  they do not drive, as the JS port handles them before its bindings (input.js:64-65), and still pause and open the
  requester through 0x42f9c0's own polls. Calls from host code (return address 0) and from anywhere else are not
  filtered; an unknown caller is logged once. Without `host.cheats`
  (the Node checks) the keys answer. The pages: `RaceRunner({ cheats })`, on by default on `/dev/race.html`
  (`?nocheats`), only with `?cheats` on the menu page.
- **NPC speeds.** hook!NpcPrepare (a wrap of 0x406940, build.py GAME_HOOKS) keeps the racer's three speeds before the
  original body and sets to 0 one that was finite before and is not after.
- **Stuck recovery** (`source/host/stuck.js`). `StuckDetector` and `selectRecoveryDestination` are the JS port's
  `PlayerStuckRecovery` and `selectPlayerRecoveryDestination` unchanged; `GameTrack` gives them the track from game
  memory and the original's own queries (nearest sector 0x450500, heading 0x493540 with the kart's yaw put back,
  sector 0x4977d0, face 0x495fe0 and height 0x496290 as 0x430ff0 calls them; "road" is 0x495fe0's first face list,
  the JS port's 'road'; rails as 0x4997f0 and bodies as 0x499630 collect them for 0x499b20, with the mesh box of
  0x490ce0). The input is `host.driveInput()` (the game worker: per action the larger of the bound keys, none while
  Shift is held and never P or Esc, and the pad's and the wheel's pedals apart and without the ±10% window, IN.JOY_GAS
  and IN.JOY_BRAKE, as the JS port's step reads InputState.snapshot; `source/input/race-keys.js` stuckInput;
  `tools/checks/full-race-gaps-lib.mjs`: the scenario's keys); without it the detector stays off. On a trigger the module queues the original rescue with 0x48dce0(player, 0x80): the flag byte
  (+0x11ac, read only at 0x48ccbd) marks it, and hook!RescueUpdate (a wrap of 0x48ca60) runs grow frame 0 of a
  marked entry itself: the JS destination (or the original's blocked branch: frame 19, table 0x67e430), the original's
  glue (velocities 0, table 0x67da70, frame 1, rings 0x48d610), the kart level and standing, wheels re-seated
  (0x507f48), controls 0, distance 0x53be70 not above the destination's, finish 0x53d1d8 not newly armed, camera
  0x41e0b0. All other frames are the original's; when a marked entry finishes, forward speed and rates are set to 0
  and its place is checked again (taken: shrink again). The game's pause and requester (polls from 0x42f220/0x42f290/
  0x473820..) start the 8 s again. Render objects have a stride of 0xa9 bytes: their fields go through `m.view`.
- **Pause entry** is not here: a byte patch in the build (build.py GAME_PATCHES 0x42f6d8).

`tools/check-safeguards.mjs` checks all of it in Node (and with `--browser` through the pages). `tools/check-keys.mjs`
checks the bindings changed during a race, P and Esc as bindings, the stuck recovery's input (Shift, the pedals) and
focus loss by race phase (the original's P in phases 0, 1, 8; the runner's hold on the result screens 3 and 6).

## Rendering

No GPU object lives in the game worker (it never returns to its event loop, and a picture made there is never
freed). `source/render/recorder.js` writes every Direct3D call and every 2D change of a screen down and sends
one message per frame to the render worker (`source/web/render-worker.js`), which replays it with
`source/render/gl-renderer.js` on the page's canvas. The screens keep their pixels in game memory (the mouse's
save-under reads them back), Flip swaps the front and back memory as DirectDraw does, and the renderer keeps two
colour buffers and one depth buffer to match, so a frame that changes part of a screen (the requester's buttons)
keeps the rest. A 2D change of the front screen is on view at once (PRESENT).

**Screen shape, resolution and MSAA.** The page fills the window in any shape and asks the render worker
for a drawing size: the canvas's size in device pixels (`?res=auto`, at most about a megapixel on touch
devices), every device pixel (`?res=full`) or the largest size of the canvas's shape inside `?res=WxH`, times
`?scale=25..200` percent, with `?msaa=2|4|8` (until the menu has these settings). The screens and the display
buffer are renderbuffers at that size, multisampled with MSAA and resolved through a single-sample buffer
(the canvas, made without alpha, cannot take a multisampled blit directly). The world's draws fill the whole
buffer: on a wider screen the clip volume is widened (more at the sides, the original's vertical framing), on a
taller one heightened (more above and below), as A2 Racer 4 does; at 4:3 it is the original's. Nothing in
the game culls by aspect (`tools/checks/wide-cull.mjs`), so this needs no game change. The HUD is drawn with the
same clip: around its draw call (m_Manager.Render 0x4614d0, wrapped in `race.js`) `source/host/hud-layout.js`
places and sizes its groups (direct children of the "Screen" composite at 0x53a5fc: Portraits, Stars, NUMBERS,
Map, Bonus, 321Timer, the arrows, the notices) for the page's shape in game memory, as the JS reconstruction lays out
its HUD (above), and puts them back after it; the page passes the shape through shared memory (CTRL.ASPECT). When the
shape changes while no pass runs (the game in its pause loop 0x42f220, or the race held between passes: a result-screen
hold, a hidden page, the menu over the race), the game worker draws the held picture again with the HUD laid out anew
(`source/web/worker.js` repaint: the render 0x430020 as a pause render and the present 0x430470,
`source/host/render-replay.js`; the page's resize wakes it through CTRL.PAUSED), between passes with the clock's real
time held at the last pass's start, so a hold adds no game time; in the quit requester it sends the front screen's
pixels (its form) again, as the render worker keeps no 2D frame to draw at a new size. A render from inside the pause
loop draws the pause entry's picture draw for draw and leaves the race after the pause as it was
(`tools/checks/pause-repaint.mjs`). Screen-space vertices and 2D screens stay in the
largest 4:3 area in the middle; a 2D picture of the whole screen (the requester) blacks out the sides, and the
pointer maps through the same area. The finish flag
(ten strips of 34 vertices from 0x5091a0, fixed to the camera, sized for 4:3) is grown evenly by the
widening or heightening so its edges stay off screen (A2's `scaleFlag`).

**Smoothing.** The game draws a frame per 25 ms pass; a 60 Hz display would show some twice. The render
worker keeps the last two frames of 3D draws and shows a blend of them on its own `requestAnimationFrame`,
one pass (25 ms) behind the game (A2 Racer 4's model): each draw of the newer frame is paired with a draw of the
older one with the same texture, primitive and counts (so karts that share a mesh do not swap): first its exact
twin when it did not move (same world matrix and vertices), then the rest by distance, closest pairs first over
all draws of that kind (of draws that start at the same point, the most alike). Its world matrix, the camera's view
and projection, and its vertices when they move by themselves (smoke, sparks, animated meshes) are blended. A draw
without a partner (something that came into view, a skid strip that grew; about one every two passes) keeps its
newer place but is seen through the blended camera of the draws around it; until 2026-11-26 it was drawn with the
newer pass's camera, up to a pass ahead of the scene, so stationary objects snapped out of place and back
(`tools/checks/pairing-probe.mjs`). A kart's body, wheels and driver are tagged with their kart (`shadows.js`, by
their drawn matrices) and pair only with the same kart's part at the same place on it; until 2026-11-26 they paired by
nearest place over all karts, so a wheel took another kart's wheel in a pack, or its own other wheel when a turbo on
Normaal or Moeilijk carried the kart further in a pass than its wheels lie apart, and glitched
(`tools/checks/wheel-probe.mjs`). Karts, what follows them and the camera are cut loose only by a jump of more than
150 units (a rescue is 400 and more). One that moved more than 30 units in a pass (a jump), or a vertex more than 10
units from its last place shows the newer frame; a turn of more than 20
degrees per pass (a wheel) keeps the newer rotation and blends the place only. The HUD's draws (the pass
0x467d30, wrapped in `race.js`) are never blended, so it changes from one pass to the next as in the original.
Every frame is still replayed once, exactly, into the flip chain; the blend goes to a display buffer of its
own, and frames with 2D changes (the requester) are shown as they are. `?nosmooth` turns it off.

**Look back** (`source/host/look-back.js`). Key 3 held selects camera mode 5 through 0x41e280; that function is a wrap hook (`CameraMode`), and after the original sets mode 5 the host writes A2 Racer 4's look-back framing into the camera (place +0xbc: 0, 33, 140; aim +0xcc: 0, 25, 0). docs/intentional-differences.md, Look back.

**Kart shadows and engine lights** (`source/host/shadows.js`; the JS reconstruction's Schaduwen op het wegdek and
Motorlicht volgt de kart, both on by default; docs/intentional-differences.md). The recorder asks a tagger about every
draw outside the HUD (`recorder.tagger`), and a tag (`CMD.TAG`: id, flags, the owner's place) goes before the draws it
knows:
- The shadow. 0x4918f0 calls the callback at 0x6802c4 (0x4260c0, registered by init_main) right before it draws each
  racer, and 0x4260c0 draws the S_SHADOW quad once (DrawIndexedPrimitive, 4 vertices, indices 2,0,3,1,0,2) with the
  kart's drawn matrix, its Y on the sector's fallback plane (0x494b70), which can lie under the road (Frankrijk's start:
  Y 0, the road at 20 and more). 0x4260c0 is a wrap hook (build.py GAME_HOOKS 'KartShadow'); its body runs as it is.
  With the setting on, the tagger draws instead an 8x8 grid over the quad in world coordinates (TRANSFORM to the
  identity before it, the game's world matrix again after it), every point 0.25 above the ground the game's own
  triangle search finds under it (0x4977d0 the sector from the kart's hint +0x1c, 0x495fe0 the first upward face,
  0x496290 its height; the rescue code's sequence, 0x4169cb..0x416a55); texture, colour, blend states and draw order
  stay the game's. The renderer draws it as a decal: polygon offset -1/-4 and no depth writes (the JS
  reconstruction's material). The calls leave game memory as it was (`tools/checks/shadows.mjs`: identical on and
  off). In free flight (`host.flightActive`) the player's shadow draw is left out. Footprint: 0x4260c0 takes the
  quad's X/Z corners from the box record (u32[0x6a5ee0] + mesh*0xbc, corners +0x4c, +0x40, +0x10, +0x1c) of the mesh
  0x490ce0 names for the kart object, its animation frame's `redcar.d3d` (28 x 37 units), but 0x4a0d80 draws the
  object's +0x99 mesh, a copy of `kart03.d3d` (41 x 64; every racer, country, character and race type, measured), so
  from the chase camera most of the original quad lies under the kart. The grid takes the same corners from the box of
  the mesh the game draws (`bodyMesh`: the slot's +0xcc while +0xc8 and +0xcc are set, 0x490d40; else +0x99; else the
  frame's), which is the JS reconstruction's footprint (race-visuals.js:144, its manifest's kart03 bounds, bit for
  bit); with the setting off the original quad is drawn as it is.
- The engine flare (0x4888b0: a 4-vertex strip whose vertices are the flare in the pool *(*(*(0x545100)+4)+4), in
  world coordinates; +0x138 its owner's slot). Tagged FOLLOW with its owner, or HOLD (the setting off, a racer's
  flare): always at the newer pass, as the JS reconstruction draws it off, sunk into the engine at speed.
- FOLLOW draws pair only with their owner's (the id joins the key), the nearest by place relative to the owner first
  (a turbo gives a kart up to three flares, and the pool moves them), and their vertices are blended unless the owner
  moved more than 30 units, the rule the kart's own matrix gets, so kart, shadow and flare snap together. At racing
  speed a kart moves 13.8 units a pass (28.1 at most with a turbo, Frankrijk), so the 10-unit vertex rule cut the
  flare loose two thirds of the time and showed it about 7 units ahead of its kart.
- The settings reach the game worker in CTRL.OPTIONS (OPT.SURFACE_SHADOWS, OPT.SMOOTH_ENGINE_LIGHTS) from the
  runner's applySettings, at race start and after the menu's OK; the game worker copies them to `host.options` before
  every pass. `?noshadows` and `?nolights` switch them off on the development page. Render stats (`rstats`): decals,
  followed, followSnapped, held. Checks: `node --test tests/shadows.test.mjs` (the grid, its footprint and its world
  points against the JS reconstruction's), `tools/checks/shadows.mjs` (Node), `tools/check-visuals.mjs` (browser,
  16:9; `js`: beside the JS reconstruction from the chase camera).

In `gl-renderer.js`, Direct3D's row-vector
matrices are uploaded as they are (GLSL reads them transposed, so P·V·W·v is the same product); the
viewport's clip volume maps to GL through `uClip`. CULLMODE 2 culls triangles that are clockwise on
screen, 3 counter-clockwise, as GL's front face is also defined on screen. Textures are RGB 565 with the
keyed texel 0 (or ARGB 4444).
