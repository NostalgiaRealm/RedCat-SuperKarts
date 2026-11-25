#!/usr/bin/env node
// Headless check of the menu -> race INI handoff (source/host/race-handoff.js, milestone 6). For each case it writes
// the handoff with writeHandoff (what rcskmenu.dat writes before a race), logs every GetPrivateProfile* read the race
// makes (file, section, key, default, value), reads a few guest globals at boot and green, drives with the bound
// accelerate key, finishes with the Ctrl+F+I cheat (held until 50 polls of Ctrl inside one tick, as
// tools/checks/full-race-gaps.mjs 'finish-cheat-live') or aborts with Esc then J, runs the race out, and records
// every WritePrivateProfileStringA at exit. Then readResult on race.ini's text, compared with the JS port's
// nativeRaceResultPatch of the race's own exit writes (race-handoff-lib.mjs expectedPatch).
//   node tools/checks/race-handoff-probe.mjs [--only name,name] [--gas 200] [--out evidence/checks/race-handoff]
// Output: <case>.json (handoff, reads, writes, result), <case>.race-exit.ini (race.ini at exit; tests/race-handoff.test.mjs
// reads these), edges.json, summary.txt. The driven five-lap finish is race-handoff-drive.mjs.
// Exit code 1 when a case throws (ERROR), its readResult is not the JS port's patch, or the reused Vfs's handoff is
// not byte for byte a fresh one's; the edge cases are only reported.
import { writeFileSync, mkdirSync } from 'node:fs';
import { join, resolve } from 'node:path';
import { makeRace, raceIniSummary, VK, vkName } from './full-race-gaps-lib.mjs';
import { writeHandoff, readResult, PRISTINE_FILES } from '../../source/host/race-handoff.js';
import { pinRace } from '../../source/host/race-setup.js';
import { ROOT, expectedPatch, defaultSettings, installationVfs, text, RACE_KEYS } from './race-handoff-lib.mjs';

const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const OUT = resolve(ROOT, opt('out', 'evidence/checks/race-handoff'));   // an absolute --out stays absolute
const ONLY = opt('only', '') ? opt('only', '').split(',') : null;
const GAS = Number(opt('gas', 200));
mkdirSync(OUT, { recursive: true });

const DEF = await defaultSettings();          // the JS port's normalizeSettings(): a first visit's settings
const NED = 0, DUI = 1, ENG = 2, FRA = 3, SPA = 4, ITA = 5;
const CASES = {
  'qr-landenrace-redcat-ned-normal': { note: 'the recorded handoff (RedCat / Normaal / Nederland / Landenrace), default settings',
    config: { country: NED, character: 0, difficulty: 1, raceType: 0 } },
  'qr-landenrace-whizzkitty-eng-hard': { config: { country: ENG, character: 1, difficulty: 2, raceType: 0 }, settings: { ...DEF, music: 0.6, effects: 0.8 } },
  'qr-tijdrace-brutus-fra-easy': { config: { country: FRA, character: 2, difficulty: 0, raceType: 1 } },
  'qr-sterrenrace-max-spa-normal': { config: { country: SPA, character: 3, difficulty: 1, raceType: 2 } },
  'adv-duel-redcat-ita-normal': { config: { country: ITA, character: 0, difficulty: 1, raceType: 3 } },
  'adv-landenrace-max-dui-hard': { config: { country: DUI, character: 3, difficulty: 2, raceType: 0 } },
  'records-position3-ned': { note: 'saved records and grid position 3 (rcsk.race-save.v1 values)',
    config: { country: NED, character: 0, difficulty: 1, raceType: 0 },
    save: { bestTimes: { lap_record_e0: 61234, race_record_e0: 345678, time_check_count_e0: 0, lap_record_e2: 1 }, playerPosition: 3 } },
  'settings-keys-display-effects0': { note: 'K/L/A/S bound, display options off, music 30%, effects 0 (the race repairs it to 75)',
    config: { country: NED, character: 1, difficulty: 1, raceType: 1 }, gasKey: 0x4b,
    settings: { ...DEF, music: 0.3, effects: 0,
      bindings: { accelerate: 'KeyK', brake: 'KeyL', left: 'KeyA', right: 'KeyS', bonus: 'ControlLeft', handbrake: 'AltLeft' },
      display: { brightnessLight: false, bilinearFiltering: false, alphaBlending: false, particles: false } } },
  'abort-esc-j': { note: 'Esc, then J in the original requester: not finished', config: { country: NED, character: 0, difficulty: 1, raceType: 0 }, abort: true },
  'pinrace-ita-brutus': { note: 'no writeHandoff call: full-race-gaps-lib makeRace\'s pinRace({ etappe 5, car 2 }) alone (old tools)',
    pinRace: { etappe: ITA, car: 2 } },
};

