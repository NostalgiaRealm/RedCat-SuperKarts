/*
 * FUN_0041018b at 0041018b
 * undefined __cdecl FUN_0041018b(int param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6, int param_7)
 * Address ranges: 0041018b-00410439
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_0041018b(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_0040235c(DAT_00438434);
  }
  else if (param_1 == 1) {
    local_8 = FUN_0040235c(DAT_00438438);
  }
  else if (param_1 == 2) {
    local_8 = FUN_0040235c(DAT_00438418);
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0043363c);
  }
  if (param_7 == 0) {
    FUN_004150a0();
  }
  else {
    if (DAT_0043d814 == 0) {
      FUN_0040187a((byte *)s__s__d____no_clipping_limit_set_00433678);
    }
    if (param_3 + param_5 < DAT_0043d808) {
      return;
    }
    if (DAT_0043d804 < param_3) {
      return;
    }
    if (param_4 + param_6 < DAT_0043d80c) {
      return;
    }
    if (DAT_0043d800 < param_4) {
      return;
    }
    if (param_4 < DAT_0043d80c) {
      param_6 = param_6 - (DAT_0043d80c - param_4);
      param_4 = DAT_0043d80c;
      if (param_6 < 1) {
        return;
      }
    }
    if ((DAT_0043d800 < param_4 + param_6) && (DAT_0043d800 - param_4 < 1)) {
      return;
    }
    if (param_3 < DAT_0043d808) {
      param_5 = param_5 - (DAT_0043d808 - param_3);
      param_3 = DAT_0043d808;
      if (param_5 < 1) {
        return;
      }
    }
    if ((DAT_0043d804 < param_3 + param_5) && (DAT_0043d804 - param_3 < 1)) {
      return;
    }
    FUN_004150a0();
  }
  if (param_1 == 0) {
    FUN_004027f9(DAT_00438434,local_8);
  }
  else if (param_1 == 1) {
    FUN_004027f9(DAT_00438438,local_8);
  }
  else if (param_1 == 2) {
    FUN_004027f9(DAT_00438418,local_8);
  }
  else {
    FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_004336ac);
  }
  return;
}

