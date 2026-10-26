import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';

const output=process.env.RCSK_STAR_HUD_OUTPUT||'evidence/star-hud/browser';
await mkdir(output,{recursive:true});
const report={status:'running',scope:'Source-only software-WebGL browser regression. Twelve distinct original pickup contacts pass through NativeBonusPickups.step with the original cooldown; the live kart is not teleported and the star count is never assigned. This is controlled pickup/HUD coverage, not a full race.',checks:[],errors:[]};
const files=['source/race-hud-meshes.js','source/race-hud-layout.js','source/simulation/native-star-hud.js',
  'source/simulation/native-bonus.js','tests/star-hud-browser.mjs',
  'public/assets/config.json','public/assets/meshes/ovrlster.json','public/assets/meshes/ovrlvlag.json',
  'public/assets/textures/overlay1.tga.png'];
const hashes=async()=>Object.fromEntries(await Promise.all(files.map(async file=>[file,
  createHash('sha256').update(await readFile(file)).digest('hex')])));
report.hashesBefore=await hashes();
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
try{
  const page=await browser.newPage({viewport:{width:1280,height:720}});
  page.on('pageerror',error=>report.errors.push(error.stack||error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.addInitScript(()=>{
    localStorage.setItem('rcsk.selection.v1',JSON.stringify({character:1,difficulty:0,country:0,race:2}));
    localStorage.setItem('rcsk.settings.v1',JSON.stringify({touch:'on'}));
  });
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4174')+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000});
  await page.evaluate(()=>rcsk.viewer.clock.pause());
  const snap=async()=>page.evaluate(async()=>{
    const v=rcsk.viewer,h=v.hudMeshes;
    // A manually loaded, paused non-star mode has not captured its first
    // native render point yet. Its current original body position is valid.
    h.capture(v.simulation.playerHudPosition??v.motion.body.position,0);
    v.updatePresentation(1);v.renderScene();v.hud.render();
    const THREE=await import('three'),layout=v.hud.layout,viewport=layout.group('stars');
    h.layer('stars').scene.updateMatrixWorld(true);h.camera.updateMatrixWorld(true);
    const nodes=['starflag',...Array.from({length:12},(_,i)=>`star${i+1}`)].map(id=>{
      const e=h.elements.get(id);if(!e)throw Error(`Missing loaded original star HUD element ${id}`);
      const p=e.mesh.geometry.attributes.position;
      const points=Array.from({length:p.count},(_,i)=>new THREE.Vector3().fromBufferAttribute(p,i)
        .applyMatrix4(e.mesh.matrixWorld).project(h.camera))
        .map(p=>[viewport.x+(p.x+1)*viewport.width/2,viewport.y+(1-p.y)*viewport.height/2]);
      return {id,visible:e.mesh.visible,rgba:Array.from(e.mesh.geometry.attributes.color.array.slice(0,4)),
        mesh:h.spec(id).mesh,texture:h.spec(id).texture,positions:Array.from(p.array),
        bounds:{left:Math.min(...points.map(p=>p[0])),right:Math.max(...points.map(p=>p[0])),
          top:Math.min(...points.map(p=>p[1])),bottom:Math.max(...points.map(p=>p[1]))}};
    });
    return {mode:v.race.raceType,count:v.pickups.stars,nodes,viewport,
      collected:nodes.slice(1).filter(n=>n.rgba[0]===255).length,
      canvas:{width:v.hud.canvas.width,height:v.hud.canvas.height},
      layout:{portrait:layout.portrait,scale:layout.scale},
      playerPosition:[...v.motion.body.position]};
  });
  const checkArt=state=>{
    const flag=state.nodes[0];assert.equal(flag.mesh,'meshes/ovrlvlag.json');
    assert.equal(flag.texture,'textures/overlay1.tga.png');assert.deepEqual(flag.rgba,[0,0,255,127]);
    for(const star of state.nodes.slice(1)){
      assert.equal(star.mesh,'meshes/ovrlster.json');assert.equal(star.texture,'textures/overlay1.tga.png');
      assert.equal(star.positions.length,12);assert.equal(star.rgba[3],255);
    }
  };
  const zero=await snap();checkArt(zero);
  assert.equal(zero.mode,2);assert.equal(zero.count,0);assert.equal(zero.collected,0);
  assert.ok(zero.nodes.every(n=>n.visible));
  assert.ok(zero.nodes.slice(1).every(n=>n.rgba.slice(0,3).every(c=>c===127)));
  report.checks.push({case:'Sterrenrace begins with the original field and twelve empty star icons',...zero});
  await page.screenshot({path:output+'/wide-0.png'});
  const collect=async number=>page.evaluate(number=>{
    const v=rcsk.viewer,c=v.pickups,sim=v.simulation,player=sim.actors.length-1;
    window.starHudContactLog??=[];
    const candidates=c.pickups.map((p,index)=>({p,index})).filter(({p})=>p.type===6&&p.state===2);
    if(candidates.length<number)throw Error(`Only ${candidates.length} active original stars remain`);
    for(const {p,index}of candidates.slice(0,number)){
      const racers=sim.actors.map((actor,i)=>({position:i===player?[...p.position]:[...actor.body.position],
        radius:actor.radius,canCollect:i===player}));
      const attempts=[];let star;
      // A nearby ordinary bonus can precede this star in native placement
      // order and consume the shared pickup cooldown. Retain that real event,
      // then admit the next controller update after the original cooldown.
      for(let attempt=0;attempt<5&&!star;attempt++){
        const nowSeconds=Math.max(sim.engineMs/1000+1,c.eligibleAfter[player]+.01);
        const events=c.step(.025,nowSeconds,racers);
        attempts.push({nowSeconds,events});
        star=events.find(event=>event.type==='star'&&event.pickup===index&&event.racer===player);
      }
      if(!star)throw Error(`Original star pickup ${index} did not collect: ${JSON.stringify(attempts)}`);
      starHudContactLog.push({index,position:[...p.position],attempts,event:star});
    }
    return {count:c.stars,events:starHudContactLog,playerPosition:[...v.motion.body.position]};
  },number);
  const first=await collect(1),one=await snap();checkArt(one);
  assert.equal(first.count,1);assert.equal(one.collected,1);
  assert.deepEqual(one.playerPosition,zero.playerPosition);
  report.checks.push({case:'one actual original pickup contact fills exactly one icon',contact:first,view:one});
  await page.screenshot({path:output+'/wide-1.png'});
  const last=await collect(11),twelve=await snap();
  assert.equal(last.count,12);assert.equal(twelve.collected,12);
  assert.equal(new Set(last.events.map(e=>e.index)).size,12);
  assert.deepEqual(twelve.playerPosition,zero.playerPosition);
  assert.ok(twelve.nodes.every(n=>n.visible));
  report.checks.push({case:'twelve distinct pickup contacts fill all twelve icons',contacts:last,view:twelve});
  await page.screenshot({path:output+'/wide-12.png'});
  await page.setViewportSize({width:390,height:844});
  const portrait=await snap();checkArt(portrait);
  assert.equal(portrait.layout.portrait,true);assert.equal(portrait.collected,12);
  const bounds=portrait.nodes[0].bounds;
  assert.ok(bounds.left>=0&&bounds.top>=0&&bounds.right<=portrait.canvas.width&&bounds.bottom<=portrait.canvas.height);
  assert.ok(portrait.nodes.slice(1).every(n=>n.bounds.left>=0&&n.bounds.right<=portrait.canvas.width));
  report.checks.push({case:'portrait retains all original star artwork within the viewport',...portrait});
  await page.screenshot({path:output+'/portrait-12.png'});
  await page.setViewportSize({width:1280,height:720});
  for(const mode of [0,1,3]){
    await page.evaluate(async mode=>{const v=rcsk.viewer;v.clock.pause();
      await v.load(0,{character:1,difficulty:0,raceMode:mode});v.clock.pause();},mode);
    const state=await snap();assert.equal(state.mode,mode);assert.ok(state.nodes.every(n=>!n.visible));
    report.checks.push({case:`star counter is hidden in race mode ${mode}`,mode,visible:state.nodes.map(n=>[n.id,n.visible])});
  }
  report.hashesAfter=await hashes();
  report.changedDuringRun=files.filter(file=>report.hashesBefore[file]!==report.hashesAfter[file]);
  assert.deepEqual(report.changedDuringRun,[]);assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=error.stack;throw error;}
finally{await writeFile(output+'/report.json',JSON.stringify(report,null,2)+'\n');await browser.close();}
console.log(`Star HUD browser: ${report.checks.length} checks passed`);
