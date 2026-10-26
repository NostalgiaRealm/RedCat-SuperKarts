/*
 * FUN_0040f789 at 0040f789
 * undefined4 __cdecl FUN_0040f789(int param_1)
 * Address ranges: 0040f789-0040f7bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040f789(int param_1)

{
  if ((param_1 < 0) || (0x11 < param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_mode_index__und_004331c0);
  }
  return *(undefined4 *)(&DAT_0042c378 + param_1 * 0x14);
}

