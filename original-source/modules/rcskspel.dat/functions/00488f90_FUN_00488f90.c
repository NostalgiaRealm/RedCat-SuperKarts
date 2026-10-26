/*
 * FUN_00488f90 at 00488f90
 * undefined FUN_00488f90(void)
 * Address ranges: 00488f90-004892e8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall
FUN_00488f90(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar3 = *(undefined4 **)(param_1 + 8);
  if ((uint)((*(int *)(param_1 + 0xc) - (int)puVar3) / 0x17c) < param_3) {
    iVar6 = *(int *)(param_1 + 4);
    if ((iVar6 == 0) || (uVar5 = ((int)puVar3 - iVar6) / 0x17c, uVar5 <= param_3)) {
      uVar5 = param_3;
    }
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = ((int)puVar3 - iVar6) / 0x17c;
    }
    iVar6 = iVar6 + uVar5;
    iVar1 = iVar6;
    if (iVar6 < 0) {
      iVar1 = 0;
    }
    puVar2 = operator_new(iVar1 * 0x17c);
    puVar4 = puVar2;
    for (puVar3 = *(undefined4 **)(param_1 + 4); uVar5 = param_3, puVar7 = puVar4, puVar3 != param_2
        ; puVar3 = puVar3 + 0x5f) {
      if (puVar4 != (undefined4 *)0x0) {
        puVar7 = puVar3;
        puVar8 = puVar4;
        for (iVar1 = 0x5f; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      puVar4 = puVar4 + 0x5f;
    }
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      if (puVar7 != (undefined4 *)0x0) {
        puVar3 = param_4;
        puVar8 = puVar7;
        for (iVar1 = 0x5f; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar8 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      puVar7 = puVar7 + 0x5f;
    }
    puVar7 = *(undefined4 **)(param_1 + 8);
    puVar3 = puVar4 + param_3 * 0x5f;
    if (param_2 != puVar7) {
      param_2 = (undefined4 *)((int)puVar3 + (param_3 * -0x17c - (int)puVar4) + (int)param_2);
      do {
        if (puVar3 != (undefined4 *)0x0) {
          puVar4 = param_2;
          puVar8 = puVar3;
          for (iVar1 = 0x5f; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar8 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        param_2 = param_2 + 0x5f;
        puVar3 = puVar3 + 0x5f;
      } while (param_2 != puVar7);
    }
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(undefined4 **)(param_1 + 0xc) = puVar2 + iVar6 * 0x5f;
    if (*(int *)(param_1 + 4) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x17c;
    }
    *(undefined4 **)(param_1 + 4) = puVar2;
    *(undefined4 **)(param_1 + 8) = puVar2 + (param_3 + iVar6) * 0x5f;
    return puVar2 + (param_3 + iVar6) * 0x5f;
  }
  puVar4 = (undefined4 *)(((int)puVar3 - (int)param_2) * -0x53896e7b);
  if ((uint)(((int)puVar3 - (int)param_2) / 0x17c) < param_3) {
    puVar4 = param_2 + param_3 * 0x5f;
    if (param_2 != puVar3) {
      puVar2 = puVar4 + param_3 * -0x5f;
      do {
        if (puVar4 != (undefined4 *)0x0) {
          puVar7 = puVar2;
          puVar8 = puVar4;
          for (iVar6 = 0x5f; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        puVar2 = puVar2 + 0x5f;
        puVar4 = puVar4 + 0x5f;
      } while (puVar2 != puVar3);
    }
    puVar3 = *(undefined4 **)(param_1 + 8);
    for (iVar6 = param_3 - ((int)puVar3 - (int)param_2) / 0x17c; iVar6 != 0; iVar6 = iVar6 + -1) {
      if (puVar3 != (undefined4 *)0x0) {
        puVar4 = param_4;
        puVar2 = puVar3;
        for (iVar1 = 0x5f; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar2 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar2 = puVar2 + 1;
        }
      }
      puVar3 = puVar3 + 0x5f;
    }
    puVar3 = *(undefined4 **)(param_1 + 8);
    while (param_2 != puVar3) {
      puVar7 = param_2 + 0x5f;
      puVar4 = param_4;
      puVar2 = param_2;
      for (iVar6 = 0x5f; param_2 = puVar7, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar2 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar2 = puVar2 + 1;
      }
    }
    puVar3 = (undefined4 *)(*(int *)(param_1 + 8) + param_3 * 0x17c);
    *(undefined4 **)(param_1 + 8) = puVar3;
    return puVar3;
  }
  if (param_3 != 0) {
    puVar4 = puVar3;
    for (puVar2 = puVar3 + param_3 * -0x5f; puVar2 != puVar3; puVar2 = puVar2 + 0x5f) {
      if (puVar4 != (undefined4 *)0x0) {
        puVar7 = puVar2;
        puVar8 = puVar4;
        for (iVar6 = 0x5f; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      puVar4 = puVar4 + 0x5f;
    }
    puVar3 = *(undefined4 **)(param_1 + 8);
    puVar4 = puVar3 + param_3 * -0x5f;
    while (param_2 != puVar4) {
      puVar4 = puVar4 + -0x5f;
      puVar3 = puVar3 + -0x5f;
      puVar2 = puVar4;
      puVar7 = puVar3;
      for (iVar6 = 0x5f; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    puVar4 = param_2;
    while (puVar4 != param_2 + param_3 * 0x5f) {
      puVar7 = puVar4 + 0x5f;
      puVar3 = param_4;
      puVar2 = puVar4;
      for (iVar6 = 0x5f; puVar4 = puVar7, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar2 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar2 = puVar2 + 1;
      }
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x17c;
  }
  return puVar4;
}

