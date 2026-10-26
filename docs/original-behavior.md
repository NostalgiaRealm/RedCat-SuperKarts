# Original behavior and evidence ledger

Evidence classes: **confirmed static** means a directly decoded original
file or executable; **confirmed runtime** requires a reproducible observation;
**inferred** and **unresolved** must not be treated as native parity.
Static parameter values alone do not establish their runtime application.
**Native instruction comparison** means original executable bytes were run
under Unicorn with the input, clock, external-call stubs and x87 precision
recorded in the fixture. It establishes that bounded routine behavior, not
observation of the complete Windows game.

## Inputs and authority

- Installed data: `/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data`.
- CD: `/home/rick/Games/UnpackedISO/RedCat Superkarts/RedCat Superkarts`.
- Technical reference (read-only): `/home/rick/Documents/Rebuilds/RedCat Spookkasteel/RCSPOOK_NEW`.
- New extraction, analysis and development are confined to this project.

## Format compatibility

The Spookkasteel `docs/asset-formats.md`, `docs/menu-media.md`,
`tools/extract_menu.py`, `source/main.js` and `source/render-quality.js` were consulted
before implementation. SuperKarts has racing maps rather than GBSP levels.
Its archives share the uint16-count/24-byte name-and-offset record layout;
level, actor, script and movement compatibility is not established.
Spookkasteel's movement/collision/VM must therefore not be copied wholesale.
Current source and current native evidence outrank historical backlog notes.

## Menus and inputs — confirmed static

`data/ini/trans.dat` defines main, character selection, country selection,
debriefing, options, adventure, controls, adventure briefing and highscore
phases. Main links to Adventure, QuickRace, Options and Highscore.
`data/ini/shellang.ini` provides original Dutch labels.
`data/ini/shellimg.dat` maps character/country cards, reward images, country
information images and adventure order.

`data/game.ini [INPUT]` sets Windows VK codes 38/40/37/39 for accelerate,
brake, left and right, 17 for bonus, 18 for handbrake (arrows, Ctrl, Alt).
This does not by itself establish braking/reverse transitions.

Four player portraits are listed in `[CHARPICS]`: RedCat, WhizzKitty, Brutus
and Max. `[AVAILABLE_CHARACTERS]` also includes country opponents; that is
not evidence that all ten characters are selectable.

`track.ini [MAPS]` maps six countries to Etappe0–5. `shellimg.dat
[ADVSEQUENCE]` defines 24 stages: six country races, six time trials,
six item races and six duels. BonusRace identifiers are retained legacy
scaffolding: there is no shipped menu/campaign entry and its HUD methods only
log. `research-legacy-features.md` records the complete bounded reachability
search, together with inactive ordinary traffic and discarded money values.

## Native behavior work

Detailed records are maintained in:

- `research-startup.md`: PE identity, working directory, startup, timing.
- `research-assets.md`: archive/map/model/image/media formats and provenance.
- `research-gameplay.md`: race rules, constants, physics and unresolved systems.
- `research-ai.md`: original opponent states, difficulty tables, decisions,
  shared random/occupancy order and executable quirks.
- `research-kart-collision.md`: paired contact response and full dynamic sweeps.
- `research-track-surfaces.md`: original texture inventory, ground selection,
  separate barriers and active authored marker rules.
- `research-race-sound-coverage.md`: trigger reachability before mixing,
  original missing sound names and real browser playback.
- `research-camera-speed.md`: cold timing history, all camera keys, phase
  gates, damping and native transform comparisons.
- `research-weather-integration.md`: update/draw order, weather, skidmarks,
  rocket rings, native clock domains and ground-dependent kart shading.
- `research-legacy-features.md`: inactive identifiers and no-op damage paths.

## Established startup and timing

The launcher runs `rcskmenu.dat /FIRST` with the data directory as its working
directory. The menu plays the intro. Native exit codes 0x28/0x29 hand off to
`rcskspel.dat` without extra arguments; returning to the menu omits `/FIRST`.
Static tracing and an isolated Wine 11 Staging working copy corroborate this.
Any delivered native keypress or mouse button skips the intro; a printable key
was also observed at runtime.

The main loop enforces at least 25 milliseconds between render iterations.
It applies one variable, filtered simulation update per iteration rather than
a fixed 32 Hz simulation. The delta filter uses weights .5/.25/.125/.125,
starts with .1-second history and caps/substitutes at .1 seconds. Race clocks
use separate pause-aware millisecond timing. The live port now schedules one
measured variable update per admitted native gate, independently of uncapped
browser rendering. Delayed callbacks are not replayed as fixed steps. Absolute
clock arithmetic and pause resets follow the original instruction traces;
the browser still supplies its own timer and explicit clock epoch. See
`research-variable-update-timing.md`. The former fixed 25 ms host is retained
only for explicit deterministic replay and historical reports.

Startup `0x442fc0 → 0x4ac410 → 0x4a1510` changes the trigonometric table to
**4096 entries**. This overrides the PE's initial 1024 value. Fixture generation
now executes the initializer, rather than using the initial global as a
runtime assumption. Native render order is Z→X→Y, selected by `0x42ccf0`.

