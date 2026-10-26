# Earlier validation overview

[Documentation index](../README.md) · [Current validation](../validation.md)

This overview was moved intact from the main README on 26 October 2026. Its
counts and conclusions describe the named earlier checkpoints; this move did
not rerun their tests or create new packages.

## Recorded checkpoints

These records describe the source and builds tested at each checkpoint. Earlier
full-race results remain tied to their historical runtime hashes.

### Initial broad checkpoint

The earlier broad checkpoint passed 374 JavaScript tests, four parser tests,
36 control-only race cases and 18 five-minute opponent runs. Every course
qualifies in all four modes on easy; every star race collects twelve stars.
Ordinary races finish at all three difficulties, with placing/qualification
reported separately. `evidence/final/validation.json` records that source,
build checks and retained unsuccessful attempts.

### Greeting, recovery and follow-up audit

Subsequent greeting, starter, danger-zone recovery and texture-key corrections
have focused native/browser
verification in `evidence/regressions/validation.json`. The subsequent broader
audit is documented in `docs/research-followup-audit.md`, with the build from
that checkpoint and separately refreshed checks in
`evidence/followup/validation.json`.
It restores menu transactions and advanced settings, original keyboard rules,
the missing bubble shell, rescue rendering and progress, and native arithmetic
details. It also checks all 24 Adventure transitions consecutively; those
controlled results are separate from physically driven race completions.

### Germany, France and Italy race completion

The three subsequently unfinished normal-race checks are now complete:
Germany 10:48.975, France 13:32.350 and Italy 9:25.975, all five laps and first
place using ordinary controls on identical frozen source. This follow-up
restores original jump callbacks and route settings, and adds an explicitly
authorized player rescue fallback for occupied or overlapping return points.
It retains the original effects and voices. Details and rebuilt-file
verification from that checkpoint are in `docs/research-race-completion.md` and
`evidence/race-completion/validation.json`.

### Full race matrix

The earlier full-race audit targeted all 72 track/difficulty/mode combinations:
71 finished, and 40 also qualified for Adventure. France on hard difficulty in
timed mode remains incomplete. Those historical fixed-25-ms results are recorded
in `evidence/full-race-matrix/race-matrix.json`; the verifier checked matching
source/asset hashes at that checkpoint. They do not establish full-race coverage
for the later variable update host and recovery changes. This audit corrected the native
race constructor's upgrade reset and mirrored rendering/input composition,
and added narrowly scoped recovery and nonfinite-opponent safeguards for
captured stuck cases. It retains the original physics, deadlines and gate
awards. That checkpoint includes 492 unit tests, eleven focused browser checks
and refreshed source-asset comparisons. See the
[full race results](../../docs/full-race-results.md) and
[research notes](../../docs/research-full-race-matrix.md).

### Extra settings and shadows

The extra-settings additions described above were checked alongside shadow
corrections. The shadow audit fixes viewport-edge disappearance and unintended
browser alpha compositing using the original shadow code and assets. Focused
checks and the refreshed static build from that checkpoint are documented in
[extra settings](../../docs/more-settings.md) and
[shadow research](../../docs/research-kart-shadows.md).

