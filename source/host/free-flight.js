// Free flight (Vrij vliegen, settings.freeFlight): the JS reconstruction's no-clip flight of the player's kart, around
// the original race code. As there (../RedCat Superkarts at 5bfe0b62: source/simulation/free-flight.js,
// race-simulation.js:260-275, :599-637, driving-view.js) the visible kart flies and the chase camera (mode 1) follows
// it; the race and the HUD stand still (no object pass, AI, timers, bonus or laps; the kart keeps its colour), sound
// effects are held and the music goes on; every chunk of the track is drawn; and stopping returns the kart to where
// it took off, at a standstill, with the chase camera started again behind it.
//
// How, with no game code changed (docs/host.md, Free flight): race.js tick() asks step() before every pass. While it
// flies the host does not call HANDLE_GAME 0x42f4c0 but a pass of its own made of the original's pieces: the kart's
// render object is placed (matrix +0x10, position +0x50), its chunk updated (0x4932e0), then the cameras 0x41d920, the
// render 0x430020 (track, objects, effects and the HUD pass; every kart's wheels and driver put back on its body by
// source/host/render-replay.js, as no object pass runs), Esc and P as 0x42f9c0 reads them, the present 0x430470 and,
// when one of them asked for it, the pause 0x42f350 (HANDLE_GAME's pause tail, tools/recomp/build.py GAME_PATCHES).
// The game's clock stands still (VirtualClock.freeze, the JS flightClockOffsetMs) and the game sees no
// key but Esc, P and Shift (0x4b3830's Shift rule) in these passes. Landing puts back every byte the take-off saved
// but the camera's eye, which it resets as the JS port does.
//
// Addresses (rcskspel.dat, from the export's functions/ and runtime probes; tools/checks/flight.mjs holds them):
//   player index i32 0x53be28; racer table u32 0x67ee20, stride 0xd0 (+0x0c render object, +0x1c/+0x20 chunk now and
//   before, +0x28 shadow slot (-1: no shadow; 0x4918f0/0x4916f0 test it), +0x34 lit colour (0x4903c0 eases it towards
//   the light under the kart at dt * (|+0xa4| * 0.1 + 1) per draw), +0x3c drawn (0x4918f0; 0x41e280 sets it), +0x64..
//   part objects and +0x8c their count (0x490d40), +0x9c/+0xa0/+0xa4 lateral, vertical and forward speed, +0xac yaw
//   rate; +0xa8 and +0xb0 grow without bound while driving: angles, not speeds); render objects u32 0x6a5c38, stride
//   0xa9 (+0x10 4x4: rows right, up, forward, translation; +0x50 position); minimap dot f32 0x53be44..4c (0x466830
//   reads it); visible chunks i32 0x53b9d0 (game.ini VISIBLECHUNKS, 0x42bba0), chunk count i32 0x680b2c; cameras u32
//   0x680ba0, stride 0x178 (+0x08 eye, +0xa0 damped eye: 0x498c00 eases +0x08 from it and copies it back), slot ->
//   camera i32 0x508620[10], each slot's last chunk i32 0x508648[10], slot i32 0x508670, chunk window 0x508674
//   (0x41d920 finds the camera's chunk from 0x508648[slot] and the eye, then calls 0x498c00 with ecx = the camera);
//   camera mode i32 0x4e3064 (0x41e280), its racer i32 0x4e3068; 0x4e2ac8 (0x41d920 writes it); phase u32 0x53b9c0;
//   pause kind u32 0x53b9f8 (0x42f9c0); frame clock 0x67ec70 (+0xc dt, 0x48f3e0; 0x48f4e0 hands it out, 0 and more
//   than 0.1 as 0.1); mirror i32 0x53a734 + track i32 0x53b9b4 * 0x94; lap armed u32 0x53d1d8 (0x440e40/0x440dd0);
//   driving input f32 0x53bd70 steer, f32 0x53bd74 throttle, i32 0x53be04 brake, i32 0x53bdf4 handbrake; engine f32
//   0x507290 rpm, i32 0x507298 gear (0 and 0 before the start; the next pass idles at 800).

