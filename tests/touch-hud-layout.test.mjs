import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {raceHudLayout} from '../source/race-hud-layout.js';
import {getHudMeshSpec,projectNativeHudPoint} from '../source/hud-mesh.js';
import {getHudStringSpec,layoutHudText} from '../source/hud-text.js';

const read=name=>JSON.parse(fs.readFileSync(new URL('../public/assets/'+name,import.meta.url)));
const config=read('config.json'),manifest=read('manifest.json');

test('large touch wheels leave standings and the original bonus frame separate on short landscape screens',()=>{
  const spec=getHudMeshSpec(config,manifest,'bonusframe'),bounds=manifest.meshes[spec.source].bounds;
  const ys=[bounds.minY,bounds.maxY].map(y=>projectNativeHudPoint([
    spec.transform.position[0],y*spec.transform.scale[1]+spec.transform.position[1],spec.transform.position[2]])[1]);
  for(const [width,height,touchHeight]of [[480,320,168],[568,320,168],[844,390,200],[1024,768,252]]){
    const layout=raceHudLayout(width,height,{touchHeight});
    const standingsBottom=layout.group('portraits').y+Number(config['overlay.ini'].portraits.height)*layout.scale;
    const bonus=layout.group('bonus'),bonusTop=bonus.y+Math.min(...ys)*layout.scale;
    const bonusBottom=bonus.y+Math.max(...ys)*layout.scale;
    assert.ok(bonusTop>standingsBottom,`${width}×${height}: bonus clears the full standings region`);
    assert.ok(bonusBottom<=height-touchHeight,`${width}×${height}: bonus clears touch controls`);
  }
});

test('landscape touch controls retain readable race-time glyph sizes and right-edge alignment',()=>{
  for(const [width,height,touchHeight]of [[480,320,168],[844,390,200]]){
    const layout=raceHudLayout(width,height,{touchHeight}),ordinary=raceHudLayout(width,height);
    for(const id of ['string_lap','string_lap_value','string_laptime_value','string_bestlap_value']){
      const a=layout.text(id),b=ordinary.text(id);
      assert.deepEqual(a,b,'touch band must not shrink or move race times');
      const glyphs=layoutHudText(getHudStringSpec(config,id),id==='string_lap'?'Ronde':'00:00:00');
      for(const glyph of glyphs.filter(glyph=>glyph.character!==' ')){
        assert.ok(glyph.height*a.scale>=8,'race-time glyph remains readable on a short screen');
        assert.ok(a.y+(glyph.y+glyph.height)*a.scale<height-touchHeight,'time text clears controls');
      }
    }
  }
});
