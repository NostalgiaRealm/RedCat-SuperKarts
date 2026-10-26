/*
 * FUN_004c0be4 at 004c0be4
 * undefined FUN_004c0be4(void)
 * Address ranges: 004c0be4-004c0c20
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c0be4(uint param_1)

{
  if ((param_1 < DAT_006b6b60) &&
     ((*(byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    return *(undefined4 *)((&DAT_006b6a60)[(int)param_1 >> 5] + (param_1 & 0x1f) * 8);
  }
  DAT_006b66ec = 0;
  _DAT_006b66e8 = 9;
  return 0xffffffff;
}

