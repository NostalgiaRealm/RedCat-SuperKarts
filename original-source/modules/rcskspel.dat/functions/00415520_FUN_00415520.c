/*
 * FUN_00415520 at 00415520
 * undefined FUN_00415520(void)
 * Address ranges: 00415520-004156be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415520(float *param_1,int param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float local_18;
  float local_10;
  
  iVar1 = param_2 * 0xd0 + DAT_0067ee20;
  fVar4 = 1.0 / *(float *)(param_2 * 0xd0 + 0x90 + DAT_0067ee20);
  fVar2 = *(float *)(&DAT_00505c04 + (DAT_0053bef4 + DAT_0053be2c * 0x2b) * 4);
  fVar5 = *(float *)(iVar1 + 0xa4) * *(float *)(iVar1 + 0xa4);
  if (*(float *)(iVar1 + 0xa4) <= 1e-05) {
    local_10 = 0.0;
    if (*(float *)(iVar1 + 0xa4) < -1e-05) {
      local_10 = (fVar4 * 9.8 + fVar5 * 2.8) * fVar2;
    }
  }
  else {
    local_10 = fVar2 * fVar4 * -9.8 - fVar5 * fVar2 * 2.8;
  }
  iVar3 = *(int *)(iVar1 + 0xc);
  local_10 = local_10 + fVar5 * *(float *)(&DAT_00505b78 + DAT_0053be2c * 0xac) * -0.456;
  local_18 = 0.0;
  if (*(float *)(iVar1 + 0xa4) <= 5.0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = *(float *)(DAT_006a5c38 + iVar3 + iVar3 * 0xa8 + 0x14) * fVar4 * -1.96;
  }
  if (DAT_0053bdf4 == 0) {
    local_10 = *(float *)(DAT_006a5c38 + iVar3 + 0x34 + iVar3 * 0xa8) * fVar4 * -9.8 + local_10;
    local_18 = fVar2;
  }
  *param_1 = local_18;
  param_1[1] = 0.0;
  param_1[2] = local_10;
  return;
}

