/**
 * Default x87 precision control for the native gameplay arithmetic: 24 or 53.
 * Values the original keeps in x87 registers round to this width; values it
 * stores with FSTP/FST float always round to float. Tests that compare with
 * fixtures of the other width pass `precision` explicitly.
 *
 * rcskspel.dat's CRT startup selects 53-bit (_FPinit 0x4be597 calls
 * 0x4c17bc, _controlfp(_PC_53, _MCW_PC)), and the game never asks DirectDraw
 * for DDSCL_FPUSETUP, so the shipped DirectX 7 runtime keeps it. See
 * docs/original-comparison-2026-10-28.md, "Gameplay precision (runtime check)".
 */
export const NATIVE_PRECISION = 53;
