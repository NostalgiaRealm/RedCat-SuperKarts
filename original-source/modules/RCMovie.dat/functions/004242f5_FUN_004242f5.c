/*
 * FUN_004242f5 at 004242f5
 * undefined4 __cdecl FUN_004242f5(uint param_1)
 * Address ranges: 004242f5-00424331
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_004242f5(uint param_1)

{
  if ((param_1 < DAT_0043f920) &&
     ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    return *(undefined4 *)((&DAT_0043f820)[(int)param_1 >> 5] + (param_1 & 0x1f) * 8);
  }
  DAT_0043e2c4 = 0;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}

