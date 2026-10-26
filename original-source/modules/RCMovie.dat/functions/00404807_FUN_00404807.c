/*
 * FUN_00404807 at 00404807
 * undefined __cdecl FUN_00404807(int param_1)
 * Address ranges: 00404807-00404862
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00404807(int param_1)

{
  if (DAT_00438488 != 0) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_type__Can_t_c_0042dff4);
  }
  if ((param_1 < 1) || (2 < param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_mouse_type__Unknow_0042e050);
  }
  else {
    DAT_0042dfa4 = param_1;
  }
  return;
}

