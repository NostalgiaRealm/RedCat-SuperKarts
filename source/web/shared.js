// Memory shared between the page, the game worker (worker.js) and the render worker (render-worker.js).
// The game thread never returns to its event loop while the race runs, so everything it must learn while it
// runs comes through here: input, the page being hidden, frames the render worker has drawn.

// Control words (Int32Array). FRAMES: frames the render worker has drawn (the recorder paces on it); DEAD: the
// render worker failed; PAUSED: the page is hidden (the game thread sleeps, also inside the game's own waits); TICKS,
// PHASE: what the game thread tells the page (passes of the loop, the race phase 0x53b9c0; -1 before a race's first
// pass and after its end). The page runs many races with the same memory (source/race-runner.js): FRAMES keeps
// counting across them, the rest is set anew per race. ASPECT: the drawing's width / height in
// millionths, from the page (the HUD's groups move to the edges of that shape: source/host/hud-layout.js).
// HUD_SCALE: 1000 (unused: the HUD's size follows from the shape, the insets and the touch band, hud-layout.js);
// INSET_L/R/T/B: the safe area's insets (notches, rounded corners, home bar; at least 8 CSS px at the top and sides
// of an upright screen) as fractions of the drawing's width (left, right) and height (top, bottom), in
// ten-thousandths. Both from the page, for hud-layout.js.
export const CTRL = {
  FRAMES: 0, DEAD: 1, PAUSED: 2, TICKS: 3, PHASE: 4, ASPECT: 5,
  HUD_SCALE: 6, INSET_L: 7, INSET_R: 8, INSET_T: 9, INSET_B: 10, CONTROLS_L: 11, CONTROLS_R: 12,
  FLIGHT: 13, OPTIONS: 14, FLIGHT_ACTIVE: 16, SAFE_STUCK: 28, SAFE_NPC: 29, SAFE_KEYS: 30, VOLUME: 31,
  KEYS: 32, KEYS_SEQ: 38, PAUSE_KIND: 39, SIZE: 40,
  HOLD: 27,
};
// HOLD (word 27): what the page holds, as bits (HOLD), from the page whenever its sound or holds change (race-runner.js
// updatePaused). SOUND: the race's sound is held on the page (the AudioContext suspended: a focus pause, a hidden page,
// the menu over the race, a result-screen hold; runner.soundOn() false); the game thread counts the game time that
// passes meanwhile and keeps it out of the sound's clock (worker.js soundUs, dsound.js, dshow.js), as the JS port's paused
// track and effects keep their place (its game-audio.js:18, driving-view.js:401). RESULTS: the focus hold on a result
// screen (runner.focusHeld): the game thread shows the original's "pauze" over it (render-replay.js notice()).
export const HOLD = { SOUND: 1, RESULTS: 2 };
// KEYS..KEYS+5: the virtual keys bound to accelerate, brake, left, right, bonus and handbrake (0: unbound), from the
// page whenever its settings are applied (race-runner.js applySettings, source/input/race-keys.js publishKeys);
// KEYS_SEQ counts their changes and is written after them. The game thread looks at KEYS_SEQ before every pass and
// writes a change into the game's own table 0x53a5b8 (race-keys.js writeGameKeys), as the JS reconstruction applies
// new bindings at once (its input.js:71).
// PAUSE_KIND: while CTRL_WAITING is 1, which loop the game waits in: the pause kind u32 0x53b9f8 that 0x42f9c0 set (1 P,
// the pause 0x42f220; 2 Esc, the quit requester 0x42f290; 0 another wait, such as a result screen waiting for its key's
// release), from the game thread before CTRL_WAITING goes to 1 and back to 0 after it. The touch controls hide only
// for the requester and stay drawn but inert in the pause, as the JS reconstruction's (its main.js:882 hides them when
// the requester shows; its P and focus pause leave them up, main.js:741-747, :767).
// SAFE_*: what the race's safeguards did this race (source/host/safeguards.js), from the game thread after every pass:
// stuck recoveries started, NPC speeds set to 0 by the velocity guard, debug and cheat key polls answered "up" (without
// OPT.CHEATS). VOLUME (word 31): the menu's music and effects levels, from the page whenever its settings are applied
// (source/host/live-volume.js packVolumes: bits 8..15 music, 0..7 effects, percent or 0xFF); the game thread puts a
// level that changed during the race into it before the next pass (LiveVolume.update), as the JS reconstruction
// applies both at once (its driving-view.js:378-383).
// FLIGHT: free flight (the JS reconstruction's Vrij vliegen) asked for by the page, 1 while on; FLIGHT_ACTIVE: the game
// thread flies (source/host/free-flight.js), 1 while it does (the page's flight panel, Omhoog/Omlaag, LB/RB). OPTIONS: settings the
// page can change during a race, as bits (OPT). Words 17..31 are free: 17..23 free flight, 24..26 the race's
// visuals (unused: their two settings are OPT bits and their draws carry tags), 27 the page's holds (HOLD), 28..30 the
// race's safeguards (stuck recovery, key filter), 31 the sound levels.
// OPT.SURFACE_SHADOWS, OPT.SMOOTH_ENGINE_LIGHTS: Schaduwen op het wegdek and Motorlicht volgt de kart (settings
// surfaceShadows, smoothEngineLights, on unless false), from the page's applySettings at race start and after OK; the
// game thread copies OPTIONS to host.options before every pass for source/host/shadows.js.
// OPT.CHEATS: the original's debug and cheat keys answer (D, numpad 7-9, Ctrl+F+I, Ctrl+E+N, the tweak keys); without it
// they read "up", as the JS reconstruction has none (safeguards.js). The development page sets it unless ?nocheats, the
// menu only with ?cheats (source/race-runner.js cheats); the game thread takes it once per pass.
export const OPT = { SURFACE_SHADOWS: 1, SMOOTH_ENGINE_LIGHTS: 2, CHEATS: 4 };

