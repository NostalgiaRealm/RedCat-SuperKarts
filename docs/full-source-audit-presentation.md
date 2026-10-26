# Original-code comparison: presentation and audio

Date: 26 October 2026. This source-only pass accompanies the complete original
binary decompilation inventory. Decompiled C is recovered pseudocode, with
inferred types and identifiers, not the lost author-written source. Findings
below use the shipped `rcskspel.dat` instructions (SHA-256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`),
the existing per-function exports, original configuration and current callers.

## Corrections made

### Native pause and quit screens keep the current sounds playing

The port used the same complete audio suspension for the P-key pause, Escape
quit requester, loss of browser focus and leaving a race. The original separates
those cases. `0042f350` pauses timers `0,3,8,9..27`, polls music completion once,
then blocks in `0042f220` (P) or `0042f290` (Escape). It resumes those timers
and resets the frame-delta history after the blocking call. Neither branch
stops or pauses the DirectSound buffers or DirectShow music. `0042f220` resumes
after the original key release sequence and dispatches HUD notice 2;
`0042f290` selects the requester result. `0042a810` separately stops the
engine, closes sound effects and stops the music on actual race exit.

`DrivingView.suspend` now accepts `pauseAudio`, defaulting to true for host
focus/menu behavior. The real P/Escape caller passes false. Race movement,
timers and HUD animation still freeze; existing loops continue and one-shot
sounds finish. Losing focus while the requester is already open still invokes
host audio suspension. A later completed cancellation closes the requester but
retains that host pause until a deliberate resume gesture; confirming quit stops
the race audio as before. A narrow focus latch also prevents a previously
pending key release or the requester's 100 ms pressed-image delay from silently
restarting the race after blur. This is a browser host recovery safeguard, not
an original game rule. It retains the intentional focus-loss behavior while
correcting the native game interaction.

### Music repeats at the original game update boundary

The port had `HTMLAudioElement.loop=true`, which would keep restarting music
even while the original game thread was blocked in pause. Native
`0042d7d0` selects `rclemu%02d.dat`, starts it only with nonzero music volume
and enables the repeat flag through `0048ec20(1)`. Completion service
`0048ef80`, called at the end of `00430020` and once on pause entry, handles
completion by resetting through `0048eee0` and starting through `0048edc0`.
The repeat flag does not independently service completion during a blocking
pause.

`TrackMusic` now disables automatic HTML looping. `pollCompletion()` restarts
a finished stream from zero; `DrivingView` calls it at the captured native
render boundary, before the post-render bonus/game actions, and once when
entering native pause. Uncapped browser refreshes and paused HUD redraws do
not run this service. A stream that ends while paused remains ended until
the game resumes. Volume conversion and original recordings are unchanged.

## Other paths compared in this pass

| Area | Original code and current integration reviewed | Outcome |
| --- | --- | --- |
| Frame/render order | `0042f4c0`, `00430020`, `render-order.js`, `DrivingView` capture callbacks | World, deferred objects, effects and HUD retain the recovered ordering. The gameplay audit separately corrects the engine-update callback's placement within the player callback. |
| Road and object submission | `004971f0`, `00497270`, `00491670`, `004918f0`, native visible groups and ordered material draws | ROAD/LAND/EXTRA/RAIL order and accelerated texture-classifier behavior are retained. The alternate software renderer is not newly treated as the accelerated path. |
| Blend/depth rules | `0048f600`, `004a0d80`, `004a7e10`, `NativeBlendState`, `createNativeMeshMaterial` | Deferred mode factors and depth-write selection already match the recovered accelerated branch; no new factor change justified. |
| Sky | `00422d50`, `00423010`, authored sky mesh colors and `TrackViewer`/`DrivingView` | Original scale and logical racer position are retained. All three selected sky meshes contain white vertex colors, so the existing unmodulated sky material does not omit authored vertex shading. |
| HUD notices | `00430610`, current dispatcher/text and pause callers | IDs 1/2 remain pause/resume; the quit requester does not manufacture a PAUZE notice. IDs 0/8/9 remain separate controllers. |
| Sound repeat/mixing | `0049d780`, `0049e970`, `00437e30`, `0042c320`, `00431610`, `NativeRaceAudio` | Repeated-play suppression, any-overlapping-group selection, effects disable/queue-clear behavior and native music gain conversion already match their covered original branches. |
| Active effects and HUD rendering | Current bubble, rescue, stream, weather, shadow, glyph and RGB565 integration, checked against the existing original-instruction research linked below | No new missing active effect was established. Existing hardware/undefined-state boundaries remain explicit rather than being replaced with guessed behavior. |

This is a bounded integration review, not a claim that every decompiled
instruction or every possible display/audio device was behaviorally proven.
Existing detailed references remain applicable:
[render composition](research-render-audit.md),
[HUD framebuffer](research-hud-framebuffer.md),
[native texture precision](research-native-texture-precision.md),
[effects and order](research-streams-squash-order.md),
[race sound dispatch](research-race-sound-coverage.md), and
[power-up audio](research-powerup-audio.md).

## Focused validation

- `tools/native-pause-audio-fixtures.py` freshly executes three unchanged
  original pause/quit dispatch traces, including P resume, quit cancellation
  and quit confirmation. Timer APIs, key polling, HUD/requester services,
  phase assignment and music-completion polling are explicit service
  boundaries. Evidence: `evidence/native/pause-audio-fixtures.json`.
- `node --test tests/native-pause-audio.test.mjs tests/audio-mixing.test.mjs`:
  six tests pass. They cover both native pause branches, subsequent host
  focus loss, one completion restart and the existing original mixing fixtures.
- `tests/pause-audio-browser.mjs`: nine checks pass with real Chromium media
  playback and P/Escape/J/N/X key events. It checks advancing audio with frozen
  race state, focus loss from an open requester, pending quit-cancel keyboard
  release and pointer press, pending P resume release, deliberate return after
  focus pause, completion while paused, normal update looping and cleanup on
  quit. The end-of-track cases explicitly seek near the original music stream's
  end; focus loss uses the existing blur event handler. The pointer/blur race
  dispatches those two UI events synchronously to cover the timing boundary.
  Evidence:
  `evidence/full-source-audit/pause-audio/browser.json`.

No full races, broad test suite, builds or publications were run for these
corrections. The original race renderer still cannot provide a reliable
framebuffer/audio comparison in WineD3D. Native Windows sound-card timing,
historical GPU filtering and exact rasterization remain unobserved. The
requested unlocked rendering, widescreen/touch controls, MSAA, cheats,
automatic muted movie startup/fullscreen audio button, original movie aspect
ratio and authorized stuck recovery remain intentional port behavior.
