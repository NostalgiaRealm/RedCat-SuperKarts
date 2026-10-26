/*
 * FUN_004a2270 at 004a2270
 * undefined FUN_004a2270(void)
 * Address ranges: 004a2270-004a22d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2270(float *param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float local_40 [8];
  float local_20;
  float local_18;
  
  iVar3 = (DAT_004fc8f8 & param_2) * 4;
  fVar1 = *(float *)(iVar3 + DAT_006a5cd0);
  fVar2 = *(float *)(iVar3 + DAT_006a5c88);
  pfVar4 = (float *)&DAT_006a5c90;
  pfVar5 = local_40;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar5 = pfVar5 + 1;
  }
  local_40[0] = fVar1;
  local_18 = fVar1;
  local_40[2] = fVar2;
  local_20 = -fVar2;
  pfVar4 = local_40;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

