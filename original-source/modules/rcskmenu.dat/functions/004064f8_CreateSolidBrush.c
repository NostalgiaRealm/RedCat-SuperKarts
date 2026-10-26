/*
 * GDI32.DLL::CreateSolidBrush at 004064f8
 * HBRUSH __stdcall CreateSolidBrush(COLORREF color)
 * Address ranges: 004064f8-004064fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreateSolidBrush
 */

HBRUSH __stdcall CreateSolidBrush(COLORREF color)

{
  HBRUSH pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateSolidBrush(color);
  return pHVar1;
}

