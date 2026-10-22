#!/usr/bin/env python3
"""Original homing-arm initialization, geometry, ratio and retirement instructions."""
import json
import math
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_EBP, UC_X86_REG_FPCW

p = NativeProbe(SOURCE)
p.uc.mem_map(0, 4096)
initialize_native_trig(p)
controller, shot, point = SCRATCH + 0x7000, SCRATCH + 0x8000, SCRATCH + 0x9000
ratio = 0
manager_probe, manager_updates, draw_calls = False, [], []

def fp(value): return struct.unpack('<f', struct.pack('<f', value))[0]
def ret(value=0, pop=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX, value)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4 + pop)

def hook(uc, address, size, data):
    global ratio
    if address == 0x44fbf0: ret(point)
    elif address == 0x4a6060: ret(0, 4)
    elif address == 0x4873f8:
        ratio = p.float(uc.reg_read(UC_X86_REG_ESP) + 0x14)
        # Audio timer/queue branch is independently executed in the 960-case
        # native-arm-audio fixture; this probe retains all preceding geometry
        # and the following native active/scale limit.
        uc.reg_write(UC_X86_REG_EIP, 0x4876fb)
    elif manager_probe and address == 0x487740:
        entry = uc.reg_read(UC_X86_REG_ECX)
        manager_updates.append(p.integer(entry + 0x720))
        p.u32(entry + 0x774, p.integer(entry + 0x774) + 1)
        ret(p.integer(entry + 0x770))
    elif address == SCRATCH + 0xa600:
        ret((p.integer(SCRATCH + 0xa108) - p.integer(SCRATCH + 0xa104)) // 0x794)
    elif address == SCRATCH + 0xa610:
        ret(p.integer(SCRATCH + 0xa108) - 0x794)
    elif address == SCRATCH + 0xa200:
        sp = uc.reg_read(UC_X86_REG_ESP)
        draw_calls.append({'state': p.integer(sp + 8), 'value': p.integer(sp + 12)})
        ret(0, 12)
    elif address == SCRATCH + 0xa210:
        ret(0, 12)
    elif address == SCRATCH + 0xa220:
        sp = uc.reg_read(UC_X86_REG_ESP)
        draw_calls.append({'primitive': p.integer(sp + 8), 'vertexType': p.integer(sp + 12),
                           'offset': p.integer(sp + 16) - controller,
                           'count': p.integer(sp + 20), 'flags': p.integer(sp + 24)})
        ret(0, 24)

p.uc.hook_add(UC_HOOK_CODE, hook)
p.run(0x486a10)
vertices = [[p.float(0x5450d0 + vertex * 12 + axis * 4) for axis in range(3)] for vertex in range(3)]
constants = {hex(a): p.float(a) for a in [0x4d2f50, 0x4d2c54, 0x4d23e0, 0x4d2570]}
p.u32(0x508610, 4)
p.u32(0x53be28, 4)
for actor in range(5):
    p.u32(0x5081bc + actor * 0x70, actor)
    p.u32(OBJECT + actor * 0xd0 + 0xc, actor)

def write_position(actor, position):
    render = SCRATCH + 0x4000 + actor * 0xa9
    for axis, value in enumerate(position): p.f32(render + 0x50 + axis * 4, value)

def snapshot():
    return {
        'active': bool(p.uc.mem_read(controller + 0x724, 1)[0]),
        'body': p.integer(controller + 0x720),
        'scale': p.float(controller + 0x76c),
        'count': p.integer(controller + 0x770),
        'growthAngle': p.float(controller + 0x774),
        'angle': p.float(controller + 0x778),
        'initialDistanceSquared': p.float(controller + 0x77c),
        'colors': [p.integer(controller + 0x784 + i * 4) for i in range(3)],
        'vertices': [{
            'position': [p.float(controller + side * 0x300 + vertex * 0x20 + axis * 4) for axis in range(3)],
            'color': p.integer(controller + side * 0x300 + vertex * 0x20 + 0x10),
            'specular': p.integer(controller + side * 0x300 + vertex * 0x20 + 0x14),
            'uv': [p.float(controller + side * 0x300 + vertex * 0x20 + 0x18 + axis * 4) for axis in range(2)],
        } for side in range(2) for vertex in range(24)],
    }

rng = random.Random(0x486ea0)
rows = []
for precision in [24, 53]:
    p.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
    p.uc.mem_unmap(0x22000000, 0x8000)
    initialize_native_trig(p)
    for case in range(180):
        target = [-2, -1, 0, 1, 2, 3, 4, 5][case % 8]
        body_id = target if 0 <= target < 4 else 4
        origin = [fp(rng.uniform(-5000, 5000)) for _ in range(3)]
        projectile = [fp(origin[axis] + rng.uniform(-500, 500)) for axis in range(3)]
        if case % 90 < 2: projectile = list(origin)
        p.uc.mem_write(controller, bytes(0x794))
        p.uc.mem_write(shot, bytes(0x40))
        p.u32(shot + 0x24, target & 0xffffffff)
        for axis, value in enumerate(projectile): p.f32(point + axis * 4, value)
        for axis, value in enumerate([0, 25, -33]): p.f32(point + 0x40 + axis * 4, value)
        write_position(body_id, origin)
        p.uc.reg_write(UC_X86_REG_ECX, controller)
        p.run(0x486ac0)
        p.uc.reg_write(UC_X86_REG_ECX, controller)
        p.run(0x486b20, [shot, point + 0x40, 10.0])
        initial = snapshot()
        state = {'count': [2, 3, 7, 8][case % 4],
                 'growthAngle': fp(rng.choice([0, 500, 512, 4095])),
                 'angle': fp(rng.choice([0, 100, 4090])),
                 'scale': fp(rng.uniform(0.1, 1.5)),
                 'colors': [rng.randrange(10000) for _ in range(3)]}
        for offset, key in [(0x76c, 'scale'), (0x774, 'growthAngle'), (0x778, 'angle')]:
            p.f32(controller + offset, state[key])
        p.u32(controller + 0x770, state['count'])
        for index, color in enumerate(state['colors']): p.u32(controller + 0x784 + index * 4, color)
        delta = fp(rng.choice([.001, .025, .03125, .1]))
        position = [fp(origin[axis] + rng.uniform(-250, 250)) for axis in range(3)]
        if case % 90 == 0: position = list(origin)
        write_position(body_id, position)
        yaw = rng.randrange(4096)
        # Execute an original X rotation and add the render world translation.
        p.run(0x4a2200, [point + 0x100, yaw])
        matrix = [p.float(point + 0x100 + i * 4) for i in range(16)]
        matrix[12:15] = position
        render = SCRATCH + 0x4000 + body_id * 0xa9
        for i, value in enumerate(matrix): p.f32(render + 0x10 + i * 4, value)
        p.f32(SCRATCH + 0x1000, delta)
        p.uc.reg_write(UC_X86_REG_ECX, controller)
        p.run(0x487740)
        rows.append({'precision': precision, 'target': target, 'origin': origin,
                     'shotPosition': projectile, 'initial': initial,
                     'state': state, 'deltaSeconds': delta, 'bodyPosition': position,
                     'matrix': matrix, 'ratio': ratio if math.isfinite(ratio) else str(ratio),
                     'expected': snapshot()})

managers = []
manager_probe = True
p.u32(SCRATCH + 0xa000, SCRATCH + 0xa400)
p.u32(SCRATCH + 0xa004, SCRATCH + 0xa100)
p.u32(SCRATCH + 0xa400, SCRATCH + 0xa600)
p.u32(SCRATCH + 0xa408, SCRATCH + 0xa610)
for flags in [[0], [0, 0, 0], [1, 0, 0], [0, 1, 0], [0, 0, 1], [1, 0, 1]]:
    manager_updates = []
    p.u32(0x53ba78, 1); p.u32(0x53ba60, 1); p.u32(0x53b9b0, 0)
    p.u32(SCRATCH + 0xa104, SCRATCH + 0xb000)
    p.u32(SCRATCH + 0xa108, SCRATCH + 0xb000 + len(flags) * 0x794)
    for index, flag in enumerate(flags):
        entry = SCRATCH + 0xb000 + index * 0x794
        p.uc.mem_write(entry, bytes(0x794))
        p.u32(entry + 0x720, index)
        p.u32(entry + 0x770, flag)
    p.uc.reg_write(UC_X86_REG_ECX, SCRATCH + 0xa000)
    p.run(0x4879c0)
    count = (p.integer(SCRATCH + 0xa108) - (SCRATCH + 0xb000)) // 0x794
    managers.append({'flags': flags, 'updates': list(manager_updates),
        'remaining': [{'id': p.integer(SCRATCH + 0xb000 + index * 0x794 + 0x720),
                       'updates': p.integer(SCRATCH + 0xb000 + index * 0x794 + 0x774)}
                      for index in range(count)]})
manager_probe = False

p.u32(0x6a621c, SCRATCH + 0xa100)
p.u32(SCRATCH + 0xa100, SCRATCH + 0xa000)
for offset, pointer in [(0x5c, 0xa200), (0x68, 0xa210), (0x74, 0xa220)]:
    p.u32(SCRATCH + 0xa000 + offset, SCRATCH + pointer)
p.u32(0x6a6290, SCRATCH + 0xa400); p.u32(0x4fd9fc, 0)
p.u32(SCRATCH + 0xa400, SCRATCH + 0xa300)
p.u32(SCRATCH + 0xa35c, 0)
p.u32(0x6a5e80, SCRATCH + 0xa500)
p.u32(0x5450f4, 0); p.u32(0x6a6254, 0)
draws = []
for active in [False, True]:
    for count in [2, 8]:
        draw_calls = []
        p.uc.mem_write(controller + 0x724, bytes([active]))
        p.u32(controller + 0x770, count)
        p.u32(controller + 0x734, 3)
        p.uc.reg_write(UC_X86_REG_ECX, controller)
        p.run(0x487780)
        draws.append({'active': active, 'growthCount': count, 'calls': list(draw_calls)})

(ROOT / 'evidence/native/arm-fixtures.json').write_text(json.dumps({
    'sourceSha256': p.sha,
    'scope': 'Original486ac0,486b20,487740 including486ea0 geometry,486d50 colors and486cc0 UV. Texture lookup/shot position are boundary adapters. Sound branch has its separate960 native fixtures. Uninitialized vertex storage is zeroed explicitly in this probe.',
    'vertices': vertices, 'constants': constants, 'rows': rows,
    'managers': managers, 'draws': draws,
}, indent=2) + '\n')
print('Wrote', len(rows), 'original arm initialization/update cases', vertices, constants)
