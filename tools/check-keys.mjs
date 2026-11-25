#!/usr/bin/env node
// Key bindings during a race, P and Esc as bindings, the stuck recovery's input and focus loss by race phase
// (source/input/race-keys.js, source/host/safeguards.js, source/race-runner.js, source/web/worker.js), against the
// JS reconstruction's behaviour (its input.js:33-42, :64-77, main.js:738-747, player-stuck-recovery.js:33-35).
// In Node, on the recompiled race (tools/checks/full-race-gaps-lib.mjs; host.cheats false, as the menu page):
//   table    at boot 0x42ce10 -> 0x42ec40 puts game.ini [INPUT] into 0x53a5b8.. (left, right, accelerate, brake, bonus,
//            handbrake) and the copy at 0x6aba20 + 8k; the keyboard device's mode word 0x53a5dc is 1
//   rebind   arrows at boot, then W, F, U, D written into that table between two passes (writeGameKeys, as the game
//            worker does): ArrowUp no longer drives, W+D+Ctrl do, with no fog, fill, debug page or overlay change
//   p-esc    P bound to accelerate: holding P pauses (0x42f9c0's own poll) and does not drive (0x4b3880 answers "up");
//            Esc bound to brake: the requester opens and the brake does nothing, where Down bound brakes
//   mix      the pad's or the wheel's actions next to a held driving key (safeguards.js BINDING_SLOTS, host.joyAction as
//            the game worker gives it): ArrowLeft held and accelerate worked by the pad: the keyboard device steers left
//            and accelerates (the JS port's per-action merge, its input.js:33-42); Shift+ArrowUp with the pad's
//            accelerate drives, Shift+ArrowUp alone does not (0x4b3880's Shift rule, which the JS port applies to its
//            keyboard sources only); every binding poll comes from 0x42ee60's eight calls
// In the browser (--browser; the dev server, Playwright, ?nocheats unless said):
//   live     the bindings changed during a race with runner.applySettings (what main.js storeSettings does after the
//            flight panel's Instellingen): the game's table follows (stats.bindings), the old ArrowUp stops driving, W
//            and D drive, the pad's X/Y and touch Bonus/Rem hold the new keys
//   stuck    accelerate rebound to W during the countdown, W held from the green on Nederland: the stuck recovery fires
//            on the new key (the worker's host.driveInput)
//   shift    at Nederland's first wall (ArrowUp from the green until the kart stands, tick ~1510), where a recovery can
//            start: Shift+ArrowUp held 10.5 s does not fire it (0x4b3880's Shift rule; the JS port's InputState.value
//            drops keys while Shift is held), the pad's RT at 0.15 for 10 s does not either (light throttle: the JS
//            port's player-stuck-recovery.js:35 needs |throttle - brake| >= 0.2), and ArrowUp alone then does, after 8 s
//   shiftpad Shift+ArrowUp+RT 0.3 from the green: the keyboard's ramps (device 1) at full throttle with the pad's
//            accelerate, as the JS port stays digital with a key: source and drops only the keyboard's sources under
//            Shift (its input.js:34-41, :49-50; race-simulation.js:390-392); Shift and ArrowUp let go: the analog handler
//   mixpad   ArrowLeft and the pad's RT 1 from the green: device 1, steer left, throttle, the kart moves (the JS port
//            drives, where a driving key used to switch the pad off)
//   pbound   P bound to accelerate in the settings: P pauses, does not drive, Space resumes
//   pedals   a scripted pad with RT 1 and LT 0.5: IN.JOY_GAS 10000 and IN.JOY_BRAKE 5000 (both pedals for the recovery)
//   focus1   blur in the countdown (phase 1): the original's pause with its "pauze" notice; Space resumes, the race goes
//            on to the green
//   focus3   (cheats on: Ctrl+F+I) blur on the finish screen (phase 3): the race is held (no passes, CTRL.PAUSED) until
//            a key, which only ends the hold
// Results in evidence/checks/keys/check-keys.json, screenshots next to it. Exit code 1 when a check fails or a browser
// page throws or crashes (checks/page-errors.mjs).
//   reqkeys  the quit requester by keyboard as the JS port's (its menuKey, main.js:799-803): Enter presses the focused
//            "nee" (the pointer parked there by the game) and the race goes on; Esc, ArrowLeft (the pointer on "ja"),
//            Enter quits
//   tab      Tab moves the focus to the touch wheel (the JS port keeps Tab from preventDefault, its input.js:70-72) and
//            reaches the game; ArrowUp (bound) is still kept from the browser
//   node tools/check-keys.mjs [--only=table,rebind,p-esc,mix] [--browser [--bonly=live,stuck,shift,shiftpad,mixpad,pbound,pedals,focus1,focus3,reqkeys,tab]]
import { writeFileSync, mkdirSync } from 'node:fs';
import { join } from 'node:path';
import { makeRace, VK, SpinDetected, ROOT } from './checks/full-race-gaps-lib.mjs';
import { writeGameKeys, gameKeys, LIB_KEY_TABLE } from '../source/input/race-keys.js';
import { BINDING_RETURNS, BINDING_SLOTS } from '../source/host/safeguards.js';
import { watchPage } from './checks/page-errors.mjs';

