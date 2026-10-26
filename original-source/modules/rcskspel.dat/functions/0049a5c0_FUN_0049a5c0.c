/*
 * FUN_0049a5c0 at 0049a5c0
 * undefined FUN_0049a5c0(void)
 * Address ranges: 0049a5c0-0049a620
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049a5c0(float *param_1,float *param_2,uint param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = (DAT_004fc8f8 & param_3) * 4;
  fVar1 = *(float *)(iVar5 + DAT_006a5cd0);
  fVar2 = *param_2;
  fVar3 = *(float *)(iVar5 + DAT_006a5c88);
  fVar4 = param_2[2];
  param_1[1] = 0.0;
  *param_1 = fVar1 * fVar2 - fVar3 * fVar4;
  iVar5 = (DAT_004fc8f8 & param_3) * 4;
  param_1[2] = *(float *)(iVar5 + DAT_006a5cd0) * param_2[2] +
               *(float *)(iVar5 + DAT_006a5c88) * *param_2;
  return;
}

