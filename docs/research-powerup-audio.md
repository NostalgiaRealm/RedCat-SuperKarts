# Power-up pickup and firing sound parity — 25 October 2026

The supplied original copies, original instruction paths and live port agree
on power-up audio. No recording replacement, mixer adjustment or gameplay
sound-dispatch change was warranted. This follow-up adds a complete turbo
instruction comparison, broader browser regressions and an updated clock
baseline in the older sound-trigger validation tool.

## Original evidence

Installed and CD `rcskspel.dat` have identical SHA-256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
Fresh REA/Hopper analysis covers 14 original functions. Isolated original
instruction execution checks 3,001 cases: 41 pickup/firing cases, 1,580 character
voice cases, 1,200 homing-warning updates and 180 complete turbo dispatches.
The latter executes `451640 → 4537f0`, retaining the character selection/chance
draws, effects request, speed update and inventory consumption.

See the [native audit](evidence/powerup-sound-native-audit.json),
[REA evidence](evidence/powerup-sound-rea.json),
[new probe](../tools/native-powerup-sound-flow-fixtures.py) and
[turbo fixture](../evidence/native/powerup-sound-flow-fixtures.json).
The owned REA session was closed after export; original files were unchanged.

## Confirmed dispatch

| Item | Pickup request / Sound.ini event | Firing requests / events |
| --- | --- | --- |
| Rocket | `GOT_ROCKET` / `PSR` | `FIRE_ROCKET1..3` / `SSR1..3` |
| Soap | `GOT_SOAP` / `PSW` | `FIRE_SOAP1..3` / `SSZ1..3` |
| Oil | `GOT_OIL` / `POD` | `FIRE_OIL1..3` / `SOD1..3` |
| Gum | `GOT_GUM` / `PGD` | `FIRE_GUM1..3` / `SGD1..3` |
| Turbo | `GOT_TURBO` / `PTU` | `FIRE_TURBO1..3` / `STU1..3` |
| Star | Literal `GOT_EURO`, absent from effects bank | No firing request |
| Supported random pickup | Literal `GOT_BONUS`, absent from effects bank | Uses the resolved owned weapon on firing |

`4540c0/4542c0` use the **static pickup type**, not the randomly resolved
inventory type. Duplicate pickups upgrade the inventory but keep the same
pickup sound. The player's pickup runs the original character BONUS
selection/chance before inventory decisions, queues the effects request, then
performs a second player BONUS selection/chance. A successful second character
request replaces the first; it does not remove the independent effects queue.
NPC pickups do not queue the player's `GOT_*` effects.

`455490` queues the player's numbered firing effect before projectile setup.
Turbo `451640 → 4537f0` requests the player character's TURBO line before its
numbered firing effect. NPC firing does not emit these player effects or the
player's turbo line. Held input cannot replay the consumed inventory's shot.
Pickup handling occurs after this tick's voice service, so its audio is first
serviced on the next tick. Player firing can be serviced in its current tick.

The effects channel retains FIFO order, one dequeue per tick and the current
playing-source gate. Hit replacement clears/stops that channel before looking
up the requested name, including a missing name. Homing beeps use the targeted
player's **character bank**, not effects channel 10. Their original interval,
distance thresholds and player-only gate are preserved.

## Original omissions and inactive recordings

The enumerated EFFECTS bank does not contain `GOT_BONUS`, `GOT_EURO`,
unnumbered `FIRE_TURBO`, `HIT_BY_*`, `IMR1..3`, `IMO1..3` or `SOAP_UP1..3`.
These original requests fail admission; existing recordings or unlisted
mapping keys do not authorize substituting a different sample. `GOT_ITEM`
exists, but the original star pickup requests `GOT_EURO` instead.
Country opponents have HIT/AMHIT entries but lack BONUS/TURBO speech.
Rocket explosion `481ec0` is a visual effect and has no separate explosion
sound call.

The bank also enumerates `SOAP_PLOPS1..3` and unnumbered `SOAP_UP`.
The executable contains no references to the pop names or their event codes;
its only `SOAP_UP` reference appends the weapon level before requesting it.
The audited bubble attachment, movement, expiry and replacement cleanup do
not queue or play sound. The native report records all 29 direct voice-queue
call sites; no extra bubble pop or loop was introduced.

No shipped OMP places the supported random type 7. Its browser cases explicitly
inject native type-7 state and original geometry; they do not add a random
pickup to the game's tracks. Authored star contacts are checked separately.

## Recording and mixing identity

The asset audit covers 11 voice banks, 327 logical entries and 314 distinct
original WAVs, including unused records. All 628 installed/CD-to-prepared byte
comparisons pass; all files have valid, non-silent PCM. Original `Sound.ini`
and `RcrSound.ini` match both copies and the prepared configuration.
See [asset/configuration/mixing evidence](../evidence/audio/powerup-parity/assets.json).

The five normal pickup effects and 15 numbered firing effects have raw volume
80, range 600 and Doppler 80. Named volume-group writes finish at 90; enabled
FX_VOLUME then replaces the source volume (100 in the shipped settings).
There is no additional effects master multiplier or weapon-level gain/pitch
multiplier. Positional distance, pan and Doppler are then applied through the
original source path. Effects channel 10 is attached to the player body;
character channels follow their racer bodies. Voice playback is one-shot.
Sound.ini field 2 controls preload/cache, not looping or priority.

The current mixer matches 3,768 retained native-fixture comparisons. The real
voice controller also passes 1,200 targeted effect-bank admission cases across
24 player/country roster combinations. Those checks establish the bank and
mixing rules independently of live browser audibility.

## Focused source validation

- Eleven bonus, character, homing and turbo comparison tests pass over the
  3,001 original instruction cases. Nine additional queue/mixing/spatial tests
  pass, including the retained 600-update FIFO fixture.
- `RCSK_URL=http://127.0.0.1:4184 node tests/powerup-audio-browser.mjs` passes
  118 controlled cases across all four playable characters. Each character's
  five normal pickup and 15 firing effects start the correct decoded original
  AudioBuffer sources. The checks also cover static stars, explicitly injected
  random pickup state, NPC suppression, empty/held inventory, actual source-
  ended FIFO progression, homing warnings and disabled effects.
- The browser fixtures use the existing Netherlands item-race route, explicit
  pickup contacts, inventory/cooldown/RNG setup and the actual DrivingView
  tick. They record source files, nonzero decoded PCM, gain, pan, pitch, loop
  flags and request order. This is not a control-only driven race.
- The old `validate-race-sound-triggers.mjs` now starts controlled time at the
  current clock snapshot, replacing its obsolete fixed-interval calculation.
  Its unrelated recovery/scenery cases were not repeated for this follow-up.

Reports: [live playback](../evidence/audio/powerup-playback.json) and
[consolidated validation](../evidence/audio/powerup-parity/validation.json).
These checks establish original recordings, dispatch and browser playback;
they do not claim a native Windows sound-card/speaker capture or identical
hardware resampling. No full race, full suite, package build or publication
was performed.
