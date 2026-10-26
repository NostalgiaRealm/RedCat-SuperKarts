/*
 * FUN_004057be at 004057be
 * undefined __cdecl FUN_004057be(LPCSTR param_1, LPCSTR param_2, LPCSTR param_3)
 * Address ranges: 004057be-004057f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004057be(LPCSTR param_1,LPCSTR param_2,LPCSTR param_3)

{
  if (DAT_0043d3fc == 0) {
    FUN_0040187a((byte *)s__write_ini_string_setting___s__d_0042ebdc);
  }
  WritePrivateProfileStringA(param_1,param_2,param_3,&DAT_0043d2d0);
  return;
}

