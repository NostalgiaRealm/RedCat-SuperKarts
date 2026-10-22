# Registered player jump callbacks

The France completion investigation found a reachable player behavior missing
from the port. The older research description calling these jump callbacks
“legacy” was incorrect. They are installed in the active generic trigger table
and are authored in three shipped tracks.

## Registration and update order

`0x42d7d0` calls `0x441970`, which copies the 89 entries at `0x4ecd80` into the
engine callback table through `0x493290`. Entry 49 is `0x441c50`; entry 52 is
`0x441d50`. Entries 61, 62 and 63 are null. The fixture executes the original
registration instructions, omitting only the unrelated scheduler registration
called by `0x440ef0`.

Player update `0x4325b0` calls `0x4938e0` at `0x432ac0`. This precedes the
movement-active gate, input processing, player forces and body integration.
`0x4938e0` dispatches the two PMP fields in their stored order when the engine's
current and previous sectors differ. An unchanged sector does not dispatch.
The NPC dispatcher `0x406470` has no cases for 49 or 52, so the player jump
callback must not be added to NPCs.

`RaceSimulation` now calls `applyNativePlayerJump` in that existing player
boundary-dispatch stage, regardless of whether weather exists or movement is
active. Its input is the current engine sector/waypoint, current render matrix,
forward speed and the four persistent wheel vertical speeds.

## Exact gates and writes

`0x441c50` requires the current DMP node's marker to equal 49 and `0x415be0` to
report forward-facing. `0x441d50` requires marker 52 and the opposite facing.
The direction calculation selects lane zero through `0x493430`, follows the
original DMP link selection in `0x404be0`, and tests its XZ dot product with the
render matrix's forward vector. A zero dot is forward-facing.

After the gates, both callbacks read the **current sector's** secondary PMP
marker, rather than necessarily the boundary that was dispatched. Marker 61
selects High, 62 Medium and 63 Low. Each of the four wheel children is obtained
through `0x4906b0`; the configured Up value is added to child render offset
`+0x60`, its vertical speed. The body forward speed at `+0xa4` is multiplied by
Forward. Each result is stored as float32. These are velocity changes, not
direct position/height changes.

The original leaves stack values undefined if a jump passes both gates with
another secondary marker. All authored active jump boundaries in the supplied
tracks use 61. The helper reports an invalid unverified configuration rather
than inventing a jump strength for that uninitialized branch.

## Integer configuration and independent direction flags

The jump loader is `0x42bbf0`, specifically `0x42bedf..0x42bfad`. Its reader
`0x4b1ed0` calls `GetPrivateProfileIntA` with default zero. The loader converts
the returned unsigned integer to float with `FILD`/`FSTP`; it does not parse the
authored decimals as floating point.

| Setting | Authored text | Runtime float |
| --- | --- | --- |
| HighForward | 1.2 | 1 |
| HighUp | 275.0 | 275 |
| MediumForward | 2.0 | 2 |
| MediumUp | 100.0 | 100 |
| LowForward | 1.5 | 1 |
| LowUp | 250 | 250 |

The instruction fixture executes that entire load slice with the profile
reader's integer return values supplied as the explicit external API boundary.
It does not claim to emulate Windows profile I/O. The final stored six floats
are checked at both x87 precisions.

`0x415be0` also exposed a separate composition error: `0x42af70` reads British
lane selection from `Race.INI / ETAPPE / british` into `0x53ba70`;
`0x42c170` reads `DIRECTION` into `0x53ba08`. The supplied configuration is
British 0 and missing Direction defaults to 0. These are independent of
`track.ini` field 14, the track's mirrored display/input mode. The jump helper
now receives the shared explicit `RaceSimulation.routeOptions`. Substituting
France's `track.mirrored=true` had selected an empty left-lane list and the
native waypoint-zero fallback, producing an unrelated direction vector.

## Authored coverage

The reproducible inventory is in
`evidence/race-completion/france-native-jump-fixtures.json`.

| Track | PMP jump boundaries | DMP gate that actually permits the forward/reverse jump |
| --- | --- | --- |
| Netherlands | 22, 101, 120: marker 49 | Some lanes at 22 and 120; all lanes at 101 have marker 0 |
| Germany | 102, 103: marker 49; 108, 109, 110: marker 52 | Forward at 103; reverse at 110 |
| France | 103, 104: marker 49 | Forward at 104; 103 has marker 0 |
| England, Spain, Italy | None | None |

France's marker-49 launch at sector 104 immediately precedes the marker-50
danger region. Omitting the launch therefore changes traversal of that gap.
The source rescue clearance can independently accept an overlapping return
position; restoring jumps and the separately authorized rescue safeguard are
different changes, with different evidence and purposes.

## Validation

Run:

```sh
/home/rick/.local/bin/re-python tools/native-blockage-jump-fixtures.py
node --test tests/native-jump.test.mjs tests/native-jump-composition.test.mjs
```

The fixture executes 648 original callbacks covering both directions, all three
configured levels, matching/mismatching waypoints and zero/positive/negative
direction dots. Another 320 cases execute the registered `0x4938e0` dispatch
across all authored jump lanes, including the unchanged-sector gate. Both
24-bit and 53-bit x87 cases match exactly. The composition test verifies that
France's launch is already applied at the pre-player-prepare hook, including
an inactive countdown phase and an absent weather controller.

These tests execute original instructions in isolated memory and compare the
port. They are not a Wine race-rendering or original full-process comparison.
Original executable SHA256:
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
