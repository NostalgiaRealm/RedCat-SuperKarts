/*
 * FUN_00413330 at 00413330
 * undefined FUN_00413330(void)
 * Address ranges: 00413330-004134d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413330(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  float10 fVar15;
  
  iVar13 = param_1 * 0xd0;
  pfVar1 = (float *)(iVar13 + 0x9c + DAT_0067ee20);
  iVar12 = DAT_006a5c38 + *(int *)(iVar13 + 0xc + DAT_0067ee20) * 0xa9;
  fVar6 = *(float *)(iVar12 + 0x50);
  fVar7 = *(float *)(iVar12 + 0x54);
  fVar8 = *(float *)(iVar12 + 0x58);
  fVar9 = *pfVar1;
  fVar10 = pfVar1[2];
  uVar11 = __ftol();
  iVar12 = (uVar11 & DAT_004fc8f8) * 4;
  fVar2 = *(float *)(iVar12 + DAT_006a5cd0);
  fVar3 = *(float *)(iVar12 + DAT_006a5c88);
  fVar4 = *(float *)(iVar12 + DAT_006a5cd0);
  fVar5 = *(float *)(iVar12 + DAT_006a5c88);
  fVar14 = (float10)FUN_0048f4e0();
  fVar2 = (float)(fVar14 * (float10)(fVar2 * fVar9 - fVar3 * fVar10) * (float10)10.0 +
                 (float10)fVar6);
  fVar14 = (float10)FUN_0048f4e0();
  fVar3 = (float)(fVar14 * (float10)(fVar5 * fVar9 + fVar4 * fVar10) * (float10)10.0 +
                 (float10)fVar8);
  FUN_004977d0(*(undefined4 *)(iVar13 + 0x1c + DAT_0067ee20),fVar2,fVar7,fVar3);
  fVar14 = (float10)FUN_00494b70(fVar2,fVar3);
  fVar2 = *(float *)(iVar13 + 0xa0 + DAT_0067ee20);
  pfVar1 = (float *)(iVar13 + 0xa0 + DAT_0067ee20);
  fVar15 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)(fVar15 * (float10)(fVar2 * -3.0 - (fVar7 - (float)fVar14) * 3.0) +
                   (float10)*pfVar1);
  if (((float)fVar14 + 2.0 < fVar7) && (param_1 == DAT_0053be28)) {
    DAT_0050728c = 0;
  }
  return;
}

