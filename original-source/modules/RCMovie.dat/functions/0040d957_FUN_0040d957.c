/*
 * FUN_0040d957 at 0040d957
 * undefined __cdecl FUN_0040d957(int param_1, int param_2, int param_3, COLORREF param_4)
 * Address ranges: 0040d957-0040da04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040d957(int param_1,int param_2,int param_3,COLORREF param_4)

{
  int iVar1;
  int *local_10;
  HDC local_8;
  
  if (param_1 == 0) {
    local_10 = DAT_00438434;
  }
  else if (param_1 == 1) {
    local_10 = DAT_00438438;
  }
  else if (param_1 == 2) {
    local_10 = DAT_00438418;
  }
  FUN_004028c2(local_10);
  iVar1 = (**(code **)(*local_10 + 0x44))(local_10,&local_8);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____error_getting_hdc_of_sc_004324c0);
  }
  SetPixel(local_8,param_2,param_3,param_4);
  (**(code **)(*local_10 + 0x68))(local_10,local_8);
  return;
}

