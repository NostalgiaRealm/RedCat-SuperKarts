import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceHud} from '../src/race-hud.js';
import {getHudStringSpec} from '../src/hud-text.js';
const config=JSON.parse(fs.readFileSync(new URL('../public/assets/config.json',import.meta.url)));
function fixture(){
  const hud=new RaceHud({getContext:()=>({})},config,{});
  for(const name of ['string_lap','string_laptime','string_bestlap','string_bonus'])
    hud.specs.set(name,getHudStringSpec(config,name));
  const race={events:[],elapsedMs:0,lapCount:0,lapLimit:5,lapTimerLimitMs:120000,
    lapStartMs:0,bestLapMs:0xfffffff,raceType:0};
  return {hud,race};
}
test('pre-render race notices advance this tick; post-render notices wait for capture',()=>{
  const {hud,race}=fixture();
  race.events.push({type:'last-lap'});hud.update(race,.02);
  assert.equal(hud.notifications.elapsedTotal,20);
  assert.equal(hud.text.string_special,'Laatste ronde!');
  hud.processEvents(race.events,.02);
  assert.equal(hud.notifications.queue.length,0,'same event cannot enqueue twice');
  hud.notify(2,0,{capture:true});hud.update({...race,events:[]},0);
  const expired={type:'time-expired'};hud.processEvents([expired],.02);
  assert.equal(hud.notifications.text,'Tijd is om!');
  assert.equal(hud.text.string_special,undefined,'post-render text remains hidden in captured frame');
  hud.update({...race,events:[]},.02);
  assert.equal(hud.text.string_special,'Tijd is om!');
  assert.ok(hud.specialOverride.rgba[3]>0);
});
test('pause and resume capture immediately without advancing frozen HUD clock',()=>{
  const {hud,race}=fixture();hud.update(race,0);
  hud.notify(5);hud.update(race,1);
  hud.notify(1,0,{capture:true});
  assert.equal(hud.text.string_special,'PAUZE');
  assert.equal(hud.notifications.elapsedTotal,0);
  hud.notify(2,0,{capture:true});
  assert.equal(hud.text.string_special,'Laatste ronde!');
  assert.equal(hud.notifications.elapsedTotal,1000);
});
test('player hit feedback is queued after rendering and captured once on the next tick',()=>{
  const {hud,race}=fixture();hud.update(race,0);
  const hit={type:'hit',racer:0,shooter:4};
  hud.processEvents([hit],.025,{playerIndex:4});
  assert.equal(hud.notifications.text,'Raak!');
  assert.equal(hud.notifications.duration,4000);
  assert.equal(hud.text.string_special,undefined);
  hud.update(race,.025);
  assert.equal(hud.text.string_special,'Raak!');
  assert.ok(hud.specialOverride.rgba[3]>0);
  hud.processEvents([hit],.025,{playerIndex:4});
  assert.equal(hud.notifications.queue.length,0);
});
test('ordinary timed gates do not create the legacy split-time notice',()=>{
  const {hud,race}=fixture();
  hud.update({...race,raceType:1,remainingMs:65000,events:[{type:'time-gate',index:1}]},.025);
  assert.equal(hud.text.string_countdown_value,'65:00');
  assert.equal(hud.text.string_special,undefined);
  hud.processEvents([{type:'native-notification',id:11}],.025);
  hud.update(race,.025);
  assert.equal(hud.text.string_special,'Controlepunt!');
});
test('event8 holds the prior rendered lap text until the callback after its native deadline',()=>{
  for(const raceType of [0,1,2,3]){
    const {hud,race}=fixture();Object.assign(race,{raceType,remainingMs:65000,elapsedMs:39950});
    hud.update(race,.025,{nowSeconds:100.95});
    assert.equal(hud.text.string_laptime_value,'00:39:95');
    Object.assign(race,{elapsedMs:40000,lapStartMs:40000,lapCount:1,events:[
      {type:'lap',lap:1,timeMs:40000},{type:'native-notification',id:8},
    ]});
    hud.update(race,.025,{nowSeconds:100.975});
    assert.equal(hud.text.string_laptime_value,'00:39:95','Do not insert the completed40000ms value');
    assert.equal(hud.lapDisplay.state.holdStampSeconds,100);
    hud.processEvents(race.events,.025,{nowSeconds:101.025,lapCount:1});
    assert.equal(hud.lapDisplay.state.holdStampSeconds,100,'The post-render pass must not restart the same hold');
    race.events=[];race.elapsedMs=42025;
    hud.update(race,.025,{nowSeconds:103});
    assert.equal(hud.lapDisplay.state.holdStampSeconds,-1);
    assert.equal(hud.text.string_laptime_value,'00:39:95','Deadline callback only clears the hold');
    race.elapsedMs=42050;hud.update(race,.025,{nowSeconds:103.025});
    assert.equal(hud.text.string_laptime_value,'00:02:05');
  }
});
test('lap holds follow native event8 including reverse crossings, not every lap-shaped event',()=>{
  const {hud,race}=fixture();race.elapsedMs=9000;
  hud.update(race,0,{nowSeconds:40});
  race.events=[{type:'native-notification',id:8}];
  hud.update(race,0,{nowSeconds:41});
  assert.equal(hud.lapDisplay.state.holdStampSeconds,-1,'No completed lap yet');
  Object.assign(race,{lapCount:1,lapStartMs:10000,elapsedMs:10000,events:[{type:'lap',timeMs:10000}]});
  hud.update(race,0,{nowSeconds:42});
  assert.equal(hud.text.string_laptime_value,'00:00:00','Only event8 starts the original hold');
  race.events=[{type:'native-notification',id:8}];race.elapsedMs=10025;
  hud.update(race,.025,{nowSeconds:42.975});
  assert.equal(hud.lapDisplay.state.holdStampSeconds,42);
  race.events=[{type:'native-notification',id:8}];race.elapsedMs=11000;
  hud.update(race,.025,{nowSeconds:44.1});
  assert.equal(hud.lapDisplay.state.holdStampSeconds,44,'A new qualifying reverse crossing restarts the hold');
  assert.equal(hud.text.string_laptime_value,'00:00:00');
});
