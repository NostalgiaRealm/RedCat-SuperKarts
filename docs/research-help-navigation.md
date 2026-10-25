# Original WinHelp navigation

Source follow-up, 23 October 2026. The supplied `data/RCSK.HLP` is unchanged:
SHA-256 `78bad04a5fbd761f5fd84c39ebb88978c00f7c13313cf38de8a9493f7de56f70`.

## What the original file actually contains

The fixed-width reader in `tools/lib/winhelp_navigation.py` follows the original
HLP directory, topic-record pointers, context tables, keyword B-tree and window
records. It supplements helpdeco's text/image extraction; it is deliberately
bounded to the shipped uncompressed version-33 file and rejects unsupported or
malformed records.

- There are 13 content topics, an empty terminal topic, 13 numeric contexts and
  13 keyword-index entries. Each keyword maps to its own named topic.
- All 14 topic headers store `0xffffffff` for both browse pointers. There is
  **no authored Next/Previous browse sequence**. Physical file order is not a
  substitute for one.
- All nine authored links jump within the current window. Eight use opcode
  `0xe7`, preserving their authored green, underlined font; four are bold.
  Racekeuze → Spelregels uses the ordinary styled-jump opcode `0xe3`.
- There are no popup links, external-file jumps, bitmap hotspots or file/topic
  macros. The second window and baggage WAV are defined, but nothing in the
  authored help records activates them. No `|VIOLA` topic-window map exists.

The old browse warnings do not identify missing source data: helpdeco's browse
reconstruction misinterprets the unsigned no-link sentinel. A separate LP64
bug explains misplaced keyword footnotes: `CollectKeywords` treats four-byte
`|KWDATA` entries as C `long*`, which is eight bytes on this host. The converter
now reads the keyword mappings directly, using unsigned 32-bit entries.

`prepare-help.py` cross-checks every recovered RTF title, numeric context,
contents target and link destination against the binary tables before writing
schema-2 `topics.json`. Guessed string aliases remain for compatibility, but
navigation uses verified numeric contexts and the original link hashes.
Original topic text, titles, 59 image placements and all 46 pixel-exact image
records are unchanged. Raw extraction warnings remain preserved for provenance.

## Game Help entry points

The menu's `00432848 → 0043271c` invokes `WinHelpA` with `HELP_CONTEXT`.
Retained original functions establish the following corrected paths:

| Caller | Original action |
| --- | --- |
| Main / settings / controls | Context 1 / 2 / 3 |
| Adventure player list / character selection / briefing | Context 5 / 6 / 7 |
| Quickrace character selection / race selection | Context 9 / 10 |
| Adventure / Quickrace results | Context 11 / 12 |
| Country information | Localized notice 46, without opening WinHelp |

The port previously used context 9 for both character-selection modes, fell
back to the main topic on result screens, and opened main Help from country
information. These paths now follow the original handlers. Existing direct
Highscores topic access retains context 4, although the original Highscores
form has no Help button. No game-specific contextual F1 action was established;
one was not added based on generic Delphi framework code alone.

## Browser navigation

The Help viewer now provides Contents, Back, the original keyword Index, and
visited-topic History. Back follows visits, independently of the absent browse
sequence. It restores the source link's focus and scroll position. The standard
navigation model is corroborated by Wine's independent WinHelp implementation:
[`MACRO_Back`, `MACRO_Contents`, `MACRO_History`](https://github.com/wine-mirror/wine/blob/master/programs/winhlp32/macro.c)
and [`WINHELP_RememberPage`](https://github.com/wine-mirror/wine/blob/master/programs/winhlp32/winhelp.c).
That reference establishes an implementation model, not an observed original
Windows session or identical history capacity/window chrome.

Opening Help retains the actual caller form and its in-memory draft. Closing
it restores that form, focus and scroll instead of reconstructing a menu,
losing unsaved settings, replaying an entrance or leaving a result screen.
Escape dismisses Index/History before closing Help; keyword input handles
Escape locally. Original link text and artwork remain in the converted topics.

Browser toolbar/panel layout, native Windows window-manager placement and the
original non-scrolling topic-header presentation remain host adaptations.
The original header-region positions are retained in the raw evidence, but
this change does not claim identical WinHelp window rendering. The file has
no authored popup behavior requiring an additional popup implementation.

## Focused verification

- `python3 -m unittest discover -s tests -p 'test_winhelp_navigation.py'`:
  13 tests, including direct original-file checks and malformed/truncated input.
- `node --test tests/help-navigation.test.mjs tests/native-help-context.test.mjs`:
  nine context/history/destination tests.
- `RCSK_URL=http://127.0.0.1:4184 node tests/help-navigation-browser.mjs`:
  ten focused Chromium/SwiftShader groups with zero page/network errors. These
  cover all topics/images/links, Contents/Back/Index/History, focus/scroll,
  original keyword mappings, unchanged Options/More settings/Controls drafts,
  actual Quickrace and Adventure menu contexts, notice 46 and portrait layout.

Result-screen context selection is unit-tested against native evidence; both
result topics are browser-tested through Index. No race completion was injected
to claim a new result-screen integration run. No full races, full test suite,
desktop builds or publication were performed.

Evidence: [raw HLP records](evidence/help-navigation-native.json),
[original menu handlers](evidence/help-context-native.json),
[conversion](evidence/help-validation.json),
[browser checks](../evidence/help-navigation/browser.json), and
[consolidated validation](../evidence/help-navigation/validation.json).
