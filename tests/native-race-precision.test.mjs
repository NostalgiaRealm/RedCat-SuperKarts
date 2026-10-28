import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NATIVE_PRECISION } from '../source/simulation/native-precision.js';
import { updateNativeAIWheels } from '../source/simulation/native-ai.js';
import { NativeAIDriver, NativeWaypointOccupancy, nativeAIFlagExpired, nativeRoutePlaneHeight, nativeRouteSpringHeight }
  from '../source/simulation/native-ai-driver.js';
import { nativeRaceGrid, nativeRaceHeading } from '../source/simulation/native-race-setup.js';
import { NativePlayerMotion, nativeStandardKartInertia } from '../source/simulation/native-motion.js';
import { NativeBonusPickups, NativeRandom, nativeBonusOverlap, nativeTrackPickups } from '../source/simulation/native-bonus.js';
import { NativeBonusCombat } from '../source/simulation/native-combat.js';
import { nativeProjectileFacing, nativeProjectileLaunchPose } from '../source/simulation/native-projectile.js';
import { NativeGroundClock } from '../source/simulation/native-ground.js';
import { NativeRailCollision } from '../source/simulation/native-collision.js';
import { createNativeTrack, sampleNativeTrack, selectNativeSector } from '../source/simulation/native-track.js';
import { nativePlayerStart } from '../source/simulation/native-start.js';
import { parsePhysicsTable, parseRacerTable } from '../source/simulation/native-tables.js';

const f32 = Math.fround;
const read = path => JSON.parse(readFileSync(new URL(`../${path}`, import.meta.url)));
const fixtures = { 24: read('evidence/gameplay/native-race-precision-fixtures.json'),
  53: read('evidence/gameplay/native-race-precision-fixtures-53.json') };
const sectorFixture = read('evidence/gameplay/native-track-fixtures.json');
const tracks = Array.from({ length: 6 }, (_, id) => read(`public/assets/tracks/etappe${id}.json`));
const config = read('public/assets/config.json');
const bonusConfig = config['game.ini'].bonus_data;
const manifest = read('public/assets/manifest.json');
const geometry = read('public/assets/cars.json').cars[0];
const physics = parsePhysicsTable(readFileSync(new URL('../public/assets/physics/phys1.dat', import.meta.url)))[0];
const inventory = read('evidence/gameplay/inventory.json');
const racerSource = inventory.binaryTables.find(table => table.source === 'cars1.dat');
const racerBytes = new Uint8Array(racerSource.bytes), racerView = new DataView(racerBytes.buffer);
racerSource.records.forEach(record => record.uint32.forEach((value, i) => racerView.setUint32(record.offset + i * 4, value, true)));
const racers = parseRacerTable(racerBytes);
const bounds = geometry.bodyBounds;
const registerRounding = precision => (precision === 24 ? f32 : Number);

// The probe's sector planes/forward axes are the 24-bit native sector fixture.
const fixtureWorld = id => ({ sectors: sectorFixture.tracks[id].sectors.map((sector, i) => ({
  ...sector, position: tracks[id].route[i].position })) });

function driverFor(id, precision) {
  const track = tracks[id], world = createNativeTrack(track, { precision });
  return new NativeAIDriver({ track, world, geometry, start: nativePlayerStart(track, world, { precision }), id: 1,
    racer: racers[1], playerRacer: racers[0], random: new NativeRandom(1999),
    occupancy: new NativeWaypointOccupancy(track, { precision }), groundClock: new NativeGroundClock(),
    collision: new NativeRailCollision(track, bounds, { precision }), efficiency: 10, precision });
}

