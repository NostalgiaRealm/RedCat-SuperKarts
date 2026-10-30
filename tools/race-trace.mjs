#!/usr/bin/env node
// Bit-exact trace of the race simulation, used to prove that performance work
// does not change gameplay. Every update hashes the exact bits of everything a
// race produces: karts, AI state, camera, scenery, pickups, projectiles, rescue,
// effects, sounds and the shared random stream. The reference in
// tests/fixtures/race-trace.json was generated before the optimizations.
//
//   node tools/race-trace.mjs --out trace.json [--ticks 3000] [--every 50]
//   node tools/race-trace.mjs --compare trace.json [--ticks 3000] [--every 50]
//   node tools/race-trace.mjs --dump 0:1234   (scenario index:tick as JSON, for diffing)
import fs from 'node:fs';
import {pathToFileURL} from 'node:url';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const json=file=>JSON.parse(read(file));

// Six tracks, all difficulties, race modes and several characters. The player
// follows the route with some noise, fires bonuses and hits things, so rescue,
// recovery, collisions and pickups are exercised along with normal driving.
export const SCENARIOS=[
  {name:'netherlands',track:0,difficulty:1,raceMode:0,character:0,seed:0},
  {name:'england',track:1,difficulty:0,raceMode:0,character:1,seed:12345},
  {name:'germany',track:2,difficulty:2,raceMode:0,character:2,seed:777},
  {name:'france-mirrored',track:3,difficulty:1,raceMode:1,character:3,seed:42,analog:true},
  {name:'spain',track:4,difficulty:0,raceMode:2,character:0,seed:9,cameras:true},
  {name:'italy',track:5,difficulty:2,raceMode:3,character:1,seed:31337},
  {name:'netherlands-countdown',track:0,difficulty:2,raceMode:0,character:2,seed:5,countdown:true},
  {name:'germany-flight',track:2,difficulty:0,raceMode:0,character:0,seed:6,freeFlight:[300,420]},
];

const f64=new Float64Array(1),u32=new Uint32Array(f64.buffer);
class Chain{
  constructor(){this.a=0x811c9dc5;this.b=0x9747b28c;}
  word(value){
    this.a=Math.imul(this.a^value,0x01000193)>>>0;
    this.b=Math.imul((this.b^value)+0x7f4a7c15,0xcc9e2d51)>>>0;
    this.b=(this.b<<13|this.b>>>19)>>>0;
  }
  number(value){
    // Exact bits, including signed zero. All NaNs are one value in JavaScript.
    if(value!==value){this.word(0x7ff80000);this.word(0);return;}
    f64[0]=value;this.word(u32[0]);this.word(u32[1]);
  }
  text(value){this.word(value.length);for(let i=0;i<value.length;i++)this.word(value.charCodeAt(i));}
  hex(){return this.a.toString(16).padStart(8,'0')+this.b.toString(16).padStart(8,'0');}
}
// Numeric sequences hash alike in arrays and typed arrays, so storage changes
// that keep the values do not count as behaviour changes.
const SKIP=new Set(['track','world','config','manifest','physics','racer','playerRacer','collision','occupancy',
  'groundClock','voices','random','pickups','actors','parameters','forwardDirection','body','firstBody','secondBody',
  'owner','target','shooter','actor','sampleGround','sampleRouteHeight','bounds','mesh','texture','sequence']);
function mix(chain,value,seen){
  switch(typeof value){
    case 'number':chain.number(value);return;
    case 'boolean':chain.word(value?0x51:0x50);return;
    case 'string':chain.text(value);return;
    case 'undefined':chain.word(0x55);return;
    case 'function':return;
  }
  if(value===null){chain.word(0x4e);return;}
  if(ArrayBuffer.isView(value)||Array.isArray(value)){
    chain.word(value.length);for(let i=0;i<value.length;i++)mix(chain,value[i],seen);return;
  }
  if(seen.has(value))return;
  seen.add(value);
  if(value instanceof Map){
    chain.word(value.size);for(const [key,entry]of value){mix(chain,key,seen);mix(chain,entry,seen);}return;
  }
  if(value instanceof Set){
    chain.word(value.size);for(const entry of value)mix(chain,entry,seen);return;
  }
  for(const key of Object.keys(value).sort()){
    if(SKIP.has(key))continue;
    chain.text(key);mix(chain,value[key],seen);
  }
}
const pick=(object,keys)=>Object.fromEntries(keys.map(key=>[key,object[key]]));
const BODY=['position','yaw','pitch','roll','matrix','sector','previousSector','lateralSpeed','verticalSpeed','forwardSpeed',
  'yawRate','pitchRate','rollRate','x','y','z','waypoint'];
const SHAPE=['position','matrix','yaw','pitch','roll','sector','visible','active','lateralSpeed','verticalSpeed','forwardSpeed',
  'pitchRate','rollRate','yawRate','mode','velocity','angles','flags','contactLatch','radius','gravity'];
