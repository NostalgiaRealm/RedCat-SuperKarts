/*
 * KERNEL32.DLL::GetVersion at 0040d93a
 * DWORD __stdcall GetVersion(void)
 * Address ranges: 0040d93a-0040d93f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetVersion
 */

DWORD GetVersion(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d93a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetVersion();
  return DVar1;
}

