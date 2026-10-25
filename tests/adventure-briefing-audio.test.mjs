import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {nativeAdventureBriefingSound} from '../src/menu-sound-events.js';

const read=async path=>JSON.parse(await readFile(new URL(path,import.meta.url)));
const fixture=await read('../evidence/native/adventure-briefing-audio-fixtures.json');
const config=await read('../public/assets/config.json');
const manifest=await read('../public/assets/manifest.json');

test('all72 original country/event/difficulty lookups select the shipped briefing recordings',()=>{
  assert.equal(fixture.selection.length,72);
  const recordings=new Set();
  for(const row of fixture.selection){
    const sample=nativeAdventureBriefingSound(row.country,row.raceType);
    assert.deepEqual({operation:'genericSound',sample,wait:false},row.expected);
    const file=config['ini/soundset.dat'].generic_samples[sample];
    assert.equal(file,row.sampleFile);assert.ok(manifest.audio[file.toLowerCase()],file);
    recordings.add(file);
  }
  assert.equal(recordings.size,24);
});

test('the original unused fifth event aliases normal race; invalid lookups fail',()=>{
  for(let country=0;country<6;country++)
    assert.equal(nativeAdventureBriefingSound(country,4),fixture.byteTable[country*5+4]);
  for(const [country,type]of [[-1,0],[6,0],[.5,0],[0,-1],[0,5],[0,NaN]])
    assert.throws(()=>nativeAdventureBriefingSound(country,type),RangeError);
});
