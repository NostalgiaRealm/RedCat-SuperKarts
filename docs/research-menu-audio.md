# Original menu sound dispatch

## Adventure speech and menu flow follow-up — 25 October 2026

The Adventure briefing previously displayed its text but never requested its
recording. Original phase initializer `004783b8`, lookup `004784b5..004784d1`
and byte table `0047c5a4` select generic sample `56 + country * 4 + eventType`
for the four offered event types. All 24 original WAVs already exist in the
prepared assets. Difficulty changes the briefing text, not its recording.
There is no FIRSTTIME condition: each actual briefing entry plays its sample
asynchronously. The unused fifth event aliases the country's normal-race
sample; this does not add a playable mode.

Original accept handler `004786a4` calls `0045c7c0` →
`sndPlaySoundA(NULL,0)` before race setup, optional start information and
closing the form. The port now follows that order, so starting a race can
interrupt the briefing instead of waiting for the whole recording.

The wider direct-call audit found and corrected these additional differences:

| Trigger | Original evidence | Correction |
| --- | --- | --- |
| Main Options | `0045d038`, `00474aa4` | Common generic46 and character23 wait, then Main's own generic46 async |
| Delete Adventure profile | `00475fec..0047601f` | Selected character26 before confirmation |
| Confirm Quit | Shell shutdown `00479242..0047925a` | Wait for selected character27 farewell before closing |
| Browse Adventure profiles | `00475ab4 → 00475d6c → 0045792c` | Update active saved-profile fields so Help/Quit use the selected character |
| Cancel Quit, delete or name entry; dismiss full-slot notice | Original modal requester/name handlers | Restore caller controls and focus without a new greeting |
| Landinfo Overview | `00478df6` | Generic46 before country introduction |
| Landinfo OK | `00477aa8`, modal caller `00478e39` | Stop narration and restore the existing briefing without replaying it |
| Landinfo Help notice | `00477a60` | Return to the same Landinfo controls without restarting the country introduction |
| Back from Adventure character selection | `00473cdc`, `trans.dat` | Return to Adventure profile list, keeping the new save |
| Adventure character entrance | `004742d4` and its Adventure branch | Generic53 without consuming Quickrace's FIRSTTIME flag |

The audit inventories 65 direct calls to the original generic, character and
stop wrappers. Profile arrows are intentionally silent. Settings generic8
and Highscore generic41 have no active callsite or authored FormShow handler;
their presence in the sound bank is not a reason to invent a greeting.
The five previously documented missing source samples remain source omissions.

Evidence: [menu callsite/flow audit](evidence/menu-flow-sound-audit.json),
[original briefing instruction probe](../tools/native-adventure-briefing-audio-fixtures.py)
and [72 selections plus four accept paths](../evidence/native/adventure-briefing-audio-fixtures.json).
REA reported Ghidra unconfigured on this host; retained original disassembly
and isolated execution of the unchanged original instruction bytes supply the
native evidence. This is not a live Windows menu/audio capture.

The independent menu asset audit checked all 403 configured sample entries:
398 supplied WAVs have valid PCM frames and match the original bytes. The
65 wrapper calls, including their dynamic country/type/character tables,
select 315 configured references: 311 are supplied, and four are known
source omissions. The fifth missing configured sample, generic49, has no
active callsite in this audit. All five original sound-bank configurations
match the prepared configuration. See
[menu assets](../evidence/audio/menu-flow/assets.json).

The existing browser Escape exit from the read-only start-information screen
is a host adaptation. The original starts the race after its modal information
form returns; no native Cancel branch is established. Likewise, Landinfo's
browser Escape exit is not claimed as an authored native key binding.

Focused source checks passed: 72 original briefing lookups and four accept
sequences, five JavaScript tests over the briefing/dispatch/greeting fixtures,
all 24 briefing recordings through actual profile UI, 12 menu-flow browser
groups and the existing 57 menu-playback cases. The existing profile-bank
browser check also passed three groups after its obsolete Adventure Back
expectation was corrected. The browser uses accelerated WAV playback for
testing, with the farewell at normal speed to inspect its wait. One Netherlands
race opening verifies the menu channel is quiet after entry; no full race,
full suite, build or publication was run.

