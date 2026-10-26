/*
 * FUN_004118dd at 004118dd
 * undefined __cdecl FUN_004118dd(int * param_1, int * param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, uint param_11)
 * Address ranges: 004118dd-00411b71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_004118dd(int *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,uint param_11)

{
  int iVar1;
  undefined4 local_100;
  undefined4 local_fc;
  int local_f8;
  int local_f4;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  int local_78;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = 0x1000000;
  local_100 = 0x6c;
  local_fc = 6;
  local_84 = 0x6c;
  local_80 = 6;
  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,&local_100);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____DDError__blt_surf_2_sur_00433e74);
  }
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2,&local_84);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____DDError__blt_surf_2_sur_00433ecc);
  }
  if ((param_11 & 8) != 0) {
    local_8 = local_8 | 0x8000;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (param_7 < 0) {
    param_7 = 0;
  }
  if (param_8 < 0) {
    param_8 = 0;
  }
  if (((((0 < param_5) && (0 < param_6)) && (param_3 <= local_f4)) &&
      ((param_4 <= local_f8 && (0 < param_9)))) &&
     ((0 < param_10 && ((param_7 <= local_78 && (param_8 <= local_7c)))))) {
    if (local_f4 < param_5) {
      param_5 = local_f4;
    }
    if (local_f8 < param_6) {
      param_6 = local_f8;
    }
    if (local_78 < param_9) {
      param_9 = local_78;
    }
    if (local_7c < param_10) {
      param_10 = local_7c;
    }
    if ((((param_3 != param_5) && (param_4 != param_6)) && (param_7 != param_9)) &&
       (param_8 != param_10)) {
      local_94 = param_3;
      local_8c = param_5;
      local_90 = param_4;
      local_88 = param_6;
      local_18 = param_7;
      local_10 = param_9;
      local_14 = param_8;
      local_c = param_10;
      if (((0 < param_9) && (0 < param_10)) &&
         ((0 < param_5 &&
          ((0 < param_6 &&
           (iVar1 = (**(code **)(*param_2 + 0x14))(param_2,&local_18,param_1,&local_94,local_8,0),
           iVar1 != 0)))))) {
        FUN_00401f61(iVar1);
        FUN_0040187a((byte *)s__s__d____blt_surf_2_surf_blittin_00433f24);
      }
    }
  }
  return;
}

