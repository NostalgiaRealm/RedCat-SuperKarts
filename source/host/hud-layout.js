// Places the HUD's groups on a screen of any shape as the JS reconstruction does (its source/race-hud-layout.js,
// raceHudLayout :5-36, applied per group in race-hud-meshes.js:251-273 and per string in hud-text-renderer.js:126):
// every group is the whole 640x480 HUD drawn at one scale into a 640x480 frame placed at an edge or the centre of
// the screen, inside the safe area and above the touch controls. The game keeps its 640x480 HUD: around the HUD's
// draw call, m_Manager.Render 0x4614d0 (called from the HUD pass 0x467d30 at 0x467dcb, after the update 0x468d30),
// the fields of whole groups are changed in game memory and put back afterwards, so no game code but the draw sees
// them. Evidence: tools/checks/hud-scale-check.mjs (every draw against the JS port's own raceHudLayout),
// hud-layout-check.mjs (shapes), hud-scale-levers.mjs (which fields scale a group), hud-shots.mjs (screenshots of
// both ports); outputs in evidence/checks/ and evidence/frames/hud/.
//
// Layout of the HUD in rcskspel.dat (the same Davilex Hud_* classes as A2 Racer 4):
//   m_Manager (CRedCatOverlay) 0x53a5f8, ecx of 0x467d30 at 0x430319; +0x04 m_Top, the "Screen" composite
//   (0x4614d0 draws *(+4) with the root transform +0x18, at 0x46160f..0x461616); +0x14 the string list.
//   Root transform +0x18 (0x4606c0): position 0,0,0; ScreenWidth 1; Width 0.75 (0x4f3920); Height H/W
//   (0x4fe934 / 0x4fe930, 480/640); scale 1; rotation 0.
//   Component (ctor 0x458230): +0x04 position x,y,z, +0x10 scale, +0x1c rotation, +0x2c visible, +0x30 a draw
//   callback (0x458550; none in the HUD, the clip's while laid out, below), +0x38 name.
//   Composite (ctor 0x458570, vtable 0x4d2834): +0x78 children {+4 begin, +8 end}, +0x7c width, +0x80 height.
//   World transform of a composite (0x4589c0): position = local * parent Width/Height + parent position;
//   Width = +0x7c * parent Width, Height = +0x80 * parent Height, ScreenWidth = the parent's; Scale = parent
//   Scale * +0x10.. . Strings (vtables 0x4d28c8, 0x4d2b98) are composites of glyph elements whose transform
//   (0x463bb0) takes Width = +0x7c * parent ScreenWidth instead, so glyph advance does not follow the parent's
//   Width; their SetScale (0x463c90) stores +0x10.. and +0x7c = scale x (0x458be0).
//   Element draw (0x459440, vtable 0x4d2890): render object +0x50.. = local * parent Width/Height + parent
//   position, z + 1; its scale = +0x10.. (raw * 0x544ab0, SetScale 0x459910) * parent Scale.
//   The HUD's view is identity and its projection x/z, y/z (0x462320), every part at z = 1 + local z, so one
//   world unit is 320 pixels of the 640x480 view and the view spans x -1..1, y -0.75..0.75.
// A direct child of Screen therefore moves by (dx / 0.75, dy / 0.75) in local units for (dx, dy) in world units,
// and grows by k about its own origin when its +0x10/+0x14 (sizes of every mesh and glyph below it), its
// +0x7c/+0x80 (places of its children) and +0x7c of every string below it (glyph advance) are multiplied by k.
// Scale z and every z stay: the HUD's parts are flat at z 1 (but the bonus model, GROUPS BONUS), so that is an
// exact 2D similarity of the drawing (evidence/checks/hud-scale-levers.txt). A frame of the JS port, the 4:3 HUD at
// f world units per 640x480 pixel with its top left corner at (X, Y) from the screen's top left, is the similarity
// q = k p + b of the HUD's world (k = 320 f, bx = X + k - xr, by = yr - Y - 0.75 k), which apply() gives each group.
//
// Clipping. The JS port draws each group of meshes with its frame as the viewport (race-hud-meshes.js:251-258
// renderElement, layers :24-26), which clips the group to its frame; its strings are drawn over the whole canvas
// (race-hud.js:123, hud-text-renderer.js:159). The game draws every child of Screen through 0x458550, called for each
// child by the composite draw 0x458760 at 0x4588c3, which first calls the child's own callback +0x30 with the child
// (cdecl, 0x458553..0x45855d; 0 in every HUD component: none is set by the overlay loader). While the groups are laid
// out, that callback is a host thunk that hands the next group's frame (or none) to opts.clip, the recorder's
// hudClip (source/render/recorder.js CMD.CLIP, a scissor in gl-renderer.js), so each group's draws are cut to its
// frame as the JS port's are (tools/checks/hud-scale-check.mjs compares every draw and its clip with raceHudLayout).
// The bonus box goes further: it stays as at 4:3 and its frame is also its viewport (GROUPS frame).

