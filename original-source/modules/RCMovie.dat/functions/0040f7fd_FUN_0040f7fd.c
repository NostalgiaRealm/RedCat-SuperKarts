/*
 * FUN_0040f7fd at 0040f7fd
 * undefined __cdecl FUN_0040f7fd(int param_1, int param_2, int param_3, int param_4)
 * Address ranges: 0040f7fd-0040f8b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040f7fd(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_1 < 0) || (param_3 < param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_clipping_limit_t_0043320c);
  }
  if ((param_2 < 0) || (param_4 < param_2)) {
    FUN_0040187a((byte *)s__s__d____illegal_clipping_limit_t_00433244);
  }
  if (DAT_0042c350 < param_3) {
    FUN_0040187a((byte *)s__s__d____illegal_clipping_limit_b_0043327c);
  }
  if (DAT_0042c354 < param_4) {
    FUN_0040187a((byte *)s__s__d____illegal_clipping_limit_b_004332b8);
  }
  DAT_0043d808 = param_1;
  DAT_0043d80c = param_2;
  DAT_0043d804 = param_3;
  DAT_0043d800 = param_4;
  DAT_0043d814 = 1;
  return;
}

