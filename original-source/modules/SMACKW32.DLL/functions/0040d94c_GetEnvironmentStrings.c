/*
 * KERNEL32.DLL::GetEnvironmentStrings at 0040d94c
 * LPCH __stdcall GetEnvironmentStrings(void)
 * Address ranges: 0040d94c-0040d951
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetEnvironmentStrings
 */

LPCH GetEnvironmentStrings(void)

{
  LPCH pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d94c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetEnvironmentStrings();
  return pCVar1;
}