export const FLIGHT = Object.freeze({ SPEED: 650, VERTICAL_SPEED: 400, TURN_SPEED: 1.5 });   // free-flight.js:7-9
const FN = {
  CHUNK: 0x004932e0,      // (racer): +0x20 = +0x1c, +0x1c = 0x4977d0(+0x20, position), cdecl
  CAMERA_MODE: 0x0041e280, // (mode), cdecl; 1 is the JS port's chase mode (native-camera.js:32-38)
  CAMERAS: 0x0041d920,
  CAMERA_STEP: 0x00498c00, // one camera's update (fastcall, ecx = the camera), as 0x41d920 calls it at 0x41dd3d
  RENDER: 0x00430020,
  KEY_DOWN: 0x004b3830,   // GetAsyncKeyState with the Shift rule, cdecl
  PAUSE_TEXT: 0x00430610, // (1): the "pauze" notice, as 0x42f9c0 calls it for P
  PRESENT: 0x00430470,
  PAUSE: 0x0042f350,
};
const A = {
  PLAYER: 0x0053be28, RACERS: 0x0067ee20, OBJECTS: 0x006a5c38, DOT: 0x0053be44, VCHUNKS: 0x0053b9d0, CHUNKS: 0x00680b2c,
  CAMS: 0x00680ba0, SLOTS: 0x00508620, SLOTS_END: 0x00508678, SLOT: 0x00508670, SLOT_CHUNKS: 0x00508648,
  CAM_CHUNK: 0x00508674, MODE: 0x004e3064, SUBJECT: 0x004e3068,
  CAMKEY: 0x004e2ac8, PHASE: 0x0053b9c0, PAUSE_KIND: 0x0053b9f8, DT: 0x0067ec7c, MIRROR: 0x0053a734, TRACK: 0x0053b9b4,
  LAP_ARMED: 0x0053d1d8, STEER: 0x0053bd70, THROTTLE: 0x0053bd74, BRAKE: 0x0053be04, HANDBRAKE: 0x0053bdf4,
  RPM: 0x00507290, GEAR: 0x00507298,
};
const CAMERA_COUNT = 10, CAMERA_SIZE = 0x178;
const VK_SHIFT = 0x10, VK_ESC = 0x1b, VK_SPACE = 0x20, VK_C = 0x43, VK_P = 0x50;
const TWO_PI = Math.fround(2 * Math.PI);
const SPEEDS = [0x9c, 0xa0, 0xa4, 0xac];   // racer lateral, vertical, forward speed and yaw rate
// The HUD's frame time while flying: the smallest that 0x48f4e0 passes on (it reads 0 as 0.1 s), so what the HUD adds
// up per frame (the start lights 0x464a70, the notices 0x46c910, 0x465570, 0x467000) stands still
const HUD_STILL_DT = Math.fround(1e-30);
const axis = (v) => (Number.isFinite(v) ? Math.max(-1, Math.min(1, v)) : 0);   // free-flight.js:11

/**
 * NativePlayerCamera.reset (native-camera.js:65-70, 53-bit as NATIVE_PRECISION): the eye at (0, 20, -150) in the
 * body's frame, up and forward its matrix rows (row vectors: the right row's 0 adds nothing), the sum rounded to a
 * float and then added to the position.
 */
export function chaseEye(pos, up, fwd) {
  return [0, 1, 2].map((k) => Math.fround(Math.fround(20 * up[k] + -150 * fwd[k]) + pos[k]));
}

/** The native 4096-step sine and cosine (native-integrator.js:8-11): float values of a double product. */
function trig(yaw) {
  const i = Math.trunc(Math.fround(yaw * 4096 / (2 * Math.PI))) & 4095;   // nativeRotationMatrix53's index
  return { s: Math.fround(Math.sin(i / 4096 * TWO_PI)), c: Math.fround(Math.cos(i / 4096 * TWO_PI)) };
}

