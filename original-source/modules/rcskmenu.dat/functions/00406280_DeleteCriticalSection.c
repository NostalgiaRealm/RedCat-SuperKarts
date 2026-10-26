/*
 * KERNEL32.DLL::DeleteCriticalSection at 00406280
 * void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
 * Address ranges: 00406280-00406285
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::DeleteCriticalSection
 */

void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)

{
                    /* WARNING: Could not recover jumptable at 0x00406280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteCriticalSection(lpCriticalSection);
  return;
}

