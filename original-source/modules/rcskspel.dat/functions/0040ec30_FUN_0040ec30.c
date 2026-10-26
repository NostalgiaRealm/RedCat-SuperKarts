/*
 * FUN_0040ec30 at 0040ec30
 * undefined FUN_0040ec30(void)
 * Address ranges: 0040ec30-0040ed32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ec30(int param_1,float *param_2)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = DAT_006a5c38 + *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
  fVar2 = (float10)*param_2 - (float10)*(float *)(iVar1 + 0x50);
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
  fpatan((float10)(param_2[2] - *(float *)(iVar1 + 0x58)) / fVar2,(float10)1);
  __ftol();
  return;
}

