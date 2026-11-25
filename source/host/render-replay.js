// The renders that no object pass precedes, the pause entry's and free flight's: the render 0x430020 changes state in
// place, and a render without the object pass before it would otherwise draw on from what the render before left.
//
// Kart parts (confirmed in the export). Each kart's engine slot (table u32 0x67ee20, 0xd0 a slot) lists its part render
// objects at +0x64.. with their count at +0x8c (five for every kart, four wheels and the driver; measured on Nederland
// and Frankrijk: the five racer slots, their objects body + 1 .. body + 5). The object pass 0x491530 calls each slot's
// callback (+0x54: 0x4325b0 the player's, 0x40b0b0 an NPC's), which sets every part's matrix (render object +0x10, 0xa9
// an object at u32 0x6a5c38) relative to the body; the racer draw 0x490d40 (0x430020 -> 0x491670 -> 0x4918f0/
// 0x4916f0) multiplies each by the body's matrix in place before it draws the part (0x4a2560 into a local, copied back
// over +0x10; functions/00490d40 lines 122-146). Between two passes a part therefore holds its world matrix, and a render
// with no object pass before it draws the parts at body * body * relative: about 7,300 units off on Nederland's grid,
// out of sight, so every kart showed without wheels and driver in the pause and in free flight.
//
// Two renders run without one. HANDLE_GAME's pause entry (0x42f703, return 0x42f708): the JS port's intentional
// departure leaves out its object pass (tools/recomp/build.py GAME_PATCHES 0x42f6d8), and that second render is the
// only one that draws the "pauze" notice. And free flight's pass (source/host/free-flight.js), which calls the render
// itself (m.call: return address 0) with no object pass at all. The render is a wrap hook (build.py GAME_HOOKS
// 'Render'). Around every render this module notes, for each kart the render drew (its part matrices changed), what
// the render found (the body-relative matrices) and what it left (the world ones). Before a render that no object pass
// precedes, every kart whose parts still hold what the last render left gets back what that render found, so the draw
// puts the parts on the body as the render before did: the kart is drawn whole, as the JS reconstruction draws every
// visible kart's whole visual at its body's pose, in its pause and in flight (driving-view.js:242-254). A kart whose
// parts anything else has written since is not touched; HANDLE_GAME's own render (return 0x42f668, after the object
// pass) is only noted, so a racing pass runs as the original.
//
// The pause entry's picture is the pass's own picture with the notice. The JS port pauses on the frame it drew and
// captures only the notice into its HUD (driving-view.js:394-395, hud.notify(1, 0, { capture: true })); here the pause
// entry's render runs the game's draw code again, and these draws age what they draw (measured: the P pass's two
// renders against each other, draw by draw, six pauses on each of the six tracks, 2026-11-25), so each is put back as
// the pass's own render found it, when it still holds what that render left:
//  - the kart's lit colour, slot +0x34: 0x4903c0 eases it towards the light under the kart (dt * (|+0xa4| * 0.1 + 1) a
//    draw) and writes it into the mesh's vertex colours;
//  - the skid marks 0x426e50 -> 0x426db0: 0x14 marks of 0x1910 bytes from 0x50dfb0, an age (+0x190c) counted per draw,
//    fading (0x426c50) or ending (0x426b90) with it;
//  - the smoke clouds 0x428a00 ("gfx_wolk"): 0x46 of 300 bytes from 0x535020, sorted in place (0x4bf5b9), moved by a
//    velocity that 0x4282e0 scales by 0.9, and a frame count (+0x11c) per draw that ends them at +0x118;
//  - the jet streams 0x48a530 -> 0x48a170 -> 0x489f50: the container at u32 0x67da6c (+4 a vector of 0x120-byte streams),
//    each stream's vertex vector (stream +4: +4 begin, +8 end, +0xc capacity; 0x20 a vertex), narrowed by 0.7 a draw
//    and cut (0x48b1d0, an erase that frees nothing) below 0.5 units;
//  - and the HUD stands still: the HUD pass 0x467d30 sees free flight's still frame time (free-flight.js HUD_STILL_DT),
//    so its slides and fades do not move on a frame; the notice, which 0x430610(1) made with its first frame after the
//    pass's own render, is drawn as free flight's pause draws it.
// What the pass changes between its two renders stays (the bonus boxes turn in 0x451200, called at 0x42f686: about 6.6
// degrees on Nederland; a moving scenery object moved 4.4 units in one measured pause). Free flight's pause render is
// a pause render too (again(), free-flight.js), so the flight pause shows the flight picture with the notice; its other
// renders get back only the kart parts: the effects age as the original's renders age them, and the opponents' colour
// eases as the JS port's captureColor does in flight (driving-view.js:262-267; the flying kart's own is free-flight.js's).
//
// The held picture drawn again (repaint(), from source/web/worker.js): when the drawing changes shape (a phone turned, a
// window resized) while the game waits in its pause loop 0x42f220 or the page holds the race between two passes, the
// render worker can only draw the last frame again, whose HUD the game laid out for the old shape (hud-layout.js works
// on the HUD's draw, 0x4614d0). The JS port lays its HUD out again for every picture (race-hud.js render ->
// RaceHudLayoutCache.get, applyLayout). repaint() runs the render 0x430020 as a pause render, so it draws the picture
// the game holds (every kart whole, the aging draws as the last render that was not a pause render found them, the HUD
// still), with the HUD laid out for the new shape, and the present 0x430470 sends it. The colours and effects that a
// pause render puts back are kept over pause renders, so a second and third pause render draw the same picture.
//
// Why a render from inside the pause loop is safe (it runs inside the GetAsyncKeyState import that 0x42f220 polls
// through 0x4b3830, as a window procedure runs inside PeekMessage on Windows; source/host/machine.js call()): the call
// frame lies 256 bytes below the import's esp, so the frames of 0x42f4c0, 0x42f350, 0x42f220 and 0x4b3830 above stay as
// they are; the render saves and restores ebx, esi, edi and ebp (they travel in the module's globals, docs/recompiler.md)
// and leaves the x87 stack as it found it, as every function the compiler made does; it installs its own SEH frames
// on fs:[0] and takes them down. What the pause holds is not touched by a render: 0x42f220 keeps only its loop counter
// and "seen" flag (in registers and its frame), 0x42f350 the timer list on its stack (the 22 timers it paused through
// 0x42a2f0, which the HUD reads as their pause stamps, the time the pass's own pictures showed), and the pause kind
// 0x53b9f8. The render is the pause entry's (0x42f703, which the original runs in the same pass after 0x42f9c0 set the
// kind) with the same frame time 0x67ec7c (0x48f520 resets it only after the loop). tools/checks/pause-repaint.mjs
// measures it: a repaint from inside the loop draws the pause entry's picture again, and the passes after the pause are
// draw for draw those of the same race without it.
//
// notice(on): the original's "pauze" notice over a held result screen (the finish 0x41fd90, phase 3, and game over
// 0x420850, phase 6, where 0x42f9c0 takes no P), shown as the JS port shows "pauze" when its race is suspended there
// (driving-view.js:388-395, hud.notify(1, 0, { capture: true })) and removed after (driving-view.js:409, notify(2)).
// It is the game's own event 0x430610: (1) is 0x469000 on the overlay 0x53a5f8, which shows text 6 at once through
// 0x46c180 (no time limit), (2) is 0x4690e0 -> 0x46cc70, which stops the special text and shows the next queued one.
// Only while the special text (overlay +0x94) is idle (its state +8 not 1, so nothing is queued: 0x46c1e0 queues only
// behind a running text): then (1) and (2) leave it idle again. Over a running text 0x46c180 calls 0x46cfb0 first,
// which keeps a timed text (+0x68 elapsed below +0x64 duration) at the front of the queue and drops an untimed one, so
// the race's own notice would come back with its animation started again, or not at all: game over in a Tijdrace keeps
// "tijd is om!" (0x420730 -> 0x430610(7), no time limit) the whole screen. There the hold stays without "pauze".
// tools/checks/pause-repaint.mjs measures that (1), a repaint and (2) on an idle finish screen leave the passes after
// it draw for draw as without them.
export const ADDR = {
  RENDER: 0x00430020,
  PRESENT: 0x00430470,
  NOTICE: 0x00430610,         // the HUD events (cdecl, one argument): 1 "pauze" on, 2 the special text off
  OVERLAY: 0x0053a5f8,        // CRedCatOverlay: +0x94 the special text (0x469110), whose +8 is 1 while a text shows
  SLOTS: 0x0067ee20,          // engine slots, 0xd0 each: +0x0c render object, +0x34 lit colour, +0x44 in use, +0x64.. parts, +0x8c their count
  SLOT_CAPACITY: 0x0067ee24,  // the T_ARRAY's size (5000); 0x491530/0x4918f0 run to the last slot whose used byte is 1
  SLOT_USED: 0x0067ee30,      // u32 -> one byte per slot
  OBJECTS: 0x006a5c38,        // render objects, 0xa9 each (unaligned): +0x10 the 4x4 (rows right, up, forward, place)
  DT: 0x0067ec7c,             // the frame clock's dt (0x67ec70 + 0xc, 0x48f3e0; 0x48f4e0 hands it out)
  SKIDS: 0x0050dfb0, SKIDS_SIZE: 0x14 * 0x1910,
  SMOKE: 0x00535020, SMOKE_SIZE: 0x46 * 300,
  JETS: 0x0067da6c,           // u32 -> the jet stream container (0x48a480)
};
export const RET = {
  RACING: 0x0042f668,         // after CALL 0x430020 at 0x42f663: HANDLE_GAME's render, the object pass before it
  PAUSE_ENTRY: 0x0042f708,    // after CALL 0x430020 at 0x42f703: the pause entry's (GAME_PATCHES 0x42f6d8)
};
const HUD_STILL_DT = Math.fround(1e-30);   // free-flight.js HUD_STILL_DT
const MAX_PARTS = 10;                       // +0x64 + 4 * 10 = +0x8c, the count: the room a slot has
const MAX_JET_BYTES = 0x20 * 4096;          // a stream's vertices read at most (a probe saw 10)
// a drawn part's world place lies within its kart (30.1 units from the body at most, six tracks): further off is
// a part drawn on a second body matrix
export const PART_OFF = 60;

