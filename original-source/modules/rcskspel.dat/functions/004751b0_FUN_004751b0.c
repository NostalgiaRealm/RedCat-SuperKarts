/*
 * FUN_004751b0 at 004751b0
 * undefined FUN_004751b0(void)
 * Address ranges: 004751b0-004751c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004751b0(int param_1)

{
  if (*(int *)(param_1 + 0x54) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x54) >> 2;
}

