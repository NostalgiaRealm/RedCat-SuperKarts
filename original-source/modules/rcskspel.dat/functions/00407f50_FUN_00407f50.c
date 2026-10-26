/*
 * FUN_00407f50 at 00407f50
 * undefined FUN_00407f50(void)
 * Address ranges: 00407f50-004080d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00407f50(int param_1,float param_2,undefined4 param_3,float param_4)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  
  iVar3 = (&DAT_00505108)[param_1 * 9] * 0xd0;
  iVar2 = *(int *)(iVar3 + 0xc + DAT_0067ee20);
  pfVar1 = (float *)(DAT_006a5c38 + iVar2 + 0x78 + iVar2 * 0xa8);
  if (4096.0 < *(float *)(DAT_006a5c38 + iVar2 + 0x78 + iVar2 * 0xa8)) {
    *pfVar1 = *pfVar1 - 4096.0;
  }
  iVar2 = *(int *)(iVar3 + 0xc + DAT_0067ee20);
  pfVar1 = (float *)(DAT_006a5c38 + iVar2 + 0x78 + iVar2 * 0xa8);
  if (*(float *)(DAT_006a5c38 + iVar2 + 0x78 + iVar2 * 0xa8) < 0.0) {
    *pfVar1 = *pfVar1 + 4096.0;
  }
  iVar2 = *(int *)(iVar3 + 0xc + DAT_0067ee20);
  iVar3 = DAT_006a5c38 + iVar2;
  fVar4 = (float10)param_2 - (float10)*(float *)(iVar3 + 0x50 + iVar2 * 0xa8);
  if (fVar4 == (float10)0.0) {
    fVar4 = (float10)0.0;
  }
  else if ((fVar4 <= (float10)0.0) || ((float10)0.1 <= fVar4)) {
    if ((fVar4 < (float10)0.0) && ((float10)-0.1 < fVar4)) {
      fVar4 = (float10)-0.1;
    }
  }
  else {
    fVar4 = (float10)0.1;
  }
  fVar5 = (float10)fpatan((float10)(param_4 - *(float *)(iVar3 + 0x58 + iVar2 * 0xa8)) / fVar4,
                          (float10)1);
  if (fVar4 <= (float10)0.0) {
    fVar4 = (float10)1024.0;
  }
  else {
    fVar4 = (float10)3072.0;
  }
  fVar4 = ((float10)(float)(fVar5 * (float10)0.15915494 * (float10)4096.0) + fVar4) -
          (float10)*(float *)(iVar3 + iVar2 * 0xa8 + 0x78);
  if ((float10)2048.0 < fVar4) {
    fVar4 = fVar4 - (float10)4096.0;
  }
  if (fVar4 < (float10)-2048.0) {
    fVar4 = fVar4 + (float10)4096.0;
  }
  return fVar4;
}

