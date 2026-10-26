/*
 * USER32.DLL::FindWindowA at 004067f8
 * HWND __stdcall FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName)
 * Address ranges: 004067f8-004067fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::FindWindowA
 */

HWND __stdcall FindWindowA(LPCSTR lpClassName,LPCSTR lpWindowName)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004067f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = FindWindowA(lpClassName,lpWindowName);
  return pHVar1;
}