const MANAGER = 0x0053a5f8;
const TOP = MANAGER + 0x04;           // m_Top, composite "Screen"
const ROOT = MANAGER + 0x18;          // root transform: +0x0c ScreenWidth, +0x10 Width, +0x14 Height
const CLIP_Y = 0.75;                  // the game's viewport clip: x -1..1, y -0.75..0.75 (dvClipY 0.75)

const VT_COMPOSITE = 0x004d2834;
const VT_ELEMENT = 0x004d2890;
const VT_STRINGS = [0x004d28c8, 0x004d2b98];   // fixed and property strings

// STRING_SPECIAL's sliding style (0x46d5d0): x = -/+((0.5 - t/T) * 2.9)^2 local, from off the left edge through
// the centre to off the right one. At 4:3 that start is world 2.1025 * 0.75 = 1.577.
export const SPECIAL_SLIDE = (0.5 * 2.9) ** 2;
// The start lights (Rco_321Player): each light's local y is 1.25 while hidden above the top edge (0x464a00),
// slides to 0.4 (0x464e90) where it stays during the countdown, and back to 1.25 after green (0x464f30). They
// stay visible above the edge for the whole race: their frame's clip hides them there, also when the frame is lower
// on the screen (the middle of an upright one, below a top inset), where the JS port shows them coming in at the
// frame's top line.
export const LIGHTS_HIDDEN = 1.25;
export const LIGHTS_PARKED = 0.4;
// In portrait the JS port draws the stars' frame 110 of its 640x480 pixels lower (race-hud-layout.js:24), below the
// race times, which share the stars' height there.
export const STARS_DROP = 110;
const EPS = 1 / 1024;                 // the JS port's Math.max(1, ...) of a usable width or height in pixels

// Frame per direct child of Screen (overlay.ini names, matched case-insensitively), as raceHudLayout's group() and
// text() place them (race-hud-layout.js:20-34): x -1 at the left inset, +1 at the right inset, 0 centred on the
// whole width; y +1 at the top inset, -1 on the bottom inset and the touch band, 0 centred in the room between;
// portraitY: y on an upright screen; times: at the race times' scale; clip: cut to the frame, the JS port's mesh
// layers (race-hud-meshes.js:251-258; its strings are not cut); frame: not moved in game memory but drawn by the
// renderer with its frame as the viewport and the game's 4:3 clip (CMD.CLIP mode 2), the JS port's way exactly.
// Labels and their values share a composite, so they move and grow together. A child not listed here stays where it
// is (scan()) and is not cut.
export const GROUPS = {
  PORTRAITS: { x: -1, y: 1, clip: true },               // racer portraits, frames, rank labels First..Fifth (1e..5e)
  STARS: { x: -1, y: 1, drop: STARS_DROP, clip: true }, // Sterrenrace: star flag and the 12 stars; lower in portrait
  NUMBERS: { x: 1, y: 1, times: true },                 // Ronde / Rondetijd / Snelste ronde with their values, lap n/5
  MAP: { x: 1, y: -1, clip: true },                     // minimap track and dots
  // bonus frame, held bonus model, BONUS label: left as at 4:3 and drawn into its frame by the renderer (frame), as
  // the JS port draws every group: the model, the one part off z 1, flies in 3D from 0.7, 0.1, 2.0 (0x465900) to its
  // rest, and a frame's similarity in game memory is exact for flat parts only
  BONUS: { x: -1, y: -1, clip: true, frame: true },
  '321TIMER': { x: 0, y: 1, portraitY: 0, clip: true }, // start lights: at the top, in the middle of an upright screen
  STRING_COUNTDOWN_VALUE: { x: 0, y: 1 },               // Tijdrace remaining time
  BACKARROW: { x: 0, y: 1, portraitY: 0, clip: true },  // wrong-way arrow (the JS port's 'arrows' layer)
  JUNCTIONARROW: { x: 0, y: 1, portraitY: 0, clip: true }, // junction warning
  STRING_SPECIAL: { x: 0, y: 0 },                       // PAUZE, Laatste ronde!, Snelste ronde, Raak!, Tijd is om! ...
};

