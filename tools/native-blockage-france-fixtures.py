#!/usr/bin/env python3
"""Execute original 491d30 frame loop around the captured France kart pair.

Only time, occupancy unlink/relink, sector/waypoint and ground callbacks are
isolated. The original candidate builder, model bounds reader, sweep/slide,
Euler, matrix rebuild, response and callback latch execute together.
"""
import json
import math
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig

OUT = ROOT / 'evidence/race-completion'
OUT.mkdir(parents=True, exist_ok=True)
live = json.loads((ROOT / 'evidence/gameplay/force-audit-live-contact.json').read_text())
manifest = json.loads((ROOT / 'public/assets/manifest.json').read_text())
bounds = {key: live['contacts'][0]['candidate'][key]
          for key in ['minX', 'maxX', 'minY', 'maxY', 'minZ', 'maxZ']}
radius = manifest['meshes']['kart03.d3d']['horizontalRadius']
f = lambda value: struct.unpack('<f', struct.pack('<f', value))[0]
FIELDS = {'lateralSpeed': 0x9c, 'verticalSpeed': 0xa0, 'forwardSpeed': 0xa4,
          'yawRate': 0xac, 'pitchRate': 0xa8, 'rollRate': 0xb0,
          'inverseMass': 0x90, 'inverseInertia': 0x94, 'restitution': 0x98}
FORCES = {'lateralForce': 0xb4, 'verticalForce': 0xb8,
          'longitudinalForce': 0xbc, 'torque': 0xc0}
POSE = {'pitch': 0x74, 'yaw': 0x78, 'roll': 0x7c}


def capture(p, index):
    base, render = OBJECT + index * 0xd0, SCRATCH + 0x4000 + index * 0xa9
    return {'position': [p.float(render + 0x50 + axis * 4) for axis in range(3)],
            **{key: p.float(render + offset) for key, offset in POSE.items()},
            **{key: p.float(base + offset) for key, offset in FIELDS.items()},
            'contactLatch': bool(p.integer(base + 0x4c))}


output = {'scope': __doc__, 'sourcePose': 'evidence/gameplay/force-audit-live-contact.json',
          'sourcePoseTimeMs': live['now'], 'bounds': bounds, 'radius': radius, 'cases': []}
