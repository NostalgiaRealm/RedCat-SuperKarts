// Lockstep run of the baseline build (before the wraps and the pause patch) and the new one, same host, same keys:
// game memory must stay identical (except the pop table and the code map, which hold thunk pops and table
// indices) as long as nobody pauses. The new build's four wrap hooks are wrapped with counting wrappers (m.wrap,
// calling next), so the chain and the default body binding are exercised. --via-original: KartShadow's wrapper
// calls m.callOriginal instead of next (its frame then sits elsewhere on the stack: only the image and heap are compared).
//   node cmp-builds.mjs --etappe 0 --ticks 3000 [--via-original]
import { makeRace, VK } from '/home/rick/Documents/Rebuilds/RedCat Superkarts Recomp/tools/checks/full-race-gaps-lib.mjs';
const S = '/home/rick/.cache/claude-tmp/claude-1000/-home-rick-Documents-Rebuilds-RedCat-Superkarts--claude-worktrees-magical-dhawan-251123/1ec21308-8e95-49e2-a440-dd51e3d7760c/scratchpad/recomp-hooks';
const opt = (n, d) => { const k = process.argv.indexOf('--' + n); return k < 0 ? d : process.argv[k + 1]; };
const etappe = Number(opt('etappe', 0)), ticks = Number(opt('ticks', 1000)), viaOriginal = process.argv.includes('--via-original');
const a = await makeRace({ gameDir: S + '/baseline-game', etappe });
const b = await makeRace({ gameDir: '/home/rick/Documents/Rebuilds/RedCat Superkarts Recomp/public/game', etappe });
const L = b.m.layout;
const counts = { NpcPrepare: 0, KartShadow: 0, BonusPickUp: 0, RescueUpdate: 0 };
for (const name of Object.keys(counts)) {
  b.m.wrap(name, (esp, ecx, edx, eax, next) => {
    counts[name]++;
    if (viaOriginal && name === 'KartShadow') return b.m.callOriginal(0x4260c0, [b.m.u32[(esp + 4) >> 2]]);
    return next(esp, ecx, edx, eax);
  });
}
const skip = [[L.POP_TABLE, L.POP_TABLE + L.N_THUNKS * 4], [L.CODE_MAP, L.CODE_MAP + (L.IMAGE_END - L.MAP_LO) * 2]];
if (viaOriginal) skip.push([L.STACK_LOW, L.STACK_TOP]);
const memDiff = () => {
  const x = a.m.u8, y = b.m.u8;
  const n = Math.min(x.length, y.length);
  const out = [];
  let p = 0;
  for (const [lo, hi] of [...skip.sort((u, v) => u[0] - v[0]), [n, n]]) {
    if (p < lo && Buffer.compare(Buffer.from(x.buffer, p, lo - p), Buffer.from(y.buffer, p, lo - p)) !== 0) {
      for (let k = p; k < lo && out.length < 8; k++) if (x[k] !== y[k]) { out.push('0x' + k.toString(16)); k += 64; }
    }
    p = hi;
  }
  return { sizes: [x.length, y.length], diffs: out };
};
a.race.boot(); b.race.boot();
const report = { etappe, ticks, viaOriginal, boot: memDiff(), checks: [] };
let drawsDiffer = 0;
for (let t = 0; t < ticks; t++) {
  const keys = [VK.UP];
  if (t % 700 > 600) keys.push(VK.LEFT);               // some steering, so the karts meet walls and rescues
  a.ctl.keys = new Set(keys); b.ctl.keys = new Set(keys);
  const da = a.stats.draws, db = b.stats.draws, fa = a.stats.flips, fb = b.stats.flips;
  const oa = a.tick(), ob = b.tick();
  if (a.stats.draws - da !== b.stats.draws - db || a.stats.flips - fa !== b.stats.flips - fb || oa !== ob) drawsDiffer++;
  if (t % 250 === 249 || t === ticks - 1) {
    const d = memDiff();
    report.checks.push({ tick: t + 1, memDiffs: d.diffs, stateA: a.state(), sameState: JSON.stringify(a.state()) === JSON.stringify(b.state()) });
    if (d.diffs.length) break;
  }
}
report.ticksWithOtherDrawsOrFlips = drawsDiffer;
report.draws = [a.stats.draws, b.stats.draws];
report.wrapCalls = counts;
report.unbound = b.race.unbound;
console.log(JSON.stringify(report, null, 1));
