#!/usr/bin/env python3
"""Read-only native/source inventory; this does not execute the original game."""
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE = Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data')
assembly = ROOT / 'evidence/native/rcskspel.dat/assembly.tsv'
rows = [line.split('\t') for line in assembly.read_text().splitlines()[1:]]
calls = []
for index, row in enumerate(rows):
    if row[2] not in ('CALL 0x00430610', 'JMP 0x00430610'):
        continue
    preceding = rows[max(0, index - 4):index]
    immediate = next((re.fullmatch(r'PUSH 0x([0-9a-f]+)', item[2])
                      for item in reversed(preceding)
                      if re.fullmatch(r'PUSH 0x([0-9a-f]+)', item[2])), None)
    calls.append({'address': row[0], 'caller': row[3],
                  'id': int(immediate.group(1), 16) if immediate else None,
                  'instructions': [{'address': item[0], 'instruction': item[2]}
                                   for item in preceding + [row]]})

config = json.loads((ROOT / 'public/assets/config.json').read_text())
markers = {}
for track in range(6):
    data = json.loads((ROOT / f'public/assets/tracks/etappe{track}.json').read_text())
    markers[track] = {str(marker): [index for index, sector in enumerate(data['route'])
                                  if marker in (sector['trigger'], sector['unknown'])]
                      for marker in (45, 54, 74, 75, 76)}
files = [SOURCE / name for name in ('rcskspel.dat', 'SndGfx.ini', 'overlay.ini', 'language.ini', 'ini/game.ini')]
files += [assembly, ROOT / 'public/assets/config.json']
files += [ROOT / f'public/assets/tracks/etappe{track}.json' for track in range(6)]
payload = {
    'scope': 'Static retained x86 callsite inventory and shipped configuration. No native process or full-game render was observed.',
    'inputs': [{'path': str(path), 'sha256': hashlib.sha256(path.read_bytes()).hexdigest()} for path in files],
    'dispatcher': '00430610', 'directCallsites': calls,
    'idsWithoutDirectCallsites': [value for value in range(12) if value not in {row['id'] for row in calls}],
    'dispatchId3And10Scope': 'Cases exist in the dispatcher; no direct caller in retained assembly. Do not infer activation from translated strings or pickups.',
    'languageDirectCallers': [dict(address=row[0], caller=row[3]) for row in rows if row[2] == 'CALL 0x00443b40'],
    'routeMarkerSectors': markers,
    'countdownFlare': {
        'registryComments': [line.strip() for line in (SOURCE / 'overlay.ini').read_text(errors='replace').splitlines()
                             if 'flare' in line.lower()],
        'controller': '00464760 looks up only 321Timer0..2; 00464a00/00464a70/00464e90/00464f30 loop over those three pointers.',
    },
    'requester': {
        'activeFile': str(SOURCE / 'SndGfx.ini'), 'loader': '00470860',
        'active': config['sndgfx.ini']['stoppen'],
        'olderUnusedConfig': {'file': str(SOURCE / 'ini/game.ini'), 'section': config['ini/game.ini']['stoppen']},
        'conclusion': 'Active RC and text slots duplicate the same 115x38 Ja/Nee art and coordinates; q_rc* illustrations belong to the older config, not the active loader.',
    },
}
target = ROOT / 'evidence/native/hud-notice-audit.json'
target.write_text(json.dumps(payload, indent=2) + '\n')
print(f'{len(calls)} direct dispatcher calls; absent IDs {payload["idsWithoutDirectCallsites"]}; {target}')
