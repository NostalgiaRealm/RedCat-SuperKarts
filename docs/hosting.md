# Hosting this port

How to build the folder a web server needs, what the server has to send with it, and how to put it in the place of
the JavaScript port at **https://games.nostalgiarealm.com/redcatsuperkarts/** with the JavaScript port kept at
`/redcatsuperkarts/classic/`, the way RedCat Spookkasteel 2.0.0 was put on the site (its `docs/hosting.md` is the
model). Nothing in this project uploads or changes anything on a server: the steps under "Putting it on the site" are
for you to carry out. The desktop app serves the same folder from its own protocol ([`building.md`](building.md)).

## Build and check

```bash
npm run package
```

```bash
npm run package:check
```

`npm run package` (`tools/package.mjs`, a few seconds) writes `dist/site/` and copies the three nginx files next to it
(`dist/nginx-redcatsuperkarts*.conf`). `npm run package:check` (`tools/package-check.mjs`, about two minutes; add
`--firefox` to try Playwright's Firefox too) serves that folder below `/redcatsuperkarts/` with the headers of those
files and uses it as a browser would; see "Checked" at the end. Both read the original game files from the CD copy and
the installation copy inside the JavaScript port's folder (`SUPERKARTS_DISC`, `SUPERKARTS_DATA` name others;
`tools/game-data.mjs`) and write only under `dist/` and `evidence/package/`.

Before packaging, when they are out of date:

| Command | Needed after |
|---|---|
| `npm run recompile` | a change in `tools/recomp/` |
| `npm run manifest` (`tools/build-manifest.mjs`) | a change in which original files exist |
| `npm run preload` (`tools/build-preload.mjs`, 15 seconds) | either of the two above, or a change in how the host reads files |
| `npm run assets` (`tools/build-assets.mjs`) | a change in which of the JS port's menu assets the menu uses |

`npm run package` refuses to build when `public/game/files.json` does not list the game files as they are.

## What is in `dist/site/`

```text
site/
├── index.html, build.json    the page; what was built (revision, date, sizes)
├── app/<revision>/
│   ├── source/               the scripts and style sheets of the page, the game worker and the render worker
│   └── game/                 rcskspel.wasm (the recompiled race), its tables, files.json, preload.json
├── assets/                   the menu's art, voices, intro and reward movies, help, touch art
└── data/                     the original game files the race reads (89), and index.json (their names and sizes)
```

918 files, 366.8 MB (app 4.6 MB, assets 173.9 MB, data 188.2 MB), plus 157 `.gz` copies. Every URL in it is relative:
it works below any folder.

- **`app/<revision>/`**: twelve hex digits made from the content of everything below it. Another script or another
  game module gives another folder name and `index.html` names its own, so a browser never combines the files of two
  builds, files below `app/` can be kept by browsers for good, and a page that is open during an upload keeps finding
  its files as long as its folder is left on the server.
- **`data/`**: the race's own files, as the original installation has them (`tools/game-data.mjs`): the CD's
  `data\Game` files and the archives `rcs.img`/`rcs.ind` and `rc.img`/`rc.ind`, taken from the CD copy under the
  installation's names. Not in it: `debug.txt` and the installation's `race.ini`, which the original wrote under Wine
  (the CD's `race.ini` is in it), the programs (`RCSK.exe`, `rcskspel.dat`, `rcskmenu.dat`, `RCMovie.dat`,
  `SMACKW32.DLL`), the help and the menu's own folders (`gfx/`, `ini/`, `Players/`), which the race never reads.
