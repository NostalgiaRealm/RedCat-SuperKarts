import test from 'node:test';
import assert from 'node:assert/strict';
import {MoviePlayback} from '../source/movie-playback.js';

const denied=()=>Object.assign(new Error('Browser policy'),{name:'NotAllowedError'});
function setup(play){
  const calls=[],button={hidden:true};
  const video={muted:false,currentTime:12,volume:1,
    play(){calls.push({muted:this.muted,source:this.src});return play(calls.length);},
    pause(){this.paused=true;},removeAttribute(name){delete this[name];},load(){}};
  const player=new MoviePlayback(video,button);
  return {player,video,button,calls};
}
test('sound policy falls back to silent playback; audio activation keeps position and gain',async()=>{
  const {player,video,button,calls}=setup(count=>count===1?Promise.reject(denied()):Promise.resolve());
  await player.start('intro.mp4',.3);
  assert.deepEqual(calls.map(c=>c.muted),[false,true]);assert.equal(button.hidden,false);
  await player.activate();
  assert.equal(video.muted,false);assert.equal(video.currentTime,12);assert.equal(video.volume,.3);
  assert.equal(button.hidden,true);assert.equal(video.src,'intro.mp4');
});
test('the audio action also starts playback when even muted autoplay is blocked',async()=>{
  const {player,video,button,calls}=setup(count=>count<=2?Promise.reject(denied()):Promise.resolve());
  await player.start('intro.mp4',1);assert.equal(button.hidden,false);
  await player.activate();assert.equal(calls.length,3);assert.equal(video.muted,false);assert.equal(button.hidden,true);
});
test('skipping a pending movie prevents its rejected autoplay from reviving the control',async()=>{
  let reject;
  const {player,video,button,calls}=setup(()=>new Promise((_,no)=>reject=no));
  const pending=player.start('intro.mp4',1);player.stop();reject(denied());await pending;
  assert.equal(calls.length,1);assert.equal(button.hidden,true);assert.equal(video.src,undefined);assert.equal(video.muted,false);
});
test('an old play rejection cannot mute a replacement reward movie',async()=>{
  let reject;
  const {player,video,button,calls}=setup(count=>count===1?new Promise((_,no)=>reject=no):Promise.resolve());
  const pending=player.start('intro.mp4',1);
  await player.start('rcwin.mp4',1);reject(denied());await pending;
  assert.equal(calls.length,2);assert.equal(video.src,'rcwin.mp4');assert.equal(video.muted,false);assert.equal(button.hidden,true);
});
test('audio starts before requesting fullscreen in the same activation',async()=>{
  const order=[];
  const {player,video}=setup(()=>{order.push('play');return Promise.resolve();});
  video.ownerDocument={fullscreenEnabled:true,fullscreenElement:null,documentElement:{requestFullscreen(){order.push('fullscreen');return Promise.resolve();}}};
  await player.start('intro.mp4',1);assert.deepEqual(order,['play']);
  await player.activate();assert.deepEqual(order,['play','play','fullscreen']);
});
test('an already fullscreen game does not request fullscreen again',async()=>{
  const {player,video}=setup(()=>Promise.resolve());
  let requests=0;
  video.ownerDocument={fullscreenEnabled:true,fullscreenElement:{},documentElement:{requestFullscreen(){requests++;return Promise.resolve();}}};
  await player.start('intro.mp4',1);await player.activate();assert.equal(requests,0);
});
test('denied fullscreen still enables movie audio and keeps playing',async()=>{
  const {player,video,button}=setup(()=>Promise.resolve());
  video.ownerDocument={fullscreenEnabled:true,fullscreenElement:null,documentElement:{requestFullscreen(){return Promise.reject(denied());}}};
  await player.start('intro.mp4',1);await player.activate();
  assert.equal(video.muted,false);assert.equal(button.hidden,true);assert.equal(video.currentTime,12);
});
