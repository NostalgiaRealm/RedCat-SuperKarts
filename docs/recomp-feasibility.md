# Recompiling SuperKarts: feasibility

Investigation of 2026-11-25. Question: is this port a recomp, and if not, what
would it take to make it one, as was done for RedCat Spookkasteel 2.0.0?
Nothing in the port was changed. The trial build ran on copies in a scratch
folder; the Spookkasteel and A2 Racer 4 projects were only read.

Labels: **measured** (run or counted here), **confirmed** (read from the
original code or data), **estimate** (judgement, not measured).

## 1. Answer

**Not a recomp.** The current port (1.0.3) reimplements the original in
JavaScript: 16,101 lines in `source/`, Three.js/WebGL2 rendering, no
WebAssembly and no x86 code at run time. The original race code
(`rcskspel.dat`) is only used as a reference: through the Ghidra export in
`original-source/`, the Unicorn original-instruction fixtures, the race trace
and the golden frames. Every rule in the race (physics, AI, collisions,
rescue, bonuses, HUD, sound triggers) is a hand-written copy whose
equivalence has to be shown case by case. The README says so too: full
handling, visual and audio parity has not been established.

**A recomp is feasible, and easier than Spookkasteel's.** The race executable
recompiles almost cleanly with the Spookkasteel recompiler as it is (section
2). It is built on the same Davilex engine and DirectX 5 interfaces as A2
Racer 4 (section 3), whose recompiled port already has a working host and
Direct3D 5 renderer. The template is therefore **A2 Racer 4**, not
Spookkasteel: Spookkasteel's host implements a Genesis3D driver, which
SuperKarts does not use.

## 2. Trial recompile (measured)

Tool: `RCSPOOK_MAIN/tools/recomp` (build.py, lift.py, recompile.py,
replacements.py, wasmgen.py; 4,745 lines), copied to a scratch folder. Input:
`original-source/inputs/rcskspel.dat` (SHA-256 `68e5c913…`) with the existing
Ghidra lists `functions.tsv` and `instructions_outside_functions.tsv`. No
other inputs are needed: the menu, launcher and movie player stay out (section
5).

Changes to the copy:

1. Module list: `('rcskspel.dat', 'rcskspel.dat', 'GAME', False)` instead of
   `RcHcGame.dat`. The image has no relocations, so it stays at 0x400000 and
   the data sections get the word-by-word pointer scan, as for A2's
   `spel.dat`.
2. Spookkasteel's `GAME_HOOKS` emptied.
3. `__CxxThrowException@8` (0x4BFC77) marked no-return. It ends in `ret 8`
   after `RaiseException`, so the recompiler's own rule does not trust
   Ghidra's no-return flag for it, and decoding ran on into the jump tables
   behind three functions (0x437EA0, 0x467E30, 0x46C910). Without this line
   29 functions fail instead of 16.

| | SuperKarts `rcskspel.dat` | Spookkasteel `RcHcGame.dat` (for scale) |
|---|---:|---:|
| Functions discovered | 5,620 | 23,915 |
| Instructions | 238,238 | |
| Lifted | 5,604 | |
| Failed | 16 | 129 |
| Wasm size | 4.0 MB | 13.3 MB |
| Build time | 5.4 s | 18 s |

- The module (4,020,980 bytes) passes `WebAssembly.validate`. It has 21 imports (`env.host`,
  `env.trace` and 19 math functions) and the usual exports (memory, table,
  register globals, `__call`).
- Matched automatically by the CRT signatures: `__ftol`, `_CIasin`, `_CIpow`,
  `_fmod`, `_CIfmod`, `_CIacos`, `_memcpy` (2), `_memset`, `_strrchr`,
  `_chkstk`, `__EH_prolog`.
- C++ exceptions: 411 handler stubs, 22 guarded functions, 1,543 unwind and
  53 catch funclets, all handled by the existing scheme.
- **The 16 failures:** 15 are x87 special-value handlers of the C runtime
  (0x4BFD64, 0x4C1EC4–0x4C1F66, 0x4C4D71–0x4C5F3C). Ghidra's references
  show them reached only through the CRT dispatch tables at
  0x5029E0–0x503070 and from `__cintrindisp2`/`__ctrandisp*`, which only the
  replaced `_CIfmod`/`_CIasin`-family entry points use (**confirmed
  statically**; not yet confirmed at run time). The 16th, 0x4C4F52, is data
  decoded as code (`les edx, …`). None should be needed in a race.
- Six functions have irreducible control flow (including `_strncpy` and
  `_strstr`); the recompiler handles those with its fallback mode.
- Untested: the module has not been run. Booting it needs the host (sections
  3 and 4).

The x87 precision option is `--fpu-pc 53`, the recompiler's default and what
the 1.0.2 research established for the original.

## 3. What the host has to provide

### Same engine as A2 Racer 4 (confirmed)

