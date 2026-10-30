// Module-level browser diagnostic: start tools/serve.mjs with --inspect-source.
import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir, writeFile} from 'node:fs/promises';

const browser = await chromium.launch({
  executablePath: process.env.CHROME_PATH || '/usr/bin/google-chrome', headless: true,
});
try {
  const page = await browser.newPage();
  await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4173') + '/assets/config.json');
  const report = await page.evaluate(async () => {
    const [{NativeRaceAudio}, config, manifest, track] = await Promise.all([
      import('/source/native-race-audio.js'), fetch('/assets/config.json').then(r => r.json()),
      fetch('/assets/manifest.json').then(r => r.json()),
      fetch('/assets/tracks/etappe0.json').then(r => r.json()),
    ]);
    const context = new OfflineAudioContext(2, 48000, 48000);
    const audio = new NativeRaceAudio(config, manifest, {context, groupVolume: 25});
    await audio.prepareEngine();
    await audio.loadEvent('CAR_START');
    await audio.prepareRaceEvents();
    await audio.prepareVoices([4, 5, 6, 7, 0],{allSamples:true});
    await audio.prepareScenery(track);
    const ambient = audio.scenery.find(entry => entry.sound.event === 'NLMILL1');
    const impact = [...audio.reactiveScenery.values()][0];
    const snapshot = () => Object.fromEntries([
      'car_start', 'cmstartm', 'switch_gear', 'cvrpmhm', 'slip', 'schuur', 'rcbonus0', 'kt4',
      ambient.voiceId, impact.voiceId,
    ].map(name => {
      const slot = audio.slots.get(name);
      return [name, {base: slot.baseVolume, volume: slot.volumePercent, gain: slot.gainNode.gain.value}];
    }));
    const initial = snapshot();
    await audio.startEngine();
    audio.execute([{event: audio.engine.spec.start.event, op: 'stop'}]);
    const engine = audio.updateEngine({gear: 0, rpm: 4000});
    const running = snapshot();
    audio.setGroupVolume(50);
    const changed = snapshot();
    const listener = {position: [0, 0, 0], forward: [0, 0, 1], velocity: [0, 0, 0]};
    const body = {position: [0, 0, 0], yaw: 0, lateralSpeed: 0, forwardSpeed: 0};
    audio.requestVoice({voiceId: 0, sample: 'BONUS0'});
    audio.updateVoices({listener, bodies: Array(5).fill(body)});
    const voiceStarted = audio.isPlaying('RCBONUS0');
    audio.setGroupVolume(0);
    const disabled = {controller: audio.controllerEnabled, voiceStopped: !audio.isPlaying('RCBONUS0'),
      queueEmpty: audio.voices.voices[0].queue.length === 0, slots: snapshot()};
    audio.updateEngine({gear: 0, rpm: 4000});
    disabled.engineAfterNativeUpdate = snapshot();
    audio.setGroupVolume(25);
    const reenabled = audio.controllerEnabled;
    // New scenery clones keep immutable TYPE levels even after static FX writes.
    await audio.prepareScenery(track);
    const recreated = snapshot();
    const repaired = new NativeRaceAudio(config, manifest, {context, groupVolume: 0});
    const repairedState = {effects: repaired.groupVolume, enabled: repaired.controllerEnabled};
    await repaired.dispose();
    const rendered = await context.startRendering();
    const rms = Array.from({length: 2}, (_, c) => {
      const values = rendered.getChannelData(c);
      return Math.sqrt(values.reduce((sum, x) => sum + x * x, 0) / values.length);
    });
    await audio.dispose();
    return {initial, engine, running, changed, voiceStarted, disabled, reenabled, recreated, repairedState, rms,
      ambient: {key: ambient.voiceId, original: ambient.baseVolume},
      impact: {key: impact.voiceId, original: impact.baseVolume}};
  });
  const gain = percent => 10 ** ((Math.trunc((percent - 100) * 3900 / 100) - 100) / 2000);
  const close = (actual, expected) => assert.ok(Math.abs(actual - expected) < 1e-7, `${actual} != ${expected}`);
  for (const [name, percent] of Object.entries({car_start:80, cmstartm:25, switch_gear:70, cvrpmhm:25, slip:25, schuur:25, rcbonus0:25, kt4:25})) {
    assert.equal(report.initial[name].base, percent, name);
    close(report.initial[name].gain, gain(percent));
  }
  for (const selected of [report.ambient, report.impact]) {
    assert.equal(report.initial[selected.key].base, selected.original);
    assert.equal(report.changed[selected.key].base, 50);
    assert.equal(report.recreated[selected.key].base, selected.original);
  }
  for (const command of report.engine.filter(x => x.op === 'volume' && x.event === 'cvrpmhm')) {
    assert.equal(report.running.cvrpmhm.volume, command.percent);
    close(report.running.cvrpmhm.gain, gain(command.percent));
    assert.equal(report.disabled.engineAfterNativeUpdate.cvrpmhm.volume, command.percent);
  }
  assert.equal(report.changed.car_start.volume, 80);
  assert.equal(report.changed.switch_gear.volume, 70);
  assert.equal(report.changed.rcbonus0.volume, 50);
  assert.equal(report.voiceStarted, true);
  assert.equal(report.disabled.controller, false);
  assert.equal(report.disabled.voiceStopped, true);
  assert.equal(report.disabled.queueEmpty, true);
  close(report.disabled.slots.schuur.gain, .01);
  assert.equal(report.reenabled, true);
  assert.deepEqual(report.repairedState, {effects:75, enabled:true});
  assert.ok(report.rms.every(x => Number.isFinite(x) && x > 0));
  report.browser = browser.version();
  report.scope = 'Browser gain-node values and real original PCM across load-time overrides, positional clones, later FX changes, queue clearing and engine overrides. Compared with native-instruction volume/gate fixtures, not an original sound-card recording.';
  await mkdir('evidence/audio', {recursive: true});
  await writeFile('evidence/audio/browser-mixing.json', JSON.stringify(report, null, 2) + '\n');
  console.log(JSON.stringify({status:'passed', repaired:report.repairedState, rms:report.rms}));
} finally {
  await browser.close();
}
