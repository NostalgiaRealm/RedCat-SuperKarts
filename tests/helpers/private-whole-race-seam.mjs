// Fixed test-only comparison with the retained projected-line seam policy.
export function wholeRaceSeamActive(simulation) {
  const body=simulation.motion.body;
  return simulation.movementActive&&simulation.race.elapsedMs>=25000&&body.forwardSpeed>=10
    &&(body.sector>=129||body.sector<=31);
}

/** Exact original test-driver call plus its previously used mirror adapter. */
export function projectedBaselineInput(driver,simulation,now,dt,options={}) {
  const input=simulation.movementActive?driver.input(simulation.motion.body,now,dt,options):
    {throttle:1,brake:0,steer:0,handbrake:0,bonus:0,analog:{throttle:1,brake:0,steer:0}};
  if(simulation.motion.mirrored){input.steer=-input.steer;input.analog.steer=-input.analog.steer;}
  return input;
}
