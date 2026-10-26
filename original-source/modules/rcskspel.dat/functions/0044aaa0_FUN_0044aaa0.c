/*
 * FUN_0044aaa0 at 0044aaa0
 * undefined FUN_0044aaa0(void)
 * Address ranges: 0044aaa0-0044adc2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044aaa0(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  
  puVar8 = *(undefined4 **)(param_1 + 8);
  if ((uint)((*(int *)(param_1 + 0xc) - (int)puVar8) / 0x78) < param_3) {
    iVar5 = *(int *)(param_1 + 4);
    if ((iVar5 == 0) || (uVar4 = ((int)puVar8 - iVar5) / 0x78, uVar4 <= param_3)) {
      uVar4 = param_3;
    }
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = ((int)puVar8 - iVar5) / 0x78;
    }
    iVar5 = iVar5 + uVar4;
    iVar2 = iVar5;
    if (iVar5 < 0) {
      iVar2 = 0;
    }
    pvVar3 = operator_new(iVar2 * 0x78);
    pvVar6 = pvVar3;
    for (puVar8 = *(undefined4 **)(param_1 + 4); uVar4 = param_3, pvVar1 = pvVar6, puVar8 != param_2
        ; puVar8 = puVar8 + 0x1e) {
      FUN_0044add0(pvVar6,puVar8);
      pvVar6 = (void *)((int)pvVar6 + 0x78);
    }
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      FUN_0044add0(pvVar1,param_4);
      pvVar1 = (void *)((int)pvVar1 + 0x78);
    }
    pvVar6 = (void *)((int)pvVar6 + param_3 * 0x78);
    puVar8 = *(undefined4 **)(param_1 + 8);
    for (; param_2 != puVar8; param_2 = param_2 + 0x1e) {
      FUN_0044add0(pvVar6,param_2);
      pvVar6 = (void *)((int)pvVar6 + 0x78);
    }
    iVar2 = *(int *)(param_1 + 8);
    for (iVar9 = *(int *)(param_1 + 4); iVar9 != iVar2; iVar9 = iVar9 + 0x78) {
      FUN_0044a880();
    }
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(void **)(param_1 + 0xc) = (void *)((int)pvVar3 + iVar5 * 0x78);
    if (*(int *)(param_1 + 4) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x78;
    }
    *(void **)(param_1 + 4) = pvVar3;
    *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar5) * 0x78);
    return;
  }
  if ((uint)(((int)puVar8 - (int)param_2) / 0x78) < param_3) {
    puVar10 = param_2 + param_3 * 0x1e;
    for (puVar7 = param_2; puVar7 != puVar8; puVar7 = puVar7 + 0x1e) {
      FUN_0044add0(puVar10,puVar7);
      puVar10 = puVar10 + 0x1e;
    }
    iVar5 = *(int *)(param_1 + 8);
    for (iVar2 = param_3 - (iVar5 - (int)param_2) / 0x78; iVar2 != 0; iVar2 = iVar2 + -1) {
      FUN_0044add0(iVar5,param_4);
      iVar5 = iVar5 + 0x78;
    }
    puVar8 = *(undefined4 **)(param_1 + 8);
    if (param_2 != puVar8) {
      puVar10 = param_2 + 0x1b;
      do {
        FUN_0044b450(param_4);
        puVar10[-1] = *(undefined4 *)(param_4 + 0x68);
        *puVar10 = *(undefined4 *)(param_4 + 0x6c);
        puVar10[1] = *(undefined4 *)(param_4 + 0x70);
        puVar10[2] = *(undefined4 *)(param_4 + 0x74);
        puVar7 = puVar10 + 3;
        puVar10 = puVar10 + 0x1e;
      } while (puVar7 != puVar8);
    }
    *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x78;
    return;
  }
  if (param_3 != 0) {
    puVar10 = puVar8;
    for (puVar7 = puVar8 + param_3 * -0x1e; puVar7 != puVar8; puVar7 = puVar7 + 0x1e) {
      FUN_0044add0(puVar10,puVar7);
      puVar10 = puVar10 + 0x1e;
    }
    iVar5 = *(int *)(param_1 + 8);
    puVar8 = (undefined4 *)(*(int *)(param_1 + 8) + param_3 * -0x78);
    while (param_2 != puVar8) {
      FUN_0044b450(puVar8 + -0x1e);
      *(undefined4 *)(iVar5 + -0x10) = puVar8[-4];
      *(undefined4 *)(iVar5 + -0xc) = puVar8[-3];
      *(undefined4 *)(iVar5 + -8) = puVar8[-2];
      *(undefined4 *)(iVar5 + -4) = puVar8[-1];
      iVar5 = iVar5 + -0x78;
      puVar8 = puVar8 + -0x1e;
    }
    puVar8 = param_2 + param_3 * 0x1e;
    for (; param_2 != puVar8; param_2 = param_2 + 0x1e) {
      FUN_0044afa0(param_4);
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x78;
  }
  return;
}

