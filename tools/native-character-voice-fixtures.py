#!/usr/bin/env python3
"""Original voice selectors/dispatch; string allocation and queue boundaries stubbed."""
import json
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP

p = NativeProbe(SOURCE)
p.uc.mem_map(0, 4096)
rng = random.Random(0x4387e0)
strings, commands, animation_callbacks = {}, [], []
allocation = SCRATCH + 0x6000
collection_racer = None

def signed(value):
    return value if value < 0x80000000 else value - 0x100000000

def cstring(address):
    return bytes(p.uc.mem_read(address, 128)).split(b'\0')[0].decode('cp1252')

def string(address):
    pointer = p.integer(address + 4)
    return cstring(pointer) if pointer else strings.get(address, '')

def output_string(address, value):
    p.uc.mem_write(address, b'\0' * 16)
    strings[address] = value

def ret(value=0, pop=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4 + pop)

def hook(uc, address, size, data):
    global allocation
    sp = uc.reg_read(UC_X86_REG_ESP)
    if address == 0x4314a0:
        output = p.integer(sp + 4)
        output_string(output, str(signed(p.integer(sp + 8))))
        ret(output)
    elif address == 0x412710:
        output = p.integer(sp + 4)
        value = cstring(p.integer(sp + 8)) + string(p.integer(sp + 12))
        output_string(output, value)
        ret(output)
    elif address in [0x437b10, 0x437b40]:
        commands.append({'voiceId': p.integer(sp + 4), 'sample': string(p.integer(sp + 8)),
                         'replace': address == 0x437b40})
        ret(1, 8)
    elif address == 0x4371f0:
        ret(SCRATCH + 0x2000)
    elif address == 0x40b600:
        this = uc.reg_read(UC_X86_REG_ECX)
        length = p.integer(sp + 4)
        p.uc.mem_write(allocation, b'\x01' + b'\0' * (length + 1))
        p.u32(this + 4, allocation + 1)
        p.u32(this + 8, 0)
        p.u32(this + 12, length)
        strings.pop(this, None)
        allocation += (length + 33) & ~15
        ret(1, 8)
    elif address == 0x40b4f0:
        output_string(uc.reg_read(UC_X86_REG_ECX), '')
        ret(0, 4)
    elif address == 0x40b540:
        output_string(uc.reg_read(UC_X86_REG_ECX),
                      cstring(p.integer(sp + 4))[:p.integer(sp + 8)])
        ret(0, 8)
    elif address in [0x4bc150, 0x4afce0]:
        ret()
    elif address == 0x40eb20:
        ret(0, 4)
    elif address == 0x44a700:
        ret(SCRATCH + 0x3000, 4)
    elif address == SCRATCH + 0x3200:
        ret(0, 4)
    elif address == 0x4513c0:
        ret(SCRATCH + 0x4500)
    elif address == 0x451f70:
        ret(1000)
    elif address == 0x435a30:
        ret(SCRATCH + 0x5000)
    elif address in [0x48d610, 0x411a90, 0x481ec0, 0x411db0, 0x457730]:
        ret()
    elif address == 0x457780:
        ret(1, 4)
    elif collection_racer is not None and address == 0x452020:
        ret(SCRATCH + 0xa000, 4)
    elif collection_racer is not None and address in [0x40d610, 0x4362f0]:
        animation_callbacks.append({"callback": address, "racer": collection_racer,
                                    "randomState": p.integer(0x502978)})
        ret()
    elif collection_racer is not None and address in [0x4500e0, 0x4500c0, 0x4a09e0]:
        ret()
    elif collection_racer is not None and address == 0x410650:
        ret(1)
    elif collection_racer is not None and address == 0x44fc80:
        ret(int(p.integer(sp + 4) == collection_racer), 4)

p.uc.hook_add(UC_HOOK_CODE, hook)
p.u32(SCRATCH + 0x3000, SCRATCH + 0x3100)
p.u32(SCRATCH + 0x3100, SCRATCH + 0x3200)
p.uc.mem_write(SCRATCH + 0x3200, b'\xc2\x04\x00')
p.uc.mem_write(0x48f4d0, b'\xd9\x05' + struct.pack('<I', SCRATCH + 0x1000) + b'\xc3')
p.f32(SCRATCH + 0x1000, 10)

def begin(seed, roster):
    global allocation
    allocation = SCRATCH + 0x6000
    strings.clear()
    commands.clear()
    animation_callbacks.clear()
    p.u32(0x502978, seed)
    p.u32(0x508610, len(roster) - 1)
    p.u32(0x53bebc, roster[-1])
    for i, available in enumerate(roster[:-1]):
        p.u32(0x50820c + i * 0x70, available)

