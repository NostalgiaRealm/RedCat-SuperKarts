/*
 * FUN_0043cbf0 at 0043cbf0
 * undefined FUN_0043cbf0(void)
 * Address ranges: 0043cbf0-0043cfd3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043cbf0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float10 fVar7;
  
  param_1 = param_1 * 0xd0;
  pfVar5 = (float *)FUN_00405f20(-*(float *)(param_1 + 0x9c + DAT_0067ee20),
                                 -*(float *)(param_1 + 0xa0 + DAT_0067ee20),
                                 -*(float *)(param_1 + 0xa4 + DAT_0067ee20));
  pfVar6 = (float *)FUN_00405f20(*pfVar5 * 0.8,pfVar5[1] * 0.8,pfVar5[2] * 0.8);
  fVar1 = *pfVar6;
  pfVar5 = (float *)(param_1 + 0x9c + DAT_0067ee20);
  fVar2 = pfVar6[2];
  fVar7 = (float10)FUN_0048f4e0();
  *pfVar5 = (float)(fVar7 * (float10)fVar1 + (float10)*pfVar5);
  pfVar5 = (float *)(param_1 + 0xa4 + DAT_0067ee20);
  fVar7 = (float10)FUN_0048f4e0();
  *pfVar5 = (float)(fVar7 * (float10)fVar2 + (float10)*pfVar5);
  iVar3 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  *(float *)(DAT_006a5c38 + iVar3 + 0x50 + iVar3 * 0xa8) =
       *(float *)(param_1 + 0x9c + DAT_0067ee20) +
       *(float *)(DAT_006a5c38 + iVar3 + 0x50 + iVar3 * 0xa8);
  iVar3 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  *(float *)(DAT_006a5c38 + iVar3 + 0x58 + iVar3 * 0xa8) =
       *(float *)(param_1 + 0xa4 + DAT_0067ee20) +
       *(float *)(DAT_006a5c38 + iVar3 + 0x58 + iVar3 * 0xa8);
  *(float *)(param_1 + 0xa8 + DAT_0067ee20) = *(float *)(param_1 + 0xa8 + DAT_0067ee20) * 1.15;
  *(float *)(param_1 + 0xb0 + DAT_0067ee20) = *(float *)(param_1 + 0xb0 + DAT_0067ee20) * 1.15;
  pfVar5 = (float *)(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x74);
  fVar7 = (float10)FUN_0048f4e0();
  *pfVar5 = (float)(fVar7 * (float10)*(float *)(param_1 + 0xb0 + DAT_0067ee20) * (float10)50.0 +
                   (float10)*pfVar5);
  pfVar5 = (float *)(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x7c);
  fVar7 = (float10)FUN_0048f4e0();
  *pfVar5 = (float)((float10)*pfVar5 -
                   fVar7 * (float10)*(float *)(param_1 + 0xa8 + DAT_0067ee20) * (float10)50.0);
  FUN_004a09e0();
  fVar1 = (float)param_2;
  iVar4 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  iVar3 = DAT_006a5c38 + iVar4 + iVar4 * 0xa8;
  if ((((*(float *)(DAT_006a5c38 + iVar4 + 0x74 + iVar4 * 0xa8) <= fVar1) &&
       (*(float *)(iVar3 + 0x7c) <= fVar1)) && ((float)-param_2 <= *(float *)(iVar3 + 0x74))) &&
     ((float)-param_2 <= *(float *)(iVar3 + 0x7c))) {
    return 0;
  }
  if (fVar1 < *(float *)(iVar3 + 0x74)) {
    *(float *)(iVar3 + 0x74) = fVar1;
    *(undefined4 *)(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x7c) = 0;
  }
  iVar3 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  fVar2 = (float)-param_2;
  if (*(float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8) < fVar2) {
    *(float *)(DAT_006a5c38 + iVar3 + 0x74 + iVar3 * 0xa8) = fVar2;
    *(undefined4 *)(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x7c) = 0;
  }
  iVar3 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  if (fVar1 < *(float *)(DAT_006a5c38 + iVar3 + 0x7c + iVar3 * 0xa8)) {
    *(undefined4 *)(DAT_006a5c38 + iVar3 + iVar3 * 0xa8 + 0x74) = 0;
    *(float *)(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x7c) = fVar1;
  }
  iVar3 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  if (*(float *)(DAT_006a5c38 + iVar3 + 0x7c + iVar3 * 0xa8) < fVar2) {
    *(undefined4 *)(DAT_006a5c38 + iVar3 + iVar3 * 0xa8 + 0x74) = 0;
    *(float *)(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x7c) = fVar2;
  }
  *(undefined4 *)(param_1 + 0x14 + DAT_0067ee20) = 2;
  return 1;
}

