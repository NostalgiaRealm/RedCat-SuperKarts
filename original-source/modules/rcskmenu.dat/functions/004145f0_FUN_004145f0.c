/*
 * FUN_004145f0 at 004145f0
 * undefined __register FUN_004145f0(int param_1, undefined4 * param_2, uint param_3)
 * Address ranges: 004145f0-00414638
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004145f0(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  while (param_3 != 0) {
    uVar2 = *(uint *)(param_1 + 0xc) - *(uint *)(param_1 + 0x10);
    if (*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 0x10) || uVar2 == 0) {
      FUN_0041463c(param_1);
      uVar2 = *(uint *)(param_1 + 0xc);
    }
    if (param_3 <= uVar2) {
      uVar2 = param_3;
    }
    param_3 = param_3 - uVar2;
    iVar1 = *(int *)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar2;
    puVar4 = (undefined4 *)(*(int *)(param_1 + 8) + iVar1);
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  return;
}

