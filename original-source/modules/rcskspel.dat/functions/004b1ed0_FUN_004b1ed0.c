/*
 * FUN_004b1ed0 at 004b1ed0
 * undefined FUN_004b1ed0(void)
 * Address ranges: 004b1ed0-004b1f07
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b1ed0(LPCSTR param_1,LPCSTR param_2)

{
  if (DAT_006ab45c == 0) {
    FUN_004afee0(s__read_ini_value_setting___s__d____004ffb78,
                 s_C__libraries_dxdraw_Inifile_cpp_004ffac0,0xa4);
  }
  GetPrivateProfileIntA(param_1,param_2,0,(LPCSTR)&DAT_006ab330);
  return;
}

