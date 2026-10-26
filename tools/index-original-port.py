#!/usr/bin/env python3
"""Index explicit native addresses in port comments against recovered functions.

This is a navigation aid, not a behavioral coverage score. The executables
share address ranges, so ambiguous module matches remain explicit.
"""
import csv
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
functions = []
for index in sorted((ROOT / 'original-source/modules').glob('*/functions.tsv')):
    for row in csv.DictReader(index.open(), delimiter='\t'):
        ranges = [tuple(int(part, 16) for part in span.split('-'))
                  for span in row['body_ranges'].split(';') if span]
        functions.append({'module': index.parent.name, 'address': row['address'],
            'name': row['name'], 'source': str((index.parent / row['file']).relative_to(ROOT)),
            'ranges': ranges})
pattern = re.compile(r'(?<![\w])(?:0x([0-9a-fA-F]{5,8})|((?:00)?[4-6][0-9a-fA-F]{5}))(?![\w])')
references, hashes = [], {}
for source in sorted((ROOT / 'source').rglob('*.js')):
    relative = str(source.relative_to(ROOT))
    data = source.read_text()
    hashes[relative] = hashlib.sha256(source.read_bytes()).hexdigest()
    block = False
    for number, line in enumerate(data.splitlines(), 1):
        # Only inspect comment text; do not mislabel numeric runtime constants
        # as a claim to implement a function at that address.
        comment = line if block else line.split('//', 1)[1] if '//' in line else line.split('/*', 1)[1] if '/*' in line else ''
        if '/*' in line:
            block = True
        if '*/' in line:
            block = False
        for match in pattern.finditer(comment):
            address = int(match.group(1) or match.group(2), 16)
            candidates = []
            for function in functions:
                if any(start <= address <= end for start, end in function['ranges']):
                    candidates.append({key: value for key, value in function.items() if key != 'ranges'} |
                        {'match': 'entry' if address == int(function['address'], 16) else 'instruction-range'})
            references.append({'portFile': relative, 'line': number,
                'address': f'{address:08x}', 'candidates': candidates,
                'interpretation': 'module-ambiguous' if len(candidates) > 1 else
                    'candidate' if candidates else 'data-or-unresolved-address'})
report = {'scope': __doc__, 'identifiedFunctions': len(functions),
    'referenceCount': len(references), 'references': references, 'sourceHashes': hashes,
    'limitations': ['A comment reference is not proof that its behavior is implemented or validated.',
        'A shared address may name different functions in different modules; inspect its caller and module.',
        'No match can mean data, an undiscovered function, a stale comment, or an interior gap.',
        'Numeric-only comments and partial shorthand addresses may be absent or ambiguous.']}
output = ROOT / 'docs/evidence/original-port-index.json'
output.write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'functions': len(functions), 'references': len(references), 'path': str(output.relative_to(ROOT))}))
