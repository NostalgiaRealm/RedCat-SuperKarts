/*
 * FUN_00448cc0 at 00448cc0
 * undefined FUN_00448cc0(void)
 * Address ranges: 00448cc0-00448e4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00448cc0(undefined1 *param_1)

{
  float *pfVar1;
  uint3 uVar2;
  int iVar3;
  float10 fVar4;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined1 auStack_c [12];
  
  iVar3 = *(int *)(param_1 + 0x10);
  FUN_0043b790(iVar3,1);
  if (*(int *)(param_1 + 8) < *(int *)(param_1 + 4) + -2) {
    pfVar1 = (float *)FUN_00445120(&fStack_18,*(undefined4 *)(param_1 + 0x18),*(int *)(param_1 + 4),
                                   *(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                                   param_1[0x1d]);
    fStack_24 = *pfVar1;
    fStack_20 = pfVar1[1];
    fStack_1c = pfVar1[2];
    pfVar1 = (float *)FUN_00445120(auStack_c,*(undefined4 *)(param_1 + 0x18),
                                   *(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) + 1,
                                   *(undefined4 *)(param_1 + 0xc),param_1[0x1d]);
    fStack_18 = *pfVar1;
    fStack_14 = pfVar1[1];
    fStack_10 = pfVar1[2];
  }
  iVar3 = iVar3 * 0xd0;
  *(int *)(iVar3 + 0x1c + DAT_0067ee20) = DAT_0053be40;
  if (*(int *)(param_1 + 8) < *(int *)(param_1 + 4) + -2) {
    fVar4 = (float10)fpatan((float10)fStack_10 - (float10)fStack_1c,
                            (float10)fStack_18 - (float10)fStack_24);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(float *)(DAT_006a5c38 + *(int *)(iVar3 + 0xc + DAT_0067ee20) * 0xa9 + 0x78) =
         (float)(((fVar4 - (float10)3.1415927 * (float10)0.5) * (float10)_DAT_004fc8f4) /
                (float10)6.2831855);
    iVar3 = DAT_006a5c38 + *(int *)(iVar3 + 0xc + DAT_0067ee20) * 0xa9;
    *(float *)(iVar3 + 0x50) = fStack_24;
    *(float *)(iVar3 + 0x54) = fStack_20;
    *(float *)(iVar3 + 0x58) = fStack_1c;
    FUN_004a09e0();
  }
  iVar3 = *(int *)(&DAT_0053f664 + *(int *)(param_1 + 0x18) * 0x340);
  uVar2 = (uint3)((uint)iVar3 >> 8);
  if ((iVar3 != 0) && (iVar3 == DAT_0053be40)) {
    *param_1 = 0;
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}

