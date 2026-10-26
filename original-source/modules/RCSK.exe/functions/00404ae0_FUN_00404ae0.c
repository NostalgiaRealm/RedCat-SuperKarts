/*
 * FUN_00404ae0 at 00404ae0
 * byte __cdecl FUN_00404ae0(uint param_1)
 * Address ranges: 00404ae0-00404b05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte __cdecl FUN_00404ae0(uint param_1)

{
  if (DAT_0040a120 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}