/** Key changes inside one tick, at counts of polls of one key (full-race-gaps.mjs live()). */
function live(r, steps) {
  const counts = new Map();
  let i = 0, base = 0;
  r.ctl.onPoll = (vk, ctl) => {
    counts.set(vk, (counts.get(vk) || 0) + 1);
    while (i < steps.length) {
      const s = steps[i];
      if ((counts.get(s.vk) || 0) - base < s.after) break;
      for (const k of s.release || []) ctl.keys.delete(k);
      for (const k of s.press || []) ctl.keys.add(k);
      i++;
      if (i < steps.length) base = counts.get(steps[i].vk) || 0;
    }
  };
  return () => { r.ctl.onPoll = null; return i; };
}

function handoffValues(vfs) {
  const out = {};
  for (const [f, s, k] of RACE_KEYS) out[`${f} [${s}] ${k}`] = vfs.iniGet(f, s, k);
  for (const k of ['Difficulty', 'FILTER']) out[`game.ini [OPTIONS] ${k}`] = vfs.iniGet('game.ini', 'OPTIONS', k);
  for (const k of ['KEY_ACCELERATE', 'KEY_BRAKE', 'KEY_STEERLEFT', 'KEY_STEERRIGHT', 'KEY_USEBONUS', 'KEY_HANDBRAKE']) out[`game.ini [INPUT] ${k}`] = vfs.iniGet('game.ini', 'INPUT', k);
  out['game.ini [PROGRAM] RESOLUTION'] = vfs.iniGet('game.ini', 'PROGRAM', 'RESOLUTION');
  for (const k of ['gamma', 'alpha_blending', 'particles', 'windowed']) out[`SndGfx.ini [GFX OPTIONS] ${k}`] = vfs.iniGet('SndGfx.ini', 'GFX OPTIONS', k);
  return out;
}

