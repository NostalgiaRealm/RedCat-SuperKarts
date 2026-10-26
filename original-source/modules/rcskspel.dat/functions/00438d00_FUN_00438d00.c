/*
 * FUN_00438d00 at 00438d00
 * undefined FUN_00438d00(void)
 * Address ranges: 00438d00-00438fa8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00438d00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uStack_34;
  
  iVar7 = *(int *)(param_1 + 0x20);
  iVar8 = *(int *)(param_1 + 0x24);
  iVar5 = *(int *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar8 == iVar1) {
    iVar9 = iVar7 - iVar5 >> 2;
  }
  else {
    iVar9 = ((iVar8 - iVar1 >> 2) + 0x3fffff) * 0x400 + (*(int *)(param_1 + 0xc) - iVar5 >> 2) +
            (iVar7 - *(int *)(param_1 + 0x18) >> 2);
  }
  if (iVar1 == *(int *)(param_1 + 0x14)) {
    uStack_34 = iVar5 - *(int *)(param_1 + 0x10) >> 2;
  }
  else {
    uStack_34 = ((iVar1 - *(int *)(param_1 + 0x14) >> 2) + 0x3fffff) * 0x400 +
                (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2) +
                (iVar5 - *(int *)(param_1 + 8) >> 2);
  }
  if (*(int *)(param_1 + 0x24) == iVar8) {
    uVar6 = *(int *)(param_1 + 0x20) - iVar7 >> 2;
  }
  else {
    uVar6 = ((*(int *)(param_1 + 0x24) - iVar8 >> 2) + 0x3fffff) * 0x400 +
            (*(int *)(param_1 + 0x1c) - iVar7 >> 2) +
            (*(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x18) >> 2);
  }
  if (uStack_34 < uVar6) {
    iVar7 = *(int *)(param_1 + 0x10);
    iVar8 = *(int *)(param_1 + 0x10);
    while (iVar8 != iVar7) {
      iVar5 = FUN_00439880();
      puVar2 = *(undefined4 **)(iVar5 + 8);
      iVar5 = FUN_00439880();
      **(undefined4 **)(iVar5 + 8) = *puVar2;
    }
    for (; iVar9 != 0; iVar9 = iVar9 + -1) {
      iVar8 = *(int *)(param_1 + 0x10) + 4;
      iVar7 = *(int *)(param_1 + 0x30) + -1;
      *(int *)(param_1 + 0x10) = iVar8;
      *(int *)(param_1 + 0x30) = iVar7;
      if ((iVar7 == 0) || (iVar8 == *(int *)(param_1 + 0xc))) {
        FUN_00438c10();
      }
    }
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0x10);
    puVar3 = *(undefined4 **)(param_1 + 0x20);
    puVar4 = *(undefined4 **)(param_1 + 0x20);
    while (puVar4 != puVar3) {
      *puVar2 = *puVar4;
      FUN_0043a400();
      FUN_0043a400();
    }
    for (; iVar9 != 0; iVar9 = iVar9 + -1) {
      if (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x18)) {
        FUN_00439f90();
      }
      if (*(int *)(param_1 + 0x30) != 0) {
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -4;
      }
      iVar7 = *(int *)(param_1 + 0x30) + -1;
      *(int *)(param_1 + 0x30) = iVar7;
      if (iVar7 == 0) {
        FUN_00439f90();
      }
    }
  }
  if (uStack_34 != 0) {
    FUN_0043a020(uStack_34);
  }
  return;
}