const arg = (name) => (process.argv.find((a) => a.startsWith(`--${name}=`)) || '').slice(name.length + 3).split(',').filter(Boolean);
const only = arg('only'), bonly = arg('bonly');
const want = (k) => !only.length || only.includes(k);
const bwant = (k) => !bonly.length || bonly.includes(k);
const results = {};
let failed = 0;
const check = (group, name, ok, detail) => {
  (results[group] ||= []).push({ name, ok: !!ok, ...(detail === undefined ? {} : { detail }) });
  if (!ok) failed++;
  console.log(`${ok ? 'ok  ' : 'FAIL'} ${group}: ${name}${detail === undefined ? '' : '  ' + JSON.stringify(detail)}`);
};
const K = { ...VK, W: 0x57, F: 0x46, U: 0x55, D: 0x44, P: 0x50, N: 0x4e, B: 0x42, H: 0x48 };
const ARROWS = { accelerate: 0x26, brake: 0x28, left: 0x25, right: 0x27, bonus: 0x11, handbrake: 0x12 };
const WFUD = { ...ARROWS, accelerate: K.W, brake: K.F, left: K.U, right: K.D };
const out = join(ROOT, 'evidence', 'checks', 'keys');
mkdirSync(out, { recursive: true });

async function racing(opts = {}) {
  const r = await makeRace({ limit: 400000, ...opts });
  r.host.cheats = false;
  r.race.boot();
  let n = 0;
  while (r.state().phase !== 0 && n < 2000) { r.tick(); n++; }
  return r;
}
const tryTick = (r) => { try { r.tick(); return 'returned'; } catch (e) { if (e instanceof SpinDetected) return 'spin: ' + e.info.reason; throw e; } };
const marks = (r) => ({ phase: r.u32(0x53b9c0), fog: r.m.u8[0x53a264], fill: r.i32(0x53a268), page: r.i32(0x53be2c), overlay: r.i32(0x53ba44) });
const drive = (r) => ({ steer: r.f32(0x53bd70), throttle: r.f32(0x53bd74), kmh: r.i32(0x53be34) });
/** One pass in which `key` is held: released after 20 of its polls, then `answer` pressed and let go (pause / requester). */
const waitPass = (r, key, answer, inner = 600) => {
  let step = 0, polls = 0, loopPolls = 0;
  r.ctl.keys = new Set([key]);
  r.ctl.onPoll = (vk, ctl) => {
    if (step > 0 || vk === key) polls++;
    if (step === 1) loopPolls++;
    if (step === 0 && polls > 20) { ctl.keys.delete(key); step = 1; polls = 0; }
    else if (step === 1 && polls > inner) { ctl.keys.add(answer); step = 2; polls = 0; }
    else if (step === 2 && polls > 600) { ctl.keys.delete(answer); step = 3; }
  };
  const res = tryTick(r);
  r.ctl.onPoll = null; r.ctl.keys = new Set();
  return { res, step, loopPolls };
};

