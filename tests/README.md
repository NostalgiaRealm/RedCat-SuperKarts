# Test inputs and the bundled game

The game runs the generated JavaScript in [`src/`](../src/), both locally and in
packaged releases. The editable modules in [`source/`](../source/README.md) are
build inputs. They are also imported directly by Node unit tests so individual
behaviors can be checked without launching the entire game. They are **not loaded
by normal game launches**.

Use the tests relevant to the change. There is no need to run every test or make a
desktop package after each edit. See the [development guide](../docs/development.md)
for the wider validation workflow and [validation records](../docs/validation.md)
for the scope of previous checks.

## Node tests

After `npm ci`, run an individual test or a related set:

```bash
node --test tests/bundle-runtime.test.mjs tests/server-runtime.test.mjs tests/electron-runtime.test.mjs
node --test tests/storage-compatibility.test.mjs
```

`npm test` runs the complete Node suite. Browser scripts and desktop checks are
separate; passing the Node suite does not establish runtime behavior on every
platform.

## Browser checks

Most browser scripts connect to a server that is already running. Start the
normal bundled game with `npm start`, then set `RCSK_URL` if the server is not at
`http://127.0.0.1:4173`:

```bash
RCSK_URL=http://127.0.0.1:4173 node tests/storage-compatibility-browser.mjs
```

Some rendering and simulation inspection scripts import individual `/source/`
modules or `three` inside the test page. These scripts need the explicit local
**diagnostic server** instead:

```bash
node tools/serve.mjs --inspect-source
RCSK_URL=http://127.0.0.1:4173 node tests/hud-framebuffer-browser.mjs
```

This opt-in server permits test imports and adds a Three.js import map. The game
entry still runs `/src/main.js` and its generated chunks. Normal `npm start`,
preview hosting and Electron do not expose editable source modules or standalone
Three.js modules. Do not use diagnostic mode as a production hosting setup.

`tools/mobile-performance.mjs` measures a race on emulated phones, and
`tools/golden-frames.mjs` compares exact framebuffer hashes between two builds; see
[mobile performance](../docs/mobile-performance.md). Both need the normal server.

`tests/subpath-browser.mjs` checks a built site served from a URL folder: the
intro movie, menu artwork and buttons, help pictures and a race, with no
request outside the folder. Point `RCSK_URL` at the folder, for example a local
`python3 -m http.server` above a copy of `dist/` named `redcatsuperkarts`, or
the live site after `tools/deploy-website.sh`.

`tests/bundle-browser.mjs` creates its own temporary server and runtime, checks
saved-data compatibility across a runtime refresh, and removes them afterward.
It can include a Linux Electron relaunch with `RCSK_BUNDLE_ELECTRON=1`. Its default
short driving checks cover six tracks; `RCSK_BUNDLE_TRACKS=2` selects England for a
focused layout check. These are opening/driving checks, not full-race validation.
