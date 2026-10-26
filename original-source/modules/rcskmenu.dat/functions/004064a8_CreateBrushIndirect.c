/*
 * GDI32.DLL::CreateBrushIndirect at 004064a8
 * HBRUSH __stdcall CreateBrushIndirect(LOGBRUSH * plbrush)
 * Address ranges: 004064a8-004064ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CreateBrushIndirect
 */

HBRUSH __stdcall CreateBrushIndirect(LOGBRUSH *plbrush)

{
  HBRUSH pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004064a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateBrushIndirect(plbrush);
  return pHVar1;
}

