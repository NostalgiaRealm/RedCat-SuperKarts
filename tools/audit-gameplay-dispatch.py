#!/usr/bin/env python3
"""Inventory shipped marker dispatch against the original PE and course files.

This records bounded static source coverage, not complete gameplay equivalence.
It verifies public marker records against fresh parses of the originals.
"""
import hashlib
import json
import struct
from collections import Counter
from pathlib import Path
import pefile
from lib.superkarts_formats import route, drive

ROOT = Path(__file__).resolve().parents[1]
SOURCE = Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data')
sha = lambda data: hashlib.sha256(data).hexdigest()


def main():
    files = {path.name.lower(): path for path in SOURCE.iterdir() if path.is_file()}
    binary = files['rcskspel.dat'].read_bytes()
    pe = pefile.PE(data=binary)
    image = pe.get_memory_mapped_image()
    image_base = pe.OPTIONAL_HEADER.ImageBase
    # Checked against4938e0's two-slot dispatch and the corresponding callers.
    handlers = {
        9: ('native-race.js', 'zero-sector progress flag'),
        13: (None, 'original callback is a single RET'),
        14: ('native-race.js', 'finish/lap callback'),
        15: ('native-race.js', 'arm the finish line'),
        49: ('native-jump.js', 'forward jump; current DMP49 and facing guard'),
        52: ('native-jump.js', 'reverse jump; current DMP52 and facing guard'),
        54: ('native-race.js', 'original notification9; no invented text'),
        61: (None, 'NULL callback; strength data for jump49/52'),
        74: ('native-race.js', 'timed gate'),
        75: ('native-race.js', 'timed gate'),
        76: ('native-race.js', 'timed gate'),
        79: ('native-weather.js', 'pause weather'),
        80: ('native-weather.js', 'resume weather'),
        83: ('native-weather.js', 'rain-data control'),
        86: ('native-weather.js', 'pause snow'),
        87: ('native-weather.js', 'resume snow'),
    }
    tracks, pmp_all, dmp_all = [], Counter(), Counter()
    for index in range(6):
        path = ROOT / f'public/assets/tracks/etappe{index}.json'
        converted_bytes = path.read_bytes()
        converted = json.loads(converted_bytes)
        original_pmp = files[f'etappe{index}.pmp'].read_bytes()
        original_dmp = files[f'etappe{index}.dmp'].read_bytes()
        original_route, original_drive = route(original_pmp), drive(original_dmp)
        assert original_route == converted['route'], f'Track{index} route differs from original'
        assert original_drive == converted['drive'], f'Track{index} drive graph differs from original'
        assert sha(original_pmp) == converted['source']['pmp']
        assert sha(original_dmp) == converted['source']['dmp']
        pmp = Counter(marker for sector in original_route
                      for marker in [sector['trigger'], sector['unknown']] if marker > 0)
        dmp = Counter(node['unknown'][1] for node in original_drive if node['unknown'][1] > 0)
        pmp_all.update(pmp)
        dmp_all.update(dmp)
        tracks.append({'track': index, 'name': converted['name'], 'originalPmpSha256': sha(original_pmp),
                       'originalDmpSha256': sha(original_dmp), 'convertedSha256': sha(converted_bytes),
                       'allRouteAndDriveRecordsMatchOriginal': True,
                       'pmpMarkers': dict(sorted(pmp.items())), 'dmpMarkers': dict(sorted(dmp.items()))})
    markers = []
    for marker, count in sorted(pmp_all.items()):
        address = struct.unpack_from('<I', image, 0x4ecd80 - image_base + marker * 4)[0]
        module, behavior = handlers[marker]
        if marker == 13:
            assert image[address - image_base] == 0xc3
        if marker == 61:
            assert address == 0
        if module:
            assert address and (ROOT / 'source/simulation' / module).is_file()
        markers.append({'marker': marker, 'placements': count, 'nativeCallback': f'0x{address:08x}',
                        'portModule': f'source/simulation/{module}' if module else None,
                        'reviewedDisposition': behavior})
    output = {'format': 'superkarts-gameplay-dispatch-audit-v1', 'date': '2026-10-26',
              'scope': __doc__.strip(), 'originalBinary': str(files['rcskspel.dat']),
              'originalBinarySha256': sha(binary), 'nativePlayerTable': '0x4ecd80',
              'nativeDispatch': '0x4938e0', 'nativeNpcDispatch': '0x406470/0x4067e0',
              'allShippedPositivePmpMarkersAccountedFor': set(pmp_all) == set(handlers),
              'pmpMarkers': markers, 'dmpMarkers': dict(sorted(dmp_all.items())),
              'dmpReview': {'49/52': 'Player jump guards read current waypoint; NPC marker switch has no jump case.',
                            '50/51': 'Environment-rescue predicate48c030 and return scan48bf80, before both racer callbacks.',
                            '68': 'NPC40b0b0 multiplies three linear velocities by float32(.98); player41cb80 is RET.',
                            '69-73': '415dd0 scans start positions; not a per-update effect.',
                            '1/55-57/79-80/255': 'No active effect in the NPC406470 switch; player weather79/80 is dispatched from PMP.'},
              'tracks': tracks}
    path = ROOT / 'evidence/full-source-audit/gameplay-dispatch.json'
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(output, indent=2) + '\n')
    print(f'All six route/drive graphs match originals; {len(markers)} positive PMP markers accounted for.')


if __name__ == '__main__':
    main()
