/*
 * GDI32.DLL::RestoreDC at 00406628
 * BOOL __stdcall RestoreDC(HDC hdc, int nSavedDC)
 * Address ranges: 00406628-0040662d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::RestoreDC
 */

BOOL __stdcall RestoreDC(HDC hdc,int nSavedDC)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406628. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = RestoreDC(hdc,nSavedDC);
  return BVar1;
}

