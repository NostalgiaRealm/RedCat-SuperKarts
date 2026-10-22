import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {createHash} from 'node:crypto';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS} from '../src/simulation/clock.js';
import {nativeCrossedTriggers} from '../src/simulation/native-race.js';
import {nativeProjectileFacing} from '../src/simulation/native-projectile.js';
import {RouteTestDriver} from './helpers/private-projected-line-driver.mjs';
import {createPrivateRaceSnapshotter} from './helpers/private-race-snapshot.mjs';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json')),
  cars=JSON.parse(read('cars.json')),track=JSON.parse(read('tracks/etappe3.json'));
const inputs={config,manifest,cars,track,physicsBytes:read('physics/phys2.dat'),
  racerBytes:read('racer-tables/cars2.dat'),character:1,difficulty:2,raceMode:1,countdown:true};
const assetDigest=()=>createHash('sha256').update(JSON.stringify([config,manifest,cars,track])).digest('hex');
function fresh(){
  const random=new NativeRandom(0),simulation=new RaceSimulation({...inputs,random});random.seed(6);
  return {simulation,filter:new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS})};
}
function advance(state,input,now){
  const events=state.simulation.step(input,state.filter.sample(.025),now);
  for(const actor of state.simulation.actors)if(actor.animationEvents)actor.animationEvents.length=0;
  return events;
}
function observer(sim,callback){const native=sim.onPlayerCollision;sim.onPlayerCollision=contact=>{callback(contact);native(contact);};}
const snapshotter=createPrivateRaceSnapshotter({constructorOptions:{...inputs,random:new NativeRandom(0)},
  permittedObservers:['onPlayerCollision']});

test('fresh timed clone keeps constructor closures, accessor bodies, aliases and known camera hints',()=>{
  const source=fresh();advance(source,{throttle:1,steer:0},25);
  source.simulation.cameraSectors.set(source.simulation.playerCamera,37);
  const clone=snapshotter.clone(source.simulation,{filter:source.filter});
  assert.deepEqual(snapshotter.capture(clone.simulation,{filter:clone.filter}),snapshotter.capture(source.simulation,{filter:source.filter}));
  assert.ok(snapshotter.assertIsolated(source.simulation,clone.simulation));
  assert.notEqual(clone.simulation.motion.sampleGround,source.simulation.motion.sampleGround);
  assert.notEqual(clone.simulation.motion.body.onCollision,source.simulation.motion.body.onCollision);
  assert.notEqual(clone.simulation.squash.entries[0].rebuildMatrix,source.simulation.squash.entries[0].rebuildMatrix);
  assert.deepEqual(clone.simulation.rescue.occupants(),[clone.simulation.motion.body,...clone.simulation.opponents.map(x=>x.body)]);
  assert.equal(clone.simulation.cameraSectors.get(clone.simulation.playerCamera),37);
  const oldX=source.simulation.motion.body.x;
  clone.simulation.motion.body.x+=1;
  assert.equal(clone.simulation.motion.body.position[0],oldX+1);
  assert.equal(source.simulation.motion.body.x,oldX);
  assert.equal(clone.simulation.opponents[0].random,clone.simulation.voices.random);
  assert.equal(clone.simulation.scenery.collision.contactState,clone.simulation.contactState);
  assert.equal(clone.simulation.rescue.playerSafety.body,clone.simulation.motion.body);
});

test('unknown hooks, partial frames, unsupported bonuses/terminal states fail closed; permitted observer retains native crash RNG',()=>{
  const source=fresh(),plain=createPrivateRaceSnapshotter({constructorOptions:inputs});
  const original=source.simulation.onPlayerCollision;let observerCalls=0;
  observer(source.simulation,()=>observerCalls++);
  assert.throws(()=>plain.clone(source.simulation),/function override/);
  const clone=snapshotter.clone(source.simulation).simulation;
  const before=snapshotter.fingerprint(source.simulation);
  const contact={impulse:26000,contactType:1,nowMs:61000};
  const reference=fresh().simulation;
  clone.onPlayerCollision(contact);reference.onPlayerCollision(contact);
  assert.equal(observerCalls,0);
  assert.equal(clone.crashAudio.random.state,reference.crashAudio.random.state);
  assert.equal(clone.crashAudio.lastTimeMs,reference.crashAudio.lastTimeMs);
  assert.equal(snapshotter.fingerprint(source.simulation),before);
  source.simulation.unrecognized=()=>{};
  assert.throws(()=>snapshotter.clone(source.simulation),/unsupported function/);delete source.simulation.unrecognized;
  source.simulation.motion.sampleGround=()=>0;
  assert.throws(()=>snapshotter.clone(source.simulation),/sampleGround/);
  source.simulation.onPlayerCollision=original;
  const partial=fresh().simulation;partial.motion.prepare({},.025);
  assert.throws(()=>snapshotter.clone(partial),/completed/);
  const bonus=fresh().simulation;bonus.pickups.owned[0].state=2;
  assert.throws(()=>snapshotter.clone(bonus),/bonus/);
  const terminal=fresh().simulation;terminal.race.phase=6;
  assert.throws(()=>snapshotter.clone(terminal),/terminal/);
});

