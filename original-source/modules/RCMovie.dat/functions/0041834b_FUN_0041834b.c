/*
 * FUN_0041834b at 0041834b
 * char __stdcall FUN_0041834b(void)
 * Address ranges: 0041834b-0041842f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_0041834b(void)

{
  MMRESULT MVar1;
  char local_8;
  
  _DAT_0043dcb0 = 0x34;
  _DAT_0043dcb4 = 0x83;
  MVar1 = joyGetPosEx(0,(LPJOYINFOEX)&DAT_0043dcb0);
  switch(MVar1) {
  case 0:
    DAT_0043dd44 = 1;
    break;
  case 2:
  case 6:
  case 0xa6:
  case 0xa7:
    DAT_0043dd44 = 0;
    break;
  case 0xb:
    FUN_0040187a((byte *)(s__Joystick_invalid_params_00435c47 + 1));
  }
  MVar1 = joyGetPosEx(1,(LPJOYINFOEX)&DAT_0043dcb0);
  switch(MVar1) {
  case 0:
    DAT_0043dda0 = 1;
    break;
  case 2:
  case 6:
  case 0xa6:
  case 0xa7:
    DAT_0043dda0 = 0;
    break;
  case 0xb:
    FUN_0040187a((byte *)s_Joystick_invalid_params_00435c64);
  }
  local_8 = DAT_0043dd44 != 0;
  if (DAT_0043dda0 != 0) {
    local_8 = local_8 + '\x02';
  }
  return local_8;
}

