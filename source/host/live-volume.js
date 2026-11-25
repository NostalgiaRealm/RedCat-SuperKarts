// The menu's music and effects levels changed while a race runs (the flight panel's Instellingen), put into the race
// through its own volume code, as the JS reconstruction applies both at once when its settings close over a race
// (main.js:732 resumeViewer -> DrivingView.setAudioSettings, driving-view.js:378-383). The original has no such menu
// inside the race; what it does at load with race.ini's levels is what runs here with the new ones:
//
// Effects: 0x437e30 on the voice controller (the object 0x4371f0 hands out, kept at 0x53bf70), as 0x437560 calls it at
// load with race.ini [GAME_SETTINGS] FX_VOLUME (0x437a33-0x437a3e) and the game's only other caller does with a new
// percent (0x47c01b-0x47c022): a percent above 0 switches the voices on (byte 0 of the controller), every sound
// source in a group other than MOTOR and MUSIC takes the percent (0x49e970 -> 0x49d4d0; a source that plays gets
// IDirectSoundBuffer::SetVolume through 0x49d570, 0x49d520: (p - 100) * 39 - 100 hundredths of a dB), and 0 switches
// the voices off and clears their queues (0x437be0). The engine keeps its level: the JS port's setGroupVolume is this
// function (native-race-audio.js:222-236, audio-mixing.js:34-44, nativeEffectsAffectsSound). Only a percent that
// differs from the race's is put in, as the JS port only calls setGroupVolume then (driving-view.js:380-383: again
// with the same percent it would overwrite the levels of sources made after the load).
//
// Music: MX_VOLUME is 0x53b9a4 (0x42c320) and its level IBasicAudio::put_Volume(0x431610(p) = 49 * p - 5000) through
// 0x48f010 on the music object 0x53a590, as init_game 0x42d7d0 sets it at 0x42deae-0x42dec3; the JS port's
// originalMusicGain is the same curve (game-audio.js:2-6). At 0 the JS port pauses its track and a level above 0
// plays it on from there (game-audio.js:15-16 setVolume and resume, driving-view.js:384): here the filter graph is
// paused and run again through its IMediaControl, asked for with the game's own IID (0x4d3480) as 0x48edc0 asks
// for it. A race that started at 0 never ran its track (0x42dee7: MX_VOLUME 0 skips 0x48edc0); a level above 0
// starts it as init_game does then (0x42deed-0x42df03: 0x48edc0 runs the graph, 0x48ec20(1) sets the loop byte),
// where the JS port's resume plays its track from the start.
//
// Both levels also go into race.ini [GAME_SETTINGS] as the menu writes them before a race (race-handoff.js), so the
// file holds the levels the race plays with and its FX_VOLUME at the end (readResult's effectsPercent) is the
// player's last choice, not the level at the start.
//
// The page publishes its two levels in one control word (CTRL.VOLUME, source/web/shared.js; packVolumes) whenever
// its settings are applied; the game worker hands every new word to update() before a pass. A level the page did
// not change since the last word (or since the race started) is not touched: at the start the race has the
// handoff's levels, and FX_VOLUME 0 with effects on is 75 after 0x437560's repair until the menu adopts it.
import { audioPercent } from './race-handoff.js';

export const NO_LEVEL = 0xFF;
const A = { MX_VOLUME: 0x53b9a4, MUSIC: 0x53a590, VOICES: 0x53bf70 };
const FN = { EFFECTS: 0x437e30, MUSIC_LEVEL: 0x431610, MUSIC_VOLUME: 0x48f010, MUSIC_RUN: 0x48edc0, MUSIC_LOOP: 0x48ec20 };
const IID_MEDIA_CONTROL = 0x4d3480;
// IUnknown::QueryInterface and Release, IMediaControl::Run and Pause: their offsets in the vtable
const COM = { QUERY: 0x00, RELEASE: 0x08, RUN: 0x1c, PAUSE: 0x20 };

/**
 * The menu's settings.music and settings.effects (0..1) as one control word: bits 8..15 the music, 0..7 the effects,
 * each the percent the handoff writes into race.ini (race-handoff.js audioPercent), or NO_LEVEL where the handoff
 * writes none (no settings, a value that is not a number).
 */
