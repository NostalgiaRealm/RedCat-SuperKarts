// The recompiled RcHcGame.dat instance: memory views, host thunks, COM objects, calls into
// original code. See docs/recompiler.md. Taken from the Maisy's Playhouse host (machine.js),
// with the COM helpers of the A2 Racer 4 host added back for DirectInput and DirectSound.

const MATH = {
  sin: Math.sin, cos: Math.cos, tan: Math.tan, atan2: Math.atan2, log2: Math.log2,
  pow2m1: (x) => Math.expm1(x * Math.LN2), pow2: (x) => Math.pow(2, x),
  fmod: (a, b) => a % b, frem: (a, b) => a - b * nearestEven(a / b),
  acos: Math.acos, asin: Math.asin, pow: Math.pow, atan: Math.atan, exp: Math.exp,
  log: Math.log, log10: Math.log10, sinh: Math.sinh, cosh: Math.cosh, tanh: Math.tanh,
};

function nearestEven(x) {
  const r = Math.round(x);
  return Math.abs(x % 1) === 0.5 && r % 2 !== 0 ? r - 1 : r;
}

// (module (type $f (func (param i32 i32 i32 i32) (result i32 i32))) (import "env" "table" (table 0 funcref))
//   (func (export "body") (param $index i32) (param i32 i32 i32 i32) (result i32) (local $eax i32)
//     local.get 1 local.get 2 local.get 3 local.get 4 local.get $index call_indirect (type $f) local.set $eax drop local.get $eax))
const BODY_CALLER = new Uint8Array([0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00,
  0x01, 0x13, 0x02, 0x60, 0x04, 0x7F, 0x7F, 0x7F, 0x7F, 0x02, 0x7F, 0x7F, 0x60, 0x05, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x01, 0x7F,
  0x02, 0x0F, 0x01, 0x03, 0x65, 0x6E, 0x76, 0x05, 0x74, 0x61, 0x62, 0x6C, 0x65, 0x01, 0x70, 0x00, 0x00,
  0x03, 0x02, 0x01, 0x01,
  0x07, 0x08, 0x01, 0x04, 0x62, 0x6F, 0x64, 0x79, 0x00, 0x00,
  0x0A, 0x18, 0x01, 0x16, 0x01, 0x01, 0x7F, 0x20, 0x01, 0x20, 0x02, 0x20, 0x03, 0x20, 0x04, 0x20, 0x00, 0x11, 0x00, 0x00, 0x21, 0x05, 0x1A, 0x20, 0x05, 0x0B]);
/** No arguments: one array for every such call (call() only reads it). */
const NO_ARGS = [];

export class GameExit extends Error {
  constructor(code) {
    super('game exit ' + code);
    this.code = code;
  }
}

export class Machine {
  constructor(meta) {
    this.meta = meta;
    this.layout = meta.layout;
    this.thunks = new Array(meta.layout.N_THUNKS).fill(null);
    this.thunkNames = new Array(meta.layout.N_THUNKS).fill(null);
    this.nextThunk = meta.firstFreeThunk;
    this.esp = meta.layout.STACK_TOP;
    this.lowBump = 0x00020000;   // low memory block for host-owned structures
    this.lowSizes = [];          // every size asked of lowAlloc while the host is put together: part of a save state's build identity (snapshot.js seal())
    this.onUnimplemented = (name) => {
      throw new Error('Host function not implemented: ' + name);
    };
    this.apiCount = new Map();
    this.bound = new Set();
    this.traceApi = null;
    this.objects = new Map();    // COM object address -> JS state
    this.vtables = new Map();
  }

