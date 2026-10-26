/*
 * FUN_00438200 at 00438200
 * undefined FUN_00438200(void)
 * Address ranges: 00438200-0043820e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00438200(int param_1)

{
  if (*(int **)(param_1 + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x38) + 0x1c))();
  }
  return;
}

