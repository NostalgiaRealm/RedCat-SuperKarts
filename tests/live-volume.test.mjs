// node --test tests/live-volume.test.mjs
// Music and effects levels changed during a race (source/host/live-volume.js): the page's control word, and the race's
// own volume code run on a race booted headless (the installation's data, as tools/run-headless.mjs): 0x437e30 for the
// effects (every source outside MOTOR and MUSIC, the voices' switch), 0x431610 + 0x48f010 for the music, the graph
// paused at 0 and run on from there, a track that the race left unstarted at 0 started as init_game starts it, and
// race.ini's [GAME_SETTINGS] following the levels.
import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync, existsSync } from 'node:fs';
import { join } from 'node:path';
import { Race } from '../source/host/race.js';
import { writeHandoff, audioPercent } from '../source/host/race-handoff.js';
import { LiveVolume, packVolumes, unpackVolumes, NO_LEVEL } from '../source/host/live-volume.js';
import { installationVfs, haveData, ROOT } from '../tools/checks/race-handoff-lib.mjs';

const GAME = join(ROOT, 'public', 'game');
const skip = !haveData() ? 'installation data not found (SUPERKARTS_DATA)' : !existsSync(join(GAME, 'rcskspel.wasm')) ? 'no recompiled module (npm run recompile)' : false;
const VOICES = 0x53bf70, SOUNDS = 0x53bf78, MUSIC = 0x53a590, MX_VOLUME = 0x53b9a4;
const VK_UP = 0x26;
let wasm = null;

/** A race booted headless with sound sinks that record what they are told; settings { music, effects } (0..1). */
async function boot(levels) {
  const meta = JSON.parse(readFileSync(join(GAME, 'rcskspel.meta.json'), 'utf8'));
  const codeMap = new Uint8Array(readFileSync(join(GAME, 'rcskspel.codemap.bin')));
  wasm ??= new WebAssembly.Module(readFileSync(join(GAME, 'rcskspel.wasm')));
  const vfs = installationVfs();
  writeHandoff(vfs, { country: 0, character: 0, raceType: 0 }, null, levels);
  const sent = [];
  const keys = new Set();
  const nop = () => {};
  const host = {
    vfs,
    render: { freeTexture: nop, fillScreen: nop, blitToScreen: nop, loadTexture: nop, setBackground: nop, clear: nop, setViewport: nop,
      beginScene: nop, endScene: nop, setRenderState: nop, setLightState: nop, setTransform: nop, drawPrimitive: nop, drawIndexed: nop },
    input: { mouseX: 320, mouseY: 240, mouseButtons: 0, keyDown: (vk) => keys.has(vk), takeMouseDelta: () => null, setMouse: nop },
    audio: { data: nop, alias: nop, play: (id, loop) => sent.push({ t: 'play', id, loop }), stop: (id) => sent.push({ t: 'stop', id }),
      volume: (id, v) => sent.push({ t: 'volume', id, v }), pan: nop, frequency: (id, hz) => sent.push({ t: 'frequency', id, hz }), free: nop },
    music: { open: (name) => sent.push({ t: 'music-open', name }), run: (offset) => sent.push({ t: 'music-run', offset }),
      pause: () => sent.push({ t: 'music-pause' }), stop: () => sent.push({ t: 'music-stop' }), volume: (v) => sent.push({ t: 'music-volume', v }) },
    screen: { width: 640, height: 480, bits: 16 }, tickSeconds: 0.025, clockStart: 1, fixedDate: Date.UTC(2000, 3, 17, 12),
    onFlip: nop, onMessageBox: nop, onStdout: nop, log: nop,
  };
  const race = new Race(meta, host);
  await race.instantiate(wasm, codeMap);
  const volume = new LiveVolume(packVolumes(levels));
  race.boot();
  const atBoot = volume.boot(vfs);
  const ticks = (n) => { for (let k = 0; k < n; k++) assert.ok(race.tick(), 'the race runs'); };
  return { race, m: race.m, vfs, sent, keys, host, volume, atBoot, ticks };
}

