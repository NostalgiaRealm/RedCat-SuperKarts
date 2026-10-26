/*
 * FUN_00412174 at 00412174
 * undefined __register FUN_00412174(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00412174-004121b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412174(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_0040f70c(*(int *)(param_4 + -4),param_1);
  if (iVar1 != -1) {
    FUN_0040f550(*(int **)(param_4 + -4),iVar1);
  }
  iVar1 = FUN_0040f70c(*(int *)(param_4 + -8),param_1);
  if (iVar1 < 0) {
    FUN_0040f504(*(int **)(param_4 + -8),param_1);
  }
  return;
}

