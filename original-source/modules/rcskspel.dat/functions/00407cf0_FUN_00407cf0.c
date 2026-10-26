/*
 * FUN_00407cf0 at 00407cf0
 * undefined FUN_00407cf0(void)
 * Address ranges: 00407cf0-00407d60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407cf0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  if ((*(uint *)(&DAT_00505114 + param_1 * 0x24) & 0x100) != 0) {
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return;
  }
  if ((*(uint *)(&DAT_00505114 + param_1 * 0x24) & 0x200) != 0) {
    *param_2 = 2;
    *param_3 = 1;
    *param_4 = 0;
    return;
  }
  *param_2 = 1;
  *param_3 = 0;
  *param_4 = 2;
  return;
}

