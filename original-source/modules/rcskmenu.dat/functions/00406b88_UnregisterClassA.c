/*
 * USER32.DLL::UnregisterClassA at 00406b88
 * BOOL __stdcall UnregisterClassA(LPCSTR lpClassName, HINSTANCE hInstance)
 * Address ranges: 00406b88-00406b8d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::UnregisterClassA
 */

BOOL __stdcall UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = UnregisterClassA(lpClassName,hInstance);
  return BVar1;
}

