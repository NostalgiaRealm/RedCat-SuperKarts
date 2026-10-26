/*
 * FUN_0048b000 at 0048b000
 * undefined FUN_0048b000(void)
 * Address ranges: 0048b000-0048b1a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0048b000(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  void *pvVar10;
  undefined4 *puVar11;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 0xc) - iVar2 >> 5 == 0) {
    if ((iVar1 == 0) || (uVar5 = iVar2 - iVar1 >> 5, uVar5 < 2)) {
      uVar5 = 1;
    }
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 - iVar1 >> 5;
    }
    iVar2 = iVar2 + uVar5;
    iVar3 = iVar2;
    if (iVar2 < 0) {
      iVar3 = 0;
    }
    pvVar4 = operator_new(iVar3 << 5);
    pvVar10 = pvVar4;
    for (puVar7 = *(undefined4 **)(param_1 + 4); puVar7 != param_2; puVar7 = puVar7 + 8) {
      FUN_0048bc90(pvVar10,puVar7);
      pvVar10 = (void *)((int)pvVar10 + 0x20);
    }
    FUN_0048bc90(pvVar10,param_3);
    FUN_0048ba30(param_2,*(undefined4 *)(param_1 + 8),(int)pvVar10 + 0x20);
    FUN_0048b600(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
    FUN_004bc150(*(undefined4 *)(param_1 + 4));
    *(void **)(param_1 + 0xc) = (void *)(iVar2 * 0x20 + (int)pvVar4);
    iVar2 = FUN_0048b1b0();
    *(void **)(param_1 + 4) = pvVar4;
    *(void **)(param_1 + 8) = (void *)((iVar2 + 1) * 0x20 + (int)pvVar4);
  }
  else {
    if (iVar2 - (int)param_2 >> 5 == 0) {
      FUN_0048ba30(param_2,iVar2,param_2 + 8);
      FUN_0048ba70(*(int *)(param_1 + 8),1 - (*(int *)(param_1 + 8) - (int)param_2 >> 5),param_3);
      puVar7 = *(undefined4 **)(param_1 + 8);
      puVar9 = param_2;
      while (puVar9 != puVar7) {
        puVar6 = puVar9 + 8;
        puVar8 = param_3;
        puVar11 = puVar9;
        for (iVar2 = 8; puVar9 = puVar6, iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar11 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar11 = puVar11 + 1;
        }
      }
    }
    else {
      FUN_0048ba30(iVar2 + -0x20,iVar2,iVar2);
      puVar9 = *(undefined4 **)(param_1 + 8);
      puVar7 = puVar9 + -8;
      while (param_2 != puVar7) {
        puVar7 = puVar7 + -8;
        puVar9 = puVar9 + -8;
        puVar8 = puVar7;
        puVar11 = puVar9;
        for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar11 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar11 = puVar11 + 1;
        }
      }
      puVar7 = param_2;
      while (puVar7 != param_2 + 8) {
        puVar11 = puVar7 + 8;
        puVar9 = param_3;
        puVar8 = puVar7;
        for (iVar2 = 8; puVar7 = puVar11, iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar8 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar8 = puVar8 + 1;
        }
      }
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x20;
  }
  return ((int)param_2 - iVar1 >> 5) * 0x20 + *(int *)(param_1 + 4);
}

