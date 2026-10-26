/*
 * FUN_00436980 at 00436980
 * undefined FUN_00436980(void)
 * Address ranges: 00436980-00436b06
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00436980(undefined4 param_1,undefined4 *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  char cVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  
  iVar10 = FUN_00436dc0(param_1);
  cVar9 = FUN_00417e90(iVar10);
  iVar12 = DAT_0053be28;
  if (cVar9 == '\0') {
    iVar12 = (&DAT_005081bc)[iVar10 * 0x1c];
  }
  iVar3 = *(int *)(iVar12 * 0xd0 + 0xc + DAT_0067ee20);
  iVar12 = DAT_006a5c38 + iVar3 + 0x50 + iVar3 * 0xa8;
  uVar4 = *(undefined4 *)(DAT_006a5c38 + iVar3 + 0x50 + iVar3 * 0xa8);
  uVar5 = *(undefined4 *)(iVar12 + 4);
  uVar6 = *(undefined4 *)(iVar12 + 8);
  cVar9 = FUN_00417e90(iVar10);
  iVar12 = DAT_0053be28;
  if (cVar9 == '\0') {
    iVar12 = (&DAT_005081bc)[iVar10 * 0x1c];
  }
  fVar7 = *(float *)(iVar12 * 0xd0 + 0x9c + DAT_0067ee20);
  fVar8 = *(float *)(iVar12 * 0xd0 + DAT_0067ee20 + 0xa4);
  FUN_00417e90(iVar10);
  uVar11 = __ftol();
  iVar12 = (DAT_004fc8f8 & uVar11) * 4;
  fVar1 = *(float *)(iVar12 + DAT_006a5cd0);
  fVar2 = *(float *)(iVar12 + DAT_006a5c88);
  *param_3 = *(float *)(iVar12 + DAT_006a5cd0) * fVar7 - *(float *)(iVar12 + DAT_006a5c88) * fVar8;
  param_3[1] = 0.0;
  param_3[2] = fVar2 * fVar7 + fVar1 * fVar8;
  *param_2 = uVar4;
  param_2[1] = uVar5;
  param_2[2] = uVar6;
  return;
}

