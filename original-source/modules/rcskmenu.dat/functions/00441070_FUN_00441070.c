/*
 * FUN_00441070 at 00441070
 * undefined __register FUN_00441070(void)
 * Address ranges: 00441070-004410f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441070(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int in_stack_00000004;
  int local_24 [4];
  int local_14 [2];
  int local_c;
  int local_8;
  
  piVar3 = (int *)(in_stack_00000004 + -4);
  FUN_0040ebd0(*(undefined4 *)(*piVar3 + 0x30),*(undefined4 *)(*piVar3 + 0x34),local_14);
  FUN_0043f1c4(*(int **)(*piVar3 + 0x24),local_14,&local_c);
  iVar1 = *(int *)(*(int *)(in_stack_00000004 + -8) + 8);
  piVar2 = *(int **)(*piVar3 + 0x24);
  FUN_0040ec04((piVar2[0xc] + *(int *)(iVar1 + 0x44)) - local_c,
               (piVar2[0xd] + *(int *)(iVar1 + 0x48)) - local_8,
               ((*(int *)(iVar1 + 0x4c) - *(int *)(iVar1 + 0x44)) + piVar2[0xe]) -
               *(int *)(*piVar3 + 0x38),local_24,
               ((*(int *)(iVar1 + 0x50) - *(int *)(iVar1 + 0x48)) + piVar2[0xf]) -
               *(int *)(*piVar3 + 0x3c));
  FUN_0043f074(piVar2,local_24);
  return;
}

