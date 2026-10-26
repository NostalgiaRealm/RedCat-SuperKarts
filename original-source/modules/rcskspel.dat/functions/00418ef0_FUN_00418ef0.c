/*
 * FUN_00418ef0 at 00418ef0
 * undefined FUN_00418ef0(void)
 * Address ranges: 00418ef0-004191f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00418ef0(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  puVar6 = param_2;
  puVar5 = *(undefined4 **)(param_1 + 8);
  if (param_3 <= (uint)(*(int *)(param_1 + 0xc) - (int)puVar5 >> 4)) {
    if (param_3 <= (uint)((int)puVar5 - (int)param_2 >> 4)) {
      if (param_3 != 0) {
        puVar6 = puVar5;
        for (puVar8 = puVar5 + param_3 * -4; puVar8 != puVar5; puVar8 = puVar8 + 4) {
          if (puVar6 != (undefined4 *)0x0) {
            *puVar6 = *puVar8;
            puVar6[1] = puVar8[1];
            puVar6[2] = puVar8[2];
            puVar6[3] = puVar8[3];
          }
          puVar6 = puVar6 + 4;
        }
        puVar5 = *(undefined4 **)(param_1 + 8);
        puVar6 = *(undefined4 **)(param_1 + 8) + param_3 * -4;
        while (param_2 != puVar6) {
          puVar5[-4] = puVar6[-4];
          puVar5[-3] = puVar6[-3];
          puVar5[-2] = puVar6[-2];
          puVar5[-1] = puVar6[-1];
          puVar5 = puVar5 + -4;
          puVar6 = puVar6 + -4;
        }
        puVar5 = param_2 + param_3 * 4;
        for (; param_2 != puVar5; param_2 = param_2 + 4) {
          *param_2 = *param_4;
          param_2[1] = param_4[1];
          param_2[2] = param_4[2];
          param_2[3] = param_4[3];
        }
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x10;
      }
      return;
    }
    puVar6 = param_2 + param_3 * 4;
    if (param_2 != puVar5) {
      puVar8 = puVar6 + param_3 * -4;
      do {
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = *puVar8;
          puVar6[1] = puVar8[1];
          puVar6[2] = puVar8[2];
          puVar6[3] = puVar8[3];
        }
        puVar8 = puVar8 + 4;
        puVar6 = puVar6 + 4;
      } while (puVar8 != puVar5);
    }
    puVar5 = *(undefined4 **)(param_1 + 8);
    for (iVar2 = param_3 - ((int)puVar5 - (int)param_2 >> 4); iVar2 != 0; iVar2 = iVar2 + -1) {
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = *param_4;
        puVar5[1] = param_4[1];
        puVar5[2] = param_4[2];
        puVar5[3] = param_4[3];
      }
      puVar5 = puVar5 + 4;
    }
    puVar5 = *(undefined4 **)(param_1 + 8);
    for (; param_2 != puVar5; param_2 = param_2 + 4) {
      *param_2 = *param_4;
      param_2[1] = param_4[1];
      param_2[2] = param_4[2];
      param_2[3] = param_4[3];
    }
    *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x10;
    return;
  }
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (uVar7 = (int)puVar5 - iVar2 >> 4, uVar7 <= param_3)) {
    uVar7 = param_3;
  }
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)puVar5 - iVar2 >> 4;
  }
  iVar2 = iVar2 + uVar7;
  iVar3 = iVar2;
  if (iVar2 < 0) {
    iVar3 = 0;
  }
  puVar4 = operator_new(iVar3 << 4);
  puVar8 = puVar4;
  for (puVar5 = *(undefined4 **)(param_1 + 4); puVar5 != param_2; puVar5 = puVar5 + 4) {
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = *puVar5;
      puVar8[1] = puVar5[1];
      puVar8[2] = puVar5[2];
      puVar8[3] = puVar5[3];
    }
    puVar8 = puVar8 + 4;
  }
  if (param_3 != 0) {
    param_2 = (undefined4 *)param_3;
    puVar5 = puVar8;
    do {
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = *param_4;
        puVar5[1] = param_4[1];
        puVar5[2] = param_4[2];
        puVar5[3] = param_4[3];
      }
      puVar5 = puVar5 + 4;
      param_2 = (undefined4 *)((int)param_2 - 1);
    } while (param_2 != (undefined4 *)0x0);
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar5 = puVar8 + param_3 * 4;
  if (puVar6 != puVar1) {
    puVar6 = (undefined4 *)((int)puVar5 + (param_3 * -0x10 - (int)puVar8) + (int)puVar6);
    do {
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = *puVar6;
        puVar5[1] = puVar6[1];
        puVar5[2] = puVar6[2];
        puVar5[3] = puVar6[3];
      }
      puVar6 = puVar6 + 4;
      puVar5 = puVar5 + 4;
    } while (puVar6 != puVar1);
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  iVar3 = *(int *)(param_1 + 4);
  *(undefined4 **)(param_1 + 0xc) = puVar4 + iVar2 * 4;
  if (iVar3 != 0) {
    *(undefined4 **)(param_1 + 4) = puVar4;
    *(undefined4 **)(param_1 + 8) = puVar4 + ((*(int *)(param_1 + 8) - iVar3 >> 4) + param_3) * 4;
    return;
  }
  *(undefined4 **)(param_1 + 4) = puVar4;
  *(undefined4 **)(param_1 + 8) = puVar4 + param_3 * 4;
  return;
}

