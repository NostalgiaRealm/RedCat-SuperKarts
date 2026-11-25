#!/usr/bin/env bash
# Puts a build of this port on the website in one command (docs/hosting.md, "A later build"). RedCat Spookkasteel's
# tools/deploy-site.sh, for this port.
#   tools/deploy-site.sh --dry-run    builds, and lists what would change on the server
#   tools/deploy-site.sh              builds, checks, uploads, switches and checks the public address
#   tools/deploy-site.sh --prune      also removes revisions under app/ that the live page no longer names
# It builds dist/site (npm run package), runs the folder and server-answer part of the package check, then uploads
# over SSH with rsync:
#   1. everything except the page: the new app/<revision>/ lands beside the one in use, and only changed files of
#      assets/ and data/ are sent (the first time: all of data/, 188 MB, and assets/, 174 MB);
#   2. index.html, index.html.gz and build.json together: that is the switch;
#   3. tools/site-check.mjs asks the public address for every file and compares.
# Nothing is ever deleted on the server unless --prune is given, and then only folders under app/. The JavaScript
# port's folder (redcatsuperkarts/, served at classic/) is never touched; its own tools/deploy-website.sh mirrors into
# that folder with --delete, which is why this port has a folder beside it. Settings, overridable in
# ~/.config/redcat-superkarts/deploy-site.env (the JavaScript port's deploy.env in the same folder is its own):
#   REDCAT_SITE_HOST   SSH name of the web server             (default Debian)
#   REDCAT_SITE_PATH   the folder nginx serves this port from  (must end in /redcatsuperkarts-recomp)
#   REDCAT_SITE_URL    the public address                      (default https://games.nostalgiarealm.com/redcatsuperkarts/)
set -euo pipefail
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
config="${XDG_CONFIG_HOME:-$HOME/.config}/redcat-superkarts/deploy-site.env"
[ -f "$config" ] && . "$config"
host="${REDCAT_SITE_HOST:-Debian}"
dest="${REDCAT_SITE_PATH:-/var/www/games.nostalgiarealm.com/redcatsuperkarts-recomp}"
url="${REDCAT_SITE_URL:-https://games.nostalgiarealm.com/redcatsuperkarts/}"
dry=; prune=
for a in "$@"; do case "$a" in
  -n|--dry-run) dry=--dry-run ;;
  --prune) prune=1 ;;
  *) echo "Usage: $0 [--dry-run] [--prune]" >&2; exit 2 ;;
esac; done
# Never into a guessed folder, and never into the JavaScript port's: an absolute path ending in /redcatsuperkarts-recomp
dest="${dest%/}"
case "$dest" in /*/redcatsuperkarts-recomp) ;; *) echo "Refusing to deploy to '$dest': expected an absolute path ending in /redcatsuperkarts-recomp" >&2; exit 1 ;; esac
case "$url" in https://*/|http://*/) ;; *) echo "REDCAT_SITE_URL must be an http(s) address ending in /: '$url'" >&2; exit 1 ;; esac

cd "$root"
echo "== Building the site"
npm run --silent package
site="$root/dist/site"
rev=$(sed -n 's/.*"revision": "\([0-9a-f]*\)".*/\1/p' "$site/build.json")
[ -n "$rev" ] && [ -s "$site/index.html" ] && [ -d "$site/app/$rev" ] && [ -s "$site/data/rcs.img" ] || { echo "The package is incomplete" >&2; exit 1; }
echo "== Checking the package (folder and server answers)"
node tools/package-check.mjs --no-browser | tail -1

# The folder must exist, be writable by this account, and be this port's: empty (the first upload) or with a build.json
# of this project. A folder with an index.html but no build.json is something else (the JavaScript port's has one).
state=$(ssh -o BatchMode=yes "$host" "if [ ! -d '$dest' ]; then echo missing; elif [ ! -w '$dest' ]; then echo readonly; elif [ -f '$dest/build.json' ]; then grep -q '\"name\": \"redcat-superkarts-recomp\"' '$dest/build.json' && echo ours || echo foreign; elif [ -z \"\$(ls -A '$dest')\" ]; then echo empty; else echo foreign; fi")
case "$state" in
  ours|empty) ;;
  missing) echo "$host:$dest does not exist; create it first (docs/hosting.md, step 1)" >&2; exit 1 ;;
  readonly) echo "$host:$dest is not writable by this account (docs/hosting.md, step 1)" >&2; exit 1 ;;
  *) echo "$host:$dest is not this port's folder (no build.json of redcat-superkarts-recomp, and not empty): refusing" >&2; exit 1 ;;
esac
live=$(ssh -o BatchMode=yes "$host" "sed -n 's/.*\"revision\": \"\\([0-9a-f]*\\)\".*/\\1/p' '$dest/build.json' 2>/dev/null" || true)
echo "== On the server: revision ${live:-none}; this build: revision $rev${dry:+ (dry run)}"

# --checksum: a rebuild gives every file a new time; only files whose content changed are sent
opts=(-a --checksum --no-owner --no-group --chmod=D755,F644 --itemize-changes)
echo "== 1. Uploading everything but the page"
rsync "${opts[@]}" ${dry:+"$dry"} --exclude /index.html --exclude /index.html.gz --exclude /build.json "$site/" "$host:$dest/" | grep -c '^[<>]f' | sed 's/^/   files sent or to send: /' || true
echo "== 2. The page (the switch)"
rsync "${opts[@]}" ${dry:+"$dry"} "$site/index.html" "$site/index.html.gz" "$site/build.json" "$host:$dest/" | sed 's/^/   /'
[ -n "$dry" ] && { echo "Dry run: nothing was changed on the server."; exit 0; }

echo "== 3. Checking $url"
node tools/site-check.mjs --url "$url" | tail -1

if [ -n "$prune" ]; then
  echo "== Removing revisions the live page no longer names"
  ssh -o BatchMode=yes "$host" "cd '$dest/app' && for d in */; do d=\${d%/}; case \"\$d\" in $rev) ;; [0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f]) rm -rf -- \"\$d\"; echo \"   removed app/\$d\" ;; esac; done"
else
  old=$(ssh -o BatchMode=yes "$host" "ls '$dest/app' | grep -v '^$rev\$' | tr '\n' ' '")
  [ -n "$old" ] && echo "Older revisions still on the server (pages that are open keep using them): $old— remove them later with --prune"
fi
echo "Done: $url serves revision $rev."
