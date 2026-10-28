import assert from 'node:assert/strict';
import fs from 'node:fs';
import test from 'node:test';
import {getHudFont, getHudStringSpec, nativeGlyphCenters, layoutHudText,
  formatRaceTime, formatCountdownTime, getRaceHudText} from '../source/hud-text.js';

const json = file => JSON.parse(fs.readFileSync(new URL(file, import.meta.url)));
const config = json('../public/assets/config.json');
const native = json('../evidence/native/hud-text-fixtures.json');
const native53 = json('../evidence/native/hud-text-fixtures-53.json');
const transforms = json('../evidence/native/hud-string-transform-fixtures.json');
const near = (actual, expected, tolerance = 0.00005) => assert.ok(Math.abs(actual - expected) < tolerance,
  `${actual} != ${expected}`);

test('306 layouts match original fixed/proportional instructions exactly at both x87 precisions', () => {
  // tools/native-hud-fixtures.py probes at PC24, or at PC53 with RCSK_FIXTURE_PRECISION=53.
  assert.equal(native53.fpuControlWord, '0x027f (53-bit precision)');
  for (const [precision, fixture] of [[24, native], [53, native53]]) {
    for (const row of fixture.layouts) {
      const font = getHudFont(config, row.font);
      assert.deepEqual(nativeGlyphCenters(font, row.type, row.alignment,
        row.length, row.cellWidth, row.text, precision), row.glyphs,
      `${precision} ${row.font} ${row.type} ${row.alignment} ${row.length} ${JSON.stringify(row.text)}`);
    }
  }
});

test('atlas glyphs follow original character table, ASCII overrides and lowercase alias', () => {
  for (const name of ['alpha', 'numeric']) {
    const font = getHudFont(config, name), source = config['overlay.ini'][name];
    for (const [key, code] of Object.entries(native.fontCharacterMap)) {
      if (!source[key]) continue;
      const [texture, x, y, width, height] = source[key].split(';');
      assert.deepEqual(font.glyphs[String.fromCharCode(code)],
        {texture: `${texture}.tga`, x: +x, y: +y, width: +width, height: +height});
    }
    assert.equal(font.distance, -2);
    assert.ok(font.glyphs['/']);
    assert.ok(font.glyphs[':']);
  }
  const font = getHudFont(config, 'ALPHA');
  assert.equal(font.glyphs.r, font.glyphs.R);
  assert.equal(font.maxWidth, 23);
});

test('lap number and slash share original anchor and keep independent alignment', () => {
  const number = getHudStringSpec(config, 'STRING_LAP_VALUE');
  const suffix = getHudStringSpec(config, 'STRING_LAPOF_VALUE');
  number.position.forEach((x, i) => near(x, [600, 18][i]));
  suffix.position.forEach((x, i) => near(x, [600, 20][i]));
  assert.equal(number.alignment, 'right');
  assert.equal(suffix.alignment, 'left');
  const numeral = layoutHudText(number, '1').find(glyph => glyph.character === '1');
  const slash = layoutHudText(suffix, '/5')[0];
  assert.ok(numeral.centerX < 600);
  assert.ok(slash.centerX > 600);
  near(numeral.height, 19 * 1.5 * .99);
  near(slash.centerY, 20);
  const label = getHudStringSpec(config, 'STRING_LAP');
  assert.equal(label.alignment, 'left');
  assert.equal(label.text, 'Ronde');
  near(layoutHudText(label)[0].x, 360 + label.font.glyphs.R.width * .005);
});

test('all ten authored strings match forty original hierarchy/scale instruction cases', () => {
  // tools/native-hud-string-transform-fixtures.py executes 4606c0, 45c4d0,
  // 45caa0, 45cc00 -> 463c90 and 4589c0/463bb0 on the shipped overlay.ini.
  assert.equal(transforms.rows.length, 40);
  assert.deepEqual([...new Set(transforms.rows.map(row => row.precision))], [24, 53]);
  for (const row of transforms.rows) {
    const spec = getHudStringSpec(config, row.id, {precision: row.precision,
      overrides: row.override ? {[row.id]: {scale: row.override}} : {}});
    const label = `${row.id} precision${row.precision} ${row.override ? 'SetScale' : 'INI'}`;
    assert.deepEqual(spec.parentContext, row.parent, `${label} parent`);
    assert.deepEqual(spec.local.position, row.position, `${label} position`);
    assert.deepEqual(spec.local.scale, row.scale, `${label} scale`);
    assert.deepEqual(spec.context, row.context, `${label} context`);
  }
  const bonus = getHudStringSpec(config, 'string_bonus');
  bonus.position.forEach((x, i) => near(x, [70, 360][i]));
  assert.equal(layoutHudText(bonus).length, 5);
});

test('time formatting matches native signed division and original literals', () => {
  assert.equal(native.formatLiterals['0x4f6074'], '%02d:%02d:%02d');
  assert.equal(native.formatLiterals['0x4f6084'], '%d:%02d');
  for (const row of native.times) assert.equal(formatRaceTime(row.milliseconds), row.formatted);
  assert.equal(formatCountdownTime(65000), '65:00');
  assert.equal(formatCountdownTime(999), '0:99');
  assert.equal(formatCountdownTime(123456789), '123456:');
});

test('race HUD bindings clamp laps, preserve sentinel and accept held lap timer', () => {
  assert.deepEqual(getRaceHudText({lapCounter: 6, totalLaps: 5, lapTimeMs: 12345,
    heldLapTimeMs: 67890, countdownTimeMs: 6000}), {
    string_lap_value: '5', string_lapof_value: '/5', string_laptime_value: '01:07:89',
    string_bestlap_value: '--:--:--', string_countdown_value: '6:00',
  });
});
