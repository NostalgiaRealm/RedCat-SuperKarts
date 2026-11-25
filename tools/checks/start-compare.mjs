#!/usr/bin/env node
// Compares two outputs of tools/checks/start-trace.mjs (recomp) and/or start-reference.mjs (JS port), row by row.
//   node tools/checks/start-compare.mjs A.txt B.txt
// Prints the event lines of both, the first update whose phase, 321 phase, sector, HUD km/h, effective dt,
// position or forward speed differ (position/speed beyond the printed precision), and the player's forward speed
// at fixed game times after the first moving update.
import { readFileSync } from 'node:fs';
import { basename } from 'node:path';

function load(file) {
  const text = readFileSync(file, 'utf8');
  const lines = text.split('\n');
  const header = lines.find((l) => l.startsWith('tick '));
  const recomp = header.includes('GTC_ms');
  const rows = new Map();
  for (const l of lines) {
    if (!/^\s*\d+\s/.test(l)) continue;
    const a = l.trim().split(/\s+/);
    // recomp: tick game GTC phase mv act cam cd_ph cd_el raw stored getter x y z sector fwd lat kmh lap fin thr rng
    // port:   tick game wall phase mv cam cd_ph cd_el dt x y z sector fwd lat kmh lap rng
    const r = recomp
      ? { game: +a[1], phase: a[3], cd: a[7], dt: a[11], x: +a[12], y: +a[13], z: +a[14], sector: a[15], fwd: +a[16], kmh: a[18], rng: a[22] }
      : { game: +a[1], phase: a[3], cd: a[6], dt: a[8], x: +a[9], y: +a[10], z: +a[11], sector: a[12], fwd: +a[13], kmh: a[15], rng: a[17] };
    rows.set(Number(a[0]), r);
  }
  const events = lines.filter((l) => l.startsWith('#   tick'));
  return { file: basename(file), recomp, rows, events };
}

const [A, B] = process.argv.slice(2).map(load);
for (const x of [A, B]) {
  console.log(`== ${x.file} (${x.recomp ? 'recomp' : 'JS port'})`);
  for (const e of x.events) console.log(e);
}
let first = null, firstRng = null;
for (const [n, a] of A.rows) {
  const b = B.rows.get(n);
  if (!b) break;
  const d = Math.max(Math.abs(a.x - b.x), Math.abs(a.y - b.y), Math.abs(a.z - b.z), Math.abs(a.fwd - b.fwd));
  if (first === null && (d > 0.0015 || a.phase !== b.phase || a.cd !== b.cd || a.sector !== b.sector || a.kmh !== b.kmh || a.dt !== b.dt)) first = n;
  if (firstRng === null && a.rng !== b.rng) firstRng = n;
}
console.log(`\n== row comparison over ${Math.min(A.rows.size, B.rows.size)} updates`);
console.log(`first update with a difference in phase/321/sector/km/h/dt or position/speed beyond print precision: ${first ?? 'none'}`);
console.log(`first update with a different CRT rand state: ${firstRng ?? 'none'}`);
if (first !== null) {
  for (let n = Math.max(1, first - 1); n <= first + 2; n++) {
    console.log(`  ${n} A ${JSON.stringify(A.rows.get(n))}`);
    console.log(`  ${n} B ${JSON.stringify(B.rows.get(n))}`);
  }
}
console.log('\n== forward speed at game time after the first moving update (linear between updates)');
for (const x of [A, B]) {
  const list = [...x.rows.entries()];
  const k0 = list.findIndex(([, r]) => r.fwd !== 0);
  if (k0 < 0) continue;
  const t0 = list[k0 - 1]?.[1].game ?? 0;   // the first moving update integrates from the previous update's time
  const at = (t) => {
    for (let k = k0; k < list.length; k++) {
      const r = list[k][1], p = list[k - 1][1];
      if (r.game - t0 >= t) return p.fwd + (r.fwd - p.fwd) * (t - (p.game - t0)) / (r.game - p.game);
    }
    return NaN;
  };
  console.log(`  ${x.file}: first moving update ${list[k0][0]} at ${list[k0][1].game.toFixed(3)} s; ` +
    [0.25, 0.5, 1, 1.5, 2].map((t) => `${t} s: ${at(t).toFixed(3)}`).join(', '));
}
