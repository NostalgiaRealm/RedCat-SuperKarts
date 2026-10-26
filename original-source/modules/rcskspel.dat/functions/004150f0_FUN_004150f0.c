/*
 * FUN_004150f0 at 004150f0
 * undefined FUN_004150f0(void)
 * Address ranges: 004150f0-0041515f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_004150f0(int param_1,int param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)1.0 / (float10)*(float *)(param_2 * 0xd0 + 0x90 + DAT_0067ee20);
  if (param_1 < 2) {
    return fVar1 * (float10)*(float *)(&DAT_00505b64 + DAT_0053be2c * 0xac) * (float10)9.8;
  }
  fVar1 = fVar1 * (float10)*(float *)(&DAT_00505b68 + DAT_0053be2c * 0xac) * (float10)9.8;
  if (DAT_0053bdf4 != 0) {
    fVar1 = fVar1 * (float10)0.6;
  }
  return fVar1;
}

