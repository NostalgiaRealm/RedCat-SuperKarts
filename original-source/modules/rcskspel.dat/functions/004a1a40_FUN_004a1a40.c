/*
 * FUN_004a1a40 at 004a1a40
 * undefined FUN_004a1a40(void)
 * Address ranges: 004a1a40-004a1ac1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a1a40(float *param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float local_40 [5];
  float local_2c;
  float local_18;
  float local_14;
  float local_8;
  undefined4 local_4;
  
  iVar1 = 0x10;
  fVar4 = (float10)fcos((float10)param_4 * (float10)0.5);
  pfVar2 = (float *)&DAT_006a5cd8;
  pfVar3 = local_40;
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  iVar1 = 0x10;
  local_4 = 0;
  fVar5 = (float10)fsin((float10)param_4 * (float10)0.5);
  fVar6 = (fVar5 * (float10)param_3) / ((float10)param_3 - (float10)param_2);
  local_40[0] = (float)fVar4;
  local_2c = (float)fVar4;
  local_18 = (float)fVar6;
  local_8 = (float)-((float10)param_2 * fVar6);
  local_14 = (float)fVar5;
  pfVar2 = local_40;
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

