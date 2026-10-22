#!/usr/bin/env python3
"""Execute original texture-format choice, TGA loader and color-key conversion.

File bytes and DirectDraw allocation/locking are captured service boundaries.
The original TGA header/pixel reads, RGB packing and color conversion execute.
No driver filtering behavior is emulated or claimed by this fixture.
"""
import hashlib
import json
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, STACK

PIXELS = SCRATCH + 0x6000
FORMAT = SCRATCH + 0x3000
FORMATS = {
    'RGB565': [32, 0x40, 0, 16, 0xf800, 0x07e0, 0x001f, 0],
    'RGB555': [32, 0x40, 0, 16, 0x7c00, 0x03e0, 0x001f, 0],
}


class TextureProbe(NativeProbe):
    def __init__(self):
        super().__init__(SOURCE)
        self.file = b''
        self.offset = 0
        self.width = 0
        self.pack_calls = []
        self.u32(0x6ab7e8, 1)
        self.u32(0x4fe938, 16)
        self.u32(0x6ab468, SCRATCH + 0x4000)
        # Keep original source-key setter and pixel converter.
        self.run(0x4afdb0, [0x7f00ff])
        for address in [0x4afce0, 0x4bf930, 0x4b08e0, 0x4b0770, 0x4b08a0,
                        0x4b9840, 0x4b5ad0]:
            self.uc.mem_write(address, b'\xc3')
        for address, value in [(0x4b96d0, 0x1234), (0x4b0a10, 0x5678)]:
            self.uc.mem_write(address, b'\xb8' + struct.pack('<I', value) + b'\xc3')
        self.uc.hook_add(UC_HOOK_CODE, self.capture)

    def capture(self, uc, address, size, _):
        if address not in [0x4bf930, 0x4b0770, 0x4b5740]:
            return
        sp = uc.reg_read(UC_X86_REG_ESP)
        if address == 0x4bf930:
            destination, item_size, count = [self.integer(sp + 4 + i * 4) for i in range(3)]
            length = item_size * count
            data = self.file[self.offset:self.offset + length]
            assert len(data) == length, 'Original TGA loader read beyond controlled file'
            uc.mem_write(destination, data)
            self.offset += length
            uc.reg_write(UC_X86_REG_EAX, count)
        elif address == 0x4b0770:
            self.u32(self.integer(sp + 8), self.width * 2)
            uc.reg_write(UC_X86_REG_EAX, PIXELS)
        elif address == 0x4b5740:
            self.pack_calls.append({'color': self.integer(sp + 4), 'sourceBits': self.integer(sp + 8)})

    def load_tga(self, pixels, bits, pixel_format, gamma):
        self.width = len(pixels)
        header = bytearray(18)
        header[2] = 2
        struct.pack_into('<HH', header, 12, self.width, 1)
        header[16], header[17] = bits, 0x20 | (8 if bits == 32 else 0)
        self.file = bytes(header) + bytes(channel for r, g, b, a in pixels
                                         for channel in ([b, g, r, a] if bits == 32 else [b, g, r]))
        self.offset = 0
        self.pack_calls.clear()
        self.u32(0x6ab830, gamma)
        self.uc.mem_write(FORMAT, struct.pack('<8I', *pixel_format))
        self.uc.mem_write(SCRATCH + 0x100, b'fixture.tga\0')
        self.run(0x4ac010, [SCRATCH + 0x100, SCRATCH + 0x200, SCRATCH + 0x204, 0x1800, FORMAT])
        assert self.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        assert self.offset == len(self.file)
        assert self.integer(SCRATCH + 0x200) == self.width
        assert self.integer(SCRATCH + 0x204) == 1
        return list(struct.unpack(f'<{self.width}H', self.uc.mem_read(PIXELS, self.width * 2)))