  async instantiate(wasm, codeMap) {
    this.codeMap = codeMap;
    const env = {
      ...MATH,
      trace: (addr, esp, eax, ecx, edx) => {
        if (this.onTrace) this.onTrace(addr >>> 0, esp >>> 0, eax >>> 0, ecx >>> 0, edx >>> 0);
      },
      host: (id, esp, eax, ecx, edx) => {
        this.esp = esp;
        if (this.traceApi) this.traceApi(id, esp);
        return this.thunks[id](esp, ecx, edx, eax) | 0;
      },
    };
    const res = wasm instanceof WebAssembly.Module
      ? { instance: await WebAssembly.instantiate(wasm, { env }) }
      : await WebAssembly.instantiate(wasm, { env });
    this.instance = res.instance;
    const ex = res.instance.exports;
    this.exports = ex;
    this.mem = ex.memory;
    this.__call = ex.__call;
    // callBody(table index, esp, eax, ecx, edx) -> eax. A function of the module returns two values (esp, eax), and
    // a call from JavaScript gets those as a new two-element array every time: 800 of them per frame from the
    // guards of eh.js alone. This small module makes the same call from WebAssembly and hands back eax only.
    this.callBody = new WebAssembly.Instance(new WebAssembly.Module(BODY_CALLER), { env: { table: ex.table } }).exports.body;
    this.gEsp = ex.g_esp;
    this.gEdx = ex.g_edx;
    this.gSt0 = ex.g_st0;
    this.gCw = ex.g_cw;
    const b = ex.memory.buffer;
    this.u8 = new Uint8Array(b);
    this.i8 = new Int8Array(b);
    this.u16 = new Uint16Array(b);
    this.i16 = new Int16Array(b);
    this.u32 = new Uint32Array(b);
    this.i32 = new Int32Array(b);
    this.f32 = new Float32Array(b);
    this.f64 = new Float64Array(b);
    this.view = new DataView(b);
    const { CODE_MAP, MAP_LO } = this.layout;
    const cm = new Uint32Array(this.codeMap.buffer, this.codeMap.byteOffset, this.codeMap.byteLength >> 2);
    for (let k = 0; k < cm.length; k += 2) this.u16[(CODE_MAP + (cm[k] - MAP_LO) * 2) >> 1] = cm[k + 1];
    this.codeMap = null;
    // Unaligned-safe IAT and pop table defaults.
    for (const [id, name] of Object.entries(this.meta.thunks)) {
      const k = Number(id);
      this.thunkNames[k] = name;
      this.thunks[k] = () => this.onUnimplemented(name);
    }
    for (let k = 0; k < this.thunks.length; k++) {
      if (!this.thunks[k]) this.thunks[k] = () => this.onUnimplemented('thunk#' + k);
    }
    // 'wrap' hooks (tools/recomp/build.py GAME_HOOKS): every call of the function reaches its thunk, and the original
    // body keeps a table slot of its own (meta.hooks[name].body). Bound here to that body, so until host code wraps
    // it (wrap()) the game runs exactly as the original, also with a host older than the wasm.
    this.bodies = new Map();               // function address -> table index of its original body
    for (const [name, h] of Object.entries(this.meta.hooks || {})) {
      if (h.kind !== 'wrap') continue;
      const body = h.body;
      this.bodies.set(h.addr, body);
      this.bindRaw('hook!' + name, h.pop, (esp, ecx, edx, eax) => this.callBody(body, esp, eax, ecx, edx));
    }
    // The thread information block: no exception frame yet, stack limits.
    const { TIB_BASE, STACK_TOP, STACK_LOW } = this.layout;
    this.u32[TIB_BASE >> 2] = 0xFFFFFFFF;
    this.u32[(TIB_BASE + 4) >> 2] = STACK_TOP;
    this.u32[(TIB_BASE + 8) >> 2] = STACK_LOW;
    this.u32[(TIB_BASE + 0x18) >> 2] = TIB_BASE;
    return this;
  }

  // --- host functions ---------------------------------------------------------
  /** Binds an imported function by "DLL!Name". fn(esp) gets the raw stack pointer. */
  bindRaw(name, popBytes, fn) {
    const id = this.thunkId(name);
    this.bound.add(name);
    this.thunks[id] = fn;
    this.u32[(this.layout.POP_TABLE + id * 4) >> 2] = popBytes;
  }

  thunkId(name) {
    if (!this._ids) {
      this._ids = new Map();
      for (const [id, n] of Object.entries(this.meta.thunks)) this._ids.set(n, Number(id));
    }
    const id = this._ids.get(name);
    if (id === undefined) throw new Error('unknown thunk ' + name);
    return id;
  }

