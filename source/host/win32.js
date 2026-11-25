// KERNEL32, USER32, ADVAPI32, GDI32 and WINMM as far as rcskspel.dat uses them. Taken from the A2 Racer 4
// host (source/host/win32.js), with SuperKarts' paths and the imports A2's spel.dat does not have.
// Call sites: docs/host.md.
import { GameExit } from './machine.js';
import { normalizePath } from './vfs.js';

const INVALID_HANDLE = 0xFFFFFFFF;
// The race runs in the installation's data folder: the launcher starts it there, and it builds every INI path
// from GetCurrentDirectoryA (0x4b1d60) and some from its own module file name (0x474410).
export const GAME_DIR = 'C:\\RCSK\\data';

export class Heap {
  constructor(m, base, limit) {
    this.m = m;
    this.bump = base;
    this.limit = limit;
    this.free = new Map();
    this.pageBump = limit;   // VirtualAlloc grows down from the limit
    this.bytesInUse = 0;
  }

  alloc(size, zero = false) {
    const n = Math.max(16, (size + 15) & ~15);
    const list = this.free.get(n);
    let p;
    if (list && list.length) {
      p = list.pop();
      if (zero) this.m.u8.fill(0, p, p + n);
    } else {
      p = this.bump + 16;
      this.bump = p + n;
      if (this.bump >= this.pageBump) throw new Error('out of game memory');
    }
    this.m.u32[(p - 16) >> 2] = n;
    this.m.u32[(p - 12) >> 2] = size;
    this.bytesInUse += n;
    return p;
  }

  sizeOf(p) {
    return this.m.u32[(p - 12) >> 2];
  }

  release(p) {
    if (!p) return;
    const n = this.m.u32[(p - 16) >> 2];
    let list = this.free.get(n);
    if (!list) {
      list = [];
      this.free.set(n, list);
    }
    list.push(p);
    this.bytesInUse -= n;
  }

  realloc(p, size, zero = false) {
    const old = this.m.u32[(p - 16) >> 2];
    const oldSize = this.m.u32[(p - 12) >> 2];
    const n = Math.max(16, (size + 15) & ~15);
    if (n <= old) {
      this.m.u32[(p - 12) >> 2] = size;
      if (zero && size > oldSize) this.m.u8.fill(0, p + oldSize, p + size);
      return p;
    }
    const q = this.alloc(size, zero);
    this.m.u8.copyWithin(q, p, p + Math.min(oldSize, size));
    this.release(p);
    return q;
  }

  /** Page-aligned block for VirtualAlloc, zero on first use. */
  pages(size) {
    const n = (size + 0xFFFF) & ~0xFFFF;
    this.pageBump -= n;
    if (this.pageBump <= this.bump) throw new Error('out of game memory (pages)');
    return this.pageBump;
  }
}

/**
 * The game's clock: only advances when the host says so (race.js). Kept in whole microseconds, so that
 * GetTickCount reads exactly n * 25 after n ticks of 25 ms: summing 0.025 as a double gave 1999 instead of
 * 2000 at tick 40, and the start camera (a 1000 ms wait in 0x4441a0) then moved one update late
 * (evidence/checks/start-parity.txt). QueryPerformanceCounter is derived from the same count.
 */
export class VirtualClock {
  constructor() {
    this.us = 0;
    this.queries = 0;
    this.polls = 0;
    this.freq = 1193182;
    // In the browser's game worker (source/web/worker.js): realNow() is the real time in ms, idle() lets
    // the thread sleep a moment. A tick that the game keeps inside one of its own waits (the pause, the
    // quit requester, a key it waits to see released) then sees real time pass, as on Windows, and does
    // not keep a processor core busy. Without them (Node), time inside a tick only moves by the bump below.
    this.realNow = null;
    this.idle = null;
    this.tickReal = 0;
    this.tickUs = 0;
    // Free flight (source/host/free-flight.js) stops the game's time: GetTickCount, timeGetTime and the counter stand
    // still while it flies (frozenUs) and go on from there after it (offsetUs), as the JS reconstruction's
    // flightClockOffsetMs (race-simulation.js:262-278). us goes on: the sounds' and the music's clock (dsound.js,
    // dshow.js). With no flight offsetUs stays 0 and nothing changes.
    this.offsetUs = 0;
    this.frozenUs = null;
  }

  freeze() { if (this.frozenUs === null) this.frozenUs = this.us; }
  thaw() { if (this.frozenUs !== null) { this.offsetUs += this.us - this.frozenUs; this.frozenUs = null; } }
  /** The game's microseconds: the clock less the time it stood still (query() still runs: its naps). */
  gameUs() { const q = this.query(); return (this.frozenUs ?? q) - this.offsetUs; }

  get seconds() { return this.us / 1e6; }
  set seconds(s) { this.us = Math.round(s * 1e6); }

