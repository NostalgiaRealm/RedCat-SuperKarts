Checks of the hook build (2026-11-25): tools/recomp/build.py GAME_HOOKS wraps and GAME_PATCHES (docs/recompiler.md).
The scripts ran from a scratch folder against a copy of the build before it (baseline-game: wasm sha256 19bc2aaf...,
4,020,976 bytes); the paths inside them point there.
  wasm-diff.txt      wasmdiff.py baseline new: differing function bodies (HANDLE_GAME + the four direct wrap callers)
  cmp-*.json         cmp-builds.mjs: both builds in lockstep, memory compared every 250 passes; wrap call counts
  pause-cmp.json     pause-cmp.mjs: the P pass and the Esc+N pass before and after the 0x42f6d8 patch
  full-race-gaps/    tools/checks/full-race-gaps.mjs --only pause-live,esc-live-no,esc-live-yes,pause-tap-frozen
  st0-probe.mjs      m.call of 0x430ff0 and 0x4977d0/0x495fe0/0x496290: result in m.gSt0 (-26.19 at NED pass 400)
  build.log          the recompile
