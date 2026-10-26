/*
 * FUN_00415160 at 00415160
 * undefined FUN_00415160(void)
 * Address ranges: 00415160-0041527d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415160(float *param_1,undefined4 param_2,float param_3,int param_4,float param_5)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float local_14;
  float local_10;
  
  if ((param_4 == 0) || (param_4 == 1)) {
    iVar2 = (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
    local_10 = *(float *)(&DAT_00505bec + iVar2);
    local_14 = *(float *)(&DAT_00505bf4 + iVar2);
    fVar3 = *(float *)(&DAT_00505bfc + iVar2);
  }
  else {
    iVar2 = (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4;
    local_10 = *(float *)(&DAT_00505bd4 + iVar2);
    local_14 = *(float *)(&DAT_00505bdc + iVar2);
    fVar3 = *(float *)(&DAT_00505be4 + iVar2);
  }
  fVar1 = *(float *)(&DAT_00505b7c + DAT_0053be2c * 0xac);
  fVar4 = (float10)FUN_004150f0(param_4,param_2);
  fVar5 = (float10)fsin((float10)fVar3 * (float10)param_3);
  fVar6 = (float10)fcos((float10)(param_5 * fVar1 * 0.01));
  *param_1 = (float)(fVar6 * ((float10)local_10 * (float10)param_3 + fVar5 * (float10)local_14) *
                             fVar4 * (float10)0.25);
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  return;
}

