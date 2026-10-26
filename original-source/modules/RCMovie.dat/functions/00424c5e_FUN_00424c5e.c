/*
 * FUN_00424c5e at 00424c5e
 * byte __cdecl FUN_00424c5e(uint param_1)
 * Address ranges: 00424c5e-00424c83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte __cdecl FUN_00424c5e(uint param_1)

{
  if (DAT_0043f920 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}

