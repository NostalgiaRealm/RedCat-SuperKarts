import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceHud} from '../source/race-hud.js';
import {getHudStringSpec,getRaceHudText} from '../source/hud-text.js';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
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

test('440d70 pauses lap timer0 at the finish, so the results-phase HUD lap time stays frozen',()=>{
  const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
  const sim=new RaceSimulation({config,manifest:JSON.parse(read('manifest.json')),cars:JSON.parse(read('cars.json')),
    track:JSON.parse(read('tracks/etappe0.json')),random:new NativeRandom(0),
    physicsBytes:read('physics/phys1.dat'),racerBytes:read('racer-tables/cars1.dat')});
  const {hud}=fixture(),race=sim.race,input={throttle:1,brake:0,steer:0,handbrake:0,bonus:0};
  let now=0;const step=()=>{now+=25;sim.step(input,.025,now);hud.update(race,.025,{nowSeconds:now/1000});};
  for(let i=0;i<40;i++)step();
  assert.equal(race.lapTimerMs,1000);
  // Cross finish marker14 on the last lap through the real event wiring.
  race.lapCount=race.lapLimit-1;race.finishArmed=true;
  const begin=race.beginUpdate.bind(race);
  race.beginUpdate=(...args)=>{const snapshot=begin(...args);race.beginUpdate=begin;race.trigger(14,{previous:0,current:1});return snapshot;};
  step();
  assert.equal(race.finished,true);assert.equal(race.phase,3);
  for(let i=0;i<160;i++)step();
  assert.equal(race.phase,3);
  assert.equal(race.elapsedMs-race.lapStartMs,4000,'race timer3 keeps the port countdown domain');
  assert.equal(race.lapTimerMs,0);
  // 42f9c0 refuses P/Escape in phase3, so only a browser host suspension
  // (focus loss, menu) can pause here; it must not end 440d70's pause.
  sim.pause(now);now+=1000;sim.resume(now);
  for(let i=0;i<40;i++)step();
  assert.equal(sim.lifecycle.running,true,'still inside the results phase');
  assert.equal(race.lapTimerMs,0);
  const frozen=getRaceHudText({lapCounter:race.lapCount,totalLaps:race.lapLimit,lapTimeMs:0,bestLapTimeMs:race.bestLapMs});
  assert.equal(hud.text.string_laptime_value,frozen.string_laptime_value);
});

test('unstarted timer0 shows 00:00:00 through start camera, countdown and a phase1 P pause',()=>{
  // 42a670 leaves timer0 unstarted (start -1); 42a4d0 then reads 0 and 46ecc0
  // formats it via 46f5f0 with no zero special case. 42f9c0 permits P in
  // phase1; 42a420 only clears an unstarted timer's pause. 42f980 starts it.
  const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
  const sim=new RaceSimulation({config,manifest:JSON.parse(read('manifest.json')),cars:JSON.parse(read('cars.json')),
    track:JSON.parse(read('tracks/etappe0.json')),random:new NativeRandom(0),countdown:true,
    physicsBytes:read('physics/phys1.dat'),racerBytes:read('racer-tables/cars1.dat')});
  const {hud}=fixture(),race=sim.race,input={throttle:0,brake:0,steer:0,handbrake:0,bonus:0};
  hud.update(race,0,{nowSeconds:0});
  assert.equal(hud.text.string_laptime_value,'00:00:00','first overlay update');
  let now=0,paused=false;
  const step=()=>{now+=25;sim.step(input,.025,now);hud.update(race,.025,{nowSeconds:sim.engineMs/1000});};
  assert.ok(sim.startCamera);
  for(let i=0;i<2000&&race.phase!==0;i++){
    step();
    assert.equal(hud.text.string_laptime_value,'00:00:00',`phase${race.phase} at ${now} ms`);
    if(!paused&&sim.countdownStarted){
      paused=true;sim.pause(now,{native:true});now+=5000;sim.resume(now);
      assert.equal(sim.timers.get(0).startMs,0xffffffff);
      assert.equal(sim.timers.get(0).pausedAtMs,0);
    }
  }
  assert.ok(paused);assert.equal(race.phase,0);
  assert.equal(sim.timers.get(0).startMs,now,'42f980 starts timer0 at green');
  for(let i=0;i<40;i++)step();
  assert.equal(hud.text.string_laptime_value,'00:01:00');
});
