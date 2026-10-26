/*
 * FUN_00420490 at 00420490
 * undefined FUN_00420490(void)
 * Address ranges: 00420490-004205e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420490(void)

{
  float fVar1;
  float fVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  DVar3 = GetTickCount();
  if (199 < (int)(DVar3 - DAT_00508b00)) {
    DAT_00508b00 = DVar3;
    iVar4 = FUN_004be6c9();
    fVar1 = (float)(iVar4 % 6 + -3) + 16.0;
    uVar5 = __ftol();
    iVar4 = FUN_004be6c9();
    iVar6 = (DAT_004fc8f8 & uVar5) * 4;
    fVar2 = (float)(iVar4 % 0x12 + -9);
    FUN_00428690(_DAT_0053be44 +
                 (*(float *)(iVar6 + DAT_006a5cd0) * fVar2 -
                 *(float *)(iVar6 + DAT_006a5c88) * fVar1),DAT_0053be48 + 5.0,
                 DAT_0053be4c +
                 *(float *)(iVar6 + DAT_006a5cd0) * fVar1 + fVar2 * *(float *)(iVar6 + DAT_006a5c88)
                 ,0,0,0);
  }
  return;
}

