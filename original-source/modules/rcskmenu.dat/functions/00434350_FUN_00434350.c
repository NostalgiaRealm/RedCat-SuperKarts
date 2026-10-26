/*
 * FUN_00434350 at 00434350
 * undefined __register FUN_00434350(int param_1, int param_2)
 * Address ranges: 00434350-00434361
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00434350(int param_1,int param_2)

{
  *(int *)(param_2 + 4) = param_1;
  if (*(int **)(param_1 + 0x40) != (int *)0x0) {
    FUN_0040f504(*(int **)(param_1 + 0x40),param_2);
  }
  return;
}

