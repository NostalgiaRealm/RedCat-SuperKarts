/*
 * GDI32.DLL::CreatePalette at 004064e0
 * HPALETTE __stdcall CreatePalette(LOGPALETTE * plpal)
 * Address ranges: 004064e0-004064e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreatePalette
 */

HPALETTE __stdcall CreatePalette(LOGPALETTE *plpal)

{
  HPALETTE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreatePalette(plpal);
  return pHVar1;
}

