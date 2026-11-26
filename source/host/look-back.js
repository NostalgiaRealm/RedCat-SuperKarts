// The look back (key 3 held), with A2 Racer 4's framing: a port departure Rick asked for (2026-11-26;
// docs/intentional-differences.md).
//
// The original (confirmed in the export). 0x41d920 polls key 3 at 0x41d969: held, it keeps the camera mode in 0x4e2ac8
// and selects mode 5 through 0x41e280; let go, it selects the kept mode again. 0x41e280 case 5 (0x41e9dd, the tail at
// 0x41ea3b) sets the camera (the object at *(0x680ba0) + 0x178 * *(0x508620)) through two setters:
//   0x498ad0 (thiscall, three floats, RET 0xc): the camera's place relative to the kart, at +0xbc: (0, 23, 40);
//   0x498b50 (thiscall, the kart's object and three floats, RET 0x10): what it looks at, the object at +0xc8 and the
//            point relative to it at +0xcc: (0, 50, 0), and +0x78 = 1.
// So the camera stands 40 units ahead of the kart and 23 up and looks at a point 50 above the kart: from close in
// front, upward past the kart, it shows the kart's front and sky, and little of the track or the karts behind.
//
// A2 Racer 4, the same Davilex engine (its spel.dat, FUN_004390d0): the look back is view 4, place (0, 20, 75) and aim
// (0, 10, 0), with the chase view (view 0) at (0, 30, -80) aiming at (0, 10, 0): the chase camera turned round, 94%
// of its distance and two thirds of its height, aiming where the chase camera aims. SuperKarts' chase camera (mode 0:
// 0x498a50 with (0, 50, -150), aim (0, 25, 0)) in those proportions gives the look back here: place (0, 33, 140), aim
// (0, 25, 0) (inferred: the proportions, not A2's units, which are not the karts').
//
// The wrap runs the original mode setter as it is and then sets mode 5's place and aim; any other mode, and the one
// key 3's release brings back, is untouched.
export const LOOK_BACK = Object.freeze({ MODE: 5, PLACE: [0, 33, 140], AIM: [0, 25, 0] });
const ADDR = { CAMERAS: 0x00680ba0, ACTIVE: 0x00508620, CAMERA_SIZE: 0x178, PLACE: 0xbc, AIM: 0xcc };

/** Installs the wrap of 0x41e280 ('CameraMode'); host.lookBackOriginal: keep the original's mode 5. */
export function installLookBack(m, host) {
  const hook = m.meta.hooks && m.meta.hooks.CameraMode;
  if (!hook || hook.kind !== 'wrap') { if (host.log) host.log('look back: no CameraMode wrap hook in this build, the original look back stays'); return null; }
  const stats = { set: 0 };
  m.wrap('CameraMode', (esp, ecx, edx, eax, next) => {
    const mode = m.i32[(esp + 4) >> 2];
    const r = next(esp, ecx, edx, eax);
    if (mode === LOOK_BACK.MODE && !host.lookBackOriginal) {
      const cam = m.u32[ADDR.CAMERAS >> 2] + ADDR.CAMERA_SIZE * m.i32[ADDR.ACTIVE >> 2];
      LOOK_BACK.PLACE.forEach((x, k) => m.view.setFloat32(cam + ADDR.PLACE + 4 * k, x, true));
      LOOK_BACK.AIM.forEach((x, k) => m.view.setFloat32(cam + ADDR.AIM + 4 * k, x, true));
      stats.set++;
    }
    return r;
  });
  return stats;
}
