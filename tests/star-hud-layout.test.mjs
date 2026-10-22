import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {raceHudLayout} from '../src/race-hud-layout.js';
import {getHudMeshSpec,projectNativeHudPoint} from '../src/hud-mesh.js';
import {getHudStringSpec,layoutHudText} from '../src/hud-text.js';

const read=name=>JSON.parse(fs.readFileSync(new URL('../public/assets/'+name,import.meta.url)));
const config=read('config.json'),manifest=read('manifest.json');
function fieldBounds(layout){
  const spec=getHudMeshSpec(config,manifest,'starflag',{overrides:{stars:{visible:true}}});
  const bounds=manifest.meshes[spec.source].bounds,group=layout.group('stars');
  const points=[bounds.minX,bounds.maxX].flatMap(x=>[bounds.minY,bounds.maxY].map(y=>{
    const p=projectNativeHudPoint([x*spec.transform.scale[0]+spec.transform.position[0],
      y*spec.transform.scale[1]+spec.transform.position[1],spec.transform.position[2]]);
    return [group.x+p[0]*layout.scale,group.y+p[1]*layout.scale];
  }));
  return {left:Math.min(...points.map(p=>p[0])),right:Math.max(...points.map(p=>p[0])),
    top:Math.min(...points.map(p=>p[1])),bottom:Math.max(...points.map(p=>p[1]))};
}

test('original star field remains at its authored anchor in 4:3 and widescreen',()=>{
  const reference=fieldBounds(raceHudLayout(640,480));
  assert.ok(Math.abs((reference.left+reference.right)/2-210)<.01);
  assert.ok(Math.abs((reference.top+reference.bottom)/2-47)<.01);
  for(const [width,height]of [[640,480],[1280,720],[2560,1440]]){
    const layout=raceHudLayout(width,height),field=fieldBounds(layout);
    for(const edge of ['left','right','top','bottom'])
      assert.ok(Math.abs(field[edge]-reference[edge]*layout.scale)<.01);
  }
});

test('portrait star field clears the timer text and touch controls without clipping',()=>{
  for(const [width,height,touchHeight]of [[320,568,100],[390,844,140],[768,1024,140]]){
    const layout=raceHudLayout(width,height,{left:8,right:8,top:8,bottom:20,touchHeight});
    const field=fieldBounds(layout);
    const timerBottom=Math.max(...['string_lap','string_laptime','string_bestlap',
      'string_lap_value','string_lapof_value','string_laptime_value','string_bestlap_value'].flatMap(id=>{
      const spec=getHudStringSpec(config,id),group=layout.text(id);
      return layoutHudText(spec,spec.text||'00:00:00').map(g=>group.y+(g.y+g.height)*layout.scale);
    }));
    assert.ok(field.top>timerBottom,`${width}: star field must clear times`);
    assert.ok(field.left>=8&&field.right<=width-8,`${width}: side clearance`);
    assert.ok(field.bottom<height-touchHeight-20,`${width}: touch clearance`);
  }
});
