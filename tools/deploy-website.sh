#!/usr/bin/env bash
# Publish the browser version to the Nginx webserver in one command.
#
#   tools/deploy-website.sh            build, upload and verify
#   tools/deploy-website.sh --dry-run  build and show what would change on the server
#
# Settings (environment, or ~/.config/redcat-superkarts/deploy.env):
#   RCSK_DEPLOY_HOST  SSH target, e.g. Debian or rick@SERVER ("local" = a local folder, for tests)
#   RCSK_DEPLOY_PATH  web folder on the server
#   RCSK_DEPLOY_URL   public address checked after the upload ("" skips the check)
#
# The upload mirrors the complete `npm run build` output in dist/ with rsync
# over SSH (docs/hosting.md): only files whose contents changed, all put in
# place at the end (--delay-updates), and files that no longer exist removed
# afterwards. Nginx keeps running; with Cache-Control: no-cache, browsers
# revalidate and load the new files on their next visit.
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
config="${XDG_CONFIG_HOME:-$HOME/.config}/redcat-superkarts/deploy.env"
[ -f "$config" ] && . "$config"
host="${RCSK_DEPLOY_HOST:-Debian}"
dest="${RCSK_DEPLOY_PATH:-/var/www/games.nostalgiarealm.com/redcatsuperkarts}"
url="${RCSK_DEPLOY_URL-https://games.nostalgiarealm.com/redcatsuperkarts/}"
dry=
case "${1:-}" in
  -n|--dry-run) dry=--dry-run ;;
  "") ;;
  *) echo "Usage: $0 [--dry-run]" >&2; exit 2 ;;
esac

# Never mirror into a guessed folder: the destination must be the absolute
# redcatsuperkarts folder (or end in it, for a local test copy).
dest="${dest%/}"
case "$dest" in
  /*/redcatsuperkarts) ;;
  *) echo "Refusing to deploy to '$dest': expected an absolute path ending in /redcatsuperkarts" >&2; exit 1 ;;
esac

cd "$root"
for file in node_modules/esbuild/package.json node_modules/three/build/three.module.js \
            public/assets/manifest.json public/assets/menu/manifest.json public/assets/media/intro.mp4; do
  [ -f "$file" ] || { echo "Missing $file; run npm ci, see docs/hosting.md" >&2; exit 1; }
done

echo "== Building the website in dist/"
npm run --silent build
for file in index.html runtime-manifest.json src/main.js src/style.css assets/manifest.json; do
  [ -s "dist/$file" ] || { echo "Build incomplete: dist/$file is missing" >&2; exit 1; }
done
du -sh dist | cut -f1 | sed 's/^/   size: /'

if [ "$host" = local ]; then target="$dest/"; mkdir -p "$dest"
else target="$host:$dest/"; fi
echo "== Uploading to $target${dry:+ (dry run)}"
if [ -n "$dry" ]; then report=(--dry-run --itemize-changes --info=stats1)
else report=(--info=progress2,stats1); fi
# Every build stamps dist/ with new file times, so compare contents instead.
rsync -az --checksum --no-owner --no-group --delete-delay --delay-updates --chmod=D755,F644 "${report[@]}" dist/ "$target"

if [ -n "$dry" ] || [ -z "$url" ] || [ "$host" = local ]; then exit 0; fi
echo "== Checking $url"
# index.html is the same for every build; the runtime manifest and entry
# module change with the generated chunks.
failed=
for file in runtime-manifest.json src/main.js; do
  want=$(sha256sum < "dist/$file" | cut -d' ' -f1)
  live=$(curl -fsSL --max-time 30 -H 'Cache-Control: no-cache' "${url%/}/$file" | sha256sum | cut -d' ' -f1) || live=unreachable
  if [ "$live" = "$want" ]; then echo "   $file: live copy matches"
  else echo "   Warning: the live $file differs from the upload ($live)" >&2; failed=1; fi
done
[ -z "$failed" ] || { echo "   Check the Nginx location for /redcatsuperkarts/ and any proxy cache." >&2; exit 1; }
echo "   The live site serves the new build."
