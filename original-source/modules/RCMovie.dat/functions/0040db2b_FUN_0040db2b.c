/*
 * FUN_0040db2b at 0040db2b
 * COLORREF __cdecl FUN_0040db2b(int * param_1, int param_2, int param_3)
 * Address ranges: 0040db2b-0040dba5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

COLORREF __cdecl FUN_0040db2b(int *param_1,int param_2,int param_3)

{
  int iVar1;
  COLORREF CVar2;
  HDC local_8;
  
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_8);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_hdc_of_sc_00432568);
  }
  CVar2 = GetPixel(local_8,param_2,param_3);
  (**(code **)(*param_1 + 0x68))(param_1,local_8);
  return CVar2;
}

