import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {NativeSliderController,nativeSliderDragPosition,nativeSliderKeyRequest,nativeSliderNeedleLeft,
  nativeSliderPixel,nativeSliderProperties,nativeSliderSetPosition} from '../source/native-slider.js';

const options=JSON.parse(await readFile(new URL('../evidence/native/menu-resources/TFRMOPTIONS.json',import.meta.url)));
const find=(node,name)=>node.name===name?node:node.children.map(child=>find(child,name)).find(Boolean);
const dfm=name=>find(options,name).properties;
const props=nativeSliderProperties(dfm('sldMusicVolume'));
// DFM slider 192x57, needle 35x35 (defMusicVolume) at MarginHorz/MarginVert.
const geometry={width:192,margin:5,needleWidth:35,needleHeight:35,needleTop:6};

function fakeTimers(){
  let now=0,next=1;const timers=new Map();
  return {
    setInterval(callback,delay){const id=next++;timers.set(id,{callback,delay,due:now+delay});return id;},
    clearInterval(id){timers.delete(id);},
    advance(ms){
      const end=now+ms;
      for(;;){
        const [id,timer]=[...timers].sort((a,b)=>a[1].due-b[1].due||a[0]-b[0])[0]??[];
        if(!timer||timer.due>end)break;
        now=timer.due;timer.due+=timer.delay;timer.callback();
      }
      now=end;
    },
    get active(){return timers.size;},
  };
}
function slider(position){
  const timers=fakeTimers(),changes=[];
  const controller=new NativeSliderController(props,{position,geometry:()=>geometry,timers,onChange:value=>changes.push(value)});
  return {controller,timers,changes};
}

test('options sliders use the DFM range, LargeStep and repeat timing',()=>{
  for(const name of ['sldMusicVolume','sldEffectVolume'])
    assert.deepEqual(nativeSliderProperties(dfm(name)),{Min:0,Max:100,LargeStep:17,MarginHorz:5,MarginVert:6,DelayTime:250,RepeatTime:50});
  assert.equal(find(options,'defMusicVolume').properties.Width,35);
});

test('0x45fb80 key steps: arrows 1, Page keys LargeStep, Home Max, End Min',()=>{
  const expected={ArrowLeft:49,ArrowDown:49,ArrowRight:51,ArrowUp:51,PageUp:67,PageDown:33,Home:100,End:0};
  for(const [key,value]of Object.entries(expected))assert.equal(nativeSliderKeyRequest(key,50,props),value,key);
  for(const key of ['Tab','Enter','Escape',' ','a','Delete'])assert.equal(nativeSliderKeyRequest(key,50,props),null,key);
});

test('0x45fd98 clamps after storing and still reports Change at the ends',()=>{
  assert.deepEqual(nativeSliderSetPosition(100,101,props),{position:100,change:true});
  assert.deepEqual(nativeSliderSetPosition(95,112,props),{position:100,change:true});
  assert.deepEqual(nativeSliderSetPosition(5,-12,props),{position:0,change:true});
  assert.deepEqual(nativeSliderSetPosition(0,0,props),{position:0,change:false});
  const {controller,changes}=slider(100);
  for(const key of ['ArrowRight','PageUp','Home','End','End'])controller.key(key);
  // Home at Max and End at Min are equal requests: no OnChange (no sound).
  assert.deepEqual(changes,[100,100,0]);
});

test('track and needle geometry follow 0x45fac0 and 0x45fb08',()=>{
  assert.deepEqual([0,50,67,100].map(p=>nativeSliderPixel(p,geometry,props)),[5,96,126,187]);
  assert.deepEqual([0,50,67,84,100].map(p=>nativeSliderNeedleLeft(p,geometry,props)),[5,78,103,128,152]);
});

test('track press steps LargeStep towards the cursor, repeats after 250 ms then every 50 ms',()=>{
  const {controller,timers,changes}=slider(50);
  assert.equal(controller.pointerDown({x:180,y:20},0),'track');
  assert.deepEqual(changes,[67]);
  timers.advance(249);assert.deepEqual(changes,[67]);
  timers.advance(1);assert.deepEqual(changes,[67,84]);
  timers.advance(50);assert.deepEqual(changes,[67,84,100]);
  // The needle [152,187) now holds the cursor: timer 2 stops, timer 1 then finds it too.
  timers.advance(1000);assert.deepEqual(changes,[67,84,100]);assert.equal(timers.active,0);
  const left=slider(50);left.controller.pointerDown({x:20,y:20},2);
  assert.deepEqual(left.changes,[33]);
  left.controller.pointerUp();left.timers.advance(1000);
  assert.deepEqual(left.changes,[33]);assert.equal(left.timers.active,0);
});

test('track presses keep stepping while the cursor is outside the needle rectangle',()=>{
  // Below the needle (y 41..56) PtInRect never succeeds, so the original alternates.
  const below=slider(50);below.controller.pointerDown({x:100,y:50},0);
  below.timers.advance(400);
  assert.deepEqual(below.changes,[67,50,67,50,67]);
  below.controller.pointerUp();
  // In the right margin past the needle at Max, every repeat calls OnChange at 100.
  const end=slider(100);end.controller.pointerDown({x:190,y:20},0);
  end.timers.advance(350);
  assert.deepEqual(end.changes,[100,100,100,100]);
  end.controller.pointerUp();
});

test('0x45f814 needle drag moves by pixel and maps with 0x45fa58 truncation',()=>{
  const {controller,changes}=slider(0);
  assert.equal(controller.pointerDown({x:20,y:20},0),'needle');
  controller.pointerMove({x:21,y:20},true);
  controller.pointerMove({x:22,y:20},true);
  // Change runs whenever the needle moved, also when the value stays.
  assert.deepEqual(changes,[0,1]);
  controller.pointerMove({x:23,y:20},false);
  assert.deepEqual(changes,[0,1]);
  controller.pointerMove({x:167,y:20},true);assert.equal(controller.position,100);
  // Clamped moves keep the last X, so the needle returns as soon as the cursor does.
  controller.pointerMove({x:220,y:20},true);controller.pointerMove({x:180,y:20},true);
  controller.pointerMove({x:166,y:20},true);
  assert.deepEqual(changes,[0,1,100,99]);
  controller.pointerUp();
  const right=slider(0);assert.equal(right.controller.pointerDown({x:20,y:20},2),'needle');
  right.controller.pointerMove({x:60,y:20},true);assert.deepEqual(right.changes,[]);
});

test('needle drag reaches every whole value on the 147-pixel track',()=>{
  const values=new Set();
  for(let left=5;left<=152;left++)values.add(nativeSliderDragPosition(left,geometry,props));
  assert.deepEqual([...values],Array.from({length:101},(_,i)=>i));
});
