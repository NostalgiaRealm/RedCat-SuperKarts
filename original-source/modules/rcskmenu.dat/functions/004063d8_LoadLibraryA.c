/*
 * KERNEL32.DLL::LoadLibraryA at 004063d8
 * HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName)
 * Address ranges: 004063d8-004063dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::LoadLibraryA
 */

HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName)

{
  HMODULE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004063d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = LoadLibraryA(lpLibFileName);
  return pHVar1;
}

