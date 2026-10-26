/*
 * FUN_004047d0 at 004047d0
 * BSTR __register FUN_004047d0(LPCSTR param_1)
 * Address ranges: 004047d0-00404852
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

BSTR FUN_004047d0(LPCSTR param_1)

{
  int cbMultiByte;
  int iVar1;
  LPCSTR lpMultiByteStr;
  UINT UVar2;
  BSTR lpWideCharStr;
  WCHAR *lpWideCharStr_00;
  WCHAR local_810 [1024];
  
  lpWideCharStr_00 = local_810;
  cbMultiByte = FUN_00403dd0((int)param_1);
  iVar1 = FUN_00403dd0((int)param_1);
  if (iVar1 < 0x400) {
    iVar1 = 0x400;
    lpMultiByteStr = FUN_00403f94(param_1);
    UVar2 = MultiByteToWideChar(0,0,lpMultiByteStr,cbMultiByte,lpWideCharStr_00,iVar1);
    lpWideCharStr = SysAllocStringLen(local_810,UVar2);
  }
  else {
    UVar2 = MultiByteToWideChar(0,0,param_1,cbMultiByte,(LPWSTR)0x0,0);
    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,UVar2);
    MultiByteToWideChar(0,0,param_1,cbMultiByte,lpWideCharStr,UVar2);
  }
  return lpWideCharStr;
}

