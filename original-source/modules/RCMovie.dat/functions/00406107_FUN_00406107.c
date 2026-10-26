/*
 * FUN_00406107 at 00406107
 * undefined4 __cdecl FUN_00406107(undefined4 param_1, int param_2, undefined2 param_3, int param_4, int param_5)
 * Address ranges: 00406107-004061ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_00406107(undefined4 param_1,int param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined2 local_30;
  short local_2e;
  int local_2c;
  int local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 *local_10;
  int local_c;
  undefined4 local_8;
  
  _memset(&local_30,0,0x10);
  local_30 = 1;
  local_2e = (param_5 != 0) + 1;
  local_2c = param_2;
  local_24 = (undefined2)param_4;
  local_28 = param_4 * param_2;
  local_22 = param_3;
  _memset(&local_20,0,0x14);
  local_20 = 0x14;
  local_1c = 0xe8;
  local_18 = param_1;
  local_10 = &local_30;
  local_c = (**(code **)(*DAT_0043d410 + 0xc))(DAT_0043d410,&local_20,&local_8,0);
  if (local_c != 0) {
    FUN_00405af0(local_c);
    FUN_0040187a((byte *)s__s__d____error_creating_sound_bu_0042f380);
  }
  return local_8;
}

