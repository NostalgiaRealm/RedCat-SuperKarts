import {getSoundSpec} from './asset-animation.js';
import {NativeVoiceController,nativeVoiceVelocity} from './native-voice-controller.js';
import {NATIVE_CRASH_SOUNDS} from './native-crash-audio.js';
import {nativeAudioLoadSettings,nativeStaticSoundVolume,nativeEffectsAffectsSound,nativeAudioControllerChange} from './audio-mixing.js';
import {getNativeSkidAudioCommands} from './skid-audio.js';
import {getNativeScenerySounds, getNativeReactiveSounds, getNativeSpatialAudioCommands, nativePanGains,nativeObjectCallbackCount} from './spatial-audio.js';
import {getNativeEngineAudioSpec, createNativeEngineAudio, startNativeEngineAudio,
  stopNativeEngineAudio, updateNativeEngineAudio, nativeSoundVolume,
  nativeSoundFrequency, nativeWavSampleRate} from './engine-audio.js';
import {NATIVE_PRECISION} from './simulation/native-precision.js';

/** Direct43b600/434f20 calls; DISAPP/REAPP instead use character voice banks. */
export const NATIVE_DIRECT_RACE_SOUNDS = Object.freeze([
  'STARTSE1', 'STARTSE2', 'STARTSE3', 'STARTSE4',
  'CHECKPOINT', 'TIME_TICK', 'KT4', ...NATIVE_CRASH_SOUNDS,
]);

// Bank entries that no recovered request site can select; loading them would only
// hold memory on phones. The banks themselves stay complete.
const UNREQUESTED_VOICE_SAMPLES=/^(SHOUT\d|DRAGON$|GOT_ITEM$|SOAP_UP$|SOAP_PLOPS\d|COMM([7-9]|1\d|20)$)/;
/** WebAudio transport for recovered native sound commands. Timing/gear rules
 * stay in engine-audio.js; this class only owns decoded original WAV voices. */
export class NativeRaceAudio {
  constructor(config, manifest, {context = null, assetBase = 'assets/', groupVolume, precision = NATIVE_PRECISION, decoded = new Map()} = {}) {
    this.config = config;
    this.manifest = manifest;
    this.context = context;
    this.ownsContext = !context;
    // Decoded PCM kept by the viewer: the next race reuses what it shares with this one.
    this.decoded = decoded;
    this.assetBase = assetBase;
    this.audioSettings = nativeAudioLoadSettings(config,{effectsPercent:groupVolume});
    this.effectsPercent = this.audioSettings.effectsPercent;
    //49e0a0 initializes the actual engine master to100. The UI effects
    //percentage is a source-volume replacement, not a second master gain.
    this.masterPercent = 100;
    this.controllerEnabled = this.audioSettings.controllerEnabled;
    this.staticEffectsApplied = this.controllerEnabled;
    this.skidEnabled = this.audioSettings.skidEnabled;
    this.engine = createNativeEngineAudio(getNativeEngineAudioSpec(config, manifest), {precision});
    this.slots = new Map();
    this.pending = new Map();
    this.scenery = [];
    this.reactiveScenery = new Map();
    this.disposed = false;
  }

  ensureContext() {
    if (this.disposed) throw new Error('Native race audio has been disposed');
    if (!this.context) this.context = new AudioContext();
    return this.context;
  }

  async unlock() {
    const context = this.ensureContext();
    if (context.state === 'suspended') await context.resume();
  }

