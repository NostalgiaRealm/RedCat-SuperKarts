/*
 * FUN_00487dc0 at 00487dc0
 * undefined FUN_00487dc0(void)
 * Address ranges: 00487dc0-004880f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall
FUN_00487dc0(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar2 = *(undefined4 **)(param_1 + 8);
  if ((uint)((*(int *)(param_1 + 0xc) - (int)puVar2) / 0x794) < param_3) {
    iVar6 = *(int *)(param_1 + 4);
    if ((iVar6 == 0) || (uVar4 = ((int)puVar2 - iVar6) / 0x794, uVar4 <= param_3)) {
      uVar4 = param_3;
    }
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = ((int)puVar2 - iVar6) / 0x794;
    }
    iVar6 = uVar4 + iVar6;
    iVar5 = iVar6;
    if (iVar6 < 0) {
      iVar5 = 0;
    }
    puVar1 = operator_new(iVar5 * 0x794);
    puVar3 = puVar1;
    for (puVar2 = *(undefined4 **)(param_1 + 4); uVar4 = param_3, puVar7 = puVar3, puVar2 != param_2
        ; puVar2 = puVar2 + 0x1e5) {
      if (puVar3 != (undefined4 *)0x0) {
        puVar7 = puVar2;
        puVar8 = puVar3;
        for (iVar5 = 0x1e5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      puVar3 = puVar3 + 0x1e5;
    }
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      if (puVar7 != (undefined4 *)0x0) {
        puVar2 = param_4;
        puVar8 = puVar7;
        for (iVar5 = 0x1e5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      puVar7 = puVar7 + 0x1e5;
    }
    puVar7 = *(undefined4 **)(param_1 + 8);
    puVar2 = puVar3 + param_3 * 0x1e5;
    if (param_2 != puVar7) {
      param_2 = (undefined4 *)((int)puVar2 + (param_3 * -0x794 - (int)puVar3) + (int)param_2);
      do {
        if (puVar2 != (undefined4 *)0x0) {
          puVar3 = param_2;
          puVar8 = puVar2;
          for (iVar5 = 0x1e5; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        param_2 = param_2 + 0x1e5;
        puVar2 = puVar2 + 0x1e5;
      } while (param_2 != puVar7);
    }
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(undefined4 **)(param_1 + 0xc) = puVar1 + iVar6 * 0x1e5;
    if (*(int *)(param_1 + 4) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x794;
    }
    *(undefined4 **)(param_1 + 4) = puVar1;
    *(undefined4 **)(param_1 + 8) = puVar1 + (param_3 + iVar6) * 0x1e5;
    return puVar1 + (param_3 + iVar6) * 0x1e5;
  }
  puVar3 = (undefined4 *)(((int)puVar2 - (int)param_2) * -0x78dfcd53);
  if ((uint)(((int)puVar2 - (int)param_2) / 0x794) < param_3) {
    puVar3 = param_2 + param_3 * 0x1e5;
    if (param_2 != puVar2) {
      puVar1 = puVar3 + param_3 * -0x1e5;
      do {
        if (puVar3 != (undefined4 *)0x0) {
          puVar7 = puVar1;
          puVar8 = puVar3;
          for (iVar6 = 0x1e5; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        puVar1 = puVar1 + 0x1e5;
        puVar3 = puVar3 + 0x1e5;
      } while (puVar1 != puVar2);
    }
    puVar2 = *(undefined4 **)(param_1 + 8);
    for (iVar6 = param_3 - ((int)puVar2 - (int)param_2) / 0x794; iVar6 != 0; iVar6 = iVar6 + -1) {
      if (puVar2 != (undefined4 *)0x0) {
        puVar3 = param_4;
        puVar1 = puVar2;
        for (iVar5 = 0x1e5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar1 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar1 = puVar1 + 1;
        }
      }
      puVar2 = puVar2 + 0x1e5;
    }
    puVar2 = *(undefined4 **)(param_1 + 8);
    while (param_2 != puVar2) {
      puVar7 = param_2 + 0x1e5;
      puVar3 = param_4;
      puVar1 = param_2;
      for (iVar6 = 0x1e5; param_2 = puVar7, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar1 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar1 = puVar1 + 1;
      }
    }
    puVar2 = (undefined4 *)(*(int *)(param_1 + 8) + param_3 * 0x794);
    *(undefined4 **)(param_1 + 8) = puVar2;
    return puVar2;
  }
  if (param_3 != 0) {
    puVar3 = puVar2;
    for (puVar1 = puVar2 + param_3 * -0x1e5; puVar1 != puVar2; puVar1 = puVar1 + 0x1e5) {
      if (puVar3 != (undefined4 *)0x0) {
        puVar7 = puVar1;
        puVar8 = puVar3;
        for (iVar6 = 0x1e5; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      puVar3 = puVar3 + 0x1e5;
    }
    puVar2 = *(undefined4 **)(param_1 + 8);
    puVar3 = puVar2 + param_3 * -0x1e5;
    while (param_2 != puVar3) {
      puVar3 = puVar3 + -0x1e5;
      puVar2 = puVar2 + -0x1e5;
      puVar1 = puVar3;
      puVar7 = puVar2;
      for (iVar6 = 0x1e5; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    puVar3 = param_2;
    while (puVar3 != param_2 + param_3 * 0x1e5) {
      puVar7 = puVar3 + 0x1e5;
      puVar2 = param_4;
      puVar1 = puVar3;
      for (iVar6 = 0x1e5; puVar3 = puVar7, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar1 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar1 = puVar1 + 1;
      }
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x794;
  }
  return puVar3;
}

