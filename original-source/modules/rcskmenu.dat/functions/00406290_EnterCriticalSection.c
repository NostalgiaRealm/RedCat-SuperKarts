/*
 * KERNEL32.DLL::EnterCriticalSection at 00406290
 * void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
 * Address ranges: 00406290-00406295
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::EnterCriticalSection
 */

void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)

{
                    /* WARNING: Could not recover jumptable at 0x00406290. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnterCriticalSection(lpCriticalSection);
  return;
}

