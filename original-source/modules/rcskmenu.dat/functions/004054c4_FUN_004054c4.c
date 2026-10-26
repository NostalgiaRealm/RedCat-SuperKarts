/*
 * FUN_004054c4 at 004054c4
 * undefined __register FUN_004054c4(int * param_1)
 * Address ranges: 004054c4-004054ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004054c4(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))();
  }
  return;
}

