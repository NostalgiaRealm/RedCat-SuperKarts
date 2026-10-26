/*
 * KERNEL32.DLL::SetErrorMode at 00406420
 * UINT __stdcall SetErrorMode(UINT uMode)
 * Address ranges: 00406420-00406425
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::SetErrorMode
 */

UINT __stdcall SetErrorMode(UINT uMode)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = SetErrorMode(uMode);
  return UVar1;
}

