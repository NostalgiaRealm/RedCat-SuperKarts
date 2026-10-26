import test from 'node:test';
import assert from 'node:assert/strict';
import {PlayerStuckRecovery,PLAYER_STUCK_SECONDS} from '../source/simulation/player-stuck-recovery.js';

const body=()=>({position:[0,0,0],yaw:0,sector:2,waypoint:8,forwardSpeed:0});
const race=()=>({distance:2,lapCount:0,finishArmed:false});
const drive={throttle:1,brake:0};
function advance(detector,kart,input,seconds,dt=.025,options){
  let detected=false;
  for(let tick=0;tick<Math.round(seconds/dt);tick++)
    detected=detector.step(kart,input,dt,options)||detected;
  return detected;
}

test('persistent driving into an obstacle recovers after eight actual seconds at different frame rates',()=>{
  for(const dt of [.01,.025,.05]){
    const detector=new PlayerStuckRecovery(),kart=body();
    assert.equal(advance(detector,kart,drive,PLAYER_STUCK_SECONDS-dt,dt),false);
    assert.equal(detector.step(kart,drive,dt),true);
  }
});

test('wheel speed, vertical vibration and bounded collision oscillation cannot hide a soft-lock',()=>{
  const detector=new PlayerStuckRecovery(),kart=body();
  let detected=false;
  for(let tick=0;tick<400;tick++){
    kart.position=[Math.sin(tick)*4,tick%3*20,Math.cos(tick)*3];
    kart.forwardSpeed=27;
    detected=detector.step(kart,{analog:drive},.025)||detected;
  }
  assert.equal(detected,true);
});

test('normal slow driving, reversing and a moving circle keep resetting the trap interval',()=>{
  for(const mode of ['slow','reverse','circle']){
    const detector=new PlayerStuckRecovery(),kart=body();
    for(let tick=0;tick<2000;tick++){
      kart.position=mode==='circle'
        ?[120*Math.sin(tick*.025),0,120*Math.cos(tick*.025)]
        :[0,0,(mode==='reverse'?-1:1)*tick*.3];
      assert.equal(detector.step(kart,mode==='reverse'?{brake:1}:drive,.025),false,mode);
    }
  }
});

test('standing idle, handbraking, two pedals or a neutral analogue stick never request recovery',()=>{
  for(const input of [{},{throttle:1,handbrake:1},{throttle:1,brake:1},
    {analog:{throttle:.1,brake:0}}]){
    const detector=new PlayerStuckRecovery();
    assert.equal(advance(detector,body(),input,30),false);
  }
});

test('reversing direction briefly preserves an escape attempt, but an ordinary stop clears it',()=>{
  const detector=new PlayerStuckRecovery(),kart=body();
  assert.equal(advance(detector,kart,drive,4),false);
  assert.equal(advance(detector,kart,{},.25),false);
  assert.equal(advance(detector,kart,{brake:1},4),true);
  detector.reset();
  advance(detector,kart,drive,7);
  assert.equal(advance(detector,kart,{},1),false);
  assert.equal(advance(detector,kart,drive,1),false);
});

test('inactive modes, explicit pause resets and suspension gaps cannot inherit a near-trigger',()=>{
  const detector=new PlayerStuckRecovery(),kart=body();
  for(const reset of [()=>detector.step(kart,drive,.025,{eligible:false}),
    ()=>detector.reset(),()=>detector.step(kart,drive,3),
    ()=>detector.step(kart,drive,0)]){
    advance(detector,kart,drive,7);
    reset();
    assert.equal(advance(detector,kart,drive,1),false);
    detector.reset();
  }
});

test('anchors retain only separated safe road positions and a new lap clears stale history',()=>{
  const detector=new PlayerStuckRecovery(),kart=body(),progress=race();
  detector.remember(kart,progress,()=>false);
  assert.equal(detector.anchors.length,0);
  detector.remember(kart,progress,()=>true);
  for(let i=0;i<400;i++)detector.remember(kart,progress,()=>true);
  assert.equal(detector.anchors.length,1);
  kart.position[2]=120;progress.distance=3;
  detector.remember(kart,progress,()=>true);
  assert.deepEqual(detector.anchors.map(pose=>pose.distance),[3,2]);
  const request=detector.request(kart,progress);
  kart.position[2]=300;detector.anchors[0].position[2]=250;
  assert.equal(request.reference.position[2],120);
  assert.equal(request.anchors[0].position[2],120);
  progress.lapCount=1;progress.distance=180;
  detector.observeLap(progress);
  assert.equal(detector.anchors.length,0);
  assert.equal(detector.request(kart,progress).reference.lapStartDistance,180);
});

test('starting a rescue clears the attempt and retains its reason for inspection',()=>{
  const detector=new PlayerStuckRecovery(),kart=body();
  advance(detector,kart,drive,8);
  const request=detector.request(kart,race());
  detector.started(request);
  assert.equal(detector.recoveries,1);
  assert.equal(detector.lastRecovery.reason,'blocked-driving');
  assert.equal(advance(detector,kart,drive,1),false);
});

test('an unavailable return retries after one second of further attempted driving',()=>{
  const detector=new PlayerStuckRecovery(),kart=body();
  assert.equal(advance(detector,kart,drive,8),true);
  detector.retryAfter();
  assert.equal(advance(detector,kart,drive,.975),false);
  assert.equal(detector.step(kart,drive,.025),true);
  assert.equal(detector.recoveries,0);
});
