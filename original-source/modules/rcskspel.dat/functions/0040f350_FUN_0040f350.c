/*
 * FUN_0040f350 at 0040f350
 * undefined FUN_0040f350(void)
 * Address ranges: 0040f350-0040f37d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f350(int param_1)

{
  param_1 = param_1 * 0x11c;
  *(undefined4 *)(&DAT_00503f7c + param_1) = 2;
  *(undefined4 *)(&DAT_00503f80 + param_1) = 1;
  *(undefined4 *)(&DAT_00503f84 + param_1) = 0;
  return;
}

