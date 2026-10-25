# RedCat SuperKarts browser and desktop reconstruction

A reconstruction of the original Windows game using **Three.js**, **Electron**
and the original supplied assets. Play in a browser or in a desktop window.

**Version 0.9.0** · [Changelog](CHANGELOG.md) ·
[GitHub downloads](https://github.com/NostalgiaRealm/RedCat-SuperKarts/releases/tag/v0.9.0) ·
[GitLab downloads](https://gitlab.com/Nostalgia_Realm/RedCat-SuperKarts/-/releases/v0.9.0)

- **Six circuits**, **four playable characters**, **four active race modes** and
  **three difficulty levels**, with the original menus.
- **QuickRace:** character and race selection, countdown, racing, results,
  highscores and retry.
- **Adventure:** player profiles, progression, unlocks, and the original
  character and country reward movies.
- Recovered player and opponent behavior, collisions, weapons, cameras,
  animations, weather, trails, race HUD, sound and music follow the recorded
  original evidence. The HUD is the information shown on screen during a race.

**Status:** the game is playable. Implemented features and comparisons against
original behavior are recorded separately. Full visual, audio and handling
parity has not been established: WineD3D does not provide a reliable original
race baseline here. See [feature status](docs/feature-parity.md) and
[validation](docs/validation.md) for the tested scope, rendering adaptations and
unavailable platforms. The [remaining-work audit](docs/remaining-work.md)
separates confirmed improvements from validation gaps and optional work.

[Run the game](#run-the-game) · [Controls](#controls) ·
[Settings and saves](#settings-and-saves) ·
[Prepare original assets](#prepare-original-assets) ·
[Build and host](#build-and-host) · [Testing](#testing) ·
[Technical documentation](#technical-documentation)

## Run the game

For a ready-to-run desktop app, download a package from the release links above.
Choose the Linux AppImage or archive, Windows installer or ZIP, or the macOS
DMG or ZIP for your Mac's processor. These packages include the game and do
not require Node.js. See [desktop instructions](docs/desktop.md) for details.

The published source release includes the prepared game assets. Download and
extract the source archive, or clone the repository, then follow the commands
below. You do not need to import the original disc files for this release.
The source archive is separate from the ready-to-run desktop downloads.

Install **Node.js 24 and npm**, then open a terminal in this project folder.
The instructions below assume the original assets have already been prepared
in `public/assets/`. For a fresh checkout that still needs those files, follow
[Prepare original assets](#prepare-original-assets) first.

### In a browser

Install the JavaScript dependencies once, then start the local server:

```sh
npm ci
npm start
```

Open **[http://127.0.0.1:4173/](http://127.0.0.1:4173/)**.
Keep the terminal open while playing. Press **Ctrl+C** in that terminal to stop
the server. Browser audio may need a click before the intro starts.

For later launches, run only `npm start`, unless `node_modules/` was removed.
The server reads `src/` and `public/assets/` directly, so **no build is needed**.
Startup reports missing Three.js dependencies and shows the reinstall command.
The `node_modules/` dependency folder is intentionally excluded from Git.

The server accepts local connections only and uses port 4173.
`npm run dev` also starts it. To use a different port, run
`PORT=4174 npm run dev`.

### In a desktop window

After installing dependencies and preparing the assets, run:

```sh
npm run desktop
```

This opens the game without a server or a build step. The first launch downloads
its pinned Electron runtime if needed. Press **F11** to toggle fullscreen.
Desktop saves use a separate application profile. Menus, movies, sound, controls
and gameplay use the same game code and assets as the browser version.

For installable or portable packages, see [Desktop packages](#desktop-packages)
and the [desktop build instructions](docs/desktop.md).

## Controls

### Keyboard and touch

The original race keys were recovered from `data/game.ini`:

| Key or control | Action |
| --- | --- |
| Arrow keys | Accelerate, brake and steer. |
| Ctrl | Use a bonus. |
| Alt | Handbrake. |
| 1 | Chase camera. |
| 2 | Body-aligned first-person view. |
| Hold 3 | Rear view; release to restore the preceding camera. |
| 4 | Lower-target chase camera. |
| Esc or the touch **Stoppen** button | Open the original **STOPPEN** quit requester. |
| P | Pause, using the original release/keypress/release sequence. |
| Click the circuit, Enter or controller Start | Resume after focus loss pauses the game. |
| F11 in the desktop app | Toggle fullscreen. |

The original restrictions on camera changes during different race phases are
retained. In menus, use the mouse, touch, arrow keys or Enter. In the separate
track-inspection views, drag to orbit and use the wheel or pinch to zoom.

On a touchscreen, hold the **steering wheel on the left** and slide your finger:

- Left/right steers; the distance from the centre controls how sharply you turn.
- The upper half gives gas; the lower half brakes and then reverses. A small
  neutral area around the centre helps avoid accidental input.
- The **pedal on the right** operates the same handbrake as **Alt**. The orange
  lightning **Bonus** button uses your power-up, like **Ctrl**.

You can hold the wheel and an action button together. Sliding outside the wheel
keeps control until you lift your finger. Enable or hide these controls under
**Instellingen → Meer instellingen → Aanraakbediening**. Their layout adapts to
portrait and landscape screens.

### Controllers

Controllers using the browser's standard Gamepad API mapping support:

| Control | Action |
| --- | --- |
| Left stick or D-pad | Navigate menus. |
| Bottom face button | Confirm. |
| Right face button | Go back. |
| Analog throttle, brake and steering | Drive, with a steering deadzone. |

Keyboard input uses the original digital ramps; controllers and the touch
steering wheel use the recovered proportional joystick routine. The wheel's
finger-position response follows SuperTuxKart's touch controls. Independent
touch pointers are supported. Simulated controller and browser touch tests
cover partial throttle, steering and braking. Physical controllers and mobile
devices remain unverified. [Touch-control sources and artwork licenses](docs/research-touch-controls.md)
are documented separately from the original game's assets.

## Settings and saves

**Instellingen → Geavanceerd** keeps the original display options. Added browser
display and input settings are presented separately.

**Meer instellingen**, below the two sound sliders, contains:

| Option | What it does |
| --- | --- |
| MSAA: **2× / 4× / 8×** | Multisample anti-aliasing to smooth polygon edges. |
| **Vrij vliegen (no-clip)** | Explore freely using the normal driving controls and **Space/C** for up/down. The race pauses while exploring, and stopping free flight returns the kart safely to the track. |
| **Alles ontgrendelen** | Unlock all tracks/countries while preserving profiles and scores. |

See [extra settings](docs/more-settings.md) for more information.
The current version is shown at the bottom of **Meer instellingen**.

### Resolution and render scale

- **Auto** uses the viewport's CSS dimensions multiplied by the device pixel
  ratio once.
- An explicit resolution preset fits inside its named rectangle while keeping
  the viewport's aspect ratio.
- **100%** uses that base size. **25–200%** multiplies both dimensions.
- The actual WebGL size is shown. Menus remain separate HTML artwork, and GPU
  texture limits proportionally constrain extremely large rendering buffers.

### Where progress is saved

Selections, browser settings, original highscore rows, records and Adventure
profiles persist in local storage for the same origin—the same website address
and port. Desktop saves use their separate application profile. The supplied
original save and configuration files are not modified.

### Adventure reward movies

Adventure plays a country-star movie after each successful duel. Completing all
**24 events** also plays the selected character's original movie after the
highscore step:

| Character | Original movie |
| --- | --- |
| RedCat | `RCWIN` |
| WhizzKitty | `WKwin` |
| Brutus | `BRwin` |
| Max | `MXwin` |

An individual QuickRace win does not trigger these movies.

## Original presentation and sound

The menus use extracted bitmap states, original component coordinates, Dutch
labels and locally available Comic Sans fonts. Original up, hover and pressed
images, click masks, menu voices and button samples are connected.

Portrait screens rearrange the artwork while preserving its proportions.
There are bounded checks of **26 layouts** at **320/390 pixels**. The race HUD
also keeps the original artwork proportions and reserves space above touch
controls. The original WinHelp content supplies **13 topics and 46
illustrations**.

Five referenced menu samples are absent from both supplied copies; their exact
names are retained in the audio manifest.

Sound follows the original source and group levels:

- Menu speech and movies are independent of the race volume sliders.
- When a race starts, the original loader changes an enabled effects setting
  of **0 to 75**. That saved-setting behavior is preserved.
- Engine layers and roadside clones follow their own original volume rules,
  rather than a blanket effects multiplier.

Rendering has **no game-imposed frame-rate cap**. Simulation uses the original
minimum **25 ms** update gate, measured elapsed time and native smoothing, on a
timer independent of display refresh. See
[timing behavior and validation](docs/research-variable-update-timing.md).

## Prepare original assets

**Skip this section if your checkout already has the prepared assets.** Asset
preparation converts the supplied original files into formats the port can use.
It reads those source files and writes only into this project folder. The
default paths are the ones supplied for this project.

### Requirements

| Tool | Needed for |
| --- | --- |
| Node.js 24 and npm | Install dependencies and run the preparation command. |
| Python 3 with Pillow and pefile | Read and convert the original assets. |
| ffmpeg with H.264/AAC encoding support | Convert movies. |
| helpdeco | Extract the original WinHelp content. |

Ghidra and Unicorn are only needed to reproduce native research. They are not
needed to run the browser code or retained regression fixtures.

Install helpdeco on `PATH`, or build the tested revision in this folder. This
one-time build requires a C compiler and Make:

```sh
git clone https://github.com/pmachapman/helpdeco.git work/helpdeco
git -C work/helpdeco checkout 785273788af17fde4fba7df7162d547f8645d7d8
make -C work/helpdeco/gcc
```

### Prepare and launch

From this project folder:

```sh
npm ci
npm run prepare:assets
npm run dev
```

Then open [http://127.0.0.1:4173/](http://127.0.0.1:4173/).

Preparation extracts both archives and converts imagery, models, tracks, fonts
and movies. It also parses all **20 native menu forms**, extracts their original
hit masks, reconstructs the launcher icon, recovers Dutch WinHelp text and
illustrations, imports the separate CD menu voices, and inventories gameplay
configuration. Output manifests retain source hashes and record ranges so the
converted content can be traced back to the original files.

### Use a different local installation

```sh
npm run prepare:assets -- \
  --installation "/path/to/RedCat Super Karts" \
  --cd "/path/to/extracted/RedCat Superkarts" \
  --font-dir "/path/to/local/Microsoft/fonts"
```

The font directory must contain `comic.ttf`, `comicbd.ttf`, `comici.ttf` and
`comicz.ttf`, the family used by the original Delphi menus. On this machine,
the default is `/home/rick/.local/share/fonts/microsoft`.

Set `PYTHON` to select another interpreter. A local virtual environment can
provide Pillow and pefile without changing the system Python. Add `--skip-media`
to reuse existing movie conversions while refreshing other assets.

## Build and host

Building creates a separate copy for distribution. It is not required for the
local browser or desktop commands above.

### Static browser build

```sh
npm run build
```

This creates `dist/` with the prepared original assets. Serve that directory
through any static HTTP server; opening `index.html` through `file://` is not
supported. For example:

```sh
python3 -m http.server 4175 --bind 127.0.0.1 --directory dist
```

### Host on a subdomain

The browser build can run as a static site at an address such as
`https://karts.example.com/`. Serve the **contents of `dist/` at the subdomain
root**, including the bundled Three.js files.

The [subdomain hosting instructions](docs/hosting.md) cover build requirements,
the exact upload layout, DNS and HTTPS, Caddy/Nginx examples, caching, media
checks and updates.

### Desktop packages

Run the packaging command on the corresponding operating system:

| Platform | Command | Output in `release/` |
| --- | --- | --- |
| Linux | `npm run dist:linux` | AppImage and tar.gz. |
| Windows | `npm run dist:win` | Installer and ZIP. |
| macOS | `npm run dist:mac` | Separate Intel and Apple Silicon DMG/ZIP packages. |

`npm run desktop:pack` creates an unpacked application for the host platform.
These commands build locally without publishing. Each package is checked for
missing or changed game files.

See [desktop build instructions](docs/desktop.md) for prerequisites, exact
commands for all three platforms, save locations, optional signing and the
scope of actual platform validation.

## Browser shortcuts for investigation

Normal play starts at `/`. The other paths make repeated checks easier:

| Path | Opens |
| --- | --- |
| `/` | Original intro, then the menu. Click or press a key to skip playback. |
| `/?skipIntro` | The main menu directly. |
| `/?track=0` through `/?track=5` | Separate asset-inspection views for Nederland, Duitsland, Engeland, Frankrijk, Spanje and Italië. |
| `/?drive=0` through `/?drive=5` | Driving research views with original kart, drivers, four opponents, difficulty tables, weapons, recovery, camera, music, HUD lettering and minimap. |

Track inspection uses an orbit camera. Driving research uses recovered player,
opponent, ground and contact routines with the original chase camera. It skips
the menu and countdown for repeatable investigation. Use **QuickRace** to check
the full menu, countdown and results path. See the
[parity inventory](docs/feature-parity.md) for comparison limits.

## Testing

These are development checks. They are not needed each time you launch the
game. Choose checks relevant to the behavior you change.

The rendering smoke tests now check the world and HUD separately from the
final screen copy. The [HUD rendering follow-up](docs/research-hud-framebuffer.md)
records the relevant source checks; older results below retain their original
checkpoint and platform scope.

### Unit, parser and asset checks

```sh
npm test
npm run test:parsers
npm run test:assets
```

### Browser and gameplay checks

Start the server:

```sh
npm run dev
```

In a second terminal, while that server is running:

```sh
npm run test:browser
npm run test:driving
node tests/quickrace-browser.mjs
node tests/adventure-browser.mjs
node tests/animation-browser.mjs
node tests/camera-browser.mjs
node tests/audio-settings-browser.mjs
node tools/validate-race-sound-triggers.mjs
node tests/weather-browser.mjs
node tests/streams-squash-browser.mjs
```

Browser tests use `/usr/bin/google-chrome`, headless Chromium with SwiftShader.
Override `CHROME_PATH` or `RCSK_URL` if needed. Those checks are not hardware
rendering benchmarks, actual 240 Hz display tests, or real mobile/controller
testing. They retain screenshots and `evidence/browser/report.json`.
The driving checks retain `evidence/driving/report.json` and cover all six
circuits, all four selectable drivers, original HUD atlas rendering, keyboard
movement, simulated controller braking, focus pause/resume and two simultaneous
touch contacts.
Animation checks drive all four characters through both steering directions
and reverse, then compare pickup/hit queue changes and displayed source meshes.
Camera checks exercise all original view keys. Audio checks verify actual
playback before checking original source/group levels.

### Firefox checks

Firefox checks use a separately started geckodriver with a disposable profile:

```sh
xvfb-run -a env LIBGL_ALWAYS_SOFTWARE=1 work/geckodriver/geckodriver --host 127.0.0.1 --port 4447
# In a second terminal:
npm run test:firefox
```

Override `WEBDRIVER_URL`, `FIREFOX_PATH` or `RCSK_URL` as needed. The recorded
run uses Firefox 158.0 under Xvfb/software OpenGL. The driver is not a runtime
dependency or included in `dist/`.

### What native checks establish

Unicorn checks execute bytes from the original race executable, with explicit
external input/timer stubs. They validate bounded recovered routines and do
not establish complete native race parity. Reproduction commands, addresses,
hashes and numerical tolerances are in the research documents.

Wine 11 Staging was useful for intro/menu/process handoff. The user reports
that WineD3D renders the race incorrectly; no full race visual/handling parity
is inferred from that environment.

## Recorded validation checkpoints

These records describe the source and builds tested at each checkpoint. Earlier
full-race results remain tied to their historical runtime hashes.

### Initial broad checkpoint

The earlier broad checkpoint passed 374 JavaScript tests, four parser tests,
36 control-only race cases and 18 five-minute opponent runs. Every course
qualifies in all four modes on easy; every star race collects twelve stars.
Ordinary races finish at all three difficulties, with placing/qualification
reported separately. `evidence/final/validation.json` records that source,
build checks and retained unsuccessful attempts.

### Greeting, recovery and follow-up audit

Subsequent greeting, starter, danger-zone recovery and texture-key corrections
have focused native/browser
verification in `evidence/regressions/validation.json`. The subsequent broader
audit is documented in `docs/research-followup-audit.md`, with the build from
that checkpoint and separately refreshed checks in
`evidence/followup/validation.json`.
It restores menu transactions and advanced settings, original keyboard rules,
the missing bubble shell, rescue rendering and progress, and native arithmetic
details. It also checks all 24 Adventure transitions consecutively; those
controlled results are separate from physically driven race completions.

### Germany, France and Italy race completion

The three subsequently unfinished normal-race checks are now complete:
Germany 10:48.975, France 13:32.350 and Italy 9:25.975, all five laps and first
place using ordinary controls on identical frozen source. This follow-up
restores original jump callbacks and route settings, and adds an explicitly
authorized player rescue fallback for occupied or overlapping return points.
It retains the original effects and voices. Details and rebuilt-file
verification from that checkpoint are in `docs/research-race-completion.md` and
`evidence/race-completion/validation.json`.

### Full race matrix

The earlier full-race audit targeted all 72 track/difficulty/mode combinations:
71 finished, and 40 also qualified for Adventure. France on hard difficulty in
timed mode remains incomplete. Those historical fixed-25-ms results are recorded
in `evidence/full-race-matrix/race-matrix.json`; the verifier checked matching
source/asset hashes at that checkpoint. They do not establish full-race coverage
for the later variable update host and recovery changes. This audit corrected the native
race constructor's upgrade reset and mirrored rendering/input composition,
and added narrowly scoped recovery and nonfinite-opponent safeguards for
captured stuck cases. It retains the original physics, deadlines and gate
awards. That checkpoint includes 492 unit tests, eleven focused browser checks
and refreshed source-asset comparisons. See the
[full race results](docs/full-race-results.md) and
[research notes](docs/research-full-race-matrix.md).

### Extra settings and shadows

The extra-settings additions described above were checked alongside shadow
corrections. The shadow audit fixes viewport-edge disappearance and unintended
browser alpha compositing using the original shadow code and assets. Focused
checks and the refreshed static build from that checkpoint are documented in
[extra settings](docs/more-settings.md) and
[shadow research](docs/research-kart-shadows.md).

## Technical documentation

In these notes, **native** means the behavior or files of the original Windows
game. Research records distinguish recovered routines, observed behavior and
remaining comparison limits.

The repository includes the retained test fixtures and validation reports.
Native analysis databases, decompiler exports, Wine environments and raw input
copies remain local; historical research paths referring to those files are
not part of the runnable source release.

The source game uses Davilex's **M25/A2 Racer** engine lineage. Spookkasteel uses
**Genesis3D** worlds and **DaviScript** formats, so only proven-compatible
extraction and technical findings are reused. The Spookkasteel checkout and
supplied original installation/ISO remain read-only inputs.

| Topic | Start here |
| --- | --- |
| Current milestone, checkpoint and next steps | [PLAN.md](PLAN.md) |
| Evidence classifications and source authority | [Original behavior](docs/original-behavior.md) |
| Separate implementation and comparison status | [Feature parity](docs/feature-parity.md) |
| Acceptance criteria, outcomes and unavailable platforms | [Validation](docs/validation.md) |
| Native processes, UI, timer and reference limits | [Startup research](docs/research-startup.md) |
| Extraction, geometry, textures and media | [Asset research](docs/research-assets.md) |
| Content, parameters and recovered native routines | [Gameplay research](docs/research-gameplay.md) |
| Original HUD coverage and restored elements across all four race modes | [HUD research](docs/research-hud-modes.md) |
| The complete original request | [docs/request.txt](docs/request.txt) |

## Original assets and rights

The original game, media and font assets retain their owners' rights. Extraction
does not imply ownership or a redistribution license. Source preparation
commands operate on the supplied local copies.
