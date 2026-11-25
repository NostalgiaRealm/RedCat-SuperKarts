// C++ exception handling for the recompiled MSVC code (the MFC TRY/CATCH blocks in Maisy.exe).
//
// The original frames and tables are used as they are: every function with destructible locals or
// a try block links an EH registration node {prev, handler stub, state} at [ebp-0Ch] into the
// chain at fs:[0]; the stub names a FuncInfo with the unwind map and the try blocks.
//
// What differs from Windows is only the mechanics of leaving frames. Wasm frames cannot be left
// from outside, so a throw is a JavaScript exception. The recompiler puts each function that owns
// a try block behind a guard (a host thunk that calls the function's body, meta.eh.guardBodies).
// The guard of the catching frame then does what __CxxFrameHandler does: runs the cleanup funclets
// of the frames in between and of its own try states, stores the exception object, calls the
// catch funclet, and enters the function again at the continuation address the funclet returns.
// See docs/recompiler.md, Exceptions.

const CPP_EXCEPTION = 0xE06D7363;
const FUNCINFO_MAGIC = 0x19930520;

export class CppException extends Error {
  constructor(info) {
    super('C++ exception ' + info.typeName);
    Object.assign(this, info);
  }
}

export function installEh(m, host) {
  const { u8, u32, i32, u16 } = m;
  const L = m.layout;
  const eh = m.meta.eh || { stubs: {}, guardBodies: {} };
  const stubs = new Map(Object.entries(eh.stubs).map(([k, v]) => [Number(k), v]));
  const ex = m.exports;
  let current = null;                 // the exception being handled, for 'throw;'
  host.ehStats = { thrown: 0, caught: 0 };

  const typeNames = (pThrowInfo) => {
    // ThrowInfo.pCatchableTypeArray -> {n, CatchableType*[]}; CatchableType.pType -> type_info {vfptr, spare, name}
    const out = [];
    if (!pThrowInfo) return out;
    const cta = u32[(pThrowInfo + 12) >> 2];
    const n = u32[cta >> 2];
    for (let k = 0; k < n && k < 32; k++) {
      const ct = u32[(cta + 4 + k * 4) >> 2];
      out.push({ name: m.cstr(u32[(ct + 4) >> 2] + 8), mdisp: i32[(ct + 8) >> 2], pdisp: i32[(ct + 12) >> 2], vdisp: i32[(ct + 16) >> 2], props: u32[ct >> 2], size: u32[(ct + 20) >> 2], copyFn: u32[(ct + 24) >> 2] });
    }
    return out;
  };
  const funcInfoOf = (node) => {
    const fi = stubs.get(u32[(node + 4) >> 2]);
    return fi && u32[fi >> 2] === FUNCINFO_MAGIC ? fi : 0;
  };
  /** Finds the innermost frame whose active try block has a matching catch. */
  const findCatch = (types) => {
    for (let node = u32[L.TIB_BASE >> 2], guard = 0; node !== 0xFFFFFFFF && node && guard < 4096; node = u32[node >> 2], guard++) {
      const fi = funcInfoOf(node);
      if (!fi) continue;
      const state = i32[(node + 8) >> 2];
      const nTry = u32[(fi + 12) >> 2], pTry = u32[(fi + 16) >> 2];
      for (let k = 0; k < nTry; k++) {
        const t = pTry + k * 20;
        const lo = i32[t >> 2], hi = i32[(t + 4) >> 2];
        if (state < lo || state > hi) continue;
        const nCatch = i32[(t + 12) >> 2], pH = u32[(t + 16) >> 2];
        for (let j = 0; j < nCatch; j++) {
          const h = pH + j * 16;
          const pType = u32[(h + 4) >> 2];
          let match = null;
          if (!pType) match = { mdisp: 0 };                      // catch (...)
          else { const want = m.cstr(pType + 8); match = types.find((x) => x.name === want) || null; }
          if (match) return { node, ebp: node + 12, fi, tryLow: lo, tryHigh: hi, adjectives: u32[h >> 2], pType, dispCatchObj: i32[(h + 8) >> 2], handler: u32[(h + 12) >> 2], mdisp: match.mdisp || 0, ct: match };
        }
      }
    }
    return null;
  };

  host.raiseException = (code, flags, nArgs, args) => {
    if ((code >>> 0) !== CPP_EXCEPTION || nArgs < 3) throw new Error('RaiseException: code ' + (code >>> 0).toString(16) + ' (structured exceptions are not supported)');
    let pObj = u32[(args + 4) >> 2], pInfo = u32[(args + 8) >> 2];
    if (!pObj && !pInfo) {                 // 'throw;' inside a catch block: the current exception again
      if (!current) throw new Error('C++ rethrow without an exception in flight');
      pObj = current.pObj; pInfo = current.pInfo;
    }
    const types = typeNames(pInfo);
    const typeName = types.length ? types[0].name : '(unknown)';
    host.ehStats.thrown++;
    const target = findCatch(types);
    if (!target) throw new Error('Unhandled C++ exception ' + typeName + ': no catch block in any active frame');
    if (host.traceEh) host.log(`throw ${typeName} -> catch funclet ${target.handler.toString(16)} in frame ebp=${target.ebp.toString(16)}`);
    throw new CppException({ ...target, pObj, pInfo, typeName, throwEsp: m.esp });
  };
  host.rtlUnwind = () => 0;

  const callFunclet = (addr, ebp, esp) => {
    ex.g_ebp.value = ebp;
    u32[esp >> 2] = 0;
    return m.__call(addr, esp, 0, 0, 0) >>> 0;
  };
  const unwindTo = (node, fi, target, esp) => {
    const maxState = i32[(fi + 4) >> 2], pMap = u32[(fi + 8) >> 2];
    let state = i32[(node + 8) >> 2];
    let guard = 0;
    while (state !== target && state >= 0 && state < maxState && guard++ < 4096) {
      const to = i32[(pMap + state * 8) >> 2];
      const action = u32[(pMap + state * 8 + 4) >> 2];
      i32[(node + 8) >> 2] = to;
      if (action) callFunclet(action, node + 12, esp);
      state = to;
    }
  };
  /** Does the catching frame's part of the work. Returns the continuation address. */
  const handle = (e) => {
    const esp = ((Math.min(e.throwEsp, e.node) - 0x800) & ~3) >>> 0;     // below every frame being left
    for (let node = u32[L.TIB_BASE >> 2], guard = 0; node !== e.node && node !== 0xFFFFFFFF && guard < 4096; node = u32[node >> 2], guard++) {
      const fi = funcInfoOf(node);
      if (fi) unwindTo(node, fi, -1, esp);
    }
    u32[L.TIB_BASE >> 2] = e.node;
    unwindTo(e.node, e.fi, e.tryLow, esp);
    i32[(e.node + 8) >> 2] = e.tryHigh + 1;
    if (e.pType && e.dispCatchObj) {
      // What __CxxFrameHandler's BuildCatchObject does (MSVC 6 frame handler). The Maisy host only
      // needed pointers (MFC); RcHcGame.dat throws its own classes by value and catches them by
      // reference, e.g. the catch at 0x4BE68D reads the object through [ebp-24h].
      const ct = e.ct || {};
      const slot = (e.ebp + e.dispCatchObj) >>> 0;
      // address of the caught sub-object inside the thrown object (PMD: mdisp, pdisp, vdisp)
      let adj = e.pObj;
      if (ct.pdisp !== undefined && ct.pdisp >= 0) adj = (adj + ct.pdisp + i32[(u32[(adj + ct.pdisp) >> 2] + ct.vdisp) >> 2]) >>> 0;
      adj = (adj + (ct.mdisp || 0)) >>> 0;
      if (e.adjectives & 8) {
        u32[slot >> 2] = adj;                                   // catch (T&): the address of the object
      } else if (ct.props & 1) {
        // simple type: copied bytewise; a pointer to a class is adjusted to the caught base
        u8.copyWithin(slot, e.pObj, e.pObj + (ct.size || 4));
        if ((ct.size || 4) === 4 && u32[slot >> 2]) u32[slot >> 2] = (u32[slot >> 2] + (ct.mdisp || 0)) >>> 0;
      } else if (!ct.copyFn) {
        u8.copyWithin(slot, adj, adj + (ct.size || 4));         // class without a copy constructor
      } else {
        const args = ct.props & 4 ? [adj, 1] : [adj];           // CT_HasVirtualBase: extra flag argument
        m.call(ct.copyFn, args, slot);                          // copy constructor, this = the catch object
      }
    }
    const before = current;
    current = e;
    let cont;
    try { cont = callFunclet(e.handler, e.ebp, esp); } finally { current = before; }
    host.ehStats.caught++;
    if (host.traceEh) host.log(`catch done, continue at ${cont.toString(16)}`);
    return cont;
  };

  const codeIndex = (addr) => u16[(L.CODE_MAP + (addr - L.MAP_LO) * 2) >> 1];
  for (const [name, hook] of Object.entries(m.meta.hooks || {})) {
    if (!name.startsWith('eh_')) continue;
    const body = eh.guardBodies[String(hook.addr)];          // its table index (m.callBody: no result array per call)
    m.bindRaw('hook!' + name, hook.pop, (esp, ecx, edx, eax) => {
      let fn = body, a0 = esp, a1 = eax, a2 = ecx, a3 = edx;
      for (;;) {
        try {
          return m.callBody(fn, a0, a1, a2, a3);
        } catch (e) {
          if (!(e instanceof CppException) || e.ebp !== ((esp - 4) >>> 0)) throw e;
          const cont = handle(e);
          const idx = codeIndex(cont);
          if (!idx) throw new Error('C++ catch continuation ' + cont.toString(16) + ' has no entry');
          fn = idx;
          // the function goes on with its own frame: ebp as before, esp as saved at try entry
          ex.g_ebp.value = e.ebp; ex.g_ebx.value = 0; ex.g_esi.value = 0; ex.g_edi.value = 0;
          a0 = u32[(e.ebp - 16) >> 2]; a1 = 0; a2 = 0; a3 = 0;
        }
      }
    });
    m.bound.add('hook!' + name);
  }
}
