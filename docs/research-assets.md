# Original asset research and reproducible conversion

[Documentation index](README.md) · [Inventory](#inventory) ·
[Mesh format](#confirmed-mesh-format) · [World formats](#confirmed-world-formats) ·
[Images and media](#images-fonts-sound-and-movies) ·
[Validation](#verification-status) · [Help](#original-winhelp) ·
[HUD atlas](#original-hud-atlas)

The original installation and unpacked ISO are opened read-only. `python tools/prepare-assets.py` extracts assets into `raw/extracted/` and creates browser files in `public/assets/`. It requires Python 3, Pillow and FFmpeg. `--installation PATH`, `--cd PATH`, `--skip-media` and `--media-only` are supported. The defaults are the paths supplied for this project. `python tools/validate-assets.py` verifies extraction digests, geometry records, image dimensions, sound files and decoded movie frame counts.

## Compatibility decision

SuperKarts does **not** contain the GBSP v15 worlds and Genesis3D `.act` archives used by the Spookkasteel reference. Its installed content uses custom `.d3d` meshes and `.rmp`, `.pmp`, `.omp`, `.cmp`, `.dmp`, `.pth` maps. Native executable source-path strings name `D:\work\libs\DX3D\Mesh.cpp`, `Win3DLib`, and `D:\work\rcsk\Code\Engine\Prog\Rd_*.cpp`. No Spook physics, entity scripts, world parser or actor loader was reused.

The one directly compatible subsystem is the **named IMG index layout**. The defensive validation pattern in `tools/lib/superkarts_formats.py::archive_entries` adapts the read-only reference `RCSPOOK_NEW/tools/extract_menu.py::archive_entries`: little-endian 16-bit count followed by 20-byte NUL-terminated name and 32-bit absolute IMG offset. The complete index length and monotonic offsets are checked. SuperKarts permits duplicate names and unnamed resources; all records are preserved with distinct output filenames. Its separate `rc.ind` uses a different, unnamed index of 16-bit count plus 32-bit offsets; this was added independently.

## Inventory

| Source | Observed content | Converted representation |
|---|---:|---|
| `rcs.ind` / `rcs.img` | 5,291 records | Every byte extracted and SHA-256 recorded |
| D3D meshes | 3,495 records, including frame animations | 3,495 geometry JSON files; 3,493 original-name lookups because `handle.d3d` occurs three times |
| TGA / PCX / PCL pictures | 256 / 487 / 74 records | 817 PNG files, 807 unique original-name lookups; PCL files have PCX signatures |
| WAV sounds | 812 records | Original WAV bytes, 810 unique original-name lookups |
| Bitmap fonts | 37 records | Original metrics, glyphs and palette-based PNG atlases |
| Nameless RCS records | 126 | Raw bytes retained, identity unresolved |
| Other RCS records | 3 `.3ds`, 1 `.txt` | Raw bytes retained |
| `rc.ind` / `rc.img` | 207 indexed sprites | Exact source indices exported to grayscale-channel PNG, dimensions and hotspots; palette unresolved |
| `data/gfx` | 251 images | Original-size menu PNGs |
| `rclemu00.dat` … `rclemu05.dat` | Six MPEG Layer III streams | Bit-identical `.mp3` files |
| ISO `Media/movies` | Intro, four character wins, six star awards | Eleven H.264/AAC MP4 videos |

Names are taken from `track.ini [MAPS]`:

| Track | Sectors | Render quads | Placed objects |
|---|---:|---:|---:|
| Nederland | 178 | 4,506 | 348 |
| Duitsland | 187 | 5,544 | 267 |
| Engeland | 178 | 4,636 | 327 |
| Frankrijk | 187 | 5,377 | 254 |
| Spanje | 181 | 5,427 | 219 |
| Italie | 181 | 5,198 | 204 |

The generated inventory is `docs/evidence/asset-inventory.json`. The complete archive provenance, offsets, sizes and SHA-256 digests are in `public/assets/manifest.json`. Do not infer that every archived legacy asset is used by the shipped game. In particular, unused old racer models coexist with the current animated character frames.

## Confirmed mesh format

`rcskspel.dat` native reader **`FUN_004a9ad0` (0x004a9ad0)** confirms both layouts, all file-read sizes, direct UV copies and the three 16-bit face indices. Its source-path diagnostic identifies `Mesh.cpp`.

* Modern layout: `int32(-1), uint32 vertexCount, uint32 faceCount`, then 49-byte vertices: twelve floats `(x,y,z,nx,ny,nz,u,v,r,g,b,a)` and one byte; then 9-byte faces: three unsigned 16-bit indices and three ignored bytes.
* Legacy layout: `uint32 vertexCount, uint32 faceCount`, then 33-byte vertices: eight floats `(x,y,z,nx,ny,nz,u,v)` and one byte, followed by the same faces. The native lit-vertex path supplies white diffuse color for this version.
* The final vertex byte and final three face bytes are retained as unknown metadata. They are not interpreted as gameplay flags.
* Three shipped meshes (`koei`, `stoneh01`, `struik00`) contain non-finite sentinel coordinates in **unreferenced** vertices. Every face reference was checked. Only those unreferenced records are omitted, indices are remapped, and their original vertex IDs are recorded in `omittedInvalidUnusedVertices`. No visible triangle is removed.

Browser mesh JSON has `position`, `normal`, `uv`, `color`, `alpha`, `index`, `vertexCount`, `triangleCount`, source digest/index, original-version metadata and unknown bytes. Coordinates, float precision and UVs are retained without coordinate conversion. The renderer must implement native handedness and UV orientation; decoding alone is not visual parity.

## Confirmed world formats

**RMP:** Header `int32(-1), uint32 headerCount, uint32 sectorCount`. For each sector, four groups are stored in order: **road, land, extra, rail**, confirmed by **`FUN_00494d20` (0x00494d20)** and its diagnostics. Each group starts with quad count; each quad contains four `(x,y,z,u,v,uint32 RGB)` vertices and six 32-bit indices. Native **`FUN_0049cc90` (0x0049cc90)** reads exactly these fields and swaps packed color bytes into D3D format. The exported colors therefore interpret the file's low byte as red, middle byte as green, upper byte as blue. `headerCount` is preserved without assuming its meaning. Every one of the six files is consumed exactly to EOF. `track.ini` supplies the runtime texture order; the map-editor INI uses a different order and is retained separately.

**PMP:** Sector count; each sector has XYZ, a trigger identifier, another 32-bit field, a counted collision-index list, a counted left-waypoint list, and a counted right-waypoint list. Native **`FUN_004949c0` (0x004949c0)** confirms the three variable-length lists; left-waypoint lists are empty in these six shipped tracks. The export calls the right-waypoint list `driveIndices` for renderer compatibility, with `driveLeftIndices` stored separately. All collision and waypoint references are bounds checked by validation.

**OMP:** Object count; each 68-byte record has sector, type, position XYZ, rotation XYZ, a 32-byte NUL-terminated animation identifier and a trailing 32-bit value. Confirmed by **`FUN_00497070` (0x00497070)**. Native creation **`FUN_0043e140` (0x0043e140)** multiplies angles by trig-table-size/360 and **negates the Y rotation** before constructing the object, establishing degrees and native yaw sign. Export keeps raw `rotation`, plus `nativeRotationDegrees=[x,-y,z]`, and the trailing `value`. Runtime billboard orientation, animated objects and per-type transforms still require their native behavior.

**CMP:** Count plus six floats per record. Export retains `position` and `delta`; bounds and exact sizes are checked. The geometric interpretation as a line origin plus displacement must be combined with the native collision implementation before claiming collision parity.

**DMP:** Count plus 36-byte records: two unsigned integers, XYZ and four signed links. All values are retained, with currently unresolved fields marked `unknown`.

**PTH:** Native **`FUN_00444bd0` (0x00444bd0)** reads marker -1, path count, then six signed integers per path and a counted list of 16-byte points. Export has `startSector`, `endSector`, `type`, `unknown`, `durationMs` and `points=[{flag,position:[x,y,z]}]`. All 41 paths across six tracks are consumed exactly to EOF. Original `pathTypes` and `pathObjects` lookup tables accompany them. The dynamic controller is recovered below; the six built-in startup camera paths are implemented and separately documented in [camera research](research-camera-speed.md#opening-camera-and-initial-clock). The exported `unknown` integer is the native lap filter (zero or current completed-lap count plus one).

Each `tracks/etappeN.json` contains complete road buffers, group ranges, texture references, route sectors, static placements, collision and driving data, and the original INI object definitions. Definition lookups use lower-case animation identifiers. No procedural replacement track geometry is generated.

## Images, fonts, sound and movies

TGA/PCX images are decoded at original size. Exact filename extensions are retained in output names (`textures/ned01.tga.png` versus `textures/ned01.pcx.png`) so low/high-color variants cannot overwrite each other. Duplicate archive records receive `__2`, `__3` suffixes. Convenience `<stem>.png` aliases prefer TGA; consumers should use manifest references.

Menu source Delphi resources confirm `clFuchsia` transparency for `TDaviImage` sprites with `Transparent=true`. Other controls specify `Transparent=false` and use `RegionLink` masks. Menu PNG conversion keys exact RGB `(255,0,255)`; this does **not** substitute for native control region masks. Per-control transparency and hit regions must come from the parsed Delphi resources.

The game uses a different key: **`FUN_0042ccf0`** calls `FUN_004afdb0(0x7f00ff)`; **`FUN_004b5470`** reads its low byte as red, establishing **RGB `(255,0,127)`**. The indexed branch defaults to palette index 254 and passes its converted value to SetColorKey in **`FUN_004a4a30`**. Texture PNGs therefore key exact `(255,0,127)`. Original files remain unchanged; source and keyed-pixel counts are recorded. `SndGfx.ini` gamma=0 leaves channels unmodified; nonzero gamma enables the native channel-square/256 conversion and is not silently enabled by asset preparation.

All 37 font files have a 256-entry table of `(uint16 width, uint16 height, uint32 offset)`, eight additional bytes, and indexed glyph pixels. Every glyph range fits its source file. Atlases use `e02_pl16.pcx`, explicitly selected by `SndGfx.ini [PALET]` for 16-bit rendering, and preserve original glyph metrics. Index 255 is made transparent based on the blank backgrounds; exact per-font runtime recoloring remains unverified. The four trailing header words are retained. These extracted font files are distinct from the active race HUD's `Overlay.ini` glyph rectangles described below; this extraction limit is not evidence of a missing active HUD font.

The Delphi menu uses Comic Sans MS. `--font-dir` copies installed `comic.ttf`, `comicbd.ttf`, `comici.ttf` and `comicz.ttf` with source paths and SHA-256 provenance in `fonts/menu-fonts.json`; these are distinct from the game's bitmap fonts.

Movie conversion preserves 320×240, 4:3, and decoded 25-fps content with original audio. Source MPEG `r_frame_rate` can misleadingly report 50; the measured `avg_frame_rate` and decoded frame count establish the 25-fps sequence. The intro has 2,652 decoded frames (106.08 seconds of video). FFmpeg reports damaged-tail concealment warnings in some original win/intro MPEG streams. Generated MP4s contain every decoded original frame; source and output frame counts are checked exactly. Container durations can differ because the source MPEG duration estimate and AAC packet boundaries differ. This is recorded per movie, not hidden by clipping content. Video encoding is high-quality lossy H.264 CRF18; AAC audio is 160 kbps. No resizing, speed filters or content edits are applied.

Browser presentation is a separate step from conversion. The shared movie
element now uses `object-fit: contain` and centered positioning inside a black,
viewport-bounded container in `source/style.css`. The intro and all reward movies
therefore retain their original 4:3 image with borders where needed, without
stretching or cropping. This source correction does not reconvert the movies
or establish that an existing package or published release contains the fix.

## Animation, sky, kart and audio bindings

`source/asset-animation.js` exposes original assets without introducing substitute artwork. `getSceneryAnimation` decodes every listed `AnimobjN.ini` prefix, inclusive first/last frame, FPS and loop value, using native **`0044e460`**. Mesh-clock **`0044e850`** advances once only when elapsed unsigned milliseconds strictly exceed `trunc(trunc(speedPercent*1000/fps)/100)`. It discards excess elapsed time. Loop -2 reverses before displaying the terminal frame; this native quirk is retained. `eNN_anim.ini` records describe overlay mesh/texture lists, not frame rates; `getOverlayAssets` keeps these separate.

Placement type 3 exists only in mode 1 and type 4 only in mode 2, confirmed by **`0043e140`**. Other types may have additional controller visibility, so `placementExistsInMode` does not claim to replace their controllers. `RotObj.ini` values are **not rotation periods**: `0043e140` stores value*0.001, and **`0043f490`** adds this increment times `60*(dt+0.01)` each update. Active game initialization **`00442fc0 → 004ac410 → 004a1510(4096)`** overrides the PE's initial 1024-entry table: a full turn is **4096 units**. The callback subtracts 4096 once when above 4096. Random phase is native `rand()%2000` only when StartRandom equals exactly 1; the shipped value 100 does not enable randomization.

Sky **`0042d480`** selects `SndGfx.ini [SKY] mesh<track>` and `<mode><track>` texture. **`00422d50`** applies scale `[10,4,10]`; **`00423010`** resets orientation to identity and copies active racer's XYZ every frame. `getSkySpec` exposes all 24 texture choices and the three original mesh choices.

`cars.json` exports all 13 `Car_SSR.ini` records and exact wheel-mesh minimum-Y radii. **`0041bb30`** reads `Race.INI [PLAYER] car`, ignoring its contestant-type argument; **`0041bdd0`** creates children in negative-X front, positive-X front, negative-X rear, positive-X rear order. Cars 0–8 use original indy positions `[±21,3.7,18]` and `[±12,-10,-21]`; the rear Y=-10 is preserved. Old `CAR_CFG.INI wheel_positions` are not the selected runtime data. Model replacements are traced through **`0042df90`** and **`00475110/20/30/40`**.

`getTrackMusic` resolves the six bit-identical MP3 streams. Native **`0042d7d0`** selects `rclemu%02d.dat` by track ID, independent of the legacy `SndGfx.ini [MUSIC]` list. `getSoundSpec` resolves named `Sound.ini [SNDTYPES]` events and retains their raw fields; `getMenuSample` resolves generic and per-character sample indices through `ini/soundset.dat` and the four original sound banks. Menu background music has not been established by the native evidence and is not substituted with race music.

`tools/native-animation-fixtures.py` runs isolated original x86 instructions through Unicorn with controlled GetTickCount and delta values. Only emulator memory is changed. `tests/asset-animation.test.mjs` matches 14 mesh-clock traces and 72 rotation cases, checks every listed scenery mesh and all 24 sky variants. This validates the clock/rotation updates independently of the JavaScript implementation, not whole-game timing. The original Animobj texture entries `FOREST01` (unused WEST0000) and `FRAN040` (KONK0000/KONH0000, placed in France) do not resolve. Placed France objects correctly bind `fran04.tga` in their map definitions; changing mesh frames should preserve that existing material.

## Verification status

`docs/evidence/asset-validation.json` is the current machine-readable authority for extraction and conversion checks. Success establishes byte-exact archive extraction, complete supported-file parsing, legal mesh references, correct generated image dimensions, readable source WAVs and matching movie frame sequences/cadence. It does **not** establish original rendering, lighting, controller integration, audio triggering, race logic or whole-game completion. The later sections record separate native-controller and browser evidence; `evidence/audio/coverage.json` records current sound dispatch coverage and its limits.

## Original WinHelp

`tools/prepare-help.py` decompiles the supplied `data/RCSK.HLP` read-only using [helpdeco](https://github.com/pmachapman/helpdeco), tested at commit `785273788af17fde4fba7df7162d547f8645d7d8`. Build it with `make -C work/helpdeco/gcc` after checking out that source revision, or supply another installed executable using `--helpdeco PATH`. The default is `work/helpdeco/gcc/helpdeco`, followed by a PATH lookup. `--source`, `--raw` and `--output` override input and output locations. `tools/prepare.mjs` includes this step. Missing helpdeco or failed/fresh-output-incomplete extraction produces an explicit error; old generated output is not accepted as a successful rebuild.

Helpdeco runs in a fresh temporary directory, then the original RTF, HPJ, bitmap and baggage files are preserved in `raw/help/`. The converter parses balanced RTF groups, CP1252 accents, bold/italic/underline runs, font sizes, colors, bullet paragraphs and table rows/cells. Metadata footnotes become the original titles, context IDs and keywords, not visible page text. Hidden WinHelp destinations become internal links; macros or external commands are not executed. Unsupported visible controls or unresolved links/images fail the conversion. All output text is HTML-escaped; image URLs and link attributes use generated local paths and validated context identifiers.

The browser entry point is `/assets/help/topics.json`, schema 2:

* `title`, `startTopic`, `presentation` (original Arial font and HPJ main-window RGB background).
* `topics`: original `id`, `title`, numeric `contextId`, `keywords`, safe `html`, plain `text`, image references and recovered links.
* `contextMap`: verified numeric help-context string to topic ID.
* `keywordIndex`: original keyword B-tree destinations; `windows` retains original window metadata.
* `navigation`: original browse/popup/window/hotspot coverage. Topic records retain original hashes and browse pointers.
* `images`: original bitmap name to PNG path, dimensions, source digest and decoded-pixel digest.
* `baggage`, source/tool digests, converter warnings and explicit limitations.

Internal links use `data-help-topic="<context>"` and `href="#help-<context>"`; the application can intercept them to select the matching topic. The HTML contains the original page header pictures, 27 bullet items and two tables (eight rows, 21 cells). All 46 distinct BMPs are converted pixel-exact to RGB PNG, with 59 image placements. No authored replacement instructions are added. The unreferenced `MN_HSP01.WAV` baggage is preserved without inventing its activation.

`docs/evidence/help-validation.json` records 13 topics, nine resolved links and
all image/table references. The [navigation follow-up](research-help-navigation.md)
checks context numbers, link hashes and keyword mappings directly against
`RCSK.HLP`. It corrects helpdeco's LP64 keyword corruption and establishes that
all original browse pointers are absent; the 14 browse warnings are extractor
errors, not an unrecovered topic sequence. No authored popup or secondary-window
link exists. The viewer now supplies Contents, Back, Index and History while
preserving the caller form and unsaved drafts. The original Windows window
layout and non-scrolling header presentation remain browser adaptations.

`docs/evidence/help-browser-validation.json` retains the initial conversion
checkpoint. Current focused navigation checks are in
`evidence/help-navigation/browser.json`; both cover all 13 topics, 59 image
placements and nine links, with zero broken images or page errors.

The three original `Phys0.dat`, `Phys1.dat`, `Phys2.dat` tables are additionally copied byte-for-byte into `public/assets/physics/phys0.dat` through `phys2.dat`, with digests in `manifest.physics`. No inferred physics constants are inserted into these source files.

## Loose menu audio and native regions

The RCS archive is not the complete sound library. `prepare_loose_audio` also inventories the installation and CD recursively, preserving exact source spelling, relative path, length and SHA-256 while creating lowercase browser lookups. The supplied CD adds **410 loose sound files**, principally `data/shellsnd` and `Media/sounds`. The complete output has **1,220 unique WAV files and six MP3 streams**. `audio/menu-sources.json` checks 403 menu-config references: 398 resolve; five refer to files absent from both supplied sources (`mn_in10.wav`, `mn_in11.wav`, `mn_s006.wav`, `mn_s007.wav`, `mn_s008.wav`). They remain explicit missing-source records rather than substitutes.

Native menu **`0045348c → 00453170`** builds a window region from the `RegionLink` bitmap, excluding RGB black. **`0045312c`** unions its horizontal runs; **`0045e1c8`** passes the region to `SetWindowRgn`. `tools/prepare-menu-regions.py` reproduces the ten distinct shipped masks as merged rectangles and records source hashes in `ui/regions.json` and each menu manifest entry's `region`. `source/menu-regions.js` applies those exact rectangles through SVG clipping, affecting painting and pointer hit testing. Original control dimensions are supplied separately from mask dimensions because several differ. Chromium checked **53,108 pixel centers** against the decoded source masks, including **40,434 active pixels**; `docs/evidence/menu-region-validation.json` records the results.

Track music **`0042d7d0`** loads `rclemu%02d.dat`, starts it only when the selected volume is nonzero, and enables looping with **`0048ec20(1)`**. **`0048ef80`** restarts completed playback; **`0042a810`** stops/resets it when leaving. Native **`00431610`** converts a percentage to DirectShow attenuation `trunc(percent*4900/100)-5000`, rather than linear amplitude.

## Player geometry and animation admission

`source/player-assets.js` resolves the four original characters from `Game.ini`, their independently selected car/color from `Car_SSR.ini`, and all **26 animation sequences per character** from `CharAnim.ini`. Native **`004765d0`** constructs a `.pcx` texture name, but accelerated loader **`004a3c50`** strips the extension and selects the `.tga` variant. Every default contestant uses `kart03.d3d` with `indyred.tga`; front and rear wheel meshes are `wiela.d3d` and `wielv.d3d`, both with `wieltest.tga`. Driver textures are `char_rc.tga`, `char_wz.tga`, `brutus09.tga`, `max06.tga`. Driver child four has zero local offset and rotation; no inferred kart scaling is applied.

`getPlayerVisualSpec` returns body mesh/texture/bounds/horizontalRadius, four wheel specs with original offsets and minimum-Y radii, and driver texture/sequences. Native **`004aa040 → 004aa0c0`** measures unscaled source vertices; `manifest.meshes` includes the six bounding limits and horizontal corner radius. `kart03` radius is `37.95783996582031`; `pootje1` through `pootje5` are `15.296518325805664`; `ster` is `25.305728912353516`. `tools/native-player-asset-fixtures.py` verifies 13 actual meshes, including a shipped `flle0008` frame containing extreme finite coordinates. That frame is preserved, not silently repaired. Its radius calculation requires x87's extended exponent even at 24-bit precision.

Native **`0044ce90`** accepts a character transition only when its expected state matches and the queue is empty. Acceptance changes state immediately. Sequence reset **`0044eb90`** clears frame/loop count but retains the sequence timer and ping-pong direction. **`0044cac0`** assigns a displayed mesh only after **`0044f110`** removes completed sequences; an emptied queue therefore leaves the last displayed frame intact. The module translates normal active-race steering/braking/reverse/turbo requests from **`004325b0`**, and 147 independent instruction fixtures verify admission. Damage, finish and quiz callbacks remain distinct systems.

`docs/evidence/bonus-placement-assets.json` preserves all 180 OMP pickup placements and the native **`00451f80`** type mapping. England contains two oil pickups whose source appearance is `pootje5_ANIM`; behavior is derived from the OMP type, not from the picture. Pickup collision **`0044fc80`** reads current render position and current mesh radius; **`004500e0`** can change that mesh when a bonus level changes.

## Original HUD atlas

`source/hud-text.js` uses `Overlay.INI`'s `overlay1.tga` rectangles, rather than a replacement browser font. The 45-entry native table at **`004d2a00`** maps `DIV` to colon; slash is the original ASCII-47 override. **`0045b140`** aliases unassigned lowercase letters to uppercase. Both fonts retain `DISTANCE=-2`.

Factory **`00461b50`** gives fixed strings a default right alignment and proportional strings a default left alignment. **`0045a030`** truncates and pads fixed strings; **`0045a6b0`** positions their fixed cells. **`004631d0/004632c0/00463400`** implement proportional left/center/right placement. **`0045ed60`** constructs centered glyph quads, so configured Y is a center, not a top edge. The lap numeral and `/5` share X=600 but use right and left alignment respectively.

`getHudStringSpec(config,id)` resolves original parent position/scale and font; `layoutHudText(spec,text)` returns source atlas and destination rectangles in 640×480 coordinates. `getRaceHudText` binds caller-supplied native timing/lap state. **`0046f5f0/0046f700`** format signed milliseconds as `%02d:%02d:%02d` (minutes, seconds, centiseconds), while **`0046f770`** uses total seconds and centiseconds (`%d:%02d`) for countdown. The best-time sentinel displays the original `--:--:--`. The caller retains ownership of the three-second completed-lap hold. **306 layout cases and 19 signed time cases** match independent original-instruction execution exactly (`evidence/native/hud-text-fixtures.json`).

## Native mesh transparency

Transparency is selected by the placed object's controller, not by inspecting its mesh alpha. **`0043e140`** assigns OMP type 9 to render mode 1, and type 10 to mode 2. **`00490d40`** queues nonzero modes. **`0048f600`** reads blend factors from **`004fa400`**: mode 1 uses `SRCALPHA/INVSRCALPHA`; mode 2 uses `ONE/INVSRCCOLOR`; mode 3 uses ordinary alpha while retaining depth writes. Modes 1 and 2 disable depth writes and retain the queue's insertion order. **`004a0d80`** enables blending exactly when the object's mode is nonzero. Each object is submitted once.

`source/asset-materials.js` exports `getNativeMaterialSpec`, `nativeVertexRGBA`, `nativeColorAttribute` and `createNativeMeshMaterial`. The geometry attribute packs source floats with the original `trunc(channel*255)` conversion, including alpha. The source files contain **13 meshes with non-unit alpha**; the tracks contain **58 ordinary-alpha and 41 screen-blended placements**. Eleven distinct source colors, four blend modes and eight enable transitions are checked by executing the original instructions in `tools/native-material-fixtures.py`.

The accelerated game selects `D3DTBLEND_MODULATE`: RGB texture color multiplies vertex color, and RGB textures retain vertex alpha. The helper keeps the converted color-key mask separate from vertex alpha so a half-transparent lamp is not discarded by a combined alpha test. The earlier material checkpoint used a `.5` filtered-mask cutoff and provisional double-sided drawing; those are superseded. Current mesh materials default to `THREE.FrontSide`, and the [native precision follow-up](research-native-texture-precision.md) implements original RGB565 packing, protected non-key black, zero-coverage key rejection and a real RGB565 scene target. `forceSinglePass` remains a guard against Three.js applying transparent double-sided blending twice when a caller requests that mode. The [HUD framebuffer follow-up](research-hud-framebuffer.md) also draws original glyphs and overlay meshes into RGB565; exact historical GPU rasterization remains a comparison limit.

The large Netherlands starting gate is original `strt0000..strt0038` geometry at OMP position `[-2346.18310546875,124,7097.0390625]`, type 12. Its initial local bounding size is approximately 538×238×135 units. The inspected creation chain **`0043e140 → 0048fb60 → 00490130 → 004a02b0`** stores original positions/angles without a special gate scale; no visual size correction is invented. Physics-enabled type-5 scenery registers a ground callback through **`0043f1b0 → 004939d0`**, which a static scenery viewer does not reproduce.

## Byte-color rendering and HUD mesh coordinates

`applyNativeByteColorPipeline` keeps source texture and vertex RGB in their stored byte space: the original Direct3D 3 device's `D3DTBLEND_MODULATE` multiplies these values directly. Three.js's automatic sRGB decode/output conversion would instead produce approximately 93 for texture 128 multiplied by vertex 128, where the native byte operation gives 64. The helper marks textures `NoColorSpace`, disables tone mapping and omits the output color-space shader chunk. This is specific to the recovered legacy renderer; it is not a general recommendation for modern material rendering. Microsoft's [gamma documentation](https://learn.microsoft.com/en-us/windows/win32/direct3d9/gamma) identifies sRGB read/write conversion as explicit Direct3D 9 states, disabled by default; the recovered earlier device path does not enable such a conversion.

`tools/validate-native-materials.mjs` reads actual WebGL2 pixels for 32 combinations of four original blend modes and eight vertex intensities, against byte-space reference equations. The retained material checkpoint matched all channels within one byte (`evidence/native/material-webgl-pixels.json`). Those historical results establish the byte-space modulation/blend stage, not validation of later source changes. The [native precision follow-up](research-native-texture-precision.md) records the subsequent texture packing, filtered-key and per-draw RGB565 framebuffer checks separately. Neither checkpoint establishes the exact rasterization or display gamma ramp of an original graphics device.

`source/hud-mesh.js` translates **`00458a00/004589c0/00459440/00459910/00462770`** and the INI factories. HUD meshes use their own 90-degree horizontal camera, near plane 0.99 and disabled depth testing. The native viewport uses width/2 for both projected axes; at 640×480 an element's original pixel scale is approximately 0.00309375 native units. Composite parents carry separate child-position and model-scale factors. Consequently the three countdown X centers are 241.25, 320 and 398.75, rather than the raw INI values 215, 320 and 425. Normalized countdown Y=0.4 projects to pixel 144.

`getHudMeshSpec` resolves original minimaps, bonus frame and caller-selected countdown animation/frame. It returns source mesh/texture, normalized native transform, visibility, tint and material mode. The original draw routine overwrites all vertex RGBA with the element tint; multiplying source mesh colors would be incorrect. `tools/native-hud-transform-fixtures.py` executes 72 cases at both x87 precisions, including parent positions/scales and RGBA replacement. Three focused tests cover those fixtures, six minimaps and nine countdown instances. String hierarchy is separately recovered below; text uses a distinct native transform.

## NPC appearance, racer tables and portrait menus

`manifest.racerTables` exposes byte-exact `cars0.dat` through `cars3.dat`, each containing 20 records of 124 bytes, with source path and SHA-256. Runtime difficulty selects tables 0, 1 or 2. Table 3 is preserved as an additional source artifact; no runtime use is asserted.

NPC normal animation **`0040b0b0`** differs from the player callback. NPC steering handlers **`0040c0c0/0040c370`** request `IDLE_LEFT/LEFT` or `IDLE_RIGHT/RIGHT`; the latter has an inclusive -999..999 return-to-idle band. They use the controller's signed target argument, not the player's lateral-speed threshold or `STEER_*` clips. **`0040e760`** uses the seconds clock and a strict five-second turbo bound. Normal ordering is FSM events, turbo, finish cheer, then turbo/right/left/idle settling requests.

`getNPCDrivingAnimationRequests`, `getNPCAnimationEventRequests` and `getNPCTurboAnimationRequests` preserve this distinction. Four original damage handlers submit unconditional `HIT`; **`0040de60`** (successful attack) and **`0040d610`** (pickup) similarly queue `CHEER` unless FSM state is 9. Native **`0044f390`** appends the clip and resets the existing queue head's frame/loop count, leaving the animator state unchanged. `requestDriverAnimation` accepts `{enqueue:true}` for this exact entrypoint. Eighty-three isolated original-instruction request cases and twelve native queue-append cases verify these behaviors; NPC target/event production remains the simulation controller's responsibility. Normal NPC steering does not call the older state-23 lean handlers, and firing an owned turbo does not submit the track-boost animation callback.

`source/native-portrait.js` reflows the existing original menu nodes for the main menu, character/country selection, country information, race results, options, controls, requesters, name entry, adventure and highscores. It reuses the original text, Comic Sans font, art, masks and event listeners; it introduces no replacement pictures. Twenty-six browser layouts cover 320- and 390-pixel portrait widths, button dimensions and horizontal overflow, plus original landscape coordinates before and after rotation. Main-menu card buttons, carousel arrows, radio choices, photo actions and result buttons retain their original callbacks. Screenshots and machine-readable results are under `evidence/portrait/`.

## Native racer recovery effect

The **`0048dc30/0048c9a0`** family comes from `Spawn.cpp`. It is a disappearance/reappearance effect, not a crane model. `source/simulation/native-rescue.js` retains the ten-object queue, duplicate exclusion, immediate clearing of three local linear velocities, and the NPC recovery-block flag. Angular velocities are not cleared. **`0048ca60`** advances once per outer game tick: twenty shrink-table entries, then twenty grow-table entries. These include the original initial overshoot values 1.2, 1.4, 1.2. Tick 21 relocates; tick 40 sets local forward velocity to 5 and marks completion. Retirement and clearing the recovery-block flag follow rendering, matching **`0048db30`**.

Normal recovery chooses the first original driving lane, tests six links ahead down to zero, retains the native last-candidate fallback, and uses the planar squared-distance exclusion threshold 2000. Native **`00450500`** selects the nearest sector by summed truncated-coordinate absolute differences. The yaw is set from that sector; **`00430ff0 → 004932e0`** then updates previous/current sector before sampling ground height. Relocation does not itself replace waypoint membership, reset suspension state or rebuild the current rendering matrix. Accordingly the renderer receives the pre-relocation translation for that tick and the original scale applied to its current matrix. The next ordinary object update rebuilds it.

The effect uses original `s_sfx.tga`, twenty strips of seven vertices and deterministic original vertex colors. **`0048c370`** constructs its seven source vertices, **`0048c7e0`** supplies UVs/colors, **`0048d610`** generates positions and **`0048d460`** draws `D3DPT_TRIANGLESTRIP` with `ONE/ONE` additive blending. `getNativeRescueVisualSpec` returns the recovered indices, UVs, colors and texture; `nativeRescueRingPositions` returns current world positions. Source geometry includes a degenerate connector and reversed-facing copy, which must not be inadvertently blended twice with an extra two-sided rendering pass.

`tools/native-rescue-fixtures.py` executes 80 update cases, 48 complete ring generations (6,720 vertices), 360 destination-node/nearest-sector selections across all six tracks, ten clearance cases and twelve heading cases at 24/53-bit precision. Tests compare these independently captured results exactly. This covers the normal NPC recovery branch. The separate special-marker respawn entrypoint **`0048dce0(flag=1)`** remains distinct; no crane, invented teleport destination or guessed animation duration is substituted.

## Native HUD portrait controller

`source/hud-portraits.js` translates **`00469990/00469b10/0046b2a0/0046b5e0`**, retaining original CHARDATA racer order and zero-based ranking. Known character names select their original back/frame/face nodes; other racers select `Cou`, whose `ovlchar` animation is supplied by each country's own animation file. The player gets the original scale multipliers `[1.25,1.25,.001]`; the getter at **`00459980`** returns authored, unscaled coordinates, so these yield `[.5,.5,.001]` for the shipped portrait definitions.

Ranks above and below the player occupy `.32` normalized spacing, while the player occupies `.4`. Ordinal meshes move immediately to their source anchors, including native `.15/.19` offsets. Portraits begin in finished state at `[0,1,0]`. A changed rank starts a 400 ms half-circle through **`00467000/004676d0`**; a later spacing correction starts a 100 ms straight interpolation, then restores the 400 ms curve mode. The controller waits for the preceding movement to finish before accepting another rank change. Its first movement update occurs on the tick after the request.

`createNativeHudPortraits` creates the state; call `updateNativeHudPortraits(state, deltaSeconds, ranks)` at native update rate, including the initial rank update, then pass each `getNativeHudPortraitCommands(state, config)` entry to `getHudMeshSpec`. Commands preserve the original numbered element order and Overlay.ini colors, including background alpha 64. No replacement portraits or text ordinals are introduced.

`tools/native-hud-portrait-fixtures.py` captures 112 interpolation samples, 96 movement boundary cases and 600 complete rank-manager updates across all five player slots at both x87 precisions. The corresponding tests compare scalar state exactly and positions within `1e-6` normalized units; all six country portraits also resolve to extracted meshes/textures. Assertions, clock, racer records and string allocation are controlled emulator services, so this is instruction-level validation rather than an original-game screenshot claim.

## Original engine audio

**`004182d0 → 00418780`** loads `Car_Snd.ini [Car0]` during game initialization, independently of the selected kart body. **`00418950`** starts the original `cmstartm.wav`; **`00418c80`**, called by player update **`004325b0`**, waits until that one-shot finishes and then starts three concurrent loops: `cvrpmm.wav`, `cvrpmhm.wav` and `cvstatm.wav`. A change from an already selected gear requests `SWITCH_GEAR` (`kpp1.wav`). Native **`0049d780`** suppresses a repeat while that event's current sample still plays.

Each gear stores its RPM on first entry, except gear zero whose minimum is initialized to 800. **`004189d0`** clamps `(RPM - savedMinimum)/(8000 - savedMinimum)` to zero through one, interpolates the four shipped gear-table integers, truncates pitch/volume separately and multiplies volume by `.75` before truncating again. The three layers retain their independent frequency and volume rows. Although `Cyl0` through `Cyl5` are present, the supplied INI has no `Cylinders` sample list; **`00418590`** consequently loads no cylinder effects.

The mixer uses **`0049d570/0049d520`**, not a linear percentage: after integer group-volume multiplication, the DirectSound volume is `trunc((percent-100)*3900/100)-100`. WebAudio gain is `10^(volume/2000)`, following DirectSound's [hundredths-of-a-decibel unit](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/ee418150%28v%3Dvs.85%29). **`0049d5e0`** adds an integer percentage of the original WAV frequency and clamps to 100–100000 Hz. The adapter reads the source WAV sample rate before WebAudio resamples the decoded buffer, preserving the native playback-rate ratio.

`source/engine-audio.js` holds the pure source state and command stream. `source/native-race-audio.js` plays those commands, uses original named effects through `getSoundSpec`, and owns pause/resume/disposal. `tools/native-engine-audio-fixtures.py` captures 360 original update frames and 101 mixer conversions; all match. `tools/validate-engine-audio.mjs` verifies actual browser decoding, the starter gate, all three loops, gear effect, repeat suppression, frozen audio time during pause, resume and complete voice disposal. A separate 48 kHz offline render produces finite nonzero stereo output from the original samples; `evidence/audio/browser-engine.json` records it. This validates the browser transport, not identity with an unavailable original sound-card recording.

The similarly named player function **`00432240`** handles skid sound and smoke. It is separate from the engine controller; skid triggers must use the original slip state rather than an inferred steering threshold.

## Native race text and notifications

`source/hud-text.js` now applies String's own **`0045caa0/00463c90/00463bb0`** hierarchy. INI string positions use height-normalized X without Composite's LEFT/TOP correction. String glyph spacing uses the parent's carried scalar at offset `0x0c`, while its anchor uses the separate position factor at `0x10`. Setting String scale also sets its horizontal extent. The former additive-pixel shortcut incorrectly placed BONUS outside the screen: the original centered parent places its anchor at approximately `(70,360)`. Glyph quads retain the HUD's near-plane pixel scale (approximately 0.99 of an authored pixel at Z=1), independent of MaxCharWidth spacing.

Forty original-instruction hierarchy fixtures cover all ten authored strings at both precisions and an additional scale override. The existing 306 native glyph-layout cases remain exact. `RaceHud` now renders the original BONUS label and dynamic `STRING_SPECIAL` atlas glyphs. Browser tests inspect actual BONUS pixels and render original PAUZE/final-lap text at 640×480 and portrait dimensions; results are in `evidence/hud/`.

`source/hud-notifications.js` translates **`00430610/0046c180/0046c1e0/0046c670/0046c890/0046c910/0046cc70/0046cfb0`** and all five animated styles **`0046d210`** through **`0046d5d0`**. Text is selected directly from the original `Language.ini`: native IDs 1, 3, 4, 5, 6, 7, 10 and 11 produce pause, superbonus, hit, last lap, best lap, time expired, collected items and checkpoint notices respectively. ID 2 stops special text. IDs 0, 8 and 9 belong to other controllers and create no invented message.

The controller preserves queued text, timed-notice interruption/resumption, zero-duration notices, alpha/scale/slide effects and frame-dependent enlargement. Queued resumption deliberately retains previous style and loop duration because the shipped **`0046cc70`** does so. `tools/native-hud-notification-fixtures.py` validates 296 native state snapshots including these queue quirks. Clock freeze, string allocation and renderer assignment are isolated boundaries; all notification state and queue instructions run unchanged.

The three authored `321Timer*Flare` sections are not instantiated by the original **`0045b860`**, which loads only the 35 numbered `[Elements]` entries. Those entries contain the main three countdown meshes but no flare sections. The browser therefore leaves those unused definitions unmounted.

`RaceHud.update` captures text at DrivingView's original render boundary, before bonus handling and race end-update. Earlier lap/record/checkpoint notices are dispatched before the HUD advances. End-update expiry requests alter the live queue after rendering and become visible on the following capture. Pause/resume explicitly capture the original PAUZE/stop command at zero delta. Separate ordering tests verify both cases and prevent duplicate dispatch of the same native event.

### Player tyre sound

`skid-audio.js` translates `00432190`, called by `00432240` in the `0042f230` update after particles and the voice controller, before rescue and rendering. The original `SLIP` WAV loops while `slipMagnitude >= 4` and `ground.playerContact` is true, with integer pitch percentage `slipMagnitude * 4 - 16`; otherwise an existing loop stops. The global sound-disabled branch returns without stopping an existing loop. The voice-controller enable byte gates only a new start, not pitch updates of an existing voice. `NativeRaceAudio.updateSkid` transports these recovered commands; `prepareEngine` also loads the original tyre sample. `native-skid-audio-fixtures.py` executes 176 native combinations, and the WebAudio browser check verifies the original loop, pitch and all gates with real decoded audio. Smoke emission in `00432240` is a separate controller and is not implied by the audio implementation.

### Dynamic scenery paths

`scenery-paths.js` translates the shipped dynamic PTH controller. All 35 scenery paths resolve to the original mesh animation registered by `0043e140`/`0044f9c0`; when an animation has multiple registered placements, the last placement is shared by every path using that animation. Static placements of the same mesh are not included in that lookup. `00446710` interprets the optional PATH_OBJECTS integer as independent repeat (bit 1) and closed-curve (bit 0) flags.

`00445900` activates only on a change to the exact nonzero start sector, once per lap, and honors the lap filter. It does not treat a skipped sector as crossed. `00445740` freezes the duration in ticks by dividing the path's seconds by the current delta, truncating, and rounding down to a complete segment count. `00446dd0` then advances one tick per call. `00445120`/`00445530` use a Hermite spline with tension .5, native float stores, endpoint clamping or wrapping, and explicit late-sample duration extension. Heading follows the next sample using the active4096 angle units. Repeating paths restart at `durationTicks-2`; nonrepeating paths retain their last sampled pose. Reaching an exact nonzero end sector disables the shared object; elapsed duration alone does not hide it.

The ten-slot allocation and lap/sector bookkeeping are preserved. `TrackViewer.captureSceneryPaths` applies the previous update at the render boundary; `stepSceneryPaths` advances after render and bonuses, before game actions, as in `0042f230`. Activation observes the player sector captured before physics by `004325b0` (`race.previousSector`). Initial authored OMP heights remain unchanged: object constructor `0048fef0` initially enables objects, and dynamic path initialization `00446bf0` is empty. There is no source basis here for snapping suspended rocks or other scenery to the ground.

`native-scenery-path-fixtures.py` executes 210 original duration conversions,1,750 spline samples,1,050 dynamic movement updates and4,368 sector/lap activation steps. XYZ samples and tick/state fields match exactly in24/53bit precision; heading agrees within .0005 native angle units. The browser check loads all six original tracks and all35 dynamic paths, verifies delayed transform capture, movement, original geometry and endpoint hiding. `evidence/scenery-paths/track-*-inspection.png` are inspection-camera screenshots, not original-game comparison images. The six built-in type1 camera paths and scenery collision consequences are not established by this rendering work.

### Positional scenery audio

`spatial-audio.js` translates `0049da60/0049d980/0049d900/0049d8a0`. The source uses strict distance < range, integer linear distance attenuation, a signed logarithmic pan curve and velocity-projected Doppler pitch. Its centered pan is +100 hundredths of a decibel rather than zero. DirectSound pan attenuates one channel while retaining the other's gain; WebAudio uses explicit stereo upmix and separate channel gains to preserve that behavior, following the documented [SetPan units and channel rule](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/mt708938%28v%3Dvs.85%29).

Factory `0043f020` resolves the final OMP integer through `etappeN.ini [sounds]`, then clones the named Sound.ini source for each placement. The six tracks contain 45/61/56/49/45/55 attached sources, including silent KKT entries. Type5 does not perform this attachment and is not incorrectly assigned the KKT event from its zero value. Attached sources set the native always-update flag; `00491530` calls them outside the nearby-sector window but skips hidden objects. Skipping a hidden callback preserves any existing voice. `NativeRaceAudio.prepareScenery` shares decoded PCM but allocates separate source and gain nodes per placement; `updateScenery` retains the source playback, volume, pan and pitch rules.

Listener handling preserves a subtle distinction. `0043b660` copies the camera's full matrix, negates its forward row and supplies player planar world velocity. `00498c00` copies body translation into POSITION_LOCK cameras, because `004a09e0` stores position in the full render matrix. Player and failure cameras therefore listen from the kart position. Startup fly-through and finish cameras have no body position lock and retain the constructor's zero translation. The listener does not follow the separately stored camera position. Ambient callbacks run before the next camera/listener update in `0042f4c0`, so use the previous listener snapshot.

`native-spatial-audio-fixtures.py` executes 700 original mixer cases at 24/53-bit precision and six complete camera/listener cases, including body position lock and retained translation. All compare exactly. The browser verification loads all 311 ambient clones and174 reactive-prop clones, checks independent voice/gain allocation, repeat suppression, hidden-object persistence and strict range stop. A real48 kHz offline render of the original mono windmill sample verifies the expected100 dB channel attenuation; results are saved in `evidence/audio/browser-spatial.json`. Reactive type2/26 placements attach PION_HIT_CAR directly through43b760;43fe80 calls the nonlooping spatial path once after launch. Their velocity comes from the original object's current local speeds and yaw. A path's explicit447210 stop clears its sound; merely skipping a hidden callback does not.

### Kart shadows and finish flag

`kart-shadow.js` recovers `00416270/004260c0`: every kart uses the original S_SHADOW quad and texture, with the four XZ corners replaced by that kart body's native bounds. Vertex diffuse is black with alpha128. UV coordinates are inset by two texture pixels. The shadow copies the kart's complete matrix, including tilt/scale, then replaces translation with X/Z+2 and Y equal to the lesser of kart Y and the current route sector's fallback plane height. The source does not sample a detailed ground triangle for this effect. The shadow draws immediately before its kart with alpha blending and inherited enabled depth writes; it does not enter the ordinary transparent-object queue.

`finish-flag.js` recovers `00423450/00423230/00423280/004233c0`. Ten strips of 34 vertices form the camera-relative flag, using the original small checker pattern in S_SFX.TGA. Activation freezes the two-second period as `trunc(2/delta)` update ticks. Each render samples the original4096 sine table for its wave depth and vertex gray, retains alpha100, then advances one tick. The original finish action requests activation after1500ms; this is captured by `NativeRaceResultGate.finishFlagRequested`. The flag disables depth testing and uses nearest texture filtering for the native high-quality setting's temporary filter change.

`race-visuals.js` exports `KartShadowVisual` and `FinishFlagVisual`. Geometry/pose evidence executes200 shadow cases and40 complete flag frames at both native precisions, with exact original grid/UV comparison. The browser check renders both against an original track: only darker pixels are introduced by the shadow, and the original checker atlas produces the animated transparent finish overlay. `evidence/race-effects/*-inspection.png` are explicit inspection views, not original-game screenshot comparisons.

### Smoke and native camera orientation

`simulation/native-smoke.js` executes the original70-slot pool, shared CRT random draws, emission gates, six-vertex fan geometry, motion, growth, fade, expiry and full-pool sorting. Sorting includes inactive slots and changes subsequent allocation order; it therefore lives in the pure simulation. Player skid emission uses the cached pre-physics position with updated native velocity/yaw; failure smoke runs at its separate post-render action. Native SndGfx.ini CLOUDS and the hardware path gate emission. `native-smoke-fixtures.py` compares180 complete original frames at24/53 precision, including random state and all70 sorted slot IDs. `SmokeVisuals` uses the original S_SFX atlas.

`native-camera-matrix.js` reproduces498c00's right/up/forward basis and intermediate float stores.480 original cases cover ordinary world-up and body-up failure cameras at both precisions. This matrix drives smoke fans and audio listener orientation. Free start/finish cameras retain native zero matrix translation; position-locked cameras inherit body translation.

### Sound coverage before level corrections

`tools/audit-audio-coverage.mjs` produces `evidence/audio/coverage.json`, containing every active Sound.ini record, all logical voice banks, attached/impact placement sources, original sound callsites and the implementation/evidence mapping. The current inputs contain496 sound records with495 distinct event names; AIRP1 is duplicated and native name lookup uses its first record. Record404 is valid native syntax `CDT=cdt.wav,...`: original4b1f60 separates on comma, equals and colon. The resolver now follows those delimiters. Every event resolves to an extracted original file.

The coverage work connected missing pickup/firing effects, character speech, collision/scrape sounds, recovery sounds, reactive prop impacts, homing-rocket warnings and the hardwired Space handler. `NativeVoiceController` retains11 logical FIFO queues, one dequeue per service call, global shared source identity, immediate replace/stop and disabled-controller admission behavior. Its600 original436760 cases pass. Character selector/chance draws use the simulation's shared RNG even if playback is disabled; collision random draws occur only in the native enabled branch. The collision selector's840 cases retain thresholds18000/25000, the strict300ms gate, rail-only short-interval SCHUUR, unsigned clock wrap and unconditional timestamp replacement. Contact callback duplication is preserved by the simulation.

Original missing names remain explicit: CLAXON is absent from character banks; GOT_BONUS and GOT_EURO are absent from effects; SOAP_UP1..3 have no entries even though SOAP_UP exists; marker53 requests FIRE_TURBO without a level, while only FIRE_TURBO1..3 exist. No near-name substitution is made. Replacement of a missing CLAXON still clears the addressed queue. Original42f9c0 passes the selected available-character index to a racer-index mapper, so its Space replacement may address an NPC voice;240 instruction cases retain this behavior and the directKT4 sound.

The arm warning uses the actual target-player squared-distance ratio.1200 original instruction cases cover its float32 .1/.4/.7 boundaries,24/53 precision and unordered ratios. It queues after that frame's voice service, so transport starts on the following update. NaN selects ARMBEEP1 before the native arm retirement branch. Recovery queues DISAPP/REAPP in the recovered actor's character FIFO at pre-update frame3, without a chance draw.

Browser evidence is layered deliberately. `all-assets-decode.json` checks all1,220 WAVs and6 music streams; only werk01.wav/werk02.wav are exact silent PCM. `browser-voices.json` starts327 logical bank entries and14 direct race effects through real WebAudio sources, checks queue/replacement/repeat rules and renders nonzero stereo PCM. `browser-spatial.json` exercises311 ambient and174 reactive clones. `race-trigger-playback.json` drives26 controlled state fixtures through live DrivingView ticks, including all three actual arm-controller warning beeps. The root's menu and media reports exercise original menu handlers and playback of all11 movies plus6 music streams. These reports establish decoded data, dispatch and transport, not a complete driven campaign or identity with an original sound-card recording.

Legacy police chase/arrest routines reference event names absent from the active Sound.ini; the old super-traction sound routine has no recorded incoming call and starts with sound ID−1. They are listed separately in the coverage report rather than assigned invented triggers. CarSound's random cylinder scheduler returns immediately because the shipped car0 has no Cylinders sample list.

### Original mixer composition

The active shell and race use Race.ini GAME_SETTINGS MX_VOLUME/FX_VOLUME, both shipped as100. The shell's options save writes these percentages but does not rewrite EFFECTS. VoiceController437560 intentionally repairs EFFECTS=1 with FX_VOLUME=0 to75 when loading the next race. The port stores slider values as fractions and rounds them back to whole percentages (`settingsAudioPercent`) before the native truncations, so 29, 57 and 58% no longer lose 1% or drift on each race. In-race437e30(0) instead writes zero to matching sources, clears the character/effects queues and disables their controller. SOUND.ON is a separate old startup flag; the direct effect, crash and voice gates read the controller byte. Skid's extra429050 gate reads SndGfx SFXVOLUME, not SOUND.ON.

The native audio engine master remains100. Static sources first receive the ordered RCRSOUND[VOLUMES] group overrides, then enabled437e30 replaces the percentages of sources whose group bits intersect the complement of MOTOR|MUSIC. This is a source-volume replacement, not multiplication by a second effects master. Scenery clones are created later from immutable Sound.ini type data, so they initially retain their authored volumes; a later actual effects-slider change updates current matching clones too. Reapplying an unchanged UI percentage on resume would incorrectly overwrite those initial clone levels and is avoided.

The active starter cmstartm belongs to GENERAL and receives the initial FX percentage; SWITCH_GEAR belongs to MOTOR. The three running engine layers also belong to GENERAL, but418c80 replaces their levels from Car_Snd.ini every frame, preserving the native engine behavior even after an effects change. Positional attenuation uses the source's current base percentage and retains the original pan/Doppler conversion.49d520 converts percentages to DirectSound hundredths of decibels with `trunc((p−100)*3900/100)−100`:100 yields−1dB,0 yields−40dB. A zero source percentage is therefore not itself digital silence; controller gates/stop commands are separate.

Race music uses431610's `trunc(p*4900/100)−5000`, skips playback at zero and loops through the native completion behavior. No voice-driven music attenuation is present in the recovered music setter callsites. RCRSOUND[MUSIC] volume−1500 is not substituted into the active streamed-music path. Menu playback uses sndPlaySound without a per-sample volume API, and RCMovie imports the Smacker playback path without SmackVolume; both retain full source gain independently of race sliders.

`native-audio-mixing-fixtures.py` executes the original parser and5,952 source-volume writes covering all496 records,16 controller gate cases and101 music conversions. Existing engine fixtures cover360 updates and101 sound-decibel conversions. `browser-mixing.json` verifies actual WebAudio gains, original PCM, immutable clone levels, live slider writes, FIFO clearing and subsequent engine overrides. `settings-playback.json` checks the real options-to-race zero→75 repair, unchanged-resume behavior, live zero gate and movie gain. This scope is stronger than checking asset presence alone and remains distinct from subjective listening comparison.

### Weather particles and route triggers

`simulation/native-weather.js` translates the original rain/snow constructor, particle update, route callbacks and camera-space draw geometry. `004818c0` selects `Track.ini [TRACK<raceType><country>]`; the first index is the race mode, not difficulty. The hardware/particles settings gate construction. A selected rain or snow pool allocates all 400 particles even when its initial Enable field is zero or absent. Each particle consumes four shared CRT random draws, so the initial pool consumes 1,600 draws before the later gameplay reseed.

Rain and snow retain their different original positions, velocities, mass, gravity, acceleration, lifetime, atlas coordinates and color. Update `00482020` follows the camera update and precedes voice servicing, skidmarks and rescue. The rain/snow tails `00483650/00483740` derive acceleration from the kart's local speed and modify surviving particles' Z velocity. `00483350` renders camera-space triangles using S_SFX, identity world/view matrices, the existing projection and SRCALPHA/ONE blending. The enclosing `00482190` temporarily disables depth writes; depth testing and culling remain inherited. The original renderer has an initialization defect: `00482840` supplies UVs to only 67 of the 400 six-vertex quads. The browser uses explicit zero UVs for the rest rather than pretending that uninitialized native heap bytes are reproducible.

The original route dispatcher invokes weather callbacks for the player. Markers 79/80 start/stop rain only when the current DMP waypoint carries the same marker; 84/85 similarly guard snow. Markers 81/82 and 86/87 are unguarded start/stop callbacks. Markers 83/88 cycle the authored percentage list forward or backward using the native travel-direction test. Sector-trigger inventory finds four weather sectors in Nederland, four in Duitsland and twenty in Engeland. Germany's unguarded 86/87 triggers can activate its initially paused snow pool. Spain constructs a paused snow pool in all four active modes but has no weather sector triggers. France and Italy select no weather. The complete mode, sector and waypoint-guard records are in `evidence/native/effect-coverage.json`.

`native-weather-fixtures.py` executes eight complete native constructors, 256 particle update/render frames and 320 route callback cases at both 24- and 53-bit FPU precision. Tests compare particle state, shared RNG state, active count, pause state and generated vertex data. Renderer services, allocation and texture lookup are the fixture boundaries; the original particle instructions execute unchanged.

### Original tyre marks

`simulation/native-skidmarks.js` retains `00426aa0`'s player-contact and slip-greater-than-three gates, the 20-record pool, first-free allocation and 98-vertex limit per side. It uses the two rear wheel X/Z offsets, a fixed local Y of 1 and local X offsets of ±4 before applying the current body matrix. It does not project marks onto a newly sampled ground surface. The source's UV pair is fixed for each emission; replacing it with alternating atlas coordinates would change the original image.

Each new strip freezes its lifetime as `trunc(20/deltaSeconds)` ticks. Capture follows pool index order through the identity lookup `00426540`, advances age and applies the original integer alpha fade. Rendering uses S_SFX with INVSRCALPHA/SRCALPHA blending and inherited enabled depth writes; alpha 255 is invisible in this blend mode. Disabling the renderer freezes mark age. No random draws are involved. `native-skidmark-fixtures.py` compares 520 complete native frames, including pool exhaustion, the vertex cap, expiry/reuse, contact/setting gates and both FPU precisions.

### Rocket explosion rings and inactive effect managers

The active rocket explosion belongs to the particle family `00481ec0`, rather than the separate generic effect manager `00485710`. Rocket hit initializer `00411830` creates a ring following the victim body after the hit-direction random draw and before the hit voices. Projectile height-impact `00455ce0` creates it on the shot body before changing the shot state. `simulation/native-explosions.js` preserves the four constructor random draws, head insertion, body-following position, 0.75-second lifetime and expiry before rendering.

`004844e0` builds three eight-vertex rings with native sine/cosine rounding. The outer and inner rings are transparent; the middle ring retains the orange RGB, original alpha change and sine-shaped vertical lift. Two indexed 18-vertex strips use the S_SFX atlas. Explosion updates precede weather updates, while explosion rendering follows weather and restores enabled depth writes; blending is SRCALPHA/ONE. Six complete original traces verify constructor RNG, lifetime, followed position and every vertex/color/UV/index at both FPU precisions.

`tools/audit-native-effects.py` records the active render families and a conservative activation audit. A whole mapped-image scan finds no direct call, jump or absolute pointer reference to generic-effect add `00485730` or halo add `00486460`; neither is an entry in the manager's available virtual table. Their constructors create empty managers. Executing both original managers for 120 update/render frames with varied settings produces zero draws, zero active records and no RNG changes. This establishes no discovered reachable activation in the shipped image, rather than a formal proof about arbitrary external code. The browser does not synthesize halo or generic effects from their dormant class definitions.

Six grass/spray particle entrypoints (`00481a50`, `00481a60`, `00481a70`, `00481e60`, `00481e70`, `00481e80`) are literal `MOV EAX,1; RET` stubs in the shipped executable. They allocate nothing and produce no particles. The remaining active kart/projectile stream family is tracked separately by its own helper and fixtures.

The source effect draw order is deferred world, tyre marks, halo manager, jetstreams, streams, homing arm, generic effect manager, rescue, smoke, finish flag, weather, explosion rings and HUD. The audit report preserves this order and separates controllers with native behavior from compiled but inactive or no-op entries.

The older 100-record spark pool is initialized by `00427c40`, but its renderer `00427c70` has no discovered direct call, jump or stored pointer reference. Its emitter `00427a60` is referenced only by `004354c0`, which likewise has no discovered reference. The active collision path calls `00435630`, a literal `RET`, instead. This dormant family therefore introduces neither spark particles nor random draws in the active port.

### Fixed bonus meshes and scenery squash

The Gen_anim bonus sections are indexed collections of meshes, rather than timed clips. `004500e0` selects `level + kindOffset - 1`, where pickup, owned and shot offsets are 0, 1 and 4. Selection runs when the bonus type, level or assigned object changes. `00455a10` advances shot age and position without advancing its mesh index. `native-bonus-visual-fixtures.py` compares 34 original pickup/owned/shot selections and 960 repeated shot updates. Thus `ProjectileVisuals` correctly reuses a fixed mesh per type/level, while the native flight controller separately rotates the body and updates its position.

The final update audit identified active squash hazards: OMP type43 in Nederland and type46 in Engeland and Spanje, plus type44's registered self-squashing props. `simulation/native-squash.js` translates the 32-record `0048e480/0048e560` registration, `0048e780` activation and `0048e970` service. Player and NPC records use game timers 19 and 20+index. Type44 records have no game timer and use their authored 1,200 ms registration duration. The source SndGfx settings limit forward speed to ±15, set a 3,000 ms racer duration and multiply only matrix coefficient m11 by 0.3.

Racers shake using alternating ±30 native yaw units. The original `004a16f0` aliases its input and output: its third row reads the already modified first row. The port preserves this detail. Timed recovery applies seventeen original rebound scale matrices, one per frame; a frame delta above the source's approximate ten-FPS threshold ends the rebound early. The raw signed tick-difference condition and the manager's retained timer-result variable are preserved, including its effect on following timerless props. Registration order therefore matters. Source service occurs after skidmarks and before rescue. No squash operation consumes random values.

`native-squash-fixtures.py` compares 720 complete native traces at 24/53-bit precision, with original timer instructions, clock wrap, repeated activation, shake matrices, rebound and both timer-backed/timerless objects. Native matrix rebuild remains an explicit callback for registered scenery; the ordinary racer update already supplies its current matrix. The separate activation helper matches 1,920 original hazard callbacks, including cached player positions, integer Manhattan distance, animation-frame boundaries, the repeated-player roster bug in type46 and the type44 callback targeting the prop itself.

Registration order is established independently of the timing of OMP loading. Lazy singleton `0048e210` calls `0048e480`, which immediately reserves the player and NPC records. Type44 initializer `0043f250` then appends a timerless prop through `0048e560`. After racer construction, `0042e910` only replaces the reserved records' body IDs through `0048e540`. It does not reorder them. The shipped tracks contain six such props in Nederland and one in Duitsland, comfortably below the 32-record capacity.

### Effect integration review

The core keeps original update order: camera/listener, explosion list, rain/snow, voice/skid audio, tyre-mark emission, squash, rescue, ribbons, jet flares and homing arms. Rendering captures tyre marks before streams and smoke, then weather before explosion rings. Streams receive the post-rescue render pose while retaining their original body identity. The separate renderer phase table preserves original immediate/deferred ordering; each kart shadow is submitted immediately before its own kart, after preceding OMP objects.

Initial rotating-object phases belong to the construction random stream. Browser-loaded states are passed to the pure simulation rather than generated twice; a headless simulation creates them before NPC construction. All nine authored rotating placements (six in Nederland and three in Spanje) exist in all four active race modes. Weather construction remains after NPC construction and before the gameplay reseed. The optional `00422ed0` fog draw is inactive because shipped `game.ini [OPTIONS] FOG=0`; custom nonzero fog settings are outside this active-configuration coverage.

The current focused review compares native helper fixtures, composed update order, shared weather RNG and geometry/material bindings. It does not claim a reference race recording, uninitialized native heap reproducibility, or exhaustive whole-program reachability. Dormant managers and literal no-op particle entrypoints remain explicitly identified above.

### S_SFX source selection and color-key filtering

The stream and flare controllers request the logical texture name `S_SFX.PCX`.
`004a6060` only performs a case-insensitive lookup in the texture manager; it
does not select an image format. Accelerated initialization `0042ccf0` calls
`004a2cc0(1)`, setting source mode `006a5edc` to 1. Loading through
`004a33b0 → 004a3d90 → 004a3c50` strips the extension and appends `.tga`
(literal at `004f6c30`), then calls TGA loader `004ac010`. Mode 0 instead appends
`.pcx` (literal at `004f6c28`). Thus the accelerated stream renderer correctly
uses the original 128×128 `S_SFX.TGA`, whose pixels differ from `S_SFX.PCX`.

The original CPU conversion **does replace key RGB with black before upload**.
This corrects the earlier version of this subsection, which stopped at the
`004b5740` dispatch and incorrectly said key pixels were not cleared. Its
RGB24 target `004b5470` compares the unquantized source against `0x7f00ff`
(RGB `(255,0,127)`) and substitutes the zero key components before packing.
Other colors that would pack to zero receive a one-unit red adjustment, keeping
ordinary black opaque. Near-pink pixels do not acquire transparency merely
because they share a hypothetical 16-bit pink value.

`004a4a30` obtains packed key **zero**, and `004a3d90` installs that value with
`DDCKEY_SRCBLT=8` on the memory and device surfaces (`004a40a8`, `004a40e3`).
Active initialization selects a 16-bit RGB texture format. Even for the two
32-bit TGA source files, `004ac010` discards source alpha on this format; it
does not synthesize an alpha channel. Converted race PNGs retain decoded
source RGB and carry only the exact color-key mask as alpha. Authored source
alpha remains provenance metadata.

At the earlier texture-key checkpoint, the common WebGL loader replaced key
RGB with black but left opaque channels unquantized and used a 0.5 filtered-mask
cutoff. That implementation is superseded by the
[native precision follow-up](research-native-texture-precision.md). The current
loader applies exact key comparison, optional integer gamma, RGB565 truncation
and protected non-key black before filtering. It stores native channel counts
in an RGBA8 carrier and expands them in the shader without an intermediate
8-bit rounding step. The shader rejects only zero key coverage, following the
documented historical driver profile. Scene blending reaches a real RGB565
target on every draw, with or without optional MSAA.

Prepared PNGs still retain the original RGB bytes; these runtime conversions
do not modify the archived source imagery. Blend factors and vertex alpha
remain separate from the generated mask. Original glyph quads and overlay
meshes now draw in native hierarchy order into a shared RGB565 composition
target; see [the HUD follow-up](research-hud-framebuffer.md). Exact historical
GPU filtering and rasterization remain unverified.
See [the complete native texture-key evidence](research-texture-key.md) for
the original-instruction fixtures, format selection and material distinctions.