/**
 * Pieces of memory a render may change: ranges [address, length]. snap() copies them; holds(b) compares them with a
 * copy; put(b) writes a copy back.
 */
class Piece {
  constructor(u8, ranges) { this.u8 = u8; this.ranges = ranges; this.size = ranges.reduce((s, r) => s + r[1], 0); }
  snap() { const b = new Uint8Array(this.size); let o = 0; for (const [a, n] of this.ranges) { b.set(this.u8.subarray(a, a + n), o); o += n; } return b; }
  holds(b) {
    let o = 0;
    for (const [a, n] of this.ranges) {
      const cur = this.u8.subarray(a, a + n);
      if (!((a | n | o) & 3)) {
        // whole words (the skid and smoke arrays): four bytes a compare
        const x = new Uint32Array(cur.buffer, a, n >> 2), y = new Uint32Array(b.buffer, b.byteOffset + o, n >> 2);
        for (let k = 0; k < x.length; k++) if (x[k] !== y[k]) return false;
      } else for (let k = 0; k < n; k++) if (cur[k] !== b[o + k]) return false;
      o += n;
    }
    return true;
  }
  put(b) { let o = 0; for (const [a, n] of this.ranges) { this.u8.set(b.subarray(o, o + n), a); o += n; } }
}

/**
 * Installs the wrapper of the render on a Race's machine (race.js instantiate). Returns { karts(), stats, again(fn),
 * held(), repaint(), notice(on), renderUs() }: the karts' slots and part matrices' addresses, the counts, again(fn), which
 * runs fn's render as a pause render, held() (the last render was a pause render: the pause picture is on the screen),
 * renderUs() (the clock as the last other render began: source/web/worker.js still() draws a held picture at it), repaint()
 * (the held picture again, see the header) and notice(on) (the "pauze" notice over a held result screen: true when shown).
 */
