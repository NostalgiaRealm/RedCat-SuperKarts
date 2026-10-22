import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {applyNativePlayerJump,nativeJumpSettings} from '../src/simulation/native-jump.js';
import {nativeCrossedTriggers} from '../src/simulation/native-race.js';

const read=path=>JSON.parse(fs.readFileSync(new URL(path,import.meta.url)));
const fixture=read('../evidence/race-completion/france-native-jump-fixtures.json');
const config=read('../public/assets/config.json');
const tracks=Array.from({length:6},(_,id)=>read(`../public/assets/tracks/etappe${id}.json`));
const settings=nativeJumpSettings(config);

function check(row,dispatched) {
  const original=tracks[row.track],track={...original,drive:[...original.drive],route:[...original.route]};
  track.drive[row.waypoint]={...track.drive[row.waypoint],unknown:[
    track.drive[row.waypoint].unknown[0],row.waypointMarker]};
  track.route[row.sector]={...track.route[row.sector],trigger:row.marker,unknown:row.secondary};
  const body={sector:row.sector,waypoint:row.waypoint,matrix:row.matrix,forwardSpeed:row.speed};
  const wheels=row.velocities.map(verticalSpeed=>({verticalSpeed}));
  for(const marker of dispatched?nativeCrossedTriggers(track,row.previous,row.sector):[row.marker])
    applyNativePlayerJump(marker,{track,body,wheels,settings,routeOptions:fixture.routeOptions});
  assert.deepEqual({speed:body.forwardSpeed,velocities:wheels.map(wheel=>wheel.verticalSpeed)},row.expected,
    JSON.stringify({precision:row.precision,track:row.track,sector:row.sector,marker:row.marker,
      waypoint:row.waypoint,waypointMarker:row.waypointMarker,matrix:row.matrix}));
}

test('648 original jump callbacks preserve waypoint/direction gates and all configured boosts',()=>{
  assert.deepEqual(fixture.registration,{'49':'0x441c50','50':'0x441e50','51':'0x441e60',
    '52':'0x441d50','61':'0x0','62':'0x0','63':'0x0'});
  for(const row of fixture.cases)check(row,false);
});

test('original integer configuration loads truncate authored decimal multipliers',()=>{
  assert.deepEqual(settings,{61:{forward:1,up:275},62:{forward:2,up:100},63:{forward:1,up:250}});
  for(const row of fixture.loads)assert.deepEqual(row.nativeStored,fixture.settings);
});

test('320 original registered boundary dispatches match every authored jump lane and unchanged-sector gate',()=>{
  for(const row of fixture.crossings)check(row,true);
  assert.deepEqual(fixture.inventory.filter(track=>track.boundaries.length).map(track=>track.track),[0,1,3]);
});

test('France104 applies its authored jump while France103 waypoint gate skips it',()=>{
  const rows=fixture.crossings.filter(row=>row.track===3&&row.precision===24&&row.previous!==row.sector);
  assert.ok(rows.filter(row=>row.sector===103).every(row=>row.velocities[0]===row.expected.velocities[0]));
  assert.ok(rows.some(row=>row.sector===104&&row.expected.velocities[0]===275
    &&row.expected.speed===row.speed));
});
