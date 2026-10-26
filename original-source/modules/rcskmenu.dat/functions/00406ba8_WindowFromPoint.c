/*
 * USER32.DLL::WindowFromPoint at 00406ba8
 * HWND __stdcall WindowFromPoint(POINT Point)
 * Address ranges: 00406ba8-00406bad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::WindowFromPoint
 */

HWND __stdcall WindowFromPoint(POINT Point)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406ba8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = WindowFromPoint(Point);
  return pHVar1;
}

