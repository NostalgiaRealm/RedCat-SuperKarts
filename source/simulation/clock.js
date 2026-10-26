/**
 * Original update-start gate (0x4432a0), independent of display refresh.
 * A caller-owned timer invokes advance(); rendering only reads snapshot().
 * Each admitted callback consumes the actual elapsed interval once. There is
 * no fixed-step backlog, catch-up loop, or discarded stall duration here.
 *
 * GetTickCount supplies the integer gate; the physics clock uses the measured
 * floating timestamp. Resume resets only that physics baseline (0x48f520),
 * while the gate retains the previous update start. Absolute wall time keeps
 * advancing during pauses; active simulation time excludes those pauses.
 */
export class NativeUpdateClock {
  constructor({update,minIntervalMs=25}={}) {
    if(typeof update!=='function')throw new TypeError('An update function is required');
    if(!Number.isInteger(minIntervalMs)||minIntervalMs<=0||minIntervalMs>0xffffffff)
      throw new RangeError('A positive integer minimum interval is required');
    this.update=update;this.minIntervalMs=minIntervalMs;this.intervalMs=minIntervalMs;
    this.lastIntervalMs=minIntervalMs;
    this.tick=0;this.simulationMs=0;this.elapsedMs=0;this.wallMs=0;this.paused=false;
    this.originTimestamp=null;this.lastTimestamp=null;this.previousStartTick=null;
    this.deltaTimestamp=null;
  }
  validateTimestamp(timestampMs) {
    if(!Number.isFinite(timestampMs))throw new RangeError('Invalid timestamp');
    if(this.lastTimestamp!==null&&timestampMs<this.lastTimestamp)
      throw new RangeError('Clock cannot run backward');
  }
  observe(timestampMs) {
    this.validateTimestamp(timestampMs);
    if(this.lastTimestamp===null){
      this.originTimestamp=timestampMs;this.previousStartTick=Math.floor(timestampMs)>>>0;
      this.deltaTimestamp=timestampMs;
    }else if(!this.paused)this.elapsedMs+=timestampMs-this.lastTimestamp;
    this.lastTimestamp=timestampMs;this.wallMs=timestampMs-this.originTimestamp;
  }
  advance(timestampMs) {
    const initialized=this.lastTimestamp!==null;
    this.observe(timestampMs);
    if(!initialized||this.paused)return this.snapshot();
    const startTick=Math.floor(timestampMs)>>>0;
    if(((startTick-this.previousStartTick)>>>0)<this.minIntervalMs)return this.snapshot();
    const deltaMs=timestampMs-this.deltaTimestamp;
    this.previousStartTick=startTick;this.deltaTimestamp=timestampMs;
    this.lastIntervalMs=deltaMs;this.simulationMs=this.elapsedMs;this.tick++;
    this.update(deltaMs/1000,this.simulationMs,this.tick);
    return this.snapshot();
  }
  pause(timestampMs=this.lastTimestamp??0) {
    this.observe(timestampMs);this.paused=true;
    return this.snapshot();
  }
  resume(timestampMs=this.lastTimestamp??0) {
    const wasPaused=this.paused,initialized=this.lastTimestamp!==null;
    this.observe(timestampMs);
    if(wasPaused||!initialized)this.deltaTimestamp=timestampMs;
    this.paused=false;
    return this.snapshot();
  }
  snapshot(timestampMs=this.lastTimestamp) {
    if(timestampMs!==null)this.validateTimestamp(timestampMs);
    const initialized=this.lastTimestamp!==null;
    const pending=initialized&&!this.paused?timestampMs-this.lastTimestamp:0;
    const elapsedMs=this.elapsedMs+pending;
    const sinceUpdate=elapsedMs-this.simulationMs;
    const gateElapsed=initialized?((Math.floor(timestampMs)-this.previousStartTick)>>>0):0;
    return {
      tick:this.tick,simulationMs:this.simulationMs,elapsedMs,
      wallMs:initialized?timestampMs-this.originTimestamp:0,
      intervalMs:this.intervalMs,lastIntervalMs:this.lastIntervalMs,
      // A zero reset-relative interval has no interpolatable duration.
      alpha:this.lastIntervalMs>0?Math.max(0,Math.min(1,sinceUpdate/this.lastIntervalMs)):1,
      paused:this.paused,
      nextUpdateInMs:this.paused?null:Math.max(0,this.minIntervalMs-gateElapsed),
    };
  }
}