/** The sound sources (0x53bf78's list, as 0x49e970 walks it): group bits (+8) and volume (+0x48, 0x49d4d0). */
function sources(m) {
  const n = m.i32[(SOUNDS + 8) >> 2];
  const out = [];
  for (let i = 0; i < n; i++) {
    const s = m.call(0x49dd20, [i], SOUNDS + 4);
    out.push({ groups: m.u32[(s + 8) >> 2], volume: m.i32[(s + 0x48) >> 2] });
  }
  return out;
}
const groupBit = (m, nameAddr) => m.call(0x49e2f0, [nameAddr], SOUNDS) >>> 0;
const fx = (p) => Math.trunc((p - 100) * 3900 / 100) - 100;          // 0x49d520 at master 100
const mx = (p) => Math.trunc(p * 4900 / 100) - 5000;                  // 0x431610

test('the control word holds the handoff\'s percent per level, 0xFF where it writes none', () => {
  assert.deepEqual(unpackVolumes(packVolumes({ music: 0.5, effects: 1 })), { music: 50, effects: 100 });
  assert.deepEqual(unpackVolumes(packVolumes({ music: 0.004, effects: 0.755 })), { music: audioPercent(0.004), effects: audioPercent(0.755) });
  assert.deepEqual(unpackVolumes(packVolumes(null)), { music: NO_LEVEL, effects: NO_LEVEL });
  assert.deepEqual(unpackVolumes(packVolumes({ effects: 0.2 })), { music: NO_LEVEL, effects: 20 });
  assert.deepEqual(unpackVolumes(packVolumes({ music: 7, effects: -1 })), { music: 100, effects: 0 });
});

test('effects during a race go through 0x437e30: every source outside MOTOR and MUSIC, the engine untouched', { skip }, async () => {
  const r = await boot({ music: 1, effects: 1 });
  assert.deepEqual(r.atBoot, { music: 100, effects: 100 });
  r.keys.add(VK_UP);
  r.ticks(480);
  const keep = groupBit(r.m, 0x4ec164) | groupBit(r.m, 0x4ec15c);      // MOTOR | MUSIC
  assert.ok(keep, 'MOTOR and MUSIC are groups');
  const before = sources(r.m);
  r.sent.length = 0;
  assert.deepEqual(r.volume.update(r.m, r.vfs, packVolumes({ music: 1, effects: 0.4 })), { effects: true });
  const after = sources(r.m);
  let changed = 0;
  after.forEach((s, i) => {
    if (s.groups & ~keep) { assert.equal(s.volume, 40, `source ${i}`); changed++; } else assert.equal(s.volume, before[i].volume, `source ${i} (MOTOR/MUSIC)`);
  });
  assert.ok(changed > 10, `${changed} effects sources`);
  assert.equal(r.m.u8[r.m.u32[VOICES >> 2]], 1, 'the voices stay on');
  const volumes = r.sent.filter((s) => s.t === 'volume');
  assert.ok(volumes.length > 0, 'playing effects get SetVolume at once');
  for (const v of volumes) assert.equal(v.v, fx(40), `buffer ${v.id}`);
  assert.equal(r.vfs.iniGet('race.ini', 'GAME_SETTINGS', 'FX_VOLUME'), '40');
  // 0: the voices off (0x437be0 clears their queues), every effects source at 0 (-40 dB, as the JS port's 0)
  r.sent.length = 0;
  r.volume.update(r.m, r.vfs, packVolumes({ music: 1, effects: 0 }));
  assert.equal(r.m.u8[r.m.u32[VOICES >> 2]], 0, 'the voices are off');
  for (const s of sources(r.m)) if (s.groups & ~keep) assert.equal(s.volume, 0);
  for (const v of r.sent.filter((s) => s.t === 'volume')) assert.equal(v.v, fx(0));
  r.ticks(80);
  r.volume.update(r.m, r.vfs, packVolumes({ music: 1, effects: 0.6 }));
  assert.equal(r.m.u8[r.m.u32[VOICES >> 2]], 1, 'the voices are on again');
  r.ticks(40);
  // a word whose effects did not change does not put them in again (driving-view.js:380-383)
  r.sent.length = 0;
  assert.deepEqual(r.volume.update(r.m, r.vfs, packVolumes({ music: 0.9, effects: 0.6 })), { music: true });
  assert.equal(r.sent.filter((s) => s.t === 'volume').length, 0);
});

