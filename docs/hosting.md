# Host RedCat SuperKarts on a subdomain

The browser game is a static website. Build it locally, then serve the contents
of `dist/` at a dedicated address such as `https://karts.example.com/`.
Gameplay runs on the player's device; the host only serves files. It needs no
game server, database, Electron installation or running Node.js process.

Replace `karts.example.com`, `deploy` and the server paths below with your own
domain, upload account and hosting directory.

## Requirements

| Where | Needed |
| --- | --- |
| Build computer | Node.js 24, npm, this project's source and complete prepared `public/assets/` |
| Hosting | A static web host or VPS, control of the subdomain's DNS, HTTPS, and support for the files and response types below |
| Storage | Allow at least 1 GB per deployed copy; the current payload is approximately 420 MiB, with thousands of files and original video/audio |
| Player | A browser with WebGL 2, JavaScript modules/import maps, Web Audio and H.264/AAC video playback |

Check the host's file-count, individual-file-size and bandwidth limits as well
as its storage allowance; players also download original movies and audio.

A fresh Git checkout does not contain `public/assets/` or `node_modules/`.
Follow [Prepare and run](../README.md#prepare-and-run) to extract the original
assets, including the menu fonts and converted movies, or copy a complete
prepared `public/assets/` from your existing checkout. Python, Pillow, pefile,
ffmpeg and helpdeco are needed for asset preparation, not on the web host.

Use HTTPS for the public site, including controller support: the browser
Gamepad API is restricted to secure contexts. [Gamepad API requirements](https://developer.mozilla.org/en-US/docs/Web/API/Navigator/getGamepads)

## Build the website

From the project directory on the build computer:

```sh
npm ci
npm run build
```

Run `npm ci` when installing dependencies or when the lockfile changes. Run
`npm run build` when preparing a new deployment; it replaces `dist/` with the
current source and prepared assets. Existing desktop packages and an older
`dist/` do not automatically receive later source changes.

The output must keep this structure:

```text
dist/
  index.html
  src/
    main.js
    style.css
    ...
  assets/
    config.json
    manifest.json
    menu/
    media/
    ...
  node_modules/
    three/
      build/
        three.module.js
        three.core.js
      examples/jsm/controls/
        OrbitControls.js
        ...
```

Upload everything inside `dist/`, including its small `node_modules/three/`
tree. The build selects the required Three.js files; uploading the project's
entire development `node_modules/` is unnecessary. Preserve file names and
letter case, and keep files at their original URLs.

The game currently uses paths beginning with `/`, including `/src/main.js`,
`/assets/` and `/node_modules/three/`. Therefore `index.html` must be at the
subdomain's web root. Hosting it at `/dist/` or `/game/` requires code/path
changes; adding an HTML `<base>` tag alone does not fix those absolute paths.
The physical folder on the server may have any name.

## Connect the subdomain and upload

1. Create the subdomain/site in your hosting panel, or add a virtual host on
   your VPS. Give it a dedicated document root, such as
   `/srv/redcat-superkarts`.
2. Set its DNS `A` record to the server's public IPv4 address. Add an `AAAA`
   record only if that server also serves the site over IPv6. For managed
   static hosting, use the `CNAME` or other records specified by the provider.
3. Upload the **contents** of `dist/` into that document root using SFTP, the
   hosting panel, or rsync. For an existing writable upload directory:

   ```sh
   rsync -av dist/ deploy@your-server:/srv/redcat-superkarts/
   ```

   The slash after `dist/` copies its contents. The resulting file must be
   `/srv/redcat-superkarts/index.html`, not
   `/srv/redcat-superkarts/dist/index.html`.
4. Make the uploaded files readable by the web server and their parent
   directories traversable. On Linux, directories 755 and files 644 are usual
   choices for this public payload; the web server needs no write access.
5. Enable an HTTPS certificate covering the exact subdomain, and redirect HTTP
   to HTTPS. For direct VPS hosting, allow inbound TCP ports 80 and 443 through
   both the provider firewall and the server firewall.

With a hosting panel, enable its static-file hosting and SSL options, then
continue to the checks below. Choose one of the following examples if you
manage the web server yourself. The project’s `npm start` server listens only
on `127.0.0.1:4173` and is intended for local source development; public hosting
can serve the built files directly.

## Caddy example

Install Caddy using its [official installation instructions](https://caddyserver.com/docs/install).
On a Linux installation using its standard service, add this site to
`/etc/caddy/Caddyfile`:

```caddyfile
karts.example.com {
    root * /srv/redcat-superkarts
    encode zstd gzip
    header Cache-Control "no-cache"
    file_server
}
```

Validate the configuration, then reload an already running service:

```sh
sudo caddy validate --config /etc/caddy/Caddyfile --adapter caddyfile
sudo systemctl reload caddy
```

For a newly installed service that is not running yet, use
`sudo systemctl enable --now caddy` after validation. With working DNS and
reachable ports 80/443, Caddy obtains and renews the certificate and redirects
HTTP automatically. Its file server serves the site from the configured root. [HTTPS setup](https://caddyserver.com/docs/quick-starts/https), [file server](https://caddyserver.com/docs/caddyfile/directives/file_server), [service management](https://caddyserver.com/docs/running#using-the-service)

## Nginx example

For an Nginx server, first provision a certificate for the subdomain using your
hosting panel or certificate manager. This example assumes that certificate
already exists at the shown Let's Encrypt paths; adjust them to your setup.
Add these server blocks in the configuration included by Nginx's `http` block:

```nginx
server {
    listen 80;
    server_name karts.example.com;
    return 301 https://karts.example.com$request_uri;
}

server {
    listen 443 ssl;
    server_name karts.example.com;

    ssl_certificate /etc/letsencrypt/live/karts.example.com/fullchain.pem;
    ssl_certificate_key /etc/letsencrypt/live/karts.example.com/privkey.pem;

    root /srv/redcat-superkarts;
    index index.html;
    include /etc/nginx/mime.types;
    default_type application/octet-stream;
    add_header Cache-Control "no-cache" always;

    location / {
        try_files $uri $uri/ =404;
    }
}
```

If you publish an `AAAA` record, also configure the corresponding IPv6
listeners, such as `listen [::]:80;` and `listen [::]:443 ssl;`, in their
respective blocks. Check the configuration before reloading:

```sh
sudo nginx -t
sudo systemctl reload nginx
```

The MIME file supplies file types; `try_files` returns an actual 404 for missing
assets. No single-page-app fallback to `index.html` is needed: game screens use
the root URL and query parameters. [Nginx HTTPS configuration](https://nginx.org/en/docs/http/configuring_https_servers.html), [root, types and try_files](https://nginx.org/en/docs/http/ngx_http_core_module.html)

## File responses and caching

Check that the host or CDN preserves these responses:

| File | Expected response type |
| --- | --- |
| `.html` | `text/html` |
| `.js` | `text/javascript` or `application/javascript`, including the Three.js modules |
| `.css` | `text/css` |
| `.json` | `application/json` |
| `.mp4` | `video/mp4` |
| `.wav` | `audio/wav` or the host's equivalent WAV type |
| `.ttf` | `font/ttf` |
| `.bin` and `.dat` | `application/octet-stream` is suitable for the binary asset fetches |

JavaScript modules require a JavaScript MIME type; an HTML error page returned
with status 200 still fails to load as a module. [Module serving requirements](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules)

Images also need their normal image MIME types. Allow `GET` and `HEAD`, and
preserve byte-range requests for movies. A request for the first 32 bytes should
receive `206 Partial Content`, a matching `Content-Range`, and 32 bytes of data. [HTTP range requests](https://developer.mozilla.org/en-US/docs/Web/HTTP/Guides/Range_requests)

The examples use `Cache-Control: no-cache`: browsers may retain files but must
revalidate before reuse. This suits the current stable file names, which lack
content hashes. Avoid long-lived `immutable` caching for this deployment.
When using a CDN, apply the same policy and purge old content on updates. [Caddy response headers](https://caddyserver.com/docs/caddyfile/directives/header)

Preserve the prepared assets without host-side transcoding or image optimization.
Keep all assets on the same subdomain. The current build needs no cross-origin
asset setup. Disable hosting rules that exclude or block the shipped
`node_modules/three/` paths, and avoid automatic script rewriting/bundling that
changes the module/import-map loading order.

## Check the deployed game

Run these against your actual subdomain:

```sh
curl -I https://karts.example.com/
curl -I https://karts.example.com/src/main.js
curl -I https://karts.example.com/node_modules/three/build/three.module.js
curl -I https://karts.example.com/node_modules/three/build/three.core.js
curl -I https://karts.example.com/node_modules/three/examples/jsm/controls/OrbitControls.js
curl -I https://karts.example.com/assets/menu/manifest.json
curl -sS -D - -o /dev/null -H 'Range: bytes=0-31' https://karts.example.com/assets/media/intro.mp4
curl -I https://karts.example.com/assets/this-file-does-not-exist.json
```

The first six requests should return 200 with the correct types. The range
request should return 206 and `Content-Length: 32`. The deliberately missing
file should return 404, not 200 with HTML.

Open the site in a browser, allow playback with **Start** if prompted, then
check the original menu, a QuickRace, music/effects and a page reload. Developer
tools should show no missing assets or module MIME errors. `/?skipIntro` opens
the menu directly when diagnosing startup.

| Symptom | Check |
| --- | --- |
| Empty or blue screen | Missing/blocked Three.js files, a wrong document root, JavaScript served as HTML, or a host Content Security Policy blocking the inline import map in `index.html` |
| Movies fail or cannot seek | MP4 MIME type, byte-range responses and proxy/CDN handling |
| Missing artwork, fonts or sound | Incomplete `assets/` upload, changed letter case, or wrong MIME types |
| HTTP visitors lack controller support | Use the HTTPS URL and redirect HTTP to it |
| Old behavior after deployment | Rebuild from current source, upload the whole output, purge CDN caches, then reload |
| 403 despite files being present | Directory/file permissions and, on an SELinux host, the web server's permitted file labels |

## Updates and saved games

For each deployment, build the intended source revision and upload its complete
output. For updates to a live site, upload to a separate release directory,
then switch the document root or release symlink to it as one operation. Keep
the previous directory for rollback; avoid mixing old modules with new assets
while players are loading. Ask active players to reload after switching.

Settings, records and adventure saves live in each browser's local storage.
They are not stored on the web server or synchronized between devices. Updating
files on the same HTTPS origin preserves them. Changing the hostname, protocol,
port or browser profile uses a different storage area; local development and
the Electron application therefore have separate saves from the public site. [Browser storage behavior](https://developer.mozilla.org/en-US/docs/Web/API/Window/localStorage)

These commands are deployment instructions. Actual DNS, certificate issuance
and public-server responses must be checked on the host you choose.
