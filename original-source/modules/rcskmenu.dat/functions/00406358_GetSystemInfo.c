/*
 * KERNEL32.DLL::GetSystemInfo at 00406358
 * void __stdcall GetSystemInfo(LPSYSTEM_INFO lpSystemInfo)
 * Address ranges: 00406358-0040635d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetSystemInfo
 */

void __stdcall GetSystemInfo(LPSYSTEM_INFO lpSystemInfo)

{
                    /* WARNING: Could not recover jumptable at 0x00406358. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetSystemInfo(lpSystemInfo);
  return;
}

