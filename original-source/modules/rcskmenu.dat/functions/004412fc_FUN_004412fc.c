/*
 * FUN_004412fc at 004412fc
 * undefined4 __register FUN_004412fc(int param_1)
 * Address ranges: 004412fc-0044131b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004412fc(int param_1)

{
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    param_1 = (**(code **)(**(int **)(param_1 + 0x5c) + 8))();
    if ((char)param_1 != '\0') {
      return 0;
    }
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}

