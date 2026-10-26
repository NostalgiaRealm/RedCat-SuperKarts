/*
 * FUN_00432240 at 00432240
 * undefined FUN_00432240(void)
 * Address ranges: 00432240-00432454
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432240(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  DWORD DVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  FUN_00432190();
  if (3 < DAT_0050728c) {
    DVar5 = GetTickCount();
    if (99 < (int)(DVar5 - DAT_0053be10)) {
      iVar8 = DAT_0053be28 * 0xd0 + DAT_0067ee20;
      fVar1 = -(*(float *)(&DAT_004e02b0 + DAT_0053be2c * 300) * 10.0);
      DAT_0053be10 = DVar5;
      uVar6 = __ftol();
      iVar7 = (DAT_004fc8f8 & uVar6) * 4;
      fVar2 = *(float *)(iVar8 + 0x9c) * 0.6;
      fVar4 = *(float *)(iVar8 + 0xa4) * 0.6;
      fVar3 = *(float *)(iVar7 + DAT_006a5cd0) * fVar2 - *(float *)(iVar7 + DAT_006a5c88) * fVar4;
      fVar2 = *(float *)(iVar7 + DAT_006a5cd0) * fVar4 + *(float *)(iVar7 + DAT_006a5c88) * fVar2;
      FUN_00428690(_DAT_0053be44 +
                   (*(float *)(iVar7 + DAT_006a5cd0) * 9.0 -
                   *(float *)(iVar7 + DAT_006a5c88) * fVar1),DAT_0053be48 + 3.0,
                   DAT_0053be4c +
                   *(float *)(iVar7 + DAT_006a5c88) * 9.0 + *(float *)(iVar7 + DAT_006a5cd0) * fVar1
                   ,fVar3,0,fVar2);
      iVar8 = (DAT_004fc8f8 & uVar6) * 4;
      FUN_00428690(_DAT_0053be44 +
                   (*(float *)(iVar8 + DAT_006a5cd0) * -9.0 -
                   *(float *)(iVar8 + DAT_006a5c88) * fVar1),DAT_0053be48 + 3.0,
                   DAT_0053be4c +
                   (*(float *)(iVar8 + DAT_006a5cd0) * fVar1 -
                   *(float *)(iVar8 + DAT_006a5c88) * 9.0),fVar3,0,fVar2);
    }
  }
  return;
}

