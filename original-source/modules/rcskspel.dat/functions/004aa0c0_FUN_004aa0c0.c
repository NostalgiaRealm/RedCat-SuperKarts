/*
 * FUN_004aa0c0 at 004aa0c0
 * undefined FUN_004aa0c0(void)
 * Address ranges: 004aa0c0-004aa22d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004aa0c0(undefined4 *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_10 = *param_2;
  fVar1 = param_2[1];
  local_4 = param_2[1];
  pfVar3 = param_2 + 2;
  local_c = param_2[2];
  param_2 = (float *)local_10;
  local_8 = local_c;
  if (0 < param_3) {
    do {
      if (pfVar3[-2] < local_10) {
        local_10 = pfVar3[-2];
      }
      if (pfVar3[-1] < local_4) {
        local_4 = pfVar3[-1];
      }
      if (*pfVar3 < local_8) {
        local_8 = *pfVar3;
      }
      if ((float)param_2 < pfVar3[-2]) {
        param_2 = (float *)pfVar3[-2];
      }
      if (fVar1 < pfVar3[-1]) {
        fVar1 = pfVar3[-1];
      }
      if (local_c < *pfVar3) {
        local_c = *pfVar3;
      }
      pfVar3 = pfVar3 + 8;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  param_1[8] = fVar1;
  param_1[0xb] = fVar1;
  param_1[0x14] = fVar1;
  param_1[0x17] = fVar1;
  param_1[1] = local_10;
  fVar1 = ((float)param_2 - local_10) * 0.5;
  param_1[3] = local_8;
  param_1[5] = local_4;
  fVar2 = (local_c - local_8) * 0.5;
  param_1[2] = local_4;
  param_1[7] = param_2;
  param_1[4] = param_2;
  param_1[10] = local_10;
  param_1[0xd] = local_10;
  param_1[6] = local_8;
  param_1[9] = local_8;
  param_1[0xc] = local_8;
  param_1[0xf] = local_c;
  param_1[0xe] = local_4;
  param_1[0x11] = local_4;
  param_1[0x10] = param_2;
  param_1[0x13] = param_2;
  param_1[0x12] = local_c;
  param_1[0x15] = local_c;
  param_1[0x16] = local_10;
  param_1[0x18] = local_c;
  *param_1 = 1;
  param_1[0x1a] = SQRT(fVar1 * fVar1 + fVar2 * fVar2);
  return;
}

