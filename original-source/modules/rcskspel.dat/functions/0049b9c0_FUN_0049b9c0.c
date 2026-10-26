/*
 * FUN_0049b9c0 at 0049b9c0
 * undefined FUN_0049b9c0(void)
 * Address ranges: 0049b9c0-0049c215
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049b9c0(int param_1)

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
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  float *pfVar19;
  float *pfVar20;
  float *pfVar21;
  float *pfVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  float local_80;
  float local_7c;
  float local_68;
  float local_38;
  float local_2c;
  float local_14;
  
  iVar24 = *(int *)(param_1 + 0xc);
  iVar25 = *(int *)(param_1 + 8) * 0xd0;
  uVar16 = __ftol();
  iVar24 = iVar24 * 0xd0;
  uVar17 = __ftol();
  fVar4 = *(float *)(param_1 + 0x1c);
  fVar5 = *(float *)(param_1 + 0x20);
  iVar18 = (uVar16 & DAT_004fc8f8) * 4;
  pfVar22 = (float *)(DAT_006a5c88 + iVar18);
  pfVar19 = (float *)(iVar18 + DAT_006a5cd0);
  fVar13 = fVar4 * *pfVar19 - *(float *)(param_1 + 0x24) * *pfVar22;
  fVar12 = fVar4 * *pfVar22 + *(float *)(param_1 + 0x24) * *pfVar19;
  pfVar20 = (float *)FUN_00405f20(*(float *)(param_1 + 0x10) * 0.1,*(float *)(param_1 + 0x14) * 0.1,
                                  *(float *)(param_1 + 0x18) * 0.1);
  fVar15 = *pfVar20 * *pfVar19 - pfVar20[2] * *pfVar22;
  pfVar21 = (float *)(iVar25 + 0x9c + DAT_0067ee20);
  fVar6 = *pfVar21;
  fVar7 = pfVar21[2];
  fVar14 = *pfVar20 * *pfVar22 + pfVar20[2] * *pfVar19;
  fVar4 = *pfVar22;
  fVar1 = *pfVar19;
  pfVar21 = (float *)(iVar24 + 0x9c + DAT_0067ee20);
  fVar8 = *pfVar21;
  fVar9 = pfVar21[2];
  iVar18 = (uVar17 & DAT_004fc8f8) * 4;
  fVar2 = *(float *)(iVar18 + DAT_006a5c88);
  fVar3 = *(float *)(iVar18 + DAT_006a5cd0);
  iVar23 = *(int *)(iVar25 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38;
  iVar18 = *(int *)(iVar24 + 0xc + DAT_0067ee20);
  pfVar21 = (float *)(DAT_006a5c38 + iVar18 + 0x50 + iVar18 * 0xa8);
  pfVar21 = (float *)FUN_00405f20(*(float *)(iVar23 + 0x50) - *pfVar21,
                                  *(float *)(iVar23 + 0x54) - pfVar21[1],
                                  *(float *)(iVar23 + 0x58) -
                                  *(float *)(DAT_006a5c38 + iVar18 + 0x58 + iVar18 * 0xa8));
  pfVar21 = (float *)FUN_00405f20(*pfVar21 * 0.1,pfVar21[1] * 0.1,pfVar21[2] * 0.1);
  pfVar21 = (float *)FUN_00405f20(*pfVar21 + fVar15,fVar5 + pfVar21[1],pfVar21[2] + fVar14);
  fVar10 = *pfVar21;
  fVar11 = pfVar21[2];
  fVar14 = -fVar14;
  fVar5 = *(float *)(iVar25 + 0xac + DAT_0067ee20);
  pfVar21 = (float *)FUN_00405f20(fVar5 * fVar14,0,fVar5 * fVar15);
  pfVar21 = (float *)FUN_00405f20(*pfVar21 + (fVar6 * fVar1 - fVar7 * fVar4),local_38 + pfVar21[1],
                                  pfVar21[2] + fVar6 * fVar4 + fVar7 * fVar1);
  fVar1 = *pfVar21;
  fVar5 = pfVar21[1];
  fVar6 = pfVar21[2];
  fVar4 = *(float *)(iVar24 + 0xac + DAT_0067ee20);
  pfVar21 = (float *)FUN_00405f20(fVar4 * -fVar11,0,fVar4 * fVar10);
  pfVar21 = (float *)FUN_00405f20(*pfVar21 + (fVar8 * fVar3 - fVar9 * fVar2),local_2c + pfVar21[1],
                                  pfVar21[2] + fVar8 * fVar2 + fVar9 * fVar3);
  pfVar19 = (float *)FUN_00405f20(fVar1 - *pfVar21,fVar5 - pfVar21[1],fVar6 - pfVar21[2]);
  pfVar21 = (float *)(iVar25 + 0x90 + DAT_0067ee20);
  local_80 = -((pfVar19[2] * fVar12 + local_68 * pfVar19[1] + *pfVar19 * fVar13) *
              ((*(float *)(iVar24 + 0x98 + DAT_0067ee20) + *(float *)(iVar25 + 0x98 + DAT_0067ee20))
               * 0.5 + 1.0));
  fVar4 = *(float *)(iVar24 + 0x90 + DAT_0067ee20) + *pfVar21;
  if (fVar4 != 0.0) {
    local_80 = local_80 / fVar4;
  }
  _DAT_006a5b80 = local_80;
  fVar4 = *pfVar21 * local_80;
  pfVar21 = (float *)FUN_00405f20(fVar4 * fVar13,local_68 * fVar4,fVar4 * fVar12);
  fVar4 = *(float *)(iVar24 + 0x90 + DAT_0067ee20) * local_80;
  iVar18 = iVar25 + DAT_0067ee20;
  fVar1 = fVar4 * fVar13;
  fVar4 = fVar4 * fVar12;
  local_7c = *(float *)(iVar18 + 0x94) * local_80 * (fVar13 * fVar14 + fVar15 * fVar12 + 0.0) * 0.34
  ;
  fVar2 = *(float *)(iVar24 + 0x94 + DAT_0067ee20) * local_80 *
          (fVar13 * -fVar11 + fVar12 * fVar10 + 0.0) * 0.34;
  if (local_7c <= 6.0) {
    if (local_7c < -6.0) {
      local_7c = -6.0;
    }
  }
  else {
    local_7c = 6.0;
  }
  if (fVar2 <= 6.0) {
    if (fVar2 < -6.0) {
      fVar2 = -6.0;
    }
  }
  else {
    fVar2 = 6.0;
  }
  fVar8 = *pfVar21;
  fVar9 = pfVar21[2];
  iVar23 = (-uVar16 & DAT_004fc8f8) * 4;
  fVar3 = *(float *)(iVar23 + DAT_006a5c88);
  fVar5 = *(float *)(iVar23 + DAT_006a5cd0);
  iVar23 = (-uVar17 & DAT_004fc8f8) * 4;
  fVar6 = *(float *)(iVar23 + DAT_006a5c88);
  fVar7 = *(float *)(iVar23 + DAT_006a5cd0);
  *(float *)(iVar18 + 0x9c) = (fVar8 * fVar5 - fVar9 * fVar3) + *(float *)(iVar18 + 0x9c);
  *(float *)(iVar18 + 0xa0) = local_14 + *(float *)(iVar18 + 0xa0);
  *(float *)(iVar18 + 0xa4) = fVar8 * fVar3 + fVar9 * fVar5 + *(float *)(iVar18 + 0xa4);
  pfVar21 = (float *)(iVar24 + 0x9c + DAT_0067ee20);
  *pfVar21 = *(float *)(iVar24 + 0x9c + DAT_0067ee20) - (fVar7 * fVar1 - fVar4 * fVar6);
  pfVar21[1] = pfVar21[1] - local_2c;
  pfVar21[2] = pfVar21[2] - (fVar6 * fVar1 + fVar4 * fVar7);
  *(float *)(iVar25 + 0xac + DAT_0067ee20) = local_7c + *(float *)(iVar25 + 0xac + DAT_0067ee20);
  *(float *)(iVar24 + 0xac + DAT_0067ee20) = *(float *)(iVar24 + 0xac + DAT_0067ee20) - fVar2;
  pfVar21 = (float *)(iVar25 + 0xa8 + DAT_0067ee20);
  *pfVar21 = *(float *)(iVar25 + 0x90 + DAT_0067ee20) * *(float *)(param_1 + 0x24) * local_80 * 16.0
             + *pfVar21;
  pfVar21 = (float *)(iVar25 + 0xb0 + DAT_0067ee20);
  *pfVar21 = *pfVar21 -
             *(float *)(iVar25 + 0x90 + DAT_0067ee20) * *(float *)(param_1 + 0x1c) * local_80 * 16.0
  ;
  iVar18 = (-uVar17 & DAT_004fc8f8) * 4;
  fVar4 = *(float *)(iVar18 + DAT_006a5c88);
  fVar1 = *(float *)(iVar18 + DAT_006a5cd0);
  pfVar21 = (float *)(iVar24 + 0xa8 + DAT_0067ee20);
  *pfVar21 = *pfVar21 -
             *(float *)(iVar24 + 0x90 + DAT_0067ee20) * (fVar4 * fVar13 + fVar1 * fVar12) * local_80
             * 16.0;
  pfVar21 = (float *)(iVar24 + 0xb0 + DAT_0067ee20);
  *pfVar21 = *(float *)(iVar24 + 0x90 + DAT_0067ee20) * (fVar1 * fVar13 - fVar4 * fVar12) * local_80
             * 16.0 + *pfVar21;
  *(float *)(iVar25 + 0xa0 + DAT_0067ee20) =
       *(float *)(iVar24 + 0x90 + DAT_0067ee20) * local_80 * 1.5;
  *(float *)(iVar24 + 0xa0 + DAT_0067ee20) =
       *(float *)(iVar24 + 0x90 + DAT_0067ee20) * local_80 * 1.5;
  return;
}

