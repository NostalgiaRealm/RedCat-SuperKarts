/*
 * FUN_0044b810 at 0044b810
 * undefined FUN_0044b810(void)
 * Address ranges: 0044b810-0044bb4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_0044b810(int param_1,int *param_2,int param_3,undefined4 *param_4,undefined4 *param_5,
            int param_6,int param_7,int param_8,undefined4 *param_9,int param_10)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint local_30;
  int local_2c;
  undefined4 *local_c;
  
  if (param_10 == param_6) {
    local_2c = (int)param_9 - (int)param_5 >> 2;
  }
  else {
    local_2c = ((param_10 - param_6 >> 2) + 0x3fffff) * 0x400 + ((int)param_4 - (int)param_5 >> 2) +
               ((int)param_9 - param_7 >> 2);
  }
  if (param_6 == *(int *)(param_1 + 0x10)) {
    local_30 = (int)param_5 - *(int *)(param_1 + 0xc) >> 2;
  }
  else {
    local_30 = ((param_6 - *(int *)(param_1 + 0x10) >> 2) + 0x3fffff) * 0x400 +
               (*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 2) +
               ((int)param_5 - param_3 >> 2);
  }
  if (*(int *)(param_1 + 0x20) == param_10) {
    uVar4 = *(int *)(param_1 + 0x1c) - (int)param_9 >> 2;
  }
  else {
    uVar4 = ((*(int *)(param_1 + 0x20) - param_10 >> 2) + 0x3fffff) * 0x400 +
            (param_8 - (int)param_9 >> 2) +
            (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x14) >> 2);
  }
  if (local_30 < uVar4) {
    puVar1 = *(undefined4 **)(param_1 + 0xc);
    while (puVar1 != param_5) {
      iVar3 = FUN_00439880();
      puVar2 = *(undefined4 **)(iVar3 + 8);
      iVar3 = FUN_00439880();
      **(undefined4 **)(iVar3 + 8) = *puVar2;
    }
    for (; local_2c != 0; local_2c = local_2c + -1) {
      iVar6 = *(int *)(param_1 + 0xc) + 4;
      iVar3 = *(int *)(param_1 + 0x2c) + -1;
      *(int *)(param_1 + 0xc) = iVar6;
      *(int *)(param_1 + 0x2c) = iVar3;
      if ((iVar3 == 0) || (iVar6 == *(int *)(param_1 + 8))) {
        FUN_00438c10();
      }
    }
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 0x1c);
    local_c = param_4;
    while (param_9 != puVar1) {
      *param_5 = *param_9;
      param_5 = param_5 + 1;
      if (param_5 == local_c) {
        param_5 = *(undefined4 **)(param_6 + 4);
        param_6 = param_6 + 4;
        local_c = param_5 + 0x400;
      }
      FUN_0043a400();
    }
    for (; local_2c != 0; local_2c = local_2c + -1) {
      if (*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x14)) {
        FUN_00439f90();
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -4;
      }
      iVar3 = *(int *)(param_1 + 0x2c) + -1;
      *(int *)(param_1 + 0x2c) = iVar3;
      if (iVar3 == 0) {
        FUN_00439f90();
      }
    }
  }
  param_3 = *(int *)(param_1 + 4);
  if (local_30 == 0) {
    param_5 = *(undefined4 **)(param_1 + 0xc);
    param_4 = *(undefined4 **)(param_1 + 8);
    param_6 = *(int *)(param_1 + 0x10);
  }
  else {
    param_4 = *(undefined4 **)(param_1 + 8);
    param_6 = *(int *)(param_1 + 0x10);
    param_5 = (undefined4 *)(*(int *)(param_1 + 0xc) + local_30 * 4);
    uVar4 = (int)param_5 - param_3 >> 2;
    if ((int)uVar4 < 0) {
      uVar5 = -(0x3ff - uVar4 >> 10);
    }
    else {
      uVar5 = uVar4 >> 10;
    }
    if (uVar5 != 0) {
      param_3 = *(int *)(param_6 + uVar5 * 4);
      param_6 = param_6 + uVar5 * 4;
      param_4 = (undefined4 *)(param_3 + 0x1000);
      param_5 = (undefined4 *)(param_3 + (uVar4 + uVar5 * -0x400) * 4);
    }
  }
  *param_2 = param_3;
  param_2[1] = (int)param_4;
  param_2[2] = (int)param_5;
  param_2[3] = param_6;
  return;
}

