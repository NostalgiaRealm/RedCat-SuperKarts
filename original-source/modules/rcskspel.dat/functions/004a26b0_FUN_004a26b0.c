/*
 * FUN_004a26b0 at 004a26b0
 * undefined FUN_004a26b0(void)
 * Address ranges: 004a26b0-004a270c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a26b0(float *param_1,float param_2,float param_3,float param_4)

{
  *param_1 = param_2 * *param_1;
  param_1[4] = param_3 * param_1[4];
  param_1[8] = param_4 * param_1[8];
  param_1[1] = param_2 * param_1[1];
  param_1[5] = param_3 * param_1[5];
  param_1[9] = param_4 * param_1[9];
  param_1[2] = param_2 * param_1[2];
  param_1[6] = param_3 * param_1[6];
  param_1[10] = param_4 * param_1[10];
  return;
}

