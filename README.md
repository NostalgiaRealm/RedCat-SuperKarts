# RedCat SuperKarts browser and desktop reconstruction

A reconstruction of the original Windows game using **Three.js**, **Electron**
and the original supplied assets. Play in a browser or in a desktop window.

**Version 1.0.2** · [Changelog](CHANGELOG.md) ·
[GitHub downloads](https://github.com/NostalgiaRealm/RedCat-SuperKarts/releases/tag/v1.0.2) ·
[GitLab downloads](https://gitlab.com/Nostalgia_Realm/RedCat-SuperKarts/-/releases/v1.0.2)

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

To inspect how the original worked, see the [recovered C and assembly](original-source/README.md).
This is decompiled reference code, not the developers' original source project.
The [source comparison report](docs/full-source-audit.md) records the earlier
confirmed corrections and the intentional port features that were preserved.
The [28 October 2026 comparison](docs/original-comparison-2026-10-28.md)
records the latest six corrections.

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
Version 1.0.2 was packaged with the normal build checks; see
[its release notes](docs/releases/1.0.2.md) for the validation scope.

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
the server. The intro starts automatically; if the browser blocks sound, use
**Geluid inschakelen** at the bottom left to enable audio while it keeps playing.
This button also enters fullscreen if the game is not already fullscreen.

For later launches, run only `npm start`, unless `node_modules/` was removed.
The command refreshes the small generated runtime in `src/`, then serves it
with the prepared `public/assets/`. **No separate build command is needed.**
The editable modules live in [`source/`](source/README.md); the game does not
load those individual files. Changes made while the server is running need
`npm run bundle` and a browser reload, or a server restart.
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

This creates `dist/` with the prepared original assets. The build combines the
JavaScript modules into a small set of files, loads the renderer when needed
and removes unused library code. Editable files stay in [`source/`](source/README.md).
Use `npm run bundle` to refresh only the local runtime, without copying assets
or creating `dist/` or desktop packages. See [the folder guide](docs/runtime-layout.md).

To try that output locally, stop any server already using port 4173, then run:

```sh
npm run preview
```

Open the same [local address](http://127.0.0.1:4173/). Switching between `npm start`
and `npm run preview` on that address keeps existing browser saves and settings;
no migration is needed. Preview requires a completed build and does not rebuild
when you edit source. Use `npm start` to refresh and run the local runtime.

You can also serve `dist/` through any static HTTP server; opening `index.html`
through `file://` is not supported. For example:

```sh
python3 -m http.server 4175 --bind 127.0.0.1 --directory dist
```

That different port has separate browser saves. See [build and loading
details](docs/code-efficiency.md) for the changes and focused validation.

### Host on a subdomain

The browser build can run as a static site at an address such as
`https://karts.example.com/`. Serve the **contents of `dist/` at the subdomain
root**, including every generated JavaScript chunk and prepared asset.

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
These commands build locally without publishing. Normal packaging verifies
missing or changed game files. The 1.0.0 release deliberately skipped package
verification and all other build checks; 1.0.1 and later run them.

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

Checks are for development, not required each time you launch the game. The
[development guide](docs/development.md) lists focused unit, asset, browser,
Firefox and native checks, their requirements and evidence limits.

## Recorded validation checkpoints

See [current validation](docs/validation.md) for dated results and platform
coverage. The [earlier checkpoint overview](docs/history/validation-overview.md)
preserves the broad race, greeting/recovery, full-matrix and shadow records.
Historical results remain tied to their tested source; the [remaining-work
list](docs/remaining-work.md) identifies the open validation gaps.

## Technical documentation

In these notes, **native** means the behavior or files of the original Windows
game. Research records distinguish recovered routines, observed behavior and
remaining comparison limits.

The repository includes retained test fixtures, validation reports and the
complete [recovered C/assembly reference](original-source/README.md), including
its copied runtime inputs and export tools. The entire `original-source/`
folder is included on GitHub and GitLab and in every release source archive.
It is inspection material, not a runtime requirement. This includes any
working databases and helper files inside `original-source/`. Other local
analysis directories, Wine environments and unrelated raw extraction folders
remain local; historical paths to those files are not required to run the game.
See the [release publication policy](docs/releases/README.md).

The source game uses Davilex's **M25/A2 Racer** engine lineage. Spookkasteel uses
**Genesis3D** worlds and **DaviScript** formats, so only proven-compatible
extraction and technical findings are reused. The Spookkasteel checkout and
supplied original installation/ISO remain read-only inputs.

The [documentation index](docs/README.md) organizes every guide and research
report by topic. Start with [PLAN.md](PLAN.md) for current priorities,
[feature parity](docs/feature-parity.md) for implementation/comparison status,
and [original behavior](docs/original-behavior.md) for evidence definitions.
The complete original request remains in [docs/request.txt](docs/request.txt).

## Original assets and rights

The original game, media and font assets retain their owners' rights. Extraction
does not imply ownership or a redistribution license. Source preparation
commands operate on the supplied local copies.
