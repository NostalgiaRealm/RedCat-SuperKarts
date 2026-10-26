import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeMenuFirstTime,nativeMainMenuGreeting} from '../source/menu-sound-events.js';

const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/menu-greeting-fixtures.json',import.meta.url)));
const config=JSON.parse(fs.readFileSync(new URL('../public/assets/config.json',import.meta.url)));
const configured=(phase,initial)=>({'ini/settings.ini':{firsttime:
  initial===null?{}:{[phase.toLowerCase()]:String(initial)}}});

test('60 original main FormShow calls preserve FIRSTTIME state, low byte and unchanged RNG',()=>{
  for(const row of fixture.main){
    const first=nativeMenuFirstTime(configured('PHASE_MAIN',row.initial),'PHASE_MAIN',row.visit>0);
    assert.equal(first,Boolean(row.firstTimeByte));
    assert.deepEqual(row.events,[
      {operation:'read',section:'FIRSTTIME',key:'PHASE_MAIN',default:1,
        value:row.visit>0?0:row.initial??1},
      {operation:'write',section:'FIRSTTIME',key:'PHASE_MAIN',value:0},
      {operation:'genericSound',sample:nativeMainMenuGreeting(first)},
    ]);
    assert.equal(row.stored,0);assert.equal(row.nextSeed,row.seed);
  }
});

test('18 original shared FIRSTTIME calls preserve later entry and authored form flags',()=>{
  for(const row of fixture.firstTime)
    assert.equal(nativeMenuFirstTime(configured(row.phase,row.initial),row.phase,row.visit>0),
      Boolean(row.result));
  for(const phase of ['PHASE_MAIN','PHASE_SELECTCHAR','PHASE_SELECTCOUNTRY','PHASE_ADVENT_MAIN'])
    assert.equal(nativeMenuFirstTime(config,phase),false);
  const sample=nativeMainMenuGreeting(nativeMenuFirstTime(config,'PHASE_MAIN'));
  assert.equal(config['ini/soundset.dat'].generic_samples[sample].toLowerCase(),'mn_hm02.wav');
});
