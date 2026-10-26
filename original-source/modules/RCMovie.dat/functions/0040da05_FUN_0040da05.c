/*
 * FUN_0040da05 at 0040da05
 * undefined __cdecl FUN_0040da05(int * param_1, int param_2, int param_3, COLORREF param_4)
 * Address ranges: 0040da05-0040da7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040da05(int *param_1,int param_2,int param_3,COLORREF param_4)

{
  int iVar1;
  HDC local_8;
  
  FUN_004028c2(param_1);
  iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_8);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_hdc_of_sc_004324f8);
  }
  SetPixel(local_8,param_2,param_3,param_4);
  (**(code **)(*param_1 + 0x68))(param_1,local_8);
  return;
}

