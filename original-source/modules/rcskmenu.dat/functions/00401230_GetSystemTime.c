/*
 * KERNEL32.DLL::GetSystemTime at 00401230
 * void __stdcall GetSystemTime(LPSYSTEMTIME lpSystemTime)
 * Address ranges: 00401230-00401235
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetSystemTime
 */

void __stdcall GetSystemTime(LPSYSTEMTIME lpSystemTime)

{
                    /* WARNING: Could not recover jumptable at 0x00401230. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetSystemTime(lpSystemTime);
  return;
}

