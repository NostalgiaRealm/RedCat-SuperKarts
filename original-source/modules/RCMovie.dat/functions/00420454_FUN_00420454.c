/*
 * FUN_00420454 at 00420454
 * undefined4 __cdecl FUN_00420454(uint param_1)
 * Address ranges: 00420454-00420506
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00420454(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  
  if (DAT_0043f920 <= param_1) {
    DAT_0043e2c4 = 0;
    _DAT_0043e2c0 = 9;
    return 0xffffffff;
  }
  iVar5 = (param_1 & 0x1f) * 8;
  if ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) {
    _DAT_0043e2c0 = 9;
    DAT_0043e2c4 = 0;
    return 0xffffffff;
  }
  iVar1 = FUN_004242f5(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_004242f5(2);
      iVar2 = FUN_004242f5(1);
      if (iVar2 == iVar1) goto LAB_004204cd;
    }
    hObject = (HANDLE)FUN_004242f5(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_004204cf;
    }
  }
LAB_004204cd:
  DVar4 = 0;
LAB_004204cf:
  FUN_0042427b(param_1);
  *(undefined1 *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + iVar5) = 0;
  if (DVar4 == 0) {
    return 0;
  }
  FUN_00424108(DVar4);
  return 0xffffffff;
}

