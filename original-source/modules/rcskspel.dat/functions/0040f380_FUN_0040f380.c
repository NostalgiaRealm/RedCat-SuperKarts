/*
 * FUN_0040f380 at 0040f380
 * undefined FUN_0040f380(void)
 * Address ranges: 0040f380-0040f3ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f380(int param_1)

{
  param_1 = param_1 * 0x11c;
  *(undefined4 *)(&DAT_00503f7c + param_1) = 1;
  *(undefined4 *)(&DAT_00503f80 + param_1) = 0;
  *(undefined4 *)(&DAT_00503f84 + param_1) = 2;
  return;
}

