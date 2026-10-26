/*
 * KERNEL32.DLL::GetStdHandle at 0040d8fe
 * HANDLE __stdcall GetStdHandle(DWORD nStdHandle)
 * Address ranges: 0040d8fe-0040d903
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetStdHandle
 */

HANDLE GetStdHandle(DWORD nStdHandle)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GetStdHandle(nStdHandle);
  return pvVar1;
}

