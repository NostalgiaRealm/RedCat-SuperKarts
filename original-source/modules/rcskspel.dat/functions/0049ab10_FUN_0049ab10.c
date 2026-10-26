/*
 * FUN_0049ab10 at 0049ab10
 * undefined FUN_0049ab10(void)
 * Address ranges: 0049ab10-0049ac7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_0049ab10(float *param_1,float *param_2,float param_3,float param_4,float param_5,
                    int *param_6,undefined4 *param_7)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float10 fVar4;
  float local_2c;
  int local_28;
  
  fVar1 = *param_2;
  local_2c = 3.4028235e+38;
  local_28 = -1;
  iVar3 = 0;
  pfVar2 = param_1;
  do {
    fVar4 = (float10)FUN_0049a7f0(*pfVar2,pfVar2[1],pfVar2[2],param_3 + *pfVar2,param_4 + pfVar2[1],
                                  param_5 + pfVar2[2],fVar1);
    if (fVar4 < (float10)local_2c) {
      local_2c = (float)fVar4;
      param_1 = param_2;
      local_28 = iVar3;
    }
    iVar3 = iVar3 + 1;
    pfVar2 = pfVar2 + 3;
  } while (iVar3 < 4);
  if (1.0 <= local_2c) {
    FUN_004afce0(s_NO_CLIP_004fb82c);
    *param_6 = -1;
    *param_7 = 0;
    return (float10)local_2c;
  }
  FUN_004afce0(s_clip_min____f_col_point____d_col_004fb838,(double)local_2c,local_28,param_1);
  *param_6 = local_28;
  *param_7 = param_1;
  return (float10)local_2c;
}

