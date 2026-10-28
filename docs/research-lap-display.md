# Original lap-time display hold

The native statistics controller has a persistent text element. Completing a
lap does not copy the completed lap measurement into that element. Event 8
only starts a hold of the string already displayed on the preceding overlay
update. This differs from retaining `event.timeMs` for exactly 3000 active-race
milliseconds.

## Source behavior and order

* Constructor `0046e680` sets the signed hold stamp at `+0x0c` to -1.
* Initializer `0046e6a0` resolves four statistics text elements and writes only
  STRING_LAPOF_VALUE. STRING_LAPTIME_VALUE has no initial Text field in the
  shipped overlay, so it remains empty until the first update.
* `00440dd0` emits event 8 after its guarded lap processing. The event reaches
  `00469650` → `0046f230`. If the resulting native lap count is positive,
  it stores `trunc(0048f4d0())` as a signed integer. The getter loads the
  absolute engine-clock float32 field. No text is assigned by this event.
* `0046ecc0` reads timer 0 and updates the lap-time string only if the hold
  stamp is -1. Otherwise it compares the current absolute engine time minus
  the integer stamp with 3. If the comparison reaches 3, it clears the stamp
  and leaves the element unchanged on that callback. The following callback
  reads and formats timer 0 again.
* Repeated native event 8 refreshes the stamp; lap count zero or negative
  leaves it untouched. The same branch is used in all four active modes.

For example, if the previous display was `00:39:95` and event 8 arrives at
engine time 100.975 seconds, the stamp is 100. The callback at 103 seconds
clears the stamp but still displays `00:39:95`; the next callback displays the
current new-lap timer. The hold is therefore approximately two to three
seconds, plus the callback that clears it, depending on the fractional event
time and sampling cadence. It is not a fixed three-second browser timeout.

The helper accepts a formatted current `lapText` and `nowSeconds`, and returns
the actual retained text. The renderer supplies timer 0's formatted value;
the helper never substitutes a completed-lap event measurement. The separate
existing HUD formatting fixtures cover `0046f5f0`/`0046f700`.

## Pause behavior

`0042f350` pauses timer 0 and other race timers, then blocks inside `0042f220`
for the P-key pause (or the quit requester). Ordinary overlay updates do not
run inside that blocking loop. On resume, `0048f520` resets the delta history
but refreshes the absolute engine clock from the current OS counter. It does
not subtract pause duration from that absolute time. Consequently a hold can
expire on the first resumed callback while the lap timer itself barely
advances; the next callback refreshes the string. Browser redraws while paused
must retain the captured text without calling the helper's update method.

## Evidence and scope

`tools/native-lap-display-fixtures.py` executes the original constructor,
initializer, complete statistics update, event handler, clock getter and x87
integer conversion. Generic CString, lookup/set-text, formatter, timer-0 and
pointer-assertion services are bounded. It records which actual element the
original initializer/update writes, rather than assuming a displayed value.
The evidence includes 88 initialized traces and 440 callbacks across all four
active modes and both 24-/53-bit x87 precision, with fractional clock edges,
repeated notifications, zero/negative lap counts, an event before the first
display, and a pause-shaped absolute-clock jump. Six additional executions of
the original reset `0048f520`, with only timeGetTime replaced, verify that
absolute time advances and delta history resets after a pause.

The exact original binary SHA-256 is recorded in
`evidence/native/lap-display-fixtures.json`. The retained Ghidra exports and
assembly are under `evidence/native/rcskspel.dat/`. REA MCP's previously observed
Ghidra configuration blocker remains unchanged; no new session or fabricated
Evidence ID was introduced. These are isolated instruction and source proofs,
not original Windows renderer observations.

Focused checks: `tests/native-lap-display.test.mjs` and
`tests/hud-text.test.mjs` pass nine tests. Browser integration and its actual
timer/capture inputs are verified separately. No full suite or release build
is part of this change.

## Results phase

`00440d70` pauses timer 0 immediately after `00440c30` restarted it on the
final lap, so after the hold the lap-time string shows the paused, roughly
zero timer for the rest of phase 3. The port pauses its timer-0 bank entry at
the `finished` event and the HUD reads that timer instead of the running
race timer.

The original game pause `0042f350` pauses timers 0, 3, 8 and 9–27 with
`0042a2f0` (which skips already paused timers) and resumes them all with
`0042a420`, which also ends a pause set earlier, such as the finish pause.
That cannot happen during the results phase: `0042f9c0` only opens the P
pause outside phases 3 and 6 and the Escape requester outside phases 1, 3
and 6, so the lap time stays frozen until the race ends. The port applies
the same phase gate to P and Escape. Its own host suspensions (focus loss,
menus) have no native counterpart; they now pause only running timers and
resume exactly those, so a focus loss during the results no longer restarts
the lap timer. The exact formatted text for a zero timer on an original
Windows machine has not been observed. Focused check: `tests/race-hud-order.test.mjs` (2026-10-28).
