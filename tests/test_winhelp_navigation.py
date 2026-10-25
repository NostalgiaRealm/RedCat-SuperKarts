"""Focused checks for navigation recovered independently of helpdeco's RTF."""
import os
from pathlib import Path
import struct
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
from lib.winhelp_navigation import Reader, _format_links, btree_entries, read_winhelp_navigation

SOURCE = Path(os.environ.get('RCSK_HELP_SOURCE',
    '/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data/RCSK.HLP'))


def formatted(commands, text):
    # One ordinary paragraph, zero spacing flags. TopicLength counts NULs too.
    return _format_links(b'\0\x80' + bytes([len(text) * 2]) + b'\0\x80\0\0\0\0' + commands,
                         text, 0x20, 123)


class WinHelpNavigationReaderTests(unittest.TestCase):
    def test_fixed_width_unsigned_sentinel(self):
        self.assertEqual(Reader(b'\xff' * 4).dword(), 0xFFFFFFFF)

    def test_compressed_integer_boundaries(self):
        self.assertEqual(Reader(b'\xfe').compressed_word(), 127)
        self.assertEqual(Reader(b'\x01\x01').compressed_word(), 128)
        self.assertEqual(Reader(b'\x80').compressed_word(signed=True), 0)
        self.assertEqual(Reader(b'\x01\x80').compressed_word(signed=True), 0)
        self.assertEqual(Reader(b'\xfe\xff').compressed_long(), 32767)
        self.assertEqual(Reader(b'\x01\0\x01\0').compressed_long(), 32768)
        self.assertEqual(Reader(b'\0\x80').compressed_long(signed=True), 0)

    def test_jump_and_popup_opcodes_keep_their_distinct_behavior(self):
        for opcode in (0xE2, 0xE3, 0xE6, 0xE7):
            with self.subTest(opcode=opcode):
                _, links, images = formatted(bytes([opcode]) + struct.pack('<I', 0xE7E3FF00)
                                            + b'\x89\xff', b'\0Topic\0')
                self.assertEqual(len(links), 1)
                self.assertEqual(links[0]['text'], 'Topic')
                self.assertEqual(links[0]['kind'], 'jump' if opcode & 1 else 'popup')
                self.assertEqual(links[0]['preserveFont'], opcode in (0xE6, 0xE7))
                self.assertEqual(links[0]['targetHash'], 0xE7E3FF00)
                self.assertIsNone(links[0]['windowTarget'])
                self.assertEqual(images, [])

    def test_font_payload_bytes_are_not_mistaken_for_hotspots(self):
        _, links, _ = formatted(b'\x80\xe7\xe3\xff', b'\0Text')
        self.assertEqual(links, [])

    def test_explicit_secondary_window_target_is_retained(self):
        payload = b'\x01' + struct.pack('<I', 54321) + b'\x01'
        _, links, _ = formatted(b'\xeb' + struct.pack('<H', len(payload)) + payload + b'\x89\xff',
                                b'\0Other window\0')
        self.assertEqual(links[0]['windowTarget'], 1)
        self.assertEqual(links[0]['targetHash'], 54321)
        self.assertEqual(links[0]['kind'], 'jump')

    def test_unknown_or_truncated_commands_fail_instead_of_losing_navigation(self):
        for commands, text in ((b'\xfe\xff', b'\0\0'), (b'\xe7\0', b'\0'),
                               (b'\x89\xff', b'\0\0')):
            with self.subTest(commands=commands):
                with self.assertRaises(ValueError):
                    formatted(commands, text)

    def test_btree_follows_leaf_chain_and_rejects_cycles(self):
        header = struct.pack('<HHH16shhhhhhI', 0x293B, 2, 32, b'L4', 0, 0, 1, -1, 2, 1, 2)
        page0 = struct.pack('<HhhhI', 20, 1, 1, -1, 20).ljust(32, b'\0')
        page1 = struct.pack('<HhhhI', 20, 1, -1, 0, 10).ljust(32, b'\0')
        self.assertEqual(btree_entries(header + page0 + page1, lambda r: r.dword()), [10, 20])
        cyclic0 = struct.pack('<HhhhI', 20, 1, 1, 1, 20).ljust(32, b'\0')
        with self.assertRaisesRegex(ValueError, 'Cyclic'):
            btree_entries(header + cyclic0 + page1, lambda r: r.dword())


