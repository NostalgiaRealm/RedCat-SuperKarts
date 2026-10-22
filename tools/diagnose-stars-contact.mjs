import fs from 'node:fs';
import crypto from 'node:crypto';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';

const file=process.argv[2]??'evidence/full-race-matrix/stars-difficulty0-attempt1.json';
const trackIndex=Number(process.argv[3]??0),difficulty=Number(process.argv[4]??0);
const bytes=fs.readFileSync(file),retained=JSON.parse(bytes);
const run=retained.runs.find(run=>run.track===trackIndex&&run.difficulty===difficulty);
const read=path=>fs.readFileSync(new URL('../public/assets/'+path,import.meta.url));
const json=path=>JSON.parse(read(path));
const simulation=new RaceSimulation({
  config:json('config.json'),manifest:json('manifest.json'),cars:json('cars.json'),
  track:json(`tracks/etappe${trackIndex}.json`),physicsBytes:read(`physics/phys${difficulty}.dat`),
  racerBytes:read(`racer-tables/cars${difficulty}.dat`),random:new NativeRandom(0),
  character:0,difficulty,raceMode:2,
});
const body=simulation.motion.body,captured=run.finalDiagnostics.player;
Object.assign(body,{yaw:captured.yaw,sector:captured.sector,previousSector:captured.sector,
  forwardSpeed:captured.forwardSpeed,lateralSpeed:captured.lateralSpeed,
  verticalSpeed:captured.verticalSpeed,yawRate:captured.yawRate});
body.position.splice(0,3,...captured.position);
const collision=simulation.motion.collision;
const rectangle=obstacle=>({
  minX:obstacle.minX,maxX:obstacle.maxX,minZ:obstacle.minZ,maxZ:obstacle.maxZ,
  position:obstacle.position,angle:obstacle.angle,type:obstacle.type,
  placement:obstacle.body?.placementIndex,mesh:obstacle.body?.mesh,
});
const report={
  scope:'Isolated contact queries at a retained star-race pose against original map rails and initial scenery. '+
    'Nearby solid scenery is static; this does not recreate every actor or dynamic object from the full race. '+
    'The query directions are synthetic diagnostics and never alter a validation race.',
  capture:file,captureSha256:crypto.createHash('sha256').update(bytes).digest('hex'),
  position:body.position,yaw:body.yaw,sector:body.sector,bounds:collision.bounds,
  nearby:collision.candidates(body.sector,body).filter(obstacle=>
    Math.hypot(obstacle.position[0]-body.x,obstacle.position[2]-body.z)<250).map(rectangle),
  queries:[],
};
for(const yaw of [captured.yaw,0,512,1024,1536,2048,2560,3072,3584]){
  for(const forwardSpeed of [-10,10]){
    const result=collision.sweep({...body,sourceBody:body,position:[...body.position],
      yaw,forwardSpeed,lateralSpeed:0,verticalSpeed:0,yawRate:0},.2);
    const contact=result.contact;
    report.queries.push({yaw,forwardSpeed,fraction:result.fraction,stopYaw:result.stopYaw,
      contact:contact&&{point:contact.point,normal:contact.normal,
        firstPlacement:contact.firstBody?.placementIndex,
        secondPlacement:contact.secondBody?.placementIndex,
        firstMesh:contact.firstBody?.mesh,secondMesh:contact.secondBody?.mesh}});
  }
}
const output=process.argv[5]??'evidence/full-race-matrix/stars-nederland-easy-contact.json';
fs.writeFileSync(output,JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report,null,2));
