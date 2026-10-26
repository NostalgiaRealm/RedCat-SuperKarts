/*
 * FUN_00402727 at 00402727
 * undefined __cdecl FUN_00402727(int param_1, undefined4 param_2)
 * Address ranges: 00402727-004027f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00402727(int param_1,undefined4 param_2)

{
  int iVar1;
  int *local_c;
  
  if (param_1 == 0) {
    if (DAT_00438444 == 0) {
      return;
    }
    local_c = DAT_00438434;
  }
  else if (param_1 == 1) {
    if (DAT_00438448 == 0) {
      return;
    }
    local_c = DAT_00438438;
  }
  else if (param_1 == 2) {
    if (DAT_0043844c == 0) {
      return;
    }
    local_c = DAT_00438418;
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0042d058);
  }
  FUN_004028c2(local_c);
  iVar1 = (**(code **)(*local_c + 0x80))(local_c,param_2);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_unlock_surfac_0042d090);
  }
  return;
}

