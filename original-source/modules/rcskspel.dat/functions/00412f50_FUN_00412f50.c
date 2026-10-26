/*
 * FUN_00412f50 at 00412f50
 * undefined FUN_00412f50(void)
 * Address ranges: 00412f50-00412fc4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00412f50(int param_1,float *param_2)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = *(int *)(&DAT_00503f24 + param_1 * 0x11c) * 0x1f +
          *(int *)(&DAT_00503f38 + param_1 * 0x11c);
  fVar2 = (float10)*(float *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) /
          (float10)(float)(&DAT_00506918)[iVar1];
  *param_2 = (float)fVar2;
  fVar2 = ((float10)1.0 - fVar2) * (float10)(float)(&DAT_005068e8)[iVar1];
  if (fVar2 < (float10)0.0) {
    fVar2 = (float10)0.0;
  }
  return fVar2;
}

