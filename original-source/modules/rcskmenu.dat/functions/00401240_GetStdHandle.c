/*
 * KERNEL32.DLL::GetStdHandle at 00401240
 * HANDLE __stdcall GetStdHandle(DWORD nStdHandle)
 * Address ranges: 00401240-00401245
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetStdHandle
 */

HANDLE __stdcall GetStdHandle(DWORD nStdHandle)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GetStdHandle(nStdHandle);
  return pvVar1;
}

