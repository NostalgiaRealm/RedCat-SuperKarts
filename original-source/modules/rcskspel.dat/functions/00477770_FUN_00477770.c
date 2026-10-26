/*
 * FUN_00477770 at 00477770
 * undefined FUN_00477770(void)
 * Address ranges: 00477770-00477782
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00477770(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) >> 2;
}

