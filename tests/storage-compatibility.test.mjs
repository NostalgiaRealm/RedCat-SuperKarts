import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import path from 'node:path';
import {readRaceSave,writeRaceSave,applyRaceResult,saveHighscore,unlockAllCountries,configWithRaceSave} from '../source/race-save.js';
import {readSettings,writeSettings,normalizeSettings,DEFAULT_BINDINGS,DEFAULT_DISPLAY_SETTINGS} from '../source/settings.js';
import {nativeAdventureConfiguration,beginNativeAdventureEvent,applyNativeAdventureResult,nativeAdventureProfilePatch,readNativeAdventureProfile} from '../source/simulation/native-adventure.js';
import {nativeRaceResultPatch,serializeNativeHighscore} from '../source/simulation/native-results.js';
import {APP_NAME,GAME_ORIGIN,userDataPath,launchURL} from '../electron/runtime.mjs';

const fixture=JSON.parse(readFileSync(new URL('./fixtures/legacy-storage-v1.json',import.meta.url)));
const config=JSON.parse(readFileSync(new URL('../public/assets/config.json',import.meta.url)));
function legacyStorage(){
  const values=new Map(Object.entries(fixture.storage).map(([key,value])=>[key,typeof value==='string'?value:JSON.stringify(value)]));
  const writes=[];
  return {values,writes,getItem:key=>values.get(key)??null,setItem(key,value){writes.push(key);values.set(key,String(value));}};
}

test('v0.9.0 race saves and settings load and save without migration or record loss',()=>{
  const storage=legacyStorage(),before=new Map(storage.values);
  const save=readRaceSave(storage),settings=readSettings(storage);
  // Features added after the fixture's save only receive their defaults.
  const added={surfaceShadows:true,smoothEngineLights:true,showFps:false};
  assert.deepEqual(save,fixture.storage['rcsk.race-save.v1']);
  assert.deepEqual(settings,{...fixture.storage['rcsk.settings.v1'],...added});
  assert.equal(writeRaceSave(save,storage),true);
  assert.equal(writeSettings(settings,storage),true);
  assert.deepEqual(storage.writes,['rcsk.race-save.v1','rcsk.settings.v1']);
  for(const [key,value]of before){
    if(key==='rcsk.settings.v1')assert.deepEqual(JSON.parse(storage.values.get(key)),{...JSON.parse(value),...added});
    else assert.equal(storage.values.get(key),value,key);
  }
  assert.deepEqual(readRaceSave(storage),save);
  assert.deepEqual(readSettings(storage),settings);
});

test('an existing Adventure profile continues and unlocks its country without touching other profiles',()=>{
  const storage=legacyStorage(),save=readRaceSave(storage),before=structuredClone(save);
  const options={...nativeAdventureConfiguration(config),locks:save.locks};
  const profile=save.profiles[save.selectedSlot];
  assert.deepEqual(beginNativeAdventureEvent(profile,options),{index:5,country:5,raceType:0,difficulty:2});
  const outcome=applyNativeAdventureResult(profile,{rank:0,finished:true,stars:0},options);
  assert.equal(outcome.advanced,true);
  assert.equal(outcome.unlockedCountry,4);
  assert.equal(profile.adventure,6);
  assert.equal(profile.matrix[5][0],1);
  assert.deepEqual(save.locks,[false,false,true,true,false,true]);
  assert.equal(writeRaceSave(save,storage),true);
  const restored=readRaceSave(storage);
  assert.deepEqual(restored,save);
  for(let slot=0;slot<30;slot++)if(slot!==14)assert.deepEqual(restored.profiles[slot],before.profiles[slot]);
  assert.deepEqual(restored.boards,before.boards);
  assert.deepEqual(restored.bestTimes,before.bestTimes);
  assert.equal(restored.selectedSlot,14);
  assert.deepEqual(beginNativeAdventureEvent(restored.profiles[14],options),{index:6,country:1,raceType:1,difficulty:2});
});

