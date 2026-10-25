import test from 'node:test';
import assert from 'node:assert/strict';
import {InputController,touchWheelInput} from '../src/input.js';
import {createNativeInputState,nativeAnalogFromNormalized,updateNativeAnalogInput,updateNativeInput} from '../src/simulation/native-input.js';

const bounds={left:100,top:200,width:200,height:200};
const empty={throttle:0,brake:0,steer:0,handbrake:0,bonus:0};
function dispatch(target,type,values={}){
  const event=new Event(type,{cancelable:true});
  Object.assign(event,{pointerId:1,pointerType:'touch',button:0,clientX:200,clientY:300,...values});
  target.dispatchEvent(event);return event;
}
class TouchTarget extends EventTarget{
  constructor(){
    super();this.dataset={};this.captures=new Set();this.classes=new Set();this.properties=new Map();
    this.classList={add:name=>this.classes.add(name),remove:name=>this.classes.delete(name),
      toggle:(name,enabled)=>enabled?this.classes.add(name):this.classes.delete(name),contains:name=>this.classes.has(name)};
    this.style={setProperty:(key,value)=>this.properties.set(key,value)};
  }
  getBoundingClientRect(){return bounds;}
  setPointerCapture(id){this.captures.add(id);}
  hasPointerCapture(id){return this.captures.has(id);}
  releasePointerCapture(id){this.captures.delete(id);dispatch(this,'lostpointercapture',{pointerId:id});}
}
function setup(){
  const win=new EventTarget();win.document=new EventTarget();win.document.hidden=false;
  win.navigator={getGamepads:()=>[]};const pauses=[];
  const input=new InputController({window:win,onPause:reason=>pauses.push(reason)});
  input.setMode('race');
  const wheel=new TouchTarget(),pedal=new TouchTarget(),bonus=new TouchTarget();
  input.bindSteeringWheel(wheel);input.bindTouch(pedal,'handbrake');input.bindTouch(bonus,'bonus');
  return {win,input,wheel,pedal,bonus,pauses};
}
function assertReleased({input,wheel,pedal,bonus}){
  assert.deepEqual(input.state.snapshot(),empty);
  assert.equal(input.state.touchAnalog.size,0);assert.equal(input.touchReleases.size,0);
  assert.equal(wheel.dataset.drive,'neutral');assert.equal(wheel.dataset.steer,'0');
  assert.equal(wheel.properties.get('--steer-angle'),'0deg');
  for(const element of [wheel,pedal,bonus]){
    assert.equal(element.classList.contains('held'),false);assert.equal(element.captures.size,0);
  }
}

test('wheel absolute axes follow the STK defaults, center deadzone and saturation',()=>{
  assert.deepEqual(touchWheelInput(200,300,bounds),{steer:0,throttle:0,brake:0});
  assert.deepEqual(touchWheelInput(205,295,bounds),{steer:0,throttle:0,brake:0});
  const partial=touchWheelInput(246,274.25,bounds);
  assert.ok(Math.abs(partial.steer-.5)<1e-12);assert.ok(Math.abs(partial.throttle-.5)<1e-12);
  assert.equal(partial.brake,0);
  assert.deepEqual(touchWheelInput(-100,-100,bounds),{steer:-1,throttle:1,brake:0});
  assert.deepEqual(touchWheelInput(500,600,bounds),{steer:1,throttle:0,brake:1});
  assert.deepEqual(touchWheelInput(200,300,{...bounds,width:0}),{steer:0,throttle:0,brake:0});
});

test('captured wheel moves from acceleration to reverse outside its bounds without sticky steering',()=>{
  const fixture=setup(),{input,wheel}=fixture;
  dispatch(wheel,'pointerdown',{clientX:246,clientY:250});
  assert.equal(input.state.snapshot().throttle,1);
  assert.ok(Math.abs(input.state.snapshot().analog.steer-.5)<1e-12);
  assert.equal(wheel.dataset.drive,'forward');assert.equal(wheel.captures.has(1),true);
  dispatch(wheel,'pointermove',{clientX:0,clientY:500});
  assert.deepEqual(input.state.snapshot().analog,{...empty,steer:-1,brake:1});
  assert.equal(wheel.dataset.drive,'reverse');
  dispatch(wheel,'pointermove',{clientX:200,clientY:300});
  assert.deepEqual(input.state.snapshot().analog,empty);
  dispatch(wheel,'pointerup');assertReleased(fixture);input.destroy();
});

test('only the first wheel contact controls it and secondary releases do not release its owner',()=>{
  const fixture=setup(),{input,wheel}=fixture;
  dispatch(wheel,'pointerdown',{clientX:250,clientY:250});
  const original=input.state.snapshot();
  dispatch(wheel,'pointerdown',{pointerId:2,clientX:100,clientY:400});
  dispatch(wheel,'pointermove',{pointerId:2,clientX:100,clientY:400});
  dispatch(wheel,'pointerup',{pointerId:2});
  assert.deepEqual(input.state.snapshot(),original);assert.deepEqual([...wheel.captures],[1]);
  dispatch(wheel,'pointerup');assertReleased(fixture);input.destroy();
});

