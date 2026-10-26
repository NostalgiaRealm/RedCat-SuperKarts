import fs from 'node:fs';
import assert from 'node:assert/strict';
import {NativeRailCollision} from '../source/simulation/native-collision.js';
import {integrateNativeEuler,quantizeNativePlanarVelocity} from '../source/simulation/native-integrator.js';
import {nativeRotationMatrix} from '../source/simulation/native-transform.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/race-completion/france-native-frame-fixtures.json',import.meta.url)));
const track={collision:[],route:Array.from({length:187},()=>({collisionIndices:[]}))};
const zero={lateralForce:0,verticalForce:0,longitudinalForce:0,torque:0};
const differences=[];
for(const c of fixture.cases) {
  const bodies=c.actors.map((actor,id)=>({...structuredClone(actor),id,sector:112,bounds:fixture.bounds,
    get x(){return this.position[0]},set x(value){this.position[0]=value},
    get y(){return this.position[1]},set y(value){this.position[1]=value},
    get z(){return this.position[2]},set z(value){this.position[2]=value}}));
  const collision=new NativeRailCollision(track,fixture.bounds,{precision:c.precision});
  collision.bodies=bodies;
  for(const [frame,expected] of c.frames.entries()) {
    for(const [index,body] of bodies.entries()) {
      quantizeNativePlanarVelocity(body,c.precision);
      const count=index===0?8:1,dt=Math.fround(c.dt/count);
      for(let step=0;step<count;step++) {
        const contact=index===0?collision.sample(body,dt):collision.sweep(body,dt);
        integrateNativeEuler(body,index===0?c.force:zero,dt,{...contact,precision:c.precision});
        body.matrix=nativeRotationMatrix([body.pitch,body.yaw,body.roll],{precision:c.precision});
        if(contact.contact)collision.resolve(body,contact.contact);
        collision.finishStep(body,contact.contact);
      }
    }
    for(let index=0;index<bodies.length;index++)for(const [key,value] of Object.entries(expected.actors[index])) {
      try { assert.deepEqual(bodies[index][key],value); }
      catch {
        differences.push({precision:c.precision,variant:c.variant,frame,actor:index,key,
          actual:bodies[index][key],expected:value});
      }
    }
    if(collision.contactState.impulse!==expected.impulse)
      differences.push({precision:c.precision,variant:c.variant,frame,key:'impulse',
        actual:collision.contactState.impulse,expected:expected.impulse});
  }
}
const report={scope:fixture.scope,nativeFrames:fixture.cases.reduce((n,c)=>n+c.frames.length,0),
  status:differences.some(row=>row.precision===24)?'active-precision-differences':'active-precision-exact',
  byPrecision:[24,53].map(precision=>({precision,frames:fixture.cases.filter(row=>row.precision===precision)
    .reduce((n,c)=>n+c.frames.length,0),differences:differences.filter(row=>row.precision===precision).length})),
  differences};
fs.writeFileSync(new URL('../evidence/race-completion/france-native-frame-comparison.json',import.meta.url),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({status:report.status,nativeFrames:report.nativeFrames,differences:differences.length,
  first:differences.slice(0,6)},null,2));
if(report.status!=='active-precision-exact')process.exitCode=1;