  async loadEvent(event) {
    const key = String(event).toLowerCase();
    if (this.slots.has(key)) return this.slots.get(key);
    if (this.pending.has(key)) return this.pending.get(key);
    const pending = (async () => {
      const spec = getSoundSpec(this.config, this.manifest, event);
      if (!spec?.file) throw new Error(`Missing original sound event: ${event}`);
      const context = this.ensureContext();
      const url = `${this.assetBase}${spec.file}`;
      let sound = this.decoded.get(url);
      if (sound?.buffer.sampleRate !== context.sampleRate) {
        const response = await fetch(url);
        if (!response.ok) throw new Error(`Unable to load original sound: ${spec.file}`);
        const bytes = await response.arrayBuffer();
        sound = {sampleRate: nativeWavSampleRate(bytes), buffer: await context.decodeAudioData(bytes)};
        this.decoded.set(url, sound);
      }
      const {buffer, sampleRate} = sound;
      if (this.disposed) return null;
      const gainNode = context.createGain();
      gainNode.connect(context.destination);
      const volume = nativeStaticSoundVolume(this.config,spec,{
        effectsPercent:this.effectsPercent,effectsEnabled:this.staticEffectsApplied});
      const slot = {spec, buffer, sampleRate, gainNode, source: null,
        baseVolume:volume,volumePercent:volume,pitchPercent:0,loop:false};
      this.slots.set(key, slot);
      this.updateVolume(slot);
      return slot;
    })();
    this.pending.set(key, pending);
    try { return await pending; }
    finally { this.pending.delete(key); }
  }

  async prepareEngine() {
    const spec = this.engine.spec;
    await Promise.all([spec.start, spec.switchGear, ...spec.layers.map(layer => layer.sound), {event: 'SLIP'}]
      .map(sound => this.loadEvent(sound.event)));
  }

  async prepareRaceEvents() {
    await Promise.all(NATIVE_DIRECT_RACE_SOUNDS.map(event => this.loadEvent(event)));
  }

  async prepareVoices(racerCharacters, {allSamples = false} = {}) {
    this.voices=new NativeVoiceController(this.config,this.manifest,racerCharacters,{
      precision:this.engine.precision,enabled:this.controllerEnabled});
    const events=[...new Set(this.voices.banks.flatMap(bank=>bank
      .filter(entry=>allSamples||!UNREQUESTED_VOICE_SAMPLES.test(entry.sample)).map(entry=>entry.event)))];
    await Promise.all(events.map(event=>this.loadEvent(event)));
    // Voice events use the same native pan path as positional scenery.
    for(const event of events)this.ensurePan(this.slots.get(event.toLowerCase()));
  }

  ensurePan(slot) {
    if(slot.panNodes)return;
    const context=this.context,splitter=context.createChannelSplitter(2),merger=context.createChannelMerger(2);
    const channels=[context.createGain(),context.createGain()];
    slot.gainNode.disconnect();slot.gainNode.channelCount=2;slot.gainNode.channelCountMode='explicit';
    slot.gainNode.connect(splitter);
    channels.forEach((channel,index)=>{splitter.connect(channel,index);channel.connect(merger,0,index);});
    merger.connect(context.destination);
    slot.panNodes=channels;slot.routingNodes=[splitter,merger,...channels];
  }

  requestVoice(request) {
    if(!this.voices)throw new Error('Original voice banks were not prepared');
    const result=this.voices.request(request);this.execute(result.commands);return result.accepted;
  }

  updateVoices({listener,bodies}) {
    if(!this.voices)throw new Error('Original voice banks were not prepared');
    return this.voices.service({listener,bodies,isPlaying:event=>this.isPlaying(event),
      baseVolume:event=>this.slots.get(event.toLowerCase()).baseVolume,
      execute:commands=>this.execute(commands)});
  }

  /** Native49dec0 gives each placement an independent voice over shared PCM. */
  async prepareScenery(track) {
    this.scenery = getNativeScenerySounds(this.config, this.manifest, track);
    this.reactiveScenery = new Map(getNativeReactiveSounds(this.config, this.manifest, track)
      .map(entry => [entry.placementIndex, entry]));
    await Promise.all([...this.scenery, ...this.reactiveScenery.values()].map(async entry => {
      const original = await this.loadEvent(entry.sound.event);
      if (!original || this.disposed) return;
      const context = this.context, gainNode = context.createGain();
      // Explicit stereo upmix is required before splitting original mono WAVs.
      gainNode.channelCount = 2;
      gainNode.channelCountMode = 'explicit';
      const splitter = context.createChannelSplitter(2), merger = context.createChannelMerger(2);
      const channels = [context.createGain(), context.createGain()];
      gainNode.connect(splitter);
      channels.forEach((channel, index) => {
        splitter.connect(channel, index);
        channel.connect(merger, 0, index);
      });
      merger.connect(context.destination);
      const slot = {...original, gainNode, source: null, baseVolume:entry.baseVolume,volumePercent: entry.baseVolume,
        pitchPercent: 0, loop: false, panNodes: channels, routingNodes: [splitter, merger, ...channels]};
      this.slots.set(entry.voiceId, slot);
      this.updateVolume(slot);
    }));
    if (this.disposed) return;
    // Memory stays bounded by one race: forget what this race does not use.
    const used = new Set([...this.slots.values()].map(slot => `${this.assetBase}${slot.spec.file}`));
    for (const url of this.decoded.keys()) if (!used.has(url)) this.decoded.delete(url);
  }

