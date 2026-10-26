/*
 * FUN_004bce53 at 004bce53
 * undefined FUN_004bce53(void)
 * Address ranges: 004bce53-004bce62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_004bce53(int param_1)

{
  **(int **)(param_1 + 0x2c) = **(int **)(param_1 + 0x2c) + 1;
  **(int **)(param_1 + 0x1c) = **(int **)(param_1 + 0x1c) + -1;
  return **(undefined4 **)(param_1 + 0x1c);
}

