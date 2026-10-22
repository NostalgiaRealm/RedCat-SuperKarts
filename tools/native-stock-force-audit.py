#!/usr/bin/env python3
"""Bounded stock kart audit: original gear/force instructions at fixed speed.

No race, integration, controls policy, timers or source artifact is changed.
The sign-change bracket is a flat/straight steady-force calculation, not a
measured top speed or proof that a kart is faster around a particular course.
"""
import hashlib
import json
import struct
import pefile
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

probe = NativeProbe(SOURCE)
for address in [0x53bef0, 0x53bef4, 0x53bf00, 0x53bdf4, 0x53bdf8, 0x53b9c0]:
    probe.u32(address, 0)
probe.f32(SCRATCH + 0x1000, .025)
probe.f32(SCRATCH + 0x4000 + 0x14, 0)
probe.f32(SCRATCH + 0x4000 + 0x34, 0)
rows = []
names = ['RedCat', 'WhizzKitty', 'Brutus', 'Max']
for record, name in enumerate(names):
    probe.set_physics(2, record)

    def sample(speed):
        probe.set_body(speed, 0, 0, 600)
        probe.run(0x415840, [0])
        for offset in [0xb4, 0xb8, 0xbc, 0xc0]:
            probe.f32(OBJECT + offset, 0)
        probe.run(0x415990, [0, 100., 0., 0.])
        return {'speed': probe.float(OBJECT + 0xa4), 'gear': probe.integer(0x507298),
                'rpm': probe.float(0x507290), 'longitudinalForce': probe.float(OBJECT + 0xbc)}

    samples = [sample(speed) for speed in [20, 40, 60, 70, 75]]
    low, high = 60., 80.
    for _ in range(26):
        middle = (low + high) / 2
        if sample(middle)['longitudinalForce'] > 0:
            low = middle
        else:
            high = middle
    rows.append({'record': record, 'character': name, 'samples': samples,
                 'equilibriumBracket': [sample(low), sample(high)]})

binary = SOURCE / 'rcskspel.dat'
data = binary.read_bytes()
pe = pefile.PE(str(binary))
pattern = struct.pack('<I', 0x432460)
pointer_occurrences = []
start = 0
while True:
    offset = data.find(pattern, start)
    if offset < 0:
        break
    pointer_occurrences.append(hex(pe.OPTIONAL_HEADER.ImageBase + pe.get_rva_from_offset(offset)))
    start = offset + 1
assembly_path = ROOT / 'evidence/native/rcskspel.dat/assembly.tsv'
assembly = assembly_path.read_text().splitlines()
incoming = [line for line in assembly if 'CALL 0x00432460' in line or 'JMP 0x00432460' in line]
turbo_writes = [line for line in assembly if 'MOV [0x0053bdf8]' in line
                or 'MOV dword ptr [0x0053bdf8]' in line]
report = {
    'format': 'native-stock-force-audit-v1',
    'scope': 'Original0x415840 then0x415990 executed at fixed flat/straight speeds in24-bit instruction emulation. No world integration or race. Force-sign brackets are not measured top speeds or lap-performance claims.',
    'inputs': {'physicsFile': 'Phys2.dat', 'records': [0, 1, 2, 3], 'motorUpgrade': 0,
               'tireUpgrade': 0, 'gearboxUpgrade': 0, 'throttle': 100, 'brake': 0,
               'steering': 0, 'handbrake': False, 'turbo': False, 'massInput': 600,
               'lateralSpeed': 0, 'yawRate': 0, 'matrix14': 0, 'matrix34': 0,
               'phase': 0, 'deltaSeconds': .025, 'precision': 24},
    'sourceSha256': {str(binary): sha(binary), str(SOURCE / 'Phys2.dat'): sha(SOURCE / 'Phys2.dat'),
                     'tools/native-stock-force-audit.py': sha(ROOT / 'tools/native-stock-force-audit.py'),
                     'tools/generate_native_gameplay_fixtures.py': sha(ROOT / 'tools/generate_native_gameplay_fixtures.py'),
                     'evidence/native/rcskspel.dat/assembly.tsv': sha(assembly_path),
                     'evidence/gameplay/native-bonus-fixtures.json': sha(ROOT / 'evidence/gameplay/native-bonus-fixtures.json'),
                     'evidence/native/startup-upgrades.json': sha(ROOT / 'evidence/native/startup-upgrades.json')},
    'rows': rows,
    'timedSettings': {'mode': 1, 'constructorAddress': '0x42a920', 'enabledBonuses': [],
                      'stockReset': '0x431ecd..0x431eeb',
                      'duelTableMultiplier': '0x4350d0 is called only when0x42abc0 returns3',
                      'analogThrottleLimit': '0x42ef90 clamps Y to0..100; active0x4341d0 maps Y>=50 to2*Y-100; maximum100',
                      'keyboardThrottleLimit': '0x433870 active model ramps70*dt and caps100'},
    'legacyTurbo': {'flag': '0x53bdf8', 'onlyNonzeroWriterFunction': '0x432460',
                    'decodedDirectIncomingCallsOrJumps': incoming,
                    'absolutePointerOccurrencesInOriginalPE': pointer_occurrences,
                    'decodedFlagWrites': turbo_writes,
                    'conclusion': 'No reachable stock input boost found in the reviewed active handlers. The force routine retains a dormant4000-force branch; the only nonzero writer has no decoded direct caller or stored absolute entry pointer. This bounded static search does not prove impossibility of arbitrary computed control flow.'},
}
path = ROOT / 'evidence/native/stock-force-audit.json'
path.write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'output': str(path), 'records': len(rows),
                  'equilibriumSpeeds': [row['equilibriumBracket'][0]['speed'] for row in rows],
                  'legacyTurboDirectCallers': len(incoming), 'legacyTurboPointers': len(pointer_occurrences)}))