- 113 source file names in `rcskspel.dat` also appear in A2's `spel.dat`:
  the engine (`Engine/Prog`: `Bbox`, `cam_main`, `Rd_chunk`, `Rd_main`,
  `rd_rail`, `obj_*`, `tmg_main`), the game layer (`ai_*`, `car_*`, `gfx_*`,
  `Hud_*`, `Gm_*`, `ev_*`, `pth_*`, `tob_main`, `tr_*`), the Direct3D library
  `DX3D` (`D3dev`, `D3dlib`, `Mesh`, `Viewport`, …), the 2D library `dxdraw`
  and the sound library `sound_lib`. They share 1,940 strings of 6 or more
  characters. SuperKarts (`D:\work\rcsk\Code`) is an older branch; A2
  (`C:\Work\A2IV`) adds Ipion physics and its own input library.
- **DirectX interfaces**, found by their IIDs in the file: `IDirectDraw2`,
  `IDirectDrawSurface2`, `IDirect3D2`, `IDirect3DTexture2`, the HAL, RGB and
  Ramp device GUIDs, `IDirectSound3DBuffer`/`Listener`, and DirectInput
  keyboard and mouse. A2's `spel.dat` has the same set, except that it
  uses `IDirectInputDevice2A` and no mouse. That is exactly what A2's
  `source/host/directx.js` (728 lines) and `source/render/d3d-renderer.js`
  (1,709 lines) implement.
- **Geometry** goes through `IDirect3DDevice2::DrawPrimitive` with vertex type
  2 (`D3DVT_LVERTEX`: world-space, pre-lit), for example in `Par_Main`,
  `rse_GenesisExplosion` and `rse_HaloEffect`. Transforms come from the
  device's matrices, as in A2. A2's renderer already blends those matrices
  between ticks, so the game can tick at its own rate while the browser
  draws at display rate.

### Imports (measured)

`rcskspel.dat` imports 134 functions from 9 DLLs. **122 exist by name** in the
A2 or Spookkasteel hosts. The 12 missing:

| Import | Where / what for | Work |
|---|---|---|
| `InflateRect`, `OffsetRect`, `PtInRect`, `GetFocus`, `ShowCursor`, `ChildWindowFromPoint`, `wsprintfA` | rectangle and cursor helpers, string format | trivial |
| `SetWindowsHookExA`, `CallNextHookEx` | `0x442FA0` installs a `WH_KEYBOARD` hook (`0x442F40`) | stub, or feed keys through the hook |
| `CoInitialize`, `CoCreateInstance` | `0x48EC50` creates DirectShow's `CLSID_FilterGraph` (`IGraphBuilder`, `IMediaEvent`) for the race music `rclemu%02d.dat`, which are MP3 files | small DirectShow object: render file, run, stop, loop restart (`0x48EF80`), volume as attenuation (`0x431610`) |
| `CreateProcessA` | `0x4431E0` starts the program named in `rrm.ini [Modules] Program` after the main loop, but only when `game.ini [HELPDESK] ENABLE_RRM` is 1 (`0x4431B0`) | stub; a normal race ends by exiting |

A name match is not a finished implementation: each A2 function was written
for A2's calls and has to be checked against SuperKarts' calls.

### Start, loop and timing (confirmed)

- The launcher starts the menu; the menu writes the INI files and exits; the
  launcher starts `rcskspel.dat` with no arguments; the race reads
  `game.ini`, `race.ini`, `SndGfx.ini` and the rest from the current
  directory and writes its results back (`docs/research-startup.md`,
  `evidence/native/runtime/race-handoff.diff`). The host replaces the
  launcher: write those files into a virtual file system, start the module,
  read the results when the module exits (exit code `0xff` asks the launcher
  for a restart).
- `0x4432A0` busy-waits until `GetTickCount` has moved 25 ms, then runs one
  frame `0x42F4C0` (update and draw together). As Spookkasteel did with
  `CAdamApplication::MainLoop`, the loop becomes a host hook: the host calls
  the frame function once per tick. That removes the busy wait, allows exact
  save states between frames, and lets the race run on the main thread per
  tick like A2 (no worker, so no cross-origin isolation headers needed).
- The physics take a measured, filtered time step (`0x48F3E0`), and its
  results depend on the step (`0x4911A0` truncates the yaw step). Which
  clock the host feeds is a decision: the original's 25 ms gate (40 Hz cap)
  with real elapsed time, or a fixed step. Higher tick rates change handling,
  so the display should get its smoothness from interpolation, not from more
  ticks.

## 4. What changes in this repository

**Kept as they are:** the menu (the original Delphi `rcskmenu.dat` is not
recompiled; A2 and Spookkasteel kept their hand-written menus as well), intro
and reward movies (MP4 conversions; `RCMovie.dat` and `SMACKW32.DLL` are not
needed), asset preparation, Meer instellingen, saves, Electron packaging,
deploy script and nginx setup.

