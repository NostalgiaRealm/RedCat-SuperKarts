# Player soft-lock recovery

This is an explicit port safeguard requested after WhizzKitty became stuck
against the stacked tyres on England. It is not claimed as original player
behavior. The original collision geometry, physics, tyres and rescue artwork
remain unchanged.

The screenshot matches England's solid `banden00.d3d` placement230, sector125,
near the bridge and Nessie. England has no waypoint marker50, so the original
environmental rescue condition cannot handle this tyre trap. The retained
regression starts on clear road at `[-7027, 0, 6317]` and reaches this actual
tyre through ordinary throttle/steering input. It does not force a rescue or
write the kart position after setup.

## Behavior

- Eight seconds of attempted driving within60 planar world units triggers a
  return. Detection uses actual travel, so wheel speed, vertical vibration and
  collision oscillation cannot conceal a stationary trap.
- Idle stops, handbraking, simultaneous pedals, moving reverse, countdown,
  free flight, completed races and temporary hit/squash effects do not accrue
  the stuck interval. Pause/resume clears it.
- The return prefers a previously visited safe road pose on the current lap.
  It rechecks the full kart footprint, road support, live obstacles and a short
  forward exit. Authored road positions behind the kart are a fallback, with
  no crossing of the lap start and a search bounded below half a circuit.
  Italy17/18 require searching farther than the earlier twelve-sector window.
- If reversing behind the lap start leaves known safe poses ahead, a recorded
  same-lap pose can be used without granting progress or arming a finish.
  No forward authored fallback is invented.
- If no safe return is currently available, the kart remains visible and
  controllable; availability is retried after another second of attempted
  driving. Traffic is checked again during relocation and at full size.
- The original40-tick shrink/grow animation, rings and character-specific
  `DISAPP`/`REAPP` sounds run through the existing rescue system. Wheel state,
  controls and residual velocities are reset at return.
- Relocation does not grant laps, checkpoint time or bonuses. Already earned
  gate/lap results and running clocks are retained. Overlapping pickups remain
  excluded after the animation until the kart leaves their contact area.

## Validation and delivery scope

All63 focused tests pass, covering real England tyre contact in all four race
modes, destination clearance,
reversing, pauses, unsafe returns, pickup exclusions and existing native rescue
rules. `evidence/player-recovery/england-tyre.json` retains the composed traces;
`browser/report.json` records a source-browser run with real WebGL visuals and
WebAudio starts (four browser check groups pass). `initial-road-candidates.json` audits candidate road support
on all six tracks under initial occupancy; it is not a full-race or arbitrary
traffic guarantee. `validation.json` records the final focused check counts.

The running AppImage exposed no debugging connection, so its exact kart state
was not read. Its process and race were left untouched. Per the user's later
instruction, that initial delivery changed source only: no full test-suite rerun,
browser build, AppImage or other desktop package was produced. Existing
`dist/` and `release/` files then retained the earlier source checkpoint.
The fix was subsequently included in the [0.9.0 packages](releases/v0.9.0.md).
To run current checkout changes, use `npm start` or `npm run desktop`; both
refresh and execute the local runtime bundles described in the
[folder guide](runtime-layout.md).
