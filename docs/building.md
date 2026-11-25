# Building the desktop packages

RedCat SuperKarts 2.0.0 is the recompiled port in an Electron window: the packaged website (`dist/site`, built by
`npm run package`, see [`hosting.md`](hosting.md)) served by the app itself under `rcsk://game`. It replaces the
JavaScript port's desktop app (1.0.x) and keeps its identity, so an installed 1.0.x's saves carry over.

| | |
|---|---|
| Shell | `electron/main.mjs`, `runtime.mjs`, `game-protocol.mjs`: the JS port's (`../RedCat Superkarts/electron/`), on `dist/site` |
| Builder | `electron-builder.json`: the JS port's targets, names, icons and macOS settings; the site goes to `resources/site` without its `.gz` copies (they are for nginx's gzip_static) |
| Packaged-file check | `tools/verify-desktop-package.mjs` (afterPack): `resources/site` equals `dist/site` (less the `.gz` copies) byte for byte, `app.asar` holds only the shell, versions agree; writes `integrity-<platform>-<arch>.json` |
| Launch check | `tools/desktop-check.mjs` (Linux, Xvfb, SwiftShader; `evidence/desktop/report.json`) |
| macOS | `.github/workflows/macos-release.yml` on a GitHub-hosted Mac |
| Versions | Electron 44.9.2, electron-builder 26.15.3, Playwright 1.58.2: the JS port's (devDependencies, `package-lock.json`) |

## What the shell does

- **Identity, as 1.0.x:** name `RedCat SuperKarts`, appId `org.redcat.superkarts.port`, scheme `rcsk`, origin
  `rcsk://game`, profile `<appData>/RedCat SuperKarts` (`~/.config/RedCat SuperKarts`, `%APPDATA%\RedCat SuperKarts`,
  `~/Library/Application Support/RedCat SuperKarts`). Both ports keep their saves in that origin's localStorage under
  the same `rcsk.*` keys with the same code, so 2.0.0 opens a 1.0.x player's Adventure profiles, highscores, records,
  settings and selection as they are. The Windows installer has the same appId, from which electron-builder derives
  the installer's GUID, so it should install over 1.0.x (not tried on Windows).
  `RCSK_USER_DATA=/absolute/folder` picks another profile (tests).
- **The protocol** (`game-protocol.mjs`) serves every file of the site with `Cross-Origin-Opener-Policy: same-origin`,
  `Cross-Origin-Embedder-Policy: require-corp` and `Cross-Origin-Resource-Policy: same-origin` on every answer, the
  404s too (the game and render workers share memory with the page), a Content-Security-Policy with
  `'wasm-unsafe-eval'` and `worker-src 'self'` (inline scripts by hash; workers take the policy of their own script),
  single byte ranges (206, 416) for `data/` and the movies, and the types the site needs (`application/wasm`, wav,
  mp3, mp4, ttf, json; the original's own data files as `application/octet-stream`). Paths with `..` or a leading dot
  and anything outside the site are refused.
- **As the JS app:** F11 and Beeld → Volledig scherm, the menu bar Spel / Bewerken / Beeld, one instance per profile (a
  second start focuses the running window), navigation only to the page itself (other pages, other origins and new
  windows are refused), a sandboxed renderer without Node, `--skip-intro`. Stoppen → Ja in the menu closes the app.

## Build

Node.js 24 and npm. Once: `npm ci`. Then the site, the version and the packages:

```bash
npm run package                 # dist/site (docs/hosting.md)
npm version 2.0.0 --no-git-tag-version   # or by hand: package.json, then npm run version:sync (source/version.js)
npm run dist:linux              # AppImage and tar.gz, x64
npm run dist:win                # NSIS installer and zip, x64 (cross-built on Linux)
```

The packages land in `release/<version>/` (gitignored) with `integrity-<platform>-<arch>.json` beside them;
`linux-unpacked/` and `win-unpacked/` are the unpacked apps. `npm run desktop` opens a checkout in Electron on
`dist/site` (or on the absolute folder in `RCSK_SITE`). `RCSK_SKIP_BUILD_CHECKS=1` skips the afterPack check.

Windows is cross-built on Linux, without Wine: electron-builder writes the executable's icon and version resources
itself. Nothing is signed: there is no certificate, so its "signing with signtool.exe" lines change nothing (the
executables have no certificate table). Building a package does not run it.

## Check

```bash
node tools/desktop-check.mjs --legacy /path/to/RedCat-SuperKarts-1.0.3-linux-x64/redcat-superkarts
```

Runs `release/<version>/linux-unpacked/redcat-superkarts` (`--exe` another; `--source` the checkout) under `xvfb-run`
on a fresh profile. With `--legacy` (the 1.0.x Linux executable, e.g. from its release `tar.gz`) that app first writes
saves with its own menu on the same profile (an Adventure profile "Rick", Meer instellingen, Alles ontgrendelen, a
QuickRace selection, and a finished race and highscore through the same save code), and the check then shows 2.0.0
reads every key unchanged and its menu shows them. Then: the intro and the menu, `crossOriginIsolated`, the
protocol's headers, types, ranges and refusals, menu bar, F11 (Electron's fullscreen state; there is no window
manager in Xvfb), single instance, a QuickRace that runs and draws (a screenshot), Esc + J, a relaunch with the saves
kept, the navigation lock, Stoppen → Ja. Not checked: Windows and macOS execution, a physical GPU, sound output, a
whole race. The Chromium profile lock needs a short temp path: leave `TMPDIR` short. `--out DIR` keeps a run's
report apart (default `evidence/desktop/`).

