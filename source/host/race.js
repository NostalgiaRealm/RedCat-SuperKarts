// One run of rcskspel.dat. The original launcher starts the race as a new process for every race, and so does
// this: a new Race is a new wasm instance. WinMain 0x4432a0 is replaced (tools/recomp/build.py, GAME_HOOKS):
// its loop busy-waits on GetTickCount and would block the page, so tick() is one pass of that loop and the
// host decides when it runs. Pattern: the A2 Racer 4 host (source/host/race.js there).
import { Machine, GameExit } from './machine.js';
import { installWin32, VirtualClock } from './win32.js';
import { installDirectX } from './directx.js';
import { installDinput } from './dinput.js';
import { installDsound } from './dsound.js';
import { installWinmm } from './winmm.js';
import { installDshow } from './dshow.js';
import { installEh, CppException } from './eh.js';
import { installSafeguards } from './safeguards.js';
import { installShadows } from './shadows.js';
import { installRenderReplay } from './render-replay.js';
import { FreeFlight } from './free-flight.js';

class BootDone extends Error {}

// WinMain 0x4432a0, in the order it calls them (functions/004432a0_FUN_004432a0.c of the export).
export const FN = {
  INIT_MAIN: 0x00442fc0,        // init_main(hInstance, nCmdShow), cdecl
  START_GAME: 0x0042f930,       // srand(GetTickCount()), overlay.ini, phase 1, RUNNING = 1
  HANDLE_GAME: 0x0042f4c0,      // one frame: timer 0x48f3e0, input, objects, AI, cameras, sound, render, present
  SCREEN_SWITCH: 0x00473460,    // returns the screen-switch object ...
  SCREEN_SWITCH_CHECK: 0x00473550, // ... whose crash-recovery check runs on it (thiscall)
  FRAME_COUNT: 0x00430cd0,
  PUMP: 0x00442e80,             // my_handle_win_msg: non-zero on WM_QUIT
  KEY_DOWN: 0x004b3830,         // GetAsyncKeyState wrapper with the Shift rule
  FATAL: 0x004afee0,             // (WinMain's Ctrl+Q check calls it; left out, see tick)
  SCREENSHOT: 0x00443460,        // (WinMain's Backspace check; left out, see tick)
  EXIT_MAIN: 0x00443150,
  RESOLUTION_OBJ: 0x00477f10,
  RESOLUTION_SAVE: 0x00478000,  // thiscall: writes game.ini [program] resolution when it changed
};
export const DATA = {
  DEVICE: 0x0053a5d8,           // input device of the driving handler 0x4325b0: 1 keyboard ramps, 3 analog joystick 0x4341d0
  RUNNING: 0x0053b9bc,          // the loop's condition; only 0x42f740(4) clears it
  PAUSE_KIND: 0x0053b9f8,       // 1 = P, 2 = Esc (0x42f9c0)
  CLOCK: 0x0067ec70,            // +0 has QPC, +4 frequency, +8 time, +0xC dt (0x48f3e0)
};

export class Race {
  /** host: { vfs, render, audio, music, input, joystick, screen, tickSeconds, clockStart, onMessageBox, onStdout, log } */
  constructor(meta, host) {
    this.meta = meta;
    this.host = host;
    this.m = new Machine(meta);
    this.clock = new VirtualClock();
    host.clock = this.clock;
    host.log = host.log || (() => {});
    this.ended = false;
    this.exitCode = null;
    this.tickSeconds = host.tickSeconds || 0.025;
    this.ticks = 0;
    // GetTickCount seeds rand (0x42f930): start the clock at a varying offset. Tests pass a fixed one.
    this.clock.seconds = host.clockStart ?? (Date.now() % 100000) / 1000 + 1;
  }

