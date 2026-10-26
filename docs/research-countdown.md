# Original start countdown

The original race binary's `00464a70` advances the `321player` overlay, using
filtered simulation delta from `0048f4e0`. The constructor leaves phase 6;
`00464a00` starts it at phase 0, elapsed zero, sound index zero and normalized
screen Y 1.25. The port's `NativeStartCountdown` represents this activated state.

- Phase 0 slides all three elements from normalized Y 1.25 toward 0.4 over
  1.2 seconds, emits STARTSE1 at duration minus 0.1, then enters phase 1.
- Phases 1, 2 and 3 replace the respective element with animation frame 1.
  Each lasts 0.8 seconds and emits STARTSE2/3/4 at duration minus 0.1.
- Phase 4 selects frame 2 for all elements and lasts 0.8 seconds.
- Phase 5 slides the elements back toward Y 1.25 over 1.2 seconds.
- Phase 6 performs no further visual commands. Its elapsed field still advances.

`00464ff0` discards elapsed overshoot when changing phase. It does not clamp the
last rendered slide coordinate, so a large step can overshoot the endpoint.
`00464fc0` returns true as soon as phase exceeds 3; the race begins while the
green display is still visible. `00420dc0` checks this predicate and
`00420f00` starts game phase 0, resets the camera and selects the chase camera.
The game therefore does not wait until the overlay has completely departed.

Original assets come from each track's `eNN_anim.ini [321player]`:
`start1.d3d`, `start2.d3d`, `start3.d3d`, using the corresponding original
`overlay2`, `overlay3` or `overlay4` texture. Overlay.ini supplies the three
horizontal positions. Source `0045c4d0` converts screen Y using `1-2*y/height`;
`00464e90` and `00464f30` change that normalized position directly.

`tools/native-countdown-fixtures.py` executes the original routines in Unicorn
with controlled delta and explicit 24/53-bit x87 precision. Renderer/sound
side effects are intercepted and recorded, not replaced with expected port
values. `evidence/native/countdown-fixtures.json` contains 1,920 state updates
and 204 original slide positions. All comparisons pass exactly, including
threshold boundaries, jitter and oversized steps. The input binary hash and
stub scope are retained in the fixture file.

Run:

```sh
re-python tools/native-countdown-fixtures.py
node --test tests/native-countdown.test.mjs
```

The controller is implemented in `source/simulation/native-countdown.js`. Mounting
its original overlay meshes and connecting the full race-start/camera/sound
flow remain separate integration work. These fixtures do not establish a
full original race rendering baseline under WineD3D.
