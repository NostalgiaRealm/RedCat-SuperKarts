# Original HUD controller audit

This is a source and isolated original-instruction audit of the shipped
`rcskspel.dat` (SHA-256 `68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`), using the retained Ghidra C/assembly and Unicorn probes. It does
not establish native Windows screenshots or GPU equivalence. Only affected
source tests and the separate HUD browser checks are in scope; no release was
rebuilt for this audit.

## Registration and race modes

`00467e30` registers the following controllers in this exact order. The second
minimap registration is present in the original program and operates on the
same overlay elements; it does not imply another missing map.

| Registration | Controller | Init / update | Modes |
| --- | --- | --- | --- |
| `004680a0` | Racer portraits/rank | `0046a3f0` / `0046a720` | All |
| `00468220` | Lap and time statistics | `0046e6a0` / `0046ecc0` | All; remaining timer only type 1 |
| `00468560` | Minimap | `00466360` / `00466830` | All |
| `004683c0` | Wrong-way/junction arrows | `00465080` / `004653c0` | All |
| `00468560` | Minimap again | same | All |
| `004686e0` | Held bonus icon | `00465990` / `00465c90` | All |
| `00468860` | Temporary special string | `0046bd60` / `0046bf80` | All |
| `00468b80` | 3-2-1 countdown | `00464740` family | All |
| `00468a00` | Twelve collected-star symbols | `0046dce0` / `0046e260` | Type 2 only |

The original mode values are 0 normal, 1 timed, 2 stars, and 3 duel. The
registration switch also accepts dormant values 4 and 5 without adding another
controller. Executed evidence for all six branches is
`evidence/native/hud-controller-dispatch.json`, reproducible with
`re-python tools/native-hud-controller-fixtures.py`.

Portrait init/update dispatches to separately named mode functions, but
`0046a9e0`–`0046aa10` and `0046aa30`–`0046aa60` contain only debug logging.
They do not hide portraits in timed races or add a duel-specific counter. The
actual roster determines which portrait and minimap-dot slots are used.

`00465990` initially hides **BonusObject**, then caches the held object's
state/type/level and its configured destination. `00465c90` animates a changed
item from the original origin and finally copies its visibility. Neither checks
race mode. The configured Bonusframe and STRING_BONUS label remain visible in
timed races even though that mode has no collectible bonus items.

`0046e6a0` and `0046ecc0` always maintain lap number, total laps, lap time and
best lap. Only type 1 calls `0046eac0` / `0046f0b0` for timer 18's remaining
time. There is no separate duel countdown or target counter in these branches.
The star controller is twelve original models turning gray to white, not a
fabricated numeric `N/12` text field; see the star HUD fixtures.

## Missing arrows restored

The original overlay registers both BackArrow (`ovlypijl.d3d`) and JunctionArrow
(`spltpijl.d3d`), using `overlay1.pcx`'s accelerated TGA asset and the authored
Screen position `320;210`. Both begin hidden. `NativeHudArrows` implements the
original state machine and produces render commands with finite alpha variants.

* `004653c0` displays BackArrow when `00415be0` says the kart faces against the
  selected original road direction. This is a matrix/route dot product, not
  reverse speed. Facing forward immediately hides that warning.
* `00465840` starts JunctionArrow only while facing forward and when neither
  arrow is active. It sets a one-second lifetime. A wrong-way warning replaces
  an active junction warning; a new junction request does not restart one.
* `004654b0` makes the selected arrow visible, resets the phase/timestamp, and
  immediately calls the update. Consequently a junction request consumes one
  delta at admission, then another in the normal overlay update that frame.
* `00465570` changes its integer alpha step at most once per callback, with
  period float32 `1/14` seconds. It oscillates 0 through 13 and back. Actual
  alpha bytes are `0,18,36,54,72,91,109,127,145,163,182,200,218,236`;
  original RGB is preserved. A long stall does not catch up in a loop.
* Junction expiration tests its remaining lifetime before subtracting the
  current delta. Absolute engine time drives the pulse; native delta drives
  the lifetime. These are not wall-time setTimeout animations.

The original trigger table at `004ecd80`, slot **54**, points to `004420f0`.
That callback calls `00430610(9)` only for the player. The event reaches
`00469660` → `004693b0` → `00465840`, with no race-mode restriction. The port
now emits the corresponding native notification from the same sector-trigger
dispatch. Authored marker-54 sectors, using zero-based track IDs, are:

| Track | Sectors |
| --- | --- |
| 0 Netherlands | 21, 77, 143 |
| 1 Germany | 17, 130, 173 |
| 2 England | none |
| 3 France | none |
| 4 Spain | 19, 80, 173 |
| 5 Italy | 19, 80 |

Event 0 does not reset arrows: `00469670` obtains the countdown controller and
calls `00464a00`. For arrows, the initial element state and normal facing/event
transitions apply. `00415be0` reads the render matrix, including a rescue's
temporary render orientation, while its route lookup uses the engine sector.

`evidence/native/hud-arrows-fixtures.json` contains 636 original arrow updates
at both 24- and 53-bit x87 precision, plus three original player-filtered trigger
calls. It covers pulse direction changes, repeated junction requests, takeover,
expiration, zero-delta updates, large clock stalls and float boundaries. Run
`re-python tools/native-hud-arrows-fixtures.py` to regenerate them.

## Registered artwork versus inactive definitions

The shipped overlay registers 35 mesh entries and 10 strings. The three
321Timer*Flare entries are commented out and excluded by ELEMENTS COUNT=35;
legacy STRING_1 through STRING_5 are also commented out. Definitions remaining
elsewhere in the INI do not establish active rendering. They should not be
invented as missing visible elements. Temporary-notification dispatch and its
active callers are audited separately by the HUD notification helper/tests.

The statistics audit also identified that the original lap display hold uses
an integer-truncated absolute engine-clock timestamp (`0046f230`), rather than
an exact three active-race seconds. The separately authorized correction and
original-instruction regression evidence are documented in
[the lap-display audit](research-lap-display.md).

## Analysis provenance

The connected REA MCP session was inspected for this audit: no target was open,
no same-session Evidence records were retained, and the Ghidra provider reported
`not_configured` because `GHIDRA_INSTALL_DIR` was unset. The complete existing
Ghidra function exports and assembly under `evidence/native/rcskspel.dat/` were
therefore reused, with new direct original-instruction probes as listed above.
No new MCP native session was opened or left running. This limitation does not
turn the retained source observations into runtime or rendered observations.

Focused verification: 14 arrow/star/race-sector tests passed. The new arrow
module itself has three tests, covering every captured update, original palette
and long-stall behavior, plus player-only junction notification in all four
active modes. Browser integration evidence is maintained by the HUD browser
audit rather than inferred from those instruction-level checks.
