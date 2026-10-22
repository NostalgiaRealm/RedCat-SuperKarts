import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {createNativeHudNotifications,showNativeHudNotification,stopNativeHudNotification,
  updateNativeHudNotifications,getNativeNotificationEvent} from '../src/hud-notifications.js';
const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/hud-notification-fixtures.json',import.meta.url)));
const config = JSON.parse(fs.readFileSync(new URL('../public/assets/config.json',import.meta.url)));

test('296 original notification updates preserve all animations, queueing and interruption',()=>{
  for(const row of fixture.rows){
    const state=createNativeHudNotifications({precision:row.precision});let dt=0;
    for(const [index,action]of row.actions.entries()){
      if(action.op==='message')showNativeHudNotification(state,action,dt);
      else if(action.op==='stop')stopNativeHudNotification(state);
      else {dt=action.delta;updateNativeHudNotifications(state,dt);}
      const actual={...state,queueLength:state.queue.length};delete actual.queue;delete actual.precision;
      assert.deepEqual(actual,action.expected,`precision${row.precision} step${index} ${JSON.stringify(action)}`);
    }
  }
});
test('notification dispatch retains original Dutch language IDs and excludes other HUD controller IDs',()=>{
  for(const[id,text]of [[1,'PAUZE'],[3,'Superbonus!'],[4,'Raak!'],[5,'Laatste ronde!'],
    [6,'Snelste ronde'],[7,'Tijd is om!'],[10,'Alle voorwerpen verzameld!'],[11,'Controlepunt!']]){
    assert.equal(getNativeNotificationEvent(config,id).text,text);
  }
  assert.deepEqual(getNativeNotificationEvent(config,2),{op:'stop'});
  for(const id of [0,8,9])assert.equal(getNativeNotificationEvent(config,id),null);
});
