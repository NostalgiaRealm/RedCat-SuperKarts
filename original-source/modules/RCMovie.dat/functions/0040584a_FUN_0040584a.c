/*
 * FUN_0040584a at 0040584a
 * undefined __cdecl FUN_0040584a(LPCSTR param_1, LPCSTR param_2)
 * Address ranges: 0040584a-00405883
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040584a(LPCSTR param_1,LPCSTR param_2)

{
  if (DAT_0043d3fc == 0) {
    FUN_0040187a((byte *)s__read_ini_value_setting___s__d____0042ec8c);
  }
  GetPrivateProfileIntA(param_1,param_2,0,&DAT_0043d2d0);
  return;
}

