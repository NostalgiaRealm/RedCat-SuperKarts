/*
 * KERNEL32.DLL::EnterCriticalSection at 004013dc
 * void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
 * Address ranges: 004013dc-004013e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::EnterCriticalSection
 */

void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)

{
                    /* WARNING: Could not recover jumptable at 0x004013dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnterCriticalSection(lpCriticalSection);
  return;
}