export class FreeFlight {
  /**
   * race: the Race (race.js). Its host may give flightWanted() (the page's setting, CTRL.FLIGHT) and flightInput()
   * ({ steer -1..1 right +, throttle 0..1, brake 0..1, lift -1..1 up + }); without them nothing ever flies.
   */
  constructor(race) {
    this.race = race;
    this.m = race.m;
    this.host = race.host;
    this.active = false;
    this.paused = false;        // inside the game's pause (0x42f350) during a flight pass: every key is seen
    this.saved = null;
    this.parts = [];
    this.hidden = new Set();    // Space and C after landing, until let go (lift keys; Space is the horn, 0x42f9c0)
    this.flights = 0;
    this.passes = 0;
    this.hudStill = false;      // in a flight pass's render: the HUD pass sees HUD_STILL_DT
    this.x = this.y = this.z = this.yaw = 0;
    // The key mask, around whatever GetAsyncKeyState is bound to (win32.js, or a wrapper of it): the import still
    // runs (its clock polls and naps), only the answer is hidden.
    const m = this.m;
    const id = m.thunkId('USER32.DLL!GetAsyncKeyState');
    const inner = m.thunks[id];
    m.thunks[id] = (esp, ecx, edx, eax) => {
      const r = inner(esp, ecx, edx, eax);
      if (!this.active && !this.hidden.size) return r;
      return this.gameSees(m.u32[(esp + 4) >> 2] & 0xFF, r) ? r : 0;
    };
    // The HUD stands still while the kart flies, as the JS reconstruction's: it skips hud.update and captures the HUD
    // meshes with dt 0 (driving-view.js:231-234), so its start lights, notices and slides stay as they were at take-off
    // (there the lights stay as the frame before green drew them, red; here as at the first racing pass, green). The
    // HUD pass 0x467d30 (behind its exception guard, as race.js wraps it too) sees a frame time that adds nothing; its
    // times read the frozen clock and the minimap's dot (0x53be44) follows the kart as there (playerHudPosition).
    const hudId = m.thunkId('hook!eh_00467d30');
    const hudPass = m.thunks[hudId];
    m.thunks[hudId] = (esp, ecx, edx, eax) => {
      if (!this.hudStill) return hudPass(esp, ecx, edx, eax);
      const dt = m.f32[A.DT >> 2];
      m.f32[A.DT >> 2] = HUD_STILL_DT;
      try { return hudPass(esp, ecx, edx, eax); } finally { m.f32[A.DT >> 2] = dt; }
    };
  }

  /** Does the game see virtual key vk (raw: GetAsyncKeyState's answer without the mask)? */
  gameSees(vk, raw) {
    // in a flight pass only what 0x42f9c0's Esc and P read (0x4b3830 also reads Shift); in its pause everything
    if (this.active && !this.paused) return vk === VK_ESC || vk === VK_P || vk === VK_SHIFT;
    if (this.hidden.has(vk)) {
      if (raw & 0x8000) return false;
      this.hidden.delete(vk);
    }
    return true;
  }

  wanted() { return !!(this.host.flightWanted && this.host.flightWanted()); }

  /**
   * Before every pass (race.js tick, after the clock moved): take off, land, and fly. True when this pass was a
   * flight pass (the host then does not call HANDLE_GAME).
   */
  step(dt) {
    const m = this.m;
    if (this.hidden.size && this.host.input) for (const vk of [...this.hidden]) if (!this.host.input.keyDown(vk)) this.hidden.delete(vk);
    const want = this.wanted();
    // race-simulation.js:260: the first step with the setting on, the kart able to move and the race in phase 0 (green
    // came in the pass before: the countdown is phase 1)
    if (!this.active && want && m.u32[A.PHASE >> 2] === 0 && m.u32[A.RACERS >> 2] && m.u32[A.OBJECTS >> 2]) this.takeOff();
    else if (this.active && !want) this.land();
    if (!this.active) return false;
    this.pass(dt);
    return true;
  }

  /** The player's racer record and render object. */
  where() {
    const m = this.m;
    const me = m.i32[A.PLAYER >> 2];
    const rec = m.u32[A.RACERS >> 2] + me * 0xd0;
    const R = m.u32[A.OBJECTS >> 2] + m.view.getInt32(rec + 0xc, true) * 0xa9;
    return { me, rec, R };
  }

  /** The active camera (slot 0x508670), or the one in slot k (0: the player's, which 0x41e280 sets up). */
  camera(k = this.m.i32[A.SLOT >> 2]) {
    const m = this.m;
    return m.u32[A.CAMS >> 2] + m.i32[(A.SLOTS + k * 4) >> 2] * CAMERA_SIZE;
  }

