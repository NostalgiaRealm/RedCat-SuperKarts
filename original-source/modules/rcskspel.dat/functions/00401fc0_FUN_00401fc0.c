/*
 * FUN_00401fc0 at 00401fc0
 * undefined FUN_00401fc0(void)
 * Address ranges: 00401fc0-0040201d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401fc0(int param_1)

{
  param_1 = param_1 * 0x11c;
  if (*(float *)(&DAT_00503f08 + param_1) <= 2.0) {
    *(undefined4 *)(&DAT_00503f08 + param_1) = 0;
  }
  else if (10.0 < *(float *)(*(int *)(&DAT_00503ef8 + param_1) * 0xd0 + 0xa4 + DAT_0067ee20)) {
    return 1;
  }
  return 0;
}

