/*
 * FUN_00411340 at 00411340
 * undefined FUN_00411340(void)
 * Address ranges: 00411340-004113a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00411340(undefined4 param_1,int param_2,undefined4 param_3)

{
  switch(param_3) {
  case 0:
    return *(undefined4 *)(param_2 * 0x50 + 0x18 + DAT_00680ae0);
  case 1:
    return *(undefined4 *)(param_2 * 0x50 + 0x14 + DAT_00680ae0);
  case 2:
    return *(undefined4 *)(param_2 * 0x50 + 0x1c + DAT_00680ae0);
  case 3:
    return *(undefined4 *)(param_2 * 0x50 + 0x20 + DAT_00680ae0);
  default:
    return 0xffffffff;
  }
}

