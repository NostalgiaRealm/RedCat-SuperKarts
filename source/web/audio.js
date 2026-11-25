// Web Audio on the page for the game worker's sound (source/host/dsound.js, dshow.js), after the RedCat Spookkasteel
// port's sink (source/web/audio.js there). The worker sends batches of plain messages:
//   effects: { t: 'data', id, bytes, fmt: { channels, rate, bits } }, { t: 'alias', id, of } (a DirectSound duplicate
//     plays its original's samples), { t: 'play', id, loop, offset }, { t: 'stop', id }, { t: 'volume', id, v },
//     { t: 'pan', id, v }, { t: 'frequency', id, hz }, { t: 'free', id }
//   music (the DirectShow graph of rclemu%02d.dat, an MP3): { t: 'music-open', name, bytes }, { t: 'music-run', offset }
//     (seconds), { t: 'music-pause' }, { t: 'music-stop' }, { t: 'music-volume', v }
// Volumes and pans are DirectSound values: hundredths of a decibel of attenuation (IBasicAudio's volume too).
// When a sound starts, when it ends and where the music is are decided in the worker, on the race's clock.
// One sink serves every race of the page (source/race-runner.js): reset() at the end of a race stops every sound
// and the music and lets go of every buffer and node; the AudioContext stays.
export function createAudioSink() {
  const AC = window.AudioContext || window.webkitAudioContext;
  let ctx = null, master = null, analyser = null, musicTap = null, effectsTap = null;
  const bufs = new Map();      // id -> { pcm: { bytes, fmt, buffer } (shared by duplicates), fmt, gain, panL, panR, src, volume, pan, hz }
  const dbGain = (hundredths) => (hundredths <= -10000 ? 0 : Math.pow(10, hundredths / 2000));
  const ensure = () => {
    if (!ctx) {
      ctx = new AC();
      master = ctx.createGain();
      analyser = ctx.createAnalyser();
      analyser.fftSize = 2048;
      master.connect(analyser);
      analyser.connect(ctx.destination);
      // for checks: the music and the effects apart (they pass through unchanged), tools/check-audio.mjs
      musicTap = ctx.createAnalyser();
      effectsTap = ctx.createAnalyser();
      musicTap.fftSize = effectsTap.fftSize = 2048;
      musicTap.connect(master);
      effectsTap.connect(master);
    }
    return ctx;
  };
  /** The samples as a buffer Web Audio can play, made at the first play; the bytes are let go then. */
  const decoded = (pcm) => {
    if (pcm.buffer || !pcm.bytes) return pcm.buffer;
    const { channels, rate, bits } = pcm.fmt, bytes = pcm.bytes;
    pcm.bytes = null;
    const frames = Math.floor(bytes.length / (channels * (bits >> 3)));
    if (!frames) return null;
    const buf = ensure().createBuffer(channels, frames, Math.max(3000, Math.min(rate, 192000)));
    const dv = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
    for (let c = 0; c < channels; c++) {
      const out = buf.getChannelData(c);
      if (bits === 16) for (let k = 0; k < frames; k++) out[k] = dv.getInt16((k * channels + c) * 2, true) / 32768;
      else for (let k = 0; k < frames; k++) out[k] = (bytes[k * channels + c] - 128) / 128;
    }
    decodedCount++;
    return (pcm.buffer = buf);
  };
  const get = (id) => { let b = bufs.get(id); if (!b) { b = { volume: 0, pan: 0, hz: 0 }; bufs.set(id, b); } return b; };
  // DirectSound's pan attenuates one channel: positive pans to the right by turning the left down
  const applyPan = (b) => {
    if (!b.panL) return;
    b.panL.gain.value = b.pan > 0 ? dbGain(-b.pan) : 1;
    b.panR.gain.value = b.pan < 0 ? dbGain(b.pan) : 1;
  };
  const stop = (b) => { if (b.src) { try { b.src.stop(); } catch (e) { /* already stopped */ } b.src.disconnect(); b.src = null; } };
  let decodedCount = 0;      // PCM buffers made (for checks: freed again by reset)

  // the music: one track at a time, decoded when it arrives; a run asked for before that starts when it is ready
  // (at, from: the context time it started and the track's place then, for checks: state().music.position)
  const tune = { buffer: null, decoding: null, src: null, gain: null, volume: 0, want: null, name: '', at: 0, from: 0 };
  const tuneStop = () => { if (tune.src) { try { tune.src.stop(); } catch (e) { /* stopped */ } tune.src.disconnect(); tune.src = null; } };
  const tuneStart = (offset) => {
    tuneStop();
    if (!tune.buffer) return;
    if (!tune.gain) { tune.gain = ctx.createGain(); tune.gain.connect(musicTap); }
    tune.gain.gain.value = dbGain(tune.volume);
    const src = ctx.createBufferSource();
    src.buffer = tune.buffer;
    src.connect(tune.gain);
    tune.from = Math.max(0, Math.min(offset, tune.buffer.duration));
    src.start(0, tune.from);
    tune.at = ctx.currentTime;
    tune.src = src;
  };

  const handlers = {
    data: (msg) => { const b = get(msg.id); b.fmt = msg.fmt; b.pcm = { bytes: msg.bytes, fmt: msg.fmt, buffer: null }; },
    alias: (msg) => { const of = bufs.get(msg.of); if (!of || !of.pcm) return; const b = get(msg.id); b.fmt = of.fmt; b.pcm = of.pcm; },
    play: (msg) => {
      const b = get(msg.id);
      if (!b.pcm) return;
      ensure();
      const buffer = decoded(b.pcm);
      if (!buffer) return;
      stop(b);
      if (!b.gain) {
        b.gain = ctx.createGain();
        const split = ctx.createChannelSplitter(2), merge = ctx.createChannelMerger(2);
        b.panL = ctx.createGain(); b.panR = ctx.createGain();
        b.gain.connect(split);
        split.connect(b.panL, 0); split.connect(b.panR, b.fmt.channels > 1 ? 1 : 0);
        b.panL.connect(merge, 0, 0); b.panR.connect(merge, 0, 1);
        merge.connect(effectsTap);
      }
      applyPan(b);
      b.gain.gain.value = dbGain(b.volume);
      const src = ctx.createBufferSource();
      src.buffer = buffer;
      src.loop = !!msg.loop;
      src.playbackRate.value = b.hz ? b.hz / b.fmt.rate : 1;
      src.connect(b.gain);
      const frame = b.fmt.channels * (b.fmt.bits >> 3);
      src.start(0, ((msg.offset || 0) / frame) / b.fmt.rate);
      src.onended = () => { if (b.src === src) b.src = null; };
      b.src = src;
    },
    stop: (msg) => stop(get(msg.id)),
    volume: (msg) => { const b = get(msg.id); b.volume = msg.v; if (b.gain) b.gain.gain.value = dbGain(b.volume); },
    pan: (msg) => { const b = get(msg.id); b.pan = msg.v; applyPan(b); },
    frequency: (msg) => { const b = get(msg.id); b.hz = msg.hz; if (b.src && b.fmt) b.src.playbackRate.value = msg.hz / b.fmt.rate; },
    free: (msg) => { const b = bufs.get(msg.id); if (b) { stop(b); bufs.delete(msg.id); } },
    'music-open': (msg) => {
      ensure();
      tuneStop();
      tune.buffer = null;
      tune.name = msg.name;
      const job = tune.decoding = ctx.decodeAudioData(msg.bytes.buffer).then((buf) => {
        if (tune.decoding !== job) return;
        tune.buffer = buf;
        tune.decoding = null;
        if (tune.want) tuneStart(tune.want.offset + (ctx.currentTime - tune.want.at));
      }).catch((e) => console.warn('music', msg.name, e));
    },
    'music-run': (msg) => { ensure(); if (tune.buffer) tuneStart(msg.offset); else tune.want = { offset: msg.offset, at: ctx.currentTime }; },
    'music-pause': () => { tune.want = null; tuneStop(); },
    'music-stop': () => { tune.want = null; tuneStop(); },
    'music-volume': (msg) => { tune.volume = msg.v; if (tune.gain) tune.gain.gain.value = dbGain(msg.v); },
  };
  const level = new Float32Array(2048);
  /** The end of a race: every sound and the music stopped, every buffer and node let go. */
  const reset = () => {
    for (const b of bufs.values()) {
      stop(b);
      for (const n of [b.gain, b.panL, b.panR]) if (n) n.disconnect();
      b.gain = b.panL = b.panR = null;
      if (b.pcm) { b.pcm.bytes = null; b.pcm.buffer = null; b.pcm = null; }
    }
    bufs.clear();
    decodedCount = 0;
    tuneStop();
    if (tune.gain) { tune.gain.disconnect(); tune.gain = null; }
    tune.buffer = null; tune.decoding = null; tune.want = null; tune.name = ''; tune.volume = 0;
  };
  return {
    handle: (list) => { for (const msg of list) { const h = handlers[msg.t]; if (h) h(msg); } },
    reset,
    resume: () => { ensure(); if (ctx.state === 'suspended') ctx.resume().catch(() => {}); },
    suspend: () => { if (ctx && ctx.state === 'running') ctx.suspend().catch(() => {}); },
    /**
     * For checks: what sounds now, and the loudness (RMS of the last 2048 samples) of the output (rms), of the music
     * alone (musicRms) and of the effects alone, the engine among them (effectsRms).
     */
    state: () => {
      const rmsOf = (node) => {
        if (!node) return 0;
        let sum = 0;
        node.getFloatTimeDomainData(level);
        for (const v of level) sum += v * v;
        return Math.sqrt(sum / level.length);
      };
      return { context: ctx ? ctx.state : 'none', effects: [...bufs.values()].filter((b) => b.src).length, buffers: bufs.size, decoded: [...bufs.values()].filter((b) => b.pcm && b.pcm.buffer).length,
        // the track's place in seconds: its context's time stands still while it is suspended (a focus pause), as the
        // game's sound clock does then (worker.js soundUs, dshow.js)
        decodedTotal: decodedCount, music: { name: tune.name, playing: !!tune.src, loaded: !!tune.buffer, volume: tune.volume, position: tune.src ? +(tune.from + ctx.currentTime - tune.at).toFixed(3) : null },
        rms: rmsOf(analyser), musicRms: rmsOf(musicTap), effectsRms: rmsOf(effectsTap) };
    },
  };
}