// One canonical record per group. A refactor that keeps the values keeps these.
export function observe(sim){
  const actor=item=>({body:pick(item.body,BODY),controls:item.controls,wheels:item.ground?.wheels,groundCount:item.ground?.groundCount,
    rpm:item.rpm,gear:item.gear,slip:item.slipMagnitude,lowSpeedTurn:item.lowSpeedTurn,updates:item.updates,state:item.state,
    progress:item.progress?.distance});
  return {
    rng:{state:sim.pickups.random.state},
    player:actor(sim.motion),
    opponents:sim.opponents.map(actor),
    race:{race:pick(sim.race,['phase','lapCount','lapTimes','sessionBestLapMs','lapStartMs','elapsedMs','raceTimeMs','distance','gateIndex',
      'gateDistance','gateDeadlineMs','zeroSectorPassed','finished','lapTimerMs','previousSector','finishArmed','remainingMs']),
      ranks:sim.rankStates,lifecycle:sim.lifecycle.phase,movement:sim.movementActive,running:sim.lifecycle.running,
      hud:sim.playerHudPosition,speed:sim.playerSpeedKmh,npcFinish:sim.npcFinishTimes,safety:sim.velocitySafetyCorrections},
    camera:{position:sim.camera.position,target:sim.camera.target,mode:sim.camera.mode,sector:sim.cameraSector,matrix:sim.cameraMatrix,
      cameraBody:sim.cameraBody,ranges:sim.callbackRanges,bodyVisible:sim.playerCamera.bodyVisible},
    scenery:{bodies:sim.scenery.bodies.map(item=>pick(item,SHAPE)),reactions:sim.sceneryReactions.objects.map(item=>pick(item,SHAPE)),
      hazards:sim.sceneryHazards.objects.map(item=>pick(item,SHAPE)),paths:[...sim.sceneryPaths.objects.values()].map(item=>pick(item,SHAPE)),
      animations:sim.scenery.animations,hazardAnimations:sim.sceneryHazards.animations,rotations:[...sim.rotationStates?.values()??[]].map(item=>item.angles)},
    pickups:{items:sim.pickups.pickups.map(item=>pick(item,['type','placementIndex','position','yaw','frame','state','level','ageSeconds'])),
      owned:sim.pickups.owned,eligibleAfter:sim.pickups.eligibleAfter,stars:sim.pickups.stars},
    combat:{shots:sim.combat.shots,secondaryShots:sim.combat.secondaryShots,effects:sim.combat.effects,arms:sim.combat.arms,
      bubbles:sim.bubbles,squash:sim.squash.entries?.map(entry=>pick(entry,['active','phase','time','scale','timerId']))},
    rescue:{entries:sim.rescue.entries.map(entry=>pick(entry,['matrix','scale','renderPosition','finished','relocated','time','phase','softLock'])),
      retired:sim.retiredRescueMatrix,recoveryLast:sim.playerRecovery.lastRecovery?.destination?.position},
    streams:{jets:sim.streamFrames.jets,ribbons:sim.streamFrames.ribbons},
    particles:{smoke:sim.smokeFrames,skidmarks:sim.skidmarkFrames,weather:sim.weatherFrames,explosions:sim.explosionFrames},
    events:{events:sim.events.map(event=>JSON.stringify(event,(key,value)=>typeof value==='object'&&value&&(value.matrix||value.position&&key.endsWith('Body'))?undefined:value))},
  };
}

function controller(scenario,sim){
  // Independent generator: must not touch the game's shared random stream.
  let state=(scenario.seed^0x5bd1e995)>>>0,steerBias=0,handbrake=0,brake=0;
  const random=()=>(state=(Math.imul(state,1103515245)+12345)>>>0)>>>16&0x7fff;
  const route=sim.race.track.route,mirror=sim.race.track.mirrored?-1:1;
  return tick=>{
    if(tick%40===0){
      steerBias=random()%100<12?(random()%2?1:-1):0;
      handbrake=random()%100<6?10:0;brake=random()%100<4?15:0;
    }
    if(handbrake>0)handbrake--;
    if(brake>0)brake--;
    const body=sim.motion.body,target=route[(body.sector+6)%route.length].position;
    const dx=target[0]-body.position[0],dz=target[2]-body.position[2];
    const cross=body.matrix[8]*dx-body.matrix[6]*dz,dot=body.matrix[6]*dx+body.matrix[8]*dz;
    const angle=Math.atan2(cross,dot)*mirror;
    let steer=angle>.12?1:angle<-.12?-1:0;
    if(steerBias)steer=steerBias;
    const input={throttle:brake?0:1,brake:brake?1:0,steer,handbrake:handbrake?1:0,bonus:tick%90<3?1:0};
    if(scenario.analog)input.analog={steer:Math.max(-1,Math.min(1,angle)),throttle:brake?0:1,brake:brake?1:0};
    return input;
  };
}

