/*
 * FUN_004bab80 at 004bab80
 * undefined FUN_004bab80(void)
 * Address ranges: 004bab80-004bac67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bab80(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((param_1 < 1) || (2 < param_1)) {
    FUN_004afee0(s__set_joystick_keys__invalid_joys_005021bc,param_1);
  }
  switch(param_2) {
  case 0:
    *(undefined4 *)(&DAT_006ab9c4 + param_1 * 0x5c) = param_3;
    return;
  case 1:
    *(undefined4 *)(&DAT_006ab9cc + param_1 * 0x5c) = param_3;
    return;
  case 2:
    *(undefined4 *)(&DAT_006ab9d4 + param_1 * 0x5c) = param_3;
    return;
  case 3:
    *(undefined4 *)(&DAT_006ab9dc + param_1 * 0x5c) = param_3;
    return;
  case 4:
    *(undefined4 *)(&DAT_006ab9e4 + param_1 * 0x5c) = param_3;
    return;
  case 5:
    *(undefined4 *)(&DAT_006ab9ec + param_1 * 0x5c) = param_3;
    return;
  case 6:
    *(undefined4 *)(&DAT_006ab9f4 + param_1 * 0x5c) = param_3;
    return;
  case 7:
    *(undefined4 *)(&DAT_006ab9fc + param_1 * 0x5c) = param_3;
    return;
  default:
    FUN_004afee0(s__set_joystick_keys__invalid_joys_00502184,param_2);
    return;
  }
}

