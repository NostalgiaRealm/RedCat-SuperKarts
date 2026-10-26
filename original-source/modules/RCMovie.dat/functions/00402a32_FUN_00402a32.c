/*
 * FUN_00402a32 at 00402a32
 * undefined4 __cdecl FUN_00402a32(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00402a32-00402ab6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00402a32(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 7;
  local_8 = param_3;
  local_64 = param_1;
  local_68 = param_2;
  local_74 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_78,0);
  if (local_74 != 0) {
    FUN_00401f61(local_74);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d1dc);
  }
  return local_78;
}

