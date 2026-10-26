/*
 * FUN_004108f0 at 004108f0
 * undefined FUN_004108f0(void)
 * Address ranges: 004108f0-00410b56
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004108f0(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  undefined1 local_c [12];
  
  uVar4 = param_1;
  iVar5 = FUN_00407cb0(param_1);
  if (iVar5 == -1) {
    return;
  }
  if ((*(uint *)(&DAT_00505114 + iVar5 * 0x24) & 0x4000) != 0) {
    return;
  }
  iVar6 = FUN_00493a20(param_2);
  iVar11 = param_1 * 0xd0;
  if (*(int *)(iVar11 + 0x10 + DAT_0067ee20) == -1) {
    return;
  }
  iVar10 = *(int *)(iVar11 + 0x38 + DAT_0067ee20);
  if (iVar10 == 0) {
    if (DAT_0053ba08 != 0) {
      bVar12 = DAT_0053ba70 != 1;
LAB_004109b2:
      param_1 = (uint)bVar12;
      goto LAB_004109b6;
    }
    param_1 = (uint)(DAT_0053ba70 == 1);
  }
  else if (iVar10 == 1) {
    if (DAT_0053ba08 != 0) {
      bVar12 = DAT_0053ba70 == 1;
      goto LAB_004109b2;
    }
    param_1 = (uint)(DAT_0053ba70 != 1);
  }
  else {
LAB_004109b6:
    if (DAT_0053ba08 != 0) {
      iVar7 = *(int *)(DAT_00680b28 + 0xe4 + iVar6 * 0x984);
      goto joined_r0x004109d3;
    }
  }
  iVar7 = *(int *)(DAT_00680b28 + 0xe8 + iVar6 * 0x984);
joined_r0x004109d3:
  if (iVar7 != 1) {
    iVar7 = FUN_00493430(iVar6,0,iVar10);
    if ((*(byte *)(iVar7 * 0x50 + DAT_00680ae0) & 4) == 0) {
      iVar8 = FUN_00410b60(iVar7,uVar4,param_3);
      if (iVar8 == 0) {
        *(undefined4 *)(iVar11 + 0x44 + DAT_0067ee20) = 0;
        return;
      }
      FUN_00493860(uVar4);
      puVar9 = (undefined4 *)FUN_004933c0(local_c,iVar6,0,iVar10);
      uVar1 = *puVar9;
      uVar2 = puVar9[1];
      uVar3 = puVar9[2];
      FUN_00493540(uVar4,iVar6,param_1);
      iVar10 = DAT_006a5c38 + *(int *)(iVar11 + 0xc + DAT_0067ee20) * 0xa9;
      *(undefined4 *)(iVar10 + 0x50) = uVar1;
      *(undefined4 *)(iVar10 + 0x54) = uVar2;
      *(undefined4 *)(iVar10 + 0x58) = uVar3;
      *(int *)(iVar11 + 0x20 + DAT_0067ee20) = iVar6;
      *(int *)(iVar11 + 0x1c + DAT_0067ee20) = iVar6;
      FUN_00404130(uVar4,0);
      *(int *)(iVar11 + 0x24 + DAT_0067ee20) = iVar7;
      *(int *)(DAT_00504f98 + *(int *)(iVar11 + 0x10 + DAT_0067ee20) * 0x6c) = iVar7;
      *(int *)(DAT_00504f98 + 4 + *(int *)(iVar11 + 0x10 + DAT_0067ee20) * 0x6c) = iVar7;
      FUN_004937e0(uVar4,0);
      *(undefined4 *)(iVar11 + 0x44 + DAT_0067ee20) = 1;
      (&DAT_0050510c)[iVar5 * 9] = 0;
      *(undefined4 *)(&DAT_00505124 + iVar5 * 0x24) = 0;
      return;
    }
    *(undefined4 *)(iVar11 + 0x44 + DAT_0067ee20) = 0;
  }
  return;
}

