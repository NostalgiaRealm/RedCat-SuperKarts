/*
 * FUN_0041213c at 0041213c
 * undefined __register FUN_0041213c(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0041213c-00412173
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041213c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_0040f70c(*(int *)(param_4 + -4),param_1);
  if (iVar1 < 0) {
    iVar1 = FUN_0040f70c(*(int *)(param_4 + -8),param_1);
    if (-1 < iVar1) {
      FUN_0040f504(*(int **)(param_4 + -4),param_1);
    }
  }
  return;
}