  /**43fe80→43b790: one positional update after the reactive prop is launched.
   * Moving props retain their independent one-shot sources until they finish. */
  playSceneryImpact(placementIndex, listener, object) {
    if (this.disposed || !this.controllerEnabled) return [];
    const entry = this.reactiveScenery.get(placementIndex);
    if (!entry) throw new Error(`Original impact source was not prepared: ${placementIndex}`);
    const slot = this.slots.get(entry.voiceId);
    const commands = getNativeSpatialAudioCommands({...entry,
      baseVolume:slot.baseVolume,
      position: object.position,
      velocity: object.velocity ?? nativeVoiceVelocity(object, this.engine.precision),
      listenerPosition: listener.position, listenerForward: listener.forward,
      listenerVelocity: listener.velocity, playing: !!slot.source, loop: false,
      precision: this.engine.precision,
    }).map(command => ({...command, event: entry.sound.event, voiceId: entry.voiceId, spatial: true}));
    this.execute(commands);
    return commands;
  }

  /** Call at the object callback stage, using the PREVIOUS listener snapshot.
   * 491530 skips hidden callbacks; it does not stop an already playing voice. */
  updateScenery(listener, objects = new Map(), {controllerEnabled = this.controllerEnabled} = {}) {
    if (this.disposed || !controllerEnabled) return [];
    const result = [];
    for (const entry of this.scenery) {
      const object = objects.get(entry.placementIndex);
      if((object?.stopRevision??0)!==(entry.stopRevision??0)){
        entry.stopRevision=object.stopRevision;
        this.execute([{event:entry.sound.event,voiceId:entry.voiceId,op:'stop'}]);
      }
      if (!nativeObjectCallbackCount({...entry,visible:object?.visible ?? true})) continue;
      const slot = this.slots.get(entry.voiceId);
      if (!slot) throw new Error(`Scenery voice was not prepared: ${entry.voiceId}`);
      const commands = getNativeSpatialAudioCommands({...entry, position: object?.position ?? entry.position,
        baseVolume:slot.baseVolume,
        //43b790 reads physical localX/Z speeds; a path alone leaves them zero.
        velocity: object?.velocity??nativeVoiceVelocity({yaw:object?.yaw??0,
          lateralSpeed:object?.lateralSpeed??0,forwardSpeed:object?.forwardSpeed??0},this.engine.precision),
        listenerPosition: listener.position, listenerForward: listener.forward,
        listenerVelocity: listener.velocity, playing: !!slot.source, loop: true, precision: this.engine.precision})
        .map(command => ({...command, event: entry.sound.event, voiceId: entry.voiceId,spatial:true}));
      this.execute(commands);
      result.push(...commands);
    }
    return result;
  }

  updateVolume(slot) {
    slot.gainNode.gain.value = nativeSoundVolume(slot.volumePercent, this.masterPercent).gain;
  }

  // Compatibility name used by the options UI; this is the effective FX
  //source percentage, while masterPercent remains the separate native100.
  get groupVolume() { return this.effectsPercent; }

  setGroupVolume(percent) {
    if (!Number.isFinite(percent) || percent < 0 || percent > 100) throw new RangeError('Native sound group volume must be 0–100');
    const change=nativeAudioControllerChange(this.controllerEnabled,percent);
    this.effectsPercent = change.volumePercent;
    this.staticEffectsApplied = true;
    this.controllerEnabled = change.enabled;
    if (this.voices) {
      if (change.clearQueues) this.execute(this.voices.clear());
      this.voices.enabled = this.controllerEnabled;
    }
    for (const slot of this.slots.values()) if(nativeEffectsAffectsSound(slot.spec)){
      slot.baseVolume=slot.volumePercent=change.volumePercent;
      this.updateVolume(slot);
    }
  }

