/*
 * USER32.DLL::GetCursor at 00406830
 * HCURSOR __stdcall GetCursor(void)
 * Address ranges: 00406830-00406835
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetCursor
 */

HCURSOR __stdcall GetCursor(void)

{
  HCURSOR pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetCursor();
  return pHVar1;
}

