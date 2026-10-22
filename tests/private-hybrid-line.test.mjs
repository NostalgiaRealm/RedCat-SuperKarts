import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs/promises';
import {hybridFranceLine,RouteTestDriver} from './helpers/private-france-hybrid-driver.mjs';
import {RouteTestDriver as ProjectedDriver} from './helpers/private-projected-line-driver.mjs';
const root=new URL('../',import.meta.url);
const read=async path=>JSON.parse(await fs.readFile(new URL(path,root),'utf8'));
const ground=(await read('evidence/full-race-matrix/timed-france-hard-reset-ground0.json')).runs[0].racingLine;
const projected=(await read('evidence/full-race-matrix/timed-france-hard-reset-line1000-p3d06.json')).runs[0].racingLine;

test('private France hybrid joins only retained edges at shared nodes and leaves source routes unchanged',()=>{
  const before=JSON.stringify({ground,projected}),line=hybridFranceLine(ground,projected);
  assert.deepEqual(line.filter(p=>p.sector<=57),ground.filter(p=>p.sector<=57));
  assert.deepEqual(line.filter(p=>p.sector>=171),ground.filter(p=>p.sector>=171));
  assert.deepEqual(line.filter(p=>p.sector>=57&&p.sector<=171),
    projected.flatMap((node,sector)=>sector>=57&&sector<=171?[{sector,node}]:[]));
  assert.equal(JSON.stringify({ground,projected}),before);
  assert.throws(()=>hybridFranceLine(ground,projected.map((node,i)=>i===57?node+1:node)),/same original node/);
});

test('private hybrid retains exact projected controller inputs outside forecast in the middle course',async()=>{
  const track=await read('public/assets/tracks/etappe3.json');
  const options={speed:170,lookAheadSeconds:1.05,steeringGain:3,dampingGain:.6};
  const hybrid=new RouteTestDriver(track,options),baseline=new ProjectedDriver(track,options);
  hybrid.configureHybridLine(ground,projected);
  baseline.racingLine=[...projected];
  baseline.racingLineNext=new Map(projected.map((node,i)=>[node,projected[(i+1)%projected.length]]));
  const hybridLine=hybrid.racingLine;
  for(let sector=58;sector<=110;sector++) {
    const p=track.drive[projected[sector]].position,z=track.drive[projected[sector+1]].position;
    const body={position:[...p],x:p[0],y:p[1],z:p[2],sector,forwardSpeed:60,
      yaw:Math.atan2(-(z[0]-p[0]),z[2]-p[2])*2048/Math.PI,yawRate:.01};
    const before=JSON.stringify(body);
    assert.deepEqual(hybrid.input(body,sector*25,25,{}),baseline.input(body,sector*25,25,{}));
    assert.equal(JSON.stringify(body),before);
    assert.equal(hybrid.racingLine,hybridLine);
  }
});
