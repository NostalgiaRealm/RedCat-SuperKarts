// Module-level browser diagnostic: start tools/serve.mjs with --inspect-source.
import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir, writeFile} from 'node:fs/promises';

const browser = await chromium.launch({executablePath: process.env.CHROME_PATH || '/usr/bin/google-chrome', headless: true});
try {
  const page = await browser.newPage();
  await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4173') + '/assets/config.json');
  const result = await page.evaluate(async () => {
    const [{NativeRaceAudio}, config, manifest] = await Promise.all([
      import('/source/native-race-audio.js'), fetch('/assets/config.json').then(r => r.json()),
      fetch('/assets/manifest.json').then(r => r.json()),
    ]);
    const tracks = [], context = new OfflineAudioContext(2, 48000, 48000);
    for (let id = 0; id < 6; id++) {
      const track = await fetch(`/assets/tracks/etappe${id}.json`).then(r => r.json());
      const audio = new NativeRaceAudio(config, manifest, {context});
      await audio.prepareScenery(track);
      const voices = audio.scenery.map(entry => audio.slots.get(entry.voiceId));
      const impacts = [...audio.reactiveScenery.values()].map(entry => {
        const object = {position: [0, 0, 0], yaw: 0, lateralSpeed: 5, forwardSpeed: 10};
        const listener = {position: [0, 0, 0], forward: [0, 0, 1], velocity: [0, 0, 0]};
        audio.playSceneryImpact(entry.placementIndex, listener, object);
        const slot = audio.slots.get(entry.voiceId), source = slot.source;
        audio.playSceneryImpact(entry.placementIndex, listener, object);
        const row = {placementIndex: entry.placementIndex, event: entry.sound.event,
          playing: !!source, loop: source?.loop, repeatSuppressed: source === slot.source};
        audio.execute([{event: entry.sound.event, voiceId: entry.voiceId, op: 'stop'}]);
        return row;
      });
      tracks.push({id, voices: voices.length, distinctVoices: new Set(voices).size,
        distinctGains: new Set(voices.map(voice => voice.gainNode)).size,
        originalEvents: new Set(voices.map(voice => voice.spec.event)).size, impacts});
      await audio.dispose();
    }
    const track = await fetch('/assets/tracks/etappe0.json').then(r => r.json());
    const audio = new NativeRaceAudio(config, manifest, {context});
    await audio.prepareScenery(track);
    const selected = audio.scenery.find(entry => entry.sound.event === 'NLMILL1');
    const objects = new Map(audio.scenery.map(entry => [entry.placementIndex, {visible: false}]));
    objects.set(selected.placementIndex, {position: [50, 0, 0], visible: true});
    const listener = {position: [0, 0, 0], forward: [0, 0, 1], velocity: [0, 0, 0]};
    const commands = audio.updateScenery(listener, objects);
    const slot = audio.slots.get(selected.voiceId), source = slot.source;
    audio.updateScenery(listener, objects);
    const repeatSuppressed = source === slot.source;
    objects.get(selected.placementIndex).visible = false;
    audio.updateScenery(listener, objects);
    const hiddenPreservesVoice = source === slot.source;
    objects.get(selected.placementIndex).visible = true;
    objects.get(selected.placementIndex).position = [selected.range, 0, 0];
    audio.updateScenery(listener, objects);
    const rangeStops = !slot.source;
    objects.get(selected.placementIndex).position = [50, 0, 0];
    audio.updateScenery(listener, objects);
    const gains = slot.panNodes.map(node => node.gain.value);
    const rendered = await context.startRendering();
    const rms = [0, 1].map(channel => Math.sqrt(rendered.getChannelData(channel)
      .reduce((sum, value) => sum + value * value, 0) / rendered.length));
    const output = {tracks, commands, repeatSuppressed, hiddenPreservesVoice, rangeStops,
      pan: slot.pan, gains, sourceChannels: slot.buffer.numberOfChannels, rms};
    await audio.dispose();
    return output;
  });
  assert.deepEqual(result.tracks.map(track => track.voices), [45, 61, 56, 49, 45, 55]);
  assert.ok(result.tracks.every(track => track.voices === track.distinctVoices && track.voices === track.distinctGains));
  assert.ok(result.tracks.flatMap(track => track.impacts).every(impact =>
    impact.playing && !impact.loop && impact.repeatSuppressed && impact.event === 'PION_HIT_CAR'));
  assert.equal(result.repeatSuppressed, true);
  assert.equal(result.hiddenPreservesVoice, true);
  assert.equal(result.rangeStops, true);
  assert.equal(result.pan, -10000);
  assert.equal(result.sourceChannels, 1);
  assert.ok(result.rms[0] > .001);
  assert.ok(Math.abs(result.rms[1] / result.rms[0] - 1e-5) < 1e-10);
  await mkdir('evidence/audio', {recursive: true});
  await writeFile('evidence/audio/browser-spatial.json', JSON.stringify(result, null, 2) + '\n');
  console.log('All six tracks: 311 separate source voices; native pan channel attenuation and visibility/range behavior passed.');
} finally {
  await browser.close();
}
