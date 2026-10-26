/*
 * FUN_00417f17 at 00417f17
 * undefined4 __cdecl FUN_00417f17(int param_1, LPCSTR param_2, int param_3, DWORD param_4, DWORD param_5, undefined4 param_6)
 * Address ranges: 00417f17-00418019
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_00417f17(int param_1,LPCSTR param_2,int param_3,DWORD param_4,DWORD param_5,undefined4 param_6)

{
  HFONT pHVar1;
  undefined4 uVar2;
  int local_8;
  
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_004359e0);
  }
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) != 0) {
    FUN_0040187a((byte *)s__s__d____Font_index_already_in_u_00435a1c);
  }
  switch(param_6) {
  case 0:
    local_8 = 100;
    break;
  case 1:
    local_8 = 400;
    break;
  case 2:
    local_8 = 700;
    break;
  case 3:
    local_8 = 800;
    break;
  case 4:
    local_8 = 900;
    break;
  default:
    FUN_0040187a((byte *)s__s__d____Font_illegal_thickness__00435a54);
  }
  pHVar1 = CreateFontA(param_3,0,0,0,local_8,param_4,param_5,0,0,0,0,0,2,param_2);
  *(HFONT *)(&DAT_00435820 + param_1 * 0x10) = pHVar1;
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) == 0) {
    uVar2 = 10000;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

