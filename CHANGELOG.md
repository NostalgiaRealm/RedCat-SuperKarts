# Changelog

## 0.9.0 — 2026-10-25

Source update since the published 0.1.0 release. All prepared assets needed
to run locally remain included. No desktop packages were rebuilt or published.

### Added

- The current version appears in **Instellingen → Meer instellingen**.
  `package.json` holds the authoritative version, with a generated browser
  module and an npm version hook to keep the menu in sync.
- Redesigned touch controls: a proportional steering wheel on the left,
  an independent Alt-equivalent brake pedal and a small round bonus button.
  The wheel's upper half accelerates; its lower half brakes and reverses.
- Help Contents, Back, the original keyword Index and visited-topic History,
  using the links and contexts recovered from the original WinHelp file.
- Original-file sound audits and focused regression checks for Adventure
  briefings, menu flow, and power-up pickup and firing audio.

### Fixed

- Movies, including the intro and rewards, retain their complete original
  4:3 image without stretching or cropping at different window shapes.
- Race HUD meshes and original font quads share an RGB565 composition surface,
  preserving native draw order, keyed filtering and per-draw colour rounding.
- Touch contacts remain independent and clear on release, cancellation,
  focus loss, rotation and mode changes. The race HUD fits above the larger
  touch controls in short landscape layouts.
- Adventure pre-race speech now uses all 24 original briefing recordings.
  Selected-profile voices, modal returns, character Back navigation,
  first-visit handling and the awaited quit farewell follow the original flow.
- Help uses the appropriate original contexts and returns to the caller
  without losing settings drafts, focus or scroll position.
- The source server and Electron protocol serve the new SVG controls correctly.
- Smoke checks use the current renderer's world/HUD statistics, packed texture
  formats and actual HUD output. The older sound-trigger harness starts from
  the current simulation clock instead of assuming fixed-step elapsed time.

### Documentation and verification

- Reorganised the README for beginners while retaining its technical content;
  clarified local launch, desktop packaging and subdomain hosting instructions.
- Updated outdated research notes and separated current source changes from
  historical package and full-race results.
- Verified power-up audio against both original copies: 314 matching WAVs,
  3,001 isolated original instruction cases, 20 focused tests and 118 controlled
  browser cases. No gameplay audio change was needed; missing original sound
  names and dormant recordings remain silent.
- Earlier movie, HUD, Help, touch and menu changes retain their own focused
  validation records. This version update checks metadata consistency and
  the menu label in landscape and portrait; it does not rerun the full suite,
  full races or desktop package checks.

### Known limits

Complete original Windows race parity, a fresh full race matrix on the current
source, historical GPU precision and physical target-device validation remain
open. Existing desktop builds predate this source update. See
[remaining work](docs/remaining-work.md) and [validation](docs/validation.md).

## 0.1.0 — previous source release

The first published source snapshot included the browser and Electron game,
prepared assets, original menus and race modes, local setup and packaging
instructions, research and retained validation. See the
[original release notes](docs/releases/v0.1.0.md).
