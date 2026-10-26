/*
 * KERNEL32.DLL::CloseHandle at 0040d8f8
 * BOOL __stdcall CloseHandle(HANDLE hObject)
 * Address ranges: 0040d8f8-0040d8fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::CloseHandle
 */

BOOL CloseHandle(HANDLE hObject)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = CloseHandle(hObject);
  return BVar1;
}