  /** Binds an stdcall import. fn receives its integer arguments. */
  api(name, nargs, fn) {
    if (!this._ids) this.thunkId(name);
    if (!this._ids.has(name)) return; // no module imports it
    this.bound.add(name);
    const u32 = this.u32;
    const wrapped = (esp) => {
      switch (nargs) {
        case 0: return fn();
        case 1: return fn(u32[(esp + 4) >> 2]);
        case 2: return fn(u32[(esp + 4) >> 2], u32[(esp + 8) >> 2]);
        case 3: return fn(u32[(esp + 4) >> 2], u32[(esp + 8) >> 2], u32[(esp + 12) >> 2]);
        case 4: return fn(u32[(esp + 4) >> 2], u32[(esp + 8) >> 2], u32[(esp + 12) >> 2], u32[(esp + 16) >> 2]);
        case 5: return fn(u32[(esp + 4) >> 2], u32[(esp + 8) >> 2], u32[(esp + 12) >> 2], u32[(esp + 16) >> 2], u32[(esp + 20) >> 2]);
        case 6: return fn(u32[(esp + 4) >> 2], u32[(esp + 8) >> 2], u32[(esp + 12) >> 2], u32[(esp + 16) >> 2], u32[(esp + 20) >> 2], u32[(esp + 24) >> 2]);
        default: {
          const a = new Array(nargs);
          for (let k = 0; k < nargs; k++) a[k] = u32[(esp + 4 + k * 4) >> 2];
          return fn(...a);
        }
      }
    };
    this.bindRaw(name, nargs * 4, wrapped);
  }

  /**
   * Wraps a game function behind a hook: a 'wrap' (meta.hooks[name].kind, build.py GAME_HOOKS) or a C++ guard
   * 'eh_XXXXXXXX' (eh.js). fn(esp, ecx, edx, eax, next) then runs for every call of it, with the registers the caller
   * passed (esp points at the return address, the first stack argument is at esp + 4), and returns eax; next(esp, ecx,
   * edx, eax) runs what was bound before (at first the original body, or the guard that runs it) and returns its eax.
   * Wrappers chain, the last one bound runs first. The stack pop stays the function's (meta.hooks[name].pop), also
   * when fn does not call next. An x87 result (ST0, m.gSt0) and edx (m.gEdx) are left as the body left them.
   */
  wrap(name, fn) {
    const id = this.thunkId('hook!' + name);
    if (!this.bound.has('hook!' + name)) throw new Error('wrap: hook!' + name + ' is not bound yet');
    const next = this.thunks[id];
    this.thunks[id] = (esp, ecx, edx, eax) => fn(esp, ecx, edx, eax, next);
  }

  /**
   * call() for the original body of a 'wrap' hook's function, past every wrapper (for any other address the same as
   * call()). For host code outside the hook; inside a wrapper, next() is the way to the body.
   */
  callOriginal(addr, args = NO_ARGS, ecx = 0, edx = 0) {
    const body = this.bodies.get(addr);
    if (body === undefined) return this.call(addr, args, ecx, edx);
    const saved = this.esp;
    const esp = this.pushArgs(args);
    const r = this.callBody(body, esp, 0, ecx, edx);
    this.esp = saved;
    return r;
  }

  /** Allocates a thunk for a JS callable that game code calls by address. */
  makeThunk(name, popBytes, fn) {
    const id = this.nextThunk++;
    if (id >= this.thunks.length) throw new Error('out of host thunks');
    this.thunks[id] = fn;
    this.thunkNames[id] = name;
    this.u32[(this.layout.POP_TABLE + id * 4) >> 2] = popBytes;
    return this.layout.THUNK_BASE + id;
  }

  /** Allocates low memory for host-owned structures. Never freed. */
  lowAlloc(size) {
    const p = (this.lowBump + 15) & ~15;
    this.lowBump = p + size;
    if (this.lowSizes) this.lowSizes.push(size);
    if (this.lowBump > 0x000F0000) throw new Error('low area full');
    return p;
  }

