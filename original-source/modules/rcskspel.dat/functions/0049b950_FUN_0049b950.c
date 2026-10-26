/*
 * FUN_0049b950 at 0049b950
 * undefined FUN_0049b950(void)
 * Address ranges: 0049b950-0049b9b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049b950(float *param_1,float param_2,undefined4 param_3,float param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_8;
  
  iVar3 = (DAT_004fc8f8 & param_5) * 4;
  fVar1 = *(float *)(iVar3 + DAT_006a5c88);
  fVar2 = *(float *)(iVar3 + DAT_006a5cd0);
  *param_1 = param_2 * fVar2 - param_4 * fVar1;
  param_1[1] = local_8;
  param_1[2] = param_2 * fVar1 + param_4 * fVar2;
  return;
}

