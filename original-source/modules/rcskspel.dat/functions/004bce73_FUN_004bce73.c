/*
 * FUN_004bce73 at 004bce73
 * undefined FUN_004bce73(void)
 * Address ranges: 004bce73-004bce82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004bce73(int param_1)

{
  **(int **)(param_1 + 0x30) = **(int **)(param_1 + 0x30) + -1;
  **(int **)(param_1 + 0x20) = **(int **)(param_1 + 0x20) + 1;
  return;
}

