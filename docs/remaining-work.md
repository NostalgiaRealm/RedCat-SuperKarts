# Remaining work

This is the maintained list of validation gaps and optional work. The initial
22 October 2026 audit compared source, original-file research and retained
records at published base `ef2d30b5ccdabc260fcc7a628688d51266216cf1`; it ran no
races, tests or builds. Later corrections are dated below. That commit is the
initial audit baseline, not a claim about the current checkout. Historical
results retain their recorded source and platform scope.

## Rendering and test follow-up — 23 October 2026

The two confirmed rendering/harness items from this audit are complete in local
source, in the requested order:

1. **HUD rendering precision:** original font quads and overlay meshes now draw
   in native hierarchy order into a shared RGB565 composition surface. Native
   key filtering, vertex alpha and per-draw rounding apply against the world.
   Responsive layout, separate world resolution and uncapped rendering remain.
2. **Smoke-test maintenance:** world/HUD/presentation statistics are separated;
   Chromium, Firefox and source Electron checks use packed texture provenance
   and real HUD output instead of obsolete triangle/Canvas assumptions.

Focused original-atlas pixel, mode, sampler, resource-lifecycle and smoke checks
passed. See [implementation and validation](research-hud-framebuffer.md).
The opening audit itself was read-only; this follow-up ran only relevant checks,
with no full races, full test suite or builds.

## Source distribution update — 25 October 2026

The `v0.9.0` source update collects the movie-layout correction, HUD renderer,
Help navigation, redesigned touch controls, menu speech/flow fixes, power-up
audio audit and test/documentation updates for GitHub and GitLab.
See the [changelog](../CHANGELOG.md) and [source release notes](releases/v0.9.0.md).
The [movie CSS](../source/style.css) preserves the complete original 4:3 image;
its earlier check covered all 11 movies at six viewport shapes plus pixel checks
and intro skipping. The subsequent 0.9.0 packaging follow-up publishes Linux,
Windows and both Mac architectures, with matching payloads, a focused Linux
launch check, the changelog and checksums. It retains the existing game-source
tag and does not refresh full-race or target-device gameplay validation.

The stale setup, settings-location and rendering notes found during this audit
are corrected in the documentation update accompanying this file. Their
superseded implementation claims are not additional open gameplay defects.

## Code and documentation follow-up — 26 October 2026

The [efficiency review](code-efficiency.md) combines distributed JavaScript into
lazy-loaded bundles, reduces redundant runtime work and consolidates current
documentation without removing historical evidence. Focused source, bundle and
save-compatibility checks pass, including short drives on all six courses.
Existing save locations and formats are preserved. This is source maintenance;
it does not resolve the full-race, native-reference or physical-device gaps below.
The subsequent [folder separation](runtime-layout.md) makes every normal launch
use generated runtime files, with editable modules kept in `source/`.

## Remaining validation

The [26 October original-code comparison](full-source-audit.md) adds the complete
five-module decompilation reference and fixes newly confirmed menu entry,
name-release, bonus/engine order and pause/music differences. Its focused
instruction/browser checks do not replace the broader validation below.

| Priority | Work | Evidence and limits |
| --- | --- | --- |
| High | Validate full races with the current variable update host and recovery safeguards. | The retained matrix predates those changes. `tools/validate-driven-races.mjs` still supplies constant 25 ms steps; use measured/captured cadence or actual browser races to cover the live host. Keep deterministic reference checks separately. See [timing validation](research-variable-update-timing.md#live-browser-integration). |
| High | Complete France, hard difficulty, timed mode over five laps. | The historical matrix is 71/72 completed. The final documented attempt completes three laps and expires while still moving. This does not prove an impossible deadline or justify weakening original rules. See [full-race research](research-full-race-matrix.md) and [retained matrix](../evidence/full-race-matrix/race-matrix.json). |
| Medium | Drive all 24 Adventure events consecutively through the normal UI, saving, unlocks and movies. | Existing consecutive checks inject final-lap/star outcomes; they verify transitions, not a naturally driven campaign. Only 40/72 historical matrix cases qualify for Adventure; legitimate losses are separate from finishing. See [campaign check scope](research-followup-audit.md#consecutive-adventure-integration). |
| Medium | Compare against a functioning original Windows race. | Full framebuffer, audible mix, trajectories, cameras and animation comparisons remain unavailable under WineD3D. Live x87 precision also needs observation: isolated routines cover 24/53-bit modes, while the connected driver uses 24-bit arithmetic. Historical GPU filtering, rounding and dithering need a defined reference device. See [AI precision](research-ai.md#validation-and-precision) and [validation limits](validation.md#platform-and-device-limits). |
| Medium | Check target platforms and real devices. | Native Windows/macOS gameplay, Safari, real Android/iOS, physical controllers, GPU/audio hardware and high-refresh displays remain outside the recorded Linux software-rendered scope. Both Mac package architectures are now built on macOS, with ad-hoc signing; that does not establish gameplay validation. See [desktop scope](desktop.md#validation-scope) and [platform matrix](validation.md#platform-and-device-limits). |
| Lower | Broaden recovery coverage during those playthroughs. | The England tyre case is fixed in all four modes. Initial-node coverage does not guarantee a safe destination with arbitrary moving occupancy, every character or at a new lap. No new broken recovery case was established by this audit. See [recovery limits](research-player-recovery-regressions.md#all-course-candidate-audit). |

## Optional or intentionally deferred

- Publisher signing and notarization remain separate work. Version 0.9.0 now
  includes desktop downloads; the source-only restriction was superseded by
  the explicit request to build and publish this version.
- Original Help navigation is implemented and the obsolete browse-chain note
  is resolved: the source has no authored sequence or popup links. Native
  Windows window placement and non-scrolling header rendering remain browser
  presentation adaptations. See [Help navigation](research-help-navigation.md).
- URL-subdirectory hosting, nonstandard controller mappings, the old software
  renderer and custom fog/device profiles would extend the current supported
  scope. Subdomain-root hosting and standard controllers already have source
  support.

## Already implemented or deliberately unchanged

Do not reopen stars/arrows/notifications, lap-display or quit-screen timing,
RGB565 world rendering, texture-key filtering, kart shadows, steering/reverse
animations, camera controls, win movies, or the reported England tyre soft-lock
as missing features. Their source and focused records are listed in
[feature parity](feature-parity.md).

The five missing menu WAV references are absent from both supplied original
copies; they are not disconnected available recordings. BonusRace, ordinary
traffic, money purchases and collision damage are inactive shipped paths.
Undefined native storage uses documented deterministic policies, and the
anti-stuck safeguards are authorized deviations. None of these observations
establishes additional missing active gameplay.