async function runCase(name, c) {
  const r = await makeRace(c.pinRace || { etappe: c.config.country, car: c.config.character });
  // makeRace has already called pinRace (now writeHandoff); the case's handoff replaces it from the installation copies
  const handoff = c.config ? writeHandoff(r.vfs, c.config, c.save || { bestTimes: {} }, c.settings || DEF) : pinRace(r.vfs, c.pinRace);
  const values = handoffValues(r.vfs);
  const m = r.m;
  const reads = new Map();
  const phaseOf = () => (r.ctl.tick === 0 ? 'boot' : 'race');
  const wrapRead = (api, isInt) => {
    const id = m.thunkId(api);
    const orig = m.thunks[id];
    m.thunks[id] = (esp, ecx, edx, eax) => {
      const a = (k) => m.u32[(esp + 4 + k * 4) >> 2];
      const file = m.cstr(a(isInt ? 3 : 5)).split('\\').pop().toLowerCase();
      const section = a(0) ? m.cstr(a(0)) : null, key = a(1) ? m.cstr(a(1)) : null;
      const def = isInt ? (a(2) | 0) : (a(2) ? m.cstr(a(2)) : '');
      const value = section && key ? r.vfs.iniGet(file, section, key) : '(list)';
      const id2 = `${file}|${(section || '').toUpperCase()}|${(key || '').toUpperCase()}`;
      if (!reads.has(id2)) reads.set(id2, { file, section, key, def, value, kind: isInt ? 'int' : 'str', first: phaseOf(), n: 0 });
      reads.get(id2).n++;
      return orig(esp, ecx, edx, eax);
    };
  };
  wrapRead('KERNEL32.DLL!GetPrivateProfileIntA', true);
  wrapRead('KERNEL32.DLL!GetPrivateProfileStringA', false);

  r.race.boot();
  const atBoot = { difficulty53b9f4: r.i32(0x53b9f4), lapLimit: r.i32(0x53ba1c), playerIndex: r.i32(0x53be28), position: r.i32(0x53be60) };
  let n = 0;
  while (r.state().phase !== 0 && n < 3000) { r.tick(); n++; }
  const green = { tick: r.ctl.tick, ...r.state(), difficulty53b9f4: r.i32(0x53b9f4) };
  // the keys the race polls in one racing tick by itself (a binding on one of them shares it with the original's use)
  const polled = new Set();
  r.ctl.onPoll = (vk) => polled.add(vk);
  r.tick();
  r.ctl.onPoll = null;
  const gasKey = c.gasKey || VK.UP;
  r.ctl.keys = new Set([gasKey]);
  for (let k = 0; k < GAS; k++) r.tick();
  const beforeEnd = r.state();
  r.ctl.keys = new Set();
  const w0 = r.iniWrites.length;
  let steps;
  if (c.abort) {
    r.ctl.keys = new Set([VK.ESCAPE]);
    const done = live(r, [
      { vk: VK.ESCAPE, after: 40, release: [VK.ESCAPE] },
      { vk: VK.J, after: 200, press: [VK.J] },
      { vk: VK.J, after: 230, release: [VK.J] },
    ]);
    r.tick();
    steps = done();
  } else {
    r.ctl.keys = new Set([VK.CONTROL, VK.F, VK.I]);
    const done = live(r, [{ vk: VK.CONTROL, after: 50, release: [VK.CONTROL, VK.F, VK.I] }]);
    r.tick();
    steps = done();
  }
  r.ctl.keys = new Set();
  let ended = false, ticks = 0;
  for (; ticks < 4000; ticks++) { if (!r.tick()) { ended = true; break; } }
  const iniWritesAtExit = r.iniWrites.slice(w0).map(({ file, section, key, value }) => [file.split('\\').pop(), section, key, value]);
  const raceIniText = text(r.vfs.read('race.ini'));
  const result = readResult(raceIniText);
  const expected = await expectedPatch(iniWritesAtExit);
  const res = {
    case: name, note: c.note || null, config: c.config || c.pinRace, save: c.save || null,
    settings: c.settings ? { music: c.settings.music, effects: c.settings.effects, bindings: c.settings.bindings, display: c.settings.display } : 'default',
    handoff, handoffValues: values, atBoot, green, polledInOneRacingTick: [...polled].sort((a, b) => a - b).map(vkName),
    beforeEnd: { gasKey: vkName(gasKey), ...beforeEnd }, endSteps: steps, ended, exitCode: r.race.exitCode, ticksAfterEnd: ticks,
    bootWrites: r.iniWrites.filter((w) => w.tick === 0).map(({ file, section, key, value }) => [file.split('\\').pop(), section, key, value]),
    iniWritesAtExit, raceIni: raceIniSummary(r.vfs), result, expected,
    resultMatchesJsPatch: JSON.stringify(result.patch) === JSON.stringify(expected),
    reads: [...reads.values()].sort((x, y) => (x.file + x.section + x.key).localeCompare(y.file + y.section + y.key)),
    messages: r.messages.slice(-5),
  };
  writeFileSync(join(OUT, name + '.json'), JSON.stringify(res, null, 1) + '\n');
  writeFileSync(join(OUT, name + '.race-exit.ini'), raceIniText);
  return { res, vfs: r.vfs };
}

