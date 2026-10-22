#!/usr/bin/env python3
"""Original48c170 clearance and49a480 overlap at a control-driven France relocation."""
import json
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig

directory = ROOT / 'evidence/race-completion'
live = json.loads((directory / 'france-live-approach.json').read_text())
track = json.loads((ROOT / 'public/assets/tracks/etappe3.json').read_text())
frame = next(frame for frame in live['frames'] if frame['now'] == 331150)
actors = frame['after']
destination = track['drive'][471]['position']
p = NativeProbe(SOURCE)
p.uc.mem_map(0, 4096)
initialize_native_trig(p)
p.uc.mem_write(0x4afce0, b'\x31\xc0\xc3')
p.u32(0x508610, 4)
p.u32(0x53be28, 4)
p.u32(0x6a5ee0, SCRATCH + 0xc000)
bounds = actors[-1]['bounds']
for offset, xyz in [(0x10, [bounds['minX'], bounds['minY'], bounds['minZ']]),
                    (0x1c, [bounds['maxX'], bounds['minY'], bounds['minZ']]),
                    (0x4c, [bounds['maxX'], bounds['minY'], bounds['maxZ']]),
                    (0x40, [bounds['minX'], bounds['minY'], bounds['maxZ']])]:
    for axis, value in enumerate(xyz):
        p.f32(SCRATCH + 0xc000 + offset + axis * 4, value)
p.f32(SCRATCH + 0xc074, 42)
for index, actor in enumerate(actors):
    base, render = OBJECT + index * 0xd0, SCRATCH + 0x4000 + index * 0xa9
    p.u32(base + 0xc, index)
    p.u32(render, 1)
    p.u32(render + 0x99, 0)
    p.u32(0x5081bc + index * 0x70, index)
    for axis, value in enumerate(actor['position']):
        p.f32(render + 0x50 + axis * 4, value)
    p.f32(render + 0x78, actor['yaw'])
p.run(0x48c170, [4, *map(float, destination)])
assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
free = bool(p.uc.reg_read(UC_X86_REG_EAX) & 255)
rectangles = [SCRATCH + 0x9000, SCRATCH + 0x9100]
for index, address in zip([4, 3], rectangles):
    p.run(0x4999c0, [index, address])
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
overlaps = []
for pair in [rectangles, rectangles[::-1]]:
    p.run(0x49a480, pair)
    overlaps.append(bool(p.uc.reg_read(UC_X86_REG_EAX)))
report = {'scope': __doc__, 'sourceSha256': p.sha, 'input': {
    'capture': 'evidence/race-completion/france-live-approach.json',
    'timeMs': frame['now'], 'waypoint': 471, 'destination': destination,
    'actors': actors},
    'nativePositionFree': free, 'nativeDirectedRectangleOverlaps': overlaps,
    'squaredDistances': [{'racer': actor['id'], 'distance2':
        (actor['position'][0] - destination[0]) ** 2 +
        (actor['position'][2] - destination[2]) ** 2} for actor in actors[:-1]],
    'serviceBoundaries': ['4afce0 logging returns0; geometry and live transforms are supplied as inputs.'],
    'interpretation': 'Native2000 squared-distance clearance accepts this authored destination despite a rotated rectangle overlap. This is not evidence for changing the original clearance threshold.'}
assert free and any(overlaps)
(directory / 'france-native-rescue-overlap.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'nativePositionFree': free, 'nativeDirectedRectangleOverlaps': overlaps,
                  'nearestSquaredDistance': min(row['distance2'] for row in report['squaredDistances'])}))
