import test from 'node:test';
import assert from 'node:assert/strict';
import {NativeUpdateClock} from '../source/simulation/clock.js';
import {NativeUpdateLoop} from '../source/native-update-loop.js';

function host({work=()=>{},beforeUpdate}={}){
  let time=0,id=0;const pending=new Map(),calls=[];
  const clock=new NativeUpdateClock({update:(dt,now)=>{calls.push({dt,now});work(api);}});
  const loop=new NativeUpdateLoop({clock,now:()=>time,beforeUpdate,
    schedule:(fn,delay)=>{const handle=++id;pending.set(handle,{fn,due:time+delay});return handle;},
    cancel:handle=>pending.delete(handle)});
  const api={clock,loop,calls,pending,setTime:value=>time=value,
    next:()=>[...pending.values()][0],
    wake:(when)=>{const [handle,entry]=pending.entries().next().value;
      pending.delete(handle);time=when??entry.due;entry.fn();}};
  return api;
}

test('the independent loop owns one wake; display reads and repeated starts cannot schedule more',()=>{
  const h=host();h.loop.start();h.loop.start();
  assert.equal(h.pending.size,1);assert.equal(h.next().due,25);
  for(const t of [0,4.2,8.4,16.8,24.9])h.clock.snapshot(t);
  assert.equal(h.calls.length,0);assert.equal(h.pending.size,1);
  h.wake(31);assert.deepEqual(h.calls,[{dt:.031,now:31}]);
  assert.equal(h.next().due,56);assert.equal(h.pending.size,1);
  h.wake(531);assert.deepEqual(h.calls.at(-1),{dt:.5,now:531});
  assert.equal(h.calls.length,2);assert.equal(h.next().due,556);
});

test('update work counts toward the next minimum interval without synchronous catch-up',()=>{
  let workMs=20;
  const h=host({work:h=>h.setTime(h.clock.wallMs+workMs)});
  h.loop.start();h.wake();assert.equal(h.next().due,50);
  workMs=35;h.wake();assert.equal(h.calls.length,2);
  assert.equal(h.next().due,85); // yield once even if the native gate is already due
  h.wake();assert.equal(h.calls.length,3);
  assert.deepEqual(h.calls.at(-1),{dt:.035,now:85});
});

test('pause cancels outstanding work; stale callbacks cannot replace the resumed schedule',()=>{
  const h=host();h.loop.start();h.wake(25);
  const stale=h.next().fn;h.setTime(30);h.loop.stop();
  assert.equal(h.pending.size,0);assert.equal(h.clock.paused,true);
  h.setTime(1030);h.loop.start();assert.equal(h.next().due,1030);
  stale();assert.equal(h.pending.size,1);assert.equal(h.calls.length,1);
  h.wake();assert.deepEqual(h.calls.at(-1),{dt:0,now:30});
  assert.equal(h.clock.wallMs,1030);assert.equal(h.next().due,1055);
  h.loop.stop();assert.equal(h.pending.size,0);
});

test('input-triggered pause and update errors stop admission and pending scheduling',()=>{
  let h=host({beforeUpdate:()=>h.loop.stop()});
  h.loop.start();h.wake();assert.equal(h.calls.length,0);
  assert.equal(h.loop.running,false);assert.equal(h.pending.size,0);
  h=host({work:()=>{throw new Error('update failed');}});
  h.loop.start();assert.throws(()=>h.wake(),/update failed/);
  assert.equal(h.loop.running,false);assert.equal(h.clock.paused,true);assert.equal(h.pending.size,0);
});

test('an externally paused clock can be resumed without leaving a duplicate timer',()=>{
  const h=host();h.loop.start();h.setTime(10);h.clock.pause(10);
  h.setTime(40);h.loop.start();assert.equal(h.pending.size,1);
  h.wake();assert.equal(h.calls.length,1);assert.equal(h.clock.paused,false);
  h.loop.stop();
});
