import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeRaceLifecycle, NativeRaceResultGate, NativeRacePauseGate,
  nativeRacePauseRequest, nativeQuitRequesterChoice} from '../source/simulation/native-race-lifecycle.js';
import {NativeGameTimers} from '../source/simulation/native-game-timers.js';
const f=JSON.parse(readFileSync(new URL('../evidence/native/race-lifecycle-fixtures.json',import.meta.url)));

test('Original success/failure delays, held-key loops, Shift and tick wrap match',()=>{
  for(const [i,c] of f.resultTraces.entries()){
    const gate=new NativeRaceResultGate(c.phase,{hardware:c.hardware});
    for(const [step,sample] of c.trace.entries()){
      assert.equal(gate.update(sample.nowMs,new Set(sample.keys)),sample.done,`${i}/${step} completion`);
      assert.equal(gate.startedMs,sample.epoch,`${i}/${step} epoch`);
      assert.equal(gate.waitingForRelease,!sample.returned,`${i}/${step} blocking loop`);
      assert.equal(gate.finishFlagRequested,sample.finishFlagRequested,`${i}/${step} finish flag`);
    }
  }
});

test('240 original phase writes preserve movement through results and only success marks completion',()=>{
  for(const [i,c] of f.phaseTransitions.entries()){
    const controller=new NativeRaceLifecycle();
    for(const [key,value] of Object.entries(c.before))controller[key]=key==='phase'?value:Boolean(value);
    let starts=0;
    if(c.finish===0x41fe50)controller.raceCompleted=true;
    const events=controller.enter(c.target,{startRace:()=>starts++});
    for(const [key,value] of Object.entries(c.expected))
      assert.equal(Number(controller[key]),value,`${i}/${key}`);
    assert.equal(starts,c.calls.filter(call=>call[0]===0x42f980).length);
    assert.deepEqual(events.filter(e=>e.type==='native-action').map(e=>[0x420ba0,e.action,e.start,e.update,e.finish]),
      c.calls.filter(call=>call[0]===0x420ba0));
  }
});

test('Native graphical requester waits for J/N/Escape release and preserves key priority',()=>{
  for(const c of f.quitKeys){
    const gate=new NativeRacePauseGate('quit');
    gate.update(); // release the opening Escape
    assert.equal(gate.update(new Set(c.keys)).done,!c.blocked);
    assert.equal(gate.update().done,c.returned);
    assert.equal(gate.quit,nativeQuitRequesterChoice(c.code));
  }
  for(const [code,quit] of [[0,true],[2,true],[1,false],[3,false],[10000,false]]){
    const gate=new NativeRacePauseGate('quit');
    assert.deepEqual(gate.update({}, {requesterCode:code}),{done:true,quit,stage:'input',heldKey:null});
  }
});

test('Pause accepts any key after initial P release; requester fallback alone accepts Y',()=>{
  const pause=new NativeRacePauseGate('pause');
  assert.equal(pause.update({P:true}).done,false);
  assert.equal(pause.update().done,false);
  assert.equal(pause.update(new Set([65,66])).done,false);
  assert.equal(pause.update(new Set([66])).done,false);
  assert.equal(pause.update().done,true);
  const graphic=new NativeRacePauseGate('quit');
  assert.equal(graphic.update({Y:true}).done,false);
  const fallback=new NativeRacePauseGate('quit',{graphical:false});
  assert.equal(fallback.update({Y:true}).quit,true);
  assert.equal(fallback.done,true);
  for(const phase of [0,1,2,3,4,6,8]){
    assert.equal(nativeRacePauseRequest(phase,{Escape:true}),[1,3,6].includes(phase)?null:'quit');
    assert.equal(nativeRacePauseRequest(phase,{Escape:true,P:true}),[3,6].includes(phase)?null:'pause');
    assert.equal(nativeRacePauseRequest(phase,{P:true,Shift:true}),null);
  }
});

test('Expiry is gated to racing phase, uses timer18, and precedes damage failure',()=>{
  const timers=new NativeGameTimers();timers.initialize(18,7000,true);timers.start(18,100);
  const state=new NativeRaceLifecycle({phase:0,movementActive:true,playerActive:true});
  assert.deepEqual(state.checkExpiry({raceType:1,timers,nowMs:2101}),[{type:'time-tick',seconds:4,sound:'TIME_TICK'}]);
  assert.deepEqual(state.checkExpiry({raceType:1,timers,nowMs:2102}),[]);
  state.checkExpiry({raceType:1,timers,nowMs:7100,damage:100});
  assert.equal(state.phase,6);assert.equal(state.gameOverMode,1);
  assert.equal(state.movementActive,true);
  state.updateResult(7100);state.updateResult(8100,{Enter:true});
  assert.equal(state.phase,4);assert.equal(state.raceCompleted,false);assert.equal(state.running,false);
});
