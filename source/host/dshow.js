// OLE32 and the part of DirectShow rcskspel.dat uses: the race music. Neither A2 Racer 4 nor Spookkasteel
// needed this; the calls are read from rcskspel.dat (docs/host.md, DirectShow).
//
// init_game 0x42d7d0 calls CoInitialize, then opens "rclemu%02d.dat" (an MP3 stream, picked by Race.ini
// [ETAPPE] ETAPPE) through 0x48ed60 -> 0x48ed00 -> 0x48ec50: CoCreateInstance(CLSID_FilterGraph,
// IID_IGraphBuilder), QueryInterface(IID_IMediaEvent) + GetEventHandle, IGraphBuilder::RenderFile.
// 0x48f010 sets the volume through IBasicAudio::put_Volume(49 * MX_VOLUME - 5000, 0x431610); when
// MX_VOLUME is not 0, 0x48edc0 runs the graph (IMediaControl::Run) and 0x48ec20(1) sets the loop byte.
// Every frame 0x48ef80 asks IMediaEvent::GetEvent for one event: EC_COMPLETE (1) stops and rewinds it
// (0x48eee0: Pause, IMediaPosition::put_CurrentPosition(0.0), GetState, Stop) and runs it again if the
// loop byte is set. Nothing checks for a null graph and a failed QueryInterface for IBasicAudio is fatal,
// so every call here succeeds.
//
// Playback runs on the race's virtual clock (host.clock), so the end of a track and its restart come at
// the same game time with and without sound. host.music (optional) is the sink:
//   { open(name, bytes), run(offsetSeconds), pause(), stop(), volume(hundredthsDb) }
// In the browser the clock is host.soundUs() (source/web/worker.js): the game's clock less the time the page held the
// sound (a focus pause, whose loop runs the game's clock in real time while the page's AudioContext is suspended), so
// the track's place stays the page's and EC_COMPLETE comes when the page's track ends, as the JS port's paused <audio>
// keeps its place (its game-audio.js:18). Without it (Node) the clock itself. host.musicPosition(): the last graph's
// place in seconds, for checks.

const S_OK = 0;
const S_FALSE = 1;
const E_NOINTERFACE = 0x80004002 | 0;
const E_ABORT = 0x80004004 | 0;
const EC_COMPLETE = 1;
// first dword of each IID (all in the {xxxxxxxx-0AD4-11CE-B03A-0020AF0BA770} family)
const IID = {
  IUnknown: 0x00000000,
  IGraphBuilder: 0x56A868A9,
  IMediaControl: 0x56A868B1,
  IMediaPosition: 0x56A868B2,
  IBasicAudio: 0x56A868B3,
  IMediaEvent: 0x56A868B6,
  IMediaEventEx: 0x56A868C0,
};
const STATE = { stopped: 0, paused: 1, running: 2 };

function slots(count, entries) {
  const out = new Array(count).fill(null);
  for (const [off, name, n, fn] of entries) out[off / 4] = [name, n, fn];
  return out;
}

/**
 * Duration of an MPEG audio stream from its frame headers (MPEG-1/2/2.5, layers I-III), in seconds.
 * The rclemu files are constant-rate layer III, 192 kbps, 44.1 kHz.
 */
