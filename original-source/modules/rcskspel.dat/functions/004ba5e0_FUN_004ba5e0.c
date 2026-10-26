/*
 * FUN_004ba5e0 at 004ba5e0
 * undefined FUN_004ba5e0(void)
 * Address ranges: 004ba5e0-004ba80c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ba5e0(void)

{
  MMRESULT MVar1;
  tagJOYCAPSA local_194;
  
  _DAT_006ab988 = 0x34;
  _DAT_006ab98c = 0x83;
  MVar1 = joyGetPosEx(0,(LPJOYINFOEX)&DAT_006ab988);
  switch(MVar1) {
  case 0:
    FUN_004afce0(s_Joystick_One_Found_00502170);
    DAT_006aba1c = 1;
    _DAT_006aba60 = DAT_006ab990;
    _DAT_006aba64 = DAT_006ab994;
    FUN_004afce0(s__1_Xbase____d_00502160,DAT_006ab990);
    FUN_004afce0(s__1_Ybase____d_00502150,DAT_006ab994);
    break;
  case 2:
  case 6:
  case 0xa6:
  case 0xa7:
    DAT_006aba1c = 0;
    break;
  case 0xb:
    FUN_004afee0(s__Joystick_invalid_params_00502067 + 1);
  }
  MVar1 = joyGetDevCapsA(0,&local_194,0x194);
  if (MVar1 == 0) {
    _DAT_006aba68 = local_194.wXmax;
    _DAT_006aba6c = local_194.wXmin;
    _DAT_006aba74 = local_194.wYmin;
    _DAT_006aba70 = local_194.wYmax;
    FUN_004afce0(s__1_Xmin____d_00502140,local_194.wXmin);
    FUN_004afce0(s__1_Xmax____d_00502130,local_194.wXmax);
    FUN_004afce0(s__1_Ymin____d_00502120,local_194.wYmin);
    FUN_004afce0(s__1_Ymax____d_00502110,local_194.wYmax);
  }
  _DAT_006ab988 = 0x34;
  _DAT_006ab98c = 0x83;
  MVar1 = joyGetPosEx(1,(LPJOYINFOEX)&DAT_006ab988);
  switch(MVar1) {
  case 0:
    FUN_004afce0(s_Joystick_Two_Found_005020e4);
    DAT_006aba78 = 1;
    _DAT_006ababc = DAT_006ab990;
    _DAT_006abac0 = DAT_006ab994;
    FUN_004afce0(s__2_Xbase____d_005020d4,DAT_006ab990);
    FUN_004afce0(s__2_Ybase____d_005020c4,DAT_006ab994);
    break;
  case 2:
  case 6:
  case 0xa6:
  case 0xa7:
    DAT_006aba78 = 0;
    break;
  case 0xb:
    FUN_004afee0(s_Joystick_invalid_param_005020f8);
  }
  MVar1 = joyGetDevCapsA(1,&local_194,0x194);
  if (MVar1 == 0) {
    _DAT_006abac4 = local_194.wXmax;
    _DAT_006abac8 = local_194.wXmin;
    _DAT_006abad0 = local_194.wYmin;
    _DAT_006abacc = local_194.wYmax;
    FUN_004afce0(s__2_Xmin____d_005020b4,local_194.wXmin);
    FUN_004afce0(s__2_Xmax____d_005020a4,local_194.wXmax);
    FUN_004afce0(s__2_Ymin____d_00502094,local_194.wYmin);
    FUN_004afce0(s__2_Ymax____d_00502084,local_194.wYmax);
  }
  return;
}

