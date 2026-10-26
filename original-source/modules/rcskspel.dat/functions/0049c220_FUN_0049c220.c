/*
 * FUN_0049c220 at 0049c220
 * undefined FUN_0049c220(void)
 * Address ranges: 0049c220-0049c4e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c220(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = *(int *)(param_1 + 8);
  fVar2 = *(float *)(param_1 + 0x1c);
  fVar3 = *(float *)(param_1 + 0x20);
  fVar4 = *(float *)(param_1 + 0x24);
  pfVar8 = (float *)FUN_00405f20(*(float *)(param_1 + 0x10) * 0.1,*(float *)(param_1 + 0x14) * 0.1,
                                 *(float *)(param_1 + 0x18) * 0.1);
  fVar5 = *pfVar8;
  fVar6 = pfVar8[2];
  iVar10 = iVar10 * 0xd0;
  fVar1 = *(float *)(iVar10 + 0xac + DAT_0067ee20);
  pfVar8 = (float *)FUN_00405f20(fVar1 * -fVar6,0,fVar1 * fVar5);
  pfVar8 = (float *)FUN_00405f20(*pfVar8 + *(float *)(iVar10 + 0x9c + DAT_0067ee20),
                                 pfVar8[1] + *(float *)(iVar10 + 0xa0 + DAT_0067ee20),
                                 pfVar8[2] + *(float *)(iVar10 + 0xa4 + DAT_0067ee20));
  fVar1 = *pfVar8 * fVar2 + pfVar8[2] * fVar4 + 0.0;
  if (fVar1 <= 0.0) {
    iVar9 = DAT_0067ee20 + iVar10;
    fVar1 = -((*(float *)(iVar9 + 0x98) + 1.0) * fVar1);
    if ((*(float *)(iVar9 + 0x90) != 0.0) || (*(float *)(iVar9 + 0x94) != 0.0)) {
      if (*(float *)(iVar9 + 0x90) != 0.0) {
        fVar1 = fVar1 / *(float *)(iVar9 + 0x90);
      }
      fVar7 = *(float *)(iVar9 + 0x90) * fVar1;
      fVar5 = *(float *)(iVar9 + 0x94) * fVar1 * (fVar2 * -fVar6 + fVar4 * fVar5 + 0.0) * 0.34;
      if (fVar5 <= 6.0) {
        if (fVar5 < -6.0) {
          fVar5 = -6.0;
        }
      }
      else {
        fVar5 = 6.0;
      }
      _DAT_006a5b80 = fVar1;
      *(float *)(iVar9 + 0x9c) = fVar7 * fVar2 + *(float *)(iVar9 + 0x9c);
      *(float *)(iVar9 + 0xa0) = fVar3 * fVar7 + *(float *)(iVar9 + 0xa0);
      *(float *)(iVar9 + 0xa4) = fVar4 * fVar7 + *(float *)(iVar9 + 0xa4);
      *(float *)(iVar10 + 0xac + DAT_0067ee20) =
           fVar5 * 0.25 + *(float *)(iVar10 + 0xac + DAT_0067ee20);
      pfVar8 = (float *)(iVar10 + 0xa8 + DAT_0067ee20);
      *pfVar8 = *(float *)(iVar10 + 0x90 + DAT_0067ee20) * *(float *)(param_1 + 0x24) * fVar1 * 16.0
                + *pfVar8;
      pfVar8 = (float *)(iVar10 + 0xb0 + DAT_0067ee20);
      *pfVar8 = *pfVar8 - *(float *)(iVar10 + 0x90 + DAT_0067ee20) * *(float *)(param_1 + 0x1c) *
                          fVar1 * 16.0;
      *(float *)(iVar10 + 0xa0 + DAT_0067ee20) =
           *(float *)(iVar10 + 0x90 + DAT_0067ee20) * fVar1 * 1.5;
    }
  }
  return;
}

