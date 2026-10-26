/*
 * FUN_004c9670 at 004c9670
 * undefined FUN_004c9670(void)
 * Address ranges: 004c9670-004c9695
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte FUN_004c9670(uint param_1)

{
  if (DAT_006b6b60 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}

