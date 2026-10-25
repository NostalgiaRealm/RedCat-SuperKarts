# Menu transactions, original controls and advanced display settings

This audit compares the active original `rcskmenu.dat` handlers with the current
port. It does not treat older research TODOs or unused menu samples as current
defects. Original installation/CD files remain unchanged.

Original menu SHA-256:
`1b6872290010d6357db1b63d6691498b52f8d3def0083e5b42e816a2b7366733`.
The retained Ghidra exports under `evidence/native/rcskmenu.dat/functions/`,
the parsed Delphi forms, and original-instruction Unicorn fixtures are the
authority. The advanced initialization/commit exports `46a350`/`46a5a0` were
recovered in the existing isolated Ghidra project during this audit.

## Corrected active behavior

| Trigger | Original evidence | Previous port deviation | Implemented behavior |
|---|---|---|---|
| Options sliders/radios, then Back | `46b7f0`, `46b80c`, `46b400`, `46b488` | Changes were saved immediately | Form draft; only OK commits the native options |
| Options Stop, then No | `46b388` | Returned to main, losing the current dialog | Returns to Options with the same draft |
| Configure keyboard, then Cancel | `461904`, `4618d0`, `458c44`, `458d6c` | Changed bindings survived Cancel | OK saves; Cancel restores the saved bindings |
| Start key capture | `4620ec` | Retained the old key and displayed an ellipsis | Clears the selected native key to zero, uses pressed original key artwork, disables OK |
| Assign a duplicate key | `461958`, `458eb4` | Warning lost the active capture | Checks all six slots; warning preserves capture and disabled OK |
| Invalid key / Escape | `461958` | Different capture completion behavior | Invalid key stays in capture; Escape ends capture without restoring the cleared key |
| Defaults | `4620b8`, `458ed0` | Immediately persisted | Changes only the control draft; Cancel still restores the saved bindings |
| Key images and captions | `461b44`, `461d74`, `461e74` | Generic keycaps and Unicode arrows | Original `pijl0000..3`, `toetskl0/toetskld`, `toetsgr0/toetsgrd`; source labels and lowercase assigned letters |
| Start information | `4616f0`, `461858`, `461904` | “Start” and inverse preference wording | Original “OK”, positive “Startinfoscherm weergeven”, positive checked state |
| Start information with gamepad/joystick | `46fdf0`, `4786a4` | Showed keyboard instructions for every control type | Both race-entry paths show it only for keyboard and an enabled start-info preference |
| Nonkeyboard Controls button | `46b554`, `46b5d8`, `46b65c` | Opened unrelated browser settings | Disabled for original joystick/gamepad selection, enabled for keyboard |
| Main menu first Enter | `474b00`, form field `+2e0` | No explicit original focus | Focuses Adventure, so first Enter activates it |
| Keyboard Tab/directional navigation | DFM `TabOrder`, `441980`, `4458dc` | Used serialized DOM order, putting Help before Options and OK before Default | Uses original parent-local tab lists, retaining focus on same-form redraw |
| Geavanceerd | `46bad8`, `46a350`, `46a5a0` | Replaced the original dialog with modern settings | Original `TFRMDISPLAYSETTINGS`, original tabs/captions and active display controls |

The original Escape result is unusual but deliberate: after entering capture,
Escape leaves that action unbound. An explicit empty binding now survives
normalization/storage. Opening or cancelling the dialog does not rewrite saved
bindings. The control dialog saves independently of Options, as the native
nested `46b828` call does.

`showSettings`, `showControlSettings`, the source start-info predicate and input
capture in `src/main.js` use the pure `src/native-control-settings.js` model.
At this audit's original checkpoint, browser settings had an additional entry
inside the restored display dialog. The later requested
[Meer instellingen change](more-settings.md) supersedes that placement: the
button is now on the main **Instellingen** page, below music and sound effects.
The original **Geavanceerd** dialog remains separate.

## Original advanced display dialog

`46bad8` creates `TfrmDisplaySettings` (VMT `469a64`), copies the extended
configuration using `45ba6c`, runs it modally, then copies those extended fields
back. `46a87c` Cancel closes without changing that copy. `46a8a0` OK calls
`46a5a0` before closing. Thus display OK is independent of outer Options Back.
`46a884` selects the first, **Algemeen**, tab even though the design-time DFM
names Problemen as its active page.

`src/native-display-settings.js` reads the original form's captions, grouping,
dimensions and control positions. These were ordinary Windows widgets, not
missing custom button art. Its HTML widgets are a platform adaptation; it does
not claim pixel-identical Windows control drawing. The original hidden
resolution group remains hidden. Portrait reflow orders the original labels
and controls by their authored vertical positions.

