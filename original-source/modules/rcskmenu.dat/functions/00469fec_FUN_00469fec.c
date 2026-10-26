/*
 * FUN_00469fec at 00469fec
 * undefined FUN_00469fec(void)
 * Address ranges: 00469fec-0046a07b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00469fec(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *in_FS_OFFSET;
  int in_stack_00000004;
  undefined4 uStack_18;
  undefined *puStack_14;
  undefined1 *puStack_10;
  int *piStack_8;
  
  puStack_10 = &stack0xfffffffc;
  piStack_8 = (int *)0x0;
  puStack_14 = &UNK_0046a07c;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  piVar1 = *(int **)(*(int *)(in_stack_00000004 + -4) + 0x2f8);
  uVar2 = FUN_00424728(piVar1);
  piVar1 = (int *)piVar1[0x7c];
  (**(code **)(*piVar1 + 0x18))(piVar1,uVar2);
  FUN_00405490((int *)&piStack_8);
  uVar3 = DirectDrawCreate();
  FUN_00468e3c(uVar3);
  piVar1 = piStack_8;
  uVar3 = (**(code **)(*piStack_8 + 0x20))();
  FUN_00468e3c(uVar3);
  *in_FS_OFFSET = piVar1;
  FUN_00405490((int *)&piStack_8);
  return;
}

