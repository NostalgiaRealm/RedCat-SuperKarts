/*
 * FUN_00459170 at 00459170
 * undefined FUN_00459170(void)
 * Address ranges: 00459170-00459378
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00459170(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar6 = *(undefined4 **)(param_1 + 8);
  if (param_3 <= (uint)(*(int *)(param_1 + 0xc) - (int)puVar6 >> 2)) {
    if ((uint)((int)puVar6 - (int)param_2 >> 2) < param_3) {
      puVar7 = param_2 + param_3;
      if (param_2 != puVar6) {
        puVar4 = puVar7 + -param_3;
        do {
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = *puVar4;
          }
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        } while (puVar4 != puVar6);
      }
      puVar6 = *(undefined4 **)(param_1 + 8);
      for (iVar2 = param_3 - ((int)puVar6 - (int)param_2 >> 2); iVar2 != 0; iVar2 = iVar2 + -1) {
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = *param_4;
        }
        puVar6 = puVar6 + 1;
      }
      puVar6 = *(undefined4 **)(param_1 + 8);
      for (; param_2 != puVar6; param_2 = param_2 + 1) {
        *param_2 = *param_4;
      }
      *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 4;
      return;
    }
    if (param_3 != 0) {
      puVar7 = puVar6;
      for (puVar4 = puVar6 + -param_3; puVar4 != puVar6; puVar4 = puVar4 + 1) {
        if (puVar7 != (undefined4 *)0x0) {
          *puVar7 = *puVar4;
        }
        puVar7 = puVar7 + 1;
      }
      puVar6 = *(undefined4 **)(param_1 + 8);
      for (puVar7 = puVar6 + -param_3; param_2 != puVar7; puVar7 = puVar7 + -1) {
        puVar6 = puVar6 + -1;
        *puVar6 = puVar7[-1];
      }
      puVar6 = param_2 + param_3;
      for (; param_2 != puVar6; param_2 = param_2 + 1) {
        *param_2 = *param_4;
      }
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 4;
    }
    return;
  }
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (uVar5 = (int)puVar6 - iVar2 >> 2, uVar5 <= param_3)) {
    uVar5 = param_3;
  }
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)puVar6 - iVar2 >> 2;
  }
  iVar2 = iVar2 + uVar5;
  iVar3 = iVar2;
  if (iVar2 < 0) {
    iVar3 = 0;
  }
  puVar4 = operator_new(iVar3 * 4);
  puVar7 = puVar4;
  for (puVar6 = *(undefined4 **)(param_1 + 4); uVar5 = param_3, puVar1 = puVar7, puVar6 != param_2;
      puVar6 = puVar6 + 1) {
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = *puVar6;
    }
    puVar7 = puVar7 + 1;
  }
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_4;
    }
    puVar1 = puVar1 + 1;
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar6 = puVar7 + param_3;
  if (param_2 != puVar1) {
    param_2 = (undefined4 *)((int)puVar6 + (param_3 * -4 - (int)puVar7) + (int)param_2);
    do {
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = *param_2;
      }
      param_2 = param_2 + 1;
      puVar6 = puVar6 + 1;
    } while (param_2 != puVar1);
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  *(undefined4 **)(param_1 + 0xc) = puVar4 + iVar2;
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 0) {
    *(undefined4 **)(param_1 + 4) = puVar4;
    *(undefined4 **)(param_1 + 8) = puVar4 + param_3;
    return;
  }
  *(undefined4 **)(param_1 + 4) = puVar4;
  *(undefined4 **)(param_1 + 8) = puVar4 + (*(int *)(param_1 + 8) - iVar2 >> 2) + param_3;
  return;
}

