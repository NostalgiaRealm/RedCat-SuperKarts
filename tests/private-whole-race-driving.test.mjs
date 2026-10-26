import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs/promises';
import {createForecastRoute,projectForecastRoute,forecastRouteTarget,executeWholeRacePolicy,predictWholeRace} from './helpers/private-whole-race-driving.mjs';
import {hybridFranceLine} from './helpers/private-france-hybrid-driver.mjs';
import {executeClosedLoopPolicy} from './helpers/private-closed-loop-contact-driving.mjs';
import {createPrivateRaceSnapshotter} from './helpers/private-race-snapshot.mjs';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS} from '../source/simulation/clock.js';
const root=new URL('../',import.meta.url);
const read=async p=>JSON.parse(await fs.readFile(new URL(p,root),'utf8'));
const clamp=(v,a,b)=>Math.max(a,Math.min(b,v));
function oldProject(track,line,b){
  let best=null,offset=0;
  for(let i=0;i<line.length-1;i++){
    const a=track.drive[line[i].node].position,z=track.drive[line[i+1].node].position;
    const dx=z[0]-a[0],dz=z[2]-a[2],length=Math.hypot(dx,dz);
    if([b.sector,b.sector+track.route.length].some(s=>s>=line[i].sector-2&&s<=line[i+1].sector+2)){
      const fraction=clamp(((b.x-a[0])*dx+(b.z-a[2])*dz)/(length*length),0,1);
      const cross=Math.hypot(b.x-a[0]-fraction*dx,b.z-a[2]-fraction*dz);
      if(!best||cross<best.cross)best={i,fraction,cross,progress:offset+fraction*length};
    }
    offset+=length;
  }
  return {...best,total:offset};
}
function oldTarget(track,line,projection,distance,offset){
  let remaining=distance;
  for(let k=0;k<line.length;k++){
    const i=(projection.i+k)%(line.length-1),a=track.drive[line[i].node].position,z=track.drive[line[i+1].node].position;
    const fraction=k?0:projection.fraction,length=Math.hypot(z[0]-a[0],z[2]-a[2]),available=length*(1-fraction);
    if(remaining<=available){const t=fraction+remaining/length;return[a[0]+(z[0]-a[0])*t+(z[2]-a[2])/length*offset,0,a[2]+(z[2]-a[2])*t-(z[0]-a[0])/length*offset];}
    remaining-=available;
  }
  throw new Error('Old target unavailable');
}

test('whole-race cached route preserves previous projection and target arithmetic around every France sector and wrap',async()=>{
  const [track,groundReport,projectedReport]=await Promise.all([
    read('public/assets/tracks/etappe3.json'),read('evidence/full-race-matrix/timed-france-hard-reset-ground0.json'),
    read('evidence/full-race-matrix/timed-france-hard-reset-line1000-p3d06.json')]);
  const line=hybridFranceLine(groundReport.runs[0].racingLine,projectedReport.runs[0].racingLine);
  const route=createForecastRoute(track,line),before=JSON.stringify(line);
  for(let sector=0;sector<track.route.length;sector++)for(const offset of [-80,0,80]){
    const p=track.route[sector].position,b={sector,x:p[0]+offset,z:p[2]-offset};
    const expected=oldProject(track,line,b),actual=projectForecastRoute(route,b);
    assert.deepEqual(actual,expected);
    for(const distance of [40,240,740])for(const lateral of [-60,0,60])
      assert.deepEqual(forecastRouteTarget(route,actual,distance,lateral),oldTarget(track,line,expected,distance,lateral));
  }
  assert.equal(JSON.stringify(line),before);
  assert.ok(Object.isFrozen(route)&&Object.isFrozen(route.segments)&&route.segments.every(Object.isFrozen));
});