selectors = {
    'HIT': 0x437ff0, 'AMHIT': 0x438090, 'PASSING': 0x438130,
    'PASSED': 0x4381d0, 'BONUS': 0x438270, 'TURBO': 0x438310,
    'COMM0_3': 0x438480, 'COMM4_6': 0x438520,
    'COMM7_8': 0x4385c0, 'COMM9_20': 0x438670,
}
out = {'sourceSha256': p.sha,
       'scope': 'Original selectors, CRT draws, voice mapping and dispatch branches. String allocation/concatenation and queue submissions are boundary stubs; no sound-card playback claim.',
       'selectors': [], 'mapping': [], 'dispatch': [], 'npcCatchup': [],
       'rescue': [], 'hitEffects': [], 'collections': []}
for kind, function in selectors.items():
    for i in range(40):
        seed = rng.randrange(2**32)
        begin(seed, [0])
        p.run(function, [SCRATCH + 0x4000])
        out['selectors'].append({'kind': kind, 'seed': seed, 'sample': string(SCRATCH + 0x4000),
                                 'nextState': p.integer(0x502978)})

for i in range(80):
    roster = rng.sample(range(10), rng.randrange(1, 6))
    racer = rng.randrange(-1, len(roster) + 2)
    begin(0, roster)
    p.run(0x437ea0, [racer & 0xffffffff])
    out['mapping'].append({'roster': roster, 'racer': racer,
                           'expected': p.uc.reg_read(UC_X86_REG_EAX)})

for kind, function in [('replacePlayer', 0x438760), ('replaceRacer', 0x4387a0),
                       ('passing', 0x4387e0), ('playerHitOther', 0x437c40),
                       ('npcHit', 0x40d260), ('npcHitPlayer', 0x40de60),
                       ('pickupBefore', 0x4106b0)]:
    for i in range(80):
        seed = rng.randrange(2**32)
        roster = rng.sample(range(10), rng.randrange(2, 6))
        racer = rng.randrange(len(roster))
        other = rng.randrange(len(roster))
        shooter = [-1, 0, len(roster)-1][i % 3]
        mode = 9 if i % 4 == 0 else 0
        begin(seed, roster)
        output_string(SCRATCH + 0x4000, 'FIXED')
        p.u32(0x503ef4 + racer * 0x11c, mode)
        if kind == 'replacePlayer': args = [SCRATCH + 0x4000]
        elif kind == 'replaceRacer': args = [racer, SCRATCH + 0x4000]
        elif kind == 'passing': args = [racer, other]
        elif kind == 'playerHitOther': args = []
        elif kind == 'npcHit': args = [racer, shooter & 0xffffffff]
        else: args = [racer]
        try:
            p.run(function, args)
        except Exception:
            print('Dispatch failure', kind, i, hex(p.uc.reg_read(UC_X86_REG_EIP)),
                  hex(p.uc.reg_read(UC_X86_REG_ESP)))
            raise
        out['dispatch'].append({'kind': kind, 'seed': seed, 'roster': roster,
                                'racer': racer, 'other': other, 'shooter': shooter, 'mode': mode,
                                'commands': list(commands), 'nextState': p.integer(0x502978)})

for i in range(160):
    seed = rng.randrange(2**32)
    roster = rng.sample(range(10), 5)
    racer, mode, active = i % 4, (9 if i % 7 == 0 else 0), i % 3 != 0
    sector_count = 178
    player_sector = [0, 1, 88, 177][i % 4]
    sector = (player_sector + [-3, -2, -1, 0, 1, 2, 3][i % 7]) % sector_count
    begin(seed, roster)
    p.u32(0x503ef4 + racer * 0x11c, mode)
    p.u32(0x503ef0 + racer * 0x11c, racer)
    p.u32(0x53be28, 4)
    p.u32(OBJECT + racer * 0xd0 + 0x1c, sector)
    p.u32(OBJECT + 4 * 0xd0 + 0x1c, player_sector)
    p.u32(0x680b2c, sector_count)
    p.run(0x40d9c0, [racer, int(active)])
    out['npcCatchup'].append({'seed': seed, 'roster': roster, 'racer': racer,
                              'mode': mode, 'activated': active, 'sector': sector,
                              'playerSector': player_sector, 'sectorCount': sector_count,
                              'commands': list(commands), 'nextState': p.integer(0x502978)})

