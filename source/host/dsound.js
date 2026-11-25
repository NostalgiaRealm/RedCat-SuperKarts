// DirectSound for rcskspel.dat, after the RedCat Spookkasteel host (source/host/dsound.js there): play state and
// positions run on the race's clock (host.clock), so GetStatus ends a sound when its samples are over whether or
// not anything is heard, in the browser and in Node alike.
//
// What the game does with it (static reading, docs/host.md): its sound library (dxdraw Sound.cpp, 0x4b3910..
// 0x4b5400) opens the default device, sets the primary buffer to PCM and plays it looping, and keeps 60 slots of
// secondary buffers (flags 0xE8: volume, pan and frequency control, in software). A WAV is loaded with
// Lock(0, size, FROMWRITECURSOR) on a new, stopped buffer (0x4b4ab0), so the write cursor is the start; a sound that
// is playing when it is asked for again is duplicated (0x4b3ef0); eviction stops and releases the oldest slot,
// which may be an original whose duplicates still play (0x4b4310). GetStatus (only bit 0) decides which slots are
// free. The 3D buffer code is never reached (slot +0x34 is never written): the game pans and attenuates itself.
// Every failure is fatal to it (0x4afee0), so nothing here refuses: values out of range are clamped.
//
//   host.audio (optional), the sink: { data(id, bytes, fmt), alias(id, ofId), play(id, loop, offsetBytes), stop(id),
//     volume(id, hundredthsDb), pan(id, hundredthsDb), frequency(id, hz), free(id) }

const S_OK = 0;

function slots(count, entries) {
  const out = new Array(count).fill(null);
  for (const [k, name, n, fn] of entries) out[k] = [name, n, fn];
  return out;
}

