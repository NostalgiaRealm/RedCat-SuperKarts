/*
 * KERNEL32.DLL::CloseHandle at 00401218
 * BOOL __stdcall CloseHandle(HANDLE hObject)
 * Address ranges: 00401218-0040121d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::CloseHandle
 */

BOOL __stdcall CloseHandle(HANDLE hObject)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401218. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = CloseHandle(hObject);
  return BVar1;
}

