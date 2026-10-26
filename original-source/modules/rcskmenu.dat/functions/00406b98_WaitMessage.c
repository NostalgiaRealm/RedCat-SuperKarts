/*
 * USER32.DLL::WaitMessage at 00406b98
 * BOOL __stdcall WaitMessage(void)
 * Address ranges: 00406b98-00406b9d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::WaitMessage
 */

BOOL __stdcall WaitMessage(void)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = WaitMessage();
  return BVar1;
}

