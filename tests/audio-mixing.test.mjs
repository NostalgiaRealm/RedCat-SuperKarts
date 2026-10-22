import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {getSoundSpec} from '../src/asset-animation.js';
import {nativeStaticSoundVolume,nativeAudioControllerChange,nativeAudioLoadSettings} from '../src/audio-mixing.js';
import {originalMusicGain} from '../src/game-audio.js';
const read = path => JSON.parse(fs.readFileSync(new URL(path, import.meta.url)));
const fixture = read('../evidence/native/audio-mixing-fixtures.json');
const config = read('../public/assets/config.json'), manifest = read('../public/assets/manifest.json');
test('all496 original records match native argument parsing, group order and effects source replacement', () => {
  const sounds = fixture.parsedFields.map(fields => ({fields}));
  assert.equal(getSoundSpec(config, manifest, 'CDT').file, 'audio/cdt.wav');
  for (const row of fixture.rows) assert.deepEqual(sounds.map(sound => nativeStaticSoundVolume(config, sound, row)),
    row.volumes, `${row.effectsEnabled}/${row.effectsPercent}`);
});
test('native effects enable/clear branches and music decibel conversion', () => {
  for (const row of fixture.gates)
    assert.deepEqual(nativeAudioControllerChange(row.enabled, row.requestedPercent), row.expected);
  for (const row of fixture.music)
    assert.equal(originalMusicGain(row.percent), row.percent === 0 ? 0 : 10 ** (row.hundredthDb / 2000));
});
test('original enabled zero-volume load repairs75, separate SFXVOLUME gates skid', () => {
  assert.deepEqual(nativeAudioLoadSettings(config, {effectsPercent: 0}),
    {musicPercent: 100,effectsPercent:75,effectsEnabled:true,soundEnabled:true,skidEnabled:true,controllerEnabled:true});
});
