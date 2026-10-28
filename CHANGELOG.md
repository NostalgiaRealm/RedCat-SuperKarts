# Changelog

## 1.0.2 — 2026-10-29

Source and desktop release for Linux x64, Windows x64, macOS Intel and macOS
Apple Silicon. A second comparison against the recovered original code
corrects Adventure, rescue, track, HUD and menu details, and the game now
calculates with the same double precision as the original. Existing saves,
profiles, unlocks, settings and records keep working without migration. See
the [1.0.2 release notes](docs/releases/1.0.2.md) and the
[comparison report](docs/original-comparison-2026-10-28.md).

### Changed

- Driving, collisions, opponents and effects now calculate with the original
  game's double precision instead of single precision. The original keeps its
  start-up precision setting with every DirectX runtime checked (5.0 to 9).
  Each difference is tiny, but races now follow the original's arithmetic.

### Fixed

- Adventure: Escape, controller B or Start on the result screen now counts the
  race instead of discarding it, Back is disabled in new-profile character
  selection, and the Adventure screen keeps the accepted profile rather than
  the last one browsed.
- Rescues: several karts rescued at once are handled newest first and retire
  as in the original, a homing rocket's arm shrinks with a rescued kart, and
  the player's wheels and slope forces use the shrinking kart during a rescue.
- Track: ground heights, slopes and the fallback planes use the original's
  plane calculation, and scenery and pickup rotations use its degree
  conversion.
- Bubble hits: the floating kart follows the route plane, and the player's
  slide resets as in the original.
- HUD: text, mesh positions and string scales follow the original's
  arithmetic.
- Menu sliders: arrow keys move 1, Page Up and Page Down move 17, Home is
  100 and End is 0. Clicking the track moves 17 towards the pointer and
  repeats while held, dragging follows the pointer, and the thumb sits at the
  original height. Touch and controller input are unchanged.
- The local development server no longer stops when a browser cancels a file
  request.

### Documentation and tests

- Extended the comparison report with the second pass, the precision switch
  and its evidence, and the follow-up fixes.
- Added original-instruction fixtures for both precisions, including the
  rescue queue, the rescue-scaled matrix, track planes, placement angles,
  HUD layout and kart sweeps with rails; the tests compare them exactly.
- Fixed browser tests that resumed only the clock, or started their own ticks
  behind the race clock.

## 1.0.1 — 2026-10-28

Source and desktop release for Linux x64, Windows x64, macOS Intel and macOS
Apple Silicon, with ten gameplay and menu corrections from a comparison
against the recovered original code. Existing saves, profiles, unlocks,
settings and records keep working without migration. See the
[1.0.1 release notes](docs/releases/1.0.1.md) and the
[comparison report](docs/original-comparison-2026-10-28.md).

### Fixed

- The player no longer waits 250 ms between bonus pickups; as in the
  original, only opponents have that cooldown.
- The starting rank now comes from the previous finished race's position, as
  the original reads it from Race.ini. A new save field carries it over
  unfinished races; older saves need no migration.
- Music and effects volumes of 29, 57 and 58% no longer lose 1%, and the
  effects volume no longer drops further on each race.
- The lap time stays frozen after the finish, including when the browser or
  desktop window loses focus during the results.
- The player's waypoint is chosen before the ground update, as for opponents.
- Keyboard throttle, brake and steering round like the original's
  single-precision arithmetic.
- Only keys that type a character skip the intro: arrow keys and Alt
  combinations no longer skip it, and Backspace now does. Controller, mouse
  and touch skipping are unchanged.
- The race's random number stream includes the original's draw when the
  player's record is first used. Normal play looks the same.
- Saved opponent result times use the opponents' current progress.
- The unused AI forced-route counter reads the efficiency level, as in the
  original.

### Documentation and tests

- Added the original-code comparison report, with evidence for each fix, the
  intentional differences kept and the open questions.
