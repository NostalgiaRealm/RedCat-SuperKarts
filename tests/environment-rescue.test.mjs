import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeEnvironmentRescueRequired,nativeEnvironmentRescueWaypoint,
  createNativeRescue,updateNativeRescue,nativeRescueNearestSector,
  nativeRescueDestination} from '../source/simulation/native-rescue.js';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {selectNativeSector} from '../source/simulation/native-track.js';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/regressions/environment-rescue-fixtures.json',import.meta.url)));
const tracks=Array.from({length:6},(_,i)=>JSON.parse(read(`tracks/etappe${i}.json`)));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json')),cars=JSON.parse(read('cars.json'));
const identity=[1,0,0,0,1,0,0,0,1];
const create=()=>new RaceSimulation({config,manifest,cars,track:tracks[0],random:new NativeRandom(0),
  physicsBytes:read('physics/phys1.dat'),racerBytes:read('racer-tables/cars1.dat')});

test('144 original danger-zone checks use marker50 and strict selected route-plane height',()=>{
  for(const item of fixture.gates){
    const track={drive:[{unknown:[0,item.marker]}]};
    const world={sectors:[1,-1].map(offset=>({
      position:[item.position[0]+offset,0,0],side:[0,0,1],fallback:item.plane}))};
    const body={position:item.position,sector:0,waypoint:0};
    assert.equal(nativeEnvironmentRescueRequired(track,world,body,item),item.calls.length>0,JSON.stringify(item));
    if(item.calls.length)assert.deepEqual(item.calls,[[0,1]]);
  }
});

test('312 original return-marker searches cover every authored danger/return node and both directions',()=>{
  for(const item of fixture.markers)
    assert.equal(nativeEnvironmentRescueWaypoint(tracks[item.track],item.start,item.direction),
      item.expected,JSON.stringify(item));
  assert.equal(nativeEnvironmentRescueWaypoint(tracks[0],453),441);
});

test('original environment relocation preserves blocked retry and no-marker grow behavior',()=>{
  for(const item of fixture.relocations){
    const body={position:[5,6,7],matrix:[...identity],forwardSpeed:4,lateralSpeed:8,verticalSpeed:12};
    const entry=createNativeRescue(body,null,{environment:true});
    Object.assign(entry,{shrinking:false,frame:0});
    updateNativeRescue(entry,.025,{precision:item.precision,effectsEnabled:false,
      resolveDestination:()=>item.marker<0?null:!item.free?{blocked:true}:{position:[100,25,300],sector:0,yaw:0}});
    assert.equal(entry.environment,item.environment);
    assert.deepEqual(body.position,item.position);
    assert.equal(entry.scale,item.scale);
    assert.equal(entry.frame,item.frame);
    assert.equal(entry.shrinking,item.shrinking);
    assert.equal(entry.relocated,item.marker>=0&&item.free);
  }
});

function placeAboveMoat(sim,actor){
  const body=actor.body;
  body.position.splice(0,3,...tracks[0].drive[453].position);
  body.position[1]=35;
  body.sector=selectNativeSector(sim.world,nativeRescueNearestSector(tracks[0],body.position),body.x,body.z);
  body.previousSector=body.sector;
  sim.occupancy.remove(body);sim.occupancy.insert(body);
  return body;
}

test('falling into Nederland moat automatically shrinks, voices, returns to marker441 and grows',()=>{
  const sim=create(),body=placeAboveMoat(sim,sim.motion),voices=[],frames=[];
  sim.race.previousSector=body.sector;
  sim.onVoiceRequest=request=>voices.push(request);
  const input={throttle:0,brake:0,steer:0,handbrake:0,bonus:0};
  let first=null,finished=null,relocated=null,relocationProgress=null;
  for(let tick=1;tick<=90;tick++){
    sim.step(input,.025,tick*25,{beforePlayerPrepare:()=>{
      if(relocated&&tick===relocated.tick+1){
        relocationProgress={distance:sim.race.distance,rankDistance:sim.rankStates.at(-1).distance,
          events:[...sim.race.events]};
      }
    },beforeBonuses:()=>{
      const entry=sim.rescue.get(body);
      if(!entry)return;
      first??=tick;frames.push(entry.scale);
      if(entry.relocated)relocated={tick,waypoint:entry.destination.waypoint,position:[...body.position],
        distance:sim.race.distance,sector:body.sector,previousSector:body.previousSector,
        oldObservedSector:sim.race.previousSector};
      if(entry.finished)finished={tick,speed:body.forwardSpeed};
    }});
  }
  assert.ok(first>1,'normal falling motion reaches the height threshold');
  assert.equal(frames.length,40);assert.equal(finished.tick-first,39);
  assert.equal(Math.min(...frames),Math.fround(.1));
  assert.equal(relocated.waypoint,441);
  assert.notEqual(relocated.oldObservedSector,relocated.sector,'the authored return actually relocates to another sector');
  assert.equal(relocated.previousSector,80,'native430ff0 records the nearest destination sector first');
  assert.equal(relocated.sector,79,'native ground selection then selects the adjacent destination sector');
  assert.equal(relocationProgress.distance,relocated.distance-1,'only the local destination-sector adjustment counts');
  assert.equal(relocationProgress.rankDistance,relocated.distance-1,'rank feed uses the same engine history');
  assert.deepEqual(relocationProgress.events,[],'relocation does not dispatch an unrelated crossed marker');
  assert.deepEqual(relocated.position,[tracks[0].drive[441].position[0],20,tracks[0].drive[441].position[2]]);
  assert.equal(finished.speed,5);
  assert.deepEqual(voices.filter(x=>['DISAPP','REAPP'].includes(x.sample)).map(x=>x.sample),['DISAPP','REAPP']);
  assert.equal(sim.rescue.get(body),undefined);
});

test('NPC environment recovery is checked even before the inactive movement gate',()=>{
  const sim=create(),actor=sim.opponents[0],body=placeAboveMoat(sim,actor);
  body.position[1]=0;sim.movementActive=false;
  sim.step({throttle:0,brake:0,steer:0,handbrake:0,bonus:0},.025,25);
  const entry=sim.rescue.get(body);
  assert.ok(entry?.environment);assert.equal(entry.frame,1);
  assert.equal(actor.state.blockRecovery,true);
});

test('occupied authored return point waits; ordinary recovery still uses the original final fallback',()=>{
  const sim=create(),body=placeAboveMoat(sim,sim.motion);
  const point=tracks[0].drive[441].position;
  const blocking=sim.opponents[0].body;blocking.position.splice(0,3,...point);
  const options={environment:true,occupants:[body,blocking]};
  assert.deepEqual(nativeRescueDestination(tracks[0],sim.world,body,options),{blocked:true});
  const entry=createNativeRescue(body,null,{environment:true});
  Object.assign(entry,{frame:0,shrinking:false,angle:10});
  const resolveDestination=()=>nativeRescueDestination(tracks[0],sim.world,body,options);
  updateNativeRescue(entry,.025,{resolveDestination});
  assert.equal(entry.frame,19);assert.equal(entry.shrinking,true);assert.equal(entry.angle,10);
  blocking.position[0]+=100;
  updateNativeRescue(entry,.025,{resolveDestination});
  updateNativeRescue(entry,.025,{resolveDestination});
  assert.equal(entry.relocated,true);assert.equal(entry.destination.waypoint,441);
  const ordinary=nativeRescueDestination(tracks[0],sim.world,body,{
    occupied:new Set(tracks[0].drive.map((_,i)=>i)),occupants:[]});
  assert.ok(ordinary.position);assert.equal(ordinary.blocked,undefined);
});
