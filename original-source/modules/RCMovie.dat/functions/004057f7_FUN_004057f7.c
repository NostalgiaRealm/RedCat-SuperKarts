/*
 * FUN_004057f7 at 004057f7
 * undefined __cdecl FUN_004057f7(LPCSTR param_1, LPCSTR param_2, uint param_3)
 * Address ranges: 004057f7-00405849
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004057f7(LPCSTR param_1,LPCSTR param_2,uint param_3)

{
  char local_28 [36];
  
  if (DAT_0043d3fc == 0) {
    FUN_0040187a((byte *)s__write_ini_value_setting___s__d__0042ec34);
  }
  FUN_00427bff(param_3,local_28,10);
  WritePrivateProfileStringA(param_1,param_2,local_28,&DAT_0043d2d0);
  return;
}

