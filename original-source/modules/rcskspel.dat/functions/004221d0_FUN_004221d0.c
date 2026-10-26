/*
 * FUN_004221d0 at 004221d0
 * undefined FUN_004221d0(void)
 * Address ranges: 004221d0-004222e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004221d0(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  param_1 = param_1 * 0xa9;
  iVar6 = *(int *)(param_1 + 0xc + DAT_006a5c38) * 0x44;
  pfVar1 = (float *)(param_1 + 0x50 + DAT_006a5c38);
  fVar2 = *(float *)(iVar6 + DAT_005090d0 + 8);
  fVar3 = pfVar1[2];
  *(float *)(param_1 + 0x5c + DAT_006a5c38) = (*pfVar1 - *(float *)(iVar6 + DAT_005090d0)) * 0.2;
  *(float *)(param_1 + 100 + DAT_006a5c38) = (fVar3 - fVar2) * 0.2;
  *(undefined4 *)(param_1 + 0x60 + DAT_006a5c38) = 0x41700000;
  iVar5 = param_1 + DAT_006a5c38;
  iVar4 = FUN_004be6c9();
  *(float *)(iVar5 + 0x68) = (float)(iVar4 % 200);
  iVar5 = param_1 + DAT_006a5c38;
  iVar4 = FUN_004be6c9();
  *(float *)(iVar5 + 0x6c) = (float)(iVar4 % 200);
  param_1 = param_1 + DAT_006a5c38;
  iVar5 = FUN_004be6c9();
  *(float *)(param_1 + 0x70) = (float)(iVar5 % 200);
  *(undefined4 *)(iVar6 + 0x34 + DAT_005090d0) = 0x19;
  return iVar5 / 200;
}

