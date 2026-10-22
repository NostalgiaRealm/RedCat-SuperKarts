import importlib.util
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest

from PIL import Image

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
spec = importlib.util.spec_from_file_location('prepare_assets', ROOT / 'tools/prepare-assets.py')
prepare = importlib.util.module_from_spec(spec)
spec.loader.exec_module(prepare)


class NativeTextureConversion(unittest.TestCase):
    def test_key_mask_matches_original_upload_instructions(self):
        fixture = json.loads((ROOT / 'evidence/native/texture-key-fixtures.json').read_text())
        for row in fixture['uploads']:
            with self.subTest(format=row['pixelFormat'], bits=row['sourceBits'], gamma=row['gamma']):
                source = Image.new('RGBA', (len(row['sourceRGBA']), 1))
                source.putdata([tuple(pixel) for pixel in row['sourceRGBA']])
                if row['sourceBits'] == 24:
                    source = source.convert('RGB')
                data = io.BytesIO()
                source.save(data, format='TGA')
                with tempfile.TemporaryDirectory() as directory:
                    output = Path(directory) / 'texture.png'
                    metadata = prepare.image(data.getvalue(), output, (255, 0, 127), nativeRGB=True)
                    actual = list(Image.open(output).getdata())
                self.assertTrue(metadata['nativeRGB'])
                self.assertEqual(metadata['sourceHasAlpha'], row['sourceBits'] == 32)
                for pixel, original, packed in zip(actual, row['sourceRGBA'], row['packedPixels']):
                    self.assertEqual(pixel[:3], tuple(original[:3]))
                    lo, hi = row['keyRange']
                    self.assertEqual(pixel[3], 0 if lo <= packed <= hi else 255)

    def test_non_native_rgb_conversion_retains_authored_alpha(self):
        source = Image.new('RGBA', (3, 1))
        source.putdata([(40, 120, 200, 64), (0, 0, 0, 0), (255, 0, 255, 255)])
        data = io.BytesIO()
        source.save(data, format='TGA')
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory) / 'menu.png'
            metadata = prepare.image(data.getvalue(), output, True)
            self.assertEqual(list(Image.open(output).getdata()),
                             [(40, 120, 200, 64), (0, 0, 0, 0), (255, 0, 255, 0)])
        self.assertFalse(metadata['nativeRGB'])
        self.assertEqual(metadata['sourceAlphaCounts'], {'zero': 1, 'partial': 1, 'opaque': 1})


if __name__ == '__main__':
    unittest.main()
