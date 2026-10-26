/*
 * FUN_00411520 at 00411520
 * undefined FUN_00411520(void)
 * Address ranges: 00411520-0041159f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00411520(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float local_4;
  
  fVar3 = (float10)500.0;
  local_4 = (float)fVar3;
  iVar1 = *(int *)(param_2 * 0x50 + 0x24 + DAT_00680ae0);
  if ((0 < iVar1) && (iVar2 = 0, 0 < iVar1)) {
    do {
      iVar1 = FUN_004944a0(iVar2);
      if ((iVar1 != param_1) && (*(float *)(iVar1 * 0xd0 + 0xa4 + DAT_0067ee20) < local_4)) {
        local_4 = *(float *)(iVar1 * 0xd0 + 0xa4 + DAT_0067ee20);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_2 * 0x50 + 0x24 + DAT_00680ae0));
    fVar3 = (float10)local_4;
  }
  return fVar3;
}

