# Motor starter timing

The original starter begins after the authored opening camera pan, at the
start of the 3–2–1 sequence. It does not begin while the race assets load and
does not wait for the green light.

## Original evidence

The inspected `rcskspel.dat` has SHA-256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
The original files were not modified.

- Camera completion `443ef0` registers action 1 with START `420d90`, UPDATE
  `420dc0`, and STOP/green `420f00`.
- START `420d90` sets the action flag when applicable, loads the global
  CarSound object `53bd98`, and calls `418950` at instruction `420da8`.
  It then calls `430610(0)` to start the countdown overlay.
- CarSound START `418950` selects its starter sample, plays it once through
  `49d780(0)`, and sets the active field at object offset `+4`.
- CarSound update `418c80` emits nothing while that field is zero. Once
  active, it waits for the starter sample to finish before starting its three
  concurrent engine loops. The shipped `Car_Snd.ini` starter is `cmstartm`.
- The game-action service runs after authored paths, rendering and bonuses;
  the pan completion and countdown START occur at this same action boundary.

Fresh REA/Ghidra evidence is saved in
`evidence/native/rea-engine-starter.json` and
`evidence/native/rea-engine-start-call.json`. The direct call is decoded from
the original bytes even though fresh automatic analysis does not recover the
indirect callback's `420d90` function boundary. That bounded analysis failure
is retained in `rea-engine-start-gate.json`; the recovered earlier export,
disassembly and executable instruction fixture establish the complete action.

`tools/native-engine-start-fixtures.py` executes original `420d90` and
`418950` instructions, capturing only the sound-output and overlay service
boundaries. Six cases cover both x87 precisions and all relevant prior action
flag branches. Twenty-four original inactive `418c80` updates remain silent.
The captured action always plays the starter before starting the overlay.
This fixture verifies the action boundary, not the camera's duration; the
separate authored-camera fixtures establish that behavior.

## Port correction

Race loading preloads the samples with `prepareEngine()` and leaves CarSound
inactive. `RaceSimulation` invokes `onEngineStart` exactly once when the
opening pan completes and `countdownStarted` becomes true. `DrivingView`
connects that callback to the original starter helper. The explicit research
view, which skips the opening sequence, continues to start its motor directly.

The source helper already had the correct inactive and starter-playing gates.
The defect was its premature invocation by `DrivingView.load`. The previous
QuickRace browser assertion incorrectly expected an active engine during the
pan and has been corrected.

`tests/engine-audio.test.mjs` verifies the new original action fixtures plus
the existing 360 engine updates, volume conversions and source sample rates.
`tests/engine-start-browser.mjs` observes actual WebAudio source creation
through the normal menu flow, checking silence during loading and the pan,
one starter at countdown START, and three loops after its PCM ends. Its
report is `evidence/audio/browser-engine-start.json`. This is a browser
integration check backed by original instructions, not a Wine race-rendering
or recorded speaker-output comparison.
