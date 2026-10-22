# HUD notices and activation audit

This source-only audit compares the retained `rcskspel.dat` x86 assembly and
decompilation with the active shipped `overlay.ini`, `language.ini` and
`SndGfx.ini`. It does not claim an original-game rendering comparison under
Wine. `evidence/native/hud-notice-audit.json` records input hashes, direct
dispatcher callsites and all six tracks' relevant PMP callback slots. Recreate
that inventory with `python3 tools/audit-hud-notifications.py`.

## Dispatcher ledger

The original dispatcher is `0x430610`. The text controller uses the original
ALPHA atlas and `STRING_SPECIAL`; it does not use browser fonts. The language
numbers below are the original `Language.ini` keys, distinct from event IDs.

| Event ID | Native caller / target | Result and current status |
| --- | --- | --- |
| 0 | `420d90 → 430610 → 469670 → 464a00` | Starts the three countdown meshes. Already integrated with the authored camera/start action. No special text. |
| 1 | `42f9c0` on P, outside phases 3/6 | Interrupting `PAUZE`, language 6, style 0, indefinite. Already integrated. |
| 2 | `42f220` after the pause key-release loop | Stops/resumes special text through `4690e0`. Already integrated. |
| 3 | Dispatcher case exists; no direct caller in retained assembly | `Superbonus!`, language 25, style 1, 5 seconds. Supported by the isolated controller, but no pickup activation is invented. |
| 4 | `455b00`, call at `455cc0` | `Raak!`, language 23, style 1, 4 seconds. Player-owned projectile hitting an NPC. The call follows the NPC handler even when finished state 9 refuses the effect. Missing composition wiring corrected by `hud-gameplay-events.js` and the post-render aggregate event pass. |
| 5 | `440c30`, call at `440ce0` | `Laatste ronde!`, language 22, style 4, 5 seconds. Already integrated; precedes a possible best-lap notice. |
| 6 | `440c30`, call at `440cf8` | Language **17**, `Snelste ronde`, style 5, 5 seconds. The shipped dispatcher uses 17, not the similar unused language 24. Already integrated. |
| 7 | `420730`, call at `420772`, game-over mode 1 | `Tijd is om!`, language 28, style 3, indefinite. Post-render expiry notice, visible on the next HUD capture. Already integrated. Damage failure does not request this text. |
| 8 | `440dd0`, calls `440e25` / `440e38` | Statistics/lap-display hold via `469650 → 46f230`, not a text notice. Original retained-string timing restored; see below. |
| 9 | Player-only `4420f0`, call at `442100`; trigger table entry 54 | Junction-arrow activation via `469660 → 465840`. Owned by the separate arrow integration; no invented bonus text. |
| 10 | Dispatcher case exists; no direct caller in retained assembly | `Alle voorwerpen verzameld!`, language 26, style 1, 5 seconds. Do not infer this notice when the twelfth star is collected. |
| 11 | `4425f0`, call at `44262a`; legacy Time_Check marker 45 | `Controlepunt!`, language 31, style 1, 5 seconds. No marker 45 occurs in either PMP callback slot on any of the six shipped tracks. Explicit native events remain supported. |

The bounded negative findings concern the retained instruction inventory, not
every hypothetical modified game configuration. The direct language lookup
`443b40` is called by the HUD dispatcher, the CD error path and language-file
initialization. The retained active paths do not emit the additional language
strings `Schiet op!`, `Je ligt voor!`, `Je ligt achter!` or `GEFINISHT!` as new
HUD notices. Duel mode does not establish a missing lead/trailing text element
merely because those strings exist.

## Timed gates are not the legacy checkpoint notice

Markers 74/75/76 call `441e70`. That handler advances the time-gate index,
extends timer 18 and plays `CHECKPOINT`; it never calls `430610`. The previous
browser mapping from every `time-gate` to notice 11 was incorrect and has been
removed. The remaining-time number still updates from timer 18 through the
equivalent of `46f0b0 → 46f770`. `42f170` plays `TIME_TICK` below six whole
seconds when the integer changes; it does not request a `Schiet op!` message.

