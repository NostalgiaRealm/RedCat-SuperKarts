/*
 * FUN_0043883c at 0043883c
 * undefined4 __register FUN_0043883c(int param_1)
 * Address ranges: 0043883c-0043885b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043883c(int param_1)

{
  if (*(int **)(param_1 + 0x38) != (int *)0x0) {
    param_1 = (**(code **)(**(int **)(param_1 + 0x38) + 8))();
    if ((char)param_1 != '\0') {
      return 0;
    }
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}

