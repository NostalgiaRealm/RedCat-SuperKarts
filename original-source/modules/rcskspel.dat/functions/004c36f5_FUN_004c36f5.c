/*
 * FUN_004c36f5 at 004c36f5
 * undefined FUN_004c36f5(void)
 * Address ranges: 004c36f5-004c37a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c36f5(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  
  if (DAT_006b6b60 <= param_1) {
    DAT_006b66ec = 0;
    _DAT_006b66e8 = 9;
    return 0xffffffff;
  }
  iVar5 = (param_1 & 0x1f) * 8;
  if ((*(byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) {
    _DAT_006b66e8 = 9;
    DAT_006b66ec = 0;
    return 0xffffffff;
  }
  iVar1 = FUN_004c0be4(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_004c0be4(2);
      iVar2 = FUN_004c0be4(1);
      if (iVar2 == iVar1) goto LAB_004c376e;
    }
    hObject = (HANDLE)FUN_004c0be4(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_004c3770;
    }
  }
LAB_004c376e:
  DVar4 = 0;
LAB_004c3770:
  FUN_004c0b6a(param_1);
  *(undefined1 *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + iVar5) = 0;
  if (DVar4 == 0) {
    return 0;
  }
  FUN_004c6e51(DVar4);
  return 0xffffffff;
}