export function mp3Duration(b) {
  const RATES = { 3: [44100, 48000, 32000], 2: [22050, 24000, 16000], 0: [11025, 12000, 8000] };
  const BR = {
    '3-3': [0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448],
    '3-2': [0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384],
    '3-1': [0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320],
    '2-3': [0, 32, 48, 56, 64, 80, 96, 112, 128, 144, 160, 176, 192, 224, 256],
    '2-2': [0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160],
  };
  let p = 0;
  if (b.length > 10 && b[0] === 0x49 && b[1] === 0x44 && b[2] === 0x33) {   // ID3v2
    p = 10 + ((b[6] & 0x7F) << 21 | (b[7] & 0x7F) << 14 | (b[8] & 0x7F) << 7 | (b[9] & 0x7F));
  }
  let seconds = 0;
  while (p + 4 <= b.length) {
    if (b[p] !== 0xFF || (b[p + 1] & 0xE0) !== 0xE0) { p++; continue; }
    const ver = (b[p + 1] >> 3) & 3, layer = (b[p + 1] >> 1) & 3;
    const bri = b[p + 2] >> 4, sri = (b[p + 2] >> 2) & 3, pad = (b[p + 2] >> 1) & 1;
    if (ver === 1 || layer === 0 || bri === 0 || bri === 15 || sri === 3) { p++; continue; }
    const rate = RATES[ver][sri];
    const kbps = (ver === 3 ? BR['3-' + layer] : BR[layer === 3 ? '2-3' : '2-2'])[bri];
    const samples = layer === 3 ? 384 : layer === 1 && ver !== 3 ? 576 : 1152;
    const len = layer === 3 ? (Math.floor(12 * kbps * 1000 / rate) + pad) * 4 : Math.floor(samples / 8 * kbps * 1000 / rate) + pad;
    if (len < 4) { p++; continue; }
    seconds += samples / rate;
    p += len;
  }
  return seconds;
}

