/*
 * FUN_00401f80 at 00401f80
 * undefined FUN_00401f80(void)
 * Address ranges: 00401f80-00401fbe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401f80(int param_1)

{
  if (*(float *)(*(int *)(&DAT_00503ef8 + param_1 * 0x11c) * 0xd0 + 0xa4 + DAT_0067ee20) < 0.0) {
    return 1;
  }
  return 0;
}

