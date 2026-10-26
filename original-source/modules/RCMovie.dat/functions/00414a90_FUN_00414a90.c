/*
 * FUN_00414a90 at 00414a90
 * undefined __cdecl FUN_00414a90(int param_1, undefined4 * param_2, int param_3, int param_4)
 * Address ranges: 00414a90-00414c5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00414a90(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (DAT_0042c354 <= param_4) {
    param_4 = DAT_0042c354;
  }
  if (param_1 == 0) {
    local_10 = DAT_004383b4;
    local_14 = DAT_00438434;
  }
  else if (param_1 == 1) {
    local_10 = DAT_00438420;
    local_14 = DAT_00438438;
  }
  else if (param_1 == 2) {
    local_10 = DAT_00438430;
    local_14 = DAT_00438418;
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_004351d4);
  }
  FUN_004028c2(local_14);
  if (DAT_0043d754 == 0) {
    local_8 = FUN_0040243c(param_1);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414e80(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_00402727(param_1,local_8);
  }
  else if (DAT_0043d754 == 1) {
    local_8 = FUN_0040243c(param_1);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414c60(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_00402727(param_1,local_8);
  }
  else if (DAT_0043d754 == 2) {
    local_8 = FUN_0040243c(param_1);
    for (local_c = 0; local_c < param_4; local_c = local_c + 1) {
      FUN_00414d60(local_8,param_2,param_3);
      local_8 = local_8 + local_10;
    }
    FUN_00402727(param_1,local_8);
  }
  return;
}