Reports: [flow/playback](../evidence/audio/menu-flow/browser.json),
[existing playback regression](../evidence/audio/menu-playback.json) and
[final source validation](../evidence/audio/menu-flow/validation.json).

## Earlier dispatch and playback checks

The menu uses its own `sndPlaySoundA` channel. Generic wrappers `45c668` and
`45c720` read `ini/soundset.dat`; character wrappers `45c518` and `45c5cc` read
the selected character's original sample bank. Flags2 wait for completion;
flags3 play asynchronously. A new sound replaces the previous menu sound.
This is separate from the race's positional voice queues.

The playback audit found and corrected these disconnected or wrong dispatches:

| Original handler | Trigger | Original sample | Port |
|---|---|---|---|
| `474234/474268` | Next/previous character | Generic47/48, then character0 | Correct direction-specific sound and character name |
| `46fd98/46fdc4`, `46fcc4` | Next/previous country | Generic47/48, then character4–9 or locked67–72 | Correct direction-specific sound and country announcement |
| `46fefc/46ff20/46ff44` | Select country/time/star race | Character10/11/12 | Connected all three announcements for all four characters |
| `477284/4772b0` | Next/previous highscore country | Generic47/48 | Connected both navigation sounds |
| `477d80` | Open country information | Generic80/85/90/95/100/105 | Connected all six country introductions |
| `477d30/477d44/477d58/477d6c` | Click one of four country photographs | The four samples following that country's introduction | Connected all24 original narrations; photos also support keyboard/controller activation |
| `4620ec`, `461958` | Begin binding capture, release a key | Generic50,51; invalid key additionally110 | Restored dispatch and original key-release timing |

`461958` accepts A–Z, Enter, Shift/Ctrl/Alt and virtual keys32–40.
Escape cancels; other keys leave capture active and play sample110. The
original keyboard dialog had no digit or function-key binding path. Existing
saved browser bindings are not rewritten by opening the dialog.

`tools/native-menu-audio-fixtures.py` executes the original menu instructions
up to their sound wrappers:32 navigation cases,12 race-mode announcements,
30 country-information cases and256 key classifications. The fixture records
the original menu binary digest. UI/string/sound-device boundaries are explicit;
this is not a native menu listening session. All330 cases match
`source/menu-sound-events.js`.

`tests/menu-audio-browser.mjs` follows actual menu controls and records real
HTML media `playing` events with decoded duration and ready state. Its57
checks include all four character race-mode banks, both navigation directions,
all30 country narrations and the rejected-key sample. Playback runs at8x
solely to shorten this validation; normal game playback remains unchanged.
Report: `evidence/audio/menu-playback.json`, zero browser/resource errors.

The supplied installation and CD are both missing generic samples17,18,49,50
and51 (`mn_in10.wav`, `mn_in11.wav`, `mn_s006.wav`, `mn_s007.wav`,
`mn_s008.wav`). These are source omissions, not replaced recordings.
Generic13/14 belong to the original software/hardware rendering selector; the
browser manages the rendering device and that selector is unavailable.

`tools/validate-audio-assets.mjs` separately checks every extracted audio
lookup through the browser decoder. All1,220 WAVs and six music streams decode
to finite PCM with positive frame counts. `werk01.wav` and `werk02.wav` contain
entirely silent decoded samples. Report: `evidence/audio/all-assets-decode.json`.
Decoder success does not prove that a gameplay trigger is connected or that
every archived recording is referenced by the shipped game.

`tools/validate-media-audio.mjs` starts all11 converted movies and all six
original music streams in Chromium. Every item advances playback with positive
decoded audio bytes and no mute flag. `evidence/audio/media-playback.json`
records all17 results. This confirms media playback startup, separately from
the original reward-eligibility checks and complete movie frame validation.