// Input (Int32Array): 0..255 one word per Windows virtual-key code, 1 while down (GetAsyncKeyState);
// the pointer in the game's screen pixels; buttons (1 left, 2 right, 4 middle); movement summed since the game
// last read it (DirectInput's mouse, 0x4318a0); SEQ counts every change, and a game thread that waits for input
// sleeps on it. JOY_*: the virtual WinMM joystick 0 (source/host/winmm.js) the pad and the touch wheel drive: X and
// Y in 0..65535 (32767 centre; X right, Y down = brake), buttons (bit 0 bonus, bit 1 handbrake), ACTIVE while one
// of them steers or works the pedals (the game worker then lets the game's analog handler 0x4341d0 drive).
// JOY_GAS, JOY_BRAKE: the pad's and the wheel's pedals apart, 0..10000, the largest of the sources and without the
// game's ±10% window (JOY_Y holds gas - brake): the stuck recovery's input, as the JS reconstruction's step reads
// accelerate and brake (source/input/race-keys.js stuckInput).
export const IN = { MOUSE_X: 256, MOUSE_Y: 257, BUTTONS: 258, DX: 259, DY: 260, DZ: 261, SEQ: 262, JOY_X: 264, JOY_Y: 265, JOY_BUTTONS: 266, JOY_ACTIVE: 267, JOY_GAS: 268, JOY_BRAKE: 269, SIZE: 272 };

// Control word set by the game thread while the game waits inside a pass in a loop of its own (its pause, its quit
// requester): the pad's A and B then answer it (J, N); the touch controls step aside in the requester (CTRL.PAUSE_KIND)
// for taps on the picture.
export const CTRL_WAITING = 15;
// CTRL.CONTROLS_L: with the touch controls showing, the height of their band at the bottom (their box less the
// bottom inset), a fraction of the drawing's height in ten-thousandths: the HUD fits above it as the JS
// reconstruction's does (hud-layout.js opts.controls.left). CONTROLS_R: 0 (unused).
