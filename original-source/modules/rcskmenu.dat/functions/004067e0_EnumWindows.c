/*
 * USER32.DLL::EnumWindows at 004067e0
 * BOOL __stdcall EnumWindows(WNDENUMPROC lpEnumFunc, LPARAM lParam)
 * Address ranges: 004067e0-004067e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::EnumWindows
 */

BOOL __stdcall EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004067e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = EnumWindows(lpEnumFunc,lParam);
  return BVar1;
}

