/*
 * FUN_00414750 at 00414750
 * undefined FUN_00414750(void)
 * Address ranges: 00414750-00414e52
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00414750(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  float10 fVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float local_10;
  float local_c;
  
  fVar11 = (float10)FUN_0048f4e0();
  fVar1 = (float)fVar11;
  iVar9 = param_1 * 0x11c;
  *(float *)(&DAT_00503f28 + iVar9) = *(float *)(&DAT_00503f28 + iVar9) * -1.0;
  iVar8 = (&DAT_00503ef0)[param_1 * 0x47];
  iVar4 = *(int *)(&DAT_00503f24 + iVar9);
  if (*(int *)(&DAT_00503f34 + iVar9) == 0) {
    pfVar7 = (float *)(iVar8 * 0xd0 + 0xac + DAT_0067ee20);
    local_c = *(float *)(iVar8 * 0xd0 + 0xac + DAT_0067ee20) * 10.0;
    *pfVar7 = *pfVar7 - local_c * fVar1;
    iVar5 = DAT_0053bef4;
    if (*(int *)(&DAT_00503f34 + iVar9) == 0) {
      *(undefined4 *)(&DAT_00503f40 + iVar9) = 0;
      *(undefined4 *)(&DAT_00503f44 + iVar9) = 0;
      *(undefined4 *)(&DAT_00503f3c + iVar9) = 0;
      if (iVar5 == 0) {
        local_c = *(float *)(iVar8 * 0xd0 + 0x9c + DAT_0067ee20) * 5.0;
      }
      else {
        local_c = *(float *)(iVar8 * 0xd0 + 0x9c + DAT_0067ee20) * 10.0;
      }
      pfVar7 = (float *)(iVar8 * 0xd0 + 0x9c + DAT_0067ee20);
      *pfVar7 = *pfVar7 - local_c * fVar1;
    }
  }
  iVar5 = DAT_0067ee20;
  iVar8 = iVar8 * 0xd0;
  fVar3 = ABS(*(float *)(iVar8 + 0xa4 + DAT_0067ee20));
  if ((2.0 <= fVar3) || (2.0 <= ABS(*(float *)(iVar8 + 0x9c + DAT_0067ee20)))) {
    fVar11 = (float10)(float)(&DAT_00506948)[iVar4 * 0x1f];
    if ((&DAT_00503ff8)[iVar9] != '\0') {
      if (*(float *)(&DAT_00503ffc + iVar9) <= 0.05) {
        fVar11 = fVar11 * (float10)10.0;
      }
      else {
        fVar11 = fVar11 * (float10)15.0;
      }
    }
  }
  else {
    fVar11 = (float10)fsin(ABS((float10)3.1415927 * (float10)*(float *)(iVar8 + 0xa4 + DAT_0067ee20)
                               * (float10)0.25));
    fVar11 = fVar11 * (float10)(float)(&DAT_00506948)[iVar4 * 0x1f];
  }
  fVar12 = (float10)*(float *)(&DAT_00503f28 + iVar9) * (float10)0.5 * (float10)6.2831855 *
           (float10)0.0027777778;
  if (fVar12 <= (float10)6.2831855) {
    if (fVar12 < (float10)0.0) {
      fVar12 = fVar12 + (float10)6.2831855;
    }
  }
  else {
    fVar12 = fVar12 - (float10)6.2831855;
  }
  fVar12 = (float10)fsin(fVar12);
  fVar2 = (float)((float10)_DAT_004e0258 * (float10)*(float *)(&DAT_00503f28 + iVar9) * fVar11 *
                  (float10)fVar1 +
                 (float10)*(float *)(iVar8 + 0xa4 + DAT_0067ee20) * (float10)50.0 *
                 fVar12 * (float10)_DAT_004e0258 * (float10)fVar1);
  uVar6 = __ftol();
  local_10 = (float)(uVar6 & 0x80000fff);
  bVar10 = false;
  if ((int)local_10 < 0) {
    local_10 = (float)(((int)local_10 - 1U | 0xfffff000) + 1);
    bVar10 = (int)local_10 < 0;
  }
  if (bVar10) {
    local_10 = (float)((int)local_10 + 0x1000);
  }
  if ((*(int *)(&DAT_00503f34 + iVar9) == 0) && (*(float *)(&DAT_00503f3c + iVar9) == 0.0)) {
    local_10 = 10.0 - fVar3 * 0.15;
    if (local_10 < 2.5) {
      local_10 = 2.5;
    }
    if ((extraout_ST0 <= (float10)0.0) || ((float10)6.2831855 <= extraout_ST0)) {
      pfVar7 = (float *)(iVar8 + 0xac + iVar5);
      if (0.0 <= *(float *)(iVar8 + 0xa4 + iVar5)) {
        fVar3 = *pfVar7 - local_10 * fVar2;
      }
      else {
        fVar3 = *(float *)(&DAT_00503f28 + iVar9) * 0.004 + *pfVar7;
      }
      *pfVar7 = fVar3;
      pfVar7 = (float *)(DAT_006a5c38 + *(int *)(iVar8 + 0xc + DAT_0067ee20) * 0xa9 + 0x7c);
      fVar11 = (float10)FUN_0048f4e0();
      *pfVar7 = (float)(fVar11 * (float10)*(float *)(&DAT_00506944 + DAT_0053be2c * 0x7c) *
                        (float10)*(float *)(&DAT_00503f28 + iVar9) + (float10)*pfVar7);
      *(float *)(iVar8 + 0xa4 + DAT_0067ee20) =
           *(float *)(iVar8 + 0xa4 + DAT_0067ee20) - local_c * fVar1 * 0.5;
    }
    else if ((10.0 <= *(float *)(iVar8 + 0xa4 + iVar5)) || (DAT_0050728c == 0)) {
      pfVar7 = (float *)(iVar8 + 0xac + iVar5);
      if (0.0 <= *(float *)(iVar8 + 0xa4 + iVar5)) {
        fVar3 = *pfVar7 - local_10 * fVar2;
      }
      else {
        fVar3 = local_10 * fVar2 + *pfVar7;
      }
      *pfVar7 = fVar3;
      pfVar7 = (float *)(DAT_006a5c38 + *(int *)(iVar8 + 0xc + DAT_0067ee20) * 0xa9 + 0x7c);
      fVar11 = (float10)FUN_0048f4e0();
      *pfVar7 = (float)((float10)*pfVar7 -
                       fVar11 * (float10)*(float *)(&DAT_00506944 + DAT_0053be2c * 0x7c) *
                       (float10)*(float *)(&DAT_00503f28 + iVar9));
    }
    else {
      pfVar7 = (float *)(iVar8 + 0xac + iVar5);
      if (0.0 <= *(float *)(iVar8 + 0xa4 + iVar5)) {
        fVar3 = *pfVar7 - local_10 * fVar2;
      }
      else {
        fVar3 = local_10 * fVar2 + *pfVar7;
      }
      *pfVar7 = fVar3;
      pfVar7 = (float *)(DAT_006a5c38 + *(int *)(iVar8 + 0xc + DAT_0067ee20) * 0xa9 + 0x7c);
      fVar11 = (float10)FUN_0048f4e0();
      *pfVar7 = (float)(fVar11 * (float10)*(float *)(&DAT_00506944 + DAT_0053be2c * 0x7c) *
                        (float10)*(float *)(&DAT_00503f28 + iVar9) + (float10)*pfVar7);
    }
    fVar11 = (float10)*(float *)(iVar8 + 0xac + DAT_0067ee20) * (float10)fVar1;
    pfVar7 = (float *)(iVar8 + 0x9c + DAT_0067ee20);
    fVar12 = (float10)fcos(fVar11);
    fVar11 = (float10)fsin(fVar11);
    fVar11 = fVar12 * (float10)*pfVar7 - fVar11 * (float10)*(float *)(iVar8 + 0xa4 + DAT_0067ee20);
    if (DAT_0053bef4 == 0) {
      *pfVar7 = (float)(fVar11 * (float10)0.8);
    }
    else {
      *pfVar7 = (float)fVar11;
    }
  }
  else {
    if (*(float *)(&DAT_00503f44 + iVar9) == 0.0) {
      *(float *)(&DAT_00503f44 + iVar9) = (float)(int)local_10 * 0.00024414062 * 6.2831855;
    }
    fVar3 = *(float *)(&DAT_00503f3c + iVar9);
    *(float *)(&DAT_00503f3c + iVar9) = fVar1 + fVar3;
    if (1.0 < fVar1 + fVar3) {
      *(undefined4 *)(&DAT_00503f3c + iVar9) = 0x3f800000;
    }
    fVar11 = (float10)*(float *)(iVar8 + 0xa4 + iVar5);
    fVar12 = (float10)*(float *)(iVar8 + 0x9c + iVar5);
    fVar11 = SQRT(fVar12 * fVar12 + fVar11 * fVar11);
    if (fVar11 <= (float10)1.0) {
      *(undefined4 *)(iVar8 + 0x9c + iVar5) = 0;
      *(undefined4 *)(iVar8 + 0xa4 + DAT_0067ee20) = 0;
      *(undefined4 *)(iVar8 + 0xac + DAT_0067ee20) = 0;
    }
    else {
      fVar11 = (float10)fsin(fVar11 * (float10)3.1415927 * (float10)0.004);
      if (param_1 < DAT_00508610) {
        fVar12 = (float10)0.5;
      }
      else {
        fVar12 = (float10)1.25;
      }
      fVar12 = (float10)*(float *)(&DAT_00503f3c + iVar9) *
               (float10)*(float *)(&DAT_00503f28 + iVar9) * (float10)0.17999999 * fVar11 * fVar12;
      fVar3 = (float)fVar12;
      if ((0.0 <= *(float *)(iVar8 + 0xa4 + iVar5)) || (DAT_00507294 == '\0')) {
        fVar12 = -fVar12;
      }
      *(float *)(iVar8 + 0xac + iVar5) = (float)fVar12;
      fVar11 = (float10)FUN_0048f4e0();
      iVar4 = DAT_00508610;
      *(float *)(&DAT_00503f40 + iVar9) =
           (float)(fVar11 * (float10)fVar3 + (float10)*(float *)(&DAT_00503f40 + iVar9));
      if (param_1 < iVar4) {
        fVar3 = *(float *)(iVar8 + 0x9c + DAT_0067ee20);
        if (*(float *)(&DAT_00503f28 + iVar9) == 0.0) {
          *(float *)(iVar8 + 0x9c + DAT_0067ee20) = fVar3 - (fVar3 + fVar3) * fVar1;
          fVar3 = *(float *)(iVar8 + 0xa4 + DAT_0067ee20);
          *(float *)(iVar8 + 0xa4 + DAT_0067ee20) = fVar3 - (fVar3 + fVar3) * fVar1;
        }
        else {
          *(float *)(iVar8 + 0x9c + DAT_0067ee20) = fVar3 - fVar3 * fVar1;
          fVar3 = *(float *)(iVar8 + 0xa4 + DAT_0067ee20);
          *(float *)(iVar8 + 0xa4 + DAT_0067ee20) = fVar3 - fVar3 * fVar1;
        }
      }
      else {
        fVar3 = *(float *)(iVar8 + 0x9c + DAT_0067ee20);
        *(float *)(iVar8 + 0x9c + DAT_0067ee20) = fVar3 - fVar3 * 3.0 * fVar1;
        fVar3 = *(float *)(iVar8 + 0xa4 + DAT_0067ee20);
        *(float *)(iVar8 + 0xa4 + DAT_0067ee20) = fVar3 - fVar3 * 3.0 * fVar1;
      }
    }
  }
  *(float *)(&DAT_00503f28 + iVar9) = *(float *)(&DAT_00503f28 + iVar9) * -1.0;
  return;
}