// --- table ------------------------------------------------------------------------------------------------------------
if (want('table')) {
  const r = await makeRace({ ini: [['game.ini', 'INPUT', 'KEY_ACCELERATE', K.W], ['game.ini', 'INPUT', 'KEY_USEBONUS', K.B]] });
  r.race.boot();
  const t = gameKeys(r.m), lib = [0, 1, 2, 3, 4, 5].map((k) => r.i32(LIB_KEY_TABLE + 8 * k));
  const want = { ...ARROWS, accelerate: K.W, bonus: K.B };
  check('table', 'after boot 0x53a5b8.. holds game.ini [INPUT] in 0x42ec40\'s order, the copy at 0x6aba20 too, mode 0x53a5dc = 1',
    Object.keys(want).every((a) => t[a] === want[a]) && JSON.stringify(lib) === JSON.stringify([0x25, 0x27, K.W, 0x28, K.B, 0x12]) && r.i32(0x53a5dc) === 1,
    { table: t, copy: lib, mode: r.i32(0x53a5dc) });
}

// --- rebind -----------------------------------------------------------------------------------------------------------
if (want('rebind')) {
  const r = await racing();
  for (let k = 0; k < 20; k++) r.tick();
  const m0 = marks(r);
  writeGameKeys(r.m, WFUD);
  r.ctl.keys = new Set([K.UP]);
  for (let k = 0; k < 60; k++) r.tick();
  const old = drive(r);
  check('rebind', 'after W, F, U, D are written mid-race, the old ArrowUp no longer drives', old.throttle <= 0 && old.kmh === 0, old);
  r.ctl.keys = new Set([K.W, K.D, K.CONTROL]);           // with cheats off: Ctrl+W+D is no fog toggle, D no overlay cycle
  const res = [];
  for (let k = 0; k < 80; k++) res.push(tryTick(r));
  const now = drive(r);
  check('rebind', 'W+D+Ctrl drive with the new binding (throttle, steer right, speed), every pass returns', res.every((x) => x === 'returned') && now.throttle > 0 && now.steer > 0 && now.kmh > 5, now);
  check('rebind', 'cheats off: no fog, fill, debug page or overlay change from the newly bound keys', JSON.stringify(marks(r)) === JSON.stringify(m0), { before: m0, after: marks(r) });
}

// --- p-esc -----------------------------------------------------------------------------------------------------------
if (want('p-esc')) {
  {
    const r = await racing();
    for (let k = 0; k < 20; k++) r.tick();
    writeGameKeys(r.m, { ...ARROWS, accelerate: K.P });
    const b0 = r.race.safeguards.stats.bindingPolls;
    const w = waitPass(r, K.P, K.SPACE);
    for (let k = 0; k < 10; k++) r.tick();
    const d = drive(r);
    check('p-esc', 'P bound to accelerate: holding P pauses (the pause loop ran, Space resumed) and does not drive', w.res === 'returned' && w.step === 3 && w.loopPolls > 0 && d.throttle === 0 && d.kmh === 0 && r.race.safeguards.stats.bindingPolls > b0,
      { ...w, ...d, bindingPollsAnsweredUp: r.race.safeguards.stats.bindingPolls - b0 });
    // the same pass with W bound and held next to P: the binding reader still answers for a key that is not P
    writeGameKeys(r.m, { ...ARROWS, accelerate: K.W });
    r.ctl.keys = new Set([K.W]);
    for (let k = 0; k < 20; k++) r.tick();
    check('p-esc', 'control: W bound in its place drives', drive(r).throttle > 0, drive(r));
  }
  {
    const brakeWith = async (key) => {
      const r = await racing();
      for (let k = 0; k < 20; k++) r.tick();
      writeGameKeys(r.m, { ...ARROWS, brake: key });
      const b0 = r.race.safeguards.stats.bindingPolls;
      const w = key === K.ESCAPE ? waitPass(r, K.ESCAPE, K.N, 3000) : (r.ctl.keys = new Set([key]), { res: tryTick(r) });
      // the keyboard handler's brake counter i32 0x53be04 (stuck.js; 0x4325b0) counts the passes the brake is held
      const brake = r.i32(0x53be04);
      r.ctl.keys = new Set();
      return { ...w, brakeAfterPass: brake, running: r.u32(0x53b9bc), phase: r.u32(0x53b9c0), answeredUp: r.race.safeguards.stats.bindingPolls - b0 };
    };
    const esc = await brakeWith(K.ESCAPE), down = await brakeWith(K.DOWN);
    check('p-esc', 'Esc bound to brake: the requester opens and N goes on, the brake does nothing (Down bound brakes in the same pass)',
      esc.res === 'returned' && esc.step === 3 && esc.running === 1 && esc.phase === 0 && esc.brakeAfterPass === 0 && esc.answeredUp > 0 && down.brakeAfterPass > 0, { esc, down });
  }
}