test('graph fingerprint preserves special numeric values and alias topology',()=>{
  const state=fresh().simulation,values=[NaN,Infinity,-Infinity,-0,undefined,null,0];
  const hashes=values.map(value=>{state.snapshotDiagnostic=value;return snapshotter.fingerprint(state);});
  assert.equal(new Set(hashes).size,values.length);
  const shared={value:1};state.snapshotDiagnostic=[shared,shared];const aliased=snapshotter.fingerprint(state);
  state.snapshotDiagnostic=[{value:1},{value:1}];assert.notEqual(snapshotter.fingerprint(state),aliased);
});

test('three ordinary-input France boundaries match independent races for 80 frames, including contacts, train and jumps',t=>{
  const beforeAssets=assetDigest(),source=fresh(),reference=fresh(),trace=[];
  const driver=new RouteTestDriver(track,{speed:170,lookAheadSeconds:1.05,steeringGain:3,dampingGain:.6,
    railBounds:source.simulation.motion.collision.bounds,
    obstacles:source.simulation.physicalBodies.filter(body=>body!==source.simulation.motion.body)});
  driver.configureRacingLine(1000);driver.testCollision=driver.starPlanner=driver.narrowStarPlanner=null;
  let activeClone=null,remaining=0,contacts=0,jumps=0,trainTicks=0,windows=0,green=null;
  const selected=new Set();let clonedJumpCount=0,clonedContactCount=0;
  observer(source.simulation,()=>contacts++);
  for(let now=25;now<=36500;now+=25){
    const input=source.simulation.movementActive?driver.input(source.simulation.motion.body,now,25):
      {throttle:1,brake:0,steer:0,handbrake:0,bonus:0,analog:{throttle:1,brake:0,steer:0}};
    if(source.simulation.motion.mirrored){input.steer=-input.steer;input.analog.steer=-input.analog.steer;}
    const body=source.simulation.motion.body;
    const jump=nativeCrossedTriggers(track,body.previousSector,body.sector).some(marker=>
      [49,52].includes(marker)&&track.drive[body.waypoint]?.unknown[1]===marker&&
      (marker===49)===nativeProjectileFacing(track,body,source.simulation.routeOptions));
    const contactsBefore=contacts;
    advance(source,input,now);advance(reference,input,now);
    if(green===null&&source.simulation.movementActive)green=now;
    if(jump)jumps++;
    if(source.simulation.sceneryPaths.slots.some(slot=>slot?.active))trainTicks++;
    if(activeClone){
      if(jump)clonedJumpCount++;
      clonedContactCount+=contacts-contactsBefore;
      const untouched=snapshotter.fingerprint(source.simulation,{filter:source.filter});
      advance(activeClone,input,now);
      assert.equal(snapshotter.fingerprint(source.simulation,{filter:source.filter}),untouched,`live mutation at ${now}`);
      assert.deepEqual(snapshotter.capture(activeClone.simulation,{filter:activeClone.filter}),
        snapshotter.capture(reference.simulation,{filter:reference.filter}),`recurrence at ${now}`);
      assert.equal(activeClone.simulation.pickups.random.state,reference.simulation.pickups.random.state);
      if(--remaining===0){assert.ok(snapshotter.assertIsolated(source.simulation,activeClone.simulation));activeClone=null;windows++;}
    }
    const reason=now===8375?'contacts':
      !activeClone&&!selected.has('path')&&source.simulation.sceneryPaths.slots.some(slot=>
        slot?.active&&slot.path.placementIndex===105)?'path':
      !activeClone&&[100,101,102].includes(source.simulation.motion.body.sector)&&!selected.has('jump')?'jump':null;
    if(reason&&!selected.has(reason)){
      assert.deepEqual(snapshotter.capture(source.simulation,{filter:source.filter}),
        snapshotter.capture(reference.simulation,{filter:reference.filter}),`independent prefix at ${now}`);
      activeClone=snapshotter.clone(source.simulation,{filter:source.filter});remaining=80;
      selected.add(reason);
      assert.ok(snapshotter.assertIsolated(source.simulation,activeClone.simulation));
      trace.push({reason,now,sector:source.simulation.motion.body.sector,cloudOrder:source.simulation.smoke.clouds.map(x=>x.id),
        activePaths:source.simulation.sceneryPaths.slots.filter(Boolean).length,
        activePlacements:source.simulation.sceneryPaths.slots.filter(Boolean).map(slot=>slot.path.placementIndex)});
    }
  }
  assert.equal(green,7475);assert.equal(windows,3,JSON.stringify(trace));assert.ok(contacts>0);assert.ok(trainTicks>0);
  assert.ok(jumps>0,'natural jump callback conditions occurred');
  assert.ok(clonedJumpCount>0,'jump callback occurred inside recurrence window');
  assert.ok(clonedContactCount>0,'native contact callback occurred inside recurrence window');
  assert.ok(trace.some(item=>item.activePlacements.includes(105)),'original frtr0000_ANIM train path state copied');
  assert.equal(assetDigest(),beforeAssets,'shared immutable asset bytes changed');
  t.diagnostic(JSON.stringify({scope:'Bounded ordinary-input recurrence, not a full race',framesPerWindow:80,
    windows:trace.map(({cloudOrder,...row})=>({...row,cloudOrderChanged:cloudOrder.some((id,index)=>id!==index)})),
    contactCallbacksInsideWindows:clonedContactCount,jumpCallbacksInsideWindows:clonedJumpCount,greenWallMs:green}));
});

