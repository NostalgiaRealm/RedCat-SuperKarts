/*
 * USER32.DLL::SetCursor at 00406ab8
 * HCURSOR __stdcall SetCursor(HCURSOR hCursor)
 * Address ranges: 00406ab8-00406abd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::SetCursor
 */

HCURSOR __stdcall SetCursor(HCURSOR hCursor)

{
  HCURSOR pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406ab8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = SetCursor(hCursor);
  return pHVar1;
}

