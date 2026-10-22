/** Private forecast tooling only. Never installs state in an existing race.
 * Fresh constructors retain their own closures; only data are transplanted.
 * Immutable shipped asset inputs/world geometry are shared read-only. */
import {createHash} from 'node:crypto';
import {RaceSimulation} from '../../src/race-simulation.js';
import {NativeRandom} from '../../src/simulation/native-random.js';
import {NativeDeltaFilter} from '../../src/simulation/clock.js';

const OBSERVERS=new Set(['onPlayerCollision','onVoiceRequest','onDirectSound',
  'onSceneryImpact','onEngineStart','onAnimationRequest']);
const CAMERAS=['playerCamera','startCamera','finishCamera','failureCamera'];
const object=value=>value!==null&&typeof value==='object';
const fnText=fn=>typeof fn==='function'?Function.prototype.toString.call(fn):undefined;
const fail=message=>{throw new Error(`Private race snapshot: ${message}`);};

function walkData(value,visit,seen=new Set()){
  if(!object(value)||seen.has(value))return;
  seen.add(value);visit(value);
  if(value instanceof Map){for(const [key,item]of value){walkData(key,visit,seen);walkData(item,visit,seen);}return;}
  if(value instanceof Set){for(const item of value)walkData(item,visit,seen);return;}
  if(value instanceof WeakMap||value instanceof WeakSet)return;
  for(const descriptor of Object.values(Object.getOwnPropertyDescriptors(value)))
    if('value'in descriptor)walkData(descriptor.value,visit,seen);
}

function requireBoundary(sim,options){
  if(!(sim instanceof RaceSimulation))fail('expected a RaceSimulation');
  if(options.raceMode!==1||sim.pickups.enabledTypes.size)fail('only original timed mode with pickups disabled is supported');
  if(sim.race.track!==options.track||sim.combat.config!==options.config||sim.combat.manifest!==options.manifest)
    fail('constructor asset identities do not match source');
  if(sim.difficulty!==(options.difficulty??1)||sim.setup.player.availableIndex!==(options.character??0))
    fail('constructor character/difficulty do not match source');
  if(!sim.lifecycle.running||sim.lifecycle.resultGate||sim.race.finished||![0,1,2].includes(sim.race.phase)
    ||sim.finishCamera||sim.failureCamera)fail('terminal/finish/expiry state is outside scope');
  if(sim.actors.some(actor=>actor.prepared))fail('snapshot must be at a completed prepare/integrate boundary');
  if(sim.pickups.owned.some(item=>item.state===2)||sim.combat.activeCount()
    ||sim.combat.effects.some(Boolean)||sim.bubbles.entries.some(Boolean)||sim.combat.arms.entries.length)
    fail('active owned bonus/projectile/effect is outside scope');
}

/** Caller-declared observer wrappers must only record data and chain any native
 * callback they replace. The clone restores the fresh native callback instead
 * of copying the wrapper. This is a trust contract, not analysis of JS effects. */