const NO_INSETS = { left: 0, right: 0, top: 0, bottom: 0 };
const part = (v) => (v > 0 ? Math.min(v, 1) : 0);

/**
 * The JS port's frames for a drawing of clip half-extents xr, yr (world units) and opts { insets: { left, right,
 * top, bottom }, controls: { left } } (source/web/shared.js CTRL.INSET_*, CTRL.CONTROLS_L): insets are fractions of
 * the drawing's width (left, right) and height (top, bottom), controls.left the touch controls' band at the bottom
 * as a fraction of its height. Returns { portrait, f, fT, frame(g) -> { k, bx, by, rect } } (f, fT: world units
 * per pixel of the 640x480 frame, for the HUD and for the race times; raceHudLayout's scale and timeScale; rect: the
 * frame as fractions of the drawing, { x, y, w, h } from its top left, the JS port's viewport of the group).
 */
export function hudFrames(xr, yr, opts) {
  const ins = (opts && opts.insets) || NO_INSETS;
  const W = 2 * xr, H = 2 * yr;
  const l = part(ins.left) * W, r = part(ins.right) * W, t = part(ins.top) * H, b = part(ins.bottom) * H;
  const band = part(opts && opts.controls && opts.controls.left) * H;
  const portrait = H > W;
  const uw = Math.max(EPS, W - l - r), ah = Math.max(EPS, H - t - b - band);
  // race-hud-layout.js:9-13: an upright screen fits 480 pixels of the frame across, a landscape one the whole
  // 640x480; the race times ignore the touch band in landscape
  const f = portrait ? Math.min(uw / 480, ah / 480) : Math.min(uw / 640, ah / 480);
  const fT = portrait ? f : Math.min(uw / 640, Math.max(EPS, H - t - b) / 480);
  const sim = (X, Y, s) => ({ k: 320 * s, bx: X + 320 * s - xr, by: yr - Y - 240 * s, rect: { x: X / W, y: Y / H, w: (640 * s) / W, h: (480 * s) / H } });
  const w = 640 * f, h = 480 * f;
  const top = t, bottom = H - b - band - h, centreX = (W - w) / 2, middle = t + (ah - h) / 2;
  return {
    portrait, f, fT,
    frame(g) {
      if (g.times) return sim(W - r - 640 * fT, top, fT);
      const y = portrait && g.portraitY !== undefined ? g.portraitY : g.y;
      const Y = y > 0 ? top + (portrait && g.drop ? g.drop * f : 0) : y < 0 ? bottom : middle;
      return sim(g.x < 0 ? l : g.x > 0 ? W - r - w : centreX, Y, f);
    },
  };
}

export class HudLayout {
  constructor(m) {
    this.m = m;
    this.found = false;
    this.entries = [];        // { c, name, group, g, kind, strings }
    this.unclassified = [];
    this.special = 0;
    this.kids = [];           // every child of Screen, in draw order
    this.saved = [];
    this.savedWords = [];     // callbacks (+0x30) set by apply: address, word before
    this.frames = null;       // the frames of the last apply (hudFrames), for checks
    this.clipOf = new Map();  // Screen child -> its frame's rect, while laid out (absent: not cut)
    this.clipSink = null;     // opts.clip of the last apply
    this.clipNow = null;      // the rect last handed to it (null: none)
    this.clipThunk = 0;       // the host thunk 0x458550 calls as a child's +0x30 callback
  }

  /** Clip half-extents for a screen of aspect width/height: 4:3 gives xr 1, yr 0.75 (the game's own). */
  static clipFor(aspect) {
    const base = 4 / 3;
    return aspect >= base ? { xr: CLIP_Y * aspect, yr: CLIP_Y } : { xr: 1, yr: (CLIP_Y * base) / aspect };
  }