test('new race results extend legacy records while preserving saved scores and native serialization',()=>{
  const storage=legacyStorage(),save=readRaceSave(storage),before=structuredClone(save);
  const record={name:'Zoë & RedCat',character:1,totalRaceMs:90000,bestLapMs:15000,difficulty:2};
  const patch=nativeRaceResultPatch({finished:true,player:{...record,carIndex:1,rank:0,finishTimeMs:90000,stars:12,damage:0},
    opponents:[],trackIndex:5,bestLapRecordMs:15000,raceRecordMs:90000,timeCheckCount:2,timeChecks:[4000,8000]});
  applyRaceResult(save,patch);
  assert.equal(saveHighscore(save,5,record),0);
  assert.equal(writeRaceSave(save,storage),true);
  const restored=readRaceSave(storage);
  assert.deepEqual(restored.lastResult,patch);
  assert.deepEqual(restored.boards[5],[record,...before.boards[5].slice(0,4)]);
  assert.equal(serializeNativeHighscore(restored.boards[5][0]),'Zoë & RedCat,1,90000,15000,2');
  assert.equal(restored.quickRaceName,record.name);
  assert.equal(restored.bestTimes.lap_record_e5,15000);
  assert.equal(restored.bestTimes.time_check_e5_c1,8000);
  for(let country=0;country<5;country++)assert.deepEqual(restored.boards[country],before.boards[country]);
  assert.deepEqual(restored.profiles,before.profiles);
  const merged=configWithRaceSave(config,restored);
  assert.equal(merged['race.ini']['best times'].lap_record_e5,15000);
  assert.notEqual(config['race.ini']['best times'].lap_record_e5,15000);
  for(const profile of restored.profiles.filter(Boolean))
    assert.deepEqual(readNativeAdventureProfile(nativeAdventureProfilePatch(profile),{slot:profile.slot}),profile);
});

test('older partial settings retain explicit choices and receive missing feature defaults automatically',()=>{
  const storage=legacyStorage();
  storage.values.set('rcsk.settings.v1',JSON.stringify(fixture.olderSettings));
  const settings=readSettings(storage);
  for(const [key,value]of Object.entries(fixture.olderSettings))assert.deepEqual(settings[key],value,key);
  assert.equal(settings.msaaEnabled,false);
  assert.equal(settings.msaaSamples,4);
  assert.equal(settings.freeFlight,false);
  assert.equal(settings.surfaceShadows,true);
  assert.equal(settings.smoothEngineLights,true);
  assert.equal(settings.showFps,false);
  assert.equal(settings.controlType,0);
  assert.deepEqual(settings.display,DEFAULT_DISPLAY_SETTINGS);
  assert.equal(settings.bindings.bonus,'');
  assert.equal(writeSettings(settings,storage),true);
  assert.deepEqual(readSettings(storage),settings);
});

test('corrupt or inaccessible settings use fresh editable defaults instead of shared frozen children',()=>{
  for(const storage of [{getItem:()=>'{invalid'},{getItem(){throw Error('Blocked');}}]){
    const settings=readSettings(storage);
    assert.deepEqual(settings,normalizeSettings());
    assert.notEqual(settings.bindings,DEFAULT_BINDINGS);
    assert.notEqual(settings.display,DEFAULT_DISPLAY_SETTINGS);
    settings.bindings.accelerate='KeyQ';
    settings.display.particles=false;
    assert.equal(readSettings(storage).bindings.accelerate,'ArrowUp');
    assert.equal(readSettings(storage).display.particles,true);
  }
});

test('a blocked localStorage getter cannot escape persistence fallbacks or change unlock state',t=>{
  const descriptor=Object.getOwnPropertyDescriptor(globalThis,'localStorage');
  t.after(()=>{if(descriptor)Object.defineProperty(globalThis,'localStorage',descriptor);else delete globalThis.localStorage;});
  Object.defineProperty(globalThis,'localStorage',{configurable:true,get(){throw Error('SecurityError: storage disabled');}});
  assert.deepEqual(readSettings(),normalizeSettings());
  const save=readRaceSave();
  assert.equal(save.profiles.length,30);
  assert.equal(save.selectedSlot,-1);
  assert.equal(writeSettings(normalizeSettings()),false);
  assert.equal(writeRaceSave(save),false);
  const before=structuredClone(save);
  assert.equal(unlockAllCountries(save),false);
  assert.deepEqual(save,before);
  // An explicit storage adapter still works when the browser default is denied.
  const storage=legacyStorage();
  assert.deepEqual(readRaceSave(storage),fixture.storage['rcsk.race-save.v1']);
  assert.equal(writeSettings(readSettings(storage),storage),true);
});

test('desktop source and packaged launches keep the established origin and profile identity',()=>{
  assert.equal(APP_NAME,'RedCat SuperKarts');
  assert.equal(GAME_ORIGIN,'rcsk://game');
  assert.equal(new URL(launchURL([])).protocol,'rcsk:');
  assert.equal(new URL(launchURL(['--skip-intro'])).hostname,'game');
  for(const appData of ['/home/test/.config','/Users/test/Library/Application Support'])
    assert.equal(userDataPath(appData),path.join(appData,'RedCat SuperKarts'));
  const windows=path.join('C:','Users','test','AppData','Roaming');
  assert.equal(userDataPath(windows),path.join(windows,'RedCat SuperKarts'));
  assert.equal(userDataPath('/unused','/temporary/test-profile'),path.normalize('/temporary/test-profile'));
});
