/*
 * FUN_00426390 at 00426390
 * undefined __register FUN_00426390(int param_1, int param_2)
 * Address ranges: 00426390-004263d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426390(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = FUN_00426320(param_1);
  if (-1 < iVar3) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x4c) + 0x24);
    iVar2 = piVar1[2];
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (iVar2 <= param_2) {
      param_2 = iVar2 + -1;
    }
    if (iVar3 != param_2) {
      FUN_0040f550(piVar1,iVar3);
      FUN_0040f72c(*(int **)(*(int *)(param_1 + 0x4c) + 0x24),param_2,param_1);
    }
  }
  return;
}

