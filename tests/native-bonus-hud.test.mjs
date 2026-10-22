import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NATIVE_BONUS_HUD_ORIGIN, NativeBonusHud, updateNativeBonusHud } from '../src/simulation/native-bonus-hud.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/bonus-hud-fixtures.json', import.meta.url)));
test('960 complete native bonus HUD callbacks preserve restart, interpolation and final visibility at both precisions', () => {
  assert.deepEqual(NATIVE_BONUS_HUD_ORIGIN, fixtures.origin);
  for (const f of fixtures.cases) {
    assert.deepEqual(updateNativeBonusHud(structuredClone(f.state), f.owned, f.dt, f), f.expected);
  }
});
test('opening the bonus HUD caches inventory, while a later collection starts at the original origin', () => {
  const owned = { state: 1, type: 0, level: 0, angles: [0, 0, 0] };
  const hud = new NativeBonusHud({ destination: [0, 0, 0], owned });
  assert.equal(hud.step(owned, .025).phase, 0);
  Object.assign(owned, { state: 2, type: 1, level: 1 });
  assert.deepEqual(hud.step(owned, .025).position, NATIVE_BONUS_HUD_ORIGIN);
  for (let i = 0; i < 40; i++) hud.step(owned, .025);
  assert.equal(hud.state.phase, 2);
  assert.deepEqual(hud.state.position, [0, 0, 0]);
});
