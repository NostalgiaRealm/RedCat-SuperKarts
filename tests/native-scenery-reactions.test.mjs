import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {nativeSceneryPlayerOverlap,launchNativeScenery,updateNativeSceneryReaction,NativeSceneryReactions} from '../source/simulation/native-scenery-reactions.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {createNativeTrack} from '../source/simulation/native-track.js';
const fixture=JSON.parse(readFileSync(new URL('../evidence/native/scenery-reaction-fixtures.json',import.meta.url)));

test('non-solid scenery checks only strict player XZ radius overlap',()=>{
  for(const c of fixture.overlap)assert.equal(nativeSceneryPlayerOverlap(c.object,c.player,c),c.expected);
});
test('native type2 launch preserves inherited velocity and three shared random draws',()=>{
  for(const [index,c] of fixture.launch.entries()){
    const object=structuredClone(c.object),random=new NativeRandom(c.seed);
    launchNativeScenery(object,{...c.player,lateralSpeed:c.player.velocity[0],forwardSpeed:c.player.velocity[2]},random,c);
    for(const key of ['velocity','pitchRate','rollRate','gravity','mode'])assert.deepEqual(object[key],c.expected[key],`${index} ${key}`);
    assert.equal(random.state,c.randomState);
  }
});
for(const family of ['flight','settle'])test(`original type2 ${family} callback matches native instructions`,()=>{
  for(const [index,c] of fixture[family].entries()){
    const object=structuredClone(c.state);
    const result=updateNativeSceneryReaction(object,c.dt,{precision:c.precision,groundHeight:()=>c.ground});
    for(const key of ['velocity','position','pitchRate','rollRate','gravity','pitch','yaw','roll','mode','matrix'])
      assert.deepEqual(object[key],c.expected[key],`${index} ${key}`);
    assert.equal(result,c.returnValue);
  }
});

test('every authored type2 object uses the same player-only launch and sound boundary',()=>{
  const manifest=JSON.parse(readFileSync(new URL('../public/assets/manifest.json',import.meta.url)));
  let total=0;
  for(let id=0;id<6;id++){
    const track=JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${id}.json`,import.meta.url)));
    const reactions=new NativeSceneryReactions({track,manifest,world:createNativeTrack(track),random:new NativeRandom(1)});
    for(const object of reactions.objects){
      const player={position:[...object.position],radius:20,yaw:0,lateralSpeed:0,forwardSpeed:15};
      const before=reactions.random.state,sounds=[];
      reactions.step(.025,player,[[object.sector,object.sector]],(index,body)=>sounds.push({index,mode:body.mode,velocity:[...body.velocity]}));
      assert.equal(object.mode,1);
      assert.ok(sounds.some(sound=>sound.index===object.placementIndex&&sound.mode===1));
      assert.notEqual(reactions.random.state,before);
      // Isolate remaining objects so every source placement exercises state0.
      for(const other of reactions.objects)if(other!==object&&other.mode!==0){
        other.mode=0;other.velocity=[0,0,0];
      }
      total++;
    }
  }
  assert.equal(total,174);
});
