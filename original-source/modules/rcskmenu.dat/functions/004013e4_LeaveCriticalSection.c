/*
 * KERNEL32.DLL::LeaveCriticalSection at 004013e4
 * void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
 * Address ranges: 004013e4-004013e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::LeaveCriticalSection
 */

void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)

{
                    /* WARNING: Could not recover jumptable at 0x004013e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection(lpCriticalSection);
  return;
}

