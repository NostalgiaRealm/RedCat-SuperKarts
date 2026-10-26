/*
 * FUN_00467514 at 00467514
 * undefined __register FUN_00467514(int param_1, int param_2)
 * Address ranges: 00467514-00467536
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467514(int param_1,int param_2)

{
  FUN_0040f504(*(int **)(param_1 + 0x240),param_2);
  *(int *)(param_2 + 500) = param_1;
  FUN_00466e9c(param_2);
  return;
}

