/*
 * FUN_004304d0 at 004304d0
 * undefined FUN_004304d0(void)
 * Address ranges: 004304d0-00430605
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004304d0(int param_1)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  pfVar2 = (float *)(DAT_00680b28 + 0x48 + DAT_00508674 * 0x984);
  fVar3 = *pfVar2;
  fVar4 = pfVar2[1];
  fVar5 = pfVar2[2];
  iVar1 = DAT_00680ba0 + (&DAT_00508620)[DAT_00508670] * 0x178;
  fVar6 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5);
  fVar9 = *(float *)(iVar1 + 0x54) - *(float *)(iVar1 + 8);
  fVar10 = *(float *)(iVar1 + 0x58) - *(float *)(iVar1 + 0xc);
  fVar8 = *(float *)(iVar1 + 0x5c) - *(float *)(iVar1 + 0x10);
  fVar7 = SQRT(fVar9 * fVar9 + fVar10 * fVar10 + fVar8 * fVar8);
  fVar3 = (fVar9 / fVar7) * (fVar3 / fVar6) +
          (fVar10 / fVar7) * (fVar4 / fVar6) + (fVar8 / fVar7) * (fVar5 / fVar6);
  if (fVar3 <= 0.0) {
    if (fVar3 < -0.5736) {
      param_1 = (DAT_00508674 - DAT_0053b9d0) + param_1;
      goto LAB_004305f2;
    }
LAB_004305e6:
    param_1 = DAT_0053b9d0 / 2;
  }
  else if (fVar3 <= 0.5736) goto LAB_004305e6;
  param_1 = DAT_00508674 - param_1;
LAB_004305f2:
  if (param_1 < 0) {
    param_1 = param_1 + -1 + DAT_00680220;
  }
  return param_1;
}

