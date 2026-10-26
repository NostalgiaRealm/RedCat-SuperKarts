/*
 * KERNEL32.DLL::WaitForSingleObject at 0040d8e6
 * DWORD __stdcall WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
 * Address ranges: 0040d8e6-0040d8eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::WaitForSingleObject
 */

DWORD WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = WaitForSingleObject(hHandle,dwMilliseconds);
  return DVar1;
}