test('fixtures probe identical inputs at control words 0x007f and 0x027f', () => {
  assert.equal(fixtures[24].fpuControlWord, '0x007f');
  assert.equal(fixtures[53].fpuControlWord, '0x027f');
  assert.equal(fixtures[24].sourceSha256, sectorFixture.sourceSha256);
  assert.equal(fixtures[53].sourceSha256, sectorFixture.sourceSha256);
  const inputs = {
    routePlane: c => [c.track, c.sector, c.point], timers: c => [c.now, c.start],
    inertia: c => [c.car, c.mass, c.length, c.width], overlaps: c => [c.a, c.b],
    pickupYaw: c => [c.yaw, c.dt, c.speed], suspensionClamp: c => [c.track, c.sector, c.point],
    bubbleSpring: c => [c.track, c.sector, c.floating, c.dt, c.body],
  };
  for (const [key, pick] of Object.entries(inputs)) {
    assert.deepEqual(fixtures[53][key].map(pick), fixtures[24][key].map(pick), key);
  }
  // Every probed group has native outputs that differ between the two widths.
  const differs = (key, pick) => fixtures[24][key].filter((c, i) => !Object.is(pick(c), pick(fixtures[53][key][i]))).length;
  assert.ok(differs('routePlane', c => c.height) > 0);
  assert.ok(differs('timers', c => `${c.hitExpired}${c.turboExpired}`) > 0);
  assert.ok(differs('inertia', c => c.inverseInertia) > 0);
  assert.ok(differs('overlaps', c => c.expected) > 0);
  assert.ok(differs('pickupYaw', c => c.expected) > 0);
  assert.ok(differs('suspensionClamp', c => c.clamped) > 0);
  assert.ok(differs('bubbleSpring', c => c.verticalSpeed) > 0);
  assert.ok(differs('bubbleSpring', c => c.playerSlipCleared) > 0);
  assert.ok(fixtures[24].headings.some((t, i) => t.yaws.some((y, s) => y !== fixtures[53].headings[i].yaws[s])));
});

