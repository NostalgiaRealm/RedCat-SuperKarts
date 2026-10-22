# Complete race texture key inventory

`tools/audit-texture-keying.py` reads the original RCS archive, verifies its
manifest SHA-256, verifies every extracted image's source-record digest, and
compares decoded original RGB with every canonical converted texture. It also
checks each convenience alias against its deterministic canonical source.
Original installation, CD and archive inputs are read-only.

| Inventory | Count |
|---|---:|
| Original archived texture records | 817 |
| Distinct original-name manifest lookups | 807 |
| Canonical converted record PNGs | 817 |
| Convenience alias PNGs | 587 |
| All verified race texture PNGs | 1,404 |
| Original record bytes verified | 84,706,144 |
| Original decoded pixels compared | 56,360,534 |
| Records containing exact RGB key pixels | 359 |
| Distinct manifest lookups containing key pixels | 352 |
| TGA records containing key pixels | 121 |
| Distinct keyed TGA manifest lookups | 119 |
| Records containing a key/non-key edge | 346 |
| TGA records containing a key/non-key edge | 118 |

The ten additional archive records are duplicate original names preserved with
separate generated filenames. They must not be conflated with the 807 runtime
manifest lookups.

The original formats are 254 RGB TGA, two RGBA TGA, 464 indexed PCX, 23 RGB PCX,
and 74 PCL files with indexed PCX encoding. The report groups the latter 74 with
indexed PCX under its decoded-format count. This inventory concerns race
textures; native Delphi menu bitmaps use their separately recovered fuchsia
key/region rules, and indexed legacy sprites and bitmap-font atlases are not
the shared WebGL texture path.

## Actual alpha semantics and repairs

Only `fran07.tga` and `fran08.tga` contain source alpha channels. `fran08` has
22 graded-alpha pixels. Source alpha is now preserved explicitly as metadata:
`sourceHasAlpha`, `sourceHasPartialAlpha`, `sourceAlphaCounts`,
`sourcePartialAlphaPixels`, `sourceTransparentPixels`, `sourceMode` and
`sourceFormat`.

Original accelerated initialization selects the RGB surface format, which
ignores these authored alpha bytes. The native upload fixtures in
`evidence/native/texture-key-fixtures.json` prove that exact RGB `(255,0,127)`
is replaced by packed black and keyed; ordinary black is adjusted to avoid
becoming transparent. Near-pink colors remain non-key. Directly comparing the
pink color after hypothetical 565/555 truncation would incorrectly identify
930/941 additional transparent pixels; no such masks were applied.

The race converter now uses `nativeRGB=True`: it retains every original RGB
byte, sets exact-key alpha to zero, and sets all other alpha to 255. Other image
conversion paths retain their existing alpha semantics. The runtime manifest
marks all 807 race image lookups `nativeRGB:true`; all 817 archive records also
retain complete `imageMetadata`.

This corrects 62,134 alpha pixels in `fran07.tga.png` and 58,479 in
`fran08.tga.png`, plus their two matching aliases. Their RGB pixels are
unchanged. In France, `fran07` is assigned to six authored placed objects:
two towers, one arch, two metro objects and one bridge. `fran08` is assigned
to twenty: castle, aqueduct, house, eight vines, two walls, two shaped bushes
and five bushes. The audit counts authored placements before race-mode
filtering.

The inventory also found 103 stale PCX convenience aliases with old
transparency. These aliases are not the canonical manifest paths used by the
current race renderer. The old preparation routine copied PCX aliases only
when absent, allowing old masks to survive a rebuild. It now rebuilds aliases
deterministically, preferring TGA and otherwise the first archived variant.
Only alias alpha changed; RGB was verified unchanged. In total, 107 PNG files
changed: two canonical TGA textures, their two aliases, and 103 stale aliases.

## Scope of the shared filtering correction

Color-key edges extend well beyond the jet flare. Forty-seven keyed TGA
records have direct road-table or placed-scenery references across the six
tracks. Examples include tree atlas `hboom`, scenery atlases `ned02`,
`eng02`, `fran07/08`, and pickup/weapon atlas `weapon`. Other shared users
include `s_shadow`, HUD atlases `overlay1` through `overlay4`, character/car
textures and the `s_sfx` effect atlas. Their exact source names, counts,
source and PNG digests, boundary counts and recovered configuration/track
references are recorded per asset.

All 13 distinct sky textures selected by the 24 active track/mode combinations
have zero key pixels, so the key-filter correction does not alter their RGB.
Effects and HUD consumers are additionally checked by the separate browser
material audit; presence of a key edge is a risk classification, not a claim
that every edge is visible in every scene.

The PNGs retain the original RGB even under generated alpha zero. The runtime
replaces those key RGB contributions with black before linear filtering. It
now also applies the original 16-bit packing, optional gamma and protected-black
conversion to non-key texels. These runtime changes do not alter the retained
source RGB images or this inventory's source-byte comparisons. See
[texture precision and edge filtering](research-native-texture-precision.md).
The host's binary alpha represents the key; it does not imply that native
DirectDraw stored an RGBA texture. A particular legacy GPU's complete filter
output has not been captured.

## Reproduction and validation

```sh
python3 tools/audit-texture-keying.py
python3 -m unittest discover -s tests -p 'test_texture_key_assets.py'
```

The inventory passes with zero source RGB, runtime alpha, source digest or
alias mismatches. The converter tests compare its transparency decisions with
96 original-instruction upload pixels across RGB565/RGB555, 24/32-bit TGA
sources and gamma settings, and separately protect non-race authored alpha.
The native fixture also includes 3,072 near-pink/near-black conversions.

Evidence:

- `evidence/assets/texture-key-audit.json`: final complete inventory.
- `evidence/assets/texture-key-audit-before.json`: initial mismatches.
- `evidence/assets/texture-key-audit-alpha-repair.json`: two canonical alpha
  changes with old/new digests.
- `evidence/assets/texture-key-audit-alias-repair.json`: 103 alias changes.
- The final audit's `changesSinceBaseline` compares all original and final
  PNG digests when run with
  `--baseline evidence/assets/texture-key-audit-before.json`.

Repairs are explicit optional tool arguments (`--refresh-metadata`,
`--repair-native-alpha`, `--repair-aliases`); the default audit is read-only
apart from its report.
