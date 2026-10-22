import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {getNativeEngineAudioSpec, createNativeEngineAudio, startNativeEngineAudio,
  updateNativeEngineAudio, stopNativeEngineAudio, nativeSoundVolume, nativeSoundFrequency,
  nativeWavSampleRate} from '../src/engine-audio.js';

const load = file => JSON.parse(fs.readFileSync(new URL(`../${file}`, import.meta.url)));
const fixture = load('evidence/native/engine-audio-fixtures.json');
const startFixture = load('evidence/native/engine-start-fixtures.json');
const config = load('public/assets/config.json'), manifest = load('public/assets/manifest.json');
const spec = getNativeEngineAudioSpec(config, manifest);
const comparable = state => ({active: state.active, gear: state.gear, minimumRpm: state.minimumRpm});

test('engine remains silent until original post-pan countdown START action', () => {
  for (const row of startFixture.cases) {
    const state = createNativeEngineAudio(spec, row);
    for (const frame of row.inactiveFrames) {
      assert.deepEqual(updateNativeEngineAudio(state, frame.input), frame.commands);
      assert.deepEqual(comparable(state), frame.state);
    }
    assert.deepEqual(startNativeEngineAudio(state), row.commands);
    assert.deepEqual(comparable(state), row.stateAfter);
    assert.deepEqual(row.serviceOrder, [
      {service: 'sound', event: spec.start.event, loop: false},
      {service: 'countdown', action: 0}
    ]);
    assert.equal(row.actionAfter, row.previousAction === -1 ? -1 : 1);
  }
});

test('360 original engine updates preserve starter gate, three layers, gear memory, pitch and volume', () => {
  for (const trace of fixture.traces) {
    const state = createNativeEngineAudio(spec, trace);
    assert.deepEqual(startNativeEngineAudio(state), trace.start);
    for (const [index, frame] of trace.frames.entries()) {
      assert.deepEqual(updateNativeEngineAudio(state, frame.input), frame.commands, `PC${trace.precision} frame${index}`);
      assert.deepEqual(comparable(state), frame.state);
    }
    assert.deepEqual(stopNativeEngineAudio(state), trace.stop);
    assert.deepEqual(comparable(state), trace.stateAfterStop);
  }
});

test('101 native volume conversions retain DirectSound logarithmic attenuation', () => {
  for (const row of fixture.volumes) assert.equal(nativeSoundVolume(row.percent).hundredthDb, row.hundredthDb);
  assert.equal(nativeSoundVolume(100).gain, 10 ** (-100 / 2000));
  assert.equal(nativeSoundVolume(50, 60).percent, 30);
  assert.equal(nativeSoundVolume(0).gain, .01);
});

test('all five original engine WAVs preserve original rate despite browser resampling', () => {
  const sounds = [spec.start, spec.switchGear, ...spec.layers.map(layer => layer.sound)];
  assert.equal(new Set(sounds.map(sound => sound.file)).size, 5);
  assert.deepEqual(spec.cylinderSamples, []);
  for (const sound of sounds) {
    const bytes = fs.readFileSync(new URL(`../public/assets/${sound.file}`, import.meta.url));
    const rate = nativeWavSampleRate(bytes.buffer.slice(bytes.byteOffset, bytes.byteOffset + bytes.byteLength));
    assert.ok(rate >= 8000 && rate <= 48000);
    for (const percent of [0, 60, 103, 270]) {
      const actual = nativeSoundFrequency(rate, percent);
      assert.equal(actual.frequency, Math.min(100000, rate + Math.trunc(rate * percent / 100)));
      assert.equal(actual.playbackRate, actual.frequency / rate);
    }
  }
});
