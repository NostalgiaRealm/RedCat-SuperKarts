/*
 * FUN_004b5d90 at 004b5d90
 * undefined FUN_004b5d90(void)
 * Address ranges: 004b5d90-004b5e3a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b5d90(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_1 < 0) || (param_3 < param_1)) {
    FUN_004afee0(s__s__d____illegal_clipping_limit_t_00500cb8,
                 s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x3b);
  }
  if ((param_2 < 0) || (param_4 < param_2)) {
    FUN_004afee0(s__s__d____illegal_clipping_limit_t_00500c90,
                 s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x3e);
  }
  if (DAT_004fe930 < param_3) {
    FUN_004afee0(s__s__d____illegal_clipping_limit_b_00500c64,
                 s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x41);
  }
  if (DAT_004fe934 < param_4) {
    FUN_004afee0(s__s__d____illegal_clipping_limit_b_00500c38,
                 s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x44);
  }
  DAT_006ab834 = param_4;
  DAT_006ab840 = param_2;
  DAT_006ab838 = param_3;
  DAT_006ab83c = param_1;
  DAT_006ab848 = 1;
  return;
}

