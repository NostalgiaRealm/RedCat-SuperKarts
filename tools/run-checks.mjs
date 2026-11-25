#!/usr/bin/env node
// Every check that holds the recomp to something, one after another, with a table of pass/fail and time at the end:
//   unit     node --test (tests/*.test.mjs)
//   node     the checks on the recompiled race in Node (no browser)
//   browser  the checks in headless Chromium, one at a time: they share the machine's SwiftShader, and several of them
//            measure timing (holds, pictures per second, load times), which a second browser beside them would disturb
// A check passes when it exits 0 before its time limit. Each one exits non-zero when one of its checks fails or a page
// of it throws or crashes (tools/checks/page-errors.mjs). Left out, because they only measure or record and assert
// nothing: check-smooth.mjs, tools/checks/{analog-wheel-map, full-race-gaps, full-race-gaps-refs, hud-phone-shot,
// hud-scale-levers, hud-shots, input-modes, start-compare, start-reference, start-trace, wide-cull}.mjs and
// tools/checks/menu/compare.mjs.
// The checks write their evidence (screenshots, results) as when run alone. Those that take --out write their text
// reports into the run's folder instead, so the recorded runs in evidence/checks/ stay as they are; so does the menu
// check with the real runner (evidence/frames/menu/ holds the skeleton runner's). The run's folder (--logs, default a
// new one in the OS temp folder) also gets <check>.log with each check's output and summary.md with the table.
// Needs the dev server (tools/serve.mjs, 4190) and, for check-pause-shape and hud-touch-boxes, the JS reconstruction's
// read-only server (tools/checks/menu/serve-js-readonly.mjs, 4173): a server that does not answer is started for the
// run and stopped after it. Playwright and Chromium as for the checks themselves (PLAYWRIGHT_MODULE, CHROME_PATH).
//   node tools/run-checks.mjs [--only unit,node,browser,<check>,...] [--skip <check>,...] [--list] [--logs DIR]
//        [--timeout-scale 2]
// Exit code 1 when a check failed or ran out of time.
import { spawn } from 'node:child_process';
import { createWriteStream, mkdirSync, readFileSync, writeFileSync } from 'node:fs';
import { get } from 'node:http';
import { tmpdir } from 'node:os';
import { dirname, join, relative, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const opt = (name, def) => { const k = process.argv.indexOf('--' + name); return k < 0 ? def : process.argv[k + 1]; };
const list = (s) => (s ? s.split(',').filter(Boolean) : []);
const stamp = new Date().toISOString().replace(/[:.]/g, '-').slice(0, 19);
const LOGS = resolve(opt('logs', join(tmpdir(), 'rcsk-checks-' + stamp)));
const SCALE = Number(opt('timeout-scale', 1));
const ONLY = list(opt('only', '')), SKIP = list(opt('skip', ''));
const DEV = 'http://127.0.0.1:4190/', JS = 'http://127.0.0.1:4173/';

// name, group, arguments to node (from the project folder), time limit in minutes; js: needs the JS port's server.
// The limits are about three times what the checks took on 2026-11-25 beside other agents' checks, at least 5 minutes.
const hudScale = (shape, args) => ({ name: 'hud-scale-' + shape, group: 'node', min: 5,
  args: ['tools/checks/hud-scale-check.mjs', ...args, '--out', join(LOGS, `hud-scale-${shape}.txt`)] });
const NOTOUCH = ['--insets', '0,0,0,0'];
const CHECKS = [
  { name: 'unit', group: 'unit', min: 5, args: ['--test'] },
  { name: 'run-headless', group: 'node', min: 5, args: ['tools/run-headless.mjs', '--ticks', '400', '--gas'] },
  { name: 'flight', group: 'node', min: 10, args: ['tools/checks/flight.mjs', '--out', join(LOGS, 'flight.txt')] },
  { name: 'pause-repaint', group: 'node', min: 10, args: ['tools/checks/pause-repaint.mjs'] },
  { name: 'shadows', group: 'node', min: 15, args: ['tools/checks/shadows.mjs'] },
  { name: 'hud-layout-4x3', group: 'node', min: 5, args: ['tools/checks/hud-layout-check.mjs', '--out', join(LOGS, 'hud-layout-4x3.txt')] },
  { name: 'hud-layout-9x16', group: 'node', min: 5, args: ['tools/checks/hud-layout-check.mjs', '--xr', '1', '--yr', String(16 / 9), '--out', join(LOGS, 'hud-layout-9x16.txt')] },
  // the shapes of evidence/checks/hud-scale-*.txt (their first two lines give aspect, insets and band)
  hudScale('9x19.5', []),
  hudScale('9x19.5-tijdrace', ['--type', '1']),
  hudScale('9x19.5-sterrenrace', ['--type', '2']),
  hudScale('9x19.5-touch', ['--aspect', '0.4623', '--insets', '0.0205,0.0205,0.0557,0.0403', '--band', '0.3128']),
  hudScale('16x9', ['--aspect', String(16 / 9), ...NOTOUCH]),
  hudScale('21x9', ['--aspect', String(7 / 3), ...NOTOUCH]),
  hudScale('19.5x9-touch', ['--aspect', '2.1632', '--insets', '0.0557,0.0557,0,0.0538', '--band', '0.4707']),
  { name: 'race-handoff-probe', group: 'node', min: 5, args: ['tools/checks/race-handoff-probe.mjs', '--out', join(LOGS, 'race-handoff')] },
  // its --out is joined to the project folder (race-handoff-drive.mjs OUT), so it gets a relative path
  { name: 'race-handoff-drive', group: 'node', min: 5, args: ['tools/checks/race-handoff-drive.mjs', '--country', '1', '--out', relative(ROOT, join(LOGS, 'race-handoff'))] },
  // what whole races would wait for beyond the preload lists (tools/build-preload.mjs); --out is joined to the project folder
  { name: 'loading-full-race', group: 'node', min: 10, args: ['tools/checks/loading-full-race.mjs', '--out', relative(ROOT, join(LOGS, 'full-races.json'))] },
  { name: 'check-input', group: 'browser', min: 8, args: ['tools/check-input.mjs'] },
  { name: 'check-loading', group: 'browser', min: 8, args: ['tools/check-loading.mjs', '--out', relative(ROOT, join(LOGS, 'loading.json'))] },
  { name: 'check-shapes', group: 'browser', min: 12, args: ['tools/check-shapes.mjs'] },
  { name: 'check-touch-pad', group: 'browser', min: 10, args: ['tools/check-touch-pad.mjs'] },
  // with --browser these two also run their Node part
  { name: 'check-keys', group: 'browser', min: 20, args: ['tools/check-keys.mjs', '--browser'] },
  { name: 'check-safeguards', group: 'browser', min: 20, args: ['tools/check-safeguards.mjs', '--browser'] },
  { name: 'check-audio', group: 'browser', min: 10, args: ['tools/check-audio.mjs'] },
  { name: 'check-runner', group: 'browser', min: 10, args: ['tools/check-runner.mjs'] },
  { name: 'check-visuals', group: 'browser', min: 20, args: ['tools/check-visuals.mjs'] },
  { name: 'check-flight', group: 'browser', min: 10, args: ['tools/check-flight.mjs'] },
  { name: 'check-pause-shape', group: 'browser', min: 20, js: true, args: ['tools/check-pause-shape.mjs'] },
  { name: 'hud-touch-boxes', group: 'browser', min: 10, js: true, args: ['tools/checks/hud-touch-boxes.mjs'] },
  { name: 'check-menu', group: 'browser', min: 10, args: ['tools/checks/menu/check-menu.mjs'] },
  { name: 'check-menu-real', group: 'browser', min: 10, env: { REAL_RUNNER: '1' }, args: ['tools/checks/menu/check-menu.mjs', DEV, join(LOGS, 'menu-real')] },
  { name: 'check-menu-race', group: 'browser', min: 15, args: ['tools/check-menu-race.mjs'] },
];
const chosen = CHECKS.filter((c) => (!ONLY.length || ONLY.includes(c.name) || ONLY.includes(c.group)) && !SKIP.includes(c.name) && !SKIP.includes(c.group));
if (process.argv.includes('--list')) {
  for (const c of CHECKS) console.log(`${c.name.padEnd(28)} ${c.group.padEnd(8)} ${String(c.min).padStart(3)} min  node ${c.args.join(' ')}`);
  process.exit(0);
}
if (!chosen.length) { console.log('no check matches --only/--skip; --list shows them'); process.exit(1); }
mkdirSync(LOGS, { recursive: true });

/** Whether a server answers at url (any HTTP status). */
const answers = (url) => new Promise((res) => {
  const req = get(url, (r) => { r.resume(); res(true); });
  req.on('error', () => res(false));
  req.setTimeout(3000, () => { req.destroy(); res(false); });
});
const sleep = (ms) => new Promise((r) => setTimeout(r, ms));
const started = [];
/** The server at url, started from script when it does not answer; false when it does not come up in 30 s. */
async function server(url, script) {
  if (await answers(url)) return true;
  const child = spawn(process.execPath, [script], { cwd: ROOT, stdio: 'ignore', detached: true });
  started.push(child);
  for (let k = 0; k < 60; k++) { await sleep(500); if (await answers(url)) { console.log(`started ${script} for the run (${url})`); return true; } }
  return false;
}
// a check runs as its own process group (detached), so a time-out ends node --test's test files and Playwright's
// browser with it: SIGTERM first (Playwright closes its browsers on it, processLauncher.js sigtermHandler), SIGKILL
// 15 s later
const killGroup = (child, signal) => { try { process.kill(-child.pid, signal); } catch { /* gone */ } };
let current = null;
process.on('SIGINT', () => {
  if (current) killGroup(current, 'SIGTERM');
  for (const s of started) killGroup(s, 'SIGTERM');
  setTimeout(() => { if (current) killGroup(current, 'SIGKILL'); process.exit(130); }, 3000);
});

function run(check) {
  return new Promise((done) => {
    const t0 = Date.now();
    const logFile = join(LOGS, check.name + '.log');
    const log = createWriteStream(logFile);
    log.write(`# node ${check.args.join(' ')}${check.env ? '  env ' + JSON.stringify(check.env) : ''}\n`);
    const child = spawn(process.execPath, check.args, { cwd: ROOT, env: { ...process.env, ...check.env }, stdio: ['ignore', 'pipe', 'pipe'], detached: true });
    current = child;
    child.stdout.pipe(log, { end: false });
    child.stderr.pipe(log, { end: false });
    let timedOut = false, hard = null;
    const limit = setTimeout(() => {
      timedOut = true;
      killGroup(child, 'SIGTERM');
      hard = setTimeout(() => killGroup(child, 'SIGKILL'), 15000);
    }, check.min * SCALE * 60000);
    child.on('close', (code, signal) => {
      clearTimeout(limit); clearTimeout(hard);
      current = null;
      log.end(() => done({ code, signal, timedOut, ms: Date.now() - t0, logFile }));
    });
  });
}

const mmss = (ms) => { const s = Math.round(ms / 1000); return `${Math.floor(s / 60)}:${String(s % 60).padStart(2, '0')}`; };
console.log(`${chosen.length} checks; logs in ${LOGS}`);
let devUp = true, jsUp = null;
if (chosen.some((c) => c.group === 'browser')) devUp = await server(DEV, 'tools/serve.mjs');
const rows = [];
const t0 = Date.now();
for (const [i, check] of chosen.entries()) {
  process.stdout.write(`[${i + 1}/${chosen.length}] ${check.name} ... `);
  let r;
  if (check.group === 'browser' && !devUp) r = { pass: false, result: 'FAIL (no dev server)', ms: 0 };
  else if (check.js && !(jsUp ??= await server(JS, 'tools/checks/menu/serve-js-readonly.mjs'))) r = { pass: false, result: 'FAIL (no JS port server)', ms: 0 };
  else {
    const x = await run(check);
    const pass = x.code === 0 && !x.timedOut;
    r = { ...x, pass, result: pass ? 'pass' : x.timedOut ? `FAIL (time-out, ${check.min * SCALE} min)` : `FAIL (exit ${x.code ?? x.signal})` };
  }
  console.log(`${r.result} ${mmss(r.ms)}`);
  if (!r.pass && r.logFile) {
    // the end of its output, where the checks print their failures and totals
    const tail = readFileSync(r.logFile, 'utf8').trimEnd().split('\n').slice(-15);
    console.log(tail.map((l) => '    ' + l.slice(0, 240)).join('\n'));
  }
  rows.push({ check, ...r });
}
for (const s of started) killGroup(s, 'SIGTERM');

const failed = rows.filter((r) => !r.pass);
const table = ['| Check | Group | Result | Time |', '|---|---|---|---|',
  ...rows.map((r) => `| ${r.check.name} | ${r.check.group} | ${r.result} | ${mmss(r.ms)} |`)];
const summary = [`# run-checks ${new Date().toISOString()}`, '', ...table, '',
  `${rows.length - failed.length} of ${rows.length} passed in ${mmss(Date.now() - t0)}; logs in ${LOGS}`];
writeFileSync(join(LOGS, 'summary.md'), summary.join('\n') + '\n');
console.log('\n' + summary.slice(2).join('\n'));
process.exitCode = failed.length ? 1 : 0;
