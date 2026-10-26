/*
 * KERNEL32.DLL::GetVersion at 00406370
 * DWORD __stdcall GetVersion(void)
 * Address ranges: 00406370-00406375
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetVersion
 */

DWORD __stdcall GetVersion(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetVersion();
  return DVar1;
}

