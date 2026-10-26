// Module-level browser diagnostic: start tools/serve.mjs with --inspect-source.
import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const errors=[];
try{
  const page=await browser.newPage();
  page.on('pageerror',error=>errors.push(error.message));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
  await page.locator('#world').click();
  const report=await page.evaluate(async()=>{
    const {deactivateNativeProjectile}=await import('/source/simulation/native-projectile.js');
    const view=rcsk.viewer,sim=view.simulation,audio=view.audio;
    view.clock.pause();await audio.resume();
    const starts=[],requests=[],execute=audio.execute.bind(audio),request=audio.requestVoice.bind(audio);
    audio.execute=commands=>{
      const before=new Map([...audio.slots].map(([id,slot])=>[id,slot.source]));
      execute(commands);
      for(const command of commands)if(command.op==='play'){
        const id=command.voiceId??command.event.toLowerCase(),slot=audio.slots.get(id);
        if(slot?.source&&slot.source!==before.get(id))starts.push({
          event:command.event,voiceId:command.voiceId??null,file:slot.spec.file,
          frames:slot.buffer.length,gain:slot.gainNode.gain.value,loop:slot.source.loop,
        });
      }
    };
    audio.requestVoice=command=>{
      const accepted=request(command);
      const event=audio.voices.banks[command.voiceId]?.find(entry=>entry.sample===command.sample)?.event;
      requests.push({...command,event,accepted});return accepted;
    };
    const input={throttle:0,brake:0,steer:0,bonus:0,handbrake:0};
    const originalSnapshot=view.input.snapshot;
    view.input.snapshot=()=>input;
    // The live host uses variable admitted intervals; begin controlled ticks
    // from its current elapsed simulation time rather than a fixed-step count.
    let now=view.clock.snapshot().simulationMs;
    // Each fixture drives the actual DrivingView tick, including the listener,
    // FIFO service, render capture and post-render bonus handlers.
    const tick=()=>view.onTick(.025,now+=25);
    const clear=()=>{
      audio.execute(audio.voices.clear());
      audio.execute([...audio.slots].filter(([,slot])=>slot.source)
        .map(([id,slot])=>({event:slot.spec.event??id,voiceId:id,op:'stop'})));
    };
    const rows=[];
    const mark=(name,fn)=>{
      // Separate controlled cases: leave no weapons from a previous fixture
      // able to interrupt the later recovery or pickup voice queues.
      for(const shot of [...sim.combat.shots,...sim.combat.secondaryShots])
        if(shot.state===2)deactivateNativeProjectile(shot);
      sim.combat.arms.entries.length=0;
      sim.combat.effects.fill(null);
      clear();const start=starts.length,voice=requests.length;
      const finish=()=>rows.push({name,starts:starts.slice(start),requests:requests.slice(voice)});
      const result=fn();
      if(result?.then)return result.then(finish);
      finish();
    };
    // Prevent unrelated racers collecting deliberately placed pickup fixtures.
    for(const actor of sim.opponents)actor.body.position[0]+=100000;
    for(const pickup of sim.pickups.pickups)pickup.state=1;
    for(let type=1;type<=5;type++)mark(`pickup-${type}`,()=>{
      const pickup=sim.pickups.pickups.find(entry=>entry.type===type);
      if(!pickup)throw Error(`Track0 lacks original pickup type${type}`);
      pickup.position=[...sim.motion.body.position];pickup.state=2;
      sim.pickups.eligibleAfter.fill(0);
      tick();tick();
    });
    for(let type=1;type<=5;type++)for(let level=1;level<=3;level++)mark(`fire-${type}-${level}`,()=>{
      Object.assign(sim.pickups.owned.at(-1),{state:2,type,level,ageSeconds:0});
      // Native input cooldown observes absolute milliseconds, so advance the
      // fixture clock past the prior fire without changing the cooldown rule.
      now+=1000;input.bonus=1;tick();input.bonus=0;tick();
    });
    await mark('recovery',async()=>{
      const first=starts.length;
      sim.rescue.enqueue(sim.motion);
      for(let n=0;n<26;n++){
        // Clear completed test voice occupancy to allow both independent
        // recovery phases to demonstrate real transport admission.
        if(n===20)clear();
        tick();
      }
      // Simulation ticks above run faster than actual PCM playback. A native
      // passing voice may legitimately enter the same FIFO before REAPP.
      // Keep servicing real ticks while that source finishes instead of
      // suppressing it or assuming that queued audio starts synchronously.
      const deadline=performance.now()+5000;
      while(!starts.slice(first).some(sound=>sound.event.toUpperCase()==='REAPP')
        &&performance.now()<deadline){
        await new Promise(resolve=>setTimeout(resolve,25));
        tick();
      }
    });
    mark('scenery-impact',()=>{
      const object=sim.sceneryReactions.objects[0];
      object.position=[...sim.motion.body.position];object.sector=sim.motion.body.sector;object.mode=0;
      sim.motion.body.forwardSpeed=10;tick();
    });
    mark('space-key',()=>{
      view.input.keys.add(32);tick();view.input.keys.delete(32);
    });
    // Explicit native controller fixtures: an existing level2 homing rocket
    // targets the player. Hold its squared-distance ratio away from thresholds,
    // then let the real arm callback queue the sound after voice service.
    for(const [index,ratio]of [.25,.55,.85].entries())mark(`arm-beep-${index+1}`,()=>{
      const body=sim.motion.body;
      body.forwardSpeed=body.lateralSpeed=body.verticalSpeed=0;
      const shot={type:1,level:2,target:sim.actors.length-1,
        position:[body.position[0]+100,body.position[1],body.position[2]]};
      const arm=sim.combat.arms.create(shot);
      if(!arm)throw Error('Original homing arm graphics gates disabled');
      shot.position[0]=body.position[0]+Math.sqrt(ratio)*100;
      arm.timer=Math.fround(.09);
      tick();tick();
    });
    view.input.snapshot=originalSnapshot;
    return {rows,contextState:audio.context.state,
      scope:'Controlled state fixtures through the live DrivingView tick. Checks original pickup/fire/recovery/scenery/Space and real homing-arm controller triggers reach decoded WebAudio sources; this is not a driven race or a speaker recording.'};
  });
  const expected=['GOT_ROCKET','GOT_SOAP','GOT_OIL','GOT_GUM','GOT_TURBO'];
  const names=row=>row.starts.map(sound=>sound.event.toUpperCase());
  const played=(row,sample)=>row.requests.some(request=>request.sample===sample&&request.accepted
    &&row.starts.some(sound=>sound.event.toLowerCase()===request.event?.toLowerCase()));
  for(let type=1;type<=5;type++){
    const row=report.rows.find(row=>row.name===`pickup-${type}`);
    assert.ok(played(row,expected[type-1]),JSON.stringify(row));
  }
  for(let type=1;type<=5;type++)for(let level=1;level<=3;level++){
    const row=report.rows.find(row=>row.name===`fire-${type}-${level}`);
    assert.ok(played(row,`FIRE_${['ROCKET','SOAP','OIL','GUM','TURBO'][type-1]}${level}`),JSON.stringify(row));
  }
  const recovery=report.rows.find(row=>row.name==='recovery');
  assert.ok(['DISAPP','REAPP'].every(sample=>played(recovery,sample)),JSON.stringify(recovery));
  assert.ok(report.rows.find(row=>row.name==='scenery-impact').starts.some(sound=>sound.voiceId!==null));
  assert.ok(names(report.rows.find(row=>row.name==='space-key')).includes('KT4'));
  for(let beep=1;beep<=3;beep++){
    const row=report.rows.find(row=>row.name===`arm-beep-${beep}`);
    assert.ok(played(row,`ARMBEEP${beep}`),JSON.stringify(row));
  }
  assert.ok(report.rows.flatMap(row=>row.starts).every(sound=>sound.frames>0));
  assert.deepEqual(errors,[]);
  report.browser=browser.version();report.errors=errors;report.status='passed';
  await writeFile('evidence/audio/race-trigger-playback.json',JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,fixtures:report.rows.length,
    starts:report.rows.reduce((n,row)=>n+row.starts.length,0),context:report.contextState}));
}finally{await browser.close();}
