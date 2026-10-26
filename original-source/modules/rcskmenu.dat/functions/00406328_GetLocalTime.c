/*
 * KERNEL32.DLL::GetLocalTime at 00406328
 * void __stdcall GetLocalTime(LPSYSTEMTIME lpSystemTime)
 * Address ranges: 00406328-0040632d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetLocalTime
 */

void __stdcall GetLocalTime(LPSYSTEMTIME lpSystemTime)

{
                    /* WARNING: Could not recover jumptable at 0x00406328. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetLocalTime(lpSystemTime);
  return;
}

