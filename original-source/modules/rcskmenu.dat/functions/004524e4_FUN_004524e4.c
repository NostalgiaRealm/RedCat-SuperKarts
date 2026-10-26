/*
 * FUN_004524e4 at 004524e4
 * undefined __register FUN_004524e4(int param_1, int param_2)
 * Address ranges: 004524e4-004525ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004524e4(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  if (param_2 != *(int *)(param_1 + 0x24)) {
    if (*(int **)(param_1 + 0x20) != (int *)0x0) {
      FUN_00418a14(*(int **)(param_1 + 0x20),0);
    }
    FUN_0041bd54(*(int **)(param_1 + 0x24));
    *(int *)(param_1 + 0x24) = param_2;
    FUN_0041bd50(param_2);
    if (*(int **)(param_1 + 0x20) != (int *)0x0) {
      FUN_00418a14(*(int **)(param_1 + 0x20),*(int *)(*(int *)(param_1 + 0x24) + 0x420));
    }
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x24) + 0x15);
    puVar3 = (undefined4 *)(param_1 + 0x94);
    for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + (uint)bVar4 * -2 + 1;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x24) + 0x444);
    puVar3 = (undefined4 *)(param_1 + 0x494);
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + (uint)bVar4 * -2 + 1;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 8);
    *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x428);
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x430);
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x24) + 0x444);
    puVar3 = (undefined4 *)(param_1 + 0x48);
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + (uint)bVar4 * -2 + 1;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x440);
    *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x474);
    *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x478);
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x47c);
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x480);
  }
  return;
}

