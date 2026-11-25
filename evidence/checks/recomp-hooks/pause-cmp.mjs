// Pause entry before and after the 0x42f6d8 patch: the same race to green + 20 ticks of throttle in both builds, then
// P pressed live (released after 40 polls of P, then Space during the pause's 0..255 scan, released again), as
// full-race-gaps.mjs 'pause-live'. Recorded for the P tick: the call sites of 0x4b3830 in order (return address of
// 0x4b3830's caller, [esp+0x10] when GetAsyncKeyState returns into 0x4b3830; the build stores return addresses),
// draws and flips; then 40 ticks with Up. Expect: the old build polls from inside 0x414160 (the player callback's key
// reads, an object pass 0x491530) between P's poll at 0x42ffda and the pause's 0x42f226, and draws/flips once more.
import { makeRace, VK, vkName } from '/home/rick/Documents/Rebuilds/RedCat Superkarts Recomp/tools/checks/full-race-gaps-lib.mjs';
const S = '/home/rick/.cache/claude-tmp/claude-1000/-home-rick-Documents-Rebuilds-RedCat-Superkarts--claude-worktrees-magical-dhawan-251123/1ec21308-8e95-49e2-a440-dd51e3d7760c/scratchpad/recomp-hooks';
const RET_IN_KEYDOWN = new Set([0x4b3848, 0x4b3850, 0x4b3860, 0x4b3868]);
async function run(gameDir, key) {
  const r = await makeRace({ gameDir, etappe: 0 });
  r.race.boot();
  let n = 0;
  while (r.state().phase !== 0 && n < 2000) { r.tick(); n++; }
  r.ctl.keys = new Set([VK.UP]);
  for (let k = 0; k < 20; k++) r.tick();
  const m = r.m;
  const sites = [];
  let recording = false;
  const id = m.thunkId('USER32.DLL!GetAsyncKeyState');
  const orig = m.thunks[id];
  m.thunks[id] = (esp, ecx, edx, eax) => {
    if (recording && RET_IN_KEYDOWN.has(m.u32[esp >> 2])) {
      const site = (m.u32[(esp + 0x10) >> 2] - 5) >>> 0;
      const last = sites.at(-1);
      if (last && last.site === site) last.n++; else sites.push({ site, n: 1 });
    }
    return orig(esp, ecx, edx, eax);
  };
  r.ctl.keys = new Set([key]);
  const steps = key === VK.P
    ? [{ vk: VK.P, after: 40, release: [VK.P] }, { vk: VK.Y, after: 50, press: [VK.SPACE] }, { vk: VK.SPACE, after: 30, release: [VK.SPACE] }]
    : [{ vk: VK.ESCAPE, after: 40, release: [VK.ESCAPE] }, { vk: VK.J, after: 200, press: [VK.N] }, { vk: VK.N, after: 220, release: [VK.N] }];
  const counts = new Map(); let i = 0, base = 0;
  r.ctl.onPoll = (vk, ctl) => {
    counts.set(vk, (counts.get(vk) || 0) + 1);
    while (i < steps.length) {
      const s = steps[i];
      if ((counts.get(s.vk) || 0) - base < s.after) break;
      for (const k of s.release || []) ctl.keys.delete(k);
      for (const k of s.press || []) ctl.keys.add(k);
      i++; if (i < steps.length) base = counts.get(steps[i].vk) || 0;
    }
  };
  const before = r.state();
  const d0 = r.stats.draws, f0 = r.stats.flips;
  recording = true;
  const ok = r.tick();
  recording = false;
  r.ctl.onPoll = null;
  const pTick = { ok, stepsDone: i, draws: r.stats.draws - d0, flips: r.stats.flips - f0, before, after: r.state() };
  const hex = (x) => x.toString(16);
  const idxP = sites.findIndex((s) => s.site === 0x42ffd5);
  const idxPause = sites.findIndex((s) => s.site === 0x42f221 || s.site === 0x42f290);
  pTick.sitesBetweenKeyAndPause = sites.slice(idxP + 1, idxPause).map((s) => hex(s.site) + 'x' + s.n);
  pTick.sitesIn414160 = sites.filter((s) => s.site >= 0x414160 && s.site < 0x414400).map((s) => hex(s.site) + 'x' + s.n);
  pTick.firstSites = sites.slice(0, 6).map((s) => hex(s.site) + 'x' + s.n);
  pTick.lastSites = sites.slice(-4).map((s) => hex(s.site) + 'x' + s.n);
  r.ctl.keys = new Set([VK.UP]);
  const then = [];
  for (let k = 0; k < 40; k++) { if (!r.tick()) { then.push('ended'); break; } if (k % 10 === 9) then.push(r.state()); }
  return { greenTick: n, pTick, then: then.map((s) => typeof s === 'string' ? s : { tick: s.tick, phase: s.phase, pauseKind: s.pauseKind, kmh: s.kmh, x: s.x, z: s.z, virtualMs: s.virtualMs }) };
}
const out = {};
for (const [name, key] of [['P', VK.P], ['Esc+N', VK.ESCAPE]]) {
  out[name] = {
    before_patch: await run(S + '/baseline-game', key),
    after_patch: await run('/home/rick/Documents/Rebuilds/RedCat Superkarts Recomp/public/game', key),
  };
}
console.log(JSON.stringify(out, null, 1));
