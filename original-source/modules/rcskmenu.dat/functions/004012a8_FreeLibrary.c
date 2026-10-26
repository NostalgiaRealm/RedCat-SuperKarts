/*
 * KERNEL32.DLL::FreeLibrary at 004012a8
 * BOOL __stdcall FreeLibrary(HMODULE hLibModule)
 * Address ranges: 004012a8-004012ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::FreeLibrary
 */

BOOL __stdcall FreeLibrary(HMODULE hLibModule)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004012a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = FreeLibrary(hLibModule);
  return BVar1;
}

