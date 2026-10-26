/*
 * FUN_00402531 at 00402531
 * undefined4 __cdecl FUN_00402531(int param_1, undefined4 * param_2)
 * Address ranges: 00402531-00402630
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00402531(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *local_78;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_4c;
  
  if (param_1 == 0) {
    if (DAT_00438444 == 0) {
      return 0;
    }
    local_78 = DAT_00438434;
  }
  else if (param_1 == 1) {
    if (DAT_00438448 == 0) {
      return 0;
    }
    local_78 = DAT_00438438;
  }
  else if (param_1 == 2) {
    if (DAT_0043844c == 0) {
      return 0;
    }
    local_78 = DAT_00438418;
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0042cf84);
  }
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  FUN_004028c2(local_78);
  iVar1 = (**(code **)(*local_78 + 100))(local_78,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042cfbc);
  }
  *param_2 = local_60;
  return local_4c;
}

