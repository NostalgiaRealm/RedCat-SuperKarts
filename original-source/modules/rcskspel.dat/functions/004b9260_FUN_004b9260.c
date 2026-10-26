/*
 * FUN_004b9260 at 004b9260
 * undefined FUN_004b9260(void)
 * Address ranges: 004b9260-004b9290
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b9260(int param_1)

{
  if ((param_1 < 0) || (0x13 < param_1)) {
    FUN_004afee0(s__s__d____illegal_mode_index__und_005017b0,
                 s_C__libraries_dxdraw_Hwinfo_cpp_0050137c,0x1e1);
  }
  return *(undefined4 *)(&DAT_004fe958 + param_1 * 0x14);
}

