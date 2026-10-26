/*
 * FUN_00402fa8 at 00402fa8
 * undefined4 __cdecl FUN_00402fa8(undefined4 param_1, undefined4 param_2, uint param_3, undefined4 * param_4, undefined4 param_5)
 * Address ranges: 00402fa8-00403049
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_00402fa8(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 *param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_58;
  undefined4 local_28 [8];
  uint local_8;
  
  _memset(&local_70,0,0x6c);
  local_70 = 0x6c;
  local_6c = 0x21007;
  local_8 = param_3 | 0x401008;
  local_58 = param_5;
  local_64 = param_1;
  local_68 = param_2;
  puVar2 = local_28;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  local_74 = (**(code **)(*DAT_00438414 + 0x18))(DAT_00438414,&local_70,&local_78,0);
  if (local_74 != 0) {
    FUN_00401f61(local_74);
    FUN_0040187a((byte *)s__s__d____could_not_create_surfac_0042d46c);
  }
  return local_78;
}

