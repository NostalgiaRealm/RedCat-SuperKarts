import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {DrivingView} from '../source/driving-view.js';
import {TrackMusic} from '../source/game-audio.js';

const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/pause-audio-fixtures.json',import.meta.url)));
function view(){
  const calls=[];
  const instance={active:true,controls:{enabled:false},pausedAt:null,input:{clear(){}},
    clock:{snapshot:()=>({wallMs:1200})},updateLoop:{stop:()=>calls.push('updates.stop')},
    simulation:{pause:()=>calls.push('timers.pause')},hud:{notify:id=>calls.push(`notice.${id}`)},
    music:{pause:()=>calls.push('music.pause'),pollCompletion:()=>calls.push('music.poll-completion')},
    audio:{pause:()=>calls.push('effects.pause')}};
  return {instance,calls};
}

test('original P/quit traces pause timers but retain media playback',()=>{
  for(const trace of fixture.traces){
    const native=trace.events.map(event=>event.call);
    assert.equal(native.filter(call=>call==='music.poll-completion').length,1);
    assert.equal(native.indexOf('music.poll-completion'),22);
    assert.ok(native.indexOf('music.poll-completion')<native.indexOf('timer.resume'));
    const {instance,calls}=view();
    DrivingView.prototype.suspend.call(instance,{notifyPause:trace.request===1,pauseAudio:false});
    assert.equal(instance.active,false);
    assert.equal(calls.filter(call=>call==='timers.pause').length,1);
    assert.ok(calls.includes('music.poll-completion'));
    assert.ok(!calls.includes('music.pause')&&!calls.includes('effects.pause'));
    assert.equal(calls.includes('notice.1'),trace.request===1);
  }
});

test('host focus loss silences an already native-paused view without pausing timers twice',()=>{
  const {instance,calls}=view();
  DrivingView.prototype.suspend.call(instance,{pauseAudio:false});
  DrivingView.prototype.suspend.call(instance);
  assert.equal(calls.filter(call=>call==='timers.pause').length,1);
  assert.equal(calls.filter(call=>call==='notice.1').length,1);
  assert.equal(calls.filter(call=>call==='music.pause').length,1);
  assert.equal(calls.filter(call=>call==='effects.pause').length,1);
});

test('music completion waits for the native update poll and restarts only once',async()=>{
  const calls=[];
  const audio={ended:false,volume:.5,_time:45,
    get currentTime(){return this._time;},
    set currentTime(time){this._time=time;this.ended=false;calls.push(['seek',time]);},
    async play(){calls.push(['play',this.currentTime]);}};
  const music=Object.assign(Object.create(TrackMusic.prototype),{audio,blocked:false});
  await music.pollCompletion();assert.deepEqual(calls,[]);
  audio.ended=true;audio._time=60;
  // An elapsed pause does not call the completion service.
  assert.equal(audio.ended,true);assert.deepEqual(calls,[]);
  await music.pollCompletion();await music.pollCompletion();
  assert.deepEqual(calls,[['seek',0],['play',0]]);
  audio.volume=0;audio.ended=true;await music.pollCompletion();
  assert.equal(calls.length,2);
});
