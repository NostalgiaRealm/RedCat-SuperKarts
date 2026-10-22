#!/usr/bin/env python3
"""Verify every archived picture against original bytes and inventory key edges.

The optional metadata refresh changes JSON only. --repair-native-alpha is an
explicit repair of PNG alpha to the proven accelerated RGB surface rule; it
never changes original RGB or original archive files.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import io
import json
from pathlib import Path
import re

import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parents[1]
KEY = (255, 0, 127)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def source_metadata(image, rgba):
    alpha = rgba[:, :, 3]
    zero = int(np.count_nonzero(alpha == 0))
    partial = int(np.count_nonzero((alpha > 0) & (alpha < 255)))
    opaque = int(np.count_nonzero(alpha == 255))
    return {
        'width': image.width, 'height': image.height,
        'sourceHasAlpha': 'A' in image.getbands(),
        'sourceHasPartialAlpha': partial > 0,
        'sourcePartialAlphaPixels': partial,
        'sourceTransparentPixels': zero,
        'sourceAlphaCounts': {'zero': zero, 'partial': partial, 'opaque': opaque},
        'sourceMode': image.mode, 'sourceFormat': image.format,
        'nativeRGB': True, 'colorKeyRGB': list(KEY),
        'pixelsMadeTransparent': int(np.count_nonzero(np.all(rgba[:, :, :3] == KEY, axis=2))),
    }


def inventory_usage():
    usage = defaultdict(list)
    for path in sorted((ROOT / 'public/assets/tracks').glob('etappe*.json')):
        track = json.loads(path.read_text())
        for index, texture in enumerate(track['textures']):
            usage[Path(texture).name.removesuffix('.png')].append({
                'kind': 'road-texture-table', 'track': track['id'], 'textureIndex': index,
                'groups': sum(group['textureIndex'] == index for group in track['groups']),
            })
        by_animation = Counter(placement['animation'].lower() for placement in track['placements'])
        for animation, definition in track['objectDefinitions'].items():
            count = by_animation[animation]
            if count:
                usage[definition['texture'].lower()].append({
                    'kind': 'authored-placed-scenery', 'track': track['id'],
                    'animation': animation, 'placements': count,
                })
    configs = json.loads((ROOT / 'public/assets/config.json').read_text())
    for file, sections in configs.items():
        for section, values in sections.items():
            for key, value in values.items():
                for name in re.findall(r'[\w -]+\.(?:tga|pcx|pcl)', str(value), flags=re.I):
                    name = name.lower().strip()
                    usage[name].append({'kind': 'config-reference', 'config': file,
                                        'section': section, 'key': key})
    return usage


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--refresh-metadata', action='store_true')
    parser.add_argument('--repair-native-alpha', action='store_true')
    parser.add_argument('--repair-aliases', action='store_true')
    parser.add_argument('--baseline', type=Path, help='Previous audit JSON for exact changed-PNG digests')
    args = parser.parse_args()
    manifest_path = ROOT / 'public/assets/manifest.json'
    manifest = json.loads(manifest_path.read_text())
    installation = Path(manifest['sourceInstallation']) / 'data'
    archive_file = next(path for path in installation.iterdir() if path.name.lower() == 'rcs.img')
    archive = archive_file.read_bytes()
    archive_hash = digest(archive)
    assert archive_hash == manifest['archives']['rcs']['imageSHA256']
    usage = inventory_usage()
    records, errors, changed, changed_aliases = [], [], [], []
    png_digests = defaultdict(list)
    alias_targets = {}
    for entry in manifest['archives']['rcs']['entries']:
        name = entry['filename']
        if Path(name).suffix.lower() not in ['.tga', '.pcx', '.pcl']:
            continue
        original = archive[entry['offset']:entry['offset'] + entry['length']]
        assert digest(original) == entry['sha256'], name
        extracted = ROOT / 'raw/extracted/rcs' / name
        assert digest(extracted.read_bytes()) == entry['sha256'], name
        image = Image.open(io.BytesIO(original))
        rgba = np.asarray(image.convert('RGBA'))
        metadata = source_metadata(image, rgba)
        mask = np.all(rgba[:, :, :3] == KEY, axis=2)
        expected = rgba.copy()
        expected[:, :, 3] = np.where(mask, 0, 255)
        output = ROOT / 'public/assets/textures' / (name + '.png')
        actual = np.asarray(Image.open(output).convert('RGBA'))
        if args.repair_native_alpha and not np.array_equal(actual, expected):
            # Reject unrelated conversion drift instead of silently repairing it.
            assert metadata['sourceHasAlpha'], name
            assert np.array_equal(actual[:, :, :3], expected[:, :, :3]), name
            before = output.read_bytes()
            Image.fromarray(expected).save(output)
            alias = output.parent / (Path(name).stem + '.png')
            if alias.exists() and digest(alias.read_bytes()) == digest(before):
                alias.write_bytes(output.read_bytes())
            changed.append({'file': str(output.relative_to(ROOT)),
                            'previousSHA256': digest(before), 'sha256': digest(output.read_bytes()),
                            'changedAlphaPixels': int(np.count_nonzero(actual[:, :, 3] != expected[:, :, 3]))})
            actual = np.asarray(Image.open(output).convert('RGBA'))
        mismatched_rgb = int(np.count_nonzero(np.any(actual[:, :, :3] != rgba[:, :, :3], axis=2)))
        mismatched_alpha = int(np.count_nonzero(actual[:, :, 3] != expected[:, :, 3]))
        if mismatched_rgb or mismatched_alpha:
            errors.append({'name': name, 'rgbPixels': mismatched_rgb, 'runtimeAlphaPixels': mismatched_alpha})
        if args.refresh_metadata:
            entry['imageMetadata'] = metadata
            spec = manifest['images'].get(entry['name'].lower())
            if spec and spec['source'] == name:
                spec.update(metadata)
        png_sha = digest(output.read_bytes())
        png_digests[png_sha].append(name)
        stem = Path(name).stem
        if Path(name).suffix.lower() == '.tga' or stem not in alias_targets:
            alias_targets[stem] = output
        record = {
            'name': name, 'logicalName': entry['name'].lower(), 'archiveIndex': entry['index'],
            'archiveOffset': entry['offset'], 'sourceBytes': entry['length'],
            'sourceSHA256': entry['sha256'], 'pngSHA256': png_sha,
            'file': str(output.relative_to(ROOT / 'public/assets')), **metadata,
            'sourceTgaBits': original[16] if image.format == 'TGA' else None,
            'sourceTgaAttributeBits': original[17] & 15 if image.format == 'TGA' else None,
            'retainedKeyRGBPixels': int(np.count_nonzero(mask & (actual[:, :, 3] == 0))),
            'nonKeyAuthoredTransparentPixels': int(np.count_nonzero((rgba[:, :, 3] == 0) & ~mask)),
            'keyToOpaqueBoundaryEdges': int(np.count_nonzero(mask[:, 1:] != mask[:, :-1])
                                           + np.count_nonzero(mask[1:, :] != mask[:-1, :])),
            'wrappedKeyBoundaryEdges': int(np.count_nonzero(mask[:, 0] != mask[:, -1])
                                           + np.count_nonzero(mask[0, :] != mask[-1, :])),
            'sourceRGBMismatchPixels': mismatched_rgb, 'runtimeAlphaMismatchPixels': mismatched_alpha,
            'usage': usage.get(entry['name'].lower(), []),
        }
        records.append(record)
    aliases = []
    record_paths = {record['file'] for record in records}
    for output in sorted((ROOT / 'public/assets/textures').glob('*.png')):
        relative = str(output.relative_to(ROOT / 'public/assets'))
        if relative in record_paths:
            continue
        target = alias_targets.get(output.stem)
        if target and args.repair_aliases and output.read_bytes() != target.read_bytes():
            before = output.read_bytes()
            old_pixels = np.asarray(Image.open(io.BytesIO(before)).convert('RGBA'))
            expected_pixels = np.asarray(Image.open(target).convert('RGBA'))
            assert np.array_equal(old_pixels[:, :, :3], expected_pixels[:, :, :3]), relative
            output.write_bytes(target.read_bytes())
            changed_aliases.append({'file': relative, 'canonicalFile': str(target.relative_to(ROOT / 'public/assets')),
                                   'previousSHA256': digest(before), 'sha256': digest(output.read_bytes()),
                                   'changedAlphaPixels': int(np.count_nonzero(old_pixels[:, :, 3] != expected_pixels[:, :, 3]))})
        png_sha = digest(output.read_bytes())
        names = png_digests.get(png_sha)
        aliases.append({'file': relative, 'sha256': png_sha, 'matchingSourceRecords': names or []})
        if not names or target and output.read_bytes() != target.read_bytes():
            errors.append({'unmatchedTexturePNG': relative})
    if args.refresh_metadata:
        manifest_path.write_text(json.dumps(manifest, separators=(',', ':'), ensure_ascii=False) + '\n')
    summary = {
        'originalRecords': len(records), 'canonicalManifestImages': len(manifest['images']),
        'sourceModes': dict(Counter(record['sourceFormat'] + '/' + record['sourceMode'] for record in records)),
        'authoredAlphaImages': [record['name'] for record in records if record['sourceHasAlpha']],
        'authoredPartialAlphaImages': [record['name'] for record in records if record['sourceHasPartialAlpha']],
        'keyedRecords': sum(record['pixelsMadeTransparent'] > 0 for record in records),
        'keyedTgaRecords': sum(record['sourceFormat'] == 'TGA' and record['pixelsMadeTransparent'] > 0 for record in records),
        'keyBoundaryRecords': sum(record['keyToOpaqueBoundaryEdges'] > 0 for record in records),
        'keyBoundaryTgaRecords': sum(record['sourceFormat'] == 'TGA' and record['keyToOpaqueBoundaryEdges'] > 0 for record in records),
        'aliasPNGs': len(aliases), 'verifiedTexturePNGs': len(records) + len(aliases),
        'sourceBytesVerified': sum(record['sourceBytes'] for record in records),
        'pixelsVerified': sum(record['width'] * record['height'] for record in records),
        'changedPNGs': changed, 'changedAliases': changed_aliases, 'errors': errors,
    }
    report = {
        'format': 'superkarts-texture-key-audit-v1',
        'sourceArchive': str(archive_file), 'sourceArchiveSHA256': archive_hash,
        'runtimeRule': 'Accelerated RGB surface: preserve original RGB; alpha=0 for exact RGB(255,0,127), otherwise255. Authored alpha retained as metadata only.',
        'usageScope': 'All six road tables and authored placed-scenery definitions, plus literal INI references. Includes authored placements independent of race-mode filtering; logical bonus overrides and dynamic effect consumers are audited separately.',
        'summary': summary, 'records': records, 'aliases': aliases,
    }
    if args.baseline:
        baseline = json.loads(args.baseline.read_text())
        def outputs(value):
            return {row['file']: row.get('pngSHA256', row.get('sha256'))
                    for row in value['records'] + value['aliases']}
        previous, current = outputs(baseline), outputs(report)
        report['changesSinceBaseline'] = {
            'baseline': str(args.baseline),
            'files': [{'file': file, 'previousSHA256': previous.get(file), 'sha256': sha}
                      for file, sha in current.items() if previous.get(file) != sha],
        }
    path = ROOT / 'evidence/assets/texture-key-audit.json'
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(summary, indent=2))
    if errors:
        raise SystemExit(1)


if __name__ == '__main__':
    main()
