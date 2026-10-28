# Documentation

[Run the game, controls and saves](../README.md) · [Current plan](../PLAN.md) ·
[Changelog](../CHANGELOG.md) · [Original accepted request](request.txt)

Use the player guides for setup and everyday use. Developers can start with
[focused validation](development.md), [feature status](feature-parity.md) and
[remaining work](remaining-work.md). The [code and loading review](code-efficiency.md)
explains loading changes and save compatibility. The current
[folder guide](runtime-layout.md) separates editable `source/` modules from
generated `src/` runtime files.

Research reports preserve native addresses, original-file hashes and dated
verification results. A historical successful test is not a fresh check of the
current source. [Original behavior](original-behavior.md) defines the evidence
classes; [validation](validation.md) keeps later checks separate from older
full-race and package results.

The [original-code reference](../original-source/README.md) contains reconstructed
C and assembly for all five runtime modules, with discovery limits and provenance.
It is not the lost authored source project. Files under `docs/evidence/` and
`evidence/` are machine-readable records linked by the relevant reports, rather
than setup instructions. Paths shown in code snippets are relative to the
repository root unless the document says otherwise.

Current code references use `source/`. Frozen reports and the retained
historical plan can still name the old editable `src/` paths; those hashes
describe their original checkpoints. Do not compare a generated bundle at
`src/` with an old individual-module hash. The corresponding authoring file
now lives at the same relative path under `source/`.

## Playing, settings and distribution

- [Meer instellingen and optional browser features](more-settings.md)
- [Player soft-lock recovery](player-stuck-recovery.md)
- [Desktop application](desktop.md)
- [Host RedCat SuperKarts on a subdomain](hosting.md)

## Working on the port

- [Editable files and generated runtime](runtime-layout.md)
- [Authoring-folder purpose](../source/README.md)
- [Test-folder purpose and diagnostic server](../tests/README.md)
- [Code, loading and documentation efficiency](code-efficiency.md)
- [Development and focused validation](development.md)
- [Feature inventory and parity](feature-parity.md)
- [Validation](validation.md)
- [Remaining work](remaining-work.md)
- [Original behavior and evidence ledger](original-behavior.md)
- [Original-code decompilation and port comparison](full-source-audit.md)
- [Gameplay source comparison — 26 October 2026](full-source-audit-gameplay.md)
- [Original-code comparison: presentation and audio](full-source-audit-presentation.md)
- [Original-code comparison and corrections — 28 October 2026](original-comparison-2026-10-28.md)

## Original files and startup

- [Original asset research and reproducible conversion](research-assets.md)
- [Native startup, menus, engine and timing investigation](research-startup.md)
- [Gameplay evidence and recovered subsystems](research-gameplay.md)
- [Legacy identifier reachability](research-legacy-features.md)
- [Loaded upgrade switches are cleared during player construction](research-startup-upgrades.md)

## Handling, opponents and recovery

- [Native opponent driving](research-ai.md)
- [Kart collision](research-kart-collision.md)
- [Registered scenery collision](research-scenery-collision.md)
- [Original track surface and collision rules](research-track-surfaces.md)
- [Registered player jump callbacks](research-player-jump.md)
- [Danger-zone recovery](research-environment-rescue.md)
- [Player recovery regression evidence](research-player-recovery-regressions.md)
- [Registered NPC catch-up overflow](research-npc-vertical-overflow.md)

## Menus, help and race HUD

- [Menu transactions, original controls and advanced display settings](research-menu-settings.md)
- [Original menu sound dispatch](research-menu-audio.md)
- [Initial menu greeting](research-menu-greeting.md)
- [Original WinHelp navigation](research-help-navigation.md)
- [HUD elements across the original race modes](research-hud-modes.md)
- [Original HUD controller audit](research-hud-arrows.md)
- [HUD notices and activation audit](research-hud-notice-audit.md)
- [Original lap-time display hold](research-lap-display.md)
- [Original quit-screen timing](research-quit-requester.md)
- [Original start countdown](research-countdown.md)
- [Touch controls: sources and behavior](research-touch-controls.md)

## Rendering, cameras, animation and effects

- [Active render composition audit](research-render-audit.md)
- [Camera speed and behavior audit](research-camera-speed.md)
- [Kart-shadow audit](research-kart-shadows.md)
- [Original HUD framebuffer and smoke-test maintenance](research-hud-framebuffer.md)
- [Native texture precision and filtered color keys](research-native-texture-precision.md)
- [Native texture upload and color-key filtering](research-texture-key.md)
- [Texture-key sampling across effects](research-texture-effects.md)
- [Complete race texture key inventory](research-texture-keying-inventory.md)
- [Bubble-hit shell composition](research-bubble-shells.md)
- [Original racer and projectile streams](research-streams.md)
- [Streams, squash hazards and render submission](research-streams-squash-order.md)
- [Weather, skidmarks and race-loop integration](research-weather-integration.md)

## Sound and music

- [Race sound coverage](research-race-sound-coverage.md)
- [Character speech and homing warnings](research-character-voice.md)
- [Motor starter timing](research-engine-start.md)
- [Power-up pickup and firing sound parity — 25 October 2026](research-powerup-audio.md)

## Timing and race-validation checkpoints

- [Variable native update timing](research-variable-update-timing.md)
- [Native frame cadence and validation scope](research-frame-cadence.md)
- [Native presentation and cadence](research-presentation-cadence.md)
- [Follow-up fidelity audit](research-followup-audit.md)
- [Control-only driving validation checkpoints](research-driven-validation.md)
- [Germany, France and Italy completion checks](research-race-completion.md)
- [Six tracks, three difficulties, four modes](research-full-race-matrix.md)
- [Full-race results](full-race-results.md)
- [Germany hard time-trial completion](research-germany-timed-completion.md)
- [Netherlands hard time-trial completion](research-nl-timed-completion.md)

## Release notes and historical summaries

- [Publication policy: include all original-source files on both hosts](releases/README.md)
- [RedCat SuperKarts v1.0.1 — desktop and source release](releases/1.0.1.md)
- [RedCat SuperKarts v1.0.0 — desktop and source release](releases/1.0.0.md)

- [RedCat SuperKarts v0.9.0 — desktop and source release](releases/v0.9.0.md)
- [RedCat SuperKarts v0.1.0 — source release](releases/v0.1.0.md)
- [Earlier reconstruction plan](history/reconstruction-plan.md)
- [Earlier validation overview](history/validation-overview.md)
