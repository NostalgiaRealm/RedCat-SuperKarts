/*
 * FUN_00414ef4 at 00414ef4
 * undefined FUN_00414ef4(void)
 * Address ranges: 00414ef4-00414f0b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414ef4(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x1c))();
    return;
  }
  FUN_004030d0();
  return;
}

