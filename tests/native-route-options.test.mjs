import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeRaceRouteOptions} from '../src/simulation/native-race-options.js';
import {nativeProjectileFacing} from '../src/simulation/native-projectile.js';
import {nativeRaceGrid,nativeRaceSetup} from '../src/simulation/native-race-setup.js';
import {createNativeTrack} from '../src/simulation/native-track.js';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';

const read=path=>fs.readFileSync(new URL('../'+path,import.meta.url));
const json=path=>JSON.parse(read(path));
const config=json('public/assets/config.json'),manifest=json('public/assets/manifest.json'),
  cars=json('public/assets/cars.json');
const tracks=Array.from({length:6},(_,i)=>json(`public/assets/tracks/etappe${i}.json`));
const fixtures=json('evidence/gameplay/native-projectile-fixtures.json');

test('race routing reads independent British/direction INI integers, not the map mirror flag',()=>{
  assert.deepEqual(nativeRaceRouteOptions(config),{british:0,direction:0});
  assert.deepEqual(nativeRaceRouteOptions({'race.ini':{etappe:{british:'1',direction:'1'}}}),
    {british:1,direction:1});
  assert.deepEqual(nativeRaceRouteOptions({'race.ini':{etappe:{}}}),{british:0,direction:0});
  let changedByOldDefault=0,checked=0;
  for(const item of fixtures.facing){
    if(item.options.british!==0||item.options.direction!==0)continue;
    const track=tracks[item.track];
    assert.equal(nativeProjectileFacing(track,item.body),item.expected);
    checked++;
    if(track.mirrored&&nativeProjectileFacing(track,item.body,{british:1,direction:0})!==item.expected)
      changedByOldDefault++;
  }
  assert.ok(checked>=60);
  assert.ok(changedByOldDefault>0,'the executed source cases distinguish the old conflated flag');
});

test('fallback grid setup consumes configured lane settings independently of mirrored artwork',()=>{
  const track=structuredClone(tracks[3]),world=createNativeTrack(track);
  for(const node of track.drive)if(node.unknown[1]>=69&&node.unknown[1]<=78)node.unknown[1]=0;
  const setup=nativeRaceSetup(config,track,world,{trackIndex:3,startChunk:1});
  const expected=nativeRaceGrid(track,world,{british:0,direction:0,startChunk:1});
  assert.deepEqual(setup.player.start,expected.player);
  assert.notDeepEqual(expected.player,nativeRaceGrid(track,world,{british:1,direction:0,startChunk:1}).player);
  const settings=structuredClone(config);settings['race.ini'].etappe.british='1';
  assert.deepEqual(nativeRaceSetup(settings,track,world,{trackIndex:3,startChunk:1}).player.start,
    nativeRaceGrid(track,world,{british:1,direction:0,startChunk:1}).player);
});

test('race composition passes the same explicit route settings to projectile, rescue and weather direction',()=>{
  for(const british of [0,1]){
    const settings=structuredClone(config);settings['race.ini'].etappe.british=String(british);
    const track=tracks[2],sim=new RaceSimulation({config:settings,manifest,cars,track,
      random:new NativeRandom(0),physicsBytes:read('public/assets/physics/phys0.dat'),
      racerBytes:read('public/assets/racer-tables/cars0.dat'),difficulty:0});
    assert.deepEqual(sim.routeOptions,{british,direction:0});
    assert.equal(sim.rescue.options.british,british);
    assert.equal(sim.rescue.options.direction,0);
    for(const item of fixtures.facing.filter(item=>item.track===2&&item.options.british===british&&item.options.direction===0))
      assert.equal(sim.combat.forwardDirection(item.body),item.expected);
    const sector=track.route.findIndex(route=>route.trigger===83||route.unknown===83);
    const body=sim.motion.body;
    body.sector=sector;body.previousSector=(sector+track.route.length-1)%track.route.length;
    const expected=nativeProjectileFacing(track,body,sim.routeOptions),calls=[];
    sim.weather.trigger=(marker,options)=>calls.push({marker,...options});
    sim.step({throttle:0,brake:0,steer:0,handbrake:0,bonus:0},.025,25);
    assert.equal(calls.find(call=>call.marker===83).forward,expected);
  }
});
