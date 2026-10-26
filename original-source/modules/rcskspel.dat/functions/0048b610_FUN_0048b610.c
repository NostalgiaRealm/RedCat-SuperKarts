/*
 * FUN_0048b610 at 0048b610
 * undefined FUN_0048b610(void)
 * Address ranges: 0048b610-0048b9f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0048b610(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  void *pvVar10;
  undefined4 *puVar11;
  
  iVar6 = param_4;
  puVar8 = *(undefined4 **)(param_1 + 8);
  if ((uint)((*(int *)(param_1 + 0xc) - (int)puVar8) / 0x120) < param_3) {
    iVar6 = *(int *)(param_1 + 4);
    if ((iVar6 == 0) || (uVar5 = ((int)puVar8 - iVar6) / 0x120, uVar5 <= param_3)) {
      uVar5 = param_3;
    }
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = ((int)puVar8 - iVar6) / 0x120;
    }
    iVar6 = iVar6 + uVar5;
    iVar2 = iVar6;
    if (iVar6 < 0) {
      iVar2 = 0;
    }
    pvVar3 = operator_new(iVar2 * 0x120);
    pvVar10 = pvVar3;
    for (puVar8 = *(undefined4 **)(param_1 + 4); uVar5 = param_3, pvVar1 = pvVar10,
        puVar8 != param_2; puVar8 = puVar8 + 0x48) {
      FUN_0048bcb0(pvVar10,puVar8);
      pvVar10 = (void *)((int)pvVar10 + 0x120);
    }
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      FUN_0048bcb0(pvVar1,param_4);
      pvVar1 = (void *)((int)pvVar1 + 0x120);
    }
    pvVar10 = (void *)(param_3 * 0x120 + (int)pvVar10);
    puVar8 = *(undefined4 **)(param_1 + 8);
    for (; param_2 != puVar8; param_2 = param_2 + 0x48) {
      FUN_0048bcb0(pvVar10,param_2);
      pvVar10 = (void *)((int)pvVar10 + 0x120);
    }
    iVar2 = *(int *)(param_1 + 8);
    for (iVar7 = *(int *)(param_1 + 4); iVar7 != iVar2; iVar7 = iVar7 + 0x120) {
      FUN_0048aca0();
    }
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(void **)(param_1 + 0xc) = (void *)(iVar6 * 0x120 + (int)pvVar3);
    if (*(int *)(param_1 + 4) == 0) {
      iVar2 = 0;
      iVar6 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
      iVar6 = iVar2 * 0x38e38e39;
      iVar2 = iVar2 / 0x120;
    }
    *(void **)(param_1 + 4) = pvVar3;
    *(void **)(param_1 + 8) = (void *)((param_3 + iVar2) * 0x120 + (int)pvVar3);
    return iVar6;
  }
  if ((uint)(((int)puVar8 - (int)param_2) / 0x120) < param_3) {
    puVar4 = param_2 + param_3 * 0x48;
    for (puVar9 = param_2; puVar9 != puVar8; puVar9 = puVar9 + 0x48) {
      FUN_0048bcb0(puVar4,puVar9);
      puVar4 = puVar4 + 0x48;
    }
    iVar6 = *(int *)(param_1 + 8);
    for (iVar2 = param_3 - (iVar6 - (int)param_2) / 0x120; iVar2 != 0; iVar2 = iVar2 + -1) {
      FUN_0048bcb0(iVar6,param_4);
      iVar6 = iVar6 + 0x120;
    }
    puVar8 = *(undefined4 **)(param_1 + 8);
    for (; param_2 != puVar8; param_2 = param_2 + 0x48) {
      FUN_0048af00(param_4);
    }
  }
  else {
    if (param_3 == 0) {
      return -((int)puVar8 - (int)param_2 >> 0x1f);
    }
    puVar4 = puVar8;
    for (puVar9 = puVar8 + param_3 * -0x48; puVar9 != puVar8; puVar9 = puVar9 + 0x48) {
      FUN_0048bcb0(puVar4,puVar9);
      puVar4 = puVar4 + 0x48;
    }
    puVar8 = (undefined4 *)(*(int *)(param_1 + 8) + param_3 * -0x120);
    while (param_2 != puVar8) {
      puVar8 = puVar8 + -0x48;
      FUN_0048af00(puVar8);
    }
    if (param_2 != param_2 + param_3 * 0x48) {
      param_4 = param_4 - (int)param_2;
      puVar8 = param_2 + 0x3a;
      do {
        FUN_0048baa0(iVar6);
        iVar2 = 7;
        puVar4 = puVar8 + -0x38;
        do {
          iVar2 = iVar2 + -1;
          puVar9 = (undefined4 *)(param_4 + (int)puVar4);
          puVar11 = puVar4;
          for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
          puVar4 = puVar4 + 8;
        } while (iVar2 != 0);
        *puVar8 = *(undefined4 *)(iVar6 + 0xe8);
        *(undefined1 *)(puVar8 + 1) = *(undefined1 *)(iVar6 + 0xec);
        puVar8[2] = *(undefined4 *)(iVar6 + 0xf0);
        puVar8[3] = *(undefined4 *)(iVar6 + 0xf4);
        puVar8[4] = *(undefined4 *)(iVar6 + 0xf8);
        puVar8[5] = *(undefined4 *)(iVar6 + 0xfc);
        *(undefined1 *)(puVar8 + 6) = *(undefined1 *)(iVar6 + 0x100);
        *(undefined1 *)((int)puVar8 + 0x19) = *(undefined1 *)(iVar6 + 0x101);
        *(undefined1 *)((int)puVar8 + 0x1a) = *(undefined1 *)(iVar6 + 0x102);
        puVar8[7] = *(undefined4 *)(iVar6 + 0x104);
        *(undefined1 *)(puVar8 + 8) = *(undefined1 *)(iVar6 + 0x108);
        puVar8[9] = *(undefined4 *)(iVar6 + 0x10c);
        puVar8[10] = *(undefined4 *)(iVar6 + 0x110);
        puVar8[0xb] = *(undefined4 *)(iVar6 + 0x114);
        param_4 = param_4 + -0x120;
        puVar8[0xc] = *(undefined4 *)(iVar6 + 0x118);
        *(undefined1 *)(puVar8 + 0xd) = *(undefined1 *)(iVar6 + 0x11c);
        puVar4 = puVar8 + 0xe;
        puVar8 = puVar8 + 0x48;
      } while (puVar4 != param_2 + param_3 * 0x48);
    }
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x120;
  return param_3 * 0x120;
}