def main():
    p = TextureProbe()
    report = {'format': 'superkarts-native-texture-key-v1', 'sourceSha256': p.sha,
              'method': __doc__, 'formatSelection': [], 'uploads': [], 'quantizationGrids': []}
    report['initialKeyComponents'] = [p.integer(address) for address in [0x6ab774, 0x6ab778, 0x6ab77c]]
    assert report['initialKeyComponents'] == [0, 0, 0]
    report['keyPaletteIndex'] = p.integer(0x4fc9d8)
    assert report['keyPaletteIndex'] == 254
    # Original initializer branch and original format selector. Device format
    # enumeration is represented by three distinct indices to identify choice.
    for address, value in [(0x6a63d2, 102), (0x6a63da, 103), (0x6a63d6, 104)]:
        p.u32(address, value)
    for bpp in [8, 16, 24, 32]:
        p.u32(0x4fe938, bpp)
        p.uc.reg_write(UC_X86_REG_ESP, STACK + 0xf000)
        p.uc.emu_start(0x4ac4d9, 0x4ac4ef, count=10000)
        chosen = p.integer(0x6a63de)
        assert chosen == (102 if bpp <= 8 else 103)
        report['formatSelection'].append({'screenBits': bpp, 'selectedFormat': chosen - 100,
                                          'selectedAlpha': chosen == 104})
    p.u32(0x4fe938, 16)
    samples = [(255, 0, 127, 255), (255, 0, 127, 0), (0, 0, 0, 255),
               (0, 0, 0, 0), (1, 1, 1, 128), (254, 0, 127, 64),
               (255, 1, 127, 192), (40, 120, 200, 0), (40, 120, 200, 64),
               (40, 120, 200, 128), (40, 120, 200, 255), (255, 255, 255, 0)]
    for name, pixel_format in FORMATS.items():
        for gamma in [0, 1]:
            values = {}
            for bits in [24, 32]:
                uploaded = p.load_tga(samples, bits, pixel_format, gamma)
                values[bits] = uploaded
                assert uploaded[0] == uploaded[1] == 0
                assert uploaded[2] == uploaded[3] != 0
                assert uploaded[7] == uploaded[8] == uploaded[9] == uploaded[10]
                assert all(call['sourceBits'] == 24 for call in p.pack_calls)
                # 4a4a30 obtains the hardware key from palette entry254.
                p.run(0x4a4a30, [SCRATCH + 0x280])
                key_range = [p.integer(SCRATCH + 0x280 + offset) for offset in [0, 4]]
                assert key_range == [0, 0]
                report['uploads'].append({'pixelFormat': name, 'screenBits': 16,
                    'gamma': gamma, 'sourceBits': bits, 'sourceRGBA': samples,
                    'packedPixels': uploaded, 'conversionCalls': p.pack_calls[:len(samples)],
                    'keyRange': key_range, 'sourceDigest': hashlib.sha256(p.file).hexdigest()})
            assert values[24] == values[32], 'Active RGB format must ignore TGA alpha'
            # Exhaust the RGB cube that would quantize to black or to pink
            # under a naive direct pack. Native conversion protects nonkey
            # black and compares the unquantized source to the exact key.
            green_values = range(4 if name == 'RGB565' else 8)
            red_unit = 0x800 if name == 'RGB565' else 0x400
            for label, red_values, blue_values in [
                    ('nearBlack', range(8), range(8)),
                    ('nearPink', range(248, 256), range(120, 128))]:
                cases = []
                for red in red_values:
                    for green in green_values:
                        for blue in blue_values:
                            source_color = red | (green << 8) | (blue << 16)
                            p.run(0x4b5470, [source_color])
                            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
                            packed = p.uc.reg_read(UC_X86_REG_EAX)
                            assert (packed == 0) == (source_color == 0x7f00ff)
                            if label == 'nearBlack':
                                assert packed == red_unit
                            cases.append({'rgb': [red, green, blue], 'packed': packed})
                report['quantizationGrids'].append({'pixelFormat': name, 'gamma': gamma,
                    'region': label, 'cases': cases,
                    'zeroCount': sum(case['packed'] == 0 for case in cases)})
    target = ROOT / 'evidence/native/texture-key-fixtures.json'
    target.write_text(json.dumps(report, indent=2) + '\n')
    print(f'Passed {len(report["formatSelection"])} format choices, '
          f'{len(report["uploads"])} complete TGA loads / {len(samples) * len(report["uploads"])} pixels, '
          f'{sum(len(grid["cases"]) for grid in report["quantizationGrids"])} grid conversions: '
          'exact key→black, nonkey black protected, and 32-bit source alpha ignored.')


if __name__ == '__main__':
    main()
