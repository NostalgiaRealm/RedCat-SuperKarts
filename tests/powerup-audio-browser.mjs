import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir, writeFile} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={browser:browser.version(),status:'running',
  scope:'Controlled original pickup contacts, inventory/cooldown grants and RNG states through the live DrivingView tick, with real decoded AudioBufferSource playback. NPC fire invokes the actual AI-facing fire entry directly. These are source regression fixtures, not a full race, native sound-card recording or listening/phone check.',
  characters:[],errors:[]};
try{
  const page=await browser.newPage();
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('response',response=>{if(response.status()>=400&&!response.url().endsWith('/favicon.ico'))
    report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto(origin+'/?skipIntro');
  for(let character=0;character<4;character++){
    await page.evaluate(character=>localStorage.setItem('rcsk.selection.v1',
      JSON.stringify({character,difficulty:1,country:0,race:2})),character);
    await page.goto(origin+'/?drive=0');
    await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
    await page.locator('#world').click();
    const result=await page.evaluate(async character=>{
      const {deactivateNativeProjectile}=await import('/source/simulation/native-projectile.js');
      const {nativeBonusVisual}=await import('/source/simulation/native-bonus.js');
      const view=rcsk.viewer,sim=view.simulation,audio=view.audio;
      view.clock.pause();await audio.resume();
      // No shipped OMP track places type7. Exercise that supported native
      // constructor as explicit injected state, using its original geometry.
      sim.pickups.pickups.push({...sim.pickups.pickups[0],
        ...nativeBonusVisual(audio.config,audio.manifest,7),type:7,state:1,placementIndex:-1});
      const starts=[],requests=[],trace=[];
      const bankEvents=new Set(audio.voices.banks.flatMap(bank=>bank.map(item=>item.event.toLowerCase())));
      let frame=0,stage='fixture',now=view.clock.simulationMs||0;
      const originalExecute=audio.execute.bind(audio),originalRequest=audio.requestVoice.bind(audio);
      audio.execute=commands=>{
        const before=new Map([...audio.slots].map(([id,slot])=>[id,slot.source]));
        originalExecute(commands);
        for(const command of commands)if(command.op==='play'){
          const key=command.voiceId??command.event.toLowerCase(),slot=audio.slots.get(key);
          if(slot?.source&&slot.source!==before.get(key)&&bankEvents.has(command.event.toLowerCase())){
            const data=slot.buffer.getChannelData(0);
            let peak=0;for(const value of data)peak=Math.max(peak,Math.abs(value));
            const entry={event:command.event,file:slot.spec.file,frame,stage,
              frames:slot.buffer.length,sampleRate:slot.buffer.sampleRate,channels:slot.buffer.numberOfChannels,
              originalSampleRate:slot.sampleRate,peak,gain:slot.gainNode.gain.value,
              pan:slot.pan??0,loop:slot.source.loop,rate:slot.source.playbackRate.value,
              bufferMatchesPrepared:slot.source.buffer===slot.buffer};
            starts.push(entry);trace.push({kind:'start',...entry});
          }
        }
      };
      audio.requestVoice=command=>{
        const accepted=originalRequest(command),voice=audio.voices.voices[command.voiceId];
        const bank=audio.voices.banks[command.voiceId];
        const entry={...command,accepted,frame,stage,
          event:bank.find(item=>item.sample===command.sample)?.event??null,
          queued:voice.queue.map(index=>bank[index].sample)};
        requests.push(entry);trace.push({kind:'request',...entry});return accepted;
      };
      const originalPickups=sim.pickups.step.bind(sim.pickups);
      let nextPickupSeed=null;
      sim.pickups.step=(...args)=>{
        stage='post-render-pickups';
        if(nextPickupSeed!==null){sim.pickups.random.seed(nextPickupSeed);nextPickupSeed=null;}
        return originalPickups(...args);
      };
      const originalService=audio.updateVoices.bind(audio);
      audio.updateVoices=options=>{
        stage='voice-controller';const result=originalService(options);stage='after-voice-controller';return result;
      };
      const input={throttle:0,brake:0,steer:0,bonus:0,handbrake:0};
      view.input.snapshot=()=>input;
      const tick=()=>{frame++;stage='before-voice-controller';view.onTick(.025,now+=25);stage='fixture';};
      const stop=()=>{
        audio.execute(audio.voices.clear());
        audio.execute([...audio.slots].filter(([,slot])=>slot.source)
          .map(([voiceId,slot])=>({event:slot.spec.event??voiceId,voiceId,op:'stop'})));
      };
      const reset=()=>{
        for(const shot of [...sim.combat.shots,...sim.combat.secondaryShots])
          if(shot.state===2)deactivateNativeProjectile(shot);
        sim.combat.arms.entries.length=0;sim.combat.effects.fill(null);
        for(const owned of sim.pickups.owned)owned.state=1;
        for(const pickup of sim.pickups.pickups){pickup.state=1;pickup.ageSeconds=0;}
        sim.pickups.eligibleAfter.fill(0);stop();
      };
      // Keep unrelated AI outside deliberately injected pickup contacts.
      for(const actor of sim.opponents)actor.body.position[0]+=100000;
      const rows=[];
      const run=async(name,callback)=>{
        reset();const start=starts.length,request=requests.length,event=trace.length;
        const details=await callback();
        rows.push({name,...details,requests:requests.slice(request),starts:starts.slice(start),trace:trace.slice(event)});
      };
      const collect=(type,racer=sim.actors.length-1)=>{
        const pickup=sim.pickups.pickups.find(item=>item.type===type);
        if(!pickup)throw Error(`Original track0 lacks static pickup ${type}`);
        pickup.position=[...sim.actors[racer].body.position];pickup.state=2;
        nextPickupSeed=11;tick();
        const firstFrame=frame,events=structuredClone(view.pickupEvents);
        tick();return {firstFrame,events,authoredType:type!==7,
          owned:{...sim.pickups.owned[racer]},stars:sim.pickups.stars};
      };
      for(let type=1;type<=7;type++)await run(`player-pickup-${type}`,()=>collect(type));
      for(let type=1;type<=5;type++)for(let level=1;level<=3;level++){
        await run(`player-fire-${type}-${level}`,()=>{
          Object.assign(sim.pickups.owned.at(-1),{type,level,state:2,ageSeconds:0});
          // Inject an eligible prior timestamp, then retain the real 500ms input gate.
          sim.combat.fireGate.lastFireMs=(sim.nativeTickMs-1000)>>>0;
          input.bonus=1;tick();const firstFrame=frame;
          input.bonus=0;tick();return{firstFrame};
        });
      }
      if(character===0){
        for(const type of [1,2,3,4,5,7])await run(`npc-pickup-${type}`,()=>collect(type,0));
        await run('npc-cannot-collect-star',()=>{
          const pickup=sim.pickups.pickups.find(item=>item.type===6);
          pickup.position=[...sim.actors[0].body.position];pickup.state=2;
          tick();tick();return{pickupState:pickup.state};
        });
        for(let type=1;type<=5;type++)for(let level=1;level<=3;level++){
          await run(`npc-fire-${type}-${level}`,()=>{
            Object.assign(sim.pickups.owned[0],{type,level,state:2,ageSeconds:0});
            const fired=sim.combat.fire(0);tick();tick();
            return{fireType:fired.type,inventoryConsumed:sim.pickups.owned[0].state===1};
          });
        }
        await run('empty-inventory-held-fire',()=>{
          sim.combat.fireGate.lastFireMs=(sim.nativeTickMs-1000)>>>0;
          input.bonus=1;tick();tick();input.bonus=0;
        });
        await run('effects-fifo-pickup-before-fire',async()=>{
          const details=collect(1),head=audio.slots.get('psr'),firstSource=head.source;
          if(!firstSource)throw Error('Pickup FIFO source did not start');
          firstSource.playbackRate.value=16; // Shorten only the transport wait after admission.
          Object.assign(sim.pickups.owned.at(-1),{type:1,level:3,state:2,ageSeconds:0});
          sim.combat.fireGate.lastFireMs=(sim.nativeTickMs-1000)>>>0;
          input.bonus=1;tick();input.bonus=0;
          details.queuedAfterFire=audio.voices.voices[10].queue.map(index=>audio.voices.banks[10][index].sample);
          details.sameHeadWhilePlaying=head.source===firstSource;
          const deadline=performance.now()+3000;
          while(head.source===firstSource&&performance.now()<deadline)
            await new Promise(resolve=>setTimeout(resolve,10));
          details.headEnded=head.source!==firstSource;tick();return details;
        });
        await run('held-fire-does-not-repeat-consumed-item',()=>{
          Object.assign(sim.pickups.owned.at(-1),{type:3,level:1,state:2,ageSeconds:0});
          sim.combat.fireGate.lastFireMs=(sim.nativeTickMs-1000)>>>0;
          input.bonus=1;for(let i=0;i<24;i++)tick();input.bonus=0;
        });
        for(const [tier,ratio]of [.25,.55,.85].entries())await run(`homing-player-beep-${tier+1}`,()=>{
          const body=sim.motion.body;
          const shot={type:1,level:2,target:sim.actors.length-1,
            position:[body.position[0]+100,body.position[1],body.position[2]]};
          const arm=sim.combat.arms.create(shot);
          if(!arm)throw Error('Native homing-arm graphics gate is disabled');
          shot.position[0]=body.position[0]+Math.sqrt(ratio)*100;arm.timer=Math.fround(.09);
          tick();tick();return{ratio:arm.ratio};
        });
        await run('homing-npc-arm-silent',()=>{
          const body=sim.actors[0].body;
          const shot={type:1,level:2,target:0,position:[body.position[0]+100,body.position[1],body.position[2]]};
          const arm=sim.combat.arms.create(shot);arm.timer=Math.fround(.09);tick();tick();
        });
        await run('disabled-effects-pickup-and-fire',()=>{
          audio.setGroupVolume(0);const details=collect(1);
          Object.assign(sim.pickups.owned.at(-1),{type:1,level:1,state:2,ageSeconds:0});
          sim.combat.fireGate.lastFireMs=(sim.nativeTickMs-1000)>>>0;
          input.bonus=1;tick();input.bonus=0;
          details.queueEmpty=audio.voices.voices.every(voice=>voice.queue.length===0&&voice.current===-1);
          audio.setGroupVolume(100);return details;
        });
      }
      const banks=audio.voices.banks.map((bank,voiceId)=>({voiceId,samples:bank.map(item=>({sample:item.sample,event:item.event}))}));
      stop();return{character,playerCharacter:sim.racerCharacters.at(-1),playerRacer:sim.actors.length-1,
        roster:sim.racerCharacters,context:audio.context.state,rows,banks};
    },character);
    report.characters.push(result);
    const types=['','ROCKET','SOAP','OIL','GUM','TURBO','EURO','BONUS'];
    const row=name=>result.rows.find(item=>item.name===name);
    const effects=item=>item.requests.filter(request=>request.voiceId===10);
    const started=(item,sample)=>item.requests.some(request=>request.sample===sample&&request.accepted
      &&item.starts.some(start=>start.event.toLowerCase()===request.event.toLowerCase()));
    assert.equal(result.playerCharacter,character);assert.equal(result.context,'running');
    for(let type=1;type<=7;type++){
      const item=row(`player-pickup-${type}`),name=`GOT_${types[type]}`;
      assert.ok(item.events.some(event=>event.racer===result.playerRacer&&(event.type==='bonus'||event.type==='star')),JSON.stringify(item));
      assert.deepEqual(effects(item).map(request=>[request.sample,request.accepted]),[[name,type<=5]]);
      assert.equal(item.requests.find(request=>request.sample===name).frame,item.firstFrame);
      assert.equal(item.requests.find(request=>request.sample===name).stage,'post-render-pickups');
      assert.equal(item.starts.some(start=>start.frame===item.firstFrame),false,'post-render pickup waits until next tick');
      if(type<=5)assert.ok(started(item,name),JSON.stringify(item));
      if(type!==7){
        assert.deepEqual(item.requests.map(request=>[request.sample,request.replace]),
          [['BONUS4',true],[name,false],['BONUS3',true]]);
        assert.ok(started(item,'BONUS3'));assert.equal(started(item,'BONUS4'),false);
      }else{
        assert.equal(item.owned.type,2,'random pickup keeps static GOT_BONUS, not resolved GOT_SOAP');
        assert.ok(started(item,'BONUS4'));assert.ok(!item.starts.some(start=>start.event==='PSW'));
      }
    }
    for(let type=1;type<=5;type++)for(let level=1;level<=3;level++){
      const item=row(`player-fire-${type}-${level}`),sample=`FIRE_${types[type]}${level}`;
      assert.deepEqual(effects(item).map(request=>request.sample),[sample]);
      assert.ok(started(item,sample),JSON.stringify(item));
      assert.ok(item.starts.some(start=>start.event===effects(item)[0].event&&start.frame===item.firstFrame),
        'player fire precedes and reaches same-tick voice service');
    }
    if(character===0){
      for(const type of [1,2,3,4,5,7]){
        const item=row(`npc-pickup-${type}`);assert.ok(item.events.some(event=>event.racer===0));
        assert.deepEqual(effects(item),[]);assert.ok(item.requests.some(request=>request.voiceId!==10));
      }
      assert.equal(row('npc-cannot-collect-star').pickupState,2);
      for(let type=1;type<=5;type++)for(let level=1;level<=3;level++){
        const item=row(`npc-fire-${type}-${level}`);assert.equal(item.inventoryConsumed,true);
        assert.deepEqual(effects(item),[]);assert.equal(item.requests.some(request=>/^TURBO/.test(request.sample)),false);
      }
      assert.deepEqual(effects(row('empty-inventory-held-fire')),[]);
      const fifo=row('effects-fifo-pickup-before-fire');
      assert.equal(fifo.sameHeadWhilePlaying,true);assert.equal(fifo.headEnded,true);
      assert.deepEqual(fifo.queuedAfterFire,['FIRE_ROCKET3']);
      assert.deepEqual(fifo.starts.filter(start=>['PSR','SSR3'].includes(start.event)).map(start=>start.event),['PSR','SSR3']);
      assert.equal(effects(row('held-fire-does-not-repeat-consumed-item')).filter(request=>/^FIRE_/.test(request.sample)).length,1);
      for(let tier=1;tier<=3;tier++)assert.ok(started(row(`homing-player-beep-${tier}`),`ARMBEEP${tier}`));
      assert.equal(row('homing-npc-arm-silent').requests.some(request=>/^ARMBEEP/.test(request.sample)),false);
      assert.equal(row('disabled-effects-pickup-and-fire').starts.length,0);
      assert.equal(row('disabled-effects-pickup-and-fire').queueEmpty,true);
    }
    assert.ok(result.rows.flatMap(item=>item.starts).every(start=>start.frames>0&&start.peak>0
      &&start.bufferMatchesPrepared&&!start.loop&&start.rate>0));
  }
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await mkdir('evidence/audio',{recursive:true});
  await writeFile('evidence/audio/powerup-playback.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify({status:report.status,characters:report.characters.length,
    cases:report.characters.reduce((total,character)=>total+character.rows.length,0),errors:report.errors}));
}
