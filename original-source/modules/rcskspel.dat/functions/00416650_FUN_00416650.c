/*
 * FUN_00416650 at 00416650
 * undefined FUN_00416650(void)
 * Address ranges: 00416650-00417036
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00416650(int param_1)

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
  int iVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  float *pfVar18;
  undefined4 *puVar19;
  int iVar20;
  float10 fVar21;
  float *pfStack_98;
  undefined1 auStack_88 [12];
  float fStack_7c;
  undefined4 auStack_78 [4];
  int iStack_68;
  float fStack_64;
  int iStack_60;
  float fStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  undefined4 *puStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [8];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  int *piStack_8;
  undefined1 auStack_4 [4];
  
  if ((DAT_00508158 & 1) == 0) {
    DAT_00508158 = DAT_00508158 | 1;
    FUN_004be654(&DAT_00417040);
  }
  if ((DAT_00508158 & 2) == 0) {
    DAT_00508158 = DAT_00508158 | 2;
    fVar21 = (float10)FUN_0048f4e0();
    _DAT_00507f70 = (float)fVar21;
  }
  if (DAT_00508184 == '\0') {
    DAT_00508184 = '\x01';
    puVar19 = &DAT_00507f48;
    for (iVar16 = 10; iVar16 != 0; iVar16 = iVar16 + -1) {
      *puVar19 = 0;
      puVar19 = puVar19 + 1;
    }
  }
  if (param_1 == DAT_0053be28) {
    DAT_004e0d14 = 1;
  }
  fVar21 = (float10)FUN_0048f4e0();
  _DAT_00507f70 = (float)(((float10)_DAT_00507f70 * (float10)9.0 + fVar21) * (float10)0.1);
  iVar16 = DAT_00508610;
  if (param_1 != DAT_0053be28) {
    iVar16 = FUN_00407580(param_1);
    if (iVar16 == -1) {
      return 0;
    }
    iVar16 = DAT_00508610;
    if (param_1 != DAT_0053be28) {
      iVar16 = FUN_00407580(param_1);
    }
  }
  piStack_8 = (int *)(&DAT_0050815c + iVar16 * 4);
  *piStack_8 = 0;
  iVar20 = param_1 * 0xd0;
  iVar10 = FUN_004906b0(0);
  iVar10 = *(int *)(*(int *)(DAT_006a5c38 + iVar10 * 0xa9 + 4) * 9 + 4 + DAT_006a5f78);
  fStack_7c = ABS(*(float *)(DAT_006a5ee0 + 0x14 +
                            *(int *)(*(int *)(iVar10 + 4) * 0x10 + DAT_006a5f30) * 0xbc));
  iVar13 = *(int *)(iVar20 + 0xc + DAT_0067ee20);
  fStack_c = ABS(*(float *)(DAT_006a5ee0 + 0x14 +
                           *(int *)(*(int *)(iVar10 + 8) * 0x10 + DAT_006a5f30) * 0xbc));
  if ((&DAT_00507f48)[iVar16] == 0) {
    iVar10 = 0;
    (&DAT_00507f48)[iVar16] = 1;
    iStack_68 = iVar13 * 0xa9 + 0x10;
    pfVar18 = (float *)(&DAT_00507f78 + iVar16 * 0x30);
    do {
      iVar11 = FUN_004906b0(iVar10);
      iVar17 = DAT_006a5c38 + iVar11 * 0xa9;
      *pfVar18 = *(float *)(iVar17 + 0x50);
      pfVar18[1] = *(float *)(iVar17 + 0x54);
      iVar11 = DAT_006a5c38;
      pfVar18[2] = *(float *)(iVar17 + 0x58);
      pfVar12 = (float *)FUN_004a25f0(auStack_48,pfVar18,iStack_68 + iVar11);
      *pfVar18 = *pfVar12;
      pfVar18[1] = pfVar12[1];
      pfVar18[2] = pfVar12[2];
      iVar17 = *(int *)(iVar20 + 0xc + DAT_0067ee20);
      iVar10 = iVar10 + 1;
      iVar11 = DAT_006a5c38 + iVar17 + 0x50 + iVar17 * 0xa8;
      *pfVar18 = *(float *)(DAT_006a5c38 + iVar17 + 0x50 + iVar17 * 0xa8) + *pfVar18;
      pfVar18[1] = *(float *)(iVar11 + 4) + pfVar18[1];
      pfVar18[2] = *(float *)(iVar11 + 8) + pfVar18[2];
      pfVar18 = pfVar18 + 3;
    } while (iVar10 < 4);
  }
  iStack_60 = 0;
  iStack_68 = iVar13 * 0xa9;
  puStack_50 = auStack_78;
  pfVar18 = &fStack_3c;
  pfStack_98 = (float *)(&DAT_00507f78 + iVar16 * 0x30);
  do {
    iVar16 = iStack_60;
    if (iStack_60 < 2) {
      fStack_64 = fStack_7c;
    }
    else {
      fStack_64 = fStack_c;
    }
    iVar13 = FUN_004906b0(iStack_60);
    iVar16 = FUN_004906b0(iVar16);
    iVar16 = iVar16 * 0xa9 + DAT_006a5c38;
    *pfVar18 = *(float *)(iVar16 + 0x50);
    pfVar18[1] = *(float *)(iVar16 + 0x54);
    pfVar18[2] = *(float *)(iVar16 + 0x58);
    pfVar12 = (float *)FUN_004a25f0(auStack_88,pfVar18,iStack_68 + 0x10 + DAT_006a5c38);
    *pfVar18 = *pfVar12;
    pfVar18[1] = pfVar12[1];
    pfVar18[2] = pfVar12[2];
    iVar10 = *(int *)(iVar20 + 0xc + DAT_0067ee20);
    iVar16 = DAT_006a5c38 + iVar10 + 0x50 + iVar10 * 0xa8;
    *pfVar18 = *(float *)(DAT_006a5c38 + iVar10 + 0x50 + iVar10 * 0xa8) + *pfVar18;
    pfVar18[1] = *(float *)(iVar16 + 4) + pfVar18[1];
    fVar1 = pfStack_98[1];
    pfVar18[2] = *(float *)(iVar16 + 8) + pfVar18[2];
    pfVar18[1] = fVar1;
    FUN_004977d0(*(undefined4 *)(iVar20 + 0x1c + DAT_0067ee20),*pfVar18,pfVar18[1],pfVar18[2]);
    FUN_00495fe0(*pfVar18,pfVar18[1],pfVar18[2],auStack_4,&uStack_58,&uStack_4c);
    fVar21 = (float10)FUN_00496290(*pfVar18,pfVar18[1],pfVar18[2],uStack_58,uStack_4c);
    iVar16 = DAT_0067ee20;
    fStack_54 = (float)fVar21;
    uVar14 = __ftol();
    iVar10 = (uVar14 & DAT_004fc8f8) * 4;
    fStack_40 = *(float *)(iVar10 + DAT_006a5cd0) * *(float *)(iVar20 + 0xa4 + iVar16) +
                *(float *)(iVar10 + DAT_006a5c88) * *(float *)(iVar20 + 0x9c + iVar16);
    *pfVar18 = (*(float *)(iVar10 + DAT_006a5cd0) * *(float *)(iVar20 + 0x9c + iVar16) -
               *(float *)(iVar10 + DAT_006a5c88) * *(float *)(iVar20 + 0xa4 + iVar16)) *
               _DAT_00507f70 * 10.0 + *pfVar18;
    pfVar18[2] = fStack_40 * _DAT_00507f70 * 10.0 + pfVar18[2];
    uVar15 = FUN_004977d0(*(undefined4 *)(iVar20 + 0x1c + iVar16),*pfVar18,pfVar18[1],pfVar18[2]);
    *puStack_50 = uVar15;
    FUN_00495fe0(*pfVar18,pfVar18[1],pfVar18[2],auStack_4,&uStack_58,&uStack_4c);
    fVar21 = (float10)FUN_00496290(*pfVar18,pfVar18[1],pfVar18[2],uStack_58,uStack_4c);
    fStack_5c = (float)fVar21;
    if (fStack_54 < pfVar18[1] - fStack_64) {
      fVar1 = _DAT_0053a4ac;
      if (param_1 == DAT_0053be28) {
        fVar1 = _DAT_0053a4a8;
      }
      pfVar12 = (float *)(DAT_006a5c38 + iVar13 * 0xa9 + 0x60);
      *pfVar12 = *pfVar12 - fVar1 * _DAT_00507f70;
    }
    iVar16 = DAT_006a5c38;
    iVar13 = iVar13 * 0xa9;
    fVar1 = _DAT_00507f70 * *(float *)(iVar13 + 0x60 + DAT_006a5c38) + pfVar18[1];
    if (fVar1 - fStack_64 <= fStack_5c) {
      *piStack_8 = *piStack_8 + 1;
      *(float *)(iVar13 + 0x60 + iVar16) = fStack_5c - fStack_54;
      *(float *)(iVar13 + 0x60 + DAT_006a5c38) =
           *(float *)(iVar13 + 0x60 + DAT_006a5c38) / _DAT_00507f70;
      if (0.0 <= *(float *)(iVar13 + 0x60 + DAT_006a5c38)) {
        fVar1 = *(float *)(iVar13 + 0x60 + DAT_006a5c38);
        if (fStack_5c < fStack_54 + 1.8) {
          fVar1 = fVar1 * 0.25;
        }
        else {
          if (10.0 < fVar1) {
            *(undefined4 *)(iVar13 + 0x60 + DAT_006a5c38) = 0x41200000;
          }
          fVar1 = *(float *)(iVar20 + 0xa4 + DAT_0067ee20) * 0.015 *
                  *(float *)(iVar13 + 0x60 + DAT_006a5c38);
        }
        *(float *)(iVar13 + 0x60 + DAT_006a5c38) = fVar1;
      }
      pfVar18[1] = fStack_5c + fStack_64;
    }
    else {
      pfVar18[1] = fVar1;
      if ((param_1 == DAT_0053be28) && (2 < iStack_60)) {
        DAT_004e0d14 = 0;
      }
    }
    iVar16 = DAT_006a5c38;
    *pfStack_98 = *pfVar18;
    pfStack_98[1] = pfVar18[1];
    pfStack_98[2] = pfVar18[2];
    iStack_60 = iStack_60 + 1;
    puStack_50 = puStack_50 + 1;
    pfVar18 = pfVar18 + 3;
    pfStack_98 = pfStack_98 + 3;
  } while (iStack_60 < 4);
  *(float *)(iVar16 + *(int *)(iVar20 + 0xc + DAT_0067ee20) * 0xa9 + 0x54) =
       fStack_14 + fStack_20 + fStack_2c + fStack_38;
  iVar16 = *(int *)(iVar20 + 0xc + DAT_0067ee20);
  *(float *)(DAT_006a5c38 + iVar16 + 0x54 + iVar16 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar16 + 0x54 + iVar16 * 0xa8) * 0.25;
  iVar16 = *(int *)(iVar20 + 0xc + DAT_0067ee20);
  *(float *)(DAT_006a5c38 + iVar16 + 0x54 + iVar16 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar16 + 0x54 + iVar16 * 0xa8) - fStack_7c;
  fVar1 = (fStack_30 - fStack_18) + (fStack_3c - fStack_24);
  fVar8 = (fStack_2c - fStack_14) + (fStack_38 - fStack_20);
  fVar9 = (fStack_28 - fStack_10) + (fStack_34 - fStack_1c);
  fVar7 = (fStack_18 - fStack_24) + (fStack_30 - fStack_3c);
  fVar6 = (fStack_14 - fStack_20) + (fStack_2c - fStack_38);
  fVar5 = (fStack_10 - fStack_1c) + (fStack_28 - fStack_34);
  fVar2 = SQRT(fVar1 * fVar1 + fVar8 * fVar8 + fVar9 * fVar9);
  fVar1 = fVar1 / fVar2;
  fVar8 = fVar8 / fVar2;
  fVar9 = fVar9 / fVar2;
  fVar2 = SQRT(fVar7 * fVar7 + fVar6 * fVar6 + fVar5 * fVar5);
  fVar7 = fVar7 / fVar2;
  fVar6 = fVar6 / fVar2;
  fVar5 = fVar5 / fVar2;
  fVar4 = fVar5 * fVar8 - fVar6 * fVar9;
  fVar3 = fVar9 * fVar7 - fVar5 * fVar1;
  fVar2 = fVar6 * fVar1 - fVar8 * fVar7;
  fVar3 = SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4);
  *(float *)(iStack_68 + 0x10 + DAT_006a5c38) = fVar7;
  *(float *)(iStack_68 + 0x14 + DAT_006a5c38) = fVar6;
  *(float *)(iStack_68 + 0x18 + DAT_006a5c38) = fVar5;
  *(float *)(iStack_68 + 0x20 + DAT_006a5c38) = fVar4 / fVar3;
  *(float *)(iStack_68 + 0x28 + DAT_006a5c38) = fVar2 / fVar3;
  *(float *)(iStack_68 + 0x30 + DAT_006a5c38) = fVar1;
  *(float *)(iStack_68 + 0x34 + DAT_006a5c38) = fVar8;
  *(float *)(iStack_68 + 0x38 + DAT_006a5c38) = fVar9;
  return 0;
}

