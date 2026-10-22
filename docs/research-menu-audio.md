# Original menu sound dispatch

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
`src/menu-sound-events.js`.

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
