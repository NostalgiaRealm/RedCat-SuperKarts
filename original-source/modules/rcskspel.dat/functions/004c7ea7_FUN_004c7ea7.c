/*
 * FUN_004c7ea7 at 004c7ea7
 * undefined FUN_004c7ea7(void)
 * Address ranges: 004c7ea7-004c7ef9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004c7ea7(undefined4 param_1,double param_2,undefined4 param_3)

{
  float10 fVar1;
  
  if (DAT_005037cc == 0) {
    fVar1 = (float10)FUN_004c845c(1,param_1,param_2,0,param_2,param_3);
    return fVar1;
  }
  _DAT_006b66e8 = 0x21;
  FUN_004c86cf();
  return (float10)param_2;
}

