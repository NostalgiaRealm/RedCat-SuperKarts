/*
 * GDI32.DLL::CreateFontIndirectA at 004064d0
 * HFONT __stdcall CreateFontIndirectA(LOGFONTA * lplf)
 * Address ranges: 004064d0-004064d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreateFontIndirectA
 */

HFONT __stdcall CreateFontIndirectA(LOGFONTA *lplf)

{
  HFONT pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateFontIndirectA(lplf);
  return pHVar1;
}

