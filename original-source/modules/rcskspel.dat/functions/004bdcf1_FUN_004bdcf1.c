/*
 * FUN_004bdcf1 at 004bdcf1
 * undefined FUN_004bdcf1(void)
 * Address ranges: 004bdcf1-004bdd00
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004bdcf1(int param_1)

{
  **(int **)(param_1 + 0x30) = **(int **)(param_1 + 0x30) + -1;
  **(int **)(param_1 + 0x20) = **(int **)(param_1 + 0x20) + 2;
  return;
}

