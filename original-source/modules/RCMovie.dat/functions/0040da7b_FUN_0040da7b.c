/*
 * FUN_0040da7b at 0040da7b
 * COLORREF __cdecl FUN_0040da7b(int param_1, int param_2, int param_3)
 * Address ranges: 0040da7b-0040db2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

COLORREF __cdecl FUN_0040da7b(int param_1,int param_2,int param_3)

{
  int iVar1;
  COLORREF CVar2;
  int *local_14;
  HDC local_8;
  
  if (param_1 == 0) {
    local_14 = DAT_00438434;
  }
  else if (param_1 == 1) {
    local_14 = DAT_00438438;
  }
  else if (param_1 == 2) {
    local_14 = DAT_00438418;
  }
  FUN_004028c2(local_14);
  iVar1 = (**(code **)(*local_14 + 0x44))(local_14,&local_8);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_hdc_of_sc_00432530);
  }
  CVar2 = GetPixel(local_8,param_2,param_3);
  (**(code **)(*local_14 + 0x68))(local_14,local_8);
  return CVar2;
}

