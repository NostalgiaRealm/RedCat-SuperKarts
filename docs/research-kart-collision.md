# Kart collision

The port executes the recovered two-object collision path as well as the
previously recovered static rails. These are original instruction comparisons,
not Wine race-rendering comparisons.

`0x499b20` discovers candidates in this order: rails from the previous/current/
next sector, followed by objects in creation order. Dynamic candidates must have
a shortest wrapped sector distance less than ten. `0x499630` creates the
candidate rectangle; `0x4999c0` creates the moving rectangle. Both round heading
away from zero before selecting entries in the initialized 4096-angle table.
The current game assembly supplies player then NPC bodies, matching `0x415d70`.
Scenery controllers and their dynamic collision flags remain separate work.

`0x499c30` checks the moving corners against every candidate, then checks the
reverse direction, retaining strict-less-than contact selection. This preserves
which kart is first/second in the resulting contact. The rotation overlap test
can stop yaw without creating a contact: its `0x4aa0b0` fallback is actually an
empty native function. The player's `0x492470` second sweep produces a sliding
displacement, while restoring velocity and the initial contact. NPCs do not use
this second sweep.

`0x49b9c0` applies a paired impulse to planar and angular velocities. It retains
two source details that should not be “corrected” to conventional physics:
there is no separating-contact early return, and **both final vertical speeds
use the second body's inverse mass**. The impulse's Y term reads three stack
slots the routine never writes: both velocity Y inputs (`0x49bd3b`,
`0x49bdca`) and the rotated normal's Y (`0x49bea9`, Ghidra `local_68`). The
rotation at `0x49ba79..0x49baa1` stores only X and Z, and the record normal's Y
(`+0x20`) only reaches the unused lever Y. The term is not zero because the
normals are planar, but because of what the slot holds. Called from `0x491d30`,
the normal-Y slot holds the low dword of the integer-valued double that the
floor call in `0x4911a0` leaves (`__frnd 0x4c855c`, `FSTP` at `0x4c8566`). That
dword is zero while a kart's unwrapped heading stays below 2²¹ units, so the
term is zero and the impulse is the planar product. This residue was derived
statically, not emulated. The port multiplies the planar record normal's Y by a
zero relative Y, which gives the same zero. The comparison generator runs the
routine on a fresh emulated stack and supplies planar normals.

Implementation:

- `source/simulation/native-kart-contact.js`: paired impulse.
- `source/simulation/native-collision.js`: candidate order, original sweeps, paired
  contact identity and response dispatch.
- `source/simulation/native-motion.js` and `native-ai-driver.js`: response at the
  original post-integration/pre-ground position.
- `source/race-simulation.js`: shared body list in creation order.

Reproduce the bounded native comparisons:

```sh
re-python tools/native-kart-contact-fixtures.py
re-python tools/native-kart-sweep-fixtures.py
node --test tests/native-kart-contact.test.mjs tests/native-kart-sweep.test.mjs
```

The response generator executes 480 original cases at 24-bit/53-bit x87
precision. The sweep generator executes 780 original cases with controlled
bounding-box inputs. That includes paired contact identity, player sliding,
90 zero-yaw-rate cases per precision, and 120 per precision where rails and
karts are swept together (`0x499c30` with `0x499b20`'s rails-then-karts
order). Both tests compare exactly (`Object.is`) at both precisions; the
earlier tolerances are gone. The fixtures record the original executable
hash.

The combined browser assembly is tested separately across rendering schedules.
This does not establish whole-race original parity. Native collision sound
callbacks and contact latches, all opponent decision states, object visibility
range scheduling and moving scenery remain to be connected/verified.
