/*
 * FUN_0044b7a0 at 0044b7a0
 * undefined FUN_0044b7a0(void)
 * Address ranges: 0044b7a0-0044b7c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0044b7a0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x60;
}