  /** Is addr an entry in the code map (callable)? */
  isCode(addr) {
    const { CODE_MAP, MAP_LO, IMAGE_END } = this.layout;
    return addr >= MAP_LO && addr < IMAGE_END && this.u16[(CODE_MAP + (addr - MAP_LO) * 2) >> 1] !== 0;
  }

  // --- COM --------------------------------------------------------------------
  /**
   * methods: array of [name, nargsExcludingThis, fn(self, ...args)] in vtable order,
   * or null for a slot the game is not known to call (it then stops with the slot's name).
   */
  defineInterface(iface, methods) {
    const vt = this.lowAlloc(methods.length * 4);
    const u32 = this.u32;
    methods.forEach((mt, k) => {
      const name = iface + '::' + (mt ? mt[0] : 'slot' + k);
      if (!mt) {
        u32[(vt + k * 4) >> 2] = this.makeThunk(name, 0, () => this.onUnimplemented(name));
        return;
      }
      const [, n, fn] = mt;
      const objects = this.objects;
      // no argument array for the usual counts: the game asks every playing sound buffer for its status every frame
      const thunk = n === 0 ? (esp) => fn(objects.get(u32[(esp + 4) >> 2]))
        : n === 1 ? (esp) => fn(objects.get(u32[(esp + 4) >> 2]), u32[(esp + 8) >> 2])
        : n === 2 ? (esp) => fn(objects.get(u32[(esp + 4) >> 2]), u32[(esp + 8) >> 2], u32[(esp + 12) >> 2])
        : n === 3 ? (esp) => fn(objects.get(u32[(esp + 4) >> 2]), u32[(esp + 8) >> 2], u32[(esp + 12) >> 2], u32[(esp + 16) >> 2])
        : n === 4 ? (esp) => fn(objects.get(u32[(esp + 4) >> 2]), u32[(esp + 8) >> 2], u32[(esp + 12) >> 2], u32[(esp + 16) >> 2], u32[(esp + 20) >> 2])
        : (esp) => {
          const self = objects.get(u32[(esp + 4) >> 2]);
          const a = new Array(n);
          for (let j = 0; j < n; j++) a[j] = u32[(esp + 8 + j * 4) >> 2];
          return fn(self, ...a);
        };
      u32[(vt + k * 4) >> 2] = this.makeThunk(name, (n + 1) * 4, thunk);
    });
    this.vtables.set(iface, vt);
    return vt;
  }

  /** Creates a COM object: returns its address. self is the JS state object. */
  newObject(iface, self) {
    const p = this.lowAlloc(16);
    this.u32[p >> 2] = this.vtables.get(iface);
    self.addr = p;
    self.refs = 1;
    self.iface = iface;
    this.objects.set(p, self);
    return p;
  }

  // --- calling game code ------------------------------------------------------
  /** cdecl or stdcall call from the host. Arguments are integers. Returns eax. */
  call(addr, args = NO_ARGS, ecx = 0, edx = 0) {
    const saved = this.esp;
    const esp = this.pushArgs(args);
    const r = this.__call(addr, esp, 0, ecx, edx);
    this.esp = saved;
    return r;
  }

  /** A call frame 256 bytes below the current esp: the arguments, then a zero return address. Returns the new esp. */
  pushArgs(args) {
    let esp = (this.esp - 256) & ~3;
    esp -= args.length * 4;
    for (let k = 0; k < args.length; k++) this.u32[(esp + k * 4) >> 2] = args[k] >>> 0;
    esp -= 4;
    this.u32[esp >> 2] = 0;
    this.esp = esp;
    return esp;
  }

  // --- strings ----------------------------------------------------------------
  cstr(p) {
    const u8 = this.u8;
    let s = '';
    for (let c = u8[p]; c; c = u8[++p]) s += String.fromCharCode(c);
    return s;
  }

  writeCStr(p, s, max = 0x7FFFFFFF) {
    const u8 = this.u8;
    const n = Math.min(s.length, max - 1);
    for (let k = 0; k < n; k++) u8[p + k] = s.charCodeAt(k) & 0xFF;
    u8[p + n] = 0;
    return n;
  }
}
