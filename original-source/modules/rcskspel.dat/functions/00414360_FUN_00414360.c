/*
 * FUN_00414360 at 00414360
 * undefined FUN_00414360(void)
 * Address ranges: 00414360-00414463
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414360(int param_1,float param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20);
  fVar2 = (float10)param_2 - (float10)*(float *)(DAT_006a5c38 + iVar1 + 0x50 + iVar1 * 0xa8);
  if (fVar2 == (float10)0.0) {
    fVar2 = (float10)0.0;
  }
  else if ((fVar2 <= (float10)0.0) || ((float10)0.1 <= fVar2)) {
    if ((fVar2 < (float10)0.0) && ((float10)-0.1 < fVar2)) {
      fVar2 = (float10)-0.1;
    }
  }
  else {
    fVar2 = (float10)0.1;
  }
  fpatan((float10)(param_4 - *(float *)(DAT_006a5c38 + iVar1 + 0x58 + iVar1 * 0xa8)) / fVar2,
         (float10)1);
  __ftol();
  return;
}

