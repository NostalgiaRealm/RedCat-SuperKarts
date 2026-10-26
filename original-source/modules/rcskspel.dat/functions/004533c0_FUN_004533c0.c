/*
 * FUN_004533c0 at 004533c0
 * undefined FUN_004533c0(void)
 * Address ranges: 004533c0-004536ef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004533c0(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  
  puVar5 = param_2;
  puVar4 = *(undefined4 **)(param_1 + 8);
  if (param_3 <= (uint)((*(int *)(param_1 + 0xc) - (int)puVar4) / 0xc)) {
    if (param_3 <= (uint)(((int)puVar4 - (int)param_2) / 0xc)) {
      if (param_3 != 0) {
        puVar5 = puVar4;
        for (puVar6 = puVar4 + param_3 * -3; puVar6 != puVar4; puVar6 = puVar6 + 3) {
          if (puVar5 != (undefined4 *)0x0) {
            *puVar5 = *puVar6;
            puVar5[1] = puVar6[1];
            puVar5[2] = puVar6[2];
          }
          puVar5 = puVar5 + 3;
        }
        puVar4 = *(undefined4 **)(param_1 + 8);
        puVar5 = *(undefined4 **)(param_1 + 8) + param_3 * -3;
        while (param_2 != puVar5) {
          puVar4[-3] = puVar5[-3];
          puVar4[-2] = puVar5[-2];
          puVar4[-1] = puVar5[-1];
          puVar4 = puVar4 + -3;
          puVar5 = puVar5 + -3;
        }
        puVar4 = param_2 + param_3 * 3;
        for (; param_2 != puVar4; param_2 = param_2 + 3) {
          *param_2 = *param_4;
          param_2[1] = param_4[1];
          param_2[2] = param_4[2];
        }
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0xc;
      }
      return;
    }
    puVar5 = param_2 + param_3 * 3;
    if (param_2 != puVar4) {
      puVar6 = puVar5 + param_3 * -3;
      do {
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = *puVar6;
          puVar5[1] = puVar6[1];
          puVar5[2] = puVar6[2];
        }
        puVar6 = puVar6 + 3;
        puVar5 = puVar5 + 3;
      } while (puVar6 != puVar4);
    }
    puVar4 = *(undefined4 **)(param_1 + 8);
    for (iVar7 = param_3 - ((int)puVar4 - (int)param_2) / 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = *param_4;
        puVar4[1] = param_4[1];
        puVar4[2] = param_4[2];
      }
      puVar4 = puVar4 + 3;
    }
    puVar4 = *(undefined4 **)(param_1 + 8);
    for (; param_2 != puVar4; param_2 = param_2 + 3) {
      *param_2 = *param_4;
      param_2[1] = param_4[1];
      param_2[2] = param_4[2];
    }
    *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0xc;
    return;
  }
  iVar7 = *(int *)(param_1 + 4);
  if ((iVar7 == 0) || (uVar8 = ((int)puVar4 - iVar7) / 0xc, uVar8 <= param_3)) {
    uVar8 = param_3;
  }
  if (iVar7 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = ((int)puVar4 - iVar7) / 0xc;
  }
  iVar7 = iVar7 + uVar8;
  iVar2 = iVar7;
  if (iVar7 < 0) {
    iVar2 = 0;
  }
  puVar3 = operator_new(iVar2 * 0xc);
  puVar6 = puVar3;
  for (puVar4 = *(undefined4 **)(param_1 + 4); puVar4 != param_2; puVar4 = puVar4 + 3) {
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = *puVar4;
      puVar6[1] = puVar4[1];
      puVar6[2] = puVar4[2];
    }
    puVar6 = puVar6 + 3;
  }
  if (param_3 != 0) {
    param_2 = (undefined4 *)param_3;
    puVar4 = puVar6;
    do {
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = *param_4;
        puVar4[1] = param_4[1];
        puVar4[2] = param_4[2];
      }
      puVar4 = puVar4 + 3;
      param_2 = (undefined4 *)((int)param_2 - 1);
    } while (param_2 != (undefined4 *)0x0);
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar4 = puVar6 + param_3 * 3;
  if (puVar5 != puVar1) {
    puVar5 = (undefined4 *)((int)puVar4 + (param_3 * -0xc - (int)puVar6) + (int)puVar5);
    do {
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = *puVar5;
        puVar4[1] = puVar5[1];
        puVar4[2] = puVar5[2];
      }
      puVar5 = puVar5 + 3;
      puVar4 = puVar4 + 3;
    } while (puVar5 != puVar1);
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 **)(param_1 + 0xc) = puVar3 + iVar7 * 3;
  if (iVar2 != 0) {
    *(undefined4 **)(param_1 + 4) = puVar3;
    *(undefined4 **)(param_1 + 8) = puVar3 + (param_3 + (*(int *)(param_1 + 8) - iVar2) / 0xc) * 3;
    return;
  }
  *(undefined4 **)(param_1 + 4) = puVar3;
  *(undefined4 **)(param_1 + 8) = puVar3 + param_3 * 3;
  return;
}

