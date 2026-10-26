/*
 * FUN_0040f8b1 at 0040f8b1
 * undefined __cdecl FUN_0040f8b1(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, uint param_7)
 * Address ranges: 0040f8b1-0040fc84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_0040f8b1(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,uint param_7)

{
  int iVar1;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0x1000000;
  if ((param_7 & 8) != 0) {
    local_8 = 0x1008000;
  }
  if ((((-1 < param_5) && (param_3 <= DAT_0042c350)) && (-1 < param_6)) &&
     ((param_4 <= DAT_0042c354 && (param_1 != param_2)))) {
    if (param_3 < 0) {
      param_3 = 0;
    }
    if (param_4 < 0) {
      param_4 = 0;
    }
    if (DAT_0042c354 < param_6) {
      param_6 = DAT_0042c354;
    }
    if (DAT_0042c350 < param_5) {
      param_5 = DAT_0042c350;
    }
    if ((param_3 < param_5) && (param_4 < param_6)) {
      local_18 = param_3;
      local_10 = param_5;
      local_14 = param_4;
      local_c = param_6;
      local_28 = param_3;
      local_20 = param_5;
      local_24 = param_4;
      local_1c = param_6;
      local_38 = param_3;
      local_30 = param_5;
      local_34 = param_4;
      local_2c = param_6;
      if (param_2 == 0) {
        FUN_004028c2(DAT_00438434);
        if (param_1 == 1) {
          FUN_004028c2(DAT_00438438);
          iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_28,DAT_00438438,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004332f4);
          }
        }
        else {
          FUN_004028c2(DAT_00438418);
          iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_28,DAT_00438418,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433324);
          }
        }
      }
      else if (param_2 == 1) {
        FUN_004028c2(DAT_00438438);
        if (param_1 == 0) {
          FUN_004028c2(DAT_00438434);
          iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                            (DAT_00438438,&local_28,DAT_00438434,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433354);
          }
        }
        else {
          FUN_004028c2(DAT_00438418);
          iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                            (DAT_00438438,&local_28,DAT_00438418,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00433384);
          }
        }
      }
      else if (param_2 == 2) {
        FUN_004028c2(DAT_00438418);
        if (param_1 == 0) {
          FUN_004028c2(DAT_00438434);
          iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                            (DAT_00438418,&local_28,DAT_00438434,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004333b4);
          }
        }
        else {
          FUN_004028c2(DAT_00438438);
          iVar1 = (**(code **)(*DAT_00438418 + 0x14))
                            (DAT_00438418,&local_28,DAT_00438438,&local_38,local_8,0);
          if (iVar1 != 0) {
            FUN_00401f61(iVar1);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___004333e4);
          }
        }
      }
      else {
        FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_00433414);
      }
    }
  }
  return;
}

