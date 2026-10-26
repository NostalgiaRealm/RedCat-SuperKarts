import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeUpdateClock,SimulationClock} from '../source/simulation/clock.js';

const close=(actual,expected)=>assert.ok(Math.abs(actual-expected)<1e-9,`${actual} != ${expected}`);
const create=()=>{
  const calls=[];
  const clock=new NativeUpdateClock({update:(...args)=>calls.push(args)});
  return {clock,calls};
};

test('native integer gate admits one measured interval from each update start',()=>{
  const {clock,calls}=create();
  clock.resume(100.9);
  clock.advance(124.99);assert.equal(calls.length,0);
  clock.advance(125.01);assert.equal(calls.length,1);
  close(calls[0][0],.02411);close(calls[0][1],24.11);
  clock.advance(149.99);assert.equal(calls.length,1);
  clock.advance(150.3);assert.equal(calls.length,2);
  close(calls[1][0],.02529);close(calls[1][1],49.4);
  assert.equal(clock.intervalMs,25);close(clock.lastIntervalMs,25.29);
});

test('a long stall is one elapsed update, without catch-up or a discarded backlog',()=>{
  const {clock,calls}=create();
  clock.resume(0);clock.advance(25);clock.advance(1031);
  assert.deepEqual(calls,[[.025,25,1],[1.006,1031,2]]);
  clock.advance(1031);clock.advance(1055);assert.equal(calls.length,2);
  clock.advance(1056);
  assert.deepEqual(calls.at(-1),[.025,1056,3]);
  assert.equal(clock.snapshot(1056).simulationMs,1056);
});

test('display-only snapshots never admit updates or affect the simulation trace',()=>{
  const timerTimes=[100,125.7,152,191.5,219,260.5];
  const traces=[];
  for(const refresh of [31,60,120,144,240]){
    const {clock,calls}=create();clock.resume(timerTimes[0]);
    let display=timerTimes[0];
    for(const next of timerTimes.slice(1)){
      while(display<next){clock.snapshot(display);display+=1000/refresh;}
      clock.advance(next);
    }
    traces.push(calls);
  }
  for(const trace of traces)assert.deepEqual(trace,traces[0]);
  assert.equal(traces[0].length,5);
});

test('interpolation reads the last measured interval rather than the minimum gate',()=>{
  const {clock}=create();clock.resume(100);clock.advance(140);
  const before={...clock};
  const snapshot=clock.snapshot(150);
  assert.equal(snapshot.alpha,.25);assert.equal(snapshot.intervalMs,25);
  assert.equal(snapshot.lastIntervalMs,40);assert.equal(snapshot.simulationMs,40);
  assert.equal(snapshot.elapsedMs,50);assert.equal(snapshot.wallMs,50);
  assert.equal(snapshot.nextUpdateInMs,15);
  assert.deepEqual({...clock},before);
  assert.equal(clock.snapshot(500).alpha,1);
});

test('pause excludes inactive wall time but preserves partial active time and native gate',()=>{
  const {clock,calls}=create();clock.resume(100);clock.advance(126);clock.advance(132);
  clock.pause(140);
  assert.equal(clock.snapshot(1000).elapsedMs,40);
  assert.equal(clock.snapshot(1000).wallMs,900);
  assert.equal(clock.snapshot(1000).nextUpdateInMs,null);
  const resumed=clock.resume(1140);
  assert.equal(resumed.nextUpdateInMs,0);assert.equal(resumed.elapsedMs,40);
  clock.advance(1140);
  assert.deepEqual(calls,[[.026,26,1],[0,40,2]]);
  assert.equal(clock.snapshot().alpha,1);
  clock.advance(1164);assert.equal(calls.length,2);clock.advance(1165);
  assert.deepEqual(calls.at(-1),[.025,65,3]);
  assert.equal(clock.wallMs,1065);assert.equal(clock.simulationMs,65);
});

test('a short pause resets the physics baseline without prematurely opening the gate',()=>{
  const {clock,calls}=create();clock.resume(0);clock.advance(25);clock.pause(30);
  const resumed=clock.resume(35);assert.equal(resumed.nextUpdateInMs,15);
  clock.advance(49.9);assert.equal(calls.length,1);clock.advance(50);
  assert.deepEqual(calls.at(-1),[.015,45,2]);
  clock.resume(52);clock.advance(75);
  assert.deepEqual(calls.at(-1),[.025,70,3]); // redundant resume must not reset
});

test('paused timer callbacks never update, while wall time continues',()=>{
  const {clock,calls}=create();clock.resume(20);clock.pause(30);
  clock.advance(100);clock.advance(1000);
  assert.equal(calls.length,0);assert.equal(clock.wallMs,980);assert.equal(clock.elapsedMs,10);
  clock.resume(1020);clock.advance(1020.25);
  assert.deepEqual(calls,[[.00025,10.25,1]]);
});

test('integer gate preserves unsigned GetTickCount rollover',()=>{
  const {clock,calls}=create();clock.resume(0x100000000-10+.9);
  clock.advance(0x100000000+14.99);assert.equal(calls.length,0);
  clock.advance(0x100000000+15.25);assert.equal(calls.length,1);
  close(calls[0][0],24.350000381469727/1000);
});

test('original x86 admitted-start traces retain boundaries, lateness, pause and rollover',()=>{
  const fixture=JSON.parse(readFileSync(new URL('../evidence/native/variable-timing-fixtures.json',import.meta.url)));
  for(const trace of fixture.gateTraces){
    const {clock,calls}=create();clock.resume(trace.initialStart);
    let epoch=0,previous=trace.initialStart;
    for(const frame of trace.frames){
      // The browser supplies one measured update-start timestamp. The native
      // probe also records its preceding gate poll; use the observed start,
      // not a fabricated fixed interval between those two native clock reads.
      if(frame.start<previous)epoch+=0x100000000;
      previous=frame.start;
      const count=calls.length;clock.advance(epoch+frame.start);
      assert.equal(calls.length-count,Number(frame.admitted),trace.name);
      assert.equal(clock.previousStartTick,frame.previousStart,trace.name);
    }
    assert.equal(calls.length,trace.starts.length,trace.name);
  }
});

test('invalid and backward timestamps are rejected without corrupting state',()=>{
  assert.throws(()=>new NativeUpdateClock(),TypeError);
  assert.throws(()=>new NativeUpdateClock({update(){},minIntervalMs:.5}),RangeError);
  const {clock}=create();clock.resume(100);const before={...clock};
  for(const method of ['advance','pause','resume','snapshot']){
    assert.throws(()=>clock[method](99),RangeError);
    assert.throws(()=>clock[method](NaN),RangeError);
    assert.deepEqual({...clock},before);
  }
});

test('historical deterministic replay clock retains fixed-step catch-up semantics',()=>{
  const calls=[],clock=new SimulationClock({intervalMs:25,update:(...args)=>calls.push(args)});
  clock.frame(0);clock.frame(101);
  assert.deepEqual(calls,[[.025,25,1],[.025,50,2],[.025,75,3],[.025,100,4]]);
  assert.equal(clock.snapshot().alpha,.04);
});
