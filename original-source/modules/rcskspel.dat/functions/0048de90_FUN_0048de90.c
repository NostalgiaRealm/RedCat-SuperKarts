/*
 * FUN_0048de90 at 0048de90
 * undefined FUN_0048de90(void)
 * Address ranges: 0048de90-0048e1dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall
FUN_0048de90(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

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
  if ((uint)((*(int *)(param_1 + 0xc) - (int)puVar2) / 0x11b0) < param_3) {
    iVar6 = *(int *)(param_1 + 4);
    if ((iVar6 == 0) || (uVar4 = ((int)puVar2 - iVar6) / 0x11b0, uVar4 <= param_3)) {
      uVar4 = param_3;
    }
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = ((int)puVar2 - iVar6) / 0x11b0;
    }
    iVar6 = uVar4 + iVar6;
    iVar5 = iVar6;
    if (iVar6 < 0) {
      iVar5 = 0;
    }
    puVar1 = operator_new(iVar5 * 0x11b0);
    puVar3 = puVar1;
    for (puVar2 = *(undefined4 **)(param_1 + 4); uVar4 = param_3, puVar7 = puVar3, puVar2 != param_2
        ; puVar2 = puVar2 + 0x46c) {
      if (puVar3 != (undefined4 *)0x0) {
        puVar7 = puVar2;
        puVar8 = puVar3;
        for (iVar5 = 0x46c; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      puVar3 = puVar3 + 0x46c;
    }
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      if (puVar7 != (undefined4 *)0x0) {
        puVar2 = param_4;
        puVar8 = puVar7;
        for (iVar5 = 0x46c; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      puVar7 = puVar7 + 0x46c;
    }
    puVar7 = *(undefined4 **)(param_1 + 8);
    puVar2 = puVar3 + param_3 * 0x46c;
    if (param_2 != puVar7) {
      param_2 = (undefined4 *)((int)puVar2 + (param_3 * -0x11b0 - (int)puVar3) + (int)param_2);
      do {
        if (puVar2 != (undefined4 *)0x0) {
          puVar3 = param_2;
          puVar8 = puVar2;
          for (iVar5 = 0x46c; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        param_2 = param_2 + 0x46c;
        puVar2 = puVar2 + 0x46c;
      } while (param_2 != puVar7);
    }
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(undefined4 **)(param_1 + 0xc) = puVar1 + iVar6 * 0x46c;
    if (*(int *)(param_1 + 4) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x11b0;
    }
    *(undefined4 **)(param_1 + 4) = puVar1;
    *(undefined4 **)(param_1 + 8) = puVar1 + (param_3 + iVar6) * 0x46c;
    return puVar1 + (param_3 + iVar6) * 0x46c;
  }
  puVar3 = (undefined4 *)(((int)puVar2 - (int)param_2) * -0x186c8d1d);
  if ((uint)(((int)puVar2 - (int)param_2) / 0x11b0) < param_3) {
    puVar3 = param_2 + param_3 * 0x46c;
    if (param_2 != puVar2) {
      puVar1 = puVar3 + param_3 * -0x46c;
      do {
        if (puVar3 != (undefined4 *)0x0) {
          puVar7 = puVar1;
          puVar8 = puVar3;
          for (iVar6 = 0x46c; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        puVar1 = puVar1 + 0x46c;
        puVar3 = puVar3 + 0x46c;
      } while (puVar1 != puVar2);
    }
    puVar2 = *(undefined4 **)(param_1 + 8);
    for (iVar6 = param_3 - ((int)puVar2 - (int)param_2) / 0x11b0; iVar6 != 0; iVar6 = iVar6 + -1) {
      if (puVar2 != (undefined4 *)0x0) {
        puVar3 = param_4;
        puVar1 = puVar2;
        for (iVar5 = 0x46c; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar1 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar1 = puVar1 + 1;
        }
      }
      puVar2 = puVar2 + 0x46c;
    }
    puVar2 = *(undefined4 **)(param_1 + 8);
    while (param_2 != puVar2) {
      puVar7 = param_2 + 0x46c;
      puVar3 = param_4;
      puVar1 = param_2;
      for (iVar6 = 0x46c; param_2 = puVar7, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar1 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar1 = puVar1 + 1;
      }
    }
    puVar2 = (undefined4 *)(*(int *)(param_1 + 8) + param_3 * 0x11b0);
    *(undefined4 **)(param_1 + 8) = puVar2;
    return puVar2;
  }
  if (param_3 != 0) {
    puVar3 = puVar2;
    for (puVar1 = puVar2 + param_3 * -0x46c; puVar1 != puVar2; puVar1 = puVar1 + 0x46c) {
      if (puVar3 != (undefined4 *)0x0) {
        puVar7 = puVar1;
        puVar8 = puVar3;
        for (iVar6 = 0x46c; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      puVar3 = puVar3 + 0x46c;
    }
    puVar2 = *(undefined4 **)(param_1 + 8);
    puVar3 = puVar2 + param_3 * -0x46c;
    while (param_2 != puVar3) {
      puVar2 = puVar2 + -0x46c;
      puVar3 = puVar3 + -0x46c;
      puVar1 = puVar3;
      puVar7 = puVar2;
      for (iVar6 = 0x46c; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    puVar3 = param_2;
    while (puVar3 != param_2 + param_3 * 0x46c) {
      puVar7 = puVar3 + 0x46c;
      puVar2 = param_4;
      puVar1 = puVar3;
      for (iVar6 = 0x46c; puVar3 = puVar7, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar1 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar1 = puVar1 + 1;
      }
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x11b0;
  }
  return puVar3;
}

