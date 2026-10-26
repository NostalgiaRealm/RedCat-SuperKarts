/*
 * FUN_004bdcdd at 004bdcdd
 * undefined FUN_004bdcdd(void)
 * Address ranges: 004bdcdd-004bdcf0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004bdcdd(int param_1,int param_2)

{
  **(int **)(param_1 + 0x30) = **(int **)(param_1 + 0x30) - param_2;
  **(int **)(param_1 + 0x20) = **(int **)(param_1 + 0x20) + param_2 * 2;
  return;
}