for (const precision of [24, 53]) {
  const fixture = fixtures[precision], r = registerRounding(precision), options = { precision };

  test(`${precision}-bit 0x494b70 route height and 0x41c4b0 suspension match native exactly`, () => {
    for (const c of fixture.routePlane) {
      const plane = sectorFixture.tracks[c.track].sectors[c.sector].fallback;
      const height = nativeRoutePlaneHeight(plane, c.point[0], c.point[2], options);
      assert.ok(Object.is(height, c.height), `${c.track}:${c.sector} height ${height} != ${c.height}`);
      assert.ok(Object.is(f32(r(height - c.point[1])), c.suspension));
    }
    assert.equal(fixture.routePlane.length, 240);
  });

  test(`${precision}-bit NPC driver wheels and route sampler use the 0x494b70 register height`, () => {
    let sampled = 0;
    for (let id = 0; id < 6; id++) {
      const driver = driverFor(id, precision), world = fixtureWorld(id);
      driver.world = world;
      for (const c of fixture.routePlane.filter(c => c.track === id)) {
        driver.prepared = null;
        driver.body.sector = c.sector;
        driver.body.position.splice(0, 3, ...c.point);
        driver.prepare(.025, { active: false });
        const suspension = Math.max(f32(-1.11), Math.min(0, c.suspension));
        driver.ground.wheels.forEach((wheel, i) => assert.ok(Object.is(wheel.local[1], f32(suspension + wheel.radius)),
          `${id}:${c.sector} wheel ${i}`));
        // 0x413330 selects from the current sector before 0x494b70.
        if (selectNativeSector(world, c.sector, c.point[0], c.point[2], options) === c.sector) {
          assert.ok(Object.is(driver.sampleRouteHeight(...c.point), c.height));
          sampled++;
        }
      }
    }
    assert.ok(sampled > 100, `only ${sampled} route samples stayed in their sector`);
  });

  test(`${precision}-bit 0x41c4b0 suspension clamp (0x41c737 ST0 vs 0, 0x41c752 float vs -1.11) matches native`, () => {
    const limit = f32(-1.11), near = 2 ** -10, classes = new Map();
    let unrounded = 0;
    for (const c of fixture.suspensionClamp) {
      const label = `${c.track}:${c.sector} y=${c.point[1]}`;
      const plane = sectorFixture.tracks[c.track].sectors[c.sector].fallback;
      const height = nativeRoutePlaneHeight(plane, c.point[0], c.point[2], options);
      assert.ok(Object.is(height, c.height), `${label} height ${height} != ${c.height}`);
      // FSUB 0x41c72f leaves this difference in ST0; FST 0x41c733 stores the float.
      const register = r(height - c.point[1]);
      assert.ok(Object.is(f32(register), c.suspension), `${label} suspension`);
      // Zero-radius wheels expose the clamped [ESP+0x18] float unchanged.
      const state = { wheels: [0, 1, 2, 3].map(() => ({ local: [0, 0, 0], radius: 0, spin: 0, steeringAngle: 0 })) };
      updateNativeAIWheels({ y: c.point[1], forwardSpeed: 0, yawRate: 0 }, state, .025, height, options);
      state.wheels.forEach((wheel, i) => assert.ok(Object.is(wheel.local[1], c.clamped),
        `${label} wheel ${i}: ${wheel.local[1]} != ${c.clamped}`));
      const key = Math.abs(c.suspension) <= near ? `0${Math.sign(c.suspension)}`
        : Math.abs(c.suspension - limit) <= near ? `limit${Math.sign(c.suspension - limit)}` : 'outside';
      classes.set(key, (classes.get(key) ?? 0) + 1);
      if (Math.abs(register) <= near && register !== 0 && !Object.is(f32(register), register)) unrounded++;
    }
    for (const key of ['0-1', '00', '01', 'limit-1', 'limit0', 'limit1']) {
      assert.ok(classes.get(key) > 0, `no case ${key}: ${JSON.stringify([...classes])}`);
    }
    // At PC=53 the 0x41c737 comparison sees differences that are not floats.
    assert.equal(unrounded > 0, precision === 53);
    // The driver feeds the same clamp to all four wheels: FLD clamp, FADD
    // radius, FST float (0x41c76e..0x41c819).
    for (let id = 0; id < 6; id++) {
      const driver = driverFor(id, precision);
      driver.world = fixtureWorld(id);
      for (const c of fixture.suspensionClamp.filter(c => c.track === id)) {
        driver.prepared = null;
        driver.body.sector = c.sector;
        driver.body.position.splice(0, 3, ...c.point);
        driver.prepare(.025, { active: false });
        driver.ground.wheels.forEach((wheel, i) => assert.ok(Object.is(wheel.local[1], f32(r(c.clamped + wheel.radius))),
          `${id}:${c.sector} y=${c.point[1]} wheel ${i}`));
      }
    }
    assert.equal(fixture.suspensionClamp.length, 352);
  });

  test(`${precision}-bit bubble spring callers sample the 0x413330 route plane, not 0x496290`, () => {
    const ground = () => ({ groundCount: 0, wheels: [0, 1, 2, 3].map(() => ({ verticalSpeed: 0 })) });
    let compared = 0, triangleDiffers = 0;
    const kinds = new Set();
    for (let id = 0; id < 6; id++) {
      // Probe planes and axes, over the port's triangles so 0x496290 stays callable.
      const probe = fixtureWorld(id).sectors, triangles = createNativeTrack(tracks[id], options);
      const world = { ...triangles, sectors: triangles.sectors.map((sector, i) => ({ ...sector,
        side: probe[i].side, forward: probe[i].forward, fallback: probe[i].fallback, position: probe[i].position })) };
      // Native object order: NPCs, then the player ([0x53be28]).
      const actors = [{ ground: ground(), radius: 10, phase: 0 }, { ground: ground(), radius: 10, phase: 0 }];
      const pickups = new NativeBonusPickups({ pickups: nativeTrackPickups(tracks[id], manifest, config), racerCount: 2,
        raceType: 2, bonusConfig, random: new NativeRandom(3), precision });
      const combat = new NativeBonusCombat({ actors, pickups, config, manifest, world, shotClearance: 0, precision });
      for (const c of fixture.bubbleSpring.filter(c => c.track === id)) {
        const label = `${id}:${c.sector} ${c.floating ? 'floating' : 'grounded'}`;
        // The probe's 0x4977d0 returns the +0x1c hint.
        if (selectNativeSector(world, c.sector, ...c.sample, options) !== c.sector) continue;
        assert.ok(Object.is(f32(nativeRouteSpringHeight(world, c.sector, ...c.sample, options)), c.height), `${label} height`);
        const triangle = sampleNativeTrack(world, c.sector, c.sample[0], c.body.position[1], c.sample[1], options);
        if (f32(triangle.height) !== c.height) triangleDiffers++;
        actors.forEach((actor, index) => {
          const player = index === actors.length - 1;
          Object.assign(actor, { body: { ...structuredClone(c.body), sector: c.sector, pitch: 0, roll: 0,
            pitchRate: 0, rollRate: 0 }, slipMagnitude: 7, lowSpeedTurn: true });
          actor.ground.groundCount = c.floating ? 0 : 4;
          combat.effects[index] = { active: true, mode: 6, type: 2, level: 1, remaining: c.floating ? 1 : -1,
            bubbleVisible: false };
          combat.prepareEffect(index, c.dt);
          assert.ok(Object.is(actor.body.verticalSpeed, c.verticalSpeed),
            `${label} ${player ? 'player' : 'NPC'} verticalSpeed ${actor.body.verticalSpeed} != ${c.verticalSpeed}`);
          // 0x4125f1/0x412602 zero these before the floating 0x413330 call.
          if (c.floating) assert.deepEqual([actor.body.lateralSpeed, actor.body.forwardSpeed], [0, 0]);
          const cleared = player ? c.playerSlipCleared : c.npcSlipCleared;
          assert.equal(actor.slipMagnitude, cleared ? 0 : 7, `${label} ${player ? 'player' : 'NPC'} [0x50728c]`);
          assert.equal(actor.lowSpeedTurn, !cleared);
        });
        kinds.add(`${c.floating}/${c.playerSlipCleared}`);
        compared++;
      }
    }
    assert.ok(compared >= 70, `only ${compared} bubble samples kept their hint sector`);
    assert.equal(kinds.size, 4, 'floating/grounded and cleared/kept slip must all be compared');
    assert.ok(triangleDiffers > 0, 'the 0x496290 triangle sampler would match every case');
    assert.ok(fixture.bubbleSpring.every(c => !c.npcSlipCleared));
  });

  test(`${precision}-bit 0x40ea50 hit flash and 0x40e760 turbo expiry compare the register difference`, () => {
    const driver = driverFor(0, precision);
    for (const c of fixture.timers) {
      assert.equal(nativeAIFlagExpired(c.now, c.start, 1, options), c.hitExpired, `hit ${c.now}-${c.start}`);
      assert.equal(nativeAIFlagExpired(c.now, c.start, 5, options), c.turboExpired, `turbo ${c.now}-${c.start}`);
      driver.prepared = null;
      Object.assign(driver.state, { hitVisible: true, hitTime: c.start, turboVisible: true, turboTime: c.start });
      driver.prepare(.025, { active: false, decision: { time: c.now } });
      assert.equal(driver.state.hitVisible, !c.hitExpired);
      assert.equal(driver.state.turboVisible, !c.turboExpired);
    }
  });

  test(`${precision}-bit 0x48fda0 inverse mass and inertia match native for all nine car records`, () => {
    for (const c of fixture.inertia) {
      assert.deepEqual([c.mass, c.length, c.width], [600, 4.5, f32(1.7)]);
      const kart = nativeStandardKartInertia(c.car, options);
      assert.equal(kart.inverseMass, c.inverseMass);
      assert.equal(kart.inverseInertia, c.inverseInertia);
    }
    const track = tracks[0], world = createNativeTrack(track, options);
    const motion = new NativePlayerMotion({ physics, geometry, world, start: nativePlayerStart(track, world, options),
      collision: { sample: () => null }, precision });
    assert.equal(motion.body.inverseInertia, fixture.inertia[0].inverseInertia);
    assert.equal(driverFor(0, precision).body.inverseInertia, fixture.inertia[1].inverseInertia);
  });

  test(`${precision}-bit 0x493540 grid heading matches native for every sector and grid racer`, () => {
    let sectors = 0;
    for (const { track: id, yaws } of fixture.headings) {
      const world = fixtureWorld(id);
      yaws.forEach((yaw, sector) => {
        assert.ok(Object.is(nativeRaceHeading(world, sector, options), yaw), `${id}:${sector}`);
        sectors++;
      });
      const grid = nativeRaceGrid(tracks[id], world, { opponentCount: 4, precision });
      assert.equal(grid.player.yaw, yaws[grid.player.sector], `${id} player`);
      for (const opponent of grid.opponents) assert.equal(opponent.yaw, yaws[opponent.sector], `${id} opponent`);
    }
    assert.equal(sectors, 1092);
  });

  test(`${precision}-bit 0x497bd0/0x44fc80 overlap matches native in direct and pickup use`, () => {
    for (const c of fixture.overlaps) {
      assert.equal(nativeBonusOverlap(c.a, c.b, options), c.expected);
      const pickups = new NativeBonusPickups({ pickups: [{ type: 1, position: c.b.position, radius: c.b.radius }],
        racerCount: 1, raceType: 2, bonusConfig, random: new NativeRandom(1), precision });
      const events = pickups.step(.025, 100, [{ position: c.a.position, radius: c.a.radius }]);
      assert.equal(events.some(event => event.type === 'bonus'), c.expected);
    }
  });

  test(`${precision}-bit 0x4540c0 static pickup rotation keeps speed*dt in ST0`, () => {
    for (const c of fixture.pickupYaw) {
      const pickups = new NativeBonusPickups({ pickups: [{ type: 1, position: [0, 0, 0], radius: 10, yaw: c.yaw }],
        racerCount: 1, raceType: 2, bonusConfig: { ...bonusConfig, weapon_rotation_speed: String(c.speed) },
        random: new NativeRandom(1), precision });
      pickups.step(c.dt, 0, [{ position: [1e4, 0, 0], radius: 1 }]);
      assert.equal(pickups.pickups[0].yaw, c.expected, `${c.yaw}+${c.speed}*${c.dt}`);
    }
  });

  test(`${precision}-bit precision reaches ground samplers and projectile launch`, () => {
    const track = tracks[0], world = createNativeTrack(track, options), start = nativePlayerStart(track, world, options);
    const motion = new NativePlayerMotion({ physics, geometry, world, start,
      collision: new NativeRailCollision(track, bounds, options), precision });
    const driver = driverFor(0, precision);
    const actors = [{ body: motion.body, ground: motion.ground, radius: 10, phase: 0 }];
    const pickups = new NativeBonusPickups({ pickups: nativeTrackPickups(track, manifest, config), racerCount: 1,
      raceType: 2, bonusConfig, random: new NativeRandom(2000), precision });
    const combat = new NativeBonusCombat({ actors, pickups, config, manifest, world, shotClearance: 0,
      forwardDirection: body => nativeProjectileFacing(track, body, options), precision });
    let unrounded = 0;
    for (const c of fixture.routePlane.filter(c => c.track === 0)) {
      const sector = selectNativeSector(world, start.sector, c.point[0], c.point[2], options);
      const expected = sampleNativeTrack(world, sector, ...c.point, options).height;
      motion.body.sector = driver.body.sector = sector;
      assert.ok(Object.is(motion.sampleGround(...c.point), expected));
      assert.ok(Object.is(driver.sampleGround(...c.point), expected));
      assert.ok(Object.is(combat.groundHeight({ position: [...c.point], sector }), expected));
      if (!Object.is(f32(expected), expected)) unrounded++;
    }
    assert.equal(unrounded > 0, precision === 53, '0x496290 ST0 height is unrounded only at PC=53');
    motion.body.sector = start.sector;
    Object.assign(pickups.owned[0], { type: 1, level: 1, state: 2 });
    const [shot] = combat.fire(0).shots;
    const height = combat.groundHeight({ position: [...motion.body.position], sector: motion.body.sector });
    assert.deepEqual(shot.position, nativeProjectileLaunchPose(motion.body, shot.radius, height, options).position);
  });
}

