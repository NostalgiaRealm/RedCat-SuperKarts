import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {getNativeHudCameraSpec,nativeHudCompositeTransform,nativeHudElementTransform,
  getHudMeshSpec,projectNativeHudPoint} from '../src/hud-mesh.js';
const read=path=>JSON.parse(fs.readFileSync(new URL(path,import.meta.url)));
const fixture=read('../evidence/native/hud-transform-fixtures.json');
const config=read('../public/assets/config.json'),manifest=read('../public/assets/manifest.json');

test('HUD transforms match72 original instruction cases at24/53-bit precision',()=>{
  for(const row of fixture.rows){
    const options={precision:row.precision};
    const input={position:row.position,scale:row.scale,rotation:row.rotation,width:row.width,height:row.height};
    assert.deepEqual(getNativeHudCameraSpec(640,480,options).pixelScale,row.pixelScale);
    assert.deepEqual(nativeHudCompositeTransform(input,row.parent,options),row.composite);
    assert.deepEqual(nativeHudElementTransform(input,row.parent,options),row.element);
    assert.equal(row.packedColor,0x7fff8040);
  }
});

test('all six original minimaps resolve through centered parent and native depth',()=>{
  for(let trackId=0;trackId<6;trackId++){
    const map=getHudMeshSpec(config,manifest,'Track',{trackId});
    assert.match(map.mesh,/ovltrck[1-6]\.json$/);
    assert.ok(map.transform.position[2]>1);
    const p=projectNativeHudPoint(map.transform.position);
    assert.ok(Math.abs(p[0]-540)<.01);assert.ok(Math.abs(p[1]-400)<.01);
  }
  const bonus=getHudMeshSpec(config,manifest,'Bonusframe');
  assert.deepEqual(bonus.rgba,[255,255,255,255]);
  assert.ok(Math.abs(projectNativeHudPoint(bonus.transform.position)[0]-70)<.001);
  assert.equal(bonus.colorOperation,'replace-vertex-rgba');
});

test('321 player keeps native normalized positions and three original frames',()=>{
  for(let i=0;i<3;i++)for(let frame=0;frame<3;frame++){
    const id=`321timer${i}`,x=[-.328125,0,.328125][i];
    const mesh=getHudMeshSpec(config,manifest,id,{animation:'321player',frame,
      overrides:{[id]:{position:[x,.4,0]}}});
    assert.equal(mesh.source,`start${frame+1}.d3d`);
    const point=projectNativeHudPoint(mesh.transform.position);
    assert.ok(Math.abs(point[0]-[241.25,320,398.75][i])<.001);
    assert.ok(Math.abs(point[1]-144)<.001);
  }
});
