/*
 * FUN_00448f80 at 00448f80
 * undefined FUN_00448f80(void)
 * Address ranges: 00448f80-00449214
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00448f80(undefined1 *param_1)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  uint3 uVar4;
  int iVar5;
  float10 fVar6;
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
  
  iVar5 = *(int *)(param_1 + 0x10);
  FUN_0043b790(iVar5,1);
  iVar1 = *(int *)(param_1 + 4) + -2;
  if (*(int *)(param_1 + 8) < iVar1) {
    pfVar2 = (float *)FUN_00445120(&fStack_c,*(undefined4 *)(param_1 + 0x18),*(int *)(param_1 + 4),
                                   *(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                                   CONCAT31((int3)((uint)iVar1 >> 8),param_1[0x1d]));
    fStack_24 = *pfVar2;
    fStack_20 = pfVar2[1];
    fStack_1c = pfVar2[2];
    pfVar2 = (float *)FUN_00445120(&fStack_c,*(undefined4 *)(param_1 + 0x18),
                                   *(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) + 1,
                                   *(undefined4 *)(param_1 + 0xc),param_1[0x1d]);
    fStack_18 = *pfVar2;
    fStack_14 = pfVar2[1];
    fStack_10 = pfVar2[2];
  }
  iVar1 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 8) = iVar1 + 1;
  if (iVar1 + 1 < *(int *)(param_1 + 4) + -2) {
    fStack_30 = fStack_18 - fStack_24;
    fStack_2c = fStack_14 - fStack_20;
    iVar5 = iVar5 * 0xd0;
    fStack_28 = fStack_10 - fStack_1c;
    iVar1 = *(int *)(iVar5 + 0xc + DAT_0067ee20);
    fStack_c = fStack_30;
    fStack_8 = fStack_2c;
    fStack_4 = fStack_28;
    fVar6 = (float10)FUN_00405f40(&fStack_30);
    fVar6 = SQRT(fVar6);
    pfVar2 = (float *)FUN_00405f20((float)((float10)fStack_30 / fVar6),
                                   (float)((float10)fStack_2c / fVar6),
                                   (float)((float10)fStack_28 / fVar6));
    fStack_30 = *pfVar2;
    fStack_14 = 0.0;
    fStack_2c = pfVar2[1];
    fStack_10 = -fStack_30;
    fStack_28 = pfVar2[2];
    fStack_c = fStack_2c * fStack_10;
    fStack_8 = fStack_28 * fStack_28 - fStack_10 * fStack_30;
    iVar1 = iVar1 * 0xa9;
    fStack_4 = -(fStack_2c * fStack_28);
    fStack_18 = fStack_28;
    FUN_004a2410(iVar1 + 0x10 + DAT_006a5c38,fStack_28,0,fStack_10);
    FUN_004a2430(iVar1 + 0x10 + DAT_006a5c38,fStack_c,fStack_8,fStack_4);
    FUN_004a2450(iVar1 + 0x10 + DAT_006a5c38,fStack_30,fStack_2c,fStack_28);
    *(float *)(iVar1 + 0x40 + DAT_006a5c38) = fStack_24;
    *(float *)(iVar1 + 0x44 + DAT_006a5c38) = fStack_20;
    *(float *)(iVar1 + 0x48 + DAT_006a5c38) = fStack_1c;
    iVar5 = iVar5 + DAT_0067ee20;
    uVar3 = FUN_004977d0(DAT_0053be40,fStack_24,fStack_20,fStack_1c);
    *(undefined4 *)(iVar5 + 0x1c) = uVar3;
  }
  iVar1 = *(int *)(&DAT_0053f664 + *(int *)(param_1 + 0x18) * 0x340);
  uVar4 = (uint3)((uint)iVar1 >> 8);
  if ((iVar1 != 0) && (iVar1 == DAT_0053be40)) {
    *param_1 = 0;
    return CONCAT31(uVar4,1);
  }
  return (uint)uVar4 << 8;
}

