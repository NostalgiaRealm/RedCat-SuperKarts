/*
 * FUN_004398f0 at 004398f0
 * undefined FUN_004398f0(void)
 * Address ranges: 004398f0-00439a48
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004398f0(int param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  
  pvVar2 = operator_new(0x1000);
  if (*(int *)(param_1 + 0x2c) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 2;
    pvVar3 = operator_new(8);
    *(void **)(param_1 + 0x24) = pvVar3;
    *(void **)((int)pvVar3 + 4) = pvVar2;
    piVar4 = (int *)(*(int *)(param_1 + 0x24) + 4);
    iVar5 = *piVar4;
    *(int *)(param_1 + 0x14) = iVar5;
    *(int *)(param_1 + 4) = iVar5;
    *(int *)(param_1 + 0x18) = iVar5 + 0x1000;
    *(int *)(param_1 + 8) = iVar5 + 0x1000;
    *(int *)(param_1 + 0x1c) = (int)pvVar2 + 0x800;
    *(int *)(param_1 + 0xc) = (int)pvVar2 + 0x800;
    *(int **)(param_1 + 0x20) = piVar4;
    *(int **)(param_1 + 0x10) = piVar4;
    return;
  }
  uVar6 = *(uint *)(param_1 + 0x20);
  if (uVar6 < (uint)(*(int *)(param_1 + 0x24) + -4 + *(int *)(param_1 + 0x28) * 4)) {
    *(undefined4 **)(param_1 + 0x20) = (undefined4 *)(uVar6 + 4);
    *(undefined4 *)(uVar6 + 4) = pvVar2;
    iVar5 = **(int **)(param_1 + 0x20);
    *(int *)(param_1 + 0x14) = iVar5;
    *(int *)(param_1 + 0x18) = iVar5 + 0x1000;
    *(void **)(param_1 + 0x1c) = pvVar2;
    *(int **)(param_1 + 0x20) = *(int **)(param_1 + 0x20);
    return;
  }
  iVar5 = ((int)(uVar6 - *(int *)(param_1 + 0x10)) >> 2) + 1;
  uVar6 = iVar5 * 8;
  if ((int)uVar6 < 0) {
    uVar6 = 0;
  }
  pvVar3 = operator_new(uVar6);
  piVar4 = (int *)((int)pvVar3 + (iVar5 * 2 & 0xfffffffcU));
  iVar1 = *(int *)(param_1 + 0x20);
  piVar8 = piVar4;
  for (piVar7 = *(int **)(param_1 + 0x10); piVar7 != (int *)(iVar1 + 4); piVar7 = piVar7 + 1) {
    *piVar8 = *piVar7;
    piVar8 = piVar8 + 1;
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 0x24));
  *(void **)(param_1 + 0x24) = pvVar3;
  *(int *)(param_1 + 0x28) = iVar5 * 2;
  piVar7 = piVar4 + iVar5;
  *piVar7 = (int)pvVar2;
  iVar5 = *piVar4;
  *(int *)(param_1 + 4) = iVar5;
  *(int *)(param_1 + 8) = iVar5 + 0x1000;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(int **)(param_1 + 0x10) = piVar4;
  iVar5 = *piVar7;
  *(int *)(param_1 + 0x14) = iVar5;
  *(int *)(param_1 + 0x18) = iVar5 + 0x1000;
  *(void **)(param_1 + 0x1c) = pvVar2;
  *(int **)(param_1 + 0x20) = piVar7;
  return;
}

