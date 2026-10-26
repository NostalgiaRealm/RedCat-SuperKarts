/*
 * FUN_0044f580 at 0044f580
 * undefined FUN_0044f580(void)
 * Address ranges: 0044f580-0044f8d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0044f580(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  
  puVar10 = *(undefined4 **)(param_1 + 8);
  if ((uint)((*(int *)(param_1 + 0xc) - (int)puVar10) / 0x60) < param_3) {
    iVar6 = *(int *)(param_1 + 4);
    if ((iVar6 == 0) || (uVar5 = ((int)puVar10 - iVar6) / 0x60, uVar5 <= param_3)) {
      uVar5 = param_3;
    }
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = ((int)puVar10 - iVar6) / 0x60;
    }
    iVar6 = iVar6 + uVar5;
    iVar2 = iVar6;
    if (iVar6 < 0) {
      iVar2 = 0;
    }
    pvVar3 = operator_new(iVar2 * 0x60);
    pvVar7 = pvVar3;
    for (puVar10 = *(undefined4 **)(param_1 + 4); uVar5 = param_3, pvVar1 = pvVar7,
        puVar10 != param_2; puVar10 = puVar10 + 0x18) {
      FUN_0044c520(pvVar7,puVar10);
      pvVar7 = (void *)((int)pvVar7 + 0x60);
    }
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      FUN_0044c520(pvVar1,param_4);
      pvVar1 = (void *)((int)pvVar1 + 0x60);
    }
    pvVar7 = (void *)(param_3 * 0x60 + (int)pvVar7);
    puVar10 = *(undefined4 **)(param_1 + 8);
    for (; param_2 != puVar10; param_2 = param_2 + 0x18) {
      FUN_0044c520(pvVar7,param_2);
      pvVar7 = (void *)((int)pvVar7 + 0x60);
    }
    iVar2 = *(int *)(param_1 + 8);
    for (iVar9 = *(int *)(param_1 + 4); iVar9 != iVar2; iVar9 = iVar9 + 0x60) {
      FUN_0044b6b0();
    }
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(void **)(param_1 + 0xc) = (void *)(iVar6 * 0x60 + (int)pvVar3);
    if (*(int *)(param_1 + 4) == 0) {
      iVar2 = 0;
      iVar6 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
      iVar6 = iVar2 * 0x2aaaaaab;
      iVar2 = iVar2 / 0x60;
    }
    *(void **)(param_1 + 4) = pvVar3;
    *(void **)(param_1 + 8) = (void *)((param_3 + iVar2) * 0x60 + (int)pvVar3);
    return iVar6;
  }
  iVar6 = -((int)puVar10 - (int)param_2 >> 0x1f);
  if (param_3 <= (uint)(((int)puVar10 - (int)param_2) / 0x60)) {
    if (param_3 != 0) {
      iVar6 = param_3 * 0x60;
      puVar4 = puVar10;
      for (puVar8 = puVar10 + param_3 * -0x18; puVar8 != puVar10; puVar8 = puVar8 + 0x18) {
        FUN_0044c520(puVar4,puVar8);
        puVar4 = puVar4 + 0x18;
      }
      puVar10 = (undefined4 *)(*(int *)(param_1 + 8) + param_3 * -0x60);
      while (param_2 != puVar10) {
        puVar10 = puVar10 + -0x18;
        FUN_0044c670(puVar10);
      }
      if (param_2 != param_2 + param_3 * 0x18) {
        puVar10 = param_2 + 2;
        do {
          puVar10[-2] = *param_4;
          puVar10[-1] = param_4[1];
          *puVar10 = param_4[2];
          puVar10[1] = param_4[3];
          puVar10[2] = param_4[4];
          puVar10[3] = param_4[5];
          puVar10[4] = param_4[6];
          *(undefined1 *)(puVar10 + 5) = *(undefined1 *)(param_4 + 7);
          FUN_00412870(param_4 + 8,0,0xffffffff);
          FUN_00412870(param_4 + 0xc,0,0xffffffff);
          FUN_00412870(param_4 + 0x10,0,0xffffffff);
          FUN_004775e0(param_4 + 0x14);
          puVar4 = puVar10 + 0x16;
          puVar10 = puVar10 + 0x18;
        } while (puVar4 != param_2 + param_3 * 0x18);
      }
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar6;
    }
    return iVar6;
  }
  puVar4 = param_2 + param_3 * 0x18;
  for (puVar8 = param_2; puVar8 != puVar10; puVar8 = puVar8 + 0x18) {
    FUN_0044c520(puVar4,puVar8);
    puVar4 = puVar4 + 0x18;
  }
  iVar6 = *(int *)(param_1 + 8);
  for (iVar2 = param_3 - (iVar6 - (int)param_2) / 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
    FUN_0044c520(iVar6,param_4);
    iVar6 = iVar6 + 0x60;
  }
  puVar10 = *(undefined4 **)(param_1 + 8);
  for (; param_2 != puVar10; param_2 = param_2 + 0x18) {
    FUN_0044c670(param_4);
  }
  iVar6 = *(int *)(param_1 + 8) + param_3 * 0x60;
  *(int *)(param_1 + 8) = iVar6;
  return iVar6;
}

