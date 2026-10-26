/*
 * FUN_00408270 at 00408270
 * undefined FUN_00408270(void)
 * Address ranges: 00408270-004083fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408270(float param_1,undefined4 param_2)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  iVar2 = (int)param_1;
  param_1 = 30.0;
  iVar4 = iVar2 * 0x24;
  iVar3 = (&DAT_00505108)[iVar2 * 9];
  if (*(float *)(&DAT_00505128 + iVar4) < 30.0) {
    param_1 = *(float *)(&DAT_00505128 + iVar4);
  }
  fVar5 = (float10)FUN_00411520(iVar3,param_2);
  if (fVar5 < (float10)param_1) {
    fVar5 = (float10)FUN_00411520(iVar3,param_2);
    param_1 = (float)fVar5;
  }
  if (0.0 < *(float *)(&DAT_00505124 + iVar4)) {
    iVar3 = iVar3 * 0xd0;
    pfVar1 = (float *)(iVar3 + 0xa4 + DAT_0067ee20);
    fVar5 = (float10)FUN_0048f4e0();
    *pfVar1 = (float)((float10)*pfVar1 - fVar5 * (float10)*(float *)(iVar3 + 0xa4 + DAT_0067ee20));
    pfVar1 = (float *)(iVar3 + 0x9c + DAT_0067ee20);
    fVar5 = (float10)FUN_0048f4e0();
    *pfVar1 = (float)((float10)*pfVar1 - fVar5 * (float10)*(float *)(iVar3 + 0x9c + DAT_0067ee20));
    return;
  }
  fVar5 = (float10)FUN_00408160(iVar2);
  if (fVar5 < (float10)param_1) {
    fVar5 = (float10)FUN_00408160(iVar2);
    param_1 = (float)fVar5;
  }
  iVar3 = iVar3 * 0xd0;
  pfVar1 = (float *)(iVar3 + 0xa4 + DAT_0067ee20);
  if (*(float *)(iVar3 + 0xa4 + DAT_0067ee20) < param_1) {
    fVar5 = (float10)FUN_0048f4e0();
    *pfVar1 = (float)(fVar5 * (float10)4.0 + (float10)*pfVar1);
    return;
  }
  if (param_1 < *pfVar1) {
    if (*pfVar1 < param_1 + 4.0) {
      fVar5 = (float10)FUN_0048f4e0();
      *pfVar1 = (float)((float10)*pfVar1 - fVar5 * (float10)*(float *)(iVar3 + 0xa4 + DAT_0067ee20))
      ;
      return;
    }
    fVar5 = (float10)FUN_0048f4e0();
    fVar5 = fVar5 * (float10)*(float *)(iVar3 + 0xa4 + DAT_0067ee20);
    *pfVar1 = (float)((float10)*pfVar1 - (fVar5 + fVar5));
  }
  return;
}

