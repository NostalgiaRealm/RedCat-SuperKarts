"""Read navigation directly from the shipped, uncompressed WinHelp 4 file.

This deliberately bounded reader supplements helpdeco's RTF extraction. It
uses fixed-width little-endian values, so DWORD sentinels and keyword offsets
are independent of the host C ABI. The supported profile is the one in RCSK.HLP:
HCRTF version 33, no LZ/phrase compression, ordinary topic/table records and
DIB/DDB pictures. Unsupported records fail instead of silently losing links.

Structure references: helpdeco's helpfile.txt and src/helpdeco.h. Topic records
are followed by their stored linked-list pointers; their physical storage order
is NOT interpreted as a browse sequence.
"""

import hashlib
import struct
from pathlib import Path

NONE = 0xFFFFFFFF


def require(condition, message):
    if not condition:
        raise ValueError(message)


class Reader:
    def __init__(self, data):
        self.data = data
        self.pos = 0

    def take(self, size):
        require(0 <= size <= len(self.data) - self.pos, 'Truncated WinHelp record')
        value = self.data[self.pos:self.pos + size]
        self.pos += size
        return value

    def unpack(self, fmt):
        return struct.unpack('<' + fmt, self.take(struct.calcsize('<' + fmt)))

    def byte(self):
        return self.take(1)[0]

    def word(self):
        return self.unpack('H')[0]

    def dword(self):
        return self.unpack('I')[0]

    def string(self):
        end = self.data.find(b'\0', self.pos)
        require(end >= 0, 'Unterminated WinHelp string')
        return self.take(end - self.pos + 1)[:-1].decode('cp1252')

    def compressed_word(self, signed=False):
        first = self.byte()
        value = first | (self.byte() << 8) if first & 1 else first
        return (value >> 1) - ((0x4000 if first & 1 else 0x40) if signed else 0)

    def compressed_long(self, signed=False):
        first = self.word()
        value = first | (self.word() << 16) if first & 1 else first
        return (value >> 1) - ((0x40000000 if first & 1 else 0x4000) if signed else 0)


def btree_entries(data, entry_reader):
    r = Reader(data)
    magic, _, page_size, _, zero, _, root, minus_one, pages, levels, count = r.unpack('HHH16shhhhhhI')
    require(magic == 0x293B and zero == 0 and minus_one == -1, 'Invalid WinHelp B-tree header')
    require(page_size >= 8 and pages > 0 and levels > 0, 'Invalid WinHelp B-tree dimensions')
    require(len(data) == 38 + pages * page_size, 'Truncated WinHelp B-tree pages')

    def page(index):
        require(0 <= index < pages, 'WinHelp B-tree page outside file')
        return Reader(data[38 + index * page_size:38 + (index + 1) * page_size])

    current = root
    for _ in range(levels - 1):
        index = page(current)
        _, _, current = index.unpack('Hhh')
    result, seen, previous = [], set(), -1
    while current != -1:
        require(current not in seen, 'Cyclic WinHelp B-tree leaf chain')
        seen.add(current)
        leaf = page(current)
        _, entries, back, next_page = leaf.unpack('Hhhh')
        require(back == previous and entries >= 0, 'Invalid WinHelp B-tree leaf chain')
        result.extend(entry_reader(leaf) for _ in range(entries))
        previous, current = current, next_page
    require(len(result) == count, 'WinHelp B-tree entry count mismatch')
    return result


def _files(data):
    r = Reader(data)
    magic, directory, _, size = r.unpack('4I')
    require(magic == 0x00035F3F and size == len(data), 'Invalid WinHelp file header')

    def file_at(offset):
        require(offset >= 16 and offset + 9 <= len(data), 'WinHelp file offset outside container')
        r = Reader(data[offset:])
        reserved, used, _ = r.unpack('IIB')
        require(used + 9 <= reserved and offset + reserved <= len(data), 'Invalid WinHelp file size')
        return r.take(used)

    entries = btree_entries(file_at(directory), lambda r: (r.string(), r.dword()))
    require(len({name for name, _ in entries}) == len(entries), 'Duplicate WinHelp internal filename')
    return {name: file_at(offset) for name, offset in entries}


