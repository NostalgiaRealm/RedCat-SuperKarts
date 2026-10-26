/*
 * FUN_00437ea0 at 00437ea0
 * undefined FUN_00437ea0(void)
 * Address ranges: 00437ea0-00437f26
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00437ea0(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0053bebc;
  if (((int)param_1 < DAT_00508610) && (-1 < (int)param_1)) {
    uVar1 = (&DAT_0050820c)[(int)param_1 * 0x1c];
  }
  switch(uVar1) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 3;
  case 4:
    return 4;
  case 5:
    return 5;
  case 6:
    return 6;
  case 7:
    return 7;
  case 8:
    return 8;
  case 9:
    return 9;
  default:
    param_1 = s_Unknown_voice_004ec16c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_1,&DAT_004d5538);
  }
}

