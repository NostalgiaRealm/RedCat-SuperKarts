/*
 * FUN_00415990 at 00415990
 * undefined FUN_00415990(void)
 * Address ranges: 00415990-00415b5a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415990(int param_1,float param_2,undefined4 param_3,float param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  if (DAT_0053b9c0 == 8) {
    FUN_004140b0(param_1);
    return;
  }
  if (DAT_0053b9c0 != 0) {
    DAT_0053bdf4 = 1;
    param_2 = 0.0;
    param_3 = 0;
  }
  DAT_0050728c = 0;
  iVar5 = param_1 * 0xd0;
  fVar2 = *(float *)(iVar5 + 0xa4 + DAT_0067ee20);
  fVar3 = *(float *)(iVar5 + 0x9c + DAT_0067ee20);
  pfVar1 = (float *)(iVar5 + 0xa4 + DAT_0067ee20);
  fVar2 = fVar2 * fVar2 + fVar3 * fVar3;
  if (100.0 <= fVar2) {
    if (fVar2 < 20.0) {
      param_4 = ((3.0 - fVar2 * 0.15) + 1.0) * param_4;
      fVar6 = (float10)FUN_0048f4e0();
      *pfVar1 = (float)((float10)*pfVar1 -
                       fVar6 * (float10)*(float *)(iVar5 + 0xa4 + DAT_0067ee20) * (float10)0.1);
    }
    FUN_00415370(param_1,param_4);
  }
  else {
    if (fVar2 < 5.0) {
      param_4 = fVar2 * 0.2 * param_4;
    }
    FUN_00414e70(param_1,param_4);
  }
  FUN_004156c0(param_1,param_2,param_3);
  FUN_00415840(param_1);
  if (*(float *)(iVar5 + 0xa4 + DAT_0067ee20) < -15.0) {
    *(undefined4 *)(iVar5 + 0xa4 + DAT_0067ee20) = 0xc1700000;
  }
  iVar4 = DAT_0067ee20;
  DAT_0050728c = __ftol();
  if (10 < DAT_0050728c) {
    DAT_0050728c = 10;
  }
  if ((DAT_0053bdf4 != 0) && (1.0 < ABS(*(float *)(iVar5 + 0xa4 + iVar4)))) {
    DAT_0050728c = 10;
  }
  if ((DAT_00507298 == 0) && (80.0 <= param_2)) {
    DAT_0050728c = 10;
  }
  return;
}

