# Player recovery regression evidence

This is a source-only regression audit of the explicitly requested added
player safeguard. Automatic stuck detection is not claimed as original game
behavior. Original movement, solid scenery collision, rescue animation and
voice dispatch remain the exercised mechanisms. The user's running desktop
race was neither instrumented nor controlled, and no package was rebuilt.

## England tyre reproduction

The original England OMP contains solid tyre placement **230**, sector 125,
`banden00.d3d` / `eng02.tga`, at
`[-7226.55517578125, 0, 6466.47705078125]`. Its original mesh bounds are
X `[-114.19992065429688,128.27020263671875]`,
Z `[-23.27532196044922,19.459718704223633]`.
The nearby decorative tyre placement 231 and Nessie placement 238 identify the
same stretch visible in the supplied screenshot. The screenshot alone does
not provide the player's exact live coordinates; this is a controlled
reproduction against that solid tyre asset, not a reconstructed live save.

The fixture starts WhizzKitty at clear original road position
`[-7027,0,6317]`, yaw 512 in the game's 4096-unit angle system, sector 124.
After initialization, only ordinary analog throttle 1 and steering +0.3 are
submitted through the composed simulation. The kart drives into tyre 230 and
remains confined near it while still attempting to drive. No rescue call,
pose, velocity, timer, progress or pickup is forced after setup.

All four race modes pass the retained composed regression. On the frozen
source, automatic detection occurs at 8800 ms and the original 40-frame rescue
finishes at 9775 ms. The safe return is authored waypoint 590,
`[-6937.10400390625,0,6314.84912109375]`. Assertions cover full-footprint and
exit clearance, exactly one occupancy entry, synchronized sector history,
no following-frame phantom trigger, no new lap/gate/star, no added deadline,
both original DISAPP/REAPP requests, and subsequent driving beyond 100 units.

- Fixture: `tests/helpers/england-tyre-fixture.mjs`
- Four focused tests: `tests/player-recovery-integration.test.mjs`
- Reproducible report: `tools/diagnose-england-tyre-recovery.mjs`
- Results and frozen hashes: `evidence/player-recovery/england-tyre.json`
- Focused test log: `evidence/player-recovery/integration-tests.log`

## Source browser

`tests/player-recovery-browser.mjs` launches its own Chromium instance with
software WebGL and a standard Gamepad API fixture. It uses the real frame
loop for the positive recovery. All four check groups passed, with no page,
console or HTTP errors and no changes to the recorded source hashes:

1. Nine simulated seconds each of idle, moving reverse and free flight cause
   no automatic rescue. Reverse travels 424.44 units; free flight leaves the
   detection accumulator zero. These negative cases advance the normal
   DrivingView callbacks at 25 ms without waiting wall-clock time.
2. The controlled start is original road and has clear full kart bounds.
3. Actual tyre contact automatically produces the shrinking WhizzKitty kart
   and original rescue rings. Screenshots were visually inspected.
4. Both original DISAPP and REAPP WebAudio sources start with a running audio
   context. After return, normal driving covers 507.16 units, with no lap/star
   award and no active rescue left behind.

The current report is `evidence/player-recovery/browser/report.json`, with
`tyre-blocked.png`, `tyre-shrinking.png` and `tyre-recovered.png`. The initial
passing browser run remains in `browser-initial/`; the passing run before the
final detection-order correction remains in `browser-before-order-fix/`.
This proves source browser
behavior and software rendering/audio-source playback, not physical GPU,
speaker output or an updated AppImage.

## All-course candidate audit

`tools/audit-recovery-road-candidates.mjs` tests every authored node without
marker 50 through the current safety predicate. It uses car 0's original
40.83×64.00-unit bounds, the collision margin, every footprint corner, and
the 30-unit forward exit, against the initial original rails, scenery and
racer occupancy.

| Course | Safe authored nodes | Sectors containing one |
| --- | ---: | ---: |
| Nederland | 516 | 134 |
| Germany | 460 | 156 |
| England | 610 | 138 |
| France | 482 | 159 |
| Spain | 414 | 146 |
| Italy | 359 | 140 |

Italy sectors 17/18 are the only sectors without such a node within the prior
12 sectors. No sector lacks one within less than half a circuit. The runtime's
same-lap progress restriction and preference for genuinely travelled safe
anchors still apply. These counts do not guarantee a destination under
arbitrary moving occupancy, at the beginning of a lap, or with the minimum
relocation-distance constraint. Evidence:
`evidence/player-recovery/initial-road-candidates.json`.

Retained historical Netherlands scenery and Germany/France paired-kart
captures additionally demonstrate why the detector must observe actual XZ
travel: local velocities and vertical movement can remain nonzero while XZ
is frozen. They were used as audit references, not relabeled as fresh races.
