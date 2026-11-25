#!/usr/bin/env node
// Is the GUI code with the 500 ms (0x478b90) and 800 ms (0x47d6e0) GetTickCount waits reachable from the race?
// Scans the original rcskspel.dat (read-only, from the SuperKarts reconstruction) for every way x86 code can
// reach an address: an absolute 32-bit value (pointer tables, vtables, push imm32, mov imm32) anywhere in the
// file, and E8 (call) / E9 (jmp) rel32 in the executable sections. Writes
// evidence/checks/full-race-gaps/unreachable-gui-waits.json.
//   node tools/checks/full-race-gaps-refs.mjs [--exe PATH]
import { readFileSync, writeFileSync, mkdirSync } from 'node:fs';
import { join } from 'node:path';
import { createHash } from 'node:crypto';
import { ROOT } from './full-race-gaps-lib.mjs';

const k = process.argv.indexOf('--exe');
const EXE = k > 0 ? process.argv[k + 1] : join(ROOT, '..', 'RedCat Superkarts', 'original-source', 'inputs', 'rcskspel.dat');
const d = readFileSync(EXE);
const v = new DataView(d.buffer, d.byteOffset, d.byteLength);
const pe = v.getUint32(0x3c, true);
const nsec = v.getUint16(pe + 6, true), optSize = v.getUint16(pe + 20, true);
const base = v.getUint32(pe + 52, true);
const secs = [];
for (let i = 0, o = pe + 24 + optSize; i < nsec; i++, o += 40) {
  const name = d.subarray(o, o + 8).toString('latin1').replace(/\0+$/, '');
  secs.push({ name, va: v.getUint32(o + 12, true), raw: v.getUint32(o + 20, true), rawSize: v.getUint32(o + 16, true), flags: v.getUint32(o + 36, true) });
}
const fileToVa = (fo) => {
  for (const s of secs) if (fo >= s.raw && fo < s.raw + s.rawSize) return { va: base + s.va + fo - s.raw, sec: s.name };
  return { va: null, sec: 'header' };
};

// GUI page builders that install the click handlers (0x4786e0 installs 0x478b90 at 0x478789; 0x478140, 0x4786e0,
// 0x47a100, 0x47a660, 0x47abd0 install the callers of 0x47d6e0), the handlers themselves, and 0x47fbb0 (caller of
// the inactive-window wait 0x47f370).
const targets = {
  0x478b90: 'handler with the 500 ms wait', 0x47d6e0: '800 ms wait', 0x478360: 'calls 0x47d6e0', 0x4791c0: 'calls 0x47d6e0',
  0x47a2f0: 'calls 0x47d6e0', 0x47aa40: 'calls 0x47d6e0', 0x47adf0: 'calls 0x47d6e0',
  0x4786e0: 'GUI page builder', 0x478140: 'GUI page builder', 0x47a100: 'GUI page builder', 0x47a660: 'GUI page builder',
  0x47abd0: 'GUI page builder', 0x47fbb0: 'calls 0x47f370 (inactive wait)',
  // code Ghidra did not disassemble (executable_without_instructions.tsv 0x47a47c-0x47a65f, 0x47b634-0x47bb8f,
  // 0x47c1aa-0x47c30f): 0x47a480 compares a page name and calls the five builders and 0x47b640; 0x47b640 installs
  // 0x47c1b0 (at 0x47b8cb), which calls 0x47d6e0 at 0x47c2bc
  0x47a480: 'page dispatcher (undisassembled)', 0x47b640: 'GUI page builder (undisassembled)',
  0x47c1b0: 'handler, calls 0x47d6e0 (undisassembled)',
};
const out = {};
for (const [t, what] of Object.entries(targets)) {
  const a = Number(t);
  const abs = [], rel = [];
  for (let i = 0; i + 4 <= d.length; i++) if (v.getUint32(i, true) === a) abs.push(fileToVa(i));
  for (const s of secs) {
    if (!(s.flags & 0x20000000)) continue;                       // IMAGE_SCN_MEM_EXECUTE
    for (let i = s.raw; i + 5 <= s.raw + s.rawSize; i++) {
      const op = d[i];
      if (op !== 0xe8 && op !== 0xe9) continue;
      const from = base + s.va + (i - s.raw);
      if ((from + 5 + v.getInt32(i + 1, true)) >>> 0 === a) rel.push({ at: '0x' + from.toString(16), op: op === 0xe8 ? 'call' : 'jmp' });
    }
  }
  out['0x' + a.toString(16)] = { what, absolute: abs.map((h) => (h.va ? '0x' + h.va.toString(16) : 'file') + ' ' + h.sec), rel32: rel };
}
const res = {
  exe: EXE, sha256: createHash('sha256').update(d).digest('hex'), imageBase: '0x' + base.toString(16),
  note: 'rel32 hits are byte-pattern matches in executable sections (they may include false positives inside other instructions); absolute hits are any aligned or unaligned 32-bit occurrence in the file',
  targets: out,
};
mkdirSync(join(ROOT, 'evidence/checks/full-race-gaps'), { recursive: true });
writeFileSync(join(ROOT, 'evidence/checks/full-race-gaps/unreachable-gui-waits.json'), JSON.stringify(res, null, 1) + '\n');
for (const [a, x] of Object.entries(out)) console.log(a.padEnd(10), x.what.padEnd(32), 'abs:', x.absolute.join(', ') || '-', '| rel32:', x.rel32.map((r) => r.op + '@' + r.at).join(', ') || '-');
