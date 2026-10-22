import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {configWithNativeDisplaySettings,nativeTextureGamma} from '../src/simulation/native-display-settings.js';
import {getNativeWeatherSpec} from '../src/simulation/native-weather.js';

const config=JSON.parse(readFileSync(new URL('../public/assets/config.json',import.meta.url)));
const native=JSON.parse(readFileSync(new URL('../evidence/native/texture-key-fixtures.json',import.meta.url)));
test('display overrides preserve source config and toggle the real weather construction gate',()=>{
  const baseline=JSON.stringify(config);
  assert.equal(configWithNativeDisplaySettings(config),config);
  const changed=configWithNativeDisplaySettings(config,{
    brightnessLight:false,bilinearFiltering:false,alphaBlending:false,particles:false,
  });
  assert.equal(changed['game.ini'].options.filter,'0');
  assert.deepEqual(['gamma','alpha_blending','particles'].map(key=>changed['sndgfx.ini']['gfx options'][key]),['1','0','0']);
  assert.ok(getNativeWeatherSpec(config,0,1));
  assert.equal(getNativeWeatherSpec(changed,0,1),null);
  assert.equal(JSON.stringify(config),baseline);
});

test('pre-filter gamma reproduces all native RGB converter fixture outputs before device packing',()=>{
  let count=0;
  for(const grid of native.quantizationGrids)for(const sample of grid.cases){
    const [r,g,b,a]=nativeTextureGamma([...sample.rgb,255],grid.gamma!==0);
    assert.equal(a,255);
    const key=sample.rgb[0]===255&&sample.rgb[1]===0&&sample.rgb[2]===127;
    let red=r>>3,green=g>>(grid.pixelFormat==='RGB565'?2:3),blue=b>>3;
    if(key)red=green=blue=0;
    else if(!red&&!green&&!blue)red=1;
    const packed=(red<<(grid.pixelFormat==='RGB565'?11:10))+(green<<5)+blue;
    assert.equal(packed,sample.packed,JSON.stringify({grid:grid.pixelFormat,gamma:grid.gamma,sample}));
    count++;
  }
  assert.equal(count,3072);
  const input=new Uint8ClampedArray([40,120,200,0,255,255,255,255]);
  assert.deepEqual([...nativeTextureGamma(input,true)],[6,56,156,0,254,254,254,255]);
  assert.deepEqual([...nativeTextureGamma(input,false)],[...input]);
  assert.deepEqual([...input],[40,120,200,0,255,255,255,255]);
});
