// Development page (/dev/race.html): races without the menu, through the same RaceRunner the menu uses
// (source/race-runner.js). One race starts from the URL unless ?idle; window.race(overrides) starts another on the
// same page (tools/check-runner.mjs runs three in a row).
//   ?etappe=N    country 0..5 in track.ini order (0 Nederland, 1 Duitsland, 2 Engeland, 3 Frankrijk, 4 Spanje, 5 Italie)
//   ?car=N       character 0..3 (RedCat, WhizzKitty, Brutus, Max)      ?race=N  race type 0..3 (Landen, Tijd, Sterren, duel)
//   ?difficulty=N  0..2 (default 1)                                     ?fixed   a fixed clock and date (repeatable runs)
//   ?stats       tick, phase, draws and pictures per second at the bottom
//   ?touch=1|0   touch controls always / never (else on touch screens)  ?deadzone=18  the pad's dead zone in percent
//   ?res=auto|native|full|WxH  drawing size   ?scale=25..200  render scale   ?msaa=2|4|8   ?fps  the FPS counter
//   ?nosmooth    no blending between passes  ?blendat=T  every picture at T between two passes  ?nocull  no culling
//   ?flight      free flight on (settings.freeFlight: the kart takes off at the first racing pass; runner.applySettings
//                with freeFlight false lands it)
//   ?noshadows   the original kart shadow (Schaduwen op het wegdek off)  ?nolights  Motorlicht volgt de kart off
//   ?nocheats    the original's debug and cheat keys read "up", as on the menu page (they answer here by default:
//                Ctrl+F+I finishes the race in the checks; source/host/safeguards.js)
// For checks: window.gameStats (the race's ticks, phase, exit code, race.ini, outcome, file loading), window.renderStats,
// window.inputState(), window.audioState(), window.runner.
import { RaceRunner } from '../race-runner.js';

const params = new URLSearchParams(location.search);
const status = document.getElementById('status');
const say = (s) => { status.textContent = s; };
const num = (name, def) => (params.has(name) && params.get(name) !== '' && Number.isFinite(Number(params.get(name))) ? Number(params.get(name)) : def);

const res = params.get('res') || 'auto';
const msaa = num('msaa', 0);
const settings = {
  resolution: res === 'full' ? 'native' : res, renderScale: Math.max(25, Math.min(200, num('scale', 100))),
  msaaEnabled: msaa >= 2, msaaSamples: [2, 4, 8].includes(msaa) ? msaa : 4,
  surfaceShadows: !params.has('noshadows'), smoothEngineLights: !params.has('nolights'), showFps: params.has('fps'), freeFlight: params.has('flight'),
  music: 1, effects: 1, deadzone: params.has('deadzone') ? num('deadzone', 18) / 100 : 0.18,
  touch: params.get('touch') === '1' ? 'on' : params.get('touch') === '0' ? 'off' : 'auto',
  fullscreen: false, startInfo: true, controlType: 0,
  bindings: { accelerate: 'ArrowUp', brake: 'ArrowDown', left: 'ArrowLeft', right: 'ArrowRight', bonus: 'ControlLeft', handbrake: 'AltLeft' },
  display: { brightnessLight: true, bilinearFiltering: true, alphaBlending: true, particles: true },
};
const runner = new RaceRunner({
  canvas: document.getElementById('game'), touchRoot: document.getElementById('touch-controls'), fpsElement: document.getElementById('fps-counter'), settings,
  dev: { smooth: !params.has('nosmooth'), debug: { noCull: params.has('nocull'), ...(params.has('blendat') ? { blendAt: Number(params.get('blendat')) } : {}) } },
  cheats: !params.has('nocheats'),
  // this page is /dev/race.html: the original files are the site's data/, one folder up
  urls: { data: new URL('../data/', location.href).href },
});
window.runner = runner;
window.renderStats = null;
window.inputState = () => runner.inputState();
window.audioState = () => runner.audioState();
const fresh = () => ({ ticks: 0, phase: -1, running: false, shown: false, exit: null, crash: null, raceIni: null, outcome: null, load: null, progress: [], fps: null, races: (window.gameStats ? window.gameStats.races : 0) });
window.gameStats = fresh();
window.renderResets = [];
runner.on('rstats', (r) => { window.renderStats = r; });
runner.on('reset', (r) => window.renderResets.push(r));
runner.on('fps', (f) => { window.gameStats.fps = f; });
runner.on('log', (s) => console.log('[game]', s));
runner.on('messagebox', (d) => { console.warn('MessageBox', d.caption, d.text); say(d.caption + ': ' + d.text); });
runner.on('loaded', (l) => { window.gameStats.load = l; });
runner.on('status', (s) => {
  if (s.stage === 'running') { window.gameStats.running = true; say(''); return; }
  say(s.stage === 'files' ? `Laden… ${s.percent}%` : 'Starten…');
});
runner.on('stats', (d) => {
  Object.assign(window.gameStats, d);
  if (params.has('stats')) { const r = window.renderStats; say(`tick ${d.ticks}  fase ${d.phase}  draws ${d.draws}` + (r ? `  beeld ${r.shownPerSec}/s  spel ${r.framesPerSec}/s` : '')); }
});

/** A race with the URL's choices, overridden by `overrides` ({ country, character, difficulty, raceType, fixed, save, settings }). */
window.race = async (overrides = {}) => {
  const races = window.gameStats.races + 1;
  window.gameStats = { ...fresh(), races };
  const stats = window.gameStats;
  const t0 = performance.now();
  const outcome = await runner.start({
    country: num('etappe', 0), character: num('car', 0), difficulty: num('difficulty', 1), raceType: num('race', 0),
    fixed: params.has('fixed'), save: { bestTimes: {}, playerPosition: null }, settings,
    ...overrides,
    onProgress: (percent, stage) => stats.progress.push([Math.round(performance.now() - t0), stage, percent]),
    onRunning: () => { stats.shown = true; stats.shownMs = Math.round(performance.now() - t0); },
  });
  stats.outcome = outcome;
  stats.raceIni = runner.lastRaceIni;
  stats.files = runner.lastFiles;
  if (outcome.error) { stats.crash = outcome.error; say('Fout: ' + outcome.error); }
  else say('Race afgelopen (exit ' + outcome.exitCode + ')');
  stats.exit = outcome.exitCode ?? (outcome.error ? -1 : null);
  return outcome;
};

if (runner.error) say(runner.error);
else if (!params.has('idle')) window.race();