  /** playerCamera.reset(body): the player's camera's eye and damped eye (0x498c00 eases from +0xa0) at chaseEye. */
  resetCamera(pos, up, fwd) {
    const v = this.m.view, cam = this.camera(0);
    chaseEye(pos, up, fwd).forEach((e, k) => { v.setFloat32(cam + 8 + 4 * k, e, true); v.setFloat32(cam + 0xa0 + 4 * k, e, true); });
  }

  /**
   * beginFreeFlight (race-simulation.js:599-621). The return anchor is the take-off itself: flight starts only at the
   * first racing pass (or, from the development page, wherever the kart is) and nothing moves while it flies, so the
   * JS port's chain (take-off, last road pose, grid, a rescue point behind) and its road and clear tests come down to
   * it (there too the take-off pose is the one chosen at the first racing pass: six tracks, four characters, measured
   * 2026-11-25). Everything the flight changes is saved here and put back by land().
   */
  takeOff() {
    const m = this.m, v = m.view;
    const { me, rec, R } = this.where();
    const subject = m.u32[A.RACERS >> 2] + m.i32[A.SUBJECT >> 2] * 0xd0;
    const cams = m.u32[A.CAMS >> 2];
    this.saved = {
      me, at: { rec, R, cams, subject },
      rec: m.u8.slice(rec, rec + 0xd0), obj: m.u8.slice(R, R + 0xa9), dot: m.u8.slice(A.DOT, A.DOT + 12),
      cameras: m.u8.slice(cams, cams + CAMERA_COUNT * CAMERA_SIZE), slots: m.u8.slice(A.SLOTS, A.SLOTS_END),
      vchunks: m.i32[A.VCHUNKS >> 2], mode: m.i32[A.MODE >> 2], camKey: m.i32[A.CAMKEY >> 2], follow: v.getInt32(subject + 0x3c, true),
      origin: v.getInt32(rec + 0x1c, true),
    };
    // Every kart's parts, the wheels and the driver (slot +0x8c of them, render objects listed from +0x64; 348..352 for
    // RedCat on Nederland). The object pass 0x491530 leaves each one's matrix relative to the body and the draw 0x490d40
    // multiplies it by the body's in place, so between passes it holds the world matrix; in flight there is no object
    // pass. source/host/render-replay.js puts back, before every flight render (and the flight pause's), the matrices
    // the last render found for every kart whose parts hold what it left: the game's own draw then puts them on the
    // body, the flying one included, and every kart is drawn whole as in the JS reconstruction (driving-view.js:242-254).
    // The flights' draws leave the opponents' parts as they were (their bodies stand still); the bytes go back on
    // landing all the same, the flying kart's as at take-off.
    this.parts = [];
    for (const k of this.race.renderReplay ? this.race.renderReplay.karts() : []) {
      for (const p of k.parts) this.parts.push({ P: p - 0x10, bytes: m.u8.slice(p - 0x10, p - 0x10 + 0xa9) });
    }
    this.x = v.getFloat32(R + 0x50, true); this.y = v.getFloat32(R + 0x54, true); this.z = v.getFloat32(R + 0x58, true);
    // the forward row is (-sin, 0, cos) of the yaw (nativeRotationMatrix's Y rotation; its pitch and roll (Z, X before
    // Y) scale both by cos(pitch), so this is the heading)
    this.yaw = Math.atan2(-v.getFloat32(R + 0x30, true), v.getFloat32(R + 0x38, true));
    this.saved.yaw = this.yaw;
    this.saved.colour = v.getUint32(rec + 0x34, true);
    this.mirrored = m.i32[(A.MIRROR + m.i32[A.TRACK >> 2] * 0x94) >> 2] === 1;
    // playerCamera.setMode(1).reset(this.motion.body) (race-simulation.js:619): the chase camera, its eye behind the
    // kart in the driving body's own frame, pitch and roll included (the flight levels it from the next pass on)
    m.call(FN.CAMERA_MODE, [1]);
    const row = (o) => [0, 4, 8].map((k) => v.getFloat32(R + o + k, true));
    this.resetCamera([this.x, this.y, this.z], row(0x20), row(0x30));
    // advanceFreeFlight zeroes the body's speeds at every flight step (free-flight.js:47); here once, for what reads
    // them in a flight pass: the lit colour's pace (0x4903c0). Landing puts the record back.
    for (const o of SPEEDS) v.setFloat32(rec + o, 0, true);
    v.setInt32(rec + 0x28, -1, true);                               // no shadow (driving-view.js:228, :250)
    m.i32[A.VCHUNKS >> 2] = m.i32[A.CHUNKS >> 2] - 1;              // every chunk, once (driving-view.js:258-259)
    this.write();
    this.race.clock.freeze();                                      // flightClockOffsetMs (race-simulation.js:263-264)
    if (this.host.dsound && this.host.dsound.hold) this.host.dsound.hold(true);  // driving-view.js:336-345
    this.active = true;
    this.host.flightActive = true;                                 // shadows.js leaves the player's shadow out too
    this.flights++;
    this.host.log(`free flight: take-off at ${[this.x, this.y, this.z].map((q) => q.toFixed(1)).join(',')} chunk ${this.saved.origin}`);
  }

