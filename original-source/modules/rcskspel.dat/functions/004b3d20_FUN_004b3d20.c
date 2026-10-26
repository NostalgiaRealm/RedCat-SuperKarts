/*
 * FUN_004b3d20 at 004b3d20
 * undefined FUN_004b3d20(void)
 * Address ranges: 004b3d20-004b3de5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b3d20(undefined4 param_1,int param_2,undefined2 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_24;
  short sStack_22;
  int local_20;
  int local_1c;
  undefined2 local_18;
  undefined2 uStack_16;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)&local_24;
  local_20 = param_2;
  local_1c = param_2 * param_4;
  _local_18 = CONCAT22(param_3,(short)param_4);
  local_8 = 0;
  _local_24 = CONCAT22((param_5 != 0) + 1,1);
  local_14 = 0x14;
  local_10 = 0xe8;
  local_c = param_1;
  iVar1 = (**(code **)(*DAT_006ab788 + 0xc))(DAT_006ab788,&local_14,&param_5,0);
  if (iVar1 != 0) {
    uVar2 = FUN_004b3910(iVar1);
    FUN_004afee0(s__s__d____error_creating_sound_bu_00500468,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x123,uVar2);
  }
  return param_1;
}

