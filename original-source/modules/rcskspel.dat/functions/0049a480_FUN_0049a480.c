/*
 * FUN_0049a480 at 0049a480
 * undefined FUN_0049a480(void)
 * Address ranges: 0049a480-0049a5b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049a480(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float *pfVar11;
  int iVar12;
  float local_30 [12];
  
  fVar7 = *param_1;
  fVar8 = param_1[3];
  fVar9 = param_1[2];
  fVar10 = param_1[8];
  FUN_0049a630(local_30,param_2);
  fVar1 = *(float *)(param_2 + 0x30);
  fVar2 = param_1[0xc];
  fVar3 = *(float *)(param_2 + 0x34);
  fVar4 = param_1[0xd];
  fVar5 = *(float *)(param_2 + 0x38);
  fVar6 = param_1[0xe];
  iVar12 = 4;
  pfVar11 = local_30 + 2;
  do {
    iVar12 = iVar12 + -1;
    pfVar11[-2] = (fVar1 - fVar2) + pfVar11[-2];
    pfVar11[-1] = (fVar3 - fVar4) + pfVar11[-1];
    *pfVar11 = (fVar5 - fVar6) + *pfVar11;
    pfVar11 = pfVar11 + 3;
  } while (iVar12 != 0);
  FUN_0049a6d0(local_30,-(int)param_1[0x11]);
  iVar12 = 0;
  pfVar11 = local_30 + 2;
  do {
    if (fVar7 < pfVar11[-2]) {
      if (pfVar11[-2] < fVar8) {
        if (fVar9 < *pfVar11) {
          if (*pfVar11 < fVar10) {
            _DAT_00680b78 = 1;
            _DAT_00680b98 = 0;
            _DAT_00680b7c = local_30[iVar12 * 3];
            _DAT_00680b80 = local_30[iVar12 * 3 + 1];
            _DAT_00680b84 = local_30[iVar12 * 3 + 2];
            return 1;
          }
        }
      }
    }
    iVar12 = iVar12 + 1;
    pfVar11 = pfVar11 + 3;
  } while (iVar12 < 4);
  return 0;
}