// --- mix -------------------------------------------------------------------------------------------------------------
if (want('mix')) {
  const r = await racing();
  for (let k = 0; k < 20; k++) r.tick();
  // every binding poll's caller (0x4b3880's return address, [esp + 0x14]), from a wrapper around the safeguards' one
  const callers = new Map();
  const id = r.m.thunkId('USER32.DLL!GetAsyncKeyState');
  const inner = r.m.thunks[id];
  r.m.thunks[id] = (esp, ecx, edx, eax) => {
    const ret = r.m.u32[esp >> 2];
    if (BINDING_RETURNS.has(ret)) { const c = r.m.u32[(esp + 0x14) >> 2]; callers.set(c, (callers.get(c) || 0) + 1); }
    return inner(esp, ecx, edx, eax);
  };
  const pad = new Set();
  r.host.joyAction = (k) => pad.has(k);
  const j0 = r.race.safeguards.stats.joyPolls;
  pad.add(2);                                      // the pad's accelerate (slot 2)
  r.ctl.keys = new Set([K.LEFT]);
  for (let k = 0; k < 60; k++) r.tick();
  const a = { ...drive(r), device: r.i32(0x53a5d8), joyPolls: r.race.safeguards.stats.joyPolls - j0 };
  check('mix', 'ArrowLeft held and the pad\'s accelerate: the keyboard device steers left and accelerates', a.device === 1 && a.steer < 0 && a.throttle > 0 && a.kmh > 5 && a.joyPolls > 0, a);
  r.ctl.keys = new Set([K.DOWN]); pad.clear();
  for (let k = 0; k < 80; k++) r.tick();
  r.ctl.keys = new Set([K.SHIFT, K.UP]);
  for (let k = 0; k < 40; k++) r.tick();
  const alone = drive(r);
  pad.add(2);
  for (let k = 0; k < 40; k++) r.tick();
  const withPad = drive(r);
  check('mix', 'Shift+ArrowUp alone does not drive (0x4b3880); with the pad\'s accelerate it does (the Shift poll answered for that slot)', alone.throttle <= 0 && withPad.throttle > 0, { alone, withPad });
  pad.clear(); r.ctl.keys = new Set();
  const slotOf = [...callers.keys()].map((c) => (BINDING_SLOTS.has(c) ? BINDING_SLOTS.get(c) : c === 0x42ef5b ? 6 : c === 0x42ef77 ? 7 : 'unknown 0x' + c.toString(16)));
  check('mix', 'every binding poll comes from one of 0x42ee60\'s eight calls of 0x4b3880 (slots 0..7)', slotOf.length > 0 && slotOf.every((x) => typeof x === 'number'), { slots: slotOf, polls: [...callers.values()].reduce((x, y) => x + y, 0) });
  r.m.thunks[id] = inner;
}

