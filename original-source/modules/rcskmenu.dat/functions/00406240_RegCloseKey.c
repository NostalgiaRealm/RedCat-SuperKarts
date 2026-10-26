/*
 * ADVAPI32.DLL::RegCloseKey at 00406240
 * LSTATUS __stdcall RegCloseKey(HKEY hKey)
 * Address ranges: 00406240-00406245
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to ADVAPI32.DLL::RegCloseKey
 */

LSTATUS __stdcall RegCloseKey(HKEY hKey)

{
  LSTATUS LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = RegCloseKey(hKey);
  return LVar1;
}