  isPlaying(event) { return !!this.slots.get(String(event).toLowerCase())?.source; }

  execute(commands) {
    if (this.disposed) return;
    for (const command of commands) {
      const slot = this.slots.get(command.voiceId ?? command.event.toLowerCase());
      if (!slot) throw new Error(`Native sound was not prepared: ${command.event}`);
      if (command.op === 'volume') {
        slot.volumePercent = command.percent;
        if(!command.spatial)slot.baseVolume=command.percent;
        this.updateVolume(slot);
      } else if (command.op === 'pitch') {
        slot.pitchPercent = command.percent;
        if (slot.source) slot.source.playbackRate.value = nativeSoundFrequency(slot.sampleRate, command.percent).playbackRate;
      } else if (command.op === 'pan') {
        if (!slot.panNodes) throw new Error('Positional voice has no native pan routing');
        const gains = nativePanGains(command.hundredthDb);
        slot.panNodes.forEach((node, index) => { node.gain.value = gains[index]; });
        slot.pan = command.hundredthDb;
      } else if (command.op === 'stop') {
        if (slot.source) {
          slot.source.stop();
          slot.source.disconnect();
          slot.source = null;
        }
      } else if (command.op === 'play') {
        // Native 0x49d780 ignores a repeated request while this sound type's
        // current buffer is playing, including one-shot gear change effects.
        if (slot.source) continue;
        const source = this.context.createBufferSource();
        source.buffer = slot.buffer;
        source.loop = slot.loop = !!command.loop;
        source.playbackRate.value = nativeSoundFrequency(slot.sampleRate, slot.pitchPercent).playbackRate;
        source.connect(slot.gainNode);
        slot.source = source;
        source.onended = () => {
          if (slot.source === source) slot.source = null;
          source.disconnect();
        };
        source.start();
      } else throw new Error(`Unknown native sound operation: ${command.op}`);
    }
  }

  async startEngine() {
    await this.prepareEngine();
    if (!this.disposed) this.execute(startNativeEngineAudio(this.engine));
  }

  updateEngine({gear, rpm}) {
    if (this.disposed || !this.engine.active) return [];
    const commands = updateNativeEngineAudio(this.engine, {gear, rpm,
      startPlaying: this.isPlaying(this.engine.spec.start.event)});
    this.execute(commands);
    return commands;
  }

  stopEngine() { if (!this.disposed) this.execute(stopNativeEngineAudio(this.engine)); }

  updateSkid(input) {
    if (this.disposed) return [];
    const commands = getNativeSkidAudioCommands({...input, playing: this.isPlaying('SLIP')});
    this.execute(commands);
    return commands;
  }

  async playEvent(event, {loop = false, volumePercent, pitchPercent} = {}) {
    const slot = await this.loadEvent(event);
    if (!slot || this.disposed) return;
    const commands = [];
    if (volumePercent !== undefined) commands.push({event, op: 'volume', percent: volumePercent});
    if (pitchPercent !== undefined) commands.push({event, op: 'pitch', percent: pitchPercent});
    commands.push({event, op: 'play', loop});
    this.execute(commands);
  }

  pause() { return this.context?.state === 'running' ? this.context.suspend() : Promise.resolve(); }
  resume() { return this.context?.state === 'suspended' ? this.context.resume() : Promise.resolve(); }

  async dispose() {
    if (this.disposed) return;
    this.disposed = true;
    this.engine.active = false;
    for (const slot of this.slots.values()) {
      if (slot.source) { slot.source.stop(); slot.source.disconnect(); slot.source = null; }
      slot.gainNode.disconnect();
      for (const node of slot.routingNodes ?? []) node.disconnect();
    }
    this.slots.clear();
    if (this.ownsContext && this.context?.state !== 'closed') await this.context?.close();
  }
}
