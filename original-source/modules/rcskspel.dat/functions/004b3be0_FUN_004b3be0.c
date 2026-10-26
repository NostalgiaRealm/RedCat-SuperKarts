/*
 * FUN_004b3be0 at 004b3be0
 * undefined FUN_004b3be0(void)
 * Address ranges: 004b3be0-004b3d12
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b3be0(int param_1,undefined2 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piStack_34;
  undefined4 *puStack_30;
  undefined4 *puStack_2c;
  undefined4 uStack_28;
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
  undefined4 local_4;
  
  local_20 = param_1;
  local_1c = param_1 * param_3;
  uStack_28 = 0;
  puStack_30 = &local_14;
  local_8 = 0;
  _local_24 = CONCAT22((param_4 != 0) + 1,1);
  local_c = 0;
  local_4 = 0;
  _local_18 = CONCAT22(param_2,(short)param_3);
  local_14 = 0x14;
  local_10 = 1;
  puStack_2c = &DAT_006ab790;
  piStack_34 = DAT_006ab788;
  iVar1 = (**(code **)(*DAT_006ab788 + 0xc))();
  if (iVar1 != 0) {
    uVar2 = FUN_004b3910(iVar1);
    FUN_004afce0(s__s__d____error_creating_sound_bu_00500468,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,199,uVar2);
    return 0x2afa;
  }
  iVar1 = (**(code **)(*DAT_006ab790 + 0x38))(DAT_006ab790,&piStack_34);
  if (iVar1 != 0) {
    uVar2 = FUN_004b3910(iVar1);
    FUN_004afce0(s__s__d____error_setting_format____00500440,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0xcc,uVar2);
    return 0x2afa;
  }
  iVar1 = (**(code **)(*DAT_006ab790 + 0x30))(DAT_006ab790,0,0,1);
  if (iVar1 != 0) {
    uVar2 = FUN_004b3910(iVar1);
    FUN_004afee0(s__s__d____error_starting_primary_s_0050040c,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0xd6,uVar2);
  }
  return 0;
}

