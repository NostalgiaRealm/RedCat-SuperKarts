/*
 * FUN_0049a750 at 0049a750
 * undefined FUN_0049a750(void)
 * Address ranges: 0049a750-0049a7eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0049a750(float param_1,float param_2,float *param_3,float *param_4)

{
  if (param_1 <= 0.0) {
    if (0.0 <= param_1) {
      if (0.0 < param_2) {
        return 0;
      }
    }
    else {
      param_2 = param_2 / param_1;
      if (param_2 < *param_3) {
        return 0;
      }
      if (param_2 < *param_4) {
        *param_4 = param_2;
        return 1;
      }
    }
  }
  else {
    param_2 = param_2 / param_1;
    if (*param_4 < param_2) {
      return 0;
    }
    if (*param_3 < param_2) {
      *param_3 = param_2;
      return 1;
    }
  }
  return 1;
}

