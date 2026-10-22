# Original quit-screen timing

The race executable's STOPPEN requester is a blocking input and presentation
sequence. The browser port now preserves that sequence while continuing to
paint browser frames and keeping race simulation suspended.

## Original input and presentation

- `0042f290` waits for the Escape key that opened the requester to be released
  before drawing it. Until then the preceding race view stays visible.
- `00474040` checks J, N and Escape in that order, using the original Shift
  filtering. `004743b0` waits for the admitted key to be released. J returns
  code 0; N and Escape return 1. A held keyboard selection cannot be replaced
  by a subsequent pointer selection while this release loop is active.
- Mouse selection happens on a held left button, without waiting for release.
  The active Yes/No and duplicate RC rectangles resolve to the same visible
  buttons. Codes 0/2 mean Yes; 1/3/10000 mean No.
- `00473f20` calls `00473fb0` for the selected choice. It plays `click4.wav`
  once and draws pressed image slot 7 for Yes or 10 for No. It returns only
  after unsigned `GetTickCount` subtraction reaches 100 ms, including wrap
  across the 32-bit clock boundary.
- This quit path does not dispatch the P-key pause notification. Cancelling
  therefore preserves the existing captured HUD notice. Ordinary P/focus
  pause keeps its separate notification and release-gate behavior.

The source `SndGfx.ini` STOPPEN section supplies `esc_hi`, `ja_u/ja_f/ja_i`
and `nee_u/nee_f/nee_i`; the existing asset resolver and original placement
remain in use. The active file is the root `SndGfx.ini`, not the older
`ini/game.ini` requester. See the [asset audit](research-hud-notice-audit.md#countdown-finish-and-requester-assets).

## Browser integration

`NativeQuitRequester` owns the initial release, input, chosen-key release,
pressed and complete states. `createRaceQuitRequester` applies the original
pressed artwork and emits the sound and result once each. `main.js` supplies
the UI clock, and only passes a completed choice to the outer native race
pause gate. Raw keys cannot bypass the pressed-state delay. The race resumes
or exits on the first UI callback at or beyond 100 ms, so frame scheduling
may make the observed delay slightly longer.

Mouse uses pointer-down. Keyboard focus, Enter/Space and controller A remain
browser accessibility/controller adaptations that choose the focused button;
controller Back chooses No. They share the same sound, original pressed
artwork and delay. Repeated activations are ignored once a choice is admitted.

## Evidence and scope

`tools/native-quit-requester-fixtures.py` executes original `00473f20` and
`00473fb0`. It replaces only the input-choice return, OS clock and presentation
services, and records sound/draw arguments and return timing. Its 15 traces
contain 75 timed observations for all five accepted codes at three epochs,
including clock wrap. The existing `race-lifecycle-fixtures.json` separately
executes the real `00474040` keyboard priority and release loop.

The exact original binary hash is retained in
`evidence/native/quit-requester-fixtures.json`. Retained Ghidra exports and
assembly under `evidence/native/rcskspel.dat/` establish the loader, pointer
paths and outer pause flow. REA MCP's previously observed Ghidra configuration
blocker was not bypassed or represented as a new successful session. These
are bounded original-instruction and shipped-file comparisons, not a claim
of original Windows GPU observation.

Four focused requester tests cover the native traces, input release/priority,
DOM artwork, duplicate-input suppression and one-shot callbacks. The combined
[timing validation](../evidence/hud-timing/validation.json) records the focused
source tests and browser integration checks. No release build or full test
suite is part of this correction.