  /** advanceFreeFlight (free-flight.js:37-52): the requested arc, integrated exactly. */
  advance(input, dt) {
    const from = this.yaw;
    const turn = -axis(input.steer) * FLIGHT.TURN_SPEED * (this.mirrored ? -1 : 1);
    const speed = (axis(input.throttle) - axis(input.brake)) * FLIGHT.SPEED, to = from + turn * dt;
    this.x += Math.abs(turn) > 1e-12 ? speed * (Math.cos(to) - Math.cos(from)) / turn : -Math.sin(from) * speed * dt;
    this.z += Math.abs(turn) > 1e-12 ? speed * (Math.sin(to) - Math.sin(from)) / turn : Math.cos(from) * speed * dt;
    this.y += axis(input.lift) * FLIGHT.VERTICAL_SPEED * dt;
    this.yaw = to;
  }

  /** The kart's render object at the flight pose, level, yaw only; the minimap's dot follows (0x466830). */
  write() {
    const v = this.m.view;
    const { R } = this.saved.at;
    const { s, c } = trig(this.yaw);
    const M = [c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, this.x, this.y, this.z, 1];
    for (let k = 0; k < 16; k++) v.setFloat32(R + 0x10 + 4 * k, M[k], true);
    [this.x, this.y, this.z].forEach((q, k) => { v.setFloat32(R + 0x50 + 4 * k, q, true); v.setFloat32(A.DOT + 4 * k, q, true); });
  }

