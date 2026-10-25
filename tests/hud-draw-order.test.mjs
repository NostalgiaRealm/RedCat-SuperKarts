import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeHudDrawOrder} from '../src/hud-draw-order.js';
import {createNativeStarHudConfig,getNativeStarHudCommands} from '../src/simulation/native-star-hud.js';

const config=JSON.parse(fs.readFileSync(new URL('../public/assets/config.json',import.meta.url)));

test('shipped HUD registration draws strings inside their original mesh hierarchy',()=>{
  assert.deepEqual(nativeHudDrawOrder(config),[
    'string_lap','string_laptime','string_bestlap','string_lap_value',
    'string_lapof_value','string_laptime_value','string_bestlap_value',
    'backredcat','backwhizzkitty','backbrutus','backmax','backcou',
    'frameredcat','framewhizzkitty','framebrutus','framemax','framecou',
    'portrredcat','portrwhizzkitty','portrbrutus','portrmax','portrcou',
    'first','second','third','fourth','fifth',
    'track','dotplayer','dotracer0','dotracer1','dotracer2','dotracer3','dotracer4',
    'bonusframe','bonusobject','string_bonus','starflag',
    '321timer0','321timer1','321timer2','backarrow','junctionarrow',
    'string_countdown_value','string_special',
  ]);
});

test('dynamic stars append inside Stars after its flag, before the countdown and root strings',()=>{
  const merged=createNativeStarHudConfig(config);
  const extraElements=getNativeStarHudCommands(0).map(({id})=>id);
  const order=nativeHudDrawOrder(merged,{extraElements});
  const stars=Array.from({length:12},(_,index)=>`star${index+1}`);
  assert.equal(order.length,57);
  assert.deepEqual(order.slice(order.indexOf('string_bonus'),order.indexOf('backarrow')),
    ['string_bonus','starflag',...stars,'321timer0','321timer1','321timer2']);
  assert.deepEqual(order.slice(-4),['backarrow','junctionarrow','string_countdown_value','string_special']);
  assert.equal(order.filter(id=>id==='starflag').length,1,'Existing definitions are not registered twice');
  assert.equal(config['overlay.ini'].star1,undefined,'Merged definitions leave original configuration untouched');
});

test('numbered registries and nested parents control order, while inactive definitions stay excluded',()=>{
  const overlay={
    composites:{2:'Unused',1:'Nested',0:'Panel',count:'2'},
    elements:{2:'Dormant',1:'Hidden',0:'Face',count:'2'},
    strings:{0:'Label',count:'1'},
    panel:{parent:'Screen'},nested:{parent:'Panel'},
    face:{parent:'Panel'},hidden:{parent:'Nested',visible:'false'},
    label:{parent:'Panel'},extra:{parent:'Nested'},
    dormant:{parent:'Screen'},unused:{parent:'Screen'},
  };
  assert.deepEqual(nativeHudDrawOrder({'overlay.ini':overlay},{extraElements:['Extra']}),
    ['hidden','extra','face','label']);
});
