# Character speech and homing warnings

The logical selectors use the same `NativeRandom` instance as gameplay.
Disabling audio does not suppress their random draws: the original queue's
admission gate runs after sample/chance selection. `NativeCharacterVoices`
emits requests synchronously through `onRequest`, so replacing a voice stops
its current sample at the native request point. Servicing the queue remains
the separate `CVoiceController` transport.

## Original request sites

| Source | Behavior |
| --- | --- |
| `437ff0..438670` | HIT modulo6, AMHIT modulo4, PASSING/PASSED modulo2, BONUS modulo7, TURBO modulo2; four COMM ranges |
| `438710/438730` | One CRT draw, accepted when modulo3 is zero |
| `4387e0`, called inline by `406be0` | First chance selects PASSING for the overtaker; otherwise PASSED is selected before a second chance for the passed racer |
| `40d9c0` | Catch-up announcement within circular sector distance2, with original mode/activation guards; PASSING then CLAXON, or gated player PASSED |
| `4514e0→4106b0` | BONUS selection and chance **before** random pickup type and NPC extra-level draws |
| `4540c0` | After player collection: static-type GOT_* request, then a second BONUS selection/chance |
| `4537f0`, `451640` | Player TURBO selection/chance, then FIRE_TURBO+level; NPC turbo has no character request here |
| `455490` | Player FIRE_ROCKET/SOAP/OIL/GUM+level at Shoot entry, before target/pose/hatching |
| `40d310→40d260` | NPC AMHIT only when the record shooter is literally -1, before effect initialization |
| `435aa0` | Player AMHIT after effect initialization, including its spin-direction draw |
| `455b00→4363e0→437c40` | Player HIT after hitting an NPC, including an NPC whose finished state ignores the effect |
| `455b00→40de60` | NPC HIT after hitting the player unless the attacker is in finished state9 |
| `430610` event5/event6 | COMM4..6 / COMM0..3 on effects voice10, without a chance gate |
| `440a90` marker53 | FIRE_TURBO without level, then player TURBO selection/chance |
| `48ca60` | At pre-update rescue frame3, DISAPP or REAPP on that racer's voice, without RNG |

Event5 is raised on entering the final lap; event6 is raised for a new best lap.
The original call graph has no incoming direct calls to COMM7..8 or COMM9..20
selectors. They are preserved and tested without adding new event sites.
Marker53 occurs in neither PMP slots nor DMP markers on any shipped course.
Collision crash selection is separate (`434f20`), with its own native timing
and RNG tests; no extra character speech is inferred from a collision.

`437ea0` resolves NPCs through their original available-character indices.
Every racer argument outside `[0, NPCcount)` selects the player voice.
The eleven channels are the ten original characters and effects channel10.

The effects bank decides whether a name exists. In particular, static stars
request **GOT_EURO**, while the shipped bank only defines GOT_ITEM. Random
pickups request GOT_BONUS. The zipper requests FIRE_TURBO without a level.
These names must remain absent rather than being substituted. Hit initializers
also retain IMR+level, SOAP_UP+level and IMO+level exactly.

## Homing arm

`456440` creates the effect when a rocket (type1) of level2 or3 enters state2.
`486b20` attaches it to the shot's **homing target at+0x24**, not its shooter
at+0x20. An out-of-range target, including -2, resolves to the player.
The manager `487af0` permits at most20 records and one record per target body.
Creation/update/render require jetstreams, alpha blending and a non-paletted
renderer. Removal only checks the jetstreams setting.

The constructor records the squared XZ separation between target body and
projectile. `486ea0` divides current squared separation by that initial value;
no approximation to tension is used. It writes scale=ratio×1.5 and retires
the effect above `1.5+float32(.01)`, including unordered values. A zero launch
separation is not replaced by an epsilon. Audio sees the ratio before
retirement. `arm-audio.js` retains the original strict timer threshold,
one beep per callback and thresholds float32(.4/.7).

The geometry consists of two oppositely rotating sets of eight triangles.
Growth begins at two and advances by at most one per callback. Positions use
the previous callback's scale; colors use its newly calculated scale.
`487780` always draws two24-vertex triangle lists, independent of growth.
It sets identity world and the S_SFX_PCX texture and only disables alpha
blending after drawing. It does not set blend factors, depth writes or culling.
It inherits those states. The port retains original XYZ/triples under its
existing coordinate conversion; no additional winding reversal is applied.

Native rendering order in `430020` is world/karts and their deferred queue,
skidmarks, halos, jetstreams, homing arm, `485710` effects, rescue, smoke, then
the finish-flag renderer. The arm's no-blending draw therefore still belongs
after the world deferred pass.

The native constructor does not initialize the complete vertex buffers.
The port explicitly initializes those unknown bytes to zero until each vertex
is written. This is a deterministic storage policy, not a native heap-value
claim. The manager also retains the original stale trailing callback after
copying/removing a record; it can service a copied sound while the live moved
record retains its earlier fields.

## Evidence

`tools/native-character-voice-fixtures.py` executes 1,580 original cases:
400 selectors,80 mappings,560 dispatches,160 catch-up branches,120 rescue
callbacks,120 complete hit initializers and140 complete pickup dispatches.
The pickup comparison includes emitted requests, inventory, star count and
final shared RNG state, verifying the voice/type/upgrade ordering together.
CString allocation/concatenation, graphics and sound-card boundaries are
explicit adapters. The original selectors, branch logic and CRT RNG execute.

`tools/native-arm-fixtures.py` executes360 constructor/update cases across
24- and53-bit x87 settings, including all geometry, colors and zero-distance
retirement; six original manager-removal cases; and four renderer call traces.
The separate arm audio probe executes1,200 timer/threshold cases including
NaN and infinity. These are bounded instruction-level comparisons, not a
whole-game Windows rendering or sound-device parity claim.
