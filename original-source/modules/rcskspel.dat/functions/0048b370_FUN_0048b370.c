/*
 * FUN_0048b370 at 0048b370
 * undefined FUN_0048b370(void)
 * Address ranges: 0048b370-0048b5fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0048b370(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar6 = *(undefined4 **)(param_1 + 8);
  if (param_3 <= (uint)(*(int *)(param_1 + 0xc) - (int)puVar6 >> 5)) {
    if ((uint)((int)puVar6 - (int)param_2 >> 5) < param_3) {
      puVar5 = param_2 + param_3 * 8;
      if (param_2 != puVar6) {
        puVar3 = puVar5 + param_3 * -8;
        do {
          if (puVar5 != (undefined4 *)0x0) {
            puVar7 = puVar3;
            puVar8 = puVar5;
            for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
            }
          }
          puVar3 = puVar3 + 8;
          puVar5 = puVar5 + 8;
        } while (puVar3 != puVar6);
      }
      puVar6 = *(undefined4 **)(param_1 + 8);
      for (iVar1 = param_3 - ((int)puVar6 - (int)param_2 >> 5); iVar1 != 0; iVar1 = iVar1 + -1) {
        if (puVar6 != (undefined4 *)0x0) {
          puVar5 = param_4;
          puVar3 = puVar6;
          for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar3 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar3 = puVar3 + 1;
          }
        }
        puVar6 = puVar6 + 8;
      }
      puVar6 = *(undefined4 **)(param_1 + 8);
      while (param_2 != puVar6) {
        puVar7 = param_2 + 8;
        puVar5 = param_4;
        puVar3 = param_2;
        for (iVar1 = 8; param_2 = puVar7, iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar3 = puVar3 + 1;
        }
      }
    }
    else {
      if (param_3 == 0) {
        return;
      }
      puVar5 = puVar6;
      for (puVar3 = puVar6 + param_3 * -8; puVar3 != puVar6; puVar3 = puVar3 + 8) {
        if (puVar5 != (undefined4 *)0x0) {
          puVar7 = puVar3;
          puVar8 = puVar5;
          for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        puVar5 = puVar5 + 8;
      }
      puVar6 = *(undefined4 **)(param_1 + 8);
      puVar5 = puVar6 + param_3 * -8;
      while (param_2 != puVar5) {
        puVar5 = puVar5 + -8;
        puVar6 = puVar6 + -8;
        puVar3 = puVar5;
        puVar7 = puVar6;
        for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar7 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      puVar6 = param_2;
      while (puVar6 != param_2 + param_3 * 8) {
        puVar7 = puVar6 + 8;
        puVar5 = param_4;
        puVar3 = puVar6;
        for (iVar1 = 8; puVar6 = puVar7, iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar3 = puVar3 + 1;
        }
      }
    }
    param_2 = (undefined4 *)(param_3 * 0x20);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + (int)param_2;
    return;
  }
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (uVar4 = (int)puVar6 - iVar1 >> 5, uVar4 <= param_3)) {
    uVar4 = param_3;
  }
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)puVar6 - iVar1 >> 5;
  }
  iVar1 = iVar1 + uVar4;
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar2 = 0;
  }
  puVar3 = operator_new(iVar2 << 5);
  puVar5 = puVar3;
  for (puVar6 = *(undefined4 **)(param_1 + 4); uVar4 = param_3, puVar7 = puVar5, puVar6 != param_2;
      puVar6 = puVar6 + 8) {
    if (puVar5 != (undefined4 *)0x0) {
      puVar7 = puVar6;
      puVar8 = puVar5;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    puVar5 = puVar5 + 8;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    if (puVar7 != (undefined4 *)0x0) {
      puVar6 = param_4;
      puVar8 = puVar7;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    puVar7 = puVar7 + 8;
  }
  puVar7 = *(undefined4 **)(param_1 + 8);
  puVar6 = puVar5 + param_3 * 8;
  if (param_2 != puVar7) {
    param_2 = (undefined4 *)((int)puVar6 + (param_3 * -0x20 - (int)puVar5) + (int)param_2);
    do {
      if (puVar6 != (undefined4 *)0x0) {
        puVar5 = param_2;
        puVar8 = puVar6;
        for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar8 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      param_2 = param_2 + 8;
      puVar6 = puVar6 + 8;
    } while (param_2 != puVar7);
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 **)(param_1 + 0xc) = puVar3 + iVar1 * 8;
  if (iVar2 != 0) {
    *(undefined4 **)(param_1 + 4) = puVar3;
    *(undefined4 **)(param_1 + 8) = puVar3 + ((*(int *)(param_1 + 8) - iVar2 >> 5) + param_3) * 8;
    return;
  }
  *(undefined4 **)(param_1 + 4) = puVar3;
  *(undefined4 **)(param_1 + 8) = puVar3 + param_3 * 8;
  return;
}

