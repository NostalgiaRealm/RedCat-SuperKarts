# RedCat SuperKarts plan

The browser/Electron game and prepared assets are available in source and in
the published **0.9.0** desktop packages. Later source changes have their own
focused checks; downloaded packages do not automatically include them.
See the [changelog](CHANGELOG.md) and [validation record](docs/validation.md)
for those separate checkpoints.

## Current priorities

The [remaining-work list](docs/remaining-work.md) is the maintained backlog.
It distinguishes confirmed defects, incomplete validation and optional features.
The main validation gaps are a reliable original Windows race reference,
full races using the live variable-cadence host, the France hard timed race,
a naturally driven 24-stage Adventure and physical-device coverage. These
are verification gaps, not permission to weaken the original game rules.

## Implementation and evidence

| Area | Current reference |
| --- | --- |
| Player instructions, controls and saves | [README](README.md) |
| Implemented features versus verified original behavior | [Feature inventory](docs/feature-parity.md) |
| Original inputs, evidence classifications and authority | [Original behavior](docs/original-behavior.md) |
| Recovered code from all five original runtime modules | [Original-code reference](original-source/README.md) |
| Confirmed corrections from the complete code-export comparison | [Source audit](docs/full-source-audit.md) |
| Focused checks and their reproduction requirements | [Development guide](docs/development.md) |
| Editable files, generated runtime and refresh commands | [Folder guide](docs/runtime-layout.md) |
| Recorded outcomes, source checkpoints and platform limits | [Validation](docs/validation.md) |
| All guides and subsystem research | [Documentation index](docs/README.md) |

## Constraints that remain in force

- Preserve the supplied original installation and disc files. Extraction and
  analysis write to this project, not back to those inputs.
- Compare original runtime behavior and callers, rather than treating an INI
  value, filename or unused enum as proof of an active game feature.
- Preserve the user's intentional adaptations: browser/Electron support,
  widescreen and touch/controller input, uncapped rendering, additional settings,
  no-clip/unlocks, media activation controls and narrowly scoped stuck recovery.
- Keep save compatibility and the original menus, assets and active rules.
- Use checks relevant to each source change. Build or publish only as requested;
  a source fix does not update an already running or downloaded package.

## Acceptance and history

Implementation and comparison are separate statuses. A successful build,
extracted asset, scripted race or plausible image does not prove complete
native parity. Unknown original behavior needs evidence before replacement.

The [earlier long-form plan](docs/history/reconstruction-plan.md) preserves
milestones, initial discoveries and historical verification counts. The
[checkpoint overview](docs/history/validation-overview.md) preserves the earlier
README summary without repeating it in current setup instructions. The complete
accepted original request remains in [docs/request.txt](docs/request.txt).
