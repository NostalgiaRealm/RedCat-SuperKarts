import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeEngineTimer} from '../src/simulation/clock.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/variable-timing-fixtures.json',import.meta.url)));

test('18 original absolute-clock traces match every store and returned delta at24/53bit',()=>{
  let frames=0;
  for(const trace of fixtures.clockTraces){
    let timer;
    for(const frame of trace.frames){
      let result;
      if(frame.operation==='initialize'){
        timer=new NativeEngineTimer({precision:trace.precision,counter:frame.counter,frequency:trace.frequency});
        result=timer.initialDelta;
      }else result=timer[frame.operation==='reset'?'resetCounter':'sampleCounter'](frame.counter,trace.frequency);
      const context=`${trace.precision}/${trace.api}/${trace.epochMs}/${frames++}`;
      assert.equal(result,frame.returnedDelta,context+' returned delta');
      assert.equal(timer.absoluteSeconds,frame.absoluteSeconds,context+' absolute');
      assert.equal(timer.deltaSeconds,frame.deltaField,context+' delta store');
      if(frame.rawDelta!==null)assert.equal(timer.rawDelta,frame.rawDelta,context+' raw delta');
      assert.deepEqual(timer.history,frame.history,context+' history');
      assert.equal(timer.historyIndex,frame.historyIndex,context+' ring index');
    }
  }
  assert.equal(frames,288);
});

test('host seconds API retains cold priming and refreshes absolute baseline on resume',()=>{
  const timer=new NativeEngineTimer({absoluteSeconds:60});
  assert.equal(timer.initialDelta,Math.fround(.1));
  for(const time of [60.025,60.058,60.083])assert.equal(timer.sampleAbsoluteSeconds(time),Math.fround(.1));
  timer.sampleAbsoluteSeconds(60.1);
  const index=timer.historyIndex;
  assert.equal(timer.resetAbsoluteSeconds(90.123),Math.fround(.1));
  assert.equal(timer.historyIndex,index);assert.equal(timer.absoluteSeconds,Math.fround(90.123));
  assert.equal(timer.sampleAbsoluteSeconds(90.123),Math.fround(.05));
  assert.equal(timer.rawDelta,0);
  timer.sampleAbsoluteSeconds(90.148);
  assert.equal(timer.rawDelta,Math.fround(Math.fround(90.148)-Math.fround(90.123)));
});

test('absolute subtraction preserves signed cancellation and actual zero/upper-cap rules',()=>{
  const timer=new NativeEngineTimer({absoluteSeconds:100.3,precision:53});
  timer.resetAbsoluteSeconds(100.3);timer.sampleAbsoluteSeconds(100.3);
  assert.ok(timer.rawDelta<0);
  timer.deltaSeconds=-.001;assert.equal(timer.readDelta(),-.001);
  timer.deltaSeconds=0;assert.equal(timer.readDelta(),Math.fround(.1));
  timer.deltaSeconds=.2;assert.equal(timer.readDelta(),Math.fround(.1));
  assert.throws(()=>timer.sampleAbsoluteSeconds(NaN),/Invalid/);
  assert.throws(()=>timer.resetCounter(1,0),/Invalid/);
});
