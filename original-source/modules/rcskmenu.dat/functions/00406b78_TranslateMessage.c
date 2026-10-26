/*
 * USER32.DLL::TranslateMessage at 00406b78
 * BOOL __stdcall TranslateMessage(MSG * lpMsg)
 * Address ranges: 00406b78-00406b7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::TranslateMessage
 */

BOOL __stdcall TranslateMessage(MSG *lpMsg)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = TranslateMessage(lpMsg);
  return BVar1;
}

