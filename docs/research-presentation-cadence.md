# Native presentation and cadence

The original game enforces a **minimum 25 ms between complete updates**. Its presentation path can add display-dependent delays, but the executable does not establish a fixed 33 ms update period. This original presentation-flags audit did not change production code. The subsequent [variable-update correction](research-variable-update-timing.md) implements measured updates while keeping browser rendering uncapped.

## Original call chain

- `0x4432a0` repeatedly reads `GetTickCount` until the unsigned difference from the previous update start is at least `0x19`, records a new start timestamp, then calls the complete `0x42f4c0` update. The wait is before simulation, rendering and presentation together.
- `0x42f4c0` calls `0x430020` to render and later `0x430470` to update the display, after ordinary game actions.
- Both supported branches of `0x430470` call `0x4aff70`. Renderer 2 first invokes `0x4b6120` to copy its software image.
- `0x4aff70` uses `IDirectDrawSurface::Flip(NULL,1)` when backbuffer-count global `0x4fe940` is nonzero. The PE initializes that count to 1. This is `DDFLIP_WAIT`, with no `DDFLIP_NOVSYNC` or interval2/3/4 bits.
- If that count is 0, `0x4aff70` instead calls `Blt(...,0x01000000,NULL)`, the wait flag. `0x4b0ec0` sets count 0 for a windowed surface and can also fall back to it during primary-surface setup.
- An additional explicit vertical-blank wait occurs at the start of `0x430020`: DirectDraw vtable slot `+0x58`, flag 4, null event. `0x42b7b0` loads its controlling `WAITVBL` setting into `0x53ba04`; the active shipped `game.ini` has `WAITVBL=0`, so this explicit wait is skipped.

The misleading `0x48ef80` call at the render tail is not the display flip. Display presentation is the later `0x430470` call above. The retained decompiler output for `0x48ef80` is unsuitable for inferring a presentation interval.

## Executed evidence

`tools/native-presentation-flags.py` executes the original `0x430470` and `0x4aff70` instructions with recording COM-call stubs. All six combinations of renderer 1/2 and backbuffer count 0/1/2 passed. `evidence/native/presentation-flags.json` records the original binary digest, PE default and actual API arguments. Only surface restore checks, software copying and external presentation are stubbed; this does **not** measure real hardware waiting or frame timing.

Reproduce:

```sh
/home/rick/.local/bin/re-python tools/native-presentation-flags.py
```

Microsoft documents `DDFLIP_WAIT` as retrying until a flip can be set up, not as a promise to block for one whole refresh. The default physical flip is synchronized with vertical blank; `DDFLIP_NOVSYNC` permits different behavior. Therefore, presentation/next-surface access may affect achieved cadence, depending on the driver, refresh rate and workload. [Flip documentation](https://learn.microsoft.com/en-us/windows/win32/api/ddraw/nf-ddraw-idirectdrawsurface7-flip). The separately gated flag 4 wait returns at the end of vertical blank. [WaitForVerticalBlank documentation](https://learn.microsoft.com/en-us/windows/win32/api/ddraw/nf-ddraw-idirectdraw7-waitforverticalblank).

**Scope:** 33 ms updates on a particular system are possible, but neither common 33 ms timing nor a native refresh rate was measured or proven. Historical full-race reports use the former 25 ms reference host. They have not been rerun under the live variable scheduler. Existing 120 Hz experiments remain diagnostic-only and cannot establish a completed native-cadence race.
