#!/usr/bin/env python3
"""Execute original shadow initialization; verify original shadow pixels/mesh."""
import hashlib
import json
import subprocess
from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH


def main():
    manifest = json.loads((ROOT / 'public/assets/manifest.json').read_text())
    output = {'method': __doc__, 'initializers': [], 'assets': []}
    # The original function performs all four diffuse/specular/UV writes.
    # Only named-object lookup and allocation are replaced with object ID 0.
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        output['sourceSha256'] = p.sha
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        p.uc.mem_write(0x4a6200, b'\x31\xc0\xc2\x04\x00')
        p.uc.mem_write(0x4a02b0, b'\x31\xc0\xc3')
        p.u32(0x6a5f78, SCRATCH + 0x5000)
        p.u32(SCRATCH + 0x5004, SCRATCH + 0x5100)
        p.u32(0x6a5f30, SCRATCH + 0x5200)
        p.u32(0x6a5ee0, SCRATCH + 0x5300)
        p.u32(SCRATCH + 0x5384, 4)
        p.u32(SCRATCH + 0x5380, SCRATCH + 0x5400)
        p.u32(0x6a5e80, SCRATCH + 0x5500)
        for width in [16, 32, 64, 128, 256]:
            p.u32(SCRATCH + 0x5524, width)
            p.uc.mem_write(SCRATCH + 0x5400, bytes(128))
            p.run(0x416270)
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            output['initializers'].append({'precision': precision, 'width': width,
                'uv': [p.float(SCRATCH + 0x5400 + vertex * 32 + axis)
                       for vertex in range(4) for axis in [24, 28]],
                'diffuse': [p.integer(SCRATCH + 0x5410 + vertex * 32) for vertex in range(4)],
                'specular': [p.integer(SCRATCH + 0x5414 + vertex * 32) for vertex in range(4)]})
    archive = next(path for path in SOURCE.iterdir() if path.name.lower() == 'rcs.img')
    with archive.open('rb') as stream:
        for entry in manifest['archives']['rcs']['entries']:
            if entry['name'].lower() not in ['s_shadow.tga', 's_shadow.d3d', 's_shadow.pcx']:
                continue
            stream.seek(entry['offset'])
            original = stream.read(entry['length'])
            sha = hashlib.sha256(original).hexdigest()
            assert sha == entry['sha256']
            assert original == (ROOT / 'raw/extracted/rcs' / entry['filename']).read_bytes()
            row = {'name': entry['name'], 'archiveIndex': entry['index'], 'sha256': sha,
                   'bytes': len(original), 'extractedBytesEqual': True}
            if entry['name'].lower().endswith('.tga'):
                # The asset-preparation Python owns Pillow; re-python owns
                # Unicorn. Keep the two existing runtimes separate.
                decoded = subprocess.check_output(['python3', '-c', '''
import io,json,sys
from PIL import Image
image=Image.open(io.BytesIO(sys.stdin.buffer.read())).convert('RGB')
pixels=list(image.getdata())
generated=Image.open(sys.argv[1]).convert('RGBA')
expected=[(r,g,b,0 if (r,g,b)==(255,0,127) else 255) for r,g,b in pixels]
assert list(generated.getdata())==expected
print(json.dumps({'size':image.size,'sourceColors':sorted(set(pixels)),
 'keyPixels':pixels.count((255,0,127)),'blackPixels':pixels.count((0,0,0)),
 'convertedRGBAndExactKeyMatch':True}))
''', str(ROOT / 'public/assets/textures/s_shadow.tga.png')], input=original)
                row.update(json.loads(decoded))
            output['assets'].append(row)
    path = ROOT / 'evidence/shadow-audit/native.json'
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(output, indent=2) + '\n')
    print(f"Passed {len(output['initializers'])} original initializers and {len(output['assets'])} archived shadow assets.")


if __name__ == '__main__':
    main()
