import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NativeBonusCombat } from '../source/simulation/native-combat.js';
import { NativeBonusPickups, NativeRandom, nativeTrackPickups } from '../source/simulation/native-bonus.js';
import { NativePlayerMotion } from '../source/simulation/native-motion.js';
import { NativeRailCollision } from '../source/simulation/native-collision.js';
import { createNativeTrack } from '../source/simulation/native-track.js';
import { nativePlayerStart } from '../source/simulation/native-start.js';
import { parsePhysicsTable } from '../source/simulation/native-tables.js';
import { nativeProjectileFacing, advanceNativeProjectile } from '../source/simulation/native-projectile.js';
import { SimulationClock } from '../source/simulation/clock.js';

const json = path => JSON.parse(readFileSync(new URL(path, import.meta.url)));
const config = json('../public/assets/config.json');
const manifest = json('../public/assets/manifest.json');
const geometry = json('../public/assets/cars.json').cars[0];
const actorRadius = manifest.meshes[geometry.body.toLowerCase()].horizontalRadius;
const physics = parsePhysicsTable(readFileSync(new URL('../public/assets/physics/phys1.dat', import.meta.url)))[0];

function setup(id, count = 1) {
  const track = json(`../public/assets/tracks/etappe${id}.json`);
  const world = createNativeTrack(track);
  const motion = new NativePlayerMotion({ physics, geometry, world,
    start: nativePlayerStart(track, world), collision: new NativeRailCollision(track, geometry.bodyBounds) });
  const actors = Array.from({ length: count }, () => ({
    body: motion.body, ground: motion.ground, radius: actorRadius, phase: 0,
  }));
  if (count > 1) {
    actors[0] = structuredClone({ body: { ...motion.body }, ground: motion.ground,
      radius: actorRadius, phase: 0 });
  }
  const pickups = new NativeBonusPickups({ pickups: nativeTrackPickups(track, manifest, config),
    racerCount: count, raceType: 2, bonusConfig: config['game.ini'].bonus_data, random: new NativeRandom(2000) });
  const combat = new NativeBonusCombat({ actors, pickups, config, manifest, world,
    shotClearance: 0, forwardDirection: body => nativeProjectileFacing(track, body) });
  return { track, world, motion, actors, pickups, combat };
}

test('combat consumes owned bonuses, preserves empty-fire cooldown and uses separate native pools', () => {
  const { combat, pickups, motion } = setup(0);
  motion.body.forwardSpeed = -10;
  Object.assign(pickups.owned[0], { type: 5, level: 2, state: 2 });
  assert.equal(combat.playerFire(true, 500), null);
  assert.equal(combat.playerFire(true, 501).type, 'turbo');
  assert.equal(motion.body.forwardSpeed, Math.fround(-10 * Math.fround(Math.fround(160 * Math.fround(0.01)))));
  assert.equal(pickups.owned[0].state, 1);
  assert.equal(combat.playerFire(true, 1002), null);
  assert.equal(combat.fireGate.lastFireMs, 1002);
  Object.assign(pickups.owned[0], { type: 2, level: 3, state: 2 });
  const event = combat.playerFire(true, 1503);
  assert.equal(event.shots.length, 5);
  assert.equal(combat.activeCount(), 5);
  assert.deepEqual(event.shots.map(shot => shot.angles[1]),
    [0, 1, 2, 3, 4].map(index => Math.fround(event.shots[0].angles[1] + index * 120)));
  assert.equal(combat.shots.length, 41);
  assert.equal(combat.secondaryShots.length, 40);
  assert.ok(combat.secondaryShots.every(shot => shot.clearance === 0), 'BSS secondary clearance is loader zero');
});

test('all four weapons create original hit states and wheel launch velocities on contact', () => {
  for (const type of [1, 2, 3, 4]) {
    const { combat, pickups, actors } = setup(0, 2);
    actors[0].state = { priorities: [2, 1, 0] };
    Object.assign(pickups.owned[1], { type, level: 2, state: 2 });
    const shot = combat.fire(1).shots[0];
    // Explicit contact fixture: place the stationary victim at the launch.
    actors[0].body.position = [...shot.position];
    const events = combat.step(0.025, 12.5);
    assert.equal(events[0].type, 'hit');
    assert.equal(events[0].racer, 0);
    assert.equal(combat.effects[0].type, type);
    assert.equal(actors[0].phase, 25);
    assert.deepEqual(actors[0].state.priorities, [1, 0, 2]);
    assert.deepEqual(actors[0].animationEvents, events.filter(event => event.type === 'hit')
      .map(() => ({ callback: [null, 0x411830, 0x411b40, 0x411e50, 0x412090][type] })));
    assert.equal(actors[0].state.hitVisible, true);
    assert.equal(actors[0].state.hitTime, 12.5);
    if (type === 1 || type === 4) assert.equal(actors[0].ground.wheels[2].verticalSpeed, 72);
    if (type === 2) assert.ok(actors[0].ground.wheels.every(wheel => wheel.verticalSpeed === 120));
  }
});

