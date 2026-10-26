/*
 * FUN_0049a2e0 at 0049a2e0
 * undefined FUN_0049a2e0(void)
 * Address ranges: 0049a2e0-0049a47c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0049a2e0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float local_30;
  float local_28;
  float local_c;
  
  fVar3 = -9999.9;
  local_30 = 9999.9;
  local_28 = 9999.9;
  local_c = -9999.9;
  iVar6 = 4;
  do {
    fVar1 = *param_2;
    fVar4 = fVar1 + *param_3;
    fVar2 = param_2[2];
    fVar5 = fVar2 + param_3[2];
    if (fVar1 < local_30) {
      local_30 = fVar1;
    }
    if (local_c < fVar1) {
      local_c = fVar1;
    }
    if (fVar2 < local_28) {
      local_28 = fVar2;
    }
    if (fVar3 < fVar2) {
      fVar3 = fVar2;
    }
    if (fVar4 < local_30) {
      local_30 = fVar4;
    }
    if (local_c < fVar4) {
      local_c = fVar4;
    }
    if (fVar5 < local_28) {
      local_28 = fVar5;
    }
    if (fVar3 < fVar5) {
      fVar3 = fVar5;
    }
    param_2 = param_2 + 3;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (local_c + 1.0 < *param_1) {
    return 0;
  }
  if (param_1[3] < local_30 - 1.0) {
    return 0;
  }
  if (fVar3 + 1.0 < param_1[2]) {
    return 0;
  }
  if (param_1[8] < local_28 - 1.0) {
    return 0;
  }
  return 1;
}