test('wheel, Alt-equivalent pedal and power-up combine without losing analog steering',()=>{
  const fixture=setup(),{input,wheel,pedal,bonus}=fixture;
  dispatch(wheel,'pointerdown',{clientX:246,clientY:250});
  dispatch(pedal,'pointerdown',{pointerId:2});dispatch(bonus,'pointerdown',{pointerId:3});
  const state=input.state.snapshot();assert.equal(state.analog.handbrake,1);assert.equal(state.analog.bonus,1);
  assert.ok(Math.abs(state.analog.steer-.5)<1e-12);assert.equal(state.brake,0);
  const nativeTouch=updateNativeAnalogInput(createNativeInputState(),nativeAnalogFromNormalized(state.analog));
  const nativeAlt=updateNativeInput(createNativeInputState(),{handbrake:true},.025);
  assert.equal(nativeTouch.handbrake,nativeAlt.handbrake);assert.equal(nativeTouch.handbrake,true);
  dispatch(pedal,'pointerup',{pointerId:2});
  assert.equal(input.state.snapshot().analog.handbrake,0);assert.equal(input.state.snapshot().analog.bonus,1);
  dispatch(wheel,'pointerup');
  assert.equal(input.state.snapshot().bonus,1);assert.equal(input.state.snapshot().analog,undefined);
  dispatch(bonus,'pointerup',{pointerId:3});assertReleased(fixture);input.destroy();
});

test('two contacts on the same button retain held styling and input until both release',()=>{
  const fixture=setup(),{input,pedal}=fixture;
  dispatch(pedal,'pointerdown',{pointerId:2});dispatch(pedal,'pointerdown',{pointerId:3});
  dispatch(pedal,'pointerup',{pointerId:2});
  assert.equal(input.state.snapshot().handbrake,1);assert.equal(pedal.classList.contains('held'),true);
  dispatch(pedal,'pointercancel',{pointerId:3});assertReleased(fixture);input.destroy();
});

test('pointer cancellation and lost capture release only the affected control',()=>{
  for(const event of ['pointercancel','lostpointercapture']){
    const fixture=setup(),{input,wheel,pedal}=fixture;
    dispatch(wheel,'pointerdown',{clientY:250});dispatch(pedal,'pointerdown',{pointerId:2});
    dispatch(wheel,event);
    assert.equal(input.state.snapshot().throttle,0);assert.equal(input.state.snapshot().handbrake,1);
    assert.equal(input.state.snapshot().analog,undefined);
    dispatch(pedal,event,{pointerId:2});assertReleased(fixture);input.destroy();
  }
});

test('blur, hidden document, mode changes, controller/state clear and destruction release captures and visuals',()=>{
  const cases=[
    fixture=>fixture.win.dispatchEvent(new Event('blur')),
    fixture=>{fixture.win.document.hidden=true;fixture.win.document.dispatchEvent(new Event('visibilitychange'));},
    fixture=>fixture.input.setMode('menu'),fixture=>fixture.input.clear(),
    fixture=>fixture.input.state.clear(),fixture=>fixture.input.destroy(),
  ];
  for(const clear of cases){
    const fixture=setup(),{input,wheel,pedal,bonus}=fixture;
    dispatch(wheel,'pointerdown',{clientX:250,clientY:250});
    dispatch(pedal,'pointerdown',{pointerId:2});dispatch(bonus,'pointerdown',{pointerId:3});
    clear(fixture);assertReleased(fixture);
    dispatch(wheel,'pointermove',{clientX:100,clientY:200});assertReleased(fixture);
    input.destroy();
  }
});

test('gamepad polling does not clear wheel analog state and keyboard priority remains unchanged',()=>{
  const fixture=setup(),{win,input,wheel}=fixture;
  dispatch(wheel,'pointerdown',{clientX:246,clientY:250});input.poll(0);
  assert.ok(Math.abs(input.state.snapshot().analog.steer-.5)<1e-12);
  input.state.set('key:ArrowUp','accelerate');assert.equal(input.state.snapshot().analog,undefined);
  input.state.release('key:ArrowUp');assert.ok(input.state.snapshot().analog);
  dispatch(wheel,'pointerup');
  const buttons=Array.from({length:16},()=>({value:0}));buttons[7].value=.35;
  win.navigator.getGamepads=()=>[{id:'pad',connected:true,mapping:'standard',buttons,axes:[.5,0]}];
  input.poll(1);assert.equal(input.state.snapshot().analog.throttle,.35);
  input.state.set('key:ArrowUp','accelerate');assert.equal(input.state.snapshot().analog,undefined);
  input.state.release('key:ArrowUp');assert.equal(input.state.snapshot().analog.throttle,.35);
  input.destroy();
});

test('destroyed controls and secondary mouse buttons cannot create new held input',()=>{
  const fixture=setup(),{input,wheel,pedal}=fixture;
  dispatch(wheel,'pointerdown',{pointerType:'mouse',button:2,clientY:250});
  dispatch(pedal,'pointerdown',{pointerType:'mouse',button:2});assertReleased(fixture);
  input.destroy();dispatch(wheel,'pointerdown',{clientY:250});dispatch(pedal,'pointerdown');
  assertReleased(fixture);
});