test('A→B→A evaluation is repeatable, keeps ordered occupancy/clouds and never calls a source observer',()=>{
  const source=fresh();let calls=0;observer(source.simulation,()=>calls++);
  for(let now=25;now<=8000;now+=25)advance(source,{throttle:1,steer:0,analog:{throttle:1,brake:0,steer:0}},now);
  const before=snapshotter.fingerprint(source.simulation,{filter:source.filter}),beforeCalls=calls;
  function forecast(steer){
    const copy=snapshotter.clone(source.simulation,{filter:source.filter});
    for(let i=1;i<=80;i++)advance(copy,{throttle:1,steer,analog:{throttle:1,brake:0,steer}},8000+i*25);
    assert.ok(snapshotter.assertIsolated(source.simulation,copy.simulation));
    return snapshotter.fingerprint(copy.simulation,{filter:copy.filter});
  }
  const a=forecast(-.25),b=forecast(.25),aAgain=forecast(-.25);
  assert.equal(a,aAgain);assert.notEqual(a,b);
  assert.equal(snapshotter.fingerprint(source.simulation,{filter:source.filter}),before);
  assert.equal(calls,beforeCalls);
});

test('recorded constructor seed is separate from an already reseeded live RNG',()=>{
  const state=fresh(),liveRandom=state.simulation.pickups.random;
  const factory=createPrivateRaceSnapshotter({constructorOptions:{...inputs,random:liveRandom},constructionSeed:0});
  const before=liveRandom.state,copy=factory.clone(state.simulation,{filter:state.filter});
  assert.equal(liveRandom.state,before);
  assert.notEqual(copy.simulation.pickups.random,liveRandom);
  assert.equal(copy.simulation.pickups.random.state,before);
  assert.deepEqual(factory.capture(copy.simulation,{filter:copy.filter}),factory.capture(state.simulation,{filter:state.filter}));
  assert.throws(()=>createPrivateRaceSnapshotter({constructorOptions:inputs,constructionSeed:-1}),/constructionSeed/);
});

test('synthetic service fixture preserves active rescue driver/body references and squash clocks for 80 frames',()=>{
  const source=fresh(),reference=fresh(),input={throttle:1,steer:0,analog:{throttle:1,brake:0,steer:0}};
  for(const state of [source,reference]){
    for(let now=25;now<=8000;now+=25)advance(state,input,now);
    // Explicit service-level setup, not an ordinary-input or native trigger claim.
    state.simulation.rescue.enqueue(state.simulation.opponents[0]);
    state.simulation.squash.trigger(state.simulation.motion.body,state.simulation.nativeTickMs);
    for(let now=8025;now<=8125;now+=25)advance(state,input,now);
  }
  const clone=snapshotter.clone(source.simulation,{filter:source.filter}),entry=clone.simulation.rescue.entries[0];
  assert.equal(entry.driver,clone.simulation.opponents[0]);
  assert.equal(entry.body,clone.simulation.opponents[0].body);
  assert.notEqual(entry,source.simulation.rescue.entries[0]);
  assert.ok(entry.frame>0);
  const before=snapshotter.fingerprint(source.simulation,{filter:source.filter});
  let relocated=false;
  for(let i=1;i<=80;i++){
    advance(reference,input,8125+i*25);advance(clone,input,8125+i*25);
    relocated ||= clone.simulation.rescue.entries.some(item=>item.relocated);
    assert.deepEqual(snapshotter.capture(clone.simulation,{filter:clone.filter}),
      snapshotter.capture(reference.simulation,{filter:reference.filter}));
  }
  assert.ok(relocated,'fixture exercises destination resolver and captured fresh occupants');
  assert.ok(snapshotter.assertIsolated(source.simulation,clone.simulation));
  assert.equal(snapshotter.fingerprint(source.simulation,{filter:source.filter}),before);
});
