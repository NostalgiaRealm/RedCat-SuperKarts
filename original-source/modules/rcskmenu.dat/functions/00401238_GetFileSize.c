/*
 * KERNEL32.DLL::GetFileSize at 00401238
 * DWORD __stdcall GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh)
 * Address ranges: 00401238-0040123d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetFileSize
 */

DWORD __stdcall GetFileSize(HANDLE hFile,LPDWORD lpFileSizeHigh)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401238. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetFileSize(hFile,lpFileSizeHigh);
  return DVar1;
}

