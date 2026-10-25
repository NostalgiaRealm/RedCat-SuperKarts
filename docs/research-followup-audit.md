# Follow-up fidelity audit

This audit follows the four reported regressions and the complete texture-key
inventory. It compares the connected runtime with the supplied executable code,
original configuration and art. The earlier `evidence/final/validation.json`
remains a historical checkpoint; `evidence/regressions/validation.json` records
the subsequent greeting, starter, environment-recovery and texture checkpoint.

The findings and test counts below retain those original checkpoints. Later
source changes are recorded separately in [variable update timing](research-variable-update-timing.md),
[HUD timing](research-hud-notice-audit.md#resolved-timing-differences),
[native texture/framebuffer precision](research-native-texture-precision.md),
and [Meer instellingen](more-settings.md). They supersede the earlier fixed
simulation host, filtered-key cutoff and browser-settings placement without
re-labeling the historical race or browser results as tests of current source.

## Texture and reported-regression checkpoint

At this checkpoint the shared texture loader replaced transparent key RGB
before linear filtering, following the original RGB texture path. This applied
to every keyed 3D texture, including effects and HUD meshes, while preserving
opaque source RGB, UVs and existing blend rules. The later precision change
also packs opaque texels to RGB565, applies protected-black conversion and
replaces the filtered-mask cutoff; source PNGs remain unchanged. The exhaustive
asset audit compares all 817 source
texture records and 587 convenience aliases with their originals: 1,404 PNGs,
zero mismatches. It also corrects ignored source alpha in two French textures
and stale alpha in convenience aliases. See `research-texture-key.md`,
`research-texture-keying-inventory.md` and `research-texture-effects.md`.

The same checkpoint fixes the shipped main-menu greeting, delays the starter
until the authored opening camera ends, and connects the original marker50
environment check and marker51 return search to both player and NPC callbacks.
The Netherlands bridge test drives into the moat from a controlled starting
pose and checks shrink/grow, return position and both original sound events.

## Broader review

The next pass checks composition as well as isolated helpers. A helper matching
native instructions does not establish that its caller invokes it, in the
right order, with the right state.

| Area | Original evidence reviewed | Result |
| --- | --- | --- |
| Main frame order | `rcskspel.dat 42f4c0`, scene callbacks, render and post-render actions | Found missing bubble-shell manager; connected before actor updates |
| Camera keys | `41d920` polls1/2/3/4 before sector selection and `498c00`; `42f4c0` calls it before sound/render | Placement was correct; restored the original Shift gate |
| Driving keys and Space audio | `4b3880`, keyboard `433870`, digital joystick `433cf0`, analog joystick `4341d0`, post-render `42f9c0` | Restored mapped-key and Space-audio Shift gates; Space handbrake exists only in the digital-joystick path, not keyboard/analog |
| Race result writes | `42c4c0`, `417d00`, connected `resultPatch` and browser save adapter | Existing completion gate, opponent IDs, integer estimate and best-lap records retained |
| Debrief and progression | Menu `471bc0`, `471b8c`, `471c70`, `472cfc`, `472fe0` | Existing qualification, unlock, highscore, final movie and profile-save order retained |
| Character movies | `470a7c`, `470c4c`, `473158`, `WINMOVIES` | Only successful final Adventure event requests the selected character's movie |
| Profile and unlock persistence | Menu `45a184`, `45a5dc`, `457b34`; original24-entry `ADVSEQUENCE` | Consecutive browser campaign transition check added |
| Wheel/ground arithmetic | `416650` and `41c0b0`, including repeated callbacks with actual wheel geometry | Removed excess intermediate precision and corrected native operation order |
| Engine and tyre arithmetic | Original full player force callbacks and repeated force/integration updates | Corrected float constants, intermediate rounding, tyre-load order and RPM calculations |
| Rescue progress | `4325b0`, `4932e0`, `4938e0`, `48ca60`, `430ff0` | Player progress uses the body's actual previous sector after relocation, avoiding a false teleport-distance increment |
| Settings and key capture | Menu `46b400`, `46b488`, `4618d0`, `461958`, `461b44` | Found immediate-save/cancellation and key-art differences; see `research-menu-settings.md` |
| Advanced display options | `46a350`, `46a5a0`, `45b334`, original `TFRMDISPLAYSETTINGS` | Restored original form, independent commit/cancel and runtime consumers for brightness, filtering, particles and alpha effects |
| Rescue rendering | `4903c0`, `4a0d80`, `4260c0`, `423010` | Retained old draw matrix while sampling new logical position for color, shadow height and sky |
| Alpha-disabled effects | `4288b0`, `487af0`, `48a570`, `48d610`, `4260c0` | Corrected effect gates and persistent shadow blend factors; ordinary textured models keep their source material rules |
| Inactive legacy candidates | `4107e0`, empty rotation-overlap fallback, previously recorded legacy caller inventory | No speculative traffic, purchase, damage or fifth-race feature added |

## Consecutive Adventure integration

`tests/adventure-sequence-browser.mjs` creates one profile through the actual
menu, then follows all24 configured events in the same browser session. Every
event loads its course, opponents, difficulty, opening sequence, HUD and result
screen. It verifies that displaying results does not yet advance the saved
profile, then checks the persisted matrix, next event, shared unlocks and
original movies after Continue. All six country movies occur in their authored
duel order; RedCat's movie occurs only after the final event. Reload preserves
completion, and replay clears the profile matrix while retaining shared unlocks.

This test passed all24 transitions without a page or asset error. Its report
is `evidence/adventure-sequence/report.json`. The test supplies a controlled
final-lap trigger and twelve-star outcome, runs animation timestamps at four
times speed and HTML media at eight times speed. It is a consecutive UI/save
integration check, **not** a claim to have driven an uninterrupted campaign.
The separate control-only race and NPC endurance tests exercise movement.

## Evidence organization

`research-menu-settings.md` records the recovered menu transactions, original
focus and start-information gates. `research-render-audit.md` and
`research-bubble-shells.md` record the render corrections and the separate
native/browser comparisons. The arithmetic, input and rescue-progress fixtures
are documented in `research-gameplay.md`.

The broad integration checkpoint is `evidence/followup/validation.json`.
The subsequent three-course completion checkpoint is
`evidence/race-completion/validation.json`, explained in
`research-race-completion.md`.
It links the rebuilt runtime, current tests and refreshed movement/browser
reports. Earlier failed harness runs remain retained; they are not silently
counted as successful runs. The automatic route follower supplies ordinary
controls and avoids live opponents; it does not alter game collision rules,
teleport to complete laps or force a winning result.

The refreshed opponent matrix passes all18 course/difficulty cases. At that
earlier checkpoint the autonomous normal-race driver completed five laps on Nederland,
England and Spain. Germany, France and Italy reach the900-second test bound
after two, one and two laps respectively. Additional slowdown, detour-radius
and ordinary bonus-use policies were diagnostic experiments only and were not
applied to production behavior. Sixteen original collision probes at a captured
France contact match the port's fraction, contact order and slide response.
This establishes that bounded contact calculation, not the full trajectory
that reached the trap. Those incomplete checks remain preserved in
`evidence/gameplay/followup-driven-normal.json`.

The requested follow-up closes all three: Germany648975ms, France812350ms
and Italy565975ms, five laps and first place each on identical frozen source.
It fixes stale test-driver detours, restores the active original jump
callbacks and separates British/direction configuration from mirrored
graphics. With explicit user authorization, player rescue now rejects
overlapping placements and selects a supported nearby alternative after
two seconds blocked. Original rescue effects and sounds remain connected;
the deliberate safety exception is documented separately from native parity.

The final resource review also found and fixed HUD texture disposal ordering
and stale HUD redraws during asynchronous race loading. A real-browser test
verifies three race reloads and final cleanup: all uploaded owned textures are
deleted and shared world textures remain valid. Both initial failures are
retained alongside `evidence/followup/hud-texture-lifecycle-browser.json`.

## Remaining verification boundaries

The supplied original race fails to render correctly under WineD3D. Full native
framebuffer, whole-race audio and trajectory comparisons therefore remain
unverified. Instruction execution, source-pixel comparisons, browser playback
and driven port tests are reported separately.

The live browser now uses measured variable updates behind the original 25 ms
minimum gate, independently of uncapped rendering; deterministic fixed-step
hosting remains available for historical replay. Its clock epoch and policies
for uninitialized native fields remain explicit host choices. The renderer now
implements original texture packing and a real RGB565 scene framebuffer, using
a documented historical color-key profile. Exact original hardware filtering,
rasterization and the graphics driver's x87 precision state are not established
by source-file or software-rendered browser checks. The later
[HUD framebuffer follow-up](research-hud-framebuffer.md) closes the separate
Canvas composition gap with native glyph/mesh draws into RGB565. Real mobile devices,
controllers, Windows and macOS remain outside the available test host. These
verification boundaries are distinct from absent active features.
