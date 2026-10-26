import test from 'node:test';
import assert from 'node:assert/strict';
import {readRaceSave,writeRaceSave,applyRaceResult,saveHighscore,configWithRaceSave,unlockAllCountries} from '../source/race-save.js';
import {createNativeAdventureProfile} from '../source/simulation/native-adventure.js';

test('race saves preserve original result/highscore records and separate original configuration',()=>{
  const storage={value:null,getItem(){return this.value;},setItem(key,value){this.value=value;}};
  const save=readRaceSave(storage);
  applyRaceResult(save,{PLAYER:{finished:1,tracktime:40000},'BEST TIMES':{LAP_RECORD_E0:8000}});
  saveHighscore(save,0,{name:'Test',character:1,totalRaceMs:40000,bestLapMs:8000,difficulty:2});
  save.profiles[3]=createNativeAdventureProfile('Speler',{slot:3});
  save.selectedSlot=3;save.locks=[false,false,true,true,false,true];
  assert.equal(writeRaceSave(save,storage),true);
  assert.deepEqual(readRaceSave(storage),save);
  const original={'race.ini':{'best times':{lap_record_e1:10000}}};
  const config=configWithRaceSave(original,save);
  assert.deepEqual(config['race.ini']['best times'],{lap_record_e1:10000,lap_record_e0:8000});
  assert.deepEqual(original['race.ini']['best times'],{lap_record_e1:10000});
});

test('malformed storage cannot create invalid profiles, score rows or record fields',()=>{
  const storage={getItem:()=>JSON.stringify({selectedSlot:200,profiles:[{name:'bad',matrix:[]}],
    bestTimes:{lap_record_e0:-1,arbitrary:1},boards:[Array(5).fill({name:'bad',bestLapMs:NaN})]})};
  const save=readRaceSave(storage);
  assert.equal(save.selectedSlot,-1);assert.ok(save.profiles.every(p=>p===null));
  assert.deepEqual(save.bestTimes,{});assert.ok(save.boards[0].every(row=>row.bestLapMs===0));
  assert.equal(writeRaceSave(save,{setItem(){throw Error('Storage full');}}),false);
});

test('unlock cheat persists all six countries without changing records or adventure progress',()=>{
  const storage={value:null,getItem(){return this.value;},setItem(key,value){this.value=value;}};
  const save=readRaceSave(storage);
  save.profiles[3]=createNativeAdventureProfile('Bewaren',{slot:3});save.profiles[3].matrix[2][1]=1;
  save.selectedSlot=3;save.locks=[false,true,true,true,true,true];
  saveHighscore(save,2,{name:'Beste',character:2,totalRaceMs:123456,bestLapMs:23456,difficulty:2});
  applyRaceResult(save,{PLAYER:{finished:1,tracktime:123456},'BEST TIMES':{LAP_RECORD_E2:23456}});
  const expected={...structuredClone(save),locks:Array(6).fill(false)};
  assert.equal(unlockAllCountries(save,storage),true);
  assert.deepEqual(save,expected);assert.deepEqual(readRaceSave(storage),expected);
  assert.equal(unlockAllCountries(save,storage),true);assert.deepEqual(save,expected);
});

test('unlock storage failure leaves the current locks and progress intact',()=>{
  const save=readRaceSave({getItem:()=>null});save.locks=[false,true,true,true,true,true];
  const previous=structuredClone(save);
  assert.equal(unlockAllCountries(save,{setItem(){throw Error('Storage unavailable');}}),false);
  assert.deepEqual(save,previous);
});
