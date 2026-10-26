/*
 * FUN_0040243c at 0040243c
 * undefined4 __cdecl FUN_0040243c(int param_1)
 * Address ranges: 0040243c-00402530
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040243c(int param_1)

{
  int iVar1;
  int *local_78;
  undefined4 local_70 [9];
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
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0042cf18);
  }
  FUN_004028c2(local_78);
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  iVar1 = (**(code **)(*local_78 + 100))(local_78,0,local_70,1,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_lock_surface___0042cf50);
  }
  return local_4c;
}

