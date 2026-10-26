/*
 * KERNEL32.DLL::GetFileType at 00401228
 * DWORD __stdcall GetFileType(HANDLE hFile)
 * Address ranges: 00401228-0040122d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetFileType
 */

DWORD __stdcall GetFileType(HANDLE hFile)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401228. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetFileType(hFile);
  return DVar1;
}