export function installRenderReplay(m, host) {
  const { u8, u32, i32 } = m;
  const v = m.view;
  const stats = { renders: 0, kartsRestored: 0, effectsRestored: 0, effectsSkipped: 0, effectsDiffer: 0, displaced: 0, lastDisplaced: 0, maxOff: 0, pauseEntries: 0, repaints: 0, notices: 0 };
  /** slot index -> { piece (part matrices), found, left } of the last render that drew the kart */
  const drawn = new Map();
  /** the last render's but a pause render's: [{ piece, found, left }] of the colours and effects it may change */
  let effects = [];

  /** The slots with parts (the karts): slot index and address, body and part matrices' addresses. */
  const karts = () => {
    const table = u32[ADDR.SLOTS >> 2], objs = u32[ADDR.OBJECTS >> 2], used = u32[ADDR.SLOT_USED >> 2];
    const out = [];
    if (!table || !objs || !used) return out;
    let last = i32[ADDR.SLOT_CAPACITY >> 2] - 1;
    while (last >= 0 && u8[used + last] !== 1) last--;
    for (let i = 0; i <= last; i++) {
      const slot = table + i * 0xd0;
      const n = v.getInt32(slot + 0x8c, true);
      if (n <= 0 || n > MAX_PARTS || !u8[used + i] || !v.getInt32(slot + 0x44, true)) continue;
      const parts = [];
      for (let k = 0; k < n; k++) parts.push(objs + v.getInt32(slot + 0x64 + 4 * k, true) * 0xa9 + 0x10);
      out.push({ i, slot, body: objs + v.getInt32(slot + 0xc, true) * 0xa9 + 0x10, parts });
    }
    return out;
  };
  /** The jet streams' vertex vectors: per stream its header's begin, end and capacity, and its vertices. */
  const jets = () => {
    const c = u32[ADDR.JETS >> 2];
    if (!c) return [];
    const vec = u32[(c + 4) >> 2];
    if (!vec) return [];
    const out = [];
    for (let s = u32[(vec + 4) >> 2], end = u32[(vec + 8) >> 2]; s && s < end && out.length < 64; s += 0x120) {
      const h = u32[(s + 4) >> 2];
      if (!h) continue;
      const b = u32[(h + 4) >> 2], e = u32[(h + 8) >> 2];
      if (!b || e < b || e - b > MAX_JET_BYTES) continue;
      out.push(new Piece(u8, e > b ? [[h + 4, 12], [b, e - b]] : [[h + 4, 12]]));
    }
    return out;
  };
  /** A drawn kart's parts against its body: the farthest part's world place from the body's. */
  const off = (k) => {
    const b = [0, 4, 8].map((o) => v.getFloat32(k.body + 0x30 + o, true));
    let worst = 0;
    for (const p of k.parts) worst = Math.max(worst, Math.hypot(...[0, 4, 8].map((o, j) => v.getFloat32(p + 0x30 + o, true) - b[j])));
    return worst;
  };

  /** The special text (overlay +0x94, 0x469110) shows nothing and has nothing queued: state +8 is not 1. */
  const textIdle = () => {
    const t = v.getUint32(ADDR.OVERLAY + 0x94, true);
    return t !== 0 && v.getInt32(t + 8, true) !== 1;
  };
  let noticeOn = false;
  /** notice(true) shows "pauze" when the special text is idle (returns whether it shows); notice(false) takes it off. */
  const notice = (on) => {
    if (!on) { if (noticeOn) { noticeOn = false; m.call(ADDR.NOTICE, [2]); } return false; }
    if (noticeOn) return true;
    if (!textIdle()) return false;
    m.call(ADDR.NOTICE, [1]);
    noticeOn = true;
    stats.notices++;
    return true;
  };

  const hook = m.meta.hooks && m.meta.hooks.Render;
  if (!(hook && hook.kind === 'wrap' && hook.addr === ADDR.RENDER)) {
    if (host.log) host.log('render replay: no Render wrap hook in this build, the pause entry and free flight draw karts without parts');
    // no pause render without the hook: the held picture is not drawn again (its karts would lose their parts)
    return { karts, stats, again: (fn) => fn(), held: () => false, repaint: () => false, notice: () => false, renderUs: () => 0 };
  }
  let hudStill = false;
  const hudId = m.thunkId('hook!eh_00467d30');
  const hudPass = m.thunks[hudId];
  m.thunks[hudId] = (esp, ecx, edx, eax) => {
    if (!hudStill) return hudPass(esp, ecx, edx, eax);
    const dt = m.f32[ADDR.DT >> 2];
    m.f32[ADDR.DT >> 2] = HUD_STILL_DT;
    try { return hudPass(esp, ecx, edx, eax); } finally { m.f32[ADDR.DT >> 2] = dt; }
  };

  let again = false;          // set by again(fn): free flight's pause render, a repaint
  let lastPause = false;      // the last render was a pause render
  let renderUs = 0;           // the clock (host.clock.us) as the last render that was not a pause render began
  m.wrap('Render', (esp, ecx, edx, eax, next) => {
    const ret = u32[esp >> 2];
    const racing = ret === RET.RACING, pause = ret === RET.PAUSE_ENTRY || again;
    if (!pause && host.clock) renderUs = host.clock.us;
    const list = karts();
    if (!racing) {
      // the parts of every kart that holds what the last render left, as that render found them
      for (const k of list) {
        const d = drawn.get(k.i);
        if (d && d.piece.ranges.every(([a], j) => a === k.parts[j]) && d.piece.holds(d.left)) { d.piece.put(d.found); stats.kartsRestored++; }
      }
    }
    const replayed = [];
    if (pause) {
      stats.pauseEntries++;
      for (const e of effects) {
        if (e.piece.holds(e.left)) { e.piece.put(e.found); replayed.push(e); stats.effectsRestored++; } else stats.effectsSkipped++;
      }
    }
    const before = list.map((k) => { const piece = new Piece(u8, k.parts.map((p) => [p, 64])); return { k, piece, found: piece.snap() }; });
    // the colours and effects of a render a pause render may follow: HANDLE_GAME's own, and free flight's
    const fx = pause ? null : [...list.map((k) => new Piece(u8, [[k.slot + 0x34, 4]])), new Piece(u8, [[ADDR.SKIDS, ADDR.SKIDS_SIZE]]),
      new Piece(u8, [[ADDR.SMOKE, ADDR.SMOKE_SIZE]]), ...jets()].map((piece) => ({ piece, found: piece.snap() }));
    hudStill = pause;
    let r;
    try { r = next(esp, ecx, edx, eax); } finally { hudStill = false; }
    stats.renders++;
    let displaced = 0;
    for (const { k, piece, found } of before) {
      if (piece.holds(found)) continue;       // not drawn in this render (out of the visible chunks)
      drawn.set(k.i, { piece, found, left: piece.snap() });
      const d = off(k);
      stats.maxOff = Math.max(stats.maxOff, d);
      if (d > PART_OFF) displaced++;
    }
    stats.lastDisplaced = displaced;
    stats.displaced += displaced;
    // the draw code is a function of what it found: the pause render leaves what the render before left (counted when
    // not: then the pause picture's effects differ from that render's)
    for (const e of replayed) if (!e.piece.holds(e.left)) stats.effectsDiffer++;
    // copies only (memcpy): whether the render changed a piece is seen at a pause render, which is rare. A pause render
    // keeps the last other render's, so the next pause render (a repaint) finds them again
    if (fx) effects = fx.map((e) => ({ ...e, left: e.piece.snap() }));
    lastPause = pause;
    return r;
  });
  /** Runs fn (free flight's pause render, m.call of 0x430020) as a pause entry's render: free-flight.js. */
  const renderAgain = (fn) => { again = true; try { return fn(); } finally { again = false; } };
  /** The held picture again: the render as a pause render, then the present (the header's "held picture"). */
  const repaint = () => {
    renderAgain(() => m.call(ADDR.RENDER));
    m.call(ADDR.PRESENT);
    stats.repaints++;
    return true;
  };
  host.renderReplay = stats;
  return { karts, stats, again: renderAgain, held: () => lastPause, repaint, notice, renderUs: () => renderUs };
}
