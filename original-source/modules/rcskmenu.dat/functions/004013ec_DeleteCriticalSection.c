/*
 * KERNEL32.DLL::DeleteCriticalSection at 004013ec
 * void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
 * Address ranges: 004013ec-004013f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::DeleteCriticalSection
 */

void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)

{
                    /* WARNING: Could not recover jumptable at 0x004013ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteCriticalSection(lpCriticalSection);
  return;
}

