/*
 * FUN_00402d63 at 00402d63
 * undefined4 __cdecl FUN_00402d63(undefined4 param_1, undefined4 param_2, uint param_3, uint param_4, undefined4 param_5)
 * Address ranges: 00402d63-00402e3a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_00402d63(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5)

{
  undefined4 *local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_58;
  uint local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = param_4 | 0x20007;
  local_8 = param_3 | 0x401008;
  local_58 = param_5;
  local_64 = param_1;
  local_68 = param_2;
  local_78 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_7c,0);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d35c);
  }
  local_78 = (**(code **)*local_7c)(local_7c,&DAT_00428700,&local_74);
  if (local_78 != 0) {
    FUN_00401f61(local_78);
    FUN_0040187a((byte *)s__s__d____could_not_get_surface2__0042d394);
  }
  return local_74;
}

