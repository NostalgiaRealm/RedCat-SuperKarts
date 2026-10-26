import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {getNativeGameplayHudNotificationId as notificationId} from '../source/hud-gameplay-events.js';
import {getNativeNotificationEvent} from '../source/hud-notifications.js';

const config = JSON.parse(fs.readFileSync(new URL('../public/assets/config.json', import.meta.url)));

test('original lap and timeout callbacks keep their text IDs and event order', () => {
  const events = [{type:'lap'}, {type:'last-lap'}, {type:'lap-record'}, {type:'finished'},
    {type:'time-expired'}, {type:'damage-expired'}];
  assert.deepEqual(events.map(event => notificationId(event)), [undefined, 5, 6, undefined, 7, undefined]);
  assert.equal(getNativeNotificationEvent(config, notificationId(events[1])).text, 'Laatste ronde!');
  assert.equal(getNativeNotificationEvent(config, notificationId(events[4])).text, 'Tijd is om!');
});

test('455b00 reports every player-owned hit on an NPC, independent of effect acceptance', () => {
  for (const playerIndex of [1, 3, 4]) {
    for (let shooter = 0; shooter <= playerIndex; shooter++) {
      for (let racer = 0; racer <= playerIndex; racer++) {
        for (const phase of [0, 9, 25]) {
          const event = {type:'hit', shooter, racer, phase, accepted:phase !== 9};
          assert.equal(notificationId(event, {playerIndex}),
            shooter === playerIndex && racer < playerIndex ? 4 : undefined);
        }
      }
    }
  }
  assert.equal(getNativeNotificationEvent(config,
    notificationId({type:'hit', shooter:4, racer:0}, {playerIndex:4})).text, 'Raak!');
});

test('timed gates, pickups and rank changes do not invent dormant HUD messages', () => {
  for (const type of ['time-gate', 'time-tick', 'pickup', 'star', 'stars-complete',
    'superbonus', 'passing', 'turbo', 'fire', 'respawn', 'green', 'finished']) {
    assert.equal(notificationId({type, additionalMs:15000, sound:'CHECKPOINT', stars:12},
      {playerIndex:4}), undefined, type);
  }
  for (const event of [null, {}, {type:'hit', shooter:4, racer:-1},
    {type:'hit', shooter:4, racer:5}, {type:'hit', shooter:4, racer:.5}]) {
    assert.equal(notificationId(event, {playerIndex:4}), undefined);
  }
  assert.equal(notificationId({type:'hit', shooter:4, racer:0}), undefined);
});

test('explicit native events retain original IDs, including non-text controller requests', () => {
  for (let id = 0; id <= 11; id++) assert.equal(notificationId({type:'native-notification', id}), id);
  for (const id of [-1, 12, undefined, '4', NaN])
    assert.equal(notificationId({type:'native-notification', id}), undefined);
  assert.equal(getNativeNotificationEvent(config,
    notificationId({type:'native-notification', id:11})).text, 'Controlepunt!');
  for (const id of [0, 8, 9]) assert.equal(getNativeNotificationEvent(config,
    notificationId({type:'native-notification', id})), null);
});
