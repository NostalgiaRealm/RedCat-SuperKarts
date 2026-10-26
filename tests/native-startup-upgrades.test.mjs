import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {nativeRacePlayerOptions,initializeNativeRacePlayerOptions} from '../source/simulation/native-race-options.js';
import {nativeRaceTimerSetup} from '../source/simulation/native-game-timers.js';
import {parseRacerTable} from '../source/simulation/native-tables.js';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';

const read=path=>readFileSync(new URL(`../${path}`,import.meta.url));
const json=path=>JSON.parse(read(path));
const fixtures=json('evidence/native/startup-upgrades.json');
const config=json('public/assets/config.json');
const zero={motorUpgrade:0,tireUpgrade:0,gearboxUpgrade:0};

test('128 original INI loader and successful/missing Phys exits clear every upgrade switch',()=>{
  assert.equal(fixtures.cases.length,128);
  for(const c of fixtures.cases){
    assert.deepEqual(c.expected,{motor:0,banden:0,turbo:0,abs:0,versnellingsbak:0,injectie:0});
    const loaded=nativeRacePlayerOptions({'race.ini':{player:c.loaded}});
    const previous={...loaded};
    assert.deepEqual(initializeNativeRacePlayerOptions(loaded),{
      motorUpgrade:c.expected.motor,tireUpgrade:c.expected.banden,gearboxUpgrade:c.expected.versnellingsbak,
    });
    assert.deepEqual(loaded,previous,'initialization must not rewrite saved INI switches');
    assert.deepEqual(c.reads.map(read=>read.key),['motor','banden','turbo','abs','versnellingsbak','injectie']);
  }
});

test('original instruction call order loads switches before construction and initializes timers afterward',()=>{
  const startup=fixtures.directCallOrder.startup;
  const index=target=>startup.findIndex(call=>call.target===target);
  assert.ok(index('0042ad70')<index('00415d70'));
  assert.ok(index('00415d70')<index('0042d360'));
  assert.ok(fixtures.directCallOrder.config.some(call=>call.target==='0042b870'));
  assert.ok(fixtures.directCallOrder.cars.findIndex(call=>call.target==='004319f0')
    <fixtures.directCallOrder.cars.findIndex(call=>call.target==='00417640'));
  const reset=fixtures.directWrites.filter(write=>write.address>='00431ecd'&&write.address<='00431eeb');
  assert.deepEqual(reset.map(write=>write.destination),['0053bef0','0053bef4','0053bef8','0053befc','0053bf00','0053bf04']);
  assert.equal(fixtures.raceIniInputs[0].sha256,fixtures.raceIniInputs[1].sha256);
});

test('72 native startup timer initializations use cleared upgrades without changing time-gate budgets',()=>{
  const tables=[0,1,2].map(i=>parseRacerTable(read(`public/assets/racer-tables/cars${i}.dat`)));
  assert.equal(fixtures.timerCases.length,72);
  let changed=0;
  for(const c of fixtures.timerCases){
    const bank=nativeRaceTimerSetup({config,...c,raceType:1,opponentCount:3,
      playerRacer:tables[c.difficulty][c.character],
      ...initializeNativeRacePlayerOptions(nativeRacePlayerOptions(config))});
    for(const timer of [0,8,18])assert.equal(bank.get(timer).limitMs,c.limits.afterConstruction[timer]);
    assert.equal(c.limits.afterConstruction[18],c.limits.loaded[18]);
    if(c.limits.afterConstruction[8]!==c.limits.loaded[8])changed++;
  }
  assert.equal(changed,36);
});

test('composed race construction shares initialized options with player, NPC steering and timers at every difficulty',()=>{
  const manifest=json('public/assets/manifest.json'),cars=json('public/assets/cars.json');
  for(const difficulty of [0,1,2]){
    const sim=new RaceSimulation({config,manifest,cars,character:1,difficulty,raceMode:1,
      track:json('public/assets/tracks/etappe1.json'),random:new NativeRandom(0),
      physicsBytes:read(`public/assets/physics/phys${difficulty}.dat`),
      racerBytes:read(`public/assets/racer-tables/cars${difficulty}.dat`)});
    assert.deepEqual(sim.loadedUpgrades,{motorUpgrade:1,tireUpgrade:1,gearboxUpgrade:1});
    assert.deepEqual(sim.upgrades,zero);
    assert.equal(sim.motion.upgrades,sim.upgrades);
    const expected=fixtures.timerCases.find(c=>c.trackIndex===1&&c.difficulty===difficulty&&c.character===1);
    assert.equal(sim.timers.get(8).limitMs,expected.limits.afterConstruction[8]);
    const observed=[];
    for(const actor of sim.opponents){
      const prepare=actor.prepare.bind(actor);
      actor.prepare=(dt,options)=>{observed.push(options.playerGlobals.tireUpgrade);return prepare(dt,options);};
    }
    sim.step({throttle:1,brake:0,steer:0,handbrake:0,bonus:0},.025,25);
    assert.deepEqual(observed,[0,0,0]);
    assert.equal(config['race.ini'].player.motor,'1');
  }
});
