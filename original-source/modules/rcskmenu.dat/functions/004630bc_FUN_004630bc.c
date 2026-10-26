/*
 * FUN_004630bc at 004630bc
 * undefined __register FUN_004630bc(int * param_1)
 * Address ranges: 004630bc-004630d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004630bc(int *param_1)

{
  (**(code **)(*(int *)param_1[0x80] + 8))();
  (**(code **)(*param_1 + 0x74))();
  return;
}

