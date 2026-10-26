/*
 * FUN_004bdcbc at 004bdcbc
 * undefined FUN_004bdcbc(void)
 * Address ranges: 004bdcbc-004bdccc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_004bdcbc(int param_1)

{
  **(int **)(param_1 + 0x2c) = **(int **)(param_1 + 0x2c) + 1;
  **(int **)(param_1 + 0x1c) = **(int **)(param_1 + 0x1c) + -2;
  return **(undefined4 **)(param_1 + 0x1c);
}

