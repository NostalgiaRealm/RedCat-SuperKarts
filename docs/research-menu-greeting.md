# Initial menu greeting

The initial greeting is selected by the original saved `FIRSTTIME/PHASE_MAIN`
value, not by the menu random-number generator. The supplied CD files and
installed game both contain `PHASE_MAIN=0`. Their main menu therefore plays
generic sample **1**, `Mn_HM02.wav`. Generic sample **0**, `Mn_HM01.wav`, is used
when that value is nonzero, or the setting is missing and defaults to 1.

The browser previously used only the presence of a browser storage key. A fresh
profile consequently selected sample 0 even though the original input settings
selected sample 1. `nativeMenuFirstTime` now initializes from the extracted
settings. A completed visit is retained in browser storage and in a session set,
and later visits select the original repeat greeting. The same native helper
also applies to character selection, country selection and adventure entry.
The original files remain unchanged.

## Native evidence

The source is `rcskmenu.dat`, SHA-256
`1b6872290010d6357db1b63d6691498b52f8d3def0083e5b42e816a2b7366733`.

| Address | Behavior |
|---|---|
| `00474b00` | Main FormShow calls the FIRSTTIME helper, selects generic 0 when AL is nonzero and generic 1 otherwise, then restores focus. |
| `0045d4a0` | Reads `FIRSTTIME/<form phase>` with integer default 1, stores its low byte, writes integer 0, and returns the saved byte. |
| `0044f4e8` / `0044f5ac` | INI integer read/write boundaries used by the helper. |
| `0045c720` | Generic sample playback boundary. |
| `00402b74` / `0047d044` | Delphi random function/state; the greeting branch does not call it or alter the state. |

Neither main FormShow nor the FIRSTTIME helper has an intro-completion or
intro-skip branch. The transition into main uses the same stored flag in both
cases. An orientation redraw is not a new form entry.

The CD and installed `ini/settings.ini` files have the same SHA-256:
`c01980d7c71e6a11e42cdb44c57274eaa97dcd836a2aab22b1b59aad86919821`.
Both contain zero for all four relevant FIRSTTIME entries.

REA/Ghidra byte observations are retained independently of the prior recovered
decompilation:

- `evidence/native/rea-menu-greeting-bytes.json`, complete 52-byte range at
  `00474b00`, evidence
  `ev_1c55bc8a6386a3ab58e05512fa3f180fc095d0f6d26619d2f1d393f6174a3b13`.
- `evidence/native/rea-menu-firsttime-bytes.json`, complete 262-byte range at
  `0045d4a0`, evidence
  `ev_6b910dc4ebb894dd3c6b22643cfa93d8ed756c4580de41ee4c2c223abf741876`.

REA's fresh default analysis did not define the Delphi main FormShow procedure,
so its function request failed; the retained `rea-menu-greeting.json`/log records
that limitation. The successful REA observations are byte reads, not a claim
that REA independently recovered the whole procedure. Existing recovered
Ghidra functions and bounded original-instruction execution establish the flow.

## Validation

`tools/native-menu-greeting-fixtures.py` executes original `474b00/45d4a0`
instructions in Unicorn. INI access, Delphi string/path housekeeping,
allocation, playback and focus are explicit boundary stubs. The fixture covers
60 main entries across four random seeds, missing/zero/nonzero values, low-byte
behavior and three visits; all retain the original RNG state. Another 18
cases exercise the shared helper for the other three forms. This is not a
full shell emulation or a claim to reproduce arbitrary INI text parsing.

`tests/menu-greeting.test.mjs` checks these 78 cases and the real extracted
sample mapping. `tests/menu-greeting-browser.mjs` records actual decoded WAV
`playing` events for ten checks: fresh profile, return from options,
orientation redraw, reload, intro click skip, intro end, and controlled
FIRSTTIME=1/missing configurations before and after reload. All ten pass with
no page or HTTP errors in `evidence/audio/menu-greeting-playback.json`.
Playback is accelerated to 8x for the check; this is browser playback evidence,
not a native sound-card recording.

The first browser harness attempt targeted an obsolete hidden skip button.
That failure is retained separately in
`evidence/audio/menu-greeting-playback-initial-harness-failure.json`. The harness
now clicks the playing movie, the actual user interaction, with no game change
for that harness error.

The wider `tests/menu-audio-browser.mjs` regression also passes all 57 expected
menu recordings with no page or HTTP errors; its refreshed report is
`evidence/audio/menu-playback.json`.
