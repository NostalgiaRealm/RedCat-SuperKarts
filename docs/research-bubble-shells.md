# Bubble-hit shell composition

The October 20 composition audit found that bubble-hit physics was implemented,
but its `bubbleVisible` state had no renderer consumer. This omitted an active
original object, rather than a dormant library feature.

`00411b40` calls `00457780` after its effect setup and player soap sounds.
The latter finds an existing attachment or the first free manager slot, maps
the CHARDATA racer index to an engine body, allocates a separate engine/render
object and assigns frame 0 of `gen_anim.ini [bubble]`:
`bubb0001.d3d,weapon.pcx`. Accelerated texture selection uses `weapon.tga`.
The shell has zero rotation, no additional scale, and blend mode 2
(`ONE / INVSRCCOLOR`), with the native deferred-object depth-write rule.

`0042f4c0` calls `00457b60` at `0042f4fb`, before scene/racer callbacks and
integration. It copies the attached racer's position, sector and waypoint,
sets zero rotation and rebuilds the shell matrix. Consequently, the shell
rendered this frame normally holds the racer's **pre-movement** pose. It is
not a child of the kart, and the first-person camera's kart visibility flag
does not hide it.

`00412560` detaches through `00457ab0` when the bubble termination conditions
complete. Accepted replacement hits also detach: player `00435aa0` first
calls `004126b0` when its previous effect is active; NPC `0040d310` does so
when its previous state is 25. Cleanup only detaches if the previous bubble
visibility byte is set. This precedes the new hit initialization and the NPC
priority/voice processing. A finished NPC's ignored hit does not detach.

The independent implementation is `src/simulation/native-bubble-attachments.js`;
`src/bubble-visuals.js` binds its captured state to the original mesh, texture
and material. Optional `NativeBonusCombat.onBubbleAttach/Detach` callbacks
preserve the hit and cleanup boundaries. No random numbers are consumed.
Core binding must call the manager before scenery and racers, then capture
its separate render objects before applying sector visibility.

`tools/native-bubble-attachment-fixtures.py` executes 480 original manager
operations across shipped opponent counts 1, 3 and 4, including duplicate
attachments, first-free slots, normal/player index mapping, detachment and
position/sector/waypoint copies. Original asset ID and mode-2 writes execute.
File `evidence/native/bubble-attachment-fixtures.json` records results and
the original executable digest. REA/Ghidra's independent attachment inspection
is in `evidence/native/rea-bubble-attachment.json`.

Fixture service boundaries are logging, engine-object allocation/free, route
selection, model lookup and the independently validated zero-angle matrix
builder. The fixture does not claim to reproduce the complete engine heap
allocator. The browser assigns relative object order after the preallocated
projectile objects; its shell allocation cursor follows the source's forward
scan and immediate reuse of a released last allocation. Whole-engine capacity
wrap after thousands of dynamic allocations is not exercised.
The renderer ranks the currently attached shell orders before assigning its
draw-order values. This preserves their relative submission order while
preventing an increasing host counter from crossing the later skid/effect
passes. It does not assert absolute native object-pool IDs or wrap behavior.

The focused test suite also verifies the renderer binding, independent pose,
replacement cleanup and player sound order (`HIT_BY_SOAP`, `SOAP_UP`, shell
attachment, then caller `AMHIT`). Existing combat replays across all six tracks
remain unchanged.

`evidence/bubble-shells/browser.json` records four passing actual browser
checks: a controlled original weapon contact attaches the shell at its
pre-movement pose, first-person hides the kart while still drawing the shell,
a replacement hit removes it, and the original settled-effect branch removes
an NPC shell. The contact positions and inventory grants are explicit test
fixtures. The report includes no console, page or HTTP errors.