  /** One flight pass (race-simulation.js:262-275 with driving-view.js's drawing). */
  pass(dt) {
    const m = this.m;
    const input = (this.host.flightInput && this.host.flightInput()) || {};
    this.advance(input, dt);
    this.write();
    // The kart keeps the colour it had at take-off, as the JS reconstruction leaves the flying kart's captureColor out
    // (driving-view.js:262-267). The draw (0x4903c0) eases it from this towards the light under the flying kart by
    // dt * 1 (the speeds are 0) per pass, 2.5% at 40 passes a second; put back every pass it does not add up (without
    // it the kart dimmed from ff to cb in 100 passes on Nederland).
    m.view.setUint32(this.saved.at.rec + 0x34, this.saved.colour, true);
    m.call(FN.CHUNK, [this.saved.me]);
    m.call(FN.CAMERAS);
    this.hudStill = true;
    try { m.call(FN.RENDER); } finally { this.hudStill = false; }
    // 0x42f9c0's last two checks, in its order: Esc asks for the quit requester outside phases 6, 3 and 1, P pauses
    // outside 6 and 3 (functions/0042f9c0 lines 240-248). Space (the horn) and the rest are not read in flight.
    const phase = m.u32[A.PHASE >> 2];
    if (m.call(FN.KEY_DOWN, [VK_ESC]) && phase !== 6 && phase !== 3 && phase !== 1) m.u32[A.PAUSE_KIND >> 2] = 2;
    if (m.call(FN.KEY_DOWN, [VK_P]) && phase !== 6 && phase !== 3) { m.call(FN.PAUSE_TEXT, [1]); m.u32[A.PAUSE_KIND >> 2] = 1; }
    m.call(FN.PRESENT);
    if (m.u32[A.PAUSE_KIND >> 2]) {
      // HANDLE_GAME's pause tail (0x42f6cf..0x42f71c with the pause-entry patch, which keeps its second render and
      // present 0x42f703/0x42f708): that render is the one that draws the "pauze" notice PAUSE_TEXT(1) just set (the
      // JS port's hud.notify(1, 0, { capture: true }), driving-view.js:395, also in flight). The HUD stays still in it
      // too: the notice took its first frame when PAUSE_TEXT made it (0x46c180 calls 0x46c910) and, made by 0x469000
      // with 0 and 0, has no time limit and no effect (inferred: 0x46c910 tests +0x64 <= 0.1 and switches on +0x6c,
      // case 0 does nothing; evidence/frames/flight/flight-pause.png shows it), and the rest of the HUD does not move
      // on a frame per pause. As the pause entry's render it runs as a pause render (render-replay.js again()): every
      // kart's parts, the karts' colours, the skid marks, smoke and jet streams as the flight render above found them,
      // so the pause shows that picture with the notice.
      this.hudStill = true;
      const replay = this.race.renderReplay;
      try { if (replay) replay.again(() => m.call(FN.RENDER)); else m.call(FN.RENDER); } finally { this.hudStill = false; }
      m.call(FN.PRESENT);
      // then the game's own pause with every key and the clock running. Its requester waits 100 ms on GetTickCount
      // (0x473fb0) and would hang on a frozen clock; the timers it stops (0x42a2f0/0x42a420: 0, 3, 8..0x1b) take the
      // pause out themselves. The JS port freezes flight time over a pause instead (race-simulation.js:648-670); the
      // race's timers end the same, and the ones the pause leaves running (1 and 7, started 8 s before green by
      // 0x4405e0/0x440960) are read only until 1 passes 2 s (0x4089b0; the export has no constant-index read of 7),
      // so nothing a player sees moves.
      this.paused = true;
      // In the browser a reading catches the clock up with real time once the pass has taken 40 ms (VirtualClock
      // query): taken here, before the thaw, that catch-up (this pass's two whole-track renders) stays out of the
      // game's time instead of landing between the frozen time and the timers' pause stamps (it moved the lap time
      // 00:00:02 to 00:00:03 over a flight pause on the menu page)
      this.race.clock.query();
      this.race.clock.thaw();
      try { m.call(FN.PAUSE); } finally {
        m.u32[A.PAUSE_KIND >> 2] = 0;
        this.paused = false;
        this.race.clock.freeze();
      }
      // 0x48f520 left the frame time at 0, which 0x48f4e0 reads as 0.1 s: the HUD would run four times as fast
      this.m.f32[A.DT >> 2] = dt;
    }
    this.passes++;
  }