- **`assets/`**: only what this port's menu uses: 758 files, 174 MB of the JS port's 418 MB (`tools/build-assets.mjs`
  copies them into `public/assets`, so neither the development server nor the package needs the JS port's folder).
  138 MB of it are the menu's voices (398 `.wav`, each fetched when it plays).
- **`.gz` copies**: next to every file that gzip makes at least a tenth smaller, `<file>.gz`; nginx sends it to a
  browser that accepts it (`gzip_static`). The game module goes from 3.8 MB to 0.6 MB, a track's `.rmp` from 0.5 to
  0.1 MB. **None** next to `rcs.img` and `rc.img` (read by byte ranges), the `.wav` voices and the `.mp4` movies (the
  browser's media elements ask for byte ranges): nginx's `gzip_static` would answer a Range request with bytes of the
  `.gz` (`tools/package-check.mjs` checks there is none).

## How the game's files reach the browser

The race reads its files as the original did: it opens one and reads it, or seeks into `rcs.img` (180 MB, the packed
textures, meshes and sounds of all six tracks and four karts) and reads a member. Until 2026-11-25 the worker fetched
every file whole before a race: 185 MB, almost all `rcs.img`. Now (`source/web/game-files.js`):

- **`rcs.img` and `rc.img` are read by byte ranges** (`Range: bytes=a-b`, answered `206`) in pages of 16 KB; a page
  once fetched is kept by the game worker for the races after it.
- **Before a race** the worker fetches what the race's lists name and it does not have yet: its files whole, and the
  archive pages in runs (one request per run, runs less than 64 KB apart in one), six requests at a time, each asked
  again twice when it fails. All INI files come along. The lists (`game/preload.json`, 8 KB) are measured
  (`tools/build-preload.mjs`): every country, race type and character (96 races) run in Node from boot through the
  countdown, 400 passes of driving and the finish (the cheat Ctrl+F+I) to the race's exit; what all races read, what
  each country, race type and character adds, and what each race adds beyond that.
- **Anything else** is fetched when the race reads it, with the game thread waiting: a whole file, or the missing
  pages from the read on, 128 KB at least. Mostly a voice or sound the measured races did not play (the game loads a
  sound when it first plays it). Measured on whole races driven by a test bot in Node with the browser's file code
  (`tools/checks/loading-full-race.mjs`, `evidence/loading/full-races.json`): 1 to 8 such waits in a race of five laps,
  64 to 128 KB each; in the browser one took 29 to 50 ms on the local stand-in server.
- A server that ignores `Range` and answers `200` with the whole file still works: the first request of an archive is
  made alone, and its whole answer is kept (180 MB, as before).

What a race fetches (headless Chromium on the packaged site, `npm run package:check`; MB as sent, `.gz` counted packed;
`evidence/package/result.json`; before: the development server, `evidence/checks/loading-before.json`):

| | Before (whole files) | Now |
|---|---|---|
| First race (Nederland, RedCat, Landenrace), game module included | 180.2 MB | 30.3 MB (28.6 MB of game files; 0.7 MB module; 1.0 MB the menu's loading screen and voices) |
| Second race, another track (Groot-Brittannië), same page | 2.4 MB | 7.9 MB |
| Both | 182.5 MB | 38.2 MB |
| Second visit, first race again | 180 MB again from the browser's cache | about 1 MB sent (the scripts, module and pages from the browser's cache) |

A race reads 22 to 30 MB of the original files (`evidence/loading/preload-summary.json`): `rcs.img` 19 to 26 MB of it,
uncompressible by `gzip_static` because it is read by ranges (as its members, about 40% smaller gzipped; a possible
next step is the archive's members as separate packed files). The JavaScript port's race needs about 15 MB gzipped.

## The server as it is, and what changes

Looked at on 25 November 2026 over SSH, read only (`/etc/nginx/sites-available/games.nostalgiarealm.com`):

| | Now |
|---|---|
| Server | nginx 1.26.3 with `http_gzip_static_module`, HTTP/2; `conf.d/*.conf` included in the `http` block (RedCat Spookkasteel's cache map is there already) |
| The game's location | `location /redcatsuperkarts/` with `root /var/www/games.nostalgiarealm.com`, `try_files $uri $uri/ =404`, dynamic gzip (JSON, JS, CSS, SVG, TTF and `application/octet-stream`); before it `location = /redcatsuperkarts` (301) and the regex against dotfiles |
| Headers | from the server block: `Cache-Control: no-cache` (always), the security headers (`snippets/security-headers.conf`: HSTS, nosniff, X-Frame-Options, Referrer-Policy, a CSP without script rules); no isolation headers |
| The live build | `/var/www/games.nostalgiarealm.com/redcatsuperkarts/` (owner `rick`, 428 MB): `index.html`, `src/main.js` and `runtime-manifest.json` are byte for byte `../RedCat Superkarts/dist` |
| Request limits | `limit_req` only on the two WordPress sites' logins; none for the games |

What this port needs on top of that:

| Change | Why |
|---|---|
| `Cross-Origin-Opener-Policy: same-origin` and `Cross-Origin-Embedder-Policy: require-corp` on every answer of this port | The page, the game worker and the render worker share memory, which a browser allows only on an isolated page. **Without them no race starts**; the page says so (in Dutch, in the menu's style) and links to `classic/` |
| `Range` for `data/` | nginx's static module answers single ranges by itself (`206`); nothing to configure, but no `.gz` copy and no dynamic gzip may come in its way: the location has `gzip off` and the package has no `.gz` of the archives |
| `Cache-Control` by folder: `app/` and `data/` a year and `immutable`, `assets/` a day, the rest `no-cache` as now | `index.html` is asked for at every visit; what it names never changes under its name |
| `gzip_static on` | Sends the `.gz` copies (the module is there) |
| The security headers repeated in the location | A location with `add_header` lines of its own no longer inherits the server's |

The old version needs nothing new: it gets its own location, `classic/`, answered exactly as today (the server's
headers, its gzip). No `Cross-Origin-Resource-Policy` header is sent: everything the page loads is its own origin's.

**The folder.** The new port goes into a folder of its own **beside** the old one, not inside it: the JavaScript
port's `tools/deploy-website.sh` mirrors its build into `redcatsuperkarts/` with `--delete`, which would remove a
folder inside it.

```text
/var/www/games.nostalgiarealm.com/
├── redcatsuperkarts/           the JavaScript port, where it is now    ->  /redcatsuperkarts/classic/
└── redcatsuperkarts-recomp/    this port (the content of dist/site)    ->  /redcatsuperkarts/
```

The switch is a change of the nginx configuration and a reload; going back is the old configuration and a reload.
The JavaScript port's own `tools/deploy-website.sh` keeps working on `redcatsuperkarts/`; after the switch set
`RCSK_DEPLOY_URL=https://games.nostalgiarealm.com/redcatsuperkarts/classic/` in `~/.config/redcat-superkarts/deploy.env`,
or its check of the public address reports a difference.

Three configuration files, all in `dist/` after packaging (their sources are in this folder):

| File | Goes to | What it is |
|---|---|---|
| `nginx-redcatsuperkarts-cache.conf` | `/etc/nginx/conf.d/redcatsuperkarts-recomp-cache.conf` (`http` block) | What a browser may keep, by folder (`$redcatsuperkarts_cache_control`) |
| `nginx-redcatsuperkarts-test.conf` | `/etc/nginx/snippets/redcatsuperkarts-recomp-test.conf` | A temporary address, `/redcatsuperkarts-test/`, to try the upload on the real server |
| `nginx-redcatsuperkarts.conf` | `/etc/nginx/snippets/redcatsuperkarts-recomp.conf` | The two final locations: this port, and the old one at `classic/` |

**Not run through nginx here** (none is installed on this machine): the package was checked behind a stand-in server
that answers as these files describe (`tools/serve-site.mjs`). That is what the temporary address is for.

## Saves

The JavaScript port and this port keep their saves in the browser's `localStorage` under the same keys
(`rcsk.race-save.v1`, `rcsk.settings.v1`, `rcsk.selection.v1`, `rcsk.firsttime.*`), read and written by the same code.
`localStorage` belongs to the origin (`https://games.nostalgiarealm.com`), not to the folder, so **`/redcatsuperkarts/`
and `/redcatsuperkarts/classic/` share the saves automatically**: a visitor's Adventure profiles, highscores, records
and settings from the old version are there in the new one at the first visit, and playing either version updates the
same saves. Nothing to migrate, nothing to do on the server. (Other origins and the old desktop app: README, "Saves".)

## Putting it on the site

Commands marked *server* are run on the web server (`ssh Debian`), the others in this project's folder.

**1. A folder for the new port** (*server*). `/var/www/games.nostalgiarealm.com` belongs to root; the new folder gets
your account, as `redcatsuperkarts/` has.

```bash
sudo install -d -m 755 -o rick -g rick /var/www/games.nostalgiarealm.com/redcatsuperkarts-recomp && ls -ld /var/www/games.nostalgiarealm.com/redcatsuperkarts* && df -h /var/www
```

The package needs 380 MB there.

**2. The nginx files on the server.**

```bash
npm run package && rsync -a dist/nginx-redcatsuperkarts.conf dist/nginx-redcatsuperkarts-cache.conf dist/nginx-redcatsuperkarts-test.conf Debian:
```

(*server*) The first command must print nothing (no file of that name yet); then the copies, and a backup of the site's
configuration that is kept for going back (`cp -n`: a second run never overwrites it):

```bash
ls /etc/nginx/conf.d/redcatsuperkarts* /etc/nginx/snippets/redcatsuperkarts* 2>/dev/null
```

```bash
sudo cp ~/nginx-redcatsuperkarts-cache.conf /etc/nginx/conf.d/redcatsuperkarts-recomp-cache.conf && sudo cp ~/nginx-redcatsuperkarts-test.conf /etc/nginx/snippets/redcatsuperkarts-recomp-test.conf && sudo cp ~/nginx-redcatsuperkarts.conf /etc/nginx/snippets/redcatsuperkarts-recomp.conf
```

```bash
sudo cp -n -p /etc/nginx/sites-available/games.nostalgiarealm.com /etc/nginx/sites-available/games.nostalgiarealm.com.bak-before-redcatsuperkarts-recomp
```

**3. The temporary address** (*server*). Adds one line, `include /etc/nginx/snippets/redcatsuperkarts-recomp-test.conf;`,
directly above `include /etc/nginx/snippets/barbiepaardrijclub.conf;`; the live game is not touched. The edit stops
without changing anything when the file is not as expected.

```bash
sudo python3 - <<'EOF'
p = '/etc/nginx/sites-available/games.nostalgiarealm.com'
s = open(p).read()
anchor = '    include /etc/nginx/snippets/barbiepaardrijclub.conf;\n'
line = '    include /etc/nginx/snippets/redcatsuperkarts-recomp-test.conf;\n'
assert s.count(anchor) == 1 and line not in s, 'unexpected file: nothing changed'
open(p, 'w').write(s.replace(anchor, line + '\n' + anchor))
EOF
```

```bash
sudo nginx -t && sudo systemctl reload nginx
```

`nginx -t` must say `syntax is ok` and `test is successful`; only then is it reloaded.

**4. Upload and check the temporary address.**

```bash
REDCAT_SITE_URL=https://games.nostalgiarealm.com/redcatsuperkarts-test/ tools/deploy-site.sh
```

```bash
npm run site:check -- --url https://games.nostalgiarealm.com/redcatsuperkarts-test/ --burst
```

The first builds, checks the package, uploads (the first time all of it, 367 MB) and ends with `all checks passed` from
`tools/site-check.mjs`; the second asks the real server for every file again and for what a browser asks for before a
first race, twice. A `note` is something that works but could be better (it says what). Then open
<https://games.nostalgiarealm.com/redcatsuperkarts-test/> in your own browsers (desktop, phone) and race: this is the
first time the port runs from the real server in a real browser, with sound. The saves there are already yours (same
origin).

**5. The switch** (*server*). Replaces the whole block `location /redcatsuperkarts/ { … }` (the one with
`root /var/www/games.nostalgiarealm.com;` and `try_files`) by `include /etc/nginx/snippets/redcatsuperkarts-recomp.conf;`
and removes the temporary address's line; the two locations above it (`= /redcatsuperkarts` and the regex against
dotfiles) stay. Checked on a copy of the live file (2026-11-25): exactly those lines change.

```bash
sudo python3 - <<'EOF'
import re
p = '/etc/nginx/sites-available/games.nostalgiarealm.com'
s = open(p).read()
test = '    include /etc/nginx/snippets/redcatsuperkarts-recomp-test.conf;\n\n'
block = re.findall(r'\n    location /redcatsuperkarts/ \{\n.*?\n    \}\n', s, re.S)
assert len(block) == 1 and 'try_files $uri $uri/ =404;' in block[0], 'unexpected file: nothing changed'
s = s.replace(block[0], '\n    include /etc/nginx/snippets/redcatsuperkarts-recomp.conf;\n').replace(test, '')
open(p, 'w').write(s)
EOF
```

```bash
sudo nginx -t && sudo systemctl reload nginx
```

Do it at a quiet moment. A reload drops no connection; somebody who has the old game open keeps what his page has
loaded, and the next file it asks for is no longer at its old address (the page then stops until it is loaded again,
which brings this port). The saves are in the browser, not in the page, and are the same for both versions. Everybody
else gets this port at the next visit, because the old page was always sent with `no-cache`.

**6. Check the public address.**

```bash
npm run site:check -- --url https://games.nostalgiarealm.com/redcatsuperkarts/ --classic
```

Then, in a browser that played the JavaScript port there: the menu shows its players and records; `classic/` opens the
old version with the same saves.

**Going back** (*server*):

```bash
sudo cp /etc/nginx/sites-available/games.nostalgiarealm.com.bak-before-redcatsuperkarts-recomp /etc/nginx/sites-available/games.nostalgiarealm.com && sudo nginx -t && sudo systemctl reload nginx
```

Nothing in a visitor's browser has to be undone. The new folder and the snippet files may stay; they are not used.

## A later build

```bash
tools/deploy-site.sh --dry-run
```

```bash
tools/deploy-site.sh
```

One command builds the site, checks the package, uploads and checks the public address (`tools/deploy-site.sh`;
settings in `~/.config/redcat-superkarts/deploy-site.env`: `REDCAT_SITE_HOST` (default `Debian`), `REDCAT_SITE_PATH`
(default `/var/www/games.nostalgiarealm.com/redcatsuperkarts-recomp`), `REDCAT_SITE_URL`). It needs no `sudo`: the
folder belongs to your account.

- It refuses a destination that is not an absolute path ending in `/redcatsuperkarts-recomp`, and a folder on the
  server that is neither empty nor holds a `build.json` of this project (the JavaScript port's folder is never its
  target).
- The new `app/<revision>/` is uploaded beside the one in use, and of `assets/` and `data/` only files whose content
  changed are sent. Then `index.html`, `index.html.gz` and `build.json` go together: that is the switch. nginx sends
  the `.gz` copy without comparing it with the file, so those two must never be uploaded apart.
- Nothing is deleted on the server. `tools/deploy-site.sh --prune` removes the revisions under `app/` that the live
  page no longer names; leave a day between an update and a prune, so pages that are still open keep their files.
- A change of the nginx files themselves still needs `sudo` on the server, as the first time (steps 2 and 5's
  `nginx -t` and reload).

## Checked

On 25 November 2026, on the development machine (`evidence/package/result.json`):

- **The folder** (`npm run package:check`): the revision is its content's; every file the page, the scripts reachable
  from it (the game worker, the render worker, the file loader and the host among them) and the style sheets refer to
  is there; the 89 game files are `files.json`'s at their sizes, and nothing else is in `data/` (no `debug.txt`, no
  program); every file the lists name is in `files.json`; the loading screens and voices the menu names through
  `manifest.json` (429) and the movies are in `assets/`; the `.gz` copies unpack to their files and there is none next
  to the archives, voices or movies; names are plain and differ in more than case.
- **The stand-in server's answers** (`tools/serve-site.mjs`): the redirect, the isolation headers, each folder's cache
  rule, `.gz` to a client that takes it, 304, `rcs.img` by a byte range from a client that takes gzip (206, the exact
  bytes, not packed), 416 beyond the end, 404 for a missing script and a dotfile, nothing outside the prefix;
  `classic/` (the JavaScript port's `dist/`) as the site answers it today.
- **`tools/site-check.mjs`** against the stand-in server, with `--classic --burst`: all checks pass.
- **Headless Chromium, 25 ms before every answer** (software WebGL): the menu comes up with every picture and nothing
  missing; a QuickRace from the menu (Nederland) loads in 1.7 s from its loading screen, runs, is finished with the
  race's cheat, and the debrief and highscore follow; a second QuickRace on Groot-Brittannië in the same page; the game
  thread waited 0 and 1 time; nothing is asked for outside `/redcatsuperkarts/`. A second visit fetches no script or
  module file again.
- **Not supported**: without the isolation headers the menu shows "De races kunnen in deze browser niet starten: …"
  with a link to `classic/`; with WebGL 2 on an OffscreenCanvas taken away, the same notice naming WebGL 2.
- **Playwright's Firefox** (146, headless) on the package: the page is isolated and a race runs (`--firefox`).

Not checked:

- **nginx** with the three files, and the real server. Steps 3 to 6 are how that gets checked.
- **A real network, a real GPU, phones, Safari.** The delay was a fixed 25 ms per answer on one machine. About 30 MB
  have to arrive before a first race starts.
- **The desktop app** on this package (another check: `tools/desktop-check.mjs`, [`building.md`](building.md)).
