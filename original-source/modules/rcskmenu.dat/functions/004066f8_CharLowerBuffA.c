/*
 * USER32.DLL::CharLowerBuffA at 004066f8
 * DWORD __stdcall CharLowerBuffA(LPSTR lpsz, DWORD cchLength)
 * Address ranges: 004066f8-004066fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::CharLowerBuffA
 */

DWORD __stdcall CharLowerBuffA(LPSTR lpsz,DWORD cchLength)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004066f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = CharLowerBuffA(lpsz,cchLength);
  return DVar1;
}

