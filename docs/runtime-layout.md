# Editable files and generated runtime

The port's editable JavaScript lives in [`source/`](../source/README.md).
**The game does not directly load or execute those individual files.** Normal
browser and desktop launches execute the combined JavaScript under `src/`.
Source files are inputs to the bundler and to development tests.

## Which folder should I use?

| Location | Purpose |
| --- | --- |
| `source/` | Editable port modules, `index.html` template and `style.css`. Make game changes here. |
| `src/` | Generated runtime entry, shared/lazy chunks, source maps and stylesheet. Do not hand-edit. |
| Root `index.html` and `runtime-manifest.json` | Generated page and runtime file inventory used for local launches. |
| `public/assets/` | Prepared original artwork, menus, audio, movies and game data used by local launches. |
| `dist/` | Separately generated website/package payload, including its own runtime and copied assets. |
| `original-source/` | Recovered C-like pseudocode and assembly from the original Windows binaries. Reference material, not the editable JavaScript port. |
| `tests/` and `tools/` | Development checks, asset preparation, research and packaging helpers. |

The runtime contains a small set of JavaScript files rather than a copy of
every authoring module. A shared chunk avoids duplicating the library, while
race/track code loads when needed. Debugging maps can show readable authoring
code in developer tools; that does not mean the game loads individual source
modules. The manifest records the actual generated files.

The complete `original-source/` directory is retained in both public
repositories and every release source archive. It is published for inspection
and is not bundled into the browser or desktop game. See the
[release publication policy](releases/README.md).

## Refresh and run

| Command | What it does |
| --- | --- |
| `npm start` or `npm run dev` | Refresh the local runtime once, then serve it at `http://127.0.0.1:4173/`. |
| `npm run desktop` | Refresh the local runtime once, then open Electron. |
| `npm run bundle` | Refresh only the local runtime; no asset conversion, `dist/` copy or desktop package. |
| `npm run build` | Generate `dist/` from the authoring inputs and copy the prepared assets. |
| `npm run preview` | Serve the existing `dist/`; does not refresh it. |

Run `npm ci` when first installing the checkout or after dependency changes.
There is no automatic file watcher. After editing `source/` while the browser
server is running, run `npm run bundle` and reload the page, or restart the
server. Restart Electron to load refreshed code. Refreshing the local runtime
does not update a previously generated `dist/` or downloaded desktop package.

## Saves and diagnostic checks

This folder change does not alter the browser address, Electron's `rcsk://game`
origin or `RedCat SuperKarts` profile folder, or the existing saved-data keys
and formats. Existing saves need no reset, export or migration. Browser saves
continue to belong to their original scheme, host and port; a different URL
has separate storage, just as before.

Ordinary game servers do not serve `/source/`. Some browser checks deliberately
import authoring modules to inspect a subsystem. For those checks only, use
`npm run dev -- --inspect-source`. This enables diagnostic module routes and
a Three.js import map while the game itself still executes its bundles. The
inspection option is not needed for playing and is not a deployment mode.
See [development checks](development.md) and [the test guide](../tests/README.md).

## Documentation review — 26 October 2026

The layout review covers every authored Markdown guide in the repository:
the root overview/plan/changelog, `docs/` guides and research, release and
historical notes, source/test purpose guides, original-code reference guide,
and touch-art attribution. Current module paths, launch/build commands,
version-update instructions, HUD presentation notes and setup claims were
checked against the source and updated where needed. Local links, anchors and
npm script names receive a separate consistency check.
The audit covers 76 Markdown files, 482 local links/anchors and 80 npm-script
references, with no remaining errors. The [validation guide](validation.md#runtime-folder-separation--26-october-2026)
records the focused runtime and save-compatibility checks.

Historical validation counts, release details, frozen hashes and original
analysis records retain their checkpoint scope. Old evidence may name an
individual module under `src/`; its editable counterpart is now at the same
relative path under `source/`. Generated `src/` bundles must not be compared
with those old module hashes. Research references point to the current
authoring paths, while the retained historical plan explains its old spelling.

External reference links and prepared original assets are retained. This
documentation pass does not establish new native-game parity or target-device
validation; those limits remain in [remaining work](remaining-work.md).

## Focused validation

The [runtime browser report](../evidence/runtime-layout/bundle-browser.json)
passes eight focused groups: same-origin saved-game compatibility, intro/menu
flow, Adventure save writes and reload, canceled track loading, a short England
drive, pause/resume, and Linux Electron persistence and race/HUD loading.
These checks run the generated bundles, with ordinary source routes unavailable.
They are not full races or validation of new desktop packages.

The [documentation audit](../evidence/runtime-layout/docs-audit.json) inventories
the reviewed guides and records local-link, anchor and npm-command checks.