export function packVolumes(settings) {
  const level = (v) => { const p = settings ? audioPercent(v) : null; return p === null ? NO_LEVEL : p; };
  return (level(settings && settings.music) << 8) | level(settings && settings.effects);
}

export function unpackVolumes(word) {
  return { music: (word >> 8) & 0xFF, effects: word & 0xFF };
}

const percentOf = (s) => {
  const n = parseInt(s, 10);
  return Number.isFinite(n) ? Math.max(0, Math.min(100, n)) : null;
};

export class LiveVolume {
  /** word: the page's control word as the race starts (its levels are the handoff's). */
  constructor(word) {
    this.word = word;
    this.effects = null;        // the percent the effects have now (after boot: what 0x437560 put in)
    this.musicHeld = false;     // the track was paused here at 0
  }

  /**
   * After boot: the levels the race plays with, race.ini as 0x42c320 read it and 0x437560 left it (an enabled
   * FX_VOLUME 0 is 75 now). { music, effects } in percent, or null where race.ini holds none.
   */
  boot(vfs) {
    const music = percentOf(vfs.iniGet('race.ini', 'GAME_SETTINGS', 'MX_VOLUME'));
    this.effects = percentOf(vfs.iniGet('race.ini', 'GAME_SETTINGS', 'FX_VOLUME'));
    return { music, effects: this.effects };
  }

  /** Before a pass: the page's word; a level it changed goes into the race. Returns what was put in (for logs). */
  update(m, vfs, word) {
    if (word === this.word) return null;
    const was = unpackVolumes(this.word), now = unpackVolumes(word);
    this.word = word;
    const done = {};
    if (now.music !== was.music && now.music !== NO_LEVEL) done.music = this.setMusic(m, vfs, now.music);
    if (now.effects !== was.effects && now.effects !== NO_LEVEL) done.effects = this.setEffects(m, vfs, now.effects);
    return done;
  }

  setEffects(m, vfs, p) {
    if (p === this.effects) return false;
    vfs.iniSet('race.ini', 'GAME_SETTINGS', 'FX_VOLUME', String(p));
    this.effects = p;
    const voices = m.u32[A.VOICES >> 2];
    // not loaded yet (0x437d50 runs in init_game): 0x437560 reads the FX_VOLUME just written when it loads
    if (!voices) return false;
    m.call(FN.EFFECTS, [p], voices);
    return true;
  }

  setMusic(m, vfs, p) {
    const was = m.i32[A.MX_VOLUME >> 2];
    if (p === was) return false;
    vfs.iniSet('race.ini', 'GAME_SETTINGS', 'MX_VOLUME', String(p));
    m.i32[A.MX_VOLUME >> 2] = p;
    // the graph (0x48ed60, init_game) is there in every race; nothing in the game checks for it either
    if (!m.u32[(A.MUSIC + 4) >> 2]) return false;
    if (p === 0) {
      if (!this.musicHeld && was !== 0) { this.control(m, COM.PAUSE); this.musicHeld = true; }
      return true;
    }
    m.call(FN.MUSIC_VOLUME, [m.call(FN.MUSIC_LEVEL, [p])], A.MUSIC);
    if (this.musicHeld) { this.musicHeld = false; this.control(m, COM.RUN); }
    else if (was === 0) { m.call(FN.MUSIC_RUN, [], A.MUSIC); m.call(FN.MUSIC_LOOP, [1], A.MUSIC); }
    return true;
  }

  /** IMediaControl::Run or Pause on the music's filter graph: QueryInterface, the call, Release (0x48edc0's steps). */
  control(m, slot) {
    const graph = m.u32[(A.MUSIC + 4) >> 2];
    const vtable = (p) => m.u32[p >> 2];
    // the interface pointer goes in a dword well below the stack in use (0x48edc0 keeps it on its stack); host
    // methods only, so nothing else is pushed there
    const out = (m.esp - 0x400) & ~3;
    m.u32[out >> 2] = 0;
    if ((m.call(m.u32[(vtable(graph) + COM.QUERY) >> 2], [graph, IID_MEDIA_CONTROL, out]) | 0) < 0) return;
    const control = m.u32[out >> 2];
    if (!control) return;
    m.call(m.u32[(vtable(control) + slot) >> 2], [control]);
    m.call(m.u32[(vtable(control) + COM.RELEASE) >> 2], [control]);
  }
}
