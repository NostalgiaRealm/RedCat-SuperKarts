/*
 * FUN_00417ebf at 00417ebf
 * int __cdecl FUN_00417ebf(LPCSTR param_1, int param_2, DWORD param_3, DWORD param_4)
 * Address ranges: 00417ebf-00417f16
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00417ebf(LPCSTR param_1,int param_2,DWORD param_3,DWORD param_4)

{
  int iVar1;
  
  iVar1 = FUN_00418303();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d____No_Free_Font_index__004359b4);
  }
  FUN_0041802e(iVar1,param_1,param_2,param_3,param_4);
  FUN_004180d3(iVar1);
  return iVar1;
}

