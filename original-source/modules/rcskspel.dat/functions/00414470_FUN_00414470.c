/*
 * FUN_00414470 at 00414470
 * undefined FUN_00414470(void)
 * Address ranges: 00414470-00414747
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414470(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  undefined1 local_8 [4];
  float local_4;
  
  iVar7 = (int)param_1 * 0x11c;
  fVar2 = *(float *)(&DAT_00503f30 + iVar7);
  fVar3 = *(float *)(&DAT_00503f2c + iVar7);
  iVar6 = (&DAT_00503ef0)[(int)param_1 * 0x47];
  iVar5 = *(int *)(&DAT_00503f24 + iVar7);
  fVar8 = (float10)FUN_0048f4e0();
  fVar1 = (float)fVar8;
  if (fVar3 == 0.0) {
    iVar4 = iVar6 * 0xd0;
    if (0.0 <= *(float *)(iVar4 + 0xa4 + DAT_0067ee20)) {
      *(float *)(iVar4 + 0xa4 + DAT_0067ee20) =
           *(float *)(iVar4 + 0xa4 + DAT_0067ee20) -
           fVar1 * *(float *)(&DAT_00506940 + iVar5 * 0x7c);
      if (0.0 <= *(float *)(iVar4 + 0xa4 + DAT_0067ee20)) goto LAB_0041456c;
    }
    else {
      *(float *)(iVar4 + 0xa4 + DAT_0067ee20) =
           fVar1 * *(float *)(&DAT_00506940 + iVar5 * 0x7c) +
           *(float *)(iVar4 + 0xa4 + DAT_0067ee20);
      if (*(float *)(iVar4 + 0xa4 + DAT_0067ee20) <= 0.0) goto LAB_0041456c;
    }
    *(undefined4 *)(iVar4 + 0xa4 + DAT_0067ee20) = 0;
  }
LAB_0041456c:
  if (0.0 < fVar3) {
    *(undefined4 *)(&DAT_00503f4c + iVar7) = 0;
  }
  iVar6 = iVar6 * 0xd0;
  local_4 = *(float *)(iVar6 + 0xa4 + DAT_0067ee20);
  fVar8 = (float10)FUN_00412f50(param_1,local_8);
  iVar4 = 0;
  *(undefined4 *)(&DAT_00503f38 + iVar7) = 0xffffffff;
  do {
    if (*(float *)(iVar6 + 0xa4 + DAT_0067ee20) <
        (float)(&DAT_00506918)[iVar4 + iVar5 * 0x1f] * *(float *)(&DAT_00506930 + iVar5 * 0x7c)) {
      *(int *)(&DAT_00503f38 + iVar7) = iVar4;
      fVar8 = (float10)FUN_00412f50(param_1,local_8);
      iVar4 = 6;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  if (*(int *)(&DAT_00503f38 + iVar7) == -1) {
    *(undefined4 *)(&DAT_00503f38 + iVar7) = 6;
  }
  fVar9 = (float10)*(float *)(&DAT_0050693c + DAT_0053be2c * 0x7c);
  if ((float10)0.0 < fVar9) {
    fVar9 = -fVar9;
  }
  if (*(int *)(&DAT_00503f34 + iVar7) != 0) {
    fVar8 = (float10)0.0;
    fVar9 = (float10)0.0;
  }
  *(float *)(iVar6 + 0xa4 + DAT_0067ee20) =
       (float)((fVar8 * (float10)fVar3 + fVar9 * (float10)fVar2) * (float10)fVar1 + (float10)local_4
              );
  if (0.0 < fVar2) {
    iVar5 = DAT_0067ee20;
    if ((ABS(*(float *)(iVar6 + 0xa4 + DAT_0067ee20)) < 0.4) &&
       (*(int *)(&DAT_00503f4c + iVar7) == 0)) {
      *(undefined4 *)(iVar6 + 0xa4 + DAT_0067ee20) = 0;
      iVar5 = DAT_0067ee20;
      *(undefined4 *)(&DAT_00503f4c + iVar7) = 1;
    }
    param_1 = fVar2 * *(float *)(iVar6 + 0xa4 + iVar5);
    if (1000.0 < param_1) {
      param_1 = 1000.0;
    }
    fVar8 = (float10)FUN_0048f4e0();
    *(float *)(iVar6 + iVar5 + 0xa8) =
         (float)((float10)*(float *)(iVar6 + iVar5 + 0xa8) - fVar8 * (float10)param_1);
  }
  if (*(float *)(iVar6 + 0xa4 + DAT_0067ee20) < -13.333) {
    *(undefined4 *)(iVar6 + 0xa4 + DAT_0067ee20) = 0xc15553f8;
  }
  return;
}

