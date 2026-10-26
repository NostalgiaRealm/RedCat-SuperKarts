/*
 * FUN_00418d09 at 00418d09
 * undefined __cdecl FUN_00418d09(int param_1, int param_2, undefined4 param_3)
 * Address ranges: 00418d09-00418e12
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00418d09(int param_1,int param_2,undefined4 param_3)

{
  if ((param_1 < 1) || (2 < param_1)) {
    FUN_0040187a((byte *)s__set_joystick_keys__invalid_joys_00435d9c);
  }
  switch(param_2) {
  case 0:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 1:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 2:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 3:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 4:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 5:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 6:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  case 7:
    *(undefined4 *)(&DAT_0043dcec + param_2 * 8 + param_1 * 0x5c) = param_3;
    break;
  default:
    FUN_0040187a((byte *)s__set_joystick_keys__invalid_joys_00435dd0);
  }
  return;
}

