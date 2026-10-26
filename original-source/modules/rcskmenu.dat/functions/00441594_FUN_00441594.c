/*
 * FUN_00441594 at 00441594
 * undefined FUN_00441594(void)
 * Address ranges: 00441594-004415a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441594(int param_1)

{
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x1c))();
  }
  return;
}

