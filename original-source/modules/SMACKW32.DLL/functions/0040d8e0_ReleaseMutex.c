/*
 * KERNEL32.DLL::ReleaseMutex at 0040d8e0
 * BOOL __stdcall ReleaseMutex(HANDLE hMutex)
 * Address ranges: 0040d8e0-0040d8e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::ReleaseMutex
 */

BOOL ReleaseMutex(HANDLE hMutex)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ReleaseMutex(hMutex);
  return BVar1;
}

