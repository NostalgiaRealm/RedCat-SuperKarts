# Gameplay source comparison — 26 October 2026

This pass compares the connected port with the recovered original game
functions, their call sites, the original PE callback table, and fresh parses
of all six original course route/drive files. Decompiled C is inspection
pseudocode with inferred names/types; it is not the authors' recovered source.
The instruction probes below execute original bytes with explicit boundaries.
They do not establish a complete Windows race comparison.

## Changes

### Restore bonus firing to its original point in the player update

The port fired the player's bonus before entering the player motion callback.
The original `0x4325b0` instead follows this order:

1. Engine audio at call site `0x432ab5` (`0x418c80`).
2. Ranking `0x406be0`, then crossed route triggers `0x4938e0`.
3. Initial wheel pass through `0x41b790 → 0x41c0b0`, at `0x432acc`.
4. Input dispatch at `0x432d97/0x432da2/0x432dad`.
   Keyboard `0x433870`, digital joystick `0x433cf0`, and analog
   `0x4341d0` perform the bonus call inside their input routines.
5. Player force call `0x414160`, then the second wheel pass at `0x432f23`.

With a turbo, the old port advanced both wheel passes using the boosted speed.
The corrected first pass uses the speed before firing; only the second uses
the boosted speed. The shot/turbo event, original cooldown and immediate
animation timestamp remain in the same simulation update. Inactive startup
does not poll the fire gate. The input pass still happens before rendering,
and timed-race expiry still happens after rendering/game actions.

`NativePlayerMotion.prepare` now delegates the bonus callback to the input
handler. The ordering inside those handlers is also retained: keyboard
`0x433870` stores handbrake, fires, then updates throttle/brake/steering;
analog `0x4341d0` stores all controls before firing. Browser pads and the touch
wheel continue using the intentionally added analog adapter. The original
digital-joystick trace is retained as evidence; this change does not silently
replace browser pad mapping with that separate DirectInput path.

Files changed: `source/simulation/native-input.js`,
`source/simulation/native-motion.js`, and `source/race-simulation.js`.

### Sample engine sound before rank and track-trigger callbacks

`DrivingView` previously updated engine sound through the hook after route
triggers. Its new `beforePlayerProgress` hook runs at the original
`0x432ab5` boundary, before ranking and crossed markers. HUD event processing
stays after the triggers, through `beforePlayerPrepare`, so lap/checkpoint
feedback still reaches the current frame.

The actual France jump verifies the boundary using wheel launch speeds.
The native caller probe additionally supplies an explicit trigger-speed
change to show which later callbacks observe it. This is a call-order
correction; it is not a claim that an audible jump discrepancy was observed
in the original Windows game. The shipped high-forward setting is parsed
as the original integer value `1`.

Files changed: `source/race-simulation.js` and the small `DrivingView` callback
adapter in `source/driving-view.js`.

## Original-data and dispatch review

`tools/audit-gameplay-dispatch.py` reads the supplied installed originals
without changing them. It reparses all six PMP route files and DMP drive
graphs and compares every resulting record with the current portable data,
including positions, links and markers. **All twelve complete data sets
match.** The original source hashes also match the conversion provenance.

The original player callback table at `0x4ecd80`, used by `0x4938e0`, accounts
for all **16 positive PMP marker values** present in the shipped courses:

| Markers | Original path | Current port disposition |
| --- | --- | --- |
| 9, 14, 15 | `0x442970`, `0x440dd0`, `0x440e40` | Progress flag, lap/finish and finish-arm state |
| 13 | `0x442370` is one `RET` instruction | No invented start-boundary effect |
| 49, 52 | `0x441c50`, `0x441d50` | DMP/facing-guarded forward and reverse jumps |
| 54 | `0x4420f0` | Original notification9; no invented HUD text |
| 61 | NULL table entry | Secondary jump-strength data, not a separate callback |
| 74–76 | `0x441e70` | Timed gates and sound, retaining duplicate/reverse guard |
| 79, 80, 83, 86, 87 | `0x442140/0x442180/0x4421e0/0x4422c0/0x4422d0` | Original weather control |

DMP markers have separate consumers. Environmental return uses
`0x48c030/0x48bf80` and markers50/51 before player and opponent updates.
Start positions69–73 belong to the construction scan `0x415dd0`.
NPC marker68 damping is present in `NativeAIDriver`; the player's analogous
`0x41cb80/0x41cba0` functions are single-return no-ops. DMP markers1,55–57,
79–80 and255 have no additional active action in the NPC `0x406470` switch;
player weather callbacks use PMP crossings.

Two apparent gaps were rejected after checking original reachability:

- Legacy split checkpoint45 is absent from all six PMP routes. Its
  `0x4425f0 → 0x4424f0` writer must not be attached to the separate active
  time gates. Consequently the port's zero saved split count remains correct
  for these courses.
- Water/ice-looking texture names do not add player friction. The player
  hooks above are no-ops; NPC damping, wheel ground geometry, rails and bonus
  hit effects remain distinct systems.

The caller review also checked `0x42f4c0`, `0x491530/0x491d30`, player
`0x4325b0`, NPC `0x40b0b0/0x406940`, lap/timer handlers, and results
`0x417d00/0x42c4c0`. No further confirmed mismatch was established in those
reviewed compositions. This is bounded evidence, not a claim that every
instruction in every game subsystem has an equivalent JavaScript statement.

## Focused verification

- `tools/native-player-frame-order-fixtures.py`: **24 fresh original-byte
  caller/input traces**, with all runs reaching the expected end boundary.
  Audio, ranks, trigger-speed changes, wheel work, force work, shooting,
  clock and joystick queries are explicitly stubbed. The original caller,
  movement gate and input logic execute. The fixture records the binary hash.
- **23 tests passed** across the new frame-order tests, native jump
  composition, HUD event ordering, existing native keyboard/force checks and
  native analog input checks.
- **18 additional tests passed** for recurring original force/integration,
  result/pause/expiry gates and projectile/hit-effect composition. These
  include the existing 2,400-frame force comparison and short deterministic
  driving/combat checks; they are not new full races.

Machine-readable evidence:

- [`gameplay-dispatch.json`](../evidence/full-source-audit/gameplay-dispatch.json)
- [`player-frame-order-fixtures.json`](../evidence/native/player-frame-order-fixtures.json)
- [`gameplay-validation.json`](../evidence/full-source-audit/gameplay-validation.json)

No full test-suite run, complete race matrix, desktop package rebuild or
publication was performed for this change. The existing original Windows
race/rendering limitation, unknown historical graphics-driver x87 state and
physical-device coverage remain separate validation boundaries.

## Intentional differences retained

The authorized stuck-kart and blocked-rescue safeguards, finite NPC velocity
recovery, explicit policies for uninitialized native storage, browser clock
epoch, variable native update admission with uncapped rendering, controller
and touch adapters, free flight, unlock cheat, responsive/widescreen layout,
MSAA and browser/desktop hosting are preserved. No difficulty table,
checkpoint award, race deadline, qualification rule or authored collision
geometry was changed.
