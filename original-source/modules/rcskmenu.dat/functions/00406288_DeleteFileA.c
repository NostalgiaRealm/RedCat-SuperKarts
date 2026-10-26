/*
 * KERNEL32.DLL::DeleteFileA at 00406288
 * BOOL __stdcall DeleteFileA(LPCSTR lpFileName)
 * Address ranges: 00406288-0040628d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::DeleteFileA
 */

BOOL __stdcall DeleteFileA(LPCSTR lpFileName)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406288. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DeleteFileA(lpFileName);
  return BVar1;
}

