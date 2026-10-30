# Original-code decompilation and port comparison

Date: 26 October 2026. This document records the requested source-only
decompilation and comparison. It is separate from the release changelog and
from historical validation checkpoints. The later
[28 October comparison](original-comparison-2026-10-28.md) records ten further
corrections, released in 1.0.1.

## Reading the original-code reference

The [original-source folder](../original-source/README.md) contains reconstructed
C-like code, assembly, function indexes and provenance for the five shipped
game runtime modules: `RCSK.exe`, `rcskmenu.dat`, `rcskspel.dat`, `RCMovie.dat`
and `SMACKW32.DLL`. Decompiled output is **not the developer's exact original
source**: names, types and control structures can be inferred, and the output
is not presented as a compilable original project. Assembly and input hashes
remain available to check an inference against the actual bytes.

The export contains **10,354 identified functions**, all with C-like output,
across all five modules. The independent verifier checks **422,295 decoded
instructions** against the original bytes. It records 1,205 functions with
decompiler warnings, 26,525 decoded bytes outside identified functions and
290,596 executable-section bytes without decoded instructions. Those last
two measures include embedded data, alignment and uncertain function boundaries;
they are not counts of missing game features.

[original-port-index.json](evidence/original-port-index.json) links explicit
native addresses in current port comments to candidate recovered functions.
Use `python3 tools/index-original-port.py` to refresh it. Multiple executable
modules can share an address, so ambiguity is retained; a reference is a
navigation aid, not proof of behavioral equivalence.

The installed and CD copies of all five modules were compared byte for byte.
Both original trees remain unchanged. CD installers, old hardware drivers and
third-party support installers are inventoried separately; they are not game
logic and are not substituted for the five runtime modules.

The folder's verification report describes identified-function coverage,
failed decompilations, instruction ranges outside functions and executable
bytes that have not been classified as instructions. Executable sections also
contain data and alignment. Neither counting every identified function nor
decoding all section bytes would prove recovery of every possible runtime path.

## Intentional differences retained

The comparison preserves the user's previous instructions:

- Browser and Electron hosting on Linux, Windows and macOS; browser storage,
  asset conversion and platform-owned device selection replace Win32 services.
- Unlocked rendering, measured native update admission, interpolation,
  widescreen/portrait layouts, safe areas, scaling and modern input support.
- The requested steering wheel, reverse/acceleration touch zones, separate
  Alt-equivalent pedal and small paw/bolt power-up button.
- **Meer instellingen**, selectable MSAA, free flight, unlock-all control,
  version display and modern display options.
- Authorized stuck detection and safe return positions when strict original
  behavior could prevent a race from finishing.
- Original movie aspect ratios; immediate playback with muted fallback,
  **Geluid inschakelen** at bottom left and fullscreen on its activation.
- Host focus/visibility audio suspension and cleared controls; existing
  browser Back/Escape shortcuts and accessible controls.

Undefined native storage and historical GPU/device behavior retain the
documented policies in the existing research. These are explicit limits,
not evidence that a guessed replacement is original behavior. Original
inactive paths and missing original recordings are not invented features.

## Confirmed corrections

| Area | Original evidence | Difference and correction |
| --- | --- | --- |
| Character selection | Menu `004742d4`, widget field `+2e8` | The browser had no entry focus. It now focuses OK/Verder as the native FormShow does. |
| Country selection | Menu `0047004c`, widget field `+2f0` | Enter now acts on the original focused OK button immediately after entering this screen. |
| Adventure profiles | Menu `004762ec`, enabled check and focus on `+2e8` | Continue receives focus for an occupied profile; the disabled button is not focused for an empty bank. |
| Adventure briefing | Published Delphi method `00479074`, exact instruction bytes and VMT field metadata | Start/OK receives the original entry focus. Existing focus is retained during a same-form selection redraw. |
| Name entry | Menu `00470600`, `edtNameKeyUp` | Holding Enter no longer submits on key-down. Enter and keypad Enter accept on release, preserving the original empty-name return behavior and preventing duplicate creation. |
| Player bonus/turbo order | Race player callback `004325b0`, wheel/input dispatch and keyboard/analog handlers | Bonus firing moves into the original input point between wheel updates. A newly fired turbo affects the second wheel pass, rather than both; animation state observes the resulting turbo timestamp. |
| Engine sound sample order | Race call site `00432ab5` | Engine audio samples player state before ranking and track-trigger callbacks, so a jump does not prematurely change the sound sample in the same update. |
| Pause/quit audio | Race `0042f350`, `0042f220`, `0042f290` | Original P/Escape pauses freeze movement/timers while current sounds continue. Browser focus loss, including while a native dialog is open, still suspends audio. |
| Music completion | `00430020` → `0048ef80`, and the final poll in `0042f350` | Automatic HTML looping is replaced with completion polling at the native update point. Music that ends during a blocking pause waits until resumption. |

