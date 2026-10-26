/*
 * FUN_0042b47c at 0042b47c
 * undefined FUN_0042b47c(void)
 * Address ranges: 0042b47c-0042b67b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b47c(int *param_1,int *param_2)

{
  int *piVar1;
  bool bVar2;
  int nNumber;
  int iVar3;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x42b48f;
  FUN_004421f4((int)param_1);
  puStack_18 = &LAB_0042b67c;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  bVar2 = false;
  *(byte *)(param_1 + 0x87) = DAT_0047d4d1 ^ 1;
  puStack_14 = &stack0xfffffffc;
  FUN_00441a54(param_1,param_2);
  if ((param_1[0x91] != 0) && (0 < param_1[0x96])) {
    if (((*(byte *)(param_1 + 0x22) & 0x10) != 0) &&
       (param_1[0x91] != *(int *)(DAT_0047d774 + 0x34))) {
      iVar3 = param_1[0x91];
      iVar4 = *(int *)(DAT_0047d774 + 0x34);
      piVar1 = (int *)param_1[0x16];
      nNumber = FUN_004178b0((int)piVar1);
      iVar3 = MulDiv(nNumber,iVar4,iVar3);
      FUN_004178b8(piVar1,iVar3);
    }
    param_1[0x91] = *(int *)(DAT_0047d774 + 0x34);
    iVar3 = FUN_0042b7ac((int)param_1);
    if (iVar3 != param_1[0x96]) {
      bVar2 = true;
      FUN_0042aa04((int)param_1,iVar3,param_1[0x96]);
      FUN_00445274((int)param_1,iVar3,param_1[0x96]);
      if ((*(byte *)(param_1 + 0x22) & 4) != 0) {
        iVar4 = MulDiv(param_1[0x94],iVar3,param_1[0x96]);
        param_1[0x94] = iVar4;
      }
      if ((*(byte *)(param_1 + 0x22) & 8) != 0) {
        iVar3 = MulDiv(param_1[0x95],iVar3,param_1[0x96]);
        param_1[0x95] = iVar3;
      }
    }
  }
  if (0 < param_1[0x94]) {
    FUN_0043f0c8(param_1,param_1[0x94]);
  }
  if (0 < param_1[0x95]) {
    FUN_0043f10c(param_1,param_1[0x95]);
  }
  *(undefined1 *)(param_1 + 0x22) = 0;
  if (!bVar2) {
    FUN_0042aa04((int)param_1,1,1);
    FUN_00445274((int)param_1,1,1);
  }
  FUN_004405f0((int)param_1,0xb03d,0,0);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0042b683;
  puStack_18 = (undefined1 *)0x42b67b;
  FUN_004421fc((int)param_1);
  return;
}

