/*
 * FUN_0041813c at 0041813c
 * undefined __cdecl FUN_0041813c(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0041813c-00418183
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041813c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_00435b64);
  }
  *(undefined4 *)(&DAT_00435828 + param_1 * 0x10) = param_2;
  *(undefined4 *)(&DAT_0043582c + param_1 * 0x10) = param_3;
  return;
}

