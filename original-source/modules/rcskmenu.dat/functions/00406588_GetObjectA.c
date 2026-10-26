/*
 * GDI32.DLL::GetObjectA at 00406588
 * int __stdcall GetObjectA(HANDLE h, int c, LPVOID pv)
 * Address ranges: 00406588-0040658d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetObjectA
 */

int __stdcall GetObjectA(HANDLE h,int c,LPVOID pv)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406588. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetObjectA(h,c,pv);
  return iVar1;
}