@unittest.skipUnless(SOURCE.is_file(), 'Set RCSK_HELP_SOURCE to the original RCSK.HLP for binary comparison')
class OriginalWinHelpNavigationTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original = SOURCE.read_bytes()
        cls.navigation = read_winhelp_navigation(cls.original)

    def test_authored_topics_have_no_browse_sequence(self):
        n = self.navigation
        self.assertEqual(n['sourceSHA256'], '78bad04a5fbd761f5fd84c39ebb88978c00f7c13313cf38de8a9493f7de56f70')
        self.assertEqual(n['topicRecordCount'], 122)
        self.assertEqual(len(n['topics']), 13)
        self.assertEqual([t['contextIds'] for t in n['topics']], [[i] for i in range(1, 14)])
        self.assertTrue(all(t['browsePrevious'] is None and t['browseNext'] is None
                            for t in n['topics'] + [n['terminalTopic']]))
        self.assertEqual(n['contentsTopicOffset'], n['topics'][0]['topicOffset'])

    def test_all_nine_authored_links_are_current_window_jumps(self):
        expected = [(2, 3, 'Besturing', 0xE7), (5, 6, 'Spelerkeuze', 0xE7),
                    (5, 7, 'Overzicht', 0xE7), (6, 5, 'Spelerlijst', 0xE7),
                    (7, 8, 'Bonussen', 0xE7), (7, 13, 'Spelregels', 0xE7),
                    (9, 10, 'Racekeuze', 0xE7), (10, 8, 'Bonussen', 0xE7),
                    (10, 13, 'Spelregels', 0xE3)]
        actual = [(t['contextIds'][0], l['targetContextIds'][0], l['text'], l['opcode'])
                  for t in self.navigation['topics'] for l in t['links']]
        self.assertEqual(actual, expected)
        for topic in self.navigation['topics']:
            for link in topic['links']:
                self.assertEqual(link['kind'], 'jump')
                self.assertIsNone(link['windowTarget'])
                self.assertIsNone(link['externalFile'])

    def test_original_keyword_offsets_are_not_helpdeco_host_long_values(self):
        keywords = self.navigation['keywords']
        self.assertEqual(len(keywords), 13)
        self.assertEqual([row['contextIds'][0] for row in keywords], [3, 8, 11, 12, 4, 1, 2, 7, 10, 6, 9, 5, 13])
        for topic in self.navigation['topics']:
            self.assertEqual(topic['keywords'], [topic['title']])

    def test_authored_link_fonts_distinguish_preserved_style_from_standard_jump(self):
        n = self.navigation
        links = [link for topic in n['topics'] for link in topic['links']]
        self.assertEqual([link['fontIds'] for link in links], [[8], [10], [10], [10], [8], [8], [10], [8], [12]])
        for link in links:
            font = n['fonts'][link['fontIds'][0]]
            self.assertEqual((font['face'], font['pointSize'], font['colorRGB']), ('Arial', 10, [0, 128, 0]))
            self.assertEqual(font['underline'], link['preserveFont'])

    def test_secondary_window_and_audio_are_defined_without_authored_activation(self):
        n = self.navigation
        self.assertEqual([w['name'] for w in n['windows']], ['main', 'second'])
        self.assertEqual(n['windows'][0]['rectangle'], [491, 0, 532, 992])
        self.assertEqual(n['windows'][0]['backgroundRGB'], [254, 255, 139])
        self.assertEqual(n['windows'][1]['rectangle'], [583, 102, 409, 870])
        self.assertTrue(n['windows'][1]['autoSizeHeight'])
        self.assertFalse(n['hasTopicWindowMap'])
        self.assertEqual(n['macros'], [])
        self.assertTrue(all(t['macros'] == [] for t in n['topics']))
        self.assertIn('MN_HSP01.WAV', n['directory'])
        self.assertEqual((n['bitmapCount'], n['bitmapHotspotCount']), (46, 0))

    def test_truncated_original_is_rejected(self):
        with self.assertRaises(ValueError):
            read_winhelp_navigation(self.original[:-1])


if __name__ == '__main__':
    unittest.main()
