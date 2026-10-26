/*
 * GDI32.DLL::SetBkMode at 00406650
 * int __stdcall SetBkMode(HDC hdc, int mode)
 * Address ranges: 00406650-00406655
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetBkMode
 */

int __stdcall SetBkMode(HDC hdc,int mode)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406650. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetBkMode(hdc,mode);
  return iVar1;
}

