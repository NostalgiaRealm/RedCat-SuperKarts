/*
 * KERNEL32.DLL::GetCurrentThreadId at 004062f0
 * DWORD __stdcall GetCurrentThreadId(void)
 * Address ranges: 004062f0-004062f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetCurrentThreadId
 */

DWORD __stdcall GetCurrentThreadId(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004062f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetCurrentThreadId();
  return DVar1;
}

