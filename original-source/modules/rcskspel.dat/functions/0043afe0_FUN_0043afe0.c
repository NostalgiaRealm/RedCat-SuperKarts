/*
 * FUN_0043afe0 at 0043afe0
 * undefined FUN_0043afe0(void)
 * Address ranges: 0043afe0-0043b174
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0043afe0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  pvVar4 = operator_new(0x1000);
  if (*(int *)(param_1 + 0x2c) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 2;
    pvVar5 = operator_new(8);
    *(void **)(param_1 + 0x24) = pvVar5;
    *(void **)((int)pvVar5 + 4) = pvVar4;
    piVar6 = (int *)(*(int *)(param_1 + 0x24) + 4);
    iVar7 = *piVar6;
    *(int *)(param_1 + 0x14) = iVar7;
    *(int *)(param_1 + 4) = iVar7;
    *(int *)(param_1 + 0x18) = iVar7 + 0x1000;
    *(int *)(param_1 + 8) = iVar7 + 0x1000;
    *(int *)(param_1 + 0x1c) = (int)pvVar4 + 0x804;
    *(int *)(param_1 + 0xc) = (int)pvVar4 + 0x804;
    *(int **)(param_1 + 0x20) = piVar6;
    *(int **)(param_1 + 0x10) = piVar6;
    return;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  if (*(undefined4 **)(param_1 + 0x24) < puVar1) {
    *(undefined4 **)(param_1 + 0x10) = puVar1 + -1;
    puVar1[-1] = pvVar4;
    iVar7 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 4) = iVar7;
    *(int *)(param_1 + 8) = iVar7 + 0x1000;
    *(int *)(param_1 + 0xc) = (int)pvVar4 + 0x1000;
    *(int **)(param_1 + 0x10) = *(int **)(param_1 + 0x10);
    return;
  }
  puVar9 = *(undefined4 **)(param_1 + 0x20);
  if (puVar9 == puVar1) {
    uVar2 = *puVar1;
    *(undefined4 **)(param_1 + 0x20) = puVar9 + 1;
    *puVar9 = uVar2;
    (*(undefined4 **)(param_1 + 0x10))[1] = **(undefined4 **)(param_1 + 0x10);
    **(undefined4 **)(param_1 + 0x10) = pvVar4;
    iVar7 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 4) = iVar7;
    *(int *)(param_1 + 8) = iVar7 + 0x1000;
    *(int *)(param_1 + 0xc) = (int)pvVar4 + 0x1000;
    *(int **)(param_1 + 0x10) = *(int **)(param_1 + 0x10);
    return;
  }
  iVar7 = ((int)puVar9 - (int)puVar1 >> 2) + 1;
  uVar8 = iVar7 * 8;
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  pvVar5 = operator_new(uVar8);
  puVar1 = (undefined4 *)((int)pvVar5 + (iVar7 * 2 & 0xfffffffcU));
  iVar3 = *(int *)(param_1 + 0x20);
  puVar10 = puVar1;
  for (puVar9 = *(undefined4 **)(param_1 + 0x10); puVar9 != (undefined4 *)(iVar3 + 4);
      puVar9 = puVar9 + 1) {
    *puVar10 = *puVar9;
    puVar10 = puVar10 + 1;
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 0x24));
  *(void **)(param_1 + 0x24) = pvVar5;
  *(int *)(param_1 + 0x28) = iVar7 * 2;
  puVar1 = puVar1 + -1;
  *puVar1 = pvVar4;
  *(void **)(param_1 + 4) = pvVar4;
  *(int *)(param_1 + 8) = (int)pvVar4 + 0x1000;
  *(int *)(param_1 + 0xc) = (int)pvVar4 + 0x1000;
  *(undefined4 **)(param_1 + 0x10) = puVar1;
  iVar3 = puVar1[iVar7];
  *(int *)(param_1 + 0x14) = iVar3;
  *(int *)(param_1 + 0x18) = iVar3 + 0x1000;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 **)(param_1 + 0x20) = puVar1 + iVar7;
  return;
}