  nameOf(c) {
    const m = this.m;
    const p = m.u32[(c + 0x38) >> 2];
    if (p < 0x400000 || p >= m.u8.length - 64) return '';
    let s = '';
    for (let k = 0; k < 48; k++) {
      const ch = m.u8[p + k];
      if (!ch) return s;
      if (ch < 32 || ch > 126) return '';
      s += String.fromCharCode(ch);
    }
    return '';
  }

  children(c) {
    const m = this.m;
    const limit = m.u8.length - 16;
    const v = m.u32[(c + 0x78) >> 2];
    if (v < 0x400000 || v >= limit || v & 3) return [];
    const a = m.u32[(v + 4) >> 2];
    const b = m.u32[(v + 8) >> 2];
    if (a < 0x400000 || b >= limit || b < a || b - a > 4096 || (a & 3) || ((b - a) & 3)) return [];
    const out = [];
    for (let p = a; p < b; p += 4) {
      const k = m.u32[p >> 2];
      if (k >= 0x400000 && k < limit && !(k & 3)) out.push(k);
    }
    return out;
  }

  kindOf(c) {
    const vt = this.m.u32[c >> 2];
    return vt === VT_COMPOSITE ? 'composite' : vt === VT_ELEMENT ? 'element' : VT_STRINGS.includes(vt) ? 'string' : '';
  }

  /** The strings below a composite, at any depth (their glyph advance follows their own +0x7c only). */
  stringsBelow(c, depth = 0) {
    const out = [];
    if (depth > 8) return out;
    for (const k of this.children(c)) {
      const kind = this.kindOf(k);
      if (kind === 'string') out.push(k);
      else if (kind === 'composite') out.push(...this.stringsBelow(k, depth + 1));
    }
    return out;
  }

  /** Finds the groups once the overlay is built (0x467bf0, in start_game 0x42f930). */
  scan() {
    const m = this.m;
    const top = m.u32[TOP >> 2];
    if (!top || m.u32[top >> 2] !== VT_COMPOSITE) return false;
    this.entries = [];
    this.unclassified = [];
    this.kids = this.children(top);
    for (const c of this.kids) {
      const name = this.nameOf(c);
      const up = name.toUpperCase();
      const g = GROUPS[up];
      if (!g) {
        this.unclassified.push(name);
        continue;
      }
      const kind = this.kindOf(c);
      const e = { c, name, group: groupName(g), g, kind, strings: kind === 'composite' ? this.stringsBelow(c) : [] };
      this.entries.push(e);
      if (up === 'STRING_SPECIAL') this.special = c;
    }
    this.found = this.entries.length > 0;
    return this.found;
  }