`RaceHud.processEvents` now uses the isolated event mapper. Earlier lap/record
events are handled before HUD advancement. Combat hits and expiry arrive after
the original render boundary, so their notices enter the live queue afterward
and are captured on the following native tick. Existing event-identity
deduplication prevents the aggregate pass from enqueuing lap events twice.

## Countdown, finish and requester assets

The `321Timer0Flare`, `321Timer1Flare` and `321Timer2Flare` sections are excluded
from the numbered original registries. `464760` resolves only `321Timer` plus
indices 0, 1 and 2 and stores three element pointers at offsets `0x0c..0x14`.
Activation, frame changes and slide helpers loop only over these three nodes.
There is no dynamic flare creation in that controller. The existing original
`321player` mesh frames and STARTSE1..4 sounds are the active presentation.

Finish action `41fc60` selects the source finish camera; `41fd90` enables the
checker flag after 1500 ms, then applies the original key/timeout gate. It does
not dispatch the legacy `GEFINISHT!` string. The source flag and result gate are
already integrated.

The active quit requester is loaded by `470860` from **root `SndGfx.ini`**, not
`ini/game.ini`. Its background is `esc_hi`; both RC and ordinary Yes slots use
`ja_u/ja_f` at `(150,350)`, and both No slots use `nee_u/nee_f` at `(425,350)`.
Every button image is 115×38. Although `473780/473d40` draw native image slots
0,1,3,5,8 and `474040` tests both button and RC rectangles, the active RC slots
are identical overlapping copies. The existing two-button browser requester
therefore does not omit visible character artwork or a distinct click region.
The `q_rcj_*` / `q_rcn_*` illustrations belong to the older `ini/game.ini`
STOPPEN section. The initial missing-illustration suspicion was withdrawn after
checking the actual loader and active file. The subsequent timing correction
preserves this active artwork and changes its input and pressed-state sequence.

<a id="separate-existing-timing-limitations"></a>

## Resolved timing differences

- Statistics event 8 stores `trunc(48f4d0 absolute engine seconds)` in `46f230`,
  only when lap count is positive. `46ecc0` retains the prior displayed lap
  string until current absolute seconds minus that integer stamp reaches 3;
  it clears the hold on that frame and updates the text on the next. The
  previous exact-completed-lap/3000-race-millisecond approximation is replaced
  by `NativeLapDisplay`. `RaceHud` receives the absolute simulation engine
  clock, including elapsed pause time, and deduplicates the same event across
  its pre- and post-render passes. See [lap-display research](research-lap-display.md)
  for 440 original callbacks, 88 initializations and six pause-clock resets.
- `473fb0` plays `click4.wav` and displays the pressed choice for 100 ms before
  returning. `NativeQuitRequester` now waits for the opening Escape release,
  then accepts mouse-down or waits for J/N/Escape release. Both routes play
  the click once and hold the original selected image for 100 ms before
  resuming or quitting. Opening this requester does not inject the P-key
  `PAUZE` notice. See [quit-requester research](research-quit-requester.md)
  for original input, clock and presentation evidence.

These source corrections have their own [validation record](../evidence/hud-timing/validation.json).
The earlier HUD inventory and browser reports remain historical checkpoints;
they are not evidence for these later timing changes.

## Focused validation

- `tests/hud-gameplay-events.test.mjs`: four tests passed, covering all player /
  NPC hit combinations (including finished victims), native lap/expiry order,
  explicit IDs and non-mapping of timed gates/pickups/rank changes.
- Existing `hud-notification-fixtures.json` retains 296 original-instruction
  queue/animation snapshots. This audit reused its evidence; it did not rerun
  that generator or the full suite.
- Existing countdown, lifecycle, glyph-layout and string-transform fixtures
  cover their isolated controllers. Fresh renderer/browser checks are reported
  by their respective owners, not claimed by this static audit.
