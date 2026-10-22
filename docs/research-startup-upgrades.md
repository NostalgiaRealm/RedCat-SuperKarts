# Loaded upgrade switches are cleared during player construction

The shipped engine does not retain the motor, tire or gearbox upgrade values
read from Race.INI. Its player constructor clears those values before active
movement, opponent steering and race timer initialization. The port previously
used the loaded values throughout a race. This was a composition error: the
isolated force and timer calculations already accepted and matched both banks.

The correction preserves the raw INI loader result as `loadedUpgrades` and
applies an explicit construction reset to the effective `upgrades` object.
It changes neither the original table bytes nor time-gate deadlines.

## Original order and writes

The source is the installed `rcskspel.dat`, SHA-256
`68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f`.
The installed and CD `race.ini` are byte-identical, SHA-256
`8bebc97b0ec58a0b68e990319599230486ea6d5f163a5e7e5bec848a2a3be834`.
Both contain motor, banden, turbo, abs and versnellingsbak set to1; injectie
is absent and the integer reader returns its zero default.

| Stage | Original instruction/call |
|---|---|
| Startup reads configuration | `0x42d801` calls `0x42ad70` |
| Configuration loads switches | `0x42aea0` calls `0x42b870` |
| Startup constructs cars | `0x42db3d` calls `0x415d70` |
| Car initialization constructs player | `0x415db5` calls `0x4319f0` |
| Player constructor initializes ESI to zero | `0x431a0f` |
| Player clears switches after Phys loading | `0x431ecd..0x431eeb` |
| Car initialization creates opponents | `0x415dba` calls `0x417640` |
| Startup applies opponent setup | `0x42db42` calls `0x42df90` |
| Startup initializes route timers | `0x42dd80` calls `0x42d360` |

The six reset stores are unconditional. Successful Phys loading and its error
branch both converge at `0x431ecd`.

| Global | INI key | Reset instruction |
|---|---|---|
| `0x53bef0` | motor | `0x431ecd` |
| `0x53bef4` | banden | `0x431ed3` |
| `0x53bef8` | turbo | `0x431ed9` |
| `0x53befc` | abs | `0x431edf` |
| `0x53bf00` | versnellingsbak | `0x431ee5` |
| `0x53bf04` | injectie | `0x431eeb` |

The three effective switches modeled by the active force path are motor,
tires and gearbox. The other three clears do not remove collected race
bonuses: the bonus controller has separate state.

The direct-store inventory finds only the INI reader, constructor reset, and
the physics-tweaking menu `0x41a200` writing these globals. The latter requires
Tab plus `0x53ba6c==1` through `0x414160→0x41a5d0`; active root `game.ini`
has `HELPDESK.tweak_mode=0`. The old nested `ini/game.ini` is not the active
configuration. No later restore is present in the reviewed shipped startup.
The direct-store scan is a bounded static result, not a claim to prove all
possible indirect stores in arbitrary modified code.

## Consequences

Player engine, tires and gearbox now use bank0. NPC steering reads the same
cleared player tire flag. The route countdown in timer8 uses `0x415cf0` with
the original bank0 speed and no motor bonus. For hard WhizzKitty, the old
loaded1 premise gave Germany/Italy11seconds and France9seconds; the original
post-construction values give43seconds and33seconds respectively.

The time-trial gate countdown is timer18. Its source is the authored
`TIME_GATES` entry; all72 country/difficulty/character comparisons preserve
the exact same timer18 budget before and after this correction. Normal
race, star and duel results must also be reverified because changed vehicle
and NPC steering inputs change trajectories. Previous full-race reports are
historical evidence for the earlier runtime, not current completion claims.

Difficulty still selects `cars0..2.dat` and `Phys0..2.dat` directly. This reset
is independent of difficulty, character and menu race mode, and applies to the
common engine startup used by quick races and adventure events.

## Validation and scope

Reproduce the instruction evidence with:

```sh
/home/rick/.local/bin/re-python tools/native-startup-upgrades-fixtures.py
node --test tests/native-startup-upgrades.test.mjs \
  tests/native-player-phase.test.mjs tests/native-game-timers.test.mjs \
  tests/race-simulation.test.mjs
```

The generator runs the original `0x42b870` stores with the INI/file services
at explicit mocked boundaries, then runs both original Phys-loading exits
through all six clear instructions. All64 switch combinations ×2 exits
produce zero in every global. It separately runs original `0x42d360` in72
country/difficulty/character combinations to capture timer0/8/18 limits.
The original constructor's `xor esi,esi` is also executed directly.
This is isolated instruction execution and source call-order analysis,
not a full native Windows startup or Wine-rendered race observation.

`evidence/native/startup-upgrades.json` retains source hashes, original reset
bytes, exact callsites, direct stores,128 loader/reset traces and72 timer
comparisons. The targeted22 tests pass, including720 complete original force
cases,576 original timer initializations, all six composed tracks at all
three difficulties, and fixed native update behavior under varied render
refresh schedules.
