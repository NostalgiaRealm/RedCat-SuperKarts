/*
 * FUN_0044ca80 at 0044ca80
 * undefined FUN_0044ca80(void)
 * Address ranges: 0044ca80-0044ca92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0044ca80(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
}