The AppImage itself needs FUSE 2 (`libfuse.so.2`) to start. To check its contents on a machine without it, unpack it
and run the check on what it holds (`--appimage-extract-and-run` is no substitute in a check: a second start, as in
the single-instance check, removes the shared extraction folder under the running first one):

```bash
(cd /some/empty/folder && /path/to/RedCat-SuperKarts-2.0.0-linux-x86_64.AppImage --appimage-extract)
node tools/verify-desktop-package.mjs /some/empty/folder/squashfs-root/resources
node tools/desktop-check.mjs --exe /some/empty/folder/squashfs-root/redcat-superkarts --out evidence/desktop/appimage
```

## macOS

DMG and ZIP for x64 and arm64 are built on a GitHub-hosted Mac by `.github/workflows/macos-release.yml`, as for
1.0.x (ad-hoc signed, hardened runtime, `desktop/entitlements.mac.plist`, not notarized). The original game files
are not in git (`rcs.img` alone is ~180 MB, over GitHub's 100 MB file limit), so the runner cannot build the site:
it downloads the `dist/site` the Linux and Windows packages were built from, as a release asset, and checks that
its packaged site has the Linux build's `gameTreeSha256`. Steps for a release, after the Linux and Windows packages
are built from the same `dist/site`:

```bash
npm run site:archive            # release/2.0.0/RedCat-SuperKarts-2.0.0-site.tar.gz and .sha256 (reproducible)
git tag v2.0.0 && git push origin v2.0.0
gh release create v2.0.0 --draft --title 'RedCat SuperKarts 2.0.0' --notes-file NOTES.md   # the release notes
gh release upload v2.0.0 release/2.0.0/RedCat-SuperKarts-2.0.0-site.tar.gz release/2.0.0/RedCat-SuperKarts-2.0.0-site.tar.gz.sha256
gh workflow run macos-release.yml -f tag=v2.0.0 \
  -f game_tree_sha256=$(node -p "require('./release/2.0.0/integrity-linux-x64.json').gameTreeSha256")
gh run watch                    # the two jobs upload the DMGs, ZIPs and integrity-darwin-*.json to the draft
```

The site archive may stay on the release (it is the website package less its `.gz` copies, game files included, as
the desktop packages already carry them) or be removed before publishing: `gh release delete-asset v2.0.0 RedCat-SuperKarts-2.0.0-site.tar.gz`
(and the `.sha256`). A run of the workflow on another `dist/site` fails at "Check the packaged game is the Linux
build's". `gh workflow run` needs the workflow on the repository's default branch.

## Icons

`desktop/icons/` and `desktop/entitlements.mac.plist` are the JS port's, copied unchanged (made by its
`tools/prepare-desktop-icons.mjs` from the original launcher icon `assets/ui/original.ico`; `provenance.json`).
