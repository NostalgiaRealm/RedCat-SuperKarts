/*
 * FUN_00401320 at 00401320
 * undefined FUN_00401320(void)
 * Address ranges: 00401320-00401560
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401320(int param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float local_10;
  
  param_1 = param_1 * 0xd0;
  iVar2 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  pfVar1 = (float *)(DAT_006a5c38 + iVar2 + 0x78 + iVar2 * 0xa8);
  if (4096.0 <= *(float *)(DAT_006a5c38 + iVar2 + 0x78 + iVar2 * 0xa8)) {
    *pfVar1 = *pfVar1 - 4096.0;
  }
  iVar2 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  pfVar1 = (float *)(DAT_006a5c38 + iVar2 + 0x78 + iVar2 * 0xa8);
  if (*(float *)(DAT_006a5c38 + iVar2 + 0x78 + iVar2 * 0xa8) < 0.0) {
    *pfVar1 = *pfVar1 + 4096.0;
  }
  iVar2 = *(int *)(param_1 + 0xc + DAT_0067ee20);
  local_10 = *param_2 - *(float *)(DAT_006a5c38 + iVar2 + 0x50 + iVar2 * 0xa8);
  fVar3 = param_2[2] - *(float *)(DAT_006a5c38 + iVar2 + iVar2 * 0xa8 + 0x58);
  if (local_10 == 0.0) {
    local_10 = 0.1;
  }
  else if ((local_10 <= 0.0) || (0.1 <= local_10)) {
    if ((local_10 < 0.0) && (-0.1 < local_10)) {
      local_10 = -0.1;
    }
  }
  else {
    local_10 = 0.1;
  }
  FUN_004afce0(s_delta_x__f_z__f_004dd924,(double)local_10,(double)fVar3);
  fpatan((float10)fVar3 / (float10)local_10,(float10)1);
  FUN_004afce0();
  FUN_004afce0();
  FUN_004afce0();
  __ftol();
  return;
}

