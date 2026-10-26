/*
 * FUN_00402040 at 00402040
 * undefined FUN_00402040(void)
 * Address ranges: 00402040-00402074
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402040(int param_1)

{
  if (((&DAT_00504000)[param_1 * 0x11c] == '\0') &&
     (2.0 < *(float *)(&DAT_00503f08 + param_1 * 0x11c))) {
    return 1;
  }
  return 0;
}

