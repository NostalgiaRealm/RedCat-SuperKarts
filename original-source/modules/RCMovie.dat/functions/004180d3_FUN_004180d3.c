/*
 * FUN_004180d3 at 004180d3
 * undefined4 __cdecl FUN_004180d3(int param_1)
 * Address ranges: 004180d3-0041813b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004180d3(int param_1)

{
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_00435af8);
  }
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) == 0) {
    FUN_0040187a((byte *)s__s__d____Font_is_not_loaded___d__00435b34);
  }
  DAT_00435818 = param_1;
  DAT_0043dca8 = 1;
  return 0;
}

