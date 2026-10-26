/*
 * FUN_00410568 at 00410568
 * undefined __register FUN_00410568(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 00410568-00410591
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410568(int *param_1,int param_2,undefined4 param_3)

{
  FUN_004104a8(param_1,param_2,CONCAT31((int3)((uint)param_3 >> 8),1));
  FUN_0040f848((int *)param_1[2],param_2);
  *(undefined4 *)(param_2 + 4) = 0;
  FUN_0041015c(param_1);
  return;
}

