/*
 * USER32.DLL::CharLowerA at 004066d0
 * LPSTR __stdcall CharLowerA(LPSTR lpsz)
 * Address ranges: 004066d0-004066d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::CharLowerA
 */

LPSTR __stdcall CharLowerA(LPSTR lpsz)

{
  LPSTR pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004066d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = CharLowerA(lpsz);
  return pCVar1;
}

