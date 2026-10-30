# Desktop application

The desktop application runs the same game locally in Electron. It opens the
original introduction and menus in its own window. It does not require a browser
server, `npm start`, or a separate `npm run build` step.

The locked toolchain is **Node.js 24**, **Electron 44.9.2** and
**electron-builder 26.15.3**. Use the committed `package-lock.json` with `npm ci`.
The builder references below deliberately use the [v26 documentation](https://www.electron.build/v26/docs/);
the unversioned website currently describes the next major version.

## Run from this folder

Install Node.js 24 and npm from the [official Node.js downloads](https://nodejs.org/en/download).
In Bash, macOS Terminal or PowerShell, open the project directory and run:

```sh
node --version
npm --version
npm ci
npm run desktop
```

`node --version` should report `v24.x`. Installing dependencies with `npm ci`
downloads the pinned Electron runtime if it is not cached. Subsequent starts only need `npm run desktop` unless
dependencies were removed or changed. Do not omit development dependencies:
Electron and the packager are development tools used by these commands.

Each `npm run desktop` refreshes the generated runtime from the editable
`source/` inputs before opening Electron. The game executes `src/` bundles;
it does not directly load the individual authoring modules. No separate static
build or asset copy is required. See [the folder guide](runtime-layout.md).

The Git repository and published source release include the complete prepared
`public/assets/` folder, including fonts and converted movies. A fresh checkout
or extracted source archive can run the commands above without the original
disc files or an asset preparation step. Keep the asset directory structure
unchanged. Dependencies in `node_modules/` and generated packages are excluded
from Git; install dependencies with `npm ci` on each build computer.

Asset preparation is optional when you want to regenerate those files from
the original game/CD/font inputs. Follow the
[asset preparation instructions](../README.md#prepare-original-assets) for
Python, Pillow, pefile, ffmpeg, helpdeco and source paths. These extraction tools
are not required to run or package the included prepared assets. Windows
extraction can select its installed Python with `$env:PYTHON = 'python'` before
running the preparation command in PowerShell.

Both the source application and packaged application use `rcsk://game/` for
their local content. No port is opened and an existing browser server on 4173
can remain running independently.

Use the **Beeld → Volledig scherm** menu or F11 for fullscreen; macOS also
offers Control+Command+F. The game keeps its own original Esc quit/pause
behavior. To launch directly into the menu during development:

```sh
npm run desktop -- --skip-intro
```

## Build packages

Ready-to-run [v1.0.3 packages](releases/1.0.3.md) are available on
[GitHub](https://github.com/NostalgiaRealm/RedCat-SuperKarts/releases/tag/v1.0.3)
and [GitLab](https://gitlab.com/Nostalgia_Realm/RedCat-SuperKarts/-/releases/v1.0.3):
Linux x64 AppImage/archive, Windows x64 installer/ZIP, and separate macOS
Intel and Apple Silicon DMG/ZIP packages. The release includes its changelog,
build metadata, packaging integrity reports and checksums. Version 1.0.3 is
built with the normal build checks described below. The commands below
describe normal local packaging.

Run the commands from the project root after installing dependencies. They use
the included prepared assets. Outputs go to `release/`. The scripts explicitly
use `--publish never`: packaging does not upload a release or publish anything.
This matters because builder v26 also supports implicit CI publishing when no
explicit policy is supplied. [Publishing reference](https://www.electron.build/v26/docs/publish/)

| Command | Output |
| --- | --- |
| `npm run desktop:pack` | Unpacked application for the current host OS/architecture |
| `npm run dist:linux` | Linux x64 AppImage and `.tar.gz` |
| `npm run dist:win` | Windows x64 NSIS installer and `.zip` |
| `npm run dist:mac` | Separate macOS x64 and arm64 `.dmg` and `.zip` packages |

The macOS outputs are separate Intel and Apple Silicon packages, not one
universal binary. A package includes Electron, so its recipient does not need
Node.js, npm, Python, the original Windows executable, or a local web server.
Packaging refreshes the static game staging folder and icons automatically.
The configuration is [electron-builder.json](../electron-builder.json).
By default, before archiving, the build verifies every staged game file
byte-for-byte and checks the wrapper's contents. Version 1.0.0 skipped this
verification as part of its explicit no-tests/no-build-checks release scope,
using `RCSK_SKIP_BUILD_CHECKS=1`; versions 1.0.1 and later run it. The generated `runtime-manifest.json` records
runtime files and sizes, and Electron checks that every listed chunk is present
before launching the bundled game. The package verifier separately compares
payload bytes. Missing generated JavaScript chunks or media stop the build.
Normal checked builds record it in `release/integrity-<platform>-<arch>.json`.
Artifact names include version, OS and architecture, for example
`RedCat-SuperKarts-1.0.3-linux-x86_64.AppImage`.

### Linux

Build on a graphical Linux desktop with Node.js 24 installed. Electron needs the
system's normal graphics, audio and desktop libraries. On Debian/Ubuntu, the
builder documentation lists this additional distribution-build tool:

```sh
sudo apt-get install --no-install-recommends libopenjp2-tools
npm ci
npm run desktop:pack
npm run dist:linux
ls -lh release/
```

Use the equivalent package for another distribution if the build requests it.
Launch the generated AppImage after making it executable:

```sh
chmod +x release/RedCat-SuperKarts-1.0.3-linux-x86_64.AppImage
./release/RedCat-SuperKarts-1.0.3-linux-x86_64.AppImage
```

Adjust the version in the filename after a version change. The unpacked test
build runs as `./release/linux-unpacked/redcat-superkarts`. Alternatively,
extract the `.tar.gz` and run `redcat-superkarts` inside its directory. If the host cannot mount
AppImages, the tar archive provides the same game without an AppImage mount.
Keep the extracted application directory together; copying only its executable
omits required resources.

### Windows

Use Windows PowerShell with the Windows x64 Node.js 24 installation on `PATH`:

```powershell
Set-Location 'C:\path\to\RedCat Superkarts'
node --version
npm ci
npm run desktop
npm run dist:win
Get-ChildItem .\release\
```

Run the generated NSIS `.exe` to install, or extract the `.zip` completely and
run `redcat-superkarts.exe`. The unpacked test build is
`release\win-unpacked\redcat-superkarts.exe`. NSIS does not require Mono. A Windows build should be
tested on Windows before distribution, including introduction playback, sound,
gamepads, fullscreen and save persistence.

### macOS

Use Terminal on macOS with Node.js 24 installed. Install Apple's command-line
tools if they are absent, then build:

```sh
xcode-select --install
cd '/path/to/RedCat Superkarts'
node --version
npm ci
npm run desktop
npm run dist:mac
ls -lh release/
```

If the command-line tools are already installed, skip their installation.
Open the DMG for the intended architecture and copy the application to
Applications, or extract the corresponding ZIP. The default build uses an
ad-hoc signature for local testing; it is not a notarized Developer ID release.
macOS can require approval under Privacy & Security. Test both architecture
packages on suitable Macs before claiming support.

The unpacked bundles are `release/mac/RedCat SuperKarts.app` for x64 and
`release/mac-arm64/RedCat SuperKarts.app` for arm64. Open the bundle matching
your Mac, for example:

```sh
open 'release/mac-arm64/RedCat SuperKarts.app'
```

### Cross-building

Building on each target operating system is the recommended workflow. The
builder supports Windows builds from Linux with Wine, but producing an archive
on Linux does not verify Windows execution. macOS signing must run on macOS;
use a Mac for DMG creation and signed/notarized releases. No cross-platform
runtime validation is implied by the command table.
[Platform prerequisites](https://www.electron.build/v26/docs/features/multi-platform-build/)

## Saves and settings

Desktop settings, adventure profiles, highscores and records persist in the
application's Chromium profile under:

| System | Profile directory |
| --- | --- |
| Linux | `$XDG_CONFIG_HOME/RedCat SuperKarts`, or `~/.config/RedCat SuperKarts` when unset |
| Windows | `%APPDATA%\RedCat SuperKarts` |
| macOS | `~/Library/Application Support/RedCat SuperKarts` |

Source and packaged desktop launches use the same profile and local origin.
Browser saves at `http://127.0.0.1:4173/` remain separate; they are not
automatically imported. Rebuilding the application does not overwrite the
profile. Quit the application before copying the profile directory for backup.
These paths follow Electron's platform-specific application-data directories.
[Electron path reference](https://www.electronjs.org/docs/latest/api/app#appgetpathname)

For a separate test profile, set `RCSK_USER_DATA` to an **absolute** directory
before launching. This changes only the desktop profile; it does not import or
erase the normal profile.

```sh
RCSK_USER_DATA=/absolute/path/to/test-profile npm run desktop
```

```powershell
$env:RCSK_USER_DATA = 'C:\absolute\path\to\test-profile'
npm run desktop
Remove-Item Env:RCSK_USER_DATA
```

## Package contents

The wrapper is stored in `app.asar`; its files are `electron/**`, package
metadata and the desktop icon. The game is copied separately into `resources/game/` (inside the app's
`Contents/Resources/` on macOS): the entry page, generated `src/` entry/chunks,
source maps, stylesheet, `runtime-manifest.json` and prepared assets. The required Three.js code is
included in those JavaScript chunks. Movies and audio are served locally from
these packaged files. The packaging scripts generate this payload through
`npm run build`; the resulting `dist/` contents become `resources/game/`.
The local launcher also runs generated bundles, refreshed by `npm run desktop`.
Editable `source/` files are build inputs and are excluded from the package.
Both paths keep
`rcsk://game/` and the same profile/storage format, so bundling does not require
players to move or reset existing saves. See [loading and build changes](code-efficiency.md).

Original installers/executables, raw extraction folders, native research,
evidence, tests and development dependencies are not part of the game resource
payload. The complete `original-source/` reference is distributed separately
with the repository/source archives on both release hosts, on this and every
future release; it is not needed inside the desktop application's game payload.
See [release publication policy](releases/README.md). The prepared original artwork, sound, fonts
and movies retain their owners' rights; packaging does not change their license
or grant redistribution rights.

## Optional release signing

Local builds do not require purchased signing credentials. Windows packages
without a trusted publisher signature may show SmartScreen warnings. The
default macOS ad-hoc signature does not establish a publisher identity or
notarization. Do not describe either as a signed public release.

For a Windows publisher release, configure a supported certificate or signing
service using the [v26 Windows signing guide](https://www.electron.build/v26/docs/features/code-signing/code-signing-win/).
For file-based signing, inject `WIN_CSC_LINK` and `WIN_CSC_KEY_PASSWORD` through
the build environment, then run `npm run dist:win`. The project does not disable
Windows executable signing. Keep certificate material and passwords outside the
repository.

For a macOS publisher release, use a Developer ID Application identity on a Mac
and override the local ad-hoc identity and disabled notarization:

```sh
npm run dist:mac -- \
  -c.mac.identity="Developer ID Application: Your Name (TEAMID)" \
  -c.mac.notarize=true
```

Use your actual installed/imported signing identity. Hardened runtime and the
Electron entitlements are already configured in
[desktop/entitlements.mac.plist](../desktop/entitlements.mac.plist), including
the library-validation exception needed by the default ad-hoc build. Review
entitlements for the intended publisher release. The Apple ID route uses
`APPLE_ID`, `APPLE_APP_SPECIFIC_PASSWORD` and `APPLE_TEAM_ID`; certificate import
can use `CSC_LINK` and `CSC_KEY_PASSWORD`. Configure these as environment secrets,
then follow the [macOS signing](https://www.electron.build/v26/docs/features/code-signing/code-signing-mac/)
and [notarization](https://www.electron.build/v26/docs/features/code-signing/notarization/)
guides. Signing and notarization are optional separate build work, not completed
by the local unsigned/ad-hoc validation. The packaging scripts still do not
publish the resulting files.

## Validation scope

### Version 1.0.3 packages — 30 October 2026

The 1.0.3 packages are built with the same normal build checks as 1.0.2, with
integrity reports published alongside the downloads. Launch tests of the
finished packages, full races and physical-device play were not run. See
[the release notes](releases/1.0.3.md).

### Version 1.0.2 packages — 29 October 2026

The 1.0.2 packages are built with the same normal build checks as 1.0.1, with
integrity reports published alongside the downloads. Launch tests of the
finished packages, full races and physical-device play were not run. Source
unit and browser results are in the
[comparison report](original-comparison-2026-10-28.md). See
[the release notes](releases/1.0.2.md).

### Version 1.0.1 packages — 28 October 2026

The 1.0.1 packages are built with the normal build checks: staged game files
are verified byte for byte, and each packaged application is checked against
them, with integrity reports published alongside the downloads. Launch tests
of the finished packages, full races and physical-device play were not run.
Source-level unit and browser results are in the
[comparison report](original-comparison-2026-10-28.md). See
[the release notes](releases/1.0.1.md).

### Version 1.0.0 packages — 26 October 2026

The 1.0.0 release creates and publishes desktop packages without tests, launch
checks, payload verification or other build checks, as explicitly requested.
Successful packaging is not gameplay validation. Historical source and package
results below remain tied to their original checkpoints and are not repeated
or relabeled as 1.0.0 results. See [the release notes](releases/1.0.0.md).

### Version 0.9.0 packages — 25 October 2026

All eight packages use the existing `v0.9.0` game-source tag. Linux and Windows
packages are built on Linux. Both Mac architectures are packaged and ad-hoc
signed on a GitHub-hosted Mac using the manual
[macOS release workflow](../.github/workflows/macos-release.yml). It accepts an
existing version tag and draft GitHub release; it uploads the DMGs, ZIPs and
payload reports. It does not create or move version tags or publish the draft.

All four payload reports confirm the same 6,868 game files, byte-for-byte.
The packaged Linux app passes a focused launch and version-menu check under
Xvfb/SwiftShader with the normal sandbox. Windows/macOS gameplay, physical
devices, publisher signatures and notarization are outside this check. No
full suite or full races were rerun. The release's build metadata and checksums
record the packages separately from the historical tests below.

### Earlier checkpoints

The 23 October HUD follow-up reran the **source** Electron check: all 12 checks
passed under Linux/Xvfb/KWin/SwiftShader with the normal sandbox enabled. Its
world/HUD/presentation assertions now cover the RGB565 composition path. No
package was rebuilt or retested; the package results below remain historical.
See [the focused follow-up](research-hud-framebuffer.md).

At the 20 October 2026 integration checkpoint, **513 JavaScript tests** passed,
including six desktop protocol and startup tests. Both the source launcher and
the actual Linux AppImage passed
**12 desktop checks**: intro decoding/playback, movie byte ranges, renderer
isolation, original menu imagery/greeting, fullscreen, single-instance focus,
QuickRace opening/countdown, keyboard movement and race audio, save persistence,
and the original quit requester. The normal Chromium sandbox remained enabled.
The AppImage ran directly, without an extraction or FUSE fallback.

These results describe that source and package checkpoint. Later source fixes
have separate focused checks in [the validation record](validation.md); existing
packages do not automatically include them. The historical AppImage and Windows
packages were not attached to the initial source-only publication. Version
0.9.0 packaging coverage is listed above; this older record does not establish
current gameplay validation on every platform.

These automated runs used Linux/Xvfb, KWin and SwiftShader. They do not establish
physical GPU performance, speaker output, physical controller operation, full
race completion or new original-game parity. The earlier browser and native
research records remain separate. The Windows x64 installer and ZIP were
cross-built on Linux; native Windows execution remains untested. macOS package
creation and ad-hoc signing now pass in the 0.9.0 follow-up above; gameplay,
publisher signing and notarization still require separate validation.

See [the consolidated record](../evidence/desktop/validation.json),
[source launch checks](../evidence/desktop/source/report.json) and
[AppImage checks](../evidence/desktop/packaged/report.json). Earlier test-harness
fullscreen failures are retained separately: a window manager and native
Electron key events were needed to exercise browser-side shortcuts.

To repeat the Linux checks in an isolated display, install `xvfb-run`,
`dbus-run-session`, `wmctrl`, and one of Openbox, Fluxbox or KWin X11, then run:

```sh
npm test
bash tools/run-desktop-test-linux.sh
RCSK_DESKTOP_EXECUTABLE="$PWD/release/RedCat-SuperKarts-1.0.3-linux-x86_64.AppImage" \
  bash tools/run-desktop-test-linux.sh
```

The helper starts and cleans up its own display and window manager. On an
existing Linux X11 desktop, `npm run test:desktop` runs the same checks directly.
Tests use a temporary profile and remove it after closing the app.
