# RedCat SuperKarts, recompiled

**Version 2.0.1** · [Changelog](CHANGELOG.md) · [Release notes](docs/releases/2.0.1.md) ·
[Play in the browser](https://games.nostalgiarealm.com/redcatsuperkarts/) ·
[GitHub downloads](https://github.com/NostalgiaRealm/RedCat-SuperKarts/releases/tag/v2.0.1) ·
[GitLab downloads](https://gitlab.com/Nostalgia_Realm/RedCat-SuperKarts/-/releases/v2.0.1)

> **This is a static recompilation, not a reconstruction.** From version 2.0.0 RedCat SuperKarts runs the
> game's own original race program, `rcskspel.dat` (Davilex, 2000), recompiled from x86 machine code to
> WebAssembly. Physics, AI, rules, timing, HUD, camera, sound and the race's own screens are the original
> code as shipped. Versions up to 1.0.3 were a reconstruction written by hand in JavaScript and Three.js;
> that port is kept on the branch [`javascript-port`](https://github.com/NostalgiaRealm/RedCat-SuperKarts/tree/javascript-port)
> with its releases, and on the website at
> [`classic/`](https://games.nostalgiarealm.com/redcatsuperkarts/classic/).

A JavaScript layer gives the recompiled race what Windows and DirectX 5 gave it: files, timers, input,
DirectSound and DirectShow on Web Audio, and a Direct3D render driver drawn with WebGL 2 in a worker. The
menus, Adventure, QuickRace, highscores, settings and saves are the JavaScript reconstruction's, unchanged,
and so are its additions around the race: any screen shape, resolution, render scale and MSAA, pictures
smoothed to the display's rate, keyboard, controller and touch controls, surface shadows, engine lights
that follow the kart, free flight, recovery of a stuck kart and a pause when the window loses focus. What
differs from the original on purpose is listed in [`docs/intentional-differences.md`](docs/intentional-differences.md).

- **Play:** in a browser at [games.nostalgiarealm.com/redcatsuperkarts](https://games.nostalgiarealm.com/redcatsuperkarts/)
  (current Chrome, Edge or Firefox; the page needs cross-origin isolation, shared memory and WebGL 2), or
  download the desktop app for Linux, Windows or macOS from the release links above.
- **Saves:** profiles, highscores, records, unlocks and settings of 1.0.x carry over, on the website and in the
  desktop app ([Saves](#saves)).
- **Status:** the whole game plays from the menu to the results. Checked in headless Chromium and Firefox and
  in the Linux desktop build; not yet on real phones, in Safari, or on Windows and macOS machines
  ([release notes](docs/releases/2.0.0.md#tested-and-not-tested)). [`PLAN.md`](PLAN.md) has what is next.

The original program, its decompilation and the analysis that the recompiler and host are built on are in
[`original-source/`](original-source/README.md) (recovered code and indexes, not the developers' source
project). The game's data files (`rcs.img` and the rest, 204 MB) are not in the repository; the website and the
desktop packages carry them, and a build reads them from an installation ([Run it](#run-it)).

## How it fits together

| Part | Where | From |
|---|---|---|
| Recompiler | `tools/recomp/` | RedCat Spookkasteel's (`RCSPOOK_MAIN/tools/recomp`), which took its core from Maisy's Playhouse and A2 Racer 4. Changes: [`docs/recompiler.md`](docs/recompiler.md) |
| Recompiled race | `public/game/rcskspel.{wasm,meta.json,codemap.bin}` | Generated from `original-source/inputs/rcskspel.dat` |
| Memory, thunks, COM, C++ exceptions | `source/host/machine.js`, `eh.js` | Spookkasteel host |
| Win32, DirectDraw/Direct3D/DirectSound, files and INI | `source/host/win32.js`, `directx.js`, `vfs.js` | A2 Racer 4 host, adapted ([`docs/host.md`](docs/host.md)) |
| DirectInput (mouse), joystick, DirectShow music | `source/host/dinput.js`, `winmm.js`, `dshow.js` | New, `winmm.js` after Spookkasteel |
| DirectSound | `source/host/dsound.js`; on the page `source/web/audio.js` | After Spookkasteel: play state on the race's clock, Web Audio plays what the worker sends |
| The race's loop | `source/host/race.js`, `race-setup.js` | New, A2's pattern: WinMain 0x4432a0 is a host hook |
| Game worker | `source/web/worker.js`, `shared.js` | New, Spookkasteel's model: the race in a worker that may block, input in shared memory |
| Recorder and render worker | `source/render/recorder.js`, `gl-renderer.js`, `source/web/render-worker.js` | New: Direct3D 5 and 2D screen calls written down per frame, replayed with WebGL2 on an OffscreenCanvas |
| Menu, saves, settings | `source/index.html`, `main.js`, `style.css`, `source/menu/` | The JS reconstruction's, copied; changes marked `// recomp:` |
| Race runner and handoff | `source/race-runner.js`, `source/host/race-handoff.js`, `source/input/` | New: one game worker for every race; the INI keys rcskmenu.dat writes, and the results read back from race.ini |
| Development race page | `source/dev/race.html`, `race.js` | New: one race with URL parameters, for the checks |

The engine is Davilex's racing engine that A2 Racer 4 also uses (113 shared source files, the same
DirectX 5 interfaces), which is why A2's host fits. Background: [`docs/recomp-feasibility.md`](docs/recomp-feasibility.md).

In the published repository `original-source/` lies in the repository itself. On the development machine this
port was built in a folder of its own beside a checkout of the JavaScript port (`../RedCat Superkarts`, branch
`javascript-port`); several tools still read from there: Playwright for the browser checks, the installation copy
of the game's data, and the JavaScript port's runtime for side-by-side comparisons. Point them elsewhere with
`PLAYWRIGHT_MODULE`, `SUPERKARTS_DATA` and `SUPERKARTS_ORIGINAL_SOURCE`.

## Run it

Inputs stay where they are and are only read: the executable and Ghidra's function lists from
`../RedCat Superkarts/original-source/` (`SUPERKARTS_ORIGINAL_SOURCE` overrides), the game's files from the
installation copy in `../RedCat Superkarts/evidence/native/runtime/wineprefix/.../RedCat Super Karts/data`
(`SUPERKARTS_DATA` or `--data` overrides).

Rebuild the WebAssembly module (5 s; needs Python with capstone, e.g. the reverse-engineering environment):

```bash
RCSK_PYTHON=~/.local/share/reverse-engineering/python-analysis/bin/python npm run recompile
```

Run a race without a browser (boot, 400 ticks of 25 ms with throttle held, the player's position every 40):

```bash
node tools/run-headless.mjs --ticks 400 --gas --pos-every 40
```

The game: start the server and open <http://127.0.0.1:4190/> (the intro, then the menu). A race on its own, for
development: <http://127.0.0.1:4190/dev/race.html>, click into it and drive.

| Action | Keyboard | Gamepad (standard) | Touch |
|---|---|---|---|
| Steer | Left, Right | Left stick, D-pad (analog) | Wheel, left and right (analog) |
| Gas | Up | RT or A (analog) | Wheel, upper half |
| Brake, then reverse | Down | LT or B (analog) | Wheel, lower half |
| Bonus | Ctrl | X | Bonus |
| Handbrake | Alt | Y | Rem |
| Pause, then any key | P | Start, then A or Start (after a focus loss also B, the D-pad or the stick) | Then tap the picture (the controls stay, inert) |
| Stop: the original requester (J/N or the mouse) | Esc, then J/N, or the arrows and Enter (focus starts on nee) | None, as in the JS port; in the requester the stick or D-pad moves between ja and nee (from nee), A presses, B is nee | Stoppen (while racing), then tap ja or nee |
| Finish and game-over screens | Enter, Space, Esc | A | Tap the picture (holds Space) |
| Free flight (Meer instellingen → Vrij vliegen): up, down | Space, C (with the driving keys) | LB, RB (with the stick and pedals) | Omhoog, Omlaag (with the wheel) |

Keys are the menu's bindings (Instellingen → Instellen); the table shows the defaults. On the development page touch
controls show on a touch screen (`?touch=1` anywhere, `?touch=0` never); `?deadzone=18` is the pad's steering dead
zone in percent, `?etappe=N` picks another country, `?stats` shows tick, phase and draw counts, `?flight` turns free flight on, and `?res`,
`?scale`, `?msaa` set the drawing. On the menu page `?skipIntro` skips the intro and `?drive=N` starts a QuickRace
in country N. The page must be cross-origin isolated (the workers share memory with it): the server
sends `Cross-Origin-Opener-Policy: same-origin` and `Cross-Origin-Embedder-Policy: require-corp`, and a
website hosting it needs the same two headers.

```bash
node tools/serve.mjs
```

Screenshots in headless Chromium (needs the server; Playwright comes from the SuperKarts reconstruction):

```bash
CHROME_PATH=~/.cache/ms-playwright/chromium-1208/chrome-linux64/chrome node tools/shot.mjs --ticks 20,340,800 --gas
```

All checks in a row (about an hour): `node --test`, the Node checks, then the browser checks one at a time, each
with a time limit, and a table of pass/fail and time at the end (exit code 1 when one failed). It starts the dev
server and the JS reconstruction's read-only server when they are not running. Each check's output and the table
go to a new folder in the temp folder (`--logs DIR` picks one). `--only unit,node,browser` or check names, `--skip`
and `--list` choose the checks, and `--timeout-scale 2` doubles the limits on a busy machine:

```bash
CHROME_PATH=~/.cache/ms-playwright/chromium-1208/chrome-linux64/chrome node tools/run-checks.mjs
```

The game's files reach the browser by the race's lists, the archives `rcs.img` and `rc.img` by byte ranges
(`source/web/game-files.js`). After a change in which original files exist, or in how the host reads them, make the
file list and the per-race lists again (`public/game/files.json`, `preload.json`; 96 races in Node, 15 s), and after a
change in which menu assets the menu uses, copy them from the JS port (`public/assets`):

```bash
npm run manifest && npm run preload && npm run assets
```

What two races fetch on the dev page (`evidence/checks/loading.json`), and what a whole five-lap race would still
wait for beyond the lists (Node, a test bot; `evidence/loading/full-races.json`):

```bash
CHROME_PATH=~/.cache/ms-playwright/chromium-1208/chrome-linux64/chrome node tools/check-loading.mjs
node tools/checks/loading-full-race.mjs
```

The website (`dist/site/`, the nginx files beside it), its check below `/redcatsuperkarts/` in headless Chromium
(`--firefox` also tries Playwright's Firefox), a check of the real server, and the upload: [`docs/hosting.md`](docs/hosting.md).

```bash
npm run package && CHROME_PATH=~/.cache/ms-playwright/chromium-1208/chrome-linux64/chrome npm run package:check
npm run site:check -- --url https://games.nostalgiarealm.com/redcatsuperkarts-test/
tools/deploy-site.sh --dry-run
```

## Saves

The recomp keeps its saves where the JS reconstruction keeps them: `localStorage` keys `rcsk.race-save.v1` (Adventure
profiles, highscores, records, grid position, unlocked countries), `rcsk.settings.v1`, `rcsk.selection.v1` and
`rcsk.firsttime.*`, read and written by the same code (`source/menu/race-save.js` and `settings.js` are copies).
On one site (the same scheme, host and port, any folder) the two ports share them: nothing to do (on the website the
new port at `/redcatsuperkarts/` and the JS port at `/redcatsuperkarts/classic/` see the same saves: `docs/hosting.md`)
(`tools/checks/save-transfer.mjs` makes saves with the JS port's own menu and checks the recomp shows and races
with them). From another site or port they move as a file: Meer instellingen →
Opslag → **Opslag exporteren** / **Opslag importeren** (importing replaces the saves in that browser). The JS port has
no export button; on its site, this line in the browser console (F12) writes the same file:

```js
(()=>{const k=Object.fromEntries(Object.keys(localStorage).filter(x=>x.startsWith('rcsk.')).map(x=>[x,localStorage.getItem(x)]));const a=document.createElement('a');a.href=URL.createObjectURL(new Blob([JSON.stringify({format:'rcsk-saves',version:1,keys:k})],{type:'application/json'}));a.download='redcat-superkarts-opslag.json';a.click();})()
```

The desktop app 2.0.0 has the JS port's desktop app's identity (origin `rcsk://game`, profile folder
`RedCat SuperKarts`), so it opens a 1.0.x player's saves where they are: nothing to do.

## Desktop app

Version 2.0.0 is this port in an Electron window and replaces the JS port's desktop app (1.0.x): the packaged site
(`dist/site`) served by the app under `rcsk://game` with the isolation headers, the JS app's window, menu bar, F11,
single instance and navigation lock, and its name, appId and profile, so saves, settings and highscores carry over.
Linux (AppImage, tar.gz) and Windows (installer, zip) x64 are built here, macOS (DMG, ZIP; x64, arm64) by a GitHub
workflow. How to build and check them: [`docs/building.md`](docs/building.md).

```bash
npm ci && npm run package && npm run dist:linux && npm run dist:win    # release/<version>/
node tools/desktop-check.mjs --legacy /path/to/1.0.3/redcat-superkarts  # launch check of the Linux build
```

## Evidence

The screenshots under `evidence/frames/` are not in the repository (164 MB): the checks named below write them
when they run. The measured results under `evidence/checks/` and `evidence/audio/` are.


- `evidence/frames/`: frames of the development page. `nederland-tick0340.png` set beside the original
  under Wine (`../RedCat Superkarts/evidence/native/runtime/race-native16.png`) shows the same start
  lights, HUD, banner and kart glows.
- `evidence/headless/files-read.txt`: the 28 files a Nederland race reads.
- `evidence/loading/`: what each of 96 races reads (`preload-summary.json`, `tools/build-preload.mjs`) and what whole
  races driven by a test bot would wait for beyond the lists (`full-races.json`); `evidence/checks/loading-before.json`
  and `loading.json`: two races on the dev page before (180 MB, whole files) and after (30 MB, byte ranges);
  `evidence/package/`: the packaged site's check (`result.json`, the menu, both races, the not-supported notice).
- `evidence/checks/`: start-sequence and full-race checks (see PLAN.md).
- `evidence/frames/input/`: pause, quit requester and finish on the worker page, driven by real key presses
  (`node tools/check-input.mjs`, results in `result.json`).
- `evidence/frames/shapes/`: the race at 4:3, 16:9, 21:9 and portrait with the HUD at the edges, 16:9 with MSAA
  4x, the requester, a mouse click on its button and the finish flag at 16:9 (`node tools/check-shapes.mjs`).
- `evidence/checks/wide-cull*`, `hud-layout*.txt`: no culling by aspect in the game (6 tracks), and the HUD
  layout's groups, shifts and exact restore (`tools/checks/wide-cull.mjs`, `hud-layout-check.mjs`).
- `evidence/frames/input/touch-*.png`, `pad-driving.png`, `touch-pad.json`: touch wheel, Stoppen and a tap on the
  requester, the controls shown but inert in the pause and the focus hold (`touch-pause.png`), a tap on the picture
  ending the finish screen, Stoppen doing nothing on the game-over screen (`touch-gameover-stoppen.png`), pad driving,
  pause and focus pause, the requester's focus on nee and ja (`pad-requester-*.png`) (`node tools/check-touch-pad.mjs`); `evidence/checks/input-modes.txt`:
  the original's input modes, run headless.
- `evidence/frames/shapes/phone-*.png`, `evidence/checks/hud-scale-*.txt`: the HUD on phones, upright and in
  landscape, with and without the touch controls, every draw and its cut to its frame held to the JS
  reconstruction's `raceHudLayout` (`tools/checks/hud-phone-shot.mjs`, `hud-scale-check.mjs`);
  `evidence/frames/hud/`: the HUD of the JS reconstruction (`js/`) and of the recomp before and after taking over
  its layout, in the same seven shapes, and both side by side with each group cut to its frame, also while the start
  lights slide in (`clip/`, `tools/checks/hud-shots.mjs [--moment slide]`); `evidence/frames/hud/touch/`,
  `evidence/checks/hud-touch-boxes.json`: the touch controls of both ports pixel for pixel on seven screens
  (`tools/checks/hud-touch-boxes.mjs`).
- `evidence/frames/smooth/`: pictures per second with and without smoothing, how many draws were paired
  (`node tools/check-smooth.mjs`, `result.json`), and a still forced halfway between two passes in a corner.
- `evidence/audio/check-audio.json`: what sounds at the start, during the countdown, while driving and in the
  pause, with the output's loudness (master, music and effects apart), a focus pause's silence (also for a hidden
  page and in free flight), music and effects levels changed during the race, and the FPS counter hidden in the
  pauses (`node tools/check-audio.mjs`, exit code 1 on a failure; screenshots next to it).
- `evidence/frames/menu/`: the menu screens, side by side with the JS reconstruction's (`compare/`, pixel-identical),
  and the menu's own checks with a stand-in race (`node tools/checks/menu/check-menu.mjs`).
- `evidence/frames/menu-race/`: the menu with the real race: a QuickRace finished, its debrief and highscore, a
  second QuickRace with the saved records quit with a quick Esc tap, and an Adventure event
  (`node tools/check-menu-race.mjs`).
- `evidence/checks/flight.txt`, `flight-browser.json`, `evidence/frames/flight/`: free flight headless (the race and
  HUD frozen, the whole kart at the flight pose in its take-off colour, pause and requester inside a flight pass,
  landing restored with the JS port's camera reset; `node tools/checks/flight.mjs [--etappe N --car N]`) and on the
  menu page (panel, keys, pad, touch buttons, "pauze" in `flight-pause.png`, settings over the race, Stop vliegen;
  `node tools/check-flight.mjs`, `airborne.png` beside the JS reconstruction's `evidence/free-flight/airborne.png`).
- `evidence/checks/runner.json`: three races on one page, their load times and memory (`node tools/check-runner.mjs`);
  `evidence/checks/race-handoff/`: the INI handoff and result reader against recorded races (`node --test`,
  `tools/checks/race-handoff-probe.mjs`).