export function createScenario(scenario){
  const simulation=new RaceSimulation({config:json('config.json'),manifest:json('manifest.json'),cars:json('cars.json'),
    track:json(`tracks/etappe${scenario.track}.json`),physicsBytes:read(`physics/phys${scenario.difficulty}.dat`),
    racerBytes:read(`racer-tables/cars${scenario.difficulty}.dat`),random:new NativeRandom(scenario.seed),
    character:scenario.character,difficulty:scenario.difficulty,raceMode:scenario.raceMode,countdown:Boolean(scenario.countdown)});
  const sounds=[];
  simulation.onVoiceRequest=request=>sounds.push(JSON.stringify(request));
  simulation.onDirectSound=event=>sounds.push(String(event));
  simulation.onAnimationRequest=(racer,request)=>sounds.push(racer+JSON.stringify(request));
  simulation.onSceneryImpact=index=>sounds.push('impact'+index);
  return {simulation,sounds,input:controller(scenario,simulation),now:0,tick:0};
}
// Variable update lengths, as in the browser's measured clock.
const stepLength=tick=>tick%31===0?.1:tick%17===0?.05:tick%7===0?.033:.025;
export function advance(scenario,run,events=[]){
  const {simulation}=run,tick=run.tick++;
  if(scenario.freeFlight){
    if(tick===scenario.freeFlight[0])simulation.setFreeFlight(true);
    if(tick===scenario.freeFlight[1])simulation.setFreeFlight(false);
  }
  const dt=stepLength(tick);run.now+=dt*1000;
  const keys={};
  if(scenario.cameras){
    const phase=Math.floor(tick/150)%5;
    if(tick%150===0)keys[[50,52,49,50,52][phase]]=true;
    if(tick%300>=120&&tick%300<140)keys[51]=true;
  }
  simulation.step(run.input(tick),dt,run.now,{keys});
}

export function trace(scenario,{ticks=3000,every=50}={}){
  const run=createScenario(scenario),groups={};
  const checkpoints=[];
  const seen=()=>new WeakSet();
  for(let tick=0;tick<ticks;tick++){
    run.sounds.length=0;
    advance(scenario,run);
    const observed=observe(run.simulation);
    observed.sounds=run.sounds;
    for(const [name,value]of Object.entries(observed)){
      const chain=groups[name]??=new Chain();
      mix(chain,value,seen());
    }
    if((tick+1)%every===0||tick===ticks-1)checkpoints.push({tick:tick+1,groups:Object.fromEntries(Object.entries(groups).map(([name,chain])=>[name,chain.hex()]))});
  }
  const sim=run.simulation;
  return {name:scenario.name,ticks,checkpoints,final:{laps:sim.race.lapCount,phase:sim.race.phase,sector:sim.motion.body.sector,
    rng:sim.pickups.random.state,opponentLaps:sim.opponents.map(actor=>actor.state.laps),
    activeShots:sim.combat.shots.filter(shot=>shot.state).length,recoveries:Boolean(sim.playerRecovery.lastRecovery)}};
}
export function firstDifference(expected,actual){
  for(let i=0;i<expected.checkpoints.length;i++){
    const a=expected.checkpoints[i],b=actual.checkpoints[i];
    if(!b)return {tick:a.tick,groups:['missing checkpoint']};
    const groups=Object.keys(a.groups).filter(name=>a.groups[name]!==b.groups[name]);
    if(groups.length)return {tick:a.tick,groups};
  }
  return null;
}

if(process.argv[1]&&import.meta.url===pathToFileURL(process.argv[1]).href){
  const option=(name,fallback)=>{const index=process.argv.indexOf('--'+name);return index<0?fallback:process.argv[index+1];};
  const ticks=Number(option('ticks',3000)),every=Number(option('every',50));
  if(option('dump')){
    const [index,at]=option('dump').split(':').map(Number),scenario=SCENARIOS[index],run=createScenario(scenario);
    for(let tick=0;tick<at;tick++){run.sounds.length=0;advance(scenario,run);}
    const replacer=(key,value)=>SKIP.has(key)||typeof value==='function'?undefined:ArrayBuffer.isView(value)?[...value]:value instanceof Map?[...value]:value instanceof Set?[...value]:Object.is(value,-0)?'-0':value;
    console.log(JSON.stringify({...observe(run.simulation),sounds:run.sounds},replacer,1));
  }else{
    const started=performance.now(),results=SCENARIOS.map(scenario=>trace(scenario,{ticks,every}));
    const seconds=((performance.now()-started)/1000).toFixed(1);
    if(option('compare')){
      const expected=JSON.parse(fs.readFileSync(option('compare'),'utf8'));
      let failed=false;
      results.forEach((result,index)=>{
        const difference=firstDifference(expected.results[index],result);
        console.log(`${result.name.padEnd(24)} ${difference?`DIFFERS at tick ${difference.tick}: ${difference.groups.join(', ')}`:'identical'}  ${JSON.stringify(result.final)}`);
        if(difference)failed=true;
      });
      console.log(`${seconds}s`);process.exitCode=failed?1:0;
    }else{
      const out=option('out');
      if(out)fs.writeFileSync(out,JSON.stringify({ticks,every,results})+'\n');
      for(const result of results)console.log(result.name.padEnd(24),result.checkpoints.at(-1).groups.rng,JSON.stringify(result.final));
      console.log(`${seconds}s`);
    }
  }
}