test('music during a race: 0x431610 + 0x48f010, paused at 0 and run on from there', { skip }, async () => {
  const r = await boot({ music: 1, effects: 1 });
  r.ticks(200);
  const graph = r.host.musicGraphs[0];
  assert.equal(graph.state, 2, 'the track runs');
  const refs = graph.refs;
  r.sent.length = 0;
  r.volume.update(r.m, r.vfs, packVolumes({ music: 0.5, effects: 1 }));
  assert.deepEqual(r.sent, [{ t: 'music-volume', v: mx(50) }]);
  assert.equal(r.m.i32[MX_VOLUME >> 2], 50);
  assert.equal(r.vfs.iniGet('race.ini', 'GAME_SETTINGS', 'MX_VOLUME'), '50');
  r.ticks(40);
  r.sent.length = 0;
  r.volume.update(r.m, r.vfs, packVolumes({ music: 0, effects: 1 }));
  assert.deepEqual(r.sent, [{ t: 'music-pause' }]);
  assert.equal(graph.state, 1, 'paused');
  const at = graph.offset;
  r.ticks(80);
  assert.equal(graph.offset, at, 'a paused track stays where it is');
  assert.equal(r.sent.filter((s) => s.t.startsWith('music')).length, 1, 'nothing else for the music while it is paused');
  r.sent.length = 0;
  r.volume.update(r.m, r.vfs, packVolumes({ music: 0.7, effects: 1 }));
  assert.deepEqual(r.sent, [{ t: 'music-volume', v: mx(70) }, { t: 'music-run', offset: at }]);
  assert.equal(graph.state, 2);
  r.ticks(40);
  assert.equal(graph.refs, refs, 'QueryInterface and Release balance');
});

test('a race that starts with the music at 0 never runs its track; a level above 0 starts it as init_game does', { skip }, async () => {
  const r = await boot({ music: 0, effects: 1 });
  r.ticks(120);
  const graph = r.host.musicGraphs[0];
  assert.equal(r.sent.filter((s) => s.t === 'music-run').length, 0);
  assert.equal(graph.state, 0);
  r.sent.length = 0;
  r.volume.update(r.m, r.vfs, packVolumes({ music: 0.6, effects: 1 }));
  assert.deepEqual(r.sent, [{ t: 'music-volume', v: mx(60) }, { t: 'music-run', offset: 0 }]);
  assert.equal(graph.state, 2);
  assert.equal(r.m.u8[MUSIC + 0xc], 1, 'the loop byte (0x48ec20(1))');
  assert.equal(r.m.u32[MUSIC >> 2], 3, 'running, as 0x48edc0 marks it');
});

test('an enabled FX_VOLUME 0 is 75 after boot (0x437560); the menu adopting it puts nothing in', { skip }, async () => {
  const r = await boot({ music: 1, effects: 0 });
  assert.deepEqual(r.atBoot, { music: 100, effects: 75 });
  assert.equal(r.vfs.iniGet('race.ini', 'GAME_SETTINGS', 'FX_VOLUME'), '75');
  assert.equal(r.m.u8[r.m.u32[VOICES >> 2]], 1, 'the voices are on');
  r.ticks(40);
  const levels = sources(r.m).map((s) => s.volume);
  r.sent.length = 0;
  // main.js onEffects: settings.effects = 0.75, applySettings -> the word's effects 0 -> 75
  assert.deepEqual(r.volume.update(r.m, r.vfs, packVolumes({ music: 1, effects: 0.75 })), { effects: false });
  assert.equal(r.sent.length, 0);
  // a word that only changes the music leaves the effects as the race has them
  r.volume.update(r.m, r.vfs, packVolumes({ music: 0.8, effects: 0.75 }));
  assert.deepEqual(sources(r.m).map((s) => s.volume), levels);
  assert.equal(r.sent.filter((s) => s.t === 'volume').length, 0);
});