| Persisted positive browser setting | Native control meaning | Original stored field / write |
|---|---|---|
| `display.brightnessLight` | Light selected, Dark not selected | `+30`: Light 0, Dark 1 → `GFX_OPTIONS/GAMMA` |
| `display.bilinearFiltering` | “Bilineaire filtering uit” unchecked | `+34`: inverse checkbox → `game.ini OPTIONS/FILTER`, multiplied by 2 |
| `display.alphaBlending` | “Transparante effecten uit” unchecked | `+38`: unchecked 2, checked 0 → `GFX_OPTIONS/ALPHA_BLENDING` |
| `display.particles` | “Minder speciale effecten” unchecked | `+41`: checkbox → `GFX_OPTIONS/PARTICLES`, inverted |

All four defaults are true, matching the extracted active configuration:
gamma 0, filter 2, alpha blending 2, particles 1. Original save instructions
`45b4b1..45b4ca` and `45b53f..45b58c` establish the file-key mappings; the retained
decompiler's `45b334` output ends early at a nested exception-handler boundary,
so that tail is also checked against disassembly.

The runtime mapping lives separately in
`src/simulation/native-display-settings.js`; the root renderer applies gamma
before sampling, including keyed textures and the original HUD font atlases.
These are specific original settings, not a blanket shader opacity switch.
The runtime/controller gates and pixel checks are documented by the renderer
audit.

The original driver selection, system-memory rendering and VBlank controls
remain visible and unavailable with explanations: the browser chooses the GPU,
manages render storage and schedules display presentation. The port does not
save changes to controls that cannot take effect. The former
**Browserinstellingen** entry has been moved and renamed **Meer instellingen**
as requested. That page contains resolution/render scale, controller deadzone,
touch, fullscreen and the added MSAA and cheat controls. Its **OK** returns a
nested draft to the main settings page; the main **OK** saves it. **Terug** or
Escape cancels the corresponding draft. The explicit **Alles ontgrendelen**
action saves immediately. See [the current controls and evidence](more-settings.md).

## Validation and limits

Before the fix, the bounded browser reproduction saved
`evidence/ui/menu-state-audit-before.json`: Options Back persisted effects25%,
Controls Cancel persisted a changed key, and returning from the duplicate
warning did not preserve capture.

`tools/native-menu-settings-fixtures.py` generates
`evidence/native/menu-settings-fixtures.json`: **216 original instruction
cases** (90 capture traces, 12 control commit/cancel, 96 key-art selections,
6 Options commit/cancel, 12 QuickRace/Adventure start-info gates).
`tools/native-display-dialog-fixtures.py` generates
`evidence/native/display-dialog-fixtures.json`: **48 original display
initialization/cancel/commit cases**. Native state arithmetic executes from the
original binary; window widgets, INI persistence, driver enumeration and sound
device operations are explicit test boundaries.

`tests/native-control-settings.test.mjs` and
`tests/native-display-dialog.test.mjs` compare the pure port helpers with those
264 instruction cases. `tests/menu-settings-browser.mjs` passes **33 checks**
with zero browser/resource errors, covering actual browser
buttons, drafts, storage/reload, source artwork, native focus, tabs and portrait
reflow. Its report is `evidence/ui/menu-settings-browser.json`; screenshots are
`start-info-corrected.png`, `display-settings-problems.png` and
`display-settings-portrait.png` in the same folder. Nonkeyboard start-info
checks end at the real loading handoff; they are not full-race tests.

The separate menu-audio browser regression still passes all **57** expected
original WAV starts with zero browser/resource errors, reported in
`evidence/audio/menu-playback.json`. Its initial post-OK assertion ran before
the original press sound's awaited completion; the harness now waits for the
Options form. That initial harness failure is retained in
`evidence/ui/menu-audio-initial-transaction-wait.json`.

Native race-start screenshot `evidence/native/runtime/race-start-screen.png`
also confirms the positive checkbox text and OK caption. This audit does not
claim a fresh original Windows interaction session for every settings control.
Native window-close semantics are not equated with browser Back/Escape
navigation, and modern automatic input-device support remains a platform
adaptation.

## Native keyboard traversal

Original `TWinControl` construction stores `-1` for the omitted order at
`4417fb`. `44246c` appends child controls to the parent's list. `441980` builds
a separate table of explicitly authored target indices and calls `4458dc` in
ascending target order to move those entries. `4458b8` obtains the actual
current list index. The native RTTI for `TabOrder` points to getter `4458b8`
and setter `445938`; the latter stores the target while the form is loading.

Omitted container orders therefore cannot be treated as zero. The source
`TTransparentControl` ancestor chain is `TCustomTransparentControl`,
`TCustomControl`, `TWinControl`; its unexposed order preserves insertion order.
`src/native-tab-order.js` reconstructs this algorithm per parent, then flattens
its children for the browser. Explicit `TabStop=false` is excluded. Added
keyboard accessibility for source clickable images remains after the authored
controls rather than changing their relative order.

`tools/native-tab-order-fixtures.py` executes `441980` and `4458dc` for
**29 original sibling lists** from the shipped forms, with explicit TList
container boundaries. `evidence/native/tab-order-fixtures.json` stores the
original binary digest and all expected orders. All lists match
`tests/native-tab-order.test.mjs`. The provisional default-zero implementation
failed two assertions and was corrected before the final build; it was not
treated as completed evidence.
