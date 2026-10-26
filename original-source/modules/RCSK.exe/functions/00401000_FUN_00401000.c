/*
 * FUN_00401000 at 00401000
 * int __cdecl FUN_00401000(UINT param_1, undefined * param_2, undefined4 param_3)
 * Address ranges: 00401000-00401083
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00401000(UINT param_1,undefined *param_2,undefined4 param_3)

{
  DWORD DVar1;
  UINT UVar2;
  int iVar3;
  char *lpRootPathName;
  int local_70;
  char local_6c [108];
  
  lpRootPathName = local_6c;
  local_70 = 0;
  DVar1 = GetLogicalDriveStringsA(0x68,local_6c);
  if ((DVar1 != 0) && (local_6c[0] != '\0')) {
    do {
      UVar2 = GetDriveTypeA(lpRootPathName);
      if (UVar2 == param_1) {
        iVar3 = (*(code *)param_2)(lpRootPathName,param_3);
        if (iVar3 == 0) {
          return local_70;
        }
        local_70 = local_70 + 1;
      }
      iVar3 = lstrlenA(lpRootPathName);
      lpRootPathName = lpRootPathName + iVar3 + 1;
    } while (*lpRootPathName != '\0');
    return local_70;
  }
  return 0;
}