test('default precision follows NATIVE_PRECISION and other control words are rejected', () => {
  const run = options => {
    const track = tracks[0], world = createNativeTrack(track), start = nativePlayerStart(track, world);
    const motion = new NativePlayerMotion({ physics, geometry, world, start,
      collision: new NativeRailCollision(track, bounds), ...options });
    const driver = new NativeAIDriver({ track, world, geometry, start, id: 1, racer: racers[1], playerRacer: racers[0],
      random: new NativeRandom(7), occupancy: new NativeWaypointOccupancy(track, options),
      groundClock: new NativeGroundClock(), collision: new NativeRailCollision(track, bounds), efficiency: 10, ...options });
    const history = [];
    for (let i = 0; i < 40; i++) {
      motion.prepare({ accelerate: true, left: i > 20 }, .025);
      driver.prepare(.025, { difficulty: 1, progressDifference: 0 });
      history.push(motion.integrate(), driver.integrate());
    }
    return { history, grid: nativeRaceGrid(track, world, options), inertia: nativeStandardKartInertia(0, options) };
  };
  assert.deepEqual(run({}), run({ precision: NATIVE_PRECISION }));
  const track = tracks[0], world = createNativeTrack(track);
  const options = { track, world, geometry, start: nativePlayerStart(track, world), id: 1, racer: racers[1],
    playerRacer: racers[0], random: new NativeRandom(1), occupancy: new NativeWaypointOccupancy(track),
    groundClock: new NativeGroundClock(), collision: new NativeRailCollision(track, bounds), efficiency: 10 };
  assert.throws(() => new NativeAIDriver({ ...options, precision: 64 }), RangeError);
  assert.throws(() => new NativeWaypointOccupancy(track, { precision: 64 }), RangeError);
  assert.throws(() => new NativePlayerMotion({ physics, geometry, world, start: options.start,
    collision: { sample: () => null }, precision: 64 }), RangeError);
  assert.throws(() => nativeStandardKartInertia(0, { precision: 64 }), RangeError);
  assert.throws(() => nativeRaceGrid(track, world, { precision: 64 }), RangeError);
  assert.throws(() => nativeRaceHeading(world, 0, { precision: 64 }), RangeError);
  assert.throws(() => nativeBonusOverlap({ position: [0, 0, 0], radius: 1 }, { position: [0, 0, 0], radius: 1 },
    { precision: 64 }), RangeError);
  assert.throws(() => nativeRoutePlaneHeight(world.sectors[0].fallback, 0, 0, { precision: 64 }), RangeError);
  assert.throws(() => nativeAIFlagExpired(1, 0, 1, { precision: 64 }), RangeError);
});
