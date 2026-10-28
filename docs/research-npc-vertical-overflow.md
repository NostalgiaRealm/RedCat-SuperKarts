# Registered NPC catch-up overflow

The England hard time-trial capture
`evidence/full-race-matrix/timed-england-nonfinite-deep.json` contains an NPC
vertical-speed overflow at 59,650 ms under finite ordinary player controls.
This is reproduced by the original arithmetic. It is not evidence that the
port omitted a spring from the normal NPC handler.

## Original call chain

- `0x406940` dispatches normal state 0 through `0x40e490` and subsequently
  calls `0x4062b0` except in state 10.
- Normal movement `0x401200` invokes speed, steering, roll and pitch routines.
  It calls vertical spring `0x413330` only when `0x407580(objectId)` returns
  −1. Registered opponents are found in the AI table and skip this spring.
- Hard catch-up `0x406100` reads the three body velocity fields at
  `+0x9c`, `+0xa0` and `+0xa4`. The full behind-player region multiplies all
  three by `1 + float32(0.08)`. Only forward velocity has the 80-unit cap.
- Ground callback `0x416650` integrates the four wheel vertical velocities,
  writes body render height from their average and rebuilds the ground basis.
  It does not clear body `+0xa0`. Body vertical velocity and wheel vertical
  velocity are separate fields.

The source PE is the installed read-only `data/rcskspel.dat`, SHA-256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
Retained Ghidra exports are under
`evidence/native/rcskspel.dat/functions/`.

## Executed evidence

`tools/native-ai-vertical-overflow-fixtures.py` executes the original x86
instructions in Unicorn, without changing the source file. It writes
`evidence/native/ai-vertical-overflow.json`, which records the source and
capture hashes and float32 byte patterns.

At the 24-bit FPU precision the capture was recorded with, all 119 consecutive captured vertical-speed
transitions match `0x406100` bit for bit. The next original call changes
`3.3529011546832445e38` (`873e7c7f`, little endian) into positive infinity
(`0000807f`). Starting with vertical speed 1 and forward speed 40, repeated
original calls overflow on call 1,153 at both tested 24- and 53-bit precision.

The original `0x401200` preserves the captured vertical speed and makes zero
calls to `0x413330` for this registered NPC. Separately, the original ground
callback is given four cached wheels on explicit flat ground and body height
500. It restores height 0 and reports four grounded wheels while leaving body
vertical speed unchanged for 0, 1, 100, the captured huge finite values, and
infinity. The ground queries in this last probe are explicit boundary stubs;
it is not a full native race replay or a Wine rendering observation.

The focused test `tests/native-ai-vertical-overflow.test.mjs` verifies the port's
unchanged native catch-up kernel against all 240 captured-input cases and
2,306 recurrence steps at both precisions. Any composition-level stability
safeguard is a deliberate exception to this demonstrated original defect,
and should not change the native kernel or be described as native behavior.

The composition now applies that explicit exception through
`source/simulation/npc-velocity-safety.js`: after NPC preparation, a linear
velocity component that was finite before the call and became nonfinite is
reset to zero before integration. Finite results are preserved, and existing
invalid inputs are not concealed. The emitted `npc-velocity-safety` event
records the previous value, rejected value and replacement. The replay
`evidence/full-race-matrix/timed-england-overflow-repaired.json` survives the
captured overflow with one correction and subsequently reaches the ordinary
time limit; it is not a five-lap success claim.

Reproduce with:

```sh
/home/rick/.local/bin/re-python tools/native-ai-vertical-overflow-fixtures.py
node --test tests/native-ai-vertical-overflow.test.mjs
```
