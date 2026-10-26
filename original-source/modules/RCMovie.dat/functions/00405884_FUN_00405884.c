/*
 * FUN_00405884 at 00405884
 * undefined __cdecl FUN_00405884(LPCSTR param_1, LPCSTR param_2, LPSTR param_3, DWORD param_4)
 * Address ranges: 00405884-004058c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00405884(LPCSTR param_1,LPCSTR param_2,LPSTR param_3,DWORD param_4)

{
  if (DAT_0043d3fc == 0) {
    FUN_0040187a((byte *)s__read_ini_string_setting___s__d__0042ece4);
  }
  GetPrivateProfileStringA(param_1,param_2,&DAT_0043d404,param_3,param_4,&DAT_0043d2d0);
  return;
}

