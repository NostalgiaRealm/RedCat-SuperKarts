/*
 * KERNEL32.DLL::FreeLibrary at 004062d0
 * BOOL __stdcall FreeLibrary(HMODULE hLibModule)
 * Address ranges: 004062d0-004062d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::FreeLibrary
 */

BOOL __stdcall FreeLibrary(HMODULE hLibModule)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004062d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = FreeLibrary(hLibModule);
  return BVar1;
}

