import test from 'node:test';
import assert from 'node:assert/strict';
import {choosePassingForecast} from './helpers/private-closed-loop-passing-driving.mjs';

test('passing targets expand only when every standard candidate explicitly collides',()=>{
  let calls=[];
  const clear={selection:{cost:-10,offset:0,blocked:false},allCandidatesBlocked:false};
  assert.equal(choosePassingForecast(options=>{calls.push(options);return clear;}).fallbackTested,false);
  assert.equal(calls.length,1);
  calls=[];
  const blocked={selection:{cost:12000,offset:0,blocked:true},allCandidatesBlocked:true};
  const result=choosePassingForecast(options=>{
    calls.push(options);
    return calls.length===1?blocked:{selection:{cost:-20,offset:100,blocked:false},allCandidatesBlocked:false};
  },{frames:48,offsets:[-60,0,60]});
  assert.deepEqual(calls[1],{frames:48,offsets:[-140,-100,100,140]});
  assert.equal(result.selection.offset,100);
  assert.equal(result.selection.passingFallbackTested,true);
  assert.equal(result.selection.standardAllBlocked,true);
  // A worse wide candidate cannot displace the safer standard trajectory.
  let count=0;
  const retained=choosePassingForecast(()=>++count===1?blocked:
    {selection:{cost:13000,offset:140,blocked:true},allCandidatesBlocked:true});
  assert.equal(retained.selection.offset,0);
});
