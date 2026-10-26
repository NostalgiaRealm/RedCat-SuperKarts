/*
 * FUN_004a16f0 at 004a16f0
 * undefined FUN_004a16f0(void)
 * Address ranges: 004a16f0-004a17bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a16f0(float *param_1,uint param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = (DAT_004fc8f8 & param_2) * 4;
  fVar1 = *(float *)(iVar3 + DAT_006a5c88);
  fVar2 = *(float *)(iVar3 + DAT_006a5cd0);
  *param_1 = fVar2 * *param_3 + fVar1 * param_3[8];
  param_1[1] = fVar1 * param_3[9] + fVar2 * param_3[1];
  param_1[2] = fVar1 * param_3[10] + fVar2 * param_3[2];
  param_1[3] = fVar1 * param_3[0xb] + fVar2 * param_3[3];
  param_1[4] = param_3[4];
  param_1[5] = param_3[5];
  param_1[6] = param_3[6];
  param_1[7] = param_3[7];
  param_1[8] = fVar2 * param_3[8] - fVar1 * *param_3;
  param_1[9] = fVar2 * param_3[9] - fVar1 * param_3[1];
  param_1[10] = fVar2 * param_3[10] - fVar1 * param_3[2];
  param_1[0xb] = fVar2 * param_3[0xb] - fVar1 * param_3[3];
  param_1[0xc] = param_3[0xc];
  param_1[0xd] = param_3[0xd];
  param_1[0xe] = param_3[0xe];
  param_1[0xf] = param_3[0xf];
  return;
}

