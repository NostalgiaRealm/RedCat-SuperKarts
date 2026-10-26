/*
 * KERNEL32.DLL::InitializeCriticalSection at 004013d4
 * void __stdcall InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
 * Address ranges: 004013d4-004013d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::InitializeCriticalSection
 */

void __stdcall InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)

{
                    /* WARNING: Could not recover jumptable at 0x004013d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeCriticalSection(lpCriticalSection);
  return;
}

