const LINEAR_VELOCITIES = ['lateralSpeed', 'verticalSpeed', 'forwardSpeed'];

export function captureNPCLinearVelocity(body) {
  return Object.fromEntries(LINEAR_VELOCITIES.map(component => [component, body[component]]));
}

/**
 * Explicit port safety exception, outside the original native routines.
 *
 * Native406100 can amplify the otherwise grounded vertical velocity until its
 * float32 store overflows. Native401200/416650 do not clear that field. Preserve
 * every finite result, and reset only a newly invalid linear component before
 * integration propagates it into the world transform. A pre-existing invalid
 * input is deliberately not hidden by this guard.
 */
export function resetNewlyNonfiniteNPCVelocity(body, before) {
  const corrections = [];
  for (const component of LINEAR_VELOCITIES) {
    if (!Number.isFinite(before[component]) || Number.isFinite(body[component])) continue;
    corrections.push({
      component, previous: before[component], rejected: String(body[component]), replacement: 0,
    });
    body[component] = 0;
  }
  return corrections;
}
