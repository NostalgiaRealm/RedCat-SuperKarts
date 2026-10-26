import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeSquashTargets} from '../source/simulation/native-squash-activation.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/squash-activation-fixtures.json',import.meta.url)));
test('1920 original hazard callbacks preserve boundary, frame, cached position and target quirks',()=>{
  for(const c of fixture.cases){
    const object={id:0,type:c.type,position:c.position,angles:[0,0,c.angle]};
    const player={id:1,position:c.player},opponents=c.opponents.map((position,i)=>({id:i+2,position}));
    assert.deepEqual(nativeSquashTargets(object,{player,opponents,playerPosition:c.cachedPlayer,
      frame:c.frame,precision:c.precision}).map(body=>body.id),c.expected,JSON.stringify(c));
  }
});
