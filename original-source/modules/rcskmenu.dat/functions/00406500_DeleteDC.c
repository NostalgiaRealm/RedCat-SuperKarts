/*
 * GDI32.DLL::DeleteDC at 00406500
 * BOOL __stdcall DeleteDC(HDC hdc)
 * Address ranges: 00406500-00406505
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::DeleteDC
 */

BOOL __stdcall DeleteDC(HDC hdc)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406500. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DeleteDC(hdc);
  return BVar1;
}

