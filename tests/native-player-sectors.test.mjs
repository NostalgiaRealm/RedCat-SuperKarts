import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeRaceState,nativeSectorDistance,nativeCrossedTriggers} from '../source/simulation/native-race.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/gameplay/native-player-sectors.json',import.meta.url)));
const tracks=Array.from({length:6},(_,i)=>JSON.parse(fs.readFileSync(
  new URL(`../public/assets/tracks/etappe${i}.json`,import.meta.url))));

test('original player progress and trigger dispatch use engine sector history even after relocation',()=>{
  for(const item of fixture.cases){
    const track=tracks[item.track],label=JSON.stringify(item);
    assert.equal(nativeSectorDistance(item.current,item.previous,track.route.length),item.distance,label);
    assert.deepEqual(nativeCrossedTriggers(track,item.previous,item.current),item.triggers,label);
    const race=new NativeRaceState({track,startSector:item.cachedPrevious,raceType:0,
      lapLimit:5,lapTimerLimitMs:900000}),triggers=[];
    race.trigger=id=>triggers.push(id);
    race.beginUpdate(item.current,25,{previousSector:item.previous});
    assert.equal(race.distance,item.distance,label);
    assert.deepEqual(triggers,item.triggers,label);
    assert.equal(race.previousSector,item.current,label);
  }
});
