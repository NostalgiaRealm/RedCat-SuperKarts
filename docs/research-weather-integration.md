# Weather, skidmarks and race-loop integration

The browser race uses the recovered weather and skidmark controllers, with the original `S_SFX` image. These additions preserve the shared random stream; no separate random generator is used for weather.

## Construction and update order

`0x4818c0`, called at the end of `0x42d7d0`, selects `TRACK<raceType><country>` from `track.ini`. Difficulty does not select weather. Hardware rendering and the `particles` option gate construction. Rain and snow each construct all 400 particles, including when `enable` leaves the controller paused. The constructor consumes four CRT random values per particle before `0x42f930` reseeds gameplay.

`RaceSimulation` constructs its weather controller after actors, bonuses and other controllers. `DrivingView` performs its gameplay reseed after this construction. The pure simulation's caller owns any reseed, as before.

The recovered `0x42f4c0` sequence is:

1. Update/integrate objects and update the selected camera (`0x41d920`).
2. Update the sound listener (`0x43b660`).
3. Update particle systems (`0x482020`), including weather.
4. Service character voices (`0x437c10`).
5. Run skid sound/smoke (`0x432240`) and skidmark emission (`0x426aa0`).
6. Update rescue and other effects, then render.

The browser exposes `afterCamera` for listener work and `afterParticles` for voice/skid audio. Weather receives the player's current local lateral, vertical and forward velocity, not camera velocity. A paused controller neither ages particles nor recycles them. The recovered explosion list updates before weather in `0x482020`.

## Track callbacks

The generic callback dispatcher `0x4938e0` is called by player callback `0x4325b0`. It dispatches the crossed PMP record's first marker and then its second marker. The NPC handler `0x406470` has a separate switch without weather callbacks.

The composition calls `NativeWeather.trigger` at that player boundary. Guarded rain markers 79/80 and snow markers 84/85 inspect the current driving node's second word: `track.drive[body.waypoint].unknown[1]`, corresponding to native DMP offset `+4`. Unconditional markers 81/82 and 86/87 do not require that match. Density markers 83/88 use the original `0x415be0` heading dot product, already recovered as `nativeProjectileFacing`; increasing sector index alone does not determine their direction.

Relevant shipped PMP boundaries include Netherlands rain start/stop markers, Germany unconditional snow markers, and England rain start/stop/density markers. The controller kind still comes from the current race type, so a marker for an absent controller has no effect. In particular, Germany's initially paused weather in some race modes can become visible later.

## Rendering

`0x430020` draws skidmarks immediately after the world, other effects and smoke next, the finish flag next, and weather through `0x482190` afterward. Weather's `0x483350` sets identity world/view matrices: its triangle vertices are camera-relative. The browser attaches its mesh to the active presentation camera and reflects local Z for Three's camera coordinate convention. It retains the normal camera projection, source-alpha/one blending, enabled depth testing and disabled depth writes. It inherits front-face culling. The finish flag restores depth testing before this pass.

Native `0x482840` initializes UVs for only `ceil(particleCount / 6)` quads. The recovered controller preserves this bound. The remaining native heap contents are unspecified; the port explicitly uses zero-filled UV storage for those slots. Filling every particle's UVs would silently change the original implementation.

Skidmarks use `0x426aa0` rear-wheel X/Z coordinates with fixed local Y=1 and the current body matrix. They are not projected onto ground triangles. The pool has 20 pairs, at most 98 vertices per strip, and source tick-based 20-second fading. `0x426540` returns the supplied index, so render traversal is pool order 0–19. The browser expands each triangle strip without changing its winding and uses inverse-source-alpha/source-alpha blending: alpha increasing toward 255 makes a mark disappear. Depth test and depth writes remain enabled.

Both controllers advance once per simulation render boundary. Display refreshes interpolate/present captured state without aging particles or marks again.

## Rocket rings and kart shading

`NativeBonusCombat.onExplosion` synchronously creates the recovered `0x481ec0` ring at the two native call sites: an accepted rocket hit after spin/launch initialization, and a projectile's qualifying height impact before deactivation. Construction consumes four values from the shared CRT stream. New entries are prepended; their 0.75-second update follows the referenced object's current position, including retained projectile objects. The browser captures the two indexed strips and renders them after weather with source-alpha/one blending, depth testing and depth writes enabled. Expired mesh geometry is disposed. This is the active rocket particle class, not the inactive generic effect manager.

Kart shading follows `0x490d40` → `0x4903c0` only for native visible-sector draw submissions. `0x495fe0` / `0x496360` selects the first eligible road/land/extra triangle's third-vertex color using the current sector and render-object position. The original color smoothing depends on forward speed and delta; track-specific brightness is applied only to the rendered result. Persistent body diffuse begins at `0xffffffff` and is stored separately, so country brightness is not accumulated every frame.

`KartVisual` applies the helper's color to all body/wheel/driver vertices, replacing the asset's vertex diffuse. It does not multiply another tint over those original colors. The `0x44cac0` animation callback first reapplies persistent diffuse to its newly selected frame; the later draw calculation supplies final brightness. Each actor owns color clones, while source positions, source colors and other actors' buffers remain unchanged. Retired animation-frame clones are disposed when the race reloads. Rescue sampling uses the temporary render position but retains the engine body's sector; it does not enable the unrelated legacy-autopilot flag.

## Related clock correction

The original mesh-animation clocks begin at zero and compare raw `GetTickCount`. The reference host uses `NATIVE_REFERENCE_UPTIME_MS = 60000`; raw consumers receive this plus wall time, while race timers and path counters retain their separate relative domains. Driving scenery, actors, fire gates, turbo animation, crash audio and smoke use that raw domain. Standalone track inspection now gives its scenery mesh callback the same epoch. Pause reinitializes the delta filter without inserting another uptime sample.

The source flag `0x53be64` has no identified writer and selects an unused legacy-autopilot branch. Rescue activity does not set it. The race animation adapter passes `legacyAutopilotActive: false`; it no longer suppresses requests merely because a rescue entry exists.

## Validation

- Native weather fixtures: eight original constructors, 256 full particle updates, and 320 marker callback cases, with 24-bit and 53-bit arithmetic.
- Native skidmark fixtures: 520 full emission, pool-exhaustion, vertex-cap, fading, reuse and expiry frames.
- `tests/race-weather.test.mjs`: shared construction RNG, stage order, real PMP/DMP guards, Germany's unconditional snow boundaries, England reverse density, and identical particle/random results at 31/60/144 presentation FPS.
- `tests/weather-visuals.test.mjs`: exact submitted vertex/UV/color values, camera-relative transform, strip winding and material/depth state.
- `tests/native-explosions.test.mjs`: original ring constructor RNG, following, lifetime and both indexed strips at 24/53-bit precision.
- `tests/native-kart-color.test.mjs`: 600 native color updates/child propagation cases plus extracted ground colors and country offsets; `tests/kart-color-visuals.test.mjs` verifies per-actor replacement, unchanged source geometry and clone disposal.
- `tests/race-simulation.test.mjs`: all six tracks at all three difficulties and existing render-rate composition checks remain passing.
- `tests/weather-browser.mjs`: Chromium rain/snow rendering, camera attachment, draw count/depth state, and a controlled explosion callback/color-binding check passed without page errors. Screenshots and report are in `evidence/weather/`.
- `tests/animation-browser.mjs`: all four drivers and 20 callback scenarios still passed, with no animation-position mismatches after color cloning.

These are native instruction comparisons and browser integration checks. No original Wine race-render screenshot comparison is claimed.
