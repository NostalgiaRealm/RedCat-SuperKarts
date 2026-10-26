/*
 * FUN_004185b0 at 004185b0
 * undefined __stdcall FUN_004185b0(void)
 * Address ranges: 004185b0-004188ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004185b0(void)

{
  MMRESULT MVar1;
  tagJOYCAPSA local_198;
  
  _DAT_0043dcb0 = 0x34;
  _DAT_0043dcb4 = 0x83;
  MVar1 = joyGetPosEx(0,(LPJOYINFOEX)&DAT_0043dcb0);
  switch(MVar1) {
  case 0:
    FUN_004015a6((byte *)s_Joystick_One_Found_00435c9c);
    DAT_0043dd44 = 1;
    _DAT_0043dd88 = DAT_0043dcb8;
    _DAT_0043dd8c = DAT_0043dcbc;
    FUN_004015a6((byte *)s__1_Xbase____d_00435cb0);
    FUN_004015a6((byte *)s__1_Ybase____d_00435cc0);
    break;
  case 2:
    DAT_0043dd44 = 0;
    break;
  case 6:
    DAT_0043dd44 = 0;
    break;
  case 0xb:
    FUN_0040187a((byte *)s_Joystick_invalid_params_00435c80);
    break;
  case 0xa6:
    DAT_0043dd44 = 0;
    break;
  case 0xa7:
    DAT_0043dd44 = 0;
  }
  MVar1 = joyGetDevCapsA(0,&local_198,0x194);
  if (MVar1 == 0) {
    _DAT_0043dd94 = local_198.wXmin;
    _DAT_0043dd90 = local_198.wXmax;
    _DAT_0043dd9c = local_198.wYmin;
    _DAT_0043dd98 = local_198.wYmax;
    FUN_004015a6((byte *)s__1_Xmin____d_00435cd0);
    FUN_004015a6((byte *)s__1_Xmax____d_00435ce0);
    FUN_004015a6((byte *)s__1_Ymin____d_00435cf0);
    FUN_004015a6((byte *)s__1_Ymax____d_00435d00);
  }
  _DAT_0043dcb0 = 0x34;
  _DAT_0043dcb4 = 0x83;
  MVar1 = joyGetPosEx(1,(LPJOYINFOEX)&DAT_0043dcb0);
  switch(MVar1) {
  case 0:
    FUN_004015a6((byte *)s_Joystick_Two_Found_00435d28);
    DAT_0043dda0 = 1;
    _DAT_0043dde4 = DAT_0043dcb8;
    _DAT_0043dde8 = DAT_0043dcbc;
    FUN_004015a6((byte *)s__2_Xbase____d_00435d3c);
    FUN_004015a6((byte *)s__2_Ybase____d_00435d4c);
    break;
  case 2:
    DAT_0043dda0 = 0;
    break;
  case 6:
    DAT_0043dda0 = 0;
    break;
  case 0xb:
    FUN_0040187a((byte *)s_Joystick_invalid_param_00435d10);
    break;
  case 0xa6:
    DAT_0043dda0 = 0;
    break;
  case 0xa7:
    DAT_0043dda0 = 0;
  }
  MVar1 = joyGetDevCapsA(1,&local_198,0x194);
  if (MVar1 == 0) {
    _DAT_0043ddf0 = local_198.wXmin;
    _DAT_0043ddec = local_198.wXmax;
    _DAT_0043ddf8 = local_198.wYmin;
    _DAT_0043ddf4 = local_198.wYmax;
    FUN_004015a6((byte *)s__2_Xmin____d_00435d5c);
    FUN_004015a6((byte *)s__2_Xmax____d_00435d6c);
    FUN_004015a6((byte *)s__2_Ymin____d_00435d7c);
    FUN_004015a6((byte *)s__2_Ymax____d_00435d8c);
  }
  return;
}

