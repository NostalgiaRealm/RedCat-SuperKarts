# Legacy identifier reachability

This is a bounded audit of the supplied menu, race binary and six tracks.
Recognizing an enum or retaining old strings does not demonstrate a playable
feature. Reproduction: `re-python tools/audit-legacy-features.py` writes
`evidence/native/legacy-feature-inventory.json` with binary hashes, source
bytes, full-disassembly direct-call references, absolute-address occurrences,
menu controls, campaign entries and track path counts.

## BonusRace mode4

The engine recognizes the numeric mode, but the supplied game does not offer
it through its normal menu/campaign flow.

- The country form has exactly three race radio controls.
  `46fefc`, `46ff20`, `46ff44` write types0,1,2.
- All24 authored `ADVSEQUENCE` entries use types0..3. Duel is supplied through
  adventure; no entry uses `BONUSRACE`.
- `shellimg.dat` has `RequiredTypes/BonusRace=0` and an empty BonusRace status
  icon. Its enum and fifth matrix column remain for profile compatibility.
- Engine portrait controller `46a3f0/46a720` recognizes case4, but
  `46aa20` (`InitBonusRace`) and `46aa70` (`HandleBonusRace`) only call the
  logger and return.
- `42c680` also recognizes4/5 for generic starting-position loading. This
  is not a menu entry or an authored race.

Classification: retained enum/config scaffolding, unreachable through the
shipped choices. Do not invent a fifth playable mode from these identifiers.

## Ordinary traffic and police paths

The original racing-engine traffic subsystem is still present in the binary.
`4077e0` can load `AI_BEHAVIOR/TBDFile` and `TRAFFIC TYPES` records. Its only
direct caller `412e00` immediately logs that traffic is disabled and returns.
No direct call or absolute function-pointer reference to `412e00` occurs in
the complete shipped PE scan. `42b1f0` reads `traffic_ai_model` into `53ba58`;
the only direct address reference found is that write.

The50 legacy traffic slots are initialized by `407680` with object/state/type
indices `-1`. The collision callback's `407cb0` lookup therefore does not
demonstrate that any traffic cars were created. Legacy path factories can
still reference traffic creation, but all six supplied PTHs have **zero**
builtin path types2..12. They contain six camera paths of type1 and35 authored
scenery paths using types13 and above. There are also zero OMP type4 traffic
light placements.

Classification: inactive legacy subsystem for the supplied content. The
moving trains, boats, animals and other authored scenery are separate live
paths and remain implemented. This is not a claim that an externally edited
configuration or invented path cannot invoke retained code.

## Money and upgrades

`42c0a0` reads `Race.INI [PLAYER] money` and immediately discards the return
value before its next log call. The supplied value is5000. The menu binary
contains no `money` string, and its profile handoff does not provide a purchase
interface or rewrite the motor/tyre/gearbox switches. Their supplied values
remain1 in the configuration file. However, the later game player constructor
`4319f0` clears all six upgrade globals before active physics, NPC and timer
setup. The active motor/tyre/gearbox table indices start at zero. The earlier
claim that the file's ones remained active is superseded by the initialization
trace in `../evidence/native/startup-upgrades.json`.

The old `money` field is separate from the live star/item counter written as
`EUROSTARS` by `42c570`. Star collection and campaign qualification remain
active behavior; their old Euro-related names must not be interpreted as a
missing shopping system.

Classification: inert legacy money read and constructor-cleared upgrade
switches; star collection remains a separate active system.

## Collision damage

The live contact callback `434c40` reaches `4350b0`, which selects the crash
sound, computes a bounded severity using `435030`, and passes it to `435630`.
The complete body of `435630` is the single byte `C3` (`RET`). It cannot
increment damage. REA independently confirms this function in
`evidence/native/rea-legacy-damage.json`, evidence
`ev_dfd8c854698e90f054cc1e7c037008b044934e142b95764a655b2c4d931c495e`.

`53be30` is loaded/clamped by `4354a0`, read by the expiry/status paths,
and reduced/clamped by the retained repair helper `435640`. The supplied
initial value is0. The `>98` expiry behavior remains meaningful for a
preloaded nonzero damage state; it does not justify adding collision damage.

The separate regional mesh-damage callback `4343d0` returns immediately when
body `+c8` is `-1`. Startup `42ccf0 → 49aec0(1000)` fills all damage-mesh
table pointers with zero. Object constructors `48ffc0/490130` only bind a
damage mesh when that table entry is nonzero. The complete decoded reference
inventory contains initialization, constructor checks, deformation access
and teardown, with no shipped fill/loader path found. The damage increment
computed in `4343d0` is not added to the regional values either.

Classification: crash audio and response are live; numerical collision damage
is explicitly a no-op; no active supplied mesh-damage binding was found.
Preserve the configuration/expiry branch without adding damage or deformation
that the original shipped path does not produce.
