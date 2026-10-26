/*
 * FUN_004387fc at 004387fc
 * undefined4 __register FUN_004387fc(int param_1)
 * Address ranges: 004387fc-0043881b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004387fc(int param_1)

{
  if (*(int **)(param_1 + 0x38) != (int *)0x0) {
    param_1 = (**(code **)(**(int **)(param_1 + 0x38) + 0x38))();
    if ((char)param_1 != '\0') {
      return 0;
    }
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}

