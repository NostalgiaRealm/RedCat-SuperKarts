import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {finishNativeContactStep,NativeRailCollision} from '../src/simulation/native-collision.js';

test('contact callback order and persistent latches match original engine dispatch',async()=>{
  const fixture=JSON.parse(await readFile(new URL('../evidence/native/contact-callback-fixtures.json',import.meta.url)));
  for(const c of fixture.cases){
    const calls=[],bodies=[0,1].map(i=>({contactLatch:Boolean(c.latchMask&(1<<i)),
      onCollision:c.callbackMask&(1<<i)?()=>calls.push(i):null}));
    const contact=c.kind<0?null:{firstBody:bodies[c.first],
      secondBody:c.kind===1?bodies[c.second]:undefined};
    finishNativeContactStep(bodies[c.mover],contact,12345);
    assert.deepEqual(calls,c.calls,JSON.stringify(c));
    assert.deepEqual(bodies.map(body=>body.contactLatch),c.latches,JSON.stringify(c));
  }
  assert.equal(fixture.cases.length,192);
});

test('skipped rail responses retain the shared native collision impulse',async()=>{
  const fixture=JSON.parse(await readFile(new URL('../evidence/native/contact-callback-fixtures.json',import.meta.url)));
  for(const c of fixture.retainedImpulse){
    const collision=new NativeRailCollision({collision:[]},{});
    const body={lateralSpeed:c.speed,forwardSpeed:0,verticalSpeed:0,yawRate:0,
      inverseMass:c.inverseMass,inverseInertia:0,restitution:c.restitution};
    collision.contactState.impulse=c.previous;
    collision.resolve(body,{point:[0,0,0],normal:[1,0,0]});
    assert.equal(collision.contactState.impulse,c.expected);
  }
});
