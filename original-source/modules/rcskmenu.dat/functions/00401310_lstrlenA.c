/*
 * KERNEL32.DLL::lstrlenA at 00401310
 * int __stdcall lstrlenA(LPCSTR lpString)
 * Address ranges: 00401310-00401315
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::lstrlenA
 */

int __stdcall lstrlenA(LPCSTR lpString)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401310. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = lstrlenA(lpString);
  return iVar1;
}