test('finished NPCs consume a colliding projectile without resetting their path or entering a hit state', () => {
  const { combat, pickups, actors } = setup(0, 2);
  actors[0].state = { priorities: [2, 1, 0] };
  actors[0].phase = 9;
  Object.assign(pickups.owned[1], { type: 1, level: 2, state: 2 });
  const shot = combat.fire(1).shots[0];
  actors[0].body.position = [...shot.position];
  const events = combat.step(0.025);
  assert.equal(events[0].type, 'hit');
  assert.equal(shot.state, 1);
  assert.equal(combat.effects[0], null);
  assert.equal(actors[0].phase, 9);
  assert.deepEqual(actors[0].state.priorities, [2, 1, 0]);
  assert.equal(actors[0].animationEvents, undefined);
});

test('an unfinished NPC hitting the player queues the original cheer callback', () => {
  for (const phase of [0, 9]) {
    const { combat, pickups, actors } = setup(0, 2);
    actors[0].phase = phase;
    Object.assign(pickups.owned[0], { type: 1, level: 1, state: 2 });
    const shot = combat.fire(0).shots[0];
    actors[1].body.position = [...shot.position];
    const events = combat.step(0.025);
    assert.equal(events[0].racer, 1);
    assert.deepEqual(actors[1].animationEvents, [{callback: 0x411830}]);
    assert.deepEqual(actors[0].animationEvents,
      phase === 9 ? undefined : [{ callback: 0x40de60, fsmState: phase }]);
  }
});

test('all player hit animations submit synchronously before effect initialization', () => {
  for (const type of [1, 2, 3, 4]) {
    const {combat, pickups, actors} = setup(0, 2);
    Object.assign(pickups.owned[0], {type, level: 1, state: 2});
    const shot = combat.fire(0).shots[0];
    actors[1].body.position = [...shot.position];
    const requests = [];
    combat.onAnimationEvent = (racer, event) => {
      if (racer === 1) assert.equal(combat.effects[1], null);
      requests.push({racer, ...event});
    };
    combat.step(.025, 10);
    assert.deepEqual(requests[0], {racer: 1,
      callback: [null, 0x411830, 0x411b40, 0x411e50, 0x412090][type]});
    assert.equal(actors[1].animationEvents, undefined, 'synchronous submission is not replayed later');
  }
});

test('expired projectiles still run native contact checks in the same update', () => {
  const shot = { state: 2, type: 1, level: 1, ageSeconds: 2.99, target: -2, shooter: 1,
    position: [0, 0, 0], radius: 10, angles: [0, 0, 0], matrix: [1, 0, 0, 0, 1, 0, 0, 0, 1],
    inheritedForward: 0, clearance: 0, previousHeight: 0, heightInitialized: true };
  const result = advanceNativeProjectile(shot, 0.025, { lifetime: 3, speed: 1000 },
    [{ position: [0, 0, 0], radius: 10 }, { position: [1000, 0, 0], radius: 10 }],
    { groundHeight: () => 0, rotationSpeed: 3000 });
  assert.deepEqual(result, { type: 'hit', racer: 0, endReason: 'expired' });
});

test('rocket explosion occurs after initializer RNG and before player hit sound dispatch', () => {
  const {combat, pickups, actors} = setup(0, 2);
  Object.assign(pickups.owned[0], {type: 1, level: 1, state: 2});
  const shot = combat.fire(0).shots[0];
  actors[1].body.position = [...shot.position];
  const trace = [];
  const originalDraw = combat.random.next.bind(combat.random);
  combat.random.next = () => { trace.push('random'); return originalDraw(); };
  combat.onExplosion = body => {
    assert.equal(body, actors[1].body);
    assert.equal(shot.state, 2);
    trace.push('explosion');
  };
  combat.voices = {
    submit: (_voice, sample) => trace.push(sample), playerHit: () => trace.push('AMHIT'),
    npcHitPlayer() {},
  };
  combat.step(.025, 10);
  const explosion = trace.indexOf('explosion');
  assert.ok(explosion > trace.lastIndexOf('random'));
  assert.ok(explosion < trace.indexOf('HIT_BY_ROCKET'));
  assert.ok(explosion < trace.indexOf('AMHIT'));
});

test('height-impact explosion observes the still-active projectile before cleanup', () => {
  for (const type of [1, 2]) {
    const shot = {state: 2, type, level: 1, ageSeconds: 0, target: -2, shooter: 0,
      position: [0, 0, 0], radius: 1, angles: [0, 0, 0],
      matrix: [1, 0, 0, 0, 1, 0, 0, 0, 1], inheritedForward: 0, clearance: 0,
      previousHeight: 0, heightInitialized: true};
    const calls = [];
    const result = advanceNativeProjectile(shot, .025, {lifetime: 3, speed: 10}, [],
      {groundHeight: () => 30, rotationSpeed: 3000, onExplosion: body => {
        assert.equal(body, shot);
        calls.push({state: shot.state, position: [...shot.position]});
      }});
    assert.equal(result.type, 'height-impact');
    assert.equal(calls.length, 1);
    assert.equal(calls[0].state, 2);
    assert.equal(calls[0].position[1], 40);
    assert.equal(shot.state, 1);
  }
});

