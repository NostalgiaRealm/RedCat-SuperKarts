/*
 * FUN_004220c0 at 004220c0
 * undefined FUN_004220c0(void)
 * Address ranges: 004220c0-004221c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004220c0(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(DAT_006a5c38 + 0xc + param_1 * 0xa9) * 0x44;
  *(int *)(iVar3 + 0x28 + DAT_005090d0) =
       *(int *)(iVar3 + 0x28 + DAT_005090d0) +
       (int)(0x1000 / (longlong)*(int *)(iVar3 + 0x34 + DAT_005090d0));
  if (0x7fe < *(int *)(iVar3 + 0x28 + DAT_005090d0)) {
    *(undefined4 *)(iVar3 + 0x28 + DAT_005090d0) = 0;
  }
  iVar4 = *(int *)(iVar3 + 0x24 + DAT_005090d0);
  fVar1 = *(float *)(iVar3 + DAT_005090d0 + 0x10);
  if (0x19 < iVar4) {
    iVar2 = (int)(0x3c / (longlong)*(int *)(iVar3 + 0x34 + DAT_005090d0));
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    *(int *)(iVar3 + 0x24 + DAT_005090d0) = iVar4 - iVar2;
  }
  *(float *)(DAT_006a5c38 + 0x54 + param_1 * 0xa9) =
       *(float *)(DAT_006a5c88 + (*(uint *)(iVar3 + 0x28 + DAT_005090d0) & DAT_004fc8f8) * 4) *
       (float)*(int *)(iVar3 + 0x24 + DAT_005090d0) + fVar1;
  iVar4 = *(int *)(iVar3 + 0x40 + DAT_005090d0) + 1;
  *(int *)(iVar3 + 0x40 + DAT_005090d0) = iVar4;
  if (*(int *)(iVar3 + 0x34 + DAT_005090d0) <= iVar4) {
    FUN_00421f90(param_1);
  }
  return 1;
}