  async instantiate(wasm, codeMap) {
    const { m, host } = this;
    await m.instantiate(wasm, codeMap);
    host.raiseException = () => { throw new Error('RaiseException before eh.js was installed'); };
    host.rtlUnwind = () => 0;
    installWin32(m, host);
    installDirectX(m, host);
    installDinput(m, host);
    installDsound(m, host);
    installWinmm(m, host);
    installDshow(m, host);
    installEh(m, host);
    // The JS reconstruction's safeguards around the original code: stuck recovery, the NPC velocity guard, the debug
    // and cheat keys behind the cheats option (source/host/safeguards.js); beforePass() in tick()
    this.safeguards = installSafeguards(m, host);
    m.bindRaw('hook!WinMain', 16, (esp) => {
      // WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow): init_main gets the first and the last
      this.winMain = [m.u32[(esp + 4) >> 2], m.u32[(esp + 16) >> 2]];
      throw new BootDone();
    });
    // The HUD pass (0x467d30, called at 0x43031e with ecx 0x53a5f8; it draws through 0x4614d0) is behind the
    // exception guard eh.js made for it: wrapped, so the renderer knows which draws are the HUD's.
    const hudId = m.thunkId('hook!eh_00467d30');
    const hudPass = m.thunks[hudId];
    m.thunks[hudId] = (esp, ecx, edx, eax) => {
      const r = host.render;
      if (r) r.hud = true;
      try { return hudPass(esp, ecx, edx, eax); } finally { if (r) r.hud = false; }
    };
    // The HUD's draw call (m_Manager.Render 0x4614d0, called from the HUD pass at 0x467dcb, after its update
    // 0x468d30), also behind a guard: on a screen of another shape than 4:3 the HUD's groups are moved to its
    // edges around it and sized as the JS reconstruction's HUD, inside the safe area (L.insets, fractions of the
    // drawing) and above the touch band (L.controls), and put back after it (source/host/hud-layout.js), so no game
    // code but the draw sees them; each group's draws are cut to its frame through L.clip (the recorder's hudClip).
    const renderId = m.thunkId('hook!eh_004614d0');
    const hudRender = m.thunks[renderId];
    m.thunks[renderId] = (esp, ecx, edx, eax) => {
      const L = host.hudLayout;
      const i = L && L.insets;
      const c = L && L.controls;
      if (!L || (L.xr === 1 && L.yr === 0.75 && (L.scale || 1) === 1 && !(i && (i.left || i.right || i.top || i.bottom)) && !(c && (c.left || c.right)))) {
        return hudRender(esp, ecx, edx, eax);
      }
      L.layout.apply(L.xr, L.yr, L);         // L: { layout, xr, yr, scale, insets, controls }
      try { return hudRender(esp, ecx, edx, eax); } finally { L.layout.restore(); }
    };
    // Kart shadows on the ground and engine flares that follow their kart (the JS reconstruction's two race visuals;
    // the shadow callback 0x4260c0 wrapped, the recorder's tagger): source/host/shadows.js
    installShadows(m, host);
    // The renders that no object pass precedes, the pause entry's and free flight's: the render 0x430020 wrapped, the
    // kart parts (wheels, driver) and the pause picture's aging draws put back (source/host/render-replay.js)
    this.renderReplay = installRenderReplay(m, host);
    // Free flight (the JS reconstruction's Vrij vliegen): its pass in place of HANDLE_GAME, see tick() and
    // source/host/free-flight.js; it also masks GetAsyncKeyState while it flies
    this.flight = new FreeFlight(this);
    if (host.installHooks) host.installHooks(m, this);
    this.unbound = Object.values(this.meta.thunks).filter((n) => !m.bound.has(n));
    return this;
  }

  /** CRT start-up, then the part of WinMain before its loop: init_main and start_game. Loads the race. */
  boot() {
    const { m } = this;
    try {
      m.__call(this.meta.entry, m.layout.STACK_TOP - 64, 0, 0, 0);
    } catch (e) {
      if (!(e instanceof BootDone)) throw e;
    }
    // The C runtime's frame is gone with its stack: its SEH node must not stay in the chain at fs:[0].
    m.u32[m.layout.TIB_BASE >> 2] = 0xFFFFFFFF;
    m.esp = m.layout.STACK_TOP - 0x100;
    this.guard(() => {
      m.call(FN.INIT_MAIN, this.winMain);
      m.call(FN.START_GAME);
    });
    m.esp = m.layout.STACK_TOP - 0x100;
  }

  /** Runs original code; a C++ exception nobody catches ends the race as WinMain's catch blocks do. */
  guard(fn) {
    try {
      fn();
    } catch (e) {
      if (e instanceof CppException) {
        this.host.log('uncaught C++ exception ' + e.typeName);
        throw e;
      }
      throw e;
    }
  }

  /** One pass of WinMain's loop, after its 25 ms gate. dt is game time in seconds. */
  tick(dt = this.tickSeconds) {
    const { m } = this;
    if (this.ended) return false;
    try {
      this.clock.advance(dt);
      if (!m.u32[DATA.RUNNING >> 2]) return this.finish();
      if (this.host.beforeTick) this.host.beforeTick(this);
      this.safeguards.beforePass();
      // free flight takes off, lands, or runs its own pass instead of the frame (source/host/free-flight.js)
      if (!this.flight.step(dt)) m.call(FN.HANDLE_GAME);
      const sw = m.call(FN.SCREEN_SWITCH);
      m.call(FN.SCREEN_SWITCH_CHECK, [], sw);
      m.call(FN.FRAME_COUNT);
      if (m.call(FN.PUMP) !== 0) return this.finish();
      // WinMain's own two key checks end its loop pass: Ctrl+Q calls the fatal "Emergency exit" (0x4afee0 with
      // 0x4edf64, 0x4edf44, line 0x1a5) and Backspace saves a screenshot (0x443460). Both are left out on purpose
      // (decided 2026-11-25, docs/intentional-differences.md): in a browser Ctrl+Q is a common shortcut and a
      // fatal error ends the race without results, and the screenshot would write a file nobody can reach. The
      // race's other cheats and debug keys (D, numpad 7-9, Ctrl+F+I, Ctrl+E+N, the tweak keys) answer only with the
      // cheats option (OPT.CHEATS; source/host/safeguards.js), as the JS reconstruction has none of them.
      this.ticks++;
    } catch (e) {
      if (e instanceof GameExit) {
        this.ended = true;
        this.exitCode = e.code;
        return false;
      }
      throw e;
    }
    return true;
  }

  /** The end of WinMain: exit_main, the resolution save, no RRM. Exit code 0 as WinMain returns. */
  finish() {
    const { m } = this;
    this.ended = true;
    // a race that ends while flying (the quit requester's J) ends where the kart took off
    if (this.flight && this.flight.active) this.flight.land({ neutralize: false });
    try {
      m.call(FN.EXIT_MAIN);
      const r = m.call(FN.RESOLUTION_OBJ);
      m.call(FN.RESOLUTION_SAVE, [], r);
      this.exitCode = 0;
    } catch (e) {
      if (!(e instanceof GameExit)) throw e;
      this.exitCode = e.code;
    }
    return false;
  }
}
