/*
 * FUN_00429d7c at 00429d7c
 * int __register FUN_00429d7c(void)
 * Address ranges: 00429d7c-00429dda
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00429d7c(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000004;
  int local_8;
  
  sVar1 = *(short *)(*(int *)(in_stack_00000004 + -8) + 6);
  FUN_00445724(*(int **)(*(int *)(in_stack_00000004 + -4) + 4));
  iVar2 = (**(code **)PTR_DAT_0047c618)();
  iVar3 = (int)sVar1;
  if (iVar2 != 0) {
    iVar3 = local_8;
  }
  return iVar3;
}

