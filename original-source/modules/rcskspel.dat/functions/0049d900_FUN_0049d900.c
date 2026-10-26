/*
 * FUN_0049d900 at 0049d900
 * undefined FUN_0049d900(void)
 * Address ranges: 0049d900-0049d975
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0049d900(float *param_1,float *param_2)

{
  param_1 = (float *)(param_1[2] * *param_2 - param_2[2] * *param_1);
  if (0.0 <= (float)param_1) {
    FUN_004bfa20();
  }
  else {
    FUN_004bfa20();
  }
  param_1 = (float *)__ftol();
  FUN_0049f340(&param_1,0xffffd8f0,10000);
  return param_1;
}

