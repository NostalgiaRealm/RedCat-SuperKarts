// WINMM's joystick for rcskspel.dat, from the Spookkasteel host (source/host/winmm.js there); timeGetTime is
// in win32.js. 0x4ba5e0 calibrates joysticks 0 and 1 (the first reading is the centre), 0x4baac0 and 0x4bac90
// read them every frame. The game takes return codes 2, 6, 0xA6 and 0xA7 as "absent" and 0xB
// (MMSYSERR_INVALPARAM) as fatal, so a missing stick always gets JOYERR_UNPLUGGED (0xA7).
//   host.joystick(id) -> null | { x, y, z, r, buttons, pov } with axes in 0..65535 (32767 = centre). In the browser,
//   joystick 0 is always there, centred unless the pad or the touch wheel moves it (source/web/worker.js): the game
//   calibrates once at start (0x4ba5e0, its first reading is the centre) and a pad shows only after a button.
export function installWinmm(m, host) {
  const { u8, u16, u32 } = m;
  const W = 'WINMM.DLL!';
  const JOYERR_UNPLUGGED = 167;
  m.api(W + 'joyGetDevCapsA', 3, (id, p, size) => {
    const j = host.joystick ? host.joystick(id) : null;
    if (!j) return JOYERR_UNPLUGGED;
    u8.fill(0, p, p + size);
    u16[p >> 1] = 1; u16[(p + 2) >> 1] = 1;
    m.writeCStr(p + 4, 'Gamepad', 32);
    // wXmin, wXmax, wYmin, wYmax, wZmin, wZmax, wNumButtons, wPeriodMin, wPeriodMax
    const v = [0, 65535, 0, 65535, 0, 65535, 8, 10, 1000];
    for (let k = 0; k < v.length; k++) u32[(p + 36 + k * 4) >> 2] = v[k];
    if (size >= 0x194) {
      const w = [0, 65535, 0, 65535, 0, 65535, 0x3F, 8, 4, 32];    // R, U, V ranges, caps, max axes, axes, max buttons
      for (let k = 0; k < w.length; k++) u32[(p + 72 + k * 4) >> 2] = w[k];
    }
    return 0;
  });
  m.api(W + 'joyGetPosEx', 2, (id, p) => {
    const j = host.joystick ? host.joystick(id) : null;
    if (!j) return JOYERR_UNPLUGGED;
    // JOYINFOEX: dwSize, dwFlags, dwXpos, dwYpos, dwZpos, dwRpos, dwUpos, dwVpos, dwButtons, dwButtonNumber, dwPOV
    u32[(p + 8) >> 2] = j.x; u32[(p + 12) >> 2] = j.y; u32[(p + 16) >> 2] = j.z === undefined ? 32767 : j.z;
    u32[(p + 20) >> 2] = j.r === undefined ? 32767 : j.r; u32[(p + 24) >> 2] = 32767; u32[(p + 28) >> 2] = 32767;
    u32[(p + 32) >> 2] = j.buttons >>> 0;
    let n = 0;
    for (let b = j.buttons >>> 0; b; b &= b - 1) n++;
    u32[(p + 36) >> 2] = n;
    u32[(p + 40) >> 2] = j.pov === undefined ? 0xFFFF : j.pov;
    return 0;
  });
}
