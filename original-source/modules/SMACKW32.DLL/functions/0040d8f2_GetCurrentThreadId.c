/*
 * KERNEL32.DLL::GetCurrentThreadId at 0040d8f2
 * DWORD __stdcall GetCurrentThreadId(void)
 * Address ranges: 0040d8f2-0040d8f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetCurrentThreadId
 */

DWORD GetCurrentThreadId(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetCurrentThreadId();
  return DVar1;
}

