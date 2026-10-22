# Control-only driving validation checkpoints

The final reports use the frozen runtime after scenery collision, audio,
weather, streams, squash and shared-RNG integration. They record hashes of
every runtime source file and the test driver, and reject source changes
during a run. Older attempts remain below as historical checkpoints.

## Method

`tools/validate-driven-races.mjs` composes the original asset data and recovered
race simulation. `tests/helpers/route-test-driver.mjs` supplies ordinary analog
throttle, brake and steering. It never changes a kart pose, velocity, trigger,
pickup, race clock or physics table. Its route-following policy is testing
infrastructure, not a claimed reconstruction of an original player or NPC.
Automatic recovery uses brake/reverse and steering inputs.

Runs start at the original grid pose in the active driving phase, use the
25ms reference cadence through the native delta filter, include configured
opponents and item interactions, and end at original finish or timeout phase.
They do not exercise the opening camera/countdown or menu save flow. Separate
browser tests cover those interfaces with controlled finish fixtures.

Input-stream hashes, lap events, positions, ranks, pickups, and failure
attempts are retained. Reaching five laps is reported separately from original
Adventure qualification; a slow control policy can finish without placing
well enough or collecting the required twelve stars.

## Final mode coverage, 2026-10-20

Every course has a control-only **qualified completion in all four active
modes on easy difficulty**. Star mode collects exactly twelve stars on every
course. These are separate races from the original grid, not an uninterrupted
24-event Adventure UI playthrough.

| Report under `evidence/gameplay/` | Coverage |
| --- | --- |
| `final-driven-normal.json` | Ordinary races, all courses and difficulties |
| `final-driven-stars.json` | Six easy star races; five laps and twelve stars each |
| `final-driven-timed-duel-fast.json` | Easy timed/duel races on courses 0, 1, 4, 5 |
| `final-driven-timed-duel-careful.json` | France timed/duel completions; also retains unsuccessful England attempts |
| `final-driven-england-timed.json` | England timed qualification with shorter steering look-ahead |
| `final-driven-england-duel.json` | England duel qualification, first place |

The England control-policy correction changes look-ahead from `.7` to `.5`
with target speed `70`, proportional gain `1.5` and damping `.6`. It finishes
the timed race in 304,175 ms and the duel in 309,925 ms, both without reverse
recovery. The longer look-ahead misses the first time gate or loses the duel
after stalls near the stone arch. No game code, physics, timer, collision,
opponent, item or qualification rule changed. The diagnosis and failed traces
are retained in `england-timed-diagnosis.json` and the careful report.

The test-only star planner reads original road links, rail geometry and solid
scenery bounds to plan approaches and exits. It still supplies ordinary
steering, throttle and brake; original pickup collision and eligibility
decide whether a star is collected.

## Historical results

These reports predate registered scenery collision and native smoke/RNG
integration. They have no exact source fingerprint and are not current-runtime
verification.

All six courses completed five laps at each of the three difficulty settings:
18/18 normal-race completions in `driven-races.json`. Easy qualified on all six;
the cautious medium/hard driver finished last and did not qualify. This is not
evidence that every difficulty is winnable by that test policy.

For easy difficulty, the combined successful attempts were:

| Course | Normal | Timed | Duel, one opponent | Item, twelve stars |
| --- | --- | --- | --- | --- |
| Netherlands | Qualified | Qualified | Qualified | 7 stars |
| Germany | Qualified | Qualified | Qualified | Qualified, 12 |
| England | Qualified | Qualified | Qualified | 10 stars |
| France | Qualified | Qualified | Qualified | Qualified, 12 |
| Spain | Qualified | Qualified | Qualified | Qualified, 12 |
| Italy | Qualified | Qualified | Qualified | Qualified, 12 |

Normal results are in `driven-races.json`. Timed successes use
`driven-timed-fast.json`, `driven-time-trials.json`, and `driven-retries.json`.
Duel successes use `driven-duels-fast.json` and `driven-retries.json`.
Item successes use `driven-stars.json` and `driven-stars-wide.json`; the later
rail-aware planner improved England to ten in `driven-stars-rails.json`.

The unsuccessful attempts remain in the reports: the initial faster timed
policy expired on England/France and on medium/hard Netherlands; the fast
England duel became stuck, then a slower policy completed it. Missing stars
were not injected. Distance diagnostics put the player on another lane or too
far from the remaining stars; no original physics defect was established from
those failures. Further route-planner work must remain test-only.

## Reproduction

Default normal-race matrix:

```sh
node tools/validate-driven-races.mjs
```

An individual star-collection attempt:

```sh
RCSK_DRIVEN_CASES='0,0,2' RCSK_DRIVEN_SEEK_STARS=1 \
RCSK_DRIVEN_REPORT=evidence/gameplay/driven-stars-current.json \
node tools/validate-driven-races.mjs
```

Cases are `track,difficulty,mode`; semicolons separate multiple cases.
Modes are normal0, timed1, item2, duel3. Driver speed/lookahead/steering gains
are recorded per report and can be selected with `RCSK_DRIVEN_SPEED`,
`RCSK_DRIVEN_LOOK`, `RCSK_DRIVEN_P`, and `RCSK_DRIVEN_D`.
The reports establish composed port behavior only. They are not a whole-game
comparison with the original Windows executable, nor a driven 24-event
Adventure playthrough.
