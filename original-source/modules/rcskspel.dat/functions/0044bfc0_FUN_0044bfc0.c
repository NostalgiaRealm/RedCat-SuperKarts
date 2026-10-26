/*
 * FUN_0044bfc0 at 0044bfc0
 * undefined FUN_0044bfc0(void)
 * Address ranges: 0044bfc0-0044c045
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044bfc0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 int param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8,
                 undefined4 param_9,undefined4 *param_10,undefined4 *param_11,undefined4 *param_12,
                 int param_13)

{
  while (param_4 != param_8) {
    *param_12 = *param_4;
    param_12 = param_12 + 1;
    if (param_12 == param_11) {
      param_12 = *(undefined4 **)(param_13 + 4);
      param_13 = param_13 + 4;
      param_11 = param_12 + 0x400;
      param_10 = param_12;
    }
    param_4 = param_4 + 1;
    if (param_4 == param_3) {
      param_4 = *(undefined4 **)(param_5 + 4);
      param_5 = param_5 + 4;
      param_3 = param_4 + 0x400;
    }
  }
  *param_1 = param_10;
  param_1[1] = param_11;
  param_1[2] = param_12;
  param_1[3] = param_13;
  return;
}