/**
 * Deterministic update host. The caller MUST supply a justified simulation
 * interval: this module makes no claim that the original used a fixed rate.
 * Captured native traces can separately drive kernels with their recorded delta.
 */
export class SimulationClock {
  constructor({ intervalMs, update, maxUpdatesPerFrame = 10000 }) {
    if (!Number.isFinite(intervalMs) || intervalMs <= 0) throw new RangeError('A positive intervalMs is required');
    if (typeof update !== 'function') throw new TypeError('An update function is required');
    this.intervalMs = intervalMs;
    this.update = update;
    this.maxUpdatesPerFrame = maxUpdatesPerFrame;
    this.elapsedMs = 0;
    this.tick = 0;
    this.paused = false;
    this.lastTimestamp = null;
  }
  frame(timestampMs) {
    if (!Number.isFinite(timestampMs)) throw new RangeError('Invalid timestamp');
    if (this.lastTimestamp === null || this.paused) {
      this.lastTimestamp = timestampMs;
      return this.snapshot();
    }
    if (timestampMs < this.lastTimestamp) throw new RangeError('Clock cannot run backward');
    const elapsed = timestampMs - this.lastTimestamp;
    this.lastTimestamp = timestampMs;
    this.elapsedMs += elapsed;
    // Multiplication by tick avoids accumulated fixed-step rounding drift.
    const targetTick = Math.floor((this.elapsedMs + 1e-8) / this.intervalMs);
    if (targetTick - this.tick > this.maxUpdatesPerFrame) {
      // Keep elapsed time pending; never silently discard simulated time.
      throw new RangeError('Simulation backlog exceeds safety limit; pause and resume explicitly');
    }
    while (this.tick < targetTick) {
      this.tick++;
      this.update(this.intervalMs / 1000, this.tick * this.intervalMs, this.tick);
    }
    return this.snapshot();
  }
  pause() { this.paused = true; this.lastTimestamp = null; }
  resume() { this.paused = false; this.lastTimestamp = null; }
  snapshot() {
    return {
      tick: this.tick, simulationMs: this.tick * this.intervalMs, elapsedMs: this.elapsedMs,
      alpha: Math.max(0, Math.min(1, (this.elapsedMs - this.tick * this.intervalMs) / this.intervalMs)),
      paused: this.paused,
    };
  }
}

/** Native delta filter, 0x48f3e0/0x48f4e0, for reference trace replay.
 * Native float absolute-clock subtraction can produce tiny negative deltas even
 * for equal clock samples. Preserve signed finite input here; the modern frame
 * adapter separately rejects backward wall time. See original x86 fixtures.
 */
/** Explicit browser reference-host policy: an already-running host, not race age.
 * Original initialization has the same capped delta/first three capped updates
 * for tested host uptimes >=1s; 60s also expires the original zero-initialized
 * 5s turbo-animation window and other raw-tick startup deadlines.
 * Absolute-clock cancellation remains an input
 * to native trace replay, not a reason to make browser physics depend on uptime.
 */
export const NATIVE_REFERENCE_UPTIME_MS=60000;

export class NativeDeltaFilter {
  constructor({uptimeMs}={}) {
    this.history = [0.1, 0.1, 0.1];
    this.initialDelta = undefined;
    if(uptimeMs!==undefined)this.initialize(uptimeMs);
  }
  /** 0x48f2c0 calls the timer update once with previous absolute time zero.
   * Host uptime is an explicit adapter input; do not equate it with race time.
   */
  initialize(uptimeMs) {
    if(!Number.isFinite(uptimeMs)||uptimeMs<0)throw new RangeError('Invalid initial host uptime');
    this.history=[0.1,0.1,0.1];
    this.initialDelta=this.sample(Math.fround(uptimeMs/1000));
    return this.initialDelta;
  }
  sample(deltaSeconds) {
    if (!Number.isFinite(deltaSeconds)) throw new RangeError('Invalid delta');
    const delta = Math.fround(deltaSeconds);
    let filtered = Math.fround(delta * 0.5);
    filtered = Math.fround(filtered + this.history[0] * 0.25);
    filtered = Math.fround(filtered + this.history[1] * 0.125);
    filtered = Math.fround(filtered + this.history[2] * 0.125);
    this.history = [delta, this.history[0], this.history[1]];
    return filtered === 0 || filtered > 0.1 ? 0.1 : filtered;
  }
}