  advance(dt) {
    this.us += Math.round(dt * 1e6);
    this.queries = 0;
    this.polls = 0;
    this.tickUs = this.us;
    if (this.realNow) this.tickReal = this.realNow();
  }

  /** Code that spins on the clock inside one tick must still see time pass. */
  query() {
    if (this.realNow) {
      const lag = this.realNow() - this.tickReal;
      if (lag > 40) this.us = Math.max(this.us, this.tickUs + Math.round(lag * 1000));
      // a nap per 512 readings, not per reading: a loop that sweeps all 256 keys must see a short press
      if (++this.queries > 2000 && (this.queries & 511) === 0 && this.idle) this.idle();
    } else if (++this.queries > 2000) this.us += 500;
    return this.us;
  }

  /** A key polled again and again inside one tick: the game waits for input. */
  poll() {
    // a nap per 512 polls once the game has been waiting a while: the pause's key scan (0x42f220) sweeps all
    // 256 keys, and a nap per poll made a sweep last half a second, so a short press fell between two looks
    if (++this.polls > 4000 && (this.polls & 511) === 0 && this.idle) {
      this.idle();
      if (this.realNow) this.query();
    }
  }

  /** GetTickCount and timeGetTime: whole milliseconds. */
  ms() { return Math.floor(this.gameUs() / 1000); }

  /** QueryPerformanceCounter: whole counts of freq per second. */
  counts() { return Math.floor(this.gameUs() * this.freq / 1e6); }
}

