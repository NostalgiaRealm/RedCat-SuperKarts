// Shared set-up for tools/checks/full-race-gaps.mjs: one recompiled rcskspel.dat race in Node, with
//  - a scripted keyboard whose state the scenario sets per tick, and optionally changes *inside* one tick
//    (onPoll), which is what a worker with live input would see and what the page's main thread cannot do;
//  - a spin watchdog on the host thunks that busy-wait loops call (GetAsyncKeyState, GetTickCount,
//    timeGetTime, QueryPerformanceCounter, PeekMessageA, WaitMessage): it counts calls per tick and throws
//    SpinDetected past a limit, with the polled virtual keys, so a loop that would never end is reported
//    instead of hanging the check;
//  - a log of every WritePrivateProfileStringA call (file, section, key, value) with its tick.
// Same host as tools/run-headless.mjs (source/host/*.js); nothing in source/ is changed.
//
// Guest addresses (rcskspel.dat, original-source/modules/rcskspel.dat of the SuperKarts reconstruction):
//   RUNNING u32[0x53b9bc] (WinMain 0x4432a0 loop condition; cleared only by 0x42f740(4))
//   phase   u32[0x53b9c0] (0x42f740: 1 countdown, 0 racing, 3 finished, 4 exit, 6 game over, 8 arrested)
//   pause request u32[0x53b9f8] (0x42f9c0: 1 = P, 2 = Esc; 0x42f4c0 calls 0x42f350 when non-zero)
//   damage i32[0x53be30] (0x4354a0/0x435640, 0..100; 0x42f1f0 ends the race above 0x62)
//   laps i32[0x53ba18], lap limit i32[0x53ba1c] (0x440c30); finished flag i32[0x53be50] (0x41fe50, 0x440d70)
//   track time i32[0x53be58], position i32[0x53be60], fastest lap i32[0x53be5c] (written by 0x42c570)
//   player index i32[0x53be28] (0x4319f0); racer table u32[0x67ee20] stride 0xd0: +0x0c render object, +0x1c sector
//   render objects u32[0x6a5c38] stride 0xa9, matrix at +0x10 (translation at floats 12..14)
//   route: chunk -> waypoint i32[u32[0x68021c] + chunk*4] (0x493430/0x493540), max chunk i32[0x680b2c],
//          waypoint record u32[0x680b28] + wp*0x984: +0x24 x,y,z (0x41fc60), +0x48/+0x50 direction (0x493540)
import { readFileSync, readdirSync, statSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';
import { Vfs } from '../../source/host/vfs.js';
import { Race } from '../../source/host/race.js';
import { pinRace } from '../../source/host/race-setup.js';

export const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
export const DEFAULT_DATA = join(ROOT, '..', 'RedCat Superkarts', 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c',
  'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');

export const VK = {
  LBUTTON: 0x01, BACK: 0x08, RETURN: 0x0d, SHIFT: 0x10, CONTROL: 0x11, ESCAPE: 0x1b, SPACE: 0x20,
  LEFT: 0x25, UP: 0x26, RIGHT: 0x27, DOWN: 0x28, D: 0x44, F: 0x46, I: 0x49, J: 0x4a, N: 0x4e, P: 0x50, Y: 0x59,
};
export const vkName = (vk) => {
  for (const [k, v] of Object.entries(VK)) if (v === vk) return k;
  if (vk >= 0x30 && vk <= 0x5a) return String.fromCharCode(vk);
  return '0x' + vk.toString(16);
};

export class SpinDetected extends Error {
  constructor(info) {
    super('spin inside one tick: ' + info.reason);
    this.info = info;
  }
}

const nop = () => {};

/**
 * opts: { dataDir, gameDir, etappe, car, limit (calls of one kind per tick before SpinDetected), ini: [[file, sec, key, val]] }
 */
export async function makeRace(opts = {}) {
  const dataDir = opts.dataDir || process.env.SUPERKARTS_DATA || DEFAULT_DATA;
  const gameDir = opts.gameDir || join(ROOT, 'public/game');
  const meta = JSON.parse(readFileSync(join(gameDir, 'rcskspel.meta.json'), 'utf8'));
  const codeMap = new Uint8Array(readFileSync(join(gameDir, 'rcskspel.codemap.bin')));
  const vfs = new Vfs();
  for (const name of readdirSync(dataDir)) {
    const p = join(dataDir, name);
    if (statSync(p).isFile()) vfs.addLazy(name, statSync(p).size, () => new Uint8Array(readFileSync(p)));
  }
  pinRace(vfs, { etappe: opts.etappe ?? 0, car: opts.car ?? 0 });
  for (const [f, s, k, v] of opts.ini || []) vfs.iniSet(f, s, k, String(v));

  const stats = { flips: 0, blits: 0, draws: 0, sounds: 0 };
  const render = {
    freeTexture: nop, fillScreen: nop, blitToScreen() { stats.blits++; }, loadTexture: nop, setBackground: nop,
    clear: nop, setViewport: nop, beginScene: nop, endScene: nop, setRenderState: nop, setLightState: nop,
    setTransform: nop, drawPrimitive() { stats.draws++; }, drawIndexed() { stats.draws++; },
  };
  const ctl = {
    keys: new Set(),
    onPoll: null,          // (vk, ctx) => void: may change ctl.keys inside a tick ("live input")
    tick: 0,
  };
  const input = {
    mouseX: 320, mouseY: 240, mouseButtons: 0,
    keyDown: (vk) => {
      if (ctl.onPoll) ctl.onPoll(vk, ctl);
      return ctl.keys.has(vk);
    },
    takeMouseDelta: () => null,
    setMouse(x, y) { this.mouseX = x; this.mouseY = y; },
  };
  const messages = [];
  const host = {
    vfs, render, input, audio: null, music: null, screen: { width: 640, height: 480, bits: 16 }, tickSeconds: 0.025,
    clockStart: 1, fixedDate: Date.UTC(2000, 3, 17, 12),
    onFlip() { stats.flips++; },
    onMessageBox: (c, t) => messages.push({ tick: ctl.tick, caption: c, text: t }),
    onStdout: nop,
    log: (s) => messages.push({ tick: ctl.tick, log: s }),
    // the stuck recovery's input (source/host/stuck.js): the default keys as the scenario holds them, read without
    // onPoll (the game's polls stay the scenario's); host.cheats is left undefined: the race's own keys answer
    driveInput: () => ({ throttle: ctl.keys.has(VK.UP) ? 1 : 0, brake: ctl.keys.has(VK.DOWN) ? 1 : 0, handbrake: ctl.keys.has(0x12) }),
  };
  const race = new Race(meta, host);
  await race.instantiate(new WebAssembly.Module(readFileSync(join(gameDir, 'rcskspel.wasm'))), codeMap);
  const m = race.m;

  // --- watchdog and INI log on the host thunks -------------------------------------------------------
  const limit = opts.limit ?? 400000;
  const per = { keys: 0, vk: new Map(), clock: 0, peek: 0, wait: 0, maxRun: 0 };
  const resetPer = () => {
    per.keys = 0; per.vk.clear(); per.clock = 0; per.peek = 0; per.wait = 0;
  };
  const snapshot = (reason) => ({
    reason, tick: ctl.tick, phase: m.u32[0x53b9c0 >> 2], running: m.u32[0x53b9bc >> 2],
    pauseKind: m.u32[0x53b9f8 >> 2], keyPolls: per.keys, clockQueries: per.clock, peeks: per.peek, waits: per.wait,
    clockQueriesThisTick: race.clock.queries,
    virtualMsIntoTick: null,
    topPolledVKs: [...per.vk.entries()].sort((a, b) => b[1] - a[1]).slice(0, 8).map(([k, n]) => `${vkName(k)}:${n}`),
    heldKeys: [...ctl.keys].map(vkName),
  });
  const wrap = (name, fn) => {
    let id;
    try { id = m.thunkId(name); } catch { return; }
    const orig = m.thunks[id];
    m.thunks[id] = (esp, ecx, edx, eax) => {
      fn(esp);
      return orig(esp, ecx, edx, eax);
    };
  };
  wrap('USER32.DLL!GetAsyncKeyState', (esp) => {
    const vk = m.u32[(esp + 4) >> 2];
    per.keys++;
    per.vk.set(vk, (per.vk.get(vk) || 0) + 1);
    if (per.keys > limit) throw new SpinDetected(snapshot('GetAsyncKeyState polled ' + per.keys + ' times in one tick'));
  });
  for (const n of ['KERNEL32.DLL!GetTickCount', 'WINMM.DLL!timeGetTime', 'KERNEL32.DLL!QueryPerformanceCounter']) {
    wrap(n, () => {
      per.clock++;
      if (per.clock > limit) throw new SpinDetected(snapshot('clock queried ' + per.clock + ' times in one tick'));
    });
  }
  wrap('USER32.DLL!PeekMessageA', () => {
    per.peek++;
    if (per.peek > limit) throw new SpinDetected(snapshot('PeekMessageA called ' + per.peek + ' times in one tick'));
  });
  wrap('USER32.DLL!WaitMessage', () => {
    per.wait++;
    if (per.wait > limit) throw new SpinDetected(snapshot('WaitMessage called ' + per.wait + ' times in one tick'));
  });
  const iniWrites = [];
  wrap('KERNEL32.DLL!WritePrivateProfileStringA', (esp) => {
    const a = (k) => m.u32[(esp + 4 + k * 4) >> 2];
    iniWrites.push({
      tick: ctl.tick, file: m.cstr(a(3)), section: a(0) ? m.cstr(a(0)) : null,
      key: a(1) ? m.cstr(a(1)) : null, value: a(2) ? m.cstr(a(2)) : null,
    });
  });
  const sndId = (() => { try { return m.thunkId('DSOUND.DLL!DirectSoundCreate'); } catch { return null; } })();
  void sndId;

  // --- guest state ------------------------------------------------------------------------------------
  const i32 = (a) => m.view.getInt32(a, true);
  const u32 = (a) => m.view.getUint32(a, true);
  const f32 = (a) => m.view.getFloat32(a, true);
  const state = () => {
    const s = {
      tick: ctl.tick, running: u32(0x53b9bc), phase: u32(0x53b9c0), pauseKind: u32(0x53b9f8),
      damage: i32(0x53be30), laps: i32(0x53ba18), lapLimit: i32(0x53ba1c), finished: i32(0x53be50),
      kmh: i32(0x53be34), trackTime: i32(0x53be58), position: i32(0x53be60), fastestLap: i32(0x53be5c),
      virtualMs: Math.round(race.clock.seconds * 1000),
    };
    const p = player();
    if (p) Object.assign(s, { sector: p.sector, x: +p.x.toFixed(1), y: +p.y.toFixed(1), z: +p.z.toFixed(1) });
    return s;
  };
  const player = () => {
    const racers = u32(0x67ee20), objs = u32(0x6a5c38);
    if (!racers || !objs) return null;
    const me = i32(0x53be28);
    const racer = racers + me * 0xd0;
    const obj = objs + i32(racer + 0xc) * 0xa9 + 0x10;
    const mat = [];
    for (let k = 0; k < 16; k++) mat.push(f32(obj + k * 4));
    return { me, racer, sector: i32(racer + 0x1c), prevSector: i32(racer + 0x20), x: mat[12], y: mat[13], z: mat[14], mat, fwd: f32(racer + 0xa4) };
  };
  const route = {
    maxChunk: () => i32(0x680b2c),
    waypoint: (c) => i32(u32(0x68021c) + c * 4),
    pos: (c) => {
      const w = u32(0x680b28) + route.waypoint(c) * 0x984 + 0x24;
      return [f32(w), f32(w + 4), f32(w + 8)];
    },
  };

  const tick = () => {
    resetPer();
    const ok = race.tick();
    per.maxRun = Math.max(per.maxRun, per.keys);
    ctl.tick++;
    return ok;
  };

  return { race, m, vfs, ctl, input, host, stats, messages, iniWrites, per, state, player, route, tick, i32, u32, f32 };
}

/** The race.ini sections the race writes at exit (0x42c570, 0x42c4d0, 0x42c3b0), as text. */
export function raceIniSummary(vfs) {
  const ini = vfs.parsedIni('race.ini');
  const out = {};
  for (const sec of ['PLAYER', 'RACERS', 'BEST TIMES']) {
    out[sec] = {};
    for (const k of ini.keys(sec)) out[sec][k] = ini.get(sec, k);
  }
  return out;
}
