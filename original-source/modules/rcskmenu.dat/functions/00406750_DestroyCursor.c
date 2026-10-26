/*
 * USER32.DLL::DestroyCursor at 00406750
 * BOOL __stdcall DestroyCursor(HCURSOR hCursor)
 * Address ranges: 00406750-00406755
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DestroyCursor
 */

BOOL __stdcall DestroyCursor(HCURSOR hCursor)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DestroyCursor(hCursor);
  return BVar1;
}

