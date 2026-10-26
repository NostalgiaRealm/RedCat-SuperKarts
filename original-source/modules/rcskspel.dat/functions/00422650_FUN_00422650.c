/*
 * FUN_00422650 at 00422650
 * undefined FUN_00422650(void)
 * Address ranges: 00422650-004227d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00422650(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = param_1 * 0xa9;
  iVar9 = *(int *)(iVar6 + 0xc + DAT_006a5c38) * 0x44;
  iVar8 = *(int *)(iVar9 + 0x24 + DAT_005090d0);
  pfVar1 = (float *)(iVar9 + DAT_005090d0);
  fVar2 = *pfVar1;
  fVar3 = pfVar1[2];
  iVar7 = __ftol();
  pfVar1[7] = (float)iVar7 + pfVar1[7];
  iVar7 = __ftol();
  fVar4 = (float)iVar8;
  *(float *)(iVar6 + 0x50 + DAT_006a5c38) =
       *(float *)(DAT_006a5cd0 + (iVar7 + 0x400U & DAT_004fc8f8) * 4) * fVar4 + fVar2;
  *(float *)(iVar6 + 0x58 + DAT_006a5c38) =
       *(float *)(DAT_006a5c88 + (iVar7 + 0x400U & DAT_004fc8f8) * 4) * fVar4 + fVar3;
  iVar8 = *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
  fVar4 = *(float *)(DAT_006a5c38 + iVar8 + iVar8 * 0xa8 + 0x58);
  fVar5 = (float)*(int *)(iVar9 + 0x34 + DAT_005090d0);
  *(float *)(iVar9 + DAT_005090d0) =
       (*(float *)(DAT_006a5c38 + iVar8 + 0x50 + iVar8 * 0xa8) - fVar2) / fVar5 +
       *(float *)(iVar9 + DAT_005090d0);
  *(float *)(iVar9 + 8 + DAT_005090d0) =
       (fVar4 - fVar3) / fVar5 + *(float *)(iVar9 + 8 + DAT_005090d0);
  FUN_004a0620(param_1);
  iVar8 = *(int *)(iVar9 + 0x34 + DAT_005090d0) + -1;
  *(int *)(iVar9 + 0x34 + DAT_005090d0) = iVar8;
  if (iVar8 == 0) {
    FUN_00421f90(param_1);
  }
  return 1;
}

