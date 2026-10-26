/*
 * KERNEL32.DLL::SetCurrentDirectoryA at 00406410
 * BOOL __stdcall SetCurrentDirectoryA(LPCSTR lpPathName)
 * Address ranges: 00406410-00406415
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::SetCurrentDirectoryA
 */

BOOL __stdcall SetCurrentDirectoryA(LPCSTR lpPathName)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetCurrentDirectoryA(lpPathName);
  return BVar1;
}