async function wholeFixture(){
  const [config,manifest,cars,track,physicsBytes,racerBytes,ground,projected]=await Promise.all([
    read('public/assets/config.json'),read('public/assets/manifest.json'),read('public/assets/cars.json'),
    read('public/assets/tracks/etappe3.json'),fs.readFile(new URL('public/assets/physics/phys2.dat',root)),
    fs.readFile(new URL('public/assets/racer-tables/cars2.dat',root)),
    read('evidence/full-race-matrix/timed-france-hard-reset-ground0.json'),
    read('evidence/full-race-matrix/timed-france-hard-reset-line1000-p3d06.json')]);
  const constructorOptions={config,manifest,cars,track,physicsBytes,racerBytes,
    character:1,difficulty:2,raceMode:1,countdown:true};
  function fresh(){
    const random=new NativeRandom(0),simulation=new RaceSimulation({...constructorOptions,random});random.seed(6);
    const filter=new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS});
    for(let now=25;now<=8000;now+=25){
      simulation.step({throttle:1,brake:0,steer:0,analog:{throttle:1,brake:0,steer:0}},filter.sample(.025),now);
      for(const actor of simulation.actors)if(actor.animationEvents)actor.animationEvents.length=0;
    }
    return {simulation,filter};
  }
  const line=hybridFranceLine(ground.runs[0].racingLine,projected.runs[0].racingLine);
  const route=createForecastRoute(track,line);
  const snapshotter=createPrivateRaceSnapshotter({constructorOptions,constructionSeed:0,
    permittedObservers:['onPlayerCollision']});
  return {fresh,track,line,route,snapshotter};
}

test('whole-race feedback preserves old control arithmetic and applies original mirrored input exactly once',async()=>{
  const fixture=await wholeFixture(),{simulation,filter}=fixture.fresh();
  const before=fixture.snapshotter.fingerprint(simulation,{filter});
  assert.equal(simulation.motion.mirrored,true,'France fixture exercises the mirrored input branch');
  let nonzero=0;
  for(const policy of [{look:.4,speed:50,offset:-60},{look:.7,speed:75,offset:0},{look:1,speed:120,offset:60}]){
    const old=executeClosedLoopPolicy(simulation.motion,fixture.track,fixture.line,policy);
    const actual=executeWholeRacePolicy(simulation,fixture.route,policy);
    assert.equal(actual.steer,-old.steer);
    assert.equal(actual.throttle,old.throttle);assert.equal(actual.brake,old.brake);
    assert.deepEqual(actual.analog,{throttle:old.throttle,brake:old.brake,steer:-old.steer});
    if(actual.steer)nonzero++;
  }
  assert.ok(nonzero>0,'nonzero steering must exercise the sign, not merely zero equality');
  assert.equal(fixture.snapshotter.fingerprint(simulation,{filter}),before);
});

test('whole-race candidate feedback matches independent full steps, leaves live state untouched and repeats A→B→A',async()=>{
  const fixture=await wholeFixture(),source=fixture.fresh(),reference=fixture.fresh();
  const native=source.simulation.onPlayerCollision;let observers=0;
  source.simulation.onPlayerCollision=contact=>{observers++;native(contact);};
  const before=fixture.snapshotter.fingerprint(source.simulation,{filter:source.filter});
  const copies=[];
  const snapshotter={clone(...args){const copy=fixture.snapshotter.clone(...args);copies.push(copy);return copy;}};
  const options={frames:8,lookaheads:[.7],speeds:[75],offsets:[-60]};
  const a=predictWholeRace(source.simulation,source.filter,snapshotter,fixture.route,options);
  const b=predictWholeRace(source.simulation,source.filter,snapshotter,fixture.route,{...options,offsets:[60]});
  const again=predictWholeRace(source.simulation,source.filter,snapshotter,fixture.route,options);
  assert.deepEqual(a.selection,again.selection);assert.deepEqual(a.candidates,again.candidates);
  assert.notDeepEqual(a.selection,b.selection);
  for(let i=0;i<8;i++){
    const sim=reference.simulation,input=executeWholeRacePolicy(sim,fixture.route,a.selection);
    sim.step(input,reference.filter.sample(.025),sim.wallMs+25);
    for(const actor of sim.actors)if(actor.animationEvents)actor.animationEvents.length=0;
  }
  assert.deepEqual(fixture.snapshotter.capture(copies[0].simulation,{filter:copies[0].filter}),
    fixture.snapshotter.capture(reference.simulation,{filter:reference.filter}));
  assert.equal(copies.length,3);
  for(const copy of copies)assert.ok(fixture.snapshotter.assertIsolated(source.simulation,copy.simulation));
  assert.equal(fixture.snapshotter.fingerprint(source.simulation,{filter:source.filter}),before);
  assert.equal(observers,0);
});
