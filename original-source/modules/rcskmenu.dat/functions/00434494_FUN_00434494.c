/*
 * FUN_00434494 at 00434494
 * bool __register FUN_00434494(void)
 * Address ranges: 00434494-004344ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00434494(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int in_stack_00000004;
  
  if (*(int *)(*(int *)(in_stack_00000004 + -4) + 0x20) == 0) {
    iVar4 = FUN_00433bb0(*(int **)(in_stack_00000004 + -8));
    return 0 < iVar4;
  }
  piVar1 = *(int **)(*(int *)(in_stack_00000004 + -4) + 0x20);
  uVar3 = FUN_00403024(piVar1,(int)&PTR_FUN_00433640);
  if (((char)uVar3 != '\0') &&
     (cVar2 = FUN_004343a4(*(int **)(in_stack_00000004 + -8),piVar1), cVar2 != '\0')) {
    return false;
  }
  return true;
}

