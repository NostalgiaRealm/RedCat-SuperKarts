/*
 * GDI32.DLL::SaveDC at 00406630
 * int __stdcall SaveDC(HDC hdc)
 * Address ranges: 00406630-00406635
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SaveDC
 */

int __stdcall SaveDC(HDC hdc)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SaveDC(hdc);
  return iVar1;
}

