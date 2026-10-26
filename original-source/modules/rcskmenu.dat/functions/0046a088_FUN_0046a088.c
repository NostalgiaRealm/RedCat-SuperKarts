/*
 * FUN_0046a088 at 0046a088
 * undefined __register FUN_0046a088(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0046a088-0046a0eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046a088(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  WPARAM WVar4;
  
  iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_4 + -4) + 0x304) + 0x1f0) + 0x14))();
  if (-1 < iVar2 + -1) {
    WVar4 = 0;
    do {
      piVar1 = *(int **)(*(int *)(*(int *)(param_4 + -4) + 0x304) + 0x1f0);
      iVar3 = (**(code **)(*piVar1 + 0x18))(piVar1,WVar4);
      if (param_1 == iVar3) {
        FUN_00424744(*(int **)(*(int *)(param_4 + -4) + 0x304),WVar4);
        return;
      }
      WVar4 = WVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

