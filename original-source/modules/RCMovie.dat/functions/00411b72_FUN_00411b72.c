/*
 * FUN_00411b72 at 00411b72
 * bool __cdecl FUN_00411b72(int * param_1, int * param_2)
 * Address ranges: 00411b72-00411cb5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __cdecl FUN_00411b72(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0x1000000;
  local_100 = 0x6c;
  local_fc = 6;
  local_84 = 0x6c;
  local_80 = 6;
  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,&local_100);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____DDError__blt_surf_2_sur_00433f64);
  }
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2,&local_84);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____DDError__blt_surf_2_sur_00433fbc);
  }
  local_94 = 0;
  local_8c = local_f4;
  local_90 = 0;
  local_88 = local_f8;
  local_18 = 0;
  local_10 = local_78;
  local_14 = 0;
  local_c = local_7c;
  iVar1 = (**(code **)(*param_2 + 0x14))(param_2,&local_18,param_1,&local_94,local_8,0);
  return iVar1 == 0;
}

