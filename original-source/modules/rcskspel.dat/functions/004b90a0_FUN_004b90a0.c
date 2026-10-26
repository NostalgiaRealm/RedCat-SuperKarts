/*
 * FUN_004b90a0 at 004b90a0
 * undefined FUN_004b90a0(void)
 * Address ranges: 004b90a0-004b919f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b90a0(undefined4 param_1)

{
  switch(param_1) {
  case 1:
    if (DAT_00501330 != -1) {
      FUN_004afce0(s_using_3dfx_driver__d_0050171c,DAT_00501330);
      return DAT_006ab8f4 + DAT_00501330 * 0xd8;
    }
    if (DAT_0050132c != -1) {
      FUN_004afce0(s_using_unknown_secondary_driver___005016f8,DAT_0050132c);
      return DAT_006ab8f4 + DAT_0050132c * 0xd8;
    }
    break;
  case 2:
    if (DAT_0050132c != -1) {
      FUN_004afce0(s_using_unknown_secondary_driver___005016f8,DAT_0050132c);
      return DAT_006ab8f4 + DAT_0050132c * 0xd8;
    }
    break;
  case 3:
    if (DAT_00501330 != -1) {
      FUN_004afce0(s_using_3dfx_driver__d_0050171c,DAT_00501330);
      return DAT_006ab8f4 + DAT_00501330 * 0xd8;
    }
    break;
  case 4:
    if (DAT_00501334 != -1) {
      FUN_004afce0(s_using_user_defined_driver__d_005016d8,DAT_00501334);
      return DAT_006ab8f4 + DAT_00501334 * 0xd8;
    }
  }
  return 0;
}

