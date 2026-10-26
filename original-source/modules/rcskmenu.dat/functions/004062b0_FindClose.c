/*
 * KERNEL32.DLL::FindClose at 004062b0
 * BOOL __stdcall FindClose(HANDLE hFindFile)
 * Address ranges: 004062b0-004062b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::FindClose
 */

BOOL __stdcall FindClose(HANDLE hFindFile)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004062b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = FindClose(hFindFile);
  return BVar1;
}

