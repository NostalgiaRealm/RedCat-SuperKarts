/*
 * FUN_004a21a0 at 004a21a0
 * undefined FUN_004a21a0(void)
 * Address ranges: 004a21a0-004a21f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a21a0(float *param_1,float param_2)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float10 fVar4;
  float10 fVar5;
  float local_40 [4];
  float local_30;
  float local_2c;
  
  fVar4 = (float10)fcos((float10)param_2);
  pfVar2 = (float *)&DAT_006a5c90;
  pfVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  iVar1 = 0x10;
  fVar5 = (float10)fsin((float10)param_2);
  local_40[0] = (float)fVar4;
  local_2c = (float)fVar4;
  local_30 = (float)fVar5;
  local_40[1] = -(float)fVar5;
  pfVar2 = local_40;
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

