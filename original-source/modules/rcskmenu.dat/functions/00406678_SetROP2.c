/*
 * GDI32.DLL::SetROP2 at 00406678
 * int __stdcall SetROP2(HDC hdc, int rop2)
 * Address ranges: 00406678-0040667d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetROP2
 */

int __stdcall SetROP2(HDC hdc,int rop2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406678. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetROP2(hdc,rop2);
  return iVar1;
}

