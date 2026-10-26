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
use the second body's inverse mass**. Its Y velocity scratch entries are not
initialized, but native `0x49ac80` contact normals have zero Y; these entries do
not contribute to reachable planar contact response. The comparison generator
therefore supplies planar normals.

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
precision. The sweep generator executes 360 original cases with controlled
bounding-box inputs, including paired contact identity and player sliding.
The tolerances were defined before comparison: response absolute `0.0001` plus
relative `0.000003`; sweep absolute `0.00003` plus relative `0.000003`.
Both pass. The fixtures record the original executable hash.

The combined browser assembly is tested separately across rendering schedules.
This does not establish whole-race original parity. Native collision sound
callbacks and contact latches, all opponent decision states, object visibility
range scheduling and moving scenery remain to be connected/verified.