  /**
   * xr, yr: half-width and half-height of the clip the renderer maps to the screen, in the HUD's world units
   * (HudLayout.clipFor). opts (optional): { insets, controls } as hudFrames takes them, and clip(rect | null), told
   * before each group's draws which rect of the drawing they are cut to (a frame's rect, hudFrames; with frame: true
   * also drawn into it) or that they are not (null); called only on a change, and with null by restore(). Each group
   * gets the similarity of its JS-port frame, but a GROUPS frame group with a clip, which the renderer maps (without
   * one it is moved as the others, exact for its flat parts only). At 4:3 with no insets and no touch band every
   * frame is the 4:3 screen itself and nothing is written.
   */
  apply(xr, yr, opts) {
    const m = this.m;
    this.saved.length = 0;
    this.savedWords.length = 0;
    if (!this.found && !this.scan()) return;
    const F = this.frames = hudFrames(xr, yr, opts);
    const frames = this.entries.map((e) => F.frame(e.g));
    if (frames.every((q) => Math.abs(q.k - 1) < 1e-9 && Math.abs(q.bx) < 1e-9 && Math.abs(q.by) < 1e-9)) return;
    const f32 = m.f32;
    const saved = this.saved;
    const poke = (addr, value) => {
      const p = addr >> 2;
      if (f32[p] === Math.fround(value)) return;
      saved.push(p, f32[p]);
      f32[p] = value;
    };
    const times = (addr, k) => poke(addr, f32[addr >> 2] * k);
    const rootX = f32[ROOT >> 2], rootY = f32[(ROOT + 4) >> 2];
    const rootW = f32[(ROOT + 0x10) >> 2];
    const rootH = f32[(ROOT + 0x14) >> 2];
    const sink = opts && typeof opts.clip === 'function' ? opts.clip : null;
    this.entries.forEach((e, n) => {
      const c = e.c;
      const { k, bx, by } = frames[n];
      if (sink && e.g.frame && m.u32[(c + 0x30) >> 2] === 0) return;     // drawn into its frame by the renderer
      // the group's origin P goes to k P + b, and everything below it grows by k about it
      const x = f32[(c + 4) >> 2], y = f32[(c + 8) >> 2];
      if (c === this.special && x) {
        // The sliding notice enters and leaves from beyond the side edges: its path is stretched so that both ends
        // stay as far off the screen as at 4:3, times the scale (the JS port does not stretch it, see
        // docs/intentional-differences.md). Resting at x 0, it is placed as its frame.
        const slide = SPECIAL_SLIDE * rootW;
        poke(c + 4, (x * (xr + k * (slide - 1))) / slide + (bx + (k - 1) * rootX) / rootW);
      } else {
        poke(c + 4, x * k + (bx + (k - 1) * rootX) / rootW);
      }
      poke(c + 8, y * k + (by + (k - 1) * rootY) / rootH);
      if (k !== 1) {
        times(c + 0x10, k);
        times(c + 0x14, k);
        if (e.kind !== 'element') {
          times(c + 0x7c, k);
          times(c + 0x80, k);
        }
        for (const s of e.strings) times(s + 0x7c, k);
      }
    });
    // Each group cut to its frame (GROUPS clip), through the callback 0x458550 makes before each child of Screen
    // (see the top of this file): the hidden start lights, above their frame, are then out of sight wherever the
    // frame is, as in the JS port.
    this.clipSink = sink;
    this.clipNow = null;
    this.clipOf.clear();
    if (sink) {
      if (!this.clipThunk) {
        this.clipThunk = m.makeThunk('hud!groupClip', 0, (esp) => {
          const rect = this.clipOf.get(m.u32[(esp + 4) >> 2]) || null;
          if (rect !== this.clipNow && this.clipSink) {
            this.clipNow = rect;
            this.clipSink(rect);
          }
          return 0;
        });
      }
      const u32 = m.u32;
      this.entries.forEach((e, n) => {
        if (!e.g.clip) return;
        this.clipOf.set(e.c, e.g.frame && u32[(e.c + 0x30) >> 2] === 0 ? { ...frames[n].rect, frame: true } : frames[n].rect);
      });
      for (const c of this.kids) {
        const p = (c + 0x30) >> 2;
        if (u32[p] !== 0) continue;           // (a callback of the game's own: none in the HUD; that child is not cut)
        this.savedWords.push(p, 0);
        u32[p] = this.clipThunk;
      }
    }
  }

  /** Puts back every field apply changed, and ends the last group's cut. */
  restore() {
    const f32 = this.m.f32, u32 = this.m.u32;
    const s = this.saved;
    for (let k = s.length - 2; k >= 0; k -= 2) f32[s[k]] = s[k + 1];
    s.length = 0;
    const w = this.savedWords;
    for (let k = w.length - 2; k >= 0; k -= 2) u32[w[k]] = w[k + 1];
    w.length = 0;
    if (this.clipNow && this.clipSink) this.clipSink(null);
    this.clipNow = null;
    this.clipSink = null;
  }

  /** Name, group and local position of every classified group, for checks. */
  describe() {
    const f32 = this.m.f32;
    return this.entries.map((e) => ({ name: e.name, group: e.group, x: f32[(e.c + 4) >> 2], y: f32[(e.c + 8) >> 2] }));
  }
}

function groupName(g) {
  const h = g.x < 0 ? 'left' : g.x > 0 ? 'right' : 'centre';
  const v = g.y > 0 ? 'top' : g.y < 0 ? 'bottom' : 'middle';
  return `${h}+${v}${g.portraitY === 0 ? '/mid' : ''}${g.drop ? '/drop' : ''}${g.times ? '/times' : ''}`;
}