export function installDsound(m, host) {
  const { u8, u16, u32, i32 } = m;
  const heap = host.heap;
  const sink = () => host.audio;
  const BUF = 'IDirectSoundBuffer';
  // the sound's clock: in the browser host.soundUs() (source/web/worker.js), the game's clock less the time the page held
  // the sound, so a one-shot effect that a focus pause held on the page ends in the game where it ends there (dshow.js)
  const nowMs = () => (host.soundUs ? host.soundUs() : host.clock.us) / 1000;
  let nextId = 1;
  const ds = host.dsound = { buffers: new Set(), plays: 0 };

  const bytesPerSec = (b) => Math.max(1, b.frequency * b.blockAlign);
  /** Play position in bytes; a one-shot sound past its end has stopped. */
  const position = (b) => {
    if (!b.playing) return b.pos;
    if (b.held !== undefined) return b.held;
    const adv = Math.floor((nowMs() - b.startMs) * bytesPerSec(b) / 1000);
    const p = b.startPos + adv - (adv % b.blockAlign);
    if (b.loop) return b.size ? p % b.size : 0;
    if (p >= b.size) { b.playing = false; b.pos = 0; return 0; }
    return p;
  };
  /** A change of rate while playing: the position so far is kept, the rest goes at the new rate. */
  const rebase = (b) => { if (b.playing) { b.startPos = position(b); b.startMs = nowMs(); } };
  const tell = (b) => { if (sink() && !b.primary) { sink().volume(b.id, b.volume); sink().pan(b.id, b.pan); sink().frequency(b.id, b.frequency); } };
  const clamp = (v, lo, hi) => Math.max(lo, Math.min(hi, v));
  ds.position = position;
  // Free flight (source/host/free-flight.js) holds the sound effects, as the JS reconstruction pauses its effects
  // context while it flies (driving-view.js:336-345, :413): every playing buffer stops where it is (held) and goes on
  // from there when the hold ends; one the game starts meanwhile waits at its start. The game still sees them playing at
  // that position (GetStatus, GetCurrentPosition), so it frees no slot. The music (dshow.js) goes on.
  ds.holding = false;
  ds.hold = (on) => {
    if (on === ds.holding) return;
    ds.holding = on;
    for (const b of ds.buffers) {
      if (b.primary) continue;
      if (on) {
        const p = position(b);
        if (b.playing) { b.held = p; if (sink()) sink().stop(b.id); }
      } else if (b.held !== undefined) {
        const p = b.held;
        b.held = undefined;
        if (b.playing) { b.startPos = p; b.startMs = nowMs(); if (sink()) sink().play(b.id, b.loop, p); }
      }
    }
  };

  m.defineInterface(BUF, slots(21, [
    [0, 'QueryInterface', 2, (self, riid, pOut) => { u32[pOut >> 2] = 0; return 0x80004002 | 0; }],
    [1, 'AddRef', 0, (self) => ++self.refs],
    [2, 'Release', 0, (self) => {
      if (--self.refs > 0) return self.refs;
      if (sink() && !self.primary) sink().free(self.id);
      // the samples are shared with duplicates: freed with the last of them
      if (self.pcm && --self.pcm.refs === 0 && self.pcm.ptr) heap.release(self.pcm.ptr);
      ds.buffers.delete(self);
      m.objects.delete(self.addr);
      return 0;
    }],
    [3, 'GetCaps', 1, (self, p) => { u32[(p + 4) >> 2] = self.flags; u32[(p + 8) >> 2] = self.size; u32[(p + 12) >> 2] = 0; u32[(p + 16) >> 2] = 0; return S_OK; }],
    [4, 'GetCurrentPosition', 2, (self, pPlay, pWrite) => {
      const p = position(self);
      if (pPlay) u32[pPlay >> 2] = p;
      if (pWrite) u32[pWrite >> 2] = self.playing && self.size ? (p + self.blockAlign * 512) % self.size : p;
      return S_OK;
    }],
    [5, 'GetFormat', 3, (self, p, n, pWritten) => {
      if (p && n >= 16) {
        u16[p >> 1] = 1; u16[(p + 2) >> 1] = self.channels; u32[(p + 4) >> 2] = self.baseFrequency;
        u32[(p + 8) >> 2] = self.baseFrequency * self.blockAlign; u16[(p + 12) >> 1] = self.blockAlign; u16[(p + 14) >> 1] = self.bits;
        if (n >= 18) u16[(p + 16) >> 1] = 0;
      }
      if (pWritten) u32[pWritten >> 2] = 18;
      return S_OK;
    }],
    [6, 'GetVolume', 1, (self, p) => { i32[p >> 2] = self.volume; return S_OK; }],
    [7, 'GetPan', 1, (self, p) => { i32[p >> 2] = self.pan; return S_OK; }],
    [8, 'GetFrequency', 1, (self, p) => { u32[p >> 2] = self.frequency; return S_OK; }],
    [9, 'GetStatus', 1, (self, p) => { position(self); u32[p >> 2] = self.playing ? (self.loop ? 5 : 1) : 0; return S_OK; }],
    [10, 'Initialize', 2, () => S_OK],
    [11, 'Lock', 7, (self, off, size, p1, n1, p2, n2, flags) => {
      if (self.primary || !self.ptr) { u32[p1 >> 2] = 0; u32[n1 >> 2] = 0; if (p2) u32[p2 >> 2] = 0; if (n2) u32[n2 >> 2] = 0; return S_OK; }
      if (flags & 2) { off = 0; size = self.size; }                                    // DSBLOCK_ENTIREBUFFER
      // DSBLOCK_FROMWRITECURSOR: a stopped buffer's write cursor is its play position (0 for a new one)
      else if (flags & 1) off = self.playing && self.size ? (position(self) + self.blockAlign * 512) % self.size : self.pos;
      size = Math.min(size, self.size);
      off = self.size ? off % self.size : 0;
      const first = Math.min(size, self.size - off);
      u32[p1 >> 2] = self.ptr + off; u32[n1 >> 2] = first;
      if (p2) u32[p2 >> 2] = size > first ? self.ptr : 0;
      if (n2) u32[n2 >> 2] = size - first;
      return S_OK;
    }],
    [12, 'Play', 3, (self, r1, pri, flags) => {
      if (self.primary) return S_OK;
      self.startPos = position(self);
      self.loop = (flags & 1) !== 0;
      self.playing = true;
      self.startMs = nowMs();
      ds.plays++;
      if (ds.holding) { self.held = self.startPos; return S_OK; }
      if (sink()) sink().play(self.id, self.loop, self.startPos);
      return S_OK;
    }],
    [13, 'SetCurrentPosition', 1, (self, pos) => {
      self.pos = clamp(pos - (pos % self.blockAlign), 0, Math.max(0, self.size - self.blockAlign));
      if (self.playing && self.held !== undefined) self.held = self.pos;
      else if (self.playing) { self.startPos = self.pos; self.startMs = nowMs(); if (sink()) sink().play(self.id, self.loop, self.startPos); }
      return S_OK;
    }],
    [14, 'SetFormat', 1, () => S_OK],
    [15, 'SetVolume', 1, (self, v) => {
      if (self.primary) return S_OK;
      self.volume = clamp(v | 0, -10000, 0);
      if (sink()) sink().volume(self.id, self.volume);
      return S_OK;
    }],
    [16, 'SetPan', 1, (self, v) => {
      if (self.primary) return S_OK;
      self.pan = clamp(v | 0, -10000, 10000);
      if (sink()) sink().pan(self.id, self.pan);
      return S_OK;
    }],
    [17, 'SetFrequency', 1, (self, v) => {
      if (self.primary) return S_OK;
      v >>>= 0;
      rebase(self);
      self.frequency = v === 0 ? self.baseFrequency : clamp(v, 100, 100000);       // 0: the buffer's own rate
      if (sink()) sink().frequency(self.id, self.frequency);
      return S_OK;
    }],
    [18, 'Stop', 0, (self) => {
      if (self.primary) return S_OK;
      self.pos = position(self);
      self.playing = false;
      self.held = undefined;
      if (sink()) sink().stop(self.id);
      return S_OK;
    }],
    [19, 'Unlock', 4, (self) => {
      if (sink() && !self.primary && self.ptr) { sink().data(self.id, u8.slice(self.ptr, self.ptr + self.size), { channels: self.channels, rate: self.baseFrequency, bits: self.bits }); self.told = true; }
      return S_OK;
    }],
    [20, 'Restore', 0, () => S_OK],
  ]));

  const newBuffer = (b) => {
    b.id = nextId++;
    b.volume = b.volume || 0; b.pan = b.pan || 0; b.pos = 0; b.playing = false; b.loop = false;
    m.newObject(BUF, b);
    ds.buffers.add(b);
    return b;
  };
  m.defineInterface('IDirectSound', slots(11, [
    [0, 'QueryInterface', 2, (self, riid, pOut) => { u32[pOut >> 2] = 0; return 0x80004002 | 0; }],
    [1, 'AddRef', 0, (self) => ++self.refs],
    [2, 'Release', 0, (self) => Math.max(--self.refs, 0)],
    [3, 'CreateSoundBuffer', 3, (self, pDesc, pOut) => {
      const flags = u32[(pDesc + 4) >> 2];
      const b = { flags, primary: (flags & 1) !== 0, ptr: 0, size: 0, channels: 2, bits: 16, blockAlign: 4, baseFrequency: 22050, frequency: 22050, pcm: null };
      const fmt = u32[(pDesc + 16) >> 2];
      if (fmt) {
        b.channels = u16[(fmt + 2) >> 1]; b.baseFrequency = u32[(fmt + 4) >> 2]; b.frequency = b.baseFrequency;
        b.blockAlign = u16[(fmt + 12) >> 1] || 1; b.bits = u16[(fmt + 14) >> 1];
      }
      if (!b.primary) {
        b.size = u32[(pDesc + 8) >> 2];
        b.ptr = heap.alloc(Math.max(4, b.size), true);
        b.pcm = { ptr: b.ptr, refs: 1 };
      }
      newBuffer(b);
      u32[pOut >> 2] = b.addr;
      return S_OK;
    }],
    [4, 'GetCaps', 1, (self, p) => {
      const size = u32[p >> 2];
      u8.fill(0, p + 4, p + size);
      u32[(p + 4) >> 2] = 0x0F1F;      // primary and secondary, mono/stereo, 8/16 bit, continuous rate
      u32[(p + 8) >> 2] = 100; u32[(p + 12) >> 2] = 100000; u32[(p + 16) >> 2] = 1;
      return S_OK;
    }],
    [5, 'DuplicateSoundBuffer', 2, (self, src, pOut) => {
      const s = m.objects.get(src);
      const b = newBuffer({ flags: s.flags, primary: false, ptr: s.ptr, size: s.size, channels: s.channels, bits: s.bits, blockAlign: s.blockAlign, baseFrequency: s.baseFrequency, frequency: s.frequency, volume: s.volume, pan: s.pan, pcm: s.pcm });
      if (b.pcm) b.pcm.refs++;
      // a duplicate plays its original's memory: the sink shares the samples it has of it
      if (sink() && b.ptr) {
        if (s.told && sink().alias) sink().alias(b.id, s.id);
        else sink().data(b.id, u8.slice(b.ptr, b.ptr + b.size), { channels: b.channels, rate: b.baseFrequency, bits: b.bits });
        b.told = true;
      }
      tell(b);
      u32[pOut >> 2] = b.addr;
      return S_OK;
    }],
    [6, 'SetCooperativeLevel', 2, () => S_OK],
    [7, 'Compact', 0, () => S_OK],
    [8, 'GetSpeakerConfig', 1, (self, p) => { u32[p >> 2] = 4; return S_OK; }],
    [9, 'SetSpeakerConfig', 1, () => S_OK],
    [10, 'Initialize', 1, () => S_OK],
  ]));
  ds.root = {};
  m.newObject('IDirectSound', ds.root);
  // The enumeration callback (0x4b3aa0) only looks for SB16.VXD; the default device is opened either way.
  m.api('DSOUND.DLL!DirectSoundEnumerateA', 2, () => S_OK);
  m.api('DSOUND.DLL!DirectSoundCreate', 3, (guid, pOut) => {
    ds.root.refs++;
    u32[pOut >> 2] = ds.root.addr;
    return S_OK;
  });
}