const lines = [];
const say = (s) => { lines.push(s); console.log(s); };
const failed = [];
say(`# race-handoff-probe ${new Date().toISOString()} (node ${process.version}); gas ${GAS} ticks, then the Ctrl+F+I cheat or Esc+J`);
let reuseFrom = null;
for (const [name, c] of Object.entries(CASES)) {
  if (ONLY && !ONLY.includes(name)) continue;
  const t0 = Date.now();
  let out;
  try { out = await runCase(name, c); } catch (e) { say(`${name}: ERROR ${e.stack?.split('\n').slice(0, 4).join(' | ')}`); failed.push(name + ' threw'); continue; }
  const { res } = out;
  if (name === 'qr-landenrace-whizzkitty-eng-hard') reuseFrom = out.vfs;
  const h = res.handoff;
  say(`## ${name} (${((Date.now() - t0) / 1000).toFixed(1)} s) ${c.note || ''}`);
  say(`handoff: country ${h.country} raceType ${h.raceType} difficulty ${h.difficulty ?? '(installation)'} opponents ${h.opponents} car ${h.car} position ${h.position} ` +
    `records ${JSON.stringify(h.records)} volumes ${JSON.stringify(h.volumes)} keys ${JSON.stringify(h.bindings)}`);
  say(`roster: ${h.roster.join(' / ')}`);
  say(`boot: ${JSON.stringify(res.atBoot)}; green tick ${res.green.tick}, position ${res.green.position}, difficulty ${res.green.difficulty53b9f4}; ` +
    `${res.beforeEnd.gasKey} held ${GAS} ticks: ${res.beforeEnd.kmh} km/h`);
  if (res.bootWrites.length) say('boot writes: ' + res.bootWrites.filter((w) => !/^Person_/.test(w[1])).map(([, s, k, v]) => `${s}.${k}=${v}`).join('; '));
  say(`ended ${res.ended} exit ${res.exitCode} after ${res.ticksAfterEnd} ticks; exit writes: ` + res.iniWritesAtExit.map(([, s, k, v]) => `${s}.${k}=${v}`).join('; '));
  say(`readResult: ${JSON.stringify(res.result)}; = nativeRaceResultPatch of the exit writes: ${res.resultMatchesJsPatch}`);
  if (!res.resultMatchesJsPatch) failed.push(name + ' readResult is not the JS patch');
}

// A Vfs that has run a race, used for the next one: writeHandoff must give the bytes a fresh installation Vfs gets.
if (reuseFrom) {
  const cfg = { country: SPA, character: 3, difficulty: 0, raceType: 2 };
  const save = { bestTimes: { lap_record_e4: 80000 }, playerPosition: 2 };
  writeHandoff(reuseFrom, cfg, save, DEF);
  const fresh = installationVfs();
  writeHandoff(fresh, cfg, save, DEF);
  const same = PRISTINE_FILES.map((f) => [f, text(reuseFrom.read(f)) === text(fresh.read(f))]);
  say(`## reuse: the Vfs of qr-landenrace-whizzkitty-eng-hard after its race, handed over again for ${JSON.stringify(cfg)}: ` +
    same.map(([f, s]) => `${f} ${s ? 'identical' : 'DIFFERENT'}`).join(', '));
  writeFileSync(join(OUT, 'reuse.json'), JSON.stringify({ config: cfg, save, identicalToFreshVfs: Object.fromEntries(same) }, null, 1) + '\n');
  if (!same.every(([, x]) => x)) failed.push('reused Vfs handoff differs from a fresh one');
}

