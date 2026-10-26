/*
 * FUN_00476560 at 00476560
 * undefined FUN_00476560(void)
 * Address ranges: 00476560-00476572
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00476560(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 5;
}