Integration review also closed a host safeguard edge case: if browser focus
is lost while a native pause dismissal is waiting for key release or its
pressed-button delay, completing that dismissal leaves the game paused.
The existing deliberate resume gesture restores it. Quit confirmation still
exits normally. This preserves the intentional focus-loss behavior.

Detailed gameplay and presentation evidence, corrected source paths and test
boundaries are recorded in [gameplay comparison](full-source-audit-gameplay.md)
and [presentation/audio comparison](full-source-audit-presentation.md).

## Menu investigation and validation

`tools/native-menu-entry-fixtures.py` executes the original byte sequences
for seven menu FormShow handlers and the name-entry key-release handler.
The 56 focus traces cover first/return visits, QuickRace/Adventure and
enabled/disabled profile acceptance. Fifteen name-entry traces cover zero,
one and twenty characters and Return, Escape, Space, letter and function keys.
Widgets, stored phase/FIRSTTIME reads, string services and speech are explicit
boundary stubs; this is instruction execution, not a native Windows UI session.
The record is [menu-entry-native.json](../evidence/full-source-audit/menu-entry-native.json).

A fresh REA/Ghidra 12.1.4 dossier independently records the character FormShow
with Evidence ID
`ev_7d6af4840a93e373e1355629ed1e54984a5b5ce515ab77bfaf979ad32c550b62`.
It is saved in [rea-character-form.json](../evidence/full-source-audit/rea-character-form.json).
REA's connected MCP provider lacked its Ghidra environment variable; the
installed version-pinned CLI was run with the existing Ghidra path for this
command, without changing global configuration or installing another engine.

`tests/menu-entry-browser.mjs` passes eight focused source-browser groups with
zero page/HTTP errors. It compares focus with the instruction fixtures,
checks held and released Return/keypad Return, an empty name, repeated key-down,
profile counts, same-form focus retention and keyboard-only progression through
QuickRace's character/country/start-information screens. Audio is accelerated
for the harness. No race outcome is injected or full race driven by this test.
See [browser results](../evidence/full-source-audit/menu-entry-browser.json).

The original country-label table at `0047bc98` was also checked against menu
consumers `0046f84c`/`004783b8`: the unusual spelling **Groot-Brittanië** is
actually shipped text and is deliberately retained. The separate enum/highscore
table uses **ENGELAND**. The review also traced debrief/highscore/profile save
ordering, reward selection, original form event tables, name limits, and the
existing settings/Help caller restoration; no additional change was justified
by those bounded comparisons.

## What this does and does not establish

The [consolidated verification record](../evidence/full-source-audit/validation.json)
records the final source hashes and links all reports. This pass completed
98 original-instruction traces, 47 focused Node tests and 17 Chromium
source-browser check groups. All twelve route/drive data sets match their
originals. The decompilation has its own independent byte and export checks.

The new decompilation makes the recovered original code available locally and
provides a reproducible basis for further comparisons. The corrections above
are confirmed differences found by this pass. The subsystem reports distinguish
reviewed unchanged paths, original no-ops, host adaptations and uncertainty.
They do **not** prove that every possible original execution and every port
execution are equivalent.

A trustworthy running original Windows race is still needed for whole-race
trajectories, audio, camera and framebuffer comparisons. WineD3D cannot supply
that baseline here. Original hardware filtering/dithering and x87 device state,
physical mobile/controller behavior and Windows/macOS gameplay remain outside
these checks. The historical full-race matrix and controlled Adventure result
transitions are not relabeled as fresh validation of the changed source.

Only checks related to the changes and the decompilation deliverable are run.
No full test suite, desktop build, version bump, commit, push or release is part
of this source comparison. Previously completed intro/autoplay/fullscreen
changes remain in the working tree and are listed separately in their existing
validation record.
