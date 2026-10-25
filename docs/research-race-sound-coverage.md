# Race sound coverage

The [25 October power-up follow-up](research-powerup-audio.md) verifies the
pickup/firing paths against both original copies, fresh REA/Hopper evidence,
3,001 original instruction cases and 118 controlled browser cases. The current
recordings, sound names, queue order and mixing matched; no game-audio change
was required. The earlier 26-case tool below retains its narrower historical
scope; its controlled clock baseline has been updated for the variable host.

The playback audit precedes mixing corrections. A decoded file, a named sound
in an INI, and a reachable gameplay trigger are separate evidence.

## Connected original dispatch

- Character FIFO requests use the original available-character mapping:
  opponents first, player last, with effects in bank 10. Passing, catch-up,
  pickup, firing, hit reactions, last-lap and lap-record events retain their
  original random draws and replacement/queue semantics.
- `434f20` crash selection runs synchronously from the original contact
  callbacks. The controller gate and 300ms deadline precede its random draws.
  The shared collision impulse is retained between original response calls.
- `48ca60` requests the corresponding character's `DISAPP` and `REAPP` at
  pre-update recovery frame 3. These are queued character samples, rather than
  substitutes played directly from the global sound table.
- Type 2 prop impacts call the placement's independent `PION_HIT_CAR` source
  after the three original launch random draws and before the new listener is
  calculated. These objects tumble without entering the solid-body registry.
- `42f9c0` tests hardwired Space after rendering and before bonus updates.
  Its available-character-index/roster-index mismatch is preserved, including
  a replacement request for the missing `CLAXON` symbol followed by `KT4`.
- Countdown, checkpoint and time-warning samples are dispatched at their
  original callback stages. They are not replayed from the resulting event
  list, which would duplicate requests or change their ordering.
- Homing-rocket warning arms queue their beeps from the original target body;
  their visual/controller integration and focused validation are recorded
  separately in the gameplay investigation.

`src/race-simulation.js` owns the deterministic requests and random calls.
`src/driving-view.js` connects these to the decoded transport, preserving the
old listener for scenery and the new listener for character FIFO service.

## Browser evidence

`tools/validate-race-sound-triggers.mjs` runs 26 controlled state fixtures through
the live `DrivingView` tick. It checks the actual decoded WebAudio source for
each of the five pickup effect names, all 15 firing levels, both recovery names,
a reactive prop clone, Space's `KT4` and all three homing-arm warning beeps.
The report records the source file,
decoded frame count, gain, loop state and queue request.

This is a trigger-composition test, not a control-only driven race, a recording
of speaker output or a comparison with Wine's broken race renderer. Fixture
weapons are retired between cases so that an unrelated hit cannot replace a
recovery voice being checked. Report:
`evidence/audio/race-trigger-playback.json`.

`tools/validate-voice-audio.mjs` separately checks 327 logical names across all
ten character banks and the effect bank, direct events, FIFO admission,
replacement, repeat suppression and nonzero rendered PCM. A symbolic name
absent from an original bank remains silent; `CLAXON`, `GOT_EURO`,
`GOT_BONUS` and certain hit names must not be replaced with plausible samples.

All 1,220 extracted WAVs and six music streams decode in Chromium; all 11
converted movies and six music streams start with decoded audio. Those asset
checks do not imply that every archived file is used by the shipped game.
Menu trigger and source-omission evidence is in `research-menu-audio.md`.
