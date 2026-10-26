/*
 * FUN_00405fa9 at 00405fa9
 * undefined4 __cdecl FUN_00405fa9(int param_1, undefined2 param_2, int param_3, int param_4)
 * Address ranges: 00405fa9-00406106
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00405fa9(int param_1,undefined2 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined2 local_2c;
  short local_2a;
  int local_28;
  int local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_c;
  int local_8;
  
  _memset(&local_2c,0,0x10);
  local_2c = 1;
  local_2a = (param_4 != 0) + 1;
  local_28 = param_1;
  local_20 = (undefined2)param_3;
  local_24 = param_3 * param_1;
  local_1e = param_2;
  _memset(&local_1c,0,0x14);
  local_1c = 0x14;
  local_18 = 0x11;
  local_14 = 0;
  local_c = 0;
  local_8 = (**(code **)(*DAT_0043d410 + 0xc))(DAT_0043d410,&local_1c,&DAT_0043d418,0);
  if (local_8 == 0) {
    local_8 = (**(code **)(*DAT_0043d418 + 0x38))(DAT_0043d418,&local_2c);
    if (local_8 == 0) {
      local_8 = (**(code **)(*DAT_0043d418 + 0x30))(DAT_0043d418,0,0,1);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____error_starting_primary_s_0042f340);
      }
      uVar1 = 0;
    }
    else {
      FUN_00405af0(local_8);
      FUN_004015a6((byte *)s__s__d____error_setting_format____0042f30c);
      uVar1 = 0x2afa;
    }
  }
  else {
    FUN_00405af0(local_8);
    FUN_004015a6((byte *)s__s__d____error_creating_sound_bu_0042f2d4);
    uVar1 = 0x2afa;
  }
  return uVar1;
}

