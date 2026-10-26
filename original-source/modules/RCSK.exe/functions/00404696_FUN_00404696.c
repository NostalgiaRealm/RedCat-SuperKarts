/*
 * FUN_00404696 at 00404696
 * undefined4 __cdecl FUN_00404696(uint param_1)
 * Address ranges: 00404696-004046d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00404696(uint param_1)

{
  if ((param_1 < DAT_0040a120) &&
     ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    return *(undefined4 *)((&DAT_0040a020)[(int)param_1 >> 5] + (param_1 & 0x1f) * 8);
  }
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return 0xffffffff;
}