/** Original 0x48f2c0/0x48f3e0 absolute engine clock, not a duration accumulator.
 * The host chooses its explicit epoch; native QPC/timeGetTime inputs can also
 * be replayed as counter/frequency pairs. No scheduler or wall-time gating is
 * performed here. In particular, reset is not another cold initialization.
 */
export class NativeEngineTimer {
  constructor({absoluteSeconds=0,precision=24,counter,frequency}={}){
    if(![24,53].includes(precision))throw new RangeError('Native clock precision must be24 or53');
    this.precision=precision;this.absoluteSeconds=0;this.deltaSeconds=0;
    this.rawDelta=0;this.history=Array(4).fill(Math.fround(.1));this.historyIndex=0;
    this.initialDelta=counter===undefined?this.sampleAbsoluteSeconds(absoluteSeconds):this.sampleCounter(counter,frequency);
  }
  quotient(counter,frequency){
    if(!Number.isFinite(counter)||counter<0||!Number.isFinite(frequency)||frequency<=0)
      throw new RangeError('Invalid native absolute clock');
    const seconds=counter/Math.fround(frequency);
    return this.precision===24?Math.fround(seconds):seconds;
  }
  /** Counter is the full native QPC integer, or unsigned timeGetTime value. */
  sampleCounter(counter,frequency){return this.sampleQuotient(this.quotient(counter,frequency));}
  sampleAbsoluteSeconds(seconds){return this.sampleCounter(seconds,1);}
  sampleQuotient(seconds){
    const f=Math.fround,r=this.precision===24?f:Number;
    // The quotient remains at x87 precision until both separate FSTP stores.
    this.rawDelta=f(r(seconds-this.absoluteSeconds));this.absoluteSeconds=f(seconds);
    this.history[this.historyIndex]=this.rawDelta;
    let value=f(r(this.rawDelta*.5));
    for(const [offset,weight]of [[1,.25],[2,.125],[3,.125]])
      value=f(r(value+r(this.history[(this.historyIndex-offset+4)%4]*weight)));
    this.historyIndex=(this.historyIndex+1)%4;this.deltaSeconds=value;
    return this.readDelta();
  }
  resetCounter(counter,frequency){
    this.absoluteSeconds=Math.fround(this.quotient(counter,frequency));
    this.deltaSeconds=0;this.rawDelta=0;this.history.fill(Math.fround(.1));
    // 0x48f520 deliberately leaves the circular history index untouched.
    return this.readDelta();
  }
  resetAbsoluteSeconds(seconds){return this.resetCounter(seconds,1);}
  readDelta(){return this.deltaSeconds===0||this.deltaSeconds>.1?Math.fround(.1):this.deltaSeconds;}
}

/** Explicit active-time clock used by browser pause/focus adapters. */
export class RaceClock {
  constructor() { this.elapsedMs = 0; this.running = false; this.lastTimestamp = null; }
  start(timestampMs) { this.running = true; this.lastTimestamp = timestampMs; }
  advance(timestampMs) {
    if (!Number.isFinite(timestampMs)) throw new RangeError('Invalid timestamp');
    if (this.running && this.lastTimestamp !== null) {
      if (timestampMs < this.lastTimestamp) throw new RangeError('Clock cannot run backward');
      this.elapsedMs += timestampMs - this.lastTimestamp;
      this.lastTimestamp = timestampMs;
    }
    return this.elapsedMs;
  }
  pause(timestampMs) { this.advance(timestampMs); this.running = false; this.lastTimestamp = null; }
  resume(timestampMs) { this.start(timestampMs); }
  reset() { this.elapsedMs = 0; this.running = false; this.lastTimestamp = null; }
}
