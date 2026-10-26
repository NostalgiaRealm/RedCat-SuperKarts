/*
 * FUN_004061cb at 004061cb
 * undefined4 __cdecl FUN_004061cb(undefined4 * param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined2 param_5, int param_6, int param_7)
 * Address ranges: 004061cb-004062d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_004061cb(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
            undefined2 param_5,int param_6,int param_7)

{
  undefined2 local_2c;
  short local_2a;
  int local_28;
  int local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 *local_c;
  int local_8;
  
  _memset(&local_2c,0,0x10);
  local_2c = 1;
  local_2a = (param_7 != 0) + 1;
  local_28 = param_4;
  local_20 = (undefined2)param_6;
  local_24 = param_6 * param_4;
  local_1e = param_5;
  _memset(&local_1c,0,0x14);
  local_1c = 0x14;
  local_18 = 0xb8;
  local_14 = param_3;
  local_c = &local_2c;
  local_8 = (**(code **)(*DAT_0043d410 + 0xc))(DAT_0043d410,&local_1c,param_1,0);
  if (local_8 != 0) {
    FUN_00405af0(local_8);
    FUN_0040187a((byte *)s__s__d____error_creating_sound_bu_0042f3b8);
  }
  local_8 = (*(code *)**(undefined4 **)*param_1)(*param_1,&DAT_004298c0,param_2);
  if (local_8 != 0) {
    FUN_00405af0(local_8);
    FUN_0040187a((byte *)s__s__d____error_creating_3d_sound_0042f3f0);
  }
  return 0;
}

