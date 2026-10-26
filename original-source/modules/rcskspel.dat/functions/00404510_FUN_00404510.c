/*
 * FUN_00404510 at 00404510
 * undefined FUN_00404510(void)
 * Address ranges: 00404510-0040465a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00404510(int param_1,int param_2,int param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  int iVar8;
  float10 fVar9;
  float10 fVar10;
  undefined1 local_c [12];
  
  iVar1 = *(int *)(DAT_00504f98 + 0x24 + param_3 * 0x6c);
  pfVar7 = (float *)(param_2 * 0x50 + 8 + DAT_00680ae0);
  iVar8 = DAT_006a5c38 + *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
  fVar4 = *pfVar7 - *(float *)(iVar8 + 0x50);
  fVar5 = pfVar7[1] - *(float *)(iVar8 + 0x54);
  fVar6 = pfVar7[2] - *(float *)(iVar8 + 0x58);
  pfVar7 = (float *)FUN_004a23d0(local_c,iVar8 + 0x10);
  fVar2 = *pfVar7;
  fVar3 = pfVar7[2];
  fVar9 = SQRT((float10)fVar4 * (float10)fVar4 +
               (float10)fVar5 * (float10)fVar5 + (float10)fVar6 * (float10)fVar6);
  fVar10 = SQRT((float10)fVar2 * (float10)fVar2 +
                (float10)pfVar7[1] * (float10)pfVar7[1] + (float10)fVar3 * (float10)fVar3);
  return (((float10)fVar6 / fVar9) * (float10)(float)((float10)fVar2 / fVar10) -
         ((float10)fVar3 / fVar10) * (float10)(float)((float10)fVar4 / fVar9)) *
         (float10)*(float *)(DAT_00504fe0 + 0xc + iVar1 * 0x2c);
}

