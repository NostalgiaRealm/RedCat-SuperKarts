/*
 * FUN_004a2560 at 004a2560
 * undefined FUN_004a2560(void)
 * Address ranges: 004a2560-004a25e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2560(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float local_40 [16];
  
  pfVar11 = param_3;
  pfVar10 = (float *)&DAT_006a5cd8;
  pfVar8 = local_40;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar8 = *pfVar10;
    pfVar10 = pfVar10 + 1;
    pfVar8 = pfVar8 + 1;
  }
  param_3 = (float *)0x4;
  iVar5 = (int)local_40 - (int)pfVar11;
  do {
    pfVar8 = (float *)(iVar5 + (int)pfVar11);
    iVar9 = 4;
    pfVar10 = param_2;
    do {
      fVar1 = *pfVar8;
      iVar7 = 4;
      pfVar4 = pfVar10;
      pfVar6 = pfVar11;
      do {
        fVar2 = *pfVar4;
        fVar3 = *pfVar6;
        pfVar4 = pfVar4 + 4;
        pfVar6 = pfVar6 + 1;
        iVar7 = iVar7 + -1;
        fVar1 = fVar2 * fVar3 + fVar1;
      } while (iVar7 != 0);
      *pfVar8 = fVar1;
      pfVar8 = pfVar8 + 1;
      pfVar10 = pfVar10 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pfVar11 = pfVar11 + 4;
    param_3 = (float *)((int)param_3 + -1);
  } while (param_3 != (float *)0x0);
  pfVar11 = local_40;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *param_1 = *pfVar11;
    pfVar11 = pfVar11 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

