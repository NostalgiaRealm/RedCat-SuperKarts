/*
 * FUN_00459c80 at 00459c80
 * undefined FUN_00459c80(void)
 * Address ranges: 00459c80-00459ca3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00459c80(int param_1)

{
  if (*(int *)(param_1 + 0x50) == -1) {
    return 0xffffffff;
  }
  return *(undefined4 *)(DAT_006a5c38 + *(int *)(param_1 + 0x50) * 0xa9 + 4);
}

