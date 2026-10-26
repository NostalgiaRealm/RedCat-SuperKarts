/*
 * FUN_0043b900 at 0043b900
 * undefined FUN_0043b900(void)
 * Address ranges: 0043b900-0043bb5c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043b900(int param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float10 fVar5;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = 0;
  uStack_8 = 0x3f800000;
  uStack_4 = 0;
  iVar1 = DAT_00680ba0 + 8 + (&DAT_00508620)[DAT_00508670] * 0x178;
  param_1 = param_1 * 0xd0;
  iVar2 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  iVar4 = DAT_006a5c38 + iVar2;
  fStack_30 = *(float *)(iVar4 + 0x50 + iVar2 * 0xa8) -
              *(float *)(DAT_00680ba0 + 8 + (&DAT_00508620)[DAT_00508670] * 0x178);
  fStack_2c = *(float *)(iVar4 + 0x54 + iVar2 * 0xa8) - *(float *)(iVar1 + 4);
  fStack_28 = *(float *)(iVar4 + iVar2 * 0xa8 + 0x58) - *(float *)(iVar1 + 8);
  if (((fStack_30 != 0.0) || (fStack_2c != 0.0)) || (fStack_28 != 0.0)) {
    fStack_24 = fStack_30;
    fStack_20 = fStack_2c;
    fStack_1c = fStack_28;
    fVar5 = (float10)FUN_00405f40(&fStack_30);
    fVar5 = SQRT(fVar5);
    pfVar3 = (float *)FUN_00405f20((float)((float10)fStack_30 / fVar5),
                                   (float)((float10)fStack_2c / fVar5),
                                   (float)((float10)fStack_28 / fVar5));
    fStack_20 = 0.0;
    uStack_14 = 0;
    fStack_24 = pfVar3[2] - 0.0;
    fStack_2c = 0.0;
    fStack_1c = 0.0 - *pfVar3;
    fStack_30 = 0.0 - fStack_1c;
    fStack_28 = fStack_24 - 0.0;
    fStack_18 = fStack_30;
    fStack_10 = fStack_28;
    FUN_004a2410(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x10,fStack_24,0,
                 fStack_1c);
    FUN_004a2430(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x10,uStack_c,
                 uStack_8,uStack_4);
    FUN_004a2450(DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9 + 0x10,fStack_30,
                 fStack_2c,fStack_28);
  }
  return 1;
}

