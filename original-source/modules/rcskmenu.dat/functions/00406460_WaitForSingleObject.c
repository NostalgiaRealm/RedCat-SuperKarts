/*
 * KERNEL32.DLL::WaitForSingleObject at 00406460
 * DWORD __stdcall WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
 * Address ranges: 00406460-00406465
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::WaitForSingleObject
 */

DWORD __stdcall WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406460. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = WaitForSingleObject(hHandle,dwMilliseconds);
  return DVar1;
}