  /**
   * setFreeFlight(false) (race-simulation.js:622-637, restoreFlightPose free-flight.js:54-68): every byte the
   * take-off saved goes back (the kart's record and render object, its chunk, shadow, the cameras, their slots and
   * mode, the visible chunks, the minimap dot), so the kart stands where it took off with its wheels and suspension as
   * they were. neutralize (the JS port's): no speed, yaw rate, driving input, rpm or gear left. Without it (the race
   * ends while flying) only the restore.
   */
  land({ neutralize = true } = {}) {
    if (!this.active) return;
    const m = this.m, v = m.view, S = this.saved;
    const { rec, R, cams, subject } = S.at;
    m.u8.set(S.rec, rec);
    m.u8.set(S.obj, R);
    for (const p of this.parts) m.u8.set(p.bytes, p.P);
    m.u8.set(S.dot, A.DOT);
    m.u8.set(S.cameras, cams);
    m.u8.set(S.slots, A.SLOTS);
    m.i32[A.VCHUNKS >> 2] = S.vchunks;
    m.i32[A.MODE >> 2] = S.mode;
    m.i32[A.CAMKEY >> 2] = S.camKey;
    v.setInt32(subject + 0x3c, S.follow, true);
    // The chase camera starts again behind the kart, as the JS reconstruction lands (race-simulation.js:630-633):
    // playerCamera.setMode(flightCameraMode) is the camera bytes put back above (the mode's offsets +0xbc.., damping
    // +0x6c/+0x88.. as 0x41e280 set them before the flight); .reset(body) its eye at chaseEye of the landed body, which
    // restoreFlightPose levels (pitch 0, roll 0: free-flight.js:57-59, the take-off yaw); camera.step(body) one update
    // of the active camera, 0x498c00 as 0x41d920 calls it; cameraSectors.set(camera, body.sector) the slot's last
    // chunk, from which 0x41d920 finds the camera's chunk in the next pass. With the next pass's own update the first
    // picture after landing has had two, as there (the step here, the next frame's in race-simulation.js:465). The
    // step reads the kart's matrix (0x498c00: +0xb8 and +200 are its render object): for it the kart is level, as the
    // JS body is until its next physics step (without it the eye came 0.7 units off on Nederland's grid).
    {
      const { s, c } = trig(S.yaw);
      const pos = [0x50, 0x54, 0x58].map((o) => v.getFloat32(R + o, true));
      this.resetCamera(pos, [0, 1, 0], [-s, 0, c]);
      const slot = m.i32[A.SLOT >> 2];
      m.i32[(A.SLOT_CHUNKS + slot * 4) >> 2] = m.i32[A.CAM_CHUNK >> 2] = v.getInt32(rec + 0x1c, true);
      const rows = m.u8.slice(R + 0x10, R + 0x40);
      [c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0].forEach((q, k) => v.setFloat32(R + 0x10 + 4 * k, q, true));
      try { m.call(FN.CAMERA_STEP, [], this.camera()); } finally { m.u8.set(rows, R + 0x10); }
    }
    if (neutralize) {
      // lateral, vertical and forward speed and yaw rate (+0xa8 and +0xb0 are angles, kept: evidence/checks/flight.txt)
      for (const o of SPEEDS) v.setFloat32(rec + o, 0, true);
      m.f32[A.STEER >> 2] = 0; m.f32[A.THROTTLE >> 2] = 0; m.i32[A.BRAKE >> 2] = 0; m.i32[A.HANDBRAKE >> 2] = 0;
      m.f32[A.RPM >> 2] = 0; m.i32[A.GEAR >> 2] = 0;     // the engine as before the start (rpm 0, gear 0)
    }
    // race.finishArmed=false when the sector changed (race-simulation.js:629): never after an exact restore
    if (v.getInt32(rec + 0x1c, true) !== S.origin) m.u32[A.LAP_ARMED >> 2] = 0;
    if (this.host.dsound && this.host.dsound.hold) this.host.dsound.hold(false);
    this.race.clock.thaw();
    this.active = false;
    this.host.flightActive = false;
    // the lift keys stay hidden from the game until let go (input.js:67-68 gave them to flight only)
    if (this.host.input) for (const vk of [VK_SPACE, VK_C]) if (this.host.input.keyDown(vk)) this.hidden.add(vk);
    this.host.log('free flight: landed');
  }

  /**
   * For the page and checks: the flight pose, the kart's drawn place (render object +0x50), where it took off and the
   * camera's eye, and the game's GetTickCount (read without a query).
   */
  state() {
    const m = this.m, c = this.race.clock;
    const at = (view, base) => [0x50, 0x54, 0x58].map((o) => +view.getFloat32(base + o, true).toFixed(1));
    const kart = m.u32[A.RACERS >> 2] && m.u32[A.OBJECTS >> 2] ? at(m.view, this.where().R) : null;
    const takeoff = this.saved ? at(new DataView(this.saved.obj.buffer), 0) : null;
    // the active camera's eye (+0x08), less 0x50 so at() reads it
    const eye = m.u32[A.CAMS >> 2] ? at(m.view, this.camera() + 8 - 0x50) : null;
    const gameMs = Math.floor(((c.frozenUs ?? c.us) - c.offsetUs) / 1000);
    // the lap timer (game timer 0, 0x53a274: start, +8 on, +0xc pause stamp; 0x42a4d0 reads it so) as the HUD shows it
    const T0 = 0x0053a274, lapMs = m.u32[(T0 + 8) >> 2] && m.i32[T0 >> 2] !== -1 ? ((m.u32[(T0 + 0xc) >> 2] || gameMs) - m.u32[T0 >> 2]) | 0 : null;
    return { active: this.active, x: +this.x.toFixed(1), y: +this.y.toFixed(1), z: +this.z.toFixed(1), yaw: +this.yaw.toFixed(3), flights: this.flights, passes: this.passes,
      kart, takeoff, eye, gameMs, lapMs };
  }
}
