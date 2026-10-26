/*
 * FUN_0044129c at 0044129c
 * undefined4 __register FUN_0044129c(int param_1)
 * Address ranges: 0044129c-004412bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044129c(int param_1)

{
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    param_1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x28))();
    if ((char)param_1 != '\0') {
      return 0;
    }
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}

