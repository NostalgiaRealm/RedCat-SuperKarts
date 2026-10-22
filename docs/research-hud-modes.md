# HUD elements across the original race modes

This source-only audit covers Landenrace (0), Tijdrace (1), Sterrenrace (2)
and the adventure duel (3). It compares the shipped overlay registries,
language and animation files, original executable controller/trigger paths,
and the port's actual HUD integration. It does not use WineD3D race rendering
as a visual reference, and no desktop package was rebuilt.

## Changes

- Restored `BackArrow` and `JunctionArrow`, using `ovlypijl.d3d` and
  `spltpijl.d3d` with the original `overlay1.pcx` atlas. The original facing
  test drives the wrong-way arrow; reversing speed alone does not activate it.
  Track marker 54 requests the one-second junction warning. The original
  fourteen-step opacity cycle, interruption rules and frame ordering are
  retained. The rendered rescue basis is used while the kart is respawning.
- Connected player-owned projectile hits on opponents to the original
  `Raak!` notice. Hits enter the queue after the native rendering boundary and
  become visible on the next HUD capture. Opponent-owned hits do not show it.
- Removed the extra `Controlepunt!` notice from ordinary timed gates. Their
  original callback adds time and plays the checkpoint sound; the text belongs
  to a different legacy marker absent from all six shipped tracks.

The earlier twelve-star counter restoration remains intact. Responsive
layouts center the arrows in the race view while retaining the original
640×480 artwork proportions; portrait touch controls retain their reserved
space.

## Element coverage

| Original display | Landenrace | Tijdrace | Sterrenrace | Duel |
| --- | --- | --- | --- | --- |
| Racer portraits, frames and rank symbols | Roster-dependent | Roster-dependent | Roster-dependent | Roster-dependent |
| Course minimap, player and opponent dots | Present | Present | Present | Present |
| Lap, lap time and best lap | Present | Present | Present | Present |
| Remaining-time counter | Hidden | Present | Hidden | Hidden |
| Bonus frame and label | Present | Present | Present | Present |
| Held bonus model | Inventory-dependent | Inventory-dependent | Inventory-dependent | Inventory-dependent |
| Twelve-star collection display | Hidden | Hidden | Present | Hidden |
| Wrong-way and junction arrows | Conditional | Conditional | Conditional | Conditional |
| Three start lights | Start sequence | Start sequence | Start sequence | Start sequence |
| Special notices, pause and finish flag | Event-dependent | Event-dependent | Event-dependent | Event-dependent |

The original creates common HUD controllers for every mode and adds the star
controller only in mode 2. The bonus frame is not hidden in time trials even
though ordinary pickups are disabled there. No additional active duel-only
counter was found. Difficulty changes the race's configured time allowances,
not this element inventory.

The asset inventory checks all nine relevant original INIs against the
converted configuration, 366 track/frame bindings and 52 unique original
mesh/texture assets. It accounts for 35 registered meshes, ten strings, six
composites, two fonts and the twelve dynamically created stars. Unused
portrait/dot definitions are roster templates. The five older ordinal text
strings and three countdown flare sections are excluded from the original
registries; they are not missing active displays. The active STOPPEN requester
uses overlapping duplicate Yes/No images, so the port's two buttons do not
omit distinct character illustrations.

## Evidence and validation

- [Final node and asset inventory](../evidence/hud-mode-audit/inventory.json)
  classifies all 75 records and retains original file hashes. The separate
  `inventory-before-mode-fixes.json` preserves the initial findings.
- [Arrow/controller research](research-hud-arrows.md) records original
  functions, mode dispatch and bounded x86 probes.
- [Notice and requester audit](research-hud-notice-audit.md) records every
  dispatcher ID and active/dormant callsite. Its two identified lap-hold and
  requester timing differences were subsequently corrected; see the
  [timing follow-up](research-hud-notice-audit.md#resolved-timing-differences)
  and its separate evidence, rather than the earlier inventory checkpoint.
- [Browser report](../evidence/hud-mode-audit/browser/report.json) records the
  six passing source-renderer checks, with controlled contacts and warnings,
  zero browser errors and unchanged source/asset hashes during the run. Wide
  and portrait screenshots were inspected. This is not a full driven race or
  an original Windows GPU comparison.

The following focused run passed all 28 tests, including 636 original arrow
state updates, three original junction-trigger probes, existing HUD transform
and notification fixtures, and race-trigger regressions:

```sh
node --test tests/native-hud-arrows.test.mjs tests/hud-gameplay-events.test.mjs \
  tests/race-hud-order.test.mjs tests/hud-notifications.test.mjs \
  tests/hud-mesh.test.mjs tests/native-star-hud.test.mjs \
  tests/star-hud-layout.test.mjs tests/simulation-race.test.mjs
```

The full test suite and release builds were not run for this change.