**Replaced by the recompiled race:** the race side of `source/`:
`race-simulation.js`, `simulation/*` (AI, collisions, rescue, bonuses,
results), `race-visuals.js`, `driving-view.js`, `world.js`, the HUD and race
audio modules. In their place come the host (from A2: `directx.js`,
`win32.js`, `machine.js`, `vfs.js`, `game-files.js`, `race.js`, plus the
recompiler's output) and A2's renderer. The test tools built for the
reimplementation (original-instruction fixtures, race trace, golden frames)
lose their purpose for the race logic; parity of the logic then holds by
construction, and checking moves to the host: rendering, sound, input and
timing.

**Saves:** the browser keeps three keys: `rcsk.settings.v1`,
`rcsk.selection.v1` and `rcsk.race-save.v1` (high scores, records, profiles,
locks; already modelled on the original's `Race.ini` fields). There is no
mid-race save today, so nothing is lost: the host maps `rcsk.race-save.v1`
to and from the files the race reads and writes, and players keep their
progress at the same address. Exact save states inside a race would be new.

## 5. Port features that become hooks

Everything the port adds inside a race has to be rebuilt on top of the
original code. The current port's own behaviour is the specification.

| Feature | In a recomp | Effort (estimate) |
|---|---|---|
| Touch, gamepad, key layout | feed DirectInput keyboard state, as A2 does | small (A2 has `input/`) |
| Resolution, render scale, MSAA, phone pixel cap, 60 FPS limit on phones, FPS counter | renderer and host settings | small |
| Full-screen aspect (no 4:3 bars) and HUD placement | projection hook plus HUD layout, as A2's `hud-layout.js` | medium |
| Schaduwen op het wegdek | hook on the shadow code (`gfx_shdw.cpp`) or a renderer-side projection onto the road | medium to hard |
| Motorlicht volgt de kart | pair the engine light's draws across ticks in the interpolation | medium |
| Vrij vliegen | freeze the simulation, drive the game camera and draw only; the chunked world draws only visible sectors, so culling needs a hook too | hard (Spookkasteel did it) |
| Stuck recovery (England tyres) | a host check on the player position, calling the original rescue | medium |
| Alles ontgrendelen | menu side, unchanged | none |
| Pause-entry object pass (intentional departure) | the recomp runs the original's extra pass by default; keeping the departure needs a hook | small, but a decision |
| QuickRace highscore name `Speler 1` (intentional departure) | depends on whether the name entry is in the race or the menu; to check | small |

## 6. Risks and open points

- **Renderer details:** SuperKarts' `DX3D` library is an older version than
  A2's. Render states, texture formats (TGA, colour keys), fog, 2D overlays
  drawn with DirectDraw blits (`dxdraw`: `Clipblit`, `Sprite`, `Font`) and
  the in-race requesters with mouse input have to be checked call by call.
- **Display options:** the Ramp and RGB device GUIDs mean the game can choose
  a software device. Whether the Geavanceerd options lead to a path A2's
  renderer does not cover (A2 needed an 8-bit path) is open.
- **Run-time failures** the static trial cannot show: unhandled imports,
  stored code pointers the scan missed, the 15 CRT handlers if they are
  reachable after all.
- **Reference runs:** checking the host against the original still needs the
  original under Wine, with the WineD3D limits the port already documented.

## 7. Plan and size

1. New project folder (as Spookkasteel's `RCSPOOK_RECOMP`), with the
   recompiler and the three changes from section 2.
2. Host from A2: VFS with the game files, INI handoff, DirectX 5, DirectSound
   3D, DirectInput, the 12 missing imports, the loop hook. Goal: the first
   frame of Nederland.
3. Playable race on Nederland: input, sound, DirectShow music, HUD,
   requesters, results back to the menu.
4. The menu from this port wired to the race; saves mapped.
5. The hooks of section 5, in the order Rick chooses.
6. Checks on one track against the current port and the original under Wine;
   packages; the same take-over and deploy as Spookkasteel (the current port
   at `classic/` if wanted).

**Size (estimate):** Spookkasteel went from feasibility study (2026-11-12) to
release 2.0.0 (2026-11-15), including a new Genesis3D driver host. SuperKarts
starts from a host that already matches its DirectX interfaces and engine, and
a module under a third the size, so steps 1 to 4 should take less than that.
Steps 5 and 6 depend on how many port features have to come along; free flight
and road shadows are the expensive ones.

## 8. Recommendation

Do it as a separate project beside this one, as with Spookkasteel, and keep
this port as it is until the recomp has caught up. Start with steps 1 and 2:
the first frame on Nederland shows quickly whether A2's host really carries
over.

## Reproducing the trial

Copy `RCSPOOK_MAIN/tools/recomp/*.py` to an empty folder. Make a folder with
`decompiled/rcskspel.dat/` (the two TSV files above) and `originals/rcskspel.dat`.
Apply the three changes of section 2, then run with the reverse-engineering
Python (it has capstone):

```bash
RC_ORIGINAL_DECOMPILED=<folder> ~/.local/share/reverse-engineering/python-analysis/bin/python build.py --out <out>
```

The log of the trial run is in `evidence/recomp-feasibility/build.log`.
