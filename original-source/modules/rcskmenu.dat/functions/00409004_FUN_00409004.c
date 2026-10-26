/*
 * FUN_00409004 at 00409004
 * undefined __register FUN_00409004(void)
 * Address ranges: 00409004-0040902d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409004(void)

{
  int iVar1;
  int *piVar2;
  int in_stack_00000004;
  
  piVar2 = (int *)(in_stack_00000004 + -4);
  iVar1 = *piVar2;
  while (*(char *)*piVar2 == *(char *)(in_stack_00000004 + -5)) {
    *piVar2 = *piVar2 + 1;
  }
  *(int *)(in_stack_00000004 + -0xc) = (*piVar2 - iVar1) + 1;
  return;
}

