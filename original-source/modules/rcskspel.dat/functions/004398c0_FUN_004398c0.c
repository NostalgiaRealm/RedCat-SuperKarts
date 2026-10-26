/*
 * FUN_004398c0 at 004398c0
 * undefined FUN_004398c0(void)
 * Address ranges: 004398c0-004398e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004398c0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x14;
}

