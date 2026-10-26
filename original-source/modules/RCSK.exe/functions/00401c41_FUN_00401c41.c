/*
 * FUN_00401c41 at 00401c41
 * undefined4 __cdecl FUN_00401c41(uint param_1)
 * Address ranges: 00401c41-00401cf3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00401c41(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  
  if (DAT_0040a120 <= param_1) {
    DAT_00408c08 = 0;
    DAT_00408c04 = 9;
    return 0xffffffff;
  }
  iVar5 = (param_1 & 0x1f) * 8;
  if ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) {
    DAT_00408c04 = 9;
    DAT_00408c08 = 0;
    return 0xffffffff;
  }
  iVar1 = FUN_00404696(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_00404696(2);
      iVar2 = FUN_00404696(1);
      if (iVar2 == iVar1) goto LAB_00401cba;
    }
    hObject = (HANDLE)FUN_00404696(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_00401cbc;
    }
  }
LAB_00401cba:
  DVar4 = 0;
LAB_00401cbc:
  FUN_0040461c(param_1);
  *(undefined1 *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + iVar5) = 0;
  if (DVar4 == 0) {
    return 0;
  }
  FUN_00402a47(DVar4);
  return 0xffffffff;
}

