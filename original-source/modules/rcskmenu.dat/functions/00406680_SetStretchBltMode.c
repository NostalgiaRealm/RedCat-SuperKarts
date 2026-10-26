/*
 * GDI32.DLL::SetStretchBltMode at 00406680
 * int __stdcall SetStretchBltMode(HDC hdc, int mode)
 * Address ranges: 00406680-00406685
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetStretchBltMode
 */

int __stdcall SetStretchBltMode(HDC hdc,int mode)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406680. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetStretchBltMode(hdc,mode);
  return iVar1;
}

