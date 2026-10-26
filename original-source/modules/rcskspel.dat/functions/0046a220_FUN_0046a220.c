/*
 * FUN_0046a220 at 0046a220
 * undefined FUN_0046a220(void)
 * Address ranges: 0046a220-0046a261
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046a220(int *param_1)

{
  FUN_004671f0();
  if (param_1[0xb] == 0) {
    param_1[0xb] = 1;
    param_1[10] = 0x43c80000;
  }
  param_1[3] = param_1[6];
  param_1[4] = param_1[7];
  param_1[5] = param_1[8];
  (**(code **)(*param_1 + 0x20))(param_1 + 6);
  return;
}

