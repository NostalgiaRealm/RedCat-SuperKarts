/*
 * FUN_00466a2c at 00466a2c
 * undefined FUN_00466a2c(void)
 * Address ranges: 00466a2c-00466a52
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466a2c(int *param_1,undefined4 *param_2)

{
  FUN_00444e50((int)param_1,(int)param_2);
  if ((*(byte *)(param_1 + 8) & 1) == 0) {
    *param_2 = 0x15;
    (**(code **)(*param_1 + -0x10))(param_1,param_2);
  }
  return;
}

