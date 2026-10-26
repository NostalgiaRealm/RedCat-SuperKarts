/*
 * FUN_004bdca8 at 004bdca8
 * undefined FUN_004bdca8(void)
 * Address ranges: 004bdca8-004bdcbb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004bdca8(int param_1,int param_2)

{
  **(int **)(param_1 + 0x2c) = **(int **)(param_1 + 0x2c) - param_2;
  **(int **)(param_1 + 0x1c) = **(int **)(param_1 + 0x1c) + param_2 * 2;
  return;
}

