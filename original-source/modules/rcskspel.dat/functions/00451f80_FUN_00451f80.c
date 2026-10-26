/*
 * FUN_00451f80 at 00451f80
 * undefined FUN_00451f80(void)
 * Address ranges: 00451f80-00451fe3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00451f80(char *param_1)

{
  FUN_004afce0(s_CBonusController__GetBonusType_004f18dc);
  switch(param_1) {
  case (char *)0x1d:
    return 1;
  case (char *)0x1e:
    return 2;
  case (char *)0x1f:
  case (char *)0x22:
  case (char *)0x25:
  case (char *)0x26:
  case (char *)0x27:
  case (char *)0x28:
    return 0;
  case (char *)0x20:
    return 3;
  case (char *)0x21:
    return 4;
  case (char *)0x23:
  case (char *)0x24:
    return 5;
  case (char *)0x29:
    return 7;
  case (char *)0x2a:
    return 6;
  default:
    param_1 = s_CBonusController__GetBonusType__U_004f18fc;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_1,&DAT_004d5538);
  }
}

