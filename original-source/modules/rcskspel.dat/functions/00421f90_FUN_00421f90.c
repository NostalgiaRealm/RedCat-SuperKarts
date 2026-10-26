/*
 * FUN_00421f90 at 00421f90
 * undefined FUN_00421f90(void)
 * Address ranges: 00421f90-0042202a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00421f90(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 * 0xa9 + 0xc + DAT_006a5c38) * 0x44;
  iVar1 = *(int *)(iVar3 + 0x38 + DAT_005090d0);
  iVar4 = *(int *)(iVar3 + 0x3c + DAT_005090d0) + 1;
  iVar2 = *(int *)(&DAT_004e40f8 + iVar1 * 0x2c);
  *(int *)(iVar3 + 0x3c + DAT_005090d0) = iVar4;
  if (iVar2 <= iVar4) {
    FUN_00421d60(param_1);
    return;
  }
  iVar1 = *(int *)(&DAT_004e40fc + (*(int *)(iVar3 + 0x3c + DAT_005090d0) + iVar1 * 0xb) * 4);
  if ((code *)(&PTR_FUN_004e40d0)[iVar1 * 2] != (code *)0x0) {
    (*(code *)(&PTR_FUN_004e40d0)[iVar1 * 2])(param_1);
  }
  *(undefined **)(param_1 * 0xa9 + 0x9d + DAT_006a5c38) = (&PTR_FUN_004e40d4)[iVar1 * 2];
  return;
}