- Added focused tests for each fix and recorded unit and browser validation.
- Clarified the 1.0.0 publication scope and the source archive command.

## 1.0.0 — 2026-10-26

Source and desktop release for Linux x64, Windows x64, macOS Intel and macOS
Apple Silicon. The complete `original-source/` reference is published with the
source on GitHub and GitLab and included in release source archives. See the
[1.0.0 release notes](docs/releases/1.0.0.md).

### Changed and fixed

- Moved editable port modules and the HTML/CSS inputs into `source/`, with a
  purpose guide. `src/` now contains generated runtime bundles; normal browser
  and desktop launches refresh and use them. Added `npm run bundle` for a local
  runtime refresh and updated documentation for the separate folders.
- Combined generated JavaScript into lazy-loaded bundles while keeping editable
  source modules. Added `npm run preview` and deferred renderer/AI loading from
  menus; existing save keys, formats and desktop profiles are unchanged.
- Reduced redundant HUD uploads and temporary transform/effect/item allocations.
- Shared browser/desktop file serving and fixed canceled track loads returning
  after Back. Hardened settings fallback without migrating valid saves.
- Reorganized documentation and corrected stale setup/status instructions while
  preserving historical evidence. See [the efficiency review](docs/code-efficiency.md).
- Movies start immediately, retrying muted when the browser blocks sound.
  A bottom-left **Geluid inschakelen** button enables audio without restarting
  playback and enters fullscreen if needed. Removed the intro Start button
  and its overlapping startup notice.
- Added the original runtime's recovered C/assembly in `original-source/`,
  with input hashes, reproducible export tooling and explicit analysis limits.
- Restored original menu entry focus and name-entry Return-key release timing.
- Corrected bonus/turbo and engine-sound ordering within the player update.
- Restored sound continuity during native Pause/Quit screens and music restart
  polling; retained host focus-loss suspension across pending pause dismissal.
  See [the separate original-code comparison](docs/full-source-audit.md).

### Distribution and compatibility

- Version 1.0.0 appears in **Instellingen → Meer instellingen** and desktop
  package metadata. `package.json` remains the version authority.
- Existing settings, Adventure profiles, unlocks, high scores and records keep
  their storage formats, browser origins and desktop profile location. No save
  reset or manual migration is required.
- Every release update must continue publishing the entire `original-source/`
  folder to both repositories and include it in source archives. These are
  recovered C-like pseudocode, assembly and provenance, not the original
  developers' authored source project.

### Release validation boundary

No tests, gameplay runs, package verification or build checks are run for this
release, as requested. Packages are built and published without those checks.
Earlier focused source and compatibility results remain historical evidence;
they do not establish that these 1.0.0 packages have been tested. Existing
original-game parity and target-device limits remain documented in
[remaining work](docs/remaining-work.md).

## 0.9.0 — 2026-10-25

Source update since the published 0.1.0 release. All prepared assets needed
to run locally remain included. Desktop packages are available for Linux x64,
Windows x64, and macOS Intel and Apple Silicon.

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

- Eight desktop packages are published with this changelog and SHA-256
  checksums. Linux/Windows packaging runs on Linux; macOS DMG and ZIP creation
  runs on a Mac through a manually dispatched GitHub workflow. The existing
  `v0.9.0` game-source tag remains unchanged.
- All four platform payload checks pass with the same 6,868 game files.
  The packaged Linux app opens with the normal sandbox and shows version 0.9.0
  in Meer instellingen. Windows and macOS gameplay have not been runtime-tested.
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
open. Windows packages have no publisher signature; macOS packages use ad-hoc
signing without notarization. See
[remaining work](docs/remaining-work.md) and [validation](docs/validation.md).

## 0.1.0 — previous source release

The first published source snapshot included the browser and Electron game,
prepared assets, original menus and race modes, local setup and packaging
instructions, research and retained validation. See the
[original release notes](docs/releases/v0.1.0.md).
