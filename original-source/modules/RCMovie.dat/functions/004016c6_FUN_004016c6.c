/*
 * FUN_004016c6 at 004016c6
 * undefined __cdecl FUN_004016c6(int param_1)
 * Address ranges: 004016c6-004016fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004016c6(int param_1)

{
  if ((param_1 < 0) || (0xff < param_1)) {
    FUN_0040187a((byte *)s__s__d____Illegal_color_key_index_0042c4f0);
  }
  DAT_0042c4d0 = param_1;
  return;
}

