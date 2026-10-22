# Kart-shadow audit

The shadow uses the original `S_SHADOW` mesh and texture. Two browser deviations
were confirmed and corrected: premature clipping and a second alpha composite
that made the displayed shadow too light. The clipping came from an extra
visibility test using stale bounds: after replacing the
small source quad with the kart's bounds, the clone still had the source sphere
of radius 21.11145. The kart03 quad needs radius 37.95784, centered at
`[-0.30969, 0, 4.38429]`. A shadow could disappear while its enlarged quad still
intersected the viewport.

`KartShadowVisual` now refreshes both bounds and omits this additional sphere
rejection. Original sector visibility and first-person hiding still apply.
The GPU clips the submitted quad, matching the direct shadow callback. No
dynamic light, extra softness, opacity fade, terrain lift, or new artwork was
introduced.

The second defect affected presentation even though GPU pixel reads looked
correct. Three r186 creates its own context with `alpha: true`, overriding the
renderer option passed by this application. Over white, the original shadow
blend produced RGB 127 with framebuffer alpha 191; the browser then composited
that partially transparent canvas over white again, displaying RGB 191.
The original game's opaque backbuffer has no such second canvas composite.
`world.js` now supplies an explicitly created WebGL2 context with
`alpha: false, antialias: false`. The optional MSAA target still resolves its
RGBA values normally, while the final framebuffer is opaque. Actual screenshot
pixels now equal the GPU RGB value 127, with framebuffer alpha 255. This leaves
the original texture, vertex alpha, and blend factors intact.

## Original evidence

The read-only original executable is `rcskspel.dat`, SHA-256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.

| Original routine | Observed behavior |
| --- | --- |
| `416270` | Resolves `S_SHADOW`, sets all four diffuse colors to ARGB `80000000`, specular to zero, and UVs to two texture pixels inside the border. |
| `4260c0` | Replaces the four X/Z corners with the current kart body's bounds. Copies the full drawn matrix, including tilt and scale. Samples the current sector plane at the logical kart X/Z, caps shadow Y by logical kart Y, and adds 2 to drawn X/Z. Directly invokes `4a0d80`. |
| `494b70` | Evaluates that sector's plane; it does not find a road triangle under each corner. |
| `4918f0` | Calls the shadow immediately before its kart after the original object/range visibility gates. |
| `4a0d80` | Submits the mesh with its copied matrix and enables blending for mode 1. It has no extra WebGL bounding-sphere test. |

With alpha blending enabled, `4260c0` explicitly selects SRCALPHA and
INVSRCALPHA. With it disabled, it inherits the preceding factors; the existing
native blend-state adapter preserves this behavior. Depth testing/writes and
single front-face submission remain unchanged. World filtering follows the
original display setting.

REA produced the complete `416270` function dossier in
[`rea-shadow-init.json`](../evidence/shadow-audit/rea-shadow-init.json), Evidence
`ev_0dba83233a7e34a31893bcab576d49a8044e453370b1c4c3ed13c12b382e3f9f`.
The configured MCP provider still lacked `GHIDRA_INSTALL_DIR`; an isolated CLI
used the already installed Ghidra 12.1.4 without changing host configuration.
Fresh default analysis did not discover the callback at `4260c0`; that failed
request is retained separately. Its complete existing Ghidra export and the
original-instruction execution fixtures supply that evidence, not a fabricated
REA dossier.

## Texture and shape

The original high-color texture is a 64×64 hard-edged rounded rectangle:
3,394 black pixels and 702 exact RGB `(255,0,127)` key pixels. There is no
fractional alpha or soft falloff. The browser PNG preserves every original RGB
value and adds exactly that binary key mask. The shared upload path clears key
RGB before interpolation; the shadow's black diffuse makes all surviving
sampled RGB black. Its opacity is the original `128/255` vertex alpha.

[`native.json`](../evidence/shadow-audit/native.json) verifies byte identity
against original `rcs.img` for the TGA, D3D mesh, and both archived PCX variants.
The TGA SHA-256 is
`69e0a91357032147b577816c235346cb2ef6d95e927b93e6749ef2d582ba809e`;
the mesh is
`b297bf85759cff57b382ca4d385f23ccd9a7a799111116ecd58e9a8828d4f84c`.
The accelerated path uses the original TGA substitution already established in
[the texture audit](research-texture-key.md).

The original plane projection has visible limitations which are retained. At
France's starting sector 174 the authored fallback plane is Y=0 while the road
triangles are at Y=20 and higher. The shadow is submitted but hidden below that road. Raising
it onto the road would change the recovered source behavior. The new browser
report records both heights rather than treating the lack of visible pixels
there as a renderer failure.

## Verification

* Ten executions of original `416270` cover five texture widths at both 24- and
  53-bit x87 precision. Only object lookup/allocation boundaries are replaced;
  the original color and UV writes execute. They match the browser helper.
* Eleven focused tests pass, including the existing 200 native shadow poses,
  200 split logical/drawn-position and blend-state cases, and original render
  order traces. Both active body shapes retain correct resized bounds without
  modifying shared mesh geometry.
* Five browser checks pass with no page/console/HTTP errors. The deliberate old
  stale-sphere control renders zero pixels at the viewport edge. The correction
  originally rendered 78,252 shadow pixels in the same view, with interior
  value 127 over white. The later native RGB565 framebuffer now stores
  `[123,125,123]` after this original alpha blend in both normal and 4×MSAA
  paths. An actual browser screenshot agrees with the framebuffer readback,
  and the context reports `alpha: false`; this assertion catches
  the second-composite defect that GPU reads alone missed. Mirrored MSAA edges
  may use different coverage values because the fixed sample pattern is not
  reflection-invariant; the interior opacity and coverage count agree.
  The loaded Netherlands race shadow
  darkens only the road and is submitted immediately before its kart. Mirrored
  France retains the original below-road behavior. See
  [`browser.json`](../evidence/shadow-audit/browser.json) and the inspection
  images beside it.
* The older combined shadow/finish-flag browser tool was repaired to provide
  current actor ownership and native draw ordering. Its former failure was a
  stale test setup, distinct from the clipping defect.

The pre-fix compositor failure is retained as `browser-compositor-before.json`,
`browser-compositor-before.log`, and `edge-compositor-before.png` beside the
current report. Earlier harness assumptions about France's shadow being visible,
its road height being exactly 20, and reflected MSAA edge samples being identical
are retained separately; those were test assumptions, not additional game bugs.

Run `re-python tools/native-shadow-audit.py`, the focused Node tests, and
`node tests/kart-shadow-browser.mjs` against the local server to reproduce.
The asset check uses the existing asset-preparation Python for Pillow and the
existing analysis Python for Unicorn. Original files remain read-only.

These are original-code/data and browser-rendering checks. The available Wine
race renderer remains unreliable, so no pixel-identical original Windows
framebuffer comparison is claimed. The later
[precision follow-up](research-native-texture-precision.md) replaces the old
filtered-mask cutoff with a documented historical driver profile and uses an
RGB565 scene target. Historical device filtering and rounding remain scoped.
