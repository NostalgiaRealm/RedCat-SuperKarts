/*
 * FUN_0043c870 at 0043c870
 * undefined FUN_0043c870(void)
 * Address ranges: 0043c870-0043cbea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043c870(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  float10 fVar9;
  
  uVar7 = 0;
  iVar8 = param_1 * 0xd0;
  pfVar4 = (float *)FUN_00405f20(-*(float *)(iVar8 + 0x9c + DAT_0067ee20),
                                 -*(float *)(iVar8 + 0xa0 + DAT_0067ee20),
                                 -*(float *)(iVar8 + 0xa4 + DAT_0067ee20));
  pfVar5 = (float *)FUN_00405f20(*pfVar4 * 0.6,pfVar4[1] * 0.6,pfVar4[2] * 0.6);
  fVar1 = *pfVar5;
  pfVar4 = (float *)(iVar8 + 0x9c + DAT_0067ee20);
  fVar2 = pfVar5[2];
  fVar9 = (float10)FUN_0048f4e0();
  *pfVar4 = (float)(fVar9 * (float10)fVar1 + (float10)*pfVar4);
  pfVar4 = (float *)(iVar8 + 0xa4 + DAT_0067ee20);
  fVar9 = (float10)FUN_0048f4e0();
  *pfVar4 = (float)(fVar9 * (float10)fVar2 + (float10)*pfVar4);
  pfVar4 = (float *)(iVar8 + 0xa0 + DAT_0067ee20);
  fVar9 = (float10)FUN_0048f4e0();
  *pfVar4 = (float)(fVar9 * (float10)*(float *)(iVar8 + 0x40 + DAT_0067ee20) + (float10)*pfVar4);
  iVar6 = iVar8 + DAT_0067ee20;
  iVar3 = *(int *)(iVar8 + 0xc + DAT_0067ee20);
  pfVar4 = (float *)(DAT_006a5c38 + iVar3 + 0x50 + iVar3 * 0xa8);
  *pfVar4 = *(float *)(iVar6 + 0x9c) + *(float *)(DAT_006a5c38 + iVar3 + 0x50 + iVar3 * 0xa8);
  pfVar4[1] = *(float *)(iVar6 + 0xa0) + pfVar4[1];
  pfVar4[2] = *(float *)(iVar6 + 0xa4) + pfVar4[2];
  FUN_004932e0(param_1);
  iVar6 = *(int *)(iVar8 + 0xc + DAT_0067ee20);
  fVar9 = (float10)FUN_00494b70(*(undefined4 *)(DAT_006a5c38 + iVar6 + iVar6 * 0xa8 + 0x50),
                                *(undefined4 *)(DAT_006a5c38 + iVar6 + 0x58 + iVar6 * 0xa8));
  iVar6 = FUN_00490ce0();
  fVar2 = *(float *)(DAT_006a5c38 + *(int *)(iVar8 + 0xc + DAT_0067ee20) * 0xa9 + 0x54) -
          (float)fVar9;
  fVar1 = *(float *)(DAT_006a5ee0 + 0x74 + iVar6 * 0xbc);
  if (fVar2 * fVar2 < fVar1 * fVar1) {
    *(float *)(iVar8 + 0xa0 + DAT_0067ee20) = *(float *)(iVar8 + 0xa0 + DAT_0067ee20) * -0.7;
    *(float *)(iVar8 + 0xa8 + DAT_0067ee20) = *(float *)(iVar8 + 0xa8 + DAT_0067ee20) * -1.0;
    *(float *)(iVar8 + 0xb0 + DAT_0067ee20) = *(float *)(iVar8 + 0xb0 + DAT_0067ee20) * -1.0;
    fVar1 = (float)fVar9 + param_3;
    *(float *)(DAT_006a5c38 + *(int *)(iVar8 + 0xc + DAT_0067ee20) * 0xa9 + 0x54) = fVar1;
    if (*(float *)(iVar8 + 0xa0 + DAT_0067ee20) < param_3) {
      *(float *)(DAT_006a5c38 + *(int *)(iVar8 + 0xc + DAT_0067ee20) * 0xa9 + 0x54) = fVar1;
      *(undefined4 *)(iVar8 + 0x14 + DAT_0067ee20) = 3;
    }
    uVar7 = 1;
  }
  pfVar4 = (float *)(DAT_006a5c38 + *(int *)(iVar8 + 0xc + DAT_0067ee20) * 0xa9 + 0x74);
  fVar9 = (float10)FUN_0048f4e0();
  *pfVar4 = (float)(fVar9 * (float10)*(float *)(iVar8 + 0xb0 + DAT_0067ee20) * (float10)80.0 +
                   (float10)*pfVar4);
  pfVar4 = (float *)(DAT_006a5c38 + *(int *)(iVar8 + 0xc + DAT_0067ee20) * 0xa9 + 0x7c);
  fVar9 = (float10)FUN_0048f4e0();
  *pfVar4 = (float)((float10)*pfVar4 -
                   fVar9 * (float10)*(float *)(iVar8 + 0xa8 + DAT_0067ee20) * (float10)80.0);
  FUN_004a09e0();
  return uVar7;
}

