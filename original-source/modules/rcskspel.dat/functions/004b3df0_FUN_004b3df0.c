/*
 * FUN_004b3df0 at 004b3df0
 * undefined FUN_004b3df0(void)
 * Address ranges: 004b3df0-004b3ee8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_004b3df0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
            undefined2 param_5,int param_6,int param_7)

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
  local_20 = param_4;
  local_1c = param_4 * param_6;
  local_8 = 0;
  _local_18 = CONCAT22(param_5,(short)param_6);
  _local_24 = CONCAT22((param_7 != 0) + 1,1);
  local_14 = 0x14;
  local_10 = 0xb8;
  local_c = param_3;
  iVar1 = (**(code **)(*DAT_006ab788 + 0xc))(DAT_006ab788,&local_14,param_1,0);
  if (iVar1 != 0) {
    uVar2 = FUN_004b3910(iVar1);
    FUN_004afee0(s__s__d____error_creating_sound_bu_00500468,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x142,uVar2);
  }
  iVar1 = (*(code *)**(undefined4 **)*param_1)((undefined4 *)*param_1,&DAT_004d4120,local_8);
  if (iVar1 != 0) {
    uVar2 = FUN_004b3910(iVar1);
    FUN_004afee0(s__s__d____error_creating_3d_sound_005004b4,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x146,uVar2);
  }
  return 0;
}

