/*
 * GDI32.DLL::RealizePalette at 00406610
 * UINT __stdcall RealizePalette(HDC hdc)
 * Address ranges: 00406610-00406615
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::RealizePalette
 */

UINT __stdcall RealizePalette(HDC hdc)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406610. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = RealizePalette(hdc);
  return UVar1;
}