// Edge cases: values the menu never writes, missing/invalid rows, the FX_VOLUME repair, and a letter key binding.
async function edge(name, ini, drive) {
  const r = await makeRace({ etappe: 0, car: 0, ini });
  let err = null;
  try { r.race.boot(); for (let i = 0; i < 330; i++) r.tick(); if (drive) drive(r); } catch (e) { err = String(e.message); }
  return { name, err, msg: r.messages.filter((x) => x.caption).map((x) => x.text).slice(-1)[0] || null,
    bootWrites: r.iniWrites.filter((w) => w.tick === 0).map((w) => [w.file.split('\\').pop(), w.section, w.key, w.value].join('|')),
    state: err ? null : r.state(), extra: r.extra };
}
if (!ONLY || ONLY.includes('edges')) {
  const E = [];
  E.push(await edge('british=1', [['race.ini', 'ETAPPE', 'british', 1]]));
  E.push(await edge('direction=1', [['race.ini', 'ETAPPE', 'direction', 1]]));
  E.push(await edge('RACERS 0..9 missing', Array.from({ length: 10 }, (_, i) => ['race.ini', 'RACERS', String(i), null])));
  E.push(await edge('RACERS 2 = "2,2"', [['race.ini', 'RACERS', '2', '2,2']]));
  E.push(await edge('FX_VOLUME=0', [['race.ini', 'GAME_SETTINGS', 'FX_VOLUME', 0]]));
  E.push(await edge('PLAYER damage=50', [['race.ini', 'PLAYER', 'damage', 50]]));
  for (const v of [38, 119, 87]) {
    E.push(await edge(`game.ini INPUT KEY_ACCELERATE=${v}`, [['game.ini', 'INPUT', 'KEY_ACCELERATE', v]], (r) => {
      const polled = new Set(); r.ctl.onPoll = (vk) => polled.add(vk); r.tick(); r.ctl.onPoll = null;
      const accel = polled.has(v) ? v : null;
      r.ctl.keys = new Set([v]); for (let i = 0; i < 40; i++) r.tick(); const raw = r.state().kmh;
      r.ctl.keys = new Set([v >= 97 ? v - 32 : v]); for (let i = 0; i < 40; i++) r.tick(); const upper = r.state().kmh;
      r.extra = { pollsBoundVk: accel !== null, kmhHoldingIniValue: raw, kmhThenHoldingUppercaseVk: upper };
    }));
  }
  // RACERS input values: three variants, same green-light run and cheat finish -> same RACERS written?
  const racersRun = async (ini) => {
    const r = await makeRace({ etappe: 0, car: 0, ini });
    r.race.boot(); for (let i = 0; i < 320; i++) r.tick();
    r.ctl.keys = new Set([VK.UP]); for (let i = 0; i < 300; i++) r.tick();
    r.ctl.keys = new Set([VK.CONTROL, VK.F, VK.I]); let c = 0;
    r.ctl.onPoll = (vk, ctl) => { if (vk === VK.CONTROL && ++c >= 50) ctl.keys.clear(); }; r.tick(); r.ctl.onPoll = null; r.ctl.keys = new Set();
    for (let i = 0; i < 400; i++) if (!r.tick()) break;
    return r.iniWrites.filter((w) => w.section !== 'Person_0' && w.tick > 0).map((w) => `${w.section}.${w.key}=${w.value}`).join('; ');
  };
  const rv = [await racersRun([]), await racersRun(Array.from({ length: 10 }, (_, i) => ['race.ini', 'RACERS', String(i), '0,0,0'])),
    await racersRun([['race.ini', 'RACERS', '0', '9,1,1000'], ['race.ini', 'RACERS', '1', '8,2,2000'], ['race.ini', 'RACERS', '3', '6,0,4000']])];
  say(`edge RACERS input values (install / all 0,0,0 / shuffled): results identical = ${rv[0] === rv[1] && rv[1] === rv[2]}; ${rv[0]}`);
  for (const e of E) say(`edge ${e.name}: ${e.err ? 'EXIT ' + e.err + ' | ' + e.msg : 'ok damage ' + e.state.damage + ' kmh ' + e.state.kmh}` +
    (e.extra ? ' ' + JSON.stringify(e.extra) : '') + (e.name === 'FX_VOLUME=0' ? ' boot writes: ' + e.bootWrites.filter((w) => /GAME_SETTINGS/.test(w)).join(', ') : ''));
  writeFileSync(join(OUT, 'edges.json'), JSON.stringify(E, null, 1) + '\n');
}
writeFileSync(join(OUT, ONLY ? 'summary-partial.txt' : 'summary.txt'), lines.join('\n') + '\n');
// on the console only, so summary.txt stays as it was
console.log(failed.length ? `FAIL ${failed.join('; ')}` : 'all passed');
if (failed.length) process.exitCode = 1;
