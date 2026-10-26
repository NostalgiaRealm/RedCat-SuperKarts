/*
 * USER32.DLL::CharNextA at 00401280
 * LPSTR __stdcall CharNextA(LPCSTR lpsz)
 * Address ranges: 00401280-00401285
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::CharNextA
 */

LPSTR __stdcall CharNextA(LPCSTR lpsz)

{
  LPSTR pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = CharNextA(lpsz);
  return pCVar1;
}