## Original presentation now connected

Twenty Delphi forms, original bitmap states, Comic Sans fonts, Dutch language
tables, caption rectangles and bitmap-defined window regions drive the menus.
Control info before QuickRace is the original controls form in mode 0:
the help paragraph/default/cancel buttons are hidden and Start moves to
384,410. The separate settings mode hides the start-info checkbox instead.

`RCSK.HLP` provides 13 original topics, 46 images, internal links and original
formatting. The [Help follow-up](research-help-navigation.md) verifies the nine
explicit links and 13 keyword mappings directly from the HLP. The old HelpDeco
browse-chain warnings are resolved: every browse pointer is the no-link sentinel,
so the source has no authored Next/Previous sequence to reconstruct.

Menu sounds include loose CD files in `data/shellsnd` and `Media/sounds`.
Five referenced filenames are absent from all supplied sources; no sounds
are substituted. See `assets/audio/menu-sources.json` in prepared output.

The race camera uses local position (0,50,-150), target (0,50,0), with
per-update position damping (.1,.1,.5) and no target damping. Its initial
position height is 20. Native horizontal FOV is approximately 81 degrees;
the D3D viewport clip region corrects aspect, yielding vertical FOV
65.2840397 degrees at 4:3. Near/far are 1.5/12500.

Keys1/2/3/4 retain their original phase gates and first-person, held rear-view
and lower-target behavior. Selecting a camera updates the persistent active
pointer; it is not overwritten unconditionally by startup/finish cameras
on the next tick. First-person hides the complete player body and its shadow.
The startup path captures the first filtered delta of0.1 after cold timer
initialization. The reference host explicitly models that history.

Player lean requests use signed pre-input lateral speed. Nearest-opponent
look requests, braking, reverse and turbo follow their original callback
order. Pickup/hit requests restart the current queue head immediately;
completing a head resets and displays the next head in that same callback.
Animation timestamps compare raw GetTickCount, advance at most once and
discard excess elapsed time. The documented60000ms reference epoch replaces
host uptime; it does not assert a measured Windows launch time.

The sound audit covers all52 discovered native call sites before applying
mixing corrections. Race source levels, shared FX-group writes, music's
DirectShow attenuation, the original FX0→75 repair at race start and independent
menu/movie gain are retained. Absent original names remain silent. The browser
checks distinguish decoded audio from actual sound-start events.

## Race start, results and difficulty

`research-startup.md` records the 28 pause-aware timer records, active green
transition, countdown actor animation passes, finish/failure camera updates and
blocking key-release loops. Absolute engine time continues across pause, while
race timers pause; these domains are not interchangeable for opponent decisions.

`research-gameplay.md` records the original result writer, qualification rules,
24-stage sequence, profile slots, unlocks and movie order. Easy/normal/hard
country races accept zero-based finishing ranks up to 4/2/0 respectively.
The star-race condition is exactly 12 stars, and duels require rank zero.
The native menu ignores a race result when PLAYER.finished is zero, including
the normal timeout path. Highscores compare best-lap time strictly, across
difficulties; the original time formatter's rounding quirks are preserved.

The supplied race settings load motor, tyre and gearbox values of one. The
later player constructor clears all six upgrade switches before active
movement, NPC setup and timer initialization. Preserve both the loaded values
and that reset; [constructor evidence](research-startup-upgrades.md) supersedes
the earlier assumption that the loaded values stay active. These switches are
not difficulty controls. No reachable upgrade purchase menu exists in the
shipped flow, and the collision-damage increment routine is a single return.
NPC grip also reads the player's tyre/low-speed turn globals;
[opponent research](research-ai.md) records this cross-racer dependency.

## Platform adaptations

Browser audio starts after a user gesture when autoplay is blocked. Responsive
menus preserve individual artwork aspect ratios. The driving research camera
preserves the native vertical framing on wider displays and the native
horizontal framing in portrait. Rendering interpolates native camera/body
poses independently of the simulation; original mesh-frame animation remains
discrete. Modern display/input controls use original UI art where applicable.

The user reports that WineD3D cannot render the actual race properly. Wine
startup/menu observations and instruction-level native comparisons therefore
do not establish whole-race visual or handling fidelity.

## Follow-up composition corrections

`research-followup-audit.md` records the subsequent whole-runtime audit.
Original menu dialogs apply their own OK/Cancel rules; key capture, main focus
and nested tab order follow the native controls. The recovered advanced display
form controls the original texture brightness, filtering, particles and alpha
effect gates. HUD sampling retains its separate state cache, including the
first linear overlay frame when world filtering is disabled.

Mapped driving keys, camera keys and the hardwired Space sound use their
original Shift gates. Keyboard and analog input do not acquire the digital
joystick's separate Space-handbrake fallback.

Bubble-hit shells copy actor poses before racer movement and clean up on the
original settle/replacement paths. Rescue relocation keeps its old draw matrix
for that frame while color, sky and shadow-height sampling use the updated
logical coordinates. Progress uses the relocated body's sector history.
These behaviors are established with executable instruction fixtures and
separate browser integration checks; they are not inferred from Wine images.