export function installDshow(m, host) {
  const { u16, u32, i32 } = m;
  const O = 'OLE32.DLL!';
  const sink = () => host.music || null;
  const now = () => (host.soundUs ? host.soundUs() : host.clock.us) / 1e6;

  m.api(O + 'CoInitialize', 1, () => S_OK);
  m.api(O + 'CoUninitialize', 0, () => 0);

  /** One filter graph: its state is shared by the interface objects that QueryInterface hands out. */
  const graphs = [];
  const position = (g) => (g.state === STATE.running ? g.offset + (now() - g.since) : g.offset);
  /** Ends a run that has reached the end of the file: one EC_COMPLETE, the graph stays "running" as in DirectShow. */
  const poll = (g) => {
    if (g.state === STATE.running && !g.completed && g.duration > 0 && position(g) >= g.duration) {
      g.completed = true;
      g.events.push(EC_COMPLETE);
    }
  };
  const view = (g, iface) => {
    let obj = g.views.get(iface);
    if (!obj) {
      obj = { graph: g };
      m.newObject(iface, obj);
      obj.refs = 0;
      g.views.set(iface, obj);
    }
    obj.refs++;
    g.refs++;
    return obj.addr;
  };
  const qi = (self, riid, pOut) => {
    const want = u32[riid >> 2];
    const iface = want === IID.IUnknown || want === IID.IGraphBuilder ? 'IGraphBuilder'
      : want === IID.IMediaEvent || want === IID.IMediaEventEx ? 'IMediaEvent'
        : want === IID.IMediaControl ? 'IMediaControl'
          : want === IID.IMediaPosition ? 'IMediaPosition'
            : want === IID.IBasicAudio ? 'IBasicAudio' : null;
    if (!iface) {
      u32[pOut >> 2] = 0;
      return E_NOINTERFACE;
    }
    u32[pOut >> 2] = view(self.graph, iface);
    return S_OK;
  };
  const addRef = (self) => {
    self.refs++;
    return ++self.graph.refs;
  };
  const release = (self) => {
    self.refs = Math.max(0, self.refs - 1);
    const g = self.graph;
    g.refs = Math.max(0, g.refs - 1);
    if (g.refs === 0 && g.state !== STATE.stopped) {
      g.state = STATE.stopped;
      if (sink()) sink().stop();
    }
    return g.refs;
  };
  const unknown = [[0x00, 'QueryInterface', 2, qi], [0x04, 'AddRef', 0, addRef], [0x08, 'Release', 0, release]];
  const dispatch = [
    [0x0C, 'GetTypeInfoCount', 1, (self, p) => { if (p) u32[p >> 2] = 0; return S_OK; }],
  ];
  const run = (g) => {
    if (g.state !== STATE.running) {
      g.since = now();
      g.state = STATE.running;
      if (sink()) sink().run(g.offset);
    }
    return S_OK;
  };
  const pause = (g) => {
    if (g.state === STATE.running) g.offset = position(g);
    g.state = STATE.paused;
    if (sink()) sink().pause();
    return S_OK;
  };
  const stop = (g) => {
    if (g.state === STATE.running) g.offset = position(g);
    g.state = STATE.stopped;
    if (sink()) sink().stop();
    return S_OK;
  };
  const wstr = (p) => {
    let s = '';
    for (let c = u16[p >> 1]; c; p += 2, c = u16[p >> 1]) s += String.fromCharCode(c);
    return s;
  };

  m.defineInterface('IGraphBuilder', slots(18, [
    ...unknown,
    [0x34, 'RenderFile', 2, (self, pFile) => {
      const g = self.graph;
      const name = wstr(pFile);
      const bytes = host.vfs.read(name);
      g.file = name;
      g.duration = bytes ? mp3Duration(bytes) : 0;
      g.offset = 0;
      g.completed = false;
      if (sink() && bytes) sink().open(name, bytes);
      // a missing file still leaves a graph: the original sets its state to 1 whatever RenderFile returns
      return bytes ? S_OK : 0x80070002 | 0;
    }],
  ]));
  m.defineInterface('IMediaEvent', slots(13, [
    ...unknown, ...dispatch,
    [0x1C, 'GetEventHandle', 1, (self, p) => { u32[p >> 2] = 0x4000; return S_OK; }],
    [0x20, 'GetEvent', 4, (self, pCode, p1, p2) => {
      const g = self.graph;
      poll(g);
      if (!g.events.length) return E_ABORT;
      i32[pCode >> 2] = g.events.shift();
      if (p1) u32[p1 >> 2] = 0;
      if (p2) u32[p2 >> 2] = 0;
      return S_OK;
    }],
    [0x30, 'FreeEventParams', 3, () => S_OK],
  ]));
  m.defineInterface('IMediaControl', slots(16, [
    ...unknown, ...dispatch,
    [0x1C, 'Run', 0, (self) => run(self.graph)],
    [0x20, 'Pause', 0, (self) => pause(self.graph)],
    [0x24, 'Stop', 0, (self) => stop(self.graph)],
    [0x28, 'GetState', 2, (self, ms, p) => { if (p) u32[p >> 2] = self.graph.state; return S_OK; }],
  ]));
  m.defineInterface('IMediaPosition', slots(18, [
    ...unknown, ...dispatch,
    [0x1C, 'get_Duration', 1, (self, p) => { m.view.setFloat64(p, self.graph.duration, true); return S_OK; }],
    // REFTIME is a double: two dwords on the stack
    [0x20, 'put_CurrentPosition', 2, (self, lo, hi) => {
      const g = self.graph;
      const d = new DataView(new ArrayBuffer(8));
      d.setUint32(0, lo, true);
      d.setUint32(4, hi, true);
      g.offset = Math.max(0, d.getFloat64(0, true));
      g.since = now();
      g.completed = false;
      if (sink() && g.state === STATE.running) sink().run(g.offset);
      return S_OK;
    }],
    [0x24, 'get_CurrentPosition', 1, (self, p) => { m.view.setFloat64(p, position(self.graph), true); return S_OK; }],
  ]));
  m.defineInterface('IBasicAudio', slots(11, [
    ...unknown, ...dispatch,
    [0x1C, 'put_Volume', 1, (self, v) => {
      self.graph.volume = v | 0;
      if (sink()) sink().volume(v | 0);
      return S_OK;
    }],
    [0x20, 'get_Volume', 1, (self, p) => { i32[p >> 2] = self.graph.volume; return S_OK; }],
  ]));

  m.api(O + 'CoCreateInstance', 5, (clsid, outer, ctx, riid, pOut) => {
    const g = { refs: 0, state: STATE.stopped, offset: 0, since: 0, duration: 0, events: [], completed: false, volume: 0, views: new Map(), file: '' };
    graphs.push(g);
    host.musicGraphs = graphs;
    host.musicPosition = () => +position(g).toFixed(3);
    return qi({ graph: g }, riid, pOut);
  });
}
