/*
 * FUN_004175f0 at 004175f0
 * undefined FUN_004175f0(void)
 * Address ranges: 004175f0-00417634
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004175f0(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *param_1 = *param_2 / param_3;
  param_1[1] = fVar1 / param_3;
  param_1[2] = fVar2 / param_3;
  return;
}

