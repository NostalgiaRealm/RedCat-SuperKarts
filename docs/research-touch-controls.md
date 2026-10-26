# Touch controls: sources and behavior

Checked on 23 October 2026. This is a browser-control adaptation requested for
the port; the original Windows game did not supply this touchscreen interface.

## SuperTuxKart behavior reference

The comparison uses the official `supertuxkart/stk-code` repository at commit
[`2997f192e6876047909d909498dbb4810e5dbb8d`](https://github.com/supertuxkart/stk-code/tree/2997f192e6876047909d909498dbb4810e5dbb8d).
The JavaScript implementation is written for this port's input system; the
SuperTuxKart C++ code is used as a behavioral reference.

- [`MultitouchDevice::updateDeviceState`](https://github.com/supertuxkart/stk-code/blob/2997f192e6876047909d909498dbb4810e5dbb8d/src/input/multitouch_device.cpp)
  measures horizontal and vertical finger position relative to a fixed wheel
  rectangle. Each axis is centered on zero, with the edges at -1 and +1.
  Steering does not require tracing a circular gesture. An active touch stays
  assigned to the wheel when it leaves the initial rectangle, until release.
- The same file's `updateAxisX`, `updateAxisY` and `getSteeringFactor` implement
  a central deadzone and proportional output. Left/right controls steering;
  the upper half accelerates; the lower half uses the game's brake/reverse
  action. Releasing the wheel centers the axes. Automatic acceleration is a
  separate option and defaults to off.
- [`user_config.hpp`](https://github.com/supertuxkart/stk-code/blob/2997f192e6876047909d909498dbb4810e5dbb8d/src/config/user_config.hpp)
  sets the default deadzone to `0.1`, horizontal sensitivity to `0.2` and
  vertical sensitivity to `0.65`. Outside the deadzone, magnitude is
  `min((abs(axis) - deadzone) / (1 - deadzone) / (1 - sensitivity), 1)`.
- [`RaceGUIMultitouch`](https://github.com/supertuxkart/stk-code/blob/2997f192e6876047909d909498dbb4810e5dbb8d/src/states_screens/race_gui_multitouch.cpp)
  puts the wheel at the lower left by default. Its diameter is `0.35 * screen
  height * control scale`; it accounts for display padding and offers inverted
  placement. Wheel rotation and upper/lower masks provide steering and drive
  feedback. The port uses responsive browser dimensions and safe-area insets.

The requested right-hand brake pedal must use RedCat's **Alt / handbrake**
action. It is separate from the wheel's downward **Arrow Down / brake-reverse**
axis. These are distinct existing inputs in `source/input.js` and
`source/simulation/native-input.js`; the new artwork does not change their physics.
The bonus button uses the existing **Ctrl / bonus** action. Simultaneous wheel,
pedal and bonus touches must remain independent.

## SVG artwork selection

SuperTuxKart's shipped Android controls at this commit are PNGs, including
`android/steering_wheel.png`; the official recursive code-repository tree has no
matching touch-wheel SVG. The Android
[`licenses.txt`](https://github.com/supertuxkart/stk-code/blob/2997f192e6876047909d909498dbb4810e5dbb8d/data/gui/icons/android/licenses.txt)
credits the wheel to Néd J. Édoire, copyright 2017, under CC BY-SA 4.0, and its
upper/lower masks to Benau, copyright 2019, under CC BY-SA 4.0. Those PNGs are
not copied into this port.

The selected editable vector set is **[Car Controls](https://opengameart.org/content/car-controls)**,
published by **looneybits** on 5 September 2015 under **CC0 1.0 Universal**.
The creator's release contains both a classic steering wheel and a recognizable
grooved brake pedal. Their rounded shapes, dark rim and bright metal highlights
provide a coherent pair without adding a new font or replacing original menu
graphics. Alternatives checked from the same creator were
[SteeringWheel 02](https://opengameart.org/content/steeringwheel-02) and
[Car Pedals 01](https://opengameart.org/content/car-pedals-01), also CC0.

| Runtime asset | Original object | Adaptation |
| --- | --- | --- |
| `public/assets/touch/steering-wheel.svg` | `g9211` in `car_controls.svg` | Extracted wheel; transparent square viewport |
| `public/assets/touch/brake-pedal.svg` | `g37281` in `car_controls.svg` | Extracted broad grooved pedal; transparent viewport |

The paths, gradients and colours are unchanged. Unrelated sheet objects,
background, editor metadata and unused gradient definitions were removed.
The source SVG, CC0 text, source URL and SHA-256 hashes are preserved under
[`public/assets/touch/`](../public/assets/touch/ATTRIBUTION.md). Both extracted
SVGs were parsed and rendered to inspect transparency, bounds and appearance.
No external images, script or external resource references occur in either
runtime SVG.

The separate power-up button is newly generated for this port, following the
user's request to match the original RedCat button and menu artwork. Its
generation provenance is recorded separately from the CC0 control artwork.

## Port integration

The wheel at the lower left accepts a single controlling contact and gives
visual feedback through rotation and highlighted Gas/Achteruit labels. The
pedal and bonus button on the right can be held independently, including
three simultaneous contacts. Their target areas stay separate in portrait
and landscape layouts, with safe-area padding and a reserved HUD band.
Stoppen still opens the original race quit requester.

`InputController.bindSteeringWheel` supplies proportional axes through the
existing native joystick path. The wheel uses the response formula above,
including a neutral center, rather than turning every small movement into
a full digital steering press. Keyboard controls keep their existing native
ramps. Pedal and bonus contacts do not disable proportional wheel steering.

Pointer capture keeps a drag alive outside the wheel. Release, cancellation,
lost capture, mode changes, focus loss, hidden-document handling, resizing and
controller destruction clear the corresponding held state and artwork.
`InputController.clear()` also releases active captures, so rotating the phone
cannot resume an old gesture at a new screen position.
The same ownership hook runs when the driving view clears `InputState`
directly during suspension or free-flight changes.

The source HTTP server and Electron protocol now serve SVG as `image/svg+xml`.
No external asset service is needed at runtime. The generated bonus button is
stored locally as [bonus.png](../public/assets/touch/bonus.png), with the complete
[built-in image-generation prompt](../public/assets/touch/bonus-prompt.txt).
Its transparent RGBA image is new artwork, separate from the CC0 SVG set and
the recovered RedCat assets.

The bonus artwork was subsequently refined against the supplied original
round `mn_0210a/b/c` and `mn_0211a/b/c` buttons. It now has three red toe pads
above the circular face and brighter red/yellow colours, retaining the bolt.
The source and dist references are byte-identical. Display sizing and input
are unchanged; the revised asset was inspected at 64, 78, 96 and 112 CSS pixels.
See [comparison](../evidence/touch-controls/bonus-comparison.png),
[artwork-only validation](../evidence/touch-controls/bonus-refinement.json) and
[edit prompt](../public/assets/touch/bonus-edit-prompt.txt). The earlier full
touch-validation record retains the initial asset hash.

The larger controls exposed a short-landscape HUD overlap: the bonus frame
moved upward into the standings while retaining a full-screen scale. The
vertical HUD groups now fit above the control band. Race-time text keeps its
normal landscape size and right-edge alignment for readability. Portrait and
non-touch layouts retain their existing proportions.

## Focused verification

- `node --test tests/touch-input.test.mjs tests/platform.test.mjs tests/native-input-key-gates.test.mjs`:
  19 passed, covering the wheel response, original keyboard behavior, independent
  contacts and lifecycle cleanup. After adding direct `InputState.clear()`
  ownership cleanup, only the nine touch-input tests were repeated; all passed.
- `node --test tests/touch-hud-layout.test.mjs tests/star-hud-layout.test.mjs`:
  four passed, including original-mesh bonus/standings clearance and readable
  race-time glyph sizes.
- `node --test --test-name-pattern='SVG touch controls' tests/electron-runtime.test.mjs`:
  one passed, serving the real SVG assets through both source and packaged
  Electron directory layouts. No desktop package was built or launched.
- `RCSK_URL=http://127.0.0.1:4184 node tests/touch-controls-browser.mjs` and scoped
  follow-ups: 12 browser groups cover actual Quickrace startup, forward/reverse
  motion, proportional steering, Alt/pedal equivalence, three simultaneous
  contacts, captured drags, cancellation, resize, quit/pause, focus/visibility
  and four phone viewport sizes. A final isolated group verifies direct driving-
  view suspension clears held pointers and permits a fresh analog gesture.
  Only affected remaining groups/layouts were repeated after fixes; the report
  identifies each source checkpoint.

The secondary-finger Stoppen check caught and fixed a missing click: browsers
do not synthesize click for that contact while the primary finger holds the
wheel. A release inside Stoppen now invokes the same original quit gate.

The checks use Chromium/SwiftShader and browser-dispatched touch contacts.
They do not establish physical phone ergonomics, Android/iOS/Safari behavior,
real GPU performance or a full race. No full suite, full races, builds or
publication were performed. Results and screenshots are under
[`evidence/touch-controls/`](../evidence/touch-controls/browser.json).
The [consolidated validation record](../evidence/touch-controls/validation.json)
includes the final source and asset hashes.
