/*
 * FUN_004b1e70 at 004b1e70
 * undefined FUN_004b1e70(void)
 * Address ranges: 004b1e70-004b1ec4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b1e70(LPCSTR param_1,LPCSTR param_2,undefined4 param_3)

{
  CHAR local_24 [36];
  
  if (DAT_006ab45c == 0) {
    FUN_004afee0(s__write_ini_value_setting___s__d__004ffb2c,
                 s_C__libraries_dxdraw_Inifile_cpp_004ffac0,0x8c);
  }
  FUN_004ccab8(param_3,local_24,10);
  WritePrivateProfileStringA(param_1,param_2,local_24,(LPCSTR)&DAT_006ab330);
  return;
}