test('stream transitions are synchronous with original turbo and projectile state changes', () => {
  const {combat, pickups} = setup(0);
  const trace = [];
  combat.voices = {turbo: () => trace.push('TURBO voice'),
    submit: (_id, sample) => trace.push(sample)};
  combat.onTurbo = (racer, level) => trace.push(['turbo stream', racer, level]);
  combat.onProjectileState = (shot, state) => trace.push(['shot stream', state, shot.state]);
  Object.assign(pickups.owned[0], {type: 5, level: 2, state: 2});
  combat.fire(0);
  assert.deepEqual(trace, ['TURBO voice', ['turbo stream', 0, 2], 'FIRE_TURBO2']);
  trace.length = 0;
  Object.assign(pickups.owned[0], {type: 1, level: 1, state: 2});
  const shot = combat.fire(0).shots[0];
  assert.deepEqual(trace, ['FIRE_ROCKET1', ['shot stream', 2, 2]]);
  trace.length = 0;
  shot.ageSeconds = 100;
  combat.step(.025, 10);
  assert.deepEqual(trace, [['shot stream', 1, 2]]);
});

test('bubble shells attach at hit, detach on settling, and clean up before replacement hits', () => {
  for(const victim of [0,1]){
    const {combat,pickups,actors}=setup(0,2),shooter=1-victim,trace=[];
    combat.onBubbleAttach=racer=>trace.push(['attach',racer]);
    combat.onBubbleDetach=racer=>{
      assert.equal(combat.effects[racer].bubbleVisible,true,
        'replacement cleanup callback precedes clearing the old visible flag');
      trace.push(['detach',racer]);
    };
    const hit=type=>{
      Object.assign(pickups.owned[shooter],{type,level:1,state:2});
      const shot=combat.fire(shooter).shots[0];
      actors[victim].body.position=[...shot.position];
      combat.step(.025,10);
    };
    hit(2);
    assert.deepEqual(trace,[['attach',victim]]);
    hit(4);
    assert.deepEqual(trace,[['attach',victim],['detach',victim]]);
    hit(2);
    assert.deepEqual(trace,[['attach',victim],['detach',victim],['attach',victim]]);
    combat.effects[victim].remaining=-1;
    actors[victim].ground.groundCount=4;
    actors[victim].ground.wheels[2].verticalSpeed=0;
    combat.onBubbleDetach=racer=>trace.push(['settled',racer]);
    combat.prepareEffect(victim,.025);
    assert.equal(combat.effects[victim].bubbleVisible,false);
    assert.deepEqual(trace.at(-1),['settled',victim]);
  }
});

test('player bubble shell attaches after SOAP_UP but before the caller AMHIT voice',()=>{
  const {combat,pickups,actors}=setup(0,2),trace=[];
  Object.assign(pickups.owned[0],{type:2,level:1,state:2});
  const shot=combat.fire(0).shots[0];actors[1].body.position=[...shot.position];
  combat.voices={submit:(_id,sample)=>trace.push(sample),playerHit:()=>trace.push('AMHIT'),
    npcHitPlayer(){}};
  combat.onBubbleAttach=()=>trace.push('shell');
  combat.step(.025,10);
  assert.deepEqual(trace.slice(0,4),['HIT_BY_SOAP','SOAP_UP1','shell','AMHIT']);
});

test('weapon/controller composition remains deterministic while driving all six tracks at different render rates', () => {
  for (let id = 0; id < 6; id++) {
    const run = fps => {
      const { motion, actors, pickups, combat } = setup(id);
      const events = [], history = [];
      const clock = new SimulationClock({ intervalMs: 25, update(dt, now) {
        // Inventory grants are replay inputs to cover all types, not native pickups.
        if (now % 1000 === 25) {
          const sequence = Math.floor(now / 1000);
          Object.assign(pickups.owned[0], { type: sequence % 5 + 1, level: sequence % 3 + 1, state: 2 });
        }
        const fired = combat.playerFire(true, now);
        if (fired) events.push([now, fired.type, fired.bonus, fired.level]);
        motion.prepare({ accelerate: now < 2000 || now >= 7000, brake: now >= 2000 && now < 7000 }, dt);
        combat.prepareEffect(0, dt);
        motion.integrate();
        pickups.step(dt, now / 1000, actors.map(actor => ({ position: actor.body.position, radius: actor.radius })),
          { activeProjectileCount: combat.activeCount() });
        events.push(...combat.step(dt).map(event => [now, event.type, event.bonus, event.level, event.racer]));
        history.push([motion.body.position.slice(), motion.body.yaw, motion.body.forwardSpeed,
          combat.activeCount(), combat.random.state]);
      } });
      clock.frame(0);
      for (let now = 1000 / fps; now < 10000; now += 1000 / fps) clock.frame(now);
      clock.frame(10000);
      return { history, events, shots: combat.shots, secondaryShots: combat.secondaryShots };
    };
    const expected = run(32);
    for (const fps of [31, 60, 144, 240]) assert.deepEqual(run(fps), expected, `track ${id}, ${fps}fps`);
    assert.ok(expected.history.every(row => row[0].every(Number.isFinite)), `track ${id}`);
  }
});
