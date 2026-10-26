/*
 * FUN_00418184 at 00418184
 * undefined __cdecl FUN_00418184(int param_1, int param_2)
 * Address ranges: 00418184-004181ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00418184(int param_1,int param_2)

{
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_00435ba0);
  }
  if (param_2 == 1) {
    *(undefined4 *)(&DAT_00435824 + param_1 * 0x10) = 1;
  }
  else if (param_2 == 2) {
    *(undefined4 *)(&DAT_00435824 + param_1 * 0x10) = 2;
  }
  else {
    FUN_0040187a((byte *)s__s__d____illegal_bkmode_for_font_00435bdc);
  }
  return;
}

