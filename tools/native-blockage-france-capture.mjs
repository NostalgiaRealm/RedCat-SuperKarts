/** Read-only control-driven France contact capture; no simulation state writes. */
import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS} from '../src/simulation/clock.js';
import {RouteTestDriver} from '../tests/helpers/route-test-driver.mjs';
const read=async path=>JSON.parse(await fs.readFile(new URL(`../public/assets/${path}`,import.meta.url)));
const [config,manifest,cars,track]=await Promise.all(['config.json','manifest.json','cars.json','tracks/etappe3.json'].map(read));
const physicsBytes=await fs.readFile(new URL('../public/assets/physics/phys0.dat',import.meta.url));
const racerBytes=await fs.readFile(new URL('../public/assets/racer-tables/cars0.dat',import.meta.url));
const hash=async()=>crypto.createHash('sha256').update(await fs.readFile(new URL('../tests/helpers/route-test-driver.mjs',import.meta.url))).digest('hex');
const driverHash=await hash();
const random=new NativeRandom(0);
const simulation=new RaceSimulation({config,manifest,cars,track,physicsBytes,racerBytes,random,character:0,difficulty:0,raceMode:0});
random.seed(0);
const options={speed:30,lookAheadSeconds:.5,steeringGain:1.5,dampingGain:.5,
  railBounds:simulation.motion.collision.bounds,
  obstacles:simulation.physicalBodies.filter(body=>body!==simulation.motion.body)};
const driver=new RouteTestDriver(track,options);
const filter=new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS});
const bodyFields=['id','yaw','sector','lateralSpeed','verticalSpeed','forwardSpeed','yawRate',
  'pitch','roll','pitchRate','rollRate','inverseMass','inverseInertia','restitution','contactLatch'];
const bodyState=body=>({...Object.fromEntries(bodyFields.map(key=>[key,body[key]])),
  position:[...body.position],matrix:[...body.matrix],bounds:body.bounds??simulation.motion.collision.bounds});
const pair=contact=>contact?{point:contact.point,normal:contact.normal,
  first:contact.firstBody?.id,second:contact.secondBody?.id}:null;
let frame=null;
const collision=simulation.motion.collision,sample=collision.sample.bind(collision),resolve=collision.resolve.bind(collision);
collision.sample=(body,dt)=>{
  const before=bodyState(body),result=sample(body,dt);
  frame.steps.push({before,dt,fraction:result.fraction,stopYaw:result.stopYaw,
    contact:pair(result.contact),velocityOverride:result.velocityOverride});
  return result;
};
collision.resolve=(body,contact)=>{
  const result=resolve(body,contact);
  frame.steps.at(-1).afterResponse=bodyState(body);
  frame.steps.at(-1).impulse=result.impulse;
  return result;
};
const frames=[],samples=[];
let anchor=[...simulation.motion.body.position],stationaryMs=0,finished=false;
for(let now=25;now<=Number(process.env.RCSK_BLOCKAGE_MAX_MS??450000);now+=25) {
  const input=driver.input(simulation.motion.body,now,25);
  frame={now,input,driver:structuredClone(driver.telemetry),steps:[]};
  simulation.step(input,filter.sample(.025),now,{afterOpponentPrepare:(_actor,index)=>{
    if(index===simulation.opponents.length-1) {
      frame.before=simulation.actors.map(actor=>bodyState(actor.body));
      frame.force=structuredClone(simulation.motion.prepared.force);
    }
  }});
  frame.after=simulation.actors.map(actor=>bodyState(actor.body));
  frames.push(frame);if(frames.length>160)frames.shift();
  const body=simulation.motion.body;
  if(Math.hypot(body.x-anchor[0],body.z-anchor[2])<.01)stationaryMs+=25;
  else {anchor=[...body.position];stationaryMs=0;}
  if(now%5000===0) {
    const row={now,lap:simulation.race.lapCount,sector:body.sector,position:[...body.position],
      stationaryMs,recoveries:driver.recoveries,contacts:frame.steps.filter(x=>x.contact).map(x=>x.contact)};
    samples.push(row);console.log(JSON.stringify(row));
  }
  if(now>30000&&stationaryMs>=2500&&frame.steps.some(x=>x.contact?.second!==undefined)) {
    finished=true;break;
  }
  if(simulation.race.finished)break;
}
const report={scope:'Current composed race; ordinary analog controls from the shared test-only route driver. Wrappers record existing sample/response results and do not change them. No poses, timers, triggers, physical state, or rules are written.',
  driverHash,driverHashAfter:await hash(),track:3,difficulty:0,detectedRepeatedDynamicBlock:finished,
  retainedFrames:frames.length,samples,frames};
await fs.mkdir(new URL('../evidence/race-completion/',import.meta.url),{recursive:true});
await fs.writeFile(new URL('../evidence/race-completion/france-live-approach.json',import.meta.url),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({detectedRepeatedDynamicBlock:finished,time:frames.at(-1).now,driverChanged:report.driverHash!==report.driverHashAfter}));
