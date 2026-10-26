/*
 * FUN_00405fd0 at 00405fd0
 * undefined FUN_00405fd0(void)
 * Address ranges: 00405fd0-004060fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00405fd0(int param_1,int param_2)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  
  if (DAT_0053b9f4 != 2) {
    iVar8 = DAT_0053b9f4 * 0xc;
    if (param_2 < *(int *)(&DAT_004d2330 + iVar8) + *(int *)(&DAT_004d2334 + iVar8)) {
      fVar3 = (float)((param_2 - *(int *)(&DAT_004d2330 + iVar8)) / *(int *)(&DAT_004d2334 + iVar8))
              * *(float *)(&DAT_004d2338 + iVar8);
    }
    else {
      fVar3 = *(float *)(&DAT_004d2338 + iVar8);
    }
    fVar3 = 1.0 - fVar3;
    cVar7 = FUN_00417e90(param_1);
    iVar8 = DAT_0053be28;
    if (cVar7 == '\0') {
      iVar8 = (&DAT_005081bc)[param_1 * 0x1c];
    }
    iVar1 = iVar8 * 0xd0 + 0x9c + DAT_0067ee20;
    fVar4 = *(float *)(iVar8 * 0xd0 + 0x9c + DAT_0067ee20);
    fVar5 = *(float *)(iVar1 + 4);
    fVar6 = *(float *)(iVar1 + 8);
    cVar7 = FUN_00417e90(param_1);
    iVar8 = DAT_0053be28;
    if (cVar7 == '\0') {
      iVar8 = (&DAT_005081bc)[param_1 * 0x1c];
    }
    pfVar2 = (float *)(iVar8 * 0xd0 + 0x9c + DAT_0067ee20);
    *pfVar2 = fVar4 * fVar3;
    pfVar2[1] = fVar5 * fVar3;
    pfVar2[2] = fVar6 * fVar3;
  }
  return;
}

