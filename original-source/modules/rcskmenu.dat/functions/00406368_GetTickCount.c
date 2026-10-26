/*
 * KERNEL32.DLL::GetTickCount at 00406368
 * DWORD __stdcall GetTickCount(void)
 * Address ranges: 00406368-0040636d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetTickCount
 */

DWORD __stdcall GetTickCount(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406368. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetTickCount();
  return DVar1;
}

