import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs/promises';
import {RouteTestDriver} from './helpers/private-projected-line-driver.mjs';
import {wholeRaceSeamActive,projectedBaselineInput} from './helpers/private-whole-race-seam.mjs';
const root=new URL('../',import.meta.url);
const read=async p=>JSON.parse(await fs.readFile(new URL(p,root),'utf8'));

test('whole-race seam admits only the fixed after25s original corner windows and speed threshold',()=>{
  const simulation={movementActive:true,race:{elapsedMs:25000},motion:{body:{sector:129,forwardSpeed:10}}};
  for(const sector of [0,31,129,186]){simulation.motion.body.sector=sector;assert.equal(wholeRaceSeamActive(simulation),true);}
  for(const sector of [32,57,111,128]){simulation.motion.body.sector=sector;assert.equal(wholeRaceSeamActive(simulation),false);}
  simulation.motion.body.sector=129;simulation.race.elapsedMs=24999;assert.equal(wholeRaceSeamActive(simulation),false);
  simulation.race.elapsedMs=25000;simulation.motion.body.forwardSpeed=9.999;assert.equal(wholeRaceSeamActive(simulation),false);
  simulation.motion.body.forwardSpeed=10;simulation.movementActive=false;assert.equal(wholeRaceSeamActive(simulation),false);
});

test('projected seam keeps retained original nodes and exact baseline inputs at every outside-window sector',async()=>{
  const [track,cars,retained]=await Promise.all([read('public/assets/tracks/etappe3.json'),read('public/assets/cars.json'),
    read('evidence/full-race-matrix/timed-france-hard-reset-line1000-p3d06.json')]);
  const options={speed:170,lookAheadSeconds:1.05,steeringGain:3,dampingGain:.6,railBounds:cars.cars[1].bodyBounds};
  const driver=new RouteTestDriver(track,options),reference=new RouteTestDriver(track,options);
  for(const current of [driver,reference]){
    current.configureRacingLine(1000);current.testCollision=current.starPlanner=current.narrowStarPlanner=null;
    assert.deepEqual(current.racingLine,retained.runs[0].racingLine);
  }
  for(const elapsedMs of [24999,25000])for(let sector=0;sector<track.route.length;sector++){
    const p=track.drive[driver.racingLine[sector]].position,z=track.drive[driver.racingLine[(sector+1)%track.route.length]].position;
    const body={position:[...p],x:p[0],y:p[1],z:p[2],sector,forwardSpeed:60,
      yaw:Math.atan2(-(z[0]-p[0]),z[2]-p[2])*2048/Math.PI,yawRate:.01};
    const simulation={movementActive:true,race:{elapsedMs},motion:{body,mirrored:true}};
    if(wholeRaceSeamActive(simulation))continue;
    const before=JSON.stringify(body),now=elapsedMs+sector*25;
    const expected=reference.input(body,now,25,{});
    expected.steer=-expected.steer;expected.analog.steer=-expected.analog.steer;
    assert.deepEqual(projectedBaselineInput(driver,simulation,now,25,{}),expected);
    assert.equal(JSON.stringify(body),before);
  }
});
