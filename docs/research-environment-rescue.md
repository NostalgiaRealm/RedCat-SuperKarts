# Danger-zone recovery

The original race executable calls `48c030` first in both player `4325b0` and
opponent `40b0b0` callbacks, including during inactive startup. The port had the
shrink/grow controller and its sounds, but only connected the NPC stuck handler.
It omitted this environment trigger and the separate authored-return branch.

`48c030` selects a route sector with `4977d0`, evaluates that sector's fallback
plane with `494b70`, and reads the body's current DMP waypoint. Marker50 and a
strict `bodyY - routePlaneHeight < 1.5` enqueue `48dce0(body,1)`. This does not
use the triangle terrain height, a texture name, or an arbitrary world boundary.
Both actor callbacks now run this check before progress/input/state dispatch.

`48c9a0` retains the environment flag at entry+11ac. At grow frame0, `48ca60`
uses `48bf80(currentWaypoint,0)` to scan forward through DMP array slots, wrapping
to marker51. It does not follow route links. The shipped DMP loader allocates
contiguous slots; all actual marker50/51 slots on all six tracks are covered by
the native scanner fixtures. Netherlands has twelve danger markers and one
return marker,441. The bridge-side moat includes marker453.

The destination must pass `48c170`: other racers at planar squared distance
2000 or less block it. A blocked return resets shrinking/frame19, applies
scale0.1 and returns before the ring update; after one final shrink tick it
retries. No marker means grow in place. Normal stuck recovery still retains
the old six-to-zero-node fallback: original `48d930` returns success even when
all candidates were rejected. This differs from the environment branch.

Successful relocation selects the nearest route sector, restores heading,
samples triangle ground, updates the player's cached HUD position/speed, and
leaves waypoint membership for ordinary integration to update. The existing
twenty shrink and twenty grow ticks, original ring geometry/texture, frame3
DISAPP/REAPP character voices and completion speed5 remain in use.

## Evidence and verification

- Original SHA256:
  `68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
- Fresh REA/Ghidra function analysis:
  `evidence/regressions/rea-environment-rescue.json`.
- `tools/native-environment-rescue-fixtures.py` executes original instructions
  at24/53-bit x87 precision:144 plane/marker gates,312 authored marker searches
  and6 free/occupied/missing-return update cases. External sector/queue or
  destination services are explicitly controlled where noted in the script.
  Unicorn translation-cache invalidation is required when replacing a service
  already executed in the same emulator.
- `tests/environment-rescue.test.mjs` checks those fixtures, full falling-body
  composition, inactive NPC recovery, voice requests, blocked retries and the
  normal-recovery fallback.
- `tests/environment-rescue-browser.mjs` starts from a controlled pose on the
  original raised bridge, then uses real ArrowUp input and the normal browser
  loop to drive off its edge. It never directly enqueues or relocates a racer.
  It verifies40 recovery frames, displayed rings/scaled kart, marker441 at
  height20, removal after completion and actual WebAudio DISAPP/REAPP sources.
  Report and screenshots are in `evidence/regressions/`.

The original race cannot be reliably rendered with WineD3D on this host.
These are original instruction and port integration checks, not a full native
race screenshot/audio comparison.