// --- browser ------------------------------------------------------------------------------------------------------------
if (process.argv.includes('--browser')) {
  const { pathToFileURL } = await import('node:url');
  const { chromium } = await import(pathToFileURL(process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs')).href);
  const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });
  const URL_ = process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html';
  const wait = (ms) => new Promise((res) => setTimeout(res, ms));
  const stats = (page) => page.evaluate(() => { const g = window.gameStats; return { ticks: g.ticks, phase: g.phase, steer: g.steer, throttle: g.throttle, kmh: g.kmh, device: g.device, bindings: g.bindings, safe: g.safe, exit: g.exit, crash: g.crash, input: window.inputState() }; });
  const code = { accelerate: 'ArrowUp', brake: 'ArrowDown', left: 'ArrowLeft', right: 'ArrowRight', bonus: 'ControlLeft', handbrake: 'AltLeft' };
  const open = async (query, bindings, { pad = false, startAt = 345 } = {}) => {
    const page = await browser.newPage({ viewport: { width: 640, height: 480 } });
    page.on('pageerror', (e) => console.log('[pageerror]', e.message));
    watchPage(page, (e) => check('browser', 'no page error' + (query ? ` (${query})` : ''), false, e));
    if (pad) await page.addInitScript(() => {
      const p = { id: 'test pad (STANDARD GAMEPAD)', index: 0, connected: true, mapping: 'standard', timestamp: 0,
        axes: [0, 0, 0, 0], buttons: Array.from({ length: 17 }, () => ({ pressed: false, touched: false, value: 0 })) };
      window.__pad = p;
      window.__press = (n, v) => { p.buttons[n].value = v; p.buttons[n].pressed = v > 0.5; };
      navigator.getGamepads = () => [p];
    });
    await page.goto(URL_ + '?fixed&stats&idle' + query);
    await page.waitForFunction(() => window.runner, null, { timeout: 60000 });
    await page.evaluate((b) => { window.race(b ? { settings: { ...window.runner.settings, bindings: b } } : {}); }, bindings || null);
    await page.waitForFunction((n) => window.gameStats.ticks >= n || window.gameStats.crash, startAt, { timeout: 240000 });
    return page;
  };
  const rebind = (page, b) => page.evaluate((x) => window.runner.applySettings({ ...window.runner.settings, bindings: x }), b);
  const shot = (page, name) => page.locator('#game').screenshot({ path: join(out, name + '.png') });

  if (bwant('live')) {
    const page = await open('&nocheats');
    const s0 = await stats(page);
    const next = { ...code, accelerate: 'KeyW', brake: 'KeyF', left: 'KeyU', right: 'KeyD', bonus: 'KeyB', handbrake: 'KeyH' };
    await rebind(page, next);
    await wait(700);
    const s1 = await stats(page);
    const pad = await page.evaluate(() => ({ pad: { ...window.runner.pads.keys }, touch: window.runner.touch ? { ...window.runner.touch.keys } : null }));
    check('browser', 'live: the game\'s table follows a binding changed mid-race (stats.bindings), pad X/Y and touch Bonus/Rem hold the new keys',
      s0.bindings && s0.bindings.accelerate === 0x26 && s1.bindings && s1.bindings.accelerate === K.W && s1.bindings.left === K.U && s1.bindings.bonus === K.B && s1.bindings.handbrake === K.H && pad.pad.bonus === K.B && pad.pad.handbrake === K.H && (!pad.touch || pad.touch.bonus === K.B),
      { before: s0.bindings, after: s1.bindings, ...pad });
    await page.keyboard.down('ArrowUp'); await wait(1500);
    const s2 = await stats(page);
    await page.keyboard.up('ArrowUp');
    check('browser', 'live: the old ArrowUp no longer drives', s2.phase === 0 && s2.kmh === 0 && s2.throttle <= 0, { kmh: s2.kmh, throttle: s2.throttle });
    for (const k of ['KeyW', 'KeyD']) await page.keyboard.down(k);
    await wait(2000);
    const s3 = await stats(page);
    await shot(page, 'live-rebound-wd');
    for (const k of ['KeyW', 'KeyD']) await page.keyboard.up(k);
    check('browser', 'live: W and D drive with the new binding (cheats off: the key filter lets the binding reader through)', s3.phase === 0 && s3.throttle > 0 && s3.steer > 0 && s3.kmh > 0 && s3.safe && s3.safe.cheats === false, { throttle: s3.throttle, steer: s3.steer, kmh: s3.kmh });
    await page.close();
  }
  if (bwant('stuck')) {
    const page = await open('&nocheats', null, { startAt: 120 });
    const s0 = await stats(page);
    await rebind(page, { ...code, accelerate: 'KeyW' });
    await page.keyboard.down('KeyW');
    await page.waitForFunction(() => window.gameStats.safe && window.gameStats.safe.relocated >= 1, null, { timeout: 90000 }).catch(() => {});
    const s = await stats(page);
    await page.keyboard.up('KeyW');
    check('browser', 'stuck: accelerate rebound to W in the countdown, W held from the green: the recovery fires on the new key', s0.phase === 1 && s.safe && s.safe.stuck >= 1 && s.safe.relocated >= 1, { rebindPhase: s0.phase, safe: s.safe, bindings: s.bindings });
    await page.close();
  }
  if (bwant('shift')) {
    // At the start line no recovery can start even with real throttle (no pose to go back to: the pad's RT 1 for 432
    // passes gave none), so the rules are held where one can: the first wall on Nederland
    const page = await open('&nocheats', null, { pad: true, startAt: 340 });
    const pick = (s) => ({ ticks: s.ticks, phase: s.phase, kmh: s.kmh, device: s.device, stuck: s.safe && s.safe.stuck, pedals: s.input.pedals });
    await page.keyboard.down('ArrowUp');
    // driven faster than 20 km/h, then below 12 in two stats in a row (they come twice a second; against the wall the
    // kart can still grind at a few km/h): at the wall, with most of the recovery's 8 s still to go
    let fast = false, slow = 0, lastTicks = -1;
    const t0 = Date.now();
    for (;;) {
      await wait(100);
      const s = await stats(page);
      if (s.ticks === lastTicks) { if (Date.now() - t0 > 60000) break; continue; }
      lastTicks = s.ticks;
      if (s.kmh > 20) fast = true;
      slow = fast && Math.abs(s.kmh) < 12 ? slow + 1 : 0;
      if (slow >= 2 || (s.safe && s.safe.stuck) || Date.now() - t0 > 60000) break;
    }
    const s0 = await stats(page);
    await page.keyboard.down('ShiftLeft');
    await wait(10500);
    const s1 = await stats(page);
    await page.keyboard.up('ShiftLeft'); await page.keyboard.up('ArrowUp');
    await wait(1000);
    await page.evaluate(() => window.__press(7, 0.15));
    await wait(10000);
    const s2 = await stats(page);
    await page.evaluate(() => window.__press(7, 0));
    await wait(1000);
    await page.keyboard.down('ArrowUp');
    const t1 = Date.now();
    await page.waitForFunction(() => window.gameStats.safe && window.gameStats.safe.stuck >= 1, null, { timeout: 15000, polling: 100 }).catch(() => {});
    const ms = Date.now() - t1;
    const s3 = await stats(page);
    await page.keyboard.up('ArrowUp');
    await shot(page, 'shift-wall-recovery');
    const wall = fast && s0.phase === 0 && Math.abs(s0.kmh) < 12 && s0.safe && s0.safe.stuck === 0;
    check('browser', 'shift: at Nederland\'s first wall, Shift+ArrowUp held 10.5 s: the kart stands and the recovery does not fire',
      wall && s1.ticks - s0.ticks >= 360 && Math.abs(s1.kmh) < 3 && s1.safe.stuck === 0, { wall: pick(s0), shift: pick(s1) });
    check('browser', 'shift: at the same wall, the pad\'s RT at 0.15 for 10 s (light throttle) does not fire it either',
      wall && s2.ticks - s1.ticks >= 360 && s2.input.pedals[0] === 1500 && s2.safe.stuck === 0, pick(s2));
    check('browser', 'shift: ArrowUp alone at that wall fires it after about 8 s (the place allows a recovery)',
      wall && s3.safe.stuck >= 1 && ms >= 7000 && ms < 12000, { ...pick(s3), ms });
    await page.close();
  }
  if (bwant('shiftpad')) {
    const page = await open('&nocheats', null, { pad: true, startAt: 360 });
    await page.keyboard.down('ShiftLeft'); await page.keyboard.down('ArrowUp');
    await page.evaluate(() => window.__press(7, 0.3));
    await wait(3000);
    const s1 = await stats(page);
    await page.keyboard.up('ShiftLeft'); await page.keyboard.up('ArrowUp');
    await wait(1000);
    const s2 = await stats(page);
    await page.evaluate(() => window.__press(7, 0));
    check('browser', 'shiftpad: Shift+ArrowUp+RT 0.3: the keyboard\'s ramps (device 1) at full throttle with the pad\'s accelerate, as the JS port; let go but RT: the analog handler (device 3) at the trigger\'s throttle',
      s1.phase === 0 && s1.device === 1 && s1.throttle > 80 && s1.kmh > 5 && s1.safe.joy > 0 && s2.device === 3 && s2.throttle > 0 && s2.throttle < 60,
      { shift: { device: s1.device, kmh: s1.kmh, throttle: s1.throttle, joyPolls: s1.safe.joy }, rtOnly: { device: s2.device, kmh: s2.kmh, throttle: s2.throttle } });
    await page.close();
  }
  if (bwant('mixpad')) {
    const page = await open('&nocheats', null, { pad: true, startAt: 360 });
    const s0 = await stats(page);
    await page.keyboard.down('ArrowLeft');
    await page.evaluate(() => window.__press(7, 1));
    await wait(3000);
    const s1 = await stats(page);
    await shot(page, 'mix-arrowleft-rt');
    await page.keyboard.up('ArrowLeft');
    await page.evaluate(() => window.__press(7, 0));
    check('browser', 'mixpad: ArrowLeft and the pad\'s RT 1: the keyboard device steers left and accelerates, the kart moves (the JS port\'s per-action merge)',
      s0.phase === 0 && s1.device === 1 && s1.steer < 0 && s1.throttle > 50 && s1.kmh > 10 && s1.safe.joy > 0, { device: s1.device, steer: s1.steer, throttle: s1.throttle, kmh: s1.kmh, joyPolls: s1.safe.joy });
    await page.close();
  }
  if (bwant('pbound')) {
    const page = await open('&nocheats', { ...code, accelerate: 'KeyP' });
    const s0 = await stats(page);
    await page.keyboard.down('KeyP'); await wait(400); await page.keyboard.up('KeyP');
    await wait(1200);
    const s1 = await stats(page);
    await shot(page, 'p-bound-paused');
    await page.keyboard.down('Space'); await wait(150); await page.keyboard.up('Space');
    await wait(800);
    const s2 = await stats(page);
    check('browser', 'pbound: P bound to accelerate pauses, does not drive, Space resumes', s0.bindings.accelerate === K.P && s1.input.waiting === true && s1.kmh === 0 && s1.throttle === 0 && s2.input.waiting === false && s2.ticks > s1.ticks && s2.kmh === 0,
      { s1: { waiting: s1.input.waiting, kmh: s1.kmh, throttle: s1.throttle, bindingPolls: s1.safe }, s2: { waiting: s2.input.waiting, ticks: s2.ticks - s1.ticks } });
    await page.close();
  }
  if (bwant('pedals')) {
    const page = await open('', null, { pad: true });
    await page.evaluate(() => { window.__press(7, 1); window.__press(6, 0.5); });
    await wait(500);
    const s = await stats(page);
    await page.evaluate(() => { window.__press(7, 0); window.__press(6, 0); });
    await wait(300);
    const z = await stats(page);
    check('browser', 'pedals: RT 1 and LT 0.5 reach the game worker apart (IN.JOY_GAS 10000, IN.JOY_BRAKE 5000), and 0 when let go',
      s.input.pedals[0] === 10000 && s.input.pedals[1] === 5000 && z.input.pedals[0] === 0 && z.input.pedals[1] === 0, { held: s.input.pedals, released: z.input.pedals });
    await page.close();
  }
  if (bwant('focus1')) {
    const page = await open('', null, { startAt: 80 });
    const s0 = await stats(page);
    await page.evaluate(() => window.dispatchEvent(new Event('blur')));
    await wait(1200);
    const s1 = await stats(page);
    await shot(page, 'focus-countdown-paused');
    await wait(800);
    const s2 = await stats(page);
    await page.keyboard.down('Space'); await wait(150); await page.keyboard.up('Space');
    await page.waitForFunction(() => window.gameStats.phase === 0, null, { timeout: 30000 }).catch(() => {});
    const s3 = await stats(page);
    check('browser', 'focus1: blur in the countdown (phase 1) enters the original pause, which holds until Space; the race reaches the green',
      s0.phase === 1 && s1.input.waiting === true && s1.phase === 1 && s2.ticks === s1.ticks && s3.phase === 0 && !s3.input.waiting,
      { s0: [s0.ticks, s0.phase], s1: [s1.ticks, s1.phase, s1.input.waiting], s2: s2.ticks, s3: [s3.ticks, s3.phase] });
    await page.close();
  }
  if (bwant('focus3')) {
    const page = await open('');                       // cheats on (the development page): Ctrl+F+I finishes
    for (const k of ['ControlLeft', 'KeyF', 'KeyI']) await page.keyboard.down(k);
    await wait(600);
    for (const k of ['ControlLeft', 'KeyF', 'KeyI']) await page.keyboard.up(k);
    await page.waitForFunction(() => window.gameStats.phase === 3, null, { timeout: 20000 }).catch(() => {});
    await wait(300);
    const s0 = await stats(page);
    await page.evaluate(() => window.dispatchEvent(new Event('blur')));
    await wait(500);
    const s1 = await stats(page);
    await wait(2000);
    const s2 = await stats(page);
    await shot(page, 'focus-finish-held');
    await page.keyboard.down('Enter'); await wait(150); await page.keyboard.up('Enter');
    await wait(600);
    const s3 = await stats(page);
    check('browser', 'focus3: blur on the finish screen (phase 3) holds the race (no passes, CTRL.PAUSED) until a key, which only ends the hold',
      s0.phase === 3 && s1.input.focusHeld === true && s1.input.paused === 1 && s2.ticks === s1.ticks && s3.input.focusHeld === false && s3.input.paused === 0 && s3.ticks > s2.ticks && s3.phase === 3,
      { s0: [s0.ticks, s0.phase], s1: [s1.ticks, s1.input.focusHeld, s1.input.paused], s2: s2.ticks, s3: [s3.ticks, s3.phase, s3.input.focusHeld] });
    await page.close();
  }
  if (bwant('reqkeys')) {
    const page = await open('&nocheats');
    const press = async (code, ms = 150) => { await page.keyboard.down(code); await wait(ms); await page.keyboard.up(code); };
    await press('Escape'); await wait(1500);
    const s1 = await stats(page);
    await press('Enter'); await wait(1200);
    const s2 = await stats(page);
    await press('Escape'); await wait(1500);
    await press('ArrowLeft'); await wait(500);
    const s3 = await stats(page);
    await shot(page, 'requester-keyboard-ja');
    await press('Enter');
    await page.waitForFunction(() => window.gameStats.exit !== null, null, { timeout: 15000, polling: 50 }).catch(() => {});
    const s4 = await stats(page);
    const pick = (x) => ({ ticks: x.ticks, waiting: x.input && x.input.waiting, kind: x.input && x.input.pauseKind, focus: x.input && x.input.requesterFocus, mouse: x.input && x.input.mouse, exit: x.exit });
    check('browser', 'reqkeys: in the requester Enter presses the focused "nee" (the race goes on); ArrowLeft moves the focus to "ja" and Enter quits',
      s1.input.pauseKind === 2 && s1.input.requesterFocus === 'no' && s1.input.mouse[0] === 482 && s1.input.mouse[1] === 369 && s2.input.waiting === false && s2.ticks > s1.ticks && s2.exit === null
      && s3.input.requesterFocus === 'yes' && s3.input.mouse[0] === 207 && s3.input.mouse[1] === 369 && s4.exit === 0, { s1: pick(s1), s2: pick(s2), s3: pick(s3), s4: pick(s4) });
    await page.close();
  }
  if (bwant('tab')) {
    const page = await open('&nocheats&touch=1');
    await page.evaluate(() => {
      window.__prevented = {};
      addEventListener('keydown', (e) => { window.__prevented[e.code] = e.defaultPrevented; });
    });
    await page.keyboard.down('Tab');
    await wait(200);
    const held = await page.evaluate(() => window.inputState().held);
    await page.keyboard.up('Tab');
    const focused = await page.evaluate(() => document.activeElement && (document.activeElement.id || document.activeElement.tagName));
    await page.keyboard.down('ArrowUp'); await wait(150); await page.keyboard.up('ArrowUp');
    await page.keyboard.down('KeyP'); await wait(150); await page.keyboard.up('KeyP');
    await wait(800);
    const prevented = await page.evaluate(() => window.__prevented);
    const s = await stats(page);
    await page.screenshot({ path: join(out, 'tab-focus-wheel.png') });
    check('browser', 'tab: Tab moves the focus to the touch wheel and still reaches the game; ArrowUp (bound) is kept from the browser, P (not bound) is not, as the JS port',
      focused === 'touch-wheel' && held.includes(0x09) && prevented.Tab === false && prevented.ArrowUp === true && prevented.KeyP === false && s.input.waiting === true,
      { focused, tabHeld: held.includes(0x09), prevented, pausedByP: s.input.waiting });
    await page.close();
  }
  await browser.close();
}

writeFileSync(join(out, 'check-keys.json'), JSON.stringify({ date: new Date().toISOString(), node: process.version, failed, results }, null, 1));
console.log(failed ? `${failed} check(s) failed` : 'all checks passed');
process.exit(failed ? 1 : 0);
