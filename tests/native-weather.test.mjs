import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeRandom} from '../src/simulation/native-random.js';
import {NativeWeather, getNativeWeatherSpec} from '../src/simulation/native-weather.js';
const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/weather-fixtures.json', import.meta.url)));
const config = JSON.parse(fs.readFileSync(new URL('../public/assets/config.json', import.meta.url)));

function snapshot(weather) {
  return {paused: weather.paused, activeCount: weather.activeCount, acceleration: weather.acceleration,
    randomState: weather.random.state, particles: weather.particles};
}
test('original eight weather constructors and256 complete particle updates', () => {
  for (const trace of fixture.traces) {
    const random = new NativeRandom(trace.seed), weather = new NativeWeather({...trace, random});
    assert.deepEqual(snapshot(weather), trace.initial, `${trace.kind}/${trace.precision}/${trace.count} constructor`);
    for (const [index, frame] of trace.frames.entries()) {
      weather.paused = frame.input.paused;
      if (frame.input.fraction !== null) weather.setFraction(frame.input.fraction);
      weather.step(frame.input.deltaSeconds, frame.input.velocity);
      assert.deepEqual(snapshot(weather), frame.expected, `${trace.kind}/${trace.precision}/${trace.count} frame${index}`);
      if (frame.drawn !== null) assert.deepEqual(weather.capture(), frame.drawn, `${trace.kind}/${trace.precision}/${trace.count} draw${index}`);
    }
  }
});
test('shipped weather selects race type, retains disabled pools, and honors hardware/particles gate', () => {
  assert.equal(getNativeWeatherSpec(config, 0, 0), null);
  assert.equal(getNativeWeatherSpec(config, 2, 0).kind, 'rain');
  assert.equal(getNativeWeatherSpec(config, 0, 1).kind, 'snow');
  assert.equal(getNativeWeatherSpec(config, 1, 1).enabled, false);
  assert.equal(getNativeWeatherSpec(config, 0, 4).enabled, false);
  assert.equal(getNativeWeatherSpec(config, 0, 2).count, 400);
  assert.equal(getNativeWeatherSpec(config, 0, 2, {hardware: false}), null);
});
test('320 original rain and snow marker callbacks, including NPC and direction guards', () => {
  for (const row of fixture.triggers) {
    const weather = new NativeWeather({...row, enabled: false, random: new NativeRandom(1), percentages: [25,50,75,100]});
    weather.trigger(row.marker, row);
    assert.deepEqual({paused: weather.paused, activeCount: weather.activeCount,
      percentageIndex: weather.percentageIndex}, row.expected, JSON.stringify(row));
  }
});
