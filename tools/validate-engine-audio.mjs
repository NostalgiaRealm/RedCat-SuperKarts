// Module-level browser diagnostic: start tools/serve.mjs with --inspect-source.
import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir, writeFile} from 'node:fs/promises';

const browser = await chromium.launch({executablePath: process.env.CHROME_PATH || '/usr/bin/google-chrome', headless: true});
try {
  const page = await browser.newPage();
  await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4173') + '/assets/config.json');
  await page.setContent('<button id="start">Start original engine</button>');
  await page.evaluate(async () => {
    const [{NativeRaceAudio}, config, manifest] = await Promise.all([
      import('/source/native-race-audio.js'), fetch('/assets/config.json').then(r => r.json()),
      fetch('/assets/manifest.json').then(r => r.json()),
    ]);
    window.audioTest = {config, manifest, NativeRaceAudio};
    document.querySelector('button').onclick = async () => {
      try {
        const audio = window.audioTest.audio = new NativeRaceAudio(config, manifest);
        await audio.unlock();
        await audio.startEngine();
        window.audioTest.starterBlocked = audio.updateEngine({gear: 0, rpm: 800}).length === 0;
        window.audioTest.interval = setInterval(() => audio.updateEngine({gear: 0, rpm: 4000}), 25);
      } catch (error) { window.audioTest.error = String(error); }
    };
  });
  await page.click('#start');
  await page.waitForFunction(() => window.audioTest.error || window.audioTest.audio?.engine.gear === 0);
  const live = await page.evaluate(async () => {
    const fixture = window.audioTest, audio = fixture.audio;
    if (fixture.error) throw new Error(fixture.error);
    clearInterval(fixture.interval);
    const playing = [...audio.slots.values()].filter(slot => slot.source).map(slot => ({
      event: slot.spec.event, sourceRate: slot.sampleRate, decodedRate: slot.buffer.sampleRate,
      loop: slot.source.loop, playbackRate: slot.source.playbackRate.value, gain: slot.gainNode.gain.value,
    }));
    await audio.pause();
    const pausedTime = audio.context.currentTime;
    await new Promise(resolve => setTimeout(resolve, 150));
    const pauseDelta = audio.context.currentTime - pausedTime;
    await audio.resume();
    audio.updateEngine({gear: 1, rpm: 4500});
    const gearEffect = audio.isPlaying('SWITCH_GEAR');
    const source = audio.slots.get('switch_gear').source;
    await audio.playEvent('SWITCH_GEAR');
    const repeatSuppressed = source === audio.slots.get('switch_gear').source;
    audio.updateSkid({slipMagnitude: 10, playerContact: true});
    const skidSlot = audio.slots.get('slip'), skid = {
      playing: audio.isPlaying('SLIP'), loop: skidSlot.source?.loop,
      pitchPercent: skidSlot.pitchPercent, playbackRate: skidSlot.source?.playbackRate.value,
    };
    audio.updateSkid({slipMagnitude: 0, playerContact: false, soundEnabled: false});
    skid.disabledPreservesVoice = audio.isPlaying('SLIP');
    audio.updateSkid({slipMagnitude: 10, playerContact: false});
    skid.airborneStops = !audio.isPlaying('SLIP');
    audio.updateSkid({slipMagnitude: 10, playerContact: true, controllerEnabled: false});
    skid.controllerBlocksStart = !audio.isPlaying('SLIP');
    await audio.dispose();
    return {starterBlocked: fixture.starterBlocked, playing, pauseDelta, gearEffect, repeatSuppressed, skid,
      disposed: audio.disposed, contextState: audio.context.state, remainingSlots: audio.slots.size};
  });
  assert.equal(live.starterBlocked, true);
  assert.deepEqual(live.playing.map(slot => slot.event).sort(), ['cvrpmhm', 'cvrpmm', 'cvstatm']);
  assert.ok(live.playing.every(slot => slot.loop && slot.sourceRate === 22050 && slot.gain > 0));
  assert.equal(live.pauseDelta, 0);
  assert.equal(live.gearEffect, true);
  assert.equal(live.repeatSuppressed, true);
  assert.equal(live.skid.playing, true);
  assert.equal(live.skid.loop, true);
  assert.equal(live.skid.pitchPercent, 24);
  assert.ok(Math.abs(live.skid.playbackRate - 1.24) < .0001);
  assert.equal(live.skid.disabledPreservesVoice, true);
  assert.equal(live.skid.airborneStops, true);
  assert.equal(live.skid.controllerBlocksStart, true);
  assert.equal(live.contextState, 'closed');
  assert.equal(live.remainingSlots, 0);
  const offline = await page.evaluate(async () => {
    const {config, manifest, NativeRaceAudio} = window.audioTest;
    const context = new OfflineAudioContext(2, 48000, 48000);
    const audio = new NativeRaceAudio(config, manifest, {context});
    await audio.startEngine();
    audio.execute([{event: audio.engine.spec.start.event, op: 'stop'}]);
    audio.updateEngine({gear: 0, rpm: 4000});
    const rendered = await context.startRendering(), channels = [];
    for (let channel = 0; channel < rendered.numberOfChannels; channel++) {
      const samples = rendered.getChannelData(channel);
      channels.push({finite: samples.every(Number.isFinite),
        rms: Math.sqrt(samples.reduce((sum, value) => sum + value * value, 0) / samples.length),
        peak: samples.reduce((max, value) => Math.max(max, Math.abs(value)), 0)});
    }
    await audio.dispose();
    return {sampleRate: rendered.sampleRate, frames: rendered.length, channels};
  });
  assert.equal(offline.sampleRate, 48000);
  assert.ok(offline.channels.every(channel => channel.finite && channel.rms > .0001 && channel.peak < 1));
  await mkdir('evidence/audio', {recursive: true});
  await writeFile('evidence/audio/browser-engine.json', JSON.stringify({live, offline}, null, 2) + '\n');
  console.log('Original WebAudio: engine layers, gear effect, tyre loop and native gates, pause/resume/disposal, 48kHz offline signal passed.');
} finally {
  await browser.close();
}
