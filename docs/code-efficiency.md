# Code, loading and documentation efficiency

Date: 26 October 2026. This is a source update after the
[original-code comparison](full-source-audit.md), with its own validation.
Existing original-game behavior, intentional port features and saved-game
formats are retained. No release packages or published versions were changed.
The later [folder-separation follow-up](runtime-layout.md) also makes local
launches use generated bundles. The measurements and test counts below belong
to the original efficiency checkpoint; later layout changes do not alter those
retained reports.

## Combining JavaScript

The efficiency checkpoint combined reachable game modules and required Three.js
code into **six JavaScript files from 125 input modules**. Shared code has one
instance, and the race/track viewer remain loaded on demand. The resulting
JavaScript totals approximately **1.36 MB**, compared with **2.92 MB** of input
modules before bundling. These are uncompressed byte counts, not download-time
or frame-rate measurements. Source maps are additional debugging files that
normal gameplay does not download.

The authored `source/` files remain readable and retain native address comments,
focused tests and useful subsystem boundaries. Combining their generated output
avoids making native-code comparisons depend on one large hand-maintained file.
The pinned [esbuild configuration](../tools/bundle.mjs) uses module splitting,
unused-code removal and whitespace reduction. It retains property names, source
maps and license comments, with syntax minification disabled to preserve
arithmetic expressions. The later [mobile performance work](mobile-performance.md)
removed `keepNames` for its per-closure cost. See the
[esbuild API](https://esbuild.github.io/api/#splitting) for those build options.

All normal launches now use bundles and defer the WebGL renderer until a course
is opened. The sample-count selector now lives with settings, avoiding a
renderer import just to display settings. The unchanged NPC finish recorder
now lives with results, with its old export retained: menu score loading no
longer imports the opponent AI graph. In the earlier focused browser comparison,
the then-direct source menu fetched **26 scripts**, while the bundled menu fetched **three**.
Starting a bundled race fetched five scripts in total.

| Command | Behavior |
| --- | --- |
| `npm start` / `npm run dev` | Refresh local runtime bundles, then serve them with prepared assets. |
| `npm run bundle` | Refresh only the local `src/`, root page and manifest; reload the running page after edits. |
| `npm run build` | Generate combined output and copy the prepared original assets into `dist/`. |
| `npm run preview` | Serve that existing `dist/` at the usual local address; does not rebuild. |
| `npm run desktop` | Refresh local runtime bundles, then run them in Electron. |
| `npm run dist:linux`, `dist:win`, `dist:mac` | Existing packaging commands first generate the combined game payload. |

After updating this checkout, use `npm ci` once to install the locked build
dependency. The default browser address remains `http://127.0.0.1:4173/`.
Local-runtime and preview servers cannot occupy that port simultaneously.

Build output is prepared in `dist.tmp/` before replacing `dist/`, so compilation
or asset-copy failure leaves the previous output available. Its
`runtime-manifest.json` lists the generated entry/chunks and stylesheet;
Electron and preview check their presence before startup. The package verifier
continues checking packaged files against `dist/` byte for byte. Original
assets are copied without conversion or alteration.

## Runtime and maintenance corrections

- **HUD:** unchanged text retains its glyph layout and GPU buffers. Text,
  position, font metrics/rectangles, atlas dimensions, tint, alpha, visibility,
  viewport and notification changes invalidate the bounded per-string cache.
  Every required RGB565 draw still happens; paused redraws do not accumulate
  extra blending.
- **Transforms and effects:** existing matrices are filled directly, shadow
  endpoint matrices are captured once per simulation update, and five effect
  renderers share an allocation-free packed-color writer.
- **Items:** active pickup/projectile counts use loops without temporary
  filtered arrays. They still recount at the original callback boundaries;
  counts are not cached across collection or firing events.
- **Loading:** backing out while a track loads cannot resume it later or show
  an obsolete error over the current menu. A subsequent load waits for the
  preceding viewer load to finish before reusing its caches and audio.
- **File serving:** the local HTTP server and Electron share one path allowlist,
  MIME table and media-range implementation. This removes duplicated logic,
  adds the desktop path's suffix-range and symlink checks to HTTP, and reports
  an occupied local port clearly. The server stays bound to loopback.
- **Settings recovery:** unavailable browser storage is caught inside the
  persistence adapters. Corrupt settings produce fresh editable defaults
  rather than sharing frozen nested defaults. Valid saves are unaffected.

A CPU-only benchmark of 20,000 unchanged five-glyph HUD draws, using a no-op
renderer, measured a median **60.74 ms before / 13.59 ms after**. Repeated buffer
updates fell from 300,000 to zero. This measures HUD preparation only; it is
not a gameplay FPS or physical-GPU claim.

## Saved games require no migration

The existing `rcsk.race-save.v1`, `rcsk.settings.v1`, `rcsk.selection.v1` and
`rcsk.firsttime.*` keys, JSON shapes and normalization rules remain compatible.
Adventure profiles, unlocks, high scores, best times, selections, explicit
unbound keys and custom settings remain stored where they were.

Electron retains `rcsk://game` and its `RedCat SuperKarts` application-data
directory. Local and packaged desktop launches use that same identity.
Browser saves still belong to their existing scheme, host and port; deploying
at a different domain has always been a separate browser origin. Bundling
does not move the game's address or ask players to export/reset data.

The compatibility fixture contains all six high-score boards, all thirty
profile slots, non-ASCII names, campaign progress and custom settings. It was
independently accepted and round-tripped by the published v0.9.0 adapters before
checking the current adapters. Tests use disposable profiles and synthetic
saves, never a real player's data.

## Documentation review

The [documentation index](README.md) now provides a topic map. Detailed test
commands have a [development guide](development.md); the long former plan and
checkpoint descriptions remain under [history](history/reconstruction-plan.md).
The main README and current plan link to those records, preserving their
information while reducing repetition.

Current setup and deployment instructions describe generated chunks, the
unchanged save locations, preview and automatic movie playback. Stale Help,
constructor-reset, camera-path and distribution claims were reconciled with
the existing original-file evidence. Historical test counts and failed race
attempts remain historical; they were not relabeled as current success.

## Validation and limits

The [consolidated record](../evidence/code-efficiency/validation.json) links the
source hashes, commands, reports and review inventory:

- 720 authored runtime/desktop/tool/test files received syntax checks and a
  static local-import inventory; all 123 runtime JavaScript modules were
  inventoried for dependency and allocation patterns. Deeper review targeted
  rendering, loading, persistence and shared tooling. Generated original-code
  exports, vendor code and prepared assets were preserved.
- **101 distinct focused Node tests passed**, including native result/timer,
  HUD/shadow/effect, save compatibility, bundle and protocol cases.
- The source HUD checks cover **120 pixel comparisons**, three MSAA
  configurations, all four race modes, portrait layout and animated notices.
- Five source-browser save groups cover loading, continuation, normal writes
  and reloads. Thirteen final bundle/browser/Electron groups cover the same-origin
  upgrade, save persistence, intro, canceled loading, six short course drives,
  pause/resume, sandboxing and a Linux desktop relaunch/race load.
- Authored documentation received a local-link/anchor and npm-command check.
  External links were retained, not exhaustively network-tested.

The first bundle harness attempt had two test errors: its seed script accessed
storage on `about:blank`, and its cancellation event could occur before the
held track request began. The initial report is retained; the corrected harness
waits for that request and only seeds HTTP documents. Those were test corrections.

That efficiency validation generated temporary JavaScript output and removed it afterward.
It did **not** refresh the working `dist/`, create installers/archives, publish,
rerun the complete test suite or drive complete races. Linux checks used
Chromium/Electron and SwiftShader; native Windows/macOS, Safari, real devices
and whole-game equivalence remain separately documented in
[remaining work](remaining-work.md). Earlier evidence files retain their own
source snapshots and are not refreshed to imply new verification.