for precision, cw in [(24, 0x7f), (53, 0x27f)]:
    p = NativeProbe(SOURCE)
    p.uc.reg_write(UC_X86_REG_FPCW, cw)
    initialize_native_trig(p)
    output['sourceSha256'] = p.sha
    # Body-list/geometry storage is constructed input, not a Windows loader.
    p.u32(0x67ee24, 2)
    p.u32(0x67ee30, SCRATCH + 0xa000)
    p.uc.mem_write(SCRATCH + 0xa000, b'\1\1')
    p.u32(0x680220, 187)
    p.u32(0x680b2c, 187)
    p.u32(0x680ad0, 1)
    p.u32(0x680ad8, 0)  # captured player, native eight-substep selector
    p.u32(0x6a5ee0, SCRATCH + 0xc000)
    # Geometry's bottom corners are read by original499630/4999c0.
    for offset, xyz in [
            (0x10, [bounds['minX'], bounds['minY'], bounds['minZ']]),
            (0x1c, [bounds['maxX'], bounds['minY'], bounds['minZ']]),
            (0x4c, [bounds['maxX'], bounds['minY'], bounds['maxZ']]),
            (0x40, [bounds['minX'], bounds['minY'], bounds['maxZ']])]:
        for axis, value in enumerate(xyz):
            p.f32(SCRATCH + 0xc000 + offset + axis * 4, value)
    p.f32(SCRATCH + 0xc074, radius)
    for address in [0x493860, 0x4932e0, 0x4937e0, 0x4936a0]:
        p.uc.mem_write(address, b'\xc3')
    events = []

    def hook(uc, address, size, unused):
        if address == 0x499c30:
            sp = uc.reg_read(UC_X86_REG_ESP)
            events.append(['sweep', p.integer(sp + 4)])
        elif address == 0x4911a0:
            events.append(['euler', (uc.reg_read(UC_X86_REG_ECX) - OBJECT) // 0xd0])
        elif address == 0x49c4f0:
            events.append(['response', bool(p.integer(0x6a5b58)),
                           p.integer(0x6a5b60), p.integer(0x6a5b64)])

    p.uc.hook_add(UC_HOOK_CODE, hook)
    for direction in range(8):
        p.uc.mem_write(OBJECT, b'\0' * 0x1a0)
        p.uc.mem_write(SCRATCH + 0x4000, b'\0' * 0x152)
        p.uc.mem_write(0x67ee78, b'\0' * (0x67fe18 - 0x67ee78))
        p.uc.mem_write(0x6a5b58, b'\0' * 48)
        actors = []
        for index, original in enumerate([live['body'], live['contacts'][0]['candidate']['body']]):
            base, render = OBJECT + index * 0xd0, SCRATCH + 0x4000 + index * 0xa9
            for offset, value in [(0, 1), (4, 3), (0xc, index), (0x1c, original['sector']),
                                  (0x2c, 0xffffffff), (0x30, 0xffffffff), (0x44, 1),
                                  (0x48, 1), (0x50, 1)]:
                p.u32(base + offset, value)
            p.u32(0x67ee78 + index * 8, 1)
            p.u32(0x67ee7c + index * 8, index)
            p.u32(render, 1)
            p.u32(render + 0x99, 0)
            for axis, value in enumerate(original['position']):
                if direction >= 4 and index == 0 and axis == 2:
                    value -= [10, 20, 40, 80][direction - 4]
                p.f32(render + 0x50 + axis * 4, value)
            for key, offset in POSE.items():
                p.f32(render + offset, original.get(key, 0))
            for offset in [0x80, 0x84, 0x88]:
                p.f32(render + offset, 1)
            inertia = f(f(f(600 * f(.083333336)) * f(f(4.5 * 4.5) + f(1.7 * 1.7))))
            values = {'inverseMass': f(1 / 600), 'inverseInertia': f(1 / inertia),
                      'restitution': f(.2), 'verticalSpeed': 0, 'pitchRate': 0, 'rollRate': 0,
                      **{key: original[key] for key in ['lateralSpeed', 'forwardSpeed', 'yawRate']}}
            if direction & 1 and index == 0:
                values['forwardSpeed'] *= -1
            if direction & 2 and index == 0:
                values['lateralSpeed'] *= -1
            if direction >= 4:
                values['yawRate'] = 0
                if index == 1:
                    values['lateralSpeed'] = values['forwardSpeed'] = 0
                else:
                    # Controlled approach to the same opponent geometry.
                    # It is a probe input, not an altered in-game trajectory.
                    dx = live['contacts'][0]['candidate']['body']['position'][0] - original['position'][0]
                    dz = live['contacts'][0]['candidate']['body']['position'][2] - (
                        original['position'][2] - [10, 20, 40, 80][direction - 4])
                    length = math.hypot(dx, dz)
                    vx, vz = dx / length * 20, dz / length * 20
                    angle = original['yaw'] * math.pi / 2048
                    values['lateralSpeed'] = f(math.cos(angle) * vx + math.sin(angle) * vz)
                    values['forwardSpeed'] = f(-math.sin(angle) * vx + math.cos(angle) * vz)
            for key, offset in FIELDS.items():
                p.f32(base + offset, values[key])
            actors.append(capture(p, index))
        # Zero and signed modest longitudinal forces are explicit controlled
        # continuation inputs; the source pose lacks the original force buffer.
        force = {'lateralForce': 0., 'verticalForce': 0.,
                 'longitudinalForce': [0., -2000., 2000., 0.][direction] if direction < 4 else 2000.,
                 'torque': [0., 0., 0., 500.][direction] if direction < 4 else 0.}
        case = {'precision': precision, 'variant': direction, 'actors': actors,
                'force': force, 'dt': f(.025), 'frames': []}
        for frame in range(32):
            p.f32(SCRATCH + 0x1000, case['dt'])
            for key, offset in FORCES.items():
                p.f32(OBJECT + offset, force[key])
                p.f32(OBJECT + 0xd0 + offset, 0)
            events.clear()
            p.run(0x491d30, [112, 20, 0])
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH, hex(p.uc.reg_read(UC_X86_REG_EIP))
            case['frames'].append({'actors': [capture(p, index) for index in range(2)],
                                   'impulse': p.float(0x6a5b80), 'events': list(events)})
        output['cases'].append(case)
        print('precision', precision, 'variant', direction, 'final',
              case['frames'][-1]['actors'][0]['position'], flush=True)
(OUT / 'france-native-frame-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
print('Executed', sum(len(case['frames']) for case in output['cases']), 'original composed collision frames.')
