#!/usr/bin/env node
// Input modes of the original race, headless: pins race.ini [GAME_SETTINGS] CONTROL (and SENSITIVITY), gives the
// race a WinMM joystick through host.joystick(id), drives keys and stick after green and reads the values the
// player handler hands to the physics. Read-only on the game: it only reads guest memory after each tick.
//   node tools/checks/input-modes.mjs [--json evidence/checks/input-modes.json]
//
// Guest addresses (rcskspel.dat):
//   device       i32[0x53a5d8]  0x42ed30: CONTROL+1 -> 1 keyboard, 2 joypad, 3 wheel ("STEAR"), 4 force feedback
//   key device   i32[0x53a5dc]  keyispressed 0x4b3880 device bits: 1 keyboard, 2 joystick flags (0x4baec0)
//   sensitivity  i32[0x53a5e0]  race.ini [GAME_SETTINGS] SENSITIVITY (0x42ce10 -> 0x42ec40)
//   stuur_model  i32[0x53ba34]  game.ini [OPTIONS] stuur_model (0x42b000)
//   steer f32[0x53bd70], throttle f32[0x53bd74], brake i32[0x53be04], handbrake u32[0x53bdf4]: written by the
//     handlers 0x433870 (device 1), 0x433cf0 (2), 0x4341d0 (3) that 0x4325b0 picks, passed to 0x414160
//   last bonus   u32[0x53be1c]  GetTickCount of the last fire request (bit 0x10, 500 ms gate)
//   joystick 1   present i32[0x6aba1c], centre x/y i32[0x6aba60/64], xmax/xmin/ymax/ymin i32[0x6aba68/6c/70/74]
//                (0x4ba5e0: the first joyGetPosEx is the centre), key slots (vk, flag) at 0x6aba20 + k*8
import { readFileSync, readdirSync, statSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';
import { Vfs } from '../../source/host/vfs.js';
import { Race } from '../../source/host/race.js';
import { pinRace } from '../../source/host/race-setup.js';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const DEFAULT_DATA = join(ROOT, '..', 'RedCat Superkarts', 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c',
  'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');
const dataDir = opt('data', process.env.SUPERKARTS_DATA || DEFAULT_DATA);
const gameDir = join(ROOT, 'public/game');
const meta = JSON.parse(readFileSync(join(gameDir, 'rcskspel.meta.json'), 'utf8'));
const codeMap = new Uint8Array(readFileSync(join(gameDir, 'rcskspel.codemap.bin')));
const wasm = new WebAssembly.Module(readFileSync(join(gameDir, 'rcskspel.wasm')));
const nop = () => {};
const render = {
  freeTexture: nop, fillScreen: nop, blitToScreen: nop, loadTexture: nop, setBackground: nop, clear: nop,
  setViewport: nop, beginScene: nop, endScene: nop, setRenderState: nop, setLightState: nop, setTransform: nop,
  drawPrimitive: nop, drawIndexed: nop,
};
const C = 32767;
const VK = { LEFT: 0x25, UP: 0x26, RIGHT: 0x27, DOWN: 0x28, CTRL: 0x11, ALT: 0x12, SPACE: 0x20 };

/** One race: CONTROL, SENSITIVITY, joystick at boot, then segments of input after green. */
async function run({ control, sensitivity, bootJoy = { x: C, y: C, buttons: 0 }, segments }) {
  const vfs = new Vfs();
  for (const name of readdirSync(dataDir)) {
    const p = join(dataDir, name);
    if (statSync(p).isFile()) vfs.addLazy(name, statSync(p).size, () => new Uint8Array(readFileSync(p)));
  }
  pinRace(vfs, { etappe: 0, car: 0 });
  vfs.iniSet('race.ini', 'GAME_SETTINGS', 'CONTROL', String(control));
  if (sensitivity !== undefined) vfs.iniSet('race.ini', 'GAME_SETTINGS', 'SENSITIVITY', String(sensitivity));
  const keys = new Set();
  let joy = bootJoy;                                   // null = unplugged (JOYERR_UNPLUGGED)
  let joy2 = null;
  const input = { mouseX: 320, mouseY: 240, mouseButtons: 0, keyDown: (vk) => keys.has(vk), takeMouseDelta: () => null };
  const host = {
    vfs, render, input, audio: null, music: null, screen: { width: 640, height: 480, bits: 16 }, tickSeconds: 0.025,
    clockStart: 1, fixedDate: Date.UTC(2000, 3, 17, 12), onFlip: nop, onMessageBox: (c, t) => console.log('MessageBox:', c, '|', t),
    onStdout: nop, log: nop,
    joystick: (id) => (id === 0 ? joy : id === 1 ? joy2 : null),
  };
  const race = new Race(meta, host);
  await race.instantiate(wasm, codeMap);
  const m = race.m;
  const f32 = (a) => m.view.getFloat32(a, true);
  const i32 = (a) => m.view.getInt32(a, true);
  const u32 = (a) => m.view.getUint32(a, true);
  race.boot();
  const cfg = {
    control, device: i32(0x53a5d8), keyDevice: i32(0x53a5dc), sensitivity: i32(0x53a5e0), stuurModel: i32(0x53ba34),
    joy1: { present: i32(0x6aba1c), cx: i32(0x6aba60), cy: i32(0x6aba64), xmax: i32(0x6aba68), xmin: i32(0x6aba6c), ymax: i32(0x6aba70), ymin: i32(0x6aba74),
      slots: [0, 1, 2, 3, 4, 5, 6, 7].map((k) => i32(0x6aba20 + k * 8)) },
    joy2present: i32(0x6aba78),
    sensTable: Array.from({ length: 31 }, (_, k) => i32(0x53bae4 + k * 4)),
  };
  const state = () => {
    const racers = u32(0x67ee20), objs = u32(0x6a5c38), me = i32(0x53be28);
    const b = racers + me * 0xd0, o = objs + i32(b + 0xc) * 0xa9;
    return {
      phase: u32(0x53b9c0), steer: f32(0x53bd70), throttle: f32(0x53bd74), brake: i32(0x53be04), handbrake: u32(0x53bdf4),
      fire: u32(0x53be1c), fwd: f32(b + 0xa4), kmh: i32(0x53be34),
      yaw: Math.atan2(f32(o + 0x30), f32(o + 0x38)) * 180 / Math.PI,
      flags: [0, 1, 2, 3, 4, 5, 6, 7].map((k) => i32(0x6aba24 + k * 8)).join(''),
    };
  };
  let green = null;
  for (let n = 1; n <= 400 && green === null; n++) {
    const p = u32(0x53b9c0);
    race.tick();
    if (p === 1 && u32(0x53b9c0) === 0) green = n;
  }
  const out = [];
  for (const seg of segments) {
    keys.clear();
    for (const k of seg.keys || []) keys.add(k);
    if ('joy' in seg) joy = seg.joy;
    if ('joy2' in seg) joy2 = seg.joy2;
    if (seg.device) m.view.setInt32(0x53a5d8, seg.device, true);   // host switch of the handler 0x4325b0 picks
    const rows = [];
    for (let t = 0; t < seg.ticks; t++) {
      if (!race.tick()) break;
      rows.push(state());
    }
    out.push({ name: seg.name, rows });
  }
  return { cfg, green, segs: out };
}

const J = (x, y = C, buttons = 0) => ({ x, y, buttons });
const fmt = (s) => `steer ${s.steer.toFixed(2).padStart(7)} thr ${s.throttle.toFixed(2).padStart(6)} brk ${String(s.brake).padStart(3)} hb ${s.handbrake} fwd ${s.fwd.toFixed(2).padStart(6)} yaw ${s.yaw.toFixed(2).padStart(7)} joyflags ${s.flags} fire ${s.fire}`;
const report = {};
function print(title, r, show = (seg) => [0, 1, 2, 3, 5, 9, seg.rows.length - 1]) {
  console.log(`\n## ${title}`);
  console.log(`# cfg ${JSON.stringify({ ...r.cfg, sensTable: r.cfg.sensTable.join(',') })}, green at tick ${r.green}`);
  for (const seg of r.segs) {
    console.log(`  - ${seg.name} (${seg.rows.length} ticks)`);
    const idx = [...new Set(show(seg).filter((k) => k >= 0 && k < seg.rows.length))];
    for (const k of idx) console.log(`      +${String(k + 1).padStart(2)}  ${fmt(seg.rows[k])}`);
  }
  report[title] = { cfg: r.cfg, green: r.green, segs: r.segs.map((s) => ({ name: s.name, rows: s.rows })) };
}

// CONTROL 0: keyboard (device 1)
print('CONTROL=0 keyboard', await run({ control: 0, segments: [
  { name: 'Up+Left keys', keys: [VK.UP, VK.LEFT], ticks: 30 },
  { name: 'Up only (steer release)', keys: [VK.UP], ticks: 12 },
  { name: 'stick full left + up, buttons 1|2, no keys', keys: [], joy: J(0, 0, 3), ticks: 12 },
  { name: 'Down key (brake ramp)', keys: [VK.DOWN], joy: J(C), ticks: 12 },
  { name: 'Alt (handbrake) / Space', keys: [VK.ALT], ticks: 2 },
  { name: 'Space only', keys: [VK.SPACE], ticks: 2 },
]}));

// CONTROL 1: joypad (device 2): digital from the stick, 10% of the centre as threshold
print('CONTROL=1 joypad', await run({ control: 1, segments: [
  { name: 'stick x=0 (full left), y=0 (full up)', joy: J(0, 0), ticks: 30 },
  { name: 'stick centre, y=0', joy: J(C, 0), ticks: 12 },
  { name: 'stick x=29400 (just past 10%), y=0', joy: J(29400, 0), ticks: 30 },
  { name: 'stick x=29600 (inside 10%), y=0', joy: J(29600, 0), ticks: 6 },
  { name: 'stick centre, keys Up+Left', joy: J(C, C), keys: [VK.UP, VK.LEFT], ticks: 6 },
  { name: 'stick y=65535 (down)', joy: J(C, 65535), ticks: 12 },
  { name: 'Space key', joy: J(C, C), keys: [VK.SPACE], ticks: 2 },
  { name: 'Alt key', keys: [VK.ALT], ticks: 2 },
  { name: 'button 2', joy: J(C, C, 2), ticks: 2 },
  { name: 'button 1', joy: J(C, C, 1), ticks: 2 },
  { name: 'buttons 3|4', joy: J(C, C, 12), ticks: 2 },
  { name: 'joystick 2 full left/up (joystick 1 centre)', joy: J(C, C), joy2: J(0, 0, 15), ticks: 4 },
]}));

// CONTROL 2: wheel (device 3): analog
const xs = [0, 8192, 16384, 24576, 29000, 29490, 29491, 32767, 36043, 36044, 40000, 49151, 57344, 65535];
const ys = [0, 16384, 29000, 29490, 32767, 36044, 49151, 65535];
const wheelSegs = [
  ...xs.map((x) => ({ name: `x=${x}`, joy: J(x, C), ticks: 2 })),
  ...ys.map((y) => ({ name: `y=${y}`, joy: J(C, y), ticks: 2 })),
  { name: 'stick centre, keys Up+Left', joy: J(C, C), keys: [VK.UP, VK.LEFT], ticks: 4 },
  { name: 'Space key', keys: [VK.SPACE], ticks: 2 },
  { name: 'button 2', joy: J(C, C, 2), ticks: 2 },
  { name: 'button 1', joy: J(C, C, 1), ticks: 2 },
  { name: 'unplugged mid-race', joy: null, ticks: 3 },
];
const last = (seg) => [seg.rows.length - 1];
print('CONTROL=2 wheel', await run({ control: 2, segments: wheelSegs }), last);
print('CONTROL=2 wheel, SENSITIVITY=100', await run({ control: 2, sensitivity: 100, segments: wheelSegs }), last);
print('CONTROL=2 wheel, no joystick at boot', await run({ control: 2, bootJoy: null, segments: [
  { name: 'no joystick, keys Up', keys: [VK.UP], ticks: 10 },
  { name: 'joystick plugged in after boot, centre', joy: J(C, C), ticks: 3 },
]}));
print('CONTROL=2 wheel, calibrated at x=40000', await run({ control: 2, bootJoy: J(40000, C), segments: [
  { name: 'x=32767 (true centre)', joy: J(C, C), ticks: 2 },
  { name: 'x=40000', joy: J(40000, C), ticks: 2 },
  { name: 'x=65535', joy: J(65535, C), ticks: 2 },
  { name: 'x=0', joy: J(0, C), ticks: 2 },
]}), last);

// CONTROL 3: force feedback (device 4): 0x4325b0 case 4 reads nothing
print('CONTROL=3 force feedback', await run({ control: 3, segments: [
  { name: 'keys Up+Left', keys: [VK.UP, VK.LEFT], ticks: 10 },
  { name: 'stick x=0 y=0 buttons 3', joy: J(0, 0, 3), ticks: 10 },
]}));

// Steering response: same throttle, constant analog steer, over 80 ticks (does physics use the analog value?)
for (const x of [36044, 45000, 55000, 65535]) {
  const r = await run({ control: 2, segments: [{ name: `full throttle, x=0..: straight`, joy: J(C, 0), ticks: 40 }, { name: `full throttle, x=${x}`, joy: J(x, 0), ticks: 40 }] });
  print(`CONTROL=2 wheel steering response x=${x}`, r, (seg) => [0, 19, 39]);
}
const r1 = await run({ control: 1, segments: [{ name: 'joypad straight', joy: J(C, 0), ticks: 40 }, { name: 'joypad x=65535 (digital right)', joy: J(65535, 0), ticks: 40 }] });
print('CONTROL=1 joypad steering response', r1, (seg) => [0, 19, 39]);
const r0 = await run({ control: 0, segments: [{ name: 'keyboard straight', keys: [VK.UP], ticks: 40 }, { name: 'keyboard Up+Right', keys: [VK.UP, VK.RIGHT], ticks: 40 }] });
print('CONTROL=0 keyboard steering response', r0, (seg) => [0, 19, 39]);

// Host switch between the keyboard handler (device 1) and the analog one (device 3) between ticks, CONTROL=0 at boot
print('CONTROL=0, device switched by the host', await run({ control: 0, segments: [
  { name: 'device 1: keys Up+Left', keys: [VK.UP, VK.LEFT], ticks: 20 },
  { name: 'device 3: stick x=49151 y=16384, button 2', device: 3, joy: J(49151, 16384, 2), ticks: 4 },
  { name: 'device 3: stick centre, keys Up+Left+Alt (not read)', joy: J(C, C), keys: [VK.UP, VK.LEFT, VK.ALT], ticks: 2 },
  { name: 'device 1: keys Up+Right from steer 0', device: 1, keys: [VK.UP, VK.RIGHT], ticks: 6 },
  { name: 'device 3: stick x=57344', device: 3, joy: J(57344, C), ticks: 2 },
  { name: 'device 1: keys Up+Right from steer 74', device: 1, keys: [VK.UP, VK.RIGHT], ticks: 4 },
  { name: 'device 1: keys Up+Left from steer >0', keys: [VK.UP, VK.LEFT], ticks: 3 },
]}), (seg) => [0, 1, seg.rows.length - 1]);

const json = opt('json', null);
if (json) writeFileSync(join(ROOT, json), JSON.stringify(report));
