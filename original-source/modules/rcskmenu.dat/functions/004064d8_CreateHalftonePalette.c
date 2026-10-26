/*
 * GDI32.DLL::CreateHalftonePalette at 004064d8
 * HPALETTE __stdcall CreateHalftonePalette(HDC hdc)
 * Address ranges: 004064d8-004064dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreateHalftonePalette
 */

HPALETTE __stdcall CreateHalftonePalette(HDC hdc)

{
  HPALETTE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateHalftonePalette(hdc);
  return pHVar1;
}

