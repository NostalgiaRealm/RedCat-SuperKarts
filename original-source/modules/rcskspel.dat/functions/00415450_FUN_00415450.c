/*
 * FUN_00415450 at 00415450
 * undefined FUN_00415450(void)
 * Address ranges: 00415450-0041551a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415450(undefined4 *param_1,undefined4 param_2,undefined4 param_3,float param_4,
                 float param_5)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  
  FUN_004150f0(param_3,param_2);
  fVar3 = (float10)FUN_00415410();
  fVar1 = *(float *)(&DAT_00505b9c + (DAT_00507298 + DAT_0053be2c * 0x2b + DAT_0053bf00 * 6) * 4);
  fVar2 = *(float *)(&DAT_00505b80 + DAT_0053be2c * 0xac);
  if (DAT_0053bdf8 == 0) {
    fVar4 = (float10)0.0;
  }
  else {
    fVar4 = (float10)4000.0;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = (float)((fVar3 * (float10)fVar1 * (float10)param_4 * (float10)0.030699998 + fVar4) -
                      (float10)param_5 * (float10)fVar2 * (float10)0.01);
  return;
}

