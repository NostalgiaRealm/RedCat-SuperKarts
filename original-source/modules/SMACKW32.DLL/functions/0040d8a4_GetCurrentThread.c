/*
 * KERNEL32.DLL::GetCurrentThread at 0040d8a4
 * HANDLE __stdcall GetCurrentThread(void)
 * Address ranges: 0040d8a4-0040d8a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetCurrentThread
 */

HANDLE GetCurrentThread(void)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GetCurrentThread();
  return pvVar1;
}

