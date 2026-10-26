/*
 * FUN_0043fb14 at 0043fb14
 * undefined FUN_0043fb14(void)
 * Address ranges: 0043fb14-0043fb27
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043fb14(int param_1)

{
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x24) + 0x80))();
  }
  return;
}

