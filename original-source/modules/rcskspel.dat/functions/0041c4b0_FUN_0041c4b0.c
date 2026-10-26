/*
 * FUN_0041c4b0 at 0041c4b0
 * undefined FUN_0041c4b0(void)
 * Address ranges: 0041c4b0-0041c8cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041c4b0(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  
  iVar5 = (int)param_1 * 0xd0;
  iVar4 = FUN_004906b0(0);
  iVar4 = *(int *)(*(int *)(DAT_006a5c38 + iVar4 * 0xa9 + 4) * 9 + 4 + DAT_006a5f78);
  fVar3 = ABS(*(float *)(DAT_006a5ee0 + 0x14 +
                        *(int *)(*(int *)(iVar4 + 4) * 0x10 + DAT_006a5f30) * 0xbc));
  fVar1 = *(float *)(DAT_006a5ee0 + 0x14 +
                    *(int *)(*(int *)(iVar4 + 8) * 0x10 + DAT_006a5f30) * 0xbc);
  iVar4 = iVar5 + DAT_0067ee20;
  fVar6 = (float10)FUN_0048f4e0();
  fVar7 = (float10)fVar3;
  fVar2 = (float)(((float10)_DAT_004fc8f4 / (fVar7 + fVar7)) * fVar6 *
                 (float10)*(float *)(iVar4 + 0xa4));
  iVar4 = FUN_004906b0(0);
  *(float *)(DAT_006a5c38 + iVar4 + 0x74 + iVar4 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar4 + 0x74 + iVar4 * 0xa8) - fVar2;
  iVar4 = FUN_004906b0(1);
  *(float *)(DAT_006a5c38 + iVar4 + 0x74 + iVar4 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar4 + 0x74 + iVar4 * 0xa8) - fVar2;
  iVar4 = FUN_004906b0(2);
  *(float *)(DAT_006a5c38 + iVar4 + 0x74 + iVar4 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar4 + 0x74 + iVar4 * 0xa8) - fVar2;
  iVar4 = FUN_004906b0(3);
  *(float *)(DAT_006a5c38 + iVar4 + 0x74 + iVar4 * 0xa8) =
       *(float *)(DAT_006a5c38 + iVar4 + 0x74 + iVar4 * 0xa8) - fVar2;
  param_1 = *(float *)(iVar5 + 0xac + DAT_0067ee20) * 400.0;
  if (param_1 <= 500.0) {
    if (param_1 < -500.0) {
      param_1 = -500.0;
    }
  }
  else {
    param_1 = 500.0;
  }
  iVar4 = FUN_004906b0(0);
  *(float *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x78) = param_1;
  iVar4 = FUN_004906b0(1);
  *(float *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x78) = param_1;
  iVar4 = *(int *)(iVar5 + 0xc + DAT_0067ee20);
  fVar6 = (float10)FUN_00494b70(*(undefined4 *)(DAT_006a5c38 + iVar4 + iVar4 * 0xa8 + 0x50),
                                *(undefined4 *)(DAT_006a5c38 + iVar4 + 0x58 + iVar4 * 0xa8));
  fVar6 = fVar6 - (float10)*(float *)(DAT_006a5c38 + *(int *)(iVar5 + 0xc + DAT_0067ee20) * 0xa9 +
                                     0x54);
  param_1 = (float)fVar6;
  if (fVar6 <= (float10)0.0) {
    if (param_1 < -1.11) {
      param_1 = -1.11;
    }
  }
  else {
    param_1 = 0.0;
  }
  iVar4 = FUN_004906b0(0);
  fVar3 = param_1 + fVar3;
  *(float *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x54) = fVar3;
  iVar4 = FUN_004906b0(1);
  *(float *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x54) = fVar3;
  iVar4 = FUN_004906b0(2);
  param_1 = param_1 + ABS(fVar1);
  *(float *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x54) = param_1;
  iVar4 = FUN_004906b0(3);
  *(float *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x54) = param_1;
  FUN_004906b0(0);
  FUN_004a09e0();
  FUN_004906b0(1);
  FUN_004a09e0();
  FUN_004906b0(2);
  FUN_004a09e0();
  FUN_004906b0(3);
  FUN_004a09e0();
  return;
}

