/*
 * GDI32.DLL::CreatePenIndirect at 004064e8
 * HPEN __stdcall CreatePenIndirect(LOGPEN * plpen)
 * Address ranges: 004064e8-004064ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreatePenIndirect
 */

HPEN __stdcall CreatePenIndirect(LOGPEN *plpen)

{
  HPEN pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreatePenIndirect(plpen);
  return pHVar1;
}