def _system(data):
    r = Reader(data)
    magic, minor, major, generated, flags = r.unpack('HHHIH')
    require((magic, minor, major, flags) == (0x036C, 33, 1, 0), 'Unsupported WinHelp compression/version')
    result = {'format': {'major': major, 'minor': minor, 'flags': flags, 'generatedUnix': generated},
              'windows': [], 'macros': [], 'systemRecordTypes': []}
    while r.pos < len(data):
        kind, length = r.unpack('HH')
        payload = r.take(length)
        result['systemRecordTypes'].append(kind)
        if kind == 1:
            result['title'] = payload.rstrip(b'\0').decode('cp1252')
        elif kind == 3:
            require(length == 4, 'Invalid contents topic record')
            result['contentsTopicOffset'] = struct.unpack('<I', payload)[0]
        elif kind == 4:
            result['macros'].append(payload.rstrip(b'\0').decode('cp1252'))
        elif kind == 6:
            require(length == 90, 'Unsupported WinHelp window record')
            w = Reader(payload)
            flags = w.word()
            type_, name, caption = (w.take(n).split(b'\0', 1)[0].decode('cp1252') for n in (10, 9, 51))
            x, y, width, height, styles = w.unpack('hhhhH')
            scroll, non_scroll = w.take(4), w.take(4)
            result['windows'].append({'name': name, 'type': type_, 'caption': caption, 'flags': flags,
                'rectangle': [x, y, width, height], 'styles': styles,
                'backgroundRGB': list(scroll[:3]), 'nonScrollingBackgroundRGB': list(non_scroll[:3]),
                'alwaysOnTop': bool(flags & 0x400), 'autoSizeHeight': bool(flags & 0x800)})
        else:
            require(kind in (9, 11), f'Unsupported navigation-related system record {kind}')
    require('contentsTopicOffset' in result and result['windows'], 'Missing WinHelp main window/contents')
    return result


def _fonts(data):
    r = Reader(data)
    name_count, count, names_offset, descriptors_offset = r.unpack('4H')
    require(names_offset == 8 and name_count > 0 and descriptors_offset >= names_offset,
            'Unsupported WinHelp font table')
    name_length, extra = divmod(descriptors_offset - names_offset, name_count)
    require(name_length > 0 and extra == 0 and len(data) == descriptors_offset + count * 11,
            'Invalid WinHelp font table dimensions')
    names = [r.take(name_length).split(b'\0', 1)[0].decode('cp1252') for _ in range(name_count)]
    fonts = []
    for index in range(count):
        attributes, half_points, family, name = r.unpack('BBBH')
        require(name < len(names), 'Unresolved WinHelp font face')
        color, background = list(r.take(3)), list(r.take(3))
        fonts.append({'id': index, 'face': names[name], 'pointSize': half_points / 2,
                      'family': family, 'colorRGB': color, 'backgroundRGB': background,
                      'bold': bool(attributes & 1), 'italic': bool(attributes & 2),
                      'underline': bool(attributes & 4), 'strikeOut': bool(attributes & 8),
                      'doubleUnderline': bool(attributes & 16), 'smallCaps': bool(attributes & 32)})
    return fonts


def _format_links(data, text, record_type, topic_position):
    """Consume commands, not byte-pattern matches (images can contain opcodes)."""
    r = Reader(data)
    r.compressed_long(signed=True)
    topic_length = r.compressed_word()
    if record_type == 0x23:
        columns, kind = r.unpack('BB')
        require(kind in (0, 1, 2, 3), 'Unsupported WinHelp table type')
        if kind in (0, 2):
            r.take(2)
        r.take(columns * 4)
    # The last text run need not have an explicit NUL at the end of LinkData2.
    strings = iter(text.decode('cp1252').split('\0'))
    links, images, current_link, font = [], [], None, None
    while r.pos < len(data):
        if record_type == 0x23:
            column = r.unpack('h')[0]
            if column == -1:
                break
            r.take(3)
        r.take(4)
        flags = r.word()
        if flags & 1:
            r.compressed_long(signed=True)
        for mask in (2, 4, 8, 16, 32, 64):
            if flags & mask:
                r.compressed_word(signed=True)
        if flags & 0x100:
            r.take(3)
        if flags & 0x200:
            count = r.compressed_word(signed=True)
            require(count >= 0, 'Negative WinHelp tab count')
            for _ in range(count):
                if r.compressed_word() & 0x4000:
                    r.compressed_word()
        while True:
            value = next(strings, None)
            require(value is not None, 'Missing WinHelp formatted text run')
            if current_link is not None:
                current_link['text'] += value
                if value and font is not None and font not in current_link['fontIds']:
                    current_link['fontIds'].append(font)
            command = r.byte()
            if command == 0xFF:
                break
            if command == 0x80:
                font = r.word()
            elif command in (0x20, 0x21):
                r.take(4 if command == 0x20 else 2)
            elif command in (0x81, 0x82, 0x83, 0x8B, 0x8C):
                pass
            elif command in (0x86, 0x87, 0x88):
                kind, length = r.byte(), r.compressed_long(signed=True)
                require(kind in (3, 0x22), 'Unsupported embedded WinHelp control')
                if kind == 0x22:
                    r.compressed_word()  # topic-offset contribution, not SHG hotspot count
                picture = Reader(r.take(length))
                require(picture.word() == 0 and length == 4, 'Unsupported embedded WinHelp picture')
                images.append(picture.word())
            elif command == 0x89:
                require(current_link is not None, 'End of WinHelp hotspot without start')
                current_link = None
            elif command in (0xC8, 0xCC):
                require(current_link is None, 'Nested WinHelp hotspot')
                current_link = {'opcode': command, 'kind': 'macro', 'preserveFont': command == 0xCC,
                                'macro': r.take(r.word()).rstrip(b'\0').decode('cp1252'), 'text': '',
                                'topicPosition': topic_position, 'fontIds': []}
                links.append(current_link)
            elif command in (0xE2, 0xE3, 0xE6, 0xE7):
                require(current_link is None, 'Nested WinHelp hotspot')
                current_link = {'opcode': command, 'kind': 'jump' if command & 1 else 'popup',
                                'preserveFont': command in (0xE6, 0xE7), 'targetHash': r.dword(),
                                'windowTarget': None, 'externalFile': None, 'text': '',
                                'topicPosition': topic_position, 'fontIds': []}
                links.append(current_link)
            elif command in (0xEA, 0xEB, 0xEE, 0xEF):
                require(current_link is None, 'Nested WinHelp hotspot')
                target = Reader(r.take(r.word()))
                kind, hash_ = target.byte(), target.dword()
                window, external = None, None
                if kind == 1:
                    window = target.byte()
                elif kind == 4:
                    external = target.string()
                elif kind == 6:
                    window, external = target.string(), target.string()
                else:
                    require(kind == 0, 'Unsupported WinHelp target kind')
                require(target.pos == len(target.data), 'Unexpected bytes in WinHelp target')
                current_link = {'opcode': command, 'kind': 'jump' if command & 1 else 'popup',
                                'preserveFont': command in (0xEE, 0xEF), 'targetHash': hash_,
                                'windowTarget': window, 'externalFile': external, 'text': '',
                                'topicPosition': topic_position, 'fontIds': []}
                links.append(current_link)
            else:
                raise ValueError(f'Unsupported WinHelp formatting opcode 0x{command:02x}')
        if record_type != 0x23:
            break
    require(current_link is None, 'Unclosed WinHelp hotspot')
    require(r.pos == len(data), 'Unparsed WinHelp formatting bytes')
    require(all(not value for value in strings), 'Unparsed WinHelp text strings')
    return topic_length, links, images


