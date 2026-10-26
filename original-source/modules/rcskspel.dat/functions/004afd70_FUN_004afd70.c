/*
 * FUN_004afd70 at 004afd70
 * undefined FUN_004afd70(void)
 * Address ranges: 004afd70-004afda0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004afd70(int param_1)

{
  if ((param_1 < 0) || (0xff < param_1)) {
    FUN_004afee0(s__s__d____Illegal_color_key_index_004feaec,
                 s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x131,param_1);
  }
  DAT_004fead8 = param_1;
  return;
}