for i in range(120):
    seed = rng.randrange(2**32)
    roster = rng.sample(range(10), 5)
    racer, frame, shrinking = i % 6, [2, 3, 4][i // 6 % 3], bool(i // 18 % 2)
    begin(seed, roster)
    controller = SCRATCH + 0x8000
    p.uc.mem_write(controller, bytes(0x11b0))
    p.u32(controller + 0x1180, racer)
    p.u32(controller + 0x1194, frame)
    p.uc.mem_write(controller + 0x1198, bytes([shrinking]))
    p.u32(0x53be28, 4)
    for actor in range(6):
        p.u32(OBJECT + actor * 0xd0 + 0xc, actor)
        if actor < 4: p.u32(0x503ef0 + actor * 0x11c, actor)
    p.uc.reg_write(UC_X86_REG_ECX, controller)
    p.run(0x48ca60)
    out['rescue'].append({'seed': seed, 'roster': roster, 'racer': racer,
                         'frame': frame, 'shrinking': shrinking,
                         'commands': list(commands), 'nextState': p.integer(0x502978)})

for i in range(120):
    seed = rng.randrange(2**32)
    roster = rng.sample(range(10), 5)
    type_id, level, player = i % 4 + 1, i // 4 % 3 + 1, bool(i // 12 % 2)
    begin(seed, roster)
    state = SCRATCH + 0xa000
    p.uc.mem_write(state, bytes(0x120))
    p.u32(0x53be28, 0)
    p.u32(0x5081bc, 0)
    p.u32(OBJECT + 0xc, 0)
    for offset, value in [(0xa0, 0), (0xa4, level), (0xa8, type_id), (0xac, 3)]:
        p.u32(state + offset, value)
    p.f32(state + 0xb8, 15)
    p.f32(OBJECT + 0xa4, 15)
    p.f32(0x543d40 + type_id * 0x60 + level * 0x20, 2)
    p.f32(0x543d40 + type_id * 0x60 + level * 0x20 + 0x14, 0.3)
    try:
        p.run({1: 0x411830, 2: 0x411b40, 3: 0x411e50, 4: 0x412090}[type_id],
              [4 if player else 0, state, level])
    except Exception:
        print('Effect failure', type_id, level, player,
              hex(p.uc.reg_read(UC_X86_REG_EIP)), hex(p.uc.reg_read(UC_X86_REG_ESP)))
        raise
    out['hitEffects'].append({'seed': seed, 'type': type_id, 'level': level,
                             'player': player, 'commands': list(commands),
                             'nextState': p.integer(0x502978)})

def initialize_bonus(address, value):
    p.uc.mem_write(address, bytes(32))
    for offset, key in [(4, 'type'), (8, 'state'), (24, 'level')]:
        p.u32(address + offset, value[key])
    p.f32(address + 28, value['ageSeconds'])

def read_bonus(address):
    return {'type': p.integer(address + 4), 'state': p.integer(address + 8),
            'level': p.integer(address + 24), 'ageSeconds': p.float(address + 28)}

collections = json.loads((ROOT / 'evidence/gameplay/native-bonus-fixtures.json').read_text())['collections']
for f in collections[:140]:
    seed, roster = f['seed'], [4, 5, 6, 7, 0]
    # Static stars only test the player in the real contact dispatcher.
    collection_racer = 4 if f['player'] or f['pickup']['type'] == 6 else 0
    begin(seed, roster)
    initialize_bonus(SCRATCH + 0xa000, f['owned'])
    initialize_bonus(SCRATCH + 0xa100, f['pickup'])
    p.u32(0x543d14, 3)
    p.u32(0x543d24, SCRATCH + 0x4500)
    p.u32(0x543d20, 1 + int(f['owned']['state'] == 2))
    p.u32(SCRATCH + 0x4504, f['stars'])
    p.u32(0x53be28, 0)
    p.u32(OBJECT + 0xc, 0)
    p.uc.reg_write(UC_X86_REG_ECX, SCRATCH + 0xa100)
    p.run(0x4540c0)
    out['collections'].append({**{key: f[key] for key in ['seed', 'pickup', 'owned', 'stars']},
        'roster': roster, 'racer': collection_racer, 'commands': list(commands),
        'animationCallbacks': list(animation_callbacks),
        'expected': {'pickup': read_bonus(SCRATCH + 0xa100),
                     'owned': read_bonus(SCRATCH + 0xa000), 'stars': p.integer(SCRATCH + 0x4504),
                     'nextState': p.integer(0x502978)}})

(ROOT / 'evidence/native/character-voice-fixtures.json').write_text(json.dumps(out, indent=2) + '\n')
print('Wrote', {key: len(value) for key, value in out.items() if isinstance(value, list)})