export function createPrivateRaceSnapshotter({constructorOptions,constructionSeed=0,permittedObservers=[]}){
  if(!constructorOptions||constructorOptions.raceMode!==1)fail('explicit original timed constructor options required');
  for(const name of permittedObservers)if(!OBSERVERS.has(name))fail(`unknown observer permission ${name}`);
  const allowed=new Set(permittedObservers),options={...constructorOptions};
  if(!Number.isInteger(constructionSeed)||constructionSeed<0||constructionSeed>0xffffffff)
    fail('constructionSeed must be the recorded uint32 original construction seed');
  const initialSeed=constructionSeed;
  // Supplying a live rotation Map to the fresh constructor would leak aliases.
  const initialRotations=options.rotationStates?structuredClone(options.rotationStates):undefined;
  const immutable=new WeakSet(),immutableNames=new WeakMap();
  function readonly(value,name){
    if(!object(value))return;
    if(!immutable.has(value))walkData(value,item=>{immutable.add(item);});
    immutableNames.set(value,name);
  }
  for(const name of ['config','manifest','cars','track'])readonly(options[name],name);
  const registered=new WeakSet();
  function registerGeometry(sim){
    if(registered.has(sim))return;
    readonly(sim.world,'world');
    sim.actors.forEach((actor,index)=>{
      readonly(actor.physics,`physics:${index}`);readonly(actor.racer,`racer:${index}`);
      readonly(actor.playerRacer,`playerRacer:${index}`);
      readonly(actor.collision.rails,`rails:${index}`);readonly(actor.collision.bounds,`bounds:${index}`);
    });
    readonly(sim.scenery.collision.rails,'rails:scenery');
    readonly(sim.scenery.collision.bounds,'bounds:scenery');
    registered.add(sim);
  }

  function clone(source,{filter}={}){
    requireBoundary(source,options);registerGeometry(source);
    if(filter!==undefined&&!(filter instanceof NativeDeltaFilter))fail('filter must be NativeDeltaFilter');
    const fresh=new RaceSimulation({...options,random:new NativeRandom(initialSeed),
      rotationStates:initialRotations?structuredClone(initialRotations):undefined});
    const pairs=new Map(),copied=new Set();
    function pair(a,b,label){
      if(!object(a)||!object(b))fail(`missing paired constructor object ${label}`);
      if(Object.getPrototypeOf(a)!==Object.getPrototypeOf(b))fail(`prototype mismatch ${label}`);
      if(pairs.has(a)&&pairs.get(a)!==b)fail(`conflicting semantic identity ${label}`);
      pairs.set(a,b);
    }
    pair(source,fresh,'race');
    // All constructor-created service instances retain their private arrow
    // fields. Stable identity arrays also remain in place for captured closures.
    for(const key of Object.keys(fresh)){
      if(key==='camera')continue; // Active camera is an alias, not a fixed role.
      const a=source[key],b=fresh[key];
      if(object(a)&&object(b)&&!(a instanceof WeakMap)&&!immutable.has(a))pair(a,b,key);
    }
    pair(source.rescue.occupants(),fresh.rescue.occupants(),'captured racer bodies');
    source.actors.forEach((actor,index)=>{
      const target=fresh.actors[index];pair(actor,target,`actor:${index}`);
      pair(actor.body,target.body,`racer-body:${actor.body.id}`);
      pair(actor.collision,target.collision,`racer-collision:${index}`);
      pair(actor.groundClock,target.groundClock,'shared ground clock');
      if(actor.progress)pair(actor.progress,target.progress,`progress:${index}`);
    });
    for(const name of ['scenery','sceneryReactions','sceneryHazards']){
      for(const [id,body]of source[name].byPlacement)
        pair(body,fresh[name].byPlacement.get(id),`${name}:${id}`);
    }
    pair(source.scenery.collision,fresh.scenery.collision,'scenery collision');
    pair(source.pickups.random,fresh.pickups.random,'shared random');
    pair(source.combat.fireGate,fresh.combat.fireGate,'fire gate');
    pair(source.combat.arms,fresh.combat.arms,'arms');
    source.squash.entries.forEach(entry=>{
      const body=pairs.get(entry.body),target=fresh.squash.entries.find(item=>item.body===body);
      pair(entry,target,`squash:${entry.timerId}:${entry.body.placementIndex??entry.body.id}`);
    });
    // capture() sorts clouds in place; source index is not construction identity.
    const clouds=new Map(fresh.smoke.clouds.map(cloud=>[cloud.id,cloud]));
    source.smoke.clouds.forEach(cloud=>pair(cloud,clouds.get(cloud.id),`cloud:${cloud.id}`));
    source.combat.shots.forEach((shot,index)=>pair(shot,fresh.combat.shots[index],`primary-shot:${index}`));
    source.combat.secondaryShots.forEach((shot,index)=>pair(shot,fresh.combat.secondaryShots[index],`secondary-shot:${index}`));

    function copy(value,path){
      if(!object(value)){
        if(typeof value==='function')fail(`unpaired function ${path}`);
        return value;
      }
      if(immutable.has(value))return value;
      if(value instanceof WeakMap||value instanceof WeakSet)fail(`unhandled weak collection ${path}`);
      let target=pairs.get(value);
      if(!target){
        const proto=Object.getPrototypeOf(value);
        if(Array.isArray(value))target=[];
        else if(value instanceof Map)target=new Map();
        else if(value instanceof Set)target=new Set();
        else if(ArrayBuffer.isView(value))target=new value.constructor(value.length);
        else if(proto===Object.prototype||proto===null)target=Object.create(proto);
        else fail(`unpaired class ${value.constructor?.name} at ${path}`);
        pairs.set(value,target);
      }
      if(copied.has(value))return target;
      copied.add(value);
      if(value instanceof Map){target.clear();for(const [k,v]of value)target.set(copy(k,`${path}.key`),copy(v,`${path}.value`));return target;}
      if(value instanceof Set){target.clear();for(const v of value)target.add(copy(v,`${path}.value`));return target;}
      if(ArrayBuffer.isView(value)){target.set(value);return target;}
      // Retain fresh internal functions/accessors. A missing/changed one is an
      // explicit unsupported override, except named top-level observer wrappers.
      const descriptors=Object.getOwnPropertyDescriptors(value);
      for(const key of Reflect.ownKeys(target)){
        if(key==='length'&&Array.isArray(target))continue;
        if(!Object.hasOwn(descriptors,key)&&!(value===source&&allowed.has(key)))delete target[key];
      }
      for(const key of Reflect.ownKeys(descriptors)){
        if(key==='length'&&Array.isArray(value))continue;
        if(value===source&&key==='cameraSectors')continue;
        const descriptor=descriptors[key],existing=Object.getOwnPropertyDescriptor(target,key),at=`${path}.${String(key)}`;
        if(value===source&&allowed.has(key)){
          if(typeof descriptor.value!=='function')fail(`observer is not a function ${at}`);
          // Internal onPlayerCollision remains native; optional sinks stay absent.
          continue;
        }
        if(!('value'in descriptor)){
          if(!existing||fnText(existing.get)!==fnText(descriptor.get)||fnText(existing.set)!==fnText(descriptor.set))
            fail(`unsupported accessor ${at}`);
        }else if(typeof descriptor.value==='function'){
          if(typeof existing?.value!=='function'||fnText(existing.value)!==fnText(descriptor.value))
            fail(`unsupported function override ${at}`);
        }else Object.defineProperty(target,key,{...descriptor,value:copy(descriptor.value,at)});
      }
      if(Array.isArray(value))target.length=value.length;
      return target;
    }
    copy(source,'simulation');
    fresh.cameraSectors=new WeakMap();
    for(const name of CAMERAS){
      const camera=source[name];
      if(camera&&source.cameraSectors.has(camera))fresh.cameraSectors.set(copy(camera,name),source.cameraSectors.get(camera));
    }
    const privateFilter=filter?Object.assign(new NativeDeltaFilter(),{
      history:[...filter.history],initialDelta:filter.initialDelta}):undefined;
    registerGeometry(fresh);
    return {simulation:fresh,filter:privateFilter};
  }

  /** Deterministic graph view for recurrence/no-mutation checks. It retains
   * alias topology, Map/Set order, NaN/Infinity/-0 and the known WeakMap keys.
   * Functions are excluded; clone() separately validates their known origins. */
  function capture(sim,{filter}={}){
    registerGeometry(sim);
    const ids=new Map();
    function encode(value){
      if(typeof value==='number'&&!Number.isFinite(value))return {$number:String(value)};
      if(Object.is(value,-0))return {$number:'-0'};
      if(value===undefined)return {$undefined:true};
      if(typeof value==='function')return {$function:true};
      if(!object(value))return value;
      if(immutable.has(value))return {$immutable:immutableNames.get(value)??'asset-child'};
      if(ids.has(value))return {$ref:ids.get(value)};
      const id=ids.size;ids.set(value,id);
      if(value===sim.cameraSectors)return {$id:id,$type:'CameraSectors',entries:CAMERAS.flatMap(name=>
        sim[name]&&value.has(sim[name])?[[name,value.get(sim[name])]]:[])};
      if(value instanceof WeakMap||value instanceof WeakSet)fail('unknown weak collection in capture');
      if(value instanceof Map)return {$id:id,$type:'Map',entries:[...value].map(([k,v])=>[encode(k),encode(v)])};
      if(value instanceof Set)return {$id:id,$type:'Set',entries:[...value].map(encode)};
      if(ArrayBuffer.isView(value))return {$id:id,$type:value.constructor.name,values:[...value].map(encode)};
      const props={};
      for(const key of Object.keys(value).sort()){
        const descriptor=Object.getOwnPropertyDescriptor(value,key);
        if(typeof descriptor.value==='function')continue;
        props[key]='value'in descriptor?encode(descriptor.value):{$accessor:true};
      }
      return {$id:id,$type:value.constructor?.name??'null',props};
    }
    return {simulation:encode(sim),filter:filter?encode(filter):null};
  }
  function fingerprint(sim,options){return createHash('sha256').update(JSON.stringify(capture(sim,options))).digest('hex');}
  function assertIsolated(source,copy){
    registerGeometry(source);const live=new Set();walkData(source,value=>{if(!immutable.has(value))live.add(value);});
    walkData(copy,value=>{if(live.has(value))fail('mutable source identity escaped into forecast');});
    if(source.rescue.occupants()===copy.rescue.occupants())fail('captured occupants array escaped');
    for(const body of copy.rescue.occupants())if(live.has(body))fail('captured occupants body escaped');
    return true;
  }
  return Object.freeze({clone,capture,fingerprint,assertIsolated,
    scope:'Private headless timed race snapshots; immutable assets shared; observer wrappers explicitly restored/omitted; no writeback API.'});
}
