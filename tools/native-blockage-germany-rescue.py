#!/usr/bin/env python3
"""Execute original48c170/49a480 at the captured NPC return into the player."""
import json
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig

directory = ROOT / 'evidence/full-race-matrix'
live = json.loads((directory / 'normal-germany-medium-contact.json').read_text())
track = json.loads((ROOT / 'public/assets/tracks/etappe1.json').read_text())
cars = json.loads((ROOT / 'public/assets/cars.json').read_text())
frame = next(frame for frame in live['approach'] if frame['now'] == 78250)
actors, destination = frame['actors'], track['drive'][425]['position']
bounds = cars['cars']['0']['bodyBounds']
cases = []
for precision, control in [(24, 0x7f), (53, 0x27f)]:
    p = NativeProbe(SOURCE)
    p.uc.mem_map(0, 4096)
    p.uc.reg_write(UC_X86_REG_FPCW, control)
    initialize_native_trig(p)
    p.uc.mem_write(0x4afce0, b'\x31\xc0\xc3')
    p.u32(0x508610, 4)
    p.u32(0x53be28, 4)
    p.u32(0x6a5ee0, SCRATCH + 0xc000)
    for offset, xyz in [
        (0x10, [bounds['minX'], bounds['minY'], bounds['minZ']]),
        (0x1c, [bounds['maxX'], bounds['minY'], bounds['minZ']]),
        (0x4c, [bounds['maxX'], bounds['minY'], bounds['maxZ']]),
        (0x40, [bounds['minX'], bounds['minY'], bounds['maxZ']]),
    ]:
        for axis, value in enumerate(xyz):
            p.f32(SCRATCH + 0xc000 + offset + axis * 4, value)
    for index, actor in enumerate(actors):
        base, render = OBJECT + index * 0xd0, SCRATCH + 0x4000 + index * 0xa9
        p.u32(base + 0xc, index)
        p.u32(render, 1)
        p.u32(render + 0x99, 0)
        p.u32(0x5081bc + index * 0x70, index)
        for axis, value in enumerate(actor['position']):
            p.f32(render + 0x50 + axis * 4, value)
        p.f32(render + 0x78, actor['yaw'])
    p.run(0x48c170, [0, *map(float, destination)])
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    free = bool(p.uc.reg_read(UC_X86_REG_EAX) & 255)
    rectangles = [SCRATCH + 0x9000, SCRATCH + 0x9100]
    for index, address in zip([0, 4], rectangles):
        p.run(0x4999c0, [index, address])
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    overlaps = []
    for pair in [rectangles, rectangles[::-1]]:
        p.run(0x49a480, pair)
        overlaps.append(bool(p.uc.reg_read(UC_X86_REG_EAX)))
    assert free and any(overlaps)
    cases.append({'precision': precision, 'nativePositionFree': free,
                  'nativeDirectedRectangleOverlaps': overlaps})
report = {
    'scope': __doc__, 'sourceSha256': p.sha,
    'input': {'capture': 'evidence/full-race-matrix/normal-germany-medium-contact.json',
              'timeMs': frame['now'], 'returningBody': 0, 'playerBody': 4,
              'waypoint': 425, 'destination': destination, 'bounds': bounds, 'actors': actors},
    'cases': cases,
    'squaredDistances': [{'racer': actor['id'], 'distance2':
                         (actor['position'][0] - destination[0]) ** 2 +
                         (actor['position'][2] - destination[2]) ** 2}
                        for actor in actors if actor['id'] != 0],
    'serviceBoundaries': ['4afce0 logging returns0; geometry and captured transforms supplied as inputs.'],
    'interpretation': 'The original center-distance return check accepts the NPC destination while '
                      'the original rectangle test reports overlap with the player. Preventing this '
                      'placement is a deliberate safety deviation, not a native collision correction.',
}
(directory / 'normal-germany-native-rescue-overlap.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'cases': cases, 'distances': report['squaredDistances']}, indent=2))
