/*
 * FUN_004b1f10 at 004b1f10
 * undefined FUN_004b1f10(void)
 * Address ranges: 004b1f10-004b1f54
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b1f10(LPCSTR param_1,LPCSTR param_2,LPSTR param_3,DWORD param_4)

{
  if (DAT_006ab45c == 0) {
    FUN_004afee0(s__read_ini_string_setting___s__d__004ffbc4,
                 s_C__libraries_dxdraw_Inifile_cpp_004ffac0,0xba);
  }
  GetPrivateProfileStringA(param_1,param_2,&DAT_005437b0,param_3,param_4,(LPCSTR)&DAT_006ab330);
  return;
}

