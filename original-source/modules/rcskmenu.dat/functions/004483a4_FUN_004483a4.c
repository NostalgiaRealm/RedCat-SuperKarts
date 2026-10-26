/*
 * FUN_004483a4 at 004483a4
 * undefined __register FUN_004483a4(int param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 004483a4-0044842a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004483a4(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  FUN_00417bbc(*(int **)(*(int *)(param_5 + -4) + 0x10),0x80000014);
  FUN_00418610(*(int **)(param_5 + -4),param_3,param_2);
  FUN_004185b0(*(int **)(param_5 + -4),param_1,param_2);
  FUN_004185b0(*(int **)(param_5 + -4),param_1,param_4);
  FUN_00417bbc(*(int **)(*(int *)(param_5 + -4) + 0x10),0x80000010);
  FUN_004185b0(*(int **)(param_5 + -4),param_3,param_4);
  FUN_004185b0(*(int **)(param_5 + -4),param_3,param_2 + -1);
  return;
}

