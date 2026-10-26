/*
 * FUN_004b6120 at 004b6120
 * undefined FUN_004b6120(void)
 * Address ranges: 004b6120-004b64bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b6120(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,
                 byte param_11)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar2 = 0x1000000;
  if ((param_11 & 8) != 0) {
    uVar2 = 0x1008000;
  }
  if ((((-1 < param_5) && (param_3 <= DAT_004fe930)) && (-1 < param_6)) && (param_4 <= DAT_004fe934)
     ) {
    if (param_3 < 0) {
      param_3 = 0;
    }
    if (param_4 < 0) {
      param_4 = 0;
    }
    if (DAT_004fe934 < param_6) {
      param_6 = DAT_004fe934;
    }
    if (DAT_004fe930 < param_5) {
      param_5 = DAT_004fe930;
    }
    if ((param_3 < param_5) && (param_4 < param_6)) {
      local_10 = param_7;
      local_8 = param_9;
      local_c = param_8;
      local_4 = param_10;
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_5;
      local_14 = param_6;
      if (param_2 == 0) {
        FUN_004b08e0(DAT_006a64bc);
        if (param_1 == 0) {
          iVar1 = (**(code **)(*DAT_006a64bc + 0x14))
                            (DAT_006a64bc,&local_10,DAT_006a64bc,&local_20,uVar2,0);
          if (iVar1 == 0) {
            return;
          }
          uVar2 = FUN_004b0190(iVar1);
          uVar3 = 0x140;
        }
        else if (param_1 == 1) {
          FUN_004b08e0(DAT_006a64c0);
          iVar1 = (**(code **)(*DAT_006a64bc + 0x14))
                            (DAT_006a64bc,&local_10,DAT_006a64c0,&local_20,uVar2,0);
          if (iVar1 == 0) {
            return;
          }
          uVar2 = FUN_004b0190(iVar1);
          uVar3 = 0x149;
        }
        else {
          if (param_1 != 2) {
            return;
          }
          FUN_004b08e0(DAT_006a64a0);
          iVar1 = (**(code **)(*DAT_006a64bc + 0x14))
                            (DAT_006a64bc,&local_10,DAT_006a64a0,&local_20,uVar2,0);
          if (iVar1 == 0) {
            return;
          }
          uVar2 = FUN_004b0190(iVar1);
          uVar3 = 0x152;
        }
      }
      else if (param_2 == 1) {
        FUN_004b08e0(DAT_006a64c0);
        if (param_1 == 0) {
          FUN_004b08e0(DAT_006a64bc);
          iVar1 = (**(code **)(*DAT_006a64c0 + 0x14))
                            (DAT_006a64c0,&local_10,DAT_006a64bc,&local_20,uVar2,0);
          if (iVar1 == 0) {
            return;
          }
          uVar2 = FUN_004b0190(iVar1);
          uVar3 = 0x183;
        }
        else if (param_1 == 1) {
          iVar1 = (**(code **)(*DAT_006a64c0 + 0x14))
                            (DAT_006a64c0,&local_10,DAT_006a64c0,&local_20,uVar2,0);
          if (iVar1 == 0) {
            return;
          }
          uVar2 = FUN_004b0190(iVar1);
          uVar3 = 0x189;
        }
        else {
          if (param_1 != 2) {
            return;
          }
          FUN_004b08e0(DAT_006a64a0);
          iVar1 = (**(code **)(*DAT_006a64c0 + 0x14))
                            (DAT_006a64c0,&local_10,DAT_006a64a0,&local_20,uVar2,0);
          if (iVar1 == 0) {
            return;
          }
          uVar2 = FUN_004b0190(iVar1);
          uVar3 = 0x192;
        }
      }
      else {
        if (param_2 != 2) {
          FUN_004afee0(s__s__d____unidentified_focus_erro_004ff408,
                       s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,0x198,param_1);
          return;
        }
        FUN_004b08e0(DAT_006a64a0);
        if (param_1 == 0) {
          FUN_004b08e0(DAT_006a64bc);
          iVar1 = (**(code **)(*DAT_006a64a0 + 0x14))
                            (DAT_006a64a0,&local_10,DAT_006a64bc,&local_20,uVar2,0);
          if (iVar1 == 0) {
            return;
          }
          uVar2 = FUN_004b0190(iVar1);
          uVar3 = 0x163;
        }
        else if (param_1 == 1) {
          FUN_004b08e0(DAT_006a64c0);
          iVar1 = (**(code **)(*DAT_006a64a0 + 0x14))
                            (DAT_006a64a0,&local_10,DAT_006a64c0,&local_20,uVar2,0);
          if (iVar1 == 0) {
            return;
          }
          uVar2 = FUN_004b0190(iVar1);
          uVar3 = 0x16c;
        }
        else {
          if (param_1 != 2) {
            return;
          }
          iVar1 = (**(code **)(*DAT_006a64a0 + 0x14))
                            (DAT_006a64a0,&local_10,DAT_006a64a0,&local_20,uVar2,0);
          if (iVar1 == 0) {
            return;
          }
          uVar2 = FUN_004b0190(iVar1);
          uVar3 = 0x172;
        }
      }
      FUN_004afee0(s__s__d____blitting_error___s___004feb9c,
                   s_C__libraries_dxdraw_Clipblit_cpp_00500ce0,uVar3,uVar2);
    }
  }
  return;
}

