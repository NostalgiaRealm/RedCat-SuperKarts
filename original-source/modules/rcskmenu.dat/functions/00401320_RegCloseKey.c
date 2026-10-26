/*
 * ADVAPI32.DLL::RegCloseKey at 00401320
 * LSTATUS __stdcall RegCloseKey(HKEY hKey)
 * Address ranges: 00401320-00401325
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to ADVAPI32.DLL::RegCloseKey
 */

LSTATUS __stdcall RegCloseKey(HKEY hKey)

{
  LSTATUS LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = RegCloseKey(hKey);
  return LVar1;
}

