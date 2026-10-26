/*
 * FUN_00444800 at 00444800
 * undefined FUN_00444800(void)
 * Address ranges: 00444800-00444b6e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00444800(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  uint3 uVar4;
  int iVar5;
  float10 fVar6;
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
  float fStack_8;
  float fStack_4;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar5 = *(int *)(param_1 + 4) + -2;
  if (*(int *)(param_1 + 8) < iVar5) {
    pfVar3 = (float *)FUN_00445120(&fStack_c,*(undefined4 *)(param_1 + 0x18),*(int *)(param_1 + 4),
                                   *(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                                   CONCAT31((int3)((uint)iVar5 >> 8),param_1[0x1d]));
    fStack_24 = *pfVar3;
    fStack_20 = pfVar3[1];
    fStack_1c = pfVar3[2];
    pfVar3 = (float *)FUN_00445120(&fStack_c,*(undefined4 *)(param_1 + 0x18),
                                   *(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) + 1,
                                   *(undefined4 *)(param_1 + 0xc),param_1[0x1d]);
    fStack_18 = *pfVar3;
    fStack_14 = pfVar3[1];
    fStack_10 = pfVar3[2];
  }
  iVar5 = iVar1 * 0xd0;
  *(int *)(iVar5 + 0x1c + DAT_0067ee20) = DAT_0053be40;
  if (*(int *)(param_1 + 8) < *(int *)(param_1 + 4) + -2) {
    fStack_3c = fStack_18 - fStack_24;
    fStack_38 = fStack_14 - fStack_20;
    iVar2 = *(int *)(iVar5 + 0xc + DAT_0067ee20);
    fStack_34 = fStack_10 - fStack_1c;
    fStack_c = fStack_3c;
    fStack_8 = fStack_38;
    fStack_4 = fStack_34;
    fVar6 = (float10)FUN_00405f40(&fStack_3c);
    fVar6 = SQRT(fVar6);
    pfVar3 = (float *)FUN_00405f20((float)((float10)fStack_3c / fVar6),
                                   (float)((float10)fStack_38 / fVar6),
                                   (float)((float10)fStack_34 / fVar6));
    fStack_3c = *pfVar3;
    fStack_38 = pfVar3[1];
    fStack_34 = pfVar3[2];
    fStack_28 = -fStack_3c;
    fStack_2c = 0.0;
    fStack_30 = fStack_34;
    fVar6 = (float10)FUN_00405f40(&fStack_30);
    fVar6 = SQRT(fVar6);
    pfVar3 = (float *)FUN_00405f20((float)((float10)fStack_30 / fVar6),
                                   (float)((float10)fStack_2c / fVar6),
                                   (float)((float10)fStack_28 / fVar6));
    fStack_30 = *pfVar3;
    fStack_2c = pfVar3[1];
    fStack_28 = pfVar3[2];
    fStack_c = fStack_38 * fStack_28 - fStack_2c * fStack_34;
    fStack_8 = fStack_30 * fStack_34 - fStack_28 * fStack_3c;
    iVar2 = iVar2 * 0xa9;
    fStack_4 = fStack_3c * fStack_2c - fStack_38 * fStack_30;
    FUN_004a2410(iVar2 + 0x10 + DAT_006a5c38,*pfVar3,pfVar3[1],pfVar3[2]);
    FUN_004a2430(iVar2 + 0x10 + DAT_006a5c38,fStack_c,fStack_8,fStack_4);
    FUN_004a2450(iVar2 + 0x10 + DAT_006a5c38,fStack_3c,fStack_38,fStack_34);
    *(float *)(iVar2 + 0x40 + DAT_006a5c38) = fStack_24;
    *(float *)(iVar2 + 0x44 + DAT_006a5c38) = fStack_20;
    *(float *)(iVar2 + 0x48 + DAT_006a5c38) = fStack_1c;
    iVar5 = DAT_006a5c38 + *(int *)(iVar5 + 0xc + DAT_0067ee20) * 0xa9;
    *(float *)(iVar5 + 0x50) = fStack_24;
    *(float *)(iVar5 + 0x54) = fStack_20;
    *(float *)(iVar5 + 0x58) = fStack_1c;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    iVar5 = FUN_004906b0(0);
    *(float *)(DAT_006a5c38 + iVar5 + 0x78 + iVar5 * 0xa8) =
         *(float *)(DAT_006a5c38 + iVar5 + 0x78 + iVar5 * 0xa8) + 512.0;
    iVar5 = FUN_004906b0(1);
    *(float *)(DAT_006a5c38 + iVar5 + 0x74 + iVar5 * 0xa8) =
         *(float *)(DAT_006a5c38 + iVar5 + 0x74 + iVar5 * 0xa8) + 512.0;
  }
  FUN_0043b790(iVar1,1);
  iVar5 = *(int *)(&DAT_0053f664 + *(int *)(param_1 + 0x18) * 0x340);
  uVar4 = (uint3)((uint)iVar5 >> 8);
  if ((iVar5 != 0) && (iVar5 == DAT_0053be40)) {
    *param_1 = 0;
    return CONCAT31(uVar4,1);
  }
  return (uint)uVar4 << 8;
}