def _bitmap_hotspots(data):
    r = Reader(data)
    magic, count = r.unpack('HH')
    require(magic in (0x506C, 0x706C), 'Unsupported WinHelp bitmap group')
    offsets = [r.dword() for _ in range(count)]
    hotspots = []
    for offset in offsets:
        p = Reader(data[offset:])
        kind, _ = p.unpack('BB')
        require(kind in (5, 6), 'Unsupported WinHelp bitmap type')
        p.compressed_long(); p.compressed_long()
        p.compressed_word(); p.compressed_word()
        for _ in range(5):
            p.compressed_long()
        size = p.compressed_long()
        p.dword()
        hotspot_offset = p.dword()
        # RCSK pictures contain zero hotspots. Fail on authored hotspots until
        # their geometry/actions are supported, rather than silently dropping them.
        require(not size and not hotspot_offset, 'WinHelp bitmap hotspots require conversion support')
    return hotspots


def read_winhelp_navigation(source):
    """Return original topic, context, keyword, window and hotspot metadata."""
    data = source if isinstance(source, bytes) else Path(source).read_bytes()
    files = _files(data)
    require(not {'|Phrases', '|PhrIndex', '|PhrImage'}.intersection(files), 'Unsupported phrase-compressed WinHelp')
    result = _system(files['|SYSTEM'])
    result['fonts'] = _fonts(files['|FONT'])
    require('|VIOLA' not in files, 'Per-topic WinHelp windows require conversion support')
    map_reader = Reader(files['|CTXOMAP'])
    contexts = [map_reader.unpack('II') for _ in range(map_reader.word())]
    require(map_reader.pos == len(map_reader.data), 'Trailing context-map data')
    hashes = btree_entries(files['|CONTEXT'], lambda r: r.unpack('II'))
    hash_map = dict(hashes)
    require(len(hash_map) == len(hashes), 'Duplicate WinHelp context hash')
    topic_data, topics, image_ids = files['|TOPIC'], [], set()

    def topic_read(position, length):
        chunks = []
        while length:
            require(position >= 12, 'Invalid WinHelp topic position')
            block, offset = divmod(position - 12, 0x4000)
            block_data = topic_data[block * 4096 + 12:(block + 1) * 4096]
            require(offset < len(block_data), 'WinHelp topic position outside data')
            count = min(length, len(block_data) - offset)
            chunks.append(block_data[offset:offset + count])
            length -= count
            position = (block + 1) * 0x4000 + 12
        return b''.join(chunks)

    position, offset, previous, seen, record_count = 12, 0, NONE, set(), 0
    while position not in (0, NONE):
        require(position not in seen, 'Cyclic WinHelp topic record chain')
        seen.add(position)
        size, text_size, back, next_, formatting_size, kind = struct.unpack('<5IB', topic_read(position, 21))
        require(back == previous, 'Broken WinHelp topic record back pointer')
        require(21 <= formatting_size <= size, 'Invalid WinHelp topic record size')
        body = topic_read(position, size)
        formatting, text = body[21:formatting_size], body[formatting_size:]
        require(len(text) == text_size, 'Unsupported compressed WinHelp text')
        record_count += 1
        if kind == 2:
            require(len(formatting) == 28, 'Invalid WinHelp topic header')
            _, browse_back, browse_next, number, non_scroll, scroll, next_topic = struct.unpack('<7I', formatting)
            strings = text.decode('cp1252').split('\0')
            topics.append({'topicOffset': offset, 'topicPosition': position, 'nativeTopicNumber': number,
                           'title': strings[0], 'macros': [s for s in strings[1:] if s],
                           'browsePrevious': None if browse_back == NONE else browse_back,
                           'browseNext': None if browse_next == NONE else browse_next,
                           'nonScrollingPosition': None if non_scroll == NONE else non_scroll,
                           'scrollingPosition': None if scroll == NONE else scroll,
                           'nextTopicPosition': None if next_topic == NONE else next_topic,
                           'links': [], 'keywords': []})
        elif kind in (0x20, 0x23):
            require(topics, 'WinHelp text outside topic')
            increment, links, images = _format_links(formatting, text, kind, position)
            offset += increment
            topics[-1]['links'].extend(links)
            image_ids.update(images)
        else:
            raise ValueError(f'Unsupported WinHelp topic record 0x{kind:02x}')
        if next_ not in (0, NONE) and (next_ - 12) // 0x4000 != (position - 12) // 0x4000:
            offset = ((next_ - 12) // 0x4000) * 0x8000
        previous, position = position, next_
    require(topics and not topics[-1]['title'] and topics[-1]['nextTopicPosition'] is None,
            'Missing WinHelp terminal topic header')
    terminal = topics.pop()
    by_offset = {topic['topicOffset']: topic for topic in topics}
    require(len(by_offset) == len(topics), 'Duplicate WinHelp topic offset')
    for topic in topics:
        offset = topic['topicOffset']
        topic['contextIds'] = [id_ for id_, value in contexts if value == offset]
        topic['contextHashes'] = [hash_ for hash_, value in hashes if value == offset]
        require(topic['contextIds'] and topic['contextHashes'], 'Unmapped WinHelp topic')
        for edge in ('browsePrevious', 'browseNext'):
            require(topic[edge] is None or topic[edge] in by_offset, 'Unresolved WinHelp browse target')
        for link in topic['links']:
            if link['kind'] != 'macro' and not link['externalFile']:
                target = hash_map.get(link['targetHash'])
                require(target in by_offset, 'Unresolved WinHelp link target hash')
                link['targetTopicOffset'] = target
                link['targetContextIds'] = [id_ for id_, value in contexts if value == target]
    require(set(value for _, value in contexts) == set(by_offset), 'Context map/topic mismatch')
    require(set(hash_map.values()) == set(by_offset), 'Hash map/topic mismatch')
    keywords = []
    for name, count, address in btree_entries(files['|KWBTREE'], lambda r: (r.string(), r.word(), r.dword())):
        r = Reader(files['|KWDATA'][address:])
        targets = [r.dword() for _ in range(count)]
        require(all(target in by_offset for target in targets), 'Unresolved WinHelp keyword target')
        for target in targets:
            by_offset[target]['keywords'].append(name)
        keywords.append({'keyword': name, 'topicOffsets': targets,
                         'contextIds': [id_ for target in targets for id_, value in contexts if value == target]})
    bitmap_files = {name: value for name, value in files.items() if name.startswith('|bm')}
    require(all(f'|bm{image}' in bitmap_files for image in image_ids), 'Missing WinHelp topic bitmap')
    bitmap_hotspots = sum(len(_bitmap_hotspots(value)) for value in bitmap_files.values())
    result.update({'schema': 1, 'sourceSHA256': hashlib.sha256(data).hexdigest(),
                   'topics': topics, 'keywords': keywords, 'contextMap': {str(k): v for k, v in contexts},
                   'hashMap': {str(k): v for k, v in hashes}, 'topicRecordCount': record_count,
                   'terminalTopic': terminal, 'bitmapCount': len(bitmap_files),
                   'bitmapHotspotCount': bitmap_hotspots, 'hasTopicWindowMap': False,
                   'directory': sorted(files)})
    require(result['contentsTopicOffset'] in by_offset, 'Unresolved contents topic')
    return result
