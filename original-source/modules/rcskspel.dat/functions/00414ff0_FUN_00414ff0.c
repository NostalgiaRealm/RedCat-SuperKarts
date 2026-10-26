/*
 * FUN_00414ff0 at 00414ff0
 * undefined FUN_00414ff0(void)
 * Address ranges: 00414ff0-004150e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00414ff0(int param_1,int param_2,float param_3)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  float10 fVar4;
  
  iVar3 = DAT_0053be2c * 0xac;
  if (param_2 < 2) {
    iVar1 = param_1 * 0xd0 + DAT_0067ee20;
    pfVar2 = (float *)(iVar1 + 0xa4);
    if (*(float *)(iVar1 + 0xa4) == 0.0) {
      fVar4 = (float10)0.0;
    }
    else {
      fVar4 = (float10)fpatan(((float10)*(float *)(iVar1 + 0x9c) -
                              (float10)*(float *)(&DAT_00505b70 + iVar3) *
                              (float10)*(float *)(iVar1 + 0xac)) / (float10)*pfVar2,(float10)1);
      fVar4 = (float10)param_3 * (float10)*(float *)(&DAT_00505b7c + iVar3) * (float10)0.01 - fVar4;
    }
  }
  else {
    iVar1 = param_1 * 0xd0 + DAT_0067ee20;
    pfVar2 = (float *)(iVar1 + 0xa4);
    if (*(float *)(iVar1 + 0xa4) == 0.0) {
      fVar4 = (float10)0.0;
    }
    else {
      fVar4 = (float10)fpatan(((float10)*(float *)(iVar1 + 0xac) *
                               (float10)*(float *)(&DAT_00505b74 + iVar3) +
                              (float10)*(float *)(iVar1 + 0x9c)) / (float10)*pfVar2,(float10)1);
      fVar4 = -fVar4;
    }
  }
  if (*pfVar2 < 0.0) {
    fVar4 = -fVar4;
  }
  return fVar4;
}

