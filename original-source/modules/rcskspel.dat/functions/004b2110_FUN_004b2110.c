/*
 * FUN_004b2110 at 004b2110
 * undefined FUN_004b2110(void)
 * Address ranges: 004b2110-004b215c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b2110(int param_1,char *param_2,size_t param_3)

{
  if ((param_1 < 0) || (DAT_006ab460 < param_1)) {
    FUN_004afee0(s__get_ini_argument_value___s__d____004ffcb8,
                 s_C__libraries_dxdraw_Inifile_cpp_004ffac0,0x123,param_1,DAT_006ab460);
  }
  _strncpy(param_2,(char *)(&DAT_006a6510 + param_1 * 0x32),param_3);
  return;
}

