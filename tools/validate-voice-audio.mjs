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
    const [{NativeRaceAudio, NATIVE_DIRECT_RACE_SOUNDS}, config, manifest] = await Promise.all([
      import('/source/native-race-audio.js'), fetch('/assets/config.json').then(r => r.json()),
      fetch('/assets/manifest.json').then(r => r.json()),
    ]);
    const context = new OfflineAudioContext(2, 48000, 48000);
    const audio = new NativeRaceAudio(config, manifest, {context});
    const listener = {position: [0, 0, 0], forward: [0, 0, 1], velocity: [0, 0, 0]};
    const body = {position: [0, 0, 0], yaw: 0, lateralSpeed: 0, forwardSpeed: 0};
    const bodies = Array.from({length: 5}, () => structuredClone(body));
    const banks = [], failures = [], observed = new Set();
    for (const roster of [[4, 5, 6, 7, 0], [5, 6, 7, 8, 1], [6, 7, 8, 9, 2], [4, 6, 8, 9, 3]]) {
      await audio.prepareVoices(roster,{allSamples:true});
      for (let voiceId = 0; voiceId < 11; voiceId++) {
        for (const entry of audio.voices.banks[voiceId]) {
          const key = `${voiceId}:${entry.sample}`;
          if (observed.has(key)) continue;
          observed.add(key);
          audio.execute(audio.voices.clear());
          const accepted = audio.requestVoice({voiceId, sample: entry.sample});
          const commands = audio.updateVoices({listener, bodies});
          const slot = audio.slots.get(entry.event.toLowerCase());
          const playing = !!slot?.source;
          banks.push({voiceId, sample: entry.sample, event: entry.event,
            file: entry.sound.file, accepted, playing, frames: slot?.buffer.length,
            loop: slot?.source?.loop, commands: commands.map(c => c.op)});
          if (!accepted || !playing || slot.source.loop || !slot.buffer.length) failures.push(key);
        }
      }
    }
    audio.execute(audio.voices.clear());
    await audio.prepareVoices([4, 5, 6, 7, 0],{allSamples:true});
    const first = audio.voices.banks[0].find(x => x.sample === 'BONUS0');
    const second = audio.voices.banks[0].find(x => x.sample === 'BONUS1');
    audio.requestVoice({voiceId: 0, sample: first.sample});
    audio.requestVoice({voiceId: 0, sample: second.sample});
    audio.updateVoices({listener, bodies});
    const firstSource = audio.slots.get(first.event.toLowerCase()).source;
    audio.updateVoices({listener, bodies});
    const fifo = {
      runningPreserved: firstSource === audio.slots.get(first.event.toLowerCase()).source,
      pending: audio.voices.voices[0].queue.length,
    };
    audio.requestVoice({voiceId: 0, sample: second.sample, replace: true});
    fifo.replacementStopsImmediately = !audio.isPlaying(first.event);
    audio.updateVoices({listener, bodies});
    fifo.replacementStarts = audio.isPlaying(second.event);
    const missing = ['CLAXON', 'GOT_BONUS', 'GOT_EURO', 'SOAP_UP1'].map(sample => ({
      sample, accepted: audio.requestVoice({voiceId: sample === 'CLAXON' ? 0 : 10, sample}),
    }));
    audio.execute(audio.voices.clear());
    await audio.prepareRaceEvents();
    const direct = NATIVE_DIRECT_RACE_SOUNDS.map(event => {
      audio.execute([{event, op: 'play', loop: false}]);
      const slot = audio.slots.get(event.toLowerCase()), source = slot.source;
      audio.execute([{event, op: 'play', loop: false}]);
      const row = {event, file: slot.spec.file, playing: !!source,
        repeatSuppressed: source === slot.source, loop: source?.loop, frames: slot.buffer.length};
      audio.execute([{event, op: 'stop'}]);
      return row;
    });
    // Leave one genuine sample scheduled for nonzero PCM output.
    audio.requestVoice({voiceId: 0, sample: first.sample});
    audio.updateVoices({listener, bodies});
    const rendered = await context.startRendering();
    const channels = Array.from({length: 2}, (_, channel) => {
      const samples = rendered.getChannelData(channel);
      return {finite: samples.every(Number.isFinite),
        rms: Math.sqrt(samples.reduce((sum, value) => sum + value * value, 0) / samples.length)};
    });
    return {banks, failures, fifo, missing, direct, channels};
  });
  assert.equal(report.failures.length, 0);
  assert.ok(report.banks.length > 300);
  assert.ok(report.direct.every(x => x.playing && x.repeatSuppressed && !x.loop && x.frames > 0));
  assert.deepEqual(report.fifo, {
    runningPreserved: true, pending: 1, replacementStopsImmediately: true, replacementStarts: true,
  });
  assert.ok(report.missing.every(x => !x.accepted));
  assert.ok(report.channels.every(x => x.finite && x.rms > 0));
  report.browser = browser.version();
  report.scope = 'Each loaded native logical voice name dispatches through the real FIFO/spatial WebAudio path; direct race events preload/start and suppress repeats. Controlled near-listener placement and replacement are test inputs. This proves transport reachability, not all gameplay triggers or speaker output.';
  await mkdir('evidence/audio', {recursive: true});
  await writeFile('evidence/audio/browser-voices.json', JSON.stringify(report, null, 2) + '\n');
  console.log(JSON.stringify({voices: report.banks.length, direct: report.direct.length,
    failures: report.failures, fifo: report.fifo, channels: report.channels}));
} finally {
  await browser.close();
}
