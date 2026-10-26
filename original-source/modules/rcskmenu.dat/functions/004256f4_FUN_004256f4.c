/*
 * FUN_004256f4 at 004256f4
 * undefined4 __register FUN_004256f4(int param_1)
 * Address ranges: 004256f4-00425713
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004256f4(int param_1)

{
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    param_1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))();
    if ((char)param_1 != '\0') {
      return 0;
    }
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}

