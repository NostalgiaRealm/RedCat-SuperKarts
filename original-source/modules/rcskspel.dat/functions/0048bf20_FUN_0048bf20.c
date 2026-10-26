/*
 * FUN_0048bf20 at 0048bf20
 * undefined FUN_0048bf20(void)
 * Address ranges: 0048bf20-0048bf32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0048bf20(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) >> 5;
}

