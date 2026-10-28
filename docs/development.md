# Development and focused validation

[Documentation index](README.md) · [Run the game](../README.md#run-the-game) ·
[Current validation](validation.md)

Run commands below from the repository root. Choose checks for the subsystem
you changed; the commands are a reference, not a requirement to rerun every
suite after each edit. A successful build is separate from gameplay validation.

## Edit and refresh the game

Edit the modules, page template and stylesheet in [`source/`](../source/README.md).
Normal launches execute generated files in `src/`, not those individual
authoring modules. `npm start`, `npm run dev` and `npm run desktop` refresh
the bundles once before launching; they do not watch for further edits.
While a browser server is running, use `npm run bundle` after editing, then
reload the page. Reopen Electron after refreshing to load its new runtime.
`npm run build` creates a separate `dist/` for distribution. See
[the folder and command guide](runtime-layout.md).

## Choose relevant checks

These are development checks, not prerequisites for launching the game.

The rendering smoke tests now check the world and HUD separately from the
final screen copy. The [HUD rendering follow-up](research-hud-framebuffer.md)
records the relevant source checks; historical results retain their original
checkpoint and platform scope.

### Unit, parser and asset checks

```sh
npm test
npm run test:parsers
npm run test:assets
```

### Browser and gameplay checks

Some browser tests inspect individual modules or construct diagnostic scenes.
Start the explicitly enabled inspection server for those checks:

```sh
npm run dev -- --inspect-source
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

The game still uses its generated bundles in this mode. The extra `/source/`
and Three.js routes exist only for test imports; ordinary game servers reject
the authoring folder. See [the test guide](../tests/README.md) for tests that
manage their own server. Do not deploy the inspection server.

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

## Publishing releases

Follow the [release publication policy](releases/README.md). Every source
release must include the complete `original-source/` folder on GitHub and
GitLab, alongside editable port sources, generated runtime files, prepared
assets and documentation. It is a recovered inspection reference, not a
replacement for `source/` or an input to the game's runtime bundle.

The 1.0.0 release explicitly skipped tests and build checks. The commands above
remain available for later development and were not run as part of that
release. The 1.0.1 and 1.0.2 releases run the normal packaging checks. Release notes must describe actual validation, keeping prior results
attached to their original checkpoints.

## Retained checkpoints

The [validation overview](history/validation-overview.md) preserves the earlier
broad race and fidelity checkpoints. Their results belong to their recorded
source versions. Use [validation.md](validation.md) for later focused checks
and [remaining work](remaining-work.md) for gaps that still need verification.
