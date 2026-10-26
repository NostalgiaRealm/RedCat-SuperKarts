/*
 * FUN_004b1e30 at 004b1e30
 * undefined FUN_004b1e30(void)
 * Address ranges: 004b1e30-004b1e67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b1e30(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

{
  if (DAT_006ab45c == 0) {
    FUN_004afee0(s__write_ini_string_setting___s__d_004ffae0,
                 s_C__libraries_dxdraw_Inifile_cpp_004ffac0,0x74);
  }
  WritePrivateProfileStringA(param_1,param_2,param_3,(LPCSTR)&DAT_006ab330);
  return;
}

