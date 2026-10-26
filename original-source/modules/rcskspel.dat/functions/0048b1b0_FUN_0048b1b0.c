/*
 * FUN_0048b1b0 at 0048b1b0
 * undefined FUN_0048b1b0(void)
 * Address ranges: 0048b1b0-0048b1c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0048b1b0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 5;
}

