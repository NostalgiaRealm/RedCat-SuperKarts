/*
 * FUN_0046683c at 0046683c
 * undefined FUN_0046683c(void)
 * Address ranges: 0046683c-00466919
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046683c(int *param_1,int param_2)

{
  int iVar1;
  int nSavedDC;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  
  iVar1 = *(int *)(param_2 + 8);
  nSavedDC = SaveDC(*(HDC *)(iVar1 + 0x18));
  FUN_004185e8(param_1[0x7c]);
  *in_FS_OFFSET = &stack0xffffffdc;
  FUN_00418a14((int *)param_1[0x7c],*(int *)(iVar1 + 0x18));
  FUN_004188b4(param_1[0x7c]);
  FUN_004188d0(param_1[0x7c]);
  uVar2 = CONCAT31((int3)((uint)iVar1 >> 8),(*(byte *)(iVar1 + 0x10) & 1) != 0);
  (**(code **)(*param_1 + 0xb8))(param_1,*(undefined4 *)(iVar1 + 8),iVar1 + 0x1c);
  *in_FS_OFFSET = uVar2;
  FUN_00418a14((int *)param_1[0x7c],0);
  FUN_0041888c(param_1[0x7c]);
  RestoreDC(*(HDC *)(iVar1 + 0x18),nSavedDC);
  return;
}

