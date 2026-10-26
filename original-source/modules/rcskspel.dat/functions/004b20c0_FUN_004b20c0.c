/*
 * FUN_004b20c0 at 004b20c0
 * undefined FUN_004b20c0(void)
 * Address ranges: 004b20c0-004b2102
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b20c0(int param_1)

{
  if ((param_1 < 0) || (DAT_006ab460 < param_1)) {
    FUN_004afee0(s__get_ini_argument_value___s__d____004ffcb8,
                 s_C__libraries_dxdraw_Inifile_cpp_004ffac0,0x10f,param_1,DAT_006ab460);
  }
  FUN_004bf812(&DAT_006a6510 + param_1 * 0x32);
  return;
}

