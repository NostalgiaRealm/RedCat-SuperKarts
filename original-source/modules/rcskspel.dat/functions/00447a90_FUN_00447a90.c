/*
 * FUN_00447a90 at 00447a90
 * undefined FUN_00447a90(void)
 * Address ranges: 00447a90-00447de3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00447a90(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  
  puVar9 = *(undefined4 **)(param_1 + 8);
  if ((uint)((*(int *)(param_1 + 0xc) - (int)puVar9) / 0x2c) < param_3) {
    iVar6 = *(int *)(param_1 + 4);
    if ((iVar6 == 0) || (uVar5 = ((int)puVar9 - iVar6) / 0x2c, uVar5 <= param_3)) {
      uVar5 = param_3;
    }
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = ((int)puVar9 - iVar6) / 0x2c;
    }
    iVar6 = iVar6 + uVar5;
    iVar2 = iVar6;
    if (iVar6 < 0) {
      iVar2 = 0;
    }
    pvVar3 = operator_new(iVar2 * 0x2c);
    pvVar7 = pvVar3;
    for (puVar9 = *(undefined4 **)(param_1 + 4); uVar5 = param_3, pvVar1 = pvVar7, puVar9 != param_2
        ; puVar9 = puVar9 + 0xb) {
      FUN_00447df0(pvVar7,puVar9);
      pvVar7 = (void *)((int)pvVar7 + 0x2c);
    }
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      FUN_00447df0(pvVar1,param_4);
      pvVar1 = (void *)((int)pvVar1 + 0x2c);
    }
    pvVar7 = (void *)((int)pvVar7 + param_3 * 0x2c);
    puVar9 = *(undefined4 **)(param_1 + 8);
    for (; param_2 != puVar9; param_2 = param_2 + 0xb) {
      FUN_00447df0(pvVar7,param_2);
      pvVar7 = (void *)((int)pvVar7 + 0x2c);
    }
    iVar2 = *(int *)(param_1 + 8);
    for (iVar10 = *(int *)(param_1 + 4); iVar10 != iVar2; iVar10 = iVar10 + 0x2c) {
      FUN_00445a40();
    }
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(void **)(param_1 + 0xc) = (void *)((int)pvVar3 + iVar6 * 0x2c);
    if (*(int *)(param_1 + 4) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x2c;
    }
    *(void **)(param_1 + 4) = pvVar3;
    *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar6) * 0x2c);
    return;
  }
  if (param_3 <= (uint)(((int)puVar9 - (int)param_2) / 0x2c)) {
    if (param_3 != 0) {
      puVar4 = puVar9;
      for (puVar8 = puVar9 + param_3 * -0xb; puVar8 != puVar9; puVar8 = puVar8 + 0xb) {
        FUN_00447df0(puVar4,puVar8);
        puVar4 = puVar4 + 0xb;
      }
      iVar6 = *(int *)(param_1 + 8);
      puVar9 = (undefined4 *)(*(int *)(param_1 + 8) + param_3 * -0x2c);
      while (param_2 != puVar9) {
        FUN_00412870(puVar9 + -0xb,0,0xffffffff);
        FUN_00412870(puVar9 + -7,0,0xffffffff);
        *(undefined4 *)(iVar6 + -0xc) = puVar9[-3];
        *(undefined4 *)(iVar6 + -8) = puVar9[-2];
        *(undefined1 *)(iVar6 + -4) = *(undefined1 *)(puVar9 + -1);
        *(undefined1 *)(iVar6 + -3) = *(undefined1 *)((int)puVar9 + -3);
        iVar6 = iVar6 + -0x2c;
        puVar9 = puVar9 + -0xb;
      }
      if (param_2 != param_2 + param_3 * 0xb) {
        puVar9 = param_2 + 8;
        do {
          FUN_00412870(param_4,0,0xffffffff);
          FUN_00412870(param_4 + 0x10,0,0xffffffff);
          *puVar9 = *(undefined4 *)(param_4 + 0x20);
          puVar9[1] = *(undefined4 *)(param_4 + 0x24);
          *(undefined1 *)(puVar9 + 2) = *(undefined1 *)(param_4 + 0x28);
          *(undefined1 *)((int)puVar9 + 9) = *(undefined1 *)(param_4 + 0x29);
          puVar4 = puVar9 + 3;
          puVar9 = puVar9 + 0xb;
        } while (puVar4 != param_2 + param_3 * 0xb);
      }
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x2c;
    }
    return;
  }
  puVar4 = param_2 + param_3 * 0xb;
  for (puVar8 = param_2; puVar8 != puVar9; puVar8 = puVar8 + 0xb) {
    FUN_00447df0(puVar4,puVar8);
    puVar4 = puVar4 + 0xb;
  }
  iVar6 = *(int *)(param_1 + 8);
  for (iVar2 = param_3 - (iVar6 - (int)param_2) / 0x2c; iVar2 != 0; iVar2 = iVar2 + -1) {
    FUN_00447df0(iVar6,param_4);
    iVar6 = iVar6 + 0x2c;
  }
  puVar9 = *(undefined4 **)(param_1 + 8);
  for (; param_2 != puVar9; param_2 = param_2 + 0xb) {
    FUN_00447f50(param_4);
  }
  *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x2c;
  return;
}

