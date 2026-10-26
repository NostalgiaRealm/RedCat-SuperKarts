/*
 * KERNEL32.DLL::InitializeCriticalSection at 004063c8
 * void __stdcall InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
 * Address ranges: 004063c8-004063cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::InitializeCriticalSection
 */

void __stdcall InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)

{
                    /* WARNING: Could not recover jumptable at 0x004063c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeCriticalSection(lpCriticalSection);
  return;
}

