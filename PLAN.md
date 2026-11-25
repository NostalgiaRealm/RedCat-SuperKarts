# Plan

Released as **2.0.0** on 2026-11-25 ([release notes](docs/releases/2.0.0.md)).

Goal: RedCat SuperKarts with the original race code (recompiled `rcskspel.dat`) and the JavaScript
reconstruction's menu, saves and extra settings, released the way RedCat Spookkasteel 2.0.0 was. The JS
reconstruction (`../RedCat Superkarts`, 1.0.3) stays as it is until this one has caught up.

## Milestones

| # | Milestone | State |
|---|---|---|
| 1 | Recompiler and module: rcskspel.wasm from the original | Done 2026-11-25: 5,604 of 5,620 functions, 4.0 MB, 5.4 s |
| 2 | Host from A2 Racer 4 and Spookkasteel; boot; first Nederland frame | Done 2026-11-25: boots in ~0.6 s, ticks in Node and Chromium, frames match the original's Wine capture |
| 3 | A whole race: input, pause, quit, finish, results, race.ini written back | Done 2026-11-25. Headless: a test bot drove all 5 laps, race.ini got tracktime, position and records. On the page (game worker, render worker): the original's pause, quit requester, finish screen and exit with real key presses (`tools/check-input.mjs`) |
| 4 | Sound: DirectSound effects and engine, DirectShow music on Web Audio | Done 2026-11-25: `dsound.js` on the race's clock, `dshow.js`, Web Audio on the page (`tools/check-audio.mjs`). Not compared by ear with the original yet |
| 5 | Presentation: interpolation between 25 ms ticks (A2's matrix blending), resolution, MSAA, full-screen aspect and HUD layout | Done 2026-11-25: smoothing (60 pictures a second from 40 passes), resolution and render scale, MSAA, any screen shape with the HUD at the edges and the finish flag grown (`tools/check-smooth.mjs`, `check-shapes.mjs`). Left: a larger HUD and safe-area insets on narrow phones (A2's `setShape`) |
| 6 | The JS reconstruction's menu wired to the race: INI handoff, results back into its saves (`rcsk.race-save.v1`) | Done 2026-11-25: the JS port's menu on `/` (`source/main.js`, `source/menu/`), `RaceRunner` (`source/race-runner.js`, one game worker for many races, module and files cached), the INI handoff and result reader (`source/host/race-handoff.js`, the JS port's result patch exactly). QuickRace, Adventure, debrief, highscores and settings run end to end with the real race (`tools/check-menu-race.mjs`, `tools/check-runner.mjs`, `tools/checks/menu/check-menu.mjs`, `node --test`); the menu screens are pixel-identical to the JS port's |
| 7 | The JS port's additions as hooks: touch and gamepad, FPS counter, surface shadows, engine light, free flight, stuck recovery; the two intentional departures | Done 2026-11-25, in headless Chromium only: touch and gamepad through the game's own analog handler; surface shadows over the drawn kart03 body (`source/host/shadows.js`); engine lights paired with their kart (`gl-renderer.js`); free flight (`free-flight.js`); stuck recovery and the NPC speed guard (`stuck.js`, `safeguards.js`); the original's debug and cheat keys only with `?cheats`; the JS port's HUD layout with per-group clipping (`hud-layout.js`); pause entry without the extra object pass but with the original's "pauze" (patch 0x42f6d8, `render-replay.js`); focus pause muted, live volume (`live-volume.js`), mid-race rebinding, the pad in the quit requester, repaint after a rotation in a pause. Checks: `tools/run-checks.mjs` runs them all (written, not yet run end to end). Not on a real phone, pad or 90/120 Hz display yet |
| 8 | Lean loading: the byte ranges of `rcs.img` a race needs instead of 180 MB | Done 2026-11-25: archives by HTTP Range in 16 KB pages, per-race lists measured on 96 races (`tools/build-preload.mjs`); first race 180 MB -> 30 MB, a second track 8 MB; 0 to 1 waits in the browser checks, 1 to 8 per five-lap bot race (`docs/hosting.md`) |
| 9 | Checks against the original under Wine; packages; hosting beside the JS port | Released as 2.0.0 on 2026-11-25: website package (`npm run package`, `docs/hosting.md`, `tools/deploy-site.sh`), desktop packages for Linux, Windows and macOS (`docs/building.md`), the JS port moved to the branch `javascript-port` and to `classic/` on the website. Comparison with the original under Wine is still open |

## Checks so far (2026-11-25)

- **Start against the JS reconstruction's original-code model** (`tools/checks/start-trace.mjs`,
  `start-reference.mjs`, `start-compare.mjs`; `evidence/checks/start-*.txt`): same start position, same
  dt clamp on the first three updates, start camera at ticks 40 and 135, countdown from 174, green at 320,
  first movement at 321, and speed, position and km/h equal through the first metres. The three inner
  countdown steps come one tick later (223/256/288 against 222/255/287): their thresholds are exact multiples
  of 25 ms and dt differs in its seventh digit between the performance-counter clock and the model's ideal
  clock. The CRT rand sequence differs from update 1 (voice choices: the headless run has no sound, so every
  sample reads as finished), and the runs drift apart around update 385.
- **Full race** (`tools/checks/full-race-gaps.mjs`): works headless. On the page's thread, nine kinds of loop
  wait inside one call for a key to change and would hang: pause (P), quit (Esc and the mouse requester
  0x473780), the D key, numpad 7-9, the cheat combinations, the finish screen's key-release wait, and the
  pump after a lost focus. The game-over screen (phase 6) waits for Esc, Enter or Space without a time-out.
  This is why the race now runs in a worker; the check's "frozen" cases still hang there by design, since they
  model the page's thread.
- **Worker page** (`tools/check-input.mjs`, `evidence/frames/input/`): P pauses and Space resumes; Esc shows
  the original's requester ("Wil je stoppen met deze race?", ja/nee, its paw pointer) and N goes on; Esc then
  J ends the race with exit code 0 and `finished=0`; the cheat Ctrl+F+I finishes, the finish screen ends the
  race by itself, and race.ini gets `finished=1`.

## Next actions

1. Rick's test round on real devices (desktop, phone, pad), and his calls on where the JS port departs from the
   original (see "Decisions open for Rick").
2. The live cadence: the original's gate (a frame when GetTickCount has moved 25 ms, the measured elapsed
   time as the step) instead of fixed 25 ms ticks, if Rick wants the measured variable step.
3. Sound by ear against the original under Wine (start, countdown voices, engines, a lap), and the CRT rand
   sequence of the first updates, which still differs from the JS reconstruction's model with real sample
   lengths (`evidence/checks/start-*.txt`).
4. The website: Rick's steps in `docs/hosting.md` (folder, nginx files, temporary address, switch); then real devices on it.

## Decisions open for Rick

- Where the JS reconstruction departs from the original (the recomp keeps the original for now): a click or tap
  ends the P pause in the original, not in the JS port; the JS port clears empty space (seen beyond the world in
  free flight) to 0x151d2b, the original to black; the JS port draws the narrow `wielv.d3d` on the rear wheels, the
  original the wide `wiela.d3d`; the quit requester's framing on phones (the JS port insets it on its page colour).
- A pad-only player has no way into the quit requester in either port (the JS port maps no Back button).

- Clock: fixed 25 ms ticks (the gate's minimum, deterministic) or the original's measured variable step.
- Decided 2026-11-25: the race runs in a worker that may block (Spookkasteel's model), not with per-tick
  hooks on the page's thread. The website's location for this port needs COOP and COEP headers.
- Which software display modes (RESOLUTION 0, 1, 5) to support, if any.
