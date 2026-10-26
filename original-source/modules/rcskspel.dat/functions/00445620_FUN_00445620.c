/*
 * FUN_00445620 at 00445620
 * undefined FUN_00445620(void)
 * Address ranges: 00445620-00445635
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00445620(float param_1,int param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)param_1;
  if (1 < param_2) {
    param_2 = param_2 + -1;
    do {
      fVar1 = fVar1 * (float10)param_1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return fVar1;
}

