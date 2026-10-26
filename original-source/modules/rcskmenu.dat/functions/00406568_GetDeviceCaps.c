/*
 * GDI32.DLL::GetDeviceCaps at 00406568
 * int __stdcall GetDeviceCaps(HDC hdc, int index)
 * Address ranges: 00406568-0040656d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetDeviceCaps
 */

int __stdcall GetDeviceCaps(HDC hdc,int index)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetDeviceCaps(hdc,index);
  return iVar1;
}

