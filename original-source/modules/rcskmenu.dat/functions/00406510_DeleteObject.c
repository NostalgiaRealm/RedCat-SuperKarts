/*
 * GDI32.DLL::DeleteObject at 00406510
 * BOOL __stdcall DeleteObject(HGDIOBJ ho)
 * Address ranges: 00406510-00406515
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::DeleteObject
 */

BOOL __stdcall DeleteObject(HGDIOBJ ho)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DeleteObject(ho);
  return BVar1;
}

