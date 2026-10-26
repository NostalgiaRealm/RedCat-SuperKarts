/*
 * KERNEL32.DLL::Sleep at 00406448
 * void __stdcall Sleep(DWORD dwMilliseconds)
 * Address ranges: 00406448-0040644d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::Sleep
 */

void __stdcall Sleep(DWORD dwMilliseconds)

{
                    /* WARNING: Could not recover jumptable at 0x00406448. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Sleep(dwMilliseconds);
  return;
}

