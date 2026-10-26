/*
 * KERNEL32.DLL::GetDriveTypeA at 00406308
 * UINT __stdcall GetDriveTypeA(LPCSTR lpRootPathName)
 * Address ranges: 00406308-0040630d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetDriveTypeA
 */

UINT __stdcall GetDriveTypeA(LPCSTR lpRootPathName)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406308. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = GetDriveTypeA(lpRootPathName);
  return UVar1;
}

