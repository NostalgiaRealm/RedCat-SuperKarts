/*
 * FUN_00415178 at 00415178
 * undefined __register FUN_00415178(int param_1, int param_2)
 * Address ranges: 00415178-00415183
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415178(int param_1,int param_2)

{
  *(int *)(param_2 + 0x10) = param_1;
  FUN_0040f504(*(int **)(param_1 + 0x40),param_2);
  return;
}

