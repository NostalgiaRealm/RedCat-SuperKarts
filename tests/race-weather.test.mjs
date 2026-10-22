import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {NATIVE_REFERENCE_UPTIME_MS,NativeDeltaFilter,SimulationClock} from '../src/simulation/clock.js';
import {nativeProjectileFacing} from '../src/simulation/native-projectile.js';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json')),cars=JSON.parse(read('cars.json'));
const input={throttle:0,brake:0,steer:0,handbrake:0,bonus:0};
function create(id,raceMode=0,settings=config){
  return new RaceSimulation({config:settings,manifest,cars,physicsBytes:read('physics/phys1.dat'),
    racerBytes:read('racer-tables/cars1.dat'),track:JSON.parse(read(`tracks/etappe${id}.json`)),
    raceMode,random:new NativeRandom(0)});
}

test('weather construction consumes the native shared random draws even for a paused pool',()=>{
  const disabled=structuredClone(config);disabled['sndgfx.ini']['gfx options'].particles='0';
  for(const id of [1,2,4]){
    const without=create(id,0,disabled),withWeather=create(id);
    const expected=new NativeRandom(without.pickups.random.state);
    for(let i=0;i<400*4;i++)expected.next();
    assert.equal(withWeather.pickups.random.state,expected.state,`country${id}`);
    assert.equal(withWeather.weather.random,withWeather.pickups.random);
  }
  assert.equal(create(4).weather.paused,true);
  assert.equal(create(0).weather,null);
});

test('advanced alpha and jetstream settings gate rescue effects and smoke independently',()=>{
  for(const alpha of [0,1])for(const jets of [0,1]){
    const settings=structuredClone(config),gfx=settings['sndgfx.ini']['gfx options'];
    gfx.alpha_blending=String(alpha);gfx.jetstreams=String(jets);gfx.clouds='1';
    const sim=create(0,0,settings);
    assert.equal(sim.smoke.enabled,Boolean(alpha));
    assert.equal(sim.rescue.options.effectsEnabled,Boolean(alpha&&jets));
  }
});

test('particle update follows camera/listener and precedes voices, skidmarks and render capture',()=>{
  const sim=create(1),stages=[];
  const explosion=sim.explosions.add(sim.motion.body);
  sim.step(input,.025,25,{
    afterCamera:()=>{
      stages.push('listener');
      assert.equal(sim.weather.particles[0].age,0);
      assert.equal(explosion.age,0);
      assert.equal(sim.nativeTickMs,NATIVE_REFERENCE_UPTIME_MS+25);
    },
    afterParticles:()=>{
      stages.push('voice');
      assert.equal(sim.weather.particles[0].age,Math.fround(.025));
      assert.equal(explosion.age,Math.fround(.025));
      sim.motion.slipMagnitude=8;sim.motion.ground.playerContact=true;
    },
    beforeBonuses:()=>{
      stages.push('render');
      assert.equal(sim.weatherFrames.length,400);
      assert.equal(sim.explosionFrames.length,1);
      assert.equal(sim.skidmarks.strips[0].tick,1);
      assert.equal(sim.skidmarkFrames.length,0); // First strip pair is only two vertices.
    },
  });
  sim.step(input,.025,50,{afterParticles:()=>{
    sim.motion.slipMagnitude=8;sim.motion.ground.playerContact=true;
  }});
  assert.equal(sim.skidmarkFrames[0].sides[0].length,4);
  assert.deepEqual(stages,['listener','voice','render']);
  assert.equal(sim.playerAnimationState.legacyAutopilotActive,false);
  assert.ok(sim.playerAnimationState.turboAgeMs>5000);
});

test('real PMP weather crossings honor DMP guards, unconditional snow, and reverse density',()=>{
  const rain=create(2),track=rain.race.track;
  const crossing=(sim,sector,previous,waypointMarker)=>{
    sim.motion.body.sector=sector;sim.motion.body.previousSector=previous;sim.race.previousSector=previous;
    if(waypointMarker!==null)sim.motion.body.waypoint=sim.race.track.drive.findIndex(node=>node.unknown[1]===waypointMarker);
    let observed;
    sim.step(input,.025,sim.wallMs+25,{beforePlayerPrepare:()=>observed=sim.weather.paused});
    return observed;
  };
  const stop=track.route.findIndex(route=>route.trigger===80||route.unknown===80);
  assert.equal(crossing(rain,stop,stop-1,80),true);
  const start=track.route.findIndex(route=>route.trigger===79||route.unknown===79);
  assert.equal(crossing(rain,start,start-1,80),true,'guarded wrong waypoint does not start rain');
  assert.equal(crossing(rain,start,start-1,79),false);
  const snow=create(1,1);
  assert.equal(snow.weather.paused,true);
  assert.equal(crossing(snow,111,110,null),false);
  assert.equal(crossing(snow,114,113,null),true);
  // England's sector1 dispatches83. Its direction is actor heading, not
  // whether the logical sector index increased.
  const density=create(2);
  density.motion.body.sector=1;density.motion.body.previousSector=0;density.race.previousSector=0;
  density.weather.percentageIndex=1;
  if(nativeProjectileFacing(density.race.track,density.motion.body)){
    density.motion.body.matrix[6]*=-1;density.motion.body.matrix[8]*=-1;
  }
  let count;
  density.step(input,.025,25,{beforePlayerPrepare:()=>count=density.weather.activeCount});
  assert.equal(count,100);
});

test('weather ages and shared random recycling are independent of presentation rate',()=>{
  const run=rate=>{
    const sim=create(2),filter=new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS});
    const clock=new SimulationClock({intervalMs:25,update:(dt,now)=>sim.step(input,filter.sample(dt),now)});
    clock.frame(0);
    for(let now=1000/rate;now<5000;now+=1000/rate)clock.frame(now);
    clock.frame(5000);
    return {particles:sim.weather.particles,frames:sim.weatherFrames,
      random:sim.weather.random.state,actors:sim.actors.map(actor=>actor.body.position)};
  };
  const expected=run(60);
  assert.deepEqual(run(31),expected);assert.deepEqual(run(144),expected);
});
