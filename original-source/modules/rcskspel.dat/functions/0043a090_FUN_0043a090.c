/*
 * FUN_0043a090 at 0043a090
 * undefined FUN_0043a090(void)
 * Address ranges: 0043a090-0043a116
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043a090(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 param_5,undefined4 *param_6,undefined4 param_7,undefined4 *param_8,
                 int *param_9,undefined4 *param_10,undefined4 *param_11,undefined4 *param_12,
                 int param_13)

{
  while (param_4 != param_8) {
    if (param_8 == param_6) {
      param_9 = param_9 + -1;
      param_6 = (undefined4 *)*param_9;
      param_8 = param_6 + 0x400;
    }
    param_8 = param_8 + -1;
    if (param_12 == param_10) {
      param_10 = *(undefined4 **)(param_13 + -4);
      param_13 = param_13 + -4;
      param_12 = param_10 + 0x400;
      param_11 = param_12;
    }
    param_12 = param_12 + -1;
    *param_12 = *param_8;
  }
  *param_1 = param_10;
  param_1[1] = param_11;
  param_1[2] = param_12;
  param_1[3] = param_13;
  return;
}