export function installWin32(m, host) {
  const { vfs, clock } = host;
  const { u8, u16, u32, i32 } = m;
  const heap = new Heap(m, m.layout.HEAP_BASE, m.layout.MEM_PAGES * 65536);
  host.heap = heap;
  let lastError = 0;
  const handles = new Map();
  let nextHandle = 0x100;
  const cmdLine = m.lowAlloc(32);
  m.writeCStr(cmdLine, 'rcskspel.dat');
  // NOCD=D: the race's own way past the disc check (0x4b9a00 reads getenv("NOCD") and takes its first letter
  // as the CD drive), so no patch is needed. The C runtime asks for the wide block first (0x4c7a3e) and
  // falls back to the narrow one when that returns 0.
  const envBlock = m.lowAlloc(16);
  m.writeCStr(envBlock, 'NOCD=D');
  u8[envBlock + 7] = 0;
  const K = 'KERNEL32.DLL!';
  const U = 'USER32.DLL!';
  const G = 'GDI32.DLL!';
  const W = 'WINMM.DLL!';

  // --- process and CRT start-up ---------------------------------------------
  m.api(K + 'GetVersion', 0, () => 0xC0000A04 | 0);    // Windows 98
  m.api(K + 'GetVersionExA', 1, (p) => {
    u32[(p + 4) >> 2] = 4;
    u32[(p + 8) >> 2] = 10;
    u32[(p + 12) >> 2] = 0x040A08AE;
    u32[(p + 16) >> 2] = 1;   // VER_PLATFORM_WIN32_WINDOWS
    u8[p + 20] = 0;
    return 1;
  });
  m.api(K + 'GetCommandLineA', 0, () => cmdLine);
  m.api(K + 'GetStartupInfoA', 1, (p) => {
    u8.fill(0, p, p + 68);
    u32[p >> 2] = 68;
    return 0;
  });
  m.api(K + 'GetModuleHandleA', 1, (p) => (p ? 0 : 0x00400000));
  m.api(K + 'GetModuleFileNameA', 3, (h, p, n) => m.writeCStr(p, GAME_DIR + '\\rcskspel.dat', n));
  m.api(K + 'LoadLibraryA', 1, () => 0);
  m.api(K + 'GetProcAddress', 2, () => 0);
  m.api(K + 'ExitProcess', 1, (code) => {
    throw new GameExit(code);
  });
  m.api(K + 'TerminateProcess', 2, (h, code) => {
    throw new GameExit(code);
  });
  m.api(K + 'GetCurrentProcess', 0, () => 0xFFFFFFFF);
  m.api(K + 'GetLastError', 0, () => lastError);
  m.api(K + 'SetUnhandledExceptionFilter', 1, () => 0);
  m.api(K + 'UnhandledExceptionFilter', 1, () => 0);
  // C++ throw (0xE06D7363): eh.js finds the catching frame. See docs/recompiler.md, Exceptions.
  m.api(K + 'RaiseException', 4, (code, flags, n, args) => host.raiseException(code, flags, n, args));
  m.api(K + 'RtlUnwind', 4, (frame, ip, rec, ret) => host.rtlUnwind(frame, ip, rec, ret));
  m.api(K + 'OutputDebugStringA', 1, () => 0);
  m.api(K + 'IsBadWritePtr', 2, () => 0);
  m.api(K + 'IsBadReadPtr', 2, () => 0);
  m.api(K + 'IsBadCodePtr', 1, () => 0);
  m.api(K + 'SetHandleCount', 1, (n) => n);
  m.api(K + 'GetStdHandle', 1, (n) => 0x10 + (n & 7));
  m.api(K + 'SetStdHandle', 2, () => 1);
  m.api(K + 'GetEnvironmentStrings', 0, () => envBlock);
  m.api(K + 'GetEnvironmentStringsW', 0, () => 0);
  m.api(K + 'FreeEnvironmentStringsA', 1, () => 1);
  m.api(K + 'FreeEnvironmentStringsW', 1, () => 1);
  m.api(K + 'SetEnvironmentVariableA', 2, () => 1);
  m.api(K + 'GetComputerNameA', 2, (p, sz) => {
    const n = m.writeCStr(p, 'RCSK');
    u32[sz >> 2] = n;
    return 1;
  });
  m.api('ADVAPI32.DLL!GetUserNameA', 2, (p, sz) => {
    const n = m.writeCStr(p, 'speler');
    u32[sz >> 2] = n + 1;
    return 1;
  });
  m.api(K + 'GetSystemInfo', 1, (p) => {
    u8.fill(0, p, p + 36);
    u32[(p + 4) >> 2] = 4096;
    u32[(p + 8) >> 2] = 0x00010000;
    u32[(p + 12) >> 2] = 0x7FFEFFFF;
    u32[(p + 16) >> 2] = 1;
    u32[(p + 20) >> 2] = 1;
    u32[(p + 24) >> 2] = 586;
    u32[(p + 28) >> 2] = 65536;
    return 0;
  });
  m.api(K + 'GlobalMemoryStatus', 1, (p) => {
    u32[p >> 2] = 32;
    u32[(p + 4) >> 2] = 50;
    u32[(p + 8) >> 2] = 256 << 20;
    u32[(p + 12) >> 2] = 128 << 20;
    u32[(p + 16) >> 2] = 512 << 20;
    u32[(p + 20) >> 2] = 256 << 20;
    u32[(p + 24) >> 2] = 2047 << 20;
    u32[(p + 28) >> 2] = 1024 << 20;
    return 0;
  });

  // --- heap -------------------------------------------------------------------
  m.api(K + 'HeapCreate', 3, () => 1);
  m.api(K + 'HeapDestroy', 1, () => 1);
  m.api(K + 'HeapAlloc', 3, (h, flags, size) => heap.alloc(size, (flags & 8) !== 0));
  m.api(K + 'HeapFree', 3, (h, flags, p) => {
    heap.release(p);
    return 1;
  });
  m.api(K + 'HeapReAlloc', 4, (h, flags, p, size) => heap.realloc(p, size, (flags & 8) !== 0));
  m.api(K + 'HeapSize', 3, (h, flags, p) => heap.sizeOf(p));
  m.api(K + 'LocalAlloc', 2, (flags, size) => heap.alloc(size, (flags & 0x40) !== 0));
  m.api(K + 'LocalFree', 1, (p) => {
    heap.release(p);
    return 0;
  });
  m.api(K + 'LocalReAlloc', 3, (p, size, flags) => heap.realloc(p, size, (flags & 0x40) !== 0));
  m.api(K + 'VirtualAlloc', 4, (addr, size) => (addr || heap.pages(size)));
  m.api(K + 'VirtualFree', 3, (addr, size, type) => {
    if (type & 0x4000 && size) u8.fill(0, addr, addr + size);
    return 1;
  });

  // --- time ---------------------------------------------------------------------
  m.api(K + 'QueryPerformanceFrequency', 1, (p) => {
    u32[p >> 2] = clock.freq;
    u32[(p + 4) >> 2] = 0;
    return 1;
  });
  m.api(K + 'QueryPerformanceCounter', 1, (p) => {
    const ticks = clock.counts();
    u32[p >> 2] = ticks % 4294967296;
    u32[(p + 4) >> 2] = Math.floor(ticks / 4294967296);
    return 1;
  });
  const msNow = () => clock.ms() >>> 0;
  m.api(K + 'GetTickCount', 0, msNow);
  m.api(W + 'timeGetTime', 0, msNow);
  const writeSystemTime = (p, d) => {
    u16[p >> 1] = d.getUTCFullYear();
    u16[(p + 2) >> 1] = d.getUTCMonth() + 1;
    u16[(p + 4) >> 1] = d.getUTCDay();
    u16[(p + 6) >> 1] = d.getUTCDate();
    u16[(p + 8) >> 1] = d.getUTCHours();
    u16[(p + 10) >> 1] = d.getUTCMinutes();
    u16[(p + 12) >> 1] = d.getUTCSeconds();
    u16[(p + 14) >> 1] = d.getUTCMilliseconds();
  };
  // host.fixedDate makes runs repeatable: the C runtime's time() seeds rand from this.
  const nowDate = () => (host.fixedDate ? new Date(host.fixedDate) : new Date());
  m.api(K + 'GetSystemTime', 1, (p) => {
    writeSystemTime(p, nowDate());
    return 0;
  });
  m.api(K + 'GetLocalTime', 1, (p) => {
    const d = nowDate();
    writeSystemTime(p, new Date(d.getTime() - d.getTimezoneOffset() * 60000));
    return 0;
  });
  const writeFileTime = (p, ms) => {
    const t = BigInt(Math.floor(ms)) * 10000n + 116444736000000000n;
    u32[p >> 2] = Number(t & 0xFFFFFFFFn);
    u32[(p + 4) >> 2] = Number(t >> 32n);
  };
  m.api(K + 'GetSystemTimeAsFileTime', 1, (p) => {
    writeFileTime(p, nowDate().getTime());
    return 0;
  });
  m.api(K + 'FileTimeToLocalFileTime', 2, (a, b) => {
    u32[b >> 2] = u32[a >> 2];
    u32[(b + 4) >> 2] = u32[(a + 4) >> 2];
    return 1;
  });
  m.api(K + 'FileTimeToSystemTime', 2, (a, b) => {
    const t = (BigInt(u32[(a + 4) >> 2]) << 32n) | BigInt(u32[a >> 2]);
    writeSystemTime(b, new Date(Number((t - 116444736000000000n) / 10000n)));
    return 1;
  });
  m.api(K + 'GetTimeZoneInformation', 1, (p) => {
    u8.fill(0, p, p + 172);
    return 0;
  });

  // --- locale -------------------------------------------------------------------
  m.api(K + 'GetACP', 0, () => 1252);
  m.api(K + 'GetOEMCP', 0, () => 437);
  m.api(K + 'GetCPInfo', 2, (cp, p) => {
    u8.fill(0, p, p + 18);
    u32[p >> 2] = 1;
    u8[p + 4] = 0x3F;
    return 1;
  });
  m.api(K + 'IsValidCodePage', 1, () => 1);
  m.api(K + 'IsValidLocale', 2, () => 1);
  m.api(K + 'EnumSystemLocalesA', 2, () => 1);
  m.api(K + 'GetUserDefaultLCID', 0, () => 0x0413);
  m.api(K + 'GetLocaleInfoA', 4, (lc, t, p, n) => {
    if (n) m.writeCStr(p, '', n);
    return 1;
  });
  m.api(K + 'GetLocaleInfoW', 4, (lc, t, p, n) => {
    if (n) u16[p >> 1] = 0;
    return 1;
  });
  m.api(K + 'MultiByteToWideChar', 6, (cp, fl, src, cb, dst, cw) => {
    let n = cb;
    if (n === 0xFFFFFFFF) {
      n = 0;
      while (u8[src + n]) n++;
      n++;
    }
    if (!cw) return n;
    n = Math.min(n, cw);
    for (let k = 0; k < n; k++) m.view.setUint16(dst + k * 2, u8[src + k], true);
    return n;
  });
  m.api(K + 'WideCharToMultiByte', 8, (cp, fl, src, cw, dst, cb) => {
    let n = cw;
    if (n === 0xFFFFFFFF) {
      n = 0;
      while (m.view.getUint16(src + n * 2, true)) n++;
      n++;
    }
    if (!cb) return n;
    n = Math.min(n, cb);
    for (let k = 0; k < n; k++) {
      const c = m.view.getUint16(src + k * 2, true);
      u8[dst + k] = c < 256 ? c : 0x3F;
    }
    return n;
  });
  const ctype1 = (c) => {
    let f = 0;
    if (c >= 0x41 && c <= 0x5A) f |= 0x81 | 0x100;
    if (c >= 0x61 && c <= 0x7A) f |= 0x82 | 0x100;
    if (c >= 0x30 && c <= 0x39) f |= 0x84;
    if (c === 0x20 || (c >= 9 && c <= 13)) f |= 0x08;
    if (c === 0x20) f |= 0x40;
    if (c < 0x20 || c === 0x7F) f |= 0x20;
    if ((c >= 0x21 && c <= 0x2F) || (c >= 0x3A && c <= 0x40) || (c >= 0x5B && c <= 0x60) || (c >= 0x7B && c <= 0x7E)) f |= 0x10;
    if ((c >= 0x41 && c <= 0x46) || (c >= 0x61 && c <= 0x66)) f |= 0x80;
    return f;
  };
  m.api(K + 'GetStringTypeA', 5, (lc, t, src, n, out) => {
    if (n === 0xFFFFFFFF) n = 0x7FFFFFFF;
    for (let k = 0; k < n; k++) {
      const c = u8[src + k];
      m.view.setUint16(out + k * 2, ctype1(c), true);
      if (!c && n === 0x7FFFFFFF) break;
    }
    return 1;
  });
  m.api(K + 'GetStringTypeW', 4, (t, src, n, out) => {
    if (n === 0xFFFFFFFF) n = 0x7FFFFFFF;
    for (let k = 0; k < n; k++) {
      const c = m.view.getUint16(src + k * 2, true);
      m.view.setUint16(out + k * 2, ctype1(c), true);
      if (!c && n === 0x7FFFFFFF) break;
    }
    return 1;
  });
  const lcmapChar = (c, fl) => {
    if (fl & 0x200 && c >= 0x61 && c <= 0x7A) return c - 32;
    if (fl & 0x100 && c >= 0x41 && c <= 0x5A) return c + 32;
    return c;
  };
  m.api(K + 'LCMapStringA', 6, (lc, fl, src, n, dst, cb) => {
    if (n === 0xFFFFFFFF) {
      n = 0;
      while (u8[src + n]) n++;
      n++;
    }
    if (!cb) return n;
    n = Math.min(n, cb);
    for (let k = 0; k < n; k++) u8[dst + k] = lcmapChar(u8[src + k], fl);
    return n;
  });
  m.api(K + 'LCMapStringW', 6, (lc, fl, src, n, dst, cb) => {
    if (n === 0xFFFFFFFF) {
      n = 0;
      while (m.view.getUint16(src + n * 2, true)) n++;
      n++;
    }
    if (!cb) return n;
    n = Math.min(n, cb);
    for (let k = 0; k < n; k++) m.view.setUint16(dst + k * 2, lcmapChar(m.view.getUint16(src + k * 2, true), fl), true);
    return n;
  });
  m.api(K + 'CompareStringA', 6, (lc, fl, a, na, b, nb) => {
    const sa = na === 0xFFFFFFFF ? m.cstr(a) : latin1At(a, na);
    const sb = nb === 0xFFFFFFFF ? m.cstr(b) : latin1At(b, nb);
    const x = fl & 1 ? sa.toLowerCase() : sa;
    const y = fl & 1 ? sb.toLowerCase() : sb;
    return x < y ? 1 : x > y ? 3 : 2;
  });
  m.api(K + 'CompareStringW', 6, () => 2);
  function latin1At(p, n) {
    let s = '';
    for (let k = 0; k < n; k++) s += String.fromCharCode(u8[p + k]);
    return s;
  }

  // --- files --------------------------------------------------------------------
  m.api(K + 'CreateFileA', 7, (pName, access, share, sec, disp) => {
    const path = m.cstr(pName);
    const write = (access & 0x40000000) !== 0;
    const stat = vfs.stat(path);
    if (!stat && (disp === 3 || disp === 5)) {
      // A last-resort fetch may still find it.
      if (!vfs.read(path)) {
        lastError = 2;
        return INVALID_HANDLE;
      }
    }
    if (stat && disp === 1) {
      lastError = 80;
      return INVALID_HANDLE;
    }
    const h = nextHandle++;
    const f = { path, pos: 0, write, data: null, size: 0, stat: vfs.stat(path) };
    if (disp === 2 || disp === 5 || (!stat && (disp === 1 || disp === 4))) {
      f.data = new Uint8Array(0);
      f.size = 0;
      f.dirty = true;
      if (write && disp !== 4) vfs.add(path, f.data);
    } else {
      // a packed archive opened for reading is read in pieces (vfs.js addRanged: the browser fetches byte ranges);
      // anything else whole, and its size is its bytes' (a lazy file's listed size may be another copy's)
      f.rangeRead = write ? null : vfs.ranged(path);
      f.data = f.rangeRead ? null : vfs.read(path);
      f.size = f.data ? f.data.length : vfs.stat(path).size;
      if (write) f.data = f.data.slice();
    }
    handles.set(h, f);
    lastError = 0;
    return h;
  });
  const readAt = (f, pos, n, dst) => {
    if (f.rangeRead) f.rangeRead(pos, n, u8, dst);
    else u8.set(f.data.subarray(pos, pos + n), dst);
  };
  m.api(K + 'ReadFile', 5, (h, buf, n, pRead) => {
    const f = handles.get(h);
    if (!f) {
      if (pRead) u32[pRead >> 2] = 0;
      return h >= 0x10 && h < 0x18 ? 1 : 0;
    }
    const k = Math.max(0, Math.min(n, f.size - f.pos));
    if (k) readAt(f, f.pos, k, buf);
    f.pos += k;
    if (pRead) u32[pRead >> 2] = k;
    return 1;
  });
  m.api(K + 'WriteFile', 5, (h, buf, n, pDone) => {
    const f = handles.get(h);
    if (pDone) u32[pDone >> 2] = n;
    if (!f) {
      if (host.onStdout && h >= 0x10 && h < 0x18) {
        let s = '';
        for (let k = 0; k < n; k++) s += String.fromCharCode(u8[buf + k]);
        host.onStdout(s);
      }
      return 1;
    }
    const end = f.pos + n;
    if (end > f.data.length) {
      const grown = new Uint8Array(Math.max(end, f.data.length * 2, 256));
      grown.set(f.data.subarray(0, f.size));
      f.data = grown;
    }
    f.data.set(u8.subarray(buf, buf + n), f.pos);
    f.pos = end;
    f.size = Math.max(f.size, end);
    f.dirty = true;
    return 1;
  });
  m.api(K + 'SetFilePointer', 4, (h, lo, pHi, method) => {
    const f = handles.get(h);
    if (!f) return INVALID_HANDLE;
    const d = i32[(m.esp + 8) >> 2];
    const base = method === 0 ? 0 : method === 1 ? f.pos : f.size;
    f.pos = base + d;
    if (pHi) u32[pHi >> 2] = 0;
    return f.pos;
  });
  m.api(K + 'SetEndOfFile', 1, (h) => {
    const f = handles.get(h);
    if (f) {
      f.size = f.pos;
      f.dirty = true;
    }
    return 1;
  });
  m.api(K + 'FlushFileBuffers', 1, () => 1);
  m.api(K + 'GetFileType', 1, (h) => (handles.has(h) ? 1 : 2));
  m.api(K + 'CloseHandle', 1, (h) => {
    const f = handles.get(h);
    if (f) {
      if (f.dirty) vfs.write(f.path, f.data.slice(0, f.size));
      handles.delete(h);
    }
    return 1;
  });
  m.api(K + 'GetFileAttributesA', 1, (p) => (vfs.exists(m.cstr(p)) ? 0x80 : INVALID_HANDLE));
  m.api(K + 'GetCurrentDirectoryA', 2, (n, p) => m.writeCStr(p, GAME_DIR, n));
  m.api(K + 'GetFullPathNameA', 4, (pName, n, p, pFile) => {
    const name = m.cstr(pName);
    const full = /^[a-zA-Z]:/.test(name) ? name : GAME_DIR + '\\' + name.replace(/^\.\\/, '');
    const len = m.writeCStr(p, full, n);
    if (pFile) u32[pFile >> 2] = p + full.lastIndexOf('\\') + 1;
    return len;
  });
  // C: holds the installation, D: is the CD-ROM drive NOCD names (0x4b89b0 builds its drive table from this).
  m.api(K + 'GetDriveTypeA', 1, (p) => {
    const s = (p ? m.cstr(p) : 'C:\\')[0].toUpperCase();
    return s === 'C' ? 3 : s === 'D' ? 5 : 1;
  });
  m.api(K + 'CreateDirectoryA', 2, () => 1);
  // Only with game.ini [HELPDESK] ENABLE_RRM=1 (0x4431b0 -> 0x4431e0): no other program is started.
  m.api(K + 'CreateProcessA', 10, (app, cmd, a, b, inherit, flags, env, dir, si, pi) => {
    if (pi) u8.fill(0, pi, pi + 16);
    lastError = 2;
    return 0;
  });
  const finds = new Map();
  const writeFind = (p, name, size) => {
    u8.fill(0, p, p + 320);
    u32[p >> 2] = 0x80;
    u32[(p + 32) >> 2] = size;
    m.writeCStr(p + 44, name, 260);
  };
  m.api(K + 'FindFirstFileA', 2, (pName, p) => {
    const pat = normalizePath(m.cstr(pName));
    const re = new RegExp('^' + pat.replace(/[.+^${}()|[\]\\]/g, '\\$&').replace(/\*/g, '.*').replace(/\?/g, '.') + '$');
    const list = vfs.list().filter((x) => re.test(x));
    if (!list.length) {
      lastError = 2;
      return INVALID_HANDLE;
    }
    const h = nextHandle++;
    finds.set(h, { list, at: 1 });
    writeFind(p, list[0], vfs.stat(list[0]).size);
    return h;
  });
  m.api(K + 'FindClose', 1, (h) => {
    finds.delete(h);
    return 1;
  });

  // --- INI ------------------------------------------------------------------------
  // Windows looks in its own folder for a bare file name. The game passes names it
  // builds itself, and they all live in the game folder here.
  m.api(K + 'GetPrivateProfileIntA', 4, (s, k, d, f) => {
    const v = vfs.iniGet(m.cstr(f), m.cstr(s), m.cstr(k));
    if (v === null || v === '') return d;
    const n = parseInt(v, 10);
    return Number.isNaN(n) ? 0 : n;
  });
  m.api(K + 'GetPrivateProfileStringA', 6, (s, k, d, p, n, f) => {
    const file = m.cstr(f);
    if (!s || !k) {
      const ini = vfs.parsedIni(file);
      const items = !s ? ini.sections() : ini.keys(m.cstr(s));
      let at = p;
      const end = p + n - 1;
      for (const it of items) {
        if (at + it.length + 1 >= end) break;
        at += m.writeCStr(at, it) + 1;
      }
      u8[at] = 0;
      return at - p;
    }
    let v = vfs.iniGet(file, m.cstr(s), m.cstr(k));
    if (v === null) v = d ? m.cstr(d) : '';
    else if (v.length >= 2 && ((v[0] === '"' && v[v.length - 1] === '"') || (v[0] === "'" && v[v.length - 1] === "'"))) v = v.slice(1, -1);
    if (!n) return 0;
    return m.writeCStr(p, v, n);
  });
  m.api(K + 'WritePrivateProfileStringA', 4, (s, k, v, f) => {
    vfs.iniSet(m.cstr(f), m.cstr(s), k ? m.cstr(k) : null, v ? m.cstr(v) : null);
    return 1;
  });

  // --- windows and messages ---------------------------------------------------------
  const win = { proc: 0, hwnd: 0x1000, queue: [] };
  host.win = win;
  const sendToWindow = (msg, wParam = 0, lParam = 0) => {
    if (win.proc) return m.call(win.proc, [win.hwnd, msg, wParam, lParam]);
    return 0;
  };
  host.sendToWindow = sendToWindow;
  host.postToWindow = (msg, wParam = 0, lParam = 0) => win.queue.push({ msg, wParam, lParam });
  m.api(U + 'RegisterClassA', 1, (p) => {
    win.proc = u32[(p + 4) >> 2];
    return 0xC000;
  });
  m.api(U + 'CreateWindowExA', 12, () => {
    const hwnd = win.hwnd;
    sendToWindow(0x0081, 0, 0);   // WM_NCCREATE
    sendToWindow(0x0001, 0, 0);   // WM_CREATE
    return hwnd;
  });
  m.api(U + 'ShowWindow', 2, () => {
    sendToWindow(0x001C, 1, 0);   // WM_ACTIVATEAPP
    sendToWindow(0x0006, 1, 0);   // WM_ACTIVATE
    return 0;
  });
  m.api(U + 'UpdateWindow', 1, () => 1);
  m.api(U + 'MoveWindow', 6, () => 1);
  m.api(U + 'LoadIconA', 2, () => 0x2000);
  m.api(U + 'LoadCursorA', 2, () => 0x2001);
  m.api(U + 'SetCursor', 1, () => 0);
  m.api(U + 'GetSystemMetrics', 1, (n) => (n === 0 ? host.screen.width : n === 1 ? host.screen.height : 0));
  const writeRect = (p, l, t, r, b) => {
    i32[p >> 2] = l;
    i32[(p + 4) >> 2] = t;
    i32[(p + 8) >> 2] = r;
    i32[(p + 12) >> 2] = b;
  };
  m.api(U + 'GetClientRect', 2, (h, p) => {
    writeRect(p, 0, 0, host.screen.width, host.screen.height);
    return 1;
  });
  m.api(U + 'SetRect', 5, (p, l, t, r, b) => {
    writeRect(p, l | 0, t | 0, r | 0, b | 0);
    return 1;
  });
  m.api(U + 'ClientToScreen', 2, () => 1);
  // The quit requester parks the pointer (0x473820 -> 0x4b9e40) and reads it back with GetCursorPos.
  m.api(U + 'SetCursorPos', 2, (x, y) => {
    if (host.input && host.input.setMouse) host.input.setMouse(x | 0, y | 0);
    return 1;
  });
  let cursorCount = 0;
  m.api(U + 'ShowCursor', 1, (show) => (show ? ++cursorCount : --cursorCount));
  m.api(U + 'PtInRect', 3, (p, x, y) => {
    x |= 0;
    y |= 0;
    return x >= i32[p >> 2] && x < i32[(p + 8) >> 2] && y >= i32[(p + 4) >> 2] && y < i32[(p + 12) >> 2] ? 1 : 0;
  });
  m.api(U + 'InflateRect', 3, (p, dx, dy) => {
    i32[p >> 2] -= dx | 0; i32[(p + 4) >> 2] -= dy | 0; i32[(p + 8) >> 2] += dx | 0; i32[(p + 12) >> 2] += dy | 0;
    return 1;
  });
  m.api(U + 'OffsetRect', 3, (p, dx, dy) => {
    i32[p >> 2] += dx | 0; i32[(p + 4) >> 2] += dy | 0; i32[(p + 8) >> 2] += dx | 0; i32[(p + 12) >> 2] += dy | 0;
    return 1;
  });
  m.api(U + 'GetFocus', 0, () => win.hwnd);
  m.api(U + 'SetFocus', 1, () => win.hwnd);
  m.api(U + 'ChildWindowFromPoint', 3, () => win.hwnd);
  // 0x442fa0 hooks the keyboard to swallow the Windows and menu keys (callback 0x442f40). The page never
  // passes those keys to the game, so the hook is never called.
  m.api(U + 'SetWindowsHookExA', 4, () => 0x3000);
  m.api(U + 'CallNextHookEx', 4, () => 0);
  m.api(U + 'ScreenToClient', 2, () => 1);
  m.api(U + 'GetCursorPos', 1, (p) => {
    i32[p >> 2] = host.input ? host.input.mouseX : 0;
    i32[(p + 4) >> 2] = host.input ? host.input.mouseY : 0;
    return 1;
  });
  // The race's only keyboard path (0x4b3830, 0x4b3880). VK 1, 2 and 4 are the mouse buttons (the requester,
  // 0x4b9ea0). In the game worker host.input reads shared memory, so a wait inside one call sees keys change.
  m.api(U + 'GetAsyncKeyState', 1, (vk) => {
    clock.poll();
    const input = host.input;
    if (!input) return 0;
    vk &= 0xFF;
    if (vk === 1 || vk === 2 || vk === 4) return input.mouseButtons & (vk === 4 ? 4 : vk) ? 0x8000 : 0;
    return input.keyDown(vk) ? 0x8000 : 0;
  });
  m.api(U + 'PeekMessageA', 5, (p, hwnd, lo, hi, flags) => {
    if (!win.queue.length) return 0;
    const e = flags & 1 ? win.queue.shift() : win.queue[0];
    u32[p >> 2] = win.hwnd;
    u32[(p + 4) >> 2] = e.msg;
    u32[(p + 8) >> 2] = e.wParam;
    u32[(p + 12) >> 2] = e.lParam;
    u32[(p + 16) >> 2] = msNow();
    u32[(p + 20) >> 2] = 0;
    u32[(p + 24) >> 2] = 0;
    return 1;
  });
  m.api(U + 'TranslateMessage', 1, () => 0);
  m.api(U + 'DispatchMessageA', 1, (p) => sendToWindow(u32[(p + 4) >> 2], u32[(p + 8) >> 2], u32[(p + 12) >> 2]));
  m.api(U + 'PostMessageA', 4, (h, msg, w, l) => {
    win.queue.push({ msg, wParam: w, lParam: l });
    return 1;
  });
  m.api(U + 'PostQuitMessage', 1, (code) => {
    win.queue.push({ msg: 0x12, wParam: code, lParam: 0 });
    return 0;
  });
  m.api(U + 'DefWindowProcA', 4, (h, msg) => {
    if (msg === 0x10) sendToWindow(0x0002);   // WM_CLOSE destroys the window: WM_DESTROY
    return 0;
  });
  m.api(U + 'WaitMessage', 0, () => 1);
  m.api(U + 'BeginPaint', 2, () => 0);
  m.api(U + 'EndPaint', 2, () => 1);
  m.api(U + 'GetUpdateRect', 3, () => 0);
  m.api(U + 'KillTimer', 2, () => 1);
  m.api(U + 'MessageBeep', 1, () => 1);
  m.api(U + 'MessageBoxExA', 5, (h, text, caption) => {
    host.onMessageBox(m.cstr(caption), m.cstr(text));
    return 1;
  });
  m.bindRaw(U + 'wsprintfA', 0, (esp) => {
    const dst = u32[(esp + 4) >> 2];
    const fmt = m.cstr(u32[(esp + 8) >> 2]);
    let ap = esp + 12;
    const s = fmt.replace(/%(-?0?\d*)(l?)([sdxXuc%])/g, (all, w, l, t) => {
      if (t === '%') return '%';
      const v = u32[ap >> 2];
      ap += 4;
      let r;
      if (t === 's') r = m.cstr(v);
      else if (t === 'd') r = String(v | 0);
      else if (t === 'u') r = String(v);
      else if (t === 'x') r = v.toString(16);
      else if (t === 'X') r = v.toString(16).toUpperCase();
      else r = String.fromCharCode(v & 0xFF);
      const wn = parseInt(w, 10);
      if (wn) r = w[0] === '-' ? r.padEnd(wn) : r.padStart(wn, w[0] === '0' ? '0' : ' ');
      return r;
    });
    return m.writeCStr(dst, s);
  });
  m.api(K + 'lstrlenA', 1, (p) => (p ? m.cstr(p).length : 0));

  // --- GDI: only used for debug text on a surface DC ----------------------------
  m.api(G + 'SetTextColor', 2, () => 0);
  m.api(G + 'SetBkColor', 2, () => 0);
  m.api(G + 'SetBkMode', 2, () => 1);
  m.api(G + 'ExtTextOutA', 8, () => 1);
  m.api(G + 'TextOutA', 5, () => 1);
  m.api(G + 'SelectObject', 2, () => 0);
  m.api(G + 'GetTextExtentPoint32A', 4, (hdc, s, n, p) => {
    i32[p >> 2] = n * 8;
    i32[(p + 4) >> 2] = 16;
    return 1;
  });

  // --- the volume mixer: no devices. Volumes are the port's own settings. ------------
  m.api(W + 'mixerGetNumDevs', 0, () => 0);
  m.api(W + 'mixerOpen', 5, () => 1);
  m.api(W + 'mixerClose', 1, () => 0);
  m.api(W + 'mixerGetLineInfoA', 3, () => 1);
  m.api(W + 'mixerGetLineControlsA', 3, () => 1);
  m.api(W + 'mixerGetControlDetailsA', 3, () => 1);
  m.api(W + 'mixerSetControlDetails', 3, () => 1);

  return { heap, win, sendToWindow };
}
